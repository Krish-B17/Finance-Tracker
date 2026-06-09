#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "report.h"
#include "expense.h"

#include <QDate>
#include <QString>
#include <QVector>

// building a category with matching-category expenses so Category::recomputeSpent counts them
static Category makeCategoryWithExpenses(const QString& name, double budgetLimit, const QVector<double>& amounts) {
    Category c(name, budgetLimit, 0.0); // FIX: Category ctor takes 3 args
    for (double amt : amounts) {
        c.addExpense(Expense(amt, name, QDate(2025, 12, 1), "test"));
    }
    return c;
}

// testing that total income, total expenses, and net savings are calculated correctly
TEST(ReportBuild, ComputesTotalsAndNetSavings) {
    // creating categories
    QVector<Category> categories;
    categories.push_back(makeCategoryWithExpenses("Rent", 1000, {600}));
    categories.push_back(makeCategoryWithExpenses("Food", 500, {200}));

    // adding income sources
    QVector<MonthlyIncome> monthly;
    monthly.push_back(MonthlyIncome(1200, "Job", QDate(2025, 12, 1)));

    QVector<IrregularIncome> irregular;
    irregular.push_back(IrregularIncome(100, "Gift", QDate(2025, 12, 2), "birthday"));

    // building a report
    ReportSummary r = Report::build(categories, monthly, irregular);

    // expecting the total values to be calculated
    EXPECT_DOUBLE_EQ(r.totalIncome, 1300.0);
    EXPECT_DOUBLE_EQ(r.totalExpenses, 800.0);
    EXPECT_DOUBLE_EQ(r.netSavings, 500.0);
}

// method to test if the percentages and extremes are being calculated correctly
TEST(ReportBuild, ComputesPercentagesAndExtremes) {
    // populating the categories
    QVector<Category> categories;
    categories.push_back(makeCategoryWithExpenses("Rent", 1000, {600}));
    categories.push_back(makeCategoryWithExpenses("Food", 500, {200}));

    // arrays for incomes
    QVector<MonthlyIncome> monthly;
    QVector<IrregularIncome> irregular;

    // build report
    ReportSummary r = Report::build(categories, monthly, irregular);

    // testing the percentage by category
    EXPECT_NEAR(r.percentByCategory["Rent"], 75.0, 1e-9);
    EXPECT_NEAR(r.percentByCategory["Food"], 25.0, 1e-9);

    // checking to see if returned values are correct
    EXPECT_TRUE(r.extremes.hasData);
    EXPECT_EQ(r.extremes.highestCategory, "Rent");
    EXPECT_DOUBLE_EQ(r.extremes.highestAmount, 600.0);
    EXPECT_EQ(r.extremes.lowestCategory, "Food");
    EXPECT_DOUBLE_EQ(r.extremes.lowestAmount, 200.0);
}

// method to handle edge cases where the total expenses are 0 and there is division by 0
TEST(ReportBuild, HandlesZeroExpenses_NoDivideByZero) {
    // populating the data
    QVector<Category> categories;
    categories.push_back(makeCategoryWithExpenses("Rent", 1000, {}));
    categories.push_back(makeCategoryWithExpenses("Food", 500, {}));
    QVector<MonthlyIncome> monthly;
    monthly.push_back(MonthlyIncome(500, "Job", QDate(2025, 12, 1)));
    QVector<IrregularIncome> irregular;

    // report building
    ReportSummary r = Report::build(categories, monthly, irregular);

    // verify total expenses is 0 and savings = 500
    EXPECT_DOUBLE_EQ(r.totalExpenses, 0.0);
    EXPECT_DOUBLE_EQ(r.netSavings, 500.0);

    // percentage should be 0 when totalExpenses == 0
    EXPECT_DOUBLE_EQ(r.percentByCategory["Rent"], 0.0);
    EXPECT_DOUBLE_EQ(r.percentByCategory["Food"], 0.0);
}

#include <gtest/gtest.h>
#include <QDate>

#include "category.h"
#include "expense.h"

// verifying the initial state of the category once it is created
TEST(CategoryBasic, StartsEmptyWithZeroSpent) {
    Category c("Food", 500.0, 0.0);

    EXPECT_EQ(c.getExpenses().size(), 0);
    EXPECT_DOUBLE_EQ(c.getSpent(), 0.0);
}

// adding an expense to the category and checking the total spent got updated
TEST(CategoryAddExpense, AddSingleExpenseUpdatesSpent) {
    Category c("Food", 500.0, 0.0);

    Expense e(10.0, "Food", QDate(2025, 1, 1), "Snack");
    c.addExpense(e);

    EXPECT_EQ(c.getExpenses().size(), 1);
    EXPECT_DOUBLE_EQ(c.getSpent(), 10.0);
}

// adding multiple expenses to test the total spent
TEST(CategoryAddExpense, AddMultipleExpensesAccumulatesSpent) {
    Category c("Food", 500.0, 0.0);

    c.addExpense(Expense(10.0, "Food", QDate(2025, 1, 1), "Snack"));
    c.addExpense(Expense(20.0, "Food", QDate(2025, 1, 2), "Meal"));
    c.addExpense(Expense(5.0,  "Food", QDate(2025, 1, 3), "Coffee"));

    EXPECT_EQ(c.getExpenses().size(), 3);
    EXPECT_DOUBLE_EQ(c.getSpent(), 35.0);
}

// testing if removing the expenses updated the internal values
TEST(CategoryRemoveExpense, RemoveValidIndexUpdatesSpent) {
    Category c("Food", 500.0, 0.0);

    c.addExpense(Expense(10.0, "Food", QDate(2025, 1, 1), "Snack"));
    c.addExpense(Expense(20.0, "Food", QDate(2025, 1, 2), "Meal"));

    bool removed = c.removeExpenseAt(0);

    EXPECT_TRUE(removed);
    EXPECT_EQ(c.getExpenses().size(), 1);
    EXPECT_DOUBLE_EQ(c.getSpent(), 20.0);
}

// same as the last test but removing the only expense
TEST(CategoryRemoveExpense, RemoveLastExpenseResetsSpentToZero) {
    Category c("Food", 500.0, 0.0);

    c.addExpense(Expense(15.0, "Food", QDate(2025, 1, 1), "Lunch"));

    bool removed = c.removeExpenseAt(0);

    EXPECT_TRUE(removed);
    EXPECT_EQ(c.getExpenses().size(), 0);
    EXPECT_DOUBLE_EQ(c.getSpent(), 0.0);
}

// testing the edge cases
TEST(CategoryRemoveExpense, RemoveFromEmptyCategoryFails) {
    Category c("Food", 500.0, 0.0);

    EXPECT_FALSE(c.removeExpenseAt(0));
    EXPECT_FALSE(c.removeExpenseAt(-1));
}

// removing something that is out of the array range
TEST(CategoryRemoveExpense, RemoveOutOfRangeIndexFails) {
    Category c("Food", 500.0, 0.0);

    c.addExpense(Expense(10.0, "Food", QDate(2025, 1, 1), "Snack"));

    EXPECT_FALSE(c.removeExpenseAt(1));
    EXPECT_FALSE(c.removeExpenseAt(100));
}

// testing the getter methods to return expenses
TEST(CategoryExpenseAccess, ReturnsCorrectExpense) {
    Category c("Food", 500.0, 0.0);

    Expense e(12.5, "Food", QDate(2025, 1, 1), "Sandwich");
    c.addExpense(e);

    const Expense& stored = c.getExpenses().at(0);

    EXPECT_DOUBLE_EQ(stored.getAmount(), 12.5);
    EXPECT_EQ(stored.getCategory(), QString("Food"));
    EXPECT_EQ(stored.getDesc(), QString("Sandwich"));
}

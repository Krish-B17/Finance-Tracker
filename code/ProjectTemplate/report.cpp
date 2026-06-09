#include "report.h"
#include <QtGlobal> // used for qAbs
#include <QTextStream>

using namespace std;

// method ensures that any 2 values that you add are safe (they do not overflow past their range
static double safeAdd(double a, double b) {
    const double s = a + b;
    return (qAbs(s) < 1e-12) ? 0.0 : s;
}

// method to determine the highest and lowest spending category
static CategoryExtremes extremesFromTotals(const QMap<QString, double>& totals) {
    CategoryExtremes ex;
    if (totals.isEmpty()) return ex;

    bool first = true;
    // looping through the categories
    for (auto it = totals.constBegin(); it != totals.constEnd(); ++it) {
        const QString cat = it.key();
        const double amt = it.value();

        if (first) {
            ex.highestCategory = ex.lowestCategory = cat;
            ex.highestAmount = ex.lowestAmount = amt;
            first = false;
            continue;
        }
        // arithmetic to commpute the highest and lowest spending
        if (amt > ex.highestAmount) { ex.highestAmount = amt; ex.highestCategory = cat; }
        if (amt < ex.lowestAmount)  { ex.lowestAmount  = amt; ex.lowestCategory  = cat; }
    }

    ex.hasData = true;
    return ex;
}

// building the report, calling helper functions
ReportSummary Report::build(const QVector<Category>& categories,
                            const QVector<MonthlyIncome>& monthlyIncomes,
                            const QVector<IrregularIncome>& irregularIncomes) {
    ReportSummary r;

    // calculating the total income from monthly and irregular
    for (const auto& m : monthlyIncomes) {
        const double amt = m.getAmount();
        if (amt > 0.0) r.totalIncome = safeAdd(r.totalIncome, amt);
    }
    for (const auto& i : irregularIncomes) {
        const double amt = i.getAmount();
        if (amt > 0.0) r.totalIncome = safeAdd(r.totalIncome, amt);
    }

    // 2) populating the hashmap with the category names and total spent in each
    for (const auto& c : categories) {
        QString name = c.getName().trimmed();
        if (name.isEmpty()) name = "Uncategorized";

        const double spent = (c.getSpent() > 0.0) ? c.getSpent() : 0.0;

        r.expenseByCategory[name] = spent;
        r.totalExpenses = safeAdd(r.totalExpenses, spent);
    }

    // calculating the net savings
    r.netSavings = r.totalIncome - r.totalExpenses;

    // calculating the percentage of spending from each category to total spending
    if (r.totalExpenses <= 0.0) {
        for (auto it = r.expenseByCategory.constBegin(); it != r.expenseByCategory.constEnd(); ++it) {
            r.percentByCategory[it.key()] = 0.0;
        }
    } else {
        for (auto it = r.expenseByCategory.constBegin(); it != r.expenseByCategory.constEnd(); ++it) {
            r.percentByCategory[it.key()] = (it.value() / r.totalExpenses) * 100.0;
        }
    }

    // 5) getting the highest and lowest spending
    r.extremes = extremesFromTotals(r.expenseByCategory);

    return r;
}


void printReport(const ReportSummary& r) {

    //extern QTextStream qout;
    //QTextStream qout(stdout);

    // Create a text stream bound to stdout for this function only
    QTextStream qout(stdout);

    qout << "\n========== FINANCIAL REPORT ==========\n\n";

    // initial summary
    qout << "Total Income   : $" << r.totalIncome << "\n";
    qout << "Total Expenses : $" << r.totalExpenses << "\n";
    qout << "Net Savings    : $";

    if (r.netSavings >= 0)
        qout << r.netSavings << " (surplus)\n\n";
    else
        qout << r.netSavings << " (deficit)\n\n";

    // breaking down expenses by category
    qout << "Expense Breakdown by Category:\n";

    if (r.expenseByCategory.isEmpty()) {
        qout << "  No expenses recorded.\n";
    } else {
        for (auto it = r.expenseByCategory.constBegin();
             it != r.expenseByCategory.constEnd(); ++it) {

            const QString& name = it.key();
            const double   spent = it.value();
            const double   pct   = r.percentByCategory.value(name, 0.0);

            qout << "  - " << name
                 << ": $" << spent
                 << " (" << pct << "%)\n";
        }
    }

    qout << "\n";

    // printing the highest and lowest spending categories
    if (r.extremes.hasData) {
        qout << "Highest Spending Category : "
             << r.extremes.highestCategory
             << " ($" << r.extremes.highestAmount << ")\n";

        qout << "Lowest Spending Category  : "
             << r.extremes.lowestCategory
             << " ($" << r.extremes.lowestAmount << ")\n";
    } else {
        qout << "No category data available.\n";
    }

    qout << "\n======================================\n\n";
    qout.flush();
}


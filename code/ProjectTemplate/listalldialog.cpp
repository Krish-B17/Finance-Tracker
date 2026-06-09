#include "listalldialog.h"
#include "ui_listalldialog.h"

#include <algorithm>  // std::sort

ListAllDialog::ListAllDialog(const Profile &profile,
                             const QVector<Category> &categories,
                             const QVector<Expense> &expenses,
                             const QVector<MonthlyIncome> &monthlyIncomes,
                             const QVector<IrregularIncome> &irregularIncomes,
                             QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ListAllDialog)
{
    ui->setupUi(this);
    setWindowTitle("Finance Overview");

    ui->summaryTextEdit->setReadOnly(true);

    // build the big text blob
    const QString text = buildSummaryText(profile,
                                          categories,
                                          expenses,
                                          monthlyIncomes,
                                          irregularIncomes);
    ui->summaryTextEdit->setHtml(text);

    // Close button just closes the dialog
    connect(ui->closeButton, &QPushButton::clicked,
            this, &QDialog::accept);
}

ListAllDialog::~ListAllDialog()
{
    delete ui;
}

QString ListAllDialog::money(double v)
{
    return QString("$%1").arg(v, 0, 'f', 2);
}

QString ListAllDialog::buildSummaryText(const Profile &profile,
                                        const QVector<Category> &categories,
                                        const QVector<Expense> &expenses,
                                        const QVector<MonthlyIncome> &monthlyIncomes,
                                        const QVector<IrregularIncome> &irregularIncomes) const
{
    QString out;

    // --- Profile ---
    out += "<h2 align='center'>Profile</h2>";
    out += "Name: " + profile.getName() + "<br>";
    out += "Age: " + QString::number(profile.getAge()) + "<br>";
    out += "Monthly Budget: " + money(profile.getMonthlyBudget()) + "<br>";
    out += "Saving Goal: &nbsp;" + money(profile.getSavingGoal()) + "<br>";
    out += "Password Protected: ";
    out += profile.isPasswordProtected() ? "Yes<br><br>" : "No<br><br>";

    // --- Categories ---
    out += "<h2 align='center'>Categories</h2>";
    if (categories.isEmpty()) {
        out += "(none)<br><br>";
    } else {
        for (const auto &c : categories) {
            out += "• " + c.getName()
                + " | Budget "    + money(c.getBudgetLimit())
                + " | Spent "     + money(c.getSpent())
                + " | Remaining " + money(c.getBudgetLimit() - c.getSpent())
                + "<br>";
        }
        out += "<br>";
    }

    // --- All Expenses (sorted by date) ---
    out += "<h2 align='center'>All Expenses</h2>";
    if (expenses.isEmpty()) {
        out += "(none)<br><br>";
    } else {
        QVector<Expense> sorted = expenses;   // copy then sort
        std::sort(sorted.begin(), sorted.end(),
                  [](const Expense &a, const Expense &b){
                      if (a.getDate() != b.getDate())
                          return a.getDate() < b.getDate();
                      if (a.getCategory() != b.getCategory())
                          return a.getCategory() < b.getCategory();
                      return a.getAmount() < b.getAmount();
                  });

        for (const auto &e : sorted) {
            out += "  " + e.getDate().toString(Qt::ISODate)
            + "  [" + e.getCategory() + "]  "
                + money(e.getAmount())
                + "  " + e.getDesc() + "<br>";
        }
        out += "<br>";
    }

    // --- Monthly Incomes ---
    out += "<h2 align='center'>Monthly Income</h2>";
    if (monthlyIncomes.isEmpty()) {
        out += "(none)<br><br>";
    } else {
        for (const auto &m : monthlyIncomes) {
            out += "  " + m.getDate().toString(Qt::ISODate)
            + "  " + money(m.getAmount())
                + "  " + m.getSource() + "<br>";
        }
        out += "<br>";
    }

    // --- Irregular Incomes ---
    out += "<h2 align='center'>Irregular Incomes</h2>";
    if (irregularIncomes.isEmpty()) {
        out += "(none)<br>";
    } else {
        for (const auto &r : irregularIncomes) {
            out += "  " + r.getDate().toString(Qt::ISODate)
            + "  " + money(r.getAmount())
                + "  " + r.getSource()
                + "  (" + r.getDescription() + ")<br>";
        }
    }

    return out;
}

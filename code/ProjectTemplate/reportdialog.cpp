#include "reportdialog.h"
#include "ui_reportdialog.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QPainter>
#include <QFont>
#include <QTextStream>

ReportDialog::ReportDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReportDialog)
{
    ui->setupUi(this);
    setWindowTitle("Financial Report");

    // Monospace-ish font for the text area (applied via CSS too)
    QFont monoFont("Monospace");
    monoFont.setStyleHint(QFont::TypeWriter);
    ui->plainTextReport->setFont(monoFont);
}

ReportDialog::~ReportDialog()
{
    delete ui;
}

void ReportDialog::setData(const Profile &profile,
                           const ReportSummary &summary)
{
    // 1) Fill the text area with rich HTML
    ui->plainTextReport->setHtml(buildReportText(profile, summary));

    // 2) Build the pie chart
    buildChart(summary);
}

// This is the report build out. A lot of this is in HTML to ensure that the report looks good.

QString ReportDialog::buildReportText(const Profile &profile,
                                      const ReportSummary &r) const
{
    QString html;
    QTextStream ts(&html);

    ts << "<html><head><style>"
       << "body { background-color:#000000; color:#FFFFFF; "
          "font-family:'Courier New',monospace; }"
       << ".sectionTitle { text-align:center; font-weight:bold; "
          "font-size:22px; margin-top:20px; margin-bottom:10px; }"
       << ".subTitle { text-align:center; font-weight:bold; "
          "font-size:18px; margin-top:18px; margin-bottom:6px; }"
       << ".line { font-size:16px; }"
       << "</style></head><body>";

    // ---- Profile section ----
    ts << "<div class='subTitle'>Profile</div>";
    ts << "<div class='line'>Name: " << profile.getName() << "</div>";
    ts << "<div class='line'>Age: " << profile.getAge() << "</div>";
    ts << "<div class='line'>Monthly Budget: $"
       << profile.getMonthlyBudget() << "</div>";
    ts << "<div class='line'>Saving Goal:   $"
       << profile.getSavingGoal() << "</div>";
    ts << "<div class='line'>Password Protected: "
       << (profile.isPasswordProtected() ? "Yes" : "No")
       << "</div>";

    // ---- Big FINANCIAL REPORT title ----
    ts << "<div class='subTitle'>Financial Report</div>";

    // ---- Totals ----
    ts << "<div class='line'>Total Income   : $"
       << r.totalIncome << "</div>";
    ts << "<div class='line'>Total Expenses : $"
       << r.totalExpenses << "</div>";

    ts << "<div class='line'>Net Savings    : $"
       << r.netSavings
       << (r.netSavings >= 0.0 ? " (surplus)" : " (deficit)")
       << "</div>";

    // ---- Expense breakdown ----
    ts << "<div class='subTitle'>Expense Breakdown by Category</div>";

    if (r.expenseByCategory.isEmpty()) {
        ts << "<div class='line'>No expenses recorded.</div>";
    } else {
        ts << "<ul>";
        for (auto it = r.expenseByCategory.constBegin();
             it != r.expenseByCategory.constEnd(); ++it) {

            const QString &name  = it.key();
            const double   spent = it.value();
            const double   pct   = r.percentByCategory.value(name, 0.0);

            ts << "<li class='line'>" << name
               << ": $" << spent
               << " (" << pct << "%)</li>";
        }
        ts << "</ul>";
    }

    // ---- Extremes ----
    ts << "<div class='subTitle'>Spending Extremes</div>";
    if (r.extremes.hasData) {
        ts << "<div class='line'>Highest Spending Category : "
           << r.extremes.highestCategory
           << " ($" << r.extremes.highestAmount << ")</div>";

        ts << "<div class='line'>Lowest Spending Category  : "
           << r.extremes.lowestCategory
           << " ($" << r.extremes.lowestAmount << ")</div>";
    } else {
        ts << "<div class='line'>No category data available.</div>";
    }

    ts.flush();
    return html;
}

// The code below is for the pie chart. I am ensuring that the pie chart is visible for the user to see their expenses properly.

void ReportDialog::buildChart(const ReportSummary &r)
{
    // Create the pie series from expense totals
    auto *series = new QPieSeries(this);

    for (auto it = r.expenseByCategory.constBegin();
         it != r.expenseByCategory.constEnd(); ++it) {
        const QString &name  = it.key();
        const double   spent = it.value();
        if (spent <= 0.0)
            continue;
        series->append(name, spent);
    }

    // Clear chart if nothing to show
    if (series->slices().isEmpty()) {
        if (auto *layout = ui->chartContainer->layout()) {
            QLayoutItem *item;
            while ((item = layout->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
        }
        return;
    }

    // Make the pie itself large inside the chart
    series->setPieSize(0.80);          // 80% of chart radius

    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Expense Breakdown by Category");
    chart->legend()->setAlignment(Qt::AlignRight);

    // Reduce margins so the pie fills more of the view
    chart->setMargins(QMargins(5, 5, 5, 5));
    chart->setBackgroundRoundness(0);

    auto *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(320, 190);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Put the chart view into the container's layout
    QLayout *layout = ui->chartContainer->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->chartContainer);
        ui->chartContainer->setLayout(layout);
    }

    // Remove any previous chart widgets
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    layout->addWidget(chartView);
}


void ReportDialog::on_btnClose_clicked()
{
    accept();   // closes dialog and returns to MainWindow
}

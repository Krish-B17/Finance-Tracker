#ifndef REPORT_H
#define REPORT_H

// data types used for data storage for the report
#include <QString>
#include <QVector>
#include <QMap>

// header files to use for the calculations
#include "category.h"
#include "MonthlyIncome.h"
#include "irregularincome.h"

// struct to store the highest and lowest spending categories with the amount
struct CategoryExtremes {
    QString highestCategory;
    double highestAmount = 0.0;

    QString lowestCategory;
    double lowestAmount = 0.0;

    bool hasData = false;
};

// struct holding data about the report
struct ReportSummary {
    // summarized data from the app
    double totalIncome = 0.0;
    double totalExpenses = 0.0;
    double netSavings = 0.0;

    // hashmaps for the total expense of each category and the percentage of total spendings
    QMap<QString, double> expenseByCategory;
    QMap<QString, double> percentByCategory;

    CategoryExtremes extremes;
};

class Report {
public:
    // method to build the report based on the array of categories, monthly income, and irregular income
    static ReportSummary build(const QVector<Category>& categories, const QVector<MonthlyIncome>& monthlyIncomes, const QVector<IrregularIncome>& irregularIncomes);

};

// method to print the report to the terminal
void printReport(const ReportSummary& r);
#endif

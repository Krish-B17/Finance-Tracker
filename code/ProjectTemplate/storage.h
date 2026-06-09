#ifndef STORAGE_H
#define STORAGE_H

#include <QString>
#include <QVector>
#include <QDate>

#include "profile.h"
#include "category.h"
#include "expense.h"
#include "MonthlyIncome.h"
#include "irregularincome.h"

class Storage
{
public:
    // method to save all the data
    static bool saveAll(const QString& filePath, const Profile& profile, const QVector<Category>& categories, const QVector<Expense>& expenses, const QVector<MonthlyIncome>& monthlyIncomes, const QVector<IrregularIncome>& irregularIncomes);

    // method to laod all the data
    static bool loadAll(const QString& filePath, Profile& profileOut, QVector<Category>& categoriesOut, QVector<Expense>& expensesOut, QVector<MonthlyIncome>& monthlyIncomesOut, QVector<IrregularIncome>& irregularIncomesOut);
};

#endif // STORAGE_H

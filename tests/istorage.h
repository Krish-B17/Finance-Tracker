#ifndef ISTORAGE_H
#define ISTORAGE_H

#include <QString>
#include <QVector>

#include "profile.h"
#include "category.h"
#include "expense.h"
#include "monthlyincome.h"
#include "irregularincome.h"

// interface that is used ONLY for testing (GoogleMock)
class IStorage {
public:
    // virtual constructor
    virtual ~IStorage() = default;

    // saves all data to the given file path
    virtual bool saveAll(const QString& filePath,
                         const Profile& profile,
                         const QVector<Category>& categories,
                         const QVector<Expense>& expenses,
                         const QVector<MonthlyIncome>& monthlyIncomes,
                         const QVector<IrregularIncome>& irregularIncomes) = 0;

    // loads all data from the given file path as long as it exists
    virtual bool loadAll(const QString& filePath,
                         Profile& profileOut,
                         QVector<Category>& categoriesOut,
                         QVector<Expense>& expensesOut,
                         QVector<MonthlyIncome>& monthlyIncomesOut,
                         QVector<IrregularIncome>& irregularIncomesOut) = 0;
};

#endif // ISTORAGE_H

#ifndef MOCK_STORAGE_H
#define MOCK_STORAGE_H

#include <gmock/gmock.h>
#include "istorage.h"

// GoogleMock class used to verify EXPECT_CALL behaviour
class MockStorage : public IStorage {
public:
    // mock version of saveall to check the return value and confirm the function works properly
    MOCK_METHOD(bool, saveAll,
                (const QString&,
                 const Profile&,
                 const QVector<Category>&,
                 const QVector<Expense>&,
                 const QVector<MonthlyIncome>&,
                 const QVector<IrregularIncome>&),
                (override));

    // mock version of load all to check the return value and confirm the functio works properly
    MOCK_METHOD(bool, loadAll,
                (const QString&,
                 Profile&,
                 QVector<Category>&,
                 QVector<Expense>&,
                 QVector<MonthlyIncome>&,
                 QVector<IrregularIncome>&),
                (override));
};

#endif // MOCK_STORAGE_H

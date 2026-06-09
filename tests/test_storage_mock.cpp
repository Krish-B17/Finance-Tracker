#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QString>
#include <QVector>

#include "mock_storage.h"
#include "appservice.h"

using ::testing::_;
using ::testing::Return;
// testing if the save all method works correctly
TEST(StorageMock, SaveCallsStorageOnceAndReturnsTrue) {
    MockStorage mock;
    AppService service(mock);

    // creating data for the test
    Profile profile("Krish", 20, false, "", 0.0, 0.0);
    QVector<Category> categories;
    QVector<Expense> expenses;
    QVector<MonthlyIncome> monthly;
    QVector<IrregularIncome> irregular;

    // file name
    QString path = "data.json";

    // testing the method
    EXPECT_CALL(mock, saveAll(path, _, _, _, _, _)).Times(1).WillOnce(Return(true));

    // outputting if this works
    EXPECT_TRUE(service.save(path, profile, categories, expenses, monthly, irregular));
}

// testing if the storage method returns false if the storage fails
TEST(StorageMock, SavePropagatesFailure) {
    MockStorage mock;
    AppService service(mock);

    // creating data
    Profile profile("Krish", 20, false, "", 0.0, 0.0);
    QVector<Category> categories;
    QVector<Expense> expenses;
    QVector<MonthlyIncome> monthly;
    QVector<IrregularIncome> irregular;

    QString path = "data.json";

    // attempting to save the data
    EXPECT_CALL(mock, saveAll(path, _, _, _, _, _)).Times(1).WillOnce(Return(false));

    // expecting false when attempting to store
    EXPECT_FALSE(service.save(path, profile, categories, expenses, monthly, irregular));
}

// testing if the loadAll method works correctly
TEST(StorageMock, LoadCallsStorageOnceAndReturnsTrue) {
    MockStorage mock;
    AppService service(mock);

    // declaring variables to store data
    Profile profile;
    QVector<Category> categories;
    QVector<Expense> expenses;
    QVector<MonthlyIncome> monthly;
    QVector<IrregularIncome> irregular;

    QString path = "data.json";

    // attempting to load the values
    EXPECT_CALL(mock, loadAll(path, _, _, _, _, _)).Times(1).WillOnce(Return(true));

    // expecting the load to work and return true
    EXPECT_TRUE(service.load(path, profile, categories, expenses, monthly, irregular));
}

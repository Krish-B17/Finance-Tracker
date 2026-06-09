#ifndef APPSERVICE_H
#define APPSERVICE_H

#include "istorage.h"

// used for testing only to replace real storage with a mock while testing
class AppService {
    IStorage& storage;

public:
    // constructor with the storage dependency
    explicit AppService(IStorage& s) : storage(s) {}

    //calls the save all to save the data to json file
    bool save(const QString& path,
              const Profile& profile,
              const QVector<Category>& categories,
              const QVector<Expense>& expenses,
              const QVector<MonthlyIncome>& monthlyIncomes,
              const QVector<IrregularIncome>& irregularIncomes) {
        return storage.saveAll(path, profile, categories, expenses,
                               monthlyIncomes, irregularIncomes);
    }

    // calls the load to load all the data from json file
    bool load(const QString& path,
              Profile& profile,
              QVector<Category>& categories,
              QVector<Expense>& expenses,
              QVector<MonthlyIncome>& monthlyIncomes,
              QVector<IrregularIncome>& irregularIncomes) {
        return storage.loadAll(path, profile, categories, expenses,
                               monthlyIncomes, irregularIncomes);
    }
};

#endif // APPSERVICE_H

#ifndef MONTHLYINCOME_H
#define MONTHLYINCOME_H

#include "income.h"
#include <QString>
#include <QDate>

// child class of income
class MonthlyIncome : public income {
public:
    // constructor
    MonthlyIncome(double amt, QString src, QDate d);

    // abstraction used here
    void printSummary() const override;
};

#endif

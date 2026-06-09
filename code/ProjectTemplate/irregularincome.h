#ifndef IRREGULARINCOME_H
#define IRREGULARINCOME_H

#include "income.h"
#include <QString>
#include <QDate>

// this class is a child class of income
class IrregularIncome : public income
{
private:
    // description for the irregular income
    QString description;
public:
    // constructor
    IrregularIncome(double amt, QString src, QDate dateReceived, const QString &desc);

    // getter
    QString getDescription() const;

    // printing the details of the expense
    void printSummary() const override;
};

#endif // IRREGULARINCOME_H

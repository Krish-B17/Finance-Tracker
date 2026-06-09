#ifndef EXPENSE_H
#define EXPENSE_H

#include <QString>
#include <QDate>

class Expense
{
private:
    // all the class member variables
    double amount;
    QString category;
    QDate date;
    QString description;
public:
    // getters for the expense and the constructor
    Expense(double amt, QString cat, QDate date, QString desc);
    double getAmount() const;
    QString getCategory() const;
    QDate getDate() const;
    QString getDesc() const;
};

#endif // EXPENSE_H

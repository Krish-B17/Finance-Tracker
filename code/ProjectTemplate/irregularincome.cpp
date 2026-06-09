#include "irregularincome.h"
#include <iostream>
using namespace std;
#include <QString>
#include <QDate>

// constructor
IrregularIncome::IrregularIncome(double amt, QString src, QDate d, const QString &desc) : income(amt, src, d) {
    description = desc;
}

// getter
QString IrregularIncome::getDescription() const{
    return description;
}

// abstraction + polymorphism: each child that inherits the income class has its own print summary method
void IrregularIncome::printSummary() const {
    cout << "[Irregular Income] " << source.toStdString() << " (" << description.toStdString()
         << ") - $" << amount << " received on " << date.toString("yyyy-MM-dd").toStdString() << endl;
}

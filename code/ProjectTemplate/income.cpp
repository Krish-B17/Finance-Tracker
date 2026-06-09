#include "income.h"
#include <iostream>
#include <QString>
#include <QDate>
using namespace std;

// Constructor for income object. Initializes fields using values passed to the constructor
income::income(double amt, QString src, QDate dateReceived) {
    amount = amt;          // store income amount
    source = src;          // store name/description of income source
    date = dateReceived;   // store date income was received
}

// Getter: return stored income amount
double income::getAmount() const {
    return amount;
}

// Getter: return income source text
QString income::getSource() const {
    return source;
}

// Getter: return date income was received
QDate income::getDate() const {
    return date;
}

// Setter: update income amount
void income::setAmount(double amt) {
    amount = amt;
}

// Setter: update income source text
void income::setSource(const QString &src) {
    source = src;
}

// Setter: update date income was received
void income::setDate(const QDate &d) {
    date = d;
}

// printing a basic summary of the income sources
void income::printSummary() const {
    cout << "Source: " << source.toStdString() << ", Amount: $" << amount << endl;
}

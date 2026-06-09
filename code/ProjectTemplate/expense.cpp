#include "expense.h"
using namespace std;

// Constructor for Expense. Initializes expense object with the given values
Expense::Expense(double amt, QString cat, QDate dateSpent, QString desc) {
    amount = amt;        // store the amount spent
    category = cat;      // category the expense belongs to
    date = dateSpent;    // date when this expense occurred
    description = desc;  // optional text description
}

// Getter: return the numeric amount of the expense
double Expense::getAmount() const {
    return amount;
}

// Getter: return the category for this expense
QString Expense::getCategory() const {
    return category;
}

// Getter: return the date this expense was recorded
QDate Expense::getDate() const {
    return date;
}

// Getter: return the description or notes attached to this expense
QString Expense::getDesc() const {
    return description;
}

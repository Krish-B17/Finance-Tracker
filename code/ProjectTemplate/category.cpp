#include "category.h"
#include "expense.h"
#include <iostream>
using namespace std;

// constructor
Category::Category(QString nameInput, double limit, double spent) {
    name = nameInput;
    budgetLimit = limit;
    totalSpent = spent;
}

// getters
QString Category::getName() const{
    return name;
}

double Category::getBudgetLimit() const{
    return budgetLimit;
}

double Category::getSpent() const{
    return totalSpent;
}

const QVector<Expense> &Category::getExpenses() const
{
    return expenses;
}

// updating the budget (setters)
void Category::updateBudget(double newBudget){
    budgetLimit = newBudget;
}

void Category::updateSpent(double newSpent){
    totalSpent = newSpent;
}

// adding an expense and sorting the list so expenses are ordered by date inccurred
void Category::addExpense(const Expense& e)
{
    expenses.push_back(e);

    // making sure the total spent is accurate
    recomputeSpent();

    // sorting by date
    sort(expenses.begin(), expenses.end(),
         [](const Expense& a, const Expense& b){
             if (a.getDate() != b.getDate())
                 return a.getDate() < b.getDate();
             return a.getAmount() < b.getAmount();
         });
}

// removing an expense
bool Category::removeExpenseAt(int index)
{
    // verifying the index is correct
    if (index < 0 || index >= expenses.size()) return false;

    expenses.removeAt(index);

    // recomputing the spent amount
    recomputeSpent();
    return true;
}

// clearing all expenses
void Category::clearExpenses()
{
    expenses.clear();
    totalSpent = 0.0;
}

// print all expenses in this category
void Category::listExpenses() const {
    std::cout << "Expenses for category: " << name.toStdString() << "\n";
    for (const auto& e : expenses) {
        std::cout << "- $" << e.getAmount()
        << " on " << e.getDate().toString("yyyy-MM-dd").toStdString()
        << " | "  << e.getDesc().toStdString()
        << "\n";
    }
    std::cout << "Total spent: $" << totalSpent << "\n\n";
}

// method to recompute the total amount spent based on the expenses in the category
void Category::recomputeSpent()
{
    double sum = 0.0;
    for (const auto& e : expenses)
        if (e.getCategory() == name)
            sum += e.getAmount();
    totalSpent = sum;
}

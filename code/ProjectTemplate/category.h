#ifndef CATEGORY_H
#define CATEGORY_H
#include <QString>
#include <QVector>
class Expense;

class Category
{
private:
    // member variables
    QString name;
    double budgetLimit;
    double totalSpent;
    QVector<Expense> expenses;

    // private method used to keep track of the total spent and remaining budget
    void recomputeSpent();

public:
    // constructor
    Category(QString nameInput, double limit, double spent);

    // getters
    QString getName() const;
    double getBudgetLimit() const;
    double getSpent() const;

    const QVector<Expense> &getExpenses() const;

    // update functions, kind of like setters
    void updateBudget(double newBudget);
    void updateSpent(double newSpent);

    // methods to perform operations on the expenses in each category
    void addExpense(const Expense& e);
    bool removeExpenseAt(int index);
    void clearExpenses();
    void listExpenses() const;
};

#endif // CATEGORY_H

#ifndef INCOME_H
#define INCOME_H
#include <QString>
#include <QDate>
using namespace std;

class income
{
protected:
    double amount;
    QString source;
    QDate date;

public:
    // constructor and destructor
    income(double amt, QString src, QDate d);
    virtual ~income() {}

    // getters and setters
    double getAmount() const;
    QString getSource() const;
    QDate getDate() const;

    void setAmount(double amt);
    void setSource(const QString &src);
    void setDate(const QDate &d);

    // Abstraction + Polymorphism, this is a virtual method and every child of this class will have to make its own print summary method
    virtual void printSummary() const;
};

#endif // INCOME_H

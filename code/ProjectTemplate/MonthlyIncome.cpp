#include "MonthlyIncome.h"
#include <iostream>
using namespace std;

// constuctor calls the income constructor
MonthlyIncome::MonthlyIncome(double amt, QString src, QDate d) : income(amt, src, d) {}

// printing the details of the monthly income
void MonthlyIncome::printSummary() const {
    cout <<"Monthly Income from "<< source.toStdString() << " is $"<< amount<<"."<<endl;
}

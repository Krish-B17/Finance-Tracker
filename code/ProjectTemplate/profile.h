#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
class Profile
{
private:
    // private member variables in the class
    QString name;
    int age;
    bool passwordEnabled;
    QString passwordHash;
    double  monthlyBudget;
    double savingGoal;

    // private method to encrypt the password
    static QString hashPassword(const QString& pass);

public:

    // default constructor used when loading the data from a file
    Profile() = default;
    // constructor used when loading the data from user inputs
    Profile(QString userName, int userAge, bool passwordProtected, QString password, double budgetMonth, double goal);

    // getters
    QString getName() const;
    int getAge() const;
    double getMonthlyBudget() const;
    double getSavingGoal() const;
    bool isPasswordProtected() const;
    QString getPassHash() const;

    // setters
    void setName(const QString& n);
    void setAge(int a);
    void setMonthlyBudget(double b);
    void setSavingGoal(double g);
    void togglePasswordProtect(bool update);
    void changePassword(QString pass);
    static Profile fromStore(QString userName, int userAge, bool passwordProtected, QString password, double budgetMonth, double goal);

    // methods to check the password and verify if the user profile is valid
    bool verifyPassword(const QString& pass) const;
    bool isValid() const;
};

#endif // PROFILE_H

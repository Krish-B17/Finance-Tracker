#include "profile.h"
#include <QCryptographicHash>

// method to encrypt the password for safety
QString Profile::hashPassword(const QString& pass) {
    return QString::fromLatin1(QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex());
}

// constructor to create the user profile initially
Profile::Profile(QString userName, int userAge, bool passwordProtected, QString password, double budgetMonth, double goal) {
    name = userName;
    age = userAge;
    passwordEnabled = passwordProtected;
    passwordHash = hashPassword(password);
    monthlyBudget = budgetMonth;
    savingGoal = goal;
}

// getters
QString Profile::getName() const {
    return name;
}

int Profile::getAge() const {
    return age;
}

double Profile::getMonthlyBudget() const {
    return monthlyBudget;
}

double Profile::getSavingGoal() const {
    return savingGoal;
}

bool Profile::isPasswordProtected() const{
    return passwordEnabled;
}

QString Profile::getPassHash() const{
    return passwordHash;
}

// setters
void Profile::setName(const QString &n) {
    name = n;
}

void Profile::setAge(int a) {
    age = a;
}

void Profile::setMonthlyBudget(double b) {
    monthlyBudget = b;
}

void Profile::setSavingGoal(double g) {
    savingGoal = g;
}

void Profile::togglePasswordProtect(bool toggle){
    passwordEnabled = toggle;
}

void Profile::changePassword(QString pass){
    passwordHash = hashPassword(pass);
}

// verifying the password
bool Profile::verifyPassword(const QString& pass) const {
    if (!passwordEnabled) return true; // password protect is off
    return hashPassword(pass) == passwordHash;
}

// this method works like the constructor but does not rehash the password because that would cause it change the password
Profile Profile::fromStore(QString userName, int userAge, bool passwordProtected, QString password, double budgetMonth, double goal)
{
    Profile p;
    p.name = userName;
    p.age = userAge;
    p.passwordEnabled = passwordProtected;

    // password would already be hashed so no need to rehash it
    p.passwordHash = password;
    p.monthlyBudget = budgetMonth;
    p.savingGoal = goal;
    return p;
}
// checking if the profile is valid
bool Profile::isValid() const {
    return !name.trimmed().isEmpty() && age >= 0;
}

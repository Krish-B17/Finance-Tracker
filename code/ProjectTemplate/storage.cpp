#include "storage.h"
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QSaveFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;

// converting the fields to a json object using getters
static QJsonObject toJson(const Profile& p) {
    QJsonObject o;
    o["name"] = p.getName();
    o["age"] = p.getAge();
    o["passwordEnabled"] = p.isPasswordProtected();
    o["passwordHash"] = p.getPassHash();
    o["monthlyBudget"] = p.getMonthlyBudget();
    o["savingGoal"] = p.getSavingGoal();
    return o;
}

// populating a profile from the json object but not using the constructor to avoid rehashing the hashed password
static bool fromJson(const QJsonObject& o, Profile& p) {
    if (!o.contains("name") || !o.contains("age")) return false;

    const QString name = o.value("name").toString();
    const int age = o.value("age").toInt();
    const bool prot = o.value("passwordEnabled").toBool(false);
    const QString hash = o.value("passwordHash").toString();
    const double mb = o.value("monthlyBudget").toDouble(0.0);
    const double goal = o.value("savingGoal").toDouble(0.0);

    p = Profile::fromStore(name, age, prot, hash, mb, goal);
    return p.isValid();
}

// convert category to json object
static QJsonObject toJson(const Category& c) {
    QJsonObject o;
    o["name"] = c.getName();
    o["budgetLimit"] = c.getBudgetLimit();
    o["totalSpent"] = c.getSpent();
    return o;
}

// going from the json object and setting up the categories
static Category fromJsonCategory(const QJsonObject &o) {
    const QString name = o.value("name").toString();
    const double limit = o.value("budgetLimit").toDouble(0.0);
    const double spent = o.value("totalSpent").toDouble(0.0);
    return Category(name, limit, spent);
}

// converting the expenses to a json object and storing the date in the correct format
static QJsonObject toJson(const Expense& e) {
    QJsonObject o;
    o["amount"] = e.getAmount();
    o["category"] = e.getCategory();
    o["date"] = e.getDate().toString(Qt::ISODate); // YYYY-MM-DD
    o["desc"] = e.getDesc();
    return o;
}

// converting from json object to expenses and calling the constructor to create the objects
static Expense fromJsonExpense(const QJsonObject& o) {
    const double amt = o.value("amount").toDouble(0.0);
    const QString cat = o.value("category").toString();
    const QDate date = QDate::fromString(o.value("date").toString(), Qt::ISODate);
    const QString d = o.value("desc").toString();
    return Expense(amt, cat, date.isValid() ? date : QDate::currentDate(), d);
}

// converting monthly income to json object
static QJsonObject toJson(const MonthlyIncome& m) {
    QJsonObject o;
    o["amount"] = m.getAmount();
    o["source"] = m.getSource();
    o["date"]   = m.getDate().toString(Qt::ISODate);
    return o;
}

// converting json object to monthly income
static MonthlyIncome fromJsonMonthlyIncome(const QJsonObject& o) {
    const double  amt = o.value("amount").toDouble(0.0);
    const QString src = o.value("source").toString();
    const QDate   dt  = QDate::fromString(o.value("date").toString(), Qt::ISODate);
    return MonthlyIncome(amt, src, dt.isValid() ? dt : QDate::currentDate());
}

// converting irregular incoem to json object
static QJsonObject toJson(const IrregularIncome& r) {
    QJsonObject o;
    o["amount"]      = r.getAmount();
    o["source"]      = r.getSource();
    o["date"]        = r.getDate().toString(Qt::ISODate);
    o["description"] = r.getDescription();
    return o;
}

// converting json object to irregular income object
static IrregularIncome fromJsonIrregularIncome(const QJsonObject& o) {
    const double  amt  = o.value("amount").toDouble(0.0);
    const QString src  = o.value("source").toString();
    const QDate   dt   = QDate::fromString(o.value("date").toString(), Qt::ISODate);
    const QString desc = o.value("description").toString();
    return IrregularIncome(amt, src, dt.isValid() ? dt : QDate::currentDate(), desc);
}


// method to save all data into a single json file
bool Storage::saveAll(const QString& filePath, const Profile& profile, const QVector<Category>& categories, const QVector<Expense>& expenses, const QVector<MonthlyIncome>& monthlyIncomes, const QVector<IrregularIncome>& irregularIncomes)
{
    QJsonObject root;

    // profile save
    root["profile"] = toJson(profile);

    // categories saved
    {
        QJsonArray arr;
        for (const Category& c : categories) {
            arr.append(toJson(c));
        }
        root["categories"] = arr;
    }

    // expenses saved
    {
        QJsonArray arr;
        for (const Expense& e : expenses) {
            arr.append(toJson(e));
        }
        root["expenses"] = arr;
    }

    // monthly incomes saved
    {
        QJsonArray arr;
        for (const MonthlyIncome& m : monthlyIncomes) {
            arr.append(toJson(m));
        }
        root["monthlyIncomes"] = arr;
    }

    // irregular incomes saved
    {
        QJsonArray arr;
        for (const IrregularIncome& r : irregularIncomes) {
            arr.append(toJson(r));
        }
        root["irregularIncomes"] = arr;
    }

    const QJsonDocument doc(root);

    // ensuring the target directory exists
    QFileInfo fi(filePath);
    QDir dir = fi.dir();
    if (!dir.exists() && !dir.mkpath(".")) {
        return false;
    }

    // writing to a temp file then committing the changes
    QSaveFile out(filePath);
    if (!out.open(QIODevice::WriteOnly)) return false;
    out.write(doc.toJson(QJsonDocument::Indented));
    return out.commit();
}

// method to load all the data from the json file, using temp variables to avoid any data inconsistencies if an error occurrs while loading the data
bool Storage::loadAll(const QString& filePath,
                      Profile& profileOut,
                      QVector<Category>& categoriesOut,
                      QVector<Expense>& expensesOut,
                      QVector<MonthlyIncome>& monthlyIncomesOut,
                      QVector<IrregularIncome>& irregularIncomesOut)
{
    QFile f(filePath);
    // if the file doesn't exist, the program starts from the new user state
    if (!f.exists()) return false;
    if (!f.open(QIODevice::ReadOnly)) return false;

    const QByteArray data = f.readAll();
    f.close();

    const QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return false;
    const QJsonObject root = doc.object();

    // Use temporaries; assign to outputs only on full success
    Profile tmpProfile = profileOut;
    QVector<Category>        tmpCats;
    QVector<Expense>         tmpExps;
    QVector<MonthlyIncome>   tmpMonthly;
    QVector<IrregularIncome> tmpIrreg;

    // ---- load profile ----
    if (!root.contains("profile") || !root.value("profile").isObject()) return false;
    if (!fromJson(root.value("profile").toObject(), tmpProfile)) return false;

    // ---- load categories ----
    if (root.contains("categories") && root.value("categories").isArray()) {
        const QJsonArray arr = root.value("categories").toArray();
        for (const QJsonValue& v : arr) {
            if (v.isObject())
                tmpCats.push_back(fromJsonCategory(v.toObject()));
        }
    }

    // ---- load expenses ----
    if (root.contains("expenses") && root.value("expenses").isArray()) {
        const QJsonArray arr = root.value("expenses").toArray();
        for (const QJsonValue& v : arr) {
            if (v.isObject())
                tmpExps.push_back(fromJsonExpense(v.toObject()));
        }
    }

    // ---- load monthly incomes ----
    if (root.contains("monthlyIncomes") && root.value("monthlyIncomes").isArray()) {
        const QJsonArray arr = root.value("monthlyIncomes").toArray();
        for (const QJsonValue& v : arr) {
            if (v.isObject())
                tmpMonthly.push_back(fromJsonMonthlyIncome(v.toObject()));
        }
    }

    // ---- load irregular incomes ----
    if (root.contains("irregularIncomes") && root.value("irregularIncomes").isArray()) {
        const QJsonArray arr = root.value("irregularIncomes").toArray();
        for (const QJsonValue& v : arr) {
            if (v.isObject())
                tmpIrreg.push_back(fromJsonIrregularIncome(v.toObject()));
        }
    }

    // ---- NEW PART: rebuild per-category expense lists from tmpExps ----
    // First clear any existing expense lists in the categories
    for (Category &c : tmpCats) {
        c.clearExpenses();      // also sets totalSpent = 0.0
    }

    // Now attach each loaded expense to its matching category by name
    for (const Expense &e : tmpExps) {
        const QString catName = e.getCategory().trimmed();
        if (catName.isEmpty())
            continue;

        for (Category &c : tmpCats) {
            if (c.getName().trimmed().compare(catName, Qt::CaseInsensitive) == 0) {
                c.addExpense(e);    // pushes into Category::expenses + recomputeSpent + sort
                break;
            }
        }
    }

    // ---- finally move everything out if all went well ----
    profileOut         = tmpProfile;
    categoriesOut      = tmpCats;
    expensesOut        = tmpExps;
    monthlyIncomesOut  = tmpMonthly;
    irregularIncomesOut = tmpIrreg;

    return true;
}


#include <QApplication>
#include <QCoreApplication>
#include <QFile>

#include "profile.h"
#include "category.h"
#include "expense.h"
#include "MonthlyIncome.h"
#include "irregularincome.h"
#include "storage.h"
#include "namedialog.h"
#include "logindialog.h"
#include "mainwindow.h"

using namespace std;

// QTextStream objects for input/output (Qt alternative to cin/cout)
static QTextStream qin(stdin);
static QTextStream qout(stdout);

static QString money(double v) { return QString("$%1").arg(v, 0, 'f', 2); }

// helpers stay the same
static bool readLine(QString& out, const QString& prompt, bool allowEmpty=false) {
    qout << prompt;
    qout.flush();
    QString s = qin.readLine();
    if (s.isNull()) return false;
    s = s.trimmed();
    if (!allowEmpty && s.isEmpty()) return false;
    out = s;
    return true;
}

static bool readDouble(double& out, const QString& prompt) {
    while (true) {
        qout << prompt << " (or 'q' to cancel): ";
        qout.flush();
        QString s = qin.readLine();
        if (s.isNull()) return false;
        s = s.trimmed();
        if (s.compare("q", Qt::CaseInsensitive) == 0) return false;
        bool ok=false;
        const double v = s.toDouble(&ok);
        if (ok) { out = v; return true; }
        qout << "Invalid number. Try again.\n";
    }
}

static bool readInt(int& out, const QString& prompt, int minVal, int maxVal) {
    while (true) {
        qout << prompt << " (or 'q' to cancel): ";
        qout.flush();
        QString s = qin.readLine();
        if (s.isNull()) return false;
        s = s.trimmed();
        if (s.compare("q", Qt::CaseInsensitive) == 0) return false;
        if (s.isEmpty()) { qout << "Please enter a number.\n"; continue; }
        bool ok=false;
        const int v = s.toInt(&ok);
        if (ok && v >= minVal && v <= maxVal) { out = v; return true; }
        qout << "Invalid choice. Try again (" << minVal << "–" << maxVal << ").\n";
    }
}

static bool readDate(QDate& out, const QString& prompt) {
    while (true) {
        qout << prompt << " [YYYY-MM-DD] (or 'q' to cancel): ";
        qout.flush();
        QString s = qin.readLine();
        if (s.isNull()) return false;      // EOF
        s = s.trimmed();
        if (s.compare("q", Qt::CaseInsensitive) == 0) return false;
        const QDate d = QDate::fromString(s, Qt::ISODate);
        if (d.isValid()) { out = d; return true; }
        qout << "Invalid date. Use YYYY-MM-DD.\n";
    }
}

class FinanceApp {
private:
    Profile profile;
    QVector<Category> categories;
    QVector<Expense>  expenses;
    QVector<MonthlyIncome> monthlyIncomes;
    QVector<IrregularIncome> irregularIncomes;

    bool hasProfile = false;      // already used earlier for GUI-created profile
    bool dataPreloaded = false;   // NEW: indicates we already loaded everything


    QString initialNameFromGui;       // NEW: name passed in from GUI

    void showMenu() const {
        qout << "\n==== Finance Tracker ====\n"
             << "0. Exit (save)\n"
             << "1. Add category\n"
             << "2. Add monthly income\n"
             << "3. Add irregular income\n"
             << "4. Add expense\n"
             << "5. Remove expense\n"
             << "6. List everything (profile, categories, expenses, incomes)\n"
             << "7. Edit profile (name/age/budget/goal)\n"
             << "8. Toggle password protection\n"
             << "9. Change password\n";
        qout.flush();
    }

    // CHANGED: use GUI name if provided
    bool createProfile() {
        QString name = initialNameFromGui;     // NEW

        if (name.isEmpty()) {
            // fall back to terminal if GUI didn't provide a name
            while (!readLine(name, "Enter your name: ")) {
                qout << "Name cannot be empty.\n";
            }
        } else {
            qout << "Using name from GUI: " << name << "\n";
        }

        int age = 0;
        while (true) {
            qout << "Enter age: ";
            qout.flush();
            QString s = qin.readLine();
            if (s.isNull()) return false;
            s = s.trimmed();
            bool ok=false; int v=s.toInt(&ok);
            if (ok && v>=0) { age=v; break; }
            qout << "Invalid age.\n";
        }

        double monthBudget=0.0;
        if (!readDouble(monthBudget, "Enter monthly budget")) return false;

        double goal=0.0;
        if (!readDouble(goal, "Enter saving goal")) return false;

        bool passProtect=false;
        {
            QString ans;
            if (!readLine(ans, "Enable password protection? (y/n): ")) return false;
            passProtect = (ans.trimmed().toLower()=="y");
        }

        QString pass;
        if (passProtect) {
            if (!readLine(pass, "Enter password: ", /*allowEmpty*/false)) return false;
        }

        profile = Profile(name, age, passProtect, pass, monthBudget, goal);
        qout << "Profile created.\n";
        return true;
    }

    // everything below here (changeProfileBasics, togglePassword, addCategory, etc.)
    // stays EXACTLY the same as your current version
    // ---------------------------------------------------------
    void changeProfileBasics() {
        qout << "Editing profile. Leave blank to keep current.\n";

        qout << "Current name: " << profile.getName() << "\n";
        qout.flush();
        QString line;
        if (readLine(line, "New name: ", /*allowEmpty*/true) && !line.trimmed().isEmpty())
            profile.setName(line);

        qout << "Current age: " << profile.getAge() << "\n";
        qout.flush();
        if (readLine(line, "New age: ", true) && !line.trimmed().isEmpty()) {
            bool ok=false; int v=line.toInt(&ok);
            if (ok && v>=0) profile.setAge(v);
        }

        qout << "Current monthly budget: " << money(profile.getMonthlyBudget()) << "\n";
        qout.flush();
        if (readLine(line, "New monthly budget: ", true) && !line.trimmed().isEmpty()) {
            bool ok=false; double v=line.toDouble(&ok);
            if (ok) profile.setMonthlyBudget(v);
        }

        qout << "Current saving goal: " << money(profile.getSavingGoal()) << "\n";
        qout.flush();
        if (readLine(line, "New saving goal: ", true) && !line.trimmed().isEmpty()) {
            bool ok=false; double v=line.toDouble(&ok);
            if (ok) profile.setSavingGoal(v);
        }
    }

    void togglePassword() {
        const bool newState = !profile.isPasswordProtected();
        profile.togglePasswordProtect(newState);
        qout << "Password protection is now " << (newState ? "ON" : "OFF") << ".\n";
    }

    void changePassword() {
        if (!profile.isPasswordProtected()) {
            qout << "Password protection is OFF. Turn it on first (menu 8).\n";
            return;
        }
        QString p;
        if (!readLine(p, "Enter new password: ")) return;
        profile.changePassword(p);
        qout << "Password updated.\n";
    }

    void addCategory() {
        QString name;
        if (!readLine(name, "Category name (or 'q' to cancel): ")) return;
        if (name.compare("q", Qt::CaseInsensitive)==0) return;

        double limit=0.0;
        if (!readDouble(limit, "Budget limit")) return;

        categories.push_back(Category(name, limit, 0.0));
        qout << "Category added.\n";
    }

    int pickCategoryIndex(bool allowCancel=true) const {
        if (categories.isEmpty()) {
            qout << "No categories. Add one first (menu 1).\n";
            return -1;
        }
        qout << "Categories:\n";
        for (int i=0;i<categories.size();++i) {
            qout << "  " << i << ". " << categories[i].getName()
            << " | Budget " << money(categories[i].getBudgetLimit())
            << " | Spent "  << money(categories[i].getSpent()) << "\n";
        }
        int idx=-1;
        if (!readInt(idx, "Choose category index", 0, categories.size()-1)) {
            return allowCancel ? -1 : 0;
        }
        return idx;
    }

    void addMonthlyIncome() {
        double amt=0.0;
        if (!readDouble(amt, "Monthly income amount")) return;

        QString src;
        if (!readLine(src, "Source (or 'q' to cancel): ")) return;
        if (src.compare("q", Qt::CaseInsensitive)==0) return;

        QDate d;
        if (!readDate(d, "Date received")) return;

        monthlyIncomes.push_back(MonthlyIncome(amt, src, d));
        qout << "Monthly income added.\n";
    }

    void addIrregularIncome() {
        double amt=0.0;
        if (!readDouble(amt, "Irregular income amount")) return;

        QString src;
        if (!readLine(src, "Source (or 'q' to cancel): ")) return;
        if (src.compare("q", Qt::CaseInsensitive)==0) return;

        QDate d;
        if (!readDate(d, "Date received")) return;

        QString desc;
        if (!readLine(desc, "Short description (or 'q' to cancel): ")) return;
        if (desc.compare("q", Qt::CaseInsensitive)==0) return;

        irregularIncomes.push_back(IrregularIncome(amt, src, d, desc));
        qout << "Irregular income added.\n";
    }

    void addExpense() {
        if (categories.isEmpty()) {
            qout << "You must add a category first.\n";
            return;
        }

        int cidx = pickCategoryIndex();
        if (cidx < 0) return;

        double amt=0.0;
        if (!readDouble(amt, "Expense amount")) return;

        QDate d;
        if (!readDate(d, "Expense date")) return;

        QString desc;
        readLine(desc, "Description (or 'q' to skip): ", /*allowEmpty*/true);
        if (desc.compare("q", Qt::CaseInsensitive)==0) desc.clear();

        Expense e(amt, categories[cidx].getName(), d, desc);
        expenses.push_back(e);

        sort(expenses.begin(), expenses.end(),
             [](const Expense& a, const Expense& b){
                 if (a.getDate() != b.getDate()) return a.getDate() < b.getDate();
                 return a.getAmount() < b.getAmount();
             });

        categories[cidx].addExpense(e);

        qout << "Expense added.\n";
    }

    void removeExpense() {
        if (categories.isEmpty()) {
            qout << "No categories.\n";
            return;
        }
        const int cidx = pickCategoryIndex();
        if (cidx < 0) return;

        qout << "Expenses in category '" << categories[cidx].getName() << "':\n";
        categories[cidx].listExpenses();

        int eidx = -1;
        if (!readInt(eidx, "Enter expense index to remove", 0, 1000000)) return;

        const bool ok = categories[cidx].removeExpenseAt(eidx);
        if (!ok) {
            qout << "Removal failed (index might be out of range).\n";
            return;
        }

        sort(expenses.begin(), expenses.end(),
             [](const Expense& a, const Expense& b){
                 if (a.getDate() != b.getDate()) return a.getDate() < b.getDate();
                 if (a.getCategory() != b.getCategory()) return a.getCategory() < b.getCategory();
                 if (a.getAmount() != b.getAmount()) return a.getAmount() < b.getAmount();
                 return a.getDesc() < b.getDesc();
             });

        qout << "If an item was removed in the category, totals were recomputed there.\n";
    }

    void listAll() const {
        qout << "\n--- Profile ---\n";
        qout << "Name: " << profile.getName() << "\n";
        qout << "Age: "  << profile.getAge()  << "\n";
        qout << "Monthly Budget: " << money(profile.getMonthlyBudget()) << "\n";
        qout << "Saving Goal:    " << money(profile.getSavingGoal())    << "\n";
        qout << "Password Protected: " << (profile.isPasswordProtected() ? "Yes" : "No") << "\n";

        qout << "\n--- Categories ---\n";
        if (categories.isEmpty()) {
            qout << "(none)\n";
        } else {
            for (const auto& c : categories) {
                qout << "• " << c.getName()
                    << " | Budget " << money(c.getBudgetLimit())
                    << " | Spent "  << money(c.getSpent())
                    << " | Remaining " << money(c.getBudgetLimit() - c.getSpent())
                    << "\n";
                c.listExpenses();
            }
        }

        qout << "\n--- All Expenses (sorted by date) ---\n";
        if (expenses.isEmpty()) {
            qout << "(none)\n";
        } else {
            auto exps = expenses;
            sort(exps.begin(), exps.end(),
                 [](const Expense& a, const Expense& b){
                     if (a.getDate() != b.getDate()) return a.getDate() < b.getDate();
                     if (a.getCategory() != b.getCategory()) return a.getCategory() < b.getCategory();
                     return a.getAmount() < b.getAmount();
                 });
            for (const auto& e : exps) {
                qout << "  " << e.getDate().toString(Qt::ISODate)
                << "  [" << e.getCategory() << "]  "
                << money(e.getAmount())
                << "  " << e.getDesc() << "\n";
            }
        }

        qout << "\n--- Monthly Incomes ---\n";
        if (monthlyIncomes.isEmpty()) qout << "(none)\n";
        else {
            for (const auto& m : monthlyIncomes) {
                qout << "  " << m.getDate().toString(Qt::ISODate)
                << "  " << money(m.getAmount())
                << "  " << m.getSource() << "\n";
            }
        }

        qout << "\n--- Irregular Incomes ---\n";
        if (irregularIncomes.isEmpty()) qout << "(none)\n";
        else {
            for (const auto& r : irregularIncomes) {
                qout << "  " << r.getDate().toString(Qt::ISODate)
                << "  " << money(r.getAmount())
                << "  " << r.getSource()
                << "  (" << r.getDescription() << ")\n";
            }
        }
        qout.flush();
    }

public:
    FinanceApp() = default;

    void setProfile(const Profile &p) {
        profile = p;
        hasProfile = true;
    }

    // NEW: called from GUI main to inject the name
    void setInitialName(const QString &name) {
        initialNameFromGui = name.trimmed();
    }

    // NEW: set all data when we load from JSON before calling run()
    void setInitialData(const Profile &p,
                        const QVector<Category> &cats,
                        const QVector<Expense> &exps,
                        const QVector<MonthlyIncome> &mon,
                        const QVector<IrregularIncome> &irr)
    {
        profile          = p;
        categories       = cats;
        expenses         = exps;
        monthlyIncomes   = mon;
        irregularIncomes = irr;
        dataPreloaded    = true;
        hasProfile       = true;
    }

    void run(const QString& filePath) {
        if (!dataPreloaded) {
            // old behaviour: try to load from disk
            if (!Storage::loadAll(filePath, profile, categories,
                                  expenses, monthlyIncomes, irregularIncomes)) {
                qout << "No existing data found. Creating a new profile…\n";
                if (!hasProfile) {          // only if GUI didn't make one already
                    if (!createProfile()) {
                        qout << "Profile creation cancelled. Exiting.\n";
                        return;
                    }
                } else {
                    qout << "Using profile from GUI.\n";
                }
            } else {
                qout << "Loaded existing data.\n";
            }
        } else {
            qout << "Using pre-loaded data.\n";
        }

        while (true) {
            showMenu();
            int choice = -1;
            if (!readInt(choice, "Enter option number", 0, 9)) {
                qout << "Cancelled input. Please choose again.\n";
                continue;
            }

            switch (choice) {
            case 0: {
                const bool ok = Storage::saveAll(filePath, profile, categories,
                                                 expenses, monthlyIncomes, irregularIncomes);
                qout << (ok ? "Saved. Bye!\n" : "Save failed, exiting anyway.\n");
                return;
            }
            case 1: addCategory(); break;
            case 2: addMonthlyIncome(); break;
            case 3: addIrregularIncome(); break;
            case 4: addExpense(); break;
            case 5: removeExpense(); break;
            case 6: listAll(); break;
            case 7: changeProfileBasics(); break;
            case 8: togglePassword(); break;
            case 9: changePassword(); break;
            default: qout << "Unknown option.\n"; break;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    const QString filePath =
        QCoreApplication::applicationDirPath() + "/appdata.json";

    Profile profile;
    QVector<Category>        categories;
    QVector<Expense>         expenses;
    QVector<MonthlyIncome>   monthlyIncomes;
    QVector<IrregularIncome> irregularIncomes;

    const bool haveData = Storage::loadAll(filePath,
                                           profile,
                                           categories,
                                           expenses,
                                           monthlyIncomes,
                                           irregularIncomes);

    // === CASE 1: existing data AND password protection enabled ===
    if (haveData && profile.isPasswordProtected()) {
        LoginDialog loginDlg(profile.getPassHash());
        if (loginDlg.exec() != QDialog::Accepted) {
            return 0;                 // user closed / cancelled
        }

        if (loginDlg.newAccountChosen()) {
            // user chose: Make new account
            QFile::remove(filePath);   // delete old JSON file

            NameDialog setupDlg;
            if (setupDlg.exec() != QDialog::Accepted) {
                return 0;
            }

            Profile newProfile(
                setupDlg.userName(),
                setupDlg.userAge(),
                setupDlg.passwordProtectionEnabled(),
                setupDlg.password(),
                setupDlg.monthlyBudget(),
                setupDlg.savingGoal()
                );

            // start app with brand-new profile, no data yet
            MainWindow w(filePath,
                         newProfile,
                         {}, {}, {}, {});
            w.show();
            return app.exec();
        } else {
            // login ok: use loaded data
            MainWindow w(filePath,
                         profile,
                         categories,
                         expenses,
                         monthlyIncomes,
                         irregularIncomes);
            w.show();
            return app.exec();
        }
    }

    // === CASE 2: existing data but NOT password protected ===
    if (haveData && !profile.isPasswordProtected()) {
        MainWindow w(filePath,
                     profile,
                     categories,
                     expenses,
                     monthlyIncomes,
                     irregularIncomes);
        w.show();
        return app.exec();
    }

    // === CASE 3: no data file yet – first time run ===
    NameDialog setupDlg;
    if (setupDlg.exec() != QDialog::Accepted) {
        return 0;
    }

    Profile newProfile(
        setupDlg.userName(),
        setupDlg.userAge(),
        setupDlg.passwordProtectionEnabled(),
        setupDlg.password(),
        setupDlg.monthlyBudget(),
        setupDlg.savingGoal()
        );

    MainWindow w(filePath,
                 newProfile,
                 {}, {}, {}, {});
    w.show();
    return app.exec();
}

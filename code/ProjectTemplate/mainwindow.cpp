#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "categorydialog.h"
#include "storage.h"
#include "monthlyincomedialog.h"
#include "irregularincomedialog.h"
#include "expensedialog.h"
#include "removeexpensedialog.h"
#include "editprofiledialog.h"
#include "setpassworddialog.h"
#include "confirmpassworddialog.h"
#include "changepassworddialog.h"
#include "listalldialog.h"
#include "reportdialog.h"
#include "report.h"

#include <algorithm>
#include <QCoreApplication>
#include <QMessageBox>
#include <QCryptographicHash>

static QString hashPassword(const QString &pass)
{
    return QString::fromLatin1(
        QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex()
        );
}

MainWindow::MainWindow(const QString &dataFilePath,
                       const Profile &profile,
                       const QVector<Category> &categories,
                       const QVector<Expense> &expenses,
                       const QVector<MonthlyIncome> &monthlyIncomes,
                       const QVector<IrregularIncome> &irregularIncomes,
                       QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_profile(profile)
    , m_categories(categories)
    , m_expenses(expenses)
    , m_monthlyIncomes(monthlyIncomes)
    , m_irregularIncomes(irregularIncomes)
    , m_dataFilePath(dataFilePath)
{
    ui->setupUi(this);
    setWindowTitle("Finance Tracker");
    updateHeader();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateHeader()
{
    ui->titleLabel->setText("Finance Tracker");
    ui->subtitleLabel->setText(
        QString("Welcome, %1").arg(m_profile.getName())
        );
}

// MENU BUTTONS

void MainWindow::on_btnAddCategory_clicked()
{
    CategoryDialog dlg(this);
    if (dlg.exec() != QDialog::Accepted) {
        return; // user cancelled
    }

    const QString name  = dlg.categoryName();
    const double  limit = dlg.budgetLimit();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Invalid category",
                             "Category name cannot be empty.");
        return;
    }

    // Add to in-memory list
    m_categories.push_back(Category(name, limit, 0.0));

    // Save everything back to JSON
    if (!Storage::saveAll(m_dataFilePath,
                          m_profile,
                          m_categories,
                          m_expenses,
                          m_monthlyIncomes,
                          m_irregularIncomes)) {
        QMessageBox::warning(this, "Save error",
                             "Failed to save data to file.");
    }
}



void MainWindow::on_btnAddMonthlyIncome_clicked()
{
    MonthlyIncomeDialog dlg(this);
    if (dlg.exec() != QDialog::Accepted) {
        return; // user cancelled, go back to main window
    }

    const double  amt  = dlg.amount();
    const QString src  = dlg.source();
    const QDate   date = dlg.dateReceived();

    // Safety check
    if (amt <= 0.0 || src.isEmpty() || !date.isValid()) {
        QMessageBox::warning(this, "Invalid data",
                             "Please enter a valid amount, source, and date.");
        return;
    }

    // Add to in-memory vector
    m_monthlyIncomes.push_back(MonthlyIncome(amt, src, date));

    // Save everything to JSON
    if (!Storage::saveAll(m_dataFilePath,
                          m_profile,
                          m_categories,
                          m_expenses,
                          m_monthlyIncomes,
                          m_irregularIncomes)) {
        QMessageBox::warning(this, "Save error",
                             "Failed to save data to file.");
    }
}

void MainWindow::on_btnAddIrregularIncome_clicked()
{
    IrregularIncomeDialog dlg(this);
    if (dlg.exec() != QDialog::Accepted) {
        return;   // user cancelled, just go back to main window
    }

    const double amt = dlg.amount();
    const QString src  = dlg.source();
    const QDate   date = dlg.dateReceived();
    const QString desc = dlg.description();

    // safety check (should already be validated in dialog)
    if (amt <= 0.0 || src.isEmpty() || !date.isValid()) {
        QMessageBox::warning(this, "Invalid data",
                             "Could not add irregular income because the data was invalid.");
        return;
    }

    // Add to in-memory list
    m_irregularIncomes.push_back(IrregularIncome(amt, src, date, desc));

    // Save everything back to JSON
    if (!Storage::saveAll(m_dataFilePath,
                          m_profile,
                          m_categories,
                          m_expenses,
                          m_monthlyIncomes,
                          m_irregularIncomes)) {
        QMessageBox::warning(this, "Save error",
                             "Failed to save data to file.");
    } else {
        QMessageBox::information(this, "Irregular income added",
                                 "Irregular income has been saved.");
    }
}


void MainWindow::on_btnAddExpense_clicked()
{
    // 1. Require categories first (same logic as console version)
    if (m_categories.isEmpty()) {
        QMessageBox::warning(this,
                             "No categories",
                             "You must add at least one category before adding an expense.");
        return;
    }

    // 2. Show the dialog, passing current categories (including any just added)
    ExpenseDialog dlg(m_categories, this);
    if (dlg.exec() != QDialog::Accepted) {
        // user hit Cancel / closed dialog – just return to main window
        return;
    }

    const int     catIdx = dlg.selectedCategoryIndex();
    const double  amt    = dlg.amount();
    const QDate   date   = dlg.date();
    const QString desc   = dlg.description();

    if (catIdx < 0 || catIdx >= m_categories.size()) {
        QMessageBox::warning(this, "Error",
                             "Invalid category selected.");
        return;
    }

    // 3. Build the Expense object (same as console version)
    Expense e(amt, m_categories[catIdx].getName(), date, desc);

    // Add to master expense list
    m_expenses.push_back(e);

    // Keep expenses sorted by date (optional, but matches your console behavior)
    std::sort(m_expenses.begin(), m_expenses.end(),
              [](const Expense &a, const Expense &b) {
                  if (a.getDate() != b.getDate())
                      return a.getDate() < b.getDate();
                  if (a.getCategory() != b.getCategory())
                      return a.getCategory() < b.getCategory();
                  return a.getAmount() < b.getAmount();
              });

    // Update that category’s spent total
    m_categories[catIdx].addExpense(e);

    // 4. Save everything to JSON
    if (!Storage::saveAll(m_dataFilePath,
                          m_profile,
                          m_categories,
                          m_expenses,
                          m_monthlyIncomes,
                          m_irregularIncomes)) {
        QMessageBox::warning(this,
                             "Save error",
                             "Failed to save data to file.");
    } else {
        QMessageBox::information(this,
                                 "Expense added",
                                 "Expense has been saved.");
    }
}


void MainWindow::on_btnRemoveExpense_clicked()
{
    if (m_categories.isEmpty()) {
        QMessageBox::warning(this,
                             "No categories",
                             "There are no categories. Add a category first.");
        return;
    }

    RemoveExpenseDialog dlg(m_categories, this);
    if (dlg.exec() != QDialog::Accepted) {
        // user hit Cancel / closed dialog
        return;
    }

    int catIdx = dlg.selectedCategoryIndex();
    int expIdx = dlg.selectedExpenseIndex();

    if (catIdx < 0 || catIdx >= m_categories.size()) {
        QMessageBox::warning(this, "Error",
                             "Invalid category selected.");
        return;
    }

    const auto &catExpenses = m_categories[catIdx].getExpenses();
    if (expIdx < 0 || expIdx >= catExpenses.size()) {
        QMessageBox::warning(this, "Error",
                             "Invalid expense selected.");
        return;
    }

    // Copy the expense we’re going to delete so we can also remove it from
    // the global m_expenses list.
    Expense toDelete = catExpenses[expIdx];

    // Remove from the category’s own list and recompute totals
    bool ok = m_categories[catIdx].removeExpenseAt(expIdx);
    if (!ok) {
        QMessageBox::warning(this, "Error",
                             "Could not remove that expense from the category.");
        return;
    }

    // Remove matching expense from the global list
    for (int i = 0; i < m_expenses.size(); ++i) {
        if (m_expenses[i].getDate()     == toDelete.getDate() &&
            m_expenses[i].getCategory() == toDelete.getCategory() &&
            m_expenses[i].getAmount()   == toDelete.getAmount() &&
            m_expenses[i].getDesc()     == toDelete.getDesc()) {
            m_expenses.remove(i);
            break;
        }
    }

    // Save everything back to JSON
    if (!Storage::saveAll(m_dataFilePath,
                          m_profile,
                          m_categories,
                          m_expenses,
                          m_monthlyIncomes,
                          m_irregularIncomes)) {
        QMessageBox::warning(this, "Save error",
                             "Failed to save data to file.");
    } else {
        QMessageBox::information(this,
                                 "Expense removed",
                                 "The selected expense has been removed.");
    }
}


void MainWindow::on_btnListAll_clicked()
{
    ListAllDialog dlg(m_profile,
                      m_categories,
                      m_expenses,
                      m_monthlyIncomes,
                      m_irregularIncomes,
                      this);
    dlg.exec();   // modal – user closes with "Close" button
}

void MainWindow::on_btnEditProfile_clicked()
{
    EditProfileDialog dlg(m_profile, this);

    if (dlg.exec() != QDialog::Accepted) {
        // user cancelled
        return;
    }

    // Apply changes to the in-memory profile
    m_profile.setName(dlg.newName());
    m_profile.setAge(dlg.newAge());
    m_profile.setMonthlyBudget(dlg.newMonthlyBudget());
    m_profile.setSavingGoal(dlg.newSavingGoal());

    // Update header labels so user sees the new name immediately
    updateHeader();

    // Save everything (profile + all data) to JSON
    const bool ok = Storage::saveAll(
        m_dataFilePath,
        m_profile,
        m_categories,
        m_expenses,
        m_monthlyIncomes,
        m_irregularIncomes
        );

    if (!ok) {
        QMessageBox::warning(this,
                             "Save failed",
                             "Could not save updated profile to file.");
    } else {
        QMessageBox::information(this,
                                 "Profile updated",
                                 "Your profile has been updated.");
    }
}


void MainWindow::on_btnTogglePassword_clicked()
{
    // CASE A: password is currently OFF -> turn it ON
    if (!m_profile.isPasswordProtected()) {
        SetPasswordDialog dlg(this);
        if (dlg.exec() != QDialog::Accepted) {
            return; // user cancelled
        }

        const QString newPass = dlg.password();
        if (newPass.isEmpty()) {
            // extra safety – should already be checked by dialog
            QMessageBox::warning(this, "Error",
                                 "Password cannot be empty.");
            return;
        }

        // Enable and set password (this hashes internally)
        m_profile.togglePasswordProtect(true);
        m_profile.changePassword(newPass);

        // Save to JSON
        if (!Storage::saveAll(m_dataFilePath,
                              m_profile,
                              m_categories,
                              m_expenses,
                              m_monthlyIncomes,
                              m_irregularIncomes)) {
            QMessageBox::warning(this, "Save error",
                                 "Failed to save updated password settings.");
        } else {
            QMessageBox::information(this, "Password",
                                     "Password protection is now ON.");
        }

        return;
    }

    // CASE B: password is currently ON -> turn it OFF (with confirmation)
    ConfirmPasswordDialog dlg(this);
    if (dlg.exec() != QDialog::Accepted) {
        return; // user cancelled
    }

    const QString entered = dlg.password();
    if (!m_profile.verifyPassword(entered)) {
        QMessageBox::warning(this, "Incorrect password",
                             "The password you entered is incorrect.");
        return;
    }

    // Correct password – disable protection
    m_profile.togglePasswordProtect(false);

    // Optional: clear password hash by setting empty password
    // (you *could* leave the hash there, but this is cleaner.)
    m_profile.changePassword(QString());

    if (!Storage::saveAll(m_dataFilePath,
                          m_profile,
                          m_categories,
                          m_expenses,
                          m_monthlyIncomes,
                          m_irregularIncomes)) {
        QMessageBox::warning(this, "Save error",
                             "Failed to save updated password settings.");
    } else {
        QMessageBox::information(this, "Password",
                                 "Password protection is now OFF.");
    }
}


void MainWindow::on_btnChangePassword_clicked()
{
    // 1. If password protection is OFF, just show message and stop
    if (!m_profile.isPasswordProtected()) {
        QMessageBox::information(
            this,
            "Password protection is OFF",
            "Password protection is OFF. Turn it on first (menu 8)."
            );
        return;
    }

    // 2. Show the change-password dialog
    ChangePasswordDialog dlg(this);
    if (dlg.exec() != QDialog::Accepted) {
        // user cancelled
        return;
    }

    const QString oldPass     = dlg.oldPassword();
    const QString newPass     = dlg.newPassword();
    const QString confirmPass = dlg.confirmPassword();

    // 3. Check new password == confirmation
    if (newPass != confirmPass) {
        QMessageBox::warning(
            this,
            "Password mismatch",
            "New password and confirmation do not match."
            );
        return;
    }

    // 4. Verify old password is correct
    const QString oldHash = hashPassword(oldPass);
    if (oldHash != m_profile.getPassHash()) {
        QMessageBox::warning(
            this,
            "Incorrect password",
            "The old password you entered is incorrect."
            );
        return;
    }

    // 5. Update password in profile (this should re-hash internally)
    m_profile.changePassword(newPass);

    // 6. Save everything to JSON so it persists for next login
    const bool ok = Storage::saveAll(
        m_dataFilePath,
        m_profile,
        m_categories,
        m_expenses,
        m_monthlyIncomes,
        m_irregularIncomes
        );

    if (!ok) {
        QMessageBox::warning(
            this,
            "Save failed",
            "Password changed, but saving to file failed."
            );
    } else {
        QMessageBox::information(
            this,
            "Password updated",
            "Your password has been updated."
            );
    }
}


void MainWindow::saveAndExit()
{
    const bool ok = Storage::saveAll(
        m_dataFilePath,
        m_profile,
        m_categories,
        m_expenses,
        m_monthlyIncomes,
        m_irregularIncomes
        );

    if (!ok) {
        QMessageBox::warning(this, "Save failed",
                             "Could not save data, but the app will close.");
    }

    close();
}

void MainWindow::on_btnShowReport_clicked()
{
    // Build summary from current in-memory data
    ReportSummary summary = Report::build(m_categories,
                                          m_monthlyIncomes,
                                          m_irregularIncomes);

    // Show dialog
    ReportDialog dlg(this);
    dlg.setData(m_profile, summary);
    dlg.exec();      // modal; when it closes, user is "back" at MainWindow
}


void MainWindow::on_btnExit_clicked()
{
    saveAndExit();
}

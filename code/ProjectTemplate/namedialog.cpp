#include "namedialog.h"
#include "ui_namedialog.h"

#include <QMessageBox>
#include <QLineEdit>
#include <QCheckBox>

NameDialog::NameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NameDialog)
{
    ui->setupUi(this);

    // widgets in .ui must have these object names:
    // nameEdit, ageEdit, budgetEdit, goalEdit,
    // passwordEdit, enablePasswordCheck, continueButton
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

NameDialog::~NameDialog()
{
    delete ui;
}

QString NameDialog::userName() const
{
    return ui->nameEdit->text().trimmed();
}

int NameDialog::userAge() const
{
    bool ok = false;
    int v = ui->ageEdit->text().toInt(&ok);
    return ok ? v : 0;
}

double NameDialog::monthlyBudget() const
{
    bool ok = false;
    double v = ui->budgetEdit->text().toDouble(&ok);
    return ok ? v : 0.0;
}

double NameDialog::savingGoal() const
{
    bool ok = false;
    double v = ui->goalEdit->text().toDouble(&ok);
    return ok ? v : 0.0;
}

bool NameDialog::passwordProtectionEnabled() const
{
    return ui->enablePasswordCheck->isChecked();
}

QString NameDialog::password() const
{
    return ui->passwordEdit->text();
}

void NameDialog::on_continueButton_clicked()
{
    const QString name = ui->nameEdit->text().trimmed();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Missing info", "Please enter your name.");
        ui->nameEdit->setFocus();
        return;
    }

    bool okAge=false, okBudget=false, okGoal=false;

    int age = ui->ageEdit->text().trimmed().toInt(&okAge);
    double budget = ui->budgetEdit->text().trimmed().toDouble(&okBudget);
    double goal = ui->goalEdit->text().trimmed().toDouble(&okGoal);

    if (!okAge || age < 0) {
        QMessageBox::warning(this, "Invalid age", "Please enter a valid age (0 or higher).");
        ui->ageEdit->setFocus();
        ui->ageEdit->selectAll();
        return;
    }

    if (!okBudget || budget <= 0) {
        QMessageBox::warning(this, "Invalid budget", "Please enter a valid monthly budget (> 0).");
        ui->budgetEdit->setFocus();
        ui->budgetEdit->selectAll();
        return;
    }

    if (!okGoal || goal < 0) {
        QMessageBox::warning(this, "Invalid goal", "Please enter a valid saving goal (0 or higher).");
        ui->goalEdit->setFocus();
        ui->goalEdit->selectAll();
        return;
    }

    // If password protection is enabled, require a password
    if (ui->enablePasswordCheck->isChecked()) {
        if (ui->passwordEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Missing password", "Please enter a password or turn off password protection.");
            ui->passwordEdit->setFocus();
            return;
        }
    }

    accept(); // only happens if everything is valid
}

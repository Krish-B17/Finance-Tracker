#include "editprofiledialog.h"
#include "ui_editprofiledialog.h"
#include <QMessageBox>

// Constructor receives current Profile data and initializes dialog fields
EditProfileDialog::EditProfileDialog(const Profile &profile,
                                     QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditProfileDialog)
{
    ui->setupUi(this);

    // Pre-fill form fields using existing profile data
    ui->nameEdit->setText(profile.getName());
    ui->ageSpinBox->setValue(profile.getAge());
    ui->budgetSpinBox->setValue(profile.getMonthlyBudget());
    ui->goalSpinBox->setValue(profile.getSavingGoal());
}

// Destructor - free allocated UI resources
EditProfileDialog::~EditProfileDialog()
{
    delete ui;
}

// Getter: return updated name with whitespace trimmed
QString EditProfileDialog::newName() const
{
    return ui->nameEdit->text().trimmed();
}

// Getter: return updated age value
int EditProfileDialog::newAge() const
{
    return ui->ageSpinBox->value();
}

// Getter: return updated monthly budget value
double EditProfileDialog::newMonthlyBudget() const
{
    return ui->budgetSpinBox->value();
}

// Getter: return updated savings goal value
double EditProfileDialog::newSavingGoal() const
{
    return ui->goalSpinBox->value();
}

// Handler for Save button click
void EditProfileDialog::on_btnSave_clicked()
{
    // Ensure a valid name was entered before accepting changes
    if (ui->nameEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this,
                             "Invalid name",
                             "Name cannot be empty.");
        return;
    }

    accept();
}

// Handler for Cancel button click
void EditProfileDialog::on_btnCancel_clicked()
{
    reject();   // close with Rejected status to discard changes
}

#include "confirmpassworddialog.h"
#include "ui_confirmpassworddialog.h"

#include <QLineEdit>
#include <QMessageBox>

// Constructor for ConfirmPasswordDialog
ConfirmPasswordDialog::ConfirmPasswordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmPasswordDialog)
{
    ui->setupUi(this);

    // Hide password characters when typing
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

// Destructor - free allocated UI resources
ConfirmPasswordDialog::~ConfirmPasswordDialog()
{
    delete ui;
}

// Getter function for retrieving entered password text
QString ConfirmPasswordDialog::password() const
{
    return ui->passwordEdit->text();
}

// Slot triggered when OK button is clicked
void ConfirmPasswordDialog::on_okButton_clicked()
{
    // Prevent empty password submission
    if (ui->passwordEdit->text().isEmpty()) {
        QMessageBox::warning(this,
                             "Invalid Password",
                             "Password cannot be empty.");
        return;
    }

    accept(); // close dialog successfully and return Accepted
}

// Slot triggered when Cancel button is clicked
void ConfirmPasswordDialog::on_cancelButton_clicked()
{
    reject(); // close dialog and return Rejected
}

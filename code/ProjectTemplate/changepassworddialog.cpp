#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"

#include <QLineEdit>

// Constructor for the ChangePasswordDialog UI
ChangePasswordDialog::ChangePasswordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePasswordDialog)
{
    ui->setupUi(this);

    // Hide password text inputs so characters appear as dots
    ui->oldPassEdit->setEchoMode(QLineEdit::Password);
    ui->newPassEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPassEdit->setEchoMode(QLineEdit::Password);

    // Connect OK button to accept() -> closes dialog successfully
    connect(ui->okButton, &QPushButton::clicked,
            this, &QDialog::accept);

    // Connect Cancel button to reject() -> closes dialog without saving
    connect(ui->cancelButton, &QPushButton::clicked,
            this, &QDialog::reject);
}

// Destructor - free allocated UI memory
ChangePasswordDialog::~ChangePasswordDialog()
{
    delete ui;
}

// Getter for the current password entered by the user. Used to verify old password before updating.
QString ChangePasswordDialog::oldPassword() const
{
    return ui->oldPassEdit->text();
}

// Getter for the new desired password entered by the user.
QString ChangePasswordDialog::newPassword() const
{
    return ui->newPassEdit->text();
}

// Getter for confirming the new password text. Used to compare new password twice for safety.
QString ChangePasswordDialog::confirmPassword() const
{
    return ui->confirmPassEdit->text();
}

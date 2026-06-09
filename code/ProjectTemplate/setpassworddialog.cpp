#include "setpassworddialog.h"
#include "ui_setpassworddialog.h"

#include <QMessageBox>
#include <QLineEdit>

SetPasswordDialog::SetPasswordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetPasswordDialog)
{
    ui->setupUi(this);

    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmEdit->setEchoMode(QLineEdit::Password);
}

SetPasswordDialog::~SetPasswordDialog()
{
    delete ui;
}

QString SetPasswordDialog::password() const
{
    return ui->passwordEdit->text();
}

void SetPasswordDialog::on_okButton_clicked()
{
    const QString pass  = ui->passwordEdit->text();
    const QString confirm = ui->confirmEdit->text();

    if (pass.isEmpty()) {
        QMessageBox::warning(this, "Error",
                             "Password cannot be empty.");
        return;
    }
    if (pass != confirm) {
        QMessageBox::warning(this, "Error",
                             "Passwords do not match. Please try again.");
        return;
    }

    accept();   // QDialog::Accepted
}

void SetPasswordDialog::on_cancelButton_clicked()
{
    reject();
}

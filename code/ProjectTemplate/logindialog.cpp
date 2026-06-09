#include "logindialog.h"
#include "ui_logindialog.h"

#include <QCryptographicHash>
#include <QMessageBox>
#include <QLineEdit>

LoginDialog::LoginDialog(const QString &storedHash, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , m_storedHash(storedHash)
{
    ui->setupUi(this);
    // widgets in .ui: passwordEdit, loginButton, newAccountButton
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::hashPassword(const QString &pass) const
{
    return QString::fromLatin1(
        QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex()
        );
}

bool LoginDialog::newAccountChosen() const
{
    return m_newAccount;
}

void LoginDialog::on_loginButton_clicked()
{
    const QString entered = ui->passwordEdit->text();
    if (hashPassword(entered) == m_storedHash) {
        accept();
    } else {
        QMessageBox::warning(this, "Login failed",
                             "Incorrect password. Please try again.");
    }
}

void LoginDialog::on_newAccountButton_clicked()
{
    m_newAccount = true;
    accept();
}

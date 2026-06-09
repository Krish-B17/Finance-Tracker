#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDialog;
}
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(const QString &storedHash, QWidget *parent = nullptr);
    ~LoginDialog();

    bool newAccountChosen() const;

private slots:
    void on_loginButton_clicked();
    void on_newAccountButton_clicked();

private:
    Ui::LoginDialog *ui;
    QString m_storedHash;
    bool    m_newAccount = false;

    QString hashPassword(const QString &pass) const;
};

#endif // LOGINDIALOG_H

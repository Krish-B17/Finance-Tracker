/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *newAccountButton;
    QLabel *label;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(400, 300);
        passwordEdit = new QLineEdit(LoginDialog);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(100, 120, 191, 51));
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(30, 240, 100, 32));
        newAccountButton = new QPushButton(LoginDialog);
        newAccountButton->setObjectName("newAccountButton");
        newAccountButton->setGeometry(QRect(259, 240, 111, 32));
        label = new QLabel(LoginDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 311, 51));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDialog", "Login", nullptr));
        newAccountButton->setText(QCoreApplication::translate("LoginDialog", "New Account", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Enter Your Password</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

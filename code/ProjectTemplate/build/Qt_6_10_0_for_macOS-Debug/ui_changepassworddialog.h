/********************************************************************************
** Form generated from reading UI file 'changepassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDDIALOG_H
#define UI_CHANGEPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangePasswordDialog
{
public:
    QLabel *label;
    QLabel *label_3;
    QLineEdit *oldPassEdit;
    QLabel *label_4;
    QLineEdit *newPassEdit;
    QLabel *label_5;
    QLineEdit *confirmPassEdit;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *ChangePasswordDialog)
    {
        if (ChangePasswordDialog->objectName().isEmpty())
            ChangePasswordDialog->setObjectName("ChangePasswordDialog");
        ChangePasswordDialog->resize(480, 640);
        label = new QLabel(ChangePasswordDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 411, 51));
        label_3 = new QLabel(ChangePasswordDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 110, 191, 81));
        oldPassEdit = new QLineEdit(ChangePasswordDialog);
        oldPassEdit->setObjectName("oldPassEdit");
        oldPassEdit->setGeometry(QRect(250, 110, 191, 81));
        oldPassEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_4 = new QLabel(ChangePasswordDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 210, 191, 81));
        newPassEdit = new QLineEdit(ChangePasswordDialog);
        newPassEdit->setObjectName("newPassEdit");
        newPassEdit->setGeometry(QRect(250, 210, 191, 81));
        newPassEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_5 = new QLabel(ChangePasswordDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 310, 201, 81));
        confirmPassEdit = new QLineEdit(ChangePasswordDialog);
        confirmPassEdit->setObjectName("confirmPassEdit");
        confirmPassEdit->setGeometry(QRect(250, 310, 191, 81));
        confirmPassEdit->setEchoMode(QLineEdit::EchoMode::Password);
        cancelButton = new QPushButton(ChangePasswordDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(270, 500, 161, 61));
        okButton = new QPushButton(ChangePasswordDialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(40, 500, 161, 61));

        retranslateUi(ChangePasswordDialog);

        QMetaObject::connectSlotsByName(ChangePasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangePasswordDialog)
    {
        ChangePasswordDialog->setWindowTitle(QCoreApplication::translate("ChangePasswordDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChangePasswordDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Edit Profile </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ChangePasswordDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:24pt;\">Old Password: </span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ChangePasswordDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:24pt;\">New Password: </span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("ChangePasswordDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:24pt;\">Confirm Password: </span></p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("ChangePasswordDialog", "Cancel", nullptr));
        okButton->setText(QCoreApplication::translate("ChangePasswordDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePasswordDialog: public Ui_ChangePasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDDIALOG_H

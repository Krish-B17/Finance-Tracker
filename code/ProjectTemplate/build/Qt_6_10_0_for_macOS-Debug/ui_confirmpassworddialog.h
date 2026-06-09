/********************************************************************************
** Form generated from reading UI file 'confirmpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMPASSWORDDIALOG_H
#define UI_CONFIRMPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfirmPasswordDialog
{
public:
    QLabel *label;
    QPushButton *cancelButton;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QPushButton *okButton;

    void setupUi(QDialog *ConfirmPasswordDialog)
    {
        if (ConfirmPasswordDialog->objectName().isEmpty())
            ConfirmPasswordDialog->setObjectName("ConfirmPasswordDialog");
        ConfirmPasswordDialog->resize(400, 300);
        label = new QLabel(ConfirmPasswordDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 181, 71));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        cancelButton = new QPushButton(ConfirmPasswordDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(230, 230, 100, 32));
        label_2 = new QLabel(ConfirmPasswordDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 361, 51));
        passwordEdit = new QLineEdit(ConfirmPasswordDialog);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(220, 110, 151, 51));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        okButton = new QPushButton(ConfirmPasswordDialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(60, 230, 100, 32));

        retranslateUi(ConfirmPasswordDialog);

        QMetaObject::connectSlotsByName(ConfirmPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmPasswordDialog)
    {
        ConfirmPasswordDialog->setWindowTitle(QCoreApplication::translate("ConfirmPasswordDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ConfirmPasswordDialog", "<html><head/><body><p><span style=\" font-size:18pt;\">Enter Current Password</span></p><p><span style=\" font-size:18pt;\">To Disable Protection</span></p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("ConfirmPasswordDialog", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("ConfirmPasswordDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Confirm Password Deletion</span></p></body></html>", nullptr));
        okButton->setText(QCoreApplication::translate("ConfirmPasswordDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmPasswordDialog: public Ui_ConfirmPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMPASSWORDDIALOG_H

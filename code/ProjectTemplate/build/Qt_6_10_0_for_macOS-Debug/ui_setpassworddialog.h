/********************************************************************************
** Form generated from reading UI file 'setpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPASSWORDDIALOG_H
#define UI_SETPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetPasswordDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QLabel *label_3;
    QLineEdit *confirmEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SetPasswordDialog)
    {
        if (SetPasswordDialog->objectName().isEmpty())
            SetPasswordDialog->setObjectName("SetPasswordDialog");
        SetPasswordDialog->resize(400, 300);
        label = new QLabel(SetPasswordDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 80, 161, 31));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(SetPasswordDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 0, 361, 51));
        passwordEdit = new QLineEdit(SetPasswordDialog);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(190, 80, 181, 31));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_3 = new QLabel(SetPasswordDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 140, 161, 31));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        confirmEdit = new QLineEdit(SetPasswordDialog);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setGeometry(QRect(190, 140, 181, 31));
        confirmEdit->setEchoMode(QLineEdit::EchoMode::Password);
        okButton = new QPushButton(SetPasswordDialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(60, 220, 100, 32));
        cancelButton = new QPushButton(SetPasswordDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(230, 220, 100, 32));

        retranslateUi(SetPasswordDialog);

        QMetaObject::connectSlotsByName(SetPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *SetPasswordDialog)
    {
        SetPasswordDialog->setWindowTitle(QCoreApplication::translate("SetPasswordDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SetPasswordDialog", "<html><head/><body><p><span style=\" font-size:18pt;\">Enter New Password:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SetPasswordDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Add Your Password</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("SetPasswordDialog", "<html><head/><body><p><span style=\" font-size:18pt;\">Confirm Password:</span></p></body></html>", nullptr));
        okButton->setText(QCoreApplication::translate("SetPasswordDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("SetPasswordDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetPasswordDialog: public Ui_SetPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPASSWORDDIALOG_H

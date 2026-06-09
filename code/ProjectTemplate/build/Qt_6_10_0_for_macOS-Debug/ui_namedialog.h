/********************************************************************************
** Form generated from reading UI file 'namedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMEDIALOG_H
#define UI_NAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NameDialog
{
public:
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *budgetEdit;
    QLineEdit *goalEdit;
    QLineEdit *passwordEdit;
    QPushButton *continueButton;
    QCheckBox *enablePasswordCheck;
    QPlainTextEdit *plainTextEdit_5;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;

    void setupUi(QDialog *NameDialog)
    {
        if (NameDialog->objectName().isEmpty())
            NameDialog->setObjectName("NameDialog");
        NameDialog->resize(400, 300);
        nameEdit = new QLineEdit(NameDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(130, 10, 131, 31));
        ageEdit = new QLineEdit(NameDialog);
        ageEdit->setObjectName("ageEdit");
        ageEdit->setGeometry(QRect(130, 50, 131, 31));
        budgetEdit = new QLineEdit(NameDialog);
        budgetEdit->setObjectName("budgetEdit");
        budgetEdit->setGeometry(QRect(130, 90, 131, 31));
        goalEdit = new QLineEdit(NameDialog);
        goalEdit->setObjectName("goalEdit");
        goalEdit->setGeometry(QRect(130, 130, 131, 31));
        passwordEdit = new QLineEdit(NameDialog);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(130, 210, 131, 31));
        continueButton = new QPushButton(NameDialog);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(270, 250, 100, 32));
        enablePasswordCheck = new QCheckBox(NameDialog);
        enablePasswordCheck->setObjectName("enablePasswordCheck");
        enablePasswordCheck->setGeometry(QRect(130, 180, 131, 20));
        plainTextEdit_5 = new QPlainTextEdit(NameDialog);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setGeometry(QRect(30, 210, 81, 31));
        plainTextEdit_4 = new QPlainTextEdit(NameDialog);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(20, 130, 91, 31));
        plainTextEdit = new QPlainTextEdit(NameDialog);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(60, 10, 51, 31));
        plainTextEdit_2 = new QPlainTextEdit(NameDialog);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(60, 50, 51, 31));
        plainTextEdit_3 = new QPlainTextEdit(NameDialog);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(50, 90, 61, 31));

        retranslateUi(NameDialog);

        QMetaObject::connectSlotsByName(NameDialog);
    } // setupUi

    void retranslateUi(QDialog *NameDialog)
    {
        NameDialog->setWindowTitle(QCoreApplication::translate("NameDialog", "Dialog", nullptr));
        continueButton->setText(QCoreApplication::translate("NameDialog", "Continue", nullptr));
        enablePasswordCheck->setText(QCoreApplication::translate("NameDialog", "Enable Password", nullptr));
        plainTextEdit_5->setPlainText(QCoreApplication::translate("NameDialog", "Password:", nullptr));
        plainTextEdit_4->setPlainText(QCoreApplication::translate("NameDialog", "Saving Goal:", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("NameDialog", "Name:", nullptr));
        plainTextEdit_2->setPlainText(QCoreApplication::translate("NameDialog", "Age:", nullptr));
        plainTextEdit_3->setPlainText(QCoreApplication::translate("NameDialog", "Budget:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NameDialog: public Ui_NameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMEDIALOG_H

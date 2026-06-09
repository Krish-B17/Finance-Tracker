/********************************************************************************
** Form generated from reading UI file 'expensedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSEDIALOG_H
#define UI_EXPENSEDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExpenseDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *categoryComboBox;
    QLabel *label_3;
    QDoubleSpinBox *amountSpinBox;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QLabel *label_5;
    QLineEdit *descriptionEdit;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *ExpenseDialog)
    {
        if (ExpenseDialog->objectName().isEmpty())
            ExpenseDialog->setObjectName("ExpenseDialog");
        ExpenseDialog->resize(480, 640);
        label = new QLabel(ExpenseDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 411, 51));
        label_2 = new QLabel(ExpenseDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 201, 61));
        categoryComboBox = new QComboBox(ExpenseDialog);
        categoryComboBox->setObjectName("categoryComboBox");
        categoryComboBox->setGeometry(QRect(230, 100, 181, 61));
        label_3 = new QLabel(ExpenseDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 170, 201, 61));
        amountSpinBox = new QDoubleSpinBox(ExpenseDialog);
        amountSpinBox->setObjectName("amountSpinBox");
        amountSpinBox->setGeometry(QRect(230, 170, 201, 71));
        amountSpinBox->setMaximum(1000000000000000043845843045076197354634047651840.000000000000000);
        label_4 = new QLabel(ExpenseDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 260, 201, 61));
        dateEdit = new QDateEdit(ExpenseDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(230, 250, 211, 81));
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::TimeSpec::UTC);
        dateEdit->setDate(QDate(2025, 12, 18));
        label_5 = new QLabel(ExpenseDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 350, 201, 61));
        descriptionEdit = new QLineEdit(ExpenseDialog);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setGeometry(QRect(230, 340, 201, 71));
        btnOk = new QPushButton(ExpenseDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(40, 500, 161, 61));
        btnCancel = new QPushButton(ExpenseDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(270, 500, 161, 61));

        retranslateUi(ExpenseDialog);

        QMetaObject::connectSlotsByName(ExpenseDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpenseDialog)
    {
        ExpenseDialog->setWindowTitle(QCoreApplication::translate("ExpenseDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ExpenseDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Add Expense</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ExpenseDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Category:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ExpenseDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Amount:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ExpenseDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Date Spent:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("ExpenseDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Description:</span></p></body></html>", nullptr));
        btnOk->setText(QCoreApplication::translate("ExpenseDialog", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("ExpenseDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpenseDialog: public Ui_ExpenseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSEDIALOG_H

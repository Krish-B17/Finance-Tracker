/********************************************************************************
** Form generated from reading UI file 'removeexpensedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEEXPENSEDIALOG_H
#define UI_REMOVEEXPENSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RemoveExpenseDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *categoryComboBox;
    QLabel *labelExpenses;
    QListWidget *expensesListWidget;
    QPushButton *btnRemove;
    QPushButton *btnCancel;

    void setupUi(QDialog *RemoveExpenseDialog)
    {
        if (RemoveExpenseDialog->objectName().isEmpty())
            RemoveExpenseDialog->setObjectName("RemoveExpenseDialog");
        RemoveExpenseDialog->resize(480, 640);
        label = new QLabel(RemoveExpenseDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 411, 51));
        label_2 = new QLabel(RemoveExpenseDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 100, 201, 61));
        categoryComboBox = new QComboBox(RemoveExpenseDialog);
        categoryComboBox->setObjectName("categoryComboBox");
        categoryComboBox->setGeometry(QRect(240, 100, 181, 61));
        labelExpenses = new QLabel(RemoveExpenseDialog);
        labelExpenses->setObjectName("labelExpenses");
        labelExpenses->setGeometry(QRect(40, 160, 391, 61));
        expensesListWidget = new QListWidget(RemoveExpenseDialog);
        expensesListWidget->setObjectName("expensesListWidget");
        expensesListWidget->setGeometry(QRect(55, 220, 371, 192));
        btnRemove = new QPushButton(RemoveExpenseDialog);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setGeometry(QRect(130, 450, 201, 51));
        btnCancel = new QPushButton(RemoveExpenseDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(130, 520, 201, 51));

        retranslateUi(RemoveExpenseDialog);

        QMetaObject::connectSlotsByName(RemoveExpenseDialog);
    } // setupUi

    void retranslateUi(QDialog *RemoveExpenseDialog)
    {
        RemoveExpenseDialog->setWindowTitle(QCoreApplication::translate("RemoveExpenseDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RemoveExpenseDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Remove Expense </span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("RemoveExpenseDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Category:</span></p></body></html>", nullptr));
        labelExpenses->setText(QCoreApplication::translate("RemoveExpenseDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">EXPENSES IN SELECTED CATEGORY:</span></p></body></html>", nullptr));
        btnRemove->setText(QCoreApplication::translate("RemoveExpenseDialog", "Remove Selected Expense", nullptr));
        btnCancel->setText(QCoreApplication::translate("RemoveExpenseDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoveExpenseDialog: public Ui_RemoveExpenseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEEXPENSEDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'monthlyincomedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHLYINCOMEDIALOG_H
#define UI_MONTHLYINCOMEDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MonthlyIncomeDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *amountSpinBox;
    QLabel *label_3;
    QLineEdit *sourceEdit;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *MonthlyIncomeDialog)
    {
        if (MonthlyIncomeDialog->objectName().isEmpty())
            MonthlyIncomeDialog->setObjectName("MonthlyIncomeDialog");
        MonthlyIncomeDialog->resize(480, 640);
        label = new QLabel(MonthlyIncomeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 411, 51));
        label_2 = new QLabel(MonthlyIncomeDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 120, 201, 61));
        amountSpinBox = new QDoubleSpinBox(MonthlyIncomeDialog);
        amountSpinBox->setObjectName("amountSpinBox");
        amountSpinBox->setGeometry(QRect(230, 110, 211, 81));
        amountSpinBox->setMaximum(999999999999999945322333868247445125709646570021247924665841614848.000000000000000);
        label_3 = new QLabel(MonthlyIncomeDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 220, 201, 61));
        sourceEdit = new QLineEdit(MonthlyIncomeDialog);
        sourceEdit->setObjectName("sourceEdit");
        sourceEdit->setGeometry(QRect(230, 210, 201, 81));
        label_4 = new QLabel(MonthlyIncomeDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 320, 201, 61));
        dateEdit = new QDateEdit(MonthlyIncomeDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(230, 310, 211, 81));
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::TimeSpec::UTC);
        dateEdit->setDate(QDate(2025, 12, 18));
        btnOk = new QPushButton(MonthlyIncomeDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(40, 470, 191, 61));
        btnCancel = new QPushButton(MonthlyIncomeDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(250, 470, 191, 61));

        retranslateUi(MonthlyIncomeDialog);

        QMetaObject::connectSlotsByName(MonthlyIncomeDialog);
    } // setupUi

    void retranslateUi(QDialog *MonthlyIncomeDialog)
    {
        MonthlyIncomeDialog->setWindowTitle(QCoreApplication::translate("MonthlyIncomeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MonthlyIncomeDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Add Monthly Income</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MonthlyIncomeDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Monthly Income Amount: </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MonthlyIncomeDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Source of Income:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MonthlyIncomeDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Date Received:</span></p></body></html>", nullptr));
        btnOk->setText(QCoreApplication::translate("MonthlyIncomeDialog", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("MonthlyIncomeDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MonthlyIncomeDialog: public Ui_MonthlyIncomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHLYINCOMEDIALOG_H

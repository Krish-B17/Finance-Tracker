/********************************************************************************
** Form generated from reading UI file 'irregularincomedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IRREGULARINCOMEDIALOG_H
#define UI_IRREGULARINCOMEDIALOG_H

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

class Ui_IrregularIncomeDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *amountSpinBox;
    QLineEdit *sourceEdit;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QLineEdit *descriptionEdit;
    QLabel *label_5;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *IrregularIncomeDialog)
    {
        if (IrregularIncomeDialog->objectName().isEmpty())
            IrregularIncomeDialog->setObjectName("IrregularIncomeDialog");
        IrregularIncomeDialog->resize(480, 640);
        label = new QLabel(IrregularIncomeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 411, 51));
        label_2 = new QLabel(IrregularIncomeDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 201, 61));
        label_3 = new QLabel(IrregularIncomeDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 200, 201, 61));
        amountSpinBox = new QDoubleSpinBox(IrregularIncomeDialog);
        amountSpinBox->setObjectName("amountSpinBox");
        amountSpinBox->setGeometry(QRect(240, 100, 201, 71));
        amountSpinBox->setMaximum(9999999999999999830336967949613257980309080240684656321838454199566729216.000000000000000);
        sourceEdit = new QLineEdit(IrregularIncomeDialog);
        sourceEdit->setObjectName("sourceEdit");
        sourceEdit->setGeometry(QRect(240, 190, 181, 71));
        label_4 = new QLabel(IrregularIncomeDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 290, 201, 61));
        dateEdit = new QDateEdit(IrregularIncomeDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(240, 280, 211, 81));
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::TimeSpec::UTC);
        dateEdit->setDate(QDate(2025, 12, 18));
        descriptionEdit = new QLineEdit(IrregularIncomeDialog);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setGeometry(QRect(240, 360, 181, 71));
        label_5 = new QLabel(IrregularIncomeDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 370, 201, 61));
        btnOk = new QPushButton(IrregularIncomeDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(40, 500, 161, 61));
        btnCancel = new QPushButton(IrregularIncomeDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(270, 500, 161, 61));

        retranslateUi(IrregularIncomeDialog);

        QMetaObject::connectSlotsByName(IrregularIncomeDialog);
    } // setupUi

    void retranslateUi(QDialog *IrregularIncomeDialog)
    {
        IrregularIncomeDialog->setWindowTitle(QCoreApplication::translate("IrregularIncomeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("IrregularIncomeDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Add Irregular Income</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("IrregularIncomeDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Irregular Income Amount: </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("IrregularIncomeDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Source of Income: </span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("IrregularIncomeDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Date Received:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("IrregularIncomeDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Description:</span></p></body></html>", nullptr));
        btnOk->setText(QCoreApplication::translate("IrregularIncomeDialog", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("IrregularIncomeDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IrregularIncomeDialog: public Ui_IrregularIncomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IRREGULARINCOMEDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'categorydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYDIALOG_H
#define UI_CATEGORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CategoryDialog
{
public:
    QLineEdit *nameEdit;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *limitSpinBox;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_3;

    void setupUi(QDialog *CategoryDialog)
    {
        if (CategoryDialog->objectName().isEmpty())
            CategoryDialog->setObjectName("CategoryDialog");
        CategoryDialog->resize(480, 640);
        nameEdit = new QLineEdit(CategoryDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(230, 130, 211, 81));
        label = new QLabel(CategoryDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 130, 181, 81));
        label_2 = new QLabel(CategoryDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 240, 181, 81));
        limitSpinBox = new QDoubleSpinBox(CategoryDialog);
        limitSpinBox->setObjectName("limitSpinBox");
        limitSpinBox->setGeometry(QRect(230, 240, 221, 81));
        limitSpinBox->setMaximum(1000000000000000057857959942726969827393378689175040438172647424.000000000000000);
        okButton = new QPushButton(CategoryDialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(50, 440, 151, 51));
        cancelButton = new QPushButton(CategoryDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(280, 440, 151, 51));
        label_3 = new QLabel(CategoryDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 20, 411, 51));

        retranslateUi(CategoryDialog);

        QMetaObject::connectSlotsByName(CategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *CategoryDialog)
    {
        CategoryDialog->setWindowTitle(QCoreApplication::translate("CategoryDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CategoryDialog", "<html><head/><body><p><span style=\" font-size:24pt;\">Category Name: </span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("CategoryDialog", "<html><head/><body><p><span style=\" font-size:24pt;\">Budget Value: </span></p></body></html>", nullptr));
        okButton->setText(QCoreApplication::translate("CategoryDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("CategoryDialog", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("CategoryDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Add Category</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CategoryDialog: public Ui_CategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYDIALOG_H

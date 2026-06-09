/********************************************************************************
** Form generated from reading UI file 'editprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROFILEDIALOG_H
#define UI_EDITPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_EditProfileDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *nameEdit;
    QSpinBox *ageSpinBox;
    QDoubleSpinBox *budgetSpinBox;
    QDoubleSpinBox *goalSpinBox;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *EditProfileDialog)
    {
        if (EditProfileDialog->objectName().isEmpty())
            EditProfileDialog->setObjectName("EditProfileDialog");
        EditProfileDialog->resize(480, 640);
        label = new QLabel(EditProfileDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 411, 51));
        label_2 = new QLabel(EditProfileDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 200, 191, 81));
        label_3 = new QLabel(EditProfileDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 100, 191, 81));
        label_4 = new QLabel(EditProfileDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 290, 211, 81));
        label_5 = new QLabel(EditProfileDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 380, 191, 81));
        nameEdit = new QLineEdit(EditProfileDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(250, 100, 191, 81));
        ageSpinBox = new QSpinBox(EditProfileDialog);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setGeometry(QRect(250, 200, 201, 81));
        ageSpinBox->setMaximum(10000000);
        budgetSpinBox = new QDoubleSpinBox(EditProfileDialog);
        budgetSpinBox->setObjectName("budgetSpinBox");
        budgetSpinBox->setGeometry(QRect(250, 290, 201, 81));
        budgetSpinBox->setMaximum(1000000000000000072531436381529235126158374409646521955518210155479040.000000000000000);
        goalSpinBox = new QDoubleSpinBox(EditProfileDialog);
        goalSpinBox->setObjectName("goalSpinBox");
        goalSpinBox->setGeometry(QRect(250, 380, 201, 81));
        goalSpinBox->setMaximum(1000000000000000048346692115553659057528394845890514255872.000000000000000);
        btnSave = new QPushButton(EditProfileDialog);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(40, 520, 161, 61));
        btnCancel = new QPushButton(EditProfileDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(270, 520, 161, 61));

        retranslateUi(EditProfileDialog);

        QMetaObject::connectSlotsByName(EditProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *EditProfileDialog)
    {
        EditProfileDialog->setWindowTitle(QCoreApplication::translate("EditProfileDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditProfileDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">Edit Profile </span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("EditProfileDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:24pt;\">New Age: </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("EditProfileDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:24pt;\">New Name: </span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("EditProfileDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:24pt;\">Monthly Budget ($):</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("EditProfileDialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:24pt;\">Saving Goal ($):</span></p></body></html>", nullptr));
        btnSave->setText(QCoreApplication::translate("EditProfileDialog", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("EditProfileDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditProfileDialog: public Ui_EditProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROFILEDIALOG_H

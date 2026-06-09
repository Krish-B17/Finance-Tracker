/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QGroupBox *groupBox;
    QPushButton *btnAddCategory;
    QPushButton *btnAddMonthlyIncome;
    QPushButton *btnAddIrregularIncome;
    QPushButton *btnAddExpense;
    QPushButton *btnRemoveExpense;
    QPushButton *btnListAll;
    QPushButton *btnEditProfile;
    QPushButton *btnTogglePassword;
    QPushButton *btnChangePassword;
    QPushButton *btnExit;
    QPushButton *btnShowReport;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(480, 640);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-1, -31, 481, 631));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(15);
        widget->setFont(font);
        widget->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        titleLabel = new QLabel(widget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(0, 30, 479, 49));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(24);
        font1.setBold(true);
        titleLabel->setFont(font1);
        titleLabel->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        titleLabel->setFrameShape(QFrame::Shape::Box);
        titleLabel->setFrameShadow(QFrame::Shadow::Plain);
        titleLabel->setLineWidth(4);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        subtitleLabel = new QLabel(widget);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setGeometry(QRect(10, 80, 461, 31));
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(-1, 109, 481, 521));
        btnAddCategory = new QPushButton(groupBox);
        btnAddCategory->setObjectName("btnAddCategory");
        btnAddCategory->setGeometry(QRect(20, 40, 231, 41));
        btnAddMonthlyIncome = new QPushButton(groupBox);
        btnAddMonthlyIncome->setObjectName("btnAddMonthlyIncome");
        btnAddMonthlyIncome->setGeometry(QRect(20, 90, 231, 41));
        btnAddIrregularIncome = new QPushButton(groupBox);
        btnAddIrregularIncome->setObjectName("btnAddIrregularIncome");
        btnAddIrregularIncome->setGeometry(QRect(20, 140, 231, 41));
        btnAddExpense = new QPushButton(groupBox);
        btnAddExpense->setObjectName("btnAddExpense");
        btnAddExpense->setGeometry(QRect(20, 190, 231, 41));
        btnRemoveExpense = new QPushButton(groupBox);
        btnRemoveExpense->setObjectName("btnRemoveExpense");
        btnRemoveExpense->setGeometry(QRect(20, 240, 231, 41));
        btnListAll = new QPushButton(groupBox);
        btnListAll->setObjectName("btnListAll");
        btnListAll->setGeometry(QRect(20, 290, 231, 41));
        btnEditProfile = new QPushButton(groupBox);
        btnEditProfile->setObjectName("btnEditProfile");
        btnEditProfile->setGeometry(QRect(20, 340, 231, 41));
        btnTogglePassword = new QPushButton(groupBox);
        btnTogglePassword->setObjectName("btnTogglePassword");
        btnTogglePassword->setGeometry(QRect(20, 390, 231, 41));
        btnChangePassword = new QPushButton(groupBox);
        btnChangePassword->setObjectName("btnChangePassword");
        btnChangePassword->setGeometry(QRect(20, 440, 231, 41));
        btnExit = new QPushButton(groupBox);
        btnExit->setObjectName("btnExit");
        btnExit->setGeometry(QRect(290, 190, 151, 71));
        btnShowReport = new QPushButton(groupBox);
        btnShowReport->setObjectName("btnShowReport");
        btnShowReport->setGeometry(QRect(290, 280, 151, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setUnderline(true);
        btnShowReport->setFont(font2);
        btnShowReport->setAutoFillBackground(false);
        btnShowReport->setAutoDefault(false);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnShowReport->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Finance Tracker", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("MainWindow", "Welcome, <user>. I hope you are doing well.", nullptr));
        groupBox->setTitle(QString());
        btnAddCategory->setText(QCoreApplication::translate("MainWindow", "1. Add category", nullptr));
        btnAddMonthlyIncome->setText(QCoreApplication::translate("MainWindow", "2. Add monthly income", nullptr));
        btnAddIrregularIncome->setText(QCoreApplication::translate("MainWindow", "3. Add irregular income", nullptr));
        btnAddExpense->setText(QCoreApplication::translate("MainWindow", "4. Add expense", nullptr));
        btnRemoveExpense->setText(QCoreApplication::translate("MainWindow", "5. Remove expense", nullptr));
        btnListAll->setText(QCoreApplication::translate("MainWindow", "6. List Everything", nullptr));
        btnEditProfile->setText(QCoreApplication::translate("MainWindow", "7. Edit profile (name, etc)", nullptr));
        btnTogglePassword->setText(QCoreApplication::translate("MainWindow", "8. Toggle Password Protection", nullptr));
        btnChangePassword->setText(QCoreApplication::translate("MainWindow", "9. Change Password", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWindow", "0. Save & Exit", nullptr));
        btnShowReport->setText(QCoreApplication::translate("MainWindow", "Display Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

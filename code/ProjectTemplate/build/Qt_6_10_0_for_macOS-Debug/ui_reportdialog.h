/********************************************************************************
** Form generated from reading UI file 'reportdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTDIALOG_H
#define UI_REPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportDialog
{
public:
    QLabel *titleLabel;
    QWidget *chartContainer;
    QPushButton *btnClose;
    QTextEdit *plainTextReport;

    void setupUi(QDialog *ReportDialog)
    {
        if (ReportDialog->objectName().isEmpty())
            ReportDialog->setObjectName("ReportDialog");
        ReportDialog->resize(480, 640);
        titleLabel = new QLabel(ReportDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(0, 0, 479, 49));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(24);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        titleLabel->setFrameShape(QFrame::Shape::Box);
        titleLabel->setFrameShadow(QFrame::Shadow::Plain);
        titleLabel->setLineWidth(4);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        chartContainer = new QWidget(ReportDialog);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setGeometry(QRect(10, 440, 321, 191));
        btnClose = new QPushButton(ReportDialog);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(340, 510, 121, 51));
        plainTextReport = new QTextEdit(ReportDialog);
        plainTextReport->setObjectName("plainTextReport");
        plainTextReport->setGeometry(QRect(10, 60, 461, 391));
        plainTextReport->setReadOnly(true);

        retranslateUi(ReportDialog);

        QMetaObject::connectSlotsByName(ReportDialog);
    } // setupUi

    void retranslateUi(QDialog *ReportDialog)
    {
        ReportDialog->setWindowTitle(QCoreApplication::translate("ReportDialog", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("ReportDialog", "Financial Report", nullptr));
        btnClose->setText(QCoreApplication::translate("ReportDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportDialog: public Ui_ReportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'listalldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTALLDIALOG_H
#define UI_LISTALLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ListAllDialog
{
public:
    QLabel *titleLabel;
    QLabel *label;
    QTextEdit *summaryTextEdit;
    QPushButton *closeButton;

    void setupUi(QDialog *ListAllDialog)
    {
        if (ListAllDialog->objectName().isEmpty())
            ListAllDialog->setObjectName("ListAllDialog");
        ListAllDialog->resize(480, 640);
        titleLabel = new QLabel(ListAllDialog);
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
        label = new QLabel(ListAllDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 441, 31));
        summaryTextEdit = new QTextEdit(ListAllDialog);
        summaryTextEdit->setObjectName("summaryTextEdit");
        summaryTextEdit->setGeometry(QRect(10, 90, 461, 541));
        summaryTextEdit->setReadOnly(true);
        closeButton = new QPushButton(ListAllDialog);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(370, 600, 91, 31));

        retranslateUi(ListAllDialog);

        QMetaObject::connectSlotsByName(ListAllDialog);
    } // setupUi

    void retranslateUi(QDialog *ListAllDialog)
    {
        ListAllDialog->setWindowTitle(QCoreApplication::translate("ListAllDialog", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("ListAllDialog", "Budget Overview", nullptr));
        label->setText(QCoreApplication::translate("ListAllDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">Full overview of all your finance so far ...</span></p></body></html>", nullptr));
        closeButton->setText(QCoreApplication::translate("ListAllDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListAllDialog: public Ui_ListAllDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTALLDIALOG_H

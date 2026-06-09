#include "monthlyincomedialog.h"
#include "ui_monthlyincomedialog.h"

#include <QMessageBox>

MonthlyIncomeDialog::MonthlyIncomeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MonthlyIncomeDialog)
{
    ui->setupUi(this);

    // sensible defaults
    ui->amountSpinBox->setMinimum(0.0);
    ui->amountSpinBox->setMaximum(1e9);
    ui->amountSpinBox->setDecimals(2);

    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDate(QDate::currentDate());
}

MonthlyIncomeDialog::~MonthlyIncomeDialog()
{
    delete ui;
}

double MonthlyIncomeDialog::amount() const
{
    return ui->amountSpinBox->value();
}

QString MonthlyIncomeDialog::source() const
{
    return ui->sourceEdit->text().trimmed();
}

QDate MonthlyIncomeDialog::dateReceived() const
{
    return ui->dateEdit->date();
}

void MonthlyIncomeDialog::on_btnOk_clicked()
{
    if (source().isEmpty()) {
        QMessageBox::warning(this, "Missing info",
                             "Please enter a source for this income.");
        return;
    } else {
        QMessageBox::warning(
            this,
            "Saved",
            "Monthly income has been saved."
            );
    }
    accept();   // closes dialog with QDialog::Accepted
}

void MonthlyIncomeDialog::on_btnCancel_clicked()
{
    reject();   // closes dialog with QDialog::Rejected
}

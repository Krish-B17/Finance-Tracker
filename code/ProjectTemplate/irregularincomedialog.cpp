#include "irregularincomedialog.h"
#include "ui_irregularincomedialog.h"

#include <QMessageBox>

// Constructor for IrregularIncomeDialog. Creates the dialog and initializes UI components
IrregularIncomeDialog::IrregularIncomeDialog(QWidget *parent)
    : QDialog(parent)                     // initialize base QDialog
    , ui(new Ui::IrregularIncomeDialog)   // allocate UI object
{
    ui->setupUi(this);                    // setup widgets from designer file

    // Configure amount input for valid financial values
    ui->amountSpinBox->setMinimum(0.0);          // disallow negative entries
    ui->amountSpinBox->setMaximum(100000000.0);  // cap at a large value
    ui->amountSpinBox->setDecimals(2);           // allow cents precision

    // Configure date selector widget
    ui->dateEdit->setCalendarPopup(true);        // open calendar when clicked
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");// standardized formatting
    ui->dateEdit->setDate(QDate::currentDate()); // default pre-fill: today
}

// Destructor - clean up UI resources allocated on heap
IrregularIncomeDialog::~IrregularIncomeDialog()
{
    delete ui;
}

// Getter: return entered income amount
double IrregularIncomeDialog::amount() const
{
    return ui->amountSpinBox->value();
}

// Getter: return text for income source
QString IrregularIncomeDialog::source() const
{
    return ui->sourceEdit->text().trimmed();
}

// Getter: return selected date for income
QDate IrregularIncomeDialog::dateReceived() const
{
    return ui->dateEdit->date();
}

// Getter: return optional text description
QString IrregularIncomeDialog::description() const
{
    return ui->descriptionEdit->text().trimmed();
}

// Slot for OK button click
void IrregularIncomeDialog::on_btnOk_clicked()
{
    // Validate amount entered
    if (amount() <= 0.0) {
        QMessageBox::warning(this, "Invalid amount",
                             "Amount must be greater than zero.");
        return;
    }

    // Validate a source is provided
    if (source().isEmpty()) {
        QMessageBox::warning(this, "Missing source",
                             "Please enter a source for this income.");
        return;
    }

    // Validate date
    if (!dateReceived().isValid()) {
        QMessageBox::warning(this, "Invalid date",
                             "Please enter a valid date.");
        return;
    }

    accept();   // close dialog and return Accepted to caller
}

// Slot for Cancel button click
void IrregularIncomeDialog::on_btnCancel_clicked()
{
    reject();   // close dialog and return Rejected to caller
}

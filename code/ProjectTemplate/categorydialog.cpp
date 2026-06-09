#include "categorydialog.h"
#include "ui_categorydialog.h"

#include <QMessageBox>

// Constructor for CategoryDialog parent = widget that opened this dialog
CategoryDialog::CategoryDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CategoryDialog)
{
    ui->setupUi(this);

    // Configure the limit input spin box (numeric input)
    ui->limitSpinBox->setMinimum(0.0);  // category budget cannot be negative
    ui->limitSpinBox->setMaximum(1e9);  // prevent extremely large values
    ui->limitSpinBox->setDecimals(2);  // allow cents (i.e., 2 decimal places)
}

// Destructor - clean up dynamically allocated UI memory
CategoryDialog::~CategoryDialog()
{
    delete ui;
}

// Getter function for category name trim whitespace and return text from QLineEdit
QString CategoryDialog::categoryName() const
{
    return ui->nameEdit->text().trimmed();
}

// Getter function for budget limit return numeric value from spinbox
double CategoryDialog::budgetLimit() const
{
    return ui->limitSpinBox->value();
}

// Slot for OK button click Validate input then close dialog with Accepted status
void CategoryDialog::on_okButton_clicked()
{
    if (categoryName().isEmpty()) {
        QMessageBox::warning(this, "Missing name",
                             "Please enter a category name.");
        return;
    } else {
        QMessageBox::warning(this, "Saved",
                             "Category has been added.");
    }
    accept();
}

// Slot for Cancel button click. Close dialog without saving data
void CategoryDialog::on_cancelButton_clicked()
{
    reject();
}

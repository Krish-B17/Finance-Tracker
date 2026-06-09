#include "expensedialog.h"
#include "ui_expensedialog.h"

#include <QMessageBox>

// Constructor for ExpenseDialog. Takes a list of existing categories and populates UI fields
ExpenseDialog::ExpenseDialog(const QVector<Category> &categories,
                             QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ExpenseDialog)
{
    ui->setupUi(this);

    // Configure the spinbox used to enter expense amount
    ui->amountSpinBox->setMinimum(0.0);          // expense cannot be negative
    ui->amountSpinBox->setMaximum(100000000.0);  // guard against extreme input
    ui->amountSpinBox->setDecimals(2);           // allow cents precision

    // Configure date entry widget
    ui->dateEdit->setCalendarPopup(true);        // popup date picker
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");// set visual format
    ui->dateEdit->setDate(QDate::currentDate()); // default to today

    // Populate category dropdown list. Also track mapping to real category indices
    m_categoryIndices.clear();
    for (int i = 0; i < categories.size(); ++i) {
        ui->categoryComboBox->addItem(categories[i].getName());
        m_categoryIndices.push_back(i);
    }

    // Disable OK button if no categories exist. MainWindow normally protects against this state, but this is a backup check
    if (categories.isEmpty()) {
        ui->btnOk->setEnabled(false);
    }
}

// Destructor - free allocated UI resources
ExpenseDialog::~ExpenseDialog()
{
    delete ui;
}

// Return true list index of selected category
// Handles case where combo box index and category vector index differ
int ExpenseDialog::selectedCategoryIndex() const
{
    int comboIndex = ui->categoryComboBox->currentIndex();
    if (comboIndex < 0 || comboIndex >= m_categoryIndices.size())
        return -1;                       // invalid selection
    return m_categoryIndices[comboIndex];// mapped index
}

// Getter: return entered amount
double ExpenseDialog::amount() const
{
    return ui->amountSpinBox->value();
}

// Getter: return user-selected date
QDate ExpenseDialog::date() const
{
    return ui->dateEdit->date();
}

// Getter: return trimmed description text
QString ExpenseDialog::description() const
{
    return ui->descriptionEdit->text().trimmed();
}

// OK button handler
void ExpenseDialog::on_btnOk_clicked()
{
    // Validation: ensure category selected
    if (selectedCategoryIndex() < 0) {
        QMessageBox::warning(this, "No category",
                             "Please choose a category.");
        return;
    }

    // Validation: ensure positive amount
    if (amount() <= 0.0) {
        QMessageBox::warning(this, "Invalid amount",
                             "Amount must be greater than zero.");
        return;
    }

    // Validation: ensure date is recognized by Qt
    if (!date().isValid()) {
        QMessageBox::warning(this, "Invalid date",
                             "Please enter a valid date.");
        return;
    }

    accept();
}

// Cancel button handler
void ExpenseDialog::on_btnCancel_clicked()
{
    reject();   // close dialog with Rejected state
}

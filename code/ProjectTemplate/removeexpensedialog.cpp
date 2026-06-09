#include "removeexpensedialog.h"
#include "ui_removeexpensedialog.h"

#include <QMessageBox>

RemoveExpenseDialog::RemoveExpenseDialog(const QVector<Category> &categories,
                                         QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveExpenseDialog)
    , m_categories(categories)
{
    ui->setupUi(this);

    // Fill the category combo with current categories
    for (int i = 0; i < m_categories.size(); ++i) {
        ui->categoryComboBox->addItem(m_categories[i].getName());
    }

    if (!m_categories.isEmpty()) {
        ui->categoryComboBox->setCurrentIndex(0);
        refreshExpenseList(0);
    }
}

RemoveExpenseDialog::~RemoveExpenseDialog()
{
    delete ui;
}

void RemoveExpenseDialog::refreshExpenseList(int categoryIndex)
{
    ui->expensesListWidget->clear();

    if (categoryIndex < 0 || categoryIndex >= m_categories.size())
        return;

    const auto &exps = m_categories[categoryIndex].getExpenses();

    for (int i = 0; i < exps.size(); ++i) {
        const Expense &e = exps[i];
        QString line = QString("%1: - $%2 on %3 | %4")
                           .arg(i)  // expense index inside this category
                           .arg(e.getAmount(), 0, 'f', 2)
                           .arg(e.getDate().toString("yyyy-MM-dd"))
                           .arg(e.getDesc());
        ui->expensesListWidget->addItem(line);
    }
}

int RemoveExpenseDialog::selectedCategoryIndex() const
{
    return ui->categoryComboBox->currentIndex();
}

int RemoveExpenseDialog::selectedExpenseIndex() const
{
    return ui->expensesListWidget->currentRow();
}

void RemoveExpenseDialog::on_categoryComboBox_currentIndexChanged(int index)
{
    refreshExpenseList(index);
}

void RemoveExpenseDialog::on_btnRemove_clicked()
{
    if (selectedCategoryIndex() < 0 ||
        selectedCategoryIndex() >= m_categories.size()) {
        QMessageBox::warning(this, "No category",
                             "Please select a category.");
        return;
    }

    if (selectedExpenseIndex() < 0) {
        QMessageBox::warning(this, "No expense selected",
                             "Please select an expense to remove.");
        return;
    }

    accept();   // dialog result = Accepted, MainWindow will actually remove it
}

void RemoveExpenseDialog::on_btnCancel_clicked()
{
    reject();   // dialog result = Rejected
}

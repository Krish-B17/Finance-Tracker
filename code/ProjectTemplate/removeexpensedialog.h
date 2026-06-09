#ifndef REMOVEEXPENSEDIALOG_H
#define REMOVEEXPENSEDIALOG_H

#include <QDialog>
#include <QVector>

#include "category.h"
#include "expense.h"

namespace Ui {
class RemoveExpenseDialog;
}

class RemoveExpenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveExpenseDialog(const QVector<Category> &categories,
                                 QWidget *parent = nullptr);
    ~RemoveExpenseDialog();

    int selectedCategoryIndex() const;  // index in the categories vector
    int selectedExpenseIndex() const;   // index in that category’s expense list

private slots:
    void on_categoryComboBox_currentIndexChanged(int index);
    void on_btnRemove_clicked();
    void on_btnCancel_clicked();

private:
    Ui::RemoveExpenseDialog *ui;
    const QVector<Category> &m_categories;

    void refreshExpenseList(int categoryIndex);
};

#endif // REMOVEEXPENSEDIALOG_H

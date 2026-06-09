#ifndef EXPENSEDIALOG_H
#define EXPENSEDIALOG_H

#include <QDialog>
#include <QVector>
#include <QDate>

#include "category.h"

namespace Ui {
class ExpenseDialog;
}

class ExpenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExpenseDialog(const QVector<Category> &categories,
                           QWidget *parent = nullptr);
    ~ExpenseDialog();

    // getters for the chosen/entered values
    int     selectedCategoryIndex() const;   // index in m_categories
    double  amount() const;
    QDate   date() const;
    QString description() const;

private slots:
    void on_btnOk_clicked();
    void on_btnCancel_clicked();

private:
    Ui::ExpenseDialog *ui;

    // store mapping from combo index -> real category index
    QVector<int> m_categoryIndices;
};

#endif // EXPENSEDIALOG_H

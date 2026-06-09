#ifndef LISTALLDIALOG_H
#define LISTALLDIALOG_H

#include <QDialog>
#include <QVector>
#include <QString>

#include "profile.h"
#include "category.h"
#include "expense.h"
#include "MonthlyIncome.h"
#include "irregularincome.h"

namespace Ui {
class ListAllDialog;
}

class ListAllDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ListAllDialog(const Profile &profile,
                           const QVector<Category> &categories,
                           const QVector<Expense> &expenses,
                           const QVector<MonthlyIncome> &monthlyIncomes,
                           const QVector<IrregularIncome> &irregularIncomes,
                           QWidget *parent = nullptr);
    ~ListAllDialog();

private:
    Ui::ListAllDialog *ui;

    static QString money(double v);
    QString buildSummaryText(const Profile &profile,
                             const QVector<Category> &categories,
                             const QVector<Expense> &expenses,
                             const QVector<MonthlyIncome> &monthlyIncomes,
                             const QVector<IrregularIncome> &irregularIncomes) const;
};

#endif // LISTALLDIALOG_H

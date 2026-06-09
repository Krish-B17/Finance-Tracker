#ifndef MONTHLYINCOMEDIALOG_H
#define MONTHLYINCOMEDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class MonthlyIncomeDialog;
}

class MonthlyIncomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MonthlyIncomeDialog(QWidget *parent = nullptr);
    ~MonthlyIncomeDialog();

    double  amount() const;
    QString source() const;
    QDate   dateReceived() const;

private slots:
    void on_btnOk_clicked();
    void on_btnCancel_clicked();

private:
    Ui::MonthlyIncomeDialog *ui;
};

#endif

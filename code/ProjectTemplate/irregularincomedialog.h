#ifndef IRREGULARINCOMEDIALOG_H
#define IRREGULARINCOMEDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class IrregularIncomeDialog;
}

class IrregularIncomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IrregularIncomeDialog(QWidget *parent = nullptr);
    ~IrregularIncomeDialog();

    double  amount() const;
    QString source() const;
    QDate   dateReceived() const;
    QString description() const;

private slots:
    void on_btnOk_clicked();
    void on_btnCancel_clicked();

private:
    Ui::IrregularIncomeDialog *ui;
};

#endif // IRREGULARINCOMEDIALOG_H

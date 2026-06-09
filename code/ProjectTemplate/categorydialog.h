#ifndef CATEGORYDIALOG_H
#define CATEGORYDIALOG_H

#include <QDialog>

namespace Ui {
class CategoryDialog;
}

class CategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CategoryDialog(QWidget *parent = nullptr);
    ~CategoryDialog();

    QString categoryName() const;
    double  budgetLimit() const;

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CategoryDialog *ui;
};

#endif

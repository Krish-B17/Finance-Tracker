#ifndef CONFIRMPASSWORDDIALOG_H
#define CONFIRMPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmPasswordDialog;
}

class ConfirmPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmPasswordDialog(QWidget *parent = nullptr);
    ~ConfirmPasswordDialog();

    QString password() const;

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::ConfirmPasswordDialog *ui;
};

#endif // CONFIRMPASSWORDDIALOG_H

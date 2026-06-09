#ifndef SETPASSWORDDIALOG_H
#define SETPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class SetPasswordDialog;
}

class SetPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetPasswordDialog(QWidget *parent = nullptr);
    ~SetPasswordDialog();

    QString password() const;   // returns the confirmed password

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::SetPasswordDialog *ui;
};

#endif // SETPASSWORDDIALOG_H

#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class ChangePasswordDialog;
}

class ChangePasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordDialog(QWidget *parent = nullptr);
    ~ChangePasswordDialog();

    QString oldPassword() const;
    QString newPassword() const;
    QString confirmPassword() const;

private:
    Ui::ChangePasswordDialog *ui;
};

#endif // CHANGEPASSWORDDIALOG_H

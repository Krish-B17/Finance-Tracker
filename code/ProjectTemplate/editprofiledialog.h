#ifndef EDITPROFILEDIALOG_H
#define EDITPROFILEDIALOG_H

#include <QDialog>
#include "profile.h"

namespace Ui {
class EditProfileDialog;
}

class EditProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditProfileDialog(const Profile &profile,
                               QWidget *parent = nullptr);
    ~EditProfileDialog();

    QString newName() const;
    int     newAge() const;
    double  newMonthlyBudget() const;
    double  newSavingGoal() const;

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::EditProfileDialog *ui;
};

#endif // EDITPROFILEDIALOG_H

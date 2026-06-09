#ifndef NAMEDIALOG_H
#define NAMEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class NameDialog;
}
QT_END_NAMESPACE

class NameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NameDialog(QWidget *parent = nullptr);
    ~NameDialog();

    QString userName() const;
    int     userAge() const;
    double  monthlyBudget() const;
    double  savingGoal() const;
    bool    passwordProtectionEnabled() const;
    QString password() const;

private slots:
    void on_continueButton_clicked();

private:
    Ui::NameDialog *ui;
};

#endif // NAMEDIALOG_H

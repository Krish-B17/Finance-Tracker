#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "profile.h"
#include "category.h"
#include "expense.h"
#include "MonthlyIncome.h"
#include "irregularincome.h"
#include "report.h"
#include "reportdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString &dataFilePath,
                        const Profile &profile,
                        const QVector<Category> &categories,
                        const QVector<Expense> &expenses,
                        const QVector<MonthlyIncome> &monthlyIncomes,
                        const QVector<IrregularIncome> &irregularIncomes,
                        QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAddCategory_clicked();
    void on_btnAddMonthlyIncome_clicked();
    void on_btnAddIrregularIncome_clicked();
    void on_btnAddExpense_clicked();
    void on_btnRemoveExpense_clicked();
    void on_btnListAll_clicked();
    void on_btnEditProfile_clicked();
    void on_btnTogglePassword_clicked();
    void on_btnChangePassword_clicked();
    void on_btnShowReport_clicked();
    void on_btnExit_clicked();

private:
    void updateHeader();
    void saveAndExit();

    Ui::MainWindow *ui;

    Profile m_profile;
    QVector<Category>        m_categories;
    QVector<Expense>         m_expenses;
    QVector<MonthlyIncome>   m_monthlyIncomes;
    QVector<IrregularIncome> m_irregularIncomes;
    QString m_dataFilePath;
};

#endif // MAINWINDOW_H

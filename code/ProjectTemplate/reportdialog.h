#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include "report.h"
#include "profile.h"          // whatever your Profile header is called

namespace Ui {
class ReportDialog;
}

class ReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportDialog(QWidget *parent = nullptr);
    ~ReportDialog();

    // Call this after constructing the dialog
    void setData(const Profile &profile,
                 const ReportSummary &summary);

private slots:
    void on_btnClose_clicked();

private:
    Ui::ReportDialog *ui;

    QString buildReportText(const Profile &profile,
                            const ReportSummary &r) const;
    void buildChart(const ReportSummary &r);
};

#endif // REPORTDIALOG_H

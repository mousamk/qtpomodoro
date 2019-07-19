#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private:
    void prepareConnections();

protected:
    void showEvent(QShowEvent* event);

signals:
    void dialogShown();

private Q_SLOTS:
    void loadSettingsToUi();
    void saveSettingsFromUi();
    void onOkClicked();

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H

#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "data/settings.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    prepareConnections();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::prepareConnections()
{
    connect(this, &SettingsDialog::dialogShown, this, &SettingsDialog::loadSettingsToUi);
    connect(ui->okButton, &QPushButton::clicked, this, &SettingsDialog::onOkClicked);
}

void SettingsDialog::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    emit dialogShown();
}

void SettingsDialog::onOkClicked()
{
    saveSettingsFromUi();
    this->close();
}

void SettingsDialog::loadSettingsToUi()
{
    Settings* settings = Settings::getInstance();
    ui->sessionDurationSpin->setValue(settings->loadPomodoroRunMinutes());
    ui->breakDurationSpin->setValue(settings->loadPomodoroBreakMinutes());
    ui->longBreakDurationSpin->setValue(settings->loadPomodoroLongBreakMinutes());
    ui->sessionNumberSpin->setValue(settings->loadPomodoroRunCounts());
}

void SettingsDialog::saveSettingsFromUi()
{
    Settings* settings = Settings::getInstance();
    settings->savePomodoroRunMinutes(ui->sessionDurationSpin->value());
    settings->savePomodoroBreakMinutes(ui->breakDurationSpin->value());
    settings->savePomodoroLongBreakMinutes(ui->longBreakDurationSpin->value());
    settings->savePomodoroRunCounts(ui->sessionNumberSpin->value());
}

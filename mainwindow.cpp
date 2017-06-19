#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSettings();
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    initPomodoro();
    setupConnections();
    initViews();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    connect(ui->btnAction, SIGNAL(clicked()), pomodoro, SLOT(handleMainAction()));
    connect(pomodoro, SIGNAL(timeUpdated(int,int)), this, SLOT(updateTime(int,int)));
    connect(pomodoro, SIGNAL(statusChanged()), this, SLOT(updateStatus()));
}

void MainWindow::initViews()
{
    ui->lblMinute->setText(QString::number(Settings::getInstance()->loadPomodoroRunMinutes()));
}

void MainWindow::updateTime(int min, int sec)
{
    ui->lblMinute->setText(QString::number(min));
    ui->lblSecond->setText(QString::number(sec));
}

void MainWindow::readSettings()
{
    restoreGeometry(Settings::getInstance()->loadMainWindowGeometry());
    restoreState(Settings::getInstance()->loadMainWindowState());
}

void MainWindow::closeEvent(QCloseEvent*)
{
    Settings::getInstance()->saveMainWindowGeometry(saveGeometry());
    Settings::getInstance()->saveMainWindowState(saveState());
}

void MainWindow::initPomodoro()
{
    pomodoro = new Pomodoro(this);
}

void MainWindow::updateStatus()
{
    ui->backFrame->setStyleSheet(QString("background-color: ") + pomodoro->getBackgroundColor() + ";");
    ui->btnAction->setText(pomodoro->getMainActionText());
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons().testFlag(Qt::LeftButton) && mMoving)
        this->move(this->pos() + (event->pos() - mLastMousePosition));
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        mMoving = false;
}

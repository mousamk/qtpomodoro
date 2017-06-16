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
    connect(ui->btnAction, SIGNAL(clicked()), this, SLOT(onActionButtonClick()));
    connect(pomodoro, SIGNAL(timeUpdated(int,int)), this, SLOT(updateTime(int,int)));
    connect(pomodoro, SIGNAL(statusChanged(PomodoroStatus)), this, SLOT(updateStatus(PomodoroStatus)));
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

void MainWindow::onActionButtonClick()
{
    /*if (!pomodoro->isRunning())
        pomodoro->start();
    else
        pomodoro->stop();*/
    switch (pomodoro->getStatus())
    {
    case WaitingToStart:
    case WaitingToRun:
    case WaitingToBreak:
        pomodoro->goNextState();
        break;

    case Running:
    case BreakRunning:
        pomodoro->stop();
        break;
    }
}

void MainWindow::updateStatus(PomodoroStatus status)
{
    switch (status)
    {
    case WaitingToStart:
        ui->backFrame->setStyleSheet("background-color: #FFFFFF;");
        ui->btnAction->setText("Start");
        break;

    case WaitingToRun:
        ui->backFrame->setStyleSheet("background-color: #FF0000;");
        ui->btnAction->setText("Start");
        break;

    case Running:
        ui->backFrame->setStyleSheet("background-color: #FF0000;");
        ui->btnAction->setText("Stop");
        break;

    case WaitingToBreak:
        ui->backFrame->setStyleSheet("background-color: #00FF00;");
        ui->btnAction->setText("Break");
        break;

    case BreakRunning:
        ui->backFrame->setStyleSheet("background-color: #00FF00;");
        ui->btnAction->setText("Stop");
    }
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

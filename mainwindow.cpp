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
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    connect(ui->btnAction, SIGNAL(clicked()), this, SLOT(onActionButtonClick()));
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

void MainWindow::onActionButtonClick()
{
    qDebug() << "Test";
}

void MainWindow::initPomodoro()
{
    pomodoro = new Pomodoro(this);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}

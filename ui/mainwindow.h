#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "entity/pomodoro.h"


namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent* event);


public slots:
    void updateTime(int min, int sec);
    void updateStatus();


protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


private:
    void readSettings();
    void setupConnections();
    void initPomodoro();
    void initViews();


private:
    Ui::MainWindow *ui;
    QPoint mLastMousePosition;
    bool mMoving;
    Pomodoro* pomodoro;
};

#endif // MAINWINDOW_H

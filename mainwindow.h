#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>


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
    void onActionButtonClick();


protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


private:
    void readSettings();
    void setupConnections();


private:
    Ui::MainWindow *ui;
    QPoint mLastMousePosition;
    bool mMoving;
};

#endif // MAINWINDOW_H

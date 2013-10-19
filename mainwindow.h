#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void shapeChanged();
    void penChaneged();
    void brushChanged();

private:

};

#endif // MAINWINDOW_H

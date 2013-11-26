#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableView;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void showWindowTitle(const QString& title);

private:
  QTableView *tableView;
};

#endif // MAINWINDOW_H

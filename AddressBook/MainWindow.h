#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AddressWidget.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
//  void updateSelection(const QItemSelection &selection);
  void openFile();
  void saveFile();

private:
  void createMenus();

  AddressWidget *addressWidget;
  QMenu *fileMenu;
  QAction *openAction;
  QAction *saveAction;
  QAction *exitAction;
};

#endif // MAINWINDOW_H

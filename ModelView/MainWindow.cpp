#include "MainWindow.h"
#include <QtWidgets>
#include <MyModel.h>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  QTableView* tableView = new QTableView();
  MyModel* myModel = new MyModel();
  tableView->setModel(myModel);

  setCentralWidget(tableView);
}

MainWindow::~MainWindow()
{

}

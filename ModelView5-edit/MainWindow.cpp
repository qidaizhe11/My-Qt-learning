
#include "MainWindow.h"
#include <QtWidgets>
#include "MyModel.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  tableView = new QTableView(this);
  setCentralWidget(tableView);
  QAbstractTableModel *myModel = new MyModel(this);
  tableView->setModel(myModel);

  connect(myModel, SIGNAL(editCompleted(const QString&)), this,
          SLOT(setWindowTitle(QString)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::showWindowTitle(const QString &title)
{
  setWindowTitle(title);
}

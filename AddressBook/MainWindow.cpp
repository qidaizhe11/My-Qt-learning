
#include "MainWindow.h"
//#include <QAction>
//#include <QFileDialog>
//#include <QMenuBar>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  addressWidget = new AddressWidget;
  setCentralWidget(addressWidget);
  createMenus();
  setWindowTitle(tr("Address Book"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenus()
{
  fileMenu = menuBar()->addMenu(tr("&File"));

  openAction = new QAction(tr("&Open..."), this);
  fileMenu->addAction(openAction);
  connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

  saveAction = new QAction(tr("&Save As..."), this);
  fileMenu->addAction(saveAction);
  connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
}

void MainWindow::openFile()
{
  QString fileName = QFileDialog::getOpenFileName(this);
  if (!fileName.isEmpty())
    addressWidget->readFromFile(fileName);
}

void MainWindow::saveFile()
{
  QString fileName = QFileDialog::getSaveFileName(this);
  if (!fileName.isEmpty())
    addressWidget->writeToFile(fileName);
}

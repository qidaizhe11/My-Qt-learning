
#include "MainWindow6.h"
#include <QtWidgets>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QItemSelectionModel>

const int ROWS = 2;
const int COLUMNS = 3;

MainWindow6::MainWindow6(QWidget *parent) :
  QMainWindow(parent)
{
  treeView = new QTreeView(this);
  setCentralWidget(treeView);
  standardModel = new QStandardItemModel;

  QStandardItem *rootNode = standardModel->invisibleRootItem();

  QStandardItem *americaItem = new QStandardItem("America");
  QStandardItem *mexicoItem = new QStandardItem("Mexico");
  QStandardItem *usaItem = new QStandardItem("USA");
  QStandardItem *bostonItem = new QStandardItem("Boston");
  QStandardItem *europeItem = new QStandardItem("Europe");
  QStandardItem *italyItem = new QStandardItem("Italy");
  QStandardItem *romeItem = new QStandardItem("Rome");
  QStandardItem *veronaItem = new QStandardItem("Verona");

  rootNode->appendRow(americaItem);
  rootNode->appendRow(europeItem);
  americaItem->appendRow(mexicoItem);
  americaItem->appendRow(usaItem);
  usaItem->appendRow(bostonItem);
  europeItem->appendRow(italyItem);
  italyItem->appendRow(romeItem);
  italyItem->appendRow(veronaItem);

  treeView->setModel(standardModel);
  treeView->expandAll();

  QItemSelectionModel *selectionModel = treeView->selectionModel();
  connect(selectionModel,
          SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
          this,
          SLOT(selectionChangedSlot(QItemSelection,QItemSelection)));

//  QList<QStandardItem *> preparedRow = prepareRow("first", "second", "third");
//  QStandardItem *item = standardModel->invisibleRootItem();
//  item->appendRow(preparedRow);

//  QList<QStandardItem *> secondRow = prepareRow("111", "222", "333");
//  preparedRow.first()->appendRow(secondRow);

//  treeView->setModel(standardModel);
//  treeView->expandAll();
}

void MainWindow6::selectionChangedSlot(const QItemSelection &/*newSelection*/,
                                       const QItemSelection &/*oldSelection*/)
{
  const QModelIndex index = treeView->selectionModel()->currentIndex();
  QString selectedText = index.data(Qt::DisplayRole).toString();
  int hierarchyLevel = 1;
  QModelIndex seekRoot = index;
  while (seekRoot.parent() != QModelIndex()) {
    seekRoot = seekRoot.parent();
    hierarchyLevel++;
  }
  QString showString = QString("%1, Level %2").arg(selectedText)
      .arg(hierarchyLevel);
  setWindowTitle(showString);
}

QList<QStandardItem *> MainWindow6::prepareRow(const QString &first,
                                               const QString &second,
                                               const QString &third)
{
  QList<QStandardItem *> rowItems;
  rowItems << new QStandardItem(first);
  rowItems << new QStandardItem(second);
  rowItems << new QStandardItem(third);
  return rowItems;
}


#include "AddressWidget.h"
#include <QtWidgets>

AddressWidget::AddressWidget(QWidget *parent) :
  QTabWidget(parent)
{
  table = new TableModel(this);

  setupTabs();
}

void AddressWidget::addEntry()
{

}

void AddressWidget::addEntry(QString name, QString address)
{
  QList<QPair<QString, QString> > list = table->getList();
  QPair<QString, QString> pair(name, address);

  if (!list.contains(pair)) {
    table->insertRows(0, 1, QModelIndex());
    QModelIndex index = table->index(0, 0, QModelIndex());
    table->setData(index, name, Qt::EditRole);
    index = table->index(0, 1, QModelIndex());
    table->setData(index, address, Qt::EditRole);
  } else {
    QMessageBox::information(this, tr("Duplicate name"),
                             tr("The name \"%1\" already exites.").arg(name));
  }
}

void AddressWidget::setupTabs()
{
  QStringList groups;
  groups << "ABC" << "DEF" << "GHI" << "JKL" << "MNO" << "PQR" << "STU" <<
            "VW" << "XYZ";

  for (int i = 0; i < groups.size(); ++i) {
    QString str = groups.at(i);

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(table);

    QTableView *tableView = new QTableView;
    tableView->setModel(proxyModel);
    tableView->setSortingEnabled(true);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->verticalHeader()->hide();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    QString newStr = QString("^[%1].*").arg(str);

    proxyModel->setFilterRegExp(QRegExp(newStr, Qt::CaseInsensitive));
    proxyModel->setFilterKeyColumn(0);
    proxyModel->sort(0, Qt::AscendingOrder);

    connect(tableView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SIGNAL(selectionChanged(QItemSelection)));

    addTab(tableView, str);
  }
}

void AddressWidget::readFromFile(const QString &fileName)
{
  QFile file(fileName);

  if (!file.open(QIODevice::ReadOnly)) {
    QMessageBox::information(this, tr("Unable to open file"),
                             file.errorString());
    return;
  }

  QList<QPair<QString, QString> >pairs = table->getList();
  QDataStream in(&file);
  in >> pairs;

  if (pairs.isEmpty()) {
    QMessageBox::information(this, tr("No contacts in file"),
             tr("The file you are attmpting to open contains no contacts."));
  } else {
    for (int i = 0; i < pairs.size(); ++i) {
      QPair<QString, QString> p = pairs.at(i);
      addEntry(p.first, p.second);
    }
  }
}

void AddressWidget::writeToFile(const QString &fileName)
{
  QFile file(fileName);

  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::information(this, tr("Unable to write file"),
                             file.errorString());
    return;
  }

  QList<QPair<QString, QString> > pairs = table->getList();
  QDataStream out(&file);
  out << pairs;
}

#ifndef ADDRESSWIDGET_H
#define ADDRESSWIDGET_H

#include <QTabWidget>
#include <QItemSelection>

#include "TableModel.h"

class QSortFilterProxyModel;
class QItemSelectionModel;

class AddressWidget : public QTabWidget
{
  Q_OBJECT
public:
  explicit AddressWidget(QWidget *parent = 0);
  void readFromFile(const QString &fileName);
  void writeToFile(const QString &fileName);

signals:
  void selectionChanged(const QItemSelection &selected);

public slots:
  void addEntry();
  void addEntry(QString name, QString address);
//  void editEntry();
//  void removeEntry();

private:
  void setupTabs();

  TableModel *table;
  QSortFilterProxyModel *proxyModel;
};

#endif // ADDRESSWIDGET_H

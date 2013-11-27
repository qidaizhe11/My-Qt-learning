#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QPair>
#include <QList>

class TableModel : public QAbstractTableModel
{
  Q_OBJECT
public:
  explicit TableModel(QObject *parent = 0);
  TableModel(QList<QPair<QString, QString> > pairs, QObject *parent = 0);

  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  Qt::ItemFlags flags(const QModelIndex &index) const;
  bool setData(const QModelIndex &index, const QVariant &value, int role);
  bool insertRows(int row, int count, const QModelIndex &parent);
  bool removeRows(int row, int count, const QModelIndex &parent);
  QList<QPair<QString, QString> > getList();

signals:

public slots:

private:
  QList<QPair<QString, QString> > listOfPairs;
};

#endif // TABLEMODEL_H

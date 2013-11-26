#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QString>

const int ROWS = 2;
const int COLS = 3;

class MyModel : public QAbstractTableModel
{
  Q_OBJECT
public:
  explicit MyModel(QObject *parent = 0);
  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  bool setData(const QModelIndex &index, const QVariant &value, int role);
  Qt::ItemFlags flags(const QModelIndex &index) const;

signals:
  void editCompleted(const QString &);

public slots:

private:
  QString m_gridData[ROWS][COLS];
};

#endif // MYMODEL_H

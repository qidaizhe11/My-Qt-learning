#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QTimer>

class MyModel : public QAbstractTableModel
{
  Q_OBJECT
public:
  explicit MyModel(QObject *parent = 0);
  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  QTimer *timer;

signals:

public slots:

private slots:
//  void timerHit();

private:
  int selectedCell;
};

#endif // MYMODEL_H

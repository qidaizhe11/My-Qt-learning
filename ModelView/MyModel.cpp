
//#include <QDebug>
#include "MyModel.h"
#include <QtWidgets>

MyModel::MyModel(QObject *parent) :
  QAbstractTableModel(parent)
{
//  timer = new QTimer(this);
//  timer->setInterval(1000);
//  connect(timer, SIGNAL(timeout()), this, SLOT(timerHit()));
//  timer->start();
}

int MyModel::rowCount(const QModelIndex &/*parent*/) const
{
  return 2;
}

int MyModel::columnCount(const QModelIndex &/*parent*/) const
{
  return 3;
}

//QVariant MyModel::data(const QModelIndex &index, int role) const
//{
//  int row = index.row();
//  int col = index.column();

//  if (role == Qt::DisplayRole) {
//    if (row == 0 && col == 0) {
//      return QTime::currentTime().toString();
//    }
//  }
//  return QVariant();
//}

//void MyModel::timerHit()
//{
//  QModelIndex topLeft = createIndex(0, 0);
//  emit dataChanged(topLeft, topLeft);
//}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
  int row = index.row();
  int col = index.column();

  qDebug() << QString("row %1, col %2, role %3").arg(row).arg(col).arg(role);

  switch (role) {
  case Qt::DisplayRole:
    if (row == 0 && col == 1) return QString("<--left");
    if (row == 1 && col == 1) return QString("right-->");
    return QString("Row%1, Column%2").arg(row + 1).arg(col + 1);
    break;
  case Qt::FontRole:
    if (row == 0 && col == 0) {
      QFont boldFont;
      boldFont.setBold(true);
      return boldFont;
    }
    break;
  case Qt::BackgroundRole:
    if (row == 1 && col == 2) {
      QBrush redBackground(Qt::red);
      return redBackground;
    }
    break;
  case Qt::TextAlignmentRole:
    if (row == 1 && col == 1) {
      return Qt::AlignRight + Qt::AlignVCenter;
    }
    break;
  case Qt::CheckStateRole:
    if (row == 1 && col == 0) {
      return Qt::Checked;
    }
  default:
    break;
  }

  return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role)
    const
{
  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Horizontal) {
      switch (section) {
      case 0:
        return QString("first"); break;
      case 1:
        return QString("second"); break;
      case 2:
        return QString("third"); break;
      default:
        break;
      }
    }
  }
  return QVariant();
}

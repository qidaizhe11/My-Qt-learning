#include "MyModel.h"

MyModel::MyModel(QObject *parent) :
  QAbstractTableModel(parent)
{
}

int MyModel::rowCount(const QModelIndex &/*parent*/) const
{
    return ROWS;
}

int MyModel::columnCount(const QModelIndex &/*parent*/) const
{
  return COLS;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
  if (role == Qt::DisplayRole) {
    return m_gridData[index.row()][index.column()];
  }
  return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
  if (role == Qt::EditRole) {
    m_gridData[index.row()][index.column()] = value.toString();
    QString result;
    for (int row = 0; row < ROWS; ++row) {
      for (int col = 0; col < COLS; ++col) {
        result += m_gridData[row][col] + " ";
      }
    }
    emit editCompleted(result);
  }
  return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
  return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

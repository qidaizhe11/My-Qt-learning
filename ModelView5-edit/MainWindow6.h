#ifndef MAINWINDOW6_H
#define MAINWINDOW6_H

#include <QMainWindow>

class QTreeView;
class QStandardItemModel;
class QStandardItem;
class QItemSelection;

class MainWindow6 : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow6(QWidget *parent = 0);

signals:

public slots:

private slots:
  void selectionChangedSlot(const QItemSelection &newSelection,
                            const QItemSelection &oldSelection);

private:
  QList<QStandardItem *> prepareRow(const QString &first,
                                    const QString &second,
                                    const QString &third);
  QTreeView *treeView;
  QStandardItemModel *standardModel;
};

#endif // MAINWINDOW6_H

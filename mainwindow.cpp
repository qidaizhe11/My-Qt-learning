
#include "mainwindow.h"
#include <QtWidgets>
#include "renderarea.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    renderArea = new RenderArea;

    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Polygon"), RenderArea::Polygon);
    shapeComboBox->addItem(tr("Rectangle"), RenderArea::Rect);
    shapeComboBox->addItem(tr("Rounded Rectangle"), RenderArea::RoundedRect);

    shapeLabel = new QLabel(tr("Shape:"));
    shapeLabel->setBuddy(shapeComboBox);
}

MainWindow::~MainWindow()
{

}

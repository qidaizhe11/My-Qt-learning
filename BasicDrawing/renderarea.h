#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPixmap>

class RenderArea : public QWidget
{
  Q_OBJECT
public:
  enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse,
               Arc, Chord, Pie, Path, Text, Pixmap };

  explicit RenderArea(QWidget *parent = 0);

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

signals:

public slots:
  void setShape(Shape shape);
  void setPen(const QPen &pen);
  void setBrush(const QBrush &brush);
  void setAntialiased(bool antialiased);
  void setTransformed(bool transformed);

protected:
  void paintEvent(QPaintEvent *);

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
};

#endif // RENDERAREA_H

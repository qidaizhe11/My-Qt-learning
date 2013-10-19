#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

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
  //void setShape()

private:

};

#endif // RENDERAREA_H

#ifndef MAINWINDOW_GQNV48OM
#define MAINWINDOW_GQNV48OM

#include <QGLWidget>

#include "particlessystem.h"

class ParticlesWidget : public QGLWidget {
  Q_OBJECT

 public:
  ParticlesWidget ();
  virtual ~ParticlesWidget ();

 protected slots:
  void paintEvent (QPaintEvent *);
  void mousePressEvent (QMouseEvent *);

  private:
   ParticlesSystem * system;
   ParticlesSystem * list[2];
   int systemId;
};

#endif /* end of include guard: MAINWINDOW_GQNV48OM */

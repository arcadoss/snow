/*
 * =====================================================================================
 *
 *       Filename:  particleswidget.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29.06.2010 21:07:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sergey Dovgal (), arcadoss@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */


#ifndef MAINWINDOW_GQNV48OM
#define MAINWINDOW_GQNV48OM

#include <QGLWidget>
//#include "ui_mainwindow.h"

#include "particlessystem.h"

class ParticlesWidget : public QGLWidget {
  Q_OBJECT

 public:
  ParticlesWidget ();
  virtual ~ParticlesWidget ();

 protected slots:
  void paintEvent (QPaintEvent *);

  private:
    //Ui::ParticlesWidget ui;
    ParticlesSystem * system;

};

#endif /* end of include guard: MAINWINDOW_GQNV48OM */

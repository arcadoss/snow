/*
 * =====================================================================================
 *
 *       Filename:  particleswidget.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.06.2010 14:13:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sergey Dovgal (), arcadoss@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include "particleswidget.h"

#include <cmath>
#include <QPainter>

#include "snow.h"


ParticlesWidget::ParticlesWidget() : QGLWidget(QGLFormat(QGL::SampleBuffers))
{
  // system = new Snow();
   system = new FaterFall();

  QObject::connect(
      system, SIGNAL(calculationsDone()), this, SLOT(update()));

  resize(500, 850);
}

ParticlesWidget::~ParticlesWidget()
{
    delete system;
}

void ParticlesWidget::paintEvent(QPaintEvent * /* event */ )
{
  QPainter painter (this);
  QBrush brush (Qt::SolidPattern);
  QPen pen (brush, 0, Qt::NoPen); 

  painter.setPen(pen);
  painter.setRenderHint(QPainter::Antialiasing);

  ParticlesSystem::List::const_iterator i = system->particles().constBegin();

  int x, y, radius;
  while (i != system->particles().constEnd()) {
    brush.setColor((*i)->color);
    painter.setBrush(brush);
    radius = (*i)->radius; 
    x = floor(0.5 + (*i)->x * width()) - radius;
    y = floor(0.5 + (*i)->y * height()) - radius;
    painter.drawEllipse(x, y, 2 * radius, 2 * radius);
    ++i;
  }
}

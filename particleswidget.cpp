#include "particleswidget.h"

#include <QPainter>

#include "snow.h"

ParticlesWidget::ParticlesWidget() : QGLWidget(QGLFormat(QGL::SampleBuffers))
{
  list[0] = system = new Snow();
  list[1] = new FaterFall();
  systemId = 0;

  QObject::connect( list[0], SIGNAL(calculationsDone()), this, SLOT(update()));
  QObject::connect( list[1], SIGNAL(calculationsDone()), this, SLOT(update()));

  system->start();
  resize(500, 850);
}

ParticlesWidget::~ParticlesWidget()
{
    delete list[0];
    delete list[1];
}

void ParticlesWidget::paintEvent(QPaintEvent * /* event */ )
{
  QPainter painter (this);
  QBrush brush (Qt::SolidPattern);
  QPen pen (brush, 0, Qt::NoPen); 

  painter.setPen(pen);
  painter.setRenderHint(QPainter::Antialiasing);

  system->draw(painter, brush, height(), width());
}

void ParticlesWidget::mousePressEvent ( QMouseEvent * /*  event  */) 
{
  system->stop();
  switch ( systemId ) {
    case 0:	
      system = list[1];
      systemId = 1;
      break;
    case 1:	
      system = list[0];
      systemId = 0;
      break;
    default:	
      break;
  }		  
  system->start();
}



#include "particlessystem.h"

#include <cmath>

ParticlesSystem::ParticlesSystem() : tickLength(kTickLength), particlesCount(0)
{
  QObject::connect( &timer, SIGNAL(timeout()), 
      this, SLOT(onTimeout()));
}

ParticlesSystem::~ParticlesSystem()
{
    List::iterator i = particles.begin();
    while (i != particles.end()) {
        delete *i;
        ++i;
    }
}

void ParticlesSystem::start()
{
  timer.start(tickLength);
}

void ParticlesSystem::stop() {
  timer.stop();
}  

void ParticlesSystem::draw(QPainter & painter, QBrush & brush, int height, int width)
{
  List::const_iterator i = particles.constBegin();

  int x, y, radius;
  while (i != particles.constEnd()) {
    brush.setColor((*i)->color);
    painter.setBrush(brush);

    radius = (*i)->radius; 
    x = floor(0.5 + (*i)->x * width) - radius;
    y = floor(0.5 + (*i)->y * height) - radius;

    painter.drawEllipse(x, y, 2 * radius, 2 * radius);
    ++i;
  }
}

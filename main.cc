#include <QApplication>

#include "particleswidget.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  ParticlesWidget widget;

  widget.show();

  return app.exec();
}

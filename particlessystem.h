#ifndef MANAGER_4T4EBFLP
#define MANAGER_4T4EBFLP

#include <QLinkedList>
#include <QTimer>
#include <QPainter>
#include <QBrush>

#include "particle.h"

class ParticlesSystem : public QObject 
{
 Q_OBJECT

 public:
  typedef QLinkedList<Particle *> List;
  ParticlesSystem ();
  virtual ~ParticlesSystem ();
  virtual void draw(QPainter & painter, QBrush & brush, int height, int width);
  void start();
  void stop();

 signals:
  void calculationsDone ();

 protected:
  static const double kTickLength = 40;
  List particles;
  QTimer timer;
  int tickLength;
  int particlesCount;

 protected slots:
  virtual void onTimeout () = 0;
};


#endif /* end of include guard: MANAGER_4T4EBFLP */

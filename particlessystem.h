/*
 * =====================================================================================
 *
 *       Filename:  particlessystem.h
 *
 *    Description:  bla
 *
 *        Version:  1.0
 *        Created:  29.06.2010 21:27:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sergey Dovgal (), arcadoss@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef MANAGER_4T4EBFLP
#define MANAGER_4T4EBFLP

#include <QLinkedList>
#include <QTimer>

#include "particle.h"

class ParticlesSystem : public QObject 
{
 Q_OBJECT

 public:
  typedef QLinkedList<Particle *> List;
  ParticlesSystem ();
  virtual ~ParticlesSystem ();
  inline List const & particles() const {return particles_;};

 signals:
  void calculationsDone ();

 protected:
  static const double kTickLength = 40;
  List particles_;
  QTimer timer;
  int tickLength;
  int particlesCount;

 protected slots:
  virtual void onTimeout () = 0;
};


#endif /* end of include guard: MANAGER_4T4EBFLP */

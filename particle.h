/*
 * =====================================================================================
 *
 *       Filename:  particle.h
 *
 *    Description:  bla
 *
 *        Version:  1.0
 *        Created:  29.06.2010 19:25:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sergey Dovgal (), arcadoss@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef SNOWFLAKE_Q29Z55V7
#define SNOWFLAKE_Q29Z55V7

#include <cstdlib>

#include <QColor>
#include <QLinkedList>

namespace Supply {
  static const double RAND_MAX_F = RAND_MAX * 1.0; 
  int Random(int up, int down = 0);
  double Random(double up = 1.0, double down = 0.0);
}

class Particle {
public:
  Particle() {};
  virtual ~Particle () {};

  double x, y;
  int radius;
  QColor color;

};

class SnowFlake : public Particle {
public:
  static const int kMaxLifeTime = 2000;
  static const int kMaxRadius = 11;

  SnowFlake(double y_ = 0.0);
  virtual ~SnowFlake() {};

  int lifeTime;
};

class WaterDrop : public Particle {
public:
  static const int kMaxLifeTime = 600;
  static const int kMinLifeTime = 200;
  static const int kMinRadius = 3;
  static const int kMaxRadius = 10;
  static const double kMinSpeed = 0.005;
  static const double kMaxSpeed = 0.0065;
  static const double kMinDrift = 0.002;
  static const double kMaxDrift = 0.0065;

  WaterDrop(double y_ = 0.0, double x_ = 0.0);
  virtual ~WaterDrop() {};
  WaterDrop & operator= (WaterDrop const & r);

  bool drifting;
  double xStart;
  double yStart;
  double speedX;
  double speedY;
  int step;
  int lifeTime;
};

#endif /* end of include guard: SNOWFLAKE_Q29Z55V7 */

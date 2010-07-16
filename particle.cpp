#include "particle.h"

#include <cmath>

double Supply::Random(double up, double down) {
  /*
   * if (up <= down || up < 0 || down < 0) {
   *   return -1;
   * }
   */
  return (down + (rand() / RAND_MAX_F) * (up - down));
}

int Supply::Random(int up, int down)
{
  /*
   * if (up <= down || up < 0 || down < 0) {
   *   return -1;
   * }
   */
  int out = down + floor(Supply::Random() * (up - down));
  if (out == up) {
    --out;
  }
  return out;
}

SnowFlake::SnowFlake(double y_)
{
  x = Supply::Random();
  y = y_;

  int blue = 128 + Supply::Random(128);
  color = QColor(blue / 2, blue / 2, blue);
  lifeTime = Supply::Random(kMaxLifeTime);
  radius = Supply::Random(kMaxRadius);
}

WaterDrop::WaterDrop(double y_, double x_)
{
  xStart = x = x_;
  yStart = y = y_;
  speedX = Supply::Random(kMaxSpeed, kMinSpeed);
  speedY = -Supply::Random(kMaxSpeed, kMinSpeed);

  int blue = Supply::Random(255);
  color = QColor(blue / 4, blue / 4, blue);

  // lifeTime = Supply::Random(kMaxLifeTime, kMinLifeTime);
  lifeTime = Supply::Random(kMaxLifeTime, kMinLifeTime);
  radius = Supply::Random(kMaxRadius, kMinRadius);
  step = 1;
  drifting = false;
}

WaterDrop & WaterDrop::operator= (WaterDrop const & r) {
  if (this != &r) {
    x = r.x;
    y = r.y;
    radius = r.radius;
    xStart = r.xStart;
    yStart = r.yStart;
    speedX = r.speedX;
    speedY = r.speedY;
    step = 1;
    lifeTime = Supply::Random(kMaxLifeTime, kMinLifeTime);
    drifting = false;
  }
  return *this;
}


#include "snow.h"
#include <algorithm>

const double Snow::kLowBorder = 1.0 - Snow::kGravity;
const double FaterFall::kGravity2 = FaterFall::kGravity * FaterFall::kGravity;

Snow::Snow()
{
  int newFlakes =
    std::min(kFirstSingleMax, kMaxParticlesCount);
    
  particlesCount += newFlakes;

  for ( ; newFlakes > 0; newFlakes--) {
    particles.append(new SnowFlake(1.0));
  }
}

bool Snow::touch(SnowFlake * flake)
{
  static int time = 0;
  static int direction;

  // temperature impact
  flake->lifeTime -= kTempImpact;
  if (flake->lifeTime < 0) {
    return true;
  }

  if (flake->y < kLowBorder ) {
    // gravity impact
    flake->y += kGravity;

    // wind impact
    if (time <= 0) {
      time = Supply::Random(kMaxFlowTime);
      direction = Supply::Random(3);
    }
    switch ( direction ) {
      case 0:	
        flake->x -= kWindStregth;
        break;
      case 1:	
        flake->x += kWindStregth;
        break;
      default:	
        break;
    }

    --time;
  }

  return false;
}

void Snow::onTimeout()
{
  List::iterator i = particles.begin();
  List::iterator prev;
  SnowFlake * flake;

  while (i != particles.end()) {
    flake = dynamic_cast<SnowFlake *>(*i);
    prev = i++;

    if (touch(flake)) {
      delete flake;
      particles.erase(prev);
      --particlesCount;
    }
  }

  int newFlakes = Supply::Random(
      std::min(kMaxParticlesCount - particlesCount + 1, kSingleMax));

  particlesCount += newFlakes;

  for ( ; newFlakes > 0; newFlakes--) {
    particles.append(new SnowFlake());
  }

  emit calculationsDone();
}

FaterFall::FaterFall()
{
  for (int i = 0; i < kMaxParticlesCount / 2; i++) {
    WaterDrop * newDrop = new WaterDrop(1.0, Supply::Random(1.0));
    newDrop->speedY = 0.0;
    newDrop->drifting = true;
    particles.append(newDrop);
  }
  particlesCount = kMaxParticlesCount / 2;
}

void FaterFall::onTimeout()
{
  List::iterator i = particles.begin();
  List::iterator prev;
  WaterDrop * drop;

  while (i != particles.end()) {
    drop = dynamic_cast<WaterDrop *>(*i);
    prev = i++;

    if (touchTemp(drop)) {
      *drop = WaterDrop(yStart, xStart);
    }
    else if (touchGravity(drop)) {
      int sparkles = Supply::Random(
          std::min(kMaxParticlesCount - particlesCount + 1, kMaxSparcles));

      particlesCount += sparkles - 1;

      for ( ; sparkles > 0; sparkles--) {
        WaterDrop * newDrop = new WaterDrop(drop->y, drop->x);
        newDrop->speedY *= Supply::Random(kJumpFactor, 1.0);
        particles.append(newDrop);
      }

      delete drop;
      particles.erase(prev);
    }
  }

  emit calculationsDone();
}

bool FaterFall::touchTemp(WaterDrop * drop) {
  drop->lifeTime -= kTempImpact;
  if (drop->lifeTime < 0) {
    return true;
  }
  return false;
}

bool FaterFall::touchGravity(WaterDrop * drop)
{
  /*
   * v(k) = v(0) + a * t(k) = v(0) + a * k * T = v(k-1) + a * T 
   * v(k) - v(k-1) = a * T
   * 
   * x(k) = x(0) + {v(0) + 1/2 * a * t(k)} * t(k)
   * x(k) - x(k-1) = v(0) * T + 1/2 * a^2 * T^2 * (k^2 - k^2 +2k -1) =
   * = v(0) * T + a^2 * T^2 * (k-0.5)
   * 
   * T = 1, a = kGravity
   */
  
  drop->x += drop->speedX;

  if (!drop->drifting) {
    drop->y += drop->speedY + kGravity2 * (drop->step - 0.5);

    if (drop->y < 1.0) {
      ++ drop->step;
    } 
    else {
      if (Supply::Random(kSparcleChanse)) {
        drop->y = drop->yStart = 1.0;
        drop->xStart = drop->x;
        drop->speedY = 0;
        drop->drifting = true;

        double newSpeedX = Supply::Random(WaterDrop::kMaxDrift, WaterDrop::kMinDrift);
        drop->speedX = (drop->speedX > 0) ? newSpeedX : -newSpeedX;
      } 
      else {
        return true;
      }
    }
  }

  if (drop->x > 1.0) {
    drop->x = 1.0;
    drop->speedX = -drop->speedX;
  }
  else if (drop->x < 0.0) {
    drop->x = 0.0;
    drop->speedX = -drop->speedX;
  }

  return false;
}

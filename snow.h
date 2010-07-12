/*
 * =====================================================================================
 *
 *       Filename:  snow.h
 *
 *    Description:  bla
 *
 *        Version:  1.0
 *        Created:  29.06.2010 19:35:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sergey Dovgal (), arcadoss@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef ACTOR_JJ9XWUGY
#define ACTOR_JJ9XWUGY

#include "particlessystem.h"

class Snow : public ParticlesSystem {
 public:
  Snow ();
  virtual ~Snow () {};

 private:
  static const double kGravity = 0.0015;
  static const double kLowBorder;
  static const double kWindStregth = 0.001;
  static const int kMaxFlowTime = 17;
  static const int kTempImpact = 1;
  static const int kMaxParticlesCount = 300;
  static const int kSingleMax = 3;
  static const int kFirstSingleMax = 180;
  void onTimeout();
  bool touch(SnowFlake * flake);

};

class FaterFall : public ParticlesSystem {
public:
  FaterFall ();
  virtual ~FaterFall () {};

private:
  static const double kGravity = 0.02;
  static const double kGravity2;
  static const double xStart = 0.0;
  static const double yStart = 0.2;
  static const double kJumpFactor = 2.7;
  static const int kMaxParticlesCount = 450;
  static const int kMaxSparcles = 4;
  static const int kTempImpact = 1;
  static const int kSparcleChanse = 4;



  bool touchGravity(WaterDrop * drop);
  bool touchTemp(WaterDrop * drop);
  void onTimeout();
};

#endif /* end of include guard: ACTOR_JJ9XWUGY */

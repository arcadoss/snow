/*
 * =====================================================================================
 *
 *       Filename:  particlessystem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.06.2010 14:38:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sergey Dovgal (), arcadoss@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include "particlessystem.h"

ParticlesSystem::ParticlesSystem() : tickLength(kTickLength), particlesCount(0)
{
  QObject::connect( &timer, SIGNAL(timeout()), 
      this, SLOT(onTimeout()));

  timer.start(tickLength);
}

ParticlesSystem::~ParticlesSystem()
{
    List::iterator i = particles_.begin();
    while (i != particles_.end()) {
        delete *i;
        ++i;
    }
}


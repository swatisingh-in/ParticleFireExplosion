#ifndef SWARM_H
#define SWARM_H

#include "particle.h"

class Swarm
{
	Particle * particles;
	int lastTime;

public:
	static const int NPARTICLES = 5000;

public:
	Swarm();
	void update(int elapsed);	
	const Particle * const getParticles() { return particles; }
	~Swarm();	
};

#endif
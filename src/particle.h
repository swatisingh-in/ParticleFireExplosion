#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
	double speed;
	double direction;
	void init();
public:
	double x;
	double y;
public:
	Particle();
	void update(int interval);
	~Particle();	
};

#endif
#ifndef EULER_H
#define EULER_H

class Particles;

class Euler : public Solver
{
public:
	Particles solve() override;
};

#endif

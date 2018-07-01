#ifndef EULER_H
#define EULER_H

#include "solver.h"

class Particles;

class Euler : public Solver
{
public:
	Particles solve() override;
};

#endif

#ifndef SOLVER_H
#define SOLVER_H

class Particles;

class Solver 
{
public:
	virtual Particles solve() = 0;
 };


#endif
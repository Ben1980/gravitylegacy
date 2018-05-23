#ifndef EULER_H
#define EULER_H

#include "solver.h"

class Euler : public Solver
{
public:
    Euler();
    Particle solve() override;
};

#endif // EULER_H

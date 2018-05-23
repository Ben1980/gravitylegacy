#ifndef SOLVER_H
#define SOLVER_H

#include "solver_global.h"

class Particle;

class SOLVERSHARED_EXPORT Solver
{
public:
    virtual Particle solve() = 0;
};

#endif // SOLVER_H

#ifndef SOLVER_H
#define SOLVER_H

#include "solver_global.h"

class Particles;

class SOLVERSHARED_EXPORT Solver
{
public:
    Solver() = default;
    virtual ~Solver() = default;
    Solver(const Solver &solver) = default;
    Solver(Solver &&solver) = default;
    Solver & operator=(const Solver &solver) = default;
    Solver & operator=(Solver &&solver) = default;

    virtual Particles solve(const Particles &particles, double deltaT) const = 0;
};

#endif // SOLVER_H

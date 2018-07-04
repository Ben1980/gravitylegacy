#ifndef SOLVER_H
#define SOLVER_H

#include "solver_global.h"

class SOLVERSHARED_EXPORT Solver
{
public:
    virtual void solve() const = 0;
};

#endif // SOLVER_H

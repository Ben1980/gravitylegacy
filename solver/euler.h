#ifndef EULER_H
#define EULER_H

#include "solver_global.h"

class SOLVERSHARED_EXPORT Euler : public Solver
{
public:
    Euler();

    void solve() const override;
};

#endif // EULER_H

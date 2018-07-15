#ifndef EULER_H
#define EULER_H

#include "solver_global.h"
#include "solver.h"

class Particles;

class SOLVERSHARED_EXPORT Euler : public Solver
{
public:
    Euler() = default;
    ~Euler() override = default;
    Euler(const Euler &euler) = default;
    Euler(Euler &&euler) = default;
    Euler & operator=(const Euler &euler) = default;
    Euler & operator=(Euler &&euler) = default;

    Particles solve(const Particles &particles, double deltaT) const override;

private:
    double calculateVelocity(double acceleration, double deltaT) const override;
    double calculateAcceleration(double position1, double position2, double mass) const override;
};

#endif // EULER_H

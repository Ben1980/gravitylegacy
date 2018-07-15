#include "euler.h"

#include <cmath>

#include "particles.h"
#include "constants.h"

using namespace Constants;

Particles Euler::solve(const Particles &particles, double deltaT) const
{
    std::vector<double> xPosition(particles.xPosition.size());
    std::vector<double> yPosition(particles.yPosition.size());

    for(size_t i = 0; i < xPosition.size(); i++) {
        for(size_t j = 0; j < xPosition.size(); j++) {
            if(j != i) {
                const double m = particles.mass[i]*particles.mass[j]/particles.mass[i];
                const double xAcc = calculateAcceleration(particles.xPosition[i], particles.xPosition[j], m);
                const double xVel = calculateVelocity(xAcc, deltaT);

                xPosition[i] = particles.xPosition[i] + xVel*deltaT + 0.5*xAcc*deltaT*deltaT;
            }
        }
    }

    for(size_t i = 0; i < yPosition.size(); i++) {
        for(size_t j = 0; j < yPosition.size(); j++) {
            if(j != i) {
                const double m = particles.mass[i]*particles.mass[j]/particles.mass[i];
                const double yAcc = calculateAcceleration(particles.yPosition[i], particles.yPosition[j], m);
                const double yVel = calculateVelocity(yAcc, deltaT);

                yPosition[i] = particles.yPosition[i] + yVel*deltaT + 0.5*yAcc*deltaT*deltaT;
            }
        }
    }

    Particles solution;
    solution.xPosition = xPosition;
    solution.yPosition = yPosition;
    solution.mass = particles.mass;

    return solution;
}

double Euler::calculateVelocity(double acceleration, double deltaT) const
{
    return acceleration*deltaT;
}

double Euler::calculateAcceleration(double position1, double position2, double mass) const
{
    const double r = position2 - position1;
    const double r3 = fabs(r*r*r);

    return GRAVITATIONAL_CONSTANT * mass * r/r3;
}

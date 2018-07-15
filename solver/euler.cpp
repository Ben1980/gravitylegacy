#include "euler.h"

#include <cmath>

#include "particles.h"
#include "constants.h"

using namespace Constants;

Particles Euler::solve(const Particles &particles, double deltaT) const
{
    std::vector<double> xPosition(particles.xPosition.size());
    std::vector<double> yPosition(particles.yPosition.size());
    std::vector<double> xVelocity(particles.xVelocity.size());
    std::vector<double> yVelocity(particles.yVelocity.size());

    for(size_t i = 0; i < xPosition.size(); i++) {
        for(size_t j = 0; j < xPosition.size(); j++) {
            if(j != i) {
                const double m = particles.mass[i]*particles.mass[j]/particles.mass[i];
                const double xAcc = calculateAcceleration(particles.xPosition[i], particles.xPosition[j], m);
                xVelocity[i] = particles.xVelocity[i] + calculateVelocity(xAcc, deltaT);

                xPosition[i] = particles.xPosition[i] + xVelocity[i]*deltaT + 0.5*xAcc*deltaT*deltaT;
            }
        }
    }

    for(size_t i = 0; i < yPosition.size(); i++) {
        for(size_t j = 0; j < yPosition.size(); j++) {
            if(j != i) {
                const double m = particles.mass[i]*particles.mass[j]/particles.mass[i];
                const double yAcc = calculateAcceleration(particles.yPosition[i], particles.yPosition[j], m);
                yVelocity[i] = particles.yVelocity[i] + calculateVelocity(yAcc, deltaT);

                yPosition[i] = particles.yPosition[i] + yVelocity[i]*deltaT + 0.5*yAcc*deltaT*deltaT;
            }
        }
    }

    Particles solution;
    solution.xPosition = xPosition;
    solution.yPosition = yPosition;
    solution.xVelocity = xVelocity;
    solution.yVelocity = yVelocity;
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

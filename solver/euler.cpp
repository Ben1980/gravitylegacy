#include "euler.h"

#include <cmath>

#include "particles.h"
#include "constants.h"

using namespace Constants;

Particles Euler::solve(const Particles &particles, double deltaT) const
{
    const size_t numberOfParticles = particles.xPosition.size();

    std::vector<double> xPosition(numberOfParticles);
    std::vector<double> yPosition(numberOfParticles);
    std::vector<double> xVelocity(numberOfParticles);
    std::vector<double> yVelocity(numberOfParticles);
    std::vector<double> xAcceleration(numberOfParticles);
    std::vector<double> yAcceleration(numberOfParticles);

    for(size_t i = 0; i < numberOfParticles; i++) {
        for(size_t j = 0; j < numberOfParticles; j++) {
            if(j != i) {
                const double m = particles.mass[i]*particles.mass[j]/particles.mass[i];

                xAcceleration[i] = particles.xAcceleration[i] + calculateAcceleration(particles.xPosition[i], particles.xPosition[j], m);
                yAcceleration[i] = particles.yAcceleration[i] + calculateAcceleration(particles.yPosition[i], particles.yPosition[j], m);

                xVelocity[i] = particles.xVelocity[i] + calculateVelocity(xAcceleration[i], deltaT);
                xPosition[i] = particles.xPosition[i] + xVelocity[i]*deltaT + 0.5*xAcceleration[i]*deltaT*deltaT;

                yVelocity[i] = particles.yVelocity[i] + calculateVelocity(yAcceleration[i], deltaT);
                yPosition[i] = particles.yPosition[i] + yVelocity[i]*deltaT + 0.5*yAcceleration[i]*deltaT*deltaT;
            }
        }
    }

    return { xPosition,
             yPosition,
             xVelocity,
             yVelocity,
             xAcceleration,
             yAcceleration,
             particles.mass };
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

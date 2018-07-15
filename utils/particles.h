#ifndef PARTICLES_H
#define PARTICLES_H

#include <cstddef>
#include <vector>

struct Particles
{
    std::vector<double> xPosition;
    std::vector<double> yPosition;
    std::vector<double> xVelocity;
    std::vector<double> yVelocity;
    std::vector<double> xAcceleration;
    std::vector<double> yAcceleration;
    std::vector<double> mass;

    Particles() {}
};

#endif // PARTICLES_H

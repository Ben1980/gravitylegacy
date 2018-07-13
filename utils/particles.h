#ifndef PARTICLES_H
#define PARTICLES_H

#include <cstddef>
#include <vector>

struct Particles
{
    std::vector<double> xPosition;
    std::vector<double> yPosition;

    Particles() {}

    size_t getNumberOfParticles() const
    {
        if(xPosition.size() != yPosition.size()) {
            return -1;
        }

        return xPosition.size();
    }
};

#endif // PARTICLES_H

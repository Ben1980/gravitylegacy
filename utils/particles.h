#ifndef PARTICLES_H
#define PARTICLES_H

#include <cstddef>
#include <vector>

struct Particles
{
    std::vector<double> xPosition;
    std::vector<double> yPosition;
    std::vector<double> mass;

    Particles() {}

    size_t getNumberOfParticles() const
    {
        if(xPosition.size() != yPosition.size()) {
            return static_cast<size_t>(-1);
        }

        return xPosition.size();
    }
};

#endif // PARTICLES_H

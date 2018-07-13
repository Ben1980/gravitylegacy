#ifndef PARTICLEBUILDER_H
#define PARTICLEBUILDER_H

struct Particles;

class ParticleBuilder
{
public:
    virtual ParticleBuilder * setPosition(double x, double y) = 0;
    virtual void addParticle(Particles &particles) const = 0;
};

#endif // PARTICLEBUILDER_H

#ifndef PARTICLEBUILDER_H
#define PARTICLEBUILDER_H

struct Particles;

class ParticleBuilder
{
public:
    ParticleBuilder() = default;
    virtual ~ParticleBuilder() = default;
    ParticleBuilder(const ParticleBuilder &builder) = default;
    ParticleBuilder(ParticleBuilder &&builder) = default;
    ParticleBuilder & operator=(const ParticleBuilder &builder) = default;
    ParticleBuilder & operator=(ParticleBuilder &&builder) = default;

    virtual ParticleBuilder * setPosition(double x, double y) = 0;
    virtual ParticleBuilder * setVelocity(double x, double y) = 0;
    virtual ParticleBuilder * setAcceleration(double x, double y) = 0;
    virtual ParticleBuilder * setMass(double mass) = 0;
    virtual void addParticle(Particles &particles) const = 0;
};

#endif // PARTICLEBUILDER_H

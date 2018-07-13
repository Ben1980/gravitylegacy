#ifndef PARTICLEBUILDERIMPL_H
#define PARTICLEBUILDERIMPL_H

#include "particlebuilder.h"

struct Particles;

class ParticleBuilderImpl : public ParticleBuilder
{
public:
    ParticleBuilderImpl();

    ParticleBuilder * setPosition(double x, double y) override;
    void addParticle(Particles &particles) const override;
};

#endif // PARTICLEBUILDERIMPL_H

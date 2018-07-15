#ifndef PARTICLEBUILDERIMPL_H
#define PARTICLEBUILDERIMPL_H

#include "particlebuilder.h"

struct Particles;

class ParticleBuilderImpl : public ParticleBuilder
{
public:
    ParticleBuilderImpl();
    ~ParticleBuilderImpl() override = default;
    ParticleBuilderImpl(const ParticleBuilderImpl &builder) = default;
    ParticleBuilderImpl(ParticleBuilderImpl &&builder) = default;
    ParticleBuilderImpl & operator=(const ParticleBuilderImpl &builder) = default;
    ParticleBuilderImpl & operator=(ParticleBuilderImpl &&builder) = default;

    ParticleBuilder * setPosition(double x, double y) override;
    virtual ParticleBuilder * setMass(double mass) override;

    void addParticle(Particles &particles) const override;

private:
    double xPosition;
    double yPosition;
    double mass;
};

#endif // PARTICLEBUILDERIMPL_H

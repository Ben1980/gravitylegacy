#include "particlebuilderimpl.h"
#include "particles.h"

ParticleBuilderImpl::ParticleBuilderImpl()
    : xPosition(0), yPosition(0)
{
}

ParticleBuilder * ParticleBuilderImpl::setPosition(double x, double y)
{
    xPosition = x;
    yPosition = y;

    return this;
}

void ParticleBuilderImpl::addParticle(Particles &particles) const
{
    particles.xPosition.push_back(xPosition);
    particles.yPosition.push_back(yPosition);
}

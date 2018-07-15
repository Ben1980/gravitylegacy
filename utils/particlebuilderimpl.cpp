#include "particlebuilderimpl.h"
#include "particles.h"

ParticleBuilderImpl::ParticleBuilderImpl()
    : xPosition(0), yPosition(0), xVelocity(0), yVelocity(0), mass(0)
{
}

ParticleBuilder * ParticleBuilderImpl::setPosition(double x, double y)
{
    xPosition = x;
    yPosition = y;

    return this;
}

ParticleBuilder * ParticleBuilderImpl::setVelocity(double x, double y)
{
    xVelocity = x;
    yVelocity = y;

    return this;
}

ParticleBuilder * ParticleBuilderImpl::setAcceleration(double x, double y)
{
    xAcceleration = x;
    yAcceleration = y;

    return this;
}

ParticleBuilder * ParticleBuilderImpl::setMass(double mass)
{
    this->mass = mass;

    return this;
}

void ParticleBuilderImpl::addParticle(Particles &particles) const
{
    particles.xPosition.push_back(xPosition);
    particles.yPosition.push_back(yPosition);
    particles.xVelocity.push_back(xVelocity);
    particles.yVelocity.push_back(yVelocity);
    particles.xAcceleration.push_back(xAcceleration);
    particles.yAcceleration.push_back(yAcceleration);
    particles.mass.push_back(mass);
}

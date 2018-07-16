#include <QString>
#include <QtTest>
#include <memory>

#include "testutils.h"
#include "particles.h"
#include "particlebuilder.h"
#include "particlebuilderimpl.h"

using namespace TestUtils;

class UtilsTest : public QObject
{
    Q_OBJECT

public:
    UtilsTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testParticleBuilderWithTwoParticlesPosition();
    void testParticleBuilderWithTwoParticlesVelocity();
    void testParticleBuilderWithTwoParticlesAcceleration();
    void testParticleBuilderWithTwoParticlesMass();

private:
    Particles particles;
};

UtilsTest::UtilsTest()
{
    std::unique_ptr<ParticleBuilder> builder = std::make_unique<ParticleBuilderImpl>();

    builder->setPosition(-0.5, -0.5)->setVelocity(-0.5, -0.5)->setAcceleration(-0.5, -0.5)->setMass(1e10)->addParticle(particles);
    builder->setPosition(0.5, 0.5)->setVelocity(0.5, 0.5)->setAcceleration(0.5, 0.5)->setMass(1e10)->addParticle(particles);
}

void UtilsTest::initTestCase()
{
}

void UtilsTest::cleanupTestCase()
{
}

void UtilsTest::testParticleBuilderWithTwoParticlesPosition()
{
    QVERIFY2(resultIsValid<double>(-0.5, particles.xPosition[0], EPSILON), "X Position of Particle 1 is wrong!");
    QVERIFY2(resultIsValid<double>(-0.5, particles.yPosition[0], EPSILON), "Y Position of Particle 1 is wrong!");

    QVERIFY2(resultIsValid<double>(0.5, particles.xPosition[1], EPSILON), "X Position of Particle 2 is wrong!");
    QVERIFY2(resultIsValid<double>(0.5, particles.yPosition[1], EPSILON), "Y Position of Particle 2 is wrong!");
}

void UtilsTest::testParticleBuilderWithTwoParticlesVelocity()
{
    QVERIFY2(resultIsValid<double>(-0.5, particles.xVelocity[0], EPSILON), "X Velocity of Particle 1 is wrong!");
    QVERIFY2(resultIsValid<double>(-0.5, particles.yVelocity[0], EPSILON), "Y Velocity of Particle 1 is wrong!");

    QVERIFY2(resultIsValid<double>(0.5, particles.xVelocity[1], EPSILON), "X Velocity of Particle 2 is wrong!");
    QVERIFY2(resultIsValid<double>(0.5, particles.yVelocity[1], EPSILON), "Y Velocity of Particle 2 is wrong!");
}

void UtilsTest::testParticleBuilderWithTwoParticlesAcceleration()
{
    QVERIFY2(resultIsValid<double>(-0.5, particles.xAcceleration[0], EPSILON), "X Acceleration of Particle 1 is wrong!");
    QVERIFY2(resultIsValid<double>(-0.5, particles.yAcceleration[0], EPSILON), "Y Acceleration of Particle 1 is wrong!");

    QVERIFY2(resultIsValid<double>(0.5, particles.xAcceleration[1], EPSILON), "X Acceleration of Particle 2 is wrong!");
    QVERIFY2(resultIsValid<double>(0.5, particles.yAcceleration[1], EPSILON), "Y Acceleration of Particle 2 is wrong!");
}

void UtilsTest::testParticleBuilderWithTwoParticlesMass()
{
    QVERIFY2(resultIsValid<double>(1e10, particles.mass[0], EPSILON), "Mass of Particle 1 is wrong!");
    QVERIFY2(resultIsValid<double>(1e10, particles.mass[1], EPSILON), "Mass of Particle 2 is wrong!");
}

QTEST_APPLESS_MAIN(UtilsTest)

#include "tst_utilstest.moc"

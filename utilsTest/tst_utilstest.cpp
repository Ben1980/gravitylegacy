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
    void testParticleBuilderWithTwoParticles();
};

UtilsTest::UtilsTest()
{
}

void UtilsTest::initTestCase()
{
}

void UtilsTest::cleanupTestCase()
{
}

void UtilsTest::testParticleBuilderWithTwoParticles()
{
    std::unique_ptr<ParticleBuilder> builder = std::make_unique<ParticleBuilderImpl>();
    Particles particles;
    builder->setPosition(-0.5, -0.5)->addParticle(particles);
    builder->setPosition(0.5, 0.5)->addParticle(particles);

    QVERIFY2(particles.getNumberOfParticles() == 2, "Number of particles generated is not two!");
    QVERIFY2(resultIsValid<double>(-0.5, particles.xPosition[0], EPSILON), "X Position of Particle 1 is wrong!");
    QVERIFY2(resultIsValid<double>(-0.5, particles.yPosition[0], EPSILON), "Y Position of Particle 1 is wrong!");
    QVERIFY2(resultIsValid<double>(0.5, particles.xPosition[1], EPSILON), "X Position of Particle 2 is wrong!");
    QVERIFY2(resultIsValid<double>(0.5, particles.yPosition[1], EPSILON), "Y Position of Particle 2 is wrong!");
}

QTEST_APPLESS_MAIN(UtilsTest)

#include "tst_utilstest.moc"

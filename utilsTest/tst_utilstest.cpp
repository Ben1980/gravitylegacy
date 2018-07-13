#include <QString>
#include <QtTest>
#include <memory>

#include "particles.h"
#include "particlebuilder.h"
#include "particlebuilderimpl.h"

class UtilsTest : public QObject
{
    Q_OBJECT

public:
    UtilsTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testParticleBuilderWithTwoParticles();

private:
    const double EPSILON = 1e-15;

    bool resultIsValid(double expected, double result, double epsilon) const;
};

UtilsTest::UtilsTest()
{
}

bool UtilsTest::resultIsValid(double expected, double result, double epsilon) const
{
    return fabs(result/expected - 1) <= epsilon;
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
    QVERIFY2(resultIsValid(-0.5, particles.xPosition[0], EPSILON), "X Position of Particle 1 is wrong!");
    QVERIFY2(resultIsValid(-0.5, particles.yPosition[0], EPSILON), "Y Position of Particle 1 is wrong!");
    QVERIFY2(resultIsValid(0.5, particles.xPosition[1], EPSILON), "X Position of Particle 2 is wrong!");
    QVERIFY2(resultIsValid(0.5, particles.yPosition[1], EPSILON), "Y Position of Particle 2 is wrong!");
}

QTEST_APPLESS_MAIN(UtilsTest)

#include "tst_utilstest.moc"

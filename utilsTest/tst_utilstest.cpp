#include <QString>
#include <QtTest>

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
    ParticleBuilder *builder = new ParticleBuilderImpl();
    Particles particles;
    builder->setPosition(-0.5, -0.5)->addParticle(particles);
    builder->setPosition(0.5, 0.5)->addParticle(particles);

    QVERIFY2(particles.getNumberOfParticles() == 2, "Number of particles generated is not two!");
}

QTEST_APPLESS_MAIN(UtilsTest)

#include "tst_utilstest.moc"

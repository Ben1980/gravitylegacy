#include <QString>
#include <QtTest>
#include <memory>

//#include "particles.h"
//#include "solver.h"

class SolverTest : public QObject
{
    Q_OBJECT

public:
    SolverTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testTwoStillStandingParticlesXPosition();

private:
//    ParticleBuilder builder;
//    std::unique_ptr<Particles> particles;
};

SolverTest::SolverTest()
{
}

void SolverTest::initTestCase()
{
//    particles = builder.addParticle()
//            .setPosition(-0.5, -0.5)
//            .addParticle()
//            .setPosition(0.5, 0.5)
//            .build();
}

void SolverTest::cleanupTestCase()
{
}

void SolverTest::testTwoStillStandingParticlesXPosition()
{
//    const double deltaT = 1e-1;
//    const double epsilon = 1e-15;
//    const std::unique_ptr<Particles> solution = particleSolver.solve(particles, deltaT);

//    const double expectedXPositionParticle_1 = 0;
//    const double expectedYPositionParticle_1 = 0;
//    const double expectedXPositionParticle_2 = 0;
//    const double expectedYPositionParticle_2 = 0;

//    QVERIFY2(resultIsValid(expectedXPositionParticle_1, solution.get()->positionX[0], epsilon), "Particle 1 has wrong X position");
//    QVERIFY2(resultIsValid(expectedYPositionParticle_1, solution.get()->positionY[0], epsilon), "Particle 1 has wrong Y position");
//    QVERIFY2(resultIsValid(expectedXPositionParticle_2, solution.get()->positionX[1], epsilon), "Particle 2 has wrong X position");
//    QVERIFY2(resultIsValid(expectedYPositionParticle_2, solution.get()->positionX[1], epsilon), "Particle 2 has wrong Y position");
}

QTEST_APPLESS_MAIN(SolverTest)

#include "tst_solvertest.moc"

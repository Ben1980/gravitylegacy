#include <QString>
#include <QtTest>
#include <memory>

#include "particlebuilder.h"
#include "particlebuilderimpl.h"
#include "particles.h"
#include "testutils.h"
#include "solver.h"
#include "euler.h"

using namespace TestUtils;

class SolverTest : public QObject
{
    Q_OBJECT

public:
    SolverTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testTwoStillStandingParticlesXPosition();
    void testTwoStillStandingParticlesYPosition();

private:
    constexpr static const double DELTA_T = 1e-1;

    std::unique_ptr<ParticleBuilder> builder;
    std::unique_ptr<Solver> solver;
    Particles particles;
};

SolverTest::SolverTest()
{
    builder = std::make_unique<ParticleBuilderImpl>();
    solver = std::make_unique<Euler>();

    builder->setPosition(0.5, 0.5)->setMass(1e10)->addParticle(particles);
    builder->setPosition(-0.5, -0.5)->setMass(1e10)->addParticle(particles);
}

void SolverTest::initTestCase()
{
}

void SolverTest::cleanupTestCase()
{
}

//F_ij = G*m_i*m_j*(q_j-q_i)/(|q_j-q_i|)^3 -> https://en.wikipedia.org/wiki/N-body_problem
//F_ij -> Force between bodys
//G = 6.67408e-11 m^3/(kg * s^2) -> https://en.wikipedia.org/wiki/Gravitational_constant
//q_j-q_i -> Distance between bodys
//m_j,m_i -> Mass of body

//F = m*a -> https://en.wikipedia.org/wiki/Equations_of_motion
//r = r_0 + v0*dt + 0.5*a0*dt^2
//a = F/m
//v = a*dt

//a_i = G*m_i*m_j*(q_j-q_i)/m_i*(|q_j-q_i|)^3
//M_i = m_i*m_j/m_i
//r = q_j-q_i
//a_i = G*M_i*r/r^3

//Example
//M = 1e10, (x1,y1) = (0.5,0,5), (x2,y2) = (-0.5,-0,5)
//a_x1 = G*1e10*(-0.5-0.5)/(|-0.5-0.5|)^3 = -0.667408
//v_x1 = a_x1*1e-1 = -0.0667408
//x_1 = 0.5 + v_x1*1e-1 + 0.5*a_x(1*1e-1)^2 = 0.48998888

void SolverTest::testTwoStillStandingParticlesXPosition()
{
    const Particles solution = solver->solve(particles, DELTA_T);

    const double expectedXPositionParticle_1 = 0.48998888;
    const double expectedXPositionParticle_2 = -0.48998888;

    QVERIFY2(resultIsValid<double>(expectedXPositionParticle_1, solution.xPosition[0], EPSILON), "Particle 1 has wrong X position");
    QVERIFY2(resultIsValid<double>(expectedXPositionParticle_2, solution.xPosition[1], EPSILON), "Particle 2 has wrong X position");
}

void SolverTest::testTwoStillStandingParticlesYPosition()
{
    const Particles solution = solver->solve(particles, DELTA_T);

    const double expectedYPositionParticle_1 = 0.48998888;
    const double expectedYPositionParticle_2 = -0.48998888;

    QVERIFY2(resultIsValid<double>(expectedYPositionParticle_1, solution.yPosition[0], EPSILON), "Particle 1 has wrong Y position");
    QVERIFY2(resultIsValid<double>(expectedYPositionParticle_2, solution.yPosition[1], EPSILON), "Particle 2 has wrong Y position");
}

QTEST_APPLESS_MAIN(SolverTest)

#include "tst_solvertest.moc"

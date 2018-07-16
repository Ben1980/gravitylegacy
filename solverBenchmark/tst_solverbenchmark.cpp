#include <QString>
#include <QtTest>
#include <memory>
#include <random>

#include "particlebuilder.h"
#include "particlebuilderimpl.h"
#include "particles.h"
#include "solver.h"
#include "euler.h"

class SolverBenchmark : public QObject
{
    Q_OBJECT

public:
    SolverBenchmark();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testPerformanceWith10000Particles();

private:
    constexpr static const double DELTA_T = 1e-1;

    std::unique_ptr<ParticleBuilder> builder;
    std::unique_ptr<Solver> solver;
};

SolverBenchmark::SolverBenchmark()
{
    builder = std::make_unique<ParticleBuilderImpl>();
    solver = std::make_unique<Euler>();
}

void SolverBenchmark::initTestCase()
{
}

void SolverBenchmark::cleanupTestCase()
{
}

void SolverBenchmark::testPerformanceWith10000Particles()
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> posDistribution(0, 1000);
    std::uniform_real_distribution<double> massDistribution(1e5, 1e20);

    Particles particles;
    for(size_t particle = 0; particle < 10000; particle++) {
        const double posX = posDistribution(generator);
        const double posY = posDistribution(generator);
        const double mass = massDistribution(generator);

        builder->setPosition(posX, posY)->setMass(mass)->addParticle(particles);
    }

    QBENCHMARK {
        const Particles solution = solver->solve(particles, DELTA_T);
    }
}

QTEST_APPLESS_MAIN(SolverBenchmark)

#include "tst_solverbenchmark.moc"

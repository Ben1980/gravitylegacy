#include <QString>
#include <QtTest>

class SolverBenchmark : public QObject
{
    Q_OBJECT

public:
    SolverBenchmark();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

SolverBenchmark::SolverBenchmark()
{
}

void SolverBenchmark::initTestCase()
{
}

void SolverBenchmark::cleanupTestCase()
{
}

void SolverBenchmark::testCase1()
{
    //QFETCH(QString, data);
    QBENCHMARK {
    }
}

QTEST_APPLESS_MAIN(SolverBenchmark)

#include "tst_solverbenchmark.moc"

#include <QString>
#include <QtTest>

class SolverTest : public QObject
{
    Q_OBJECT

public:
    SolverTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1_data();
    void testCase1();
};

SolverTest::SolverTest()
{
}

void SolverTest::initTestCase()
{
}

void SolverTest::cleanupTestCase()
{
}

void SolverTest::testCase1_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void SolverTest::testCase1()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(SolverTest)

#include "tst_solvertest.moc"

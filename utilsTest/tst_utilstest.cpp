#include <QString>
#include <QtTest>

class UtilsTest : public QObject
{
    Q_OBJECT

public:
    UtilsTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
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

void UtilsTest::testCase1()
{
    //QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(UtilsTest)

#include "tst_utilstest.moc"

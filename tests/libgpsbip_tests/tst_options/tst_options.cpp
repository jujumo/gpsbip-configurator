#include <QString>
#include <QtTest>

class Tst_options : public QObject
{
    Q_OBJECT

public:
    Tst_options();

private Q_SLOTS:
    void testCase1();
};

Tst_options::Tst_options()
{
}

void Tst_options::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Tst_options)

#include "tst_options.moc"

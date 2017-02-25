#include <QString>
#include <QtTest>

#include <libgpsbip/OptionBase.h>

class Tst_options : public QObject
{
    Q_OBJECT

public:
    Tst_options();

private Q_SLOTS:
    // OptionBase tests
    void testOptionBaseEnabledProperty();
};

Tst_options::Tst_options()
{
}

void Tst_options::testOptionBaseEnabledProperty()
{
    struct OptionStub : gpsbip::OptionBase { };
    OptionStub opt;
    opt.setEnabled(true);
    QCOMPARE(opt.isEnabled(), true);

    opt.setEnabled(false);
    QCOMPARE(opt.property("enabled").toBool(), false);
}
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Tst_options)

#include "tst_options.moc"

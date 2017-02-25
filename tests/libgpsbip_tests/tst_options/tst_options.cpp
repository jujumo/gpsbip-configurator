#include <QString>
#include <QtTest>

#include <libgpsbip/OptionBase.h>
#include <libgpsbip/OptionTypes.h>

class Tst_options : public QObject
{
    Q_OBJECT

public:
    Tst_options();

private Q_SLOTS:
    // OptionBase tests
    void testOptionBaseEnabledProperty();

    // Typed options tests
    void testStringOption();
    void testBoolOption();
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

void Tst_options::testStringOption()
{
    gpsbip::StringOption opt;
    opt = "test";

    QCOMPARE(static_cast<QString>(opt), QString("test"));
}

void Tst_options::testBoolOption()
{
    gpsbip::BoolOption opt;
    opt = true;
    QCOMPARE(static_cast<bool>(opt), true);
    opt = false;
    QCOMPARE(static_cast<bool>(opt), false);
}

QTEST_APPLESS_MAIN(Tst_options)

#include "tst_options.moc"

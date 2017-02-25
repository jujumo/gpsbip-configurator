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
    void testOptionBaseEnabler();

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

void Tst_options::testOptionBaseEnabler()
{
    gpsbip::BoolOption root;

    gpsbip::BoolOption dependant;
    dependant.dependsOn(root);

    QCOMPARE(dependant.isEnabled(), false);

    root = true;
    QCOMPARE(dependant.isEnabled(), true);

    root = false;
    QCOMPARE(dependant.isEnabled(), false);
}

void Tst_options::testStringOption()
{
    bool valueChanged = false;
    gpsbip::StringOption opt;
    connect(&opt, &gpsbip::StringOption::valueChanged, [&valueChanged] () { valueChanged = true; });
    opt = "test";

    QCOMPARE(static_cast<QString>(opt), QString("test"));
    QCOMPARE(valueChanged, true);

    valueChanged = false;
    opt = "test";
    QCOMPARE(valueChanged, false);
}

void Tst_options::testBoolOption()
{
    bool valueChanged = false;
    gpsbip::BoolOption opt;
    connect(&opt, &gpsbip::BoolOption::valueChanged, [&valueChanged] () { valueChanged = true; });

    opt = true;
    QCOMPARE(static_cast<bool>(opt), true);
    QCOMPARE(valueChanged, true);

    valueChanged = false;
    opt = false;
    QCOMPARE(static_cast<bool>(opt), false);
    QCOMPARE(valueChanged, true);

    valueChanged = false;
    opt = false;
    QCOMPARE(static_cast<bool>(opt), false);
    QCOMPARE(valueChanged, false);
}

QTEST_APPLESS_MAIN(Tst_options)

#include "tst_options.moc"

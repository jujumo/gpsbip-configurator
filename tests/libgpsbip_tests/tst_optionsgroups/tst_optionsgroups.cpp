#include <QString>
#include <QtTest>

#include <libgpsbip/OptionTypes.h>
#include <libgpsbip/OptionsGroupBase.h>
#include <libgpsbip/GpsOptionsGroup.h>

class MockGroup : public gpsbip::OptionsGroupBase
{
    Q_OBJECT

public:
    MockGroup() {
        auto r = new gpsbip::BoolOption();
        root = addOption(r);
        opt = addOption<gpsbip::BoolOption>("label");
        strOpt = addOption<gpsbip::StringOption>(*r, "label");
    }

    gpsbip::BoolOption* getRootOption() { return &get<gpsbip::BoolOption>(root); }
    gpsbip::BoolOption* getOption() { return &get<gpsbip::BoolOption>(opt); }
    gpsbip::StringOption* getStrOption() { return &get<gpsbip::StringOption>(strOpt); }

private:
    int root, opt, strOpt;
};

class Tst_optionsGroups : public QObject
{
    Q_OBJECT

public:
    Tst_optionsGroups();

private Q_SLOTS:
    // Base group validation
    void testOptionGroupMechanic();
    void testOptionGroupMechanic_optionParenting();

    // Real groups validation
    void validateGpsOptionsGroup();
};

Tst_optionsGroups::Tst_optionsGroups()
{
}

void Tst_optionsGroups::testOptionGroupMechanic()
{
    try {
        // Validates all 3 addOption variants (by definition, can't really assert that :/)
        MockGroup g;

        // Validates get<>
        gpsbip::BoolOption *root = g.getRootOption();
        QVERIFY(root != nullptr);
        gpsbip::BoolOption *opt = g.getOption();
        QVERIFY(opt != nullptr);
        gpsbip::StringOption *str = g.getStrOption();
        QVERIFY(str != nullptr);

        // Confirm that the string option is dependant on the root one and that the expected addOption was used
        QCOMPARE(str->isEnabled(), false);
        *root = true;
        QCOMPARE(str->isEnabled(), true);
    }
    catch (std::exception &e) {
        QFAIL(e.what());
    }
}

void Tst_optionsGroups::testOptionGroupMechanic_optionParenting()
{
    try {
        MockGroup g;

        gpsbip::BoolOption *root = g.getRootOption();
        gpsbip::BoolOption *opt = g.getOption();
        gpsbip::StringOption *str = g.getStrOption();

        QCOMPARE(root->parent(), &g);
        QCOMPARE(opt->parent(), &g);
        QCOMPARE(str->parent(), &g);
    }
    catch (std::exception &e) {
        QFAIL(e.what());
    }
}

void Tst_optionsGroups::validateGpsOptionsGroup()
{
    // Since we validated base mechanics previously, we will only validates that the
    // properties are indeed available and the relationships between those is correct.

    try {
        gpsbip::GpsOptionsGroup gps;
        gpsbip::BoolOption * const root         = qvariant_cast<gpsbip::BoolOption*>(gps.property("gpsEnabled"));
        gpsbip::BoolOption * const toDetection  = qvariant_cast<gpsbip::BoolOption*>(gps.property("takeOffDetection"));

        QVERIFY(root != nullptr);
        QVERIFY(toDetection != nullptr);

        // Enablement checking
        QCOMPARE(toDetection->isEnabled(), false);

        *root = true;

        QCOMPARE(toDetection->isEnabled(), true);
    }
    catch (std::exception &e) {
        QFAIL(e.what());
    }
}

QTEST_APPLESS_MAIN(Tst_optionsGroups)

#include "tst_optionsgroups.moc"

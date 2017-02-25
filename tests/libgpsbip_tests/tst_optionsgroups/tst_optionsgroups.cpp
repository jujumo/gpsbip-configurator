#include <QString>
#include <QtTest>

#include <libgpsbip/OptionTypes.h>
#include <libgpsbip/OptionsGroupBase.h>

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
    void testOptionGroupMechanic();
};

Tst_optionsGroups::Tst_optionsGroups()
{
}

void Tst_optionsGroups::testOptionGroupMechanic()
{
    // Validates all 3 addOption variants
    MockGroup g;

    // Validates get<>
    gpsbip::BoolOption *root = g.getRootOption();
    QVERIFY(root != nullptr);
    gpsbip::BoolOption *opt = g.getOption();
    QVERIFY(opt != nullptr);
}

QTEST_APPLESS_MAIN(Tst_optionsGroups)

#include "tst_optionsgroups.moc"

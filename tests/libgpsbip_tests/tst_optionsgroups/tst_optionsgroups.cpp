#include <QString>
#include <QtTest>

#include <libgpsbip/OptionTypes.h>
#include <libgpsbip/OptionsGroupBase.h>

#include <QDebug>
class MockGroup : public gpsbip::OptionsGroupBase
{
    Q_OBJECT
    Q_PROPERTY(int stubOption READ getStubOption WRITE setStubOption NOTIFY stubOptionChanged)

public:
    MockGroup() {
        opt = addOption(new gpsbip::BoolOption());
    }

    bool getStubOption() { return get<gpsbip::BoolOption>(opt); }
    void setStubOption(bool v) { get<gpsbip::BoolOption>(opt) = v; emit stubOptionChanged(); }

signals:
    void stubOptionChanged();

private:
    int opt;
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
    MockGroup g;
    g.setStubOption(true);
    QCOMPARE(g.getStubOption(), true);

    g.setProperty("stubOption", false);
    QCOMPARE(g.property("stubOption").toBool(), false);
}

QTEST_APPLESS_MAIN(Tst_optionsGroups)

#include "tst_optionsgroups.moc"

#include "../libgpsbip/OptionBase.h"
#include "../libgpsbip/OptionTypes.h"

namespace gpsbip {

void OptionBase::dependsOn(BoolOption &enabler)
{
    setEnabled(enabler);
    connect(&enabler, &BoolOption::valueChanged, this, [&] () { setEnabled(enabler); });
}

void OptionBase::setEnabled(bool e)
{
    if (m_isEnabled == e)
        return;
    m_isEnabled = e;
    emit enabledChanged();
}

}

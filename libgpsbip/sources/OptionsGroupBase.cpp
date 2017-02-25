#include "../libgpsbip/OptionsGroupBase.h"

namespace gpsbip {

int OptionsGroupBase::addOption(OptionBase *opt)
{
    Q_ASSERT(opt != nullptr);
    if (opt == nullptr) return -1;

    const int index = m_options.size();
    opt->setParent(this);
    m_options.append(opt);

    return index;
}

}

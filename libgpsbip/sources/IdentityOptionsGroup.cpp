#include "../libgpsbip/IdentityOptionsGroup.h"

#include <utility>

namespace gpsbip {

struct IdentityOptionsGroupImpl
{
    // Property indices
    int     pilotNameIdx = -1;
    int  aircraftNameIdx = -1;
    int  competitorIdIdx = -1;
    int       trigramIdx = -1;
    int  aircraftTypeIdx = -1;
};

IdentityOptionsGroup::IdentityOptionsGroup()
    : m_impl(new IdentityOptionsGroupImpl)
{
    m_impl->   pilotNameIdx = addOption<StringOption>("Pilot name"             );
    m_impl->aircraftNameIdx = addOption<StringOption>("Aircraft name"          );
    m_impl->competitorIdIdx = addOption<StringOption>("Competitor ID"          );
    m_impl->     trigramIdx = addOption<StringOption>("Trigram identification" );
    m_impl->aircraftTypeIdx = addOption<StringOption>("Aircraft type"          );
}

IdentityOptionsGroup::~IdentityOptionsGroup()
{
    // Can't be defaulted due to QScopedPointer
}

StringOption* IdentityOptionsGroup::   pilotName()  { return &get<StringOption>(m_impl->   pilotNameIdx); }
StringOption* IdentityOptionsGroup::aircraftName()  { return &get<StringOption>(m_impl->aircraftNameIdx); }
StringOption* IdentityOptionsGroup::competitorId()  { return &get<StringOption>(m_impl->competitorIdIdx); }
StringOption* IdentityOptionsGroup::     trigram()  { return &get<StringOption>(m_impl->     trigramIdx); }
StringOption* IdentityOptionsGroup::aircraftType()  { return &get<StringOption>(m_impl->aircraftTypeIdx); }

}

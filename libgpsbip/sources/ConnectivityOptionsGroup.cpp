#include "../libgpsbip/ConnectivityOptionsGroup.h"
#include <utility>

namespace gpsbip {

struct ConnectivityOptionsGroupImpl
{
    // Property indices
    int         isConnectedIdx = -1;
    int  connectionProtocolIdx = -1;
};

ConnectivityOptionsGroup::ConnectivityOptionsGroup()
    : m_impl(new ConnectivityOptionsGroupImpl)
{
    m_impl->       isConnectedIdx = addOption<StringOption>("Connected"  );
    m_impl->connectionProtocolIdx = addOption<StringOption>("Protocol"   );
}

ConnectivityOptionsGroup::~ConnectivityOptionsGroup()
{
    // Can't be defaulted due to QScopedPointer
}

BoolOption   * ConnectivityOptionsGroup::       isConnected()  { return &get<BoolOption   >(m_impl->       isConnectedIdx); }
IntegerOption* ConnectivityOptionsGroup::connectionProtocol()  { return &get<IntegerOption>(m_impl->connectionProtocolIdx); }

}

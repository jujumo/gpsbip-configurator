#include "../libgpsbip/GpsOptionsGroup.h"

#include <utility>

namespace gpsbip {

struct GpsOptionsGroupImpl
{
    // Property indices
    int gpsEnabled = -1;
    int takeOffDetection = -1;
};

GpsOptionsGroup::GpsOptionsGroup()
    : m_impl(new GpsOptionsGroupImpl)
{
    BoolOption* const gpsRootOpt = new BoolOption("GPS enabled");
    m_impl->gpsEnabled = addOption(gpsRootOpt);
    m_impl->takeOffDetection = addOption<BoolOption>(*gpsRootOpt, "Takeoff detection");
}

GpsOptionsGroup::~GpsOptionsGroup()
{
    // Can't be defaulted due to QScopedPointer
}

BoolOption* GpsOptionsGroup::gpsEnabled()       { return &get<BoolOption>(m_impl->gpsEnabled); }
BoolOption* GpsOptionsGroup::takeOffDetection() { return &get<BoolOption>(m_impl->takeOffDetection); }

}

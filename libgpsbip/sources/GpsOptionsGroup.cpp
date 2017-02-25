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
    m_impl->gpsEnabled = addOption(new BoolOption("GPS enabled"));
    m_impl->takeOffDetection = addOption(new BoolOption("Takeoff detection"));
}

GpsOptionsGroup::~GpsOptionsGroup()
{
    // Can't be defaulted due to QScopedPointer
}

BoolOption* GpsOptionsGroup::gpsEnabled()       { return &get<BoolOption>(m_impl->gpsEnabled); }
BoolOption* GpsOptionsGroup::takeOffDetection() { return &get<BoolOption>(m_impl->takeOffDetection); }

}

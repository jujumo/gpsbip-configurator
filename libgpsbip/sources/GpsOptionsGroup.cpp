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
    m_impl->gpsEnabled = addOption(new BoolOption());
    m_impl->takeOffDetection = addOption(new BoolOption());
}

GpsOptionsGroup::~GpsOptionsGroup()
{
    // Can't be defaulted due to QScopedPointer
}

bool GpsOptionsGroup::isGpsEnabled() const          { return get<BoolOption>(m_impl->gpsEnabled); }
void GpsOptionsGroup::setGpsEnabled(bool enabled)
{
    if (enabled == isGpsEnabled())
        return;

    get<BoolOption>(m_impl->gpsEnabled) = enabled;
    emit gpsEnabledChanged();
}

bool GpsOptionsGroup::isTakeOffDetectionEnabled() const   { return get<BoolOption>(m_impl->takeOffDetection); }
void GpsOptionsGroup::setTakeOffDetection(bool enabled)
{
    if (enabled == isTakeOffDetectionEnabled())
        return;

    get<BoolOption>(m_impl->takeOffDetection) = enabled;
    emit takeOffDetectionChanged();
}

}

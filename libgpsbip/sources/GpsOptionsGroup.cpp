#include "../libgpsbip/GpsOptionsGroup.h"

#include <utility>

namespace gpsbip {

struct GpsOptionsGroupImpl
{
    // Property indices
    int      isGpsEnabledIdx = -1;
    int isTakeoffDetectedIdx = -1;
    int   takeoffDistanceIdx = -1;
    int     isIgcRecordedIdx = -1;
    int     isKmlRecordedIdx = -1;
    int     isKmlGroundedIdx = -1;
    int   isGpsPerformantIdx = -1;
    int         gpsPeriodIdx = -1;
};

GpsOptionsGroup::GpsOptionsGroup()
    : m_impl(new GpsOptionsGroupImpl)
{
    BoolOption* const gpsRootOpt = new BoolOption("GPS enabled");
    m_impl->     isGpsEnabledIdx = addOption(gpsRootOpt);
    m_impl->isTakeoffDetectedIdx = addOption<BoolOption    >(*gpsRootOpt, "Takeoff detection");
    m_impl->  takeoffDistanceIdx = addOption<IntegerOption >(*gpsRootOpt, "Takeoff distance");
    m_impl->    isIgcRecordedIdx = addOption<BoolOption    >(*gpsRootOpt, "IGC track");
    m_impl->    isKmlRecordedIdx = addOption<BoolOption    >(*gpsRootOpt, "KML track");
    m_impl->    isKmlGroundedIdx = addOption<BoolOption    >(*gpsRootOpt, "KML 2D");
    m_impl->  isGpsPerformantIdx = addOption<BoolOption    >(*gpsRootOpt, "GPS full perf.");
    m_impl->        gpsPeriodIdx = addOption<IntegerOption >(*gpsRootOpt, "GPS period");

}

GpsOptionsGroup::~GpsOptionsGroup()
{
    // Can't be defaulted due to QScopedPointer
}

BoolOption   * GpsOptionsGroup::      isGpsEnabled() { return &get<BoolOption   >(m_impl->     isGpsEnabledIdx); }
BoolOption   * GpsOptionsGroup:: isTakeoffDetected() { return &get<BoolOption   >(m_impl->isTakeoffDetectedIdx); }
IntegerOption* GpsOptionsGroup::   takeoffDistance() { return &get<IntegerOption>(m_impl->  takeoffDistanceIdx); }
BoolOption   * GpsOptionsGroup::     isIgcRecorded() { return &get<BoolOption   >(m_impl->    isIgcRecordedIdx); }
BoolOption   * GpsOptionsGroup::     isKmlRecorded() { return &get<BoolOption   >(m_impl->    isKmlRecordedIdx); }
BoolOption   * GpsOptionsGroup::     isKmlGrounded() { return &get<BoolOption   >(m_impl->    isKmlGroundedIdx); }
BoolOption   * GpsOptionsGroup::   isGpsPerformant() { return &get<BoolOption   >(m_impl->  isGpsPerformantIdx); }
IntegerOption* GpsOptionsGroup::         gpsPeriod() { return &get<IntegerOption>(m_impl->        gpsPeriodIdx); }


}

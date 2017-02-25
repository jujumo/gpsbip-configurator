#include "gpsbip_context.h"

namespace gpsbip {

Context::Context()
{
}

GpsOptionsGroup& Context::gps()
{
    return m_gpsProps;
}

}

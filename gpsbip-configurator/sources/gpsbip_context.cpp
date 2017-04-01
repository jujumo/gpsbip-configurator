#include "gpsbip_context.h"

namespace gpsbip {

Context::Context()
{
}

IdentityOptionsGroup *Context::identity()
{
    return &m_idProps;
}

GpsOptionsGroup* Context::gps()
{
    return &m_gpsProps;
}

ConnectivityOptionsGroup *Context::connect()
{
    return &m_connectProps;
}

}

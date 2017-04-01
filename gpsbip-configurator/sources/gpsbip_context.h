#pragma once

#include <libgpsbip/ConnectivityOptionsGroup.h>
#include <libgpsbip/IdentityOptionsGroup.h>
#include <libgpsbip/GpsOptionsGroup.h>

#include <QObject>

namespace gpsbip {

    class Context : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(     IdentityOptionsGroup* identity READ identity CONSTANT)
        Q_PROPERTY(          GpsOptionsGroup*      gps READ      gps CONSTANT)
        Q_PROPERTY( ConnectivityOptionsGroup*  connect READ  connect CONSTANT)

    public:
        Context();
        Context(const Context&) = delete;
        Context(Context &&) = delete;
        Context& operator=(const Context&) = delete;
        Context& operator=(Context&&) = delete;

        // accessors
        IdentityOptionsGroup    *       identity();
        GpsOptionsGroup         *            gps();
        ConnectivityOptionsGroup*        connect();

    private:
        IdentityOptionsGroup       m_idProps;
        GpsOptionsGroup            m_gpsProps;
        ConnectivityOptionsGroup   m_connectProps;
    };

}

QML_DECLARE_TYPE(gpsbip::Context)

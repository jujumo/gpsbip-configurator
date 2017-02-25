#pragma once

#include <libgpsbip/GpsOptionsGroup.h>

#include <QObject>

namespace gpsbip {

    class Context : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(GpsOptionsGroup gps READ gps CONSTANT)

    public:
        Context();
        Context(const Context&) = delete;
        Context(Context &&) = delete;
        Context& operator=(const Context&) = delete;
        Context& operator=(Context&&) = delete;

        GpsOptionsGroup& gps();

    private:
        GpsOptionsGroup m_gpsProps;
    };

}

QML_DECLARE_TYPE(gpsbip::Context)

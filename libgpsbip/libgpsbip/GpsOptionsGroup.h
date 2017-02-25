#pragma once

#include "OptionsGroupBase.h"

namespace gpsbip {

    struct GpsOptionsGroupImpl;

    class GpsOptionsGroup : public OptionsGroupBase
    {
        Q_OBJECT

        Q_PROPERTY(BoolOption* gpsEnabled READ gpsEnabled CONSTANT)
        Q_PROPERTY(BoolOption* takeOffDetection READ takeOffDetection CONSTANT)

    public:
        GpsOptionsGroup();
        GpsOptionsGroup(const GpsOptionsGroup&) = delete;
        virtual ~GpsOptionsGroup();

        GpsOptionsGroup& operator=(const GpsOptionsGroup&) = delete;

        BoolOption* gpsEnabled();
        BoolOption* takeOffDetection();

    private:
        QScopedPointer<GpsOptionsGroupImpl> m_impl;
    };

}

QML_DECLARE_TYPE(gpsbip::GpsOptionsGroup)

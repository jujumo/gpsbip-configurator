#pragma once

#include "OptionsGroupBase.h"

namespace gpsbip {

    struct GpsOptionsGroupImpl;

    class GpsOptionsGroup : public OptionsGroupBase
    {
        Q_OBJECT

        Q_PROPERTY(bool gpsEnabled READ isGpsEnabled WRITE setGpsEnabled NOTIFY gpsEnabledChanged)
        Q_PROPERTY(bool takeOffDetection READ isTakeOffDetectionEnabled WRITE setTakeOffDetection NOTIFY takeOffDetectionChanged)

    public:
        GpsOptionsGroup();
        GpsOptionsGroup(const GpsOptionsGroup&) = delete;
        virtual ~GpsOptionsGroup();

        GpsOptionsGroup& operator=(const GpsOptionsGroup&) = delete;

        bool isGpsEnabled() const;
        void setGpsEnabled(bool enabled);

        bool isTakeOffDetectionEnabled() const;
        void setTakeOffDetection(bool enabled);

    signals:
        void gpsEnabledChanged();
        void takeOffDetectionChanged();

    private:
        QScopedPointer<GpsOptionsGroupImpl> m_impl;
    };

}

QML_DECLARE_TYPE(gpsbip::GpsOptionsGroup)

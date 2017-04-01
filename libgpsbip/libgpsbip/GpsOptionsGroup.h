#pragma once

#include "OptionsGroupBase.h"

namespace gpsbip {

    struct GpsOptionsGroupImpl;

    class GpsOptionsGroup : public OptionsGroupBase
    {
        Q_OBJECT

        Q_PROPERTY(BoolOption   *          isGpsEnabled READ      isGpsEnabled CONSTANT)
        Q_PROPERTY(BoolOption   *     isTakeoffDetected READ isTakeoffDetected CONSTANT)
        Q_PROPERTY(IntegerOption*       takeoffDistance READ   takeoffDistance CONSTANT)
        Q_PROPERTY(BoolOption   *         isIgcRecorded READ     isIgcRecorded CONSTANT)
        Q_PROPERTY(BoolOption   *         isKmlRecorded READ     isKmlRecorded CONSTANT)
        Q_PROPERTY(BoolOption   *         isKmlGrounded READ     isKmlGrounded CONSTANT)
        Q_PROPERTY(BoolOption   *       isGpsPerformant READ   isGpsPerformant CONSTANT)
        Q_PROPERTY(IntegerOption*             gpsPeriod READ         gpsPeriod CONSTANT)

    public:
        GpsOptionsGroup();
        GpsOptionsGroup(const GpsOptionsGroup&) = delete;
        virtual ~GpsOptionsGroup();

        GpsOptionsGroup& operator=(const GpsOptionsGroup&) = delete;

        BoolOption   *       isGpsEnabled();
        BoolOption   *  isTakeoffDetected();
        IntegerOption*    takeoffDistance();
        BoolOption   *      isIgcRecorded();
        BoolOption   *      isKmlRecorded();
        BoolOption   *      isKmlGrounded();
        BoolOption   *    isGpsPerformant();
        IntegerOption*          gpsPeriod();

    private:
        QScopedPointer<GpsOptionsGroupImpl> m_impl;
    };

}

QML_DECLARE_TYPE(gpsbip::GpsOptionsGroup)

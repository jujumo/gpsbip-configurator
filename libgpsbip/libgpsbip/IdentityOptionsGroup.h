#pragma once

#include "OptionsGroupBase.h"

namespace gpsbip {

    struct IdentityOptionsGroupImpl;

    class IdentityOptionsGroup : public OptionsGroupBase
    {
        Q_OBJECT

        Q_PROPERTY(StringOption*    pilotName READ    pilotName CONSTANT)
        Q_PROPERTY(StringOption* aircraftName READ aircraftName CONSTANT)
        Q_PROPERTY(StringOption* competitorId READ competitorId CONSTANT)
        Q_PROPERTY(StringOption*      trigram READ      trigram CONSTANT)
        Q_PROPERTY(StringOption* aircraftType READ aircraftType CONSTANT)

    public:
        IdentityOptionsGroup();
        IdentityOptionsGroup(const IdentityOptionsGroup&) = delete;
        virtual ~IdentityOptionsGroup();

        IdentityOptionsGroup& operator=(const IdentityOptionsGroup&) = delete;

        StringOption*    pilotName();
        StringOption* aircraftName();
        StringOption* competitorId();
        StringOption*      trigram();
        StringOption* aircraftType();

    private:
        QScopedPointer<IdentityOptionsGroupImpl> m_impl;
    };

}

QML_DECLARE_TYPE(gpsbip::IdentityOptionsGroup)

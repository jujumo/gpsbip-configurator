#pragma once

#include "OptionsGroupBase.h"

namespace gpsbip {

    struct ConnectivityOptionsGroupImpl;

    class ConnectivityOptionsGroup : public OptionsGroupBase
    {
        Q_OBJECT

        Q_PROPERTY(BoolOption   *        isConnected READ        isConnected CONSTANT)
        Q_PROPERTY(IntegerOption* connectionProtocol READ connectionProtocol CONSTANT)

    public:
        ConnectivityOptionsGroup();
        ConnectivityOptionsGroup(const ConnectivityOptionsGroup&) = delete;
        virtual ~ConnectivityOptionsGroup();

        ConnectivityOptionsGroup& operator=(const ConnectivityOptionsGroup&) = delete;

        BoolOption   *        isConnected();
        IntegerOption* connectionProtocol();

    private:
        QScopedPointer<ConnectivityOptionsGroupImpl> m_impl;
    };

}

QML_DECLARE_TYPE(gpsbip::ConnectivityOptionsGroup)

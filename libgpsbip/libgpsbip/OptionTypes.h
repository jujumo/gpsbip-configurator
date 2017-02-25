#pragma once

#include "OptionBase.h"

namespace gpsbip {

    class StringOption : public OptionBase
    {
        Q_OBJECT

    public:
        StringOption() = default;
        StringOption(const StringOption&) = default;
        StringOption& operator=(const StringOption&) = default;
        virtual ~StringOption() = default;

        operator QString&() { return m_value; }

        template <typename T>
        StringOption& operator=(T value) { m_value = QString(value); return *this; }

    private:
        QString m_value;
    };

    class BoolOption : public OptionBase
    {
        Q_OBJECT

    public:
        BoolOption() = default;
        BoolOption(const BoolOption&) = default;
        BoolOption& operator=(const BoolOption&) = default;
        virtual ~BoolOption() = default;

        operator bool() const { return m_value; }
        operator bool&() { return m_value; }

        BoolOption& operator=(bool value) { m_value = value; return *this; }

        // Disable any implicit conversion to bool by deleting cast operator/assignment for anything else than bool
        template <typename T>
        operator T() = delete;
        template <typename T>
        operator T&() = delete;
        template <typename T>
        BoolOption& operator=(T value) = delete;

    private:
        bool m_value;
    };

}

QML_DECLARE_TYPE(gpsbip::StringOption)
QML_DECLARE_TYPE(gpsbip::BoolOption)

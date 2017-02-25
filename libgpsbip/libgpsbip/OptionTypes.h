#pragma once

#include "OptionBase.h"

namespace gpsbip {

    class StringOption : public OptionBase
    {
        Q_OBJECT

        Q_PROPERTY(QString value MEMBER m_value NOTIFY valueChanged)

    public:
        StringOption(QString label = QString()) : OptionBase(label) {}
        StringOption(const StringOption&) = default;
        StringOption& operator=(const StringOption&) = default;
        virtual ~StringOption() = default;

        operator QString() { return m_value; }

        template <typename T>
        StringOption& operator=(T value)
        {
            if (m_value == QString(value)) return *this;
            m_value = QString(value);
            emit valueChanged();
            return *this;
        }

    signals:
        void valueChanged();

    private:
        QString m_value;
    };

    class BoolOption : public OptionBase
    {
        Q_OBJECT

        Q_PROPERTY(bool value MEMBER m_value NOTIFY valueChanged)

    public:
        BoolOption(QString label = QString()) : OptionBase(label), m_value(false) {}
        BoolOption(const BoolOption&) = default;
        BoolOption& operator=(const BoolOption&) = default;
        virtual ~BoolOption() = default;

        operator bool() const { return m_value; }

        BoolOption& operator=(bool value)
        {
            if (m_value == value) return *this;
            m_value = value;
            emit valueChanged();
            return *this;
        }

        // Disable any implicit conversion to bool by deleting cast operator/assignment for anything else than bool
        template <typename T>
        operator T() = delete;
        template <typename T>
        BoolOption& operator=(T value) = delete;

    signals:
        void valueChanged();

    private:
        bool m_value;
    };

}

QML_DECLARE_TYPE(gpsbip::StringOption)
QML_DECLARE_TYPE(gpsbip::BoolOption)

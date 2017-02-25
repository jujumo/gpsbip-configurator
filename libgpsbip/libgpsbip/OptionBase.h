#pragma once

#include <QObject>
#include <qqml.h>

namespace gpsbip {

    class OptionBase : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)

    public:
        OptionBase(const OptionBase&) = delete;
        OptionBase& operator=(const OptionBase&) = delete;
        virtual ~OptionBase() = default;

        bool isEnabled() const  { return m_isEnabled; }
        void setEnabled(bool e) { m_isEnabled = e; emit enabledChanged(); }

    signals:
        void enabledChanged();

    protected:
        OptionBase() = default;

    private:
        bool m_isEnabled;
    };

}

QML_DECLARE_TYPE(gpsbip::OptionBase)

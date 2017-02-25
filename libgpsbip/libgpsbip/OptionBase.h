#pragma once

#include <QObject>
#include <QString>
#include <qqml.h>

namespace gpsbip {

    class BoolOption;

    class OptionBase : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QString label READ label CONSTANT)
        Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)

    public:
        OptionBase(const OptionBase&) = delete;
        OptionBase& operator=(const OptionBase&) = delete;
        virtual ~OptionBase() = default;

        void dependsOn(BoolOption &enabler);

        QString label() const { return m_label; }

        bool isEnabled() const  { return m_isEnabled; }

    public slots:
        void setEnabled(bool e);

    signals:
        void enabledChanged();

    protected:
        OptionBase(QString label = QString()) : m_label(label), m_isEnabled(true) {}

    private:
        QString m_label;
        bool m_isEnabled;
    };

}

QML_DECLARE_TYPE(gpsbip::OptionBase)

#pragma once

#include "OptionTypes.h"

#include <exception>

#include <QList>

namespace gpsbip {

    class OptionsGroupBase : public QObject
    {
        Q_OBJECT

    public:
        OptionsGroupBase(const OptionsGroupBase&) = delete;
        OptionsGroupBase(OptionsGroupBase &&rhs) = delete;
        virtual ~OptionsGroupBase() = default;

        OptionsGroupBase& operator=(const OptionsGroupBase&) = delete;
        OptionsGroupBase& operator=(OptionsGroupBase&&) = delete;

    protected:
        OptionsGroupBase() = default;

        //! Adds \p opt to this group options' list.
        /*! Ownership of the option is transfered to the group instance.
         *  Null options will assert in debug, and be a no-op in release.
         *  \return the index at which the option will be available.
         */
        int addOption(OptionBase *opt);

        template <typename OptionT, typename ...Args>
        int addOption(const Args &...args)
        {
            return addOption(new OptionT(args...));
        }

        template <typename OptionType>
        OptionType& get(int index)
        {
            check_get(index);

            auto opt = reinterpret_cast<OptionType*>(m_options.at(index));
            Q_ASSERT(opt != nullptr);
            if (opt == nullptr) throw std::invalid_argument("Requested option type was incorrect.");

            return *opt;
        }

        template <typename OptionType>
        const OptionType& get(int index) const
        {
            check_get(index);

            auto opt = reinterpret_cast<OptionType*>(m_options.at(index));
            Q_ASSERT(opt != nullptr);
            if (opt == nullptr) throw std::invalid_argument("Requested option type was incorrect.");

            return *opt;
        }

    private:
        void check_get(int index) const
        {
            Q_ASSERT(index < m_options.size());
            if (index >= m_options.size()) throw std::out_of_range("Requested option index went beyond available options.");
            Q_ASSERT(index >= 0);
            if (index < 0) throw std::out_of_range("Requested option index was below 0.");
        }

    private:
        QList<OptionBase*> m_options;
    };

}
QML_DECLARE_TYPE(gpsbip::OptionsGroupBase)

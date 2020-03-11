// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_PREFERENCES_CONTROL_H__
#define __MURL_I_PREFERENCES_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_data.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IPreferencesControl
     * @brief The IPreferencesControl interface.
     * The IPreferencesControl implements operating system dependent preferences,
     * limitations to the number of keys and size of the keys should be considered.
     *  - iOS / tvOS / OSX uses standardUserDefaults from NSUserDefaults
     *  - Android uses SharedPreferences from Activity
     *  - Windows uses Registry entries
     */
    class IPreferencesControl : public IControlable
    {
    public:
        /**
         * @brief Check if a given key exists in the preferences.
         * @param key The item key to check.
         * @return true if the key exists.
         */
        virtual Bool Exists(const String& key) const = 0;

        /**
         * @brief Get the value from a preference item with a given key.
         * @param key The item key to query.
         * @return The value of the item, or an empty string if the key
         *  does not exist or the key does not contain a string.
         */
        virtual String GetValue(const String& key) const = 0;

        /**
         * @brief Get the value from a preference item with a given key.
         * @param key The item key to query.
         * @param value The string return value.
         * @return true if successful, false if the key does not exist or
         *  the key does not contain a string.
         *  If false the 'value' return value stays unchanged.
         */
        virtual Bool GetValue(const String& key, String& value) const = 0;

        /**
         * @brief Set the value to a preference item with a given key.
         * @param key The item key to set.
         * @param value The item's new value.
         * @return true if successful.
         */
        virtual Bool SetValue(const String& key, const String& value) = 0;

        /**
         * @brief Get binary data from a preference item with a given key.
         * @param key The item key to query.
         * @param value The data return value.
         * @return true if successful, false if the key does not exist or
         *  the key does not contain binary data.
         *  If false the 'value' return value stays unchanged.
         */
        virtual Bool GetData(const String& key, Data& value) const = 0;

        /**
         * @brief Set binary data to a preference item with a given key.
         * @param key The item key to set.
         * @param value The item's new binary data.
         * @return true if successful.
         */
        virtual Bool SetData(const String& key, const Data& value) = 0;

        /**
         * @brief Remove an preference item for a given key.
         * @param key The item key to reomve.
         * @return true if successful, false if the key does not exist.
         */
        virtual Bool Remove(const String& key) = 0;

    protected:
        virtual ~IPreferencesControl() {}
    };
}

#endif  // __MURL_I_PREFERENCES_CONTROL_H__

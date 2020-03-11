// Copyright 2015 Spraylight

#ifndef __MURL_I_CLOUD_RECORD_H__
#define __MURL_I_CLOUD_RECORD_H__

#include "murl_data.h"
#include "murl_enum.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface ICloudRecord
     * @brief The ICloudRecord interface.
     * ICloud records can be created by the ICloudControl interface.
     */
    class ICloudRecord
    {
    public:
        /**
         * @brief Enumeration of the record states.
         * Use GetStatus() to get the current status.
         */
        enum Status
        {
            /** The record is idle. */
            STATUS_IDLE = 0,
            /** The record is ready to set/get key/values. */
            STATUS_READY,
            /** The record is loading. */
            STATUS_LOADING,
            /** The record is saving. */
            STATUS_SAVING,
            /** The record is deleting. */
            STATUS_DELETING,
            /** The record has an error. */
            STATUS_ERROR
        };

        /**
         * @brief Get the cloud record status.
         * LoadRecord(), SaveRecord() and DeleteRecord() operation works asynchronously,
         * the application can check the current status to operate correctly.
         * @return The cloud record status.
         */
        virtual Status GetStatus() const = 0;

        /**
         * @brief Load the record.
         * After creating an ICloudRecord object or deleting a record, the status is
         * ICloudRecord::STATUS_IDLE. First of all this method must be called to get the record ready.
         * If the status is ICloudRecord::STATUS_ERROR this method can be called to re-load the record.
         * \n
         * When start loading, the status changes to ICloudRecord::STATUS_LOADING immediately.
         * When the loading is finished, the status changes to ICloudRecord::STATUS_READY.
         * In case of any error the status changes to ICloudRecord::STATUS_ERROR.
         * @return true if loading was started, false if the record is ready or a
         *  load / save / delete operation is running.
         */
        virtual Bool LoadRecord() = 0;

        /**
         * @brief Save the record.
         * When start saving, the status changes to ICloudRecord::STATUS_SAVING immediately.
         * When the saving is finished, the status changes to ICloudRecord::STATUS_READY.
         * In case of any error the status changes to ICloudRecord::STATUS_ERROR.
         * @return true if saving was started, false if the record status is not ready.
         */
        virtual Bool SaveRecord() = 0;

        /**
         * @brief Delete the record.
         * When start deleting, the status changes to ICloudRecord::STATUS_DELETING immediately.
         * When the deletion is finished, the status changes to ICloudRecord::STATUS_IDLE.
         *
         * In case of any error the status changes to ICloudRecord::STATUS_ERROR.
         * @return true if deletion was started, false if the record status is not ready.
         */
        virtual Bool DeleteRecord() = 0;

        /**
         * @brief Check if a key exists.
         * @param key The key name string.
         * @return true if the key exists, false if the key does not exist
         *  or the record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool KeyExists(const String& key) const = 0;

        /**
         * @brief Delete a key.
         * @param key The key name string.
         * @return true if successful, false if the record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool DeleteKey(const String& key) = 0;

        /**
         * @brief Get a string value by a key.
         * @param key The key name string.
         * @param value The string return value.
         * @return true if successful, false if the key does not exist or the
         * record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool GetStringValue(const String& key, String& value) const = 0;

        /**
         * @brief Set a string value for a key.
         * @param key The key name string.
         * @param value The string value to set.
         * @return true if successful, false if the record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool SetStringValue(const String& key, const String& value) = 0;

        /**
         * @brief Get a double value by a key.
         * @param key The key name string.
         * @param value The double return value.
         * @return true if successful, false if the key does not exist or the
         * record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool GetDoubleValue(const String& key, Double& value) const = 0;

        /**
         * @brief Set a double value for a key.
         * @param key The key name string.
         * @param value The double value to set.
         * @return true if successful, false if the record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool SetDoubleValue(const String& key, Double value) = 0;

        /**
         * @brief Get an integer value by a key.
         * @param key The key name string.
         * @param value The integer return value.
         * @return true if successful, false if the key does not exist or the
         * record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool GetIntValue(const String& key, SInt64& value) const = 0;

        /**
         * @brief Set an integer value for a key.
         * @param key The key name string.
         * @param value The integer value to set.
         * @return true if successful, false if the record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool SetIntValue(const String& key, SInt64 value) = 0;

        /**
         * @brief Get a data value by a key.
         * @param key The key name string.
         * @param value The data return value.
         * @return true if successful, false if the key does not exist or the
         * record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool GetDataValue(const String& key, Data& value) const = 0;

        /**
         * @brief Set a data value for a key.
         * @param key The key name string.
         * @param value The data value to set.
         * @return true if successful, false if the record status is not ICloudRecord::STATUS_READY.
         */
        virtual Bool SetDataValue(const String& key, const Data& value) = 0;

    protected:
        virtual ~ICloudRecord() {}
    };

    /**
     * @brief Get the ICloudRecord::Status enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<ICloudRecord::Status>& GetICloudRecordStatusEnum();
}

#endif  // __MURL_I_CLOUD_RECORD_H__

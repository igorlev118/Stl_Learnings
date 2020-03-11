// Copyright 2015 Spraylight

#ifndef __MURL_I_CLOUD_CONTROL_H__
#define __MURL_I_CLOUD_CONTROL_H__

#include "murl_i_cloud_record.h"
#include "murl_i_preferences_control.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface ICloudControl
     * @brief The ICloudControl interface.
     * The cloud control must be enabled during IApp::Configure()
     * by setting IEngineConfiguration::SetCloudControlEnable(). \n
     * On iOS/OSX/tvOS this control follows the iCloud guides: \n
     * An app has access to both a public and private database in each container.
     * The public database is for storing user and app data that is shared between
     * all instances of the app. By default, all users can read the public database,
     * but they need to enter iCloud credentials to write to the public database.
     * There’s a private database for each user of your app, but the app only has
     * access to the private database of the current user. The user has to enter
     * iCloud credentials for the app to read and write to the private database.
     * @see CloudKit Framework Reference.
     */
    class ICloudControl : public IControlable
    {
    public:
        /**
         * @brief The account states.
         */
        enum AccountStatus
        {
            /** Unknown account status, call GetAccountStatus() again next tick. */
            ACCOUNT_UNKNOWN = 0,
            /** The user is not authenticated. */
            ACCOUNT_NOT_AUTHENTICATED,
            /** The user is authenticated. */
            ACCOUNT_AUTHENTICATED
        };

        /**
         * @brief Get the user's cloud account status.
         * On iOS/OSX/tvOS follow the iCloud guides: \n
         * Before saving records, verify that the user is signed in to their iCloud account.
         * If the user is not signed in, present an alert instructing the user how to enter
         * their iCloud credentials and enable iCloud Drive. @see CloudKit Framework Reference.
         * @return true if the user is signed in.
         */
        virtual AccountStatus GetAccountStatus() = 0;

        /**
         * @brief Get the key-value store preference control.
         * @return The key-value store preference control.
         */
        virtual IPreferencesControl* GetKeyValueStore() = 0;

        /**
         * @brief The key-value store states.
         */
        enum KeyValueStatus
        {
            /** The idle state. */
            KEYVALUE_STATUS_IDLE = 0,
            /** Your attempt to write to key-value storage was discarded because an initial download
             *  from iCloud has not yet happened. That is, before you can first write key-value data,
             *  the system must ensure that your app’s local, on-disk cache matches the truth in iCloud. */
            KEYVALUE_STATUS_INITIAL_SYNC,
            /** A value changed in iCloud. This occurs when another device, running another instance
             *  of your app and attached to the same iCloud account, uploads a new value. */
            KEYVALUE_STATUS_SERVER_CHANGE,
            /** Your app’s key-value store has exceeded its space quota on the iCloud server. */
            KEYVALUE_STATUS_QUOTA_VIOLATION
        };

        /**
         * @brief Get the key-value store status.
         * If the status changes to KeyValueStatus::KEYVALUE_STATUS_INITIAL_SYNC or
         *  KeyValueStatus::KEYVALUE_STATUS_SERVER_CHANGE the changed keys can be evaluated
         *  by GetChangedKeys(). To receive further changes, the status must be cleared by
         *  calling ClearKeyValueStatus().
         * @return The key-value store status.
         */
        virtual KeyValueStatus GetKeyValueStatus() const = 0;

        /**
         * @brief Get the key-value store changed keys.
         * @return The key-value store changed keys.
         */
        virtual const StringArray& GetChangedKeys() const = 0;

        /**
         * @brief Clear the key-value store status.
         * Set the key-value store status to KeyValueStatus::KEYVALUE_STATUS_IDLE
         * and clears the changed keys.
         * @return true if successful.
         */
        virtual Bool ClearKeyValueStatus() = 0;

        /**
         * @brief Open a record in the private database from the default container
         *  with a given record type name.
         * @param recordName The record name.
         * @param recordType The record type name.
         * @return The record object.
         */
        virtual ICloudRecord* OpenPrivateRecord(const String& recordName,
                                                const String& recordType) = 0;

        /**
         * @brief Open a record in the private database from a specified container
         *  with a given record type name.
         * @param recordName The record name.
         * @param recordType The record type name.
         * @param containerName The container name.
         * @return The record object.
         */
        virtual ICloudRecord* OpenPrivateRecord(const String& recordName,
                                                const String& recordType,
                                                const String& containerName) = 0;

        /**
         * @brief Open a record in the public database from the default container
         *  with a given record type name.
         * @param recordName The record name.
         * @param recordType The record type name.
         * @return The record object.
         */
        virtual ICloudRecord* OpenPublicRecord(const String& recordName,
                                               const String& recordType) = 0;

        /**
         * @brief Open a record in the public database from a specified container
         *  with a given record type name.
         * @param recordName The record name.
         * @param recordType The record type name.
         * @param containerName The container name.
         * @return The record object.
         */
        virtual ICloudRecord* OpenPublicRecord(const String& recordName,
                                               const String& recordType,
                                               const String& containerName) = 0;

        /**
         * @brief Close a record.
         * @param record A reference to the record object to destroy.
         *  After destruction the pointer is set to null.
         * @param autoSave If true the record's ICloudRecord::SaveRecord() method is
         *  executed before closing the record.
         * @return true if successful.
         */
        virtual Bool CloseRecord(ICloudRecord*& record, Bool autoSave = false) = 0;

    protected:
        virtual ~ICloudControl() {}
    };

    /**
     * @brief Get the ICloudControl::AccountStatus enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<ICloudControl::AccountStatus>& GetICloudAccountStatusEnum();

    /**
     * @brief Get the ICloudControl::KeyValueStatus enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<ICloudControl::KeyValueStatus>& GetICloudKeyValueStatusEnum();
}

#endif  // __MURL_I_CLOUD_CONTROL_H__

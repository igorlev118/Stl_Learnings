// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_CUSTOM_CONTROLABLE_H__
#define __MURL_I_CUSTOM_CONTROLABLE_H__

#include "murl_i_controlable.h"
#include "murl_i_platform.h"
#include "murl_data.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface ICustomControlable
     * @brief The ICustomControlable interface.
     * The ICustomControlable is the base class for implementing custom control
     * objects which can be registered to the Output::IDeviceHandler.
     */
    class ICustomControlable : public IControlable
    {
    public:
        /**
         * @brief Initialize the control
         * @param platform A pointer to the platform.
         * @return true if successful.
         */
        virtual Bool Init(IPlatform* platform) = 0;
        /**
         * @brief De-initialize the control
         * @return true if successful.
         */
        virtual Bool DeInit() = 0;

        /**
         * @brief The engine is paused.
         * Is called if the application will resign active.
         */
        virtual void PauseEngine() = 0;

        /**
         * @brief The engine is continued.
         * Is called if the application did become active.
         * This happens also at start of the application.
         */
        virtual void ContinueEngine() = 0;

        /**
         * @brief The engine is suspended.
         * Is called if the application did enter background.
         */
        virtual void SuspendEngine() = 0;

        /**
         * @brief The engine is resumed.
         * Is called if the application did enter foreground.
         */
        virtual void ResumeEngine() = 0;

        /**
         * @name iOS / OSX application delegates
         * @brief Application delegate methods are called by iOS and OSX platform only.
         *  CustomControlable implementations for other platforms should leave these methods empty.
         * @{
         */

        /**
         * @brief The app application did finish launching.
         * On iOS this method is called by UIApplicationDelegate didFinishLaunchingWithOptions.
         * On OSX this method is called by NSApplicationDelegate applicationDidFinishLaunching.
         * @param launchOptions The launch options iOS dictionary (NSDictionary*) or
         *  OSX notification (NSNotification*).
         * @return false if not used, true if the launchOptions have been processed.
         */
        virtual Bool AppFinishLaunching(void* launchOptions) = 0;

        /**
         * @brief The application is opened by an url.
         * On iOS this method is called by UIApplicationDelegate openURL.
         * @param url The url string.
         * @param sourceApplication The source application string.
         * @param annotation A property-list object supplied by the source application.
         * @return false if not used, true if the url has been processed.
         */
        virtual Bool AppOpenURL(String url, String sourceApplication, void* annotation) = 0;

        /**
         * @brief The application is opened by an url with options.
         * On iOS this method is called by UIApplicationDelegate openURL.
         * @param url The url string.
         * @param options A dictionary of launch options.
         * @return false if not used, true if the url has been processed.
         */
        virtual Bool AppOpenURL(String url, void* options) = 0;

        /**
         * @brief The application received a local notification.
         * On iOS this method is called by UIApplicationDelegate didReceiveLocalNotification.
         * @param notification Encapsulates details about the notification (UILocalNotification*).
         */
        virtual void AppReceiveNotification(void* notification) = 0;

        /**
         * @brief The application is registered for push notifications.
         * On iOS / OSX this method is called by UIApplicationDelegate / NSApplicationDelegate
         * didRegisterForRemoteNotificationsWithDeviceToken or in case of an error by
         * didFailToRegisterForRemoteNotificationsWithError with an error parameter.
         * @param deviceToken The device token.
         * @param error An optional error (NSError*) or null.
         */
        virtual void AppRegisterForRemoteNotification(const ConstData& deviceToken, void* error) = 0;

        /**
         * @brief The application is registered for user notifications.
         * On iOS this method is called by UIApplicationDelegate didRegisterUserNotificationSettings.
         * @param notificationSettings The user notification settings (UIUserNotificationSettings*).
         */
        virtual void AppRegisterUserNotificationSettings(void* notificationSettings) = 0;

        /**
         * @brief Perform the custom action specified by a local or remote notification.
         * On iOS this method is called by UIApplicationDelegate handleActionWithIdentifier.
         * Depending on the notification either the parameter notification or userInfo is null.
         * @param identifier The identifier string associated with the action.
         * @param notification The local notification object that was triggered (UILocalNotification*).
         * @param userInfo Dictionary containing information related to the remote notification (NSDictionary*).
         */
        virtual void AppHandleActionWithIdentifier(const String& identifier, void* notification, void* userInfo) = 0;

        /**
         * @brief Enumeration to indicate the result of a background fetch operation.
         */
        enum FetchResult
        {
            /** The control does not support the operation. */
            FETCHRESULT_NONE = 0,
            /** New data was successfully downloaded. */
            FETCHRESULT_NEWDATA,
            /** There was no new data to download. */
            FETCHRESULT_NODATA,
            /** An attempt to download data was made but that attempt failed. */
            FETCHRESULT_FAILED
        };

        /**
         * @brief The application received a push notification.
         * On iOS / OSX this method is called by UIApplicationDelegate / NSApplicationDelegate
         *  didReceiveRemoteNotification.
         * @param userInfo Encapsulates details about the notification (NSDictionary*).
         * @return A result that indicates whether content was available.
         */
        virtual FetchResult AppReceiveRemoteNotification(void* userInfo) = 0;

        /**
         * @brief The application can perform a background fetch.
         * On iOS this method is called by UIApplicationDelegate performFetchWithCompletionHandler.
         * @return A result that indicates whether content was available.
         */
        virtual FetchResult AppPerformBackgroundFetch() = 0;

        /**
         * @brief Events related to a URL session are waiting to be processed.
         * @param identifier The identifier of the URL session requiring attention.
         */
        virtual void AppHandleEventsForBackgroundURLSession(const String& identifier) = 0;

        /**
         * @brief The application will terminate.
         * On iOS / OSX this method is called by UIApplicationDelegate / NSApplicationDelegate
         *  applicationWillTerminate.
         */
        virtual void AppWillTerminate() = 0;
        /** @} */

    protected:
        virtual ~ICustomControlable() {}
    };
}

#endif  // __MURL_I_CUSTOM_CONTROLABLE_H__

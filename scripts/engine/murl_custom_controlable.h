// Copyright 2014 Spraylight GmbH

#ifndef __MURL_CUSTOM_CONTROLABLE_H__
#define __MURL_CUSTOM_CONTROLABLE_H__

#include "murl_i_custom_controlable.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @brief The CustomControlable default implementation class.
     * The CustomControlable should be used as the base class for implementing a
     * custom control object to get default implelentations for all methods.
     */
    class CustomControlable : public ICustomControlable
    {
    public:
        /**
         * @brief Constructor taking the name of the control.
         * @param controlName The name of the control.
         */
        CustomControlable(const String& controlName)
        : mControlName(controlName)
        {
        }

        /**
         * @brief The destructor.
         */
        virtual ~CustomControlable()
        {
        }

        /**
         * @brief Default implementation of IControlable::GetName().
         * @return The controlable's name.
         */
        virtual const String& GetName() const
        {
            return mControlName;
        }

        /**
         * @brief Default implementation of IControlable::FrameUpdate().
         */
        virtual void FrameUpdate()
        {
        }

        /**
         * @brief Default implementation of IControlable::LogicUpdate().
         */
        virtual void LogicUpdate()
        {
        }

        /**
         * @brief Default implementation of IControlable::ConfigChanged().
         * @param appConfig The application configuration object.
         */
        virtual void ConfigChanged(const IAppConfiguration* appConfig)
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::Init().
         * @param platform A pointer to the platform.
         * @return true if successful.
         */
        virtual Bool Init(IPlatform* platform)
        {
            return true;
        }

        /**
         * @brief Default implementation of ICustomControlable::DeInit().
         * @return true if successful.
         */
        virtual Bool DeInit()
        {
            return true;
        }

        /**
         * @brief Default implementation of ICustomControlable::PauseEngine().
         */
        virtual void PauseEngine()
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::ContinueEngine().
         */
        virtual void ContinueEngine()
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::SuspendEngine().
         */
        virtual void SuspendEngine()
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::ResumeEngine().
         */
        virtual void ResumeEngine()
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::AppFinishLaunching().
         * @param launchOptions The launch options.
         * @return false if not used, true if the launchOptions have been processed.
         */
        virtual Bool AppFinishLaunching(void* launchOptions)
        {
            return false;
        }

        /**
         * @brief Default implementation of ICustomControlable::AppOpenURL().
         * @param url The url string.
         * @param sourceApplication The source application string.
         * @param annotation A property-list object supplied by the source application.
         * @return false if not used, true if the url has been processed.
         */
        virtual Bool AppOpenURL(String url, String sourceApplication, void* annotation)
        {
            return false;
        }

        /**
         * @brief Default implementation of ICustomControlable::AppOpenURL().
         * @param url The url string.
         * @param options A dictionary of launch options.
         * @return false if not used, true if the url has been processed.
         */
        virtual Bool AppOpenURL(String url, void* options)
        {
            return false;
        }

        /**
         * @brief Default implementation of ICustomControlable::AppReceiveNotification().
         * @param notification Encapsulates details about the notification (UILocalNotification*).
         */
        virtual void AppReceiveNotification(void* notification)
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::AppRegisterForRemoteNotification().
         * @param deviceToken The device token.
         * @param error An optional error (NSError*) or null.
         */
        virtual void AppRegisterForRemoteNotification(const ConstData& deviceToken, void* error)
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::AppRegisterUserNotificationSettings().
         * @param notificationSettings The user notification settings (UIUserNotificationSettings*).
         */
        virtual void AppRegisterUserNotificationSettings(void* notificationSettings)
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::AppHandleActionWithIdentifier().
         * @param identifier The identifier string associated with the action.
         * @param notification The local notification object that was triggered (UILocalNotification*).
         * @param userInfo Dictionary containing information related to the remote notification (NSDictionary*).
         */
        virtual void AppHandleActionWithIdentifier(const String& identifier, void* notification, void* userInfo)
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::AppReceiveRemoteNotification().
         * @param userInfo Encapsulates details about the notification (NSDictionary*).
         * @return A result that indicates whether content was available.
         */
        virtual FetchResult AppReceiveRemoteNotification(void* userInfo)
        {
            return FETCHRESULT_NONE;
        }

        /**
         * @brief Default implementation of ICustomControlable::AppPerformBackgroundFetch().
         * @return A result that indicates whether content was available.
         */
        virtual FetchResult AppPerformBackgroundFetch()
        {
            return FETCHRESULT_NONE;
        }

        /**
         * @brief Default implementation of ICustomControlable::AppHandleEventsForBackgroundURLSession().
         * @param identifier The identifier of the URL session requiring attention.
         */
        virtual void AppHandleEventsForBackgroundURLSession(const String& identifier)
        {
        }

        /**
         * @brief Default implementation of ICustomControlable::AppWillTerminate().
         */
        virtual void AppWillTerminate()
        {
        }

    protected:
        String mControlName;
    };
}

#endif  // __MURL_I_CUSTOM_CONTROLABLE_H__

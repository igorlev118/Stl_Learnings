// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_I_APP_STATE_H__
#define __MURL_I_APP_STATE_H__

#include "murl_i_app_configuration.h"
#include "murl_i_engine_configuration.h"
#include "murl_i_platform_configuration.h"
#include "murl_i_loader.h"

namespace Murl
{
    class IFileInterface;

    namespace Logic
    {
        class IFactory;
        class IDeviceHandler;
    }

    namespace Net
    {
        class IFactory;
    }

    /**
     * @ingroup MurlInterfaces
     * @interface IAppState
     * @brief The application state interface.
     * The application state object contains all necessary engine interfaces for
     * for initializing an application.
     * \n
     * IApp interface methods gets an instance of the IAppState object by parameter.
     */
    class IAppState
    {
    public:
        /**
         * @brief Get the logic object factory.
         * @return The logic object factory.
         */
        virtual Logic::IFactory* GetLogicFactory() const = 0;

        /**
         * @brief Get the platform configuration object.
         * @return The configuration object.
         */
        virtual const IPlatformConfiguration* GetPlatformConfiguration() const = 0;

        /**
         * @brief Get the engine configuration object.
         * @return The configuration object.
         */
        virtual const IEngineConfiguration* GetEngineConfiguration() const = 0;

        /**
         * @brief Get the app configuration object.
         * @return The configuration object.
         */
        virtual IAppConfiguration* GetAppConfiguration() const = 0;

        /**
         * @brief Get the device handler object.
         * @return The device handler object.
         */
        virtual Logic::IDeviceHandler* GetDeviceHandler() const = 0;

        /**
         * @brief Get the file interface object.
         * @return The file interface object.
         */
        virtual IFileInterface* GetFileInterface() const = 0;

        /**
         * @brief Get the net object factory.
         * @return The net object factory.
         */
        virtual Net::IFactory* GetNetFactory() const = 0;

        /**
         * @brief Get the package loader object.
         * @return The package loader object.
         */
        virtual ILoader* GetLoader() const = 0;

    protected:
        virtual ~IAppState() {}
    };
}

#endif  // __MURL_I_APP_STATE_H__

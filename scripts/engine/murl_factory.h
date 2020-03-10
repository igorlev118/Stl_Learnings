// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_FACTORY_H__
#define __MURL_FACTORY_H__

#include "murl_types.h"

namespace Murl
{
    class IEngine;
    class IDeviceHandler;
    class IPlatform;
    class IPlatformConfiguration;

    /**
     * @ingroup MurlClasses
     * @brief The factory class used to create and initialize the engine,
     * configuration and device handler instances.
     */
    class Factory
    {
    public:
        /**
         * @brief The default constructor.
         */
        Factory();
        /**
         * @brief The destructor.
         */
        virtual ~Factory();

        /**
         * @brief Initialize the engine.
         * Calls the Murl::Engine::Init() method.
         * @param platform The platform.
         * @return true if successful.
         */
        Bool Init(IPlatform* platform);

        /**
         * @brief Deinitialize the engine.
         * Calls the Murl::Engine::DeInit() method.
         * @return true if successful.
         */
        Bool DeInit();

        /**
         * @brief Create an engine object.
         * @return The created engine object, or null if failed.
         */
        IEngine* CreateEngine();
        /**
         * @brief Destroy an engine object.
         * @param engine A reference to the engine pointer.
         *  After destruction the pointer is set to null.
         * @return true if successful.
         */
        Bool DestroyEngine(IEngine*& engine);

        /**
         * @brief Create and initialize the platform configuration object.
         * Create and initialize the internal IAppConfiguration object
         * and the IEngineConfiguration object.
         * @return The created platform configuration object, or null if failed.
         */
        IPlatformConfiguration* CreatePlatformConfiguration();
        /**
         * @brief Destroy the platform configuration object.
         * Destroy the internal IAppConfiguration object and the
         * IEngineConfiguration object.
         * @param config A reference to the platform configuration pointer.
         *  After destruction the pointer is set to null.
         * @return true if successful.
         */
        Bool DestroyPlatformConfiguration(IPlatformConfiguration*& config);

        /**
         * @brief Create a device handler object.
         * @return The created device handler object, or null if failed.
         */
        IDeviceHandler* CreateDeviceHandler();
        /**
         * @brief Destroy device handler object.
         * @param deviceHandler A reference to the device handler pointer.
         *  After destruction the pointer is set to null.
         * @return true if successful.
         */
        Bool DestroyDeviceHandler(IDeviceHandler*& deviceHandler);

    protected:
        IPlatform* mPlatform;
    };
}

#endif  // __MURL_FACTORY_H__

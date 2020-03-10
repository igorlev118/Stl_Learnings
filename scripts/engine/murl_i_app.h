// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_APP_H__
#define __MURL_I_APP_H__

#include "murl_i_app_state.h"
#include "murl_i_app_addon_registry.h"
#include "murl_i_app_factory_registry.h"
#include "murl_i_app_module_registry.h"
#include "murl_i_file_interface.h"

namespace Murl
{
    namespace Logic
    {
        class IFactory;
    }

    /**
     * @ingroup MurlInterfaces
     * @interface IApp
     * @brief The application interface.
     * An application implements the IApp interface to integrate to the engine.
     */
    class IApp
    {
    public:
        /**
         * @brief Configure the application.
         * This method is called by the platform first of all to provide
         * the current platform configuration to the application.
         * At this point the application can read the platform configuration
         * and setup the app configuration and the engine configuration.
         * The application can return false to abort starting the application.
         * @param engineConfig The engine configuration object.
         * @param fileInterface The file interface object.
         * @return true if successful.
         */
        virtual Bool Configure(IEngineConfiguration* engineConfig, IFileInterface* fileInterface) = 0;

        /**
         * @brief Check if the current app configuration matches a given user ID.
         * This method is called by the engine whenever a resource object or graph node
         * needs to be created that depends on some user-defined condition. The app
         * should return true whenever the queried user configuration ID matches the
         * current configuration.
         * @param userConfigId A string representing the user-defined configuration
         *      to be queried.
         * @return true if the current configuration is represented by the given ID.
         */
        virtual Bool IsUserConfigurationMatching(const String& userConfigId) const = 0;

        /**
         * @brief Register custom add-ons with the engine.
         * This method is called by the engine core before initializing the application, and
         * also before any of the other register methods below. It allows the application
         * to create and register custom add-ons as needed, which in turn are allowed to
         * register their own factory and module classes.
         * @param addonRegistry The registry to access individual add-ons.
         * @return true if successful.
         */
        virtual Bool RegisterCustomAddonClasses(IAppAddonRegistry* addonRegistry) = 0;
        /**
         * @brief Unregister custom add-ons from the engine.
         * This method is called by the engine core after deinitializing the application, and
         * after all configuration-dependent modules and factory classes have been released.
         * See RegisterCustomAddonClasses().
         * @param addonRegistry The registry to access individual add-ons.
         * @return true if successful.
         */
        virtual Bool UnregisterCustomAddonClasses(IAppAddonRegistry* addonRegistry) = 0;

        /**
         * @brief Register custom factory classes with the engine.
         * This method is called by the engine core before initializing the application, and
         * also before creating any configuration-dependent modules, such as video/audio
         * renderers and physics engine.
         * An application can register custom factory classes with any of the registries provided
         * by the factoryRegistry object to provide extensions to different engine components,
         * such as graph nodes, resource loaders or audio/video renderers and physics engines.
         * @param factoryRegistry The main registry to access individual factory registries.
         * @return true if successful.
         */
        virtual Bool RegisterCustomFactoryClasses(IAppFactoryRegistry* factoryRegistry) = 0;
        /**
         * @brief Unregister custom factory classes from the engine.
         * This method is called by the engine core after deinitializing the application, and
         * after all configuration-dependent modules have been released.
         * See RegisterCustomFactoryClasses().
         * @param factoryRegistry The main registry to access individual factory registries.
         * @return true if successful.
         */
        virtual Bool UnregisterCustomFactoryClasses(IAppFactoryRegistry* factoryRegistry) = 0;

        /**
         * @brief Register custom module classes with the engine.
         * This method is called by the engine core after RegisterCustomFactoryClasses(), when
         * there is already a present set of configuration-dependent modules, such as audio
         * or video renderers, and physics engine.
         * An application can register custom module classes with any of the registries provided
         * by the moduleRegistry parameter to provide extensions to different engine modules,
         * such as audio/video renderer objects or physics objects.
         * @param moduleRegistry The main registry to access individual module registries.
         * @return true if successful.
         */
        virtual Bool RegisterCustomModuleClasses(IAppModuleRegistry* moduleRegistry) = 0;
        /**
         * @brief Unregister custom module classes from the engine.
         * This method is called by the engine core after deinitializing the application, but
         * before the actual configuration-dependent modules are released.
         * See RegisterCustomModuleClasses().
         * @param moduleRegistry The main registry to access individual module registries.
         * @return true if successful.
         */
        virtual Bool UnregisterCustomModuleClasses(IAppModuleRegistry* moduleRegistry) = 0;

        /**
         * @brief Initialize the application.
         * This method is called by the engine core for application initialization.
         * At this point an application can trigger loading resources and
         * creating Logic::IProcessor objects.
         * @param appState The application state object.
         * @return true if successful.
         */
        virtual Bool Init(const IAppState* appState) = 0;
        /**
         * @brief Deinitialize the application.
         * This method is called by the engine core for application deinitialization.
         * At this point an application can destroy Logic::IProcessor objects.
         * @param appState The application state object.
         * @return true if successful.
         */
        virtual Bool DeInit(const IAppState* appState) = 0;

        virtual ~IApp() {}
    };

    /** @brief The IApp shared pointer type. */
    typedef SharedPointer<IApp> IAppPtr;
}

#endif  // __MURL_I_APP_H__

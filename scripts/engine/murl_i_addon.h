// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_ADDON_H__
#define __MURL_I_ADDON_H__

#include "murl_i_app_state.h"
#include "murl_i_app_factory_registry.h"
#include "murl_i_app_module_registry.h"

#include "murl_graph_i_node.h"
#include "murl_video_i_object.h"
#include "murl_audio_i_object.h"

#include "murl_shared_pointer.h"

namespace Murl
{
    namespace Logic
    {
        class IFactory;
    }

    /**
     * @ingroup MurlAddonsNamespaces
     * @brief Namespace containing addon related interfaces.
     */
    namespace Addons
    {
    }

    /**
     * @ingroup MurlInterfaces
     * @interface IAddon
     * @brief The add-on interface.
     * An add-on represents an optionally linkable component that can be used
     * to extend the engine's functionality, e.g. the Facebook integration.
     */
    class IAddon
    {
    public:
        /**
         * @brief Get the addon's name.
         * @return The addon's name.
         */
        virtual String GetName() const = 0;

        /**
         * @brief Configure the addon.
         * This method is called by the engine right after IApp::RegisterCustomAddonClasses()
         * is called, in order to apply any add-on specific settings to the engine and/or
         * app configuration. Note that this is happening after IApp::Configure() gets called,
         * so these settings are not yet available in during IApp::Configure().
         * @param engineConfig The engine configuration object.
         * @param fileInterface The file interface object.
         * @return true if successful.
         */
        virtual Bool Configure(IEngineConfiguration* engineConfig, IFileInterface* fileInterface) = 0;

        /**
         * @brief Register custom factory classes with the engine.
         * This method is used to register custom factory classes specific for this add-on,
         * and it is called by the engine core right before its counterpart
         * IApp::RegisterCustomFactoryClasses().
         * @param factoryRegistry The main registry to access individual factory registries.
         * @return true if successful.
         */
        virtual Bool RegisterCustomFactoryClasses(IAppFactoryRegistry* factoryRegistry) = 0;
        /**
         * @brief Unregister custom factory classes from the engine.
         * This method is called by the engine core right after
         * IApp::UnregisterCustomFactoryClasses().
         * @param factoryRegistry The main registry to access individual factory registries.
         * @return true if successful.
         */
        virtual Bool UnregisterCustomFactoryClasses(IAppFactoryRegistry* factoryRegistry) = 0;

        /**
         * @brief Register custom module classes with the engine.
         * This method is used to register custom module classes with any of the registries
         * provided by the moduleRegistry parameter to provide extensions to different engine
         * modules, such as audio/video renderer objects or physics objects. It is called
         * right before its counterpart IApp::RegisterCustomModuleClasses().
         * @param moduleRegistry The main registry to access individual module registries.
         * @return true if successful.
         */
        virtual Bool RegisterCustomModuleClasses(IAppModuleRegistry* moduleRegistry) = 0;
        /**
         * @brief Unregister custom module classes from the engine.
         * This method is called by the engine core right after
         * IApp::UnregisterCustomModuleClasses().
         * @param moduleRegistry The main registry to access individual module registries.
         * @return true if successful.
         */
        virtual Bool UnregisterCustomModuleClasses(IAppModuleRegistry* moduleRegistry) = 0;

        /**
         * @brief Initialize the add-on.
         * This method is called by the engine core for add-on initialization, immediately
         * before the application is initialized. See IApp::Init().
         * @param appState The application state object.
         * @return true if successful.
         */
        virtual Bool Init(const IAppState* appState) = 0;
        /**
         * @brief Deinitialize the add-on.
         * This method is called by the engine core for application deinitialization,
         * immediately after the application is de-initialized. See IApp::DeInit().
         * @param appState The application state object.
         * @return true if successful.
         */
        virtual Bool DeInit(const IAppState* appState) = 0;

        virtual ~IAddon() {}
    };

    /** The IAddon shared pointer type. */
    typedef SharedPointer<IAddon> IAddonPtr;
}

#endif  // __MURL_I_ADDON_H__

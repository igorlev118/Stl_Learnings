// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_I_APP_ADDON_REGISTRY_H__
#define __MURL_I_APP_ADDON_REGISTRY_H__

#include "murl_i_addon.h"

namespace Murl
{
    /**
     * @ingroup MurlFactoryInterfaces
     * @interface IAppAddonRegistry
     * @brief The add-on registry interface.
     * An add-on represents an optionally linkable component that can be used
     * to extend the engine's functionality, e.g. the Facebook integration.\n
     * Add-ons are typically registered by the application in IApp::RegisterCustomAddonClasses()
     * and unregistered in IApp::UnregisterCustomAddonClasses().
     */
    class IAppAddonRegistry
    {
    public:
        /**
         * @brief Register an add-on.
         * @param addon The add-on to register.
         * @return true if successful.
         */
        virtual Bool RegisterAddon(IAddonPtr addon) = 0;

        /**
         * @brief Unregister an add-on.
         * @param addon The add-on to unregister.
         * @return true if successful.
         */
        virtual Bool UnregisterAddon(IAddonPtr addon) = 0;

        /**
         * @brief Get the number of registered an add-ons.
         * @return The number of registered an add-ons.
         */
        virtual UInt32 GetNumberOfRegisteredAddons() const = 0;

        /**
         * @brief Get a registered add-on.
         * A valid add-on index is [0 .. GetNumberOfRegisteredAddons() - 1].
         * @param index The zero-based index of the add-on.
         * @return The registered add-on or null if index is out of range.
         */
        virtual IAddonPtr GetRegisteredAddon(UInt32 index) const = 0;

    protected:
        virtual ~IAppAddonRegistry() {}
    };
}

#endif  // __MURL_I_APP_ADDON_REGISTRY_H__

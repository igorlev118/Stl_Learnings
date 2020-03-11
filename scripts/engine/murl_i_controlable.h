// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_CONTROLABLE_H__
#define __MURL_I_CONTROLABLE_H__

#include "murl_string.h"

namespace Murl
{
    class IAppConfiguration;

    /**
     * @ingroup MurlControlInterfaces
     * @interface IControlable
     * @brief The IControlable interface.
     * The IControlable is the base class for implementing control
     * objects which can be registered to the Output::IDeviceHandler.
     */
    class IControlable
    {
    public:
        /**
         * @brief Get the controlable's name.
         * @return The controlable's name.
         */
        virtual const String& GetName() const = 0;

        /**
         * @brief Is executed in the platform thread context each frame tick.
         */
        virtual void FrameUpdate() = 0;

        /**
         * @brief Is executed in the logic thread context each logic tick.
         */
        virtual void LogicUpdate() = 0;

        /**
         * @brief Notification of changed configuration.
         * The notification is executed in the engine thread context
         * if any configuration item has changed.
         * @param appConfig The application configuration object.
         */
        virtual void ConfigChanged(const IAppConfiguration* appConfig) = 0;

    protected:
        virtual ~IControlable() {}
    };
}

#endif  // __MURL_I_CONTROLABLE_H__

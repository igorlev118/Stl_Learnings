// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_PLATFORM_H__
#define __MURL_I_PLATFORM_H__

#include "murl_types.h"

namespace Murl
{
    class IFileInterface;
    class IMethodCall;
    class IPlatformConfiguration;

    class IPlatform
    {
    public:
        /**
         * @brief Get the const platform configuration object.
         * @return The platform configuration object.
         */
        virtual const IPlatformConfiguration* GetPlatformConfiguration() const = 0;

        /**
         * @brief Get the file interface object.
         * @return The file interface object.
         */
        virtual IFileInterface* GetFileInterface() const = 0;

        /**
         * @brief Invoke a method in the render thread context.
         * The render thread context is the context of the EndFrame() caller.
         * The invoke call is waiting until the method was processed.
         * This method is intend for internal use only.
         * @param call The method call object.
         * @param waitForMore If true, the engine continues processing the message
         *      loop for a given maximum amount of time, in order to e.g. speed up
         *      initialization of multiple render objects in a sequence. The maximum
         *      time can be set via IEngineConfiguration::SetSyncLoadingTimeout().
         * @return true if successful.
         */
        virtual Bool Invoke(const IMethodCall* call, Bool waitForMore) = 0;

    protected:
        virtual ~IPlatform() {}
    };
}

#endif  // __MURL_I_PLATFORM_H__

// Copyright 2013 Spraylight GmbH

#ifndef __MURL_ENGINE_H__
#define __MURL_ENGINE_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief The engine class used to initialize the engine.
     */
    class Engine
    {
    public:
        /**
         * @brief Initialize the engine.
         * Calls the Core::Version::Init() and the System::Init() method.\n
         * This method is intentionally static and can be used to initialize
         * the engine's subsystems, e.g. for implementing tools with no rendering.
         * @return true if successful.
         */
        static Bool Init();

        /**
         * @brief Deinitialize the engine.
         * Calls the System::DeInit() and the Core::Version::DeInit() method.\n
         * This method is intentionally static and can be used to de-initialize
         * the engine's subsystems, e.g. for implementing tools with no rendering.
         * @return true if successful.
         */
        static Bool DeInit();
    };
}

#endif  // __MURL_ENGINE_H__

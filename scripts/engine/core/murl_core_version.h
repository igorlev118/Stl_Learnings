// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_CORE_VERSION_H__
#define __MURL_CORE_VERSION_H__

#include "murl_string.h"

namespace Murl
{
    namespace Core
    {
        /**
         * @ingroup MurlCoreNamespaces
         * @brief The core version namspace.
         * The version information is initialized by the engine's core
         * and is accessible by the IEngineConfiguration interface.
         */
        namespace Version
        {
            /**
             * @brief Initialize the version information.
             * This method is called by the engine's Murl::Engine::Init() method.
             * @return true if successful.
             */
            Bool Init();
            /**
             * @brief Deinitialize the version information.
             * This method is called by the engine's Murl::Engine::DeInit() method.
             * @return true if successful.
             */
            Bool DeInit();

            /**
             * @brief Get the major revision of the engine.
             * @return The major revision of the engine.
             */
            UInt32 GetMajorRevision();
            /**
             * @brief Get the minor revision of the engine.
             * @return The minor revision of the engine.
             */
            UInt32 GetMinorRevision();
            /**
             * @brief Get the build number of the engine.
             * @return The build number of the engine.
             */
            UInt32 GetBuildNumber();

            /**
             * @brief Get the release state string of the engine.
             * @return The release state string of the engine.
             */
            const String& GetReleaseState();
            /**
             * @brief Get the version string of the engine.
             * @return The version string of the engine.
             */
            const String& GetVersionString();
            /**
             * @brief Get the copyright string of the engine.
             * @return The copyright string of the engine.
             */
            const String& GetCopyrightString();
        }
    }
}

#endif  // __MURL_CORE_VERSION_H__

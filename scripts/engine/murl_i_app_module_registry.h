// Copyright 2012 Spraylight GmbH

#ifndef __MURL_I_APP_MODULE_REGISTRY_H__
#define __MURL_I_APP_MODULE_REGISTRY_H__

#include "murl_audio_i_renderer_registry.h"
#include "murl_video_i_renderer_registry.h"
#include "murl_physics_i_simulator_registry.h"

namespace Murl
{
    /**
     * @ingroup MurlFactoryInterfaces
     * @interface IAppModuleRegistry
     * @brief The app module registry interface.
     */
    class IAppModuleRegistry
    {
    public:
        /**
         * @brief Get the audio renderer registry.
         * @return The audio renderer registry.
         */
        virtual Audio::IRendererRegistry* GetAudioRendererRegistry() = 0;
        /**
         * @brief Get the video renderer registry.
         * @return The video renderer registry.
         */
        virtual Video::IRendererRegistry* GetVideoRendererRegistry() = 0;
        /**
         * @brief Get the physics simulator registry.
         * @return The physics simulator registry.
         */
        virtual Physics::ISimulatorRegistry* GetPhysicsSimulatorRegistry() = 0;
        
    protected:
        virtual ~IAppModuleRegistry() {}
    };
}

#endif  // __MURL_I_APP_MODULE_REGISTRY_H__

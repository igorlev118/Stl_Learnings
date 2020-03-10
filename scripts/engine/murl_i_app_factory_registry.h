// Copyright 2012 Spraylight GmbH

#ifndef __MURL_I_APP_FACTORY_REGISTRY_H__
#define __MURL_I_APP_FACTORY_REGISTRY_H__

#include "murl_resource_i_factory.h"
#include "murl_graph_i_factory.h"
#include "murl_audio_i_factory.h"
#include "murl_video_i_factory.h"
#include "murl_physics_i_factory.h"

namespace Murl
{
    /**
     * @ingroup MurlFactoryInterfaces
     * @interface IAppFactoryRegistry
     * @brief The app factory registry interface.
     */
    class IAppFactoryRegistry
    {
    public:
        /**
         * @brief Get the resource factory registry.
         * @return The resource factory registry.
         */
        virtual Resource::IFactoryRegistry* GetResourceFactoryRegistry() = 0;
        /**
         * @brief Get the graph factory registry.
         * @return The graph factory registry.
         */
        virtual Graph::IFactoryRegistry* GetGraphFactoryRegistry() = 0;
        /**
         * @brief Get the audio factory registry.
         * @return The audio factory registry.
         */
        virtual Audio::IFactoryRegistry* GetAudioFactoryRegistry() = 0;
        /**
         * @brief Get the video factory registry.
         * @return The video factory registry.
         */
        virtual Video::IFactoryRegistry* GetVideoFactoryRegistry() = 0;
        /**
         * @brief Get the physics factory registry.
         * @return The physics factory registry.
         */
        virtual Physics::IFactoryRegistry* GetPhysicsFactoryRegistry() = 0;

        /**
         * @brief Get the resource factory.
         * @return The resource factory.
         */
        virtual const Resource::IFactory* GetResourceFactory() const = 0;
        /**
         * @brief Get the graph factory.
         * @return The graph factory.
         */
        virtual const Graph::IFactory* GetGraphFactory() const = 0;
        /**
         * @brief Get the audio factory.
         * @return The audio factory.
         */
        virtual const Audio::IFactory* GetAudioFactory() const = 0;
        /**
         * @brief Get the video factory.
         * @return The video factory.
         */
        virtual const Video::IFactory* GetVideoFactory() const = 0;
        /**
         * @brief Get the physics factory.
         * @return The physics factory.
         */
        virtual const Physics::IFactory* GetPhysicsFactory() const = 0;
        
    protected:
        virtual ~IAppFactoryRegistry() {}
    };
}

#endif  // __MURL_I_APP_FACTORY_REGISTRY_H__

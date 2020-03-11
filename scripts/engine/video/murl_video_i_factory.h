// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_FACTORY_H__
#define __MURL_VIDEO_I_FACTORY_H__

#include "murl_video_i_factory_registry.h"

namespace Murl
{
    class IAppConfiguration;

    namespace Video
    {
        class IRenderer;
    
        /**
         * @ingroup MurlVideoFactoryInterfaces
         * @interface IFactory
         * @brief The factory used to create and destroy video renderers.
         * Use the Video::IFactoryRegistry base interface for managing registered
         * renderer classes.
         */
        class IFactory : public IFactoryRegistry
        {
        public:
            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Create a default video renderer.
             * @return The newly created renderer, or null if failed.
             */
            virtual IRenderer* CreateDefaultRenderer() = 0;
            /**
             * @brief Create a video renderer from the set of registered renderers.
             * @param className The class name of the renderer to create.
             * @return The newly created renderer, or null if failed.
             */
            virtual IRenderer* CreateRenderer(const String& className) = 0;
            /**
             * @brief Create a video renderer from the set of registered renderers.
             * @param classInfo The ClassInfo structure of the renderer to create.
             * @return The newly created renderer, or null if failed.
             */
            virtual IRenderer* CreateRenderer(const IRenderer::ClassInfo& classInfo) = 0;
            /**
             * @brief Destroy a previously created video renderer.
             * @param renderer A reference to a pointer holding the renderer to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyRenderer(IRenderer*& renderer) = 0;
            
        protected:
            virtual ~IFactory() {}
        };
        
        /**
         * @ingroup MurlVideoFactoryClasses
         * @brief The StaticFactory class to create the IFactory object.
         * The StaticFactory is used by the engine's core only.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create the video factory object.
             * @param appConfig The application's configuration.
             * @return The created video factory object, or null if failed.
             */
            static IFactory* CreateFactory(const IAppConfiguration* appConfig);
            /**
             * @brief Destroy the video factory object.
             * @param factory A reference to the video factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyFactory(IFactory*& factory);
        };
    }
}

#endif  // __MURL_VIDEO_I_FACTORY_H__

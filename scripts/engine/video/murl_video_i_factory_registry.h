// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_FACTORY_REGISTRY_H__
#define __MURL_VIDEO_I_FACTORY_REGISTRY_H__

#include "murl_video_i_renderer.h"

namespace Murl
{
    namespace Video
    {
        /**
         * @ingroup MurlVideoFactoryInterfaces
         * @interface IFactoryRegistry
         * The IFactoryRegistry interface provides methods to add, remove and query different
         * video renderer classes that can be instantiated using the Video::IFactory implementing
         * this interface.
         */
        class IFactoryRegistry
        {
        public:
            /**
             * @brief Register a video renderer class.
             * @param classInfo The ClassInfo structure of the renderer to register.
             * @return true if successful.
             */
            virtual Bool RegisterRendererClass(const IRenderer::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered video renderer class.
             * @param classInfo The ClassInfo structure of the renderer to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterRendererClass(const IRenderer::ClassInfo& classInfo) = 0;
            
            /**
             * @brief Query the index of a registered video renderer class, by its ClassInfo structure.
             * @param classInfo The class info structure of the renderer class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredRendererClassInfoIndex(const IRenderer::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the index of a registered video renderer class, by its class name.
             * @param className The name of the renderer class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredRendererClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered video renderer classes.
             * @return The number of registered renderer classes.
             */
            virtual UInt32 GetNumberOfRegisteredRendererClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered video renderer class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredRendererClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const IRenderer::ClassInfo* GetRegisteredRendererClassInfo(UInt32 index) const = 0;
             
        protected:
            virtual ~IFactoryRegistry() {}
        };
    }
}

#endif  // __MURL_VIDEO_I_FACTORY_REGISTRY_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_VIDEO_SOURCE_H__
#define __MURL_GRAPH_I_VIDEO_SOURCE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IVideoStream;

    namespace Video
    {
        class ITexture;
        class IRenderer;
    }

    namespace Resource
    {
        class IVideo;
    }

    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IVideoSource
         * @brief The IVideoSource graph node interface.
         * This interface represents a node referencing a read-only Resource::IVideo object, which can
         * be played back by assigning it to one or more individual Graph::IVideoSequence nodes.
         */
        class IVideoSource
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;
            
            /**
             * @brief Get a mutable Graph::IVideoResourceTarget container.
             * This method returns a mutable pointer to a Graph::IVideoResourceTarget
             * container, which allows to add, remove or query the video resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IVideoResourceTarget container, or null if not available
             */
            virtual IVideoResourceTarget* GetVideoResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IVideoResourceTarget container.
             * This method returns a constant pointer to a Graph::IVideoResourceTarget
             * container, which allows to query the video resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IVideoResourceTarget container, or null if not available
             */
            virtual const IVideoResourceTarget* GetVideoResourceTarget() const = 0;

            /**
             * @brief Set the video node's buffer type.
             * @param type The buffer type.
             * @return true if successful.
             */
            virtual Bool SetBufferType(IEnums::BufferType type) = 0;
            /**
             * @brief Get the video node's buffer type.
             * @return The buffer type.
             */
            virtual IEnums::BufferType GetBufferType() const = 0;

            /**
             * @brief Get the duration of the video.
             * @return The video duration in seconds.
             */
            virtual Double GetDuration() const = 0;
            
            /**
             * @brief Get a video stream.
             * @return The video stream, or null if not available.
             */
            virtual IVideoStream* AcquireVideoStream() = 0;
            /**
             * @brief Release a previously acquired video stream.
             * @param stream The video stream to release
             * @return true if successful.
             */
            virtual Bool ReleaseVideoStream(IVideoStream* stream) = 0;

            /**
             * @brief Create a suitable video texture for optimal decoding.
             * A video source may provide special texture objects that are better
             * suited for optimal decoding than the standard textures created
             * via a video renderer. If no special texture is needed, this
             * method returns a null pointer, and a standard texture should be
             * created in the usual way. If this method returns a valid pointer,
             * the returned texture can be used just like a standard one, including
             * destruction via the renderer.
             * @param renderer The video renderer used for creation.
             * @return A pointer to a special texture, or null if not needed.
             */
            virtual Video::ITexture* CreateVideoTexture(Video::IRenderer* renderer) const = 0;

        protected:
            virtual ~IVideoSource() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IVideoSource nodes.
         */
        typedef IGenericNodeTarget<IVideoSource> IVideoSourceNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_VIDEO_SOURCE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_AUDIO_SOURCE_H__
#define __MURL_GRAPH_I_AUDIO_SOURCE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAudioStream;

    namespace Audio
    {
        class IBuffer;
        class IRenderer;
    }

    namespace Resource
    {
        class IAudio;
    }

    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IAudioSource
         * @brief The IAudioSource graph node interface.
         * This interface represents a node referencing a read-only Resource::IAudio object, which can
         * be played back by assigning it to one or more individual Graph::IAudioSequence nodes.
         */
        class IAudioSource
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
             * @brief Get a mutable Graph::IAudioResourceTarget container.
             * This method returns a mutable pointer to a Graph::IAudioResourceTarget
             * container, which allows to add, remove or query the audio resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IAudioResourceTarget container, or null if not available
             */
            virtual IAudioResourceTarget* GetAudioResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IAudioResourceTarget container.
             * This method returns a constant pointer to a Graph::IAudioResourceTarget
             * container, which allows to query the audio resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IAudioResourceTarget container, or null if not available
             */
            virtual const IAudioResourceTarget* GetAudioResourceTarget() const = 0;
            
            /**
             * @brief Set the audio node's buffer type.
             * @param type The buffer type.
             * @return true if successful.
             */
            virtual Bool SetBufferType(IEnums::BufferType type) = 0;
            /**
             * @brief Get the audio node's buffer type.
             * @return The buffer type.
             */
            virtual IEnums::BufferType GetBufferType() const = 0;
            
            /**
             * @brief Get the duration of the audio object.
             * @return The duration in seconds.
             */
            virtual Double GetDuration() const = 0;
            
            /**
             * @brief Get the audio node's audio stream.
             * @return The audio stream.
             */
            virtual IAudioStream* AcquireAudioStream() = 0;
            /**
             * @brief Release a previously acquired audio stream.
             * @param stream The audio stream to release
             * @return true if successful.
             */
            virtual Bool ReleaseAudioStream(IAudioStream* stream) = 0;

            /**
             * @brief Create a suitable audio buffer for optimal decoding.
             * An audio source may provide special audio buffers that are better
             * suited for optimal decoding than the standard buffers created
             * via an audio renderer. If no special buffer is needed, this
             * method returns a null pointer, and a standard buffer should be
             * created in the usual way. If this method returns a valid pointer,
             * the returned buffer can be used just like a standard one, including
             * destruction via the renderer.
             * @param renderer The audio renderer used for creation.
             * @return A pointer to a special buffer, or null if not needed.
             */
            virtual Audio::IBuffer* CreateAudioBuffer(Audio::IRenderer* renderer) const = 0;

        protected:
            virtual ~IAudioSource() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IAudioSource nodes.
         */
        typedef IGenericNodeTarget<IAudioSource> IAudioSourceNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_AUDIO_SOURCE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_AUDIO_SEQUENCE_H__
#define __MURL_GRAPH_I_AUDIO_SEQUENCE_H__

#include "murl_graph_i_playable.h"
#include "murl_graph_i_audible.h"
#include "murl_graph_i_audio_source.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IAudioSequence
         * @brief The IAudioSequence graph node interface.
         * An audio sequence represents a single instance of a playable sound object,
         * that can be positioned within the virtual world space. It can reference any
         * number of individual audio source nodes that can be seamlessly played back in
         * the order they are specified through the node's Graph::IAudioSourceNodeTarget.
         *
         * Use the interface's Graph::IPlayable base to query the total duration, and
         * set or query endless looping.
         *
         * Use the interface's Graph::IAudible base to access audio parameters like
         * volume, sample format etc.
         *
         * See Graph::IAudioSource for defining individual sound objects.
         */
        class IAudioSequence : public IPlayable, public IAudible
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
             * @brief Get the mutable Graph::ITransform interface.
             * This method returns a mutable pointer to the node's Graph::ITransform interface,
             * to be able to query or modify the node's transformation matrix and depth
             * order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's Graph::ITransform interface,
             * to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;
            
            /**
             * @brief Get the mutable Graph::IAudioSourceNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IAudioSourceNodeTarget
             * container, which allows to add, remove or query the audio sequence's
             * referenced audio objects.
             * @return The mutable Graph::IAudioSourceNodeTarget container, or null if not available
             */
            virtual IAudioSourceNodeTarget* GetAudioSourceNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IAudioSourceNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IAudioSourceNodeTarget
             * container, which allows to query the audio sequence's referenced audio
             * objects.
             * @return The constant Graph::IAudioSourceNodeTarget container, or null if not available
             */
            virtual const IAudioSourceNodeTarget* GetAudioSourceNodeTarget() const = 0;

            /**
             * @brief Set the timeline unit to respond to.
             * @param unit The timeline unit in the range from 0 to IEnums::NUM_TIMELINE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool SetTimelineUnit(UInt32 unit) = 0;
            /**
             * @brief Get the timeline unit responding to.
             * @return The timeline unit in the range from 0 to IEnums::NUM_TIMELINE_UNITS-1.
             */
            virtual UInt32 GetTimelineUnit() const = 0;

        protected:
            virtual ~IAudioSequence() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IAudioSequence nodes.
         */
        typedef IGenericNodeTarget<IAudioSequence> IAudioSequenceNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_AUDIO_SEQUENCE_H__

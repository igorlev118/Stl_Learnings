// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CLIP_SEQUENCER_H__
#define __MURL_GRAPH_I_CLIP_SEQUENCER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_clip.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IClipSequencer
         * @brief The IClipSequencer graph node interface.
         * A clip sequencer is similar to a state machine, in that it manages a set of individual
         * Graph::IClip child nodes (states) and transitions between them (Graph::IClipTransition).
         * Both types of nodes must be defined as direct children of the sequencer. In addition,
         * a start clip must be defined, which is active when the sequencer is initialized (see
         * GetStartClipNodeTarget()).
         *
         * Unlike a "traditional" state machine, a clip sequencer allows more than one "state"
         * (i.e. clip) to be active at the same time, in order to smoothly blend between them
         * to create smooth animations. For this reason, the Graph::IClipTransition interface
         * provides methods to set in and out transition durations and offsets.
         *
         * See Graph::IClip and Graph::IClipTransition for details.
         */
        class IClipSequencer
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
             * @brief Get the mutable Graph::IClipNodeTarget container storing the start clip.
             * This method returns a mutable pointer to the node's Graph::IClipNodeTarget
             * container, which allows to set or query the sequencer's start clip.
             * @return The mutable Graph::IClipNodeTarget container.
             */
            virtual IClipNodeTarget* GetStartClipNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IClipNodeTarget container storing the start clip.
             * This method returns a constant pointer to the node's Graph::IClipNodeTarget
             * container, which allows to query the sequencer's start clip.
             * @return The constant Graph::IClipNodeTarget container.
             */
            virtual const IClipNodeTarget* GetStartClipNodeTarget() const = 0;

            /**
             * @brief Get the currently active clip
             * @return A pointer to a mutable clip, or null if none is active.
             */
            virtual IClip* GetCurrentClip() = 0;
            /**
             * @brief Get the currently active clip
             * @return A pointer to a constant clip, or null if none is active.
             */
            virtual const IClip* GetCurrentClip() const = 0;

            /**
             * @brief Reset the sequencer to its initial state.
             * @return true if successful.
             */
            virtual Bool Reset() = 0;

        protected:
            virtual ~IClipSequencer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IClipSequencer nodes.
         */
        typedef IGenericNodeTarget<IClipSequencer> IClipSequencerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CLIP_SEQUENCER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_VIDEO_SEQUENCE_H__
#define __MURL_GRAPH_I_VIDEO_SEQUENCE_H__

#include "murl_graph_i_playable.h"
#include "murl_graph_i_visible.h"
#include "murl_graph_i_video_source.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IVideoSequence
         * @brief The IVideoSequence graph node interface.
         * A video sequence represents a single instance of a playable video object.
         * It can reference any number of individual video source nodes that can be seamlessly 
         * played back in the order they are specified through the node's 
         * Graph::IVideoSourceNodeTarget.
         *
         * Use the interface's Graph::IPlayable base to query the total duration, and
         * set or query endless looping.
         *
         * Use the interface's Graph::IVisible base to access the used pixel format.
         *
         * See Graph::IVideoSource for defining individual video objects.
         */
        class IVideoSequence : public IPlayable, public IVisible
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
             * @brief Get the mutable Graph::IVideoSourceNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IVideoSourceNodeTarget
             * container, which allows to add, remove or query the video sequence's
             * referenced sound objects.
             * @return The mutable Graph::IVideoSourceNodeTarget container, or null if not available
             */
            virtual IVideoSourceNodeTarget* GetVideoSourceNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IVideoSourceNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IVideoSourceNodeTarget
             * container, which allows to query the video sequence's referenced sound
             * objects.
             * @return The constant Graph::IVideoSourceNodeTarget container, or null if not available
             */
            virtual const IVideoSourceNodeTarget* GetVideoSourceNodeTarget() const = 0;
            
        protected:
            virtual ~IVideoSequence() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IVideoSequence nodes.
         */
        typedef IGenericNodeTarget<IVideoSequence> IVideoSequenceNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_VIDEO_SEQUENCE_H__

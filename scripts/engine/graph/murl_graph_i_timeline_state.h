// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TIMELINE_STATE_H__
#define __MURL_GRAPH_I_TIMELINE_STATE_H__

#include "murl_graph_i_timeline.h"
#include "murl_graph_i_state_unit.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITimelineState
         * @brief The ITimelineState graph node interface.
         * Timeline state nodes are used to activate and/or quickly switch between timelines
         * during scene graph traversal. As soon as a specific timeline is activated via a
         * timeline state node, it stays active during traversal until a different timeline
         * state node is encountered.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during 
         * scene graph traversal.\n
         * See Graph::ITimeline for defining a specific timeline.\n
         */
        class ITimelineState : public IStateUnit
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
             * @brief Get the mutable Graph::ITimelineNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ITimelineNodeTarget
             * container, which allows to set or query the timeline this state node refers to.
             * @return The mutable Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual ITimelineNodeTarget* GetTimelineNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITimelineNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ITimelineNodeTarget
             * container, which allows to query the timeline this state node refers to.
             * @return The mutable Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual const ITimelineNodeTarget* GetTimelineNodeTarget() const = 0;
            
        protected:
            virtual ~ITimelineState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITimelineState nodes.
         */
        typedef IGenericNodeTarget<ITimelineState> ITimelineStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TIMELINE_STATE_H__

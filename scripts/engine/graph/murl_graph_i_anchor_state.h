// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ANCHOR_STATE_H__
#define __MURL_GRAPH_I_ANCHOR_STATE_H__

#include "murl_graph_i_anchor.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IAnchorState
         * @brief The IAnchorState graph node interface.
         * Anchor state nodes are used to activate and/or quickly switch between anchors
         * during scene graph traversal. As soon as a specific anchor is activated via a
         * anchor state node, it stays active during traversal until a different anchor
         * state node is encountered.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene
         * graph traversal.\n
         * See Graph::IAnchor for defining a specific anchor for rendering.
         */
        class IAnchorState : public IStateSlot
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
             * @brief Get the mutable Graph::IAnchorNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IAnchorNodeTarget
             * container, which allows to set or query the anchor this state node refers to.
             * @return The mutable Graph::IAnchorNodeTarget container, or null if not available.
             */
            virtual IAnchorNodeTarget* GetAnchorNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IAnchorNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IAnchorNodeTarget
             * container, which allows to query the anchor this state node refers to.
             * @return The mutable Graph::IAnchorNodeTarget container, or null if not available.
             */
            virtual const IAnchorNodeTarget* GetAnchorNodeTarget() const = 0;
            
        protected:
            virtual ~IAnchorState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IAnchorState nodes.
         */
        typedef IGenericNodeTarget<IAnchorState> IAnchorStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_ANCHOR_STATE_H__

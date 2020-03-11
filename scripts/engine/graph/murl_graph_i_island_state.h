// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ISLAND_STATE_H__
#define __MURL_GRAPH_I_ISLAND_STATE_H__

#include "murl_graph_i_island.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IIslandState
         * @brief The IIslandState graph node interface.
         * Island state nodes are used to activate and/or quickly switch between physics
         * simulation islands (Graph::IIsland) during scene graph traversal. As soon as a
         * specific island is activated at a given slot via an island state node, it stays
         * active during traversal until a different island state node using the same slot
         * is encountered.
         *
         * Use the base interface's IStateSlot::SetSlot() method to set the actual slot index
         * the referenced islandf should be attached to.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene
         * graph traversal.\n
         * See Graph::IIsland for defining a specific physics island.\n
         */
        class IIslandState : public IStateSlot
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
             * @brief Get the mutable Graph::IIslandNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IIslandNodeTarget
             * container, which allows to set or query the island this state node refers to.
             * @return The mutable Graph::IIslandNodeTarget container, or null if not available.
             */
            virtual IIslandNodeTarget* GetIslandNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IIslandNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IIslandNodeTarget
             * container, which allows to query the island this state node refers to.
             * @return The mutable Graph::IIslandNodeTarget container, or null if not available.
             */
            virtual const IIslandNodeTarget* GetIslandNodeTarget() const = 0;
            
        protected:
            virtual ~IIslandState() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IIslandState nodes.
         */
        typedef IGenericNodeTarget<IIslandState> IIslandStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_ISLAND_STATE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ISLAND_H__
#define __MURL_GRAPH_I_ISLAND_H__

#include "murl_graph_i_body.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Physics
    {
        class IIsland;
    }

    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IIsland
         * @brief The IIsland graph node interface.
         * Island nodes represent a closed group of physics simulator objects (such as bodies,
         * joints, springs, etc.) that are supposed to interact with each other. Individual
         * islands are separate from each other, i.e. no physics object from one island can
         * interact with any object from another island.
         * All objects belonging to a single island must be within the sub-graph of that island.
         * If no island is defined, the default global island is used.
         */
        class IIsland : public IStateSlot
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
             * @brief Get the island's internal physics simulator object.
             * @return A pointer to the mutable physics simulator object.
             */
            virtual Physics::IIsland* GetPhysicsIslandObject() const = 0;

        protected:
            virtual ~IIsland() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IIsland nodes.
         */
        typedef IGenericNodeTarget<IIsland> IIslandNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_ISLAND_H__

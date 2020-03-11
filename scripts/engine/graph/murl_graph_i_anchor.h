// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ANCHOR_H__
#define __MURL_GRAPH_I_ANCHOR_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IAnchor
         * @brief The IAnchor graph node interface.
         * Anchor nodes may be used to temporarily "store" the current world transform and depth
         * order during logic traversal, to be later retrieved by e.g. a node that implements the
         * Graph::ICloneTransform interface.
         *
         * See Graph::ICloneTransform for accessing the anchor's transform.
         */
        class IAnchor
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
             * @brief Get the world transform stored during logic traversal.
             * This returns a constant reference to the world transform calculated and stored
             * during the most recent logic traversal. The returned transform is only valid
             * until the next logic tick.
             * @return The most recent world transform.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            /**
             * @brief Get the world position stored during logic traversal.
             * This returns a constant reference to the world positon calculated and stored
             * during the most recent logic traversal. The returned position is only valid
             * until the next logic tick.
             * @return The most recent world position.
             */
            virtual const Vector& GetWorldPosition() const = 0;
            /**
             * @brief Get the world depth order stored during logic traversal.
             * This returns the absolute depth order calculated and stored during the most
             * recent logic traversal. The returned value is only valid until the next logic
             * tick.
             * @return The most recent absolute depth order.
             */
            virtual SInt32 GetWorldDepthOrder() const = 0;

        protected:
            virtual ~IAnchor() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IAnchor nodes.
         */
        typedef IGenericNodeTarget<IAnchor> IAnchorNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_ANCHOR_H__

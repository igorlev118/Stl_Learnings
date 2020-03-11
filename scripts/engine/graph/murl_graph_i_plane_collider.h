// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PLANE_COLLIDER_H__
#define __MURL_GRAPH_I_PLANE_COLLIDER_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        class ICollider;
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IPlaneCollider
         * @brief The IPlaneCollider graph node interface.
         * This interface represents a Graph::ICollider in the shape of an infinite plane,
         * lying in the XZ plane at Y=0, with its positive face towards the +Y axis.
         */
        class IPlaneCollider
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
             * @brief Get the mutable Graph::ICollider interface.
             * This method returns a mutable pointer to the node's Graph::ICollider interface,
             * to be able to query or modify common collider-related properties.
             * @return The mutable Graph::ICollider interface
             */
            virtual ICollider* GetColliderInterface() = 0;
            /**
             * @brief Get the constant Graph::ICollider interface.
             * This method returns a constant pointer to the node's Graph::ICollider interface,
             * to be able to query common collider-related properties.
             * @return The constant Graph::ICollider interface
             */
            virtual const ICollider* GetColliderInterface() const = 0;

        protected:
            virtual ~IPlaneCollider() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IPlaneCollider nodes.
         */
        typedef IGenericNodeTarget<IPlaneCollider> IPlaneColliderNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_PLANE_COLLIDER_H__

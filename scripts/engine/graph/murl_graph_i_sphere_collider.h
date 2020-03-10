// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SPHERE_COLLIDER_H__
#define __MURL_GRAPH_I_SPHERE_COLLIDER_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        class ICollider;
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISphereCollider
         * @brief The ISphereCollider graph node interface.
         * This interface represents a Graph::ICollider in the shape of a sphere, with a default
         * radius of 1.0 and a default center at the origin (0/0/0).
         */
        class ISphereCollider
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

            /**
             * @brief Set the sphere's radius.
             * @param radius The radius.
             * @return true if successful.
             */
            virtual Bool SetRadius(Real radius) = 0;
            /**
             * @brief Get the sphere's radius.
             * @return The radius.
             */
            virtual Real GetRadius() const = 0;
            
        protected:
            virtual ~ISphereCollider() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISphereCollider nodes.
         */
        typedef IGenericNodeTarget<ISphereCollider> ISphereColliderNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SPHERE_COLLIDER_H__

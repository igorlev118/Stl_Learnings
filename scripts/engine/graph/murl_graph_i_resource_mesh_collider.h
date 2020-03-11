// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_RESOURCE_MESH_COLLIDER_H__
#define __MURL_GRAPH_I_RESOURCE_MESH_COLLIDER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"

namespace Murl
{
    namespace Graph
    {
        class ICollider;
        class INode;
        class ITransform;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IResourceMeshCollider
         * @brief The IResourceMeshCollider graph node interface.
         * This interface represents a Graph::ICollider with an arbitrary collision shape,
         * which is obtained from a given Resource::IMesh object.
         *
         * Initialization will fail if the referenced Resource::IMesh object does not contain
         * appropriate collision information; it is necessary to include such information already
         * at the time of converting the mesh object. Similar to the Graph::IResourceMeshCuller
         * interface, this interface does not explicitly require a specific type of structural
         * information to be present in the mesh; a specialized Graph::ResourceMeshCollider
         * on the other hand demands the presence of a bounding volume tree.
         *
         * See also Graph::IResourceMeshCuller.
         */
        class IResourceMeshCollider
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
             * @brief Get a mutable Graph::IMeshResourceTarget container.
             * This method returns a mutable pointer to a Graph::IMeshResourceTarget
             * container, which allows to add, remove or query the mesh resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IMeshResourceTarget container, or null if not available
             */
            virtual IMeshResourceTarget* GetMeshResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IMeshResourceTarget container.
             * This method returns a constant pointer to a Graph::IMeshResourceTarget
             * container, which allows to query the mesh resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IMeshResourceTarget container, or null if not available
             */
            virtual const IMeshResourceTarget* GetMeshResourceTarget() const = 0;
            
        protected:
            virtual ~IResourceMeshCollider() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IResourceMeshCollider nodes.
         */
        typedef IGenericNodeTarget<IResourceMeshCollider> IResourceMeshColliderNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_RESOURCE_MESH_COLLIDER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_RESOURCE_MESH_CULLER_H__
#define __MURL_GRAPH_I_RESOURCE_MESH_CULLER_H__

#include "murl_graph_i_generic_resource_target.h"
#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Resource
    {
        class IMesh;
    }
    
    namespace Graph
    {
        class ICuller;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IResourceMeshCuller
         * @brief The IResourceMeshCuller graph node interface.
         * This interface represents a specialized Graph::ICuller node that takes additional
         * information about the scene to be rendered; here, the necessary information must be
         * present in a given Resource::IMesh object.
         *
         * Resource::IMesh objects can contain different types of structural information, like
         * a tree of bounding volumes or a BSP tree. This interface does not explicitly require
         * a specific type; however, e.g. a Graph::ResourceBspCuller demands the presence of a
         * BSP tree for culling.
         *
         * See also Graph::IResourceMeshCollider.
         */
        class IResourceMeshCuller
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
             * @brief Get the mutable Graph::ICuller interface.
             * This method returns a mutable pointer to the node's Graph::ICuller interface,
             * to be able to query or modify the node's basic culler properties.
             * @return The mutable Graph::ICuller interface, or null if not available
             */
            virtual ICuller* GetCullerInterface() = 0;
            /**
             * @brief Get the constant Graph::ICuller interface.
             * This method returns a mutable pointer to the node's Graph::ICuller interface,
             * to be able to query the node's basic culler properties.
             * @return The constant Graph::ICuller interface, or null if not available
             */
            virtual const ICuller* GetCullerInterface() const = 0;

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
            virtual ~IResourceMeshCuller() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IResourceMeshCuller nodes.
         */
        typedef IGenericNodeTarget<IResourceMeshCuller> IResourceMeshCullerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_RESOURCE_MESH_CULLER_H__

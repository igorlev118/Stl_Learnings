// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_RESOURCE_MESH_GEOMETRY_H__
#define __MURL_GRAPH_I_RESOURCE_MESH_GEOMETRY_H__

#include "murl_graph_i_generic_resource_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_blendable.h"

namespace Murl
{
    namespace Resource
    {
        class IMesh;
    }
    
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IResourceMeshGeometry
         * @brief The IResourceMeshGeometry graph node interface.
         * This interface represents a renderable object that references a given read-only
         * Resource::IMesh object containing vertex and index data for one or more individual
         * sub-meshes.
         */
        class IResourceMeshGeometry : public IDrawable, public IBlendable
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
            virtual ~IResourceMeshGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IResourceMeshGeometry nodes.
         */
        typedef IGenericNodeTarget<IResourceMeshGeometry> IResourceMeshGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_RESOURCE_MESH_GEOMETRY_H__

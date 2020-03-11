// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_GENERIC_GEOMETRY_H__
#define __MURL_GRAPH_I_GENERIC_GEOMETRY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_index_buffer.h"
#include "murl_graph_i_vertex_buffer.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IGenericGeometry
         * @brief The IGenericGeometry graph node interface.
         * This interface represents a generic geometry object for rendering, composed
         * of a vertex buffer holding individual vertices with different attributes,
         * and an index buffer holding a sequence of indices into that vertex buffer.
         *
         * Use the Graph::IVertexBuffer and Graph::IIndexBuffer base interfaces to access
         * the underlying vertex and index data, respectively.
         */
        class IGenericGeometry : public IDrawable, public IIndexBuffer, public IVertexBuffer
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
             * @brief Set the bounding box used for culling and aligning.
             * @param boundingBox The bounding box.
             * @return true if successful.
             */
            virtual Bool SetBoundingBox(const Box& boundingBox) = 0;
            /**
             * @brief Get the bounding box used for culling and aligning.
             * @return The bounding box.
             */
            virtual const Box& GetBoundingBox() const = 0;
            
        protected:
            virtual ~IGenericGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IGenericGeometry nodes.
         */
        typedef IGenericNodeTarget<IGenericGeometry> IGenericGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_GENERIC_GEOMETRY_H__

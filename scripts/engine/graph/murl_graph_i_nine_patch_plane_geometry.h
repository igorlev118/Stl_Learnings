// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_NINE_PATCH_PLANE_GEOMETRY_H__
#define __MURL_GRAPH_I_NINE_PATCH_PLANE_GEOMETRY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_nine_patch.h"
#include "murl_graph_i_scalable.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        class IPlaneGeometry;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface INinePatchPlaneGeometry
         * @brief The INinePatchPlaneGeometry graph node interface.
         * This interface represents a plane geometry node implementing the
         * Graph::INinePatch property interface for dividing the resulting plane
         * into 9 segments.
         *
         * See the Graph::IPlaneGeometry interface for common plane properties.
         * See the Graph::INinePatch interface for details on nine patch objects.
         */
        class INinePatchPlaneGeometry : public INinePatch
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
             * @brief Get the mutable Graph::IPlaneGeometry interface.
             * This method returns a mutable pointer to the node's Graph::IPlaneGeometry interface,
             * to be able to query or modify the node's basic plane properties.
             * @return The mutable Graph::IPlaneGeometry interface, or null if not available
             */
            virtual IPlaneGeometry* GetPlaneGeometryInterface() = 0;
            /**
             * @brief Get the constant Graph::IPlaneGeometry interface.
             * This method returns a constant pointer to the node's Graph::IPlaneGeometry interface,
             * to be able to query the node's basic plane properties.
             * @return The constant Graph::IPlaneGeometry interface, or null if not available
             */
            virtual const IPlaneGeometry* GetPlaneGeometryInterface() const = 0;

        protected:
            virtual ~INinePatchPlaneGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::INinePatchPlaneGeometry nodes.
         */
        typedef IGenericNodeTarget<INinePatchPlaneGeometry> INinePatchPlaneGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_NINE_PATCH_PLANE_GEOMETRY_H__

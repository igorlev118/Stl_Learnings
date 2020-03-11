// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_NINE_PATCH_PLANE_SEQUENCE_GEOMETRY_H__
#define __MURL_GRAPH_I_NINE_PATCH_PLANE_SEQUENCE_GEOMETRY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_nine_patch.h"
#include "murl_graph_i_scalable.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        class IPlaneSequenceGeometry;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface INinePatchPlaneSequenceGeometry
         * @brief The INinePatchPlaneSequenceGeometry graph node interface.
         * This interface represents a plane sequence geometry node sourcing its
         * texture coordinates from a given Resource::IAtlas, additionally implementing
         * the Graph::INinePatch property interface for dividing the resulting plane
         * into 9 segments.
         *
         * See the Graph::IPlaneSequenceGeometry interface for common plane properties.
         * See the Graph::INinePatch interface for details on nine patch objects.
         */
        class INinePatchPlaneSequenceGeometry : public INinePatch
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
             * @brief Get the mutable Graph::IPlaneSequenceGeometry interface.
             * This method returns a mutable pointer to the node's Graph::IPlaneSequenceGeometry interface,
             * to be able to query or modify the node's basic plane properties.
             * @return The mutable Graph::IPlaneSequenceGeometry interface, or null if not available
             */
            virtual IPlaneSequenceGeometry* GetPlaneSequenceGeometryInterface() = 0;
            /**
             * @brief Get the constant Graph::IPlaneSequenceGeometry interface.
             * This method returns a constant pointer to the node's Graph::IPlaneSequenceGeometry interface,
             * to be able to query the node's basic plane properties.
             * @return The constant Graph::IPlaneSequenceGeometry interface, or null if not available
             */
            virtual const IPlaneSequenceGeometry* GetPlaneSequenceGeometryInterface() const = 0;

            /**
             * @brief Set the size of the display rectangle.
             * @param sizeX The rectangle width.
             * @param sizeY The rectangle height.
             * @return true if successful.
             */
            virtual Bool SetFrameSize(Real sizeX, Real sizeY) = 0;
            /**
             * @brief Set the width of the display rectangle.
             * @param sizeX The rectangle width.
             * @return true if successful.
             */
            virtual Bool SetFrameSizeX(Real sizeX) = 0;
            /**
             * @brief Set the height of the display rectangle.
             * @param sizeY The rectangle height.
             * @return true if successful.
             */
            virtual Bool SetFrameSizeY(Real sizeY) = 0;

        protected:
            virtual ~INinePatchPlaneSequenceGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::INinePatchPlaneSequenceGeometry nodes.
         */
        typedef IGenericNodeTarget<INinePatchPlaneSequenceGeometry> INinePatchPlaneSequenceGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_NINE_PATCH_PLANE_SEQUENCE_GEOMETRY_H__

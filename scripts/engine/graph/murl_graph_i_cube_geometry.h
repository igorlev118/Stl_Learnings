// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CUBE_GEOMETRY_H__
#define __MURL_GRAPH_I_CUBE_GEOMETRY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_scalable.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ICubeGeometry
         * @brief The ICubeGeometry graph node interface.
         * This interface represents a simple geometry that represents a centered unit cube.
         *
         * Use the Graph::IScalable base interface methods to set or query the actual
         * size of the cube via its scale factor.
         */
        class ICubeGeometry : public IDrawable, public IScalable
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
            
        protected:
            virtual ~ICubeGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICubeGeometry nodes.
         */
        typedef IGenericNodeTarget<ICubeGeometry> ICubeGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CUBE_GEOMETRY_H__

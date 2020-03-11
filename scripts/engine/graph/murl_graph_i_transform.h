// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TRANSFORM_H__
#define __MURL_GRAPH_I_TRANSFORM_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_transformable.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITransform
         * @brief The ITransform graph node interface.
         * This interface represents a node implementing the Graph::ITransformable interface,
         * for the purpose of creating a transform hierarchy in the scene graph.
         *
         * See the Graph::ITransformable base interface for details.
         */
        class ITransform : public ITransformable
        {
        public:
            /**
             * @brief Get the mutable INode interface.
             * This method returns a mutable pointer to the node's INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant INode interface.
             * This method returns a constant pointer to the node's INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;
            
        protected:
            virtual ~ITransform() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITransform nodes.
         */
        typedef IGenericNodeTarget<ITransform> ITransformNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TRANSFORM_H__

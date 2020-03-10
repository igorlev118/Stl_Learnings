// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SCALE_H__
#define __MURL_GRAPH_I_SCALE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_scalable.h"

namespace Murl
{
    namespace Graph
    {
        class INode;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IScale
         * @brief The IScale graph node interface.
         * This interface represents a node implementing the Graph::IScalable interface,
         * for the purpose to add an explicit scaling factor to a transform hierarchy made up
         * from e.g. Graph::ITransform nodes.
         *
         * Although scaling is a basic operation on a transformation matrix, this should not be
         * done directly through the Graph::ITransformable interface. Instead, individual
         * IScale nodes should be used, which (in addition to the regular scaling operation)
         * explicitly calculate a global scale factor from the transform hierarchy to quickly
         * determine e.g. the radius of a bounding sphere.
         */
        class IScale : public IScalable
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
             * @brief Enable/disable scale inversion.
             * If set to true, the actual scaling factors used during traversal are the
             * reciprocals of the given values. However, calls made to the IScalable
             * getter methods always return the non-inverted values.
             * @param inverted If true, scaling is inverted.
             * @return true if successful.
             */
            virtual Bool SetInverted(Bool inverted) = 0;
            /**
             * @brief Check if scale inversion is enabled.
             * @return true if enabled.
             */
            virtual Bool IsInverted() const = 0;

        protected:
            virtual ~IScale() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IScale nodes.
         */
        typedef IGenericNodeTarget<IScale> IScaleNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SCALE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_REFERENCE_H__
#define __MURL_GRAPH_I_REFERENCE_H__

#include "murl_graph_i_node.h"

namespace Murl
{
    namespace Graph
    {
        class IScale;
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IReference
         * @brief The IReference graph node interface.
         * Reference nodes can be used to directly reference to any other (previously defined)
         * node in the scene graph, without actually duplicating that node and its children
         * (in contrast to Graph::IInstance nodes, which actually create new sub-graphs).
         *
         * Scene graph traversal is carried out on the referenced node and its children as if
         * they were regular children of this node. In other words, multiple traversals may be
         * carried out on the same node more than once per tick and/or frame, depending on its
         * active and/or visible state, respectively. If some animated node is referenced,
         * all references to this node reflect the same animation state during that frame.
         * It is not possible to e.g. reference a single animated Graph::IPlaneSequenceGeometry
         * multiple times and show different animation frames: all references are in sync
         * regarding animation state. In such a case, e.g. a Graph::IInstance must be used
         * instead, to create distinct animated objects.
         *
         * The interface exposes two GetTransformInterface() methods that can be used to
         * access a node's optionally present Graph::ITransform interface, which allows to
         * define an additional transform applied to the referenced node. Note, that simple
         * references need not implement this interface and return null on both methods.
         */
        class IReference
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
             * This method returns a mutable pointer to the node's optional Graph::ITransform
             * interface, to be able to query or modify the node's transformation matrix and
             * depth order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's optional Graph::ITransform
             * interface, to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;

            /**
             * @brief Get the mutable Graph::IScale interface.
             * This method returns a mutable pointer to the node's optional Graph::IScale
             * interface, to be able to query or modify the node's scale factor.
             * @return The mutable Graph::IScale interface, or null if not available
             */
            virtual IScale* GetScaleInterface() = 0;
            /**
             * @brief Get the constant Graph::IScale interface.
             * This method returns a constant pointer to the node's optional Graph::IScale
             * interface, to be able to query the node's scale factor.
             * @return The constant Graph::IScale interface, or null if not available
             */
            virtual const IScale* GetScaleInterface() const = 0;

            /**
             * @brief Get the mutable Graph::INodeTarget container.
             * This method returns a mutable pointer to the node's Graph::INodeTarget
             * container, which allows to set or query the referenced node.
             * @return The mutable Graph::INodeTarget container, or null if not available.
             */
            virtual INodeTarget* GetNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::INodeTarget container.
             * This method returns a constant pointer to the node's Graph::INodeTarget
             * container, which allows to query the referenced node.
             * @return The mutable Graph::INodeTarget container, or null if not available.
             */
            virtual const INodeTarget* GetNodeTarget() const = 0;
            
        protected:
            virtual ~IReference() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IReference nodes.
         */
        typedef IGenericNodeTarget<IReference> IReferenceNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_REFERENCE_H__

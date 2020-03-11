// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_GRAPH_NODE_H__
#define __MURL_RESOURCE_I_GRAPH_NODE_H__

#include "murl_i_attributes.h"

namespace Murl
{
    namespace Resource
    {
        class IGraph;

        /**
         * @ingroup MurlResourceMiscInterfaces
         * @interface IGraphNode
         * @brief The IGraphNode resource interface.
         * This interface represents a single node contained in a Resource::IGraph object.
         */
        class IGraphNode
        {
        public:
            /**
             * @brief Get the class name of the node to create.
             * @return The class name.
             */
            virtual String GetName() const = 0;

            /**
             * @brief Get the node's number of children.
             * @return The number of children.
             */
            virtual UInt32 GetNumberOfChildren() const = 0;
            /**
             * @brief Get the node's child at a given index.
             * @param index The child index, in the range from 0 to GetNumberOfChildren()-1.
             * @return The child node, or null if index is out of range.
             */
            virtual const IGraphNode* GetChild(UInt32 index) const = 0;

            /**
             * @brief Get the optional node attributes.
             * @return A pointer to the attributes object, or null if not present.
             */
            virtual const IAttributes* GetAttributes() const = 0;

            /**
             * @brief Get the graph resource owning this node.
             * @return A pointer to the graph object, or null if not present.
             */
            virtual const IGraph* GetOwner() const = 0;

        protected:
            virtual ~IGraphNode() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_GRAPH_NODE_H__

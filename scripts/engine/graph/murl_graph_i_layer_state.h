// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LAYER_STATE_H__
#define __MURL_GRAPH_I_LAYER_STATE_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ILayerState
         * @brief The ILayerState graph node interface.
         * To allow finer control over the order in which geometry is rendered within an
         * active Graph::ICamera, it is possible to select an individual render layer by
         * using a Graph::ILayerState node with a given index. Layers with lower indices
         * (default 0) are rendered first, i.e. their objects will be overdrawn by objects
         * contained in layers with higher indices.
         *
         * In any case, if one layer contains both solid and (semi-)transparent objects,
         * the solid ones are always rendered before the transparent ones. If this order
         * is to be reversed, all solid objects must be put to a layer with an index higher
         * than the current one.
         */
        class ILayerState
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
             * @brief Set the current layer index.
             * @param layerIndex The current layer index to set.
             * @return true if successful.
             */
            virtual Bool SetLayerIndex(UInt32 layerIndex) = 0;
            /**
             * @brief Get the current layer index.
             * @return The current layer index.
             */
            virtual UInt32 GetLayerIndex() const = 0;
            
        protected:
            virtual ~ILayerState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ILayerState nodes.
         */
        typedef IGenericNodeTarget<ILayerState> ILayerStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_LAYER_STATE_H__

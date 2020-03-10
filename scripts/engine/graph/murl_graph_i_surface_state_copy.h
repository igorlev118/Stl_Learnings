// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SURFACE_STATE_COPY_H__
#define __MURL_GRAPH_I_SURFACE_STATE_COPY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISurfaceStateCopy
         * @brief The ISurfaceStateCopy graph node interface.
         * Nodes implementing this interface provide a means to copy the current surface
         * state assignment (performed via an ISurfaceState node) at a given source slot
         * to a given destination slot.
         *
         * See Graph::ISurfaceState for additional details.
         */
        class ISurfaceStateCopy : public IStateSlot
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
             * @brief Set the source slot to copy the state assignment from.
             * @param slot The source slot, from 0 to IEnums::NUM_SURFACE_SLOTS-1.
             * @return true if successful.
             */
            virtual Bool SetSourceSlot(SInt32 slot) = 0;
            /**
             * @brief Get the source slot to copy the state assignment from.
             * @return The source slot, from 0 to IEnums::NUM_SURFACE_SLOTS-1.
             */
            virtual SInt32 GetSourceSlot() const = 0;

        protected:
            virtual ~ISurfaceStateCopy() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISurfaceStateCopy nodes.
         */
        typedef IGenericNodeTarget<ISurfaceStateCopy> ISurfaceStateCopyNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SURFACE_STATE_COPY_H__

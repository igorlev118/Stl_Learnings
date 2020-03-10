// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CULLER_STATE_COPY_H__
#define __MURL_GRAPH_I_CULLER_STATE_COPY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ICullerStateCopy
         * @brief The ICullerStateCopy graph node interface.
         * Nodes implementing this interface provide a means to copy the current culler
         * state assignment (performed via an ICullerState node) at a given source slot
         * to a given destination slot.
         *
         * See Graph::ICullerState for additional details.
         */
        class ICullerStateCopy : public IStateSlot
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
             * Valid slot value ranges depend on the actual node, e.g. 
             * IEnums::NUM_VIDEO_CULLER_SLOTS-1 or IEnums::NUM_AUDIO_CULLER_SLOTS-1.
             * @param slot The source slot.
             * @return true if successful.
             */
            virtual Bool SetSourceSlot(SInt32 slot) = 0;
            /**
             * @brief Get the source slot to copy the state assignment from.
             * @return The source slot.
             */
            virtual SInt32 GetSourceSlot() const = 0;

        protected:
            virtual ~ICullerStateCopy() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICullerStateCopy nodes.
         */
        typedef IGenericNodeTarget<ICullerStateCopy> ICullerStateCopyNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CULLER_STATE_COPY_H__

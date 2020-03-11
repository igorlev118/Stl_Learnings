// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_STATE_SLOT_H__
#define __MURL_GRAPH_I_STATE_SLOT_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IStateSlot
         * @brief The IStateSlot property interface.
         * This interface provides a common way to select a generic "slot" in
         * which an object is used. One application of this mechanism is found
         * in the Graph::IProcessOutputTracker interface, where e.g. different
         * video rendering entities like textures, materials etc. are assigned
         * to specific slots during scene graph traversal, using state nodes
         * like Graph::ITextureState or Graph::IMaterialState, respectively.
         * In this case, these slots serve as a connection for rendering geometry
         * with dynamically assigned properties. See also Graph::IStateUnit.
         */
        class IStateSlot
        {
        public:
            /**
             * @brief Set the slot index to use.
             * @param slot The slot index.
             * @return true if successful.
             */
            virtual Bool SetSlot(SInt32 slot) = 0;
            /**
             * @brief Get the slot index to use.
             * @return The slot index.
             */
            virtual SInt32 GetSlot() const = 0;
            
        protected:
            virtual ~IStateSlot() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IStateSlot nodes.
         */
        typedef IGenericNodeTarget<IStateSlot> IStateSlotNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_STATE_SLOT_H__

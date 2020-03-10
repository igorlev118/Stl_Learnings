// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_STATE_UNIT_H__
#define __MURL_GRAPH_I_STATE_UNIT_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IStateUnit
         * @brief The IStateUnit property interface.
         * This interface provides a common way to select a generic "unit" for
         * which an object is used. One application of this mechanism is found
         * in the Graph::IProcessOutputTracker interface, where e.g. different
         * video rendering entities like textures, light groups etc. are assigned
         * to one available unit (e.g. 8 parallel texture units in the GPU),
         * using state nodes like Graph::ITextureState or Graph::ILightState,
         * respectively. See also Graph::IStateSlot.
         */
        class IStateUnit
        {
        public:
            /**
             * @brief Set the unit index to use.
             * @param unit The unit index.
             * @return true if successful.
             */
            virtual Bool SetUnit(UInt32 unit) = 0;
            /**
             * @brief Get the unit index to use.
             * @return The unit index.
             */
            virtual UInt32 GetUnit() const = 0;
            
        protected:
            virtual ~IStateUnit() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IStateUnit nodes.
         */
        typedef IGenericNodeTarget<IStateUnit> IStateUnitNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_STATE_UNIT_H__

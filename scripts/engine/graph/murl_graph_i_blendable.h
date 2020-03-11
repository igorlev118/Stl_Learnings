// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BLENDABLE_H__
#define __MURL_GRAPH_I_BLENDABLE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    class Color;

    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IBlendable
         * @brief The IBlendable property interface.
         * This interface provides a generic way to specify individual blend factors.
         *
         * Animation controllers may call the SetBlendFactor() method when blend factor
         * keys are present in a given Resource::IAnimation.
         */
        class IBlendable
        {
        public:
            /**
             * @brief Set the blend factor for a given stage.
             * @param stageIndex The stage index
             * @param blendFactor The blend factor to set.
             * @return true if successful.
             */
            virtual Bool SetBlendFactor(UInt32 stageIndex, Real blendFactor) = 0;
            /**
             * @brief Get the blend factor set for a given stage.
             * @param stageIndex The stage index
             * @return The blend factor.
             */
            virtual Real GetBlendFactor(UInt32 stageIndex) const = 0;

        protected:
            virtual ~IBlendable() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IBlendable nodes.
         */
        typedef IGenericNodeTarget<IBlendable> IBlendableNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BLENDABLE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_DRAWABLE_CONTAINER_H__
#define __MURL_GRAPH_I_DRAWABLE_CONTAINER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_drawable.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IDrawableContainer
         * @brief The IDrawableContainer property interface.
         * This interface provides a common way to store and retrieve individual drawables.
         * Not currently in use.
         */
        class IDrawableContainer
        {
        public:
            
        protected:
            virtual ~IDrawableContainer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IDrawableContainer nodes.
         */
        typedef IGenericNodeTarget<IDrawableContainer> IDrawableContainerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_DRAWABLE_CONTAINER_H__

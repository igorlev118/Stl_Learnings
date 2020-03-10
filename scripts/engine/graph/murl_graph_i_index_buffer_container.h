// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_INDEX_BUFFER_CONTAINER_H__
#define __MURL_GRAPH_I_INDEX_BUFFER_CONTAINER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_index_buffer.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IIndexBufferContainer
         * @brief The IIndexBufferContainer property interface.
         * This interface provides a common way to store and retrieve individual vertex buffers.
         * Not currently in use.
         */
        class IIndexBufferContainer
        {
        public:
            
        protected:
            virtual ~IIndexBufferContainer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IIndexBufferContainer nodes.
         */
        typedef IGenericNodeTarget<IIndexBufferContainer> IIndexBufferContainerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_INDEX_BUFFER_CONTAINER_H__

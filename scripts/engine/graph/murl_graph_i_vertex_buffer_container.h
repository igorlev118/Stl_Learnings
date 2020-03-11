// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_VERTEX_BUFFER_CONTAINER_H__
#define __MURL_GRAPH_I_VERTEX_BUFFER_CONTAINER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_vertex_buffer.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IVertexBufferContainer
         * @brief The IVertexBufferContainer property interface.
         * This interface provides a common way to store and retrieve individual vertex buffers.
         * Not currently in use.
         */
        class IVertexBufferContainer
        {
        public:
            
        protected:
            virtual ~IVertexBufferContainer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IVertexBufferContainer nodes.
         */
        typedef IGenericNodeTarget<IVertexBufferContainer> IVertexBufferContainerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_VERTEX_BUFFER_CONTAINER_H__

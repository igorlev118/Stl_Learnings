// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_VERTEX_BUFFER_H__
#define __MURL_GRAPH_I_VERTEX_BUFFER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_attribute_container.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IVertexBuffer
         * @brief The IVertexBuffer property interface.
         * This interface provides properties common to a class representing an
         * array of individual vertices. Rendering of this buffer can either be done
         * directly or in conjunction with an index buffer.
         */
        class IVertexBuffer : public IAttributeContainer
        {
        public:
            /**
             * @brief Set the buffer access mode.
             * @param mode The access mode.
             * @return true if successful.
             */
            virtual Bool SetVertexBufferAccessMode(IEnums::BufferAccessMode mode) = 0;
            /**
             * @brief Get the buffer access mode.
             * @return The access mode.
             */
            virtual IEnums::BufferAccessMode GetVertexBufferAccessMode() const = 0;

            /**
             * @brief Set the maximum number of vertices the vertex buffer can hold.
             * @param maxNumberOfVertices The maximum capacity.
             * @param preserveContents If true, existing contents will be copied;
             *      but existing vertices beyond the new capacity are discarded.
             * @return true if successful.
             */
            virtual Bool SetMaxNumberOfVertices(UInt32 maxNumberOfVertices, Bool preserveContents) = 0;
            /**
             * @brief Get the maximum number of vertices the vertex buffer can hold.
             * @return The maximum capacity.
             */
            virtual UInt32 GetMaxNumberOfVertices() const = 0;

            /**
             * @brief Explicitly set the total byte size of single vertex element.
             * This method explicitly sets the total byte size of a vertex element, i.e. the sum of
             * all individual attributes' byte sizes. If not set, the vertex size is automatically
             * calculated from all given attributes.
             * @param byteSize The total byte size (i.e. stride) of a vertex element.
             * @return true if successful.
             */
            virtual Bool SetVertexByteSize(UInt32 byteSize) = 0;
            /**
             * @brief Get the total byte size of single vertex element in the buffer.
             * This method returns the total size in bytes of a single vertex element,
             * which represents the sum of all individual attribute item byte sizes.
             * @return The total vertex element byte size.
             */
            virtual UInt32 GetVertexByteSize() const = 0;
            
            /**
             * @brief Retrieve a mutable pointer to the vertex data stored in the buffer.
             * @return A mutable pointer to the data.
             */
            virtual void* GetVertexData() = 0;
            /**
             * @brief Retrieve a constant pointer to the vertex data stored in the buffer.
             * @return A constant pointer to the data.
             */
            virtual const void* GetVertexData() const = 0;
            /**
             * @brief Set the actual number of vertices currently used.
             * @param numberOfVertices The current number of vertices, in the range
             *      from 0 to GetMaxNumberOfVertices().
             * @return true if successful.
             */
            virtual Bool SetNumberOfVertices(UInt32 numberOfVertices) = 0;
            /**
             * @brief Mark the whole vertex buffer as modified.
             * @return true if successful.
             */
            virtual Bool SetVerticesModified() = 0;
            /**
             * @brief Mark a portion of the vertex buffer as modified.
             * @param firstVertex The zero-based index of the first modified vertex.
             * @param numberOfVertices The number of modified vertices.
             * @return true if successful.
             */
            virtual Bool SetVerticesModified(UInt32 firstVertex, UInt32 numberOfVertices) = 0;

        protected:
            virtual ~IVertexBuffer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IVertexBuffer nodes.
         */
        typedef IGenericNodeTarget<IVertexBuffer> IVertexBufferNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_VERTEX_BUFFER_H__

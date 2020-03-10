// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_INDEX_BUFFER_H__
#define __MURL_GRAPH_I_INDEX_BUFFER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IIndexBuffer
         * @brief The IIndexBuffer property interface.
         * This interface provides properties common to a class representing an
         * array of individual indices. Typically this is used in conjunction
         * with a Graph::IVertexBuffer to represent an indexed mesh geometry, but
         * there is no restriction to do so.
         */
        class IIndexBuffer
        {
        public:
            /**
             * @brief Set the buffer access mode.
             * @param mode The access mode.
             * @return true if successful.
             */
            virtual Bool SetIndexBufferAccessMode(IEnums::BufferAccessMode mode) = 0;
            /**
             * @brief Get the buffer access mode.
             * @return The access mode.
             */
            virtual IEnums::BufferAccessMode GetIndexBufferAccessMode() const = 0;

            /**
             * @brief Set the maximum number of indices the index buffer can hold.
             * @param maxNumberOfIndices The maximum capacity.
             * @param preserveContents If true, existing contents will be copied;
             *      but existing indices beyond the new capacity are discarded.
             * @return true if successful.
             */
            virtual Bool SetMaxNumberOfIndices(UInt32 maxNumberOfIndices, Bool preserveContents) = 0;
            /**
             * @brief Get the maximum number of indices the index buffer can hold.
             * @return The maximum capacity.
             */
            virtual UInt32 GetMaxNumberOfIndices() const = 0;

            /**
             * @brief Set the data type of the indices stored in the buffer.
             * @param type One of the IEnums::IndexType members.
             * @return true if successful.
             */
            virtual Bool SetIndexType(IEnums::IndexType type) = 0;
            /**
             * @brief Get the data type of the indices stored in the buffer.
             * @return One of the IEnums::IndexType members.
             */
            virtual IEnums::IndexType GetIndexType() const = 0;
            /**
             * @brief Get the number of bytes of a single index element stored.
             * @return The number of bytes per index element.
             */
            virtual UInt32 GetIndexByteSize() const = 0;

            /**
             * @brief Retrieve a mutable pointer to the index data stored in the buffer.
             * @return A mutable pointer to the data.
             */
            virtual void* GetIndexData() = 0;
            /**
             * @brief Retrieve a constant pointer to the index data stored in the buffer.
             * @return A constant pointer to the data.
             */
            virtual const void* GetIndexData() const = 0;
            /**
             * @brief Set the actual number of indices currently used.
             * @param numberOfIndices The current number of indices, in the range
             *      from 0 to GetMaxNumberOfIndices().
             * @return true if successful.
             */
            virtual Bool SetNumberOfIndices(UInt32 numberOfIndices) = 0;
            /**
             * @brief Mark the whole index buffer as modified.
             * @return true if successful.
             */
            virtual Bool SetIndicesModified() = 0;
            /**
             * @brief Mark a portion of the index buffer as modified.
             * @param firstIndex The zero-based index of the first modified index value.
             * @param numberOfIndices The number of modified indices.
             * @return true if successful.
             */
            virtual Bool SetIndicesModified(UInt32 firstIndex, UInt32 numberOfIndices) = 0;

        protected:
            virtual ~IIndexBuffer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IIndexBuffer nodes.
         */
        typedef IGenericNodeTarget<IIndexBuffer> IIndexBufferNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_INDEX_BUFFER_H__

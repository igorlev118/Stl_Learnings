// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_INDICES_H__
#define __MURL_VIDEO_I_INDICES_H__

#include "murl_video_i_drawable.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IProgram;
        class IIndexBuffer;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IIndices
         * @brief The IIndices video object interface.
         * This interface represents a container object holding references to one or
         * more individual IIndexBuffer objects.
         *
         * Used internally by various geometry graph nodes, such as Graph::GenericGeometry,
         * Graph::ResourceMeshGeometry and others.
         */
        class IIndices : public IDrawable
        {
        public:
            /**
             * @brief Add a single default index buffer.
             * @param indexBuffer The index buffer to add.
             * @return The zero-based index of the index buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddIndexBuffer(IIndexBuffer* indexBuffer) = 0;
            /**
             * @brief Add a single predefined index buffer.
             * @param item The predefined item.
             * @param indexBuffer The index buffer to add.
             * @return The zero-based index of the index buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddIndexBuffer(IEnums::IndexBufferItem item, IIndexBuffer* indexBuffer) = 0;
            /**
             * @brief Add a single custom index buffer, by its unique integer ID in the renderer.
             * @param id The buffer's unique integer ID.
             * @param indexBuffer The index buffer to add.
             * @return The zero-based index of the index buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddIndexBuffer(SInt32 id, IIndexBuffer* indexBuffer) = 0;
            /**
             * @brief Add a single custom index buffer, by its actual name.
             * @param name The buffer name.
             * @param indexBuffer The index buffer to add.
             * @return The zero-based index of the index buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddIndexBuffer(const String& name, IIndexBuffer* indexBuffer) = 0;
            /**
             * @brief Remove all present index buffers from the container.
             * @return true if successful.
             */
            virtual Bool RemoveAllIndexBuffers() = 0;

            /**
             * @brief Get the index of a predefined index buffer in the container.
             * @param item The index buffer item to query.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetIndexBufferIndex(IEnums::IndexBufferItem item) const = 0;
            /**
             * @brief Get the index of a custom index buffer in the container, by its unique integer ID.
             * @param id The unique integer ID of the index buffer to query.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetIndexBufferIndex(SInt32 id) const = 0;
            /**
             * @brief Get the index of a custom index buffer in the container, by its actual name.
             * @param name The buffer name.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetIndexBufferIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual index buffers present in the container.
             * @return The number of index buffers present.
             */
            virtual UInt32 GetNumberOfIndexBuffers() const = 0;

            /**
             * @brief Get the predefined index buffer item at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The predefined buffer item, or IEnums::CONSTANT_BUFFER_ITEM_DEFAULT if the index
             *      is out of range.
             */
            virtual IEnums::IndexBufferItem GetIndexBufferItem(UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of a index buffer at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetIndexBufferId(UInt32 index) const = 0;
            
            /**
             * @brief Get the index buffer at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The buffer, or null if the index is out of range.
             */
            virtual IIndexBuffer* GetIndexBuffer(UInt32 index) const = 0;
            
            /**
             * @brief Get the signature, obtained via IRenderer::AcquireIndicesSignature().
             * @return The buffer signature.
             */
            virtual UInt32 GetSignature() const = 0;
            
        protected:
            virtual ~IIndices() {}
        };
    }
}

#endif // __MURL_VIDEO_I_INDICES_H__

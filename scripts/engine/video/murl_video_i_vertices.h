// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_VERTICES_H__
#define __MURL_VIDEO_I_VERTICES_H__

#include "murl_video_i_drawable.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IProgram;
        class IVertexBuffer;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IVertices
         * @brief The IVertices video object interface.
         * This interface represents a container object holding references to one or
         * more individual IVertexBuffer objects.
         *
         * Used internally by various geometry graph nodes, such as Graph::GenericGeometry,
         * Graph::ResourceMeshGeometry and others.
         */
        class IVertices : public IDrawable
        {
        public:
            /**
             * @brief Enable the vertices container.
             * @return true if successful.
             */
            virtual Bool Enable() = 0;
            /**
             * @brief Disable the vertices container.
             * @return true if successful.
             */
            virtual Bool Disable() = 0;

            /**
             * @brief Attach the vertices container to the current GPU program.
             * @param currentProgram The current GPU program.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram) = 0;
            
            /**
             * @brief Set the primitive type to render, if no index buffer is used.
             * @param type The primitive type.
             * @return true if successful.
             */
            virtual Bool SetPrimitiveType(IEnums::PrimitiveType type) = 0;
            /**
             * @brief Get the primitive type.
             * @return The primitive type.
             */
            virtual IEnums::PrimitiveType GetPrimitiveType() const = 0;
            
            /**
             * @brief Add a single default vertex buffer.
             * @param vertexBuffer The vertex buffer to add.
             * @return The zero-based index of the vertex buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddVertexBuffer(IVertexBuffer* vertexBuffer) = 0;
            /**
             * @brief Add a single predefined vertex buffer.
             * @param item The predefined item.
             * @param vertexBuffer The vertex buffer to add.
             * @return The zero-based index of the vertex buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddVertexBuffer(IEnums::VertexBufferItem item, IVertexBuffer* vertexBuffer) = 0;
            /**
             * @brief Add a single custom vertex buffer, by its unique integer ID in the renderer.
             * @param id The buffer's unique integer ID.
             * @param vertexBuffer The vertex buffer to add.
             * @return The zero-based index of the vertex buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddVertexBuffer(SInt32 id, IVertexBuffer* vertexBuffer) = 0;
            /**
             * @brief Add a single custom vertex buffer, by its actual name.
             * @param name The buffer name.
             * @param vertexBuffer The vertex buffer to add.
             * @return The zero-based index of the vertex buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddVertexBuffer(const String& name, IVertexBuffer* vertexBuffer) = 0;
            /**
             * @brief Remove all present vertex buffers from the container.
             * @return true if successful.
             */
            virtual Bool RemoveAllVertexBuffers() = 0;
            
            /**
             * @brief Get the index of a predefined vertex buffer in the container.
             * @param item The vertex buffer item to query.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetVertexBufferIndex(IEnums::VertexBufferItem item) const = 0;
            /**
             * @brief Get the index of a custom vertex buffer in the container, by its unique integer ID.
             * @param id The unique integer ID of the vertex buffer to query.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetVertexBufferIndex(SInt32 id) const = 0;
            /**
             * @brief Get the index of a custom vertex buffer in the container, by its actual name.
             * @param name The buffer name.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetVertexBufferIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual vertex buffers present in the container.
             * @return The number of vertex buffers present.
             */
            virtual UInt32 GetNumberOfVertexBuffers() const = 0;

            /**
             * @brief Get the predefined vertex buffer item at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The predefined buffer item, or IEnums::VERTEX_BUFFER_ITEM_CUSTOM if the index
             *      is out of range.
             */
            virtual IEnums::VertexBufferItem GetVertexBufferItem(UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of a vertex buffer at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetVertexBufferId(UInt32 index) const = 0;
            
            /**
             * @brief Get the vertex buffer at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The buffer, or null if the index is out of range.
             */
            virtual IVertexBuffer* GetVertexBuffer(UInt32 index) const = 0;
            
            /**
             * @brief Get the signature, obtained via IRenderer::AcquireVerticesSignature().
             * @return The buffer signature.
             */
            virtual UInt32 GetSignature() const = 0;
            
        protected:
            virtual ~IVertices() {}
        };
    }
}

#endif // __MURL_VIDEO_I_VERTICES_H__

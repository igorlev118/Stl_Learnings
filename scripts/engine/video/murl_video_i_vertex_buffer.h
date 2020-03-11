// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_VERTEX_BUFFER_H__
#define __MURL_VIDEO_I_VERTEX_BUFFER_H__

#include "murl_video_i_attribute.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IProgram;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IVertexBuffer
         * @brief The IVertexBuffer video object interface.
         * This interface represents a buffer containing geometry vertices.
         *
         * Used internally by various geometry graph nodes, such as Graph::PlaneGeometry,
         * Graph::ResourceMeshGeometry and others.
         */
        class IVertexBuffer
        {
        public:
            /**
             * @brief Get the mutable Video::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Video::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Attach the vertex buffer to the current GPU program.
             * @param currentProgram The current GPU program.
             * @param id The unique integer ID of the vertex buffer in the renderer.
             * @param unit The vertex buffer unit.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram, SInt32 id, UInt32 unit) = 0;

            /**
             * @brief Allow/disallow dynamic batching.
             * @param allowed If true, dynamic batching is allowed.
             * @return true if successful.
             */
            virtual Bool SetDynamicBatchingAllowed(Bool allowed) = 0;
            /**
             * @brief Check if the buffer allows for dynamic batching.
             * @return true if dynamic batching is allowed.
             */
            virtual Bool IsDynamicBatchingAllowed() const = 0;
            
            /**
             * @brief Set the access mode hint (read only or read/write).
             * @param mode The access mode.
             * @return true if successful.
             */
            virtual Bool SetAccessMode(IEnums::BufferAccessMode mode) = 0;
            /**
             * @brief Get the access mode hint.
             * @return The access mode.
             */
            virtual IEnums::BufferAccessMode GetAccessMode() const = 0;
            
            /**
             * @brief Set the number of bones affecting the vertex buffer.
             * @param numberOfBones The number of bones needed.
             * @return true if successful.
             */
            virtual Bool SetNumberOfBones(UInt32 numberOfBones) = 0;
            /**
             * @brief Get the number of bones affecting the vertex buffer.
             * @return The number of bones needed.
             */
            virtual UInt32 GetNumberOfBones() const = 0;
            
            /**
             * @brief Assign a mutable source data storage.
             * @param vertices A pointer to the mutable buffer holding the source vertices.
             * @param maxNumberOfVertices The maximum number of vertices the buffer can hold.
             * @param byteStride The buffer stride, i.e. the size of a single vertex entry in bytes.
             * @return true if successful.
             */
            virtual Bool SetVertexData(void* vertices, UInt32 maxNumberOfVertices, UInt32 byteStride) = 0;
            /**
             * @brief Assign a constant source data storage.
             * @param vertices A pointer to the constant buffer holding the source vertices.
             * @param maxNumberOfVertices The maximum number of vertices the buffer can hold.
             * @param byteStride The buffer stride, i.e. the size of a single vertex entry in bytes.
             * @return true if successful.
             */
            virtual Bool SetVertexData(const void* vertices, UInt32 maxNumberOfVertices, UInt32 byteStride) = 0;
            /**
             * @brief Set the actual number of vertices used.
             * @param numberOfVertices The actual number of vertices. Must be less or equal than
             *      the maximum number defined via SetVertexData().
             * @return true if successful.
             */
            virtual Bool SetNumberOfVertices(UInt32 numberOfVertices) = 0;
            /**
             * @brief Mark the whole buffer as modified.
             * @return true if successful.
             */
            virtual Bool SetVerticesModified() = 0;
            /**
             * @brief Mark a sub-region of the buffer as modified.
             * @param firstVertex The first modified vertex in the buffer.
             * @param numberOfVertices The number of modified vertices.
             * @return true if successful.
             */
            virtual Bool SetVerticesModified(UInt32 firstVertex, UInt32 numberOfVertices) = 0;
            /**
             * @brief Get a pointer to the mutable source data, if available.
             * If the source data storage was defined using a constant pointer, this method returns null.
             * @return A pointer to the mutable source data, or null if the source is immutable.
             */
            virtual void* GetVertexData() = 0;
            /**
             * @brief Get a pointer to the constant source data.
             * @return A pointer to the source data.
             */
            virtual const void* GetVertexData() const = 0;
            /**
             * @brief Get a pointer to the actual mutable buffer data.
             * @return A pointer to the actual buffer data.
             */
            virtual void* GetVertexBufferData() = 0;
            /**
             * @brief Get a pointer to the actual constant buffer data.
             * @return A pointer to the actual buffer data.
             */
            virtual const void* GetVertexBufferData() const = 0;
            /**
             * @brief Get the maximum number of vertices the buffer can hold.
             * @return The maximum number of vertices.
             */
            virtual UInt32 GetMaxNumberOfVertices() const = 0;
            /**
             * @brief Get the actual number of vertices used.
             * @return The actual number of vertices.
             */
            virtual UInt32 GetNumberOfVertices() const = 0;
            /**
             * @brief Get the byte stride, i.e. the size of a single vertex entry in bytes.
             * @return The byte stride.
             */
            virtual UInt32 GetByteStride() const = 0;
            /**
             * @brief Check if the buffer contents are modified.
             * @return true if modified.
             */
            virtual Bool AreVerticesModified() const = 0;

            /**
             * @brief Add a single predefined attribute variable.
             * @param item The predefined item.
             * @param type The attribute data type.
             * @param byteOffset The offset in bytes of the attribute's location within the actual buffer data.
             * @return The zero-based index of the attribute in the buffer, or -1 if failed.
             */
            virtual SInt32 AddAttribute(IEnums::AttributeItem item, IEnums::AttributeType type, UInt32& byteOffset) = 0;
            /**
             * @brief Add a single custom attribute variable, by its unique integer ID in the renderer.
             * @param id The attribute's unique integer ID.
             * @param type The attribute data type.
             * @param byteOffset The offset in bytes of the attribute's location within the actual buffer data.
             * @return The zero-based index of the attribute in the buffer, or -1 if failed.
             */
            virtual SInt32 AddAttribute(SInt32 id, IEnums::AttributeType type, UInt32& byteOffset) = 0;
            /**
             * @brief Add a single custom attribute variable, by its actual name.
             * @param name The attribute variable name.
             * @param type The attribute data type.
             * @param byteOffset The offset in bytes of the attribute's location within the actual buffer data.
             * @return The zero-based index of the attribute in the buffer, or -1 if failed.
             */
            virtual SInt32 AddAttribute(const String& name, IEnums::AttributeType type, UInt32& byteOffset) = 0;
            /**
             * @brief Remove all present attribute variables from the buffer.
             * @return true if successful.
             */
            virtual Bool RemoveAllAttributes() = 0;

            /**
             * @brief Get the index of a predefined attribute variable in the buffer.
             * @param item The attribute item to query.
             * @return The zero-based index of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(IEnums::AttributeItem item) const = 0;
            /**
             * @brief Get the index of a custom attribute variable in the buffer, by its unique integer ID.
             * @param id The unique integer ID of the variable to query.
             * @return The zero-based index of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(SInt32 id) const = 0;
            /**
             * @brief Get the index of a custom attribute variable in the buffer, by its actual name.
             * @param name The attribute variable name to query.
             * @return The zero-based index of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual attribute variables present in the buffer.
             * @return The number of attribute variables present.
             */
            virtual UInt32 GetNumberOfAttributes() const = 0;
            
            /**
             * @brief Get the data type of an attribute variable at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable data type, or IEnums::ATTRIBUTE_TYPE_UNDEFINED if the index is
             *      out of range.
             */
            virtual IEnums::AttributeType GetAttributeType(UInt32 index) const = 0;
            /**
             * @brief Get the predefined attribute variable item at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The predefined variable item, or IEnums::ATTRIBUTE_ITEM_CUSTOM if the index is
             *      out of range.
             */
            virtual IEnums::AttributeItem GetAttributeItem(UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of an attribute variable at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetAttributeId(UInt32 index) const = 0;
            /**
             * @brief Get the byte offset of an attribute variable relative to the buffer start.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The byte offset, or 0 if the index is out of range.
             */
            virtual UInt32 GetAttributeByteOffset(UInt32 index) const = 0;
            
            /**
             * @brief Get the generic attribute variable at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range.
             */
            virtual IAttribute* GetAttribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IFloatAttribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatAttribute* GetFloatAttribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IFloatVector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatVector2Attribute* GetFloatVector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IFloatVector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatVector3Attribute* GetFloatVector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IFloatVector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatVector4Attribute* GetFloatVector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt8Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Attribute* GetUInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt8Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Vector2Attribute* GetUInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt8Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Vector3Attribute* GetUInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt8Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Vector4Attribute* GetUInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt8Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Attribute* GetSInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt8Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Vector2Attribute* GetSInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt8Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Vector3Attribute* GetSInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt8Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Vector4Attribute* GetSInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt16Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Attribute* GetUInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt16Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Vector2Attribute* GetUInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt16Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Vector3Attribute* GetUInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an IUInt16Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Vector4Attribute* GetUInt16Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt16Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Attribute* GetSInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt16Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Vector2Attribute* GetSInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt16Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Vector3Attribute* GetSInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as an ISInt16Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Vector4Attribute* GetSInt16Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt8Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Attribute* GetNormalizedUInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt8Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Vector2Attribute* GetNormalizedUInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt8Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Vector3Attribute* GetNormalizedUInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt8Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt8Vector4Attribute* GetNormalizedUInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt8Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Attribute* GetNormalizedSInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt8Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Vector2Attribute* GetNormalizedSInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt8Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Vector3Attribute* GetNormalizedSInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt8Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt8Vector4Attribute* GetNormalizedSInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt16Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Attribute* GetNormalizedUInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt16Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Vector2Attribute* GetNormalizedUInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt16Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Vector3Attribute* GetNormalizedUInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized IUInt16Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IUInt16Vector4Attribute* GetNormalizedUInt16Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt16Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Attribute* GetNormalizedSInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt16Vector2Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Vector2Attribute* GetNormalizedSInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt16Vector3Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Vector3Attribute* GetNormalizedSInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute variable at a given index as a normalized ISInt16Vector4Attribute.
             * @param index The index of the variable to query, from 0 to GetNumberOfAttributes()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt16Vector4Attribute* GetNormalizedSInt16Vector4Attribute(UInt32 index) const = 0;

            /**
             * @brief Check if the actual buffer resides in video memory.
             * @return true if in video memory.
             */
            virtual Bool IsInVideoMemory() const = 0;
            
            /**
             * @brief Get the signature, obtained via IRenderer::AcquireVertexBufferSignature().
             * @return The buffer signature.
             */
            virtual UInt32 GetSignature() const = 0;
            
        protected:
            virtual ~IVertexBuffer() {}
        };
    }
}

#endif // __MURL_VIDEO_I_VERTEX_BUFFER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_CONSTANT_BUFFER_H__
#define __MURL_VIDEO_I_CONSTANT_BUFFER_H__

#include "murl_video_i_uniform.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IProgram;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IConstantBuffer
         * @brief The IConstantBuffer video object interface.
         * This interface represents a buffer containing one or more individual
         * GPU program uniform variables.
         *
         * Used internally by Graph::FixedParameters and Graph::GenericParameterGroup.
         */
        class IConstantBuffer
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
             * @brief Attach the constant buffer to the current GPU program.
             * @param currentProgram The current GPU program.
             * @param id The unique integer ID of the constant buffer in the renderer.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram, SInt32 id) = 0;
            
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
             * @brief Assign a mutable source data storage.
             * @param constants A pointer to the mutable buffer holding individual uniform values.
             * @param maxByteSize The size of the buffer in bytes.
             * @return true if successful.
             */
            virtual Bool SetConstantData(void* constants, UInt32 maxByteSize) = 0;
            /**
             * @brief Assign a constant source data storage.
             * @param constants A pointer to the constant buffer holding individual uniform values.
             * @param maxByteSize The size of the buffer in bytes.
             * @return true if successful.
             */
            virtual Bool SetConstantData(const void* constants, UInt32 maxByteSize) = 0;
            /**
             * @brief Set the actual size of the buffer used.
             * @param byteSize The actual buffer size in bytes. Must be less or equal than the
             *      maximum byte size defined via SetConstantData().
             * @return true if successful.
             */
            virtual Bool SetByteSize(UInt32 byteSize) = 0;
            /**
             * @brief Mark the whole buffer as modified.
             * @return true if successful.
             */
            virtual Bool SetConstantsModified() = 0;
            /**
             * @brief Mark a sub-region of the buffer as modified.
             * @param firstConstant The first modified constant in the buffer.
             * @param numberOfConstants The number of modified constants.
             * @return true if successful.
             */
            virtual Bool SetConstantsModified(UInt32 firstConstant, UInt32 numberOfConstants) = 0;
            /**
             * @brief Get a pointer to the mutable source data, if available.
             * If the source data storage was defined using a constant pointer, this method returns null.
             * @return A pointer to the mutable source data, or null if the source is immutable.
             */
            virtual void* GetConstantData() = 0;
            /**
             * @brief Get a constant pointer to the source data.
             * @return A pointer to the source data.
             */
            virtual const void* GetConstantData() const = 0;
            /**
             * @brief Get a pointer to the actual mutable buffer data.
             * @return A pointer to the actual buffer data.
             */
            virtual void* GetConstantBufferData() = 0;
            /**
             * @brief Get a pointer to the actual constant buffer data.
             * @return A pointer to the actual buffer data.
             */
            virtual const void* GetConstantBufferData() const = 0;
            /**
             * @brief Get the maximum number of bytes the buffer can hold.
             * @return The maximum buffer byte size.
             */
            virtual UInt32 GetMaxByteSize() const = 0;
            /**
             * @brief Get the actual number of buffer bytes used.
             * @return The actual buffer byte size.
             */
            virtual UInt32 GetByteSize() const = 0;
            /**
             * @brief Check if the buffer contents are modified.
             * @return true if modified.
             */
            virtual Bool AreConstantsModified() const = 0;

            /**
             * @brief Add a single predefined uniform variable.
             * @param item The predefined item.
             * @param type The uniform data type.
             * @param byteOffset The offset in bytes of the uniform's location within the actual buffer data.
             * @return The zero-based index of the uniform in the buffer, or -1 if failed.
             */
            virtual SInt32 AddUniform(IEnums::UniformItem item, IEnums::UniformType type, UInt32& byteOffset) = 0;
            /**
             * @brief Add a single custom uniform variable, by its unique integer ID in the renderer.
             * @param id The uniform's unique integer ID.
             * @param type The uniform data type.
             * @param byteOffset The offset in bytes of the uniform's location within the actual buffer data.
             * @return The zero-based index of the uniform in the buffer, or -1 if failed.
             */
            virtual SInt32 AddUniform(SInt32 id, IEnums::UniformType type, UInt32& byteOffset) = 0;
            /**
             * @brief Add a single custom uniform variable, by its actual name.
             * @param name The uniform variable name.
             * @param type The uniform data type.
             * @param byteOffset The offset in bytes of the uniform's location within the actual buffer data.
             * @return The zero-based index of the uniform in the buffer, or -1 if failed.
             */
            virtual SInt32 AddUniform(const String& name, IEnums::UniformType type, UInt32& byteOffset) = 0;
            /**
             * @brief Remove all present uniform variables from the buffer.
             * @return true if successful.
             */
            virtual Bool RemoveAllUniforms() = 0;

            /**
             * @brief Get the index of a predefined uniform variable in the buffer.
             * @param item The uniform item to query.
             * @return The zero-based index of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(IEnums::UniformItem item) const = 0;
            /**
             * @brief Get the index of a custom uniform variable in the buffer, by its unique integer ID.
             * @param id The unique integer ID of the variable to query.
             * @return The zero-based index of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(SInt32 id) const = 0;
            /**
             * @brief Get the index of a custom uniform variable in the buffer, by its actual name.
             * @param name The uniform variable name to query.
             * @return The zero-based index of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual uniform variables present in the buffer.
             * @return The number of uniform variables present.
             */
            virtual UInt32 GetNumberOfUniforms() const = 0;

            /**
             * @brief Get the data type of a uniform variable at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable data type, or IEnums::UNIFORM_TYPE_UNDEFINED if the index is 
             *      out of range.
             */
            virtual IEnums::UniformType GetUniformType(UInt32 index) const = 0;
            /**
             * @brief Get the predefined uniform variable item at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The predefined variable item, or IEnums::UNIFORM_ITEM_CUSTOM if the index is
             *      out of range.
             */
            virtual IEnums::UniformItem GetUniformItem(UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of a uniform variable at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetUniformId(UInt32 index) const = 0;
            /**
             * @brief Get the byte offset of a uniform variable relative to the buffer start.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The byte offset, or 0 if the index is out of range.
             */
            virtual UInt32 GetUniformByteOffset(UInt32 index) const = 0;

            /**
             * @brief Get the generic uniform variable at a given index.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range.
             */
            virtual IUniform* GetUniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an IFloatUniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatUniform* GetFloatUniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an IFloatVector2Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatVector2Uniform* GetFloatVector2Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an IFloatVector3Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatVector3Uniform* GetFloatVector3Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an IFloatVector4Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatVector4Uniform* GetFloatVector4Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an IFloatMatrix2Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatMatrix2Uniform* GetFloatMatrix2Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an IFloatMatrix3Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatMatrix3Uniform* GetFloatMatrix3Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an IFloatMatrix4Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual IFloatMatrix4Uniform* GetFloatMatrix4Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an ISInt32Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt32Uniform* GetSInt32Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an ISInt32Vector2Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt32Vector2Uniform* GetSInt32Vector2Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an ISInt32Vector3Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt32Vector3Uniform* GetSInt32Vector3Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform variable at a given index as an ISInt32Vector4Uniform.
             * @param index The index of the variable to query, from 0 to GetNumberOfUniforms()-1.
             * @return The variable, or null if the index is out of range or the variable
             *      has a different data type.
             */
            virtual ISInt32Vector4Uniform* GetSInt32Vector4Uniform(UInt32 index) const = 0;

            /**
             * @brief Check if the constant buffer is equal to another one.
             * @param other The buffer to compare with.
             * @return true if the buffers are equal.
             */
            virtual Bool IsEqual(const IConstantBuffer* other) const = 0;

            /**
             * @brief Get the signature, obtained via IRenderer::AcquireConstantBufferSignature().
             * @return The buffer signature.
             */
            virtual UInt32 GetSignature() const = 0;
            
        protected:
            virtual ~IConstantBuffer() {}
        };
    }
}

#endif // __MURL_VIDEO_I_CONSTANT_BUFFER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_PROGRAM_H__
#define __MURL_VIDEO_I_PROGRAM_H__

#include "murl_video_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IConstants;
        class IConstantBuffer;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IProgram
         * @brief The IProgram video object interface.
         * This interface represents a GPU program used during rendering.
         *
         * Used internally by Graph::FixedProgram and Graph::ShaderProgram.
         */
        class IProgram
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
             * @brief Enable the program.
             * @return true if successful.
             */
            virtual Bool Enable() = 0;
            /**
             * @brief Disable the program.
             * @return true if successful.
             */
            virtual Bool Disable() = 0;

            /**
             * @brief Attach the new program to the current GPU program.
             * @param currentProgram The current GPU program.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram) = 0;

            /**
             * @brief Check if the program represents a fixed-function one.
             * @return true if the program represents a fixed-function one.
             */
            virtual Bool UsesFixedTechnique() const = 0;

            /**
             * @brief Get a possible branch depending on some constants value.
             * @param constants The constants to check.
             * @return A program branch, or this if not depending on any value.
             */
            virtual IProgram* GetBranch(const IConstants* constants) = 0;

            /**
             * @brief Check if a given predefined constant buffer item is present.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined constant buffer item to query.
             * @return true if present.
             */
            virtual Bool HasConstantBuffer(IEnums::ShaderType shaderType, IEnums::ConstantBufferItem item) const = 0;
            /**
             * @brief Check if a specific constant buffer is present.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the constant buffer to query.
             * @return true if present.
             */
            virtual Bool HasConstantBuffer(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the index of a given predefined constant buffer item in the program.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined constant buffer item to retrieve.
             * @return The zero-based index of the constant buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(IEnums::ShaderType shaderType, IEnums::ConstantBufferItem item) const = 0;
            /**
             * @brief Get the index of a specific constant buffer in the program.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the constant buffer to retrieve.
             * @return The zero-based index of the constant buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the location (register number) of a given predefined constant buffer item in the program.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined constant buffer item to retrieve.
             * @return The location of the constant buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferLocation(IEnums::ShaderType shaderType, IEnums::ConstantBufferItem item) const = 0;
            /**
             * @brief Get the location (register number) of a specific constant buffer in the program.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the constant buffer to retrieve.
             * @return The location of the constant buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferLocation(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the total number of constant buffers in the program.
             * @param shaderType The type of the attached shader to check.
             * @return The number of constant buffers.
             */
            virtual UInt32 GetNumberOfConstantBuffers(IEnums::ShaderType shaderType) const = 0;
            /**
             * @brief Get the predefined constant buffer item at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the constant buffer, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The item, or IEnums::CONSTANT_BUFFER_ITEM_CUSTOM if the index is out of range.
             */
            virtual IEnums::ConstantBufferItem GetConstantBufferItem(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of a constant buffer at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the constant buffer, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetConstantBufferId(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the actual name of a constant buffer at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the constant buffer, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The name, or an empty string if the index is out of range.
             */
            virtual const String& GetConstantBufferName(IEnums::ShaderType shaderType, UInt32 index) const = 0;

            /**
             * @brief Update the constant buffer in the program for a predefined buffer.
             * @param shaderType The type of the attached shader for which to update the buffer.
             * @param item The predefined constant buffer item.
             * @param buffer A handle to the constant buffer.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetConstantBuffer(IEnums::ShaderType shaderType, IEnums::ConstantBufferItem item, const void* buffer, const void* data) = 0;
            
            /**
             * @brief Update the constant buffer in the program for a specific buffer.
             * @param shaderType The type of the attached shader for which to update the buffer.
             * @param id The unique integer ID of the constant buffer.
             * @param buffer A handle to the constant buffer.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetConstantBuffer(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            
            /**
             * @brief Check if a given predefined uniform item is present.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item to query.
             * @return true if present.
             */
            virtual Bool HasUniform(IEnums::ShaderType shaderType, IEnums::UniformItem item) const = 0;
            /**
             * @brief Check if a specific uniform is present.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform to query.
             * @return true if present.
             */
            virtual Bool HasUniform(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the index of a given predefined uniform item in the program.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item to retrieve.
             * @return The zero-based index of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(IEnums::ShaderType shaderType, IEnums::UniformItem item) const = 0;
            /**
             * @brief Get the index of a specific uniform in the program.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform to retrieve.
             * @return The zero-based index of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the location (register number) of a given predefined uniform item in the program.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item to retrieve.
             * @return The location of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformLocation(IEnums::ShaderType shaderType, IEnums::UniformItem item) const = 0;
            /**
             * @brief Get the location (register number) of a specific uniform in the program.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform to retrieve.
             * @return The location of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformLocation(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the total number of uniforms in the program.
             * @param shaderType The type of the attached shader to check.
             * @return The number of uniforms.
             */
            virtual UInt32 GetNumberOfUniforms(IEnums::ShaderType shaderType) const = 0;
            /**
             * @brief Get the predefined uniform item at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the uniform, from 0 to GetNumberOfUniforms()-1.
             * @return The item, or IEnums::UNIFORM_ITEM_CUSTOM if the index is out of range.
             */
            virtual IEnums::UniformItem GetUniformItem(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the data type of a uniform at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the uniform, from 0 to GetNumberOfUniforms()-1.
             * @return The data type, or IEnums::UNIFORM_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::UniformType GetUniformType(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of a uniform at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the uniform, from 0 to GetNumberOfUniforms()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetUniformId(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the actual name of a uniform at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the uniform, from 0 to GetNumberOfUniforms()-1.
             * @return The name, or an empty string if the index is out of range.
             */
            virtual const String& GetUniformName(IEnums::ShaderType shaderType, UInt32 index) const = 0;

            /**
             * @brief Update the uniform in the program for a predefined IFloatUniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloat(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined IFloatVector2Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatVector2(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined IFloatVector3Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatVector3(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined IFloatVector4Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatVector4(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined IFloatMatrix2Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatMatrix2(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined IFloatMatrix3Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatMatrix3(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined IFloatMatrix4Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatMatrix4(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined ISInt32Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined ISInt32Vector2Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32Vector2(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined ISInt32Vector3Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32Vector3(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a predefined ISInt32Vector4Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined uniform item.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32Vector4(IEnums::ShaderType shaderType, IEnums::UniformItem item, const void* buffer, const void* data) = 0;
            
            /**
             * @brief Update the uniform in the program for a specific IFloatUniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloat(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific IFloatVector2Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatVector2(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific IFloatVector3Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatVector3(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific IFloatVector4Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatVector4(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific IFloatMatrix2Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatMatrix2(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific IFloatMatrix3Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatMatrix3(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific IFloatMatrix4Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformFloatMatrix4(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific ISInt32Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific ISInt32Vector2Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32Vector2(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific ISInt32Vector3Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32Vector3(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the uniform in the program for a specific ISInt32Vector4Uniform.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the uniform.
             * @param buffer A handle to the constant buffer containing the uniform.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetUniformSInt32Vector4(IEnums::ShaderType shaderType, SInt32 id, const void* buffer, const void* data) = 0;
            
            /**
             * @brief Check if a given predefined attribute item is present.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item to query.
             * @return true if present.
             */
            virtual Bool HasAttribute(IEnums::ShaderType shaderType, IEnums::AttributeItem item) const = 0;
            /**
             * @brief Check if a specific attribute is present.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute to query.
             * @return true if present.
             */
            virtual Bool HasAttribute(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the index of a given predefined attribute item in the program.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item to retrieve.
             * @return The zero-based index of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(IEnums::ShaderType shaderType, IEnums::AttributeItem item) const = 0;
            /**
             * @brief Get the index of a specific attribute in the program.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute to retrieve.
             * @return The zero-based index of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the location (register number) of a given predefined attribute item in the program.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item to retrieve.
             * @return The location of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeLocation(IEnums::ShaderType shaderType, IEnums::AttributeItem item) const = 0;
            /**
             * @brief Get the location (register number) of a specific attribute in the program.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute to retrieve.
             * @return The location of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeLocation(IEnums::ShaderType shaderType, SInt32 id) const = 0;
            /**
             * @brief Get the total number of attributes in the program.
             * @param shaderType The type of the attached shader to check.
             * @return The number of attributes.
             */
            virtual UInt32 GetNumberOfAttributes(IEnums::ShaderType shaderType) const = 0;
            /**
             * @brief Get the predefined attribute item at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the attribute, from 0 to GetNumberOfAttributes()-1.
             * @return The item, or IEnums::ATTRIBUTE_ITEM_CUSTOM if the index is out of range.
             */
            virtual IEnums::AttributeItem GetAttributeItem(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the data type of an attribute at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the attribute, from 0 to GetNumberOfAttributes()-1.
             * @return The data type, or IEnums::ATTRIBUTE_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::AttributeType GetAttributeType(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of an attribute at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the attribute, from 0 to GetNumberOfAttributes()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetAttributeId(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            /**
             * @brief Get the actual name of an attribute at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the attribute, from 0 to GetNumberOfAttributes()-1.
             * @return The name, or an empty string if the index is out of range.
             */
            virtual const String& GetAttributeName(IEnums::ShaderType shaderType, UInt32 index) const = 0;
            
            /**
             * @brief Update the attribute in the program for a predefined IFloatAttribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloat(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IFloatVector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloatVector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IFloatVector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloatVector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IFloatVector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloatVector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined IUInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined ISInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized IUInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16Vector2(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16Vector3(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a predefined normalized ISInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param item The predefined attribute item.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16Vector4(IEnums::ShaderType shaderType, IEnums::AttributeItem item, UInt32 byteStride, const void* buffer, const void* data) = 0;

            /**
             * @brief Update the attribute in the program for a specific IFloatAttribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloat(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IFloatVector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloatVector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IFloatVector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloatVector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IFloatVector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeFloatVector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt8Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt8Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific IUInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeUInt16Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific ISInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeSInt16Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt8Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt8Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt8Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt8Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt8Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt8Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized IUInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedUInt16Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt16Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt16Vector2Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16Vector2(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt16Vector3Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16Vector3(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;
            /**
             * @brief Update the attribute in the program for a specific normalized ISInt16Vector4Attribute.
             * @param shaderType The type of the attached shader to check.
             * @param id The unique integer ID of the attribute.
             * @param byteStride The byte stride of the vertex buffer.
             * @param buffer A handle to the vertex buffer containing the attribute.
             * @param data The actual buffer data to update with.
             * @return true if successful.
             */
            virtual Bool SetAttributeNormalizedSInt16Vector4(IEnums::ShaderType shaderType, SInt32 id, UInt32 byteStride, const void* buffer, const void* data) = 0;

            /**
             * @brief Check if a texture sampler is present at a given unit.
             * @param shaderType The type of the attached shader to check.
             * @param unit The texture unit, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             * @return true if present.
             */
            virtual Bool HasTexture(IEnums::ShaderType shaderType, UInt32 unit) const = 0;
            /**
             * @brief Get the index of a given texture sampler in the program.
             * @param shaderType The type of the attached shader to check.
             * @param unit The texture unit, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             * @return The zero-based index of the sampler, or -1 if not present.
             */
            virtual SInt32 GetTextureIndex(IEnums::ShaderType shaderType, UInt32 unit) const = 0;
            /**
             * @brief Get the total number of texture samplers in the program.
             * @param shaderType The type of the attached shader to check.
             * @return The number of samplers.
             */
            virtual UInt32 GetNumberOfTextures(IEnums::ShaderType shaderType) const = 0;
            /**
             * @brief Get the semantic of a sampler for a given index and color component.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the sampler, from 0 to GetNumberOfTextures()-1.
             * @param colorComponent The color component to query.
             * @return The semantic, or IEnums::TEXTURE_SEMANTIC_UNDEFINED if the index is out of range.
             */
            virtual IEnums::TextureSemantic GetTextureSemantic(IEnums::ShaderType shaderType, UInt32 index, IEnums::ColorComponent colorComponent) const = 0;
            /**
             * @brief Get the used texture unit of a sampler at a given index.
             * @param shaderType The type of the attached shader to check.
             * @param index The index of the sampler, from 0 to GetNumberOfTextures()-1.
             * @return The unit, or -1 if the index is out of range.
             */
            virtual SInt32 GetTextureUnit(IEnums::ShaderType shaderType, UInt32 index) const = 0;

            /**
             * @brief Set the number of texture units used.
             * @param numberOfUnits The number of units, from 0 to IEnums::NUM_TEXTURE_UNITS.
             * @return true if successful.
             */
            virtual Bool SetNumberOfTextureUnitsUsed(UInt32 numberOfUnits) = 0;
            /**
             * @brief Get the number of texture units used.
             * @return The number of units.
             */
            virtual UInt32 GetNumberOfTextureUnitsUsed() const = 0;

            /**
             * @brief Set the number of light units used.
             * @param numberOfUnits The number of units, from 0 to IEnums::NUM_LIGHT_UNITS.
             * @return true if successful.
             */
            virtual Bool SetNumberOfLightUnitsUsed(UInt32 numberOfUnits) = 0;
            /**
             * @brief Get the number of light units used.
             * @return The number of units.
             */
            virtual UInt32 GetNumberOfLightUnitsUsed() const = 0;

            /**
             * @brief Set the number of bone units used.
             * @param numberOfUnits The number of units, from 0 to IEnums::NUM_BONE_UNITS.
             * @return true if successful.
             */
            virtual Bool SetNumberOfBoneUnitsUsed(UInt32 numberOfUnits) = 0;
            /**
             * @brief Get the number of bone units used.
             * @return The number of units.
             */
            virtual UInt32 GetNumberOfBoneUnitsUsed() const = 0;

            /**
             * @brief Get the texture unit used together with a given light unit, for rendering projective lights.
             * @param lightUnit The light unit to check, from 0 to IEnums::NUM_LIGHT_UNITS-1.
             * @return The texture unit, or -1 if projective lights are not used.
             */
            virtual SInt32 GetLightTextureUnit(UInt32 lightUnit) const = 0;

            /**
             * @brief Check if the program is valid.
             * If linking of the program object fails, this method returns false.
             * @return true if program linking succeeded during initialization.
             */
            virtual Bool IsValid() const = 0;
            /**
             * @brief Get the shader linker log.
             * If linking of the program object fails, this method returns the output
             * provided by the OS/video API. Otherwise, an empty string is returned.
             * @return The linker log message.
             */
            virtual const String& GetLinkerLog() const = 0;

        protected:
            virtual ~IProgram() {}
        };
    }
}

#endif // __MURL_VIDEO_I_PROGRAM_H__

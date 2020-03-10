// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_SHADER_H__
#define __MURL_VIDEO_I_SHADER_H__

#include "murl_video_types.h"
#include "murl_data.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IShader
         * @brief The IShader video object interface.
         * This interface represents a GPU shader to be attached to an IProgram.
         *
         * Used internally by Graph::Shader.
         */
        class IShader
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
             * @brief Attach the shader to a program.
             * @param handle A handle to the program.
             * @return true if successful.
             */
            virtual Bool AttachToProgram(void* handle) = 0;
            /**
             * @brief Detach the shader from a program.
             * @param handle A handle to the program.
             * @return true if successful.
             */
            virtual Bool DetachFromProgram(void* handle) = 0;
            
            /**
             * @brief Set the shader type.
             * @param type The shader type.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::ShaderType type) = 0;
            /**
             * @brief Get the shader type.
             * @return The shader type.
             */
            virtual IEnums::ShaderType GetType() const = 0;
            
            /**
             * @brief Directly set the shader's source code from a given string.
             * @param source The shader source code.
             * @return true if successful.
             */
            virtual Bool SetSource(const String& source) = 0;
            /**
             * @brief Get the shader's source code, if it was explicitly set via SetSource().
             * @return The shader source code.
             */
            virtual const String& GetSource() const = 0;

            /**
             * @brief Set the shader binary.
             * @param data The binary shader data.
             * @return true if successful.
             */
            virtual Bool SetData(const ConstData& data) = 0;
            /**
             * @brief Get the shader binary, if it was set via SetData().
             * @return The binary shader data.
             */
            virtual const ConstData& GetData() const = 0;

            /**
             * @brief Add a constant buffer descriptor.
             * @param name The constant buffer name.
             * @param location The location (register number) of the constant buffer in the shader.
             * @param item The predefined constant buffer item.
             * @return The index of the added constant buffer, or -1 if failed.
             */
            virtual SInt32 AddConstantBuffer(const String& name, UInt32 location, IEnums::ConstantBufferItem item) = 0;
            /**
             * @brief Add an alternative name for a previously added constant buffer.
             * @param index The index of the constant buffer in the shader, from 0 to GetNumberOfConstantBuffers()-1.
             * @param name The constant buffer's alternative name.
             * @return The index of the alternative name string, or -1 if failed.
             */
            virtual SInt32 AddConstantBufferAlternativeName(UInt32 index, const String& name) = 0;
            /**
             * @brief Get the zero-based index of the constant buffer at a given location.
             * @param location The location (register number) to query.
             * @return The index of the constant buffer in the shader, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(UInt32 location) const = 0;
            /**
             * @brief Get the total number of constant buffers present in the shader.
             * @return The number of constant buffers.
             */
            virtual UInt32 GetNumberOfConstantBuffers() const = 0;
            /**
             * @brief Get the location (register number) of a constant buffer at a given index.
             * @param constantBufferIndex The index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetConstantBufferLocation(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get the predefined item of a constant buffer at a given index.
             * @param constantBufferIndex The index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The predefined item.
             */
            virtual IEnums::ConstantBufferItem GetConstantBufferItem(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get the name of a constant buffer at a given index.
             * @param constantBufferIndex The index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The name, or an empty string if the index is out of range.
             */
            virtual const String& GetConstantBufferName(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get the number of alternative names of a constant buffer at a given index.
             * @param constantBufferIndex The index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfConstantBufferAlternativeNames(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get an alternative name of a constant buffer at a given index.
             * @param constantBufferIndex The buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfConstantBufferAlternativeNames()-1.
             * @return The alternative name, or an empty string if an index is out of range.
             */
            virtual const String& GetConstantBufferAlternativeName(UInt32 constantBufferIndex, UInt32 alternativeNameIndex) const = 0;
            
            /**
             * @brief Add a uniform descriptor.
             * @param name The uniform name.
             * @param location The location (register number) of the uniform in the shader.
             * @param item The predefined uniform item.
             * @param type The uniform data type.
             * @return The index of the added uniform, or -1 if failed.
             */
            virtual SInt32 AddUniform(const String& name, UInt32 location, IEnums::UniformItem item, IEnums::UniformType type) = 0;
            /**
             * @brief Add an alternative name for a previously added uniform.
             * @param index The index of the uniform in the shader, from 0 to GetNumberOfUniforms()-1.
             * @param name The uniform's alternative name.
             * @return The index of the alternative name string, or -1 if failed.
             */
            virtual SInt32 AddUniformAlternativeName(UInt32 index, const String& name) = 0;
            /**
             * @brief Get the zero-based index of the uniform at a given location.
             * @param location The location (register number) to query.
             * @return The index of the uniform in the shader, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(UInt32 location) const = 0;
            /**
             * @brief Get the total number of uniforms present in the shader.
             * @return The number of uniforms.
             */
            virtual UInt32 GetNumberOfUniforms() const = 0;
            /**
             * @brief Get the location (register number) of a uniform at a given index.
             * @param uniformIndex The index, from 0 to GetNumberOfUniforms()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetUniformLocation(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the predefined item of a uniform at a given index.
             * @param uniformIndex The index, from 0 to GetNumberOfUniforms()-1.
             * @return The predefined item.
             */
            virtual IEnums::UniformItem GetUniformItem(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the data type of a uniform at a given index.
             * @param uniformIndex The index, from 0 to GetNumberOfUniforms()-1.
             * @return The data type, or IEnums::UNIFORM_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::UniformType GetUniformType(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the name of a uniform at a given index.
             * @param uniformIndex The index, from 0 to GetNumberOfUniforms()-1.
             * @return The name, or an empty string if the index is out of range.
             */
            virtual const String& GetUniformName(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the number of alternative names of a uniform at a given index.
             * @param uniformIndex The index, from 0 to GetNumberOfUniforms()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfUniformAlternativeNames(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get an alternative name of a uniform at a given index.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfUniformAlternativeNames()-1.
             * @return The alternative name, or an empty string if an index is out of range.
             */
            virtual const String& GetUniformAlternativeName(UInt32 uniformIndex, UInt32 alternativeNameIndex) const = 0;

            /**
             * @brief Add an attribute descriptor.
             * @param name The attribute name.
             * @param location The location (register number) of the attribute in the shader.
             * @param item The predefined attribute item.
             * @param type The attribute data type.
             * @return The index of the added attribute, or -1 if failed.
             */
            virtual SInt32 AddAttribute(const String& name, UInt32 location, IEnums::AttributeItem item, IEnums::AttributeType type) = 0;
            /**
             * @brief Add an alternative name for a previously added attribute.
             * @param index The index of the attribute in the shader, from 0 to GetNumberOfAttributes()-1.
             * @param name The attribute's alternative name.
             * @return The index of the alternative name string, or -1 if failed.
             */
            virtual SInt32 AddAttributeAlternativeName(UInt32 index, const String& name) = 0;
            /**
             * @brief Get the zero-based index of the attribute at a given location.
             * @param location The location (register number) to query.
             * @return The index of the attribute in the shader, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(UInt32 location) const = 0;
            /**
             * @brief Get the total number of attributes present in the shader.
             * @return The number of attributes.
             */
            virtual UInt32 GetNumberOfAttributes() const = 0;
            /**
             * @brief Get the location (register number) of an attribute at a given index.
             * @param attributeIndex The index, from 0 to GetNumberOfAttributes()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetAttributeLocation(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the predefined item of an attribute at a given index.
             * @param attributeIndex The index, from 0 to GetNumberOfAttributes()-1.
             * @return The predefined item.
             */
            virtual IEnums::AttributeItem GetAttributeItem(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the data type of an attribute at a given index.
             * @param attributeIndex The index, from 0 to GetNumberOfAttributes()-1.
             * @return The data type, or IEnums::ATTRIBUTE_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::AttributeType GetAttributeType(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the name of an attribute at a given index.
             * @param attributeIndex The index, from 0 to GetNumberOfAttributes()-1.
             * @return The name, or an empty string if the index is out of range.
             */
            virtual const String& GetAttributeName(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the number of alternative names of an attribute at a given index.
             * @param attributeIndex The index, from 0 to GetNumberOfAttributes()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfAttributeAlternativeNames(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get an alternative name of an attribute at a given index.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfAttributeAlternativeNames()-1.
             * @return The alternative name, or an empty string if an index is out of range.
             */
            virtual const String& GetAttributeAlternativeName(UInt32 attributeIndex, UInt32 alternativeNameIndex) const = 0;

            /**
             * @brief Add a texture sampler descriptor.
             * @param name The sampler name.
             * @param location The location (register number) of the constant buffer in the shader.
             * @param type The texture type.
             * @param semantics An array of 4 texture semantics, one for each color component.
             * @param semanticIndices An array of 4 texture semantic indices, one for each color component.
             * @return The index of the added sampler, or -1 if failed.
             */
            virtual SInt32 AddTexture(const String& name, UInt32 location, IEnums::TextureType type, const IEnums::TextureSemantic* semantics, const UInt32* semanticIndices) = 0;
            /**
             * @brief Add an alternative name for a previously added texture sampler.
             * @param index The index of the sampler in the shader, from 0 to GetNumberOfTextures()-1.
             * @param name The sampler's alternative name.
             * @return The index of the alternative name string, or -1 if failed.
             */
            virtual SInt32 AddTextureAlternativeName(UInt32 index, const String& name) = 0;
            /**
             * @brief Get the zero-based index of the texture sampler at a given location.
             * @param location The location (register number) to query.
             * @return The index of the sampler in the shader, or -1 if not found.
             */
            virtual SInt32 GetTextureIndex(UInt32 location) const = 0;
            /**
             * @brief Get the total number of texture samplers present in the shader.
             * @return The number of samplers.
             */
            virtual UInt32 GetNumberOfTextures() const = 0;
            /**
             * @brief Get the location (texture unit) of a sampler at a given index.
             * @param textureIndex The index, from 0 to GetNumberOfTextures()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetTextureLocation(UInt32 textureIndex) const = 0;
            /**
             * @brief Get the type of a texture sampler at a given index.
             * @param textureIndex The index, from 0 to GetNumberOfTextures()-1.
             * @return The sampler type.
             */
            virtual IEnums::TextureType GetTextureType(UInt32 textureIndex) const = 0;
            /**
             * @brief Get the texture semantic of a sampler for a given index and color component.
             * @param textureIndex The index, from 0 to GetNumberOfTextures()-1.
             * @param colorComponent The color component to query.
             * @return The semantic, or IEnums::TEXTURE_SEMANTIC_UNDEFINED if the index is out of range.
             */
            virtual IEnums::TextureSemantic GetTextureSemantic(UInt32 textureIndex, IEnums::ColorComponent colorComponent) const = 0;
            /**
             * @brief Get the texture semantic index of a sampler for a given index and color component.
             * @param textureIndex The index, from 0 to GetNumberOfTextures()-1.
             * @param colorComponent The color component to query.
             * @return The semantic index, or 0 if the index is out of range.
             */
            virtual UInt32 GetTextureSemanticIndex(UInt32 textureIndex, IEnums::ColorComponent colorComponent) const = 0;
            /**
             * @brief Get the name of a texture sampler at a given index.
             * @param textureIndex The index, from 0 to GetNumberOfTextures()-1.
             * @return The name, or an empty string if the index is out of range.
             */
            virtual const String& GetTextureName(UInt32 textureIndex) const = 0;
            /**
             * @brief Get the number of alternative names of a texture sampler at a given index.
             * @param textureIndex The index, from 0 to GetNumberOfTextures()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfTextureAlternativeNames(UInt32 textureIndex) const = 0;
            /**
             * @brief Get an alternative name of a texture sampler at a given index.
             * @param textureIndex The texture index, from 0 to GetNumberOfTextures()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfTextureAlternativeNames()-1.
             * @return The alternative name, or an empty string if an index is out of range.
             */
            virtual const String& GetTextureAlternativeName(UInt32 textureIndex, UInt32 alternativeNameIndex) const = 0;

            /**
             * @brief Check if the shader is valid.
             * If creation/compilation of the shader object fails, this method returns false.
             * @return true if shader compilation succeeded during initialization.
             */
            virtual Bool IsValid() const = 0;
            /**
             * @brief Get the shader compiler log.
             * If creation/compilation of the shader object fails, this method returns the output
             * provided by the OS/video API. Otherwise, an empty string is returned.
             * @return The compiler log message.
             */
            virtual const String& GetCompilerLog() const = 0;

        protected:
            virtual ~IShader() {}
        };
    }
}

#endif // __MURL_VIDEO_I_SHADER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_SHADER_H__
#define __MURL_RESOURCE_I_SHADER_H__

#include "murl_util_iff.h"
#include "murl_data.h"
#include "murl_string.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Resource
    {
        class IObject;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IShader
         * @brief The IShader resource object interface.
         * A shader resource contains GPU shader program code in a number of possible
         * formats, both source and binary forms are defined.
         * The resource object can also contain meta information for the shader (such
         * as information about attributes, texture semantics etc.), for shaders that
         * cannot be queried for this information at run-time (e.g. DirectX 10+ HLSL
         * binary blobs).
         */
        class IShader
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as a shader.
                    FOURCC = 'SHDR',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.02'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native shader resource.
                 * If the file contains more than one block of actual shader data, the members
                 * mLanguage, mType, mDataOffset and mDataByteSize are zero, and the individual
                 * blocks must be parsed from following DataChunk entries.
                 */
                struct HeaderChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a HeaderChunk.
                        FOURCC = 'HEAD'
                    };

                    /// The actual resource version.
                    UInt32 mVersion;

                    /// The shader type, from the IEnums::ShaderType enumeration.
                    UInt32 mType;
                    /// The shader output language, from the IEnums::ShaderLanguage enumeration.
                    UInt32 mOutputLanguage;
                    /// The optional shader input language, from the IEnums::ShaderLanguage enumeration.
                    UInt32 mInputLanguage;

                    /// An offset into the chunk where the shader code data is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The total size in bytes of the contained shader data.
                    UInt32 mDataByteSize;
                };

                /**
                 * @struct DataChunk
                 * @brief An IFF chunk storing information about a single shader.
                 */
                struct DataChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a DataChunk.
                        FOURCC = 'DATA'
                    };

                    /// The shader index.
                    UInt32 mIndex;

                    /// An offset into the chunk where the sub-shader is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The total size in bytes of the sub-shader.
                    UInt32 mDataByteSize;
                };
                
                /**
                 * @struct PrefixChunk
                 * @brief An IFF chunk storing a fragment of a shader's prefix string.
                 */
                struct PrefixChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a PrefixChunk.
                        FOURCC = 'PRFX'
                    };

                    /// An offset into the chunk where the string data is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The total size in bytes of the string data.
                    UInt32 mDataByteSize;
                };
                
                /**
                 * @struct CodeChunk
                 * @brief An IFF chunk storing a fragment of a shader's source code.
                 */
                struct CodeChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a CodeChunk.
                        FOURCC = 'CODE'
                    };

                    /// An offset into the chunk where the string data is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The total size in bytes of the string data.
                    UInt32 mDataByteSize;
                };
                
                /**
                 * @struct ConstantChunk
                 * @brief An IFF chunk of a native shader resource storing a varying variable descriptor.
                 * The data pointed to by mNamesOffset must be interpreted as a pointer to a
                 * Char pointer, which stores mNumberOfNames consecutive C strings.
                 */
                struct ConstantChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a ConstantChunk.
                        FOURCC = 'CNST'
                    };

                    /// The varying variable data type, from the IEnums::ConstantType enumeration.
                    UInt32 mType;
                    /// The variable precision, from the IEnums::ShaderVariablePrecision enumeration.
                    UInt32 mPrecision;
                    /// Optional flags. Must be 0.
                    UInt32 mFlags;
                    /// Array size. Currently not supported, must be 0.
                    UInt32 mArraySize;

                    /// An offset into the chunk where the default value string data is stored. See IffOffset().
                    UInt32 mDefaultValueOffset;
                    /// The total size in bytes of the contained default value string data.
                    UInt32 mDefaultValueByteSize;

                    /// An offset into the chunk where the name string data is stored. See IffOffset().
                    UInt32 mNameOffset;
                    /// The total size in bytes of the contained name string data.
                    UInt32 mNameByteSize;
                };
                
                /**
                 * @struct ConstantBufferChunk
                 * @brief An IFF chunk of a native shader resource storing a constant buffer descriptor.
                 * The data pointed to by mNamesOffset must be interpreted as a pointer to a
                 * Char pointer, which stores mNumberOfNames consecutive C strings.
                 */
                struct ConstantBufferChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a ConstantBufferChunk.
                        FOURCC = 'CBUF'
                    };

                    /// The constant buffer location or register number in the shader.
                    UInt32 mLocation;
                    /// The predefined constant buffer variable item, from the IEnums::ConstantBufferItem enumeration.
                    UInt32 mItem;
                    /// Optional flags. Must be 0.
                    UInt32 mFlags;
                    /// Array size. Currently not supported, must be 0.
                    UInt32 mArraySize;

                    /// The total number of different names by which this constant buffer can be referred to.
                    UInt32 mNumberOfNames;
                    /// An offset into the chunk where the name string data is stored. See IffOffset().
                    UInt32 mNamesOffset;
                    /// The total size in bytes of the contained string data.
                    UInt32 mNamesByteSize;
                };

                /**
                 * @struct UniformChunk
                 * @brief An IFF chunk of a native shader resource storing a uniform variable descriptor.
                 * The data pointed to by mNamesOffset must be interpreted as a pointer to a
                 * Char pointer, which stores mNumberOfNames consecutive C strings.
                 */
                struct UniformChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a UniformChunk.
                        FOURCC = 'UNIF'
                    };

                    /// The uniform variable location or register number in the shader.
                    UInt32 mLocation;
                    /// The index of the constant buffer this uniform belongs to, or -1.
                    SInt32 mConstantBufferIndex;
                    /// The predefined uniform variable item, from the IEnums::UniformItem enumeration.
                    UInt32 mItem;
                    /// The uniform variable data type, from the IEnums::UniformType enumeration.
                    UInt32 mType;
                    /// The variable precision, from the IEnums::ShaderVariablePrecision enumeration.
                    UInt32 mPrecision;
                    /// Optional flags. Must be 0.
                    UInt32 mFlags;
                    /// The array size, or 0 for a scalar uniform.
                    UInt32 mArraySize;

                    /// An offset into the chunk where the default value string data is stored. See IffOffset().
                    UInt32 mDefaultValueOffset;
                    /// The total size in bytes of the contained default value string data.
                    UInt32 mDefaultValueByteSize;

                    /// The total number of different names by which this uniform can be referred to.
                    UInt32 mNumberOfNames;
                    /// An offset into the chunk where the name string data is stored. See IffOffset().
                    UInt32 mNamesOffset;
                    /// The total size in bytes of the contained string data.
                    UInt32 mNamesByteSize;
                };
                
                /**
                 * @struct AttributeChunk
                 * @brief An IFF chunk of a native shader resource storing an attribute variable descriptor.
                 * The data pointed to by mNamesOffset must be interpreted as a pointer to a
                 * Char pointer, which stores mNumberOfNames consecutive C strings.
                 */
                struct AttributeChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a AttributeChunk.
                        FOURCC = 'ATTR'
                    };

                    /// The attribute variable location or register number in the shader.
                    UInt32 mLocation;
                    /// The predefined attribute variable item, from the IEnums::AttributeItem enumeration.
                    UInt32 mItem;
                    /// The attribute variable data type, from the IEnums::AttributeType enumeration.
                    UInt32 mType;
                    /// The variable precision, from the IEnums::ShaderVariablePrecision enumeration.
                    UInt32 mPrecision;
                    /// Optional flags. Must be 0.
                    UInt32 mFlags;
                    /// The array size, or 0 for a scalar attribute.
                    UInt32 mArraySize;

                    /// The total number of different names by which this attribute can be referred to.
                    UInt32 mNumberOfNames;
                    /// An offset into the chunk where the name string data is stored. See IffOffset().
                    UInt32 mNamesOffset;
                    /// The total size in bytes of the contained string data.
                    UInt32 mNamesByteSize;
                };

                /**
                 * @struct VaryingChunk
                 * @brief An IFF chunk of a native shader resource storing a varying variable descriptor.
                 * The data pointed to by mNamesOffset must be interpreted as a pointer to a
                 * Char pointer, which stores mNumberOfNames consecutive C strings.
                 */
                struct VaryingChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a VaryingChunk.
                        FOURCC = 'VRYN'
                    };

                    /// The varying variable location or register number in the shader.
                    UInt32 mLocation;
                    /// The varying variable data type, from the IEnums::VaryingType enumeration.
                    UInt32 mType;
                    /// The variable precision, from the IEnums::ShaderVariablePrecision enumeration.
                    UInt32 mPrecision;
                    /// Optional flags. Must be 0.
                    UInt32 mFlags;
                    /// The array size, or 0 for a scalar varying.
                    UInt32 mArraySize;

                    /// An offset into the chunk where the name string data is stored. See IffOffset().
                    UInt32 mNameOffset;
                    /// The total size in bytes of the contained string data.
                    UInt32 mNameByteSize;
                };

                /**
                 * @struct TextureChunk
                 * @brief An IFF chunk of a native shader resource storing a texture descriptor.
                 */
                struct TextureChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a TextureChunk.
                        FOURCC = 'TXTR'
                    };
                    
                    /// The sampler variable location or register number in the shader.
                    UInt32 mLocation;
                    /// The type of texture, from the IEnums::TextureType enumeration.
                    UInt32 mType;
                    /// The variable precision, from the IEnums::ShaderVariablePrecision enumeration.
                    UInt32 mPrecision;
                    /// Optional flags. Must be 0.
                    UInt32 mFlags;
                    /// Array size. Currently not supported, must be 0.
                    UInt32 mArraySize;

                    /// The default values for each color component.
                    Float mDefaultValue[IEnums::NUM_COLOR_COMPONENTS];
                    /// The semantic for each color component, from the IEnums::TextureSemantic enumeration.
                    UInt32 mSemantic[IEnums::NUM_COLOR_COMPONENTS];
                    /// The semantic index for each color component.
                    UInt32 mSemanticIndex[IEnums::NUM_COLOR_COMPONENTS];

                    /// The total number of different names by which this sampler can be referred to.
                    UInt32 mNumberOfNames;
                    /// An offset into the chunk where the name string data is stored. See IffOffset().
                    UInt32 mNamesOffset;
                    /// The total size in bytes of the contained string data.
                    UInt32 mNamesByteSize;
                };
            };
            
            /**
             * @brief Get the mutable Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Get the number of individual shader chunks.
             * @return The number of chunks.
             */
            virtual UInt32 GetNumberOfSubShaders() const = 0;
            /**
             * @brief Get the sub-shader at a given index.
             * @param shaderIndex The index of the shader, from 0 to GetNumberOfShaders()-1.
             * @return The sub-shader, or null if index is out of range.
             */
            virtual IShader* GetSubShader(UInt32 shaderIndex) = 0;
            /**
             * @brief Get the sub-shader at a given index.
             * @param shaderIndex The index of the shader, from 0 to GetNumberOfShaders()-1.
             * @return The sub-shader, or null if index is out of range.
             */
            virtual const IShader* GetSubShader(UInt32 shaderIndex) const = 0;

            /**
             * @brief Get the index of a sub-shader via a given type and language.
             * If the resource does not contain a shader matching the given type
             * and language, -1 is returned.
             * @param type The shader type to query.
             * @param language The shader language to query.
             * @return The number of chunks.
             */
            virtual SInt32 GetSubShaderIndex(IEnums::ShaderType type, IEnums::ShaderLanguage language) const = 0;

            /**
             * @brief Get the shader type.
             * @return The shader type.
             */
            virtual IEnums::ShaderType GetType() const = 0;
            /**
             * @brief Get the actual output shader language.
             * @return The output shader language.
             */
            virtual IEnums::ShaderLanguage GetOutputLanguage() const = 0;
            /**
             * @brief Get the input shader language this shader was translated from.
             * @return The input shader language, or IEnums::SHADER_LANGUAGE_UNDEFINED
             *  if the shader is compiled from its own source, i.e. not translated.
             */
            virtual IEnums::ShaderLanguage GetInputLanguage() const = 0;

            /**
             * @brief Get the raw shader code data.
             * This method returns the actual shader data that are passed to the video
             * API. In case of OpenGL(ES), this represents a (possibly optimized) piece
             * of GLSL source code. For DirectX, the data are present in binary form.
             * @return A reference to a ConstData object holding the shader data.
             */
            virtual const ConstData& GetRawData() const = 0;

            /**
             * @brief Get the unoptimized shader source code, if present.
             * This method returns a string containing the whole source code of the shader
             * including prefix, definitions and actual code, before it is optimized and 
             * compiled. An empty string is a valid return value, which indicates that the 
             * original source code is not available.
             * @return A string holding the source code, or an empty one if not available.
             */
            virtual const String& GetUnoptimizedSource() const = 0;
            /**
             * @brief Get the compiler log output of the unoptimized shader source code, if present.
             * @return A string holding the log, or an empty one if not available.
             */
            virtual const String& GetUnoptimizedLog() const = 0;

            /**
             * @brief Get the variable definitions of the unoptimized shader source code, if present.
             * This method returns only the variable definition section of the unoptimized code.
             * Use GetUnoptimizedSource() to get the full source.
             * @return A string holding the variables, or an empty one if not available.
             */
            virtual const String& GetUnoptimizedDefinitions() const = 0;
            /**
             * @brief Get the prefix(es) of the unoptimized shader source code, if present.
             * This method returns only the prefix of the unoptimized code. 
             * Use GetUnoptimizedSource() to get the full source.
             * @return A string array holding the prefixes, or an empty one if not available.
             */
            virtual const StringArray& GetUnoptimizedPrefix() const = 0;
            /**
             * @brief Get the code section(s) of the unoptimized shader source code, if present.
             * This method returns only the actual code section of the unoptimized code.
             * Use GetUnoptimizedSource() to get the full source.
             * @return A string array holding the code, or an empty one if not available.
             */
            virtual const StringArray& GetUnoptimizedCode() const = 0;

            /**
             * @brief Get the optimized shader source code, if present.
             * This method returns a string containing the optimized source code of the 
             * including prefix, definitions and actual code.
             * An empty string is a valid return value, which indicates that the original
             * source is not available.
             * @return A string holding the source code, or an empty one if not available.
             */
            virtual const String& GetOptimizedSource() const = 0;
            /**
             * @brief Get the compiler log output of the optimized shader source code, if present.
             * @return A string holding the log, or an empty one if not available.
             */
            virtual const String& GetOptimizedLog() const = 0;

            /**
             * @brief Get the variable definitions of the optimized shader source code, if present.
             * This method returns only the variable definition section of the optimized code.
             * Use GetOptimizedSource() to get the full source.
             * @return A string holding the variables, or an empty one if not available.
             */
            virtual const String& GetOptimizedDefinitions() const = 0;
            /**
             * @brief Get the prefix(es) of the optimized shader source code, if present.
             * This method returns only the prefix of the optimized code.
             * Use GetOptimizedSource() to get the full source.
             * @return A string array holding the prefixes, or an empty one if not available.
             */
            virtual const StringArray& GetOptimizedPrefix() const = 0;
            /**
             * @brief Get the code section(s) of the optimized shader source code, if present.
             * This method returns only the actual code section of the optimized code.
             * Use GetOptimizedSource() to get the full source.
             * @return A string array holding the code, or an empty one if not available.
             */
            virtual const StringArray& GetOptimizedCode() const = 0;

            /**
             * @brief Get the number of constants used by the shader.
             * @return The number of constants.
             */
            virtual UInt32 GetNumberOfConstants() const = 0;
            /**
             * @brief Get the index of a constant with a given name.
             * @param name The name to query.
             * @return The zero-bases index, or -1 if not found.
             */
            virtual SInt32 GetConstantIndex(const String& name) const = 0;
            /**
             * @brief Get the data type of a given constant.
             * @param constantIndex The constant index, from 0 to GetNumberOfConstants()-1.
             * @return The data type, or IEnums::CONSTANT_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::ConstantType GetConstantType(UInt32 constantIndex) const = 0;
            /**
             * @brief Get the precision of a given constant.
             * @param constantIndex The constant index, from 0 to GetNumberOfConstants()-1.
             * @return The precision, or IEnums::SHADER_VARIABLE_PRECISION_DEFAULT if the index is out of range.
             */
            virtual IEnums::ShaderVariablePrecision GetConstantPrecision(UInt32 constantIndex) const = 0;
            /**
             * @brief Get the default value of a given constant as a string.
             * @param constantIndex The constant index, from 0 to GetNumberOfConstants()-1.
             * @return The default value, or an empty string if the index is out of range.
             */
            virtual String GetConstantDefaultValue(UInt32 constantIndex) const = 0;
            /**
             * @brief Get the name of a given constant.
             * @param constantIndex The constant index, from 0 to GetNumberOfConstants()-1.
             * @return The constant name, or an empty string if the index is out of range.
             */
            virtual String GetConstantName(UInt32 constantIndex) const = 0;

            /**
             * @brief Get the number of constant buffers used by the shader.
             * @return The number of constant buffers.
             */
            virtual UInt32 GetNumberOfConstantBuffers() const = 0;
            /**
             * @brief Get the index of a constant buffer with a given name.
             * @param name The name to query.
             * @return The zero-bases index, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(const String& name) const = 0;
            /**
             * @brief Get the location or register number of a given constant buffer.
             * @param constantBufferIndex The buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetConstantBufferLocation(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get the predefined item of a given constant buffer.
             * @param constantBufferIndex The buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The item, or IEnums::CONSTANT_BUFFER_ITEM_CUSTOM if the index is out of range.
             */
            virtual IEnums::ConstantBufferItem GetConstantBufferItem(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get the primary variable name of a given constant buffer.
             * @param constantBufferIndex The buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The variable name, or an empty string if the index is out of range.
             */
            virtual String GetConstantBufferName(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get the number of alternative variable names of a given constant buffer.
             * @param constantBufferIndex The buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfConstantBufferAlternativeNames(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get an alternative variable name of a given constant buffer.
             * @param constantBufferIndex The buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfConstantBufferAlternativeNames()-1.
             * @return The alternative variable name, or an empty string if an index is out of range.
             */
            virtual String GetConstantBufferAlternativeName(UInt32 constantBufferIndex, UInt32 alternativeNameIndex) const = 0;
            /**
             * @brief Get the number of uniform variables present in a given constant buffer.
             * @param constantBufferIndex The buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The number of uniforms present in the constant buffer at the given index.
             */
            virtual UInt32 GetNumberOfConstantBufferUniforms(UInt32 constantBufferIndex) const = 0;
            /**
             * @brief Get the global index of a uniform in a given constant buffer at a given index.
             * @param constantBufferIndex The constant buffer index, from 0 to GetNumberOfConstantBuffers()-1.
             * @param uniformIndex The local uniform index, from 0 to GetNumberOfConstantBufferUniforms(constantBufferIndex)-1.
             * @return The zero-based global uniform index to be used in any of the GetUniform*() calls, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferUniformIndex(UInt32 constantBufferIndex, UInt32 uniformIndex) const = 0;

            /**
             * @brief Get the number of uniform variables used by the shader.
             * @return The number of uniform variables.
             */
            virtual UInt32 GetNumberOfUniforms() const = 0;
            /**
             * @brief Get the index of a uniform with a given name.
             * @param name The name to query.
             * @return The zero-bases index, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(const String& name) const = 0;
            /**
             * @brief Get the location, register number or constant buffer offset of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetUniformLocation(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the index of the constant buffer the uniform belongs to.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The constant buffer index, or -1 if the index is out of range or
             *  the uniform does not belong to a constant buffer.
             */
            virtual SInt32 GetUniformConstantBufferIndex(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the predefined item of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The item, or IEnums::UNIFORM_ITEM_CUSTOM if the index is out of range.
             */
            virtual IEnums::UniformItem GetUniformItem(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the data type of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The data type, or IEnums::UNIFORM_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::UniformType GetUniformType(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the variable precision of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The precision, or IEnums::SHADER_VARIABLE_PRECISION_DEFAULT if the index is out of range.
             */
            virtual IEnums::ShaderVariablePrecision GetUniformPrecision(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the array size of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The array size, or 0 for a scalar uniform.
             */
            virtual UInt32 GetUniformArraySize(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the default value of a given uniform as a string.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The default value, or an empty string if the index is out of range.
             */
            virtual String GetUniformDefaultValue(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the primary variable name of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The variable name, or an empty string if the index is out of range.
             */
            virtual String GetUniformName(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get the number of alternative variable names of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfUniformAlternativeNames(UInt32 uniformIndex) const = 0;
            /**
             * @brief Get an alternative variable name of a given uniform.
             * @param uniformIndex The uniform index, from 0 to GetNumberOfUniforms()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfUniformAlternativeNames()-1.
             * @return The alternative variable name, or an empty string if an index is out of range.
             */
            virtual String GetUniformAlternativeName(UInt32 uniformIndex, UInt32 alternativeNameIndex) const = 0;

            /**
             * @brief Get the number of attribute variables used by the shader.
             * @return The number of attribute variables.
             */
            virtual UInt32 GetNumberOfAttributes() const = 0;
            /**
             * @brief Get the index of an attribute with a given name.
             * @param name The name to query.
             * @return The zero-bases index, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(const String& name) const = 0;
            /**
             * @brief Get the location or register number of a given attribute.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetAttributeLocation(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the predefined item of a given attribute.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @return The item, or IEnums::ATTRIBUTE_ITEM_CUSTOM if the index is out of range.
             */
            virtual IEnums::AttributeItem GetAttributeItem(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the data type of a given attribute.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @return The data type, or IEnums::ATTRIBUTE_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::AttributeType GetAttributeType(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the variable precision of a given attribute.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @return The precision, or IEnums::SHADER_VARIABLE_PRECISION_DEFAULT if the index is out of range.
             */
            virtual IEnums::ShaderVariablePrecision GetAttributePrecision(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the primary variable name of a given attribute.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @return The variable name, or an empty string if the index is out of range.
             */
            virtual String GetAttributeName(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the number of alternative variable names of a given attribute.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfAttributeAlternativeNames(UInt32 attributeIndex) const = 0;
            /**
             * @brief Get an alternative variable name of a given attribute.
             * @param attributeIndex The attribute index, from 0 to GetNumberOfAttributes()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfAttributeAlternativeNames()-1.
             * @return The alternative variable name, or an empty string if an index is out of range.
             */
            virtual String GetAttributeAlternativeName(UInt32 attributeIndex, UInt32 alternativeNameIndex) const = 0;

            /**
             * @brief Get the number of varying variables used by the shader.
             * @return The number of varying variables.
             */
            virtual UInt32 GetNumberOfVaryings() const = 0;
            /**
             * @brief Get the index of a varying with a given name.
             * @param name The name to query.
             * @return The zero-bases index, or -1 if not found.
             */
            virtual SInt32 GetVaryingIndex(const String& name) const = 0;
            /**
             * @brief Get the location or register number of a given varying variable.
             * @param varyingIndex The varying variable index, from 0 to GetNumberOfVaryings()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetVaryingLocation(UInt32 varyingIndex) const = 0;
            /**
             * @brief Get the data type of a given varying variable.
             * @param varyingIndex The varying variable index, from 0 to GetNumberOfVaryings()-1.
             * @return The data type, or IEnums::VARYING_TYPE_UNDEFINED if the index is out of range.
             */
            virtual IEnums::VaryingType GetVaryingType(UInt32 varyingIndex) const = 0;
            /**
             * @brief Get the variable precision of a given varying variable.
             * @param varyingIndex The varying variable index, from 0 to GetNumberOfVaryings()-1.
             * @return The precision, or IEnums::SHADER_VARIABLE_PRECISION_DEFAULT if the index is out of range.
             */
            virtual IEnums::ShaderVariablePrecision GetVaryingPrecision(UInt32 varyingIndex) const = 0;
            /**
             * @brief Get the name of a given varying variable.
             * @param varyingIndex The varying variable index, from 0 to GetNumberOfVaryings()-1.
             * @return The variable name, or an empty string if the index is out of range.
             */
            virtual String GetVaryingName(UInt32 varyingIndex) const = 0;

            /**
             * @brief Get the number of texture (sampler) variables used by the shader.
             * @return The number of sampler variables.
             */
            virtual UInt32 GetNumberOfTextures() const = 0;
            /**
             * @brief Get the index of a texture with a given name.
             * @param name The name to query.
             * @return The zero-bases index, or -1 if not found.
             */
            virtual SInt32 GetTextureIndex(const String& name) const = 0;
            /**
             * @brief Get the location or register number of a given texture sampler.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @return The location, or -1 if the index is out of range.
             */
            virtual SInt32 GetTextureLocation(UInt32 textureIndex) const = 0;
            /**
             * @brief Get the data type of a given texture sampler.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @return The type, or IEnums::TEXTURE_TYPE_DEFAULT if the index is out of range.
             */
            virtual IEnums::TextureType GetTextureType(UInt32 textureIndex) const = 0;
            /**
             * @brief Get additional flags of a given texture sampler.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @return The flag bit mask, or IEnums::TEXTURE_FLAG_MASK_NONE if the index is out of range.
             */
            virtual IEnums::TextureFlagMask GetTextureFlags(UInt32 textureIndex) const = 0;
            /**
             * @brief Get the variable precision of a given texture sampler.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @return The precision, or IEnums::SHADER_VARIABLE_PRECISION_DEFAULT if the index is out of range.
             */
            virtual IEnums::ShaderVariablePrecision GetTexturePrecision(UInt32 textureIndex) const = 0;
            /**
             * @brief Get the semantic of a given texture sampler for a given color channel.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @param colorComponent The color component to query.
             * @return The semantic, or IEnums::TEXTURE_SEMANTIC_UNDEFINED if the index is out of range.
             */
            virtual IEnums::TextureSemantic GetTextureSemantic(UInt32 textureIndex, IEnums::ColorComponent colorComponent) const = 0;
            /**
             * @brief Get the semantic index of a given texture sampler for a given color channel.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @param colorComponent The color component to query.
             * @return The index, or 0 if the index is out of range.
             */
            virtual UInt32 GetTextureSemanticIndex(UInt32 textureIndex, IEnums::ColorComponent colorComponent) const = 0;
            /**
             * @brief Get the default value of a given texture sampler for a given color channel.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @param colorComponent The color component to query.
             * @return The default value, or 0.0 if the index is out of range.
             */
            virtual Float GetTextureDefaultValue(UInt32 textureIndex, IEnums::ColorComponent colorComponent) const = 0;
            /**
             * @brief Get the primary variable name of a given texture sampler.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @return The variable name, or an empty string if the index is out of range.
             */
            virtual String GetTextureName(UInt32 textureIndex) const = 0;
            /**
             * @brief Get the number of alternative variable names of a given texture sampler.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @return The number of alternative names, or 0 if the index is out of range.
             */
            virtual UInt32 GetNumberOfTextureAlternativeNames(UInt32 textureIndex) const = 0;
            /**
             * @brief Get an alternative variable name of a given texture sampler.
             * @param textureIndex The sampler index, from 0 to GetNumberOfTextures()-1.
             * @param alternativeNameIndex The name index, from 0 to GetNumberOfTextureAlternativeNames()-1.
             * @return The alternative variable name, or an empty string if an index is out of range.
             */
            virtual String GetTextureAlternativeName(UInt32 textureIndex, UInt32 alternativeNameIndex) const = 0;

        protected:
            virtual ~IShader() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_SHADER_H__

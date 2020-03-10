// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_SHADER_BUILDER_H__
#define __MURL_UTIL_SHADER_BUILDER_H__

#include "murl_i_enums.h"
#include "murl_object_array.h"
#include "murl_result.h"

namespace Murl
{
    namespace Util
    {
        class ShaderBuilder
        {
        public:
            struct Constant
            {
                Constant();

                String mName;
                String mValue;
                String mDefaultValue;

                IEnums::ConstantType mType;
                IEnums::ShaderVariablePrecision mPrecision;
            };
            
            struct Attribute
            {
                Attribute();

                String mName;

                IEnums::AttributeItem mItem;
                IEnums::AttributeType mType;
                IEnums::ShaderVariablePrecision mPrecision;
            };

            struct Uniform
            {
                Uniform();

                String mName;
                String mValue;
                String mDefaultValue;
                UInt32 mArraySize;

                IEnums::UniformItem mItem;
                IEnums::UniformType mType;
                IEnums::ShaderVariablePrecision mPrecision;
            };

            struct ConstantBuffer
            {
                ConstantBuffer();

                String mName;

                IEnums::ConstantBufferItem mItem;
                ObjectArray<Uniform> mUniforms;
            };

            struct Varying
            {
                Varying();

                String mName;

                IEnums::VaryingType mType;
                IEnums::ShaderVariablePrecision mPrecision;
            };

            struct Texture
            {
                Texture();

                UInt32 mUnit;
                String mName;

                IEnums::TextureType mType;
                IEnums::TextureSemantic mSemantic[IEnums::NUM_COLOR_COMPONENTS];
                UInt32 mSemanticIndex[IEnums::NUM_COLOR_COMPONENTS];
                IEnums::ShaderVariablePrecision mPrecision;
                IEnums::TextureFlagMask mFlags;
            };

            struct Prefix
            {
                Prefix();

                IEnums::ShaderType mType;
                IEnums::ShaderLanguage mLanguage;

                StringArray mSource;
            };
            
            struct Code
            {
                Code();

                IEnums::ShaderType mType;
                IEnums::ShaderLanguage mLanguage;
                IEnums::ShaderLanguage mInputLanguage;
                IEnums::ShaderLanguage mOutputLanguage;

                Bool mIsOptimizationEnabled;

                StringArray mSource;
            };

            struct Context
            {
                Context();

                IEnums::ShaderType mType;
                IEnums::ShaderLanguage mInputLanguage;
                IEnums::ShaderLanguage mOutputLanguage;

                ObjectArray<Constant> mConstants;
                ObjectArray<Attribute> mAttributes;
                ObjectArray<ConstantBuffer> mConstantBuffers;
                ObjectArray<Varying> mVaryings;
                ObjectArray<Texture> mTextures;

                ObjectArray<Prefix> mPrefix;
                ObjectArray<Code> mCode;

                Result mResult;

                String mUnoptimizedLog;
                String mUnoptimizedDefinitions;
                StringArray mUnoptimizedPrefix;
                StringArray mUnoptimizedSource;

                String mOptimizedLog;
                String mOptimizedDefinitions;
                StringArray mOptimizedPrefix;
                StringArray mOptimizedSource;
            };

            ShaderBuilder();
            virtual ~ShaderBuilder();

            virtual Bool Setup(Context& context);
            virtual Bool Finish();

            virtual Bool BuildSource(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& source, Bool disableOptimization);

            virtual const Context* GetContext() const;

            static String GetShaderPrefix(IEnums::ShaderType type, IEnums::ShaderLanguage language);
            static IEnums::ShaderLanguage GetShaderLanguage(const String& source);

            static Bool ValidateSource(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& source);

            static IEnums::UniformType ParseUniformType(const String& typeStr);

        protected:
            Code* GetCode(IEnums::ShaderType type, IEnums::ShaderLanguage language, Bool actualOnly);
            Prefix* GetPrefix(IEnums::ShaderType type, IEnums::ShaderLanguage language);

            SInt32 GetPrefixIndex(IEnums::ShaderType shaderType, IEnums::ShaderLanguage shaderLanguage, SInt32 startIndex = -1);
            SInt32 GetCodeIndex(IEnums::ShaderType shaderType, IEnums::ShaderLanguage shaderLanguage, Bool actualOnly, SInt32 startIndex = -1);

            Bool BuildUnoptimizedShader(IEnums::ShaderType type, IEnums::ShaderLanguage inputLanguage, IEnums::ShaderLanguage outputLanguage, Prefix* prefix, Code* code, String& source);
            Bool BuildOptimizedShader(IEnums::ShaderType type, IEnums::ShaderLanguage inputLanguage, IEnums::ShaderLanguage outputLanguage, Prefix* prefix, Code* code, String& source);

            Bool OptimizeShader(IEnums::ShaderType type, IEnums::ShaderLanguage inputLanguage, IEnums::ShaderLanguage outputLanguage, const String& inputSource, String& outputSource);

            Bool BuildShaderDefinitions(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool BuildGlslShaderDefinitions(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool BuildHlslShaderDefinitions(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);

            Bool BuildGlslVertexShaderDefinitions(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& source);
            Bool BuildGlslFragmentShaderDefinitions(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& source);

            Bool AppendGlslConstants(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendGlslAttributes(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendGlslConstantBuffers(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendGlslVaryings(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendGlslTextures(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendGlslBuiltins(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);

            Bool AppendGlslConstant(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Constant& constant, String& defs);
            Bool AppendGlslAttribute(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Attribute& attribute, String& defs);
            Bool AppendGlslUniform(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Uniform& uniform, String& defs);
            Bool AppendGlslVarying(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Varying& varying, String& defs);
            Bool AppendGlslTexture(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Texture& texture, String& defs);

            Bool BuildHlslVertexShaderDefinitions(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& source);
            Bool BuildHlslFragmentShaderDefinitions(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& source);

            Bool AppendHlslConstants(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendHlslAttributes(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendHlslConstantBuffers(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendHlslVaryings(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendHlslTextures(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);
            Bool AppendHlslOutput(IEnums::ShaderType type, IEnums::ShaderLanguage language, String& defs);

            Bool AppendHlslConstant(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Constant& constant, String& defs);
            Bool AppendHlslAttribute(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Attribute& attribute, String& defs);
            Bool AppendHlslUniform(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Uniform& uniform, String& defs);
            Bool AppendHlslVarying(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Varying& varying, String& defs, UInt32 index);
            Bool AppendHlslTexture(IEnums::ShaderType type, IEnums::ShaderLanguage language, const Texture& texture, String& defs);

            String GetGlslAttributeQualifier(IEnums::ShaderType type, IEnums::ShaderLanguage language);
            String GetGlslUniformQualifier(IEnums::ShaderType type, IEnums::ShaderLanguage language);
            String GetGlslVaryingQualifier(IEnums::ShaderType type, IEnums::ShaderLanguage language);

            Bool CanProcessLanguage(IEnums::ShaderLanguage language) const;

            String Concatenate(const StringArray& a) const;

            static String GetGlslPrecision(IEnums::ShaderLanguage language, IEnums::ShaderVariablePrecision precision, IEnums::ShaderVariablePrecision defaultPrecision);
            static String GetGlslConstantType(IEnums::ShaderLanguage language, IEnums::ConstantType constantType);
            static String GetGlslAttributeType(IEnums::ShaderLanguage language, IEnums::AttributeType attributeType);
            static String GetGlslUniformType(IEnums::ShaderLanguage language, IEnums::UniformType uniformType);
            static String GetGlslVaryingType(IEnums::ShaderLanguage language, IEnums::VaryingType varyingType);
            static String GetGlslTextureType(IEnums::ShaderLanguage language, IEnums::TextureType textureType, IEnums::TextureFlagMask textureFlags);

            static String GetHlslAttributeType(IEnums::ShaderLanguage language, IEnums::AttributeType attributeType);
            static String GetHlslUniformType(IEnums::ShaderLanguage language, IEnums::UniformType uniformType);
            static String GetHlslVaryingType(IEnums::ShaderLanguage language, IEnums::VaryingType varyingType);

            static String GetHlslAttributeSemantic(IEnums::ShaderLanguage language, IEnums::AttributeItem attributeItem);

            static Bool IsGlsl130OrHigher(IEnums::ShaderLanguage language);
            static Bool IsHlsl40OrHigher(IEnums::ShaderLanguage language);

            static Bool ValidateGlslEsSource(IEnums::ShaderType type, String& source);

            static Bool AreGlslConstantBuffersSupported(IEnums::ShaderLanguage language);
            static Bool AreHlslConstantBuffersSupported(IEnums::ShaderLanguage language);

            Context* mContext;
        };
    }
}

#endif  // __MURL_UTIL_SHADER_BUILDER_H__

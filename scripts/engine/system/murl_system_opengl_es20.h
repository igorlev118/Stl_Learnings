// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_SYSTEM_OPENGL_ES20_H__
#define __MURL_SYSTEM_OPENGL_ES20_H__

#include "murl_i_enums.h"
#include "murl_string.h"

namespace Murl
{
    namespace System
    {
        namespace OpenGl
        {
            namespace Es20
            {
                // Various constants
                enum
                {
                    NUM_TEXTURE_UNITS = 8,
                    NUM_VERTEX_ATTRIBUTES = 16
                };
                
                // Startup/Shutdown code
                Bool Init(Bool enableChecks);
                Bool DeInit();
                
                // Platform-specific utility functions
                Bool GetCompressedTextureFormat(IEnums::PixelFormat pixelFormat, UInt32& format);

                Bool GetColorBufferFormat(IEnums::ColorBufferFormat colorBufferFormat, UInt32& format);
                Bool GetDepthBufferFormat(IEnums::DepthBufferFormat depthBufferFormat, UInt32& format);
                Bool GetStencilBufferFormat(IEnums::StencilBufferFormat stencilBufferFormat, UInt32& format);
                
                Bool GetTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);
                Bool GetColorTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);
                Bool GetDepthTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);
                Bool GetStencilTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);

                String PreprocessVertexShaderSource(const String& source);
                String PreprocessFragmentShaderSource(const String& source);

                Bool IsDepthBufferFormatGenericSupported();
                Bool IsDepthBufferFormat16BitSupported();
                Bool IsDepthBufferFormat24BitSupported();
                Bool IsDepthBufferFormat32BitSupported();

                Bool IsStencilBufferFormatGenericSupported();
                Bool IsStencilBufferFormat8BitSupported();

                Bool IsReverseTextureByteOrderingSupported();

                UInt32 GetMaxVertexAttributeCount();
                UInt32 GetMaxVertexUniformVectorCount();
                UInt32 GetMaxVertexTextureUnitCount();
                UInt32 GetMaxFragmentUniformVectorCount();
                UInt32 GetMaxFragmentTextureUnitCount();
                UInt32 GetMaxVaryingVectorCount();

                // ==================
                // OpenGL ES 2.0 Core
                // ==================

                // API Functions
                void ActiveTexture(UInt32 texture);
                void AttachShader(UInt32 program, UInt32 shader);
                void BindAttribLocation(UInt32 program, UInt32 index, const char* name);
                void BindBuffer(UInt32 target, UInt32 buffer);
                void BindFramebuffer(UInt32 target, UInt32 framebuffer);
                void BindRenderbuffer(UInt32 target, UInt32 renderbuffer);
                void BindTexture(UInt32 target, UInt32 texture);
                void BlendColor(float red, float green, float blue, float alpha);
                void BlendEquation( UInt32 mode );
                void BlendEquationSeparate(UInt32 modeRGB, UInt32 modeAlpha);
                void BlendFunc(UInt32 sfactor, UInt32 dfactor);
                void BlendFuncSeparate(UInt32 srcRGB, UInt32 dstRGB, UInt32 srcAlpha, UInt32 dstAlpha);
                void BufferData(UInt32 target, SInt32 size, const void* data, UInt32 usage);
                void BufferSubData(UInt32 target, SInt32 offset, SInt32 size, const void* data);
                UInt32 CheckFramebufferStatus(UInt32 target);
                void Clear(UInt32 mask);
                void ClearColor(float red, float green, float blue, float alpha);
                void ClearDepthf(float depth);
                void ClearStencil(SInt32 s);
                void ColorMask(UInt8 red, UInt8 green, UInt8 blue, UInt8 alpha);
                void CompileShader(UInt32 shader);
                void CompressedTexImage2D(UInt32 target, SInt32 level, UInt32 internalformat, SInt32 width, SInt32 height, SInt32 border, SInt32 imageSize, const void* data);
                void CompressedTexSubImage2D(UInt32 target, SInt32 level, SInt32 xoffset, SInt32 yoffset, SInt32 width, SInt32 height, UInt32 format, SInt32 imageSize, const void* data);
                void CopyTexImage2D(UInt32 target, SInt32 level, UInt32 internalformat, SInt32 x, SInt32 y, SInt32 width, SInt32 height, SInt32 border);
                void CopyTexSubImage2D(UInt32 target, SInt32 level, SInt32 xoffset, SInt32 yoffset, SInt32 x, SInt32 y, SInt32 width, SInt32 height);
                UInt32 CreateProgram(void);
                UInt32 CreateShader(UInt32 type);
                void CullFace(UInt32 mode);
                void DeleteBuffers(SInt32 n, const UInt32* buffers);
                void DeleteFramebuffers(SInt32 n, const UInt32* framebuffers);
                void DeleteProgram(UInt32 program);
                void DeleteRenderbuffers(SInt32 n, const UInt32* renderbuffers);
                void DeleteShader(UInt32 shader);
                void DeleteTextures(SInt32 n, const UInt32* textures);
                void DepthFunc(UInt32 func);
                void DepthMask(UInt8 flag);
                void DepthRangef(float zNear, float zFar);
                void DetachShader(UInt32 program, UInt32 shader);
                void Disable(UInt32 cap);
                void DisableVertexAttribArray(UInt32 index);
                void DrawArrays(UInt32 mode, SInt32 first, SInt32 count);
                void DrawBuffer(UInt32 mode);
                void DrawElements(UInt32 mode, SInt32 count, UInt32 type, const void* indices);
                void Enable(UInt32 cap);
                void EnableVertexAttribArray(UInt32 index);
                void Finish(void);
                void Flush(void);
                void FramebufferRenderbuffer(UInt32 target, UInt32 attachment, UInt32 renderbuffertarget, UInt32 renderbuffer);
                void FramebufferTexture2D(UInt32 target, UInt32 attachment, UInt32 textarget, UInt32 texture, SInt32 level);
                void FrontFace(UInt32 mode);
                void GenBuffers(SInt32 n, UInt32* buffers);
                void GenerateMipmap(UInt32 target);
                void GenFramebuffers(SInt32 n, UInt32* framebuffers);
                void GenRenderbuffers(SInt32 n, UInt32* renderbuffers);
                void GenTextures(SInt32 n, UInt32* textures);
                void GetActiveAttrib(UInt32 program, UInt32 index, SInt32 bufsize, SInt32* length, SInt32* size, UInt32* type, char* name);
                void GetActiveUniform(UInt32 program, UInt32 index, SInt32 bufsize, SInt32* length, SInt32* size, UInt32* type, char* name);
                void GetAttachedShaders(UInt32 program, SInt32 maxcount, SInt32* count, UInt32* shaders);
                SInt32 GetAttribLocation(UInt32 program, const char* name);
                void GetBooleanv(UInt32 pname, UInt8* params);
                void GetBufferParameteriv(UInt32 target, UInt32 pname, SInt32* params);
                UInt32 GetError(void);
                void GetFloatv(UInt32 pname, float* params);
                void GetFramebufferAttachmentParameteriv(UInt32 target, UInt32 attachment, UInt32 pname, SInt32* params);
                void GetIntegerv(UInt32 pname, SInt32* params);
                void GetProgramiv(UInt32 program, UInt32 pname, SInt32* params);
                void GetProgramInfoLog(UInt32 program, SInt32 bufsize, SInt32* length, char* infolog);
                void GetRenderbufferParameteriv(UInt32 target, UInt32 pname, SInt32* params);
                void GetShaderiv(UInt32 shader, UInt32 pname, SInt32* params);
                void GetShaderInfoLog(UInt32 shader, SInt32 bufsize, SInt32* length, char* infolog);
                void GetShaderPrecisionFormat(UInt32 shadertype, UInt32 precisiontype, SInt32* range, SInt32* precision);
                void GetShaderSource(UInt32 shader, SInt32 bufsize, SInt32* length, char* source);
                const UInt8* GetString(UInt32 name);
                void GetTexParameterfv(UInt32 target, UInt32 pname, float* params);
                void GetTexParameteriv(UInt32 target, UInt32 pname, SInt32* params);
                void GetUniformfv(UInt32 program, SInt32 location, float* params);
                void GetUniformiv(UInt32 program, SInt32 location, SInt32* params);
                SInt32 GetUniformLocation(UInt32 program, const char* name);
                void GetVertexAttribfv(UInt32 index, UInt32 pname, float* params);
                void GetVertexAttribiv(UInt32 index, UInt32 pname, SInt32* params);
                void GetVertexAttribPointerv(UInt32 index, UInt32 pname, void** pointer);
                void Hint(UInt32 target, UInt32 mode);
                UInt8 IsBuffer(UInt32 buffer);
                UInt8 IsEnabled(UInt32 cap);
                UInt8 IsFramebuffer(UInt32 framebuffer);
                UInt8 IsProgram(UInt32 program);
                UInt8 IsRenderbuffer(UInt32 renderbuffer);
                UInt8 IsShader(UInt32 shader);
                UInt8 IsTexture(UInt32 texture);
                void LineWidth(float width);
                void LinkProgram(UInt32 program);
                void PixelStorei(UInt32 pname, SInt32 param);
                void PolygonOffset(float factor, float units);
                void ReadBuffer(UInt32 mode);
                void ReadPixels(SInt32 x, SInt32 y, SInt32 width, SInt32 height, UInt32 format, UInt32 type, void* pixels);
                void ReleaseShaderCompiler(void);
                void RenderbufferStorage(UInt32 target, UInt32 internalformat, SInt32 width, SInt32 height);
                void SampleCoverage(float value, UInt8 invert);
                void Scissor(SInt32 x, SInt32 y, SInt32 width, SInt32 height);
                void ShaderBinary(SInt32 n, const UInt32* shaders, UInt32 binaryformat, const void* binary, SInt32 length);
                void ShaderSource(UInt32 shader, SInt32 count, const char** string, const SInt32* length);
                void StencilFunc(UInt32 func, SInt32 ref, UInt32 mask);
                void StencilFuncSeparate(UInt32 face, UInt32 func, SInt32 ref, UInt32 mask);
                void StencilMask(UInt32 mask);
                void StencilMaskSeparate(UInt32 face, UInt32 mask);
                void StencilOp(UInt32 fail, UInt32 zfail, UInt32 zpass);
                void StencilOpSeparate(UInt32 face, UInt32 fail, UInt32 zfail, UInt32 zpass);
                void TexImage2D(UInt32 target, SInt32 level, SInt32 internalformat, SInt32 width, SInt32 height, SInt32 border, UInt32 format, UInt32 type, const void* pixels);
                void TexParameterf(UInt32 target, UInt32 pname, float param);
                void TexParameterfv(UInt32 target, UInt32 pname, const float* params);
                void TexParameteri(UInt32 target, UInt32 pname, SInt32 param);
                void TexParameteriv(UInt32 target, UInt32 pname, const SInt32* params);
                void TexSubImage2D(UInt32 target, SInt32 level, SInt32 xoffset, SInt32 yoffset, SInt32 width, SInt32 height, UInt32 format, UInt32 type, const void* pixels);
                void Uniform1f(SInt32 location, float x);
                void Uniform1fv(SInt32 location, SInt32 count, const float* v);
                void Uniform1i(SInt32 location, SInt32 x);
                void Uniform1iv(SInt32 location, SInt32 count, const SInt32* v);
                void Uniform2f(SInt32 location, float x, float y);
                void Uniform2fv(SInt32 location, SInt32 count, const float* v);
                void Uniform2i(SInt32 location, SInt32 x, SInt32 y);
                void Uniform2iv(SInt32 location, SInt32 count, const SInt32* v);
                void Uniform3f(SInt32 location, float x, float y, float z);
                void Uniform3fv(SInt32 location, SInt32 count, const float* v);
                void Uniform3i(SInt32 location, SInt32 x, SInt32 y, SInt32 z);
                void Uniform3iv(SInt32 location, SInt32 count, const SInt32* v);
                void Uniform4f(SInt32 location, float x, float y, float z, float w);
                void Uniform4fv(SInt32 location, SInt32 count, const float* v);
                void Uniform4i(SInt32 location, SInt32 x, SInt32 y, SInt32 z, SInt32 w);
                void Uniform4iv(SInt32 location, SInt32 count, const SInt32* v);
                void UniformMatrix2fv(SInt32 location, SInt32 count, UInt8 transpose, const float* value);
                void UniformMatrix3fv(SInt32 location, SInt32 count, UInt8 transpose, const float* value);
                void UniformMatrix4fv(SInt32 location, SInt32 count, UInt8 transpose, const float* value);
                void UseProgram(UInt32 program);
                void ValidateProgram(UInt32 program);
                void VertexAttrib1f(UInt32 indx, float x);
                void VertexAttrib1fv(UInt32 indx, const float* values);
                void VertexAttrib2f(UInt32 indx, float x, float y);
                void VertexAttrib2fv(UInt32 indx, const float* values);
                void VertexAttrib3f(UInt32 indx, float x, float y, float z);
                void VertexAttrib3fv(UInt32 indx, const float* values);
                void VertexAttrib4f(UInt32 indx, float x, float y, float z, float w);
                void VertexAttrib4fv(UInt32 indx, const float* values);
                void VertexAttribPointer(UInt32 indx, SInt32 size, UInt32 type, UInt8 normalized, SInt32 stride, const void* ptr);
                void Viewport(SInt32 x, SInt32 y, SInt32 width, SInt32 height);

                // Constants
                enum
                {
                    /* ClearBufferMask */
                    DEPTH_BUFFER_BIT               = 0x00000100,
                    STENCIL_BUFFER_BIT             = 0x00000400,
                    COLOR_BUFFER_BIT               = 0x00004000,
                
                    /* Boolean */
                    FALSE                          = 0,
                    TRUE                           = 1,
                
                    /* BeginMode */
                    POINTS                         = 0x0000,
                    LINES                          = 0x0001,
                    LINE_LOOP                      = 0x0002,
                    LINE_STRIP                     = 0x0003,
                    TRIANGLES                      = 0x0004,
                    TRIANGLE_STRIP                 = 0x0005,
                    TRIANGLE_FAN                   = 0x0006,
                
                    /* BlendingFactorDest */
                    ZERO                           = 0,
                    ONE                            = 1,
                    SRC_COLOR                      = 0x0300,
                    ONE_MINUS_SRC_COLOR            = 0x0301,
                    SRC_ALPHA                      = 0x0302,
                    ONE_MINUS_SRC_ALPHA            = 0x0303,
                    DST_ALPHA                      = 0x0304,
                    ONE_MINUS_DST_ALPHA            = 0x0305,
                
                    /* BlendingFactorSrc */
                    DST_COLOR                      = 0x0306,
                    ONE_MINUS_DST_COLOR            = 0x0307,
                    SRC_ALPHA_SATURATE             = 0x0308,
                
                    /* BlendEquationSeparate */
                    FUNC_ADD                       = 0x8006,
                    BLEND_EQUATION                 = 0x8009,
                    BLEND_EQUATION_RGB             = 0x8009,
                    BLEND_EQUATION_ALPHA           = 0x883D,
                
                    /* BlendSubtract */
                    FUNC_SUBTRACT                  = 0x800A,
                    FUNC_REVERSE_SUBTRACT          = 0x800B,
                
                    /* Separate Blend Functions */
                    BLEND_DST_RGB                  = 0x80C8,
                    BLEND_SRC_RGB                  = 0x80C9,
                    BLEND_DST_ALPHA                = 0x80CA,
                    BLEND_SRC_ALPHA                = 0x80CB,
                    CONSTANT_COLOR                 = 0x8001,
                    ONE_MINUS_CONSTANT_COLOR       = 0x8002,
                    CONSTANT_ALPHA                 = 0x8003,
                    ONE_MINUS_CONSTANT_ALPHA       = 0x8004,
                    BLEND_COLOR                    = 0x8005,
                
                    /* Buffer Objects */
                    ARRAY_BUFFER                   = 0x8892,
                    ELEMENT_ARRAY_BUFFER           = 0x8893,
                    ARRAY_BUFFER_BINDING           = 0x8894,
                    ELEMENT_ARRAY_BUFFER_BINDING   = 0x8895,
                
                    STREAM_DRAW                    = 0x88E0,
                    STATIC_DRAW                    = 0x88E4,
                    DYNAMIC_DRAW                   = 0x88E8,
                
                    BUFFER_SIZE                    = 0x8764,
                    BUFFER_USAGE                   = 0x8765,
                
                    CURRENT_VERTEX_ATTRIB          = 0x8626,
                
                    /* CullFaceMode */
                    FRONT                          = 0x0404,
                    BACK                           = 0x0405,
                    FRONT_AND_BACK                 = 0x0408,
                
                    /* EnableCap */
                    TEXTURE_2D                     = 0x0DE1,
                    CULL_FACE                      = 0x0B44,
                    BLEND                          = 0x0BE2,
                    DITHER                         = 0x0BD0,
                    STENCIL_TEST                   = 0x0B90,
                    DEPTH_TEST                     = 0x0B71,
                    SCISSOR_TEST                   = 0x0C11,
                    POLYGON_OFFSET_FILL            = 0x8037,
                    SAMPLE_ALPHA_TO_COVERAGE       = 0x809E,
                    SAMPLE_COVERAGE                = 0x80A0,
                
                    /* ErrorCode */
                    NO_ERROR                       = 0,
                    INVALID_ENUM                   = 0x0500,
                    INVALID_VALUE                  = 0x0501,
                    INVALID_OPERATION              = 0x0502,
                    OUT_OF_MEMORY                  = 0x0505,
                
                    /* FrontFaceDirection */
                    CW                             = 0x0900,
                    CCW                            = 0x0901,
                
                    /* GetPName */
                    LINE_WIDTH                     = 0x0B21,
                    ALIASED_POINT_SIZE_RANGE       = 0x846D,
                    ALIASED_LINE_WIDTH_RANGE       = 0x846E,
                    CULL_FACE_MODE                 = 0x0B45,
                    FRONT_FACE                     = 0x0B46,
                    DEPTH_RANGE                    = 0x0B70,
                    DEPTH_WRITEMASK                = 0x0B72,
                    DEPTH_CLEAR_VALUE              = 0x0B73,
                    DEPTH_FUNC                     = 0x0B74,
                    STENCIL_CLEAR_VALUE            = 0x0B91,
                    STENCIL_FUNC                   = 0x0B92,
                    STENCIL_FAIL                   = 0x0B94,
                    STENCIL_PASS_DEPTH_FAIL        = 0x0B95,
                    STENCIL_PASS_DEPTH_PASS        = 0x0B96,
                    STENCIL_REF                    = 0x0B97,
                    STENCIL_VALUE_MASK             = 0x0B93,
                    STENCIL_WRITEMASK              = 0x0B98,
                    STENCIL_BACK_FUNC              = 0x8800,
                    STENCIL_BACK_FAIL              = 0x8801,
                    STENCIL_BACK_PASS_DEPTH_FAIL   = 0x8802,
                    STENCIL_BACK_PASS_DEPTH_PASS   = 0x8803,
                    STENCIL_BACK_REF               = 0x8CA3,
                    STENCIL_BACK_VALUE_MASK        = 0x8CA4,
                    STENCIL_BACK_WRITEMASK         = 0x8CA5,
                    VIEWPORT                       = 0x0BA2,
                    SCISSOR_BOX                    = 0x0C10,
                    /*      MGL_SCISSOR_TEST */
                    COLOR_CLEAR_VALUE              = 0x0C22,
                    COLOR_WRITEMASK                = 0x0C23,
                    UNPACK_ALIGNMENT               = 0x0CF5,
                    PACK_ALIGNMENT                 = 0x0D05,
                    MAX_TEXTURE_SIZE               = 0x0D33,
                    MAX_VIEWPORT_DIMS              = 0x0D3A,
                    SUBPIXEL_BITS                  = 0x0D50,
                    RED_BITS                       = 0x0D52,
                    GREEN_BITS                     = 0x0D53,
                    BLUE_BITS                      = 0x0D54,
                    ALPHA_BITS                     = 0x0D55,
                    DEPTH_BITS                     = 0x0D56,
                    STENCIL_BITS                   = 0x0D57,
                    POLYGON_OFFSET_UNITS           = 0x2A00,
                    /*      MGL_POLYGON_OFFSET_FILL */
                    POLYGON_OFFSET_FACTOR          = 0x8038,
                    TEXTURE_BINDING_2D             = 0x8069,
                    SAMPLE_BUFFERS                 = 0x80A8,
                    SAMPLES                        = 0x80A9,
                    SAMPLE_COVERAGE_VALUE          = 0x80AA,
                    SAMPLE_COVERAGE_INVERT         = 0x80AB,
                
                    /* GetTextureParameter */
                    NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2,
                    COMPRESSED_TEXTURE_FORMATS     = 0x86A3,
                
                    /* HintMode */
                    DONT_CARE                      = 0x1100,
                    FASTEST                        = 0x1101,
                    NICEST                         = 0x1102,
                
                    /* HintTarget */
                    GENERATE_MIPMAP_HINT           = 0x8192,
                
                    /* DataType */
                    BYTE                           = 0x1400,
                    UNSIGNED_BYTE                  = 0x1401,
                    SHORT                          = 0x1402,
                    UNSIGNED_SHORT                 = 0x1403,
                    INT                            = 0x1404,
                    UNSIGNED_INT                   = 0x1405,
                    FLOAT                          = 0x1406,
                    FIXED                          = 0x140C,
                
                    /* PixelFormat */
                    DEPTH_COMPONENT                = 0x1902,
                    ALPHA                          = 0x1906,
                    RGB                            = 0x1907,
                    RGBA                           = 0x1908,
                    LUMINANCE                      = 0x1909,
                    LUMINANCE_ALPHA                = 0x190A,
                
                    /* PixelType */
                    UNSIGNED_SHORT_4_4_4_4         = 0x8033,
                    UNSIGNED_SHORT_5_5_5_1         = 0x8034,
                    UNSIGNED_SHORT_5_6_5           = 0x8363,
                
                    /* Shaders */
                    FRAGMENT_SHADER                  = 0x8B30,
                    VERTEX_SHADER                    = 0x8B31,
                    MAX_VERTEX_ATTRIBS               = 0x8869,
                    MAX_VERTEX_UNIFORM_VECTORS       = 0x8DFB,
                    MAX_VARYING_VECTORS              = 0x8DFC,
                    MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
                    MAX_VERTEX_TEXTURE_IMAGE_UNITS   = 0x8B4C,
                    MAX_TEXTURE_IMAGE_UNITS          = 0x8872,
                    MAX_FRAGMENT_UNIFORM_VECTORS     = 0x8DFD,
                    SHADER_TYPE                      = 0x8B4F,
                    DELETE_STATUS                    = 0x8B80,
                    LINK_STATUS                      = 0x8B82,
                    VALIDATE_STATUS                  = 0x8B83,
                    ATTACHED_SHADERS                 = 0x8B85,
                    ACTIVE_UNIFORMS                  = 0x8B86,
                    ACTIVE_UNIFORM_MAX_LENGTH        = 0x8B87,
                    ACTIVE_ATTRIBUTES                = 0x8B89,
                    ACTIVE_ATTRIBUTE_MAX_LENGTH      = 0x8B8A,
                    SHADING_LANGUAGE_VERSION         = 0x8B8C,
                    CURRENT_PROGRAM                  = 0x8B8D,
                
                    /* StencilFunction */
                    NEVER                          = 0x0200,
                    LESS                           = 0x0201,
                    EQUAL                          = 0x0202,
                    LEQUAL                         = 0x0203,
                    GREATER                        = 0x0204,
                    NOTEQUAL                       = 0x0205,
                    GEQUAL                         = 0x0206,
                    ALWAYS                         = 0x0207,
                
                    /* StencilOp */
                    KEEP                           = 0x1E00,
                    REPLACE                        = 0x1E01,
                    INCR                           = 0x1E02,
                    DECR                           = 0x1E03,
                    INVERT                         = 0x150A,
                    INCR_WRAP                      = 0x8507,
                    DECR_WRAP                      = 0x8508,
                
                    /* StringName */
                    VENDOR                         = 0x1F00,
                    RENDERER                       = 0x1F01,
                    VERSION                        = 0x1F02,
                    EXTENSIONS                     = 0x1F03,
                
                    /* TextureMagFilter */
                    NEAREST                        = 0x2600,
                    LINEAR                         = 0x2601,
                
                    /* TextureMinFilter */
                    NEAREST_MIPMAP_NEAREST         = 0x2700,
                    LINEAR_MIPMAP_NEAREST          = 0x2701,
                    NEAREST_MIPMAP_LINEAR          = 0x2702,
                    LINEAR_MIPMAP_LINEAR           = 0x2703,
                
                    /* TextureParameterName */
                    TEXTURE_MAG_FILTER             = 0x2800,
                    TEXTURE_MIN_FILTER             = 0x2801,
                    TEXTURE_WRAP_S                 = 0x2802,
                    TEXTURE_WRAP_T                 = 0x2803,
                
                    /* TextureTarget */
                    /*      TEXTURE_2D */
                    TEXTURE                        = 0x1702,
                
                    TEXTURE_CUBE_MAP               = 0x8513,
                    TEXTURE_BINDING_CUBE_MAP       = 0x8514,
                    TEXTURE_CUBE_MAP_POSITIVE_X    = 0x8515,
                    TEXTURE_CUBE_MAP_NEGATIVE_X    = 0x8516,
                    TEXTURE_CUBE_MAP_POSITIVE_Y    = 0x8517,
                    TEXTURE_CUBE_MAP_NEGATIVE_Y    = 0x8518,
                    TEXTURE_CUBE_MAP_POSITIVE_Z    = 0x8519,
                    TEXTURE_CUBE_MAP_NEGATIVE_Z    = 0x851A,
                    MAX_CUBE_MAP_TEXTURE_SIZE      = 0x851C,
                
                    /* TextureUnit */
                    TEXTURE0                       = 0x84C0,
                    TEXTURE1                       = 0x84C1,
                    TEXTURE2                       = 0x84C2,
                    TEXTURE3                       = 0x84C3,
                    TEXTURE4                       = 0x84C4,
                    TEXTURE5                       = 0x84C5,
                    TEXTURE6                       = 0x84C6,
                    TEXTURE7                       = 0x84C7,
                    TEXTURE8                       = 0x84C8,
                    TEXTURE9                       = 0x84C9,
                    TEXTURE10                      = 0x84CA,
                    TEXTURE11                      = 0x84CB,
                    TEXTURE12                      = 0x84CC,
                    TEXTURE13                      = 0x84CD,
                    TEXTURE14                      = 0x84CE,
                    TEXTURE15                      = 0x84CF,
                    TEXTURE16                      = 0x84D0,
                    TEXTURE17                      = 0x84D1,
                    TEXTURE18                      = 0x84D2,
                    TEXTURE19                      = 0x84D3,
                    TEXTURE20                      = 0x84D4,
                    TEXTURE21                      = 0x84D5,
                    TEXTURE22                      = 0x84D6,
                    TEXTURE23                      = 0x84D7,
                    TEXTURE24                      = 0x84D8,
                    TEXTURE25                      = 0x84D9,
                    TEXTURE26                      = 0x84DA,
                    TEXTURE27                      = 0x84DB,
                    TEXTURE28                      = 0x84DC,
                    TEXTURE29                      = 0x84DD,
                    TEXTURE30                      = 0x84DE,
                    TEXTURE31                      = 0x84DF,
                    ACTIVE_TEXTURE                 = 0x84E0,
                
                    /* TextureWrapMode */
                    REPEAT                         = 0x2901,
                    CLAMP_TO_EDGE                  = 0x812F,
                    MIRRORED_REPEAT                = 0x8370,
                
                    /* Uniform Types */
                    FLOAT_VEC2                     = 0x8B50,
                    FLOAT_VEC3                     = 0x8B51,
                    FLOAT_VEC4                     = 0x8B52,
                    INT_VEC2                       = 0x8B53,
                    INT_VEC3                       = 0x8B54,
                    INT_VEC4                       = 0x8B55,
                    BOOL                           = 0x8B56,
                    BOOL_VEC2                      = 0x8B57,
                    BOOL_VEC3                      = 0x8B58,
                    BOOL_VEC4                      = 0x8B59,
                    FLOAT_MAT2                     = 0x8B5A,
                    FLOAT_MAT3                     = 0x8B5B,
                    FLOAT_MAT4                     = 0x8B5C,
                    SAMPLER_2D                     = 0x8B5E,
                    SAMPLER_CUBE                   = 0x8B60,
                
                    /* Vertex Arrays */
                    VERTEX_ATTRIB_ARRAY_ENABLED        = 0x8622,
                    VERTEX_ATTRIB_ARRAY_SIZE           = 0x8623,
                    VERTEX_ATTRIB_ARRAY_STRIDE         = 0x8624,
                    VERTEX_ATTRIB_ARRAY_TYPE           = 0x8625,
                    VERTEX_ATTRIB_ARRAY_NORMALIZED     = 0x886A,
                    VERTEX_ATTRIB_ARRAY_POINTER        = 0x8645,
                    VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
                
                    /* Read Format */
                    IMPLEMENTATION_COLOR_READ_TYPE   = 0x8B9A,
                    IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
                
                    /* Shader Source */
                    COMPILE_STATUS                 = 0x8B81,
                    INFO_LOG_LENGTH                = 0x8B84,
                    SHADER_SOURCE_LENGTH           = 0x8B88,
                    SHADER_COMPILER                = 0x8DFA,
                
                    /* Shader Binary */
                    SHADER_BINARY_FORMATS          = 0x8DF8,
                    NUM_SHADER_BINARY_FORMATS      = 0x8DF9,
                
                    /* Shader Precision-Specified Types */
                    LOW_FLOAT                      = 0x8DF0,
                    MEDIUM_FLOAT                   = 0x8DF1,
                    HIGH_FLOAT                     = 0x8DF2,
                    LOW_INT                        = 0x8DF3,
                    MEDIUM_INT                     = 0x8DF4,
                    HIGH_INT                       = 0x8DF5,
                
                    /* Framebuffer Object. */
                    FRAMEBUFFER                    = 0x8D40,
                    RENDERBUFFER                   = 0x8D41,
                
                    RGBA4                          = 0x8056,
                    RGB5_A1                        = 0x8057,
                    RGB565                         = 0x8D62,
                    DEPTH_COMPONENT16              = 0x81A5,
                    DEPTH_COMPONENT24              = 0x81A6,
                    DEPTH_COMPONENT32              = 0x81A7,

                    STENCIL_INDEX                  = 0x1901,
                    STENCIL_INDEX8                 = 0x8D48,
                
                    RENDERBUFFER_WIDTH             = 0x8D42,
                    RENDERBUFFER_HEIGHT            = 0x8D43,
                    RENDERBUFFER_INTERNAL_FORMAT   = 0x8D44,
                    RENDERBUFFER_RED_SIZE          = 0x8D50,
                    RENDERBUFFER_GREEN_SIZE        = 0x8D51,
                    RENDERBUFFER_BLUE_SIZE         = 0x8D52,
                    RENDERBUFFER_ALPHA_SIZE        = 0x8D53,
                    RENDERBUFFER_DEPTH_SIZE        = 0x8D54,
                    RENDERBUFFER_STENCIL_SIZE      = 0x8D55,
                
                    FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE           = 0x8CD0,
                    FRAMEBUFFER_ATTACHMENT_OBJECT_NAME           = 0x8CD1,
                    FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL         = 0x8CD2,
                    FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
                
                    COLOR_ATTACHMENT0              = 0x8CE0,
                    DEPTH_ATTACHMENT               = 0x8D00,
                    STENCIL_ATTACHMENT             = 0x8D20,
                
                    NONE                           = 0,
                
                    FRAMEBUFFER_COMPLETE                      = 0x8CD5,
                    FRAMEBUFFER_INCOMPLETE_ATTACHMENT         = 0x8CD6,
                    FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
                    FRAMEBUFFER_INCOMPLETE_DIMENSIONS         = 0x8CD9,
                    FRAMEBUFFER_UNSUPPORTED                   = 0x8CDD,
                
                    FRAMEBUFFER_BINDING            = 0x8CA6,
                    RENDERBUFFER_BINDING           = 0x8CA7,
                    MAX_RENDERBUFFER_SIZE          = 0x84E8,
                
                    INVALID_FRAMEBUFFER_OPERATION  = 0x0506,

                    /* Nonstandard ES */
                    UNSIGNED_BYTE_3_3_2     = 0x8032,
                    UNSIGNED_INT_8_8_8_8    = 0x8035,
                    UNSIGNED_INT_10_10_10_2 = 0x8036,

                    HALF_FLOAT_ARB          = 0x140B,
                    LUMINANCE16F_ARB        = 0x881E,
                    LUMINANCE32F_ARB        = 0x8818,
                    ALPHA16F_ARB            = 0x881C,
                    ALPHA32F_ARB            = 0x8816,
                    LUMINANCE_ALPHA16F_ARB  = 0x881F,
                    LUMINANCE_ALPHA32F_ARB  = 0x8816,
                    R16F                    = 0x822D,
                    R32F                    = 0x822E,
                    RG16F                   = 0x822F,
                    RG32F                   = 0x8230,
                    RGB16F_ARB              = 0x881B,
                    RGB32F_ARB              = 0x8815,
                    RGBA16F_ARB             = 0x881A,
                    RGBA32F_ARB             = 0x8814
                };
                
                // ============================================================
                // OpenGL ES 2.0 Extension #5: OES_compressed_ETC1_RGB8_texture
                // ============================================================

                // API functions
                Bool IsOesCompressedEtc1Rgb8TextureSupported();

                // Constants
                enum
                {
                    ETC1_RGB8_OES = 0x8D64
                };
                
                // ========================================
                // OpenGL ES 2.0 Extension #24: OES_depth24
                // ========================================

                // API functions
                Bool IsOesDepth24Supported();

                // ========================================
                // OpenGL ES 2.0 Extension #25: OES_depth32
                // ========================================

                // API functions
                Bool IsOesDepth32Supported();
                
                // ===================================================
                // OpenGL ES 2.0 Extension #26: OES_element_index_uint
                // ===================================================

                // API functions
                Bool IsOesElementIndexUintSupported();
                
                // ==================================================
                // OpenGL ES 2.0 Extension #27: OES_fbo_render_mipmap
                // ==================================================

                // API functions
                Bool IsOesFboRenderMipmapSupported();

                // ===========================================
                // OpenGL ES 2.0 Extension #30: OES_rgb8_rgba8
                // ===========================================

                // API functions
                Bool IsOesRgb8Rgba8Supported();

                // Constants
                enum
                {
                    RGB8_OES                                    = 0x8051,
                    RGBA8_OES                                   = 0x8058
                };
                
                // =====================================================================================
                // OpenGL ES 2.0 Extension #35: OES_texture_half_float_linear & OES_texture_float_linear
                // =====================================================================================

                // API functions
                Bool IsOesTextureHalfFloatLinearSupported();
                Bool IsOesTextureFloatLinearSupported();
                
                // =======================================================================
                // OpenGL ES 2.0 Extension #36: OES_texture_half_float & OES_texture_float
                // =======================================================================

                // API functions
                Bool IsOesTextureHalfFloatSupported();
                Bool IsOesTextureFloatSupported();

                // Constants
                enum
                {
                    HALF_FLOAT_OES          = 0x8D61
                };

                // ================================================================
                // OpenGL ES 2.0 Extension #37: OES_texture_npot & IMG_texture_npot
                // ================================================================

                // API functions
                Bool IsOesTextureNpotSupported();
                Bool IsImgTextureNpotSupported();

                // ===========================================================
                // OpenGL ES 2.0 Extension #41: EXT_texture_filter_anisotropic
                // ===========================================================

                // API functions
                Bool IsExtTextureFilterAnisotropicSupported();
                Float GetMaxMaxTextureAnisotropy();

                // Constants
                enum
                {
                    TEXTURE_MAX_ANISOTROPY_EXT                  = 0x84FE,
                    MAX_TEXTURE_MAX_ANISOTROPY_EXT              = 0x84FF
                };
                
                // ==============================================
                // OpenGL ES 2.0 Extension #43: OES_depth_texture
                // ==============================================

                // API functions
                Bool IsOesDepthTextureSupported();

                // =====================================================
                // OpenGL ES 2.0 Extension #44: OES_packed_depth_stencil
                // =====================================================

                // API functions
                Bool IsOesPackedDepthStencilSupported();

                // Constants
                enum
                {
                    DEPTH_STENCIL_OES       = 0x84F9,
                    UNSIGNED_INT_24_8_OES   = 0x84FA,
                    DEPTH24_STENCIL8_OES    = 0x88F0
                };

                // =========================================================
                // OpenGL ES 2.0 Extension #49: EXT_texture_compression_dxt1
                // =========================================================

                // API functions
                Bool IsExtTextureCompressionDxt1Supported();

                // Constants
                enum
                {
                    COMPRESSED_RGB_S3TC_DXT1_EXT  = 0x83F0,
                    COMPRESSED_RGBA_S3TC_DXT1_EXT = 0x83F1
                };
                
                // ========================================================
                // OpenGL ES 2.0 Extension #51: EXT_texture_format_BGRA8888
                // ========================================================

                // API functions
                Bool IsExtTextureFormatBgra8888Supported();

                // Constants
                enum
                {
                    BGRA_EXT = 0x80E1
                };
                
                // ==========================================================
                // OpenGL ES 2.0 Extension #54: IMG_texture_compression_pvrtc
                // ==========================================================

                // API functions
                Bool IsImgTextureCompressionPvrtcSupported();

                // Constants
                enum
                {
                    COMPRESSED_RGB_PVRTC_4BPPV1_IMG     = 0x8C00,
                    COMPRESSED_RGB_PVRTC_2BPPV1_IMG     = 0x8C01,
                    COMPRESSED_RGBA_PVRTC_4BPPV1_IMG    = 0x8C02,
                    COMPRESSED_RGBA_PVRTC_2BPPV1_IMG    = 0x8C03
                };

                // ====================================================
                // OpenGL ES 2.0 Extension #64: EXT_discard_framebuffer
                // ====================================================

                // API functions
                Bool IsExtDiscardFramebufferSupported();

                void DiscardFramebufferEXT(UInt32 target, UInt32 numAttachments, const UInt32* attachments);

                // Constants
                enum
                {
                    COLOR_EXT                           = 0x1800,
                    DEPTH_EXT                           = 0x1801,
                    STENCIL_EXT                         = 0x1802,
                };

                // ====================================================
                // OpenGL ES 2.0 Extension #71: OES_vertex_array_object
                // ====================================================

                // API functions
                Bool IsOesVertexArrayObjectSupported();
                
                void BindVertexArrayOES(UInt32 array);
                void DeleteVertexArraysOES(SInt32 n, const UInt32* arrays);
                void GenVertexArraysOES(SInt32 n, UInt32* arrays);
                UInt8 IsVertexArrayOES(UInt32 array);
                
                // Constants
                enum
                {
                    VERTEX_ARRAY_BINDING_OES = 0x85B5
                };

                // ===================================================
                // OpenGL ES 2.0 Extension #77: EXT_shader_texture_lod
                // ===================================================

                // API functions
                Bool IsExtShaderTextureLodSupported();
                
                // ==========================================================
                // OpenGL ES 2.0 Extension #79: APPLE_texture_format_BGRA8888
                // ==========================================================

                // API functions
                Bool IsAppleTextureFormatBgra8888Supported();

                // Constants
                enum
                {
                    //BGRA_EXT = 0x80E1     // same as in EXT_texture_format_BGRA8888 above
                    BGRA8_EXT = 0x93A1      // internalformat in TexStorage* calls
                };
                
                // ========================================================
                // OpenGL ES 2.0 Extension #97: EXT_color_buffer_half_float
                // ========================================================

                // API functions
                Bool IsExtColorBufferHalfFloatSupported();

                // Constants
                enum
                {
                    RGBA16F_EXT                                  = 0x881A,
                    RGB16F_EXT                                   = 0x881B,
                    RG16F_EXT                                    = 0x822F,
                    R16F_EXT                                     = 0x822D
                };


                // =================================================
                // OpenGL ES 2.0 Extension #102: EXT_shadow_samplers
                // =================================================

                // API functions
                Bool IsExtShadowSamplersSupported();

                // Constants
                enum
                {
                    TEXTURE_COMPARE_MODE_EXT    = 0x884C,
                    TEXTURE_COMPARE_FUNC_EXT    = 0x884D,
                    COMPARE_REF_TO_TEXTURE_EXT  = 0x884E,
                    SAMPLER_2D_SHADOW_EXT       = 0x8B62
                };

                // ============================================
                // OpenGL ES 2.0 Extension #103: EXT_texture_rg
                // ============================================

                // API functions
                Bool IsExtTextureRgSupported();

                // Constants
                enum
                {
                    RED_EXT                 = 0x1903,
                    RG_EXT                  = 0x8227,
                    R8_EXT                  = 0x8229,
                    RG8_EXT                 = 0x822B
                };

                // ======================================
                // OpenGL ES 2.0 Extension #105: EXT_sRGB
                // ======================================

                // API functions
                Bool IsExtSRgbSupported();

                // Constants
                enum
                {
                    SRGB_EXT                                    = 0x8C40,
                    SRGB_ALPHA_EXT                              = 0x8C42,
                    SRGB8_ALPHA8_EXT                            = 0x8C43,
                    FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING_EXT   = 0x8210
                };
                
                // ===========================================================
                // OpenGL ES 2.0 Extension #111: ANGLE_texture_compression_dxt
                // ===========================================================

                // API functions
                Bool IsAngleTextureCompressionDxt1Supported();
                Bool IsAngleTextureCompressionDxt3Supported();
                Bool IsAngleTextureCompressionDxt5Supported();

                // Constants
                enum
                {
                    COMPRESSED_RGB_S3TC_DXT1_ANGLE  = 0x83F0,
                    COMPRESSED_RGBA_S3TC_DXT1_ANGLE = 0x83F1,
                    COMPRESSED_RGBA_S3TC_DXT3_ANGLE = 0x83F2,
                    COMPRESSED_RGBA_S3TC_DXT5_ANGLE = 0x83F3
                };
                
                // ==============================================================
                // OpenGL ES 2.0 Extension #117: KHR_texture_compression_astc_hdr
                // ==============================================================

                // API functions
                Bool IsKhrTextureCompressionAstcHdrSupported();
                Bool IsKhrTextureCompressionAstcLdrSupported();

                // Constants
                enum
                {
                    COMPRESSED_RGBA_ASTC_4x4_KHR            = 0x93B0,
                    COMPRESSED_RGBA_ASTC_5x4_KHR            = 0x93B1,
                    COMPRESSED_RGBA_ASTC_5x5_KHR            = 0x93B2,
                    COMPRESSED_RGBA_ASTC_6x5_KHR            = 0x93B3,
                    COMPRESSED_RGBA_ASTC_6x6_KHR            = 0x93B4,
                    COMPRESSED_RGBA_ASTC_8x5_KHR            = 0x93B5,
                    COMPRESSED_RGBA_ASTC_8x6_KHR            = 0x93B6,
                    COMPRESSED_RGBA_ASTC_8x8_KHR            = 0x93B7,
                    COMPRESSED_RGBA_ASTC_10x5_KHR           = 0x93B8,
                    COMPRESSED_RGBA_ASTC_10x6_KHR           = 0x93B9,
                    COMPRESSED_RGBA_ASTC_10x8_KHR           = 0x93BA,
                    COMPRESSED_RGBA_ASTC_10x10_KHR          = 0x93BB,
                    COMPRESSED_RGBA_ASTC_12x10_KHR          = 0x93BC,
                    COMPRESSED_RGBA_ASTC_12x12_KHR          = 0x93BD,

                    COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR    = 0x93D0,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR    = 0x93D1,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR    = 0x93D2,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR    = 0x93D3,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR    = 0x93D4,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR    = 0x93D5,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR    = 0x93D6,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR    = 0x93D7,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR   = 0x93D8,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR   = 0x93D9,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR   = 0x93DA,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR  = 0x93DB,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR  = 0x93DC,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR  = 0x93DD
                };
                
                // =============================================
                // OpenGL ES 2.0 Extension #127: NV_packed_float
                // =============================================

                // API functions
                Bool IsNvPackedFloatSupported();

                // Constants
                enum
                {
                    R11F_G11F_B10F_NV                            = 0x8C3A,
                    UNSIGNED_INT_10F_11F_11F_REV_NV              = 0x8C3B
                };

                // =========================================================
                // OpenGL ES 2.0 Extension #128: NV_texture_compression_s3tc
                // =========================================================

                // API functions
                Bool IsNvTextureCompressionS3tcSupported();

                // Constants
                enum
                {
                    COMPRESSED_RGB_S3TC_DXT1_NV     = 0x83F0,
                    COMPRESSED_RGBA_S3TC_DXT1_NV    = 0x83F1,
                    COMPRESSED_RGBA_S3TC_DXT3_NV    = 0x83F2,
                    COMPRESSED_RGBA_S3TC_DXT5_NV    = 0x83F3
                };
                
                // =================================================
                // OpenGL ES 2.0 Extension #133: GL_NV_texture_array
                // =================================================

                // API functions
                Bool IsNvTextureArraySupported();

                void TexImage3DNV(UInt32 target, SInt32 level, SInt32 internalformat, SInt32 width, SInt32 height, SInt32 depth, SInt32 border, UInt32 format, UInt32 type, const void* pixels);
                void TexSubImage3DNV(UInt32 target, SInt32 level, SInt32 xoffset, SInt32 yoffset, SInt32 zoffset, SInt32 width, SInt32 height, SInt32 depth, UInt32 format, UInt32 type, const void* pixels);
                void CopyTexSubImage3DNV(UInt32 target, SInt32 level, SInt32 xoffset, SInt32 yoffset, SInt32 zoffset, SInt32 x, SInt32 y, SInt32 width, SInt32 height);
                void CompressedTexImage3DNV(UInt32 target, SInt32 level, UInt32 internalformat, SInt32 width, SInt32 height, SInt32 depth, SInt32 border, SInt32 imageSize, const void* data);
                void CompressedTexSubImage3DNV(UInt32 target, SInt32 level, SInt32 xoffset, SInt32 yoffset, SInt32 zoffset, SInt32 width, SInt32 height, SInt32 depth, UInt32 format, SInt32 imageSize, const void* data);
                void FramebufferTextureLayerNV(UInt32 target, UInt32 attachment, UInt32 texture, SInt32 level, SInt32 layer);

                // Constants
                enum
                {
                    TEXTURE_2D_ARRAY_NV                             = 0x8C1A,
                    TEXTURE_BINDING_2D_ARRAY_NV                     = 0x8C1D,
                    MAX_ARRAY_TEXTURE_LAYERS_NV                     = 0x88FF,
                    FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_NV         = 0x8CD4,
                    SAMPLER_2D_ARRAY_NV                             = 0x8DC1,
                    UNPACK_SKIP_IMAGES_NV                           = 0x806D,
                    UNPACK_IMAGE_HEIGHT_NV                          = 0x806E
                };

                // ========================================================
                // OpenGL ES 2.0 Extension #136: OES_depth_texture_cube_map
                // ========================================================

                // API functions
                Bool IsOesDepthTextureCubeMapSupported();

                // ====================================================
                // OpenGL ES 2.0 Extension #137: EXT_color_buffer_float
                // ====================================================

                // API functions
                Bool IsExtColorBufferFloatSupported();
                
                // ====================================================
                // OpenGL ES 2.0 Extension #153: EXT_sRGB_write_control
                // ====================================================

                // API functions
                Bool IsExtSRgbWriteControlSupported();

                // Constants
                enum
                {
                    FRAMEBUFFER_SRGB_EXT                        = 0x8DB9
                };
                
                // ==========================================================
                // OpenGL ES 2.0 Extension #154: EXT_texture_compression_s3tc
                // ==========================================================

                // API functions
                Bool IsExtTextureCompressionS3tcSupported();

                // Constants
                enum
                {
                    /* already defined in EXT_texture_compression_dxt1
                    COMPRESSED_RGB_S3TC_DXT1_EXT    = 0x83F0,
                    COMPRESSED_RGBA_S3TC_DXT1_EXT   = 0x83F1,
                     */
                    COMPRESSED_RGBA_S3TC_DXT3_EXT   = 0x83F2,
                    COMPRESSED_RGBA_S3TC_DXT5_EXT   = 0x83F3
                };
                
                // ============================================
                // OpenGL ES 2.0 Extension #155: EXT_pvrtc_sRGB
                // ============================================

                // API functions
                Bool IsExtPvrtcSRgbSupported();

                // Constants
                enum
                {
                    COMPRESSED_SRGB_PVRTC_2BPPV1_EXT       = 0x8A54,
                    COMPRESSED_SRGB_PVRTC_4BPPV1_EXT       = 0x8A55,
                    COMPRESSED_SRGB_ALPHA_PVRTC_2BPPV1_EXT = 0x8A56,
                    COMPRESSED_SRGB_ALPHA_PVRTC_4BPPV1_EXT = 0x8A57
                };

                // ==========================================================
                // OpenGL ES 2.0 Extension #162: OES_texture_compression_astc
                // ==========================================================

                // API functions
                Bool IsOesTextureCompressionAstcSupported();

                // Constants
                enum
                {
                    /* already defined in KHR_texture_compression_astc_hdr
                    COMPRESSED_RGBA_ASTC_4x4_KHR            = 0x93B0,
                    COMPRESSED_RGBA_ASTC_5x4_KHR            = 0x93B1,
                    COMPRESSED_RGBA_ASTC_5x5_KHR            = 0x93B2,
                    COMPRESSED_RGBA_ASTC_6x5_KHR            = 0x93B3,
                    COMPRESSED_RGBA_ASTC_6x6_KHR            = 0x93B4,
                    COMPRESSED_RGBA_ASTC_8x5_KHR            = 0x93B5,
                    COMPRESSED_RGBA_ASTC_8x6_KHR            = 0x93B6,
                    COMPRESSED_RGBA_ASTC_8x8_KHR            = 0x93B7,
                    COMPRESSED_RGBA_ASTC_10x5_KHR           = 0x93B8,
                    COMPRESSED_RGBA_ASTC_10x6_KHR           = 0x93B9,
                    COMPRESSED_RGBA_ASTC_10x8_KHR           = 0x93BA,
                    COMPRESSED_RGBA_ASTC_10x10_KHR          = 0x93BB,
                    COMPRESSED_RGBA_ASTC_12x10_KHR          = 0x93BC,
                    COMPRESSED_RGBA_ASTC_12x12_KHR          = 0x93BD,

                    COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR    = 0x93D0,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR    = 0x93D1,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR    = 0x93D2,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR    = 0x93D3,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR    = 0x93D4,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR    = 0x93D5,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR    = 0x93D6,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR    = 0x93D7,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR   = 0x93D8,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR   = 0x93D9,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR   = 0x93DA,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR  = 0x93DB,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR  = 0x93DC,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR  = 0x93DD,
                     */

                    COMPRESSED_RGBA_ASTC_3x3x3_OES          = 0x93C0,
                    COMPRESSED_RGBA_ASTC_4x3x3_OES          = 0x93C1,
                    COMPRESSED_RGBA_ASTC_4x4x3_OES          = 0x93C2,
                    COMPRESSED_RGBA_ASTC_4x4x4_OES          = 0x93C3,
                    COMPRESSED_RGBA_ASTC_5x4x4_OES          = 0x93C4,
                    COMPRESSED_RGBA_ASTC_5x5x4_OES          = 0x93C5,
                    COMPRESSED_RGBA_ASTC_5x5x5_OES          = 0x93C6,
                    COMPRESSED_RGBA_ASTC_6x5x5_OES          = 0x93C7,
                    COMPRESSED_RGBA_ASTC_6x6x5_OES          = 0x93C8,
                    COMPRESSED_RGBA_ASTC_6x6x6_OES          = 0x93C9,

                    COMPRESSED_SRGB8_ALPHA8_ASTC_3x3x3_OES  = 0x93E0,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_4x3x3_OES  = 0x93E1,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x3_OES  = 0x93E2,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x4_OES  = 0x93E3,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_5x4x4_OES  = 0x93E4,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x4_OES  = 0x93E5,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x5_OES  = 0x93E6,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_6x5x5_OES  = 0x93E7,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x5_OES  = 0x93E8,
                    COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x6_OES  = 0x93E9
                };
                
                // ===========================================================
                // OpenGL ES 2.0 Extension #184: GL_EXT_texture_cube_map_array
                // ===========================================================

                // API functions
                Bool IsExtTextureCubeMapArraySupported();

                // Constants
                enum
                {
                    TEXTURE_CUBE_MAP_ARRAY_EXT                      = 0x9009,
                    TEXTURE_BINDING_CUBE_MAP_ARRAY_EXT              = 0x900A,
                    SAMPLER_CUBE_MAP_ARRAY_EXT                      = 0x900C,
                    SAMPLER_CUBE_MAP_ARRAY_SHADOW_EXT               = 0x900D,
                    INT_SAMPLER_CUBE_MAP_ARRAY_EXT                  = 0x900E,
                    UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_EXT         = 0x900F,
                    IMAGE_CUBE_MAP_ARRAY_EXT                        = 0x9054,
                    INT_IMAGE_CUBE_MAP_ARRAY_EXT                    = 0x905F,
                    UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT           = 0x906A
                };

                // =============================================================
                // OpenGL ES 2.0 Extension #194: APPLE_color_buffer_packed_float
                // =============================================================

                // API functions
                Bool IsAppleColorBufferPackedFloatSupported();
                
                // ========================================================
                // OpenGL ES 2.0 Extension #195: APPLE_texture_packed_float
                // ========================================================

                // API functions
                Bool IsAppleTexturePackedFloatSupported();

                // Constants
                enum
                {
                    UNSIGNED_INT_10F_11F_11F_REV_APPLE              = 0x8C3B,
                    UNSIGNED_INT_5_9_9_9_REV_APPLE                  = 0x8C3E,
                    R11F_G11F_B10F_APPLE                            = 0x8C3A,
                    RGB9_E5_APPLE                                   = 0x8C3D
                };

                // ===========================================================
                // OpenGL ES 2.0 Extension #217: GL_OES_texture_cube_map_array
                // ===========================================================

                // API functions
                Bool IsOesTextureCubeMapArraySupported();

                // Constants
                enum
                {
                    TEXTURE_CUBE_MAP_ARRAY_OES                      = 0x9009,
                    TEXTURE_BINDING_CUBE_MAP_ARRAY_OES              = 0x900A,
                    SAMPLER_CUBE_MAP_ARRAY_OES                      = 0x900C,
                    SAMPLER_CUBE_MAP_ARRAY_SHADOW_OES               = 0x900D,
                    INT_SAMPLER_CUBE_MAP_ARRAY_OES                  = 0x900E,
                    UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_OES         = 0x900F,
                    IMAGE_CUBE_MAP_ARRAY_OES                        = 0x9054,
                    INT_IMAGE_CUBE_MAP_ARRAY_OES                    = 0x905F,
                    UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_OES           = 0x906A
                };
                
                // ==========================================================
                // OpenGL ES 2.0 Extension #286: EXT_texture_compression_rgtc
                // ==========================================================

                // API functions
                Bool IsExtTextureCompressionRgtcSupported();

                // Constants
                enum
                {
                    COMPRESSED_RED_RGTC1_EXT                       = 0x8DBB,
                    COMPRESSED_SIGNED_RED_RGTC1_EXT                = 0x8DBC,
                    COMPRESSED_RED_GREEN_RGTC2_EXT                 = 0x8DBD,
                    COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT          = 0x8DBE
                };
                
                // ==========================================================
                // OpenGL ES 2.0 Extension #287: EXT_texture_compression_bptc
                // ==========================================================

                // API functions
                Bool IsExtTextureCompressionBptcSupported();

                // Constants
                enum
                {
                    COMPRESSED_RGBA_BPTC_UNORM_EXT                 = 0x8E8C,
                    COMPRESSED_SRGB_ALPHA_BPTC_UNORM_EXT           = 0x8E8D,
                    COMPRESSED_RGB_BPTC_SIGNED_FLOAT_EXT           = 0x8E8E,
                    COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_EXT         = 0x8E8F
                };
                
                // ===============================================================
                // OpenGL ES 2.0 Extension #289: EXT_texture_compression_s3tc_srgb
                // ===============================================================

                // API functions
                Bool IsExtTextureCompressionS3tcSrgbSupported();

                // Constants
                enum
                {
                    COMPRESSED_SRGB_S3TC_DXT1_EXT                  = 0x8C4C,
                    COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT            = 0x8C4D,
                    COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT            = 0x8C4E,
                    COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT            = 0x8C4F
                };
                
                // ======================================================
                // EXT_framebuffer_multisample   / EXT_framebuffer_blit
                // ANGLE_framebuffer_multisample / ANGLE_framebuffer_blit
                // NV_framebuffer_multisample    / NV_framebuffer_blit
                // APPLE_framebuffer_multisample
                // ======================================================

                // API functions
                Bool IsFramebufferMultisampleSupported();

                void RenderbufferStorageMultisample(UInt32 target, UInt32 samples, UInt32 internalformat, UInt32 width, UInt32 height);
                void ResolveMultisampleFramebuffer(UInt32 width, UInt32 height);

                // Constants
                enum
                {
                    RENDERBUFFER_SAMPLES                        = 0x8CAB,
                    FRAMEBUFFER_INCOMPLETE_MULTISAMPLE          = 0x8D56,
                    MAX_SAMPLES                                 = 0x8D57,
                    READ_FRAMEBUFFER                            = 0x8CA8,
                    DRAW_FRAMEBUFFER                            = 0x8CA9,
                    DRAW_FRAMEBUFFER_BINDING                    = 0x8CA6, // alias FRAMEBUFFER_BINDING_EXT
                    READ_FRAMEBUFFER_BINDING                    = 0x8CAA,
                };
            }
        }
    }
}

#endif  // __MURL_SYSTEM_OPENGL_ES20_H__

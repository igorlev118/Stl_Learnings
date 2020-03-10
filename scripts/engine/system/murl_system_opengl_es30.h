// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_SYSTEM_OPENGL_ES30_H__
#define __MURL_SYSTEM_OPENGL_ES30_H__

#include "murl_system_opengl_es20.h"

namespace Murl
{
    namespace System
    {
        namespace OpenGl
        {
            namespace Es30
            {
                // Startup/Shutdown code
                Bool Init(Bool enableChecks);
                Bool DeInit();

                // Platform-specific utility functions
                Bool GetTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);
                Bool GetColorTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);
                Bool GetDepthTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);
                Bool GetStencilTextureFormatAndType(IEnums::PixelFormat pixelFormat, UInt32& internal, UInt32& format, UInt32& type);

                Bool ApplyAdditionalTextureFormatParameters(UInt32 target, IEnums::PixelFormat pixelFormat);

                String PreprocessVertexShaderSource(const String& source);
                String PreprocessFragmentShaderSource(const String& source);

                // ==================
                // OpenGL ES 3.0 Core
                // ==================

                // API Functions
                void BindVertexArray(UInt32 array);
                void DeleteVertexArrays(SInt32 n, const UInt32* arrays);
                void GenVertexArrays(SInt32 n, UInt32* arrays);
                UInt8 IsVertexArray(UInt32 array);

                // Constants
                enum
                {
                    // Internal texture formats
                    R8                              = 0x8229,
                    RG8                             = 0x822B,
                    RGB8                            = 0x8051,
                    RGBA8                           = 0x8058,
                    RGB565                          = 0x8D62,
                    RGB5_A1                         = 0x8057,
                    RGBA4                           = 0x8056,
                    SRGB8                           = 0x8C41,
                    SRGB8_ALPHA8                    = 0x8C43,

                    R16F                            = 0x822D,
                    RG16F                           = 0x822F,
                    RGB16F                          = 0x881B,
                    RGBA16F                         = 0x881A,

                    R32F                            = 0x822E,
                    RG32F                           = 0x8230,
                    RGB32F                          = 0x8815,
                    RGBA32F                         = 0x8814,

                    R11F_G11F_B10F                  = 0x8C3A,

                    DEPTH_COMPONENT16               = 0x81A5,
                    DEPTH_COMPONENT24               = 0x81A6,
                    DEPTH_COMPONENT32F              = 0x8CAC,

                    DEPTH24_STENCIL8                = 0x88F0,
                    DEPTH32F_STENCIL8               = 0x8CAD,

                    // Texture formats
                    RED                             = 0x1903,
                    RG                              = 0x8227,

                    DEPTH_STENCIL                   = 0x84F9,

                    // Texture types
                    HALF_FLOAT                      = 0x140B,
                    UNSIGNED_INT_10F_11F_11F_REV    = 0x8C3B,
                    UNSIGNED_INT_24_8               = 0x84FA,
                    FLOAT_32_UNSIGNED_INT_24_8_REV  = 0x8DAD

                };
            }
        }
    }
}

#endif  // __MURL_SYSTEM_OPENGL_ES30_H__

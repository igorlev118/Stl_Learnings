// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_ENUMS_GRAPH_H__
#define __MURL_I_ENUMS_GRAPH_H__

#include "murl_enum.h"

namespace Murl
{
    namespace IEnums
    {
        /**
         * @addtogroup MurlGraphEnumerations
         * @brief Graph items enumerations.
         * @{
         */

        /**
         * @brief Limits for rendering slots.
         */
        enum Limits
        {
            /// Maximum number of material slots.
            NUM_MATERIAL_SLOTS = 256,
            /// Maximum number of parameters slots.
            NUM_PARAMETERS_SLOTS = 256,
            /// Maximum number of texture slots.
            NUM_TEXTURE_SLOTS = 256,
            /// Maximum number of vertices slots.
            NUM_VERTICES_SLOTS = 256,
            /// Maximum number of light slots.
            NUM_LIGHT_SLOTS = 256,
            /// Maximum number of surface slots.
            NUM_SURFACE_SLOTS = 256,
            /// Maximum number of island slots.
            NUM_ISLAND_SLOTS = 1,
            /// Maximum number of camera slots.
            NUM_CAMERA_SLOTS = 8,
            /// Maximum number of listener slots.
            NUM_LISTENER_SLOTS = 1,
            /// Maximum number of video culler slots.
            NUM_VIDEO_CULLER_SLOTS = 8,
            /// Maximum number of audio culler slots.
            NUM_AUDIO_CULLER_SLOTS = 1,
            /// Maximum number of anchor slots.
            NUM_ANCHOR_SLOTS = 16,

            /// Maximum number of layers per camera
            MAX_LAYERS = 256,

            /// Maximum number of texture array layers
            MAX_TEXTURE_LAYERS = 1024,

            // Maximum number of shadow cascades
            MAX_SHADOW_CASCADES = 4
        };

        /**
         * @brief Available mip-map level generators.
         */
        enum MipMapGenerationMode
        {
            /// Use default method.
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, DEFAULT)

            /// Do not create mip levels.
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, NONE)

            /// Create mip levels by simple pixel averaging (fast, but not not gamma-correct).
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, FAST)
            /// Perform gamma-correct mip-level generation (slower)
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, GAMMA_CORRECT)

            /// Fast mode, replacing any present mip levels
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, REPLACE_FAST)
            /// Gamma-correct mode, replacing any present mip levels
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, REPLACE_GAMMA_CORRECT)

            /// Fast mode, preserving any present mip levels (equivalent to FAST)
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, PRESERVE_FAST)
            /// Gamma-correct mode, preserving any present mip levels (equivalent to GAMMA_CORRECT)
            MURL_DECLARE_ENUM_VALUE(MIP_MAP_GENERATION_MODE, PRESERVE_GAMMA_CORRECT)

            NUM_MIP_MAP_GENERATION_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(MipMapGenerationMode)

        /**
         * @brief Available pixel formats to use for images and textures.
         */
        enum PixelFormat
        {
            /// Undefined format
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, UNDEFINED)

            /// 8 bit integer luminance only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, L8)
            /// 8 bit integer alpha only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, A8)
            /// 16 bit integer, with 8 luminance bits and 8 alpha bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, L8_A8)
            /// 8 bit integer red only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, R8)
            /// 16 bit integer, with 8 red bits and 8 green bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, R8_G8)
            /// 24 bit integer RGB, with 8 bits per component.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, R8_G8_B8)
            /// 16 bit integer RGB, with 5 red bits, 6 green bits and 5 blue bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, R5_G6_B5)
            /// 32 bit integer RGBA, with 8 bits per component (always available).
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, R8_G8_B8_A8)
            /// 32 bit integer BGRA, with 8 bits per component (on certain platforms).
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, B8_G8_R8_A8)
            /// 32 bit integer ABGR, with 8 bits per component (on certain platforms).
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, A8_B8_G8_R8)
            /// 32 bit integer ARGB, with 8 bits per component (on certain platforms).
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, A8_R8_G8_B8)
            /// 16 bit integer RGBA, with 5 red bits, 5 green bits, 5 blue bits and 1 alpha bit.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, R5_G5_B5_A1)
            /// 16 bit integer RGBA, with 4 bits per component.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, R4_G4_B4_A4)

            /// 8 bit integer luminance only in sRGB color space.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, SL8)
            /// 16 bit integer, with 8 bits luminance in sRGB color space and 8 bits alpha.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, SL8_A8)
            /// 8 bit integer red only in sRGB color space
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, SR8)
            /// 16 bit integer, with 8 red and 8 green bits in sRGB color space.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, SR8_SG8)
            /// 24 bit integer sRGB, with 8 bits per component.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, SR8_SG8_SB8)
            /// 32 bit integer sRGB with Alpha, with 8 bits per component
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, SR8_SG8_SB8_A8)

            /// 16 bit half-float luminance only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, LF16)
            /// 16 bit half-float alpha only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, AF16)
            /// 32 bit half-float, with 16 luminance bits and 16 alpha bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, LF16_AF16)
            /// 16 bit half-float red only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF16)
            /// 32 bit half-float, with 16 red bits and 16 green bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF16_GF16)
            /// 48 bit half-float RGB, with 16 bits per component.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF16_GF16_BF16)
            /// 64 bit half-float RGBA, with 16 bits per component.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF16_GF16_BF16_AF16)

            /// 32 bit float luminance only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, LF32)
            /// 32 bit float alpha only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, AF32)
            /// 64 bit float, with 32 luminance bits and 32 alpha bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, LF32_AF32)
            /// 32 bit float red only.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF32)
            /// 64 bit float, with 32 red bits and 32 green bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF32_GF32)
            /// 96 bit float RGB, with 32 bits per component.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF32_GF32_BF32)
            /// 128 bit float RGBA, with 32 bits per component.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF32_GF32_BF32_AF32)

            // 32bit float RGB, with 11 bits for red and green, and 10 bits for blue
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RF11_GF11_BF10)

            /// 16 bit integer depth buffer format.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, D16)
            /// 32 bit integer depth buffer format.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, D32)

            /// 32 bit float depth buffer format.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, DF32)

            /// 8 bit integer stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, S8)

            /// 32 bit integer combined depth & stencil buffer format, with 24 depth bits and 8 stencil bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, D24_S8)

            /// 64 bit combined depth & stencil buffer format, with 32 float depth bits, 8 stencil bits and 24 unused bits.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, DF32_S8)

            // 8 bit integer luminance, used for multi-planar YUV streams.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, Y8)
            // 8 bit integer U chrominance, used for multi-planar YUV streams.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, U8)
            // 8 bit integer V chrominance, used for multi-planar YUV streams.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, V8)
            // 16 bit combined UV chrominance
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, U8_V8)
            // 16 bit combined VU chrominance
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, V8_U8)

            /// PVR compressed RGB, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_RGB_4BPPV1)
            /// PVR compressed RGB, with 2 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_RGB_2BPPV1)
            /// PVR compressed RGBA, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_RGBA_4BPPV1)
            /// PVR compressed RGBA, with 2 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_RGBA_2BPPV1)
            /// PVR compressed sRGB, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_SRGB_4BPPV1)
            /// PVR compressed sRGB, with 2 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_SRGB_2BPPV1)
            /// PVR compressed sRGB+A, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_SRGBA_4BPPV1)
            /// PVR compressed sRGB+A, with 2 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, PVRTC_SRGBA_2BPPV1)

            /// ETC1 compressed RGB, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC1_RGB_4BPP)

            /// ETC2 compressed red only with 4 bits per pixel, representing 11 bit unsigned color values.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_R11_4BPP)
            /// ETC2 compressed red only with 4 bits per pixel, representing 11 bit signed color values.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_SIGNED_R11_4BPP)
            /// ETC2 compressed red/green with 8 bits per pixel, representing 11 bit unsigned color values.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_RG11_8BPP)
            /// ETC2 compressed red/green with 8 bits per pixel, representing 11 bit signed color values.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_SIGNED_RG11_8BPP)
            /// ETC2 compressed RGB, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_RGB8_4BPP)
            /// ETC2 compressed sRGB, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_SRGB8_4BPP)
            /// ETC2 compressed RGB plus 1 bit alpha, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_RGB8_PUNCHTHROUGH_ALPHA1_4BPP)
            /// ETC2 compressed sRGB plus 1 bit alpha, with 4 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_SRGB8_PUNCHTHROUGH_ALPHA1_4BPP)
            /// ETC2 compressed RGBA, with 8 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_RGBA8_8BPP)
            /// ETC2 compressed sRGB plus Alpha, with 8 bits per pixel.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ETC2_SRGB8_ALPHA8_8BPP)

            /// ASTC compressed LDR RGBA, with a 4x4 block footprint (8 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_4X4)
            /// ASTC compressed LDR RGBA, with a 5x4 block footprint (6.4 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_5X4)
            /// ASTC compressed LDR RGBA, with a 5x5 block footprint (5.12 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_5X5)
            /// ASTC compressed LDR RGBA, with a 6x5 block footprint (4.27 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_6X5)
            /// ASTC compressed LDR RGBA, with a 6x6 block footprint (3.56 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_6X6)
            /// ASTC compressed LDR RGBA, with a 8x5 block footprint (3.2 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_8X5)
            /// ASTC compressed LDR RGBA, with a 8x6 block footprint (2.67 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_8X6)
            /// ASTC compressed LDR RGBA, with a 8x8 block footprint (2 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_8X8)
            /// ASTC compressed LDR RGBA, with a 10x5 block footprint (2.56 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_10X5)
            /// ASTC compressed LDR RGBA, with a 10x6 block footprint (2.13 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_10X6)
            /// ASTC compressed LDR RGBA, with a 10x8 block footprint (1.6 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_10X8)
            /// ASTC compressed LDR RGBA, with a 10x10 block footprint (1.28 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_10X10)
            /// ASTC compressed LDR RGBA, with a 12x10 block footprint (1.07 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_12X10)
            /// ASTC compressed LDR RGBA, with a 12x12 block footprint (0.89 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_RGBA_12X12)

            /// ASTC compressed LDR sRGB with Alpha, with a 4x4 block footprint (8 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_4X4)
            /// ASTC compressed LDR sRGB with Alpha, with a 5x4 block footprint (6.4 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_5X4)
            /// ASTC compressed LDR sRGB with Alpha, with a 5x5 block footprint (5.12 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_5X5)
            /// ASTC compressed LDR sRGB with Alpha, with a 6x5 block footprint (4.27 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_6X5)
            /// ASTC compressed LDR sRGB with Alpha, with a 6x6 block footprint (3.56 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_6X6)
            /// ASTC compressed LDR sRGB with Alpha, with a 8x5 block footprint (3.2 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_8X5)
            /// ASTC compressed LDR sRGB with Alpha, with a 8x6 block footprint (2.67 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_8X6)
            /// ASTC compressed LDR sRGB with Alpha, with a 8x8 block footprint (2 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_8X8)
            /// ASTC compressed LDR sRGB with Alpha, with a 10x5 block footprint (2.56 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_10X5)
            /// ASTC compressed LDR sRGB with Alpha, with a 10x6 block footprint (2.13 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_10X6)
            /// ASTC compressed LDR sRGB with Alpha, with a 10x8 block footprint (1.6 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_10X8)
            /// ASTC compressed LDR sRGB with Alpha, with a 10x10 block footprint (1.28 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_10X10)
            /// ASTC compressed LDR sRGB with Alpha, with a 12x10 block footprint (1.07 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_12X10)
            /// ASTC compressed LDR sRGB with Alpha, with a 12x12 block footprint (0.89 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_SRGB8_ALPHA8_12X12)

            /// ASTC compressed HDR RGBA, with a 4x4 block footprint (8 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_4X4)
            /// ASTC compressed HDR RGBA, with a 5x4 block footprint (6.4 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_5X4)
            /// ASTC compressed HDR RGBA, with a 5x5 block footprint (5.12 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_5X5)
            /// ASTC compressed HDR RGBA, with a 6x5 block footprint (4.27 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_6X5)
            /// ASTC compressed HDR RGBA, with a 6x6 block footprint (3.56 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_6X6)
            /// ASTC compressed HDR RGBA, with a 8x5 block footprint (3.2 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_8X5)
            /// ASTC compressed HDR RGBA, with a 8x6 block footprint (2.67 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_8X6)
            /// ASTC compressed HDR RGBA, with a 8x8 block footprint (2 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_8X8)
            /// ASTC compressed HDR RGBA, with a 10x5 block footprint (2.56 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_10X5)
            /// ASTC compressed HDR RGBA, with a 10x6 block footprint (2.13 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_10X6)
            /// ASTC compressed HDR RGBA, with a 10x8 block footprint (1.6 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_10X8)
            /// ASTC compressed HDR RGBA, with a 10x10 block footprint (1.28 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_10X10)
            /// ASTC compressed HDR RGBA, with a 12x10 block footprint (1.07 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_12X10)
            /// ASTC compressed HDR RGBA, with a 12x12 block footprint (0.89 bpp)
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, ASTC_HDR_RGBA_12X12)

            /// BC1 (a.k.a. DXT1) compressed RGB, with 8 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC1_RGB_4BPP)
            /// BC1 (a.k.a. DXT1) compressed sRGB, with 8 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC1_SRGB_4BPP)
            /// BC1 (a.k.a. DXT1) compressed RGB plus 1 bit alpha, with 8 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC1_RGBA_4BPP)
            /// BC1 (a.k.a. DXT1) compressed sRGB plus 1 bit alpha, with 8 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC1_SRGBA_4BPP)
            /// BC2 (a.k.a. DXT3) compressed RGBA, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC2_RGBA_8BPP)
            /// BC2 (a.k.a. DXT3) compressed sRGBA, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC2_SRGBA_8BPP)
            /// BC3 (a.k.a. DXT5) compressed RGBA, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC3_RGBA_8BPP)
            /// BC3 (a.k.a. DXT5) compressed sRGBA, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC3_SRGBA_8BPP)
            /// BC4 compressed red only, with 8 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC4_R_4BPP)
            /// BC5 compressed red/green, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC5_RG_8BPP)
            /// BC6 compressed signed float RGB, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC6_RGB_SF_8BPP)
            /// BC6 compressed unsigned float RGB, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC6_RGB_UF_8BPP)
            /// BC7 compressed RGBA, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC7_RGBA_8BPP)
            /// BC7 compressed sRGB plus Alpha, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, BC7_SRGBA_8BPP)

            /// RGTC compressed unsigned red only, with 8 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RGTC_R_U_4BPP)
            /// RGTC compressed signed red only, with 8 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RGTC_R_S_4BPP)
            /// RGTC compressed unsigned red/green, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RGTC_RG_U_8BPP)
            /// RGTC compressed signed red/green, with 16 bytes per block.
            MURL_DECLARE_ENUM_VALUE(PIXEL_FORMAT, RGTC_RG_S_8BPP)

            NUM_PIXEL_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(PixelFormat)
        /**
         * @brief Query if a given pixel format uses hardware compression.
         * @param pixelFormat The pixel format to check.
         * @return true if compression is used.
         */
        Bool IsPixelFormatCompressed(PixelFormat pixelFormat);
        /**
         * @brief Query if a given pixel format stores alpha values.
         * @param pixelFormat The pixel format to check.
         * @return true if alpha values are stored.
         */
        Bool IsPixelFormatStoringAlphaValues(PixelFormat pixelFormat);
        /**
         * @brief Query if a given pixel format stores color and/or alpha values.
         * @param pixelFormat The pixel format to check.
         * @return true if color values are stored.
         */
        Bool IsPixelFormatStoringColorValues(PixelFormat pixelFormat);
        /**
         * @brief Query if a given pixel format stores linear color values.
         * This method returns true for all pixel formats that store linear color
         * values. This is the case for all the sRGB integer formats (e.g. SR8_SG8_SB8_A8)
         * and all floating point formats (e.g. RF32_GF32_BF32).
         * @param pixelFormat The pixel format to check.
         * @return true if color values are present and they are linear.
         */
        Bool IsPixelFormatStoringLinearColorValues(PixelFormat pixelFormat);
        /**
         * @brief Query if a given pixel format stores depth values.
         * In case of the combined IEnums::PIXEL_FORMAT_D24_S8 and IEnums::PIXEL_FORMAT_DF32_S8 
         * formats, both this function and IsPixelFormatStoringStencilValues() will return true.
         * @param pixelFormat The pixel format to check.
         * @return true if depth values are stored.
         */
        Bool IsPixelFormatStoringDepthValues(PixelFormat pixelFormat);
        /**
         * @brief Query if a given pixel format stores stencil values.
         * In case of the combined IEnums::PIXEL_FORMAT_D24_S8 and IEnums::PIXEL_FORMAT_DF32_S8
         * formats, both this function and IsPixelFormatStoringDepthValues() will return true.
         * @param pixelFormat The pixel format to check.
         * @return true if stencil values are stored.
         */
        Bool IsPixelFormatStoringStencilValues(PixelFormat pixelFormat);
        /**
         * @brief Query the number of bytes per pixel for a given pixel format.
         * In case of a compressed format, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The number of bytes per pixel.
         */
        UInt32 GetPixelFormatByteSize(PixelFormat pixelFormat);
        /**
         * @brief Query the size in bytes of a single color component for a given pixel format.
         * In case of a compressed format, or a format that does not store components that are
         * multiples of a single byte (such as PIXEL_FORMAT_R5_G6_B5), this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The number of bytes per component.
         */
        UInt32 GetPixelFormatComponentByteSize(PixelFormat pixelFormat);
        /**
         * @brief Query the number of color components per pixel for a given pixel format.
         * In case of a compressed format, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The number of components per pixel.
         */
        UInt32 GetPixelFormatNumberOfComponents(PixelFormat pixelFormat);
        /**
         * @brief Query the required number of bytes in a single line for a given width and pixel format.
         * This function returns the minimum required line pitch, without any extra padding.
         * In case of a compressed format, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @param sizeX The width in pixels.
         * @return The number of bytes per line.
         */
        UInt32 GetPixelFormatBytesPerLine(PixelFormat pixelFormat, UInt32 sizeX);
        /**
         * @brief Query the required number of surface data bytes for a given width, height and pixel format.
         * This function returns the minimum required surface data size, without any extra padding.
         * @param pixelFormat The pixel format to query.
         * @param sizeX The width in pixels.
         * @param sizeY The height in pixels.
         * @return The number of data bytes needed for a surface.
         */
        UInt32 GetPixelFormatBytesPerSurface(PixelFormat pixelFormat, UInt32 sizeX, UInt32 sizeY);
        /**
         * @brief Query the minimum number of required horizontal blocks for a compressed pixel format.
         * For uncompressed formats, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The minimum number of horizontal blocks required, or 0 for an uncompressed format.
         */
        UInt32 GetPixelFormatMinNumberOfBlocksX(PixelFormat pixelFormat);
        /**
         * @brief Query the minimum number of required vertical blocks for a compressed pixel format.
         * For uncompressed formats, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The minimum number of vertical blocks required, or 0 for an uncompressed format.
         */
        UInt32 GetPixelFormatMinNumberOfBlocksY(PixelFormat pixelFormat);
        /**
         * @brief Query the horizontal block size in pixels for a compressed pixel format.
         * For uncompressed formats, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The horizontal block size in pixels, or 0 for an uncompressed format.
         */
        UInt32 GetPixelFormatCompressedBlockSizeX(PixelFormat pixelFormat);
        /**
         * @brief Query the vertical block size in pixels for a compressed pixel format.
         * For uncompressed formats, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The vertical block size in pixels, or 0 for an uncompressed format.
         */
        UInt32 GetPixelFormatCompressedBlockSizeY(PixelFormat pixelFormat);
        /**
         * @brief Query the block size in bytes for a compressed pixel format.
         * For uncompressed formats, this function returns 0.
         * @param pixelFormat The pixel format to query.
         * @return The block size in bytes, or 0 for an uncompressed format.
         */
        UInt32 GetPixelFormatCompressedBytesPerBlock(PixelFormat pixelFormat);

        /**
         * @brief Available video stream formats.
         */
        enum VideoStreamFormat
        {
            /// The default formats
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, DEFAULT)

            /// Raw format, i.e. uncompressed pixel values.
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, RAW)
            /// JPEG format.
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, JPG)
            /// PNG format.
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, PNG)
            /// PowerVR texture compression format (PVRTC).
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, PVR)
            /// WEBP format.
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, WEBP)
            /// DirectX surface (DDS) format.
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, DDS)
            /// Khronos texture (KTX) format.
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, KTX)
            /// ASTC format.
            MURL_DECLARE_ENUM_VALUE(VIDEO_STREAM_FORMAT, ASTC)

            NUM_VIDEO_STREAM_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(VideoStreamFormat)

        /**
         * @brief Available formats for stand-alone color buffers.
         * These formats are used only for stand-alone color buffers used in a multisample
         * frame buffer. If rendering to a color texture is desired, one of the IEnums::PixelFormat 
         * enum values must be used for that texture.
         */
        enum ColorBufferFormat
        {
            /// Undefined color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, UNDEFINED)

            /// No format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, NONE)
            /// Any suitable color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, GENERIC)

            /// Explicit 8 bit integer red only color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, R8)                    // GL_EXT_texture_rg,               GL_R8_EXT
            /// Explicit 8 bit integer red/green color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, R8_G8)                 // GL_EXT_texture_rg,               GL_RG8_EXT
            /// Explicit 8 bit integer RGB color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, R8_G8_B8)              // GL_OES_rgb8_rgba8,               GL_RGB8_OES
            /// Explicit integer 5:6:5 RGB color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, R5_G6_B5)              // Core,                            GL_RGB565
            /// Explicit 8 bit integer RGBA color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, R8_G8_B8_A8)           // GL_OES_rgb8_rgba8,               GL_RGBA8_OES
            /// Explicit integer 5:5:5 RGB color buffer format with 1 bit alpha.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, R5_G5_B5_A1)           // Core,                            GL_RGB5_A1
            /// Explicit 4 bit integer RGBA color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, R4_G4_B4_A4)           // Core,                            GL_RGBA4

            /// Explicit sRGB 8 bit integer red only color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, SR8)                   //
            /// Explicit sRGB 8 bit integer red/green color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, SR8_SG8)               //
            /// Explicit sRGB 8 bit integer RGB color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, SR8_SG8_SB8)           // GL_EXT_sRGB_write_control
            /// Explicit sRGB 8 bit integer RGBA color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, SR8_SG8_SB8_A8)        // GL_EXT_sRGB_write_control

            /// Explicit 16 bit half float red only color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF16)                  // GL_EXT_color_buffer_half_float,  GL_RGBA16F_EXT
            /// Explicit 16 bit half float red/green color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF16_GF16)             // GL_EXT_color_buffer_half_float,  GL_RGB16F_EXT
            /// Explicit 16 bit half float RGB color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF16_GF16_BF16)        // GL_EXT_color_buffer_half_float,  GL_RG16F_EXT
            /// Explicit 16 bit half float RGBA color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF16_GF16_BF16_AF16)   // GL_EXT_color_buffer_half_float,  GL_R16F_EXT

            /// Explicit 32 bit float red only color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF32)                  // GL_EXT_color_buffer_float,       GL_R32F
            /// Explicit 32 bit float red/green color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF32_GF32)             // GL_EXT_color_buffer_float,       GL_RG32F
            /// Explicit 32 bit float RGB color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF32_GF32_BF32)        // GL_EXT_color_buffer_float,       ???
            /// Explicit 32 bit float RGBA color buffer format.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF32_GF32_BF32_AF32)   // GL_EXT_color_buffer_float,       GL_RGBA32F

            /// Explicit floating point RGB color buffer format, packed into a single 32 bit value.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_FORMAT, RF11_GF11_BF10)        // GL_APPLE_color_buffer_packed_float

            NUM_COLOR_BUFFER_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(ColorBufferFormat)
        /**
         * @brief Select a color buffer format compatible to a given image pixel format.
         * @param pixelFormat The image pixel format.
         * @return A compatible color buffer format or IEnums::COLOR_BUFFER_FORMAT_UNDEFINED
         *      if there is no matching color buffer format.
         */
        ColorBufferFormat GetColorBufferFormatFromPixelFormat(PixelFormat pixelFormat);
        /**
         * @brief Select an image pixel format compatible to a given color buffer format.
         * @param colorBufferFormat The color buffer format.
         * @return A compatible image pixel format or IEnums::PIXEL_FORMAT_UNDEFINED if there
         *      is no matching image pixel format.
         */
        PixelFormat GetPixelFormatFromColorBufferFormat(ColorBufferFormat colorBufferFormat);


        /**
         * @brief Available formats for stand-alone depth buffers.
         * These formats are used only for stand-alone depth buffers; if rendering to
         * a depth texture is desired, one of the IEnums::PixelFormat enum values must be used
         * for that texture. To create a combined depth/stencil buffer, use the
         * IEnums::DEPTH_BUFFER_FORMAT_D24_S8 and IEnums::STENCIL_BUFFER_FORMAT_D24_S8 formats
         * (or their DF32 equivalents) in combination.
         */
        enum DepthBufferFormat
        {
            /// Undefined depth buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, UNDEFINED)

            /// No format; use this during frame buffer creation when no depth buffer is needed.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, NONE)
            /// Any suitable depth buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, GENERIC)

            /// Explicit 16 bit integer depth buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, D16)
            /// Explicit 24 bit integer depth buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, D24)
            /// Explicit 32 bit integer depth buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, D32)
            /// Explicit 32 bit float depth buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, DF32)
            /// Explicit 32 bit integer combined depth & stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, D24_S8)
            /// Explicit 64 bit combined depth & stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_FORMAT, DF32_S8)

            NUM_DEPTH_BUFFER_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(DepthBufferFormat)
        /**
         * @brief Select a depth buffer format compatible to a given image pixel format.
         * @param pixelFormat The image pixel format.
         * @return A compatible depth buffer format or IEnums::DEPTH_BUFFER_FORMAT_UNDEFINED
         *      if there is no matching depth buffer format.
         */
        DepthBufferFormat GetDepthBufferFormatFromPixelFormat(PixelFormat pixelFormat);
        /**
         * @brief Select an image pixel format compatible to a given depth buffer format.
         * @param depthBufferFormat The depth buffer format.
         * @return A compatible image pixel format or IEnums::PIXEL_FORMAT_UNDEFINED if there
         *      is no matching image pixel format.
         */
        PixelFormat GetPixelFormatFromDepthBufferFormat(DepthBufferFormat depthBufferFormat);

        /**
         * @brief Available formats for stand-alone stencil buffers.
         * These formats are used only for stand-alone stencil buffers; if rendering to
         * a stencil texture is desired, one of the IEnums::PixelFormat enum values must be used
         * for that texture. To create a combined depth/stencil buffer, use the
         * IEnums::DEPTH_BUFFER_FORMAT_D24_S8 and IEnums::STENCIL_BUFFER_FORMAT_D24_S8 formats
         * (or their DF32 equivalents) in combination.
         */
        enum StencilBufferFormat
        {
            /// Undefined stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_FORMAT, UNDEFINED)

            /// No format; use this during frame buffer creation when no stencil buffer is needed.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_FORMAT, NONE)
            /// Any suitable stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_FORMAT, GENERIC)

            /// Explicit 8 bit integer stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_FORMAT, S8)
            /// Explicit 32 bit integer combined depth & stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_FORMAT, D24_S8)
            /// Explicit 64 bit combined depth & stencil buffer format.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_FORMAT, DF32_S8)

            NUM_STENCIL_BUFFER_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(StencilBufferFormat)
        /**
         * @brief Select a stencil buffer format compatible to a given image pixel format.
         * @param pixelFormat The image pixel format.
         * @return A compatible stencil buffer format or IEnums::STENCIL_BUFFER_FORMAT_UNDEFINED
         *      if there is no matching stencil buffer format.
         */
        StencilBufferFormat GetStencilBufferFormatFromPixelFormat(PixelFormat pixelFormat);
        /**
         * @brief Select an image pixel format compatible to a given stencil buffer format.
         * @param stencilBufferFormat The stencil buffer format.
         * @return A compatible image pixel format or IEnums::PIXEL_FORMAT_UNDEFINED if there is
         *      no matching image pixel format.
         */
        PixelFormat GetPixelFormatFromStencilBufferFormat(StencilBufferFormat stencilBufferFormat);

        /**
         * @brief Available filter types for e.g. image scaling.
         */
        enum FilterType
        {
            /// Default filter type.
            MURL_DECLARE_ENUM_VALUE(FILTER_TYPE, DEFAULT)

            /// Nearest neighbor filter.
            MURL_DECLARE_ENUM_VALUE(FILTER_TYPE, NEAREST)
            /// Nearest neighbor filter.
            MURL_DECLARE_ENUM_VALUE(FILTER_TYPE, BOX)
            /// Nearest neighbor filter.
            MURL_DECLARE_ENUM_VALUE(FILTER_TYPE, BILINEAR)
            /// Nearest neighbor filter.
            MURL_DECLARE_ENUM_VALUE(FILTER_TYPE, GAUSSIAN)

            NUM_FILTER_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(FilterType)

        /**
         * @brief Available shader program types.
         */
        enum ShaderType
        {
            /// Undefined shader type.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_TYPE, NONE, 0)

            /// Vertex shader.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_TYPE, VERTEX,   (1 << 0))
            /// Fragment shader.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_TYPE, FRAGMENT, (1 << 1))

            // TODO: In the future: consider geometry/hull/domain shaders as well.

            /// All shaders combined.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_TYPE, ALL, SHADER_TYPE_VERTEX + SHADER_TYPE_FRAGMENT)

        };
        MURL_DECLARE_ENUM_ACCESSOR(ShaderType)

        /**
         * @brief Available shader variable types.
         */
        enum ShaderVariableType
        {
            /// Unknown type.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_TYPE, UNKNOWN)

            /// A simple constant to be used in both vertex and fragment shaders.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_TYPE, CONSTANT)
            /// A constant buffer containing one or more uniforms to be used in both vertex and fragment shaders.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_TYPE, CONSTANT_BUFFER)
            /// A single uniform variable.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_TYPE, UNIFORM)
            /// A vertex attribute variable used in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_TYPE, ATTRIBUTE)
            /// A varying variable, used as output of a vertex shader and input of a fragment shader.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_TYPE, VARYING)
            /// A texture (sampler) variable.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_TYPE, TEXTURE)

            NUM_SHADER_VARIABLE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ShaderVariableType)

        /**
         * @brief Available shader variable precision qualifiers.
         */
        enum ShaderVariablePrecision
        {
            /// Default precision.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_PRECISION, DEFAULT)

            /// Low precision.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_PRECISION, LOW)
            /// Medium precision.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_PRECISION, MEDIUM)
            /// High precision.
            MURL_DECLARE_ENUM_VALUE(SHADER_VARIABLE_PRECISION, HIGH)

            NUM_SHADER_VARIABLE_PRECISIONS
        };
        MURL_DECLARE_ENUM_ACCESSOR(ShaderVariablePrecision)

        /**
         * @brief Available shader languages.
         */
        enum ShaderLanguage
        {
            /// Undefined shader language.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, UNDEFINED,          0)

            /// Unknown GLSL|ES version
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, GLSL_ES_UNKNOWN,    1)
            /// GLSL|ES version 1.20 (OpenGL|ES 2.0)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, GLSL_ES_120,        2)
            /// GLSL|ES version 3.00 (OpenGL|ES 3.0+)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, GLSL_ES_300,        3)

            /// Unknown HLSL version
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_UNKNOWN,       257)
            /// HLSL shader model 2.0 (DirectX 9.0)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_20,            258)
            /// HLSL shader model 2.0a (DirectX 9.0a)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_20A,           259)
            /// HLSL shader model 2.0b (DirectX 9.0b)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_20B,           260)
            /// HLSL shader model 3.0 (DirectX 9.0c)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_30,            261)
            /// HLSL shader model 4.0, level 9.1 (DirectX 11.1 on WinPhone8)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_40_91,         262)
            /// HLSL shader model 4.0, level 9.2 (DirectX 11.1 on WinPhone8)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_40_92,         263)
            /// HLSL shader model 4.0, level 9.3 (DirectX 11.1 on WinPhone8)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_40_93,         264)
            /// HLSL shader model 4.0
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SHADER_LANGUAGE, HLSL_40,            265)
        };
        MURL_DECLARE_ENUM_ACCESSOR(ShaderLanguage)

        /**
         * @brief Available texture wrap modes.
         */
        enum TextureWrapMode
        {
            /// Undefined wrap mode
            MURL_DECLARE_ENUM_VALUE(TEXTURE_WRAP_MODE, UNDEFINED)

            /// Textures are clamped at their edge, i.e. texture coordinates are always in the range 0.0-1.0.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_WRAP_MODE, CLAMP_TO_EDGE)
            /// Textures are repeated (tiled).
            MURL_DECLARE_ENUM_VALUE(TEXTURE_WRAP_MODE, REPEAT)
            /// Textures are repeated (tiled), with every second tile mirrored.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_WRAP_MODE, MIRRORED_REPEAT)

            NUM_TEXTURE_WRAP_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextureWrapMode)

        /**
         * @brief Available texture filter modes for magnification & minification.
         */
        enum TextureFilter
        {
            /// Undefined texture filter.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_FILTER, UNDEFINED)

            /// No filter.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_FILTER, NONE)
            /// Nearest-neighbor filter.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_FILTER, NEAREST)
            /// Linear filter.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_FILTER, LINEAR)

            NUM_TEXTURE_FILTERS
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextureFilter)

        /**
         * @brief Available texture types.
         */
        enum TextureType
        {
            /// Default texture type.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TYPE, DEFAULT)

            /// A 2D texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TYPE, FLAT)
            /// A cube map texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TYPE, CUBE)
            /// A 3D volume texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TYPE, VOLUME)
            /// An array of 2D textures.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TYPE, FLAT_ARRAY)
            /// An array of cube map textures.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TYPE, CUBE_ARRAY)

            NUM_TEXTURE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextureType)

        /**
         * @brief Mask bits for additional texture sampler parameters.
         * The values in this enumeration are specified as a bit field so they
         * can be ORed together.
         */
        enum TextureFlagMaskBit
        {
            /// No bit set.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TEXTURE_FLAG_MASK_BIT, NONE, 0)

            /// The bit to indicate a shadow sampler.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TEXTURE_FLAG_MASK_BIT, SHADOW,   (1 << 0))
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextureFlagMaskBit)

        /**
         * @brief Data type for combined texture flag mask bits,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 TextureFlagMask;
        /// Combined texture flag mask bits for no flags.
        static const TextureFlagMask TEXTURE_FLAG_MASK_NONE = 0;
        /// Combined texture flag mask bits for a float shadow sampler.
        static const TextureFlagMask TEXTURE_FLAG_MASK_FLOAT_SHADOW = TEXTURE_FLAG_MASK_BIT_SHADOW;
        MURL_DECLARE_ENUM_ACCESSOR(TextureFlagMask)

        /**
         * @brief Available texture semantics.
         */
        enum TextureSemantic
        {
            /// Undefined semantic.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, UNDEFINED)
            /// Unknown semantic.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, UNKNOWN)
            /// No semantic at all.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, NONE)
            /// Don't care.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DONT_CARE)
            /// Ambient lighting red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, AMBIENT_RED)
            /// Ambient lighting green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, AMBIENT_GREEN)
            /// Ambient lighting blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, AMBIENT_BLUE)
            /// Ambient lighting alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, AMBIENT_ALPHA)
            /// Ambient lighting luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, AMBIENT_LUMINANCE)
            /// Diffuse lighting red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DIFFUSE_RED)
            /// Diffuse lighting green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DIFFUSE_GREEN)
            /// Diffuse lighting blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DIFFUSE_BLUE)
            /// Diffuse lighting alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DIFFUSE_ALPHA)
            /// Diffuse lighting luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DIFFUSE_LUMINANCE)
            /// Specular lighting red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, SPECULAR_RED)
            /// Specular lighting green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, SPECULAR_GREEN)
            /// Specular lighting blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, SPECULAR_BLUE)
            /// Specular lighting alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, SPECULAR_ALPHA)
            /// Specular lighting luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, SPECULAR_LUMINANCE)
            /// Emissive lighting red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, EMISSIVE_RED)
            /// Emissive lighting green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, EMISSIVE_GREEN)
            /// Emissive lighting blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, EMISSIVE_BLUE)
            /// Emissive lighting alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, EMISSIVE_ALPHA)
            /// Emissive lighting luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, EMISSIVE_LUMINANCE)
            /// Reflection map red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, REFLECTION_RED)
            /// Reflection map green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, REFLECTION_GREEN)
            /// Reflection map blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, REFLECTION_BLUE)
            /// Reflection map blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, REFLECTION_ALPHA)
            /// Reflection map luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, REFLECTION_LUMINANCE)
            /// Light map/ambient occlusion map red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHTMAP_RED)
            /// Light map/ambient occlusion map green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHTMAP_GREEN)
            /// Light map/ambient occlusion map blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHTMAP_BLUE)
            /// Light map/ambient occlusion map alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHTMAP_ALPHA)
            /// Light map/ambient occlusion map luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHTMAP_LUMINANCE)
            /// Projected light texture #0 red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHT_RED)
            /// Projected light texture #0 green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHT_GREEN)
            /// Projected light texture #0 blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHT_BLUE)
            /// Projected light texture #0 alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHT_ALPHA)
            /// Projected light texture #0 luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, LIGHT_LUMINANCE)
            /// Environment (cube) map red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, ENVIRONMENT_RED)
            /// Environment (cube) map green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, ENVIRONMENT_GREEN)
            /// Environment (cube) map blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, ENVIRONMENT_BLUE)
            /// Environment (cube) map alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, ENVIRONMENT_ALPHA)
            /// Environment (cube) map luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, ENVIRONMENT_LUMINANCE)
            /// Irradiance (cube) map red component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, IRRADIANCE_RED)
            /// Irradiance (cube) map green component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, IRRADIANCE_GREEN)
            /// Irradiance (cube) map blue component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, IRRADIANCE_BLUE)
            /// Irradiance (cube) map alpha component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, IRRADIANCE_ALPHA)
            /// Irradiance (cube) map luminance.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, IRRADIANCE_LUMINANCE)
            /// Normal map X direction.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, NORMAL_X)
            /// Normal map Y direction.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, NORMAL_Y)
            /// Normal map Z direction.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, NORMAL_Z)
            /// Displacement map X direction.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DISPLACEMENT_X)
            /// Displacement map Y direction.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DISPLACEMENT_Y)
            /// Displacement map Z direction.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DISPLACEMENT_Z)
            /// Normalization cube map X component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, NORMALIZATION_X)
            /// Normalization cube map Y component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, NORMALIZATION_Y)
            /// Normalization cube map Z component.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, NORMALIZATION_Z)
            /// Opacity value.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, OPACITY_VALUE)
            /// Shininess value.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, SHININESS_VALUE)
            /// Glossiness value.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, GLOSSINESS_VALUE)
            /// Height map value.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, HEIGHT_VALUE)
            /// Dissolve value.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_SEMANTIC, DISSOLVE_VALUE)

            NUM_TEXTURE_SEMANTICS
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextureSemantic)

        /**
         * @brief Available texture upload targets.
         */
        enum TextureTarget
        {
            /// The default texture upload target.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, DEFAULT)

            /// Single target for 2D (flat) textures.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, FLAT)

            /// The +X face of a cube map texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, CUBE_POS_X)
            /// The -X face of a cube map texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, CUBE_NEG_X)
            /// The +Y face of a cube map texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, CUBE_POS_Y)
            /// The -Y face of a cube map texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, CUBE_NEG_Y)
            /// The +Z face of a cube map texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, CUBE_POS_Z)
            /// The -Z face of a cube map texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_TARGET, CUBE_NEG_Z)

            NUM_TEXTURE_TARGETS,

            NUM_TEXTURE_FLAT_TARGETS = 1,
            NUM_TEXTURE_CUBE_TARGETS = 6,
            NUM_TEXTURE_MAX_TARGETS = 6
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextureTarget)

        /**
         * @brief Available attachment points to attach a texture to a frame buffer.
         */
        enum TextureAttachment
        {
            /// Default attachment point.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_ATTACHMENT, DEFAULT)

            /// Attachment point for 1st color texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_ATTACHMENT, COLOR_BUFFER_0)
            /// Attachment point for 2nd color texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_ATTACHMENT, COLOR_BUFFER_1)
            /// Attachment point for 3rd color texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_ATTACHMENT, COLOR_BUFFER_2)
            /// Attachment point for 4th color texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_ATTACHMENT, COLOR_BUFFER_3)
            /// Attachment point for a depth texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_ATTACHMENT, DEPTH_BUFFER_0)
            /// Attachment point for a stencil texture.
            MURL_DECLARE_ENUM_VALUE(TEXTURE_ATTACHMENT, STENCIL_BUFFER_0)

            NUM_TEXTURE_ATTACHMENTS
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextureAttachment)

        /**
         * @brief Available index buffer items.
         */
        enum IndexBufferItem
        {
            MURL_DECLARE_ENUM_VALUE(INDEX_BUFFER_ITEM, DEFAULT)

            NUM_INDEX_BUFFER_ITEMS
        };
        MURL_DECLARE_ENUM_ACCESSOR(IndexBufferItem)
        /**
         * @brief Query the name of a index buffer item.
         * @param indexBufferItem The index buffer item to query.
         * @return The human-readable index buffer item name.
         */
        const Char* GetIndexBufferItemName(IndexBufferItem indexBufferItem);
        /**
         * @brief Query the alternative name of a index buffer item.
         * @param indexBufferItem The index buffer item to query.
         * @return The human-readable alternative index buffer item name.
         */
        const Char* GetIndexBufferItemAlternativeName(IndexBufferItem indexBufferItem);

        /**
         * @brief Available data types for index buffer elements.
         */
        enum IndexType
        {
            /// Undefined data type.
            MURL_DECLARE_ENUM_VALUE(INDEX_TYPE, UNDEFINED)

            /// Unsigned 8 bit indices.
            MURL_DECLARE_ENUM_VALUE(INDEX_TYPE, UINT8)
            /// Unsigned 16 bit indices.
            MURL_DECLARE_ENUM_VALUE(INDEX_TYPE, UINT16)
            /// Unsigned 32 bit indices.
            MURL_DECLARE_ENUM_VALUE(INDEX_TYPE, UINT32)

            NUM_INDEX_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(IndexType)
        /**
         * @brief Query the number of bytes per element for a given index type.
         * @param indexType The index data type to query.
         * @return The number of bytes per element.
         */
        UInt32 GetIndexTypeByteSize(IndexType indexType);

        /**
         * @brief Available vertex buffer items to be used in vertex shaders.
         */
        enum VertexBufferItem
        {
            MURL_DECLARE_ENUM_VALUE(VERTEX_BUFFER_ITEM, DEFAULT)

            NUM_VERTEX_BUFFER_ITEMS
        };
        MURL_DECLARE_ENUM_ACCESSOR(VertexBufferItem)
        /**
         * @brief Query the name of a vertex buffer item.
         * @param vertexBufferItem The vertex buffer item to query.
         * @return The human-readable vertex buffer item name.
         */
        const Char* GetVertexBufferItemName(VertexBufferItem vertexBufferItem);
        /**
         * @brief Query the alternative name of a vertex buffer item.
         * @param vertexBufferItem The vertex buffer item to query.
         * @return The human-readable alternative vertex buffer item name.
         */
        const Char* GetVertexBufferItemAlternativeName(VertexBufferItem vertexBufferItem);

        /**
         * @brief Available data types for vertex buffer attribute items.
         */
        enum AttributeType
        {
            /// Undefined type.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UNDEFINED)

            /// Scalar 32 bit float value.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, FLOAT)
            /// A 2-component vector of 32 bit float values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, FLOAT_VECTOR_2)
            /// A 3-component vector of 32 bit float values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, FLOAT_VECTOR_3)
            /// A 4-component vector of 32 bit float values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, FLOAT_VECTOR_4)

            /// Scalar 8 bit unsigned integer value.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT8)
            /// A 2-component vector of 8 bit unsigned integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT8_VECTOR_2)
            /// A 3-component vector of 8 bit unsigned integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT8_VECTOR_3)
            /// A 4-component vector of 8 bit unsigned integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT8_VECTOR_4)

            /// Scalar 8 bit signed integer value.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT8)
            /// A 2-component vector of 8 bit signed integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT8_VECTOR_2)
            /// A 3-component vector of 8 bit signed integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT8_VECTOR_3)
            /// A 4-component vector of 8 bit signed integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT8_VECTOR_4)

            /// Scalar 16 bit unsigned integer value.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT16)
            /// A 2-component vector of 16 bit unsigned integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT16_VECTOR_2)
            /// A 3-component vector of 16 bit unsigned integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT16_VECTOR_3)
            /// A 4-component vector of 16 bit unsigned integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, UINT16_VECTOR_4)

            /// Scalar 16 bit signed integer value.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT16)
            /// A 2-component vector of 16 bit signed integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT16_VECTOR_2)
            /// A 3-component vector of 16 bit signed integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT16_VECTOR_3)
            /// A 4-component vector of 16 bit signed integer values.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, SINT16_VECTOR_4)

            /// Scalar 8 bit unsigned integer value, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT8)
            /// A 2-component vector of 8 bit unsigned integer values, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT8_VECTOR_2)
            /// A 3-component vector of 8 bit unsigned integer values, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT8_VECTOR_3)
            /// A 4-component vector of 8 bit unsigned integer values, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT8_VECTOR_4)

            /// Scalar 8 bit signed integer value, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT8)
            /// A 2-component vector of 8 bit signed integer values, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT8_VECTOR_2)
            /// A 3-component vector of 8 bit signed integer values, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT8_VECTOR_3)
            /// A 4-component vector of 8 bit signed integer values, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT8_VECTOR_4)

            /// Scalar 16 bit unsigned integer value, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT16)
            /// A 2-component vector of 16 bit unsigned integer values, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT16_VECTOR_2)
            /// A 3-component vector of 16 bit unsigned integer values, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT16_VECTOR_3)
            /// A 4-component vector of 16 bit unsigned integer values, normalized to [0..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_UINT16_VECTOR_4)

            /// Scalar 16 bit signed integer value, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT16)
            /// A 2-component vector of 16 bit signed integer values, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT16_VECTOR_2)
            /// A 3-component vector of 16 bit signed integer values, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT16_VECTOR_3)
            /// A 4-component vector of 16 bit signed integer values, normalized to [-1..1].
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_TYPE, NORMALIZED_SINT16_VECTOR_4)

            NUM_ATTRIBUTE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(AttributeType)
        /**
         * @brief Query the total number of bytes per item for a given attribute type.
         * This returns the total number of bytes per item, e.g. for a 3-component vector
         * of unsigned 16 bit integer values (IEnums::ATTRIBUTE_TYPE_UINT16_VECTOR_3) the
         * returned number of bytes will be 3 * 2 = 6.
         * @param attributeType The attribute data type to query.
         * @return The number of bytes per item.
         */
        UInt32 GetAttributeTypeByteSize(AttributeType attributeType);
        /**
         * @brief Query the number of bytes per item component for a given attribute type.
         * This returns the number of bytes of a single component, e.g. 4 for all float-based
         * types (scalars and vectors of any size), 2 for UINT16-based types etc.
         * @param attributeType The attribute data type to query.
         * @return The number of bytes per item component.
         */
        UInt32 GetAttributeTypeComponentByteSize(AttributeType attributeType);
        /**
         * @brief Query the number of item components for a given attribute type.
         * This always returns 1 for scalar types, 2 for 2-component vectors etc.
         * @param attributeType The attribute data type to query.
         * @return The number of components.
         */
        UInt32 GetAttributeTypeNumberOfComponents(AttributeType attributeType);

        /**
         * @brief Available vertex buffer attribute items.
         */
        enum AttributeItem
        {
            /// Vertex coordinates.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, COORD)

            /// Normal vector.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, NORMAL)
            /// Binormal vector.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, BINORMAL)
            /// Tangent vector.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TANGENT)

            /// Vertex color.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, COLOR)

            /// Texture coordinate set #0.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_0)
            /// Texture coordinate set #1.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_1)
            /// Texture coordinate set #2.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_2)
            /// Texture coordinate set #3.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_3)
            /// Texture coordinate set #4.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_4)
            /// Texture coordinate set #5.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_5)
            /// Texture coordinate set #6.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_6)
            /// Texture coordinate set #7.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, TEXCOORD_7)

            /// Bone indices, to index into a given bone matrix array.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, BONE_INDICES)
            /// Bone weights, to blend bones together.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, BONE_WEIGHTS)

            /// Custom item.
            MURL_DECLARE_ENUM_VALUE(ATTRIBUTE_ITEM, CUSTOM)

            NUM_ATTRIBUTE_ITEMS
        };
        MURL_DECLARE_ENUM_ACCESSOR(AttributeItem)
        /**
         * @brief Query the predefined attribute item from a shader variable name.
         * @param name The human-readable variable name to query.
         * @return The attribute item, or ATTRIBUTE_ITEM_CUSTOM if not found.
         */
        AttributeItem GetAttributeItem(const Char* name);
        /**
         * @brief Query the shader variable data type for an attribute item.
         * @param attributeItem The attribute item to query.
         * @return The attribute variable data type.
         */
        AttributeType GetAttributeItemDataType(AttributeItem attributeItem);
        /**
         * @brief Query the default variable precision for an attribute item.
         * @param attributeItem The attribute item to query.
         * @return The variable precision.
         */
        ShaderVariablePrecision GetAttributeItemDefaultPrecision(AttributeItem attributeItem);
        /**
         * @brief Query an attribute item's predefined vertex buffer item.
         * @param attributeItem The attribute item to query.
         * @return The attribute variable vertex buffer item.
         */
        VertexBufferItem GetAttributeItemVertexBufferItem(AttributeItem attributeItem);
        /**
         * @brief Query the shader variable name for an attribute item.
         * @param attributeItem The attribute item to query.
         * @return The human-readable attribute variable name.
         */
        const Char* GetAttributeItemName(AttributeItem attributeItem);
        /**
         * @brief Query the alternative shader variable name for an attribute item.
         * @param attributeItem The attribute item to query.
         * @return The human-readable alternative attribute variable name.
         */
        const Char* GetAttributeItemAlternativeName(AttributeItem attributeItem);

        /**
         * @brief Available data types for constant shader variable items.
         */
        enum ConstantType
        {
            /// Undefined type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, UNDEFINED)

            /// Scalar signed integer type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, SINT32)
            /// 2-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, SINT32_VECTOR_2)
            /// 3-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, SINT32_VECTOR_3)
            /// 4-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, SINT32_VECTOR_4)

            /// Scalar floating point type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, FLOAT)
            /// 2-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, FLOAT_VECTOR_2)
            /// 3-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, FLOAT_VECTOR_3)
            /// 4-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, FLOAT_VECTOR_4)
            /// 2x2 floating point matrix type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, FLOAT_MATRIX_2)
            /// 3x3 floating point matrix type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, FLOAT_MATRIX_3)
            /// 4x4 floating point matrix type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, FLOAT_MATRIX_4)

            /// Scalar signed integer type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, BOOL)
            /// 2-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, BOOL_VECTOR_2)
            /// 3-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, BOOL_VECTOR_3)
            /// 4-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(CONSTANT_TYPE, BOOL_VECTOR_4)

            NUM_CONSTANT_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ConstantType)
        /**
         * @brief Query the number of item components for a given constant type.
         * This always returns 1 for scalar types, 2 for 2-component vectors etc.
         * @param constantType The constant data type to query.
         * @return The number of components.
         */
        UInt32 GetConstantTypeNumberOfComponents(ConstantType constantType);

        /**
         * @brief Available constant buffer items to be used in vertex and fragment shaders.
         */
        enum ConstantBufferItem
        {
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, DEFAULT)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, VIEWPORT)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, MODEL)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, CAMERA)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_0)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_1)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_2)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_3)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_4)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_5)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_6)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, LIGHT_7)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, MATERIAL)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SAMPLERS)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, BONES)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, CUSTOM)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, TIME)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_0)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_1)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_2)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_3)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_4)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_5)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_6)
            MURL_DECLARE_ENUM_VALUE(CONSTANT_BUFFER_ITEM, SHADOW_7)

            NUM_CONSTANT_BUFFER_ITEMS
        };
        MURL_DECLARE_ENUM_ACCESSOR(ConstantBufferItem)
        /**
         * @brief Query the predefined constant buffer item from a shader variable name.
         * @param name The human-readable variable name to query.
         * @return The constant buffer item, or CONSTANT_BUFFER_ITEM_CUSTOM if not found.
         */
        ConstantBufferItem GetConstantBufferItem(const Char* name);
        /**
         * @brief Query the name of a constant buffer item.
         * @param constantBufferItem The constant buffer item to query.
         * @return The human-readable constant buffer item name.
         */
        const Char* GetConstantBufferItemName(ConstantBufferItem constantBufferItem);
        /**
         * @brief Query the alternative name of a constant buffer item.
         * @param constantBufferItem The constant buffer item to query.
         * @return The human-readable alternative constant buffer item name.
         */
        const Char* GetConstantBufferItemAlternativeName(ConstantBufferItem constantBufferItem);

        /**
         * @brief Available data types for uniform variable items.
         */
        enum UniformType
        {
            /// Undefined type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, UNDEFINED)

            /// Scalar signed integer type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SINT32)
            /// 2-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SINT32_VECTOR_2)
            /// 3-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SINT32_VECTOR_3)
            /// 4-component integer vector type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SINT32_VECTOR_4)

            /// Scalar floating point type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, FLOAT)
            /// 2-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, FLOAT_VECTOR_2)
            /// 3-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, FLOAT_VECTOR_3)
            /// 4-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, FLOAT_VECTOR_4)
            /// 2x2 floating point matrix type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, FLOAT_MATRIX_2)
            /// 3x3 floating point matrix type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, FLOAT_MATRIX_3)
            /// 4x4 floating point matrix type.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, FLOAT_MATRIX_4)

            /// Flat texture sampler.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SAMPLER_FLAT)
            /// Cubemap sampler.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SAMPLER_CUBE)
            /// Flat texture array sampler.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SAMPLER_FLAT_ARRAY)
            /// Cubemap array sampler.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_TYPE, SAMPLER_CUBE_ARRAY)

            NUM_UNIFORM_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(UniformType)
        /**
         * @brief Query the total number of bytes per item for a given uniform type.
         * This returns the total number of bytes per item, e.g. for a 3-component vector
         * of signed 32 bit integer values (IEnums::UNIFORM_TYPE_SINT32_VECTOR_3) the
         * returned number of bytes will be 3 * 4 = 12.
         * @param uniformType The uniform data type to query.
         * @return The number of bytes per item.
         */
        UInt32 GetUniformTypeByteSize(UniformType uniformType);
        /**
         * @brief Query the number of bytes per item component for a given uniform type.
         * This returns the number of bytes of a single component, e.g. 4 for all float-based
         * types (scalars and vectors of any size) etc.
         * @param uniformType The uniform data type to query.
         * @return The number of bytes per item component.
         */
        UInt32 GetUniformTypeComponentByteSize(UniformType uniformType);
        /**
         * @brief Query the number of item components for a given uniform type.
         * This always returns 1 for scalar types, 2 for 2-component vectors etc.
         * @param uniformType The uniform data type to query.
         * @return The number of components.
         */
        UInt32 GetUniformTypeNumberOfComponents(UniformType uniformType);

        /**
         * @brief Available uniform variable items to be used in vertex and fragment shaders.
         */
        enum UniformItem
        {
            /// The current viewport size in pixels.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, VIEWPORT_SIZE)
            /// The inverted (i.e. reciprocal) viewport size.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, VIEWPORT_SIZE_INVERTED)

            /// The model matrix, to transform from model space to world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, MODEL_MATRIX)

            /// The camera world matrix.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, CAMERA_WORLD_MATRIX)
            /// The camera view matrix, to transform from world space to camera space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, CAMERA_VIEW_MATRIX)
            /// The camera projection matrix, to project from camera space to screen space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, CAMERA_PROJECTION_MATRIX)
            /// The combined camera view & projection matrix (world space to screen space).
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, CAMERA_VIEW_PROJECTION_MATRIX)
            /// The camera position vector in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, CAMERA_POSITION)
            /// The camera view direction vector in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, CAMERA_DIRECTION)

            /// The world matrix of light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_0)
            /// The world matrix of light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_1)
            /// The world matrix of light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_2)
            /// The world matrix of light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_3)
            /// The world matrix of light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_4)
            /// The world matrix of light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_5)
            /// The world matrix of light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_6)
            /// The world matrix of light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_WORLD_MATRIX_7)
            /// The view matrix of light unit #0, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_0)
            /// The view matrix of light unit #1, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_1)
            /// The view matrix of light unit #2, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_2)
            /// The view matrix of light unit #3, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_3)
            /// The view matrix of light unit #4, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_4)
            /// The view matrix of light unit #5, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_5)
            /// The view matrix of light unit #6, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_6)
            /// The view matrix of light unit #7, useful for e.g. shadow map generation.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_MATRIX_7)
            /// The projection matrix of light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_0)
            /// The projection matrix of light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_1)
            /// The projection matrix of light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_2)
            /// The projection matrix of light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_3)
            /// The projection matrix of light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_4)
            /// The projection matrix of light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_5)
            /// The projection matrix of light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_6)
            /// The projection matrix of light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_PROJECTION_MATRIX_7)
            /// The combined view & projection matrix of light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_0)
            /// The combined view & projection matrix of light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_1)
            /// The combined view & projection matrix of light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_2)
            /// The combined view & projection matrix of light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_3)
            /// The combined view & projection matrix of light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_4)
            /// The combined view & projection matrix of light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_5)
            /// The combined view & projection matrix of light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_6)
            /// The combined view & projection matrix of light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_VIEW_PROJECTION_MATRIX_7)
            /// The position vector of light unit #0 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_0)
            /// The position vector of light unit #1 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_1)
            /// The position vector of light unit #2 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_2)
            /// The position vector of light unit #3 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_3)
            /// The position vector of light unit #4 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_4)
            /// The position vector of light unit #5 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_5)
            /// The position vector of light unit #6 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_6)
            /// The position vector of light unit #7 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_POSITION_7)
            /// The direction vector of light unit #0 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_0)
            /// The direction vector of light unit #1 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_1)
            /// The direction vector of light unit #2 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_2)
            /// The direction vector of light unit #3 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_3)
            /// The direction vector of light unit #4 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_4)
            /// The direction vector of light unit #5 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_5)
            /// The direction vector of light unit #6 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_6)
            /// The direction vector of light unit #7 in world space.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_DIRECTION_7)
            /// Light attenuation values for light unit #0, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_0)
            /// Light attenuation values for light unit #1, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_1)
            /// Light attenuation values for light unit #2, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_2)
            /// Light attenuation values for light unit #3, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_3)
            /// Light attenuation values for light unit #4, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_4)
            /// Light attenuation values for light unit #5, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_5)
            /// Light attenuation values for light unit #6, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_6)
            /// Light attenuation values for light unit #7, packed into the X, Y and Z components of a vector.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_ATTENUATION_7)
            /// Packed light spot values for light unit #0: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_0)
            /// Packed light spot values for light unit #1: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_1)
            /// Packed light spot values for light unit #2: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_2)
            /// Packed light spot values for light unit #3: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_3)
            /// Packed light spot values for light unit #4: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_4)
            /// Packed light spot values for light unit #5: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_5)
            /// Packed light spot values for light unit #6: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_6)
            /// Packed light spot values for light unit #7: X = spot exponent, Y = spot cutoff angle, Z = light intensity.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_SPOT_7)
            /// The ambient color component for light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_0)
            /// The ambient color component for light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_1)
            /// The ambient color component for light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_2)
            /// The ambient color component for light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_3)
            /// The ambient color component for light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_4)
            /// The ambient color component for light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_5)
            /// The ambient color component for light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_6)
            /// The ambient color component for light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_AMBIENT_7)
            /// The diffuse color component for light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_0)
            /// The diffuse color component for light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_1)
            /// The diffuse color component for light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_2)
            /// The diffuse color component for light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_3)
            /// The diffuse color component for light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_4)
            /// The diffuse color component for light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_5)
            /// The diffuse color component for light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_6)
            /// The diffuse color component for light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_DIFFUSE_7)
            /// The specular color component for light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_0)
            /// The specular color component for light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_1)
            /// The specular color component for light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_2)
            /// The specular color component for light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_3)
            /// The specular color component for light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_4)
            /// The specular color component for light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_5)
            /// The specular color component for light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_6)
            /// The specular color component for light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, LIGHT_COLOR_SPECULAR_7)

            /// The current material's ambient color component.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, MATERIAL_COLOR_AMBIENT)
            /// The current material's diffuse color component.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, MATERIAL_COLOR_DIFFUSE)
            /// The current material's specular color component.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, MATERIAL_COLOR_SPECULAR)
            /// The current material's emissive color component (self illumination).
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, MATERIAL_COLOR_EMISSIVE)
            /// The current material's shininess parameter (specular exponent).
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, MATERIAL_SHININESS)

            /// Sampler for texture unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_0)
            /// Sampler for texture unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_1)
            /// Sampler for texture unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_2)
            /// Sampler for texture unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_3)
            /// Sampler for texture unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_4)
            /// Sampler for texture unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_5)
            /// Sampler for texture unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_6)
            /// Sampler for texture unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SAMPLER_7)

            /// Bone matrix #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_0)
            /// Bone matrix #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_1)
            /// Bone matrix #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_2)
            /// Bone matrix #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_3)
            /// Bone matrix #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_4)
            /// Bone matrix #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_5)
            /// Bone matrix #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_6)
            /// Bone matrix #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_7)
            /// Bone matrix #8.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_8)
            /// Bone matrix #9.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_9)
            /// Bone matrix #10.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_10)
            /// Bone matrix #11.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_11)
            /// Bone matrix #12.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_12)
            /// Bone matrix #13.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_13)
            /// Bone matrix #14.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_14)
            /// Bone matrix #15.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_15)
            /// Bone matrix #16.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_16)
            /// Bone matrix #17.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_17)
            /// Bone matrix #18.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_18)
            /// Bone matrix #19.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_19)
            /// Bone matrix #20.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_20)
            /// Bone matrix #21.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_21)
            /// Bone matrix #22.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_22)
            /// Bone matrix #23.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_23)
            /// Bone matrix #24.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_24)
            /// Bone matrix #25.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_25)
            /// Bone matrix #26.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_26)
            /// Bone matrix #27.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_27)
            /// Bone matrix #28.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_28)
            /// Bone matrix #29.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_29)
            /// Bone matrix #30.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_30)
            /// Bone matrix #31.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_31)
            /// Bone matrix #32.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_32)
            /// Bone matrix #33.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_33)
            /// Bone matrix #34.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_34)
            /// Bone matrix #35.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_35)
            /// Bone matrix #36.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_36)
            /// Bone matrix #37.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_37)
            /// Bone matrix #38.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_38)
            /// Bone matrix #39.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_39)
            /// Bone matrix #40.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_40)
            /// Bone matrix #41.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_41)
            /// Bone matrix #42.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_42)
            /// Bone matrix #43.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_43)
            /// Bone matrix #44.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_44)
            /// Bone matrix #45.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_45)
            /// Bone matrix #46.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_46)
            /// Bone matrix #47.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_47)
            /// Bone matrix #48.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_48)
            /// Bone matrix #49.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_49)
            /// Bone matrix #50.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_50)
            /// Bone matrix #51.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_51)
            /// Bone matrix #52.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_52)
            /// Bone matrix #53.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_53)
            /// Bone matrix #54.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_54)
            /// Bone matrix #55.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_55)
            /// Bone matrix #56.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_56)
            /// Bone matrix #57.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_57)
            /// Bone matrix #58.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_58)
            /// Bone matrix #59.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_59)
            /// Bone matrix #60.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_60)
            /// Bone matrix #61.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_61)
            /// Bone matrix #62.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_62)
            /// Bone matrix #63.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, BONE_MATRIX_63)

            /// Custom item
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, CUSTOM)

            /// Running time (seconds part)
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, TIME_SECONDS)
            /// Running time (fractional part)
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, TIME_FRACTION)

            /// The combined shadow view & projection matrix for cascade #0 of light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_0_0)
            /// The combined shadow view & projection matrix for cascade #0 of light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_1_0)
            /// The combined shadow view & projection matrix for cascade #0 of light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_2_0)
            /// The combined shadow view & projection matrix for cascade #0 of light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_3_0)
            /// The combined shadow view & projection matrix for cascade #0 of light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_4_0)
            /// The combined shadow view & projection matrix for cascade #0 of light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_5_0)
            /// The combined shadow view & projection matrix for cascade #0 of light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_6_0)
            /// The combined shadow view & projection matrix for cascade #0 of light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_7_0)

            /// The combined shadow view & projection matrix for cascade #1 of light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_0_1)
            /// The combined shadow view & projection matrix for cascade #1 of light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_1_1)
            /// The combined shadow view & projection matrix for cascade #1 of light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_2_1)
            /// The combined shadow view & projection matrix for cascade #1 of light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_3_1)
            /// The combined shadow view & projection matrix for cascade #1 of light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_4_1)
            /// The combined shadow view & projection matrix for cascade #1 of light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_5_1)
            /// The combined shadow view & projection matrix for cascade #1 of light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_6_1)
            /// The combined shadow view & projection matrix for cascade #1 of light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_7_1)

            /// The combined shadow view & projection matrix for cascade #2 of light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_0_2)
            /// The combined shadow view & projection matrix for cascade #2 of light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_1_2)
            /// The combined shadow view & projection matrix for cascade #2 of light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_2_2)
            /// The combined shadow view & projection matrix for cascade #2 of light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_3_2)
            /// The combined shadow view & projection matrix for cascade #2 of light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_4_2)
            /// The combined shadow view & projection matrix for cascade #2 of light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_5_2)
            /// The combined shadow view & projection matrix for cascade #2 of light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_6_2)
            /// The combined shadow view & projection matrix for cascade #2 of light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_7_2)

            /// The combined shadow view & projection matrix for cascade #3 of light unit #0.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_0_3)
            /// The combined shadow view & projection matrix for cascade #3 of light unit #1.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_1_3)
            /// The combined shadow view & projection matrix for cascade #3 of light unit #2.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_2_3)
            /// The combined shadow view & projection matrix for cascade #3 of light unit #3.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_3_3)
            /// The combined shadow view & projection matrix for cascade #3 of light unit #4.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_4_3)
            /// The combined shadow view & projection matrix for cascade #3 of light unit #5.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_5_3)
            /// The combined shadow view & projection matrix for cascade #3 of light unit #6.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_6_3)
            /// The combined shadow view & projection matrix for cascade #3 of light unit #7.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_VIEW_PROJECTION_MATRIX_7_3)

            /// The shadow split distances (far distances) of light unit #0, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_0)
            /// The shadow split distances (far distances) of light unit #1, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_1)
            /// The shadow split distances (far distances) of light unit #2, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_2)
            /// The shadow split distances (far distances) of light unit #3, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_3)
            /// The shadow split distances (far distances) of light unit #4, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_4)
            /// The shadow split distances (far distances) of light unit #5, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_5)
            /// The shadow split distances (far distances) of light unit #6, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_6)
            /// The shadow split distances (far distances) of light unit #7, packed into XYZW.
            MURL_DECLARE_ENUM_VALUE(UNIFORM_ITEM, SHADOW_SPLIT_DISTANCE_7)

            NUM_UNIFORM_ITEMS
        };
        MURL_DECLARE_ENUM_ACCESSOR(UniformItem)
        /**
         * @brief Query the predefined uniform item from a shader variable name.
         * @param name The human-readable variable name to query.
         * @return The constant buffer item, or UNIFORM_ITEM_CUSTOM if not found.
         */
        UniformItem GetUniformItem(const Char* name);
        /**
         * @brief Query the shader variable data type for a uniform item.
         * @param uniformItem The uniform item to query.
         * @return The uniform variable data type.
         */
        UniformType GetUniformItemDataType(UniformItem uniformItem);
        /**
         * @brief Query the default variable precision for a uniform item.
         * @param uniformItem The uniform item to query.
         * @return The variable precision.
         */
        ShaderVariablePrecision GetUniformItemDefaultPrecision(UniformItem uniformItem);
        /**
         * @brief Query a uniform item's predefined constant buffer item.
         * @param uniformItem The uniform item to query.
         * @return The uniform variable constant buffer item.
         */
        ConstantBufferItem GetUniformItemConstantBufferItem(UniformItem uniformItem);
        /**
         * @brief Query the shader variable name for a uniform item.
         * @param uniformItem The uniform item to query.
         * @return The human-readable uniform variable name.
         */
        const Char* GetUniformItemName(UniformItem uniformItem);
        /**
         * @brief Query the alternative shader variable name for a uniform item.
         * @param uniformItem The uniform item to query.
         * @return The human-readable alternative uniform variable name.
         */
        const Char* GetUniformItemAlternativeName(UniformItem uniformItem);

        /**
         * @brief Query the number of uniform items for a predefined constant buffer.
         * @param constantBufferItem The predefined constant buffer item to query.
         * @return The number of uniforms.
         */
        UInt32 GetConstantBufferItemNumberOfUniformItems(ConstantBufferItem constantBufferItem);
        /**
         * @brief Query the predefined uniform item for a predefined constant buffer at a given index.
         * @param constantBufferItem The predefined constant buffer item to query.
         * @param index The uniform index, from 0 to GetConstantBufferItemNumberOfUniformItems()-1.
         * @return The predefined uniform item.
         */
        IEnums::UniformItem GetConstantBufferItemUniformItem(ConstantBufferItem constantBufferItem, UInt32 index);
        /**
         * @brief Query the array size of a predefined uniform item for a predefined constant buffer at a given index.
         * @param constantBufferItem The predefined constant buffer item to query.
         * @param index The uniform index, from 0 to GetConstantBufferItemNumberOfUniformItems()-1.
         * @return The array size, or 0 if scalar.
         */
        UInt32 GetConstantBufferItemUniformItemArraySize(ConstantBufferItem constantBufferItem, UInt32 index);

        /**
         * @brief Available data types for varying variable items.
         */
        enum VaryingType
        {
            /// Undefined type.
            MURL_DECLARE_ENUM_VALUE(VARYING_TYPE, UNDEFINED)

            /// Scalar floating point type.
            MURL_DECLARE_ENUM_VALUE(VARYING_TYPE, FLOAT)
            /// 2-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(VARYING_TYPE, FLOAT_VECTOR_2)
            /// 3-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(VARYING_TYPE, FLOAT_VECTOR_3)
            /// 4-component floating point vector type.
            MURL_DECLARE_ENUM_VALUE(VARYING_TYPE, FLOAT_VECTOR_4)

            NUM_VARYING_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(VaryingType)
        /**
         * @brief Query the total number of bytes per item for a given varying type.
         * This returns the total number of bytes per item, e.g. for a 3-component vector
         * of 32 bit float values (IEnums::VARYING_TYPE_FLOAT_VECTOR_3) the
         * returned number of bytes will be 3 * 4 = 12.
         * @param varyingType The varying data type to query.
         * @return The number of bytes per item.
         */
        UInt32 GetVaryingTypeByteSize(VaryingType varyingType);
        /**
         * @brief Query the number of bytes per item component for a given varying type.
         * This returns the number of bytes of a single component, e.g. 4 for all float-based
         * types (scalars and vectors of any size) etc.
         * @param varyingType The varying data type to query.
         * @return The number of bytes per item component.
         */
        UInt32 GetVaryingTypeComponentByteSize(VaryingType varyingType);
        /**
         * @brief Query the number of item components for a given varying type.
         * This always returns 1 for scalar types, 2 for 2-component vectors etc.
         * @param varyingType The varying data type to query.
         * @return The number of components.
         */
        UInt32 GetVaryingTypeNumberOfComponents(VaryingType varyingType);

        /**
         * @brief Available primitive types for rendering vertex/index buffers.
         */
        enum PrimitiveType
        {
            /// Undefined primitive type.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, UNDEFINED)

            /// Individual points.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, POINTS)
            /// A sequence of lines, with each line using the previous line's end point as
            /// the new starting point.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, LINE_STRIP)
            /// A sequence of lines, with each line using the previous line's end point as
            /// the new starting point; an additional line is inserted from the very last
            /// to the very first point, to form a loop.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, LINE_LOOP)
            /// A sequence of lines; every subsequent pair of vertices forms an individual line.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, LINES)
            /// A sequence of triangles, with each triangle using the previous triangle's
            /// last two vertices as its first two vertices.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, TRIANGLE_STRIP)
            /// A triangle fan, where all triangles share the first vertex of the buffer,
            /// and each triangle shares the last vertex of the previous triangle.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, TRIANGLE_FAN)
            /// A sequence of triangles; every subsequent triple of vertices forms an
            /// individual triangle.
            MURL_DECLARE_ENUM_VALUE(PRIMITIVE_TYPE, TRIANGLES)

            NUM_PRIMITIVE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(PrimitiveType)

        /**
         * @brief Available access modes for e.g. vertex/index buffers.
         */
        enum BufferAccessMode
        {
            /// Default access mode.
            MURL_DECLARE_ENUM_VALUE(BUFFER_ACCESS_MODE, DEFAULT)

            /// Read-only access mode.
            MURL_DECLARE_ENUM_VALUE(BUFFER_ACCESS_MODE, READ_ONLY)
            /// Read-and-write access mode.
            MURL_DECLARE_ENUM_VALUE(BUFFER_ACCESS_MODE, READ_AND_WRITE)

            NUM_BUFFER_ACCESS_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(BufferAccessMode)

        /**
         * @brief Available types for e.g. vertex/index buffers.
         */
        enum BufferType
        {
            /// Default buffer type.
            MURL_DECLARE_ENUM_VALUE(BUFFER_TYPE, DEFAULT)

            /// Static buffer type.
            MURL_DECLARE_ENUM_VALUE(BUFFER_TYPE, STATIC)
            /// Stream buffer type.
            MURL_DECLARE_ENUM_VALUE(BUFFER_TYPE, STREAM)

            NUM_BUFFER_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(BufferType)

        /**
         * @brief Available variable types for e.g. Graph::IVariable nodes.
         */
        enum VariableType
        {
            /// Undefined type.
            MURL_DECLARE_ENUM_VALUE(VARIABLE_TYPE, UNDEFINED)

            // Boolean type (true/false).
            MURL_DECLARE_ENUM_VALUE(VARIABLE_TYPE, BOOL)
            // Floating point type.
            MURL_DECLARE_ENUM_VALUE(VARIABLE_TYPE, REAL)
            // 32bit signed integer type.
            MURL_DECLARE_ENUM_VALUE(VARIABLE_TYPE, SINT32)

            NUM_VARIABLE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(VariableType)

        /**
         * @brief Available timeline units.
         */
        enum TimelineUnit
        {
            /// Timeline unit #0
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 0)
            /// Timeline unit #1
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 1)
            /// Timeline unit #2
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 2)
            /// Timeline unit #3
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 3)
            /// Timeline unit #4
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 4)
            /// Timeline unit #5
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 5)
            /// Timeline unit #6
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 6)
            /// Timeline unit #7
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 7)
            /// Timeline unit #8
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 8)
            /// Timeline unit #9
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 9)
            /// Timeline unit #10
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 10)
            /// Timeline unit #11
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 11)
            /// Timeline unit #12
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 12)
            /// Timeline unit #13
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 13)
            /// Timeline unit #14
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 14)
            /// Timeline unit #15
            MURL_DECLARE_ENUM_VALUE(TIMELINE_UNIT, 15)

            NUM_TIMELINE_UNITS
        };

        /**
         * @brief Available bone units.
         */
        enum BoneUnit
        {
            /// Bone unit #0
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 0)
            /// Bone unit #1
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 1)
            /// Bone unit #2
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 2)
            /// Bone unit #3
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 3)
            /// Bone unit #4
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 4)
            /// Bone unit #5
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 5)
            /// Bone unit #6
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 6)
            /// Bone unit #7
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 7)
            /// Bone unit #8
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 8)
            /// Bone unit #9
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 9)
            /// Bone unit #10
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 10)
            /// Bone unit #11
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 11)
            /// Bone unit #12
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 12)
            /// Bone unit #13
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 13)
            /// Bone unit #14
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 14)
            /// Bone unit #15
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 15)
            /// Bone unit #16
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 16)
            /// Bone unit #17
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 17)
            /// Bone unit #18
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 18)
            /// Bone unit #19
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 19)
            /// Bone unit #20
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 20)
            /// Bone unit #21
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 21)
            /// Bone unit #22
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 22)
            /// Bone unit #23
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 23)
            /// Bone unit #24
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 24)
            /// Bone unit #25
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 25)
            /// Bone unit #26
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 26)
            /// Bone unit #27
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 27)
            /// Bone unit #28
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 28)
            /// Bone unit #29
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 29)
            /// Bone unit #30
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 30)
            /// Bone unit #31
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 31)
            /// Bone unit #32
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 32)
            /// Bone unit #33
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 33)
            /// Bone unit #34
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 34)
            /// Bone unit #35
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 35)
            /// Bone unit #36
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 36)
            /// Bone unit #37
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 37)
            /// Bone unit #38
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 38)
            /// Bone unit #39
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 39)
            /// Bone unit #40
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 40)
            /// Bone unit #41
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 41)
            /// Bone unit #42
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 42)
            /// Bone unit #43
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 43)
            /// Bone unit #44
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 44)
            /// Bone unit #45
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 45)
            /// Bone unit #46
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 46)
            /// Bone unit #47
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 47)
            /// Bone unit #48
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 48)
            /// Bone unit #49
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 49)
            /// Bone unit #50
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 50)
            /// Bone unit #51
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 51)
            /// Bone unit #52
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 52)
            /// Bone unit #53
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 53)
            /// Bone unit #54
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 54)
            /// Bone unit #55
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 55)
            /// Bone unit #56
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 56)
            /// Bone unit #57
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 57)
            /// Bone unit #58
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 58)
            /// Bone unit #59
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 59)
            /// Bone unit #60
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 60)
            /// Bone unit #61
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 61)
            /// Bone unit #62
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 62)
            /// Bone unit #63
            MURL_DECLARE_ENUM_VALUE(BONE_UNIT, 63)

            NUM_BONE_UNITS
        };

        /**
         * @brief Available light units.
         */
        enum LightUnit
        {
            /// Light unit #0
            MURL_DECLARE_ENUM_VALUE(LIGHT_UNIT, 0)
            /// Light unit #1
            MURL_DECLARE_ENUM_VALUE(LIGHT_UNIT, 1)
            /// Light unit #2
            MURL_DECLARE_ENUM_VALUE(LIGHT_UNIT, 2)
            /// Light unit #3
            MURL_DECLARE_ENUM_VALUE(LIGHT_UNIT, 3)

            NUM_LIGHT_UNITS
        };

        /**
         * @brief Available texture units.
         */
        enum TextureUnit
        {
            /// Texture unit #0
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 0)
            /// Texture unit #1
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 1)
            /// Texture unit #2
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 2)
            /// Texture unit #3
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 3)
            /// Texture unit #4
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 4)
            /// Texture unit #5
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 5)
            /// Texture unit #6
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 6)
            /// Texture unit #7
            MURL_DECLARE_ENUM_VALUE(TEXTURE_UNIT, 7)

            NUM_TEXTURE_UNITS
        };

        /**
         * @brief Polygon vertex order.
         */
        enum VertexOrder
        {
            /// Undefined.
            MURL_DECLARE_ENUM_VALUE(VERTEX_ORDER, UNDEFINED)

            /// Front faces are in clockwise vertex order.
            MURL_DECLARE_ENUM_VALUE(VERTEX_ORDER, CLOCKWISE)
            /// Front faces are in counter-clockwise vertex order.
            MURL_DECLARE_ENUM_VALUE(VERTEX_ORDER, COUNTER_CLOCKWISE)
        };
        MURL_DECLARE_ENUM_ACCESSOR(VertexOrder)

        /**
         * @brief Polygon faces.
         */
        enum PolygonFaces
        {
            /// Undefined.
            MURL_DECLARE_ENUM_VALUE(POLYGON_FACES, UNDEFINED)

            /// No faces visible.
            MURL_DECLARE_ENUM_VALUE(POLYGON_FACES, NONE)
            /// Only front faces visible (i.e. back face culling enabled).
            MURL_DECLARE_ENUM_VALUE(POLYGON_FACES, FRONT_ONLY)
            /// Only back faces visible (i.e. front face culling enabled).
            MURL_DECLARE_ENUM_VALUE(POLYGON_FACES, BACK_ONLY)
            /// Both front and back faces visible (i.e. culling disabled).
            MURL_DECLARE_ENUM_VALUE(POLYGON_FACES, FRONT_AND_BACK)
        };
        MURL_DECLARE_ENUM_ACCESSOR(PolygonFaces)

        /**
         * @brief Color buffer access mode during rendering.
         */
        enum ColorBufferMode
        {
            /// Undefined mode.
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_MODE, UNDEFINED)

            /// No access (no color values are written)
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_MODE, NONE)
            /// Write access (default for rendering)
            MURL_DECLARE_ENUM_VALUE(COLOR_BUFFER_MODE, WRITE_ONLY)
        };
        MURL_DECLARE_ENUM_ACCESSOR(ColorBufferMode)

        /**
         * @brief Mask bits to control which color components are written.
         * The values in this enumeration are specified as a bit field so they
         * can be ORed together. If the renderer's color buffer mode is set to
         * IEnums::COLOR_BUFFER_MODE_WRITE_ONLY, a set mask bit enables writing
         * to the respective color channel. In case of IEnums::COLOR_BUFFER_MODE_NONE
         * this has no effect.
         */
        enum ColorBufferMaskBit
        {
            /// No bit set.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(COLOR_BUFFER_MASK_BIT, NONE, 0)

            /// The bit to enable writing of the red color component.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(COLOR_BUFFER_MASK_BIT, RED,   (1 << 0))
            /// The bit to enable writing of the green color component.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(COLOR_BUFFER_MASK_BIT, GREEN, (1 << 1))
            /// The bit to enable writing of the blue color component.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(COLOR_BUFFER_MASK_BIT, BLUE,  (1 << 2))
            /// The bit to enable writing of the alpha color component.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(COLOR_BUFFER_MASK_BIT, ALPHA, (1 << 3))
        };
        MURL_DECLARE_ENUM_ACCESSOR(ColorBufferMaskBit)

        /**
         * @brief Data type for combined color buffer mask bits,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 ColorBufferMask;
        /// Combined color buffer mask bits for no masks.
        static const ColorBufferMask COLOR_BUFFER_MASK_NONE = 0;
        /// Combined color buffer mask bits for all masks.
        static const ColorBufferMask COLOR_BUFFER_MASK_ALL  = 0xf;
        /// Special undefined color buffer mask.
        static const ColorBufferMask COLOR_BUFFER_MASK_UNDEFINED  = 0x80000000;
        MURL_DECLARE_ENUM_ACCESSOR(ColorBufferMask)

        /**
         * @brief Stencil buffer access mode during rendering.
         */
        enum StencilBufferMode
        {
            /// Undefined mode.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_MODE, UNDEFINED)

            /// No access (no stencil values are read or written)
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_MODE, NONE)
            /// Read-only access
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_MODE, READ_ONLY)
            /// Write-only access
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_MODE, WRITE_ONLY)
            /// Read-and-write access
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_MODE, READ_AND_WRITE)
        };
        MURL_DECLARE_ENUM_ACCESSOR(StencilBufferMode)

        /**
         * @brief Mask bits to control which stencil buffer bits are written.
         * The values in this enumeration are specified as a bit field so they
         * can be ORed together. If the renderer's stencil buffer mode is set to
         * IEnums::STENCIL_BUFFER_MODE_WRITE_ONLY or IEnums::STENCIL_BUFFER_MODE_READ_AND_WRITE,
         , a set mask bit enables writing to the respective bit. In case of all
         * other stencil buffer modes, this has no effect.
         */
        enum StencilBufferMaskBit
        {
            /// No bit set.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, NONE, 0)

            /// Enable stencil bit #0
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 0, (1 << 0))
            /// Enable stencil bit #1
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 1, (1 << 1))
            /// Enable stencil bit #2
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 2, (1 << 2))
            /// Enable stencil bit #3
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 3, (1 << 3))
            /// Enable stencil bit #4
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 4, (1 << 4))
            /// Enable stencil bit #5
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 5, (1 << 5))
            /// Enable stencil bit #6
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 6, (1 << 6))
            /// Enable stencil bit #7
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(STENCIL_BUFFER_MASK_BIT, 7, (1 << 7))
        };
        MURL_DECLARE_ENUM_ACCESSOR(StencilBufferMaskBit)

        /**
         * @brief Data type for combined stencil buffer mask bits,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 StencilBufferMask;
        /// Combined stencil buffer mask bits for no masks.
        static const StencilBufferMask STENCIL_BUFFER_MASK_NONE = 0;
        /// Combined stencil buffer mask bits for all masks.
        static const StencilBufferMask STENCIL_BUFFER_MASK_ALL  = 0xff;
        /// Special undefined stencil buffer mask.
        static const StencilBufferMask STENCIL_BUFFER_MASK_UNDEFINED  = 0x80000000;
        MURL_DECLARE_ENUM_ACCESSOR(StencilBufferMask)

        /**
         * @brief Stencil test functions.
         * There is a number of different functions that can be used for stencil value
         * comparison when the stencil buffer is enabled. In this case, during
         * rendering of each individual fragment, the fragment's associated stencil
         * value present in the stencil buffer is compared to a reference value, using
         * one of the given functions. Depending on the result of this comparison,
         * a specific IEnums::StencilBufferAction can be carried out to modify this
         * stencil value. By setting an IEnums::StencilBufferMask value of other than
         * IEnums::STENCIL_BUFFER_MASK_ALL, it is possible to control which bits of
         * the stencil buffer and reference value are actually used for comparison
         * and modification.
         */
        enum StencilTestFunction
        {
            /// Undefined function.
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, UNDEFINED)

            /// Stencil test always fails.
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, NEVER)
            /// Stencil test passes, if (ref & mask) < (stencil & mask)
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, LESS)
            /// Stencil test passes, if (ref & mask) <= (stencil & mask)
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, LESS_OR_EQUAL)
            /// Stencil test passes, if (ref & mask) > (stencil & mask)
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, GREATER)
            /// Stencil test passes, if (ref & mask) >= (stencil & mask)
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, GREATER_OR_EQUAL)
            /// Stencil test passes, if (ref & mask) == (stencil & mask)
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, EQUAL)
            /// Stencil test passes, if (ref & mask) != (stencil & mask)
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, NOT_EQUAL)
            /// Stencil test always passes.
            MURL_DECLARE_ENUM_VALUE(STENCIL_TEST_FUNCTION, ALWAYS)
        };
        MURL_DECLARE_ENUM_ACCESSOR(StencilTestFunction)

        /**
         * @brief Stencil buffer action.
         * These values specify an action carried out on a fragment's stencil buffer
         * value. Different actions can be carried out, depending if the stencil test
         * fails, if the stencil test passes but the depth buffer test does not, and
         * if both stencil and depth buffer tests pass.
         */
        enum StencilBufferAction
        {
            /// Undefined action.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, UNDEFINED)

            /// Keep the value in the stencil buffer.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, KEEP)
            /// Set the stencil buffer value to zero.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, ZERO)
            /// Set the stencil buffer value to the current reference value.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, REPLACE)
            /// Increment the stencil buffer value by 1, clamping at the maximum value (255).
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, CLAMPED_INCREMENT)
            /// Decrement the stencil buffer value by 1, clamping at the minimum value (0).
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, WRAPPED_INCREMENT)
            /// Increment the stencil buffer value by 1 and wrap around if the result is
            /// greater than the maximum value (255 => 0).
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, CLAMPED_DECREMENT)
            /// Decrement the stencil buffer value by 1 and wrap around if the result is
            /// smaller than the maximum value (0 => 255).
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, WRAPPED_DECREMENT)
            /// Invert the value in the stencil buffer bit-wise.
            MURL_DECLARE_ENUM_VALUE(STENCIL_BUFFER_ACTION, INVERT)
        };
        MURL_DECLARE_ENUM_ACCESSOR(StencilBufferAction)

        /**
         * @brief Depth buffer access mode during rendering.
         */
        enum DepthBufferMode
        {
            /// Undefined mode.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_MODE, UNDEFINED)

            /// Do not use the depth buffer at all.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_MODE, NONE)
            /// Perform only depth comparisons, but do not update the depth buffer.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_MODE, READ_ONLY)
            /// Always draw all pixels and update the depth buffer accordingly.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_MODE, WRITE_ONLY)
            /// Reject fragments based on a failed depth test, and update the depth
            /// buffer for all fragments that are not rejected.
            MURL_DECLARE_ENUM_VALUE(DEPTH_BUFFER_MODE, READ_AND_WRITE)
        };
        MURL_DECLARE_ENUM_ACCESSOR(DepthBufferMode)

        /**
         * @brief Mask bits to control which depth buffer entries are written.
         */
        enum DepthBufferMaskBit
        {
            /// Nothing is written to the depth buffer.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(DEPTH_BUFFER_MASK_BIT, NONE, 0)

            /// Depth value is written normally.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(DEPTH_BUFFER_MASK_BIT, DEPTH, (1 << 0))
        };
        MURL_DECLARE_ENUM_ACCESSOR(DepthBufferMaskBit)

        /**
         * @brief Data type for combined depth buffer mask bits,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 DepthBufferMask;
        /// Combined depth buffer mask bits for no masks.
        static const DepthBufferMask DEPTH_BUFFER_MASK_NONE = 0;
        /// Combined depth buffer mask bits for all masks.
        static const DepthBufferMask DEPTH_BUFFER_MASK_ALL  = 1;
        /// Special undefined depth buffer mask.
        static const DepthBufferMask DEPTH_BUFFER_MASK_UNDEFINED  = 0x80000000;
        MURL_DECLARE_ENUM_ACCESSOR(DepthBufferMask)

        /**
         * @brief Depth test functions.
         * Depending on the selected depth test function, the GPU decides whether
         * to render or discard individual fragments. The fragment's calculated
         * depth value is compared to the according depth value already present
         * in the depth buffer.
         */
        enum DepthTestFunction
        {
            /// Undefined function.
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, UNDEFINED)

            /// Depth test always fails.
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, NEVER)
            /// Depth test passes if fragment depth < stored depth
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, LESS)
            /// Depth test passes if fragment depth <= stored depth
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, LESS_OR_EQUAL)
            /// Depth test passes if fragment depth > stored depth
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, GREATER)
            /// Depth test passes if fragment depth >= stored depth
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, GREATER_OR_EQUAL)
            /// Depth test passes if fragment depth == stored depth
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, EQUAL)
            /// Depth test passes if fragment depth != stored depth
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, NOT_EQUAL)
            /// Depth test always passes
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_FUNCTION, ALWAYS)
        };
        MURL_DECLARE_ENUM_ACCESSOR(DepthTestFunction)

        /**
         * @brief Depth test modes.
         * When using depth textures, the depth test mode defines how the actual
         * result of a texture sample operation in the shader gets calculated.
         * A value of NONE directly returns the actually stored value in the texture.
         * A value of REFERENCE returns the result of the comparison to
         * a given reference value, using a given DepthTestFunction.
         */
        enum DepthTestMode
        {
            /// Undefined function.
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_MODE, UNDEFINED)

            /// Depth test always fails.
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_MODE, NONE)
            /// Depth test passes if fragment depth < stored depth
            MURL_DECLARE_ENUM_VALUE(DEPTH_TEST_MODE, REFERENCE)
        };
        MURL_DECLARE_ENUM_ACCESSOR(DepthTestMode)

        /**
         * @brief Available object sorting modes.
         * Renderable objects can be pre-sorted in different ways. In general, for any
         * opaque objects the "BY_MATERIAL" mode is the preferred one, as it groups together
         * any drawables that share common material properties, including texture sets and
         * GPU programs used. For (semi-)transparent objects, the "BY_DEPTH" mode is usually
         * needed, so that the correct back-to-front drawing order is maintained for blending.
         * If the "DEFAULT" mode is selected, the engine sets one of the two explicit modes,
         * with "BY_DEPTH" being used whenever the material does not write to the Z buffer.
         */
        enum ObjectSortMode
        {
            /// Undefined mode
            MURL_DECLARE_ENUM_VALUE(OBJECT_SORT_MODE, UNDEFINED)

            /// Sort objects according to their material properties
            MURL_DECLARE_ENUM_VALUE(OBJECT_SORT_MODE, BY_MATERIAL)
            /// Sort objects according to their distance from the viewer
            MURL_DECLARE_ENUM_VALUE(OBJECT_SORT_MODE, BY_DEPTH)
        };
        MURL_DECLARE_ENUM_ACCESSOR(ObjectSortMode)

        /**
         * @brief Available depth sorting modes.
         * If depth comparisons are performed in software on an object-level
         * (i.e. depth buffer writes are disabled), there is a number of different
         * depth sorting measures that can be applied.
         */
        enum DepthSortMode
        {
            /// Undefined mode
            MURL_DECLARE_ENUM_VALUE(DEPTH_SORT_MODE, UNDEFINED)

            /// Do not sort according to a depth value.
            MURL_DECLARE_ENUM_VALUE(DEPTH_SORT_MODE, NONE)
            /// Simple world-Z sorting (absolute Z position in world space)
            MURL_DECLARE_ENUM_VALUE(DEPTH_SORT_MODE, WORLD_Z)
            /// Sort according to squared distance from camera.
            MURL_DECLARE_ENUM_VALUE(DEPTH_SORT_MODE, DISTANCE)
            /// Simple view-Z sorting (Z distance in camera space)
            MURL_DECLARE_ENUM_VALUE(DEPTH_SORT_MODE, VIEW_Z)

            // TODO: Think about a different criterion for deciding if depth buffer or manual sorting is used.
            // TODO: WORLD_X, WORLD_Y ?
        };
        MURL_DECLARE_ENUM_ACCESSOR(DepthSortMode)

        /**
         * @brief Available blending modes.
         * Fragment blending in the GPU is done as a fixed-function stage in the
         * pipeline. By enabling alpha blending, the output color value written
         * in the fragment shader (or in the fixed function fragment stage) may
         * contain an alpha value other than the maximum, which can be used to
         * blend that fragment with the color value already present in the color
         * buffer at the respective location, using one of the available
         * IEnums::BlendFunction to calculate source and destination values,
         * and an IEnums::BlendEquation to specify how these two are actually
         * combined.
         */
        enum BlendMode
        {
            /// Undefined mode.
            MURL_DECLARE_ENUM_VALUE(BLEND_MODE, UNDEFINED)

            /// Blending is disabled.
            MURL_DECLARE_ENUM_VALUE(BLEND_MODE, NONE)
            /// The fragment's output color alpha value is used for blending.
            MURL_DECLARE_ENUM_VALUE(BLEND_MODE, ALPHA)
        };
        MURL_DECLARE_ENUM_ACCESSOR(BlendMode)

        /**
         * @brief Available blend equations.
         * See IEnums::BlendMode.
         */
        enum BlendEquation
        {
            /// Undefined equation.
            MURL_DECLARE_ENUM_VALUE(BLEND_EQUATION, UNDEFINED)

            /// Resulting color = source color + destination color.
            MURL_DECLARE_ENUM_VALUE(BLEND_EQUATION, ADD)
            /// Resulting color = source color - destination color.
            MURL_DECLARE_ENUM_VALUE(BLEND_EQUATION, SUBTRACT)
            /// Resulting color = destination color - source color.
            MURL_DECLARE_ENUM_VALUE(BLEND_EQUATION, REVERSE_SUBTRACT)
        };
        MURL_DECLARE_ENUM_ACCESSOR(BlendEquation)

        /**
         * @brief Available blend functions.
         * To determine the actual values for source and destination color to be
         * combined by a specific IEnums::BlendEquation, it is possible to set
         * a different blend function for both source and destination. In addition,
         * it is also possible to specify separate functions for color and alpha
         * values, resulting in 4 distinct values.
         * See IEnums::BlendMode.
         */
        enum BlendFunction
        {
            /// Undefined function.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, UNDEFINED)

            /// Zero color (i.e. all black, with 0% alpha)
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ZERO)
            /// Full color (i.e. all white, with 100% alpha)
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ONE)
            /// The source input color.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, SRC_COLOR)
            /// The inverted source input color.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ONE_MINUS_SRC_COLOR)
            /// The destination input color.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, DST_COLOR)
            /// The inverted destination input color.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ONE_MINUS_DST_COLOR)
            /// The source input color's alpha value, used for all 4 color components (RGBA).
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, SRC_ALPHA)
            /// The inverted source input color's alpha value, used for all 4 color components (RGBA).
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ONE_MINUS_SRC_ALPHA)
            /// The destination input color's alpha value, used for all 4 color components (RGBA).
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, DST_ALPHA)
            /// The inverted destination input color's alpha value, used for all 4 color components (RGBA).
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ONE_MINUS_DST_ALPHA)
            /// Constant blend color.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, CONSTANT_COLOR)
            /// Inverted constant blend color.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ONE_MINUS_CONSTANT_COLOR)
            /// Constant alpha.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, CONSTANT_ALPHA)
            /// Inverted constant alpha.
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, ONE_MINUS_CONSTANT_ALPHA)
            /// The source input color's saturated alpha value, used for all 4 color components (RGBA).
            MURL_DECLARE_ENUM_VALUE(BLEND_FUNCTION, SRC_ALPHA_SATURATE)
        };
        MURL_DECLARE_ENUM_ACCESSOR(BlendFunction)

        /**
         * @brief Color components
         */
        enum ColorComponent
        {
            /// Red component
            MURL_DECLARE_ENUM_VALUE(COLOR_COMPONENT, RED)
            /// Green component
            MURL_DECLARE_ENUM_VALUE(COLOR_COMPONENT, GREEN)
            /// Blue component
            MURL_DECLARE_ENUM_VALUE(COLOR_COMPONENT, BLUE)
            /// Alpha component
            MURL_DECLARE_ENUM_VALUE(COLOR_COMPONENT, ALPHA)

            NUM_COLOR_COMPONENTS
        };
        MURL_DECLARE_ENUM_ACCESSOR(ColorComponent)

        /**
         * @brief The lighting model used for fixed-function rendering.
         */
        enum LightModel
        {
            /// One-sided lighting model.
            MURL_DECLARE_ENUM_VALUE(LIGHT_MODEL, ONE_SIDED)
            /// Two-sided lighting model.
            MURL_DECLARE_ENUM_VALUE(LIGHT_MODEL, TWO_SIDED)

            NUM_LIGHT_MODELS
        };
        MURL_DECLARE_ENUM_ACCESSOR(LightModel)

        /**
         * @brief Available lighting equation components.
         * These components are used for both material and light source parameters,
         * except the EMISSIVE component, which does not make any sense for light
         * sources.
         */
        enum LightingComponent
        {
            /// Ambient component.
            MURL_DECLARE_ENUM_VALUE(LIGHTING_COMPONENT, AMBIENT)
            /// Diffuse component.
            MURL_DECLARE_ENUM_VALUE(LIGHTING_COMPONENT, DIFFUSE)
            /// Specular component.
            MURL_DECLARE_ENUM_VALUE(LIGHTING_COMPONENT, SPECULAR)
            /// Emissive component.
            MURL_DECLARE_ENUM_VALUE(LIGHTING_COMPONENT, EMISSIVE)

            NUM_LIGHTING_COMPONENTS
        };
        MURL_DECLARE_ENUM_ACCESSOR(LightingComponent)

        /**
         * @brief Available light types.
         * See Graph::ILight for a detailed description.
         */
        enum LightType
        {
            /// Directional light.
            MURL_DECLARE_ENUM_VALUE(LIGHT_TYPE, DIRECTIONAL)
            /// Point light.
            MURL_DECLARE_ENUM_VALUE(LIGHT_TYPE, POINT)
            /// Spot light.
            MURL_DECLARE_ENUM_VALUE(LIGHT_TYPE, SPOT)

            NUM_LIGHT_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(LightType)

        /**
         * @brief Available light projection shapes.
         */
        enum LightShape
        {
            /// A circular light.
            MURL_DECLARE_ENUM_VALUE(LIGHT_SHAPE, CIRCLE)
            /// A rectangular light.
            MURL_DECLARE_ENUM_VALUE(LIGHT_SHAPE, RECTANGLE)

            NUM_LIGHT_SHAPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(LightShape)

        /**
         * @brief Available modes for shadow volume generation.
         */
        enum ShadowVolumeGenerationMode
        {
            /// Default mode.
            MURL_DECLARE_ENUM_VALUE(SHADOW_VOLUME_GENERATION_MODE, DEFAULT)

            /// Do not generate, i.e. directly use present information as a shadow volume.
            MURL_DECLARE_ENUM_VALUE(SHADOW_VOLUME_GENERATION_MODE, NONE)
            /// Generate from geometry data. Adjacency information must be present.
            MURL_DECLARE_ENUM_VALUE(SHADOW_VOLUME_GENERATION_MODE, FROM_GEOMETRY)
            /// Generate from collider data. Bounding leaves must be present.
            MURL_DECLARE_ENUM_VALUE(SHADOW_VOLUME_GENERATION_MODE, FROM_COLLIDER)

            NUM_SHADOW_VOLUME_GENERATION_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ShadowVolumeGenerationMode)

        /**
         * @brief Available modes for shadow map placement.
         */
        enum ShadowMapPlacementMode
        {
            /// Default mode.
            MURL_DECLARE_ENUM_VALUE(SHADOW_MAP_PLACEMENT_MODE, DEFAULT)

            /// Place the shadow map at the center of the actual camera view volume.
            MURL_DECLARE_ENUM_VALUE(SHADOW_MAP_PLACEMENT_MODE, CAMERA_VIEW_VOLUME)
            /// Place the shadow map at the center of the camera's bounding sphere.
            MURL_DECLARE_ENUM_VALUE(SHADOW_MAP_PLACEMENT_MODE, CAMERA_BOUNDING_SPHERE)

            NUM_SHADOW_MAP_PLACEMENT_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ShadowMapPlacementMode)

        /**
         * @brief Available modes for shadow map alignment.
         */
        enum ShadowMapAlignmentMode
        {
            /// Default mode.
            MURL_DECLARE_ENUM_VALUE(SHADOW_MAP_ALIGNMENT_MODE, DEFAULT)

            /// Align the shadow map to the direction of the light casting the shadow.
            MURL_DECLARE_ENUM_VALUE(SHADOW_MAP_ALIGNMENT_MODE, LIGHT_DIRECTION)
            /// Align the shadow map to a fixed plane.
            MURL_DECLARE_ENUM_VALUE(SHADOW_MAP_ALIGNMENT_MODE, FIXED_PLANE)

            NUM_SHADOW_MAP_ALIGNMENT_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ShadowMapAlignmentMode)
        
        /**
         * @brief Available access mode hints for audio/video streams.
         * See IVideoStream or IAudioStream for a detailed description.
         */
        enum StreamMode
        {
            /// Inactive mode.
            MURL_DECLARE_ENUM_VALUE(STREAM_MODE, INACTIVE)
            /// Random access to individual frames or samples.
            MURL_DECLARE_ENUM_VALUE(STREAM_MODE, RANDOM_ACCESS)
            /// Provide a forward sequence of frames or samples.
            MURL_DECLARE_ENUM_VALUE(STREAM_MODE, RUNNING_FORWARD)

            NUM_STREAM_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(StreamMode)

        /**
         * @brief Generic enumeration for horizontal alignment of objects.
         */
        enum AlignmentX
        {
            /// Undefined alignment.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_X, UNDEFINED)

            /// Align at left border.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_X, LEFT)
            /// Horizontal center alignment.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_X, CENTER)
            /// Align at right border.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_X, RIGHT)

            NUM_ALIGNMENTS_X,

            /// Align at negative end (left).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ALIGNMENT_X, NEGATIVE, ALIGNMENT_X_LEFT)
            /// Align at positive end (right).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ALIGNMENT_X, POSITIVE, ALIGNMENT_X_RIGHT)
        };
        MURL_DECLARE_ENUM_ACCESSOR(AlignmentX)

        /**
         * @brief Generic enumeration for vertical alignment of objects.
         */
        enum AlignmentY
        {
            /// Undefined alignment.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Y, UNDEFINED)

            /// Align at bottom border.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Y, BOTTOM)
            /// Vertical center alignment.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Y, CENTER)
            /// Align at top border.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Y, TOP)

            NUM_ALIGNMENTS_Y,

            /// Align at negative end (bottom).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ALIGNMENT_Y, NEGATIVE, ALIGNMENT_Y_BOTTOM)
            /// Align at positive end (top).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ALIGNMENT_Y, POSITIVE, ALIGNMENT_Y_TOP)
        };
        MURL_DECLARE_ENUM_ACCESSOR(AlignmentY)

        /**
         * @brief Generic enumeration for depth alignment of objects.
         */
        enum AlignmentZ
        {
            /// Undefined alignment.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Z, UNDEFINED)

            /// Align at distant border.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Z, BACK)
            /// Depth center alignment.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Z, CENTER)
            /// Align at near border.
            MURL_DECLARE_ENUM_VALUE(ALIGNMENT_Z, FRONT)

            NUM_ALIGNMENTS_Z,

            /// Align at negative end (distant).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ALIGNMENT_Z, NEGATIVE, ALIGNMENT_Z_BACK)
            /// Align at positive end (near).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ALIGNMENT_Z, POSITIVE, ALIGNMENT_Z_FRONT)
        };
        MURL_DECLARE_ENUM_ACCESSOR(AlignmentZ)

        /**
         * @brief Enumeration for text-specific horizontal alignment.
         */
        enum TextAlignmentX
        {
            /// Left alignment.
            MURL_DECLARE_ENUM_VALUE(TEXT_ALIGNMENT_X, LEFT)
            /// Horizontal center alignment.
            MURL_DECLARE_ENUM_VALUE(TEXT_ALIGNMENT_X, CENTER)
            /// Right alignment.
            MURL_DECLARE_ENUM_VALUE(TEXT_ALIGNMENT_X, RIGHT)

            NUM_TEXT_ALIGNMENTS_X
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextAlignmentX)

        /**
         * @brief Enumeration for text-specific vertical alignment.
         */
        enum TextAlignmentY
        {
            /// Top alignment.
            MURL_DECLARE_ENUM_VALUE(TEXT_ALIGNMENT_Y, TOP)
            /// Vertical center alignment.
            MURL_DECLARE_ENUM_VALUE(TEXT_ALIGNMENT_Y, CENTER)
            /// Bottom alignment.
            MURL_DECLARE_ENUM_VALUE(TEXT_ALIGNMENT_Y, BOTTOM)
            /// Alignment along a text's base line.
            MURL_DECLARE_ENUM_VALUE(TEXT_ALIGNMENT_Y, BASE_LINE)

            NUM_TEXT_ALIGNMENTS_Y
        };
        MURL_DECLARE_ENUM_ACCESSOR(TextAlignmentY)

        /**
         * @brief Enumeration for how to calculate the bounding box of an object
         */
        enum ObjectBoundingMode
        {
            /// Bounds are calculated from the object's container.
            MURL_DECLARE_ENUM_VALUE(OBJECT_BOUNDING_MODE, CONTAINER)
            /// Bounds are calculated from the object itself
            MURL_DECLARE_ENUM_VALUE(OBJECT_BOUNDING_MODE, CONTENTS)

            NUM_OBJECT_BOUNDING_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ObjectBoundingMode)

        /**
         * @brief Generic geometry types used for e.g. collision detection in the physics simulator
         */
        enum GeometryType
        {
            /// A single point without dimension.
            MURL_DECLARE_ENUM_VALUE(GEOMETRY_TYPE, POINT)
            /// A ray.
            MURL_DECLARE_ENUM_VALUE(GEOMETRY_TYPE, RAY)
            /// A sphere.
            MURL_DECLARE_ENUM_VALUE(GEOMETRY_TYPE, SPHERE)
            /// An infinite plane.
            MURL_DECLARE_ENUM_VALUE(GEOMETRY_TYPE, PLANE)
            /// A box.
            MURL_DECLARE_ENUM_VALUE(GEOMETRY_TYPE, BOX)
            /// A generic triangle mesh.
            MURL_DECLARE_ENUM_VALUE(GEOMETRY_TYPE, MESH)

            NUM_GEOMETRY_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(GeometryType)

        /**
         * @brief Field types used in the physics simulator.
         */
        enum FieldType
        {
            /// A field influencing the acceleration of a body.
            MURL_DECLARE_ENUM_VALUE(FIELD_TYPE, ACCELERATION)
            /// A field imposing a force on a body.
            MURL_DECLARE_ENUM_VALUE(FIELD_TYPE, FORCE)

            NUM_FIELD_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(FieldType)

        /**
         * @brief Field shapes used in the physics simulator.
         */
        enum FieldShape
        {
            /// A planar field.
            MURL_DECLARE_ENUM_VALUE(FIELD_SHAPE, PLANE)
            /// A spherical field.
            MURL_DECLARE_ENUM_VALUE(FIELD_SHAPE, SPHERE)

            NUM_FIELD_SHAPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(FieldShape)

        /**
         * @brief Individual phases of a single node's traversal
         */
        enum TraversalPhase
        {
            /// Phase 1: Before calling PreProcess*() on all attached controllers.
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, BEFORE_PRE_PROCESS_CONTROLLERS)
            /// Phase 2: After calling PreProcess*() on all attached controllers.
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, AFTER_PRE_PROCESS_CONTROLLERS)

            /// Phase 3: Before calling Process*Self() on the node itself
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, BEFORE_PROCESS_SELF)
            /// Phase 4: After calling Process*Self() on the node itself
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, AFTER_PROCESS_SELF)

            /// Phase 5: Before calling Process*Children() on the node itself
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, BEFORE_PROCESS_CHILDREN)
            /// Phase 6: After calling Process*Children() on the node itself
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, AFTER_PROCESS_CHILDREN)

            /// Phase 7: Before calling PostProcess*() on all attached controllers.
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, BEFORE_POST_PROCESS_CONTROLLERS)
            /// Phase 8: After calling PostProcess*() on all attached controllers.
            MURL_DECLARE_ENUM_VALUE(TRAVERSAL_PHASE, AFTER_POST_PROCESS_CONTROLLERS)

            NUM_TRAVERSAL_PHASES
        };
        MURL_DECLARE_ENUM_ACCESSOR(TraversalPhase)

        /**
         * @brief Individual states modified during scene graph traversal
         */
        enum TraversalState
        {
            /// No state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, NONE,            0)

            /// State of texture unit #0.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_0,       1 << 0)
            /// State of texture unit #1.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_1,       1 << 1)
            /// State of texture unit #2.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_2,       1 << 2)
            /// State of texture unit #3.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_3,       1 << 3)
            /// State of texture unit #4.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_4,       1 << 4)
            /// State of texture unit #5.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_5,       1 << 5)
            /// State of texture unit #6.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_6,       1 << 6)
            /// State of texture unit #7.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURE_7,       1 << 7)

            /// State of light unit #0.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LIGHT_0,         1 << 8)
            /// State of light unit #1.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LIGHT_1,         1 << 9)
            /// State of light unit #2.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LIGHT_2,         1 << 10)
            /// State of light unit #3.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LIGHT_3,         1 << 11)

            /// Material state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, MATERIAL,        1 << 16)
            /// Parameters state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, PARAMETERS,      1 << 17)
            /// Bone state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, BONE,            1 << 18)
            /// Timeline state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TIMELINE,        1 << 19)

            /// Audio culler state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, AUDIO_CULLER,    1 << 20)
            /// Video culler state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, VIDEO_CULLER,    1 << 21)
            /// Camera state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, CAMERA,          1 << 22)
            /// Listener state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LISTENER,        1 << 23)
            /// Layer state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LAYER,           1 << 24)

            /// Physics surface state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, SURFACE,         1 << 25)
            /// Physics island state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, ISLAND,          1 << 26)

            /// Anchor state
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, ANCHOR,          1 << 27)

            /// Flag for automatic state change determination.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, AUTO,            1 << 31)

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, TEXTURES,     (  TRAVERSAL_STATE_TEXTURE_0
                                                                               | TRAVERSAL_STATE_TEXTURE_1
                                                                               | TRAVERSAL_STATE_TEXTURE_2
                                                                               | TRAVERSAL_STATE_TEXTURE_3
                                                                               | TRAVERSAL_STATE_TEXTURE_4
                                                                               | TRAVERSAL_STATE_TEXTURE_5
                                                                               | TRAVERSAL_STATE_TEXTURE_6
                                                                               | TRAVERSAL_STATE_TEXTURE_7))

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LIGHTS,       (  TRAVERSAL_STATE_LIGHT_0
                                                                               | TRAVERSAL_STATE_LIGHT_1
                                                                               | TRAVERSAL_STATE_LIGHT_2
                                                                               | TRAVERSAL_STATE_LIGHT_3))

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, OBJECT,       (  TRAVERSAL_STATE_MATERIAL
                                                                               | TRAVERSAL_STATE_PARAMETERS
                                                                               | TRAVERSAL_STATE_BONE))

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, VIEWER,       (  TRAVERSAL_STATE_AUDIO_CULLER
                                                                               | TRAVERSAL_STATE_VIDEO_CULLER
                                                                               | TRAVERSAL_STATE_CAMERA
                                                                               | TRAVERSAL_STATE_LISTENER
                                                                               | TRAVERSAL_STATE_LAYER))

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, LOGIC,        (  TRAVERSAL_STATE_TIMELINE
                                                                               | TRAVERSAL_STATE_SURFACE
                                                                               | TRAVERSAL_STATE_ISLAND
                                                                               | TRAVERSAL_STATE_ANCHOR))

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, INPUT,        (  TRAVERSAL_STATE_CAMERA
                                                                               | TRAVERSAL_STATE_LISTENER
                                                                               | TRAVERSAL_STATE_LAYER
                                                                               | TRAVERSAL_STATE_ANCHOR))

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, OUTPUT,       (  TRAVERSAL_STATE_TEXTURES
                                                                               | TRAVERSAL_STATE_LIGHTS
                                                                               | TRAVERSAL_STATE_MATERIAL
                                                                               | TRAVERSAL_STATE_PARAMETERS
                                                                               | TRAVERSAL_STATE_BONE
                                                                               | TRAVERSAL_STATE_AUDIO_CULLER
                                                                               | TRAVERSAL_STATE_VIDEO_CULLER
                                                                               | TRAVERSAL_STATE_CAMERA
                                                                               | TRAVERSAL_STATE_LISTENER
                                                                               | TRAVERSAL_STATE_LAYER
                                                                               | TRAVERSAL_STATE_ANCHOR))

            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRAVERSAL_STATE, ALL,          (  TRAVERSAL_STATE_LOGIC
                                                                               | TRAVERSAL_STATE_INPUT
                                                                               | TRAVERSAL_STATE_OUTPUT))
        };
        MURL_DECLARE_ENUM_ACCESSOR(TraversalState)

        /**
         * @brief Generic enumeration of 3-space axes.
         */
        enum Axis
        {
            /// The X axis.
            MURL_DECLARE_ENUM_VALUE(AXIS, X)
            /// The Y axis.
            MURL_DECLARE_ENUM_VALUE(AXIS, Y)
            /// The Z axis.
            MURL_DECLARE_ENUM_VALUE(AXIS, Z)

            /// No axis.
            MURL_DECLARE_ENUM_VALUE(AXIS, NONE)

            NUM_AXES
        };
        MURL_DECLARE_ENUM_ACCESSOR(Axis)

        /**
         * @brief Sort order enumeration
         */
        enum SortOrder
        {
            /// Ascending order.
            MURL_DECLARE_ENUM_VALUE(SORT_ORDER, ASCENDING)
            /// Descending order.
            MURL_DECLARE_ENUM_VALUE(SORT_ORDER, DESCENDING)

            NUM_SORT_ORDERS
        };
        MURL_DECLARE_ENUM_ACCESSOR(SortOrder)

        /**
         * @brief Rotation order enumeration
         */
        enum RotationOrder
        {
            /// ZYX order.
            MURL_DECLARE_ENUM_VALUE(ROTATION_ORDER, ZYX)
            /// ZXY order.
            MURL_DECLARE_ENUM_VALUE(ROTATION_ORDER, ZXY)
            /// YZX order.
            MURL_DECLARE_ENUM_VALUE(ROTATION_ORDER, YZX)
            /// YXZ order.
            MURL_DECLARE_ENUM_VALUE(ROTATION_ORDER, YXZ)
            /// XZY order.
            MURL_DECLARE_ENUM_VALUE(ROTATION_ORDER, XZY)
            /// XYZ order.
            MURL_DECLARE_ENUM_VALUE(ROTATION_ORDER, XYZ)

            NUM_ROTATION_ORDERS
        };
        MURL_DECLARE_ENUM_ACCESSOR(RotationOrder)

        /**
         * @brief Enumeration of different angle measures.
         */
        enum AngleMeasure
        {
            /// Radians, full circle is [0, 2*PI].
            MURL_DECLARE_ENUM_VALUE(ANGLE_MEASURE, RADIANS)
            /// Degrees, full circle is [0, 360].
            MURL_DECLARE_ENUM_VALUE(ANGLE_MEASURE, DEGREES)

            NUM_ANGLE_MEASURES
        };
        MURL_DECLARE_ENUM_ACCESSOR(AngleMeasure)

        /**
         * @brief Enumeration of different length measures.
         */
        enum LengthMeasure
        {
            /// Virtual length unit.
            MURL_DECLARE_ENUM_VALUE(LENGTH_MEASURE, VIRTUAL)
            /// Pixels.
            MURL_DECLARE_ENUM_VALUE(LENGTH_MEASURE, PIXELS)
            /// Millimeters.
            MURL_DECLARE_ENUM_VALUE(LENGTH_MEASURE, MILLIMETERS)
            /// Centimeters.
            MURL_DECLARE_ENUM_VALUE(LENGTH_MEASURE, CENTIMETERS)
            /// Inches.
            MURL_DECLARE_ENUM_VALUE(LENGTH_MEASURE, INCHES)

            NUM_LENGTH_MEASURES
        };
        MURL_DECLARE_ENUM_ACCESSOR(LengthMeasure)

        /**
         * @brief Compression types used for resource conversion.
         */
        enum CompressionType
        {
            /// Default compression
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_TYPE, DEFAULT)

            /// Lossless compression, e.g. for WEBP images
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_TYPE, LOSSLESS)
            /// Lossy compression, e.g. for WEBP images
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_TYPE, LOSSY)

            /// Best compression, e.g. for PNG images
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_TYPE, BEST)

            NUM_COMPRESSION_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(CompressionType)

        /** @} */
    }
}

#endif  // __MURL_I_ENUMS_GRAPH_H__

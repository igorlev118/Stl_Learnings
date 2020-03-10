// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_UTIL_PIXEL_CONVERTER_H__
#define __MURL_UTIL_PIXEL_CONVERTER_H__

#include "murl_i_enums.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief Pixel format conversion class.
         */
        class PixelConverter
        {
        public:
            /**
             * @brief Convert a color to a given pixelformat.
             * @param pixel The destination pixel data.
             * @param format The pixel format to convert to.
             * @param color The color to convert.
             * @return true if successful.
             */
            static Bool ColorToPixel(UInt8Array& pixel, IEnums::PixelFormat format, const Color& color);

            /**
             * @brief Definition of the converter function pointer.
             * Use IEnums::GetPixelFormatByteSize() to calculate the
             * size of the source and destination memory.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            typedef void (*Method)(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer for specified pixel formats.
             * @param destFormat The destination pixel format.
             * @param srcFormat The source pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetConverter(IEnums::PixelFormat destFormat, IEnums::PixelFormat srcFormat);

            /**
             * @brief Get the converter function pointer for a specified pixel format to copy.
             * @param pixelFormat The pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetCopy(IEnums::PixelFormat pixelFormat);
            /**
             * @brief The 1 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy1BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The 2 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy2BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The 3 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy3BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The 4 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy4BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The 6 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy6BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The 8 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy8BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The 12 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy12BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The 16 byte per pixel copy function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to copy.
             */
            static void Copy16BPP(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from L8 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromL8(IEnums::PixelFormat destFormat);
            /**
             * @brief The L8 to LA16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void L8ToLA16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The L8 to RGBA15 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void L8ToRGBA15(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The L8 to RGB16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void L8ToRGB16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The L8 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void L8ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The L8 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void L8ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            static void L8ToLF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void L8ToLF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void L8ToLAF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void L8ToLAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void L8ToRGBF48(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void L8ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void L8ToRGBAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void L8ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from LA16 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromLA16(IEnums::PixelFormat destFormat);
            /**
             * @brief The LA16 to L8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LA16ToL8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The LA16 to RGBA15 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LA16ToRGBA15(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The LA16 to RGB16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LA16ToRGB16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The LA16 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LA16ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The LA16 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LA16ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            static void LA16ToLF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void LA16ToLF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void LA16ToLAF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void LA16ToLAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void LA16ToRGBF48(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void LA16ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void LA16ToRGBAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            static void LA16ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGBA32 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGBA32(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGBA32 to A8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToA8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to L8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToL8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to LA16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToLA16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGBA15 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGBA15(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGB16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGB16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGBA16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGBA16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to R8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToR8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RG16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRG16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to BGRA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToBGRA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to ABGR32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToABGR32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to ARGB32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToARGB32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to AF16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToAF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to LF16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToLF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to LAF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToLAF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RF16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGBF48 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGBF48(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGBAF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGBAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to AF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToAF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to LF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToLF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to LAF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToLAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGBF96 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA32 to RGBAF128 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA32ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGB24 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGB24(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGB24 to A8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToA8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to L8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToL8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to LA16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToLA16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGBA15 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGBA15(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGB16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGB16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGBA16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGBA16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to R8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToR8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RG16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRG16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to BGRA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToBGRA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to ABGR32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToABGR32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to ARGB32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToARGB32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to AF16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToAF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to LF16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToLF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to LAF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToLAF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RF16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRF16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGBF48 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGBF48(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGBAF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGBAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to AF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToAF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to LF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToLF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to LAF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToLAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RF32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRF32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGBF96 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB24 to RGBAF128 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB24ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGB16 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGB16(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGB16 to RGBA15 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB16ToRGBA15(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB16 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB16ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGB16 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGB16ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGBA15 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGBA15(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGBA15 to RGB16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA15ToRGB16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA15 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA15ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBA15 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBA15ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGBAF64 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGBAF64(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGBAF64 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF64ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF64 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF64ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF64 to RGBF48 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF64ToRGBF48(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF64 to RGBF96 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF64ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF64 to RGBAF128 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF64ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGBF48 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGBF48(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGBF48 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF48ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF48 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF48ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF48 to RGBAF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF48ToRGBAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF48 to RGBF96 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF48ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF48 to RGBAF128 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF48ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGBAF128 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGBAF128(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGBAF128 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF128ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF128 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF128ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF128 to RGBF48 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF128ToRGBF48(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF128 to RGBAF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF128ToRGBAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBAF128 to RGBF96 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBAF128ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from RGBF96 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromRGBF96(IEnums::PixelFormat destFormat);
            /**
             * @brief The RGB24 to RGB24 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF96ToRGB24(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF96 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF96ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF96 to RGBF48 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF96ToRGBF48(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF96 to RGBAF64 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF96ToRGBAF64(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The RGBF96 to RGBAF128 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void RGBF96ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);

            /**
             * @brief Get the converter function pointer from LF32 source format.
             * @param destFormat The destination pixel format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromLF32(IEnums::PixelFormat destFormat);
            /**
             * @brief The LF32 to L8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LF32ToL8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The LF32 to RGBA32 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LF32ToRGBA32(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The LF32 to RGBF96 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LF32ToRGBF96(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
            /**
             * @brief The LF32 to RGBAF128 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfPixels The number of pixels to convert.
             */
            static void LF32ToRGBAF128(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfPixels);
        };
    }
}

#endif // __MURL_UTIL_PIXEL_CONVERTER_H__

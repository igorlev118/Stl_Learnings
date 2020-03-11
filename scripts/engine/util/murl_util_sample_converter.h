// Copyright 2013 Spraylight GmbH

#ifndef __MURL_UTIL_SAMPLE_CONVERTER_H__
#define __MURL_UTIL_SAMPLE_CONVERTER_H__

#include "murl_i_enums.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilAudioClasses
         * @brief Sample format conversion class.
         */
        class SampleConverter
        {
        public:
            /**
             * @brief Definition of the converter function pointer.
             * Use IEnums::GetSampleFormatByteSize() to calculate the
             * size of the source and destination memory.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            typedef void (*Method)(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);

            /**
             * @brief Get the converter function pointer for specified sample formats.
             * @param destFormat The destination sample format.
             * @param srcFormat The source sample format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetConverter(IEnums::SampleFormat destFormat, IEnums::SampleFormat srcFormat);

            /**
             * @brief Get the converter function pointer from MONO_8 source format.
             * @param destFormat The destination sample format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromM8(IEnums::SampleFormat destFormat);
            /**
             * @brief The MONO_8 to MONO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M8ToM8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The MONO_8 to MONO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M8ToM16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The MONO_8 to STEREO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M8ToS8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The MONO_8 to STEREO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M8ToS16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);

            /**
             * @brief Get the converter function pointer from MONO_16 source format.
             * @param destFormat The destination sample format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromM16(IEnums::SampleFormat destFormat);
            /**
             * @brief The MONO_16 to MONO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M16ToM8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The MONO_16 to MONO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M16ToM16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The MONO_16 to STEREO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M16ToS8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The MONO_16 to STEREO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void M16ToS16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);

            /**
             * @brief Get the converter function pointer from STEREO_8 source format.
             * @param destFormat The destination sample format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromS8(IEnums::SampleFormat destFormat);
            /**
             * @brief The STEREO_8 to MONO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S8ToM8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The STEREO_8 to MONO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S8ToM16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The STEREO_8 to STEREO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S8ToS8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The STEREO_8 to STEREO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S8ToS16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);

            /**
             * @brief Get the converter function pointer from STEREO_16 source format.
             * @param destFormat The destination sample format.
             * @return The converter function pointer
             *  or null if the conversion is not available.
             */
            static Method GetFromS16(IEnums::SampleFormat destFormat);
            /**
             * @brief The STEREO_16 to MONO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S16ToM8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The STEREO_16 to MONO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S16ToM16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The STEREO_16 to STEREO_8 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S16ToS8(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
            /**
             * @brief The STEREO_16 to STEREO_16 conversion function.
             * @param dstPtr Pointer to the destination memory.
             * @param srcPtr Pointer to the source memory.
             * @param numberOfSamples The number of samples to convert.
             */
            static void S16ToS16(UInt8* dstPtr, const UInt8* srcPtr, UInt32 numberOfSamples);
        };
    }
}

#endif // __MURL_UTIL_SAMPLE_CONVERTER_H__

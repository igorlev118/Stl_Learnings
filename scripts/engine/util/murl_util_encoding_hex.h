// Copyright 2011-2014 Spraylight GmbH

#ifndef __MURL_UTIL_ENCODING_HEX_H__
#define __MURL_UTIL_ENCODING_HEX_H__

#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @addtogroup MurlUtilCodingFunctions
         * @{
         */

        /**
         * @brief Encode a string to a Hex character string.
         * @param dataIn The source string to encode.
         * @return The Hex character encoded string.
         */
        String EncodeHex(const String& dataIn);

        /**
         * @brief Encode a data object to a Hex character string
         * @param dataIn The source data object to encode.
         * @return The Hex character encoded string.
         */
        String EncodeHex(const ConstData& dataIn);

        /**
         * @brief Encode a memory block to a Hex character string
         * @param dataIn Pointer to the source memory block.
         * @param byteSizeIn The byte size of the memory block.
         * @return The Hex character encoded string.
         */
        String EncodeHex(const void* dataIn, UInt64 byteSizeIn);

        /**
         * @brief Decode a Hex character string.
         * @param dataIn The source Hex character string to decode.
         * @return The decoded data object.
         */
        Data DecodeHex(const String& dataIn);

        /**
         * @brief Decode Hex characters from a data object.
         * @param dataIn The source data object to decode.
         * @return The decoded data object.
         */
        Data DecodeHex(const ConstData& dataIn);

        /**
         * @brief Decode Hex characters from a memory block.
         * @param dataIn Pointer to the source memory block.
         * @param byteSizeIn The byte size of the memory block.
         * @return The decoded data object.
         */
        Data DecodeHex(const void* dataIn, UInt64 byteSizeIn);

        /**
         * @brief Encode a memory block to Hex characters.
         * @param dataIn Pointer to the source memory block.
         * @param byteSizeIn The byte size of the source memory block.
         * @param dataOut Pointer to the destination memory block.
         * @param byteSizeOut The byte size of the destination memory block.
         * @return The number of bytes written into destination.
         */
        UInt64 EncodeHex(const void* dataIn, UInt64 byteSizeIn,
                         void* dataOut, UInt64 byteSizeOut);

        /**
         * @brief Decode Hex characters from a memory block.
         * @param dataIn Pointer to the source memory block.
         * @param byteSizeIn The byte size of the source memory block.
         * @param dataOut Pointer to the destination memory block.
         * @param byteSizeOut The byte size of the destination memory block.
         * @return The number of bytes written into destination.
         */
        UInt64 DecodeHex(const void* dataIn, UInt64 byteSizeIn,
                         void* dataOut, UInt64 byteSizeOut);

        /** @} */
    }
}

#endif // __MURL_UTIL_ENCODING_HEX_H__

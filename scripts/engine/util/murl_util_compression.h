// Copyright 2011-2015 Spraylight

#ifndef __MURL_UTIL_COMPRESSION_H__
#define __MURL_UTIL_COMPRESSION_H__

#include "murl_data.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @addtogroup MurlUtilCompressionFunctions
         * @brief Data compression functions.
         * @{
         */

        /**
         * @brief Compress a given data object using ZLib with IEnums::COMPRESSION_LEVEL_DEFAULT.
         * @param uncompressedIn The source data object to compress.
         * @param compressedOut A reference to an empty Data object to receive
         *      the compressed data.
         * @return true if successful.
         */
        Bool Compress(const ConstData& uncompressedIn, Data& compressedOut);

        /**
         * @brief Compress a given data object using ZLib with a specified
         *  compression level.
         * @param uncompressedIn The source data object to compress.
         * @param compressedOut A reference to an empty Data object to receive
         *      the compressed data.
         * @param compressionLevel The compression level.
         * @return true if successful.
         */
        Bool Compress(const ConstData& uncompressedIn, Data& compressedOut,
                      IEnums::CompressionLevel compressionLevel);

        /**
         * @brief Uncompress a given data object using ZLib.
         * @param compressedIn The source data object to decompress.
         * @param uncompressedOut A reference to an empty Data object to receive
         *      the uncompressed data.
         * @return true if successful.
         */
        Bool Uncompress(const ConstData& compressedIn, Data& uncompressedOut);

        /** @} */
    }
}

#endif // __MURL_UTIL_COMPRESSION_H__

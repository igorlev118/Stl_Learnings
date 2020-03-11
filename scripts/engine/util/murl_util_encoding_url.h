// Copyright 2013-2014 Spraylight GmbH

#ifndef __MURL_UTIL_ENCODING_URL_H__
#define __MURL_UTIL_ENCODING_URL_H__

#include "murl_string.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @addtogroup MurlUtilCodingFunctions
         * @{
         */

        /**
         * @brief Encode a string to a url character string (percentage encoding).
         * @param source The source string to encode.
         * @return The url character encoded string.
         */
        String EncodeUrl(const String& source);

        /**
         * @brief Decode a url character string (percentage encoding) to a string.
         * @param source The source url character string to decode.
         * @return The decoded string.
         */
        String DecodeUrl(const String& source);

        /** @} */
    }
}

#endif // __MURL_UTIL_ENCODING_URL_H__

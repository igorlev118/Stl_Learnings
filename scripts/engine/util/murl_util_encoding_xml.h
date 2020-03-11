// Copyright 2013-2014 Spraylight GmbH

#ifndef __MURL_UTIL_ENCODING_XML_H__
#define __MURL_UTIL_ENCODING_XML_H__

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
         * @brief Encode a string so that it can be used as an XML attribute value.
         * @param source The source string to encode.
         * @return The XML encoded string.
         */
        String EncodeXml(const String& source);

        /** @} */
    }
}

#endif // __MURL_UTIL_ENCODING_XML_H__

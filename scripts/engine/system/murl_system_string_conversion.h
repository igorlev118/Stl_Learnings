// Copyright 2014 Spraylight GmbH

#ifndef __MURL_SYSTEM_STRING_CONVERSION_H__
#define __MURL_SYSTEM_STRING_CONVERSION_H__

#include "murl_types.h"

namespace Murl
{
    namespace System
    {
        /**
         * @brief Convert a string to a UInt64 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @param numChars The number of characters consumed return value.
         * @param base The base of the number, if zero the base is octal for
         *  prefix "0", hexadecimal for prefix "0x" or decimal if no prefix.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToUInt64(const String& inputString, UInt64& value, UInt32& numChars, UInt32 base);

        /**
         * @brief Convert a string to a SInt64 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @param numChars The number of characters consumed return value.
         * @param base The base of the number, if zero the base is octal for
         *  prefix "0", hexadecimal for prefix "0x" or decimal if no prefix.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToSInt64(const String& inputString, SInt64& value, UInt32& numChars, UInt32 base);

        /**
         * @brief Convert a string to a UInt32 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @param numChars The number of characters consumed return value.
         * @param base The base of the number, if zero the base is octal for
         *  prefix "0", hexadecimal for prefix "0x" or decimal if no prefix.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToUInt32(const String& inputString, UInt32& value, UInt32& numChars, UInt32 base);

        /**
         * @brief Convert a string to a SInt32 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @param numChars The number of characters consumed return value.
         * @param base The base of the number, if zero the base is octal for
         *  prefix "0", hexadecimal for prefix "0x" or decimal if no prefix.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToSInt32(const String& inputString, SInt32& value, UInt32& numChars, UInt32 base);

        /**
         * @brief Convert a string to a Double value.
         * The conversion ignores leading and trailing whitespaces.
         * The decimal separator is the '.' character (locale independent).
         * @param inputString The string to convert.
         * @param value The return value.
         * @param numChars The number of characters consumed return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToDouble(const String& inputString, Double& value, UInt32& numChars);

        /**
         * @brief Convert a string to a Float value.
         * The conversion ignores leading and trailing whitespaces.
         * The decimal separator is the '.' character (locale independent).
         * @param inputString The string to convert.
         * @param value The return value.
         * @param numChars The number of characters consumed return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToFloat(const String& inputString, Float& value, UInt32& numChars);
    }
}

#endif // __MURL_SYSTEM_STRING_CONVERSION_H__

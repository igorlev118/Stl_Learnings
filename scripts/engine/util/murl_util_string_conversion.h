// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_UTIL_STRING_CONVERSION_H__
#define __MURL_UTIL_STRING_CONVERSION_H__

#include "murl_color.h"
#include "murl_string.h"

namespace Murl
{
    namespace System
    {
        class Time;
    }

    namespace Util
    {
        /**
         * @addtogroup MurlUtilStringConversionFunctions
         * @brief String conversion functions.
         * @{
         */

        /**
         * @brief Convert a decimal string to a bool value.
         * The conversion ignores case, leading and trailing whitespaces.
         * - "true", "on", "yes", "1" or any integer not equal to zero for true.
         * - "false", "off", "no" or "0" for false.
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToBool(const String& inputString, Bool& value);

        /**
         * @brief Convert a decimal string to a UInt64 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToUInt64(const String& inputString, UInt64& value);

        /**
         * @brief Convert a decimal string to a SInt64 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToSInt64(const String& inputString, SInt64& value);

        /**
         * @brief Convert a decimal string to a UInt32 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToUInt32(const String& inputString, UInt32& value);

        /**
         * @brief Convert a decimal string to a SInt32 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToSInt32(const String& inputString, SInt32& value);

        /**
         * @brief Convert a string to a Double value.
         * The conversion ignores leading and trailing whitespaces.
         * The decimal separator is the '.' character (locale independent).
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToDouble(const String& inputString, Double& value);

        /**
         * @brief Convert a string to a Float value.
         * The conversion ignores leading and trailing whitespaces.
         * The decimal separator is the '.' character (locale independent).
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool StringToFloat(const String& inputString, Float& value);

        /**
         * @brief Convert a string to a color object.
         * The conversion ignores case, leading and trailing whitespaces.
         * A color value can be specified by comma separated component values or
         * a single 32 bit hex value:
         *  - "RR, GG, BB, AA" The alpha value is optional, the default alpha is 1.0.
         *  - "AARRGGBBh", e.g. "ff7f3f1fh".
         *  - "RRGGBBh", e.g. "7f3f1fh", alpha is set to 1.0.
         *
         * The component format specifiers are:
         *  - f float component range is [0.0 .. 1.0], e.g. "0.5f, 0.25f, 0.125f, 1.0f".
         *  - i integer component range is [0 .. 255], e.g. "127i, 63i, 31i, 255i".
         *  - h hex component range is [0x00 .. 0xff], e.g. "7fh, 3fh, 1fh, ffh".
         *
         * If a component has no format specifier the float format is assumed.
         * If the string has only one component and the format specifier is missing,
         * the "AARRGGBBh" format is assumed.
         * @param inputString The string to convert.
         * @param value The color return value.
         * @param format This return value is set to the color string format recognized
         *  during conversion, or Color::STRING_FORMAT_UNKNOWN if failed. If different
         *  format specifiers are given, Color::STRING_FORMAT_MIXED is returned, and if
         *  not all of the given components have an explicit specifier, 
         *  Color::STRING_FORMAT_INCOMPLETE is returned.
         * @return true if conversion was successful. If the conversion
         *  failed the 'value' return value is unchanged and false is returned.
         */
        Bool StringToColor(const String& inputString, Color& value, Color::StringFormat& format);
        /**
         * @brief Convert a string to a color object.
         * See StringToColor(const String& inputString, Color& value, Color::StringFormat& format).
         * @param inputString The string to convert.
         * @param value The color return value.
         * @param hasType This return value is set to false if any format specifier is missing.
         * @return true if conversion was successful, if the conversion
         *  failed the 'value' return value is unchanged and false is returned.
         */
        Bool StringToColor(const String& inputString, Color& value, Bool& hasType);
        /**
         * @brief Convert a string to a color object.
         * See StringToColor(const String& inputString, Color& value, Color::StringFormat& format).
         * @param inputString The string to convert.
         * @param value The color return value.
         * @return true if conversion was successful, if the conversion
         *  failed the 'value' return value is unchanged and false is returned.
         */
        Bool StringToColor(const String& inputString, Color& value);

        /**
         * @brief Convert a string to a Float color component.
         * The conversion ignores case, leading and trailing whitespaces.
         * The component format specifiers are:
         *  - f float component range is [0.0 .. 1.0], e.g. "0.5f".
         *  - i integer component range is [0 .. 255], e.g. "127i".
         *  - h hex component range is [0x00 .. 0xff], e.g. "7fh".
         *
         * If the format specifier is missing the float format is assumed.
         * @param inputString The string to convert.
         * @param value The color component return value.
         * @param format This return value is set to the color string format recognized
         *  during conversion, or Color::STRING_FORMAT_UNKNOWN if failed. If different
         *  format specifiers are given, Color::STRING_FORMAT_MIXED is returned, and if
         *  not all of the given components have an explicit specifier,
         *  Color::STRING_FORMAT_INCOMPLETE is returned.
         * @return true if conversion was successful, if the conversion
         *  failed the 'value' return value is unchanged and false is returned.
         */
        Bool StringToColorComponent(const String& inputString, Float& value, Color::StringFormat& format);
        /**
         * @brief Convert a string to a Float color component.
         * See StringToColorComponent(const String& inputString, Float& value, Color::StringFormat& format).
         * @param inputString The string to convert.
         * @param value The color component return value.
         * @param hasType This return value is set to false if any format specifier is missing.
         * @return true if conversion was successful, if the conversion
         *  failed the 'value' return value is unchanged and false is returned.
         */
        Bool StringToColorComponent(const String& inputString, Float& value, Bool& hasType);
        /**
         * @brief Convert a string to a Float color component.
         * See StringToColorComponent(const String& inputString, Float& value, Color::StringFormat& format).
         * @param inputString The string to convert.
         * @param value The color component return value.
         * @return true if conversion was successful, if the conversion
         *  failed the 'value' return value is unchanged and false is returned.
         */
        Bool StringToColorComponent(const String& inputString, Float& value);

        /**
         * @brief Convert a hexadecimal string to a UInt64 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool HexStringToUInt64(const String& inputString, UInt64& value);

        /**
         * @brief Convert a hexadecimal string to a UInt32 value.
         * The conversion ignores leading and trailing whitespaces.
         * @param inputString The string to convert.
         * @param value The return value.
         * @return true if conversion was successful, if the conversion
         *  failed the value parameter is unchanged and false is returned.
         */
        Bool HexStringToUInt32(const String& inputString, UInt32& value);

        /**
         * @brief Convert an angle string to a Double value.
         * The conversion ignores case, leading and trailing whitespaces.
         * An angle string can specify the unit:
         *  - deg or d for degress, e.g. "180 deg"
         *  - rad or r for radiants, e.g. "3.1415 rad"
         *
         * If the unit specifier is missing the radiants unit is assumed.
         * @param inputString The string to convert.
         * @param value The angle return value.
         * @param hasUnit This return value is set to false if the unit specifier is missing.
         * @return true if conversion was successful, if the conversion
         *  failed the 'value' return value is unchanged and false is returned.
         */
        Bool AngleStringToDouble(const String& inputString, Double& value, Bool& hasUnit);

        /**
         * @brief Convert a string to a Bool array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values The return values array.
         * @return true if successful, false if converting the values failed.
         */
        Bool StringToBoolArray(const String& inputString, Char delimiter, BoolArray& values);

        /**
         * @brief Convert a string to a UInt64 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values The return values array.
         * @return true if successful, false if converting the values failed.
         */
        Bool StringToUInt64Array(const String& inputString, Char delimiter, UInt64Array& values);

        /**
         * @brief Convert a string to a SInt64 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values The return values array.
         * @return true if successful, false if converting the values failed.
         */
        Bool StringToSInt64Array(const String& inputString, Char delimiter, SInt64Array& values);

        /**
         * @brief Convert a string to a UInt32 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values The return values array.
         * @return true if successful, false if converting the values failed.
         */
        Bool StringToUInt32Array(const String& inputString, Char delimiter, UInt32Array& values);

        /**
         * @brief Convert a string to a SInt32 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values The return values array.
         * @return true if successful, false if converting the values failed.
         */
        Bool StringToSInt32Array(const String& inputString, Char delimiter, SInt32Array& values);

        /**
         * @brief Convert a string to a Double array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values The return values array.
         * @return true if successful, false if converting the values failed.
         */
        Bool StringToDoubleArray(const String& inputString, Char delimiter, DoubleArray& values);

        /**
         * @brief Convert a string to a Float array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values The return values array.
         * @return true if successful, false if converting the values failed.
         */
        Bool StringToFloatArray(const String& inputString, Char delimiter, FloatArray& values);

        /**
         * @brief Convert a string to a Bool array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values Pointer to the return values array.
         * @param numValues The number of elements to write into the values array.
         * @return The number of elements written to the values array
         *  or zero if the conversion failed.
         */
        UInt32 StringToBoolArray(const String& inputString, Char delimiter, Bool* values, UInt32 numValues);

        /**
         * @brief Convert a string to a UInt64 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values Pointer to the return values array.
         * @param numValues The number of elements to write into the values array.
         * @return The number of elements written to the values array
         *  or zero if the conversion failed.
         */
        UInt32 StringToUInt64Array(const String& inputString, Char delimiter, UInt64* values, UInt32 numValues);

        /**
         * @brief Convert a string to a SInt64 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values Pointer to the return values array.
         * @param numValues The number of elements to write into the values array.
         * @return The number of elements written to the values array
         *  or zero if the conversion failed.
         */
        UInt32 StringToSInt64Array(const String& inputString, Char delimiter, SInt64* values, UInt32 numValues);

        /**
         * @brief Convert a string to a UInt32 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values Pointer to the return values array.
         * @param numValues The number of elements to write into the values array.
         * @return The number of elements written to the values array
         *  or zero if the conversion failed.
         */
        UInt32 StringToUInt32Array(const String& inputString, Char delimiter, UInt32* values, UInt32 numValues);

        /**
         * @brief Convert a string to a SInt32 array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values Pointer to the return values array.
         * @param numValues The number of elements to write into the values array.
         * @return The number of elements written to the values array
         *  or zero if the conversion failed.
         */
        UInt32 StringToSInt32Array(const String& inputString, Char delimiter, SInt32* values, UInt32 numValues);

        /**
         * @brief Convert a string to a Double array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values Pointer to the return values array.
         * @param numValues The number of elements to write into the values array.
         * @return The number of elements written to the values array
         *  or zero if the conversion failed.
         */
        UInt32 StringToDoubleArray(const String& inputString, Char delimiter, Double* values, UInt32 numValues);

        /**
         * @brief Convert a string to a Float array using a given delimiter.
         * @param inputString The string to convert.
         * @param delimiter The delimiter character.
         * @param values Pointer to the return values array.
         * @param numValues The number of elements to write into the values array.
         * @return The number of elements written to the values array
         *  or zero if the conversion failed.
         */
        UInt32 StringToFloatArray(const String& inputString, Char delimiter, Float* values, UInt32 numValues);

        /**
         * @brief Convert a UInt64 value to a string.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        String UInt64ToString(UInt64 inputValue);

        /**
         * @brief Convert a SInt64 value to a string.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        String SInt64ToString(SInt64 inputValue);

        /**
         * @brief Convert a UInt32 value to a string.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        String UInt32ToString(UInt32 inputValue);

        /**
         * @brief Convert a SInt32 value to a string.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        String SInt32ToString(SInt32 inputValue);

        /**
         * @brief Convert a Double value to a string.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        String DoubleToString(Double inputValue);

        /**
         * @brief Convert a Color object to a string in float representation.
         * @param inputValue The color to convert.
         * @return The converted string.
         */
        String ColorToString(const Color& inputValue);

        /**
         * @brief Convert a Color object to a string using a given color string format.
         * @param inputValue The color to convert.
         * @param colorStringFormat The color string format.
         * @return The converted string.
         */
        String ColorToString(const Color& inputValue, Color::StringFormat colorStringFormat);

        /**
         * @brief Convert a UInt64 value to a string using a format string.
         * @param inputValue The value to convert.
         * @param format The format string should contain "%llu".
         * @return The converted string.
         */
        String UInt64ToString(UInt64 inputValue, const String& format);

        /**
         * @brief Convert a SInt64 value to a string using a format string.
         * @param inputValue The value to convert.
         * @param format The format string should contain "%lld".
         * @return The converted string.
         */
        String SInt64ToString(SInt64 inputValue, const String& format);

        /**
         * @brief Convert a UInt32 value to a string using a format string.
         * @param inputValue The value to convert.
         * @param format The format string should contain "%u".
         * @return The converted string.
         */
        String UInt32ToString(UInt32 inputValue, const String& format);

        /**
         * @brief Convert a SInt32 value to a string using a format string.
         * @param inputValue The value to convert.
         * @param format The format string should contain "%d".
         * @return The converted string.
         */
        String SInt32ToString(SInt32 inputValue, const String& format);

        /**
         * @brief Convert a Double value to a string using a format string.
         * @param inputValue The value to convert.
         * @param format The format string should contain "%f" or "%g".
         * @return The converted string.
         */
        String DoubleToString(Double inputValue, const String& format);

        /**
         * @brief Convert a Color object to a string in float representation.
         * @param inputValue The color to convert.
         * @param format The format string should contain "%f" or "%g".
         * @return The converted string.
         */
        String ColorToString(const Color& inputValue, const String& format);

        /**
         * @brief Convert a Color object to a string using a given color string format.
         * @param inputValue The color to convert.
         * @param colorStringFormat The color string format
         * @param format The format string should contain "%f" or "%g" for
         *  Color::STRING_FORMAT_FLOAT, "%i" or "%x" (or similar) for int and hex formats.
         * @return The converted string.
         */
        String ColorToString(const Color& inputValue, Color::StringFormat colorStringFormat, const String& format);

        /**
         * @brief Convert a Bool value to a string.
         * @param inputValue The value to convert.
         * @return The converted string "true" or "false".
         */
        String BoolToString(Bool inputValue);

        /**
         * @brief Convert a time value to a string.
         * @param inputValue The value to convert.
         * @return The converted string "h:mm:ss".
         */
        String TimeToString(const System::Time& inputValue);

        /**
         * @brief Convert a time value to a string using a separator.
         * @param inputValue The value to convert.
         * @param separator The separator string.
         * @return The converted string "h[separator]mm[separator]ss".
         */
        String TimeToString(const System::Time& inputValue, const String& separator);

        /**
         * @brief Convert an UTF8 character sequence to a wide-character.
         * For string operation the String class provides the GetWChars() method.
         * @param inputBytes Pointer to the UTF8 character(s).
         * @param numToSkip Return value parameter returning the number of input bytes
         *  to skip to the next UTF8 character.
         * @param outputValues Pointer to the wide-character(s).
         * @param numValues In/out parameter. Must contain the number of values available
         *  in the output buffer; receives the actual number of values converted,
         *  on success. If the given number of values is smaller than the number of
         *  values needed, false is returned.
         * @return true if successful.
         */
        Bool Utf8ToWChar(const Char* inputBytes, UInt32& numToSkip,
                         WChar* outputValues, UInt32& numValues);

        /**
         * @brief Convert a wide-character to an UTF8 character sequence.
         * For string operation the String class provides the SetWChars() method.
         * @param inputValues Pointer to the wide-character(s).
         * @param numToSkip Return value parameter returning the number of input values
         *  (not the number of bytes!) to skip to the next wide-character.
         * @param outputBytes Pointer to a memory block to receive the converted bytes.
         * @param numBytes In/out parameter. Must contain the number of bytes available
         *  in the output buffer; receives the actual number of bytes converted,
         *  on success. If the given number of bytes is smaller than the number of
         *  bytes needed, false is returned.

         * @return true if successful.
         */
        Bool WCharToUtf8(const WChar* inputValues, UInt32& numToSkip,
                         Char* outputBytes, UInt32& numBytes);

        /**
         * @brief Convert an UTF8 character sequence to an UTF16 character.
         * For string operation the String class provides the GetUTF16Chars() method.
         * @param inputBytes Pointer to the UTF8 character(s).
         * @param numToSkip Return value parameter returning the number of input bytes
         *  to skip to the next UTF8 character.
         * @param outputValues Pointer to the UTF-16 character(s).
         * @param numValues In/out parameter. Must contain the number of values available
         *  in the output buffer; receives the actual number of values converted,
         *  on success. If the given number of values is smaller than the number of
         *  values needed, false is returned.
         * @return true if successful.
         */
        Bool Utf8ToUtf16(const Char* inputBytes, UInt32& numToSkip,
                         UInt16* outputValues, UInt32& numValues);

        /**
         * @brief Convert an UTF16 character to an UTF8 character sequence.
         * For string operation the String class provides the SetUTF16Chars() method.
         * @param inputValues Pointer to the UTF16 character(s).
         * @param numToSkip Return value parameter returning the number of input values
         *  (not the number of bytes!) to skip to the next UTF16 character.
         * @param outputBytes Pointer to a memory block to receive the converted bytes.
         * @param numBytes In/out parameter. Must contain the number of bytes available
         *  in the output buffer; receives the actual number of bytes converted,
         *  on success. If the given number of bytes is smaller than the number of
         *  bytes needed, false is returned.
         * @return true if successful.
         */
        Bool Utf16ToUtf8(const UInt16* inputValues, UInt32& numToSkip,
                         Char* outputBytes, UInt32& numBytes);

        /**
         * @brief Convert an UTF8 character sequence to an UTF32 character.
         * For string operation the String class provides the GetUTF32Chars() method.
         * @param inputBytes Pointer to the UTF8 character(s).
         * @param outputValue The UTF-32 character return value.
         * @param numToSkip Return value parameter returning the number of input bytes
         *  to skip to the next UTF8 character.
         * @return true if successful.
         */
        Bool Utf8ToUtf32(const Char* inputBytes, UInt32& outputValue, UInt32& numToSkip);

        /**
         * @brief Convert an UTF32 character to an UTF8 character sequence.
         * For string operation the String class provides the SetUTF32Chars() method.
         * @param inputValue The UTF32 character.
         * @param outputBytes Pointer to a memory block to receive the converted bytes.
         * @param numBytes In/out parameter. Must contain the number of bytes available
         *  in the output buffer; receives the actual number of bytes converted,
         *  on success. If the given number of bytes is smaller than the number of
         *  bytes needed, false is returned.
         * @return true if successful.
         */
        Bool Utf32ToUtf8(UInt32 inputValue, Char* outputBytes, UInt32& numBytes);

        /**
         * @brief ValueToString overload for UInt64ToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(UInt64 inputValue)
        {
            return UInt64ToString(inputValue);
        }

        /**
         * @brief ValueToString overload for SInt64ToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(SInt64 inputValue)
        {
            return SInt64ToString(inputValue);
        }

        /**
         * @brief ValueToString overload for UInt32ToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(UInt32 inputValue)
        {
            return UInt32ToString(inputValue);
        }

        /**
         * @brief ValueToString overload for SInt32ToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(SInt32 inputValue)
        {
            return SInt32ToString(inputValue);
        }

        /**
         * @brief ValueToString overload for DoubleToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(Double inputValue)
        {
            return DoubleToString(inputValue);
        }

        /**
         * @brief ValueToString overload for ColorToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(const Color& inputValue)
        {
            return ColorToString(inputValue);
        }

        /**
         * @brief ValueToString overload for BoolToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(Bool inputValue)
        {
            return BoolToString(inputValue);
        }

        /**
         * @brief ValueToString overload for TimeToString() method.
         * @param inputValue The value to convert.
         * @return The converted string.
         */
        inline String ValueToString(const System::Time& inputValue)
        {
            return TimeToString(inputValue);
        }
        
        /** @} */
    }
}

#endif // __MURL_UTIL_STRING_CONVERSION_H__

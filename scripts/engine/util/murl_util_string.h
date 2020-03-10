// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_UTIL_STRING_H__
#define __MURL_UTIL_STRING_H__

#include "murl_util_string_conversion.h"
#include "murl_util_string_name.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @addtogroup MurlUtilStringFunctions
         * @brief String manipulation and test functions.
         * @{
         */

        /**
         * @brief Get the reference to a static empty string.
         * @return The reference to a static empty string.
         */
        const String& StaticEmptyString();

        /**
         * @brief Get the reference to a static whitespace string.
         * The whitespace string contains the characters:
         * @code
         *  " \t\r\n"
         * @endcode
         * @return The reference to a static whitespace string.
         */
        const String& StaticWhitespaceString();

        /**
         * @brief Get the reference to a static empty string array.
         * @return The reference to a static empty string array.
         */
        const StringArray& StaticEmptyStringArray();

        /**
         * @brief Print formatted variadic arguments into string.
         * @param format The format string.
         * @param ... The variadic arguments.
         * @return The string with the printed arguments.
         */
        String PrintToString(const Char* format, ...);

        /**
         * @brief Split a string into pieces using a given delimiter, the pieces
         * are stored in a string array.
         * @param inputString The string to split.
         * @param delimiter The delimiter character.
         * @param pieces The pieces return value.
         * @param acceptEmpty If true, also empty pieces are accepted, i.e. subsequent
         *  pieces are considered to be separated by a single delimiter only.
         * @return The number of pieces.
         */
        UInt32 SplitString(const String& inputString, Char delimiter, StringArray& pieces, Bool acceptEmpty = false);

        /**
         * @brief Split a string into pieces using a given delimiter, the pieces
         * are stored in a string index.
         * @param inputString The string to split.
         * @param delimiter The delimiter character.
         * @param pieces The pieces return value.
         * @param acceptEmpty If true, also empty pieces are accepted, i.e. subsequent
         *  pieces are considered to be separated by a single delimiter only.
         * @return The number of pieces.
         */
        UInt32 SplitString(const String& inputString, Char delimiter, StringIndex& pieces, Bool acceptEmpty = false);

        /**
         * @brief Split a string into pieces using a given set of delimiters, the pieces
         * are stored in a string array.
         * @param inputString The string to split.
         * @param delimiters A string containing all delimiter characters.
         * @param pieces The pieces return value.
         * @param acceptEmpty If true, also empty pieces are accepted, i.e. subsequent
         *  pieces are considered to be separated by a single delimiter only.
         * @return The number of pieces.
         */
        UInt32 SplitString(const String& inputString, const String& delimiters, StringArray& pieces, Bool acceptEmpty = false);

        /**
         * @brief Split a string into pieces using a given set of delimiters, the pieces
         * are stored in a string index.
         * @param inputString The string to split.
         * @param delimiters A string containing all delimiter characters.
         * @param pieces The pieces return value.
         * @param acceptEmpty If true, also empty pieces are accepted, i.e. subsequent
         *  pieces are considered to be separated by a single delimiter only.
         * @return The number of pieces.
         */
        UInt32 SplitString(const String& inputString, const String& delimiters, StringIndex& pieces, Bool acceptEmpty = false);

        /**
         * @brief Join all strings from a string array.
         * @param inputStrings The string array to join.
         * @param separator The separator string to separate the input strings.
         * @param joinEmpty If true, also empty strings are added from the input strings.
         * @return The joined string.
         */
        String JoinStringArray(const StringArray& inputStrings, const String& separator, Bool joinEmpty = false);

        /**
         * @brief Join all strings from a string index.
         * @param inputStrings The string index to join.
         * @param separator The separator string to separate the input strings.
         * @param joinEmpty If true, also empty strings are added from the input strings.
         * @return The joined string.
         */
        String JoinStringIndex(const StringIndex& inputStrings, const String& separator, Bool joinEmpty = false);

        /**
         * @brief Indent a (multi-line) string by a given number of white spaces.
         * @param inputString The string to indent.
         * @param indent The number of spaces to indent. If this is negative, the given
         *  number of spaces are removed from the beginning of each line, if present.
         * @param indentEmpty If false, empty lines are not processed (default).
         * @return The processed string.
         */
        String IndentString(const String& inputString, SInt32 indent, Bool indentEmpty = false);

        /**
         * @brief Fill in a set of given parameters into a placeholder string.
         * A placeholder is represented by a zero-based integer within curly braces,
         * e.g. "{0}", "{7}" or "{42}" (without quotes). The integer represents the
         * index into the given parameters array.
         * @param inputString The placeholder string.
         * @param parameters An array of string holding the individual parameters.
         * @return The processed string.
         */
        String FillInParameters(const String& inputString, const StringArray& parameters);

        /**
         * @brief Trim all strings in a string array.
         * Trim white spaces from left and right for each string in the array.
         * @param inputString The string array to trim.
         */
        void TrimStringArray(StringArray& inputString);

        /**
         * @brief Get a line from a string.
         * @param inputString The string to get the line from.
         * @param startPos The start position to get the line from.
         *  The start position is set to the beginning of the next line
         *  or to -1 if the end of the input string is reached.
         * @return The line string.
         */
        String GetLine(const String& inputString, SInt32& startPos);

        /**
         * @brief Get the next word from a string.
         * @param inputString The string to get the word from.
         * @param startPos The start position to get the word from.
         *  The start position is set to the beginning of the next word
         *  or to -1 if the end of the input string is reached.
         * @return The word string.
         */
        String GetWord(const String& inputString, SInt32& startPos);

        /**
         * @brief Check if a class name has a "::" part.
         * @param className The class name string.
         * @return true if the class name contains a "::" part.
         */
        Bool HasCppScope(const String& className);

        /**
         * @brief Get the class name substring before the "::" part.
         * @param className The class name string.
         * @return The class name substring before the "::" part.
         *  If the "::" part is not found an empty string is returned.
         */
        String GetCppScope(const String& className);

        /**
         * @brief Get the class name substring behind the "::" part.
         * @param className The class name string.
         * @return The class name substring behind the "::" part.
         *  If the "::" part is not found an empty string is returned.
         */
        String StripCppScope(const String& className);

        /**
         * @brief Check if a name has a dot character.
         * @param name The name string.
         * @return true if the name contains a '.' character.
         */
        Bool HasScope(const String& name);

        /**
         * @brief Get the substring before the dot character.
         * @param name The name string.
         * @return The name substring before the '.' character.
         *  If the '.' character is not found an empty string is returned.
         */
        String GetScope(const String& name);

        /**
         * @brief Get the substring behind the dot character.
         * @param name The name string.
         * @return The name substring behind the '.' character.
         *  If the '.' character is not found an empty string is returned.
         */
        String StripScope(const String& name);

        /**
         * @brief Strip the index part from a name and get the index value.
         * For example, the input string "param[7]" will be split so that the
         * "name" variable contains the string "param", and index is set to 7.
         * @param name The name string to strip.
         * @param index The index return value.
         * @param trimOutput If true, leading and trailing whitespaces are
         *      removed from the name after stripping.
         * @return true if successful.
         */

        Bool StripIndex(String& name, UInt32& index, Bool trimOutput = true);
        /**
         * @brief Strip the count part from a name and get its value.
         * For example, the input string "param7" will be split so that the
         * "name" variable contains the string "param", and count is set to 7.
         * @param name The name string to strip.
         * @param count The count return value.
         * @param trimOutput If true, leading and trailing whitespaces are
         *      removed from the name after stripping.
         * @return true if successful.
         */
        Bool StripCount(String& name, UInt32& count, Bool trimOutput = true);

        /**
         * @brief Check if an identifier string is valid.
         * A valid identifer contains:
         *  - Alphanumeric characters and '.', '_', '{', '}'.
         *  - No leading numeric characters.
         * @param identifier The identifer string to check.
         * @return true if the identifier string is valid.
         */
        Bool IsIdValid(const String& identifier);

        /**
         * @brief Check if a string has numeric characters only.
         * A leading '+' or '-' character is allowed.
         * @param str The string to check.
         * @return true if the string has numeric characters only.
         */
        Bool IsNumeric(const String& str);

        /**
         * @brief Check if a string has alphanumeric characters only.
         * @param str The string to check.
         * @return true if the string has alphanumeric characters only.
         */
        Bool IsAlphaNumeric(const String& str);

        /**
         * @brief Check if a character is a digit character.
         * @param chr The character to check.
         * @return true if the character is a digit character.
         */
        inline Bool IsDigit(Char chr)
        {
            return (chr >= '0') && (chr <= '9');
        }

        /**
         * @brief Check if a character is an alphabetic character.
         * @param chr The character to check.
         * @return true if the character is an alphabetic character.
         */
        inline Bool IsAlpha(Char chr)
        {
            return ((chr >= 'A') && (chr <= 'Z')) || ((chr >= 'a') && (chr <= 'z'));
        }

        /**
         * @brief Check if a character is an alphanumeric character.
         * @param chr The character to check.
         * @return true if the character is an alphanumeric character.
         */
        inline Bool IsAlphaNumeric(Char chr)
        {
            return IsDigit(chr) || IsAlpha(chr);
        }

        /**
         * @brief Check if a character is a punctuation character.
         * @param chr The character to check.
         * @return true if the character is a punctuation character.
         */
        inline Bool IsPunctuation(Char chr)
        {
            return (chr != ' ') && !IsAlphaNumeric(chr);
        }

        /**
         * @brief Check if a character is a spacing character.
         * A whitespace is a space, form feed '\\f', newline '\\n',
         * carriage return '\\r', vertical tabulator '\\v' or
         * horizontal tabulator '\\t' character.
         * @param chr The character to check.
         * @return true if the character is a spacing character.
         */
        inline Bool IsSpace(Char chr)
        {
            return (chr == ' ')  || (chr == '\f') || (chr == '\n') ||
            (chr == '\r') || (chr == '\v') || (chr == '\t');
        }

        /**
         * @brief Check if a character is a hexadecimal character.
         * @param chr The character to check.
         * @return true if the character is a hexadecimal character.
         */
        inline Bool IsHexDigit(Char chr)
        {
            return IsDigit(chr) ||
            ((chr >= 'A') && (chr <= 'F')) || ((chr >= 'a') && (chr <= 'f'));
        }

        /**
         * @brief Check if a character is a control character.
         * @param chr The character to check.
         * @return true if the character is a control character.
         */
        inline Bool IsControl(Char chr)
        {
            return (chr >= 0) && (chr <= 31);
        }

        /** @} */
    }
}

#endif // __MURL_UTIL_STRING_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_STRING_H__
#define __MURL_STRING_H__

#include "murl_array.h"

namespace Murl
{
    class Color;

    namespace System
    {
        class Time;
    }

    /**
     * @ingroup MurlClasses
     * @brief A string class.
     * The string class contains an array of byte characters which
     * can store an 8 bit encoded string or an UTF-8 encoded string.
     * The array of characters is zero terminated.
     * \n A C-string is a pointer to an array of byte characters which
     * is zero-terminated.
     * \n This class is based on the NTL String container, see http://www.ultimatepp.org
     */
    class String
    {
    public:
        /**
         * @brief Construct an empty string.
         */
        String()
        {
            Zero();
        }

        /**
         * @brief Construct using a given string.
         * @param str The original string.
         */
        String(const String& str)
        {
            Set(str);
        }

        /**
         * @brief Construct a copy from a given C-string.
         * @param str The C-string to copy.
         */
        String(const Char* str)
        {
            Set(str, StringLength(str));
        }

        /**
         * @brief Construct a copy of a given string and length.
         * Verify (assert in debug build) 'length' against the length of 'str'.
         * @param str The string to copy.
         * @param length The number of bytes to copy.
         */
        String(const String& str, SInt32 length)
        {
            if (MURL_VERIFY((length >= 0) && (length <= str.GetLength())))
            {
                Set(str.Begin(), length);
            }
            else
            {
                Zero();
            }
        }

        /**
         * @brief Construct a copy from a given C-string & length.
         * @param str The C-string to copy.
         * @param length The number of bytes to copy.
         */
        String(const Char* str, SInt32 length)
        {
            Set(str, length);
        }

        /**
         * @brief Construct a copy from a given byte pointer and length.
         * @param str The byte pointer to copy.
         * @param length The number of bytes to copy.
         */
        String(const UInt8* str, SInt32 length)
        {
            Set(reinterpret_cast<const Char*>(str), length);
        }

        /**
         * @brief Construct and fill a string with a given character and length.
         * @param charCode The character code to fill.
         * @param length The number of bytes to fill.
         */
        String(Char charCode, SInt32 length)
        {
            Zero();
            Cat(charCode, length);
        }

        /**
         * @brief Destroy the string.
         */
        ~String()
        {
            Free();
        }

        /**
         * @brief Clear the string and remove the underlying storage.
         */
        void Clear()
        {
            Free();
            Zero();
        }

        /**
         * @brief Shrink the string so that the underlying storage is only as large as necessary.
         */
        void Shrink()
        {
            *this = String(Begin(), GetLength());
        }

        /**
         * @brief Reserve additional storage space.
         * @param count The number of additional bytes to reserve.
         * @return true if successful.
         */
        Bool Reserve(SInt32 count)
        {
            SInt32 l = GetLength();
            if (Insert(l, count, 0) != 0)
            {
                return CutAt(l);
            }
            return false;
        }

        /**
         * @brief Cut the string on a given position.
         * Verify (assert in debug build) 'pos' against the string length.
         * @param pos The position to cut the string.
         * @return true if successful.
         */
        Bool CutAt(SInt32 pos);

        /**
         * @brief Trim white spaces from left and right.
         * @return The trimmed string.
         */
        String Trim() const;

        /**
         * @brief Trim white spaces from left.
         * @return The trimmed string.
         */
        String TrimLeft() const;

        /**
         * @brief Trim white spaces from right.
         * @return The trimmed string.
         */
        String TrimRight() const;

        /**
         * @brief Get the lower case string including UTF-8 characters.
         * @return The lower case UTF-8 string.
         */
        String ToLowerUTF8() const;

        /**
         * @brief Get the upper case string including UTF-8 characters.
         * @return The upper case UTF-8 string.
         */
        String ToUpperUTF8() const;

        /**
         * @brief Count the number of UTF-8 characters.
         * @return The number of UTF-8 characters.
         */
        SInt32 GetLengthUTF8() const;

        /**
         * @brief Get a UTF-8 character at a specified position.
         * Verify (assert in debug build) 'pos' against the string length.
         * @param pos The byte position to get the character from.
         * @return The UTF-8 character at the specified position,
         *  or an empty string if the position is out of range.
         */
        String GetUTF8Char(SInt32 pos) const;

        /**
         * @brief Get the UTF-8 characters.
         * @return The UTF-8 characters string array.
         */
        StringArray GetUTF8Chars() const;

        /**
         * @brief Get the wide-characters.
         * @return The wide-characters array, if the
         *  conversion fails the characters array is empty.
         */
        WCharArray GetWChars() const
        {
            WCharArray wcharArray;
            if (!GetWChars(wcharArray))
            {
                wcharArray.Clear();
            }
            return wcharArray;
        }

        /**
         * @brief Get the wide-characters and success status.
         * @param wcharArray The wide-characters array return value.
         * @return true if successful, if conversion fails the wcharArray
         *  contains the already converted characters and false is returned.
         */
        Bool GetWChars(WCharArray& wcharArray) const;

        /**
         * @brief Get the UTF-16 characters.
         * @return The UTF-16 characters array, if the
         *  conversion fails the characters array is empty.
         */
        UInt16Array GetUTF16Chars() const
        {
            UInt16Array utf16Array;
            if (!GetUTF16Chars(utf16Array))
            {
                utf16Array.Clear();
            }
            return utf16Array;
        }

        /**
         * @brief Get the UTF-16 characters and success status.
         * @param utf16Array The UTF-16 characters array return value.
         * @return true if successful, if conversion fails the utf16Array
         *  contains the already converted characters and false is returned.
         */
        Bool GetUTF16Chars(UInt16Array& utf16Array) const;

        /**
         * @brief Get the UTF-32 characters.
         * @return The UTF-32 characters array, if the
         *  conversion fails the characters array is empty.
         */
        UInt32Array GetUTF32Chars() const
        {
            UInt32Array utf32Array;
            if (!GetUTF32Chars(utf32Array))
            {
                utf32Array.Clear();
            }
            return utf32Array;
        }

        /**
         * @brief Get the UTF-32 characters and success status.
         * @param utf32Array The UTF-32 characters array return value.
         * @return true if successful, if conversion fails the utf32Array
         *  contains the already converted characters and false is returned.
         */
        Bool GetUTF32Chars(UInt32Array& utf32Array) const;

        /**
         * @brief Set UTF-8 characters from a wide-character string.
         * @param wcharArray The wide-characters array.
         * @return true if successful, if conversion fails this String
         *  contains the already converted characters and false is returned.
         */
        Bool SetWChars(const WCharArray& wcharArray);

        /**
         * @brief Set UTF-8 characters from a wide-character string pointer.
         * @param wcharArray A pointer to the zero-terminated wide-characters.
         * @return true if successful, if conversion fails this String
         *  contains the already converted characters and false is returned.
         */
        Bool SetWChars(const WChar* wcharArray);

        /**
         * @brief Set UTF-8 characters from an UTF16 string.
         * @param utf16Array The UTF-16 characters array.
         * @return true if successful, if conversion fails this String
         *  contains the already converted characters and false is returned.
         */
        Bool SetUTF16Chars(const UInt16Array& utf16Array);

        /**
         * @brief Set UTF-8 characters from an UTF16 string pointer.
         * @param utf16Array A pointer to the zero-terminated UTF16 characters.
         * @return true if successful, if conversion fails this String
         *  contains the already converted characters and false is returned.
         */
        Bool SetUTF16Chars(const UInt16* utf16Array);

        /**
         * @brief Set UTF-8 characters from an UTF32 string.
         * @param utf32Array The UTF-32 characters array.
         * @return true if successful, if conversion fails this String
         *  contains the already converted characters and false is returned.
         */
        Bool SetUTF32Chars(const UInt32Array& utf32Array);

        /**
         * @brief Set UTF-8 characters from an UTF32 string pointer.
         * @param utf32Array A pointer to the zero-terminated UTF32 characters.
         * @return true if successful, if conversion fails this String
         *  contains the already converted characters and false is returned.
         */
        Bool SetUTF32Chars(const UInt32* utf32Array);

        /**
         * @brief Append all strings from an string array.
         * @param stringArray The string array to append.
         * @return The string itself.
         */
        String& Cat(const StringArray& stringArray)
        {
            for (SInt32 i = 0; i < stringArray.GetCount(); i++)
            {
                Cat(stringArray[i]);
            }
            return *this;
        }

        /**
         * @brief Remove the last character from the string including UTF-8.
         * @return true if successful, false is string is empty.
         */
        Bool RemoveLastUTF8();

        /**
         * @brief Get a character at a specified position.
         * Verify (assert in debug build) 'pos' against the string length.
         * @param pos The byte position to get the character from.
         * @return The character at the specified position,
         *  or 0 if the position is out of range.
         */
        Char GetChar(SInt32 pos) const
        {
            if (MURL_VERIFY((pos >= 0) && (pos <= GetLength())))
            {
                return Begin()[pos];
            }
            return 0;
        }

        /**
         * @brief Set a character.
         * Verify (assert in debug build) 'pos' against the string length.
         * @param pos The byte position.
         * @param charCode The character code to set.
         * @return true if successful.
         */
        Bool Set(SInt32 pos, Char charCode)
        {
            if (!MURL_VERIFY((pos >= 0) && (pos < GetLength())))
            {
                return false;
            }
            UnShare();
            Ptr()[pos] = charCode;
            return true;
        }

        /**
         * @brief Set to a given string.
         * @param str The string to set.
         */
        void Set(const String& str)
        {
            if (str.IsSmall())
            {
                SetSmall(str);
            }
            else
            {
                LSet(str);
            }
            Dsyn();
        }

        /**
         * @brief Set to a given string and length.
         * @param str The string to copy.
         * @param length The number of bytes to copy.
         */
        void Set(const Char* str, SInt32 length);

        /**
         * @brief Insert a character.
         * @param pos The byte position to insert.
         * @param charCode The character code to insert.
         * @return true if successful.
         */
        Bool Insert(SInt32 pos, Char charCode)
        {
            Char* ptr = Insert(pos, 1, 0);
            if (ptr != 0)
            {
                *ptr = charCode;
            }
            return false;
        }

        /**
         * @brief Insert a C-string & length.
         * @param pos The byte position to insert.
         * @param str The C-string to insert.
         * @param count The number of bytes to insert.
         * @return true if successful.
         */
        Bool Insert(SInt32 pos, const Char* str, SInt32 count)
        {
            return (Insert(pos, count, str) != 0);
        }

        /**
         * @brief Insert a string.
         * @param pos The byte position to insert.
         * @param str The string to insert.
         * @return true if successful.
         */
        Bool Insert(SInt32 pos, const String& str)
        {
            return (Insert(pos, str, str.GetLength()) != 0);
        }

        /**
         * @brief Insert a C-string.
         * @param pos The byte position to insert.
         * @param str The C-string to insert.
         * @return true if successful.
         */
        Bool Insert(SInt32 pos, const Char* str)
        {
            return (Insert(pos, str, StringLength(str)) != 0);
        }

        /**
         * @brief Remove character(s).
         * Verify (assert in debug build) 'pos' and 'count' against the string length.
         * @param pos The byte position to remove.
         * @param count The number of characters to remove.
         * @return true if successful.
         */
        Bool Remove(SInt32 pos, SInt32 count = 1);

        /**
         * @brief Remove all occurrences of a character.
         * @param character The character to remove.
         * @return The number of characters removed.
         */
        SInt32 RemoveChar(Char character);

        /**
         * @brief Append a C-string.
         * @param str The C-string to append.
         * @return The string itself.
         */
        String& Cat(const Char* str)
        {
            return Cat(str, StringLength(str));
        }

        /**
         * @brief Append a string.
         * @param str The string to append.
         * @return The string itself.
         */
        String& Cat(const String& str)
        {
            return Cat(str.Begin(), str.GetLength());
        }

        /**
        * @brief Append one UTF-32 character.
        * @param utf32CharCode The UTF-32 character code to append.
        * @return true if successful.
        */
        Bool AppendUtf32(UInt32 utf32CharCode);

        /**
        * @brief Append UTF-32 characters.
        * @param utf32CharCode The UTF-32 character code to append.
        * @param count The number of characters to append.
        * @return true if successful.
        */
        Bool AppendUtf32(UInt32 utf32CharCode, SInt32 count);

        /**
        * @brief Append UTF-32 characters from a given pointer and length.
        * @param utf32str The UTF-32 pointer to append.
        * @param length The number of bytes to copy.
        * @return true if successful.
        */
        Bool AppendUtf32(const UInt32* utf32str, SInt32 length);

        /**
         * @brief Append characters.
         * @param charCode The character code to append.
         * @param count The number of characters to append.
         * @return The string itself.
         */
        String& Cat(Char charCode, SInt32 count);

        /**
         * @brief Append from a given string and length.
         * @param str The string to append.
         * @param length The number of bytes to copy.
         * @return The string itself.
         */
        String& Cat(const String& str, SInt32 length)
        {
            return Cat(str.Begin(), length);
        }

        /**
         * @brief Append from a given byte pointer and length.
         * @param str The byte pointer to append.
         * @param length The number of bytes to copy.
         * @return The string itself.
         */
        String& Cat(const UInt8* str, SInt32 length)
        {
            return Cat((const Char*)str, length);
        }

        /**
         * @brief Get a reference of the string.
         * @return The string reference.
         */
        String& Cat()
        {
            return *(String*)this;
        }

        /**
         * @brief Append a character.
         * @param charCode The character code to append.
         * @return The string itself.
         */
        String& Cat(Char charCode)
        {
            if (mSLen < 14)
            {
                mCharData[mSLen++] = charCode;
            }
            else
            {
                LCat(charCode);
            }
            Dsyn();
            return *this;
        }

        /**
         * @brief Append from a given C-string & length.
         * @param str The C-string to append.
         * @param length The number of bytes to copy.
         * @return The string itself.
         */
        String& Cat(const Char* str, SInt32 length);

        /**
         * @brief Get a substring copy.
         * @param from The byte position to start.
         * @param count the number of bytes to copy.
         * @return The substring.
         */
        String Mid(SInt32 from, SInt32 count) const;

        /**
         * @brief Get a substring copy using delimiters.
         * @param startDelimiter The start delimiter string.
         * @param endDelimiter The end delimiter string.
         * @param isStartOptional false if start delimiter is required to be found.
         * @param isEndOptional false if end delimiter is required to be found.
         * @return The substring, or an empty string is a required limiter is not found.
         */
        String Mid(const String& startDelimiter, const String& endDelimiter,
                   Bool isStartOptional = true, Bool isEndOptional = true) const;

        /**
         * @brief Get a substring copy.
         * @param from The byte position to start.
         * @return The substring.
         */
        String Mid(SInt32 from) const
        {
            return Mid(from, GetLength() - from);
        }

        /**
         * @brief Get a substring from the right.
         * @param count Number of bytes to copy.
         * @return The substring.
         */
        String Right(SInt32 count) const
        {
            return Mid(GetLength() - count);
        }

        /**
         * @brief Get a substring from the left.
         * @param count Number of bytes to copy.
         * @return The substring.
         */
        String Left(SInt32 count) const
        {
            return Mid(0, count);
        }

        /**
         * @brief Find any occurrence of a C-string & length and
         *  replace each occurrence by a C-string & length.
         * @param find The C-string to find.
         * @param findLen The number of bytes to find.
         * @param replace The C-string to replace.
         * @param replaceLen The number of bytes to replace.
         * @return The number of replaced occurrences.
         */
        UInt32 Replace(const Char* find, SInt32 findLen, const Char* replace, SInt32 replaceLen);

        /**
         * @brief Find any occurrence of a string and
         *  replace each occurrence by a string.
         * @param find The string to find.
         * @param replace The string to replace.
         * @return The number of replaced occurrences.
         */
        UInt32 Replace(const String& find, const String& replace)
        {
            return Replace(find.Begin(), find.GetLength(), replace.Begin(), replace.GetLength());
        }

        /**
         * @brief Find any occurrence of a C-string and
         *  replace each occurrence by a C-string.
         * @param find The C-string to find.
         * @param replace The C-string to replace.
         * @return The number of replaced occurrences.
         */
        UInt32 Replace(const Char* find, const Char* replace)
        {
            return Replace(find, StringLength(find), replace, StringLength(replace));
        }

        /**
         * @brief Find any occurrence of a string and
         *  replace each occurrence by a C-string.
         * @param find The string to find.
         * @param replace The C-string to replace.
         * @return The number of replaced occurrences.
         */
        UInt32 Replace(const String& find, const Char* replace)
        {
            return Replace(find.Begin(), find.GetLength(), replace, StringLength(replace));
        }

        /**
         * @brief Find any occurrence of a C-string and
         *  replace each occurrence by a string.
         * @param find The C-string to find.
         * @param replace The string to replace.
         * @return The number of replaced occurrences.
         */
        UInt32 Replace(const Char* find, const String& replace)
        {
            return Replace(find, StringLength(find), replace.Begin(), replace.GetLength());
        }

        /**
         * @brief Find a character.
         * Verify (assert in debug build) 'from' against the string length.
         * @param charCode The character to find.
         * @param from The byte position to start.
         * @return The byte position of the character or -1 if not found.
         */
        SInt32 Find(Char charCode, SInt32 from = 0) const;

        /**
         * @brief Find a C-string & length.
         * Verify (assert in debug build) 'from' against the string length.
         * @param length The number of bytes to find.
         * @param str The C-string to find.
         * @param from The byte position to start.
         * @return The byte position of the string or -1 if not found.
         */
        SInt32 Find(SInt32 length, const Char* str, SInt32 from) const;

        /**
         * @brief Find a C-string.
         * @param str The C-string to find.
         * @param from The byte position to start.
         * @return The byte position of the string or -1 if not found.
         */
        SInt32 Find(const Char* str, SInt32 from = 0) const
        {
            return Find(StringLength(str), str, from);
        }

        /**
         * @brief Find a string.
         * @param str The string to find.
         * @param from The byte position to start.
         * @return The byte position of the string or -1 if not found.
         */
        SInt32 Find(const String& str, SInt32 from = 0) const
        {
            return Find(str.GetLength(), str.Begin(), from);
        }

        /**
         * @brief Find a character from right to left.
         * Verify (assert in debug build) 'from' against the string length.
         * @param charCode The character to find.
         * @param from The byte position to start.
         * @return The byte position of the character or -1 if not found.
         */
        SInt32 ReverseFind(Char charCode, SInt32 from) const;

        /**
         * @brief Find a character from right to left.
         * @param charCode The character to find.
         * @return The byte position of the character or -1 if not found.
         */
        SInt32 ReverseFind(Char charCode) const
        {
            return GetLength() ? ReverseFind(charCode, GetLength() - 1) : -1;
        }

        /**
         * @brief Find a C-string & length from right to left at position.
         * Verify (assert in debug build) 'from' against the string length.
         * @param length The number of bytes to find.
         * @param str The C-string to find.
         * @param from The byte position to start.
         * @return The byte position of the character or -1 if not found.
         */
        SInt32 ReverseFind(SInt32 length, const Char* str, SInt32 from) const;

        /**
         * @brief Find a C-string from right to left at position.
         * @param str The C-string to find.
         * @param from The byte position to start.
         * @return The byte position of the string or -1 if not found.
         */
        SInt32 ReverseFind(const Char* str, SInt32 from) const
        {
            return ReverseFind(StringLength(str), str, from);
        }

        /**
         * @brief Find a string from right to left at position.
         * @param str The string to find.
         * @param from The byte position to start.
         * @return The byte position of the string or -1 if not found.
         */
        SInt32 ReverseFind(const String& str, SInt32 from) const
        {
            return ReverseFind(str.GetLength(), str.Begin(), from);
        }

        /**
         * @brief Find a C-string from right to left.
         * @param str The C-string to find.
         * @return The byte position of the string or -1 if not found.
         */
        SInt32 ReverseFind(const Char* str) const
        {
            return ReverseFind(str, GetLength() - 1);
        }

        /**
         * @brief Find a string from right to left.
         * @param str The string to find.
         * @return The byte position of the string or -1 if not found.
         */
        SInt32 ReverseFind(const String& str) const
        {
            return ReverseFind(str, GetLength() - 1);
        }

        /**
         * @brief Find first character from a character set C-string & length.
         * Verify (assert in debug build) 'from' against the string length.
         * @param length The number of bytes in the C-string.
         * @param str The character set C-string.
         * @param from The byte position to start.
         * @return The byte position of a matching character or -1 if not found.
         */
        SInt32 FindFirstOf(SInt32 length, const Char* str, SInt32 from) const;

        /**
         * @brief Find first character from a character set C-string.
         * @param str The character set C-string.
         * @param from The byte position to start.
         * @return The byte position of a matching character or -1 if not found.
         */
        SInt32 FindFirstOf(const Char* str, SInt32 from = 0) const
        {
            return FindFirstOf(StringLength(str), str, from);
        }

        /**
         * @brief Find first character from a character set string.
         * @param str The character set string.
         * @param from The byte position to start.
         * @return The byte position of a matching character or -1 if not found.
         */
        SInt32 FindFirstOf(const String& str, SInt32 from = 0) const
        {
            return FindFirstOf(str.GetLength(), str.Begin(), from);
        }

        /**
         * @brief Find the first character not matching any of the characters in a given set.
         * Verify (assert in debug build) 'from' against the string length.
         * @param length The number of bytes in the given C-string character set.
         * @param str The character set C-string.
         * @param from The byte position to start.
         * @return The byte position of the first non-matching character or -1 if not found.
         */
        SInt32 FindFirstNotOf(SInt32 length, const Char* str, SInt32 from) const;

        /**
         * @brief Find the first character not matching any of the characters in a given set.
         * @param str The character set C-string.
         * @param from The byte position to start.
         * @return The byte position of a matching character or -1 if not found.
         */
        SInt32 FindFirstNotOf(const Char* str, SInt32 from = 0) const
        {
            return FindFirstNotOf(StringLength(str), str, from);
        }

        /**
         * @brief Find the first character not matching any of the characters in a given set.
         * @param str The character set string.
         * @param from The byte position to start.
         * @return The byte position of a matching character or -1 if not found.
         */
        SInt32 FindFirstNotOf(const String& str, SInt32 from = 0) const
        {
            return FindFirstNotOf(str.GetLength(), str.Begin(), from);
        }

        /**
         * @brief Check if the start matches a C-string & length.
         * @param str The C-string to match.
         * @param length The number of bytes to match.
         * @return true if the start matches the string.
         */
        Bool StartsWith(const Char* str, SInt32 length) const
        {
            if (length > GetLength())
            {
                return false;
            }
            return System::CLib::MemCompare(str, Begin(), length) == 0;
        }

        /**
         * @brief Check if the start matches a C-string.
         * @param str The C-string to match.
         * @return true if the start matches the string.
         */
        Bool StartsWith(const Char* str) const
        {
            return StartsWith(str, StringLength(str));
        }

        /**
         * @brief Check if the start matches a string.
         * @param str The string to match.
         * @return true if the start matches the string.
         */
        Bool StartsWith(const String& str) const
        {
            return StartsWith(str.Begin(), str.GetLength());
        }

        /**
         * @brief Check if the end matches a C-string & length.
         * @param str The C-string to match.
         * @param length The number of bytes to match.
         * @return true if the end matches the string.
         */
        Bool EndsWith(const Char* str, SInt32 length) const
        {
            SInt32 l = GetLength();
            if (length > l)
            {
                return false;
            }
            return System::CLib::MemCompare(str, Begin() + l - length, length) == 0;
        }

        /**
         * @brief Check if the end matches a C-string.
         * @param str The C-string to match.
         * @return true if the end matches the string.
         */
        Bool EndsWith(const Char* str) const
        {
            return EndsWith(str, StringLength(str));
        }

        /**
         * @brief Check if the end matches a string.
         * @param str The string to match.
         * @return true if the end matches the string.
         */
        Bool EndsWith(const String& str) const
        {
            return EndsWith(str.Begin(), str.GetLength());
        }

        /**
         * @brief Compare a C-string.
         * @param str The C-string to compare.
         * @return return -1 if lower, 0 if equal, 1 if greater.
         */
        SInt32 Compare(const Char* str) const;

        /**
         * @brief Compare a string.
         * @param str The string to compare.
         * @return return -1 if lower, 0 if equal, 1 if greater.
         */
        SInt32 Compare(const String& str) const
        {
            return LCompare(str);
        }

        /**
         * @brief Check if a C-string is equal.
         * @param str The C-string to compare.
         * @return return true if equal.
         */
        Bool IsEqual(const Char* str) const
        {
            return Compare(str) == 0;
        }

        /**
         * @brief Check if a string is equal.
         * @param str The string to compare.
         * @return return true if equal.
         */
        Bool IsEqual(const String& str) const
        {
            if ((mKind | str.mKind) != 0)
            {
                return LEqual(str);
            }
            return ((mUInt64Data0 == str.mUInt64Data0) &&
                    (mUInt64Data1 == str.mUInt64Data1));
        }

        /**
         * @brief Calculate the string hash value.
         * @return The hash value.
         */
        UInt32 GetHashValue() const;

        /**
         * @brief Get the number of allocated bytes for characters,
         *  excluding the zero terminator.
         * @return The number of allocated bytes for characters.
         */
        SInt32 GetAlloc() const
        {
            return IsSmall() ? 14 : LAlloc();
        }

        /**
         * @brief Get number of byte characters.
         * @return The number of byte characters.
         */
        SInt32 GetLength() const
        {
            return IsSmall() ? mSLen : mLength;
        }

        /**
         * @brief Check if the string is empty.
         * @return true if the string is empty.
         */
        Bool IsEmpty() const
        {
            return GetLength() == 0;
        }

        /**
         * @brief Get a const reference of the string.
         * Convenience method for Lua scripting support.
         * @return The string reference.
         */
        const String& ToString() const
        {
            return *this;
        }

        /**
         * Get the pointer to the first character.
         * @return The read-only pointer to the first character.
         */
        const Char* Begin() const
        {
            return IsSmall() ? mCharData : mCharPtr;
        }

        /**
         * Get the pointer to the end of the string.
         * @return The read-only pointer to end of the string.
         */
        const Char* End() const
        {
            return Begin() + GetLength();
        }

        /**
         * Get the pointer to the last character.
         * @return The read-only pointer to the last character.
         */
        const Char* Last() const
        {
            const Char* begin = Begin();
            SInt32 length = GetLength();
            if (length > 0)
            {
                begin += (length - 1);
            }
            return begin;
        }

        /**
         * @brief Conversion operator to C-string.
         * @return The pointer to the C-string.
         */
        operator const Char*() const
        {
            return Begin();
        }

        /**
         * @brief Conversion operator to byte pointer.
         * @return The byte pointer to the Begin().
         */
        operator const UInt8*() const
        {
            return reinterpret_cast<const UInt8*>(Begin());
        }

        /**
         * @brief Conversion operator to void pointer.
         * @return The void pointer to the Begin().
         */
        operator const void*() const
        {
            return Begin();
        }

        /**
         * @brief The array operator.
         * Verify (assert in debug build) 'pos' against the string length.
         * @param pos The character byte position.
         * @return The character at the specified position,
         *  if the position is out of range 0 is returned.
         */
        Char operator[](SInt32 pos) const
        {
            if (MURL_VERIFY((pos >= 0) && (pos <= GetLength())))
            {
                return Begin()[pos];
            }
            return 0;
        }

        /**
         * @brief Indirection operator.
         * @return The first character.
         */
        Char operator*() const
        {
            return *Begin();
        }

        /**
         * @brief Assignment operator for C-string.
         * @param str The C-string to assign.
         * @return The object itself.
         */
        String& operator=(const Char* str)
        {
            SInt32 length = GetLength();
            const Char* b = Begin();
            if ((str >= b) && (str <= (b + length)))
            {
                return *this = String(str, StringLength(str));
            }
            Free();
            Set(str, StringLength(str));
            return *this;
        }

        /**
         * @brief Assignment operator for string.
         * @param str The string to assign.
         * @return The object itself.
         */
        String& operator=(const String& str)
        {
            return Assign(str);
        }

        /**
         * @brief In-place addition operator for a character.
         * @param chr The character to add.
         * @return The object itself.
         */
        const String& operator+=(Char chr)
        {
            return Cat(chr);
        }

        /**
         * @brief In-place addition operator for const C-string.
         * @param str The C-string to add.
         * @return The string itself.
         */
        const String& operator+=(const Char* str)
        {
            return Cat(str);
        }

        /**
         * @brief In-place addition operator for string.
         * @param str The string to add.
         * @return The string itself.
         */
        const String& operator+=(const String& str)
        {
            return Cat(str);
        }

#ifndef MURL_STRING_DISABLE_CONVERSION

        /**
         * @brief In-place addition operator for UInt64.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(UInt64 value);

        /**
         * @brief In-place addition operator for SInt64.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(SInt64 value);

        /**
         * @brief In-place addition operator for UInt32.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(UInt32 value);

        /**
         * @brief In-place addition operator for SInt32.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(SInt32 value);

        /**
         * @brief In-place addition operator for Double.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(Double value);

        /**
         * @brief In-place addition operator for Color.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(const Color& value);

        /**
         * @brief In-place addition operator for Bool.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(Bool value);

        /**
         * @brief In-place addition operator for Color.
         * @param value The value to add.
         * @return The string itself.
         */
        const String& operator+=(const System::Time& value);

#endif // MURL_STRING_DISABLE_CONVERSION

        /**
         * @brief Addition operator for string and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side string.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, const String& rhs)
        {
            String c(lhs);
            return c.Cat(rhs);
        }

        /**
         * @brief Addition operator for string and C-string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side C-string.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, const Char* rhs)
        {
            String c(lhs);
            return c.Cat(rhs);
        }

        /**
         * @brief Addition operator for C-string and string.
         * @param lhs The left hand side C-string.
         * @param rhs The right hand side string.
         * @return The concatenated string.
         */
        friend String operator+(const Char* lhs, const String& rhs)
        {
            String c(lhs);
            return c.Cat(rhs);
        }

        /**
         * @brief Addition operator for string and character.
         * @param lhs The left hand side string.
         * @param rhs The right hand side character.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, Char rhs)
        {
            String c(lhs);
            return c.Cat(rhs);
        }

        /**
         * @brief Addition operator for character and string.
         * @param lhs The left hand side character.
         * @param rhs The right hand side string.
         * @return The concatenated string.
         */
        friend String operator+(Char lhs, const String& rhs)
        {
            String c(lhs, 1);
            return c.Cat(rhs);
        }

#ifndef MURL_STRING_DISABLE_CONVERSION

        /**
         * @brief Addition operator for UInt64 and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, UInt64 rhs);

        /**
         * @brief Addition operator for SInt64 and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, SInt64 rhs);

        /**
         * @brief Addition operator for UInt32 and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, UInt32 rhs);

        /**
         * @brief Addition operator for SInt32 and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, SInt32 rhs);

        /**
         * @brief Addition operator for Double and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, Double rhs);

        /**
         * @brief Addition operator for Color and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, const Color& rhs);

        /**
         * @brief Addition operator for Bool and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, Bool rhs);

        /**
         * @brief Addition operator for Time and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side variable.
         * @return The concatenated string.
         */
        friend String operator+(const String& lhs, const System::Time& rhs);

#endif // MURL_STRING_DISABLE_CONVERSION

        /**
         * @brief Less than operator for string and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is less than the right hand string.
         */
        friend bool operator<(const String& lhs, const String& rhs)
        {
            return lhs.Compare(rhs) < 0;
        }

        /**
         * @brief Less than operator for string and C-string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side C-string.
         * @return true if the left hand string is less than the right hand string.
         */
        friend bool operator<(const String& lhs, const Char* rhs)
        {
            return lhs.Compare(rhs) < 0;
        }

        /**
         * @brief Less than operator for C-string and string.
         * @param lhs The left hand side C-string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is less than the right hand string.
         */
        friend bool operator<(const Char* lhs, const String& rhs)
        {
            return rhs.Compare(lhs) > 0;
        }

        /**
         * @brief Less than or equal to operator for string and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is less than or equal
         *  to the right hand string.
         */
        friend bool operator<=(const String& lhs, const String& rhs)
        {
            return lhs.Compare(rhs) <= 0;
        }

        /**
         * @brief Less than or equal to operator for string and C-string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side C-string.
         * @return true if the left hand string is less than or equal
         *  to the right hand string.
         */
        friend bool operator<=(const String& lhs, const Char* rhs)
        {
            return lhs.Compare(rhs) <= 0;
        }

        /**
         * @brief Less than or equal to operator for C-string and string.
         * @param lhs The left hand side C-string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is less than or equal
         *  to the right hand string.
         */
        friend bool operator<=(const Char* lhs, const String& rhs)
        {
            return rhs.Compare(lhs) >= 0;
        }

        /**
         * @brief Greater than operator for string and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is greater than the right hand string.
         */
        friend bool operator>(const String& lhs, const String& rhs)
        {
            return lhs.Compare(rhs) > 0;
        }

        /**
         * @brief Greater than operator for string and C-string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side C-string.
         * @return true if the left hand string is greater than the right hand string.
         */
        friend bool operator>(const String& lhs, const Char* rhs)
        {
            return lhs.Compare(rhs) > 0;
        }

        /**
         * @brief Greater than operator for C-string and string.
         * @param lhs The left hand side C-string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is greater than the right hand string.
         */
        friend bool operator>(const Char* lhs, const String& rhs)
        {
            return rhs.Compare(lhs) < 0;
        }

        /**
         * @brief Greater than or equal to operator for string and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is greater than or equal
         *  to the right hand string.
         */
        friend bool operator>=(const String& lhs, const String& rhs)
        {
            return lhs.Compare(rhs) >= 0;
        }

        /**
         * @brief Greater than or equal to operator for string and C-string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side C-string.
         * @return true if the left hand string is greater than or equal
         *  to the right hand string.
         */
        friend bool operator>=(const String& lhs, const Char* rhs)
        {
            return lhs.Compare(rhs) >= 0;
        }

        /**
         * @brief Greater than or equal to operator for C-string and string.
         * @param lhs The left hand side C-string.
         * @param rhs The right hand side string.
         * @return true if the left hand string is greater than or equal
         *  to the right hand string.
         */
        friend bool operator>=(const Char* lhs, const String& rhs)
        {
            return rhs.Compare(lhs) <= 0;
        }

        /**
         * @brief Equal to comparison operator for string and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side string.
         * @return true if the strings are equal.
         */
        friend bool operator==(const String& lhs, const String& rhs)
        {
            return lhs.IsEqual(rhs);
        }

        /**
         * @brief Equal to comparison operator for string and C-string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side C-string.
         * @return true if the strings are equal.
         */
        friend bool operator==(const String& lhs, const Char* rhs)
        {
            return lhs.Compare(rhs) == 0;
        }

        /**
         * @brief Equal to comparison operator for C-string and string.
         * @param lhs The left hand side C-string.
         * @param rhs The right hand side string.
         * @return true if the strings are equal.
         */
        friend bool operator==(const Char* lhs, const String& rhs)
        {
            return rhs.Compare(lhs) == 0;
        }

        /**
         * @brief Not equal to comparison operator for string and string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side string.
         * @return true if the strings are not equal.
         */
        friend bool operator!=(const String& lhs, const String& rhs)
        {
            return !lhs.IsEqual(rhs);
        }

        /**
         * @brief Not equal to comparison operator for string and C-string.
         * @param lhs The left hand side string.
         * @param rhs The right hand side C-string.
         * @return true if the strings are not equal.
         */
        friend bool operator!=(const String& lhs, const Char* rhs)
        {
            return lhs.Compare(rhs) != 0;
        }

        /**
         * @brief Not equal to comparison operator for C-string and string.
         * @param lhs The left hand side C-string.
         * @param rhs The right hand side string.
         * @return true if the strings are not equal.
         */
        friend bool operator!=(const Char* lhs, const String& rhs)
        {
            return rhs.Compare(lhs) != 0;
        }

        /**
         * @brief Exchange the content of the string with a given second one.
         * @param other The second string.
         */
        void Swap(String& other);

        /**
         * @brief Definition of the const iterator.
         */
        typedef const Char* ConstIterator;

#ifdef MURL_COMPILER_C11
        MURL_STL_CONST_ITERATOR
#endif // MURL_COMPILER_C11

    private:
        String(const Char* str, const Char* end)
        {
            if (MURL_VERIFY(end >= str))
            {
                Set(str, SInt32(end - str));
            }
        }

        Bool Cat(const Char* str, const Char* end)
        {
            if (!MURL_VERIFY(str <= end))
            {
                return false;
            }
            Cat(str, SInt32(end - str));
            return true;
        }

        SInt32 StringLength(const Char* str) const
        {
            if (str != 0)
            {
                return SInt32(System::CLib::StrLen(str));
            }
            return 0;
        }

        enum Kind
        {
            SMALL = 0,  // must be 0, terminating zero
            MEDIUM = 31
        };

        Bool IsSmall() const
        {
            return mKind == SMALL;
        }

        Bool IsRef() const
        {
            return mKind > MEDIUM;
        }

        Bool IsSharedRef() const;

        SInt32 LAlloc() const;

        Bool LEqual(const String& str) const;

        SInt32 LCompare(const String& str) const;

        void LSet(const String& str);

        void LFree();

        void LCat(Char charCode);

        UInt32 LHashValue() const;

        void UnShare();

        void SetSLen(SInt32 l);

        Char* Ptr()
        {
            return IsSmall() ? mCharData : mCharPtr;
        }

        Char* Alloc(SInt32 count, UInt8& kind);

        void Zero()
        {
            mUInt64Data0 = 0;
            mUInt64Data1 = 0;
            Dsyn();
        }

        void Free()
        {
            if (!IsSmall())
            {
                LFree();
            }
        }

        void SetSmall(const String& str)
        {
            mUInt64Data0 = str.mUInt64Data0;
            mUInt64Data1 = str.mUInt64Data1;
        }

        String& Assign(const String& str);

        Char* Insert(SInt32 pos, SInt32 count, const Char* str);

#if defined(MURL_DEBUG) && !defined(MURL_COMPILER_GCC)
    public:
        void Dsyn()
        {
            mDebugString = Begin();
            mDebugLength = GetLength();
        }
    private:
        const char* mDebugString;
        SInt32 mDebugLength;
#else   // MURL_DEBUG && !MURL_COMPILER_GCC
        void Dsyn() {}
#endif  // MURL_DEBUG && !MURL_COMPILER_GCC

        union
        {
            Char* mCharPtr;
            char mCharData[14];
            struct
            {
                UInt64 mUInt64Data0;
                union
                {
                    UInt64 mUInt64Data1;
                    struct
                    {
                        SInt32 mLength;
                        char mCharData12;
                        char mCharData13;
                        UInt8 mKind;
                        UInt8 mSLen;
                    };
                };
            };
        };
    };
}

#endif // __MURL_STRING_H__

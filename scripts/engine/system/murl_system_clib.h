// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_SYSTEM_CLIB_H__
#define __MURL_SYSTEM_CLIB_H__

#include "murl_types.h"

namespace Murl
{
    namespace System
    {
        /**
         * @ingroup MurlSystemNamespaces
         * @brief System C-runtime library functions.
         */
        namespace CLib
        {
            /**
             * @addtogroup MurlSystemCLibFunctions
             * @brief Forward to C-runtime library functions.
             * @{
             */

            /**
             * @brief Print formatted variadic arguments into string.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return The string with the printed arguments.
             */
            String PrintToString(const Char* format, ...);
            /**
             * @brief Print formatted variadic arguments into string.
             * @param format The format string.
             * @param vaListPtr Pointer to the variadic arguments.
             * @return The string with the printed arguments.
             */
            String PrintToStringArg(const Char* format, void* vaListPtr);

            /**
             * @brief Print formatted variadic arguments to the system specific debug output.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return The number of characters printed excluding the null terminator.
             */
            SInt32 PrintToDebug(const Char* format, ...);
            /**
             * @brief Print formatted variadic arguments to the system specific error output.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return The number of characters printed excluding the null terminator.
             */
            SInt32 PrintToError(const Char* format, ...);

            /**
             * @brief Print formatted variadic arguments into a C-string.
             * @param targetString The C-string to print into.
             * @param targetLength The byte length of the C-string to print into.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return The number of characters printed excluding the null terminator.
             */
            SInt32 PrintToCString(Char* targetString, UInt32 targetLength, const Char* format, ...);
            /**
             * @brief Print formatted variadic arguments to file.
             * The printed string is appended to the file.
             * @param fileName The file name to print into.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return The number of characters printed excluding the null terminator.
             */
            SInt32 PrintToFile(const Char* fileName, const Char* format, ...);
            /**
             * @brief Print formatted variadic arguments to stdout.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return The number of characters printed excluding the null terminator.
             */
            SInt32 PrintToStdOut(const Char* format, ...);

            /**
             * @brief Scan formatted string into variadic arguments.
             * @param stringToScan The string to scan.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return The number of items assigned.
             */
            SInt32 ScanString(const Char* stringToScan, const Char* format, ...);

            /**
             * @brief Allocate heap memory.
             * @param byteSize The number of bytes to allocate.
             * @return The pointer to the allocated memory.
             */
            void* Alloc(UInt64 byteSize);
            /**
             * @brief Free allocated heap memory.
             * @param data The pointer to the allocated memory.
             */
            void Free(void* data);

            /**
             * @brief Fill memory with a value.
             * @param destination Pointer to the destination memory.
             * @param value The byte-value to fill the memory.
             * @param byteSize The number of bytes to fill.
             * @return The pointer to the destination memory.
             */
            void* MemSet(void* destination, UInt32 value, UInt64 byteSize);
            /**
             * @brief Copy non-overlapping memory.
             * Use MemMove if the memory areas do overlap.
             * @param destination Pointer to the destination memory.
             * @param source Pointer to the source memory.
             * @param byteSize The number of bytes to copy.
             * @return The pointer to the destination memory.
             */
            void* MemCopy(void* destination, const void* source, UInt64 byteSize);
            /**
             * @brief Copy overlapping memory.
             * @param destination Pointer to the destination memory.
             * @param source Pointer to the source memory.
             * @param byteSize The number of bytes to copy.
             * @return The pointer to the destination memory.
             */
            void* MemMove(void* destination, const void* source, UInt64 byteSize);
            /**
             * @brief Compare memory.
             * @param source1 Pointer to the 1st source memory.
             * @param source2 Pointer to the 2nd source memory.
             * @param byteSize The number of bytes to compare.
             * @return Zero if source1 is equal to source2,
             *  negativ if source1 is lesser than source2,
             *  positive if source1 is greater than source2.
             */
            SInt32 MemCompare(const void* source1, const void* source2, UInt64 byteSize);

            /**
             * @brief Definition of the compare function.
             * @param source1 Pointer to the 1st source.
             * @param source2 Pointer to the 2nd source.
             * @return Zero if source1 is equal to source2,
             *  negativ if source1 is lesser than source2,
             *  positive if source1 is greater than source2.
             */
            typedef SInt32 (*CompareFunctionType)(const void* source1, const void* source2);
            /**
             * @brief Quick sort items.
             * @param items Pointer to the items to sort.
             * @param numberOfItems Number of items to sort.
             * @param itemByteSize Bytesize of an item.
             * @param compareFunction The CompareFunctionType for the item.
             */
            void QuickSort(void* items, UInt32 numberOfItems, UInt32 itemByteSize,
                           CompareFunctionType compareFunction);
            /**
             * @brief Binary search an item.
             * The items to search for are required to be sorted.
             * @param key Pointer to the item to find.
             * @param items Pointer to the items to search for.
             * @param numberOfItems Number of items to search for.
             * @param itemByteSize Bytesize of an item.
             * @param compareFunction The CompareFunctionType for the item.
             * @return Pointer to the item found or null if item is not found.
             * If there are multiple elements matching key, the element returned is unspecified.
             */
            void* BinarySearch(const void* key, const void* items, UInt32 numberOfItems, UInt32 itemByteSize,
                               CompareFunctionType compareFunction);

            /**
             * @brief Seed the C-runtime library random number generator.
             * @param seed The seed for the random number generator.
             */
            void SRand(UInt32 seed);
            /**
             * @brief Get a random number form the  C-runtime library random number generator.
             * @return The random number.
             */
            SInt32 Rand();

            /**
             * @brief Compare C-strings.
             * @param string1 Pointer to the 1st C-string.
             * @param string2 Pointer to the 2nd C-string.
             * @return Zero if string1 is equal to string2,
             *  negativ if string1 is lesser than string2,
             *  positive if string1 is greater than string2.
             */
            SInt32 StrCmp(const Char* string1, const Char* string2);
            /**
             * @brief Get the length of C-string.
             * @param string Pointer to the C-string.
             * @return The length of the C-string.
             */
            UInt32 StrLen(const Char* string);

            /**
             * @brief Check if a character is a numeric character.
             * @param characterCode The character to check.
             * @return true if the character is a numeric character.
             */
            Bool IsDigit(SInt32 characterCode);
            /**
             * @brief Check if a character is an alphabetic character.
             * @param characterCode The character to check.
             * @return true if the character is an alphabetic character.
             */
            Bool IsAlpha(SInt32 characterCode);
            /**
             * @brief Check if a character is an alphanumeric character.
             * @param characterCode The character to check.
             * @return true if the character is an alphanumeric character.
             */
            Bool IsAlphaNumeric(SInt32 characterCode);
            /**
             * @brief Check if a character is a punctuation character.
             * @param characterCode The character to check.
             * @return true if the character is a punctuation character.
             */
            Bool IsPunctuation(SInt32 characterCode);
            /**
             * @brief Check if a character is a spacing character.
             * @param characterCode The character to check.
             * @return true if the character is a spacing character.
             */
            Bool IsSpace(SInt32 characterCode);
            /**
             * @brief Check if a character is a hexadecimal character.
             * @param characterCode The character to check.
             * @return true if the character is a hexadecimal character.
             */
            Bool IsHexDigit(SInt32 characterCode);
            /**
             * @brief Check if a character is a control character.
             * @param characterCode The character to check.
             * @return true if the character is a control character.
             */
            Bool IsControl(SInt32 characterCode);

            /**
             * @brief Check if a file exists.
             * @param path The path and the filename.
             * @return true if the file exists.
             */
            Bool FileExists(const Char* path);
            /**
             * @brief Delete a file.
             * @param path The path to the file to delete.
             * @return true if successful.
             */
            Bool DeleteFile(const Char* path);
            /**
             * @brief Move/rename a file.
             * @param oldPath The current path to the file to move.
             * @param newPath The new path of the file.
             * @return true if successful.
             */
            Bool MoveFile(const Char* oldPath, const Char* newPath);

            /**
             * @brief Check if a folder exists.
             * @param path The path and the folder.
             * @return true if the folder exists.
             */
            Bool FolderExists(const Char* path);
            /**
             * @brief Create a folder.
             * @param path The path and the folder to create.
             * @return true if successful.
             */
            Bool CreateFolder(const Char* path);
            /**
             * @brief Delete a folder.
             * @param path The path and the folder to delete.
             * @param recursively If true, the folder and all contents are deleted.
             *      If false, the function fails when the folder is not empty.
             * @return true if successful.
             */
            Bool DeleteFolder(const Char* path, Bool recursively);
            /**
             * @brief Move/rename a folder.
             * @param oldPath The current path to the folder to move.
             * @param newPath The new path of the folder.
             * @return true if successful.
             */
            Bool MoveFolder(const Char* oldPath, const Char* newPath);

            /**
             * @brief Get the creation time of a file or folder.
             * Note: explicit item creation time is not available on all platforms, e.g. Android,
             * Linux or emscripten. In this case, false is returned.
             * @param path The path to the file or folder to query.
             * @param seconds A reference to an UInt64 value to receive the seconds part.
             * @param nanoSeconds A reference to an UInt64 value to receive the nanoseconds part.
             * @return true if successful.
             */
            Bool GetItemCreationTime(const Char* path, UInt64& seconds, UInt64& nanoSeconds);
            /**
             * @brief Get the time a file or folder was most recently modified.
             * @param path The path to the file or folder to query.
             * @param seconds A reference to an UInt64 value to receive the seconds part.
             * @param nanoSeconds A reference to an UInt64 value to receive the nanoseconds part.
             * @return true if successful.
             */
            Bool GetItemModificationTime(const Char* path, UInt64& seconds, UInt64& nanoSeconds);

            /**
             * @brief Launch a shell command if supported by the platform.
             * Internally, this calls the CLib std::system function.
             * @param commandLine The shell command line, including any parameters.
             * @return The shell command's exit status.
             */
            SInt32 LaunchShellCommand(const Char* commandLine);

            /**
             * @brief Call the C-runtime abort function.
             */
            void Abort();

            /**
             * @brief Call the C-runtime exit function.
             * On iOS this function does nothing.
             * @param exitCode The exit code.
             */
            void Exit(SInt32 exitCode);

            /** @} */
        }
    }
}

#endif  // __MURL_SYSTEM_CLIB_H__

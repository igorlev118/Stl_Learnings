// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_UTIL_STRING_NAME_H__
#define __MURL_UTIL_STRING_NAME_H__

#include "murl_string.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @addtogroup MurlUtilStringNameFunctions
         * @brief String manipulation and test functions.
         * @{
         */

        /**
         * @brief Get the file path substring of a file path and name.
         * Returns the substring before the last '/' character.
         * @param filePathAndName The file path and name.
         * @return The file path substring of the file name.
         *  If the '/' character is not found an empty string is returned.
         */
        String GetFilePath(const String& filePathAndName);

        /**
         * @brief Get the file name substring of a file path and name.
         * Returns the substring behind the last '/' character.
         * @param filePathAndName The file path and name.
         * @return The file name substring of the file name.
         *  If the '/' character is not found the input string is returned.
         */
        String GetFileName(const String& filePathAndName);

        /**
         * @brief Get the file extension substring of a file name.
         * Returns the substring behind the last '.' character.
         * @param fileName The file name.
         * @return The file extension substring of the file name.
         *  If the '.' character is not found an empty string is returned.
         */
        String GetFileExtension(const String& fileName);

        /**
         * @brief Strip the file extension from a file name.
         * Returns the substring before the last '.' character.
         * @param fileName The file name.
         * @return The file name substring excluding the file extension.
         *  If the '.' character is not found the input string is returned.
         */
        String StripExtension(const String& fileName);

        /**
         * @brief Strip the file path and extension from a file path and name.
         * Returns the substring from the last '/' to the last '.' character.
         * @param filePathAndName The file path and name.
         * @return The file name substring excluding the file path and extension.
         *  If the '.' and '/' character is not found the input string is returned.
         */
        String StripPathAndExtension(const String& filePathAndName);

        /**
         * @brief Join two path strings.
         * Ensures exactly one '/' character between the left and the right part.
         * @param leftPath The left path string.
         * @param rightPath The right path string.
         * @return The left plus the right path string.
         */
        String JoinPaths(const String& leftPath, const String& rightPath);

        /**
         * @brief Exchange all '\\' with '/' characters.
         * @param windowsPath The path string to convert.
         * @return The Unix path string.
         */
        String GetUnixPath(const String& windowsPath);

        /**
         * @brief Exchange all '/' with '\\' characters.
         * @param unixPath The path string to convert.
         * @return The Windows path string.
         */
        String GetWindowsPath(const String& unixPath);

        /**
         * @brief Get a normalized path.
         * Returns the given path, with all occurrences of "." removed, and
         * any occurrences of ".." revursively joined with the previous
         * sub-path.
         * @param path The path to normalize.
         * @return The normalized Unix-style path.
         */
        String GetNormalizedPath(const String& path);

        /**
         * @brief Get a relative path from an absolute one.
         * When the relative path cannot be resolved, the given absolute path
         * is returned. This may happen e.g. when both given paths are located
         * on different volumes.
         * @param absolutePath The absolute path to convert.
         * @param absoluteBasePath The absolute base path relative to which
         *      the path is converted.
         * @return The relative path if it can be resolved, or absolutePath if not.
         */
        String GetRelativePath(const String& absolutePath, const String& absoluteBasePath);
        /**
         * @brief Get an absolute path from a relative one.
         * When the given relative path is actually representing an absolute location
         * (i.e. starting with "/"), it is directly returned. Otherwise, the base path
         * and relative path are concatenated and normalized.
         * @param relativePath The relative path to convert.
         * @param absoluteBasePath The absolute base path relative to which
         *      the path is converted.
         * @return The absolute path if it can be resolved, or relativePath if not.
         */
        String GetAbsolutePath(const String& relativePath, const String& absoluteBasePath);

        /** @brief Match option flags, can be combined using bitwise OR. */
        enum MatchOptions
        {
            MATCH_DEFAULT     = 0x00,   ///< Default matching <code>* ? [0-z]</code>.
            MATCH_NOESCAPE    = 0x01,   ///< Disable backslash escaping.
            MATCH_PATHNAME    = 0x02,   ///< Slash must be matched by slash.
            MATCH_PERIOD      = 0x04,   ///< Period must be matched by period.
            MATCH_CASEFOLD    = 0x08,   ///< Pattern is matched case-insensitive.
            MATCH_LEADING_DIR = 0x10    ///< Ignore / tail after match.
        };

        /**
         * @brief Check if a name contains pattern matching statements.
         * Pattern matching is supported by IsNameMatching().
         * @param name The name string to check.
         * @param matchOption The option for checking, either MATCH_DEFAULT or MATCH_NOESCAPE.
         * @return true if the name contains pattern matching statements, otherwise false.
         */
        Bool HasMatchPattern(const String& name, UInt32 matchOption = MATCH_DEFAULT);

        /**
         * @brief Check if a name matches a specified pattern.
         * Matches patterns according to the Unix-like globbing rules <code>* ? [0-z]</code>.
         * See HasMatchPattern() to check a name for patterns.
         * @param pattern The pattern string.
         * @param name The name string to check.
         * @param matchOptions The options for checking, any #MatchOptions can be combined using bitwise OR.
         * @return true if the name matches the pattern, otherwise false.
         */
        Bool IsNameMatching(const String& pattern, const String& name, UInt32 matchOptions = MATCH_DEFAULT);

        /** @} */
    }
}

#endif // __MURL_UTIL_STRING_H__

// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_UTIL_FILE_TOOLS_H__
#define __MURL_UTIL_FILE_TOOLS_H__

#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilFileClasses
         * @brief Utility class to read / write binary files.
         */
        class FileTools
        {
        public:
            /**
             * @brief Load a binary file.
             * @param name The file name.
             * @param data The data object to read the file into.
             * @param byteSize The maximum number of bytes to read,
             *  if zero the entire file is loaded.
             * @return true if successful.
             */
            static Bool LoadBinaryFile(const String& name, Data& data, UInt64 byteSize = 0);

            /**
             * @brief Save data to a binary file.
             * @param name The file name.
             * @param data The data object to write into the file.
             * @return true if successful.
             */
            static Bool SaveBinaryFile(const String& name, const ConstData& data);

            /**
             * @brief Save a string to a binary file.
             * @param name The file name.
             * @param string The string to write into the file.
             * @return true if successful.
             */
            static Bool SaveBinaryFile(const String& name, const String& string);

            /**
             * @brief Check if a folder exists.
             * @param path The path and the folder.
             * @param create If the folder does not exist, create the folder if true.
             * @return true if the folder exists.
             */
            static Bool FolderExists(const String& path, Bool create);
        };
    }
}

#endif // __MURL_UTIL_FILE_TOOLS_H__

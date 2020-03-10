// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_FILE_H__
#define __MURL_I_FILE_H__

#include "murl_data.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IFile
     * @brief The file interface provides access to a single file.
     * The IFile object can be created by the IFileInterface object.
     */
    class IFile
    {
    public:
        /**
         * @brief Get the position of the file pointer.
         * Read() / Write() operations start at the file pointer position,
         * the default position is zero.
         * @return The position of the file pointer in bytes.
         */
        virtual UInt64 GetPosition() = 0;

        /**
         * @brief Set the position of the file pointer.
         * Read() / Write() operations start at the file pointer position,
         * the default position is zero.
         * @param position The position of the file pointer in bytes.
         */
        virtual void SetPosition(UInt64 position) = 0;

        /**
         * @brief Get the size of the file.
         * @return The size of the file in bytes.
         */
        virtual UInt64 GetSize() = 0;

        /**
         * @brief Read from the file at the current file pointer position.
         * @param data The memory pointer to read the file into.
         * @param byteSize The number of bytes to read.
         * @return The number of bytes read into the memory.
         */
        virtual UInt64 Read(void* data, UInt64 byteSize) = 0;

        /**
         * @brief Write to the file at the current file pointer position.
         * @param data The memory pointer to write into the file.
         * @param byteSize The number of bytes to write.
         * @return The number of bytes written into the file.
         */
        virtual UInt64 Write(const void* data, UInt64 byteSize) = 0;

        /**
         * @brief Read from the file at the current file pointer position.
         *  The size of the data object's data is the number of bytes to read,
         *  if the data object is empty the data is resized to GetSize().
         * @param data The data object to read the file into.
         * @return The number of bytes read into the data object.
         */
        virtual UInt64 Read(Data& data) = 0;

        /**
         * @brief Write to the file at the current file pointer position.
         * @param data The data object to write into the file.
         * @return The number of bytes written into the file.
         */
        virtual UInt64 Write(const ConstData& data) = 0;

    protected:
        virtual ~IFile() {}
    };
}

#endif  // __MURL_I_FILE_H__

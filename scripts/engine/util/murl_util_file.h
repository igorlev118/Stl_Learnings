// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_FILE_H__
#define __MURL_UTIL_FILE_H__

#include "murl_i_file.h"
#include "murl_system_file.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilFileClasses
         * @brief Utility class implementing the IFile interface.
         */
        class File : public IFile, NonCopyable
        {
        public:
            /**
             * @brief Constructor taking the file name and access mode.
             * @param name The file name.
             * @param accessMode The access mode for opening the file.
             */
            File(const String& name, IEnums::FileAccessMode accessMode);

            /**
             * @brief The destructor.
             *  Close the file if open.
             */
            virtual ~File();

            /**
             * @brief Implementation of IFile::GetPosition().
             * @return The position of the file pointer in bytes.
             */
            virtual UInt64 GetPosition();

            /**
             * @brief Implementation of IFile::SetPosition().
             * @param position The position of the file pointer in bytes.
             */
            virtual void SetPosition(UInt64 position);

            /**
             * @brief Implementation of IFile::GetSize().
             * @return The size of the file in bytes.
             */
            virtual UInt64 GetSize();

            /**
             * @brief Implementation of IFile::Read(void* data, UInt64 byteSize).
             * @param data The memory pointer to read the file into.
             * @param byteSize The number of bytes to read.
             * @return The number of bytes read into the memory.
             */
            virtual UInt64 Read(void* data, UInt64 byteSize);

            /**
             * @brief Implementation of IFile::Write(const void* data, UInt64 byteSize).
             * @param data The memory pointer to write into the file.
             * @param byteSize The number of bytes to write.
             * @return The number of bytes written into the file.
             */
            virtual UInt64 Write(const void* data, UInt64 byteSize);

            /**
             * @brief Implementation of IFile::Read(Data& data).
             * @param data The data object to read the file into.
             * @return The number of bytes read into the data object.
             */
            virtual UInt64 Read(Data& data);

            /**
             * @brief Implementation of IFile::Write(const ConstData& data).
             * @param data The data object to write into the file.
             * @return The number of bytes written into the file.
             */
            virtual UInt64 Write(const ConstData& data);

            /**
             * @brief Open the file.
             * Open with the name and access mode specified by the constructor.
             * @return true if successful.
             */
            virtual Bool Open();

            /**
             * @brief Close the file.
             * @return true if successful.
             */
            virtual Bool Close();

        protected:
            /** The file name storage. */
            String mName;
            /** The access mode storage. */
            IEnums::FileAccessMode mAccessMode;
            /** The system file object. */
            System::File mFile;
        };
    }
}

#endif  // __MURL_UTIL_FILE_H__

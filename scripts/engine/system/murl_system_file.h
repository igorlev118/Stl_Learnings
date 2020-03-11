// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_SYSTEM_FILE_H__
#define __MURL_SYSTEM_FILE_H__

#include "murl_data.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace System
    {
        class FileHandle;
        class Time;
        
        /**
         * @ingroup MurlSystemClasses
         * @brief The system file access class.
         */
        class File : NonCopyable
        {
        public:
            /**
             * @brief Get all file names from a specified path.
             * @param path The path to examine the files.
             * @return A string array containing all files names.
             */
            static StringArray GetFiles(const String& path);
            /**
             * @brief Check if a file exists.
             * @param path The path and filename.
             * @return true if the file exists.
             */
            static Bool FileExists(const String& path);
            /**
             * @brief Delete a file.
             * @param path The path to the file to delete.
             * @return true if successful.
             */
            static Bool DeleteFile(const String& path);
            /**
             * @brief Move/rename a file.
             * @param oldPath The current path to the file to move.
             * @param newPath The new path of the file.
             * @return true if successful.
             */
            static Bool MoveFile(const String& oldPath, const String& newPath);
            /**
             * @brief Get the size of a file in bytes.
             * @param path The path to the file to check.
             * @return The file's size in bytes.
             */
            static UInt64 GetFileSize(const String& path);

            /**
             * @brief Get all folder names from a specified path.
             * @param path The path to examine the folders.
             * @return A string array containing all folder names.
             */
            static StringArray GetFolders(const String& path);
            /**
             * @brief Check if a folder exists.
             * @param path The path and the folder.
             * @return true if the folder exists.
             */
            static Bool FolderExists(const String& path);
            /**
             * @brief Create a folder.
             * @param path The path and the folder to create.
             * @return true if successful.
             */
            static Bool CreateFolder(const String& path);
            /**
             * @brief Delete a folder.
             * @param path The path and the folder to delete.
             * @param recursively If true, the folder and all contents are deleted.
             *      If false, the function fails when the folder is not empty.
             * @return true if successful.
             */
            static Bool DeleteFolder(const String& path, Bool recursively);
            /**
             * @brief Move/rename a folder.
             * @param oldPath The current path to the folder to move.
             * @param newPath The new path of the folder.
             * @return true if successful.
             */
            static Bool MoveFolder(const String& oldPath, const String& newPath);

            /** 
             * @brief Get the creation time of a file or folder.
             * @param path The path to the file or folder to query.
             * @param time A reference to a time object to receive the creation time.
             * @return true if successful.
             */
            static Bool GetItemCreationTime(const String& path, Time& time);
            /**
             * @brief Get the time a file or folder was most recently modified.
             * @param path The path to the file or folder to query.
             * @param time A reference to a time object to receive the last modification time.
             * @return true if successful.
             */
            static Bool GetItemModificationTime(const String& path, Time& time);

            /**
             * @brief The default constructor.
             */
            File();
            /**
             * @brief The destructor.
             *  Close the file if open.
             */
            virtual ~File();
            
            /**
             * @brief Open a file.
             * @param fileName The file name to open.
             * @param mode The access mode for opening the file.
             * @return true if successful.
             */
            Bool Open(const String& fileName, IEnums::FileAccessMode mode = IEnums::FILE_ACCESS_MODE_READ_ONLY);
            /**
             * @brief Close the file.
             * @return true if successful.
             */
            Bool Close();
            
            /**
             * @brief Check if the file is open.
             * @return true if the file is open.
             */
            Bool IsOpen() const;
            /**
             * @brief Get the size of the file.
             * @return The byte size of the file.
             */
            UInt64 GetSize() const;
            
            /**
             * @brief Get the file pointer position.
             * @return The file pointer position in bytes.
             */
            UInt64 GetPosition() const;
            /**
             * @brief Set the file pointer position.
             * @param position The file pointer position in bytes.
             */
            void SetPosition(UInt64 position);
            
            /**
             * @brief Read from the file at the current file pointer position.
             * @param data Pointer to the memory to read into.
             * @param byteSize The byte size of the memory.
             * @return The number of bytes read from the file.
             */
            UInt64 Read(void* data, UInt64 byteSize);
            /**
             * @brief Write to the file at the current file pointer position.
             * @param data Pointer to the memory to read from.
             * @param byteSize The byte size of the memory.
             * @return The number of bytes written to the file.
             */
            UInt64 Write(const void* data, UInt64 byteSize);
            
        protected:
            /** The anonymous file handle for internal use only. */
            FileHandle* mHandle;
            /** The mode used for opening the file. */
            IEnums::FileAccessMode mMode;
        };
    }
}

#endif  // __MURL_SYSTEM_FILE_H__

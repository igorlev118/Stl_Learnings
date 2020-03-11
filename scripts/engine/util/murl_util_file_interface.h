// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_FILE_INTERFACE_H__
#define __MURL_UTIL_FILE_INTERFACE_H__

#include "murl_i_file_interface.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilFileClasses
         * @brief Utility class implementing a IFileInterface base class.
         */
        class FileInterface : public IFileInterface
        {
        public:
            /**
             * @brief The constructor.
             */
            FileInterface();

            /**
             * @brief The destructor.
             */
            virtual ~FileInterface();

            /**
             * @brief Implementation of IFileInterface::GetAbsoluteName().
             * @param relativeName The name of the file.
             * @param category The category where the file reside.
             * @param absoluteName The absolute file name return value.
             * @return true if successful, if false the 'absoluteName' return value is unchanged.
             */
            virtual Bool GetAbsoluteName(const String& relativeName, IEnums::FileCategory category, String& absoluteName);

            /**
             * @brief Implementation of IFileInterface::GetAllFileNames().
             * @param relativePath The name of the folder.
             * @param category The category where the folder reside.
             * @param names The array of file names return value.
             * @return true if successful, if false the 'names' return value is unchanged.
             */
            virtual Bool GetAllFileNames(const String& relativePath, IEnums::FileCategory category, StringArray& names);

            /**
             * @brief Implementation of IFileInterface::GetAllFolderNames().
             * @param relativePath The name of the folder.
             * @param category The category where the folder reside.
             * @param names The array of folder names return value.
             * @return true if successful, if false the 'names' return value is unchanged.
             */
            virtual Bool GetAllFolderNames(const String& relativePath, IEnums::FileCategory category, StringArray& names);

            /**
             * @brief Implementation of IFileInterface::OpenFile().
             * @param name The name of the file.
             * @param category The category where the file reside.
             * @param mode The access mode for the file to open.
             * @param createFolders Create the folders constained in file name
             *  if the folders do not exist.
             * @return The file interface or null if not successful.
             */
            virtual IFile* OpenFile(const String& name, IEnums::FileCategory category, IEnums::FileAccessMode mode, Bool createFolders);

            /**
             * @brief Implementation of IFileInterface::CloseFile().
             * @param handle A reference to the file interface to close.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool CloseFile(IFile*& handle);

            /**
             * @brief Implementation of IFileInterface::MapFileData().
             * @param name The name of the file.
             * @param category The category where the file reside.
             * @param data The file data object return value.
             * @return true if successful, if false the 'data' return value is unchanged.
             */
            virtual Bool MapFileData(const String& name, IEnums::FileCategory category, ConstData& data);

            /**
             * @brief Implementation of IFileInterface::UnmapFileData().
             * @param data The file data object to the memory mapped file.
             *  After unmapping the data object is empty.
             * @return true if successful.
             */
            virtual Bool UnmapFileData(ConstData& data);

        protected:
            /**
             * @brief Memory-map a read-only file.
             * @param name The name of the file.
             * @param category The category where the file reside.
             * @param data The file data pointer return value.
             * @param byteSize The byte size return value.
             * @return true if successful, if false the return values stay unchanged.
             */
            virtual Bool MapFile(const String& name, IEnums::FileCategory category, const UInt8*& data, UInt64& byteSize) = 0;

            /**
             * @brief Unmap a memory mapped file.
             * @param data The mapped file data pointer.
             * @return true if successful.
             */
            virtual Bool UnmapFile(const UInt8* data) = 0;

            /**
             * @brief Create a folder.
             * @param absolutePath The path of the folder to create.
             * @return true if successful.
             */
            virtual Bool CreateFolder(const String& absolutePath) = 0;

            /**
             * @brief Get the absolute folder path to a file category.
             * @param category The category of the folder.
             * @param absolutePath The path of the folder return value.
             * @return true if successful.
             */
            virtual Bool GetAbsolutePath(IEnums::FileCategory category, String& absolutePath) = 0;
        };
    }
}

#endif  // __MURL_UTIL_FILE_INTERFACE_H__

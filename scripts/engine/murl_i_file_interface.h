// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_I_FILE_INTERFACE_H__
#define __MURL_I_FILE_INTERFACE_H__

#include "murl_i_file.h"
#include "murl_i_enums.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IFileInterface
     * @brief The file access interface.
     * The file interface provides file access for locations on
     * the target system specified by a IEnums::FileCategory.
     */
    class IFileInterface
    {
    public:
        /**
         * @brief Check if a file exists.
         * @param name The name of the file.
         * @param category The category where the file reside.
         * @return true if the file exists.
         */
        virtual Bool FileExists(const String& name, IEnums::FileCategory category) = 0;
        /**
         * @brief Check if a folder exists.
         * @param name The name of the folder.
         * @param category The category where the folder reside.
         * @return true if the folder exists.
         */
        virtual Bool FolderExists(const String& name, IEnums::FileCategory category) = 0;

        /**
         * @brief Get the absolute file name.
         * @param relativeName The name of the file.
         * @param category The category where the file reside.
         * @param absoluteName The absolute file name return value.
         * @return true if successful, if false the 'absoluteName' return value is unchanged.
         */
        virtual Bool GetAbsoluteName(const String& relativeName, IEnums::FileCategory category, String& absoluteName) = 0;

        /**
         * @brief Get all file names inside a folder.
         * @param relativePath The name of the folder.
         * @param category The category where the folder reside.
         * @param names The array of file names return value.
         * @return true if successful, if false the 'names' return value is unchanged.
         */
        virtual Bool GetAllFileNames(const String& relativePath, IEnums::FileCategory category, StringArray& names) = 0;
        /**
         * @brief Get all folder names inside a folder.
         * @param relativePath The name of the folder.
         * @param category The category where the folder reside.
         * @param names The array of folder names return value.
         * @return true if successful, if false the 'names' return value is unchanged.
         */
        virtual Bool GetAllFolderNames(const String& relativePath, IEnums::FileCategory category, StringArray& names) = 0;

        /**
         * @brief Open a file.
         * @param name The name of the file.
         * @param category The category where the file reside.
         * @param mode The access mode for the file to open.
         * @param createFolders Create the folders constained in file name
         *  if the folders do not exist.
         * @return The file interface or null if not successful.
         */
        virtual IFile* OpenFile(const String& name, IEnums::FileCategory category, IEnums::FileAccessMode mode, Bool createFolders) = 0;
        /**
         * @brief Close a file.
         * @param handle A reference to the file interface to close.
         *  After destruction the pointer is set to null.
         * @return true if successful.
         */
        virtual Bool CloseFile(IFile*& handle) = 0;

        /**
         * @brief Memory-map a read-only file.
         * @param name The name of the file.
         * @param category The category where the file reside.
         * @param data The file data object return value.
         * @return true if successful, if false the 'data' return value is unchanged.
         */
        virtual Bool MapFileData(const String& name, IEnums::FileCategory category, ConstData& data) = 0;
        /**
         * @brief Unmap a memory mapped file.
         * @param data The file data object to the memory mapped file.
         *  After unmapping the data object is empty.
         * @return true if successful.
         */
        virtual Bool UnmapFileData(ConstData& data) = 0;

    protected:
        virtual ~IFileInterface() {}
    };
}

#endif  // __MURL_I_FILE_INTERFACE_H__

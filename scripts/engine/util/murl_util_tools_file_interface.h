// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_TOOLS_FILE_INTERFACE_H__
#define __MURL_UTIL_TOOLS_FILE_INTERFACE_H__

#include "murl_util_file_interface.h"
#include "murl_index.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilFileClasses
         * @brief Utility class implementing the IFileInterface class.
         * The tools file interface class is intend for tools development and supports the
         * file category IEnums::FILE_CATEGORY_CURRENT and IEnums::FILE_CATEGORY_ROOT only.
         */
        class ToolsFileInterface : public Util::FileInterface
        {
        public:
            /**
             * @brief The default constructor.
             */
            ToolsFileInterface();

            /**
             * @brief The destructor.
             */
            virtual ~ToolsFileInterface();

            /**
             * @brief Implementation of IFileInterface::FileExists().
             * @param name The name of the file.
             * @param category The category where the file reside.
             * @return true if the file exists.
             */
            virtual Bool FileExists(const String& name, IEnums::FileCategory category);

            /**
             * @brief Implementation of IFileInterface::FolderExists().
             * @param name The name of the folder.
             * @param category The category where the folder reside.
             * @return true if the folder exists.
             */
            virtual Bool FolderExists(const String& name, IEnums::FileCategory category);

        protected:
            /**
             * @brief Implementation of FileInterface::MapFile().
             * @param name The name of the file.
             * @param category The category where the file reside.
             * @param data The file data pointer return value.
             * @param byteSize The byte size return value.
             * @return true if successful, if false the return values stay unchanged.
             */
            virtual Bool MapFile(const String& name, IEnums::FileCategory category,
                                 const UInt8*& data, UInt64& byteSize);

            /**
             * @brief Implementation of FileInterface::UnmapFile().
             * @param data The mapped file data pointer.
             * @return true if successful.
             */
            virtual Bool UnmapFile(const UInt8* data);

            /**
             * @brief Implementation of FileInterface::CreateFolder().
             * @param absolutePath The path of the folder to create.
             * @return true if successful.
             */
            virtual Bool CreateFolder(const String& absolutePath);

            /**
             * @brief Implementation of FileInterface::GetAbsolutePath().
             * @param category The category of the folder.
             * @param absolutePath The path of the folder return value.
             * @return true if successful.
             */
            virtual Bool GetAbsolutePath(IEnums::FileCategory category, String& absolutePath);

            /** The mapped files memory pointer storage. */
            Index<const UInt8*> mMappedFiles;
        };
    }
}

#endif  // __MURL_UTIL_TOOLS_FILE_INTERFACE_H__

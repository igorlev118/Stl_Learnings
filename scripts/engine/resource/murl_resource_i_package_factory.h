// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_PACKAGE_FACTORY_H__
#define __MURL_RESOURCE_I_PACKAGE_FACTORY_H__

#include "murl_resource_i_package_factory_registry.h"
#include "murl_resource_i_object_factory.h"
#include "murl_i_factory_object.h"

namespace Murl
{
    namespace Resource
    {
        class IFactory;

        /**
         * @ingroup MurlResourceFactoryInterfaces
         * @interface IPackageFactory
         * @brief The IPackageFactory interface.
         */
        class IPackageFactory : public IFactoryObject<IPackageFactory>, public IPackageFactoryRegistry
        {
        public:
            typedef IPackageFactory* (*CreateFunction)(const IFactory* resourceFactory);

        public:
            virtual ~IPackageFactory() {}

            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Create a resource package from a file.
             * @param id The internal package ID.
             * @param fileName The name of the package file, relative to the given file category below.
             * @param fileCategory The file system category where to look for the given file.
             * @param result The object to receive the result of the operation.
             * @return The newly created package, or null if failed.
             */
            virtual IPackage* CreatePackageFromFile(const String& id,
                                                    const String& fileName, IEnums::FileCategory fileCategory,
                                                    Result& result) const = 0;
            /**
             * @brief Create a resource package from a block of memory.
             * @param id The internal package ID.
             * @param fileName The file name of the package, relative to which any individual file
             *      sub-resources/-packages are accessed from the file system.
             * @param fileCategory The file system category to prepend to the file name.
             * @param data The binary package data.
             * @param dataCanBeDisposed A reference to a Bool variable receiving true whenever it is safe
             *      to delete the input data right after package creation. If this value receives false,
             *      the input data must be kept until the package is destroyed using DestroyPackage().
             * @param result The object to receive the result of the operation.
             * @return The newly created package, or null if failed.
             */
            virtual IPackage* CreatePackageFromMemory(const String& id, const String& fileName,
                                                      IEnums::FileCategory fileCategory, const ConstData& data,
                                                      Bool& dataCanBeDisposed, Result& result) const = 0;
            /**
             * @brief Destroy a previously created package.
             * @param package A reference to a pointer holding the package to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyPackage(IPackage*& package) const = 0;

            /**
             * @brief Query information about a package file.
             * @param fileName The name of the package file, relative to the given file category below.
             * @param fileCategory The file system category where to look for the given file.
             * @param id An optional pointer to receive the package ID, if present.
             * @param revision An optional pointer to receive the user-defined package revision, if present.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @param isChecksumValid An optional pointer to receive the result of the checksum comparison,
             *      if the package does include one.
             * @return true if the package could be loaded in the first place.
             */
            virtual Bool QueryPackageFromFile(const String& fileName, IEnums::FileCategory fileCategory,
                                              String* id, UInt32* revision,
                                              Bool* isDataValid, Bool* isVersionValid, Bool* isChecksumValid) const = 0;
            /**
             * @brief Query information about a package file.
             * @param fileName The name of the package file, relative to the given file category below.
             * @param fileCategory The file system category where to look for the given file.
             * @param resourceType An optional pointer to receive the package resource type.
             * @param fileType An optional pointer to receive the package file type.
             * @param id An optional pointer to receive the package ID, if present.
             * @param revision An optional pointer to receive the user-defined package revision, if present.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @param isChecksumValid An optional pointer to receive the result of the checksum comparison,
             *      if the package does include one.
             * @return true if the package could be loaded in the first place.
             */
            virtual Bool QueryPackageFromFile(const String& fileName, IEnums::FileCategory fileCategory,
                                              IEnums::ResourceType* resourceType, IEnums::FileType* fileType,
                                              String* id, UInt32* revision,
                                              Bool* isDataValid, Bool* isVersionValid, Bool* isChecksumValid) const = 0;
            /**
             * @brief Query information about a package in memory.
             * @param data The binary package data.
             * @param id An optional pointer to receive the package ID, if present.
             * @param revision An optional pointer to receive the user-defined package revision, if present.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @param isChecksumValid An optional pointer to receive the result of the checksum comparison,
             *      if the package does include one.
             * @return true if the package could be loaded in the first place.
             */
            virtual Bool QueryPackageFromMemory(const ConstData& data,
                                                String* id, UInt32* revision, Bool* isDataValid,
                                                Bool* isVersionValid, Bool* isChecksumValid) const = 0;
            /**
             * @brief Query information about a package in memory.
             * @param data The binary package data.
             * @param resourceType An optional pointer to receive the package resource type.
             * @param fileType An optional pointer to receive the package file type.
             * @param id An optional pointer to receive the package ID, if present.
             * @param revision An optional pointer to receive the user-defined package revision, if present.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @param isChecksumValid An optional pointer to receive the result of the checksum comparison,
             *      if the package does include one.
             * @return true if the package could be loaded in the first place.
             */
            virtual Bool QueryPackageFromMemory(const ConstData& data,
                                                IEnums::ResourceType* resourceType, IEnums::FileType* fileType,
                                                String* id, UInt32* revision, Bool* isDataValid,
                                                Bool* isVersionValid, Bool* isChecksumValid) const = 0;

            /**
             * @brief Get the main resource factory.
             * @return A pointer to the main resource factory.
             */
            virtual const IFactory* GetResourceFactory() const = 0;
        };
    }
}

#endif // __MURL_RESOURCE_I_PACKAGE_FACTORY_H__

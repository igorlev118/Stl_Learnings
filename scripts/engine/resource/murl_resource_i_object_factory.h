// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_OBJECT_FACTORY_H__
#define __MURL_RESOURCE_I_OBJECT_FACTORY_H__

#include "murl_resource_i_object_factory_registry.h"
#include "murl_i_factory_object.h"

namespace Murl
{
    namespace Resource
    {
        class IFactory;

        /**
         * @ingroup MurlResourceFactoryInterfaces
         * @interface IObjectFactory
         * @brief The IObjectFactory interface.
         */
        class IObjectFactory : public IFactoryObject<IObjectFactory>, public IObjectFactoryRegistry
        {
        public:
            typedef IObjectFactory* (*CreateFunction)(const IFactory* resourceFactory);

        public:
            virtual ~IObjectFactory() {}

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
             * @brief Create a single resource object from a given file.
             * To automatically detect the actual type of resource represented by the given file,
             * specify the IEnums::RESOURCE_TYPE_DEFAULT type. If it is desired to create a raw binary
             * resource, use IEnums::RESOURCE_TYPE_BINARY. If the object should be represented as a
             * compressed binary, IEnums::RESOURCE_TYPE_ARCHIVE can be used.
             * @param type The desired resource type.
             * @param params An optional pointer to user-defined parameters used during creation.
             * @param id The object ID.
             * @param fileName The file name, relative to the file category below.
             * @param fileCategory The file category to search the file in.
             * @param result The object to receive the result of the operation.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromFile(IEnums::ResourceType type, const IAttributes* params,
                                                  const String& id,
                                                  const String& fileName, IEnums::FileCategory fileCategory,
                                                  Result& result) const = 0;
            /**
             * @brief Create a single resource object from a given block of memory.
             * See CreateObjectFromFile().
             * @param type The desired resource type.
             * @param params An optional pointer to user-defined parameters used during creation.
             * @param id The object ID.
             * @param fileName The optional file name used for internal purposes, may be empty.
             * @param fileCategory The optional file category.
             * @param data A data object holding the data for the resource to create.
             * @param dataCanBeDisposed A reference to a boolean variable receiving true when it is
             *      safe to destroy the given data object right after resource creation. If false,
             *      the data object must be kept until the object was successfully destroyed via
             *      DestroyObject().
             * @param result The object to receive the result of the operation.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromMemory(IEnums::ResourceType type, const IAttributes* params,
                                                    const String& id,
                                                    const String& fileName, IEnums::FileCategory fileCategory,
                                                    const ConstData& data, Bool& dataCanBeDisposed,
                                                    Result& result) const = 0;
            /**
             * @brief Destroy a previously created resource object.
             * @param object A reference to a pointer holding the object to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyObject(IObject*& object) const = 0;

            /**
             * @brief Query information about an object file.
             * @param fileName The name of the object file, relative to the given file category below.
             * @param fileCategory The file system category where to look for the given file.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @return true if the object could be loaded in the first place.
             */
            virtual Bool QueryObjectFromFile(const String& fileName, IEnums::FileCategory fileCategory,
                                             Bool* isDataValid, Bool* isVersionValid) const = 0;
            /**
             * @brief Query information about an object file.
             * @param fileName The name of the object file, relative to the given file category below.
             * @param fileCategory The file system category where to look for the given file.
             * @param resourceType An optional pointer to receive the object resource type.
             * @param fileType An optional pointer to receive the object file type.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @return true if the object could be loaded in the first place.
             */
            virtual Bool QueryObjectFromFile(const String& fileName, IEnums::FileCategory fileCategory,
                                             IEnums::ResourceType* resourceType, IEnums::FileType* fileType,
                                             Bool* isDataValid, Bool* isVersionValid) const = 0;
            /**
             * @brief Query information about an object in memory.
             * @param data The binary object data.
             * @param fileName The name of the object file.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @return true if the object could be loaded in the first place.
             */
            virtual Bool QueryObjectFromMemory(const ConstData& data, const String& fileName,
                                               Bool* isDataValid, Bool* isVersionValid) const = 0;
            /**
             * @brief Query information about an object in memory.
             * @param data The binary object data.
             * @param fileName The name of the object file.
             * @param resourceType An optional pointer to receive the object resource type.
             * @param fileType An optional pointer to receive the object file type.
             * @param isDataValid An optional pointer to receive the result of the overall data validity check.
             * @param isVersionValid An optional pointer to receive the result of the version check.
             * @return true if the object could be loaded in the first place.
             */
            virtual Bool QueryObjectFromMemory(const ConstData& data, const String& fileName,
                                               IEnums::ResourceType* resourceType, IEnums::FileType* fileType,
                                               Bool* isDataValid, Bool* isVersionValid) const = 0;

            /**
             * @brief Get the main resource factory.
             * @return A pointer to the main resource factory.
             */
            virtual const IFactory* GetResourceFactory() const = 0;
        };
    }
}

#endif // __MURL_RESOURCE_I_OBJECT_FACTORY_H__

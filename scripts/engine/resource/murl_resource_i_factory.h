// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_FACTORY_H__
#define __MURL_RESOURCE_I_FACTORY_H__

#include "murl_resource_i_factory_registry.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAppConfiguration;
    class IEngineConfiguration;
    class IPlatformConfiguration;
    class IFileInterface;
    class Result;

    namespace Output
    {
        class IDeviceHandler;
    }

    namespace Resource
    {
        class ICollection;
        class IImage;
        class IObject;

        /**
         * @ingroup MurlResourceFactoryInterfaces
         * @interface IFactory
         * @brief The factory class used to create and destroy any type of resource objects.
         * Use the Resource::IFactoryRegistry base interface for managing registered
         * resource collection, package and object classes.
         */
        class IFactory : public IFactoryRegistry
        {
        public:
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
             * @brief Get the total number of known collection factories.
             * @return The number of known factories.
             */
            virtual UInt32 GetNumberOfCollectionFactories() const = 0;
            /**
             * @brief Get the collection factory at a given index.
             * @param index The index, from 0 to GetNumberOfCollectionFactories()-1.
             * @return A mutable pointer to the collection factory interface.
             */
            virtual ICollectionFactory* GetCollectionFactory(UInt32 index) = 0;
            /**
             * @brief Get the collection factory at a given index.
             * @param index The index, from 0 to GetNumberOfCollectionFactories()-1.
             * @return A constant pointer to the collection factory interface.
             */
            virtual const ICollectionFactory* GetCollectionFactory(UInt32 index) const = 0;
            /**
             * @brief Get the default collection factory.
             * @return A mutable pointer to the default collection factory.
             */
            virtual ICollectionFactory* GetDefaultCollectionFactory() = 0;
            /**
             * @brief Get the default collection factory.
             * @return A constant pointer to the default collection factory.
             */
            virtual const ICollectionFactory* GetDefaultCollectionFactory() const = 0;
            /**
             * @brief Get a known collection factory by its class name.
             * @param className The class name of the factory to query.
             * @return A mutable pointer to the requested collection factory, or null if not found.
             */
            virtual ICollectionFactory* GetCollectionFactory(const String& className) = 0;
            /**
             * @brief Get a known collection factory by its class name.
             * @param className The class name of the factory to query.
             * @return A constant pointer to the requested collection factory, or null if not found.
             */
            virtual const ICollectionFactory* GetCollectionFactory(const String& className) const = 0;
            /**
             * @brief Get a known collection factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A mutable pointer to the requested collection factory, or null if not found.
             */
            virtual ICollectionFactory* GetCollectionFactory(const ICollectionFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Get a known collection factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A constant pointer to the requested collection factory, or null if not found.
             */
            virtual const ICollectionFactory* GetCollectionFactory(const ICollectionFactory::ClassInfo& classInfo) const = 0;

            /**
             * @brief Get the total number of known package factories.
             * @return The number of known factories.
             */
            virtual UInt32 GetNumberOfPackageFactories() const = 0;
            /**
             * @brief Get the package factory at a given index.
             * @param index The index, from 0 to GetNumberOfPackageFactories()-1.
             * @return A mutable pointer to the package factory interface.
             */
            virtual IPackageFactory* GetPackageFactory(UInt32 index) = 0;
            /**
             * @brief Get the package factory at a given index.
             * @param index The index, from 0 to GetNumberOfPackageFactories()-1.
             * @return A constant pointer to the package factory interface.
             */
            virtual const IPackageFactory* GetPackageFactory(UInt32 index) const = 0;
            /**
             * @brief Get the default package factory.
             * @return A mutable pointer to the default package factory.
             */
            virtual IPackageFactory* GetDefaultPackageFactory() = 0;
            /**
             * @brief Get the default package factory.
             * @return A constant pointer to the default package factory.
             */
            virtual const IPackageFactory* GetDefaultPackageFactory() const = 0;
            /**
             * @brief Get a known package factory by its class name.
             * @param className The class name of the factory to query.
             * @return A mutable pointer to the requested package factory, or null if not found.
             */
            virtual IPackageFactory* GetPackageFactory(const String& className) = 0;
            /**
             * @brief Get a known package factory by its class name.
             * @param className The class name of the factory to query.
             * @return A constant pointer to the requested package factory, or null if not found.
             */
            virtual const IPackageFactory* GetPackageFactory(const String& className) const = 0;
            /**
             * @brief Get a known package factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A mutable pointer to the requested package factory, or null if not found.
             */
            virtual IPackageFactory* GetPackageFactory(const IPackageFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Get a known package factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A constant pointer to the requested package factory, or null if not found.
             */
            virtual const IPackageFactory* GetPackageFactory(const IPackageFactory::ClassInfo& classInfo) const = 0;

            /**
             * @brief Get the total number of known object factories.
             * @return The number of known factories.
             */
            virtual UInt32 GetNumberOfObjectFactories() const = 0;
            /**
             * @brief Get the object factory at a given index.
             * @param index The index, from 0 to GetNumberOfObjectFactories()-1.
             * @return A mutable pointer to the object factory interface.
             */
            virtual IObjectFactory* GetObjectFactory(UInt32 index) = 0;
            /**
             * @brief Get the object factory at a given index.
             * @param index The index, from 0 to GetNumberOfObjectFactories()-1.
             * @return A constant pointer to the object factory interface.
             */
            virtual const IObjectFactory* GetObjectFactory(UInt32 index) const = 0;
            /**
             * @brief Get the default object factory.
             * @return A mutable pointer to the default object factory.
             */
            virtual IObjectFactory* GetDefaultObjectFactory() = 0;
            /**
             * @brief Get the default object factory.
             * @return A constant pointer to the default object factory.
             */
            virtual const IObjectFactory* GetDefaultObjectFactory() const = 0;
            /**
             * @brief Get a known object factory by its class name.
             * @param className The class name of the factory to query.
             * @return A mutable pointer to the requested object factory, or null if not found.
             */
            virtual IObjectFactory* GetObjectFactory(const String& className) = 0;
            /**
             * @brief Get a known object factory by its class name.
             * @param className The class name of the factory to query.
             * @return A constant pointer to the requested object factory, or null if not found.
             */
            virtual const IObjectFactory* GetObjectFactory(const String& className) const = 0;
            /**
             * @brief Get a known object factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A mutable pointer to the requested object factory, or null if not found.
             */
            virtual IObjectFactory* GetObjectFactory(const IObjectFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Get a known object factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A constant pointer to the requested object factory, or null if not found.
             */
            virtual const IObjectFactory* GetObjectFactory(const IObjectFactory::ClassInfo& classInfo) const = 0;

            /**
             * @brief Create a default resource collection.
             * @return The newly created collection, or null if failed.
             */
            virtual ICollection* CreateDefaultCollection() const = 0;
            /**
             * @brief Create a resource collection using a given collection class name.
             * @param className The class name of a registered collection used for creation.
             * @return The newly created collection, or null if failed.
             */
            virtual ICollection* CreateCollection(const String& className) const = 0;
            /**
             * @brief Create a resource collection using a given collection class info.
             * @param classInfo The ClassInfo structure of a registered collection used for creation.
             * @return The newly created collection, or null if failed.
             */
            virtual ICollection* CreateCollection(const ICollection::ClassInfo& classInfo) const = 0;
            /**
             * @brief Destroy a previously created resource collection.
             * @param collection A reference to a pointer holding the collection to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyCollection(ICollection*& collection) const = 0;

            /**
             * @brief Create a single resource object from a given file.
             * To automatically detect the actual type of resource represented by the given file,
             * specify the IEnums::RESOURCE_TYPE_DEFAULT type. If it is desired to include the file
             * "as is" (i.e. raw binary data), use IEnums::RESOURCE_TYPE_BINARY. To include the file
             * as a compressed binary, IEnums::RESOURCE_TYPE_ARCHIVE can be used.
             * The file with the given name is loaded from the default resource location, which
             * can be set via IEngineConfiguration::SetResourceFileCategory().
             * @param type The desired resource type.
             * @param fileName The name of the file to load.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromFile(IEnums::ResourceType type, const String& fileName) const = 0;
            /**
             * @brief Create a single resource object from a given file.
             * To automatically detect the actual type of resource represented by the given file,
             * specify the IEnums::RESOURCE_TYPE_DEFAULT type. If it is desired to include the file
             * "as is" (i.e. raw binary data), use IEnums::RESOURCE_TYPE_BINARY. To include the file
             * as a compressed binary, IEnums::RESOURCE_TYPE_ARCHIVE can be used.
             * The file with the given name is loaded from the default resource location, which
             * can be set via IEngineConfiguration::SetResourceFileCategory().
             * @param type The desired resource type.
             * @param fileName The name of the file to load.
             * @param result The object to receive the result of the operation.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromFile(IEnums::ResourceType type, const String& fileName, Result& result) const = 0;
            /**
             * @brief Create a single resource object from a given file.
             * To automatically detect the actual type of resource represented by the given file,
             * specify the IEnums::RESOURCE_TYPE_DEFAULT type. If it is desired to include the file
             * "as is" (i.e. raw binary data), use IEnums::RESOURCE_TYPE_BINARY. To include the file
             * as a compressed binary, IEnums::RESOURCE_TYPE_ARCHIVE can be used.
             * The file with the given name is loaded from the default resource location, which
             * can be set via IEngineConfiguration::SetResourceFileCategory().
             * @param type The desired resource type.
             * @param params An optional pointer to user-defined parameters used during creation.
             * @param fileName The name of the file to load.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromFile(IEnums::ResourceType type, const IAttributes* params, const String& fileName) const = 0;
            /**
             * @brief Create a single resource object from a given file.
             * To automatically detect the actual type of resource represented by the given file,
             * specify the IEnums::RESOURCE_TYPE_DEFAULT type. If it is desired to include the file
             * "as is" (i.e. raw binary data), use IEnums::RESOURCE_TYPE_BINARY. To include the file
             * as a compressed binary, IEnums::RESOURCE_TYPE_ARCHIVE can be used.
             * The file with the given name is loaded from the default resource location, which
             * can be set via IEngineConfiguration::SetResourceFileCategory().
             * @param type The desired resource type.
             * @param params An optional pointer to user-defined parameters used during creation.
             * @param fileName The name of the file to load.
             * @param result The object to receive the result of the operation.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromFile(IEnums::ResourceType type, const IAttributes* params, const String& fileName, Result& result) const = 0;
            /**
             * @brief Create a single resource object from a given block of memory.
             * See CreateObjectFromFile().
             * @param type The desired resource type.
             * @param data A data object holding the data for the resource to create.
             * @param dataCanBeDisposed A reference to a boolean variable receiving true when it is
             *      safe to destroy the given data object right after resource creation. If false,
             *      the data object must be kept until the object was successfully destroyed via
             *      DestroyObject().
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromMemory(IEnums::ResourceType type, const ConstData& data,
                                                    Bool& dataCanBeDisposed) const = 0;
            /**
             * @brief Create a single resource object from a given block of memory.
             * See CreateObjectFromFile().
             * @param type The desired resource type.
             * @param data A data object holding the data for the resource to create.
             * @param dataCanBeDisposed A reference to a boolean variable receiving true when it is
             *      safe to destroy the given data object right after resource creation. If false,
             *      the data object must be kept until the object was successfully destroyed via
             *      DestroyObject().
             * @param result The object to receive the result of the operation.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromMemory(IEnums::ResourceType type, const ConstData& data,
                                                    Bool& dataCanBeDisposed, Result& result) const = 0;
            /**
             * @brief Create a single resource object from a given block of memory.
             * See CreateObjectFromFile().
             * @param type The desired resource type.
             * @param params An optional pointer to user-defined parameters used during creation.
             * @param data A data object holding the data for the resource to create.
             * @param dataCanBeDisposed A reference to a boolean variable receiving true when it is
             *      safe to destroy the given data object right after resource creation. If false,
             *      the data object must be kept until the object was successfully destroyed via
             *      DestroyObject().
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromMemory(IEnums::ResourceType type, const IAttributes* params, const ConstData& data,
                                                    Bool& dataCanBeDisposed) const = 0;
            /**
             * @brief Create a single resource object from a given block of memory.
             * See CreateObjectFromFile().
             * @param type The desired resource type.
             * @param params An optional pointer to user-defined parameters used during creation.
             * @param data A data object holding the data for the resource to create.
             * @param dataCanBeDisposed A reference to a boolean variable receiving true when it is
             *      safe to destroy the given data object right after resource creation. If false,
             *      the data object must be kept until the object was successfully destroyed via
             *      DestroyObject().
             * @param result The object to receive the result of the operation.
             * @return A pointer to the newly created resource object, or null if failed.
             */
            virtual IObject* CreateObjectFromMemory(IEnums::ResourceType type, const IAttributes* params, const ConstData& data,
                                                    Bool& dataCanBeDisposed, Result& result) const = 0;
            /**
             * @brief Destroy a previously created resource object.
             * @param object A reference to a pointer holding the object to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyObject(IObject*& object) const = 0;

            /**
             * @brief Create a raw image resource.
             * @param pixelFormat The pixel format to use.
             * @param pixelSizeX The width of the image in pixels.
             * @param pixelSizeY The height of the image in pixels.
             * @return A pointer to the newly created image resource, or null if failed.
             */
            virtual IImage* CreateRawImage(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY) const = 0;
            /**
             * @brief Destroy a previously created image resource.
             * @param image A reference to a pointer holding the image to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyRawImage(IImage*& image) const = 0;

            /**
             * @brief Get the current platform configuration.
             * @return A pointer to the platform configuration object.
             */
            virtual const IPlatformConfiguration* GetPlatformConfiguration() const = 0;
            /**
             * @brief Get the current engine configuration.
             * @return A pointer to the engine configuration object.
             */
            virtual const IEngineConfiguration* GetEngineConfiguration() const = 0;
            /**
             * @brief Get the current app configuration.
             * @return A pointer to the app configuration object.
             */
            virtual const IAppConfiguration* GetAppConfiguration() const = 0;

            /**
             * @brief Get the current file interface.
             * @return A pointer to the file interface object.
             */
            virtual IFileInterface* GetFileInterface() const = 0;

            /**
             * @brief Get the current output device handler.
             * @return A pointer to the output device handler object.
             */
            virtual const Output::IDeviceHandler* GetOutputDeviceHandler() const = 0;

        protected:
            virtual ~IFactory() {}
        };

        /**
         * @ingroup MurlResourceFactoryClasses
         * @brief The StaticFactory class to create the IFactory object.
         * The StaticFactory is used by the engine's core only.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create the resource factory object.
             * @param appConfig The application configuration object.
             * @param outputDeviceHandler The output device handler.
             * @param fileInterface The file interface object.
             * @return The created resource factory object, or null if failed.
             */
            static IFactory* CreateFactory(const IAppConfiguration* appConfig, const Output::IDeviceHandler* outputDeviceHandler,
                                           IFileInterface* fileInterface);
            /**
             * @brief Destroy the resource factory object.
             * @param factory A reference to the resource factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyFactory(IFactory*& factory);
        };
    }
}

#endif  // __MURL_RESOURCE_I_FACTORY_H__

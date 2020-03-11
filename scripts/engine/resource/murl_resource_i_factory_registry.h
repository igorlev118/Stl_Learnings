// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_FACTORY_REGISTRY_H__
#define __MURL_RESOURCE_I_FACTORY_REGISTRY_H__

#include "murl_resource_i_collection_factory.h"
#include "murl_resource_i_object_factory.h"
#include "murl_resource_i_package_factory.h"

namespace Murl
{
    namespace Resource
    {
        /**
         * @ingroup MurlResourceFactoryInterfaces
         * @interface IFactoryRegistry
         * @brief The IFactoryRegistry interface.
         * The IFactoryRegistry interface provides methods to add, remove and query different
         * sub-factory classes for creating collections, packages and individual objects.
         * The Resource::IFactory interfaces derives from this interface, in order to be able
         * to actually instantiate any entities via the set of classes present in the registry.
         */
        class IFactoryRegistry
        {
        public:
            /**
             * @brief Register a collection factory class.
             * @param classInfo The ClassInfo structure of the collection factory to register.
             * @return true if successful.
             */
            virtual Bool RegisterCollectionFactoryClass(const ICollectionFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered collection factory class.
             * @param classInfo The ClassInfo structure of the collection factory to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterCollectionFactoryClass(const ICollectionFactory::ClassInfo& classInfo) = 0;
            
            /**
             * @brief Register a package factory class.
             * @param classInfo The ClassInfo structure of the package factory to register.
             * @return true if successful.
             */
            virtual Bool RegisterPackageFactoryClass(const IPackageFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered package factory class.
             * @param classInfo The ClassInfo structure of the package factory to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterPackageFactoryClass(const IPackageFactory::ClassInfo& classInfo) = 0;
            
            /**
             * @brief Register an object factory class.
             * @param classInfo The ClassInfo structure of the object factory to register.
             * @return true if successful.
             */
            virtual Bool RegisterObjectFactoryClass(const IObjectFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered object factory class.
             * @param classInfo The ClassInfo structure of the object factory to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterObjectFactoryClass(const IObjectFactory::ClassInfo& classInfo) = 0;

            /**
             * @brief Get the total number of known collection factory registries.
             * @return The number of known registries.
             */
            virtual UInt32 GetNumberOfCollectionFactoryRegistries() const = 0;
            /**
             * @brief Get the registry interface of the collection factory at a given index.
             * @param index The index, from 0 to GetNumberOfCollectionFactoryRegistries()-1.
             * @return A mutable pointer to the collection factory's registry interface.
             */
            virtual ICollectionFactoryRegistry* GetCollectionFactoryRegistry(UInt32 index) = 0;
            /**
             * @brief Get the registry interface of the collection factory at a given index.
             * @param index The index, from 0 to GetNumberOfCollectionFactoryRegistries()-1.
             * @return A constant pointer to the collection factory's registry interface.
             */
            virtual const ICollectionFactoryRegistry* GetCollectionFactoryRegistry(UInt32 index) const = 0;
            /**
             * @brief Get the registry interface of the default collection factory.
             * @return A mutable pointer to the default collection factory's registry interface.
             */
            virtual ICollectionFactoryRegistry* GetDefaultCollectionFactoryRegistry() = 0;
            /**
             * @brief Get the registry interface of the default collection factory.
             * @return A constant pointer to the default collection factory's registry interface.
             */
            virtual const ICollectionFactoryRegistry* GetDefaultCollectionFactoryRegistry() const = 0;
            /**
             * @brief Get the registry interface of a known collection factory by its class name.
             * @param className The class name of the factory to query.
             * @return A mutable pointer to the requested collection factory's registry interface,
             *      or null if not found.
             */
            virtual ICollectionFactoryRegistry* GetCollectionFactoryRegistry(const String& className) = 0;
            /**
             * @brief Get the registry interface of a known collection factory by its class name.
             * @param className The class name of the factory to query.
             * @return A constant pointer to the requested collection factory's registry interface,
             *      or null if not found.
             */
            virtual const ICollectionFactoryRegistry* GetCollectionFactoryRegistry(const String& className) const = 0;
            /**
             * @brief Get the registry interface of a known collection factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A mutable pointer to the requested collection factory's registry interface,
             *      or null if not found.
             */
            virtual ICollectionFactoryRegistry* GetCollectionFactoryRegistry(const ICollectionFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Get the registry interface of a known collection factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A constant pointer to the requested collection factory's registry interface,
             *      or null if not found.
             */
            virtual const ICollectionFactoryRegistry* GetCollectionFactoryRegistry(const ICollectionFactory::ClassInfo& classInfo) const = 0;

            /**
             * @brief Get the total number of known package factory registries.
             * @return The number of known registries.
             */
            virtual UInt32 GetNumberOfPackageFactoryRegistries() const = 0;
            /**
             * @brief Get the registry interface of the package factory at a given index.
             * @param index The index, from 0 to GetNumberOfPackageFactoryRegistries()-1.
             * @return A mutable pointer to the package factory's registry interface.
             */
            virtual IPackageFactoryRegistry* GetPackageFactoryRegistry(UInt32 index) = 0;
            /**
             * @brief Get the registry interface of the package factory at a given index.
             * @param index The index, from 0 to GetNumberOfPackageFactoryRegistries()-1.
             * @return A constant pointer to the package factory's registry interface.
             */
            virtual const IPackageFactoryRegistry* GetPackageFactoryRegistry(UInt32 index) const = 0;
            /**
             * @brief Get the registry interface of the default package factory.
             * @return A mutable pointer to the default package factory's registry interface.
             */
            virtual IPackageFactoryRegistry* GetDefaultPackageFactoryRegistry() = 0;
            /**
             * @brief Get the registry interface of the default package factory.
             * @return A constant pointer to the default package factory's registry interface.
             */
            virtual const IPackageFactoryRegistry* GetDefaultPackageFactoryRegistry() const = 0;
            /**
             * @brief Get the registry interface of a known package factory by its class name.
             * @param className The class name of the factory to query.
             * @return A mutable pointer to the requested package factory's registry interface,
             *      or null if not found.
             */
            virtual IPackageFactoryRegistry* GetPackageFactoryRegistry(const String& className) = 0;
            /**
             * @brief Get the registry interface of a known package factory by its class name.
             * @param className The class name of the factory to query.
             * @return A constant pointer to the requested package factory's registry interface,
             *      or null if not found.
             */
            virtual const IPackageFactoryRegistry* GetPackageFactoryRegistry(const String& className) const = 0;
            /**
             * @brief Get the registry interface of a known package factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A mutable pointer to the requested package factory's registry interface,
             *      or null if not found.
             */
            virtual IPackageFactoryRegistry* GetPackageFactoryRegistry(const IPackageFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Get the registry interface of a known package factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A constant pointer to the requested package factory's registry interface,
             *      or null if not found.
             */
            virtual const IPackageFactoryRegistry* GetPackageFactoryRegistry(const IPackageFactory::ClassInfo& classInfo) const = 0;
            
            /**
             * @brief Get the total number of known object factory registries.
             * @return The number of known registries.
             */
            virtual UInt32 GetNumberOfObjectFactoryRegistries() const = 0;
            /**
             * @brief Get the registry interface of the object factory at a given index.
             * @param index The index, from 0 to GetNumberOfObjectFactoryRegistries()-1.
             * @return A mutable pointer to the object factory's registry interface.
             */
            virtual IObjectFactoryRegistry* GetObjectFactoryRegistry(UInt32 index) = 0;
            /**
             * @brief Get the registry interface of the object factory at a given index.
             * @param index The index, from 0 to GetNumberOfObjectFactoryRegistries()-1.
             * @return A constant pointer to the object factory's registry interface.
             */
            virtual const IObjectFactoryRegistry* GetObjectFactoryRegistry(UInt32 index) const = 0;
            /**
             * @brief Get the registry interface of the default object factory.
             * @return A mutable pointer to the default object factory's registry interface.
             */
            virtual IObjectFactoryRegistry* GetDefaultObjectFactoryRegistry() = 0;
            /**
             * @brief Get the registry interface of the default object factory.
             * @return A constant pointer to the default object factory's registry interface.
             */
            virtual const IObjectFactoryRegistry* GetDefaultObjectFactoryRegistry() const = 0;
            /**
             * @brief Get the registry interface of a known object factory by its class name.
             * @param className The class name of the factory to query.
             * @return A mutable pointer to the requested object factory's registry interface,
             *      or null if not found.
             */
            virtual IObjectFactoryRegistry* GetObjectFactoryRegistry(const String& className) = 0;
            /**
             * @brief Get the registry interface of a known object factory by its class name.
             * @param className The class name of the factory to query.
             * @return A constant pointer to the requested object factory's registry interface,
             *      or null if not found.
             */
            virtual const IObjectFactoryRegistry* GetObjectFactoryRegistry(const String& className) const = 0;
            /**
             * @brief Get the registry interface of a known object factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A mutable pointer to the requested object factory's registry interface,
             *      or null if not found.
             */
            virtual IObjectFactoryRegistry* GetObjectFactoryRegistry(const IObjectFactory::ClassInfo& classInfo) = 0;
            /**
             * @brief Get the registry interface of a known object factory by its class info structure.
             * @param classInfo The factory's ClassInfo structure.
             * @return A constant pointer to the requested object factory's registry interface,
             *      or null if not found.
             */
            virtual const IObjectFactoryRegistry* GetObjectFactoryRegistry(const IObjectFactory::ClassInfo& classInfo) const = 0;

        protected:
            virtual ~IFactoryRegistry() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_FACTORY_REGISTRY_H__

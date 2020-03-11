//Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_COLLECTION_FACTORY_REGISTRY_H__
#define __MURL_RESOURCE_I_COLLECTION_FACTORY_REGISTRY_H__

#include "murl_resource_i_collection.h"
#include "murl_resource_i_package_factory.h"

namespace Murl
{
    namespace Resource
    {
        /**
         * @ingroup MurlResourceFactoryInterfaces
         * @interface ICollectionFactoryRegistry
         * @brief The ICollectionFactoryRegistry interface.
         * The ICollectionFactoryRegistry interface provides methods to add, remove and query different
         * collection classes that can be instantiated using the Resource::ICollectionFactory implementing
         * this interface. It also allows to register/unregister individual package factories that
         * can be associated with one or more of the given collection factories, so that multiple
         * collection factories can possibly handle the same type(s) of packages.
         */
        class ICollectionFactoryRegistry
        {
        public:
            /**
             * @brief Register a collection class.
             * @param collectionClassInfo The ClassInfo structure of the collection to register.
             * @return true if successful.
             */
            virtual Bool RegisterCollectionClass(const ICollection::ClassInfo& collectionClassInfo) = 0;
            /**
             * @brief Unregister a previously registered collection class.
             * @param collectionClassInfo The ClassInfo structure of the collection to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterCollectionClass(const ICollection::ClassInfo& collectionClassInfo) = 0;
            
            /**
             * @brief Register a package factory.
             * @param packageFactory The package factory to register.
             * @return true if successful.
             */
            virtual Bool RegisterPackageFactory(const IPackageFactory* packageFactory) = 0;
            /**
             * @brief Unregister a previously registered package factory class.
             * @param packageFactory The package factory to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterPackageFactory(const IPackageFactory* packageFactory) = 0;

            /**
             * @brief Query the index of a registered collection class, by its ClassInfo structure.
             * @param classInfo The class info structure of the collection class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredCollectionClassInfoIndex(const ICollection::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the index of a registered collection class, by its class name.
             * @param className The name of the collection class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredCollectionClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered collection classes.
             * @return The number of registered collection classes.
             */
            virtual UInt32 GetNumberOfRegisteredCollectionClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered collection class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredCollectionClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const ICollection::ClassInfo* GetRegisteredCollectionClassInfo(UInt32 index) const = 0;
            
            /**
             * @brief Get the total number of registered package factories.
             * @return The number of registered package factories.
             */
            virtual UInt32 GetNumberOfRegisteredPackageFactories() const = 0;
            /**
             * @brief Get the package factory at a given index.
             * @param index The index to query, from 0 to GetNumberOfRegisteredPackageFactories()-1.
             * @return The package factory, or null if the index is out of range.
             */
            virtual const IPackageFactory* GetRegisteredPackageFactory(UInt32 index) const = 0;

        protected:
            virtual ~ICollectionFactoryRegistry() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_COLLECTION_FACTORY_REGISTRY_H__


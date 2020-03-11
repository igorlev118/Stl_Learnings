//Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_COLLECTION_FACTORY_H__
#define __MURL_RESOURCE_I_COLLECTION_FACTORY_H__

#include "murl_resource_i_collection_factory_registry.h"
#include "murl_resource_i_package_factory.h"
#include "murl_i_factory_object.h"

namespace Murl
{
    namespace Resource
    {
        class IFactory;

        /**
         * @ingroup MurlResourceFactoryInterfaces
         * @interface ICollectionFactory
         * @brief The resource collection factory interface.
         * Use the Resource::ICollectionFactoryRegistry base interface for managing registered
         * resource collection classes.
         */
        class ICollectionFactory : public IFactoryObject<ICollectionFactory>, public ICollectionFactoryRegistry
        {
        public:
            typedef ICollectionFactory* (*CreateFunction)(const IFactory* resourceFactory);
            
        public:
            virtual ~ICollectionFactory() {}

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
             * @brief Create a default resource collection.
             * @return The newly created collection, or null if failed.
             */
            virtual ICollection* CreateDefaultCollection() const = 0;
            /**
             * @brief Create a resource collection via its class name.
             * @param className The class name of a registered collection used for creation.
             * @return The newly created collection, or null if failed.
             */
            virtual ICollection* CreateCollection(const String& className) const = 0;
            /**
             * @brief Create a resource collection via its class info.
             * @param classInfo The ClassInfo structure of a registered collection used for creation.
             * @return The newly created collection, or null if failed.
             */
            virtual ICollection* CreateCollection(const ICollection::ClassInfo& classInfo) const = 0;
            /**
             * @brief Destroy a resource collection previously created by this factory.
             * @param collection A reference to a pointer holding the collection to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyCollection(ICollection*& collection) const = 0;

            /**
             * @brief Get the main resource factory.
             * @return A pointer to the main resource factory.
             */
            virtual const IFactory* GetResourceFactory() const = 0;
        };
    }
}

#endif  // __MURL_RESOURCE_I_COLLECTION_FACTORY_H__


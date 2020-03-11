// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_PACKAGE_FACTORY_REGISTRY_H__
#define __MURL_RESOURCE_I_PACKAGE_FACTORY_REGISTRY_H__

#include "murl_resource_i_package.h"
#include "murl_resource_i_object_factory.h"
    
namespace Murl
{
    namespace Resource
    {
        /**
         * @ingroup MurlResourceFactoryInterfaces
         * @interface IPackageFactoryRegistry
         * @brief The IPackageFactoryRegistry interface.
         * The IPackageFactoryRegistry interface provides methods to add, remove and query different
         * package classes that can be instantiated using the Resource::IPackageFactory implementing
         * this interface.
         */
        class IPackageFactoryRegistry
        {
        public:
            /**
             * @brief Register a package class.
             * A specific package factory class may be registered multiple times with (mandatory) different 
             * file name patterns, and a possibly different object factory used for object creation.
             * @param packageClassInfo The ClassInfo structure of the package to register.
             * @param objectFactory The actual object factory used to create individual resource objects
             *      from within the package.
             * @param fileNamePattern The file name pattern used to identify packages of this type, e.g. "murlpkg" or "murlres/package.xml".
             * @return true if successful.
             */
            virtual Bool RegisterPackageClass(const IPackage::ClassInfo& packageClassInfo, const IObjectFactory* objectFactory, const String& fileNamePattern) = 0;
            /**
             * @brief Unregister a previously registered package class/object factory/file name pattern combination.
             * @param packageClassInfo The ClassInfo structure of the package to unregister.
             * @param objectFactory The object factory the given package class was registered with.
             * @param fileNamePattern The file name pattern the given package class was registered with.
             * @return true if successful.
             */
            virtual Bool UnregisterPackageClass(const IPackage::ClassInfo& packageClassInfo, const IObjectFactory* objectFactory, const String& fileNamePattern) = 0;
            
            /**
             * @brief Query the first index of a registered package class, by its ClassInfo structure.
             * @param classInfo The class info structure of the package class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredPackageClassInfoIndex(const IPackage::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the first index of a registered package class, by its class name.
             * @param className The name of the package class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredPackageClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered package classes.
             * @return The number of registered package classes.
             */
            virtual UInt32 GetNumberOfRegisteredPackageClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered package class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredPackageClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const IPackage::ClassInfo* GetRegisteredPackageClassInfo(UInt32 index) const = 0;
            /**
             * @brief Get the file name pattern of a registered package class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredPackageClassInfos()-1.
             * @return The name pattern, or an empty string if the index is out of range.
             */
            virtual const String& GetRegisteredPackageClassInfoFileNamePattern(UInt32 index) const = 0;
            /**
             * @brief Get the associated object factory of a registered package class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredPackageClassInfos()-1.
             * @return The object factory, or null if the index is out of range.
             */
            virtual const IObjectFactory* GetRegisteredPackageClassInfoObjectFactory(UInt32 index) const = 0;

        public:
            virtual ~IPackageFactoryRegistry() {}
        };
    }
}

#endif // __MURL_RESOURCE_I_PACKAGE_FACTORY_REGISTRY_H__

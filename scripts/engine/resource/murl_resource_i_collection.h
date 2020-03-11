// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_COLLECTION_H__
#define __MURL_RESOURCE_I_COLLECTION_H__

#include "murl_resource_types.h"
#include "murl_i_factory_object.h"
#include "murl_i_enums.h"
#include "murl_data.h"

namespace Murl
{
    namespace Resource
    {
        class IAnimation;
        class IArchive;
        class IAtlas;
        class IAudio;
        class IBinary;
        class ICollectionFactory;
        class ICondition;
        class IDictionary;
        class IFont;
        class IGraph;
        class IGrid;
        class IImage;
        class IMesh;
        class IObject;
        class IPackage;
        class IPackageFactory;
        class IScript;
        class IShader;
        class IText;
        class IVideo;

        /**
         * @ingroup MurlResourceContainerInterfaces
         * @interface ICollection
         * @brief The resource collection interface.
         * A resource collection provides methods to manage individual Resource::IPackage objects,
         * which contain a number of individual Resource::IObject instances. The resource collection
         * also provides methods to retrieve individual objects via a package/object identifier
         * pair in the form "packageId:objectId", as in GetObject() and related methods.
         */
        class ICollection : public IFactoryObject<ICollection>
        {
        public:
            typedef ICollection* (*CreateFunction)(const ICollectionFactory* collectionFactory, const Array<const IPackageFactory*>& packageFactories);

        public:
            virtual ~ICollection() {}

            /**
             * @brief Get the mutable ICollection interface.
             * @return The ICollection interface.
             */
            virtual ICollection* GetCollectionInterface() = 0;
            /**
             * @brief Get the constant ICollection interface.
             * @return The ICollection interface.
             */
            virtual const ICollection* GetCollectionInterface() const = 0;

            /**
             * @brief Get the factory object used to create this collection.
             * @return The creator factory.
             */
            virtual const ICollectionFactory* GetCreator() const = 0;

            /**
             * @brief Initialize this collection.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief De-initialize this collection.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Register a specific package from a block of memory.
             * This method can be used to register a package from memory as if it was a file on disk.
             * Internally, the CreatePackageFromFile() first checks if any package with the given file
             * name was registered through this method before actually searching the file system.
             * @param name The file name to register.
             * @param data A Data object containing the binary package.
             * @return true if successful.
             */
            virtual Bool RegisterPackageData(const String& name, const ConstData& data) = 0;
            /**
             * @brief Unregister a package previously registered through RegisterPackageData().
             * @param name The file name to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterPackageData(const String& name) = 0;

            /**
             * @brief Create a resource package from a file.
             * @param id The internal package ID.
             * @param condition An optional condition interface to check.
             * @param fileName The name of the package file, relative to the given file category below.
             * @param fileCategory The file system category where to look for the given file.
             * @param result The object to receive the result of the operation.
             * @return The newly created package, or null if failed.
             */
            virtual const IPackage* CreatePackageFromFile(const String& id, const ICondition* condition, const String& fileName, IEnums::FileCategory fileCategory, Result& result) = 0;
            /**
             * @brief Create a resource package from a block of memory.
             * @param id The internal package ID.
             * @param condition An optional condition interface to check.
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
            virtual const IPackage* CreatePackageFromMemory(const String& id, const ICondition* condition, const String& fileName, IEnums::FileCategory fileCategory, const ConstData& data, Bool& dataCanBeDisposed, Result& result) = 0;
            /**
             * @brief Create a reference to an existing resource package.
             * @param referencedPackage The package to refer to.
             * @param id The internal package ID.
             * @param condition An optional condition interface to check.
             * @return The referenced package, or null if failed.
             */
            virtual const IPackage* CreatePackageReference(const IPackage* referencedPackage, const String& id, const ICondition* condition) = 0;
            /**
             * @brief Destroy a previously created package.
             * @param package A reference to a pointer holding the package to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyPackage(const IPackage*& package) = 0;

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
            virtual Bool QueryPackageFromFile(const String& fileName, IEnums::FileCategory fileCategory, String* id, UInt32* revision, Bool* isDataValid, Bool* isVersionValid, Bool* isChecksumValid) const = 0;
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
            virtual Bool QueryPackageFromMemory(const ConstData& data, String* id, UInt32* revision, Bool* isDataValid, Bool* isVersionValid, Bool* isChecksumValid) const = 0;

            /**
             * @brief Get the total number of packages in this collection.
             * @return The number of packages.
             */
            virtual UInt32 GetNumberOfPackages() const = 0;
            /**
             * @brief Get the package at a given index.
             * @param index The index of the package, from 0 to GetNumberOfPackages()-1.
             * @return A pointer to the package, or null if the index is out of range.
             */
            virtual const IPackage* GetPackage(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a package at a given index.
             * @param index The index of the package, from 0 to GetNumberOfPackages()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetPackageCondition(UInt32 index) const = 0;
            /**
             * @brief Get a package by its ID.
             * @param id The package ID to query.
             * @return A pointer to the package, or null if a package with given ID was not found.
             */
            virtual const IPackage* GetPackage(const String& id) const = 0;

            /**
             * @brief Get a single generic resource object by its package/object ID.
             * The given ID must be in the form "/packageId/objectId", to reference an object in
             * a specific loaded package. If the package contains sub-packages, the resource may
             * be referenced via e.g. "/packageId/subPackageId/objectId".
             * @param id The ID of the object to retrieve.
             * @return A pointer to the generic object, or null if not found.
             */
            virtual const IObject* GetObject(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IBinary.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IBinary* GetBinary(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IGraph.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IGraph* GetGraph(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IImage.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IImage* GetImage(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IMesh.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IMesh* GetMesh(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IFont.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IFont* GetFont(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IShader.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IShader* GetShader(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IAudio.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IAudio* GetAudio(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IAnimation.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IAnimation* GetAnimation(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IAtlas.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IAtlas* GetAtlas(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IArchive.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IArchive* GetArchive(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IVideo.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IVideo* GetVideo(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IScript.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IScript* GetScript(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IDictionary.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IDictionary* GetDictionary(const String& id) const = 0;
            /**
             * @brief Get a single object as a specialized Resource::IGrid.
             * See GetObject().
             * @param id The ID of the object to retrieve.
             * @return A pointer to the specialized object, or null if not found.
             */
            virtual const IGrid* GetGrid(const String& id) const = 0;
            /**
             * @brief Get a single text resource.
             * See GetObject().
             * @param id The ID of the text to retrieve.
             * @return A pointer to the text object, or null if not found.
             */
            virtual const IText* GetText(const String& id) const = 0;

            /**
             * @brief Set the optional parent package this collection belongs to.
             * @param parentPackage The containing package, or null for removing.
             * @return true if successful.
             */
            virtual Bool SetParentPackage(const IPackage* parentPackage) = 0;
            /**
             * @brief Get the optional parent package this collection belongs to.
             * @return The containing package, or null if the collection is not
             *      contained in another package.
             */
            virtual const IPackage* GetParentPackage() const = 0;

            /**
             * @brief Set the optional parent collection.
             * An optional parent collection can be defined to perform an additional
             * search for a resource (via package and object ID) if it cannot be
             * found in this collection.
             * @param parentCollection The parent collection, or null for removing.
             * @return true if successful.
             */
            virtual Bool SetParentCollection(const ICollection* parentCollection) = 0;
            /**
             * @brief Get the optional parent collection.
             * @return The parent collection, or null if not defined.
             */
            virtual const ICollection* GetParentCollection() const = 0;

            /**
             * @brief Query the total number of allocated resource bytes in this collection.
             * @return The number of allocated bytes.
             */
            virtual UInt32 GetNumberOfAllocatedResourceBytes() const = 0;
        };
    }
}

#endif  // __MURL_RESOURCE_I_COLLECTION_H__

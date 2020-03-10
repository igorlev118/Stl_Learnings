// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_PACKAGE_H__
#define __MURL_RESOURCE_I_PACKAGE_H__

#include "murl_resource_i_object.h"
#include "murl_i_factory_object.h"
#include "murl_data.h"
#include "murl_util_iff.h"

namespace Murl
{
    class IAppConfiguration;
    class IFileInterface;
    class Result;

    namespace Resource
    {
        class IAnimation;
        class IArchive;
        class IAtlas;
        class IAudio;
        class IBinary;
        class ICondition;
        class IDictionary;
        class IFont;
        class IGraph;
        class IGrid;
        class IImage;
        class IInstance;
        class IMesh;
        class IObject;
        class IObjectFactory;
        class IPackageFactory;
        class IShader;
        class IScript;
        class IText;
        class IVideo;

        /**
         * @ingroup MurlResourceContainerInterfaces
         * @interface IPackage
         * @brief The IPackage resource interface.
         */
        class IPackage : public IFactoryObject<IPackage>
        {
        public:
            typedef IPackage* (*CreateFunction)(const IPackageFactory* packageFactory, const IObjectFactory* objectFactory, const String& fileName, IEnums::FileCategory fileCategory, const ConstData& data, Bool& dataCanBeDisposed, Result& result);
            typedef Bool (*QueryFunction)(const ConstData& data, IEnums::ResourceType* resourceType, IEnums::FileType* fileType, String* id, UInt32* revision, Bool* isDataValid, Bool* isVersionValid, Bool* isChecksumValid);

            /**
             * @brief The class information object.
             */
            class ClassInfo : public IFactoryObject<IPackage>::ClassInfo
            {
            public:
                /**
                 * @brief The default constructor.
                 */
                ClassInfo()
                : IFactoryObject<IPackage>::ClassInfo()
                , mQueryFunction(0)
                {
                }

                /**
                 * @brief The constructor taking a class name, create function and query function.
                 * @param className The class name.
                 * @param createFunction The function to create a package.
                 * @param queryFunction The function to query information about a package.
                 * @param baseClassInfo A pointer to the ClassInfo structure of an
                 *      optional base class, if this class is a derived one.
                 * @param propertyInfo The property information of the class.
                 * @param attributeInfo The attribute information of the class.
                 */
                ClassInfo(const String& className, CreateFunction createFunction, QueryFunction queryFunction, const IFactoryObject<IPackage>::ClassInfo* baseClassInfo, const PropertyInfo* propertyInfo, const AttributeInfo* attributeInfo)
                : IFactoryObject<IPackage>::ClassInfo(className, createFunction, baseClassInfo, propertyInfo, attributeInfo)
                , mQueryFunction(queryFunction)
                {
                }

                /**
                 * @brief Get the query function.
                 * @return The query function.
                 */
                QueryFunction GetQueryFunction() const
                {
                    return mQueryFunction;
                }

            protected:
                QueryFunction mQueryFunction;
            };

        public:
            /// Package flags.
            enum Flags
            {
                /// If set, the mChecksum value in the header chunk holds the package checksum.
                FLAG_HAS_CHECKSUM = (1 << 0)
            };

            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource package.
                    FOURCC = 'RPKG',
                    /// The version of a native package supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native package.
                 */
                struct HeaderChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a HeaderChunk.
                        FOURCC = 'HEAD'
                    };

                    /// The actual package version.
                    UInt32 mVersion;
                    /// The optional checksum.
                    UInt32 mChecksum;

                    /// A user-defined revision code.
                    UInt32 mRevision;
                    /// Package flags, from the Flags enumeration.
                    UInt32 mFlags;

                    /// An offset into the chunk where the package ID is stored. See IffOffset().
                    UInt32 mIdOffset;
                    /// The size in bytes of the ID string, including the terminating null character.
                    UInt32 mIdByteSize;

                    UInt32 mReserved1;
                    UInt32 mReserved2;
                    UInt32 mReserved3;
                    UInt32 mReserved4;
                };

                /**
                 * @struct PackageChunk
                 * @brief An IFF chunk of a native package storing a sub-package.
                 * The data pointed to by the mDataOffset member holds itself another IFF package
                 * data stream, representing a sub-package.
                 */
                struct PackageChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a PackageChunk.
                        FOURCC = 'SPKG'
                    };

                    /// An offset into the chunk where the sub-package ID is stored. See IffOffset().
                    UInt32 mIdOffset;
                    /// The size in bytes of the ID string, including the terminating null character.
                    UInt32 mIdByteSize;

                    /// An offset into the chunk where the sub-package data is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The size in bytes of the sub-package data.
                    UInt32 mDataByteSize;

                    /// An offset into the chunk where the condition tag key/value pairs are stored. See IffOffset().
                    UInt32 mTagsOffset;
                    /// The number of tags present. Total byte size of tags: mNumberOfTags*sizeof(UInt32).
                    UInt32 mNumberOfTags;
                };

                /**
                 * @struct PackageReferenceChunk
                 * @brief An IFF chunk of a native package storing a reference to a resource package.
                 */
                struct PackageReferenceChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an PackageReferenceChunk.
                        FOURCC = 'SPKR'
                    };

                    /// The zero-based index of the referenced object's chunk
                    UInt32 mReferenceIndex;

                    /// An offset into the chunk where the object ID is stored. See IffOffset().
                    UInt32 mIdOffset;
                    /// The size in bytes of the ID string, including the terminating null character.
                    UInt32 mIdByteSize;

                    /// An offset into the chunk where the condition tag key/value pairs are stored. See IffOffset().
                    UInt32 mTagsOffset;
                    /// The number of tags present. Total byte size of tags: mNumberOfTags*sizeof(UInt32).
                    UInt32 mNumberOfTags;
                };

                /**
                 * @struct ObjectChunk
                 * @brief An IFF chunk of a native package storing a resource object.
                 */
                struct ObjectChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an ObjectChunk.
                        FOURCC = 'RSRC'
                    };

                    /// The object type.
                    UInt32 mType;

                    /// An offset into the chunk where the object ID is stored. See IffOffset().
                    UInt32 mIdOffset;
                    /// The size in bytes of the ID string, including the terminating null character.
                    UInt32 mIdByteSize;

                    /// An offset into the chunk where the resource object data is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The size in bytes of the resource object data.
                    UInt32 mDataByteSize;

                    /// An offset into the chunk where the condition tag key/value pairs are stored. See IffOffset().
                    UInt32 mTagsOffset;
                    /// The number of tags present. Total byte size of tags: mNumberOfTags*sizeof(UInt32).
                    UInt32 mNumberOfTags;
                };

                /**
                 * @struct ObjectReferenceChunk
                 * @brief An IFF chunk of a native package storing a reference to a resource object.
                 */
                struct ObjectReferenceChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an ObjectReferenceChunk.
                        FOURCC = 'RSRR'
                    };

                    /// The zero-based index of the referenced object's chunk
                    UInt32 mReferenceIndex;

                    /// An offset into the chunk where the object ID is stored. See IffOffset().
                    UInt32 mIdOffset;
                    /// The size in bytes of the ID string, including the terminating null character.
                    UInt32 mIdByteSize;

                    /// An offset into the chunk where the condition tag key/value pairs are stored. See IffOffset().
                    UInt32 mTagsOffset;
                    /// The number of tags present. Total byte size of tags: mNumberOfTags*sizeof(UInt32).
                    UInt32 mNumberOfTags;
                };

                /**
                 * @struct TextChunk
                 * @brief An IFF chunk of a native package storing a text resource.
                 */
                struct TextChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a TextChunk.
                        FOURCC = 'TEXT'
                    };

                    /// An offset into the chunk where the text ID is stored. See IffOffset().
                    UInt32 mIdOffset;
                    /// The size in bytes of the ID string, including the terminating null character.
                    UInt32 mIdByteSize;

                    /// An offset into the chunk where the string value is stored. See IffOffset().
                    UInt32 mValueOffset;
                    /// The size in bytes of the string value, including the terminating null character.
                    UInt32 mValueByteSize;

                    /// An offset into the chunk where the condition tag key/value pairs are stored. See IffOffset().
                    UInt32 mTagsOffset;
                    /// The number of tags present. Total byte size of tags: mNumberOfTags*sizeof(UInt32).
                    UInt32 mNumberOfTags;
                };

                /**
                 * @struct TextChunk
                 * @brief An IFF chunk of a native package referencing an optional graph instance to create.
                 */
                struct InstanceChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an InstanceChunk for IGraph resource.
                        FOURCC_GRAPH = 'INST',
                        /// The four character code identifying this chunk as an InstanceChunk for IScript resource.
                        FOURCC_SCRIPT = 'INSC'
                    };

                    /// The number of replications to create when instantiating the graph.
                    UInt32 mNumberOfReplications;

                    /// An offset into the chunk where the ID of the graph to create is stored. See IffOffset().
                    UInt32 mResourceIdOffset;
                    /// The size in bytes of the resource ID string, including the terminating null character.
                    UInt32 mResourceIdByteSize;

                    /// An offset into the chunk where the node ID of the graph's parent is stored. See IffOffset().
                    UInt32 mParentNodeIdOffset;
                    /// The size in bytes of the parent graph node ID string, including the terminating null character.
                    UInt32 mParentNodeIdByteSize;

                    /// An offset into the chunk where the condition tag key/value pairs are stored. See IffOffset().
                    UInt32 mTagsOffset;
                    /// The number of tags present. Total byte size of tags: mNumberOfTags*sizeof(UInt32).
                    UInt32 mNumberOfTags;
                };

                /**
                 * @struct StringChunk
                 * @brief An IFF chunk of a native package storing the attribute string table.
                 */
                struct StringChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a StringChunk.
                        FOURCC = 'STRG'
                    };

                    /// An offset into the chunk where the consecutive attribute strings are stored. See IffOffset().
                    UInt32 mStringOffset;
                    /// The total size in bytes of the string table.
                    UInt32 mStringByteSize;
                };
            };

        public:
            virtual ~IPackage() {}

            /**
             * @brief Get the mutable IPackage interface.
             * @return The IPackage interface.
             */
            virtual IPackage* GetPackageInterface() = 0;
            /**
             * @brief Get the constant IPackage interface.
             * @return The IPackage interface.
             */
            virtual const IPackage* GetPackageInterface() const = 0;

            /**
             * @brief Get the factory object used to create this package.
             * @return The creator factory.
             */
            virtual const IPackageFactory* GetCreator() const = 0;

            /**
             * @brief Initialize this package.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief De-initialize this package.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Create a binary representation from the package.
             * @param data A reference to a Data object receiving the binary.
             * @param checkConfig If true, the current IAppConfiguration object (and its contained
             *      IEngineConfiguration and IPlatformConfiguration objects) are checked for valid
             *      configuration options to include in the actual binary. If false, all present
             *      objects are included, for all configuration specified in the package.
             * @param makeDefault Only considered if checkConfig is true. If makeDefault is also
             *      true, only the first object of a set of conditional resources (i.e. resource
             *      objects with the same ID) matching a valid configuration is packed into the
             *      output binary, and all other ones in this set are left out. If false, all
             *      objects with matching configuration tags are included.
             * @param allowReferences If true, resource objects with identical binary representations
             *      are included only once in the package and referenced multiple times. If false,
             *      all objects are packaged regardless of duplication.
             * @return true if successful.
             */
            virtual Bool CreateBinary(Data& data, Bool checkConfig, Bool makeDefault, Bool allowReferences) const = 0;

            /**
             * @brief Get the package ID.
             * @return The package ID.
             */
            virtual const String& GetId() const = 0;
            /**
             * @brief Get the user-defined package revision.
             * @return The package revision.
             */
            virtual UInt32 GetRevision() const = 0;

            /**
             * @brief Get the package's actual type.
             * @return The package type.
             */
            virtual IEnums::PackageType GetPackageType() const = 0;
            /**
             * @brief Get the type of file this resource package was constructed from.
             * @return The file type.
             */
            virtual IEnums::FileType GetFileType() const = 0;
            /**
             * @brief Get the optional file category containing the file this package was constructed from.
             * @return The file category, or IEnums::FILE_CATEGORY_DEFAULT if the package was constructed directly from memory.
             */
            virtual IEnums::FileCategory GetFileCategory() const = 0;
            /**
             * @brief Get the optional file name this package was constructed from, relative to the file category returned via GetFileCategory().
             * @return The file name, or an empty string if the package was constructed directly from memory.
             */
            virtual const String& GetFileName() const = 0;

            /**
             * @brief Get the number of graph instances defined to be created upon package loading.
             * @return The number of instances to create.
             */
            virtual UInt32 GetNumberOfGraphInstancesToCreate() const = 0;
            /**
             * @brief Get a specific graph instance to create upon package loading.
             * @param index The instance index, from 0 to GetNumberOfGraphInstancesToCreate()-1.
             * @return The instance object, or null if the index is out of range.
             */
            virtual const IInstance* GetGraphInstanceToCreate(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specific graph instance to create upon package loading.
             * @param index The instance index, from 0 to GetNumberOfGraphInstancesToCreate()-1.
             * @return The condition object, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetGraphInstanceConditionToCreate(UInt32 index) const = 0;

            /**
             * @brief Get the number of script instances defined to be created upon package loading.
             * @return The number of instances to create.
             */
            virtual UInt32 GetNumberOfScriptInstancesToCreate() const = 0;
            /**
             * @brief Get a specific script instance to create upon package loading.
             * @param index The instance index, from 0 to GetNumberOfScriptInstancesToCreate()-1.
             * @return The instance object, or null if the index is out of range.
             */
            virtual const IInstance* GetScriptInstanceToCreate(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specific script instance to create upon package loading.
             * @param index The instance index, from 0 to GetNumberOfScriptInstancesToCreate()-1.
             * @return The condition object, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetScriptInstanceConditionToCreate(UInt32 index) const = 0;

            /**
             * @brief Get the total number of generic resource objects contained in the package.
             * @return The total number of generic objects.
             */
            virtual UInt32 GetNumberOfObjects() const = 0;
            /**
             * @brief Get the number of specialized IBinary resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfBinaries() const = 0;
            /**
             * @brief Get the number of specialized IGraph resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfGraphs() const = 0;
            /**
             * @brief Get the number of specialized IImage resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfImages() const = 0;
            /**
             * @brief Get the number of specialized IMesh resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfMeshes() const = 0;
            /**
             * @brief Get the number of specialized IFont resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfFonts() const = 0;
            /**
             * @brief Get the number of specialized IShader resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfShaders() const = 0;
            /**
             * @brief Get the number of specialized IAudio resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfAudios() const = 0;
            /**
             * @brief Get the number of specialized IAnimation resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfAnimations() const = 0;
            /**
             * @brief Get the number of specialized IAtlas resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfAtlases() const = 0;
            /**
             * @brief Get the number of specialized IArchive resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfArchives() const = 0;
            /**
             * @brief Get the number of specialized IVideo resource objects contained in the package.
             * @return The number of objects.
             */
            virtual UInt32 GetNumberOfVideos() const = 0;
            /**
             * @brief Get the number of script resources contained in the package.
             * @return The number of script resources.
             */
            virtual UInt32 GetNumberOfScripts() const = 0;
            /**
             * @brief Get the number of dictionary resources contained in the package.
             * @return The number of dictionary resources.
             */
            virtual UInt32 GetNumberOfDictionaries() const = 0;
            /**
             * @brief Get the number of grid resources contained in the package.
             * @return The number of grid resources.
             */
            virtual UInt32 GetNumberOfGrids() const = 0;
            /**
             * @brief Get the number of text resources contained in the package.
             * @return The number of text resources.
             */
            virtual UInt32 GetNumberOfTexts() const = 0;
            /**
             * @brief Get the number of sub-packages contained in the package.
             * @return The number of sub-packages.
             */
            virtual UInt32 GetNumberOfSubPackages() const = 0;

            /**
             * @brief Get the generic resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfObjects()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IObject* GetObject(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IBinary resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfBinaries()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IBinary* GetBinary(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IGraph resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfGraphs()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IGraph* GetGraph(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IImage resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfImages()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IImage* GetImage(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IMesh resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfMeshes()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IMesh* GetMesh(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IFont resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfFonts()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IFont* GetFont(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IShader resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfShaders()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IShader* GetShader(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IAudio resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfAudios()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IAudio* GetAudio(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IAnimation resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfAnimations()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IAnimation* GetAnimation(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IAtlas resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfAtlases()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IAtlas* GetAtlas(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IArchive resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfArchives()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IArchive* GetArchive(UInt32 index) const = 0;
            /**
             * @brief Get the specialized IVideo resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfVideos()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IVideo* GetVideo(UInt32 index) const = 0;
            /**
             * @brief Get the script resource at a given index.
             * @param index The script index, from 0 to GetNumberOfScripts()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IScript* GetScript(UInt32 index) const = 0;
            /**
             * @brief Get the dictionary resource at a given index.
             * @param index The dictionary index, from 0 to GetNumberOfDictionaries()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IDictionary* GetDictionary(UInt32 index) const = 0;
            /**
             * @brief Get the grid resource at a given index.
             * @param index The grid index, from 0 to GetNumberOfGrids()-1.
             * @return The object, or null if the index is out of range.
             */
            virtual const IGrid* GetGrid(UInt32 index) const = 0;
            /**
             * @brief Get the text resource at a given index.
             * @param index The text index, from 0 to GetNumberOfTexts()-1.
             * @return The text object, or null if the index is out of range.
             */
            virtual const IText* GetText(UInt32 index) const = 0;
            /**
             * @brief Get the sub-package at a given index.
             * @param index The sub-package index, from 0 to GetNumberOfSubPackages()-1.
             * @return The sub-package, or null if the index is out of range.
             */
            virtual const IPackage* GetSubPackage(UInt32 index) const = 0;

            /**
             * @brief Get the condition of a generic resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfObjects()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetObjectCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IBinary resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfBinaries()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetBinaryCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IGraph resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfGraphs()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetGraphCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IImage resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfImages()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetImageCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IMesh resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfMeshes()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetMeshCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IFont resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfFonts()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetFontCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IShader resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfShaders()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetShaderCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IAudio resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfAudios()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetAudioCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IAnimation resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfAnimations()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetAnimationCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IAtlas resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfAtlases()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetAtlasCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IArchive resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfArchives()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetArchiveCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a specialized IVideo resource object at a given index.
             * @param index The object index, from 0 to GetNumberOfVideos()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetVideoCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a script resource at a given index.
             * @param index The script index, from 0 to GetNumberOfScripts()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetScriptCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a dictionary resource at a given index.
             * @param index The dictionary index, from 0 to GetNumberOfDictionaries()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetDictionaryCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a grid resource at a given index.
             * @param index The grid index, from 0 to GetNumberOfGrids()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetGridCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a text resource at a given index.
             * @param index The text index, from 0 to GetNumberOfTexts()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetTextCondition(UInt32 index) const = 0;
            /**
             * @brief Get the condition of a sub-package at a given index.
             * @param index The sub-package index, from 0 to GetNumberOfSubPackages()-1.
             * @return The condition, or null if unconditional or the index is out of range.
             */
            virtual const ICondition* GetSubPackageCondition(UInt32 index) const = 0;

            /**
             * @brief Get the first generic resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IObject* GetObject(const String& id) const = 0;
            /**
             * @brief Get the first specialized IBinary resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IBinary* GetBinary(const String& id) const = 0;
            /**
             * @brief Get the first specialized IGraph resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IGraph* GetGraph(const String& id) const = 0;
            /**
             * @brief Get the first specialized IImage resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IImage* GetImage(const String& id) const = 0;
            /**
             * @brief Get the first specialized IMesh resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IMesh* GetMesh(const String& id) const = 0;
            /**
             * @brief Get the first specialized IFont resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IFont* GetFont(const String& id) const = 0;
            /**
             * @brief Get the first specialized IShader resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IShader* GetShader(const String& id) const = 0;
            /**
             * @brief Get the first specialized IAudio resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IAudio* GetAudio(const String& id) const = 0;
            /**
             * @brief Get the first specialized IAnimation resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IAnimation* GetAnimation(const String& id) const = 0;
            /**
             * @brief Get the first specialized IAtlas resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IAtlas* GetAtlas(const String& id) const = 0;
            /**
             * @brief Get the first specialized IArchive resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IArchive* GetArchive(const String& id) const = 0;
            /**
             * @brief Get the first specialized IVideo resource object matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IVideo* GetVideo(const String& id) const = 0;
            /**
             * @brief Get the first script resource matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IScript* GetScript(const String& id) const = 0;
            /**
             * @brief Get the first dictionary resource matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IDictionary* GetDictionary(const String& id) const = 0;
            /**
             * @brief Get the first grid resource matching the current configuration.
             * @param id The resource object ID.
             * @return The object, or null if not found.
             */
            virtual const IGrid* GetGrid(const String& id) const = 0;
            /**
             * @brief Get the first text resource matching the current configuration.
             * @param id The text ID.
             * @return The text object, or null if not found.
             */
            virtual const IText* GetText(const String& id) const = 0;
            /**
             * @brief Get the first sub-package matching the current configuration.
             * @param id The sub-package ID.
             * @return The sub-package, or null if not found.
             */
            virtual const IPackage* GetSubPackage(const String& id) const = 0;

            /**
             * @brief Set the optional parent package this package belongs to.
             * @param parentPackage The containing package, or null for removing.
             * @return true if successful.
             */
            virtual Bool SetParentPackage(const IPackage* parentPackage) = 0;
            /**
             * @brief Get the optional parent package this package belongs to.
             * @return The containing package, or null if the package is not
             *      contained in another package.
             */
            virtual const IPackage* GetParentPackage() const = 0;

            /**
             * @brief Query the total number of allocated resource bytes in this package.
             * @return The number of allocated bytes.
             */
            virtual UInt32 GetNumberOfAllocatedResourceBytes() const = 0;
        };
    }
}

#endif // __MURL_RESOURCE_I_PACKAGE_H__

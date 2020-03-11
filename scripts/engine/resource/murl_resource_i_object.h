// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_OBJECT_H__
#define __MURL_RESOURCE_I_OBJECT_H__

#include "murl_resource_types.h"
#include "murl_data.h"
#include "murl_object_array.h"
#include "murl_i_factory_object.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAttributes;
    class IFileInterface;
    class Result;
    
    namespace Resource
    {
        class IObjectFactory;
        class IPackage;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IObject
         * @brief The base interface for all resource objects.
         */
        class IObject : public IFactoryObject<IObject>
        {
        public:
            typedef IObject* (*CreateFunction)(const IObjectFactory* objectFactory, IFileInterface* fileInterface, IEnums::ResourceType type, const IAttributes* params, const String& id, const String& fileName, IEnums::FileCategory fileCategory, const ConstData& data, Bool& dataCanBeDisposed, Result& result);
            typedef Bool (*QueryFunction)(const ConstData& data, IEnums::ResourceType queryType, const String& fileName, IEnums::ResourceType* resourceType, IEnums::FileType* fileType, Bool* isDataValid, Bool* isVersionValid);

            /**
             * @brief The class information object.
             */
            class ClassInfo : public IFactoryObject<IObject>::ClassInfo
            {
            public:
                /**
                 * @brief The default constructor.
                 */
                ClassInfo()
                : IFactoryObject<IObject>::ClassInfo()
                , mQueryFunction(0)
                {
                }

                /**
                 * @brief The constructor taking a class name and create function
                 * @param className The class name.
                 * @param createFunction The function to create an object
                 * @param queryFunction The function to query information about an object.
                 * @param baseClassInfo A pointer to the ClassInfo structure of an
                 *      optional base class, if this class is a derived one.
                 * @param propertyInfo The property information of the class.
                 * @param attributeInfo The attribute information of the class.
                 */
                ClassInfo(const String& className, CreateFunction createFunction, QueryFunction queryFunction, const IFactoryObject<IObject>::ClassInfo* baseClassInfo, const PropertyInfo* propertyInfo, const AttributeInfo* attributeInfo)
                : IFactoryObject<IObject>::ClassInfo(className, createFunction, baseClassInfo, propertyInfo, attributeInfo)
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
            virtual ~IObject() {}

            /**
             * @brief Get the mutable IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;
            
            /**
             * @brief Get the object factory used to create this object.
             * @return The object factory.
             */
            virtual const IObjectFactory* GetCreator() const = 0;

            /**
             * @brief Set the optional package this object belongs to.
             * @param parentPackage The containing package, or null for removing.
             * @return true if successful.
             */
            virtual Bool SetParentPackage(const IPackage* parentPackage) = 0;
            /**
             * @brief Get the optional package this object belongs to.
             * @return The containing package, or null if the object is not
             *      contained in a package.
             */
            virtual const IPackage* GetParentPackage() const = 0;

            /**
             * @brief Initialize this object.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief De-initialize this object.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Create a binary representation from the object.
             * @param data A reference to a Data object receiving the binary.
             * @return true if successful.
             */
            virtual Bool CreateBinary(Data& data) const = 0;

            /**
             * @brief Get the object's ID.
             * @return The object ID.
             */
            virtual const String& GetId() const = 0;
            
            /**
             * @brief Get the object's actual resource type.
             * @return The resource type.
             */
            virtual IEnums::ResourceType GetResourceType() const = 0;
            /**
             * @brief Get the type of file this resource object was constructed from.
             * @return The file type.
             */
            virtual IEnums::FileType GetFileType() const = 0;
            /**
             * @brief Get the optional file category containing the file this resource was constructed from.
             * @return The file category, or IEnums::FILE_CATEGORY_DEFAULT if the resource was constructed directly from memory.
             */
            virtual IEnums::FileCategory GetFileCategory() const = 0;
            /**
             * @brief Get the optional file name this resource was constructed from, relative to the file category returned via GetFileCategory().
             * @return The file name, or an empty string if the resource was constructed directly from memory.
             */
            virtual const String& GetFileName() const = 0;

            /**
             * @brief Fill a given IAttributes object with the actual parameters used
             * during creation.
             * @param params An attributes object receiving the parameters.
             * @return true if successful.
             */
            virtual Bool GetParameters(IAttributes* params) const = 0;

            /**
             * @brief Fill a given array with possible error or warning results from validating given parameters.
             * @param results An array of result objects.
             * @return true if successful.
             */
            virtual Bool GetValidationResults(ObjectArray<Result>& results) const = 0;

            /**
             * @brief Fill a given string array with names of files the resource depends on.
             * @param fileNames A string array receiving the dependency file names.
             * @return true if successful.
             */
            virtual Bool GetFileDependencies(Array<String>& fileNames) const = 0;

            /**
             * @brief Take ownership of the data buffer used to create the resource.
             * After taking ownership, the resource object will delete the underlying
             * data when the resource itself is deleted. The caller must ensure that
             * the given data is not deallocated in a different place.
             * @return true if successful.
             */
            virtual Bool TakeDataOwnership() = 0;
        };
    }
}

#endif // __MURL_RESOURCE_I_OBJECT_H__

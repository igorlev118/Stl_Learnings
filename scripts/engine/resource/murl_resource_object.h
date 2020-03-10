// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_OBJECT_H__
#define __MURL_RESOURCE_OBJECT_H__

#include "murl_resource_property.h"
#include "murl_resource_i_object.h"

#define MURL_RESOURCE_OBJECT_FACTORY_OBJECT_CLASS_INTERNAL(name) \
virtual const ClassInfo* GetObjectClassInfo() const \
{ \
return &GetClassInfo(); \
} \
protected: \
static const name* GetNullInstance() \
{ \
static const name* sNullInstance = 0; \
return sNullInstance; \
} \
private:


#define MURL_RESOURCE_OBJECT_FACTORY_OBJECT_ABSTRACT_BASE_CLASS(name) \
public: \
static const ClassInfo& GetClassInfo() \
{ \
static const ClassInfo sClassInfo(#name, 0, 0, 0, GetPropertyInfo(), GetAttributeInfo()); \
return sClassInfo; \
} \
virtual void ResetObjectProperties() \
{ \
ResetProperties(this); \
} \
MURL_RESOURCE_OBJECT_FACTORY_OBJECT_CLASS_INTERNAL(name)


#define MURL_RESOURCE_OBJECT_FACTORY_OBJECT_BASE_CLASS(name) \
public: \
static const ClassInfo& GetClassInfo() \
{ \
static const ClassInfo sClassInfo(#name, name::Create, name::Query, 0, GetPropertyInfo(), GetAttributeInfo()); \
return sClassInfo; \
} \
virtual void ResetObjectProperties() \
{ \
ResetProperties(this); \
} \
MURL_RESOURCE_OBJECT_FACTORY_OBJECT_CLASS_INTERNAL(name)


#define MURL_RESOURCE_OBJECT_FACTORY_OBJECT_ABSTRACT_DERIVED_CLASS(name, baseName) \
public: \
static const ClassInfo& GetClassInfo() \
{ \
static const ClassInfo sClassInfo(#name, 0, 0, &baseName::GetClassInfo(), GetPropertyInfo() == baseName::GetPropertyInfo() ? 0 : GetPropertyInfo(), GetAttributeInfo() == baseName::GetAttributeInfo() ? 0 : GetAttributeInfo()); \
return sClassInfo; \
} \
virtual void ResetObjectProperties() \
{ \
baseName::ResetObjectProperties(); \
ResetProperties(this); \
} \
MURL_RESOURCE_OBJECT_FACTORY_OBJECT_CLASS_INTERNAL(name)


#define MURL_RESOURCE_OBJECT_FACTORY_OBJECT_DERIVED_CLASS(name, baseName) \
public: \
static const ClassInfo& GetClassInfo() \
{ \
static const ClassInfo sClassInfo(#name, name::Create, name::Query, &baseName::GetClassInfo(), GetPropertyInfo() == baseName::GetPropertyInfo() ? 0 : GetPropertyInfo(), GetAttributeInfo() == baseName::GetAttributeInfo() ? 0 : GetAttributeInfo()); \
return sClassInfo; \
} \
virtual void ResetObjectProperties() \
{ \
baseName::ResetObjectProperties(); \
ResetProperties(this); \
} \
MURL_RESOURCE_OBJECT_FACTORY_OBJECT_CLASS_INTERNAL(name)


namespace Murl
{
    namespace Resource
    {
        /**
         * @ingroup MurlResourceObjectClasses
         * @brief The abstract base class for a resource object.
         * When specified within an XML resource package, there is a common set of resource
         * attributes that can be used to control e.g. inclusion or exclusion of a specific
         * resource for a given run-time configuration. All different resource objects must
         * use the &lt;Resource&gt; tag for specifying a resource file.
         *
         * Example of a package.xml file inside the murl_startup.murlres folder defining an
         * XML package:
         * @code{.xml}
         * <?xml version="1.0" ?>
         * <Package id="murl_startup">
         *   <!-- Bitmap resources -->
         *   <Resource id="loading" fileName="startup_loading_german.png" includeForLanguages="GERMAN"/>
         *   <Resource id="loading" fileName="startup_loading_default.png"/>
         *   <Resource id="circle" fileName="startup_circle.png"/>
         *
         *   <!-- Animation resources -->
         *   <Resource id="circle_anim" fileName="startup_circle_anim.xml"/>
         *
         *   <!-- Sub-Graphs -->
         *   <Resource id="graph" fileName="startup_graph.xml"/>
         *
         *   <!-- Graph instances -->
         *   <Instance graphResourceId="graph"/>
         * </Package>
         * @endcode
         *
         * @xmlelements
         *
         * @restags
         * @restag{Resource}
         *
         * @resatts
         * @resatt{id,String,, The ID of the resource object.
         *      If a graph node accepts a resource object as an input attribute
         *      (e.g. "imageResourceId")\, this resource must be specified in the
         *      form "<Package ID>:<Resource ID>".}
         * @resatt{type,IEnums::ResourceType,DEFAULT, The optional specific resource type.}
         * @resatt{fileName,String,, The actual file name of the resource on disk.
         *      Sub-directories can be included in the file name; the specified
         *      path is relative to the directory where the "package.xml" file is
         *      placed.}
         * @resatt{excludeForX,String,, A comma-separated list of enumeration values\, to specify
         *      for which configuration(s) this resource should be excluded.
         *      See the "includeForX" attribute below.}
         * @resatt{includeForX,String,, A comma-separated list of enumeration values\, to specify
         *      for which configuration(s) this resource should be included.
         *      Resources in a package that have one or more condition attributes
         *      are evaluated in a top-down manner until the first match is found
         *      for the specified inclusions and/or exclusions.
         *      Possible values for X (e.g. "includeForLanguages") and their data
         *      types:
         *      - "Languages":          Murl::IEnums::Language
         *      - "TargetClasses":      Murl::IEnums::TargetClass
         *      - "TargetDevices":      Murl::IEnums::TargetDevice
         *      - "TargetHosts":        Murl::IEnums::TargetHost
         *      - "OperatingSystems":   Murl::IEnums::OperatingSystem
         *      - "Gpus":               Murl::IEnums::Gpu
         *      - "VideoApis":          Murl::IEnums::VideoApi
         *      - "AudioApis":          Murl::IEnums::AudioApi
         *      - "PrescaleFactors":    UInt32
         *      - "Features":           Murl::IEnums::Feature
         *      - "UserConfigurations": String}
         */
        class Object : public IObject
        {
            MURL_RESOURCE_OBJECT_FACTORY_OBJECT_ABSTRACT_BASE_CLASS(Murl::Resource::Object)
            
        public:
            virtual IObject* GetObjectInterface();
            virtual const IObject* GetObjectInterface() const;

            virtual const IObjectFactory* GetCreator() const;

            virtual Bool SetParentPackage(const IPackage* parentPackage);
            virtual const IPackage* GetParentPackage() const;

            virtual Bool Init();
            virtual Bool DeInit();

            virtual const String& GetId() const;

            virtual IEnums::FileType GetFileType() const;
            virtual IEnums::FileCategory GetFileCategory() const;
            virtual const String& GetFileName() const;

            virtual Bool GetParameters(IAttributes* params) const;

            virtual Bool GetValidationResults(ObjectArray<Result>& results) const;

            virtual Bool SetFileDependencies(const Array<String>& fileNames);
            virtual Bool GetFileDependencies(Array<String>& fileNames) const;

            virtual Bool TakeDataOwnership();

        protected:
            Object(const IObjectFactory* objectFactory, const String& id, const ConstData& data,
                   IEnums::FileType fileType, IEnums::FileCategory fileCategory, const String& fileName);
            virtual ~Object();

            virtual Bool ProcessParameters(const IAttributes* params, Result& result);
            virtual Bool DeserializeParameters(const IAttributes* params, Bool& error);
            virtual Bool ValidateParameters();

            static Bool AreResourceTypesCompatible(IEnums::ResourceType type1, IEnums::ResourceType type2);

            String mId;
            IEnums::FileType mFileType;
            IEnums::FileCategory mFileCategory;
            String mFileName;

            ConstData mData;
            Bool mHasDataOwnership;

            const IPackage* mParentPackage;

            Array<String> mDependencyFileNames;

        private:
            const IObjectFactory* mObjectFactory;
        };
    }
}

#endif  // __MURL_RESOURCE_OBJECT_H__

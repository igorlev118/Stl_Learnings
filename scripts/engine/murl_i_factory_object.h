// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_FACTORY_OBJECT_H__
#define __MURL_I_FACTORY_OBJECT_H__

#include "murl_i_attributes.h"
#include "murl_i_enums.h"
#include "murl_attribute_info.h"
#include "murl_enum.h"
#include "murl_macros.h"

namespace Murl
{
    /**
     * @ingroup MurlFactoryInterfaces
     * @brief The factory object interface.
     * Classes derived from IFactoryObject can be registered to
     * the corresponding factory registry or module registry.
     * @tparam ClassType The derived class type.
     */
    template<class ClassType>
    class IFactoryObject
    {
    public:
        /**
         * @brief The class information object.
         */
        class ClassInfo
        {
        public:
            /**
             * @brief The default constructor.
             */
            ClassInfo()
            : mCreateFunction(0)
            , mBaseClassInfo(0)
            , mPropertyInfo(0)
            , mAttributeInfo(0)
            {
            }

            /**
             * @brief The constructor taking a class name and create function.
             * @param className The class name.
             * @param createFunction The function to create the derived class.
             * @param baseClassInfo A pointer to the ClassInfo structure of an
             *      optional base class, if this class is a derived one.
             * @param propertyInfo The property info struct of the class.
             * @param attributeInfo The attribute info struct of the class.
             */
            ClassInfo(const String& className, typename ClassType::CreateFunction createFunction, const ClassInfo* baseClassInfo, const PropertyInfo* propertyInfo, const AttributeInfo* attributeInfo)
            : mClassName(className)
            , mCreateFunction(createFunction)
            , mBaseClassInfo(baseClassInfo)
            , mPropertyInfo(propertyInfo)
            , mAttributeInfo(attributeInfo)
            {
            }

            /**
             * @brief Get the class name.
             * @return The class name.
             */
            const String& GetClassName() const
            {
                return mClassName;
            }

            /**
             * @brief Get the create function.
             * @return The create function.
             */
            typename ClassType::CreateFunction GetCreateFunction() const
            {
                return mCreateFunction;
            }

            /**
             * @brief Get the ClassInfo struct of the base class.
             * @return The ClassInfo struct, or null if there is no base class.
             */
            const ClassInfo* GetBaseClassInfo() const
            {
                return mBaseClassInfo;
            }
            /**
             * @brief Get the class' property info struct.
             * @return The property info struct.
             */
            const PropertyInfo* GetPropertyInfo() const
            {
                return mPropertyInfo;
            }
            /**
             * @brief Get the class' attribute info struct.
             * @return The attribute info struct.
             */
            const AttributeInfo* GetAttributeInfo() const
            {
                return mAttributeInfo;
            }

        protected:
            /** @brief The class name. */
            String mClassName;
            /** @brief The function to create the derived class. */
            typename ClassType::CreateFunction mCreateFunction;
            /** @brief The class info struct of the base class if present. */
            const ClassInfo* mBaseClassInfo;
            /** @brief The property info structure. */
            const PropertyInfo* mPropertyInfo;
            /** @brief The attribute info structure. */
            const AttributeInfo* mAttributeInfo;
        };

        /** @brief The destructor. */
        virtual ~IFactoryObject()
        {
        }

        /** 
         * @brief Get the object instance's class info, if present. 
         * @return The class info.
         */
        virtual const ClassInfo* GetObjectClassInfo() const = 0;
        /**
         * @brief Reset the object instance's properties to their default values.
         */
        virtual void ResetObjectProperties() = 0;

        /**
         * @brief Get the class' property info struct.
         * @return The property info struct.
         */
        static const PropertyInfo* GetPropertyInfo() { return 0; }
        /**
         * @brief Get the class' attribute info struct.
         * @return The attribute info struct.
         */
        static const AttributeInfo* GetAttributeInfo() { return 0; }
        /**
         * @brief Reset an object instance's properties to their default values.
         * @param object The object to reset.
         */
        static void ResetProperties(IFactoryObject<ClassType>* object) {}

        /** @brief Definition of an array of ClassInfo objects. */
        typedef Array<const ClassInfo*> ClassInfoArray;
    };
}

#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ID_(id, name, var, comp, acc, elem) id
#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ID(item) MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ID_ item

#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_NAME_(id, name, var, comp, acc, elem) name
#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_NAME(item) MURL_GET_FACTORY_OBJECT_ATTRIBUTE_NAME_ item

#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_VAR_(id, name, var, comp, acc, elem) var
#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_VAR(item) MURL_GET_FACTORY_OBJECT_ATTRIBUTE_VAR_ item

#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_COMP_(id, name, var, comp, acc, elem) comp
#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_COMP(item) MURL_GET_FACTORY_OBJECT_ATTRIBUTE_COMP_ item

#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ACC_(id, name, var, comp, acc, elem) acc
#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ACC(item) MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ACC_ item

#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ELEM_(id, name, var, comp, acc, elem) elem
#define MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ELEM(item) MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ELEM_ item

#define MURL_DECLARE_FACTORY_OBJECT_ATTRIBUTE(item) \
    MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ID(item),

#define MURL_DEFINE_FACTORY_OBJECT_ATTRIBUTE(item) \
    { \
        MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ID(item), \
        MURL_GET_FACTORY_OBJECT_ATTRIBUTE_NAME(item), \
        GetNullInstance()->MURL_GET_FACTORY_OBJECT_ATTRIBUTE_VAR(item).GetId(), \
        GetNullInstance()->MURL_GET_FACTORY_OBJECT_ATTRIBUTE_VAR(item).MURL_GET_FACTORY_OBJECT_ATTRIBUTE_COMP(item), \
        GetNullInstance()->MURL_GET_FACTORY_OBJECT_ATTRIBUTE_VAR(item).MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ACC(item), \
        Murl::SInt32(GetNullInstance()->MURL_GET_FACTORY_OBJECT_ATTRIBUTE_VAR(item).MURL_GET_FACTORY_OBJECT_ATTRIBUTE_ELEM(item)) \
    },

#define MURL_FACTORY_OBJECT_CLASS_INTERNAL(name) \
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

#define MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_ID_(propId, varName, ...) propId
#define MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_ID(item) MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_ID_ item

#define MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_VARNAME_(propId, varName, ...) varName
#define MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_VARNAME(item) MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_VARNAME_ item

#define MURL_GET_FACTORY_OBJECT_PROPERTY_ID_(propId, varName, defaultValue, propType, ...) propId
#define MURL_GET_FACTORY_OBJECT_PROPERTY_ID(item) MURL_GET_FACTORY_OBJECT_PROPERTY_ID_ item

#define MURL_GET_FACTORY_OBJECT_PROPERTY_VARNAME_(propId, varName, defaultValue, propType, ...) varName
#define MURL_GET_FACTORY_OBJECT_PROPERTY_VARNAME(item) MURL_GET_FACTORY_OBJECT_PROPERTY_VARNAME_ item

#define MURL_GET_FACTORY_OBJECT_PROPERTY_DEFVAL_(propId, varName, defaultValue, propType, ...) defaultValue
#define MURL_GET_FACTORY_OBJECT_PROPERTY_DEFVAL(item) MURL_GET_FACTORY_OBJECT_PROPERTY_DEFVAL_ item

#define MURL_GET_FACTORY_OBJECT_PROPERTY_TYPE_(propId, varName, defaultValue, propType, ...) propType
#define MURL_GET_FACTORY_OBJECT_PROPERTY_TYPE(item) MURL_GET_FACTORY_OBJECT_PROPERTY_TYPE_ item

#define MURL_GET_FACTORY_OBJECT_PROPERTY_ARGS_(propId, varName, defaultValue, propType, ...) __VA_ARGS__
#define MURL_GET_FACTORY_OBJECT_PROPERTY_ARGS(item) MURL_GET_FACTORY_OBJECT_PROPERTY_ARGS_ item

#ifdef MURL_COMPILER_VS

#define MURL_PROP_BASE(propType, ...) \
    propType##Base MURL_LT_IF_NOT_EMPTY(MURL_EXPAND2(FUT, __VA_ARGS__)) __VA_ARGS__ MURL_RT_IF_NOT_EMPTY(MURL_EXPAND2(FUT, __VA_ARGS__))

#define MURL_FACTORY_OBJECT_PROPERTY_(propId, varName, defaultValue, propType, ...) \
    protected: \
        static const MURL_PROP_BASE(propType, __VA_ARGS__)::Value& MURL_CONCATENATE(varName,GetDefaultValue()) \
        { \
            static const MURL_PROP_BASE(propType, __VA_ARGS__)::Value sDefaultValue = {propId, MURL_STRIP_PARENTHESES(defaultValue)}; \
            return sDefaultValue; \
        } \
        propType<__VA_ARGS__ MURL_COMMA_IF_NOT_EMPTY(MURL_EXPAND2(FUT, __VA_ARGS__)) MURL_CONCATENATE(varName,GetDefaultValue) > varName;

#else

#define MURL_PROP_BASE(propType, ...) \
    propType##Base MURL_LT_IF_NOT_EMPTY(__VA_ARGS__) __VA_ARGS__ MURL_RT_IF_NOT_EMPTY(__VA_ARGS__)

#define MURL_FACTORY_OBJECT_PROPERTY_(propId, varName, defaultValue, propType, ...) \
    protected: \
        static const MURL_PROP_BASE(propType, __VA_ARGS__)::Value& varName##GetDefaultValue() \
        { \
            static const MURL_PROP_BASE(propType, __VA_ARGS__)::Value sDefaultValue = {propId, MURL_STRIP_PARENTHESES(defaultValue)}; \
            return sDefaultValue; \
        } \
        propType<__VA_ARGS__ MURL_COMMA_IF_NOT_EMPTY(__VA_ARGS__) varName##GetDefaultValue> varName;

#endif

#define MURL_FACTORY_OBJECT_PROPERTY(propId, varName, defaultValue, propType, ...) \
    MURL_FACTORY_OBJECT_PROPERTY_(propId, varName, defaultValue, propType, __VA_ARGS__)

#define MURL_DECLARE_FACTORY_OBJECT_PROPERTY(item) \
    MURL_GET_FACTORY_OBJECT_PROPERTY_ID(item),

#define MURL_DEFINE_FACTORY_OBJECT_PROPERTY(item) \
    MURL_FACTORY_OBJECT_PROPERTY( \
        MURL_GET_FACTORY_OBJECT_PROPERTY_ID(item), \
        MURL_GET_FACTORY_OBJECT_PROPERTY_VARNAME(item), \
        MURL_GET_FACTORY_OBJECT_PROPERTY_DEFVAL(item), \
        MURL_GET_FACTORY_OBJECT_PROPERTY_TYPE(item), \
        MURL_GET_FACTORY_OBJECT_PROPERTY_ARGS(item) \
    )

#define MURL_FACTORY_OBJECT_PROPERTY_INFO(varName) \
    GetNullInstance()->varName.GetTypeInfo(),

#define MURL_DEFINE_FACTORY_OBJECT_PROPERTY_INFO(item) \
    MURL_FACTORY_OBJECT_PROPERTY_INFO( \
        MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_VARNAME(item) \
    )

#define MURL_FACTORY_OBJECT_RESET_PROPERTY(varName) \
    object->varName.Reset();

#define MURL_DEFINE_FACTORY_OBJECT_RESET_PROPERTY(item) \
    MURL_FACTORY_OBJECT_RESET_PROPERTY( \
        MURL_GET_FACTORY_OBJECT_PROPERTY_INFO_VARNAME(item) \
    )

/**
 * @addtogroup MurlFactoryInterfaces
 * @{
 */

/**
 * @brief Definition of an abstract base class.
 * @param className The class name.
 */
#define MURL_FACTORY_OBJECT_ABSTRACT_BASE_CLASS(className) \
    public: \
        static const ClassInfo& GetClassInfo() \
        { \
            static const ClassInfo sClassInfo(#className, 0, 0, GetPropertyInfo(), GetAttributeInfo()); \
            return sClassInfo; \
        } \
        virtual void ResetObjectProperties() \
        { \
            ResetProperties(this); \
        } \
        MURL_FACTORY_OBJECT_CLASS_INTERNAL(className)

/**
 * @brief Definition of a concrete base class.
 * @param className The class name.
 */
#define MURL_FACTORY_OBJECT_BASE_CLASS(className) \
    public: \
        static const ClassInfo& GetClassInfo() \
        { \
            static const ClassInfo sClassInfo(#className, className::Create, 0, GetPropertyInfo(), GetAttributeInfo()); \
            return sClassInfo; \
        } \
        virtual void ResetObjectProperties() \
        { \
            ResetProperties(this); \
        } \
        MURL_FACTORY_OBJECT_CLASS_INTERNAL(className)

/**
 * @brief Definition of an abstract derived class.
 * @param className The class name.
 * @param baseClassName The name of the base class.
 */
#define MURL_FACTORY_OBJECT_ABSTRACT_DERIVED_CLASS(className, baseClassName) \
    public: \
        static const ClassInfo& GetClassInfo() \
        { \
            static const ClassInfo sClassInfo(#className, 0, &baseClassName::GetClassInfo(), GetPropertyInfo() == baseClassName::GetPropertyInfo() ? 0 : GetPropertyInfo(), GetAttributeInfo() == baseClassName::GetAttributeInfo() ? 0 : GetAttributeInfo()); \
            return sClassInfo; \
        } \
        virtual void ResetObjectProperties() \
        { \
            baseClassName::ResetObjectProperties(); \
            ResetProperties(this); \
        } \
        MURL_FACTORY_OBJECT_CLASS_INTERNAL(className)

/**
 * @brief Definition of a concrete derived class.
 * @param className The class name.
 * @param baseClassName The name of the base class.
 */
#define MURL_FACTORY_OBJECT_DERIVED_CLASS(className, baseClassName) \
    public: \
        static const ClassInfo& GetClassInfo() \
        { \
            static const ClassInfo sClassInfo(#className, className::Create, &baseClassName::GetClassInfo(), GetPropertyInfo() == baseClassName::GetPropertyInfo() ? 0 : GetPropertyInfo(), GetAttributeInfo() == baseClassName::GetAttributeInfo() ? 0 : GetAttributeInfo()); \
            return sClassInfo; \
        } \
        virtual void ResetObjectProperties() \
        { \
            baseClassName::ResetObjectProperties(); \
            ResetProperties(this); \
        } \
        MURL_FACTORY_OBJECT_CLASS_INTERNAL(className)

/**
 * @brief Definition of object properties.
 * @param className The class name.
 */
#define MURL_FACTORY_OBJECT_PROPERTIES(className, ...) \
    protected: \
        enum ClassProperty \
        { \
            MURL_FOR_EACH(MURL_DECLARE_FACTORY_OBJECT_PROPERTY, __VA_ARGS__) \
            NUM_CLASS_PROPERTIES \
        }; \
        MURL_FOR_EACH(MURL_DEFINE_FACTORY_OBJECT_PROPERTY, __VA_ARGS__) \
    public: \
        static const Murl::PropertyInfo* GetPropertyInfo() \
        { \
            static const Murl::PropertyInfo::Item* sPropertyItems[] = \
            { \
                MURL_FOR_EACH(MURL_DEFINE_FACTORY_OBJECT_PROPERTY_INFO, __VA_ARGS__) \
                0 \
            }; \
            static const Murl::PropertyInfo sPropertyInfo(sPropertyItems, NUMBER_OF_ARRAY_ELEMENTS(sPropertyItems)); \
            return &sPropertyInfo;\
        } \
        static void ResetProperties(className* object) \
        { \
            MURL_FOR_EACH(MURL_DEFINE_FACTORY_OBJECT_RESET_PROPERTY, __VA_ARGS__) \
        } \
    private:

/**
 * @brief Definition of object attributes.
 * @param className The class name.
 */
#define MURL_FACTORY_OBJECT_ATTRIBUTES(className, ...) \
    protected: \
        enum ClassAttribute \
        { \
            MURL_FOR_EACH(MURL_DECLARE_FACTORY_OBJECT_ATTRIBUTE, __VA_ARGS__) \
            NUM_CLASS_ATTRIBUTES \
        }; \
    public: \
        static const Murl::AttributeInfo* GetAttributeInfo() \
        { \
            static const Murl::AttributeInfo::Item sAttributeItems[] = \
            { \
                MURL_FOR_EACH(MURL_DEFINE_FACTORY_OBJECT_ATTRIBUTE, __VA_ARGS__) \
                { NUM_CLASS_ATTRIBUTES } \
            }; \
            static const Murl::AttributeInfo sAttributeInfo(sAttributeItems, NUMBER_OF_ARRAY_ELEMENTS(sAttributeItems)); \
            return &sAttributeInfo;\
        } \
    private:

/** @} */

#endif  // __MURL_I_FACTORY_OBJECT_H__

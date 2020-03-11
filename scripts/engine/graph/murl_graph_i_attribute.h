// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ATTRIBUTE_H__
#define __MURL_GRAPH_I_ATTRIBUTE_H__

#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IAttribute
         * @brief The IAttribute interface.
         * This interface represents a generic vertex attribute object that exposes properties
         * such as predefined item, variable name, data type or byte offset into a vertex array entry.
         */
        class IAttribute
        {
        public:
            /**
             * @brief Get the zero-based index of this attribute.
             * @return The attribute's index inside the parent container.
             */
            virtual SInt32 GetIndex() const = 0;
            /**
             * @brief Get the attribute's user-defined variable name.
             * If the attribute is a predefined one, this method always returns an empty string.
             * @return The attribute's variable name.
             */
            virtual const String& GetName() const = 0;
            /**
             * @brief Get the attribute's predefined item.
             * If the attribute is a user-defined one, this method always returns
             * IEnums::ATTRIBUTE_ITEM_CUSTOM.
             * @return The attribute item.
             */
            virtual IEnums::AttributeItem GetItem() const = 0;
            /**
             * @brief Get the attribute's data type.
             * @return The attribute's data type.
             */
            virtual IEnums::AttributeType GetType() const = 0;
            /**
             * @brief Query if the attribute values are being normalized in the shader.
             * @return true if normalized.
             */
            virtual Bool IsNormalizing() const = 0;
            /**
             * @brief Get the attribute's byte offset.
             * This method returns the attribute's byte offset relative to the beginning of a
             * single vertex entry.
             * @return The attribute's byte offset within a vertex entry.
             */
            virtual UInt32 GetByteOffset() const = 0;
        protected:
            virtual ~IAttribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IFloatAttribute
         * @brief The IFloatAttribute interface.
         * This interface represents a specialized vertex attribute object representing a scalar
         * 32bit floating point value.
         */
        class IFloatAttribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual Float* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const Float* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IFloatAttribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IFloatVector2Attribute
         * @brief The IFloatVector2Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 2-component
         * vector of 32bit floating point values.
         */
        class IFloatVector2Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual Float* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const Float* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IFloatVector2Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IFloatVector3Attribute
         * @brief The IFloatVector3Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 3-component
         * vector of 32bit floating point values.
         */
        class IFloatVector3Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual Float* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const Float* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IFloatVector3Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IFloatVector4Attribute
         * @brief The IFloatVector4Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 4-component
         * vector of 32bit floating point values.
         */
        class IFloatVector4Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual Float* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const Float* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IFloatVector4Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt8Attribute
         * @brief The IUInt8Attribute interface.
         * This interface represents a specialized vertex attribute object representing a scalar
         * 8bit unsigned integer value.
         */
        class IUInt8Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt8Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt8Vector2Attribute
         * @brief The IUInt8Vector2Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 2-component
         * vector of 8bit unsigned integer values.
         */
        class IUInt8Vector2Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt8Vector2Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt8Vector3Attribute
         * @brief The IUInt8Vector3Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 3-component
         * vector of 8bit unsigned integer values.
         */
        class IUInt8Vector3Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt8Vector3Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt8Vector4Attribute
         * @brief The IUInt8Vector4Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 4-component
         * vector of 8bit unsigned integer values.
         */
        class IUInt8Vector4Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt8Vector4Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt8Attribute
         * @brief The ISInt8Attribute interface.
         * This interface represents a specialized vertex attribute object representing a scalar
         * 8bit signed integer value.
         */
        class ISInt8Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt8Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt8Vector2Attribute
         * @brief The ISInt8Vector2Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 2-component
         * vector of 8bit signed integer values.
         */
        class ISInt8Vector2Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt8Vector2Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt8Vector3Attribute
         * @brief The ISInt8Vector3Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 3-component
         * vector of 8bit signed integer values.
         */
        class ISInt8Vector3Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt8Vector3Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt8Vector4Attribute
         * @brief The ISInt8Vector4Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 4-component
         * vector of 8bit signed integer values.
         */
        class ISInt8Vector4Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt8* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt8* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt8Vector4Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt16Attribute
         * @brief The IUInt16Attribute interface.
         * This interface represents a specialized vertex attribute object representing a scalar
         * 16bit unsigned integer value.
         */
        class IUInt16Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt16Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt16Vector2Attribute
         * @brief The IUInt16Vector2Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 2-component
         * vector of 16bit unsigned integer values.
         */
        class IUInt16Vector2Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt16Vector2Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt16Vector3Attribute
         * @brief The IUInt16Vector3Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 3-component
         * vector of 16bit unsigned integer values.
         */
        class IUInt16Vector3Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt16Vector3Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface IUInt16Vector4Attribute
         * @brief The IUInt16Vector4Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 4-component
         * vector of 16bit unsigned integer values.
         */
        class IUInt16Vector4Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual UInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const UInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~IUInt16Vector4Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt16Attribute
         * @brief The ISInt16Attribute interface.
         * This interface represents a specialized vertex attribute object representing a scalar
         * 16bit signed integer value.
         */
        class ISInt16Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt16Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt16Vector2Attribute
         * @brief The ISInt16Vector2Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 2-component
         * vector of 16bit signed integer values.
         */
        class ISInt16Vector2Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt16Vector2Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt16Vector3Attribute
         * @brief The ISInt16Vector3Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 3-component
         * vector of 16bit signed integer values.
         */
        class ISInt16Vector3Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt16Vector3Attribute() {}
        };
        
        /**
         * @ingroup MurlGraphAttributePropertyInterfaces
         * @interface ISInt16Vector4Attribute
         * @brief The ISInt16Vector4Attribute interface.
         * This interface represents a specialized vertex attribute object representing a 4-component
         * vector of 16bit signed integer values.
         */
        class ISInt16Vector4Attribute
        {
        public:
            /**
             * @brief Get the attribute object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the attribute object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual SInt16* GetValue(UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the attribute's value at a given index.
             * @param index The zero-based index of the vertex entry to access.
             * @return A pointer to the attribute value within the requested vertex entry.
             */
            virtual const SInt16* GetValue(UInt32 index) const = 0;
        protected:
            virtual ~ISInt16Vector4Attribute() {}
        };
    }
}

#endif // __MURL_GRAPH_I_ATTRIBUTE_H__

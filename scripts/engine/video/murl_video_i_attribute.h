// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_ATTRIBUTE_H__
#define __MURL_VIDEO_I_ATTRIBUTE_H__

#include "murl_video_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IAttribute
         * @brief The IAttribute video object interface.
         * This is the base interface of a single vertex attribute within a vertex buffer.
         */
        class IAttribute
        {
        public:
            virtual ~IAttribute() {}
            /**
             * @brief Get the attribute data type.
             * @return The data type.
             */
            virtual IEnums::AttributeType GetType() const = 0;
            /**
             * @brief Get the predefine attribute item.
             * @return The item.
             */
            virtual IEnums::AttributeItem GetItem() const = 0;
            /**
             * @brief Get the byte offset into the first vertex entry of the containing vertex buffer.
             * @return The byte offset.
             */
            virtual UInt32 GetByteOffset() const = 0;
            /**
             * @brief Get the attribute's unique integer ID in the renderer.
             * @return The unique ID.
             */
            virtual SInt32 GetId() const = 0;
        };

        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IFloatAttribute
         * @brief The IFloatAttribute video object interface.
         * This interface represents a scalar 32bit floating-point attribute.
         */
        class IFloatAttribute
        {
        public:
            virtual ~IFloatAttribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IFloatVector2Attribute
         * @brief The IFloatVector2Attribute video object interface.
         * This interface represents a 2-component 32bit floating-point vector attribute.
         */
        class IFloatVector2Attribute
        {
        public:
            virtual ~IFloatVector2Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IFloatVector3Attribute
         * @brief The IFloatVector3Attribute video object interface.
         * This interface represents a 3-component 32bit floating-point vector attribute.
         */
        class IFloatVector3Attribute
        {
        public:
            virtual ~IFloatVector3Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IFloatVector4Attribute
         * @brief The IFloatVector4Attribute video object interface.
         * This interface represents a 4-component 32bit floating-point vector attribute.
         */
        class IFloatVector4Attribute
        {
        public:
            virtual ~IFloatVector4Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt8Attribute
         * @brief The IUInt8Attribute video object interface.
         * This interface represents a scalar 8bit unsigned integer attribute.
         */
        class IUInt8Attribute
        {
        public:
            virtual ~IUInt8Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt8Vector2Attribute
         * @brief The IUInt8Vector2Attribute video object interface.
         * This interface represents a 2-component 8bit unsigned integer vector attribute.
         */
        class IUInt8Vector2Attribute
        {
        public:
            virtual ~IUInt8Vector2Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt8Vector3Attribute
         * @brief The IUInt8Vector3Attribute video object interface.
         * This interface represents a 3-component 8bit unsigned integer vector attribute.
         */
        class IUInt8Vector3Attribute
        {
        public:
            virtual ~IUInt8Vector3Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt8Vector4Attribute
         * @brief The IUInt8Vector4Attribute video object interface.
         * This interface represents a 4-component 8bit unsigned integer vector attribute.
         */
        class IUInt8Vector4Attribute
        {
        public:
            virtual ~IUInt8Vector4Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt8Attribute
         * @brief The ISInt8Attribute video object interface.
         * This interface represents a scalar 8bit signed integer attribute.
         */
        class ISInt8Attribute
        {
        public:
            virtual ~ISInt8Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt8Vector2Attribute
         * @brief The ISInt8Vector2Attribute video object interface.
         * This interface represents a 2-component 8bit signed integer vector attribute.
         */
        class ISInt8Vector2Attribute
        {
        public:
            virtual ~ISInt8Vector2Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt8Vector3Attribute
         * @brief The ISInt8Vector3Attribute video object interface.
         * This interface represents a 3-component 8bit signed integer vector attribute.
         */
        class ISInt8Vector3Attribute
        {
        public:
            virtual ~ISInt8Vector3Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt8Vector4Attribute
         * @brief The ISInt8Vector4Attribute video object interface.
         * This interface represents a 4-component 8bit signed integer vector attribute.
         */
        class ISInt8Vector4Attribute
        {
        public:
            virtual ~ISInt8Vector4Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt8* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt8* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt16Attribute
         * @brief The IUInt16Attribute video object interface.
         * This interface represents a scalar 16bit unsigned integer attribute.
         */
        class IUInt16Attribute
        {
        public:
            virtual ~IUInt16Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt16* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt16Vector2Attribute
         * @brief The IUInt16Vector2Attribute video object interface.
         * This interface represents a 2-component 16bit unsigned integer vector attribute.
         */
        class IUInt16Vector2Attribute
        {
        public:
            virtual ~IUInt16Vector2Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt16* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt16Vector3Attribute
         * @brief The IUInt16Vector3Attribute video object interface.
         * This interface represents a 3-component 16bit unsigned integer vector attribute.
         */
        class IUInt16Vector3Attribute
        {
        public:
            virtual ~IUInt16Vector3Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt16* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface IUInt16Vector4Attribute
         * @brief The IUInt16Vector4Attribute video object interface.
         * This interface represents a 4-component 16bit unsigned integer vector attribute.
         */
        class IUInt16Vector4Attribute
        {
        public:
            virtual ~IUInt16Vector4Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual UInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const UInt16* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt16Attribute
         * @brief The ISInt16Attribute video object interface.
         * This interface represents a scalar 16bit signed integer attribute.
         */
        class ISInt16Attribute
        {
        public:
            virtual ~ISInt16Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt16* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt16Vector2Attribute
         * @brief The ISInt16Vector2Attribute video object interface.
         * This interface represents a 2-component 16bit signed integer vector attribute.
         */
        class ISInt16Vector2Attribute
        {
        public:
            virtual ~ISInt16Vector2Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt16* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt16Vector3Attribute
         * @brief The ISInt16Vector3Attribute video object interface.
         * This interface represents a 3-component 16bit signed integer vector attribute.
         */
        class ISInt16Vector3Attribute
        {
        public:
            virtual ~ISInt16Vector3Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt16* GetData(const void* base, UInt32 index) const = 0;
        };
        
        /**
         * @ingroup MurlVideoAttributeObjectInterfaces
         * @interface ISInt16Vector4Attribute
         * @brief The ISInt16Vector4Attribute video object interface.
         * This interface represents a 4-component 16bit signed integer vector attribute.
         */
        class ISInt16Vector4Attribute
        {
        public:
            virtual ~ISInt16Vector4Attribute() {}
            /**
             * @brief Get the mutable IAttribute interface.
             * @return The mutable IAttribute interface.
             */
            virtual IAttribute* GetAttributeInterface() = 0;
            /**
             * @brief Get the constant IAttribute interface.
             * @return The constant IAttribute interface.
             */
            virtual const IAttribute* GetAttributeInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual SInt16* GetData(void* base, UInt32 index) = 0;
            /**
             * @brief Get a constant pointer to the raw attribute data within a vertex buffer.
             * @param base The base pointer to the vertex buffer data.
             * @param index The vertex index.
             * @return A pointer to the raw data.
             */
            virtual const SInt16* GetData(const void* base, UInt32 index) const = 0;
        };
    }
}

#endif // __MURL_VIDEO_I_ATTRIBUTE_H__

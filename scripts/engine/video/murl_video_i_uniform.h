// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_UNIFORM_H__
#define __MURL_VIDEO_I_UNIFORM_H__

#include "murl_video_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IUniform
         * @brief The IUniform video object interface.
         * This is the base interface of a single uniform variable used in a GPU
         * program, stored in a constant buffer.
         */
        class IUniform
        {
        public:
            virtual ~IUniform() {}
            /**
             * @brief Get the uniform data type.
             * @return The data type.
             */
            virtual IEnums::UniformType GetType() const = 0;
            /**
             * @brief Get the predefine uniform item.
             * @return The item.
             */
            virtual IEnums::UniformItem GetItem() const = 0;
            /**
             * @brief Get the byte offset into the containing constant buffer.
             * @return The byte offset.
             */
            virtual UInt32 GetByteOffset() const = 0;
            /**
             * @brief Get the uniform's unique integer ID in the renderer.
             * @return The unique ID.
             */
            virtual SInt32 GetId() const = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IFloatUniform
         * @brief The IFloatUniform video object interface.
         * This interface represents a scalar 32bit floating-point uniform variable.
         */
        class IFloatUniform
        {
        public:
            virtual ~IFloatUniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value The scalar variable value.
             */
            virtual void SetValue(Float value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IFloatVector2Uniform
         * @brief The IFloatVector2Uniform video object interface.
         * This interface represents a 2-component 32bit floating-point vector uniform variable.
         */
        class IFloatVector2Uniform
        {
        public:
            virtual ~IFloatVector2Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 2 component values.
             */
            virtual void SetValue(const Float* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IFloatVector3Uniform
         * @brief The IFloatVector3Uniform video object interface.
         * This interface represents a 3-component 32bit floating-point vector uniform variable.
         */
        class IFloatVector3Uniform
        {
        public:
            virtual ~IFloatVector3Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 3 component values.
             */
            virtual void SetValue(const Float* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IFloatVector4Uniform
         * @brief The IFloatVector4Uniform video object interface.
         * This interface represents a 4-component 32bit floating-point vector uniform variable.
         */
        class IFloatVector4Uniform
        {
        public:
            virtual ~IFloatVector4Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 4 component values.
             */
            virtual void SetValue(const Float* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IFloatMatrix2Uniform
         * @brief The IFloatMatrix2Uniform video object interface.
         * This interface represents a 32bit floating-point 2x2 matrix uniform variable.
         */
        class IFloatMatrix2Uniform
        {
        public:
            virtual ~IFloatMatrix2Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 4 component values (2x2).
             */
            virtual void SetValue(const Float* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IFloatMatrix3Uniform
         * @brief The IFloatMatrix3Uniform video object interface.
         * This interface represents a 32bit floating-point 3x3 matrix uniform variable.
         */
        class IFloatMatrix3Uniform
        {
        public:
            virtual ~IFloatMatrix3Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 9 component values (3x3).
             */
            virtual void SetValue(const Float* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface IFloatMatrix4Uniform
         * @brief The IFloatMatrix4Uniform video object interface.
         * This interface represents a 32bit floating-point 4x4 matrix uniform variable.
         */
        class IFloatMatrix4Uniform
        {
        public:
            virtual ~IFloatMatrix4Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual Float* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const Float* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 16 component values (4x4).
             */
            virtual void SetValue(const Float* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface ISInt32Uniform
         * @brief The ISInt32Uniform video object interface.
         * This interface represents a scalar 32bit signed integer uniform variable.
         */
        class ISInt32Uniform
        {
        public:
            virtual ~ISInt32Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value The scalar variable value.
             */
            virtual void SetValue(SInt32 value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface ISInt32Vector2Uniform
         * @brief The ISInt32Vector2Uniform video object interface.
         * This interface represents a 2-component 32bit signed integer vector uniform variable.
         */
        class ISInt32Vector2Uniform
        {
        public:
            virtual ~ISInt32Vector2Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 2 component values.
             */
            virtual void SetValue(const SInt32* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface ISInt32Vector3Uniform
         * @brief The ISInt32Vector3Uniform video object interface.
         * This interface represents a 3-component 32bit signed integer vector uniform variable.
         */
        class ISInt32Vector3Uniform
        {
        public:
            virtual ~ISInt32Vector3Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 3 component values.
             */
            virtual void SetValue(const SInt32* value) = 0;
        };
        
        /**
         * @ingroup MurlVideoUniformObjectInterfaces
         * @interface ISInt32Vector4Uniform
         * @brief The ISInt32Vector4Uniform video object interface.
         * This interface represents a 4-component 32bit signed integer vector uniform variable.
         */
        class ISInt32Vector4Uniform
        {
        public:
            virtual ~ISInt32Vector4Uniform() {}
            /**
             * @brief Get the mutable IUniform interface.
             * @return The mutable IUniform interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the constant IUniform interface.
             * @return The constant IUniform interface.
             */
            /**
             * @brief Get a mutable pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData(void* base) = 0;
            /**
             * @brief Get a constant pointer to the raw data within a given constant buffer.
             * @param base The base pointer to the constant buffer data.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData(const void* base) const = 0;
            /**
             * @brief Get a mutable pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual SInt32* GetData() = 0;
            /**
             * @brief Get a constant pointer to the raw data within the owning constant buffer.
             * @return A pointer to the raw data.
             */
            virtual const SInt32* GetData() const = 0;
            /**
             * @brief Set the variable value in the owning constant buffer.
             * @param value A pointer to an array of 4 component values.
             */
            virtual void SetValue(const SInt32* value) = 0;
        };
    }
}

#endif // __MURL_VIDEO_I_UNIFORM_H__

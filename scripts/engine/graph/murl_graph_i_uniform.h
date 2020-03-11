// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_UNIFORM_H__
#define __MURL_GRAPH_I_UNIFORM_H__

#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IUniform
         * @brief The IUniform interface.
         * This interface represents a generic shader uniform variable object that exposes properties
         * such as predefined item, variable name or data type. It can also be used to set a uniform
         * variable's value by parsing a given string.
         */
        class IUniform
        {
        public:
            /**
             * @brief Get the zero-based index of this uniform variable.
             * @return The uniform's index inside the parent container.
             */
            virtual SInt32 GetIndex() const = 0;
            /**
             * @brief Get the uniform's user-defined variable name.
             * If the uniform is a predefined one, this method always returns an empty string.
             * @return The uniform variable's name.
             */
            virtual const String& GetName() const = 0;
            /**
             * @brief Get the uniform's predefined item.
             * If the uniform is a user-defined one, this method always returns
             * IEnums::UNIFORM_ITEM_CUSTOM.
             * @return The uniform item.
             */
            virtual IEnums::UniformItem GetItem() const = 0;
            /**
             * @brief Get the uniform's data type.
             * @return The uniform's data type.
             */
            virtual IEnums::UniformType GetType() const = 0;
            /**
             * @brief Get the uniform's byte offset.
             * This method returns the uniform's byte offset relative to the beginning of its
             * container.
             * @return The uniform's byte offset within a constant array.
             */
            virtual UInt32 GetByteOffset() const = 0;
        protected:
            virtual ~IUniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface IFloatUniform
         * @brief The IFloatUniform interface.
         * This interface represents a specialized shader uniform object representing a scalar
         * 32bit floating point value.
         */
        class IFloatUniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value The scalar value to set.
             */
            virtual void SetValue(Float value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return The current scalar value.
             */
            virtual Float GetValue() const = 0;
            /**
             * @brief Get a mutable pointer to the uniform object's current value.
             * @return The current scalar value.
             */
            virtual Float* GetValue() = 0;
        protected:
            virtual ~IFloatUniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface IFloatVector2Uniform
         * @brief The IFloatVector2Uniform interface.
         * This interface represents a specialized shader uniform object representing a 2-component
         * 32bit floating point vector value.
         */
        class IFloatVector2Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const Float* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const Float* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual Float* GetValue() = 0;
        protected:
            virtual ~IFloatVector2Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface IFloatVector3Uniform
         * @brief The IFloatVector3Uniform interface.
         * This interface represents a specialized shader uniform object representing a 3-component
         * 32bit floating point vector value.
         */
        class IFloatVector3Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const Float* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const Float* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual Float* GetValue() = 0;
        protected:
            virtual ~IFloatVector3Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface IFloatVector4Uniform
         * @brief The IFloatVector4Uniform interface.
         * This interface represents a specialized shader uniform object representing a 4-component
         * 32bit floating point vector value.
         */
        class IFloatVector4Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const Float* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const Float* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual Float* GetValue() = 0;
        protected:
            virtual ~IFloatVector4Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface IFloatMatrix2Uniform
         * @brief The IFloatMatrix2Uniform interface.
         * This interface represents a specialized shader uniform object representing a 2x2-component
         * 32bit floating point matrix value.
         */
        class IFloatMatrix2Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const Float* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const Float* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual Float* GetValue() = 0;
        protected:
            virtual ~IFloatMatrix2Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface IFloatMatrix3Uniform
         * @brief The IFloatMatrix3Uniform interface.
         * This interface represents a specialized shader uniform object representing a 3x3-component
         * 32bit floating point matrix value.
         */
        class IFloatMatrix3Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const Float* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const Float* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual Float* GetValue() = 0;
        protected:
            virtual ~IFloatMatrix3Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface IFloatMatrix4Uniform
         * @brief The IFloatMatrix4Uniform interface.
         * This interface represents a specialized shader uniform object representing a 4x4-component
         * 32bit floating point matrix value.
         */
        class IFloatMatrix4Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const Float* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const Float* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual Float* GetValue() = 0;
        protected:
            virtual ~IFloatMatrix4Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface ISInt32Uniform
         * @brief The ISInt32Uniform interface.
         * This interface represents a specialized shader uniform object representing a scalar
         * 32bit signed integer value.
         */
        class ISInt32Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value The scalar value to set.
             */
            virtual void SetValue(SInt32 value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return The current scalar value.
             */
            virtual SInt32 GetValue() const = 0;
            /**
             * @brief Get a mutable pointer to the uniform object's current value.
             * @return The current scalar value.
             */
            virtual SInt32* GetValue() = 0;
        protected:
            virtual ~ISInt32Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface ISInt32Vector2Uniform
         * @brief The ISInt32Vector2Uniform interface.
         * This interface represents a specialized shader uniform object representing a 2-component
         * 32bit signed integer vector value.
         */
        class ISInt32Vector2Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const SInt32* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const SInt32* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual SInt32* GetValue() = 0;
        protected:
            virtual ~ISInt32Vector2Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface ISInt32Vector3Uniform
         * @brief The ISInt32Vector3Uniform interface.
         * This interface represents a specialized shader uniform object representing a 3-component
         * 32bit signed integer vector value.
         */
        class ISInt32Vector3Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const SInt32* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const SInt32* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual SInt32* GetValue() = 0;
        protected:
            virtual ~ISInt32Vector3Uniform() {}
        };
        
        /**
         * @ingroup MurlGraphUniformPropertyInterfaces
         * @interface ISInt32Vector4Uniform
         * @brief The ISInt32Vector4Uniform interface.
         * This interface represents a specialized shader uniform object representing a 4-component
         * 32bit signed integer vector value.
         */
        class ISInt32Vector4Uniform
        {
        public:
            /**
             * @brief Get the uniform object's mutable base interface to access common properties.
             * @return The mutable base interface.
             */
            virtual IUniform* GetUniformInterface() = 0;
            /**
             * @brief Get the uniform object's constant base interface to access common properties.
             * @return The constant base interface.
             */
            virtual const IUniform* GetUniformInterface() const = 0;
            /**
             * @brief Set the uniform object's value.
             * @param value A pointer to the raw component values to set.
             */
            virtual void SetValue(const SInt32* value) = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A constant pointer to the current raw component values.
             */
            virtual const SInt32* GetValue() const = 0;
            /**
             * @brief Get the uniform object's current value.
             * @return A mutable pointer to the current raw component values.
             */
            virtual SInt32* GetValue() = 0;
        protected:
            virtual ~ISInt32Vector4Uniform() {}
        };
    }
}

#endif // __MURL_GRAPH_I_UNIFORM_H__

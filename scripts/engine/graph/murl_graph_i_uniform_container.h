// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_UNIFORM_CONTAINER_H__
#define __MURL_GRAPH_I_UNIFORM_CONTAINER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_uniform.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IUniformContainer
         * @brief The IUniformContainer property interface.
         * This interface provides a common way to store and retrieve individual shader uniform variables
         * of different types, usually found in nodes implementing e.g. the Graph::IGenericParameters
         * interface.
         */
        class IUniformContainer
        {
        public:
            /**
             * @brief Add a predefined shader uniform variable.
             * This method adds a predefined shader uniform variable to the container, with a
             * given uniform type. If successful, this method returns the zero-based index of the 
             * newly created uniform in the container; if failed, -1 is returned.
             * @param item The predefined uniform item to add.
             * @param type The uniform's data type.
             * @param byteOffset The byte offset of the uniform location relative to its container
             *      data start.
             * @return The zero-based index of the uniform in the container, or -1 if failed.
             */
            virtual SInt32 AddUniform(IEnums::UniformItem item, IEnums::UniformType type, UInt32& byteOffset) = 0;
            /**
             * @brief Add a user-defined shader uniform variable.
             * This method adds a user-defined shader uniform variable to the container, with a
             * given uniform type. The newly created uniform variable is only in effect when a shader
             * material is currently active that actually uses a uniform variable with the given name 
             * in its vertex and/or fragment shader. If successful, this method returns the zero-based 
             * index of the newly created uniform in the container; if failed, -1 is returned.
             * @param name The name of the uniform variable to add.
             * @param type The uniform's data type.
             * @param byteOffset The byte offset of the uniform location relative to its container
             *      data start.
             * @return The zero-based index of the uniform in the container, or -1 if failed.
             */
            virtual SInt32 AddUniform(const String& name, IEnums::UniformType type, UInt32& byteOffset) = 0;

            /**
             * @brief Query the location of a predefined uniform variable in the container.
             * This method can be used to query the zero-based index of a given predefined uniform
             * in the container. If the container does not hold the given uniform, -1 is returned.
             * @param item The predefined uniform to query.
             * @return The zero-based index of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(IEnums::UniformItem item) const = 0;
            /**
             * @brief Query the location of a user-defined uniform variable in the container.
             * This method can be used to query the zero-based index of a given user-defined uniform
             * in the container. If the container does not hold the given uniform, -1 is returned.
             * @param name The name of the user-defined uniform to query.
             * @return The zero-based index of the uniform, or -1 if not found.
             */
            virtual SInt32 GetUniformIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual uniform variables in the container.
             * @return The total number of uniform added.
             */
            virtual UInt32 GetNumberOfUniforms() const = 0;
            
            /**
             * @brief Query the type of a uniform variable at a given index.
             * @param index The zero-based index of the uniform to query.
             * @return The uniform type.
             */
            virtual IEnums::UniformType GetUniformType(UInt32 index) const = 0;
            /**
             * @brief Query the predefined item of a uniform variable at a given index.
             * If the uniform at the given index represents a predefined one, this method returns
             * the actual item, e.g. IEnums::UNIFORM_ITEM_MATERIAL_COLOR_DIFFUSE.
             * If the attribute is a user-defined one, it returns IEnums::UNIFORM_ITEM_CUSTOM.
             * @param index The zero-based index of the uniform to query.
             * @return The predefined uniform item.
             */
            virtual IEnums::UniformItem GetUniformItem(UInt32 index) const = 0;
            /**
             * @brief Query the variable name of a uniform at a given index.
             * If the uniform at the given index represents a user-defined one, this method returns
             * its actual name string. If it is a predefined one, an empty string is returned.
             * @param index The zero-based index of the uniform to query.
             * @return The user-defined uniform variable name.
             */
            virtual const String& GetUniformName(UInt32 index) const = 0;
            /**
             * @brief Get the byte offset of a uniform at a given index.
             * @param index The zero-based index of the uniform to query.
             * @return The uniform's byte offset relative to the beginning of its container data.
             */
            virtual UInt32 GetUniformByteOffset(UInt32 index) const = 0;

            /**
             * @brief Get the uniform object at a given index.
             * This method returns an actual uniform object by its Graph::IUniform base interface.
             * The base interface can be used to query common uniform properties; if access to actual
             * uniform data is required, use either a dynamic_cast to one of the available specialized
             * interfaces (e.g. Graph::IFloatMatrix4Uniform), or use the respective explicit method,
             * e.g. GetFloatMatrix4Uniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object.
             */
            virtual IUniform* GetUniform(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a scalar 32bit floating point object.
             * This method can be used as a convenience to retrieve a typed uniform object. If the
             * uniform present in the container at the given index does not match the requested
             * type (scalar float in this case), a null pointer is returned.
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual IFloatUniform* GetFloatUniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 2-component 32bit floating point vector object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual IFloatVector2Uniform* GetFloatVector2Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 3-component 32bit floating point vector object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual IFloatVector3Uniform* GetFloatVector3Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 4-component 32bit floating point vector object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual IFloatVector4Uniform* GetFloatVector4Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 2x2-component 32bit floating point matrix object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual IFloatMatrix2Uniform* GetFloatMatrix2Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 3x3-component 32bit floating point matrix object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual IFloatMatrix3Uniform* GetFloatMatrix3Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 4x4-component 32bit floating point matrix object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual IFloatMatrix4Uniform* GetFloatMatrix4Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a scalar 32bit signed integer object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual ISInt32Uniform* GetSInt32Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 2-component 32bit signed integer vector object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual ISInt32Vector2Uniform* GetSInt32Vector2Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 3-component 32bit signed integer vector object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual ISInt32Vector3Uniform* GetSInt32Vector3Uniform(UInt32 index) const = 0;
            /**
             * @brief Get the uniform at a given index as a 4-component 32bit signed integer vector object.
             * See GetFloatUniform().
             * @param index The zero-based index of the uniform to retrieve.
             * @return The uniform object, or a null pointer if the types do not match.
             */
            virtual ISInt32Vector4Uniform* GetSInt32Vector4Uniform(UInt32 index) const = 0;
            
        protected:
            virtual ~IUniformContainer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IUniformContainer nodes.
         */
        typedef IGenericNodeTarget<IUniformContainer> IUniformContainerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_UNIFORM_CONTAINER_H__

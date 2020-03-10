// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETER_H__
#define __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_uniform.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IConstantBufferParameter;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IConstantBufferParameter nodes.
         */
        typedef IGenericNodeTarget<IConstantBufferParameter> IConstantBufferParameterNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IConstantBufferParameter
         * @brief The IConstantBufferParameter graph node interface.
         * A single constant buffer parameter is used in conjunction with a Graph::IShaderProgram and
         * its referenced Graph::IShader nodes, in order to set the value of a specific custom
         * (or predefined) uniform variable in these GPU shaders.
         *
         * Each constant buffer parameter is defined by a name and data type matching the name and type
         * of a uniform variable in the shader(s); in addition, it is possible to reference an
         * optional parent parameter whose value can be modulated by a given arithmetic
         * operation such as addition, replacement or multiplication.
         *
         * Constant buffer parameters must be grouped together in a Graph::IConstantBufferParameterGroup, which
         * in turn must be part of a set of groups in a Graph::IConstantBufferParameters node.
         *
         * See the Graph::IUniform base interface for accessing actual uniform parameters.
         * See Graph::IConstantBufferParameterGroup for grouping individual parameter nodes.
         * See Graph::IConstantBufferParameters for collecting individual groups.
         */
        class IConstantBufferParameter : public IUniform
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;

            /**
             * @brief Get the mutable Graph::IConstantBufferParameter container storing the optional parent.
             * This method returns a mutable pointer to the node's Graph::IConstantBufferParameter
             * container that stores an optional reference to another generic parameter object, to set
             * or query the object's parent.
             * @return The mutable Graph::IConstantBufferParameter parent container, or null if not available.
             */
            virtual IConstantBufferParameterNodeTarget* GetParentConstantBufferParameterNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IConstantBufferParameter container storing the optional parent.
             * This method returns a constant pointer to the node's Graph::IConstantBufferParameter
             * container that stores an optional reference to another generic parameter object, to
             * query the object's parent.
             * @return The constant Graph::IConstantBufferParameter parent container, or null if not available.
             */
            virtual const IConstantBufferParameterNodeTarget* GetParentConstantBufferParameterNodeTarget() const = 0;

            /**
             * @brief Set the actual uniform variable name.
             * Once initialized, the variable name cannot be changed.
             * @param name The uniform name.
             * @return true if successful.
             */
            virtual Bool SetName(const String& name) = 0;

            /**
             * @brief Set the arithmetic operation for modulating the optional parent's value.
             * @param operation The modulation operation.
             * @return true if successful.
             */
            virtual Bool SetOperation(IEnums::AluOperation operation) = 0;

            /**
             * @brief Set the actual parameter value(s) by string.
             * Sets the modified state to true if successful.
             * @param value The value(s) in string representation.
             * @return true if successful.
             */
            virtual Bool SetValue(const String& value) = 0;
            /**
             * @brief Set an actual parameter value by string and index.
             * Sets the modified state to true if successful.
             * @param value The value in string representation.
             * @param index The zero-based index to the value.
             * @return true if successful.
             */
            virtual Bool SetValue(const String& value, UInt32 index) = 0;

            /**
             * @brief Set an actual float parameter value.
             * Sets the modified state to true if successful.
             * @param value The value.
             * @param index The zero-based index to the value.
             * @return true if successful.
             */
            virtual Bool SetFloatValue(Float value, UInt32 index) = 0;
            /**
             * @brief Set an actual integer parameter value.
             * Sets the modified state to true if successful.
             * @param value The value.
             * @param index The zero-based index to the value.
             * @return true if successful.
             */
            virtual Bool SetSInt32Value(SInt32 value, UInt32 index) = 0;

            /**
             * @brief Get an actual float parameter value.
             * @param index The zero-based index to the value.
             * @return The value.
             */
            virtual Float GetFloatValue(UInt32 index) const = 0;
            /**
             * @brief Get an actual integer parameter value.
             * @param index The zero-based index to the value.
             * @return The value.
             */
            virtual SInt32 GetSInt32Value(UInt32 index) const = 0;

            /**
             * @brief Get an actual modulated float parameter value.
             * @param index The zero-based index to the value.
             * @return The modulated value.
             */
            virtual Float GetModulatedFloatValue(UInt32 index) const = 0;
            /**
             * @brief Get an actual modulated integer parameter value.
             * @param index The zero-based index to the value.
             * @return The modulated value.
             */
            virtual SInt32 GetModulatedSInt32Value(UInt32 index) const = 0;

            /**
             * @brief Get a mutable pointer to the actual parameter value.
             * Depending on the actual data type, the given pointer must be cast to the corresponding
             * C++ data type, e.g. Float* for IEnums::UNIFORM_TYPE_FLOAT or IEnums::UNIFORM_TYPE_FLOAT_VECTOR_4
             * etc. Care must be taken to only access the given number of components of that data type.
             * @return The mutable pointer.
             */
            virtual void* GetData() = 0;
            /**
             * @brief Get a constant pointer to the actual parameter value.
             * Depending on the actual data type, the given pointer must be cast to the corresponding
             * C++ data type, e.g. Float* for IEnums::UNIFORM_TYPE_FLOAT or IEnums::UNIFORM_TYPE_FLOAT_VECTOR_4
             * etc. Care must be taken to only access the given number of components of that data type.
             * @return The constant pointer.
             */
            virtual const void* GetData() const = 0;

            /**
             * @brief Get a mutable pointer to the parent's parameter value modulated by the actual value.
             * See GetData().
             * @return The mutable pointer.
             */
            virtual void* GetModulatedData() = 0;
            /**
             * @brief Get a constant pointer to the parent's parameter value modulated by the actual value.
             * See GetData().
             * @return The constant pointer.
             */
            virtual const void* GetModulatedData() const = 0;

            /**
             * @brief Set the modified state of the parameter value.
             * @param isModified The modified state.
             * @return true if successful.
             */
            virtual Bool SetValueModified(Bool isModified) = 0;
            /**
             * @brief Query the modified state of the parameter value.
             * @return The modified state.
             */
            virtual Bool IsValueModified() const = 0;

            /**
             * @brief Apply the parameter's modulated value to a given block of data.
             * @param targetData A pointer to the target memory block.
             * @return true if successful.
             */
            virtual Bool UpdateValue(void* targetData) const = 0;

        protected:
            virtual ~IConstantBufferParameter() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETER_H__

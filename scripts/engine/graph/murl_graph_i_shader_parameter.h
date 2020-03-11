// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SHADER_PARAMETER_H__
#define __MURL_GRAPH_I_SHADER_PARAMETER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_shader.h"
#include "murl_graph_i_program.h"
#include "murl_graph_i_material.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IConstantBufferParameter;
        class IShaderParameter;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IShaderParameter nodes.
         */
        typedef IGenericNodeTarget<IShaderParameter> IShaderParameterNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IShaderParameter
         * @brief The IShaderParameter graph node interface.
         * A shader parameter represents a specialized constant buffer parameter,
         * and can be used to define a single shader parameter from a given shader resource
         * using its default value stored therein.
         *
         * See the Graph::IConstantBufferParameterGroup base interface for additional information.
         */
        class IShaderParameter
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
             * @brief Get the mutable Graph::IConstantBufferParameter interface.
             * This method returns a mutable pointer to the node's Graph::IConstantBufferParameter interface.
             * @return The mutable Graph::IConstantBufferParameter interface, or null if not available
             */
            virtual IConstantBufferParameter* GetConstantBufferParameterInterface() = 0;
            /**
             * @brief Get the constant Graph::IConstantBufferParameter interface.
             * This method returns a constant pointer to the node's Graph::IConstantBufferParameter interface.
             * @return The constant Graph::IConstantBufferParameter interface, or null if not available
             */
            virtual const IConstantBufferParameter* GetConstantBufferParameterInterface() const = 0;

            /**
             * @brief Get the mutable Graph::IMaterial container storing the material to source parameters from.
             * This method returns a mutable pointer to the node's Graph::IMaterial container that can be
             * used to set or query the material node to source parameters from.
             * @return The mutable Graph::IMaterial container, or null if not available.
             */
            virtual IMaterialNodeTarget* GetMaterialNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IMaterial container storing the material to source parameters from.
             * This method returns a constant pointer to the node's Graph::IMaterial container that can be
             * used to query the material node to source parameters from.
             * @return The constant Graph::IMaterial container, or null if not available.
             */
            virtual const IMaterialNodeTarget* GetMaterialNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IProgram container storing the shader program to source parameters from.
             * This method returns a mutable pointer to the node's Graph::IProgram container that can be
             * used to set or query the shader program node to source parameters from.
             * @return The mutable Graph::IProgram container, or null if not available.
             */
            virtual IProgramNodeTarget* GetProgramNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IProgram container storing the shader program to source parameters from.
             * This method returns a constant pointer to the node's Graph::IProgram container that can be
             * used to query the shader program node to source parameters from.
             * @return The constant Graph::IProgram container, or null if not available.
             */
            virtual const IProgramNodeTarget* GetProgramNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IShader container storing the shader to source the parameter from.
             * This method returns a mutable pointer to the node's Graph::IShader container that can be
             * used to set or query the shader node to source the parameter from.
             * @return The mutable Graph::IShader container, or null if not available.
             */
            virtual IShaderNodeTarget* GetShaderNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IShader container storing the shader to source the parameter from.
             * This method returns a constant pointer to the node's Graph::IShader container that can be
             * used to query the shader node to source the parameter from.
             * @return The constant Graph::IShader container, or null if not available.
             */
            virtual const IShaderNodeTarget* GetShaderNodeTarget() const = 0;

            /**
             * @brief Get the mutable Resource::IShader container storing the shader to source the parameter from.
             * This method returns a mutable pointer to the node's Resource::IShader container that can be
             * used to set or query the shader node to source the parameter from.
             * @return The mutable Resource::IShader container, or null if not available.
             */
            virtual IShaderResourceTarget* GetShaderResourceTarget() = 0;
            /**
             * @brief Get the constant Resource::IShader container storing the shader to source the parameter from.
             * This method returns a constant pointer to the node's Resource::IShader container that can be
             * used to query the shader node to source the parameter from.
             * @return The constant Resource::IShader container, or null if not available.
             */
            virtual const IShaderResourceTarget* GetShaderResourceTarget() const = 0;

        protected:
            virtual ~IShaderParameter() {}
        };
    }
}

#endif // __MURL_GRAPH_I_SHADER_PARAMETER_H__

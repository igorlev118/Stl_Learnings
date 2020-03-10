// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SHADER_PARAMETERS_H__
#define __MURL_GRAPH_I_SHADER_PARAMETERS_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_graph_i_shader.h"
#include "murl_graph_i_program.h"
#include "murl_graph_i_material.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IParameters;
        class IConstantBufferParameters;
        class IShaderParameters;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IShaderParameters nodes.
         */
        typedef IGenericNodeTarget<IShaderParameters> IShaderParametersNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IShaderParameters
         * @brief The IShaderParameters graph node interface.
         * A shader parameters node represent a specialized constant buffer parameters node,
         * and can be used to define a set of parameter groups and parameters that are sourced
         * from a given shader node or resource. All group and parameter names are taken from
         * the given shader and pre-initialized with any default values present, in the correct
         * order for the shader to work correctly.
         *
         * See the Graph::IConstantBufferParameters base interface for additional information.
         */
        class IShaderParameters
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
             * @brief Get the mutable Graph::IParameters interface.
             * This method returns a mutable pointer to the node's Graph::IParameters interface, to
             * be able to query or modify common parameter properties.
             * @return The mutable Graph::IParameters interface, or null if not available
             */
            virtual IParameters* GetParametersInterface() = 0;
            /**
             * @brief Get the constant Graph::IParameters interface.
             * This method returns a constant pointer to the node's Graph::IParameters interface, to
             * be able to query common parameter properties.
             * @return The constant Graph::IParameters interface, or null if not available
             */
            virtual const IParameters* GetParametersInterface() const = 0;

            /**
             * @brief Get the mutable Graph::IConstantBufferParameters interface.
             * This method returns a mutable pointer to the node's Graph::IConstantBufferParameters interface.
             * @return The mutable Graph::IConstantBufferParameters interface, or null if not available
             */
            virtual IConstantBufferParameters* GetConstantBufferParametersInterface() = 0;
            /**
             * @brief Get the constant Graph::IConstantBufferParameters interface.
             * This method returns a constant pointer to the node's Graph::IConstantBufferParameters interface.
             * @return The constant Graph::IConstantBufferParameters interface, or null if not available
             */
            virtual const IConstantBufferParameters* GetConstantBufferParametersInterface() const = 0;

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
             * @brief Get the mutable Graph::IShader container storing the shader to source parameters from.
             * This method returns a mutable pointer to the node's Graph::IShader container that can be 
             * used to set or query the shader node to source parameters from.
             * @return The mutable Graph::IShader container, or null if not available.
             */
            virtual IShaderNodeTarget* GetShaderNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IShader container storing the shader to source parameters from.
             * This method returns a constant pointer to the node's Graph::IShader container that can be
             * used to query the shader node to source parameters from.
             * @return The constant Graph::IShader container, or null if not available.
             */
            virtual const IShaderNodeTarget* GetShaderNodeTarget() const = 0;

            /**
             * @brief Get the mutable Resource::IShader container storing the shader to source parameters from.
             * This method returns a mutable pointer to the node's Resource::IShader container that can be
             * used to set or query the shader node to source parameters from.
             * @return The mutable Resource::IShader container, or null if not available.
             */
            virtual IShaderResourceTarget* GetShaderResourceTarget() = 0;
            /**
             * @brief Get the constant Resource::IShader container storing the shader to source parameters from.
             * This method returns a constant pointer to the node's Resource::IShader container that can be
             * used to query the shader node to source parameters from.
             * @return The constant Resource::IShader container, or null if not available.
             */
            virtual const IShaderResourceTarget* GetShaderResourceTarget() const = 0;

        protected:
            virtual ~IShaderParameters() {}
        };
    }
}

#endif // __MURL_GRAPH_I_SHADER_PARAMETERS_H__

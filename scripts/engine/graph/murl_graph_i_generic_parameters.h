// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_GENERIC_PARAMETERS_H__
#define __MURL_GRAPH_I_GENERIC_PARAMETERS_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_constant_buffer_parameter_group.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IParameters;
        class IConstantBufferParameters;
        class IGenericParameters;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IGenericParameters nodes.
         */
        typedef IGenericNodeTarget<IGenericParameters> IGenericParametersNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IGenericParameters
         * @brief The IGenericParameters graph node interface.
         * A generic parameters node represent a specialized constant buffer parameters node,
         * and can be used to manually define a set of individual parameter groups without
         * any connection to a specific shader.
         *
         * See the Graph::IConstantBufferParameters base interface for additional information.
         */
        class IGenericParameters
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
             * @brief Get the mutable Graph::IConstantBufferParameterGroup container storing the individual
             * parameter groups.
             * This method returns a mutable pointer to the node's Graph::IConstantBufferParameterGroup
             * container that can be used to set or query the individual generic parameter group nodes.
             * @return The mutable Graph::IConstantBufferParameterGroup container, or null if not available.
             */
            virtual IConstantBufferParameterGroupNodeTarget* GetConstantBufferParameterGroupNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IConstantBufferParameterGroup container storing the individual
             * parameter groups.
             * This method returns a constant pointer to the node's Graph::IConstantBufferParameterGroup
             * container that can be used to query the individual generic parameter group nodes.
             * @return The constant Graph::IConstantBufferParameterGroup container, or null if not available.
             */
            virtual const IConstantBufferParameterGroupNodeTarget* GetConstantBufferParameterGroupNodeTarget() const = 0;
            
        protected:
            virtual ~IGenericParameters() {}
        };
    }
}

#endif // __MURL_GRAPH_I_GENERIC_PARAMETERS_H__

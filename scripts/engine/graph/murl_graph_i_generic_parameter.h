// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_GENERIC_PARAMETER_H__
#define __MURL_GRAPH_I_GENERIC_PARAMETER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IConstantBufferParameter;
        class IGenericParameter;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IGenericParameter nodes.
         */
        typedef IGenericNodeTarget<IGenericParameter> IGenericParameterNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IGenericParameter
         * @brief The IGenericParameter graph node interface.
         * A generic parameter represents a specialized constant buffer parameter,
         * and can be used to manually define a single shader parameter without
         * any connection to a specific shader.
         *
         * See the Graph::IConstantBufferParameterGroup base interface for additional information.
         */
        class IGenericParameter
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
             * @brief Set the actual uniform variable data type.
             * Once initialized, the variable name cannot be changed.
             * @param type The uniform data type.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::UniformType type) = 0;

        protected:
            virtual ~IGenericParameter() {}
        };
    }
}

#endif // __MURL_GRAPH_I_GENERIC_PARAMETER_H__

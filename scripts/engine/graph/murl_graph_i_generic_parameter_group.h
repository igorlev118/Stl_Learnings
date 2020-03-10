// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_GENERIC_PARAMETER_GROUP_H__
#define __MURL_GRAPH_I_GENERIC_PARAMETER_GROUP_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_constant_buffer_parameter.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IConstantBufferParameterGroup;
        class IGenericParameterGroup;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IGenericParameterGroup nodes.
         */
        typedef IGenericNodeTarget<IGenericParameterGroup> IGenericParameterGroupNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IGenericParameterGroup
         * @brief The IGenericParameterGroup graph node interface.
         * A generic parameter group represents a specialized constant buffer parameter group,
         * and can be used to manually define a group of individual shader parameters without
         * any connection to a specific shader.
         *
         * See the Graph::IConstantBufferParameterGroup base interface for additional information.
         */
        class IGenericParameterGroup
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
             * @brief Get the mutable Graph::IConstantBufferParameterGroup interface.
             * This method returns a mutable pointer to the node's Graph::IConstantBufferParameterGroup interface.
             * @return The mutable Graph::IConstantBufferParameterGroup interface, or null if not available
             */
            virtual IConstantBufferParameterGroup* GetConstantBufferParameterGroupInterface() = 0;
            /**
             * @brief Get the constant Graph::IConstantBufferParameterGroup interface.
             * This method returns a constant pointer to the node's Graph::IConstantBufferParameterGroup interface.
             * @return The constant Graph::IConstantBufferParameterGroup interface, or null if not available
             */
            virtual const IConstantBufferParameterGroup* GetConstantBufferParameterGroupInterface() const = 0;

            /**
             * @brief Get the mutable Graph::IConstantBufferParameter container storing the individual parameters.
             * This method returns a mutable pointer to the node's Graph::IConstantBufferParameter container
             * that can be used to set or query the individual generic parameter nodes.
             * @return The mutable Graph::IConstantBufferParameter container, or null if not available.
             */
            virtual IConstantBufferParameterNodeTarget* GetConstantBufferParameterNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IConstantBufferParameter container storing the individual parameters.
             * This method returns a constant pointer to the node's Graph::IConstantBufferParameter container
             * that can be used to query the individual generic parameter nodes.
             * @return The constant Graph::IConstantBufferParameter container, or null if not available.
             */
            virtual const IConstantBufferParameterNodeTarget* GetConstantBufferParameterNodeTarget() const = 0;

        protected:
            virtual ~IGenericParameterGroup() {}
        };
    }
}

#endif // __MURL_GRAPH_I_GENERIC_PARAMETER_GROUP_H__

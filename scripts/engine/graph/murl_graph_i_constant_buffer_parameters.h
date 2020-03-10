// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETERS_H__
#define __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETERS_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_constant_buffer_container.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IParameters;
        class IConstantBufferParameters;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IConstantBufferParameters nodes.
         */
        typedef IGenericNodeTarget<IConstantBufferParameters> IConstantBufferParametersNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IConstantBufferParameters
         * @brief The IConstantBufferParameters graph node interface.
         * The IConstantBufferParameters provides a means to define custom material parameters
         * present in one or more uniform buffers.
         *
         * Use the Graph::IConstantBufferContainer base interface to define, set or query
         * user-defined parameter groups.
         *
         * See the Graph::IConstantBufferParameterGroup interface for defining individual groups.
         * See the Graph::IParameters base interface for additional information.
         */
        class IConstantBufferParameters : public IConstantBufferContainer
        {
        public:
            enum ConstantBufferParametersFlags
            {
                CONSTANT_BUFFER_PARAMETERS_FLAG_MODIFIED        = (1 << 0),
                CONSTANT_BUFFER_PARAMETERS_FLAG_FORCE_UPDATE    = (1 << 1),
                CONSTANT_BUFFER_PARAMETERS_FLAG_CHANGED         = (1 << 2)
            };
            
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
             * @brief Get current flags.
             * @return A bit mask made up from individual GenericParametersFlags values.
             */
            virtual UInt32 GetConstantBufferParametersFlags() const = 0;
            
        protected:
            virtual ~IConstantBufferParameters() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETERS_H__

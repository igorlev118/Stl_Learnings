// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETER_GROUP_H__
#define __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETER_GROUP_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_constant_buffer.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IConstantBuffer;
    }
    
    namespace Graph
    {
        class IConstantBufferParameterGroup;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IConstantBufferParameterGroup nodes.
         */
        typedef IGenericNodeTarget<IConstantBufferParameterGroup> IConstantBufferParameterGroupNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IConstantBufferParameterGroup
         * @brief The IConstantBufferParameterGroup graph node interface.
         * A parameter group collects references to a number of individual Graph::IConstantBufferParameter
         * nodes, which together make up a logical block of uniform variables in a GPU shader
         * program. 
         *
         * Parameter groups essentially employ the "constant buffer" or "uniform buffer"
         * concept of DirectX 10+ and OpenGL|ES 3.0+, which allows for efficient variable state 
         * switching during rendering, as well as efficient updates of individual groups of variables
         * with different update frequencies. API versions below the versions mentioned above do
         * not (necessarily) implement this concept; however, in the Murl Engine it is necessary to 
         * follow this scheme to be compatible in both directions.
         *
         * For this reason, a parameter group is defined using a given group name, which must match 
         * the name of a group defined in the shader code (if the API demands so).
         *
         * A number of individual generic parameter groups must be grouped together in a 
         * Graph::IConstantBufferParameters container, which can then be activated for rendering in the
         * same way as Graph::IFixedParameters nodes.
         *
         * See the Graph::IConstantBuffer base interface for accessing the underlying data buffer.
         * See the Graph::IParameters interface for additional information.
         */
        class IConstantBufferParameterGroup : public IConstantBuffer
        {
        public:
            enum ConstantBufferParameterGroupFlags
            {
                CONSTANT_BUFFER_PARAMETER_GROUP_FLAG_MODIFIED        = (1 << 0),
                CONSTANT_BUFFER_PARAMETER_GROUP_FLAG_FORCE_UPDATE    = (1 << 1),
                CONSTANT_BUFFER_PARAMETER_GROUP_FLAG_CHANGED         = (1 << 2)
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
             * @brief Set the group name, (constant buffer or uniform buffer name).
             * Once initialized, the name cannot be changed.
             * @param name The name.
             * @return true if successful.
             */
            virtual Bool SetName(const String& name) = 0;

            /**
             * @brief Get current flags.
             * @return A bit mask made up from individual ConstantBufferParameterGroupFlags values.
             */
            virtual UInt32 GetConstantBufferParameterGroupFlags() const = 0;
            
            /**
             * @brief Get the group's internal video renderer object.
             * @return A pointer to the mutable video renderer object.
             */
            virtual Video::IConstantBuffer* GetVideoConstantBufferObject() const = 0;
            
        protected:
            virtual ~IConstantBufferParameterGroup() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CONSTANT_BUFFER_PARAMETER_GROUP_H__

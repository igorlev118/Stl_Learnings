// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TEMPLATE_H__
#define __MURL_GRAPH_I_TEMPLATE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAttributes;

    namespace Resource
    {
        class IGraphNode;
    }

    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITemplate
         * @brief The ITemplate graph node interface.
         * A template node stores the Resource::IGraphNode object it was created from, in 
         * order to be able to create Graph::IInstance nodes later on, which may directly
         * source their sub-graph from the already existing graph by referencing this
         * template.
         * It is often cumbersome to always have to create an extra graph resource object
         * within a package when it is desired to create multiple instances of a sub-graph.
         * Using nodes implementing this interface, instantiation may also occur like this:
         * @code
         * <Template id="myTemplate>
         *   <Namespace id="{namespaceId}">
         *      ... put your nodes here ...
         *   </Namespace>
         * </Template>
         *
         * <Instance templateId="myTemplate" namespaceId="nmSpc1"/>
         * <Instance templateId="myTemplate" namespaceId="nmSpc2"/>
         * <Instance templateId="myTemplate" namespaceId="nmSpc3"/>
         * @endcode
         */
        class ITemplate
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
             * @brief Set the resource graph node from which to create template instances.
             * @param node The resource graph node.
             * @return true if successful.
             */
            virtual Bool SetResourceGraphNode(const Resource::IGraphNode* node) = 0;
            /**
             * @brief Get the resource graph node from which to create template instances.
             * @return The resource graph node.
             */
            virtual const Resource::IGraphNode* GetResourceGraphNode() const = 0;

            /**
             * @brief Get the set of user-defined template parameters, if any are present.
             * @return The set of parameters, or null if no user-defined parameters are present.
             */
            virtual const IAttributes* GetUserParameters() const = 0;

        protected:
            virtual ~ITemplate() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITemplate nodes.
         */
        typedef IGenericNodeTarget<ITemplate> ITemplateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TEMPLATE_H__

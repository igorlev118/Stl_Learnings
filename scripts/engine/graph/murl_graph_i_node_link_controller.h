// Copyright 2010-2017 Spraylight GmbH

#ifndef __MURL_GRAPH_I_NODE_LINK_CONTROLLER_H__
#define __MURL_GRAPH_I_NODE_LINK_CONTROLLER_H__

#include "murl_graph_i_link_controller.h"
#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface INodeLinkController
         * @brief The INodeLinkController interface.
         */
        class INodeLinkController
        {
        public:
            /**
             * @brief Get the mutable IController interface.
             * @return The mutable IController interface.
             */
            virtual IController* GetControllerInterface() = 0;
            /**
             * @brief Get the constant IController interface.
             * @return The constant IController interface.
             */
            virtual const IController* GetControllerInterface() const = 0;

            /**
             * @brief Get the mutable ILinkController interface.
             * @return The mutable ILinkController interface.
             */
            virtual ILinkController* GetLinkControllerInterface() = 0;
            /**
             * @brief Get the constant ILinkController interface.
             * @return The constant ILinkController interface.
             */
            virtual const ILinkController* GetLinkControllerInterface() const = 0;

            /**
             * @brief Get the mutable source node target container.
             * This method returns a mutable pointer to a typed Graph::IGenericNodeTarget
             * container, which allows to set or query the linked source node.
             * @return The mutable Graph::IGenericNodeTarget container.
             */
            virtual IGenericNodeTarget<INode>* GetSourceNodeTarget() = 0;
            /**
             * @brief Get the constant source node target container.
             * This method returns a constant pointer to a typed Graph::IGenericNodeTarget
             * container, which allows to query the linked source node.
             * @return The constant Graph::IGenericNodeTarget container.
             */
            virtual const IGenericNodeTarget<INode>* GetSourceNodeTarget() const = 0;

        protected:
            virtual ~INodeLinkController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_NODE_LINK_CONTROLLER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SWITCH_H__
#define __MURL_GRAPH_I_SWITCH_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_indexed.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISwitch
         * @brief The ISwitch graph node interface.
         * Graph::ISwitch nodes provide an easy and efficient way to select at most one child
         * among a given number of children to be active and visible at the same time.
         *
         * The currently active child can be either selected via the Graph::IIndexed base interface
         * by specifying that child's index, or by calling SetSelectedChild() with a given child
         * node ID. When doing so, any previously active other child gets deactivated.
         */
        class ISwitch : public IIndexed
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
             * @brief Set the currently active child node.
             * @param id The node ID of the child to activate.
             * @return true if successful.
             */
            virtual Bool SetSelectedChild(const String& id) = 0;
            /**
             * @brief Get the currently active child node.
             * @return The currently active node, or a null pointer if none is active.
             */
            virtual INode* GetSelectedChild() const = 0;
            
            /**
             * @brief Check if a child with a given node ID is currently active.
             * @param id The child node ID to check.
             * @return true if the child with the given ID is active.
             */
            virtual Bool IsChildSelected(const Char* id) const = 0;
            /**
             * @brief Check if a child with a given node ID is currently active.
             * @param id The child node ID to check.
             * @return true if the child with the given ID is active.
             */
            virtual Bool IsChildSelected(const String& id) const = 0;
            
        protected:
            virtual ~ISwitch() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISwitch nodes.
         */
        typedef IGenericNodeTarget<ISwitch> ISwitchNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SWITCH_H__

// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_NAMESPACE_H__
#define __MURL_GRAPH_I_NAMESPACE_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        class INamespace;
        typedef Array<INamespace*> INamespaceArray;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface INamespace
         * @brief The INamespace graph node interface.
         * When interacting with a scene graph, it is useful and often necessary to retrieve
         * a reference to a specific node from within a large graph via a given node ID.
         *
         * Generally, such node IDs must be unique; to facilitate organization of node
         * hierarchies it is possible to restrict this uniqueness to the sub-graph below
         * a given INamespace node. In such a case, a specific node can be found in the graph
         * by prepending the namespace's ID followed by a slash ('/') to the actual node ID.
         * This scheme also works for nested namespaces, by simply concatenating such namespace
         * prefixes.
         *
         * When referring to a specific node from a given other node, the path to the target
         * node can be expressed very much like the notation commonly used in a UNIX-like
         * file path, with '.' representing the current namespace, '..' the parent, and a
         * leading '/' the root namespace.
         *
         * Example, assuming the graph is instantiated at root level:
         *
         * @code
         * <Graph>
         *   <Namespace id="nmspc1">
         *     <Namespace id="nmspc2">
         *       <!-- The node that gets referenced in this example -->
         *       <Node id="node1"/>
         *       <!-- The following five references target the node from the same namespace -->
         *       <Reference targetId="node1"/>
         *       <Reference targetId="./node1"/>
         *       <Reference targetId="../nmspc2/node1"/>
         *       <Reference targetId="../../nmspc1/nmspc2/node1"/>
         *       <Reference targetId="/nmspc1/nmspc2/node1"/>
         *       <!-- ... several other ways exist -->
         *     </Namespace>
         *     <Namespace id="nmspc3">
         *       <!-- The following two references target the node from a sibling namespace -->
         *       <Reference targetId="../nmspc2/node1"/>
         *       <Reference targetId="/nmspc1/nmspc2/node1"/>
         *       <!-- ... several other ways exist -->
         *     </Namespace>
         *   </Namespace>
         * </Graph>
         * @endcode
         *
         * Note, when targeting a node from a Logic::IProcessor, it is always assumed to start
         * the search from the root level, i.e. namespaces must always be specified.
         *
         * A namespace node can also be referenced from another node; the given ID represents
         * both a separator for its children as well as a regular ID.
         *
         * See Graph::INode::SetId() for a description of valid IDs.
         */
        class INamespace
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
             * @brief Register a given node with this namespace.
             * This method registers a given node with the current namespace, using a given
             * (single) node ID. Registering will only succeed if the given ID is valid and not
             * empty, no other node or namespace is already registered with the same ID, and the
             * ID does not represent a complex path.
             * @param name The ID of the node to register.
             * @param node The node to register.
             * @return true if successful.
             */
            virtual Bool RegisterNode(const String& name, INode* node) = 0;
            /**
             * @brief Unregister a given node from this namespace.
             * This method unregisters a previously registered node from the current namespace,
             * using a given (single) node ID. Unregistering will fail if no node is currently
             * registered with the given ID, or the registered node does not match the given
             * input node.
             * @param name The ID of the node to unregister.
             * @param node The node to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterNode(const String& name, INode* node) = 0;

            /**
             * @brief Register a given sub-namespace with this namespace.
             * This method registers a given other namespace with the current namespace, using
             * a given (single) node ID. Registering will only succeed if the given ID is valid
             * and not empty, no other node or namespace is already registered with the same ID,
             * and the ID does not represent a complex path.
             * @param name The ID of the sub-namespace to register.
             * @param nameSpace The sub-namespace to register.
             * @return true if successful.
             */
            virtual Bool RegisterSubNamespace(const String& name, INamespace* nameSpace) = 0;
            /**
             * @brief Unregister a given sub-namespace from this namespace.
             * This method unregisters a previously registered other namespace from the current
             * namespace, using a given (single) node ID. Unregistering will fail if no namespace
             * is currently registered with the given ID, or the registered sub-namespace does
             * not match the given input namespace.
             * @param name The ID of the sub-namespace to unregister.
             * @param nameSpace The sub-namespace to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterSubNamespace(const String& name, INamespace* nameSpace) = 0;

            /**
             * @brief Find a mutable node within the namespace's sub-graph.
             * This method tries to find and return the node at the given path within the sub-graph
             * below this namespace.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return A pointer to the requested node, or null if not found.
             */
            virtual INode* FindNode(const String& nodeIdPath) = 0;

            /**
             * @brief Find a constant node within the namespace's sub-graph.
             * This method tries to find and return the node at the given path within the sub-graph
             * below this namespace.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return A pointer to the requested node, or null if not found.
             */
            virtual const INode* FindNode(const String& nodeIdPath) const = 0;

        protected:
            virtual ~INamespace() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::INamespace nodes.
         */
        typedef IGenericNodeTarget<INamespace> INamespaceNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_NAMESPACE_H__

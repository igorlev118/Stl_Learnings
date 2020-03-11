// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_OBSERVABLE_NODE_H__
#define __MURL_LOGIC_GRAPH_OBSERVABLE_NODE_H__

#include "murl_logic_i_observable_node.h"

#include "murl_graph_i_namespace.h"
#include "murl_graph_i_reference.h"

#include "murl_debug_trace.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief A template class to create an IObservableNode object for accessing a Graph node.
         */
        template<class NodeType>
        class GraphObservableNode : public IObservableNode
        {
        public:
            /**
             * @brief The default constructor.
             */
            GraphObservableNode()
            : mTypedNode(0)
            {
            }

            /**
             * @brief The destructor.
             * Removes the reference from the graph node.
             */
            virtual ~GraphObservableNode()
            {
                RemoveReference();
            }

            /**
             * @brief Check if the graph node is valid.
             * @return true if the graph node is valid.
             */
            virtual Bool IsValid() const
            {
                return mTypedNode != 0;
            }

            /**
             * @brief Remove the reference from the graph node.
             * @return true if successful or if the graph node is null.
             */
            virtual Bool RemoveReference()
            {
                Bool ret = true;
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    ret = node->RemoveReference();
                }
                mTypedNode = 0;
                return ret;
            }

            /**
             * @brief Get a reference to a graph node.
             * @param node The graph node.
             * @return true if successful.
             */
            Bool GetReference(Graph::INode* node)
            {
                return CreateTypedNode(node);
            }

            /**
             * @brief Get a reference to a graph node by identifier relative to a namespace.
             * @param namespaceNode The graph namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return true if successful.
             */
            Bool GetReference(Graph::INamespace* namespaceNode, const String& nodeIdPath)
            {
                Graph::INode* node = FindNode(namespaceNode, nodeIdPath);
                return CreateTypedNode(node);
            }

            /**
             * @brief Get a reference to a graph node by resolving a Graph::IReference node.
             * @param node The Graph::IReference node to resolve.
             * @return true if successful.
             */
            Bool ResolveReference(Graph::INode* node)
            {
                return CreateTypedNode(TrackReference(node));
            }

            /**
             * @brief Get a reference to a graph node by resolving a Graph::IReference node by identifier
             *  relative to a namespace.
             * @param namespaceNode The graph namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return true if successful.
             */
            Bool ResolveReference(Graph::INamespace* namespaceNode, const String& nodeIdPath)
            {
                Graph::INode* node = FindNode(namespaceNode, nodeIdPath);
                return CreateTypedNode(TrackReference(node));
            }

            /**
             * @brief Get the graph node interface.
             * @return A pointer to the graph node interface or null.
             */
            NodeType* GetNode() const
            {
                return mTypedNode;
            }

            /**
             * @brief Get the graph Graph::INode interface.
             * @return A pointer to the Graph::INode interface or null.
             */
            Graph::INode* GetNodeInterface() const
            {
                if (mTypedNode != 0)
                {
                    return mTypedNode->GetNodeInterface();
                }
                return 0;
            }

            /**
             * @brief Dynamic cast a graph node to this template's node type.
             * @param node The graph node to cast.
             * @return A pointer to the graph node interface or null.
             */
            NodeType* DynamicCastNode(Graph::INode* node) const
            {
                return dynamic_cast<NodeType*>(node);
            }

            /**
             * @brief Dynamic cast a graph node by resolving a Graph::IReference node
             *  to this template's node type.
             * @param node The graph node to cast.
             * @return A pointer to the graph node interface or null.
             */
            NodeType* DynamicCastResolveNode(Graph::INode* node) const
            {
                return dynamic_cast<NodeType*>(TrackReference(node));
            }

        protected:
            /**
             * @brief Create a typed graph node pointer and get a reference.
             * Dynamic cast the graph node pointer to the template's graph node
             * type and add a reference to the node if successful.
             * @param node The graph node.
             * @return true if successful.
             */
            Bool CreateTypedNode(Graph::INode* node)
            {
                if (node != 0)
                {
                    NodeType* typedNode = DynamicCastNode(node);
                    if (typedNode == 0)
                    {
                        MURL_ERROR("Incorrect type for node \"%s\"", node->GetId().Begin());
                        return false;
                    }
                    RemoveReference();
                    mTypedNode = typedNode;
                    return node->AddReference();
                }
                return false;
            }

            /**
             * @brief Find a graph node by identifier relative to a namespace.
             * @param namespaceNode The graph namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return A pointer to the graph node or null if not found.
             */
            Graph::INode* FindNode(Graph::INamespace* namespaceNode, const String& nodeIdPath) const
            {
                Graph::INode* node = 0;
                if (namespaceNode != 0)
                {
                    node = namespaceNode->FindNode(nodeIdPath);
                    if (node == 0)
                    {
                        const String& namespaceId = namespaceNode->GetNodeInterface()->GetId();
                        if (namespaceId.IsEmpty())
                        {
                            MURL_ERROR("Node \"%s\" not found", nodeIdPath.Begin());
                        }
                        else
                        {
                            MURL_ERROR("Node \"%s\" not found relative to namespace \"%s\"",
                                       nodeIdPath.Begin(), namespaceId.Begin());
                        }
                    }
                }
                return node;
            }

            /**
             * @brief Track a Graph::IReference node's target.
             * @param node The graph node to track.
             * @return A pointer to the target node.
             */
            Graph::INode* TrackReference(Graph::INode* node) const
            {
                Graph::IReference* reference = dynamic_cast<Graph::IReference*>(node);
                while (reference != 0)
                {
                    Graph::INodeTarget* target = reference->GetNodeTarget();
                    if (target == 0)
                    {
                        MURL_ERROR("Missing target in node \"%s\"", reference->GetNodeInterface()->GetId().Begin());
                        break;
                    }
                    node = target->GetNode(0);
                    if (node == 0)
                    {
                        MURL_ERROR("Missing node in target \"%s\"", reference->GetNodeInterface()->GetId().Begin());
                        break;
                    }
                    reference = dynamic_cast<Graph::IReference*>(node);
                }
                return node;
            }

            NodeType* mTypedNode;
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_OBSERVABLE_NODE_H__

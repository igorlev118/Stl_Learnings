// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_NODE_H__
#define __MURL_LOGIC_GRAPH_NODE_H__

#include "murl_logic_graph_observable_node.h"

#include "murl_graph_i_root.h"
#include "murl_graph_i_animation_time_controller.h"
#include "murl_graph_i_link_controller.h"
#include "murl_graph_i_node_link_controller.h"
#include "murl_graph_i_script_logic_controller.h"
#include "murl_graph_i_time_controller.h"
#include "murl_graph_i_timeline_variable_controller.h"
#include "murl_graph_i_uniform_time_controller.h"
#include "murl_graph_i_variable_controller.h"
#include "murl_graph_i_wave_uniform_time_controller.h"

namespace Murl
{
    namespace Logic
    {
        template<class NodeType>
        class GraphNodeT;
        typedef GraphNodeT<Graph::INamespace> NamespaceNode;

        /**
         * @ingroup MurlLogicClasses
         * @brief A template class for safe access of basic graph node properties and for
         * easy use of the GraphObservableNode object in combination with a INodeObserver.
         * See @link MurlLogicGraphNodeTypes GraphNodeTypes @endlink for predefined types.
         */
        template<class NodeType>
        class GraphNodeT
        {
        public:
            /** Type definition of the observable node. */
            typedef GraphObservableNode<NodeType> ObservableNodeT;

            /**
             * @brief The default constructor.
             * Creates a GraphObservableNode object.
             */
            GraphNodeT()
            : mObservableNode(new ObservableNodeT)
            {
            }

            /**
             * @brief The constructor including a graph node.
             * Creates a GraphObservableNode object.
             * @param node The graph node.
             */
            GraphNodeT(Graph::INode* node)
            : mObservableNode(new ObservableNodeT)
            {
                mObservableNode->GetReference(node);
            }

            /**
             * @brief The constructor including a graph node object.
             * Creates a GraphObservableNode object.
             * @param graphNode The graph node object.
             */
            template<class NodeType2>
            GraphNodeT(const GraphNodeT<NodeType2>& graphNode)
            : mObservableNode(new ObservableNodeT)
            {
                mObservableNode->GetReference(graphNode.GetNodeInterface());
            }

            /**
             * @brief The constructor including the graph root node and path.
             * Creates a GraphObservableNode object.
             * @param root The graph root node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             */
            GraphNodeT(const Graph::IRoot* root, const String& nodeIdPath)
            : mObservableNode(new ObservableNodeT)
            {
                mObservableNode->GetReference(root->GetRootNamespace(), nodeIdPath);
            }

            /**
             * @brief The constructor including a graph namespace node and path.
             * Creates a GraphObservableNode object.
             * @param namespaceNode The graph namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             */
            GraphNodeT(Graph::INamespace* namespaceNode, const String& nodeIdPath)
            : mObservableNode(new ObservableNodeT)
            {
                mObservableNode->GetReference(namespaceNode, nodeIdPath);
            }

            /**
             * @brief The constructor including a graph namespace node and path.
             * Creates a GraphObservableNode object.
             * @param namespaceNode The logic namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             */
            GraphNodeT(const NamespaceNode& namespaceNode, const String& nodeIdPath)
            : mObservableNode(new ObservableNodeT)
            {
                mObservableNode->GetReference(namespaceNode.GetNode(), nodeIdPath);
            }

            /**
             * @brief The destructor.
             * Destroys the GraphObservableNode object.
             */
            virtual ~GraphNodeT()
            {
            }

            /**
             * @brief Check if the graph node is valid.
             * @return true if the graph node is valid.
             */
            Bool IsValid() const
            {
                return mObservableNode->IsValid();
            }

            /**
             * @brief Remove the reference from the graph node.
             * @return true if successful or if the graph node is null.
             */
            Bool RemoveReference()
            {
                return mObservableNode->RemoveReference();
            }

            /**
             * @brief Check if a graph node can be referenced by this template's node type.
             * @param node The graph node to check.
             * @return true if the graph node has a compatible type, otherwise false.
             */
            Bool CanReference(Graph::INode* node) const
            {
                return mObservableNode->DynamicCastNode(node) != 0;
            }

            /**
             * @brief Check if a graph node object can be referenced by this template's node type.
             * @param graphNode The graph node object to check.
             * @return true if the graph node object has a compatible type, otherwise false.
             */
            template<class NodeType2>
            Bool CanReference(const GraphNodeT<NodeType2>& graphNode) const
            {
                return CanReference(graphNode.GetNodeInterface());
            }

            /**
             * @brief Check if a graph node can be referenced by this template's node type
             *  by resolving a Graph::IReference node.
             * @param node The graph node to check.
             * @return true if the graph node has a compatible type, otherwise false.
             */
            Bool CanResolveReference(Graph::INode* node) const
            {
                return mObservableNode->DynamicCastResolveNode(node) != 0;
            }

            /**
             * @brief Check if a graph node object can be referenced by this template's node type
             *  by resolving a Logic::ReferenceNode.
             * @param graphNode The graph node object to check.
             * @return true if the graph node object has a compatible type, otherwise false.
             */
            template<class NodeType2>
            Bool CanResolveReference(const GraphNodeT<NodeType2>& graphNode) const
            {
                return CanResolveReference(graphNode.GetNodeInterface());
            }
            
            /**
             * @brief Get a reference to a graph node of this template's node type.
             * @param node The graph node.
             * @return The observable node.
             */
            IObservableNodePtr GetReference(Graph::INode* node)
            {
                mObservableNode->GetReference(node);
                return mObservableNode;
            }

            /**
             * @brief Get a reference to a graph node object of this template's node type.
             * @param graphNode The graph node object.
             * @return The observable node.
             */
            template<class NodeType2>
            IObservableNodePtr GetReference(const GraphNodeT<NodeType2>& graphNode)
            {
                return GetReference(graphNode.GetNodeInterface());
            }

            /**
             * @brief Get a reference to a graph node by identifier.
             * @param root The graph root node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return The observable node.
             */
            IObservableNodePtr GetReference(const Graph::IRoot* root, const String& nodeIdPath)
            {
                mObservableNode->GetReference(root->GetRootNamespace(), nodeIdPath);
                return mObservableNode;
            }

            /**
             * @brief Get a reference to a graph node by identifier relative to a namespace.
             * @param namespaceNode The graph namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return The observable node.
             */
            IObservableNodePtr GetReference(Graph::INamespace* namespaceNode, const String& nodeIdPath)
            {
                mObservableNode->GetReference(namespaceNode, nodeIdPath);
                return mObservableNode;
            }

            /**
             * @brief Get a reference to a graph node by identifier relative to a namespace.
             * @param namespaceNode The logic namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return The observable node.
             */
            IObservableNodePtr GetReference(const NamespaceNode& namespaceNode, const String& nodeIdPath)
            {
                mObservableNode->GetReference(namespaceNode.GetNode(), nodeIdPath);
                return mObservableNode;
            }

            /**
             * @brief Get a reference to a graph node by resolving a Graph::IReference node.
             * @param node The Graph::IReference node to resolve.
             * @return The observable node.
             */
            IObservableNodePtr ResolveReference(Graph::INode* node)
            {
                mObservableNode->ResolveReference(node);
                return mObservableNode;
            }

            /**
             * @brief Get a reference to a graph node by resolving a Logic::ReferenceNode.
             * @param graphNode The Logic::ReferenceNode node to resolve.
             * @return The observable node.
             */
            template<class NodeType2>
            IObservableNodePtr ResolveReference(const GraphNodeT<NodeType2>& graphNode)
            {
                return ResolveReference(graphNode.GetNodeInterface());
            }

            /**
             * @brief Get a reference to a graph node by resolving a Graph::IReference node by identifier.
             * @param root The graph root node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return The observable node.
             */
            IObservableNodePtr ResolveReference(const Graph::IRoot* root, const String& nodeIdPath)
            {
                mObservableNode->ResolveReference(root->GetRootNamespace(), nodeIdPath);
                return mObservableNode;
            }

            /**
             * @brief Get a reference to a graph node by resolving a Graph::IReference node by identifier
             *  relative to a namespace.
             * @param namespaceNode The graph namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return The observable node.
             */
            IObservableNodePtr ResolveReference(Graph::INamespace* namespaceNode, const String& nodeIdPath)
            {
                mObservableNode->ResolveReference(namespaceNode, nodeIdPath);
                return mObservableNode;
            }

            /**
             * @brief Get a reference to a graph node by resolving a Graph::IReference node by identifier
             *  relative to a namespace.
             * @param namespaceNode The logic namespace node.
             * @param nodeIdPath The node ID to find, with optional path specification when searching
             *      in sub-namespaces.
             * @return The observable node.
             */
            IObservableNodePtr ResolveReference(const NamespaceNode& namespaceNode, const String& nodeIdPath)
            {
                mObservableNode->ResolveReference(namespaceNode.GetNode(), nodeIdPath);
                return mObservableNode;
            }

            /**
             * @brief Conversion operator.
             * @return The IObservableNode interface shared pointer.
             */
            operator IObservableNodePtr() const
            {
                return mObservableNode;
            }

            /**
             * @brief Dereference operator.
             * @return A pointer to the graph node interface or null.
             */
            NodeType* operator->() const
            {
                return mObservableNode->GetNode();
            }

            /**
             * @brief Get the graph node interface.
             * @return A pointer to the graph node interface or null.
             */
            NodeType* GetNode() const
            {
                return mObservableNode->GetNode();
            }

            /**
             * @brief Get the graph Graph::INode interface.
             * @return A pointer to the Graph::INode interface or null.
             */
            Graph::INode* GetNodeInterface() const
            {
                return mObservableNode->GetNodeInterface();
            }

            /**
             * @brief Get the Graph::INode node identifier.
             * @return The Graph::INode node identifier
             */
            const String& GetId() const
            {
                const Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetId();
                }
                return Util::StaticEmptyString();
            }

            /**
             * @brief Enable/disable logic traversals.
             * Calls Graph::ITraversable::SetActive().
             * @param isActive If true, logic traversals are enabled.
             * @return true if successful.
             */
            Bool SetActive(Bool isActive)
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->SetActive(isActive);
                }
                return false;
            }

            /**
             * @brief Check if logic traversals are enabled.
             * Calls Graph::ITraversable::IsActive().
             * @return true if enabled.
             */
            Bool IsActive() const
            {
                const Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->IsActive();
                }
                return false;
            }

            /**
             * @brief Enable/disable output traversals.
             * Calls Graph::ITraversable::SetVisible().
             * @param isVisible If true, output traversals are enabled.
             * @return true if successful.
             */
            Bool SetVisible(Bool isVisible)
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->SetVisible(isVisible);
                }
                return false;
            }

            /**
             * @brief Check if output traversals are enabled.
             * Calls Graph::ITraversable::IsVisible().
             * @return true if enabled.
             */
            Bool IsVisible() const
            {
                const Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->IsVisible();
                }
                return false;
            }

            /**
             * @brief Enable/disable both logic and output traversals.
             * Calls Graph::ITraversable::SetActiveAndVisible().
             * @param enabled If true, both logic and output traversals are enabled.
             * @return true if successful.
             */
            Bool SetActiveAndVisible(Bool enabled)
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->SetActiveAndVisible(enabled);
                }
                return false;
            }

            /**
             * @brief Check if both logic and output traversals are enabled.
             * Calls Graph::ITraversable::IsActiveAndVisible().
             * @return true if both are enabled.
             */
            Bool IsActiveAndVisible() const
            {
                const Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->IsActiveAndVisible();
                }
                return false;
            }

            /**
             * @brief Get the graph Graph::INode interface of a child by index.
             * @param index The zero-based index of the child.
             * @return A pointer to the Graph::INode interface or null.
             */
            Graph::INode* GetChild(UInt32 index = 0) const
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetChild(index);
                }
                return 0;
            }

            /**
             * @brief Get the graph Graph::INode interface of a child by identifier.
             * @param identifier The identifier of the child to search for.
             * @return A pointer to the Graph::INode interface or null.
             */
            Graph::INode* GetChild(const String& identifier) const
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetChild(identifier);
                }
                return 0;
            }

            /**
             * @brief Return the number of the graph node's children.
             * @return The number of children.
             */
            UInt32 GetNumberOfChildren() const
            {
                const Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetNumberOfChildren();
                }
                return 0;
            }

            /**
             * @brief Get the graph Graph::INode interface of a parent by index.
             * @param index The zero-based index of the parent.
             * @return A pointer to the Graph::INode interface or null.
             */
            Graph::INode* GetParent(UInt32 index = 0) const
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetParent(index);
                }
                return 0;
            }

            /**
             * @brief Get the graph Graph::INode interface of a parent by identifier.
             * @param identifier The identifier of the parent to search for.
             * @return A pointer to the Graph::INode interface or null.
             */
            Graph::INode* GetParent(const String& identifier) const
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetParent(identifier);
                }
                return 0;
            }

            /**
             * @brief Return the number of the graph node's parents.
             * @return The number of parents.
             */
            UInt32 GetNumberOfParents() const
            {
                const Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetNumberOfParents();
                }
                return 0;
            }

            /**
             * @brief Get the Graph::IController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::IController interface or null.
             */
            Graph::IController* GetController(UInt32 index = 0) const
            {
                Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetController(index);
                }
                return 0;
            }

            /**
             * @brief Get the graph controller interface of a specified type at a given index.
             * @param index The zero-based index of the controller.
             * @tparam ControllerType The controller interface class type.
             * @return A pointer to the ControllerType interface or null.
             */
            template<class ControllerType>
            ControllerType* GetController(UInt32 index = 0) const
            {
                Graph::IController* controller = GetController(index);
                if (controller != 0)
                {
                    return dynamic_cast<ControllerType*>(controller);
                }
                return 0;
            }

            /**
             * @brief Return the number of the graph node's controllers.
             * @return The number of controllers.
             */
            UInt32 GetNumberOfControllers() const
            {
                const Graph::INode* node = GetNodeInterface();
                if (node != 0)
                {
                    return node->GetNumberOfControllers();
                }
                return 0;
            }

            /**
             * @brief Get the Graph::ILinkController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::ILinkController interface or null.
             */
            Graph::ILinkController* GetLinkController(UInt32 index = 0) const
            {
                return GetController<Graph::ILinkController>(index);
            }

            /**
             * @brief Get the Graph::ILogicController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::ILogicController interface or null.
             */
            Graph::ILogicController* GetLogicController(UInt32 index = 0) const
            {
                return GetController<Graph::ILogicController>(index);
            }

            /**
             * @brief Get the Graph::INodeLinkController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::INodeLinkController interface or null.
             */
            Graph::INodeLinkController* GetNodeLinkController(UInt32 index = 0) const
            {
                return GetController<Graph::INodeLinkController>(index);
            }

            /**
             * @brief Get the Graph::IScriptLogicController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::IScriptLogicController interface or null.
             */
            Graph::IScriptLogicController* GetScriptLogicController(UInt32 index = 0) const
            {
                return GetController<Graph::IScriptLogicController>(index);
            }

            /**
             * @brief Get the Graph::ITimeController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::ITimeController interface or null.
             */
            Graph::ITimeController* GetTimeController(UInt32 index = 0) const
            {
                return GetController<Graph::ITimeController>(index);
            }

            /**
             * @brief Get the Graph::IAnimationTimeController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::IAnimationTimeController interface or null.
             */
            Graph::IAnimationTimeController* GetAnimationTimeController(UInt32 index = 0) const
            {
                return GetController<Graph::IAnimationTimeController>(index);
            }

            /**
             * @brief Get the Graph::IUniformTimeController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::IUniformTimeController interface or null.
             */
            Graph::IUniformTimeController* GetUniformTimeController(UInt32 index = 0) const
            {
                return GetController<Graph::IUniformTimeController>(index);
            }

            /**
             * @brief Get the Graph::IWaveUniformTimeController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::IWaveUniformTimeController interface or null.
             */
            Graph::IWaveUniformTimeController* GetWaveUniformTimeController(UInt32 index = 0) const
            {
                return GetController<Graph::IWaveUniformTimeController>(index);
            }

            /**
             * @brief Get the Graph::IVariableController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::IVariableController interface or null.
             */
            Graph::IVariableController* GetVariableController(UInt32 index = 0) const
            {
                return GetController<Graph::IVariableController>(index);
            }

            /**
             * @brief Get the Graph::ITimelineVariableController interface at a given index.
             * @param index The zero-based index of the controller.
             * @return A pointer to the Graph::ITimelineVariableController interface or null.
             */
            Graph::ITimelineVariableController* GetTimelineVariableController(UInt32 index = 0) const
            {
                return GetController<Graph::ITimelineVariableController>(index);
            }

        protected:
            SharedPointer<ObservableNodeT> mObservableNode;
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_NODE_H__

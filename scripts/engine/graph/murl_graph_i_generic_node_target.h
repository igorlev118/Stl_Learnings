// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_GENERIC_NODE_TARGET_H__
#define __MURL_GRAPH_I_GENERIC_NODE_TARGET_H__

#include "murl_graph_types.h"

namespace Murl
{
    namespace Graph
    {
        class IInitTracker;
        class IDeInitTracker;
        class INode;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @interface IGenericNodeTarget
         * @brief The IGenericNodeTarget graph node target interface.
         * A generic node target is used to encapsulate (possibly) any number of
         * nodes in a scene graph, referenced by their unique ID or directly by
         * pointer. It provides access methods to add, remove or query the set
         * of nodes that are referenced. By using an IGenericNodeTarget, a graph
         * node's process of handling references to other nodes can be unified,
         * the respective node references may be acquired by either specifying a
         * node ID in an XML scene graph file, or directly set from code when
         * a new node is created from a Logic::IProcessor.
         */
        template<class ObjectType>
        class IGenericNodeTarget
        {
        public:
            /**
             * @brief Initialize the node target.
             * To be able to reference nodes via their unique IDs in a scene
             * graph, a Graph::IInitTracker must be passed to the node target,
             * which holds a reference to the scene graph's root.
             * @param tracker The tracker used for node initialization.
             * @return true if successful.
             */
            virtual Bool Init(IInitTracker* tracker) = 0;
            /**
             * @brief De-Initialize the node target.
             * @param tracker The tracker used for node de-initialization.
             * @return true if successful.
             */
            virtual Bool DeInit(IDeInitTracker* tracker) = 0;
            
            /**
             * @brief Check if the node target is initialized.
             * @return true if initialized.
             */
            virtual Bool IsInitialized() const = 0;
            /**
             * @brief Check if the node target is modified.
             * This method returns true, whenever the set of encapsulated node
             * references changes, either in size or by content. When modified,
             * that state persists until a manual call to SetModified() with
             * parameter false.
             * @return true if modified.
             */
            virtual Bool IsModified() const = 0;
            
            /**
             * @brief Manually set or reset the initialized state of the target.
             * @param initialized The initialized state.
             * @return true if successful.
             */
            virtual Bool SetInitialized(Bool initialized) = 0;
            /**
             * @brief Manually set or reset the modified state of the target.
             * @param modified The modified state.
             * @return true if successful.
             */
            virtual Bool SetModified(Bool modified) = 0;
            
            /**
             * @brief Query the minimum number of nodes.
             * This method returns the defined minimum number of node references
             * that must be present for the Init() call to be successful.
             * @return The required minimum number of nodes for the target to
             *      be valid.
             */
            virtual UInt32 GetMinNumberOfNodes() const = 0;
            /**
             * @brief Query the maximum number of nodes.
             * This method returns the defined maximum number of node references
             * that can be present for the Init() call to be successful.
             * @return The required maximum number of nodes for the target to
             *      be valid.
             */
            virtual UInt32 GetMaxNumberOfNodes() const = 0;
            
            /**
             * @brief Set the total number of nodes.
             * The given value must be in the range from GetMinNumberOfNodes()
             * to GetMaxNumberOfNodes().
             * @param numberOfNodes The total number of nodes in the target.
             * @return true if successful.
             */
            virtual Bool SetNumberOfNodes(UInt32 numberOfNodes) = 0;
            /**
             * @brief Get the total number of nodes.
             * @return The total number of nodes in the target.
             */
            virtual UInt32 GetNumberOfNodes() const = 0;
            
            /**
             * @brief Set a single node ID at a given index.
             * You need to make sure that the given index is in the range from
             * 0 to GetNumberOfNodes()-1, use SetNumberOfNodes() to define the 
             * actual node count.
             * @param nodeId A string containing the full path and ID to a node
             *      in the scene graph.
             * @param index The index of the node ID to set, in the range from
             *      0 to GetNumberOfNodes()-1.
             * @return true if successful.
             */
            virtual Bool SetNodeId(const String& nodeId, UInt32 index) = 0;
            /**
             * @brief Get the node ID at a given index.
             * @param index The node ID index in the range from 0 to GetNumberOfNodes()-1.
             * @return The node ID at the given index.
             */
            virtual const String& GetNodeId(UInt32 index) const = 0;

            /**
             * @brief Set (replace) a single node for referencing at a given position.
             * You need to make sure that the given index is in the range from
             * 0 to GetNumberOfNodes()-1, use SetNumberOfNodes() to define the
             * actual node count.
             * @param object A pointer to the node.
             * @param index The zero-based position where to set the node, in the
             *      range from 0 to GetNumberOfNodes()-1.
             * @return true if successful.
             */
            virtual Bool SetNode(ObjectType* object, UInt32 index) = 0;
            /**
             * @brief Get the node at a given index.
             * @param index The node index in the range from 0 to GetNumberOfNodes()
             * @return The node at the given index.
             */
            virtual ObjectType* GetNode(UInt32 index) const = 0;
             
        protected:
            virtual ~IGenericNodeTarget() {}
        };
    }
}

#endif // __MURL_GRAPH_I_GENERIC_NODE_TARGET_H__

// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_NODE_ARRAY_TARGET_H__
#define __MURL_GRAPH_NODE_ARRAY_TARGET_H__

#include "murl_graph_generic_node_target.h"
#include "murl_graph_property.h"
#include "murl_graph_i_namespace.h"
#include "murl_graph_i_init_tracker.h"
#include "murl_graph_i_de_init_tracker.h"
#include "murl_graph_i_deserialize_attribute_tracker.h"
#include "murl_i_engine_configuration.h"
#include "murl_debug_trace.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphTargetClasses
         * @interface NodeArrayTarget
         * @brief The NodeArrayTarget class.
         * This class implements an IGenericNodeTarget that can reference any number
         * of graph nodes.
         * The MIN_NUMBER_OF_NODES and MAX_NUMBER_OF_NODES template parameters represent
         * the minimum and maximum number of referenced nodes that must be present for 
         * the Init() method to succeed.
         * The RESERVED_NUMBER_OF_NODES parameter defines the initial size of the reference
         * array. Must be in the range from MIN_NUMBER_OF_NODES to MAX_NUMBER_OF_NODES.
         */
        template<class ObjectType, UInt32 MIN_NUMBER_OF_NODES, UInt32 MAX_NUMBER_OF_NODES, UInt32 RESERVED_NUMBER_OF_NODES>
        class NodeArrayTarget : public GenericNodeTarget<ObjectType>
        {
        public:
            /**
             * @brief The constructor.
             */
            NodeArrayTarget()
            {
                if (RESERVED_NUMBER_OF_NODES > 0)
                {
                    mNodeIds.SetCount(RESERVED_NUMBER_OF_NODES);
                    mNodes.SetCount(RESERVED_NUMBER_OF_NODES, 0);
                }
            }

            NodeArrayTarget(ObjectType* const* nodes)
            {
                if (RESERVED_NUMBER_OF_NODES > 0)
                {
                    mNodeIds.SetCount(RESERVED_NUMBER_OF_NODES);
                    mNodes.SetCount(RESERVED_NUMBER_OF_NODES, 0);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_NODES; i++)
                    {
                        mNodes[i] = nodes[i];
                    }
                }
            }

            virtual ~NodeArrayTarget()
            {
            }
            
            /**
             * @brief Deserialize all defined target node IDs from a given tracker.
             * @param tracker The tracker to deserialize.
             * @return true if successful.
             */
            Bool DeserializeNodeIds(IDeserializeAttributeTracker* tracker)
            {
                tracker->GetAttributeValues(mNodeIds);
                mNodes.SetCount(mNodeIds.GetCount(), 0);
                return true;
            }
            
            /**
             * @brief Deserialize a single target node ID from a given tracker.
             * The actual index is retrieved from the tracker's base attribute.
             * @param tracker The tracker to deserialize.
             * @return true if successful.
             */
            Bool DeserializeNodeId(IDeserializeAttributeTracker* tracker)
            {
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                return DeserializeNodeId(tracker, index);
            }
            
            /**
             * @brief Deserialize a single target node ID from a given tracker at a given index.
             * @param tracker The tracker to deserialize.
             * @param index The index of the referenced node.
             * @return true if successful.
             */
            Bool DeserializeNodeId(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (index >= mNodeIds.GetCount())
                {
                    mNodeIds.SetCount(index + 1);
                }
                if (index >= mNodes.GetCount())
                {
                    mNodes.SetCount(index + 1, 0);
                    
                    for (UInt32 i = 0; i <= index; i++)
                    {
                        mNodes[i] = 0;
                    }
                }
                
                tracker->GetAttributeValue(mNodeIds[index]);
                return true;
            }
            
            virtual Bool Init(IInitTracker* tracker)
            {
                if (GenericNodeTarget<ObjectType>::IsInitialized())
                {
                    return true;
                }
                
                if (MIN_NUMBER_OF_NODES > MAX_NUMBER_OF_NODES)
                {
                    MURL_ERROR("Minimum number of targets cannot be greater than %d", MAX_NUMBER_OF_NODES);
                    return false;
                }

                IEnums::ResultAction actionNotFound = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_NOT_FOUND_ERROR);
                IEnums::ResultAction actionWrongInterface = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_WRONG_INTERFACE_ERROR);

                for (UInt32 i = 0; i < mNodeIds.GetCount(); i++)
                {
                    if (mNodeIds[i].IsEmpty())
                    {
                        continue;
                    }
                    
                    if (mNodes.GetCount() > i)
                    {
                        if (mNodes[i] != 0)
                        {
                            MURL_ERROR("Cannot specify both node ID and object for index %d", i);
                            ClearNamedNodes();
                            return false;
                        }
                    }
                    while (mNodes.GetCount() <= i)
                    {
                        mNodes.Add(0);
                    }
                    
                    INamespace* nmspc = tracker->GetCurrentNamespace();
                    if (nmspc == 0)
                    {
                        MURL_ERROR("No current namespace");
                        ClearNamedNodes();
                        return false;
                    }

                    ObjectType* object = 0;

                    INode* node = nmspc->FindNode(mNodeIds[i]);
                    if (node == 0)
                    {
                        if (actionNotFound != IEnums::RESULT_ACTION_IGNORE)
                        {
                            MURL_ERROR("Failed to get node \"%s\"", mNodeIds[i].Begin());
                            if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                            {
                                ClearNamedNodes();
                                return false;
                            }
                        }
                    }
                    else
                    {
                        node = node->GetNodeInterface();

                        object = dynamic_cast<ObjectType*>(node);
                        if (object == 0)
                        {
                            if (actionWrongInterface != IEnums::RESULT_ACTION_IGNORE)
                            {
                                MURL_ERROR("Failed to get interface \"%s\"", mNodeIds[i].Begin());
                                if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                                {
                                    ClearNamedNodes();
                                    return false;
                                }
                            }
                        }
                        else
                        {
                            node->AddReference();
                        }
                    }

                    mNodes[i] = object;
                }
                
                if (mNodes.GetCount() < MIN_NUMBER_OF_NODES)
                {
                    MURL_ERROR("Need at least %d nodes", MIN_NUMBER_OF_NODES);
                    ClearNamedNodes();
                    return false;
                }
                for (UInt32 i = 0; i < MIN_NUMBER_OF_NODES; i++)
                {
                    if (mNodes[i] == 0)
                    {
                        if (mNodeIds[i].IsEmpty())
                        {
                            MURL_ERROR("Node %d is empty", i);
                            ClearNamedNodes();
                            return false;
                        }
                    }
                }
                
                GenericNodeTarget<ObjectType>::SetInitialized(true);
                GenericNodeTarget<ObjectType>::SetModified(false);
                return true;
            }
            
            virtual Bool DeInit(IDeInitTracker* tracker)
            {
                if (!GenericNodeTarget<ObjectType>::IsInitialized())
                {
                    return true;
                }

                ClearNamedNodes();

                GenericNodeTarget<ObjectType>::SetInitialized(false);
                GenericNodeTarget<ObjectType>::SetModified(false);
                return true;
            }
            
            virtual UInt32 GetMinNumberOfNodes() const
            {
                return MIN_NUMBER_OF_NODES;
            }
            
            virtual UInt32 GetMaxNumberOfNodes() const
            {
                return MAX_NUMBER_OF_NODES;
            }
            
            virtual Bool SetNumberOfNodes(UInt32 numberOfNodes)
            {
                if (numberOfNodes == mNodes.GetCount())
                {
                    return true;
                }
                
                mNodeIds.SetCount(numberOfNodes);
                mNodes.SetCount(numberOfNodes, 0);
                
                GenericNodeTarget<ObjectType>::SetModified(true);
                return true;
            }
            
            virtual UInt32 GetNumberOfNodes() const
            {
                return mNodes.GetCount();
            }
            
            virtual Bool SetNodeId(const String& nodeId, UInt32 index)
            {
                if (index >= mNodes.GetCount())
                {
                    return false;
                }
                if (mNodeIds[index] == nodeId)
                {
                    return true;
                }
                
                mNodeIds[index] = nodeId;
                mNodes[index] = 0;
                GenericNodeTarget<ObjectType>::SetModified(true);
                
                return true;
            }
            
            virtual const String& GetNodeId(UInt32 index) const
            {
                if (index >= mNodeIds.GetCount())
                {
                    return Util::StaticEmptyString();
                }
                return mNodeIds[index];
            }
            
            virtual Bool SetNode(ObjectType* object, UInt32 index)
            {
                if (index >= mNodes.GetCount())
                {
                    return false;
                }
                if (mNodes[index] == object)
                {
                    return true;
                }
                
                mNodeIds[index].Clear();
                mNodes[index] = object;
                GenericNodeTarget<ObjectType>::SetModified(true);
                
                return true;
            }
            
            virtual const Array<ObjectType*>& GetResources() const
            {
                return mNodes;
            }
            
            virtual ObjectType* GetNode(UInt32 index) const
            {
                if (index >= mNodes.GetCount())
                {
                    return 0;
                }
                return mNodes[index];
            }

        public:
            Array<ObjectType*> mNodes;
            
        protected:
            void ClearNamedNodes()
            {
                UInt32 numNodes = Math::Min(mNodeIds.GetCount(), mNodes.GetCount());
                for (UInt32 i = 0; i < numNodes; i++)
                {
                    if (mNodeIds[i].IsEmpty())
                    {
                        continue;
                    }

                    INode* node = dynamic_cast<INode*>(mNodes[i]);
                    if (node != 0)
                    {
                        if (!node->RemoveReference())
                        {
                            MURL_ERROR("Failed to remove node reference %s", mNodeIds[i].Begin());
                        }
                    }
                    mNodes[i] = 0;
                }
            }

            StringArray mNodeIds;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_NODES, UInt32 MAX_NUMBER_OF_NODES, UInt32 RESERVED_NUMBER_OF_NODES>
        class NodeArrayPropertyBase : public TypedProperty<ObjectType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                ObjectType* mValue[MAX_NUMBER_OF_NODES];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit NodeArrayPropertyBase(const Value& v)
            : mValue(v.mValue)
            {
            }

            Bool DeserializeNodeIds(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeNodeIds(tracker);
            }
            Bool DeserializeNodeId(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeNodeId(tracker);
            }
            Bool DeserializeNodeId(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeNodeId(tracker, index);
            }

            NodeArrayTarget<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>* operator&()
            {
                return &mValue;
            }
            const NodeArrayTarget<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>* operator&() const
            {
                return &mValue;
            }

            NodeArrayTarget<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>& operator*()
            {
                return mValue;
            }
            const NodeArrayTarget<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>& operator*() const
            {
                return mValue;
            }

            NodeArrayTarget<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>* operator->()
            {
                return &mValue;
            }
            const NodeArrayTarget<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>* operator->() const
            {
                return &mValue;
            }

            NodeArrayTarget<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES> mValue;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_NODES, UInt32 MAX_NUMBER_OF_NODES, UInt32 RESERVED_NUMBER_OF_NODES, const typename NodeArrayPropertyBase<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>::GetValueFunction DEFAULT>
        class NodeArrayProperty : public NodeArrayPropertyBase<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>
        {
        public:
            explicit NodeArrayProperty()
            : NodeArrayPropertyBase<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>(DEFAULT())
            {
            }
            void Reset()
            {
                NodeArrayPropertyBase<ObjectType, MIN_NUMBER_OF_NODES, MAX_NUMBER_OF_NODES, RESERVED_NUMBER_OF_NODES>::mValue = DEFAULT().mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::IGenericNodeTarget<" + TypedProperty<ObjectType>::GetTypeName() + ">",
                    IEnums::PROPERTY_SEMANTIC_OBJECT,
                    1,
                    MIN_NUMBER_OF_NODES,
                    MAX_NUMBER_OF_NODES,
                    MIN_NUMBER_OF_NODES,
                    MAX_NUMBER_OF_NODES
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
        };
    }
}

#endif // __MURL_GRAPH_NODE_ARRAY_TARGET_H__

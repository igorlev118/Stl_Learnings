// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_NODE_TARGET_H__
#define __MURL_GRAPH_NODE_TARGET_H__

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
         * @interface NodeTarget
         * @brief The NodeTarget class.
         * This class implements an IGenericNodeTarget that can reference at most
         * one graph node.
         * The MIN_NUMBER_OF_NODES template parameter represents the minimum number
         * of referenced nodes that must be present for the Init() method to succeed. 
         * May be either 0 or 1.
         */
        template<class ObjectType, UInt32 MIN_NUMBER_OF_NODES>
        class NodeTarget : public GenericNodeTarget<ObjectType>
        {
        public:
            /**
             * @brief The default constructor.
             */
            NodeTarget()
            : mNode(0)
            , mNumberOfNodes(0)
            {
            }
            /**
             * @brief Constructor taking a single (optional) node.
             * @param node The node or null.
             */
            NodeTarget(ObjectType* node)
            : mNode(node)
            , mNumberOfNodes(node == 0 ? 0 : 1)
            {
            }

            virtual ~NodeTarget()
            {
            }

            /**
             * @brief Deserialize the single target node ID from a given tracker.
             * @param tracker The tracker to deserialize.
             * @return true if successful.
             */
            Bool DeserializeNodeId(IDeserializeAttributeTracker* tracker)
            {
                tracker->GetAttributeValue(mNodeId);
                return true;
            }
            
            virtual Bool Init(IInitTracker* tracker)
            {
                if (GenericNodeTarget<ObjectType>::IsInitialized())
                {
                    return true;
                }
                
                if (MIN_NUMBER_OF_NODES > 1)
                {
                    MURL_ERROR("Minimum number of targets cannot be greater than 1");
                    return false;
                }
                
                if (!mNodeId.IsEmpty())
                {
                    if (mNode != 0)
                    {
                        MURL_ERROR("Cannot specify both node ID \"%s\" and node instance", mNodeId.Begin());
                        return false;
                    }
                    
                    INamespace* nmspc = tracker->GetCurrentNamespace();
                    if (nmspc == 0)
                    {
                        MURL_ERROR("No current namespace");
                        return false;
                    }

                    IEnums::ResultAction actionNotFound = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_NOT_FOUND_ERROR);
                    IEnums::ResultAction actionWrongInterface = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_WRONG_INTERFACE_ERROR);

                    mNode = 0;

                    INode* node = nmspc->FindNode(mNodeId);
                    if (node == 0)
                    {
                        if (actionNotFound != IEnums::RESULT_ACTION_IGNORE)
                        {
                            MURL_ERROR("Failed to get node \"%s\"", mNodeId.Begin());
                            if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                            {
                                return false;
                            }
                        }
                    }
                    else
                    {
                        node = node->GetNodeInterface();

                        mNode = dynamic_cast<ObjectType*>(node);
                        if (mNode == 0)
                        {
                            if (actionWrongInterface != IEnums::RESULT_ACTION_IGNORE)
                            {
                                MURL_ERROR("Failed to get interface \"%s\"", mNodeId.Begin());
                                if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                                {
                                    return false;
                                }
                            }
                        }
                        else
                        {
                            node->AddReference();
                        }
                    }

                    mNumberOfNodes = 1;
                }
                
                if ((MIN_NUMBER_OF_NODES != 0) && (mNumberOfNodes == 0))
                {
                    MURL_ERROR("Need exactly 1 node");
                    return false;
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
                
                if (!mNodeId.IsEmpty())
                {
                    INode* node = dynamic_cast<INode*>(mNode);
                    if (node != 0)
                    {
                        if (!node->RemoveReference())
                        {
                            MURL_ERROR("Failed to remove node reference \"%s\"", mNodeId.Begin());
                            return false;
                        }
                    }
                    mNode = 0;
                    mNumberOfNodes = 0;
                }
                
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
                return 1;
            }
            
            virtual Bool SetNumberOfNodes(UInt32 numberOfNodes)
            {
                if (numberOfNodes == mNumberOfNodes)
                {
                    return true;
                }
                
                if (numberOfNodes == 0)
                {
                    mNodeId.Clear();
                    mNode = 0;
                }
                else if (numberOfNodes != 1)
                {
                    return false;
                }
                
                mNumberOfNodes = numberOfNodes;
                GenericNodeTarget<ObjectType>::SetModified(true);
                
                return true;
            }
            
            virtual UInt32 GetNumberOfNodes() const
            {
                return mNumberOfNodes;
            }
            
            virtual Bool SetNodeId(const String& nodeId, UInt32 index)
            {
                if (index >= mNumberOfNodes)
                {
                    return false;
                }
                if (mNodeId == nodeId)
                {
                    return true;
                }
                
                mNodeId = nodeId;
                mNode = 0;
                GenericNodeTarget<ObjectType>::SetModified(true);
                
                return true;
            }
            
            /**
             * @brief Get the single node ID.
             * @return The node ID, or an empty string if no node is referenced.
             */
            const String& GetNodeId() const
            {
                return mNodeId;
            }
            
            virtual const String& GetNodeId(UInt32 index) const
            {
                if (index > 0)
                {
                    return Util::StaticEmptyString();
                }
                return mNodeId;
            }
            
            virtual Bool SetNode(ObjectType* object, UInt32 index)
            {
                if (index >= mNumberOfNodes)
                {
                    return false;
                }
                if (mNode == object)
                {
                    return true;
                }
                mNodeId.Clear();
                mNode = object;
                GenericNodeTarget<ObjectType>::SetModified(true);
                return true;
            }
            
            /**
             * @brief Get the single node.
             * @return The node, or null if none is referenced.
             */
            ObjectType* GetNode() const
            {
                return mNode;
            }
            
            virtual ObjectType* GetNode(UInt32 index) const
            {
                if (index > 0)
                {
                    return 0;
                }
                return mNode;
            }
            
        protected:
            String mNodeId;
            ObjectType* mNode;

            UInt32 mNumberOfNodes;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_NODES>
        class NodePropertyBase : public TypedProperty<ObjectType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                ObjectType* mValue;
            };

            typedef const Value& (*GetValueFunction)();
            
        public:
            explicit NodePropertyBase(const Value& v)
            : mValue(v.mValue)
            {
            }

            Bool DeserializeNodeId(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeNodeId(tracker);
            }

            NodeTarget<ObjectType, MIN_NUMBER_OF_NODES>* operator&()
            {
                return &mValue;
            }
            const NodeTarget<ObjectType, MIN_NUMBER_OF_NODES>* operator&() const
            {
                return &mValue;
            }

            NodeTarget<ObjectType, MIN_NUMBER_OF_NODES>& operator*()
            {
                return mValue;
            }
            const NodeTarget<ObjectType, MIN_NUMBER_OF_NODES>& operator*() const
            {
                return mValue;
            }

            NodeTarget<ObjectType, MIN_NUMBER_OF_NODES>* operator->()
            {
                return &mValue;
            }
            const NodeTarget<ObjectType, MIN_NUMBER_OF_NODES>* operator->() const
            {
                return &mValue;
            }

            NodeTarget<ObjectType, MIN_NUMBER_OF_NODES> mValue;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_NODES, const typename NodePropertyBase<ObjectType, MIN_NUMBER_OF_NODES>::GetValueFunction DEFAULT>
        class NodeProperty : public NodePropertyBase<ObjectType, MIN_NUMBER_OF_NODES>
        {
        public:
            explicit NodeProperty()
            : NodePropertyBase<ObjectType, MIN_NUMBER_OF_NODES>(DEFAULT())
            {
            }
            void Reset()
            {
                NodePropertyBase<ObjectType, MIN_NUMBER_OF_NODES>::mValue = DEFAULT().mValue;
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
                    1,
                    MIN_NUMBER_OF_NODES,
                    1
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

#endif // __MURL_GRAPH_NODE_TARGET_H__

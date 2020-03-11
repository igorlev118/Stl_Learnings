// Copyright 2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_REPLICATION_H__
#define __MURL_LOGIC_GRAPH_REPLICATION_H__

#include "murl_logic_base_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief Base class for a single replication required by Logic::GraphInstanceObjects.
         */
        class GraphReplication : public BaseStepable
        {
        public:
            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param root The graph root node.
             * @param replicationIdPath The full path to the replication's graph node.
             * @param index The index of the replication.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, const Graph::IRoot* root,
                              const String& replicationIdPath, SInt32 index)
            {
                return Init(nodeObserver, root->FindNode(replicationIdPath), index);
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param replicationNode The replication's graph node.
             * @param index The index of the replication.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, Graph::INode* replicationNode,
                              SInt32 index) = 0;

            /**
             * @brief Deinitialize the object.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Set the obtained state.
             * @param isObtained The obtained state.
             */
            virtual void SetObtained(Bool isObtained) = 0;

        protected:
            virtual ~GraphReplication() {}
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_REPLICATION_H__

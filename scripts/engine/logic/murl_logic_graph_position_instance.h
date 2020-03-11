// Copyright 2011-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_POSITION_INSTANCE_H__
#define __MURL_LOGIC_GRAPH_POSITION_INSTANCE_H__

#include "murl_logic_graph_replication.h"
#include "murl_logic_graph_position_object.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief Class controlling a position sub tree for GraphInstanceObjects usage.
         *
         *  MyLogic.h
         *  @code
         *  #include "murl_logic_graph_instance_objects.h"
         *  #include "murl_logic_graph_position_instance.h"
         *  ...
         *  Logic::GraphInstanceObjects<Logic::GraphPositionInstance> mMyInstances;
         *  @endcode
         *
         *  MyLogic.cpp
         *  @code
         *  Bool App::MyLogic::OnInit(const Logic::IState* state)
         *  {
         *      const Graph::IRoot* root = state->GetGraphRoot();
         *      if (!mMyInstances.Init(root, "/MY_LOCATION", "/MY_INSTANCE_NODE", "/MY_INSTANCE"))
         *      {
         *          return false;
         *      }
         *      // other stuff
         *      return true;
         *  }
         *  Bool App::MyLogic::OnDeInit(const Logic::IState* state)
         *  {
         *      Bool ret = true;
         *      //  other stuff
         *      if (!mMyInstances.DeInit())
         *      {
         *          ret = false;
         *      }
         *      return ret;
         *  }
         *  @endcode
         *
         *  MyGraph.xml
         *  @code
         *  <Namespace id="MY_LOCATION">
         *    <Instance id="MY_INSTANCE_NODE" graphResourceId="MyInstanceXml" replications="10"
         *  </Namespace>
         *  @endcode
         *
         *  MyInstance.xml
         *  @code
         *  <Graph>
         *    <Namespace id="MY_INSTANCE{replication}" activeAndVisible="no">
         *      <Transform id="position">
         *        <!-- my nodes -->
         *      </Transform>
         *    </Namespace>
         *  </Graph>
         *  @endcode
         *
         * \n Alternatively a replication with anonymous namespace can be accessed as follows.
         *  @code
         *  Bool App::MyLogic::OnInit(const Logic::IState* state)
         *  {
         *      if (!mMyInstances.Init(root->GetRootNamespace(), "/MY_LOCATION/MY_INSTANCE_NODE"))
         *      {
         *          return false;
         *      }
         *      // other stuff
         *      return true;
         *  }
         *  @endcode
         *
         *  MyInstance.xml
         *  @code
         *  <Graph>
         *    <Namespace activeAndVisible="no">
         *      <Transform id="position">
         *        <!-- my nodes -->
         *      </Transform>
         *    </Namespace>
         *  </Graph>
         *  @endcode
         */
        class GraphPositionInstance : public GraphReplication, public GraphPositionObject
        {
        public:
            /**
             * @brief The default constructor.
             * @param baseDepth The base depth order.
             */
            GraphPositionInstance(SInt32 baseDepth = 0)
            : GraphPositionObject(baseDepth)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~GraphPositionInstance()
            {
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param root The graph root node.
             * @param replicationIdPath The full path to the replication's graph namespace node.
             * @param baseDepth The base depth order.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, const Graph::IRoot* root,
                              const String& replicationIdPath, SInt32 baseDepth)
            {
                return Init(nodeObserver, root->FindNode(replicationIdPath), baseDepth);
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param replicationNode The replication's graph namespace node.
             * @param baseDepth The base depth order.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, Graph::INode* replicationNode, SInt32 baseDepth)
            {
                if (!nodeObserver->Add(mNamespaceNode.GetReference(replicationNode)))
                {
                    return false;
                }
                if (!GraphPositionObject::Init(nodeObserver, mNamespaceNode.GetNode(), "position", baseDepth))
                {
                    return false;
                }
                return true;
            }

            using GraphPositionObject::Init;

            /**
             * @brief Deinitialize the object.
             * @return true if successful.
             */
            virtual Bool DeInit()
            {
                Bool ret = true;
                if (!GraphPositionObject::DeInit())
                {
                    ret = false;
                }
                return ret;
            }

            /**
             * @brief Set the obtained state.
             * @param isObtained The obtained state.
             */
            virtual void SetObtained(Bool isObtained)
            {
                mNamespaceNode.SetActiveAndVisible(isObtained);
            }

        protected:
            /**
             * @brief Overwrite of the BaseStepable::OnReset() method.
             * Reset the graph position and depth to zero.
             */
            virtual void OnReset()
            {
                SetSortDepth(0);
                SetPosition(Vector(Vector::ZERO_POSITION));
            }

            NamespaceNode mNamespaceNode;
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_POSITION_INSTANCE_H__

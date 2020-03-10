// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_SOUND_INSTANCE_H__
#define __MURL_LOGIC_GRAPH_SOUND_INSTANCE_H__

#include "murl_logic_graph_replication.h"
#include "murl_logic_graph_sound_object.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief Class controlling a sound sub tree for GraphInstanceObjects usage.
         *
         *  MyLogic.h
         *  @code
         *  #include "murl_logic_graph_instance_objects.h"
         *  #include "murl_logic_graph_sound_instance.h"
         *  ...
         *  Logic::GraphInstanceObjects<Logic::GraphSoundInstance> mMyInstances;
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
         *      // other stuff
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
         *      <Timeline id="timeline">
         *        <AudioSequence id="sequence"/>
         *      </Timeline>
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
         *      <Timeline id="timeline">
         *        <AudioSequence id="sequence"/>
         *      </Timeline>
         *    </Namespace>
         *  </Graph>
         *  @endcode
         */
        class GraphSoundInstance : public GraphReplication, public GraphSoundObject
        {
        public:
            /**
             * @brief The default constructor.
             * @param masterVolume The master volume in range [0.0 .. 1.0].
             */
            GraphSoundInstance(Real masterVolume = Real(1.0))
            : GraphSoundObject(masterVolume)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~GraphSoundInstance()
            {
            }

            /**
             * @brief Initialize the object.
             * @param nodeObserver The INodeObserver object.
             * @param root The graph root node.
             * @param replicationIdPath The full path to the replication's graph namespace node.
             * @param index The index of the instance.
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
             * @param replicationNode The replication's graph namespace node.
             * @param index The index of the instance.
             * @return true if successful.
             */
            virtual Bool Init(INodeObserver* nodeObserver, Graph::INode* replicationNode, SInt32 index)
            {
                if (!nodeObserver->Add(mNamespaceNode.GetReference(replicationNode)))
                {
                    return false;
                }
                if (!GraphSoundObject::Init(nodeObserver, mNamespaceNode.GetNode(), "timeline", "sequence", index))
                {
                    return false;
                }
                return true;
            }

            using GraphSoundObject::Init;

            /**
             * @brief Deinitialize the object.
             * @return true if successful.
             */
            virtual Bool DeInit()
            {
                Bool ret = true;
                if (!GraphSoundObject::DeInit())
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
                if (!isObtained)
                {
                    StopPlaying();
                }
                mNamespaceNode.SetActiveAndVisible(isObtained);
            }

        protected:
            /**
             * @brief Overwrite of the BaseStepable::OnReset() method.
             * Reset the master volume to 1.0 and stop playing.
             */
            virtual void OnReset()
            {
                SetMasterVolume(Real(1.0));
                StopPlaying();
            }

            NamespaceNode mNamespaceNode;
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_SOUND_INSTANCE_H__

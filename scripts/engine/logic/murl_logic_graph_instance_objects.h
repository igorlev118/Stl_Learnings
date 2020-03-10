// Copyright 2011-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_INSTANCE_OBJECTS_H__
#define __MURL_LOGIC_GRAPH_INSTANCE_OBJECTS_H__

#include "murl_logic_graph_replication.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief Template class controlling multiple replications created by XML &lt;Instance&gt; node.
         *  A InstanceObjectType class must derive from the Logic::GraphReplication base class.
         *  See class Logic::GraphPositionInstance or Logic::GraphSoundInstance for example.
         */
        template<class InstanceObjectType>
        class GraphInstanceObjects : public BaseStepable
        {
        public:
            /**
             * @brief The default constructor.
             */
            GraphInstanceObjects()
            : mNodeObserver(StaticFactory::CreateNodeObserver())
            , mNumObtained(0)
            , mMaxObtained(0)
            {
            }

            /**
             * @brief Set the node observer.
             * @param nodeObserver The node observer.
             * @return true if successful, false if the internal node observer is already in use.
             */
            Bool SetNodeObserver(INodeObserverPtr nodeObserver)
            {
                if (mNodeObserver->GetNumberOfNodes() == 0)
                {
                    mNodeObserver = nodeObserver;
                    return true;
                }
                return false;
            }

            /**
             * @brief The destructor.
             */
            virtual ~GraphInstanceObjects()
            {
                if (mContainer.GetCount() != 0)
                {
                    MURL_ERROR("DeInit() missing!");
                }
            }

            /**
             * @brief Initialize the object.
             * Create and initialize InstanceObjectType classes for each of the Graph::IInstance replications.
             * @param root The graph root node.
             * @param pathName The full path to the Graph::IInstance excluding the replication name.
             * @param instanceName The instance name excluding the path.
             * @param replicationName The prefix of the {replication} name excluding the path.
             * @param postfixName An optional postfix of the {replication} name excluding the path.
             * @return true if successful.
             */
            virtual Bool Init(const Graph::IRoot* root, const String& pathName, const String& instanceName,
                              const String& replicationName, const String& postfixName = String())
            {
                if (IsInitialized())
                {
                    return true;
                }
                if (root == 0)
                {
                    return false;
                }

                if (!mNodeObserver->Add(mInstanceNode.GetReference(root, pathName + instanceName)))
                {
                    return false;
                }

                UInt32 nrOfChildren = mInstanceNode->GetNumberOfReplications();
                mContainer.SetCount(nrOfChildren);
                String nodePath = pathName + replicationName;
                for (UInt32 i = 0; i < nrOfChildren; i++)
                {
                    String replicationIdPath = nodePath + Util::UInt32ToString(i) + postfixName;
                    if (!mContainer[i].GetReplication().Init(mNodeObserver.Get(), root, replicationIdPath, i))
                    {
                        return false;
                    }
                }

                if (!mNodeObserver->AreValid())
                {
                    return false;
                }
                return true;
            }

            /**
             * @brief Initialize the object.
             * Create and initialize InstanceObjectType classes for each of the Graph::IInstance replications.
             * @param namespaceNode The graph namespace node.
             * @param instanceNodeIdPath The instance name with optional path.
             * @return true if successful.
             */
            virtual Bool Init(Graph::INamespace* namespaceNode, const String& instanceNodeIdPath)
            {
                if (IsInitialized())
                {
                    return true;
                }
                if (!mNodeObserver->Add(mInstanceNode.GetReference(namespaceNode, instanceNodeIdPath)))
                {
                    return false;
                }

                UInt32 nrOfChildren = mInstanceNode->GetNumberOfReplications();
                mContainer.SetCount(nrOfChildren);
                for (UInt32 i = 0; i < nrOfChildren; i++)
                {
                    if (!mContainer[i].GetReplication().Init(mNodeObserver.Get(), mInstanceNode->GetReplicationNode(i), i))
                    {
                        return false;
                    }
                }

                if (!mNodeObserver->AreValid())
                {
                    return false;
                }
                return true;
            }

            /**
             * @brief Initialize the object.
             * Create and initialize InstanceObjectType classes for each of the Graph::IInstance replications.
             * @param namespaceNode The logic namespace node.
             * @param instanceNodeIdPath The instance name with optional path.
             * @return true if successful.
             */
            virtual Bool Init(Logic::NamespaceNode namespaceNode, const String& instanceNodeIdPath)
            {
                return Init(namespaceNode.GetNode(), instanceNodeIdPath);
            }

            /**
             * @brief Deinitialize the object.
             * Deinitialize all InstanceObjectType class instances.
             * @return true if successful.
             */
            virtual Bool DeInit()
            {
                if (!IsInitialized())
                {
                    return true;
                }
                Bool ret = true;
                for (UInt32 i = 0; i < mContainer.GetCount(); i++)
                {
                    if (!mContainer[i].GetReplication().DeInit())
                    {
                        ret = false;
                    }
                }

                if (!mNodeObserver->RemoveAll())
                {
                    ret = false;
                }

                mContainer.Empty();
                mNumObtained = 0;
                mMaxObtained = 0;

                return ret;
            }

            /**
             * Check if the object is initialized successful.
             * @return true if initialized successful.
             */
            virtual Bool IsInitialized() const
            {
                return mInstanceNode.IsValid();
            }

            /**
             * @brief Get the interface of the graph instance node.
             * @return A pointer to the graph instance interface or null.
             */
            virtual Graph::IInstance* GetInstanceNode() const
            {
                return mInstanceNode.GetNode();
            }

            /**
             * @brief Obtain a single InstanceObjectType object.
             * @return A pointer to the InstanceObjectType object or null.
             */
            virtual InstanceObjectType* Obtain()
            {
                UInt32 i = 0;
                if (mNumObtained == mMaxObtained)
                {
                    i = mMaxObtained;
                }
                for (; i < mContainer.GetCount(); i++)
                {
                    if (!mContainer[i].IsObtained())
                    {
                        SetObtained(i, true);
                        return &mContainer[i].GetInstance();
                    }
                }
                return 0;
            }

            /**
             * @brief Obtain all InstanceObjectType object.
             */
            virtual void ObtainAll()
            {
                for (UInt32 i = 0; i < mContainer.GetCount(); i++)
                {
                    mContainer[i].ApplyObtained(true);
                }
                mNumObtained = mContainer.GetCount();
                mMaxObtained = mNumObtained;
            }

            /**
             * @brief Release a single InstanceObjectType object.
             * @param object A pointer to the InstanceObjectType.
             * @return true if successful.
             */
            virtual Bool Release(InstanceObjectType* object)
            {
                if (object != 0)
                {
                    for (UInt32 i = 0; i < mContainer.GetCount(); i++)
                    {
                        if (&mContainer[i].GetInstance() == object)
                        {
                            SetObtained(i, false);
                            return true;
                        }
                    }
                }
                return false;
            }

            /**
             * @brief Release all InstanceObjectType object.
             */
            virtual void ReleaseAll()
            {
                for (UInt32 i = 0; i < mContainer.GetCount(); i++)
                {
                    mContainer[i].ApplyObtained(false);
                }
                mNumObtained = 0;
                mMaxObtained = 0;
            }

            /**
             * @brief Set the obtained status of an InstanceObjectType object.
             * A valid index is [0 .. GetNumberOfInstances() - 1].
             * @param index The zero-based index of the object.
             * @param isObtained The obtained state.
             */
            void SetObtained(UInt32 index, Bool isObtained)
            {
                if (index < mContainer.GetCount())
                {
                    if (mContainer[index].ApplyObtained(isObtained))
                    {
                        if (isObtained)
                        {
                            mNumObtained++;
                            if (mMaxObtained < (index + 1))
                            {
                                mMaxObtained = (index + 1);
                            }
                        }
                        else
                        {
                            mNumObtained--;
                            if (mNumObtained > 0)
                            {
                                for (SInt32 k = mMaxObtained - 1; k >= 0; k--)
                                {
                                    if (mContainer[k].IsObtained())
                                    {
                                        mMaxObtained = k + 1;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                mMaxObtained = 0;
                            }
                        }
                    }
                }
            }

            /**
             * @brief Get the highest obtained instance index.
             * This is an effective approach for iterating through all obtained instances.
             *  @code
             *  for (UInt32 i = 0; i < mMyInstances.GetMaxObtained(); i++)
             *  {
             *      MyInstanceType* instance = mMyInstances.GetObtainedInstance(i);
             *      if (instance != 0)
             *      {
             *          instance->DoSomething();
             *      }
             *  }
             *  @endcode
             * @return The highest obtained instance index.
             */
            UInt32 GetMaxObtained() const
            {
                return mMaxObtained;
            }

            /**
             * @brief Get the number of obtained instances.
             * @return The number of obtained instances.
             */
            UInt32 GetNumberOfObtained() const
            {
                return mNumObtained;
            }

            /**
             * @brief Get the number of non-obtained instances.
             * @return The number of non-obtained instances.
             */
            UInt32 GetNumberOfRemaining() const
            {
                return mContainer.GetCount() - mNumObtained;
            }

            /**
             * @brief Get the number of instances.
             * @return The number of instances.
             */
            UInt32 GetNumberOfInstances() const
            {
                return mContainer.GetCount();
            }

            /**
             * @brief Get the const InstanceObjectType object by index.
             * A valid index is [0 .. GetNumberOfInstances() - 1].
             * @param index The zero-based index of the object.
             * @return A const pointer to the InstanceObjectType object or null.
             */
            const InstanceObjectType* GetInstance(UInt32 index) const
            {
                if (index < mContainer.GetCount())
                {
                    return &mContainer[index].GetInstance();
                }
                return 0;
            }

            /**
             * @brief Get the const InstanceObjectType object by index if obtained.
             * A valid index is [0 .. GetNumberOfInstances() - 1].
             * @param index The zero-based index of the object.
             * @return A const pointer to the InstanceObjectType object
             *  or null if the object is not obtained.
             */
            const InstanceObjectType* GetObtainedInstance(UInt32 index) const
            {
                if (index < mContainer.GetCount())
                {
                    if (mContainer[index].IsObtained())
                    {
                        return &mContainer[index].GetInstance();
                    }
                }
                return 0;
            }

            /**
             * @brief Get the InstanceObjectType object by index.
             * A valid index is [0 .. GetNumberOfInstances() - 1].
             * @param index The zero-based index of the object.
             * @return A pointer to the InstanceObjectType object or null.
             */
            InstanceObjectType* GetInstance(UInt32 index)
            {
                if (index < mContainer.GetCount())
                {
                    return &mContainer[index].GetInstance();
                }
                return 0;
            }

            /**
             * @brief Get the InstanceObjectType object by index if obtained.
             * A valid index is [0 .. GetNumberOfInstances() - 1].
             * @param index The zero-based index of the object.
             * @return A pointer to the InstanceObjectType object
             *  or null if the object is not obtained.
             */
            InstanceObjectType* GetObtainedInstance(UInt32 index)
            {
                if (index < mContainer.GetCount())
                {
                    if (mContainer[index].IsObtained())
                    {
                        return &mContainer[index].GetInstance();
                    }
                }
                return 0;
            }

            /**
             * @brief Check if a InstanceObjectType object is obtained.
             * A valid index is [0 .. GetNumberOfInstances() - 1].
             * @param index The zero-based index of the object.
             * @return true if obtained.
             */
            Bool IsObtained(UInt32 index) const
            {
                if (index < mContainer.GetCount())
                {
                    return mContainer[index].IsObtained();
                }
                return false;
            }

        protected:
            /**
             * @brief Overwrite of the BaseStepable::OnSetEnabled() method,
             * calls SetEnabled() to all obtained InstanceObjectType objects.
             * @param isEnabled true if enabled.
             */
            virtual void OnSetEnabled(Bool isEnabled)
            {
                for (UInt32 i = 0; i < mMaxObtained; i++)
                {
                    if (mContainer[i].IsObtained())
                    {
                        mContainer[i].GetStepable().SetEnabled(isEnabled);
                    }
                }
                mInstanceNode.SetActive(isEnabled);
            }

            /**
             * @brief Overwrite of the BaseStepable::OnReset() method,
             * calls Reset() to all obtained InstanceObjectType objects.
             */
            virtual void OnReset()
            {
                for (UInt32 i = 0; i < mMaxObtained; i++)
                {
                    if (mContainer[i].IsObtained())
                    {
                        mContainer[i].GetStepable().Reset();
                        mContainer[i].ApplyObtained(false);
                    }
                }
                mNumObtained = 0;
                mMaxObtained = 0;
            }

            /**
             * @brief Overwrite of the BaseStepable::OnProcessTick() method,
             * calls ProcessTick() to all obtained InstanceObjectType objects.
             * @param state The IState object.
             */
            virtual void OnProcessTick(const Logic::IState* state)
            {
                for (UInt32 i = 0; i < mMaxObtained; i++)
                {
                    if (mContainer[i].IsObtained())
                    {
                        mContainer[i].GetStepable().ProcessTick(state);
                    }
                }
            }
            /**
             * @brief Overwrite of the BaseStepable::OnFinishTick() method,
             * calls FinishTick() to all obtained InstanceObjectType objects.
             * @param state The IState object.
             */
            virtual void OnFinishTick(const Logic::IState* state)
            {
                for (UInt32 i = 0; i < mMaxObtained; i++)
                {
                    if (mContainer[i].IsObtained())
                    {
                        mContainer[i].GetStepable().FinishTick(state);
                    }
                }
            }

        protected:
            INodeObserverPtr mNodeObserver;
            InstanceNode mInstanceNode;

            class Container
            {
            public:
                Container()
                : mIsObtained(false)
                {
                }

                Bool IsObtained() const
                {
                    return mIsObtained;
                }

                IStepable& GetStepable()
                {
                    return mInstance;
                }

                GraphReplication& GetReplication()
                {
                    return mInstance;
                }

                InstanceObjectType& GetInstance()
                {
                    return mInstance;
                }
                const InstanceObjectType& GetInstance() const
                {
                    return mInstance;
                }

                Bool ApplyObtained(Bool isObtained)
                {
                    if (mIsObtained != isObtained)
                    {
                        GetReplication().SetObtained(isObtained);
                        mIsObtained = isObtained;
                        return true;
                    }
                    return false;
                }

            protected:
                Bool mIsObtained;
                InstanceObjectType mInstance;
            };
            ObjectArray<Container> mContainer;

            UInt32 mNumObtained;
            UInt32 mMaxObtained;
        };
    }
}

#endif  // __MURL_LOGIC_GRAPH_INSTANCE_OBJECTS_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_LOGIC_STATE_MACHINE_H__
#define __MURL_LOGIC_STATE_MACHINE_H__

#include "murl_logic_base_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief A template class to create a BaseStepable object with
         *  simple statemachine capabilities.
         * The statemachine can register any number of states,
         * for each state a class method call can be registered for:
         *  - OnEnterTick the state
         *  - OnProcessTick the state
         *  - OnLeaveTick the state
         *  - OnFinishTick the state
         *
         * Usage e.g. my_processor.h:
         * @code
         *  #ifndef __MY_PROCESSOR_H__
         *  #define __MY_PROCESSOR_H__
         *
         *  #include "murl_app_types.h"
         *  #include "murl_logic_base_processor.h"
         *
         *  namespace Murl
         *  {
         *      namespace App
         *      {
         *          class MyProcessor : public Logic::BaseProcessor
         *          {
         *          public:
         *              MyProcessor(Logic::IFactory* factory);
         *
         *          protected:
         *              virtual Bool OnInit(const Logic::IState* state);
         *
         *              enum States
         *              {
         *                  STATE_IDLE = 0,
         *                  STATE_PLAYING,
         *                  STATE_PAUSED
         *              };
         *
         *              Logic::EnumStateMachine<States>::Type mStateMachine;
         *
         *              void OnEnterPlaying(const Logic::IState* logicState);
         *              void OnProcessPlaying(const Logic::IState* logicState);
         *              void OnLeavePlaying(const Logic::IState* logicState);
         *
         *              void OnEnterPaused(const Logic::IState* logicState);
         *              void OnProcessPaused(const Logic::IState* logicState);
         *              void OnLeavePaused(const Logic::IState* logicState);
         *          };
         *      }
         *  }
         *  #endif // __MY_PROCESSOR_H__
         * @endcode
         * and e.g. my_processor.cpp:
         * @code
         *  #include "my_processor.h"
         *
         *  using namespace Murl;
         *
         *  App::MyProcessor::MyProcessor(Logic::IFactory* factory)
         *  : BaseProcessor(factory)
         *  {
         *  }
         *
         *  Bool App::MyProcessor::OnInit(const Logic::IState* state)
         *  {
         *      mStateMachine.Register<MyProcessor>(STATE_PLAYING, this, &MyProcessor::OnProcessPlaying,
         *                                          &MyProcessor::OnEnterPlaying, &MyProcessor::OnLeavePlaying);
         *      mStateMachine.Register<MyProcessor>(STATE_PAUSED, this, &MyProcessor::OnProcessPaused,
         *                                          &MyProcessor::OnEnterPaused, &MyProcessor::OnLeavePaused);
         *      AddStepable(mStateMachine);
         *      return true;
         *  }
         *
         *  void App::MyProcessor::OnEnterPlaying(const Logic::IState* logicState)
         *  {
         *      if (mStateMachine.GetPreviousState() == STATE_PAUSED)
         *      {
         *          // State changed from paused to playing.
         *      }
         *  }
         *  void App::MyProcessor::OnProcessPlaying(const Logic::IState* logicState)
         *  {
         *  }
         *  void App::MyProcessor::OnLeavePlaying(const Logic::IState* logicState)
         *  {
         *      if (mStateMachine.GetNextState() == STATE_PAUSED)
         *      {
         *          // State changed from playing to paused.
         *      }
         *  }
         *
         *  void App::MyProcessor::OnEnterPaused(const Logic::IState* logicState)
         *  {
         *  }
         *  void App::MyProcessor::OnProcessPaused(const Logic::IState* logicState)
         *  {
         *  }
         *  void App::MyProcessor::OnLeavePaused(const Logic::IState* logicState)
         *  {
         *  }
         * @endcode
         *
         * To change the state simply call:
         * @code
         *  mStateMachine.SetNextState(STATE_PLAYING);
         * @endcode
         * This execute at the next logic tick:
         *  - OnLeaveTick of the current state and OnEnterTick of the next state.
         *  - All following logic ticks execute OnProcessTick / OnFinishTick of the (new) current state.
         *
         * If OnEnterTick is null OnProcessTick is called instead.
         *
         * @tparam StateType The data type of the state.
         * @tparam HashFunc The hash function of the state type.
         */
        template<class StateType, class HashFunc = StdHash<StateType> >
        class StateMachine : public BaseStepable
        {
        protected:
            template<class ObjectType> class StateMethods;

        public:
            /** @brief The template state parameter value type. */
            typedef StateType ValueType;

            /**
             * @brief The default constructor.
             */
            StateMachine()
            : mCurrentState()
            , mPrevState()
            , mNextState()
            , mIsNextState(false)
            , mIsReset(false)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~StateMachine()
            {
            }

            /**
             * @brief Register a state and the corresponding method calls.
             * @tparam ObjectType The type of the class to call.
             * @param state The state to register.
             * @param objectInstance The instance of the object to call.
             * @param onProcessTick The method to call on process or null for no action.
             * @param onEnterTick The method to call on enter or null for no action.
             * @param onLeaveTick The method to call on leave or null for no action.
             * @param onFinishTick The method to call on finish or null for no action.
             * @return true if the state was successfuly registered,
             *  false if the state is already registered.
             */
            template<class ObjectType>
            Bool Register(const StateType& state, ObjectType* objectInstance,
                          typename StateMethods<ObjectType>::ObjectMethod onProcessTick,
                          typename StateMethods<ObjectType>::ObjectMethod onEnterTick = 0,
                          typename StateMethods<ObjectType>::ObjectMethod onLeaveTick = 0,
                          typename StateMethods<ObjectType>::ObjectMethod onFinishTick = 0)
            {
                if (mStateMap.Find(state) < 0)
                {
                    IStateMethods* methods = new StateMethods<ObjectType>(objectInstance, onProcessTick,
                                                                      onEnterTick, onLeaveTick, onFinishTick);
                    mStateMap.Add(state, methods);
                    return true;
                }
                return false;
            }

            /**
             * @brief Unregister a state and the corresponding method calls.
             * @param state The state to unregister.
             * @return true if the state was successfuly unregistered.
             */
            Bool Unregister(const StateType& state)
            {
                return mStateMap.RemoveKey(state) != 0;
            }

            /**
             * @brief Set the next state.
             * @param nextState The next state.
             */
            void SetNextState(const StateType& nextState)
            {
                mNextState = nextState;
                mIsNextState = true;
            }

            /**
             * @brief Check if the next state is set.
             * @return true if the next state is set.
             */
            Bool IsNextState() const
            {
                return mIsNextState;
            }

            /**
             * @brief Get the next state.
             * @return The next state.
             */
            const StateType& GetNextState() const
            {
                return mNextState;
            }

            /**
             * @brief Get the previous state.
             * @return The previous state.
             */
            const StateType& GetPreviousState() const
            {
                return mPrevState;
            }

            /**
             * @brief Get the current state.
             * @return The current state.
             */
            const StateType& GetCurrentState() const
            {
                return mCurrentState;
            }

        protected:  // BaseStepable

            /**
             * @brief Overwrite of the BaseStepable::OnReset() method.
             * Reset the states to the state's default constructor.
             */
            virtual void OnReset()
            {
                mCurrentState = StateType();
                mPrevState = StateType();
                mNextState = StateType();
                mIsNextState = false;
                mIsReset = true;
            }

            /**
             * @brief Overwrite of the BaseStepable::OnProcessTick() method.
             * Either execute OnProcessTick of the current state, or OnLeaveTick of the current
             * state and OnEnterTick of the next state, if the next state was set.
             * If OnEnterTick is null OnProcessTick is called instead.
             * @param state The IState object.
             */
            virtual void OnProcessTick(const IState* state)
            {
                Bool isNextState = mIsNextState;
                StateType nextState = StateType();
                if (isNextState)
                {
                    nextState = mNextState;
                    mIsNextState = false;
                }
                mIsReset = false;

                SInt32 currentIndex = mStateMap.Find(mCurrentState);
                if (currentIndex >= 0)
                {
                    if (isNextState)
                    {
                        mStateMap[currentIndex].OnLeaveTick(state);
                    }
                    else
                    {
                        mStateMap[currentIndex].OnProcessTick(state);
                    }
                }

                if (!mIsReset && isNextState)
                {
                    mPrevState = mCurrentState;
                    mCurrentState = nextState;
                    SInt32 nextIndex = mStateMap.Find(nextState);
                    if (nextIndex >= 0)
                    {
                        mStateMap[nextIndex].OnEnterOrProcessTick(state);
                    }
                }
            }

            /**
             * @brief Overwrite of the BaseStepable::OnFinishTick() method.
             * Execute OnFinishTick of the current state.
             * @param state The IState object.
             */
            virtual void OnFinishTick(const IState* state)
            {
                SInt32 currentIndex = mStateMap.Find(mCurrentState);
                if (currentIndex >= 0)
                {
                    mStateMap[currentIndex].OnFinishTick(state);
                }
            }

        protected:  // StateMachine

            class IStateMethods
            {
            public:
                virtual void OnProcessTick(const IState* logicState) const = 0;
                virtual void OnEnterTick(const IState* logicState) const = 0;
                virtual void OnEnterOrProcessTick(const IState* logicState) const = 0;
                virtual void OnLeaveTick(const IState* logicState) const = 0;
                virtual void OnFinishTick(const IState* logicState) const = 0;

                virtual ~IStateMethods() {}
            };

            template<class ObjectType>
            class StateMethods : public IStateMethods
            {
            public:
                typedef void (ObjectType::*ObjectMethod)(const IState* logicState);

                StateMethods(ObjectType* objectInstance, ObjectMethod onProcessTick,
                             ObjectMethod onEnterTick, ObjectMethod onLeaveTick, ObjectMethod onFinishTick)
                : mObject(objectInstance)
                , mOnProcessTick(onProcessTick)
                , mOnEnterTick(onEnterTick)
                , mOnLeaveTick(onLeaveTick)
                , mOnFinishTick(onFinishTick)
                {
                }

                virtual void OnProcessTick(const IState* logicState) const
                {
                    if ((mObject != 0) && (mOnProcessTick != 0))
                    {
                        (mObject->*mOnProcessTick)(logicState);
                    }
                }

                virtual void OnEnterTick(const IState* logicState) const
                {
                    if ((mObject != 0) && (mOnEnterTick != 0))
                    {
                        (mObject->*mOnEnterTick)(logicState);
                    }
                }

                virtual void OnEnterOrProcessTick(const IState* logicState) const
                {
                    if (mObject != 0)
                    {
                        if (mOnEnterTick != 0)
                        {
                            (mObject->*mOnEnterTick)(logicState);
                        }
                        else if (mOnProcessTick != 0)
                        {
                            (mObject->*mOnProcessTick)(logicState);
                        }
                    }
                }

                virtual void OnLeaveTick(const IState* logicState) const
                {
                    if ((mObject != 0) && (mOnLeaveTick != 0))
                    {
                        (mObject->*mOnLeaveTick)(logicState);
                    }
                }

                virtual void OnFinishTick(const IState* logicState) const
                {
                    if ((mObject != 0) && (mOnFinishTick != 0))
                    {
                        (mObject->*mOnFinishTick)(logicState);
                    }
                }

            protected:
                ObjectType* mObject;
                ObjectMethod mOnProcessTick;
                ObjectMethod mOnEnterTick;
                ObjectMethod mOnLeaveTick;
                ObjectMethod mOnFinishTick;
            };

            StateType mCurrentState;
            StateType mPrevState;
            StateType mNextState;
            Bool mIsNextState;
            Bool mIsReset;
            ObjectMap<StateType, IStateMethods, HashFunc> mStateMap;
        };

        /**
         * @addtogroup MurlLogicClasses
         * @{
         */
        /** Predefined StateMachine using an enumerated state data type.
         * Usage:
         * @code
         *  typedef EnumStateMachine<MyEnum>::Type MyEnumStateMachine;
         * @endcode
         */
        template<class EnumStateType>
        struct EnumStateMachine
        {
            typedef StdHash<UInt32> EnumHash;
            typedef StateMachine<EnumStateType, EnumHash> Type;
        };

        /** Predefined StateMachine using an integer state data type. */
        typedef StateMachine<SInt32> IntStateMachine;

        /** Predefined StateMachine using a string state data type. */
        typedef StateMachine<String> StringStateMachine;
        /** @} */
    }
}

#endif // __MURL_LOGIC_STATE_MACHINE_H__

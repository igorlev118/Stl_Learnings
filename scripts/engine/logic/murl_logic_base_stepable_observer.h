// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_BASE_STEPABLE_OBSERVER_H__
#define __MURL_LOGIC_BASE_STEPABLE_OBSERVER_H__

#include "murl_logic_i_stepable_observer.h"
#include "murl_logic_i_factory.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the IStepableObserver object.
         * A stepable observer is created at object instantiation.
         */
        class BaseStepableObserver : public NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             * Creates a IStepableObserver object.
             */
            BaseStepableObserver()
            : mStepableObserver(StaticFactory::CreateStepableObserver())
            {
            }

            /**
             * @brief The destructor.
             * Destroys the IStepableObserver object.
             */
            virtual ~BaseStepableObserver()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The IStepableObserver interface.
             */
            operator IStepableObserverPtr() const
            {
                return mStepableObserver;
            }

            /**
             * @brief Get the stepable observer interface.
             * @return The IStepableObserver interface.
             */
            IStepableObserverPtr GetStepableObserver() const
            {
                return mStepableObserver;
            }

        public: // IStepableObserver

            /**
             * @brief Forward to IStepableObserver::Add() method.
             * @param stepable The stepable object to add.
             * @return true if successful.
             */
            Bool Add(IStepablePtr stepable)
            {
                return mStepableObserver->Add(stepable);
            }
            /**
             * @brief Forward to IStepableObserver::Remove() method.
             * @param stepable The stepable object to remove.
             * @return true if successful.
             */
            Bool Remove(IStepablePtr stepable)
            {
                return mStepableObserver->Remove(stepable);
            }
            /**
             * @brief Forward to IStepableObserver::RemoveAt() method.
             * @param index The zero-based index of the stepable object to remove.
             * @return true if successful.
             */
            Bool RemoveAt(UInt32 index)
            {
                return mStepableObserver->RemoveAt(index);
            }

            /**
             * @brief Forward to IStepableObserver::GetNumberOfStepables() method.
             * @return The number of stepable objects.
             */
            UInt32 GetNumberOfStepables() const
            {
                return mStepableObserver->GetNumberOfStepables();
            }
            /**
             * @brief Forward to IStepableObserver::GetStepable() method.
             * @param index The zero-based index of the stepable object.
             * @return The stepable object or 0 if index is out of range.
             */
            IStepablePtr GetStepable(UInt32 index) const
            {
                return mStepableObserver->GetStepable(index);
            }

            /**
             * @brief Forward to IStepableObserver::SetEnabled() method.
             * @param isEnabled true for enable, false for disable.
             */
            void SetEnabled(Bool isEnabled)
            {
                return mStepableObserver->SetEnabled(isEnabled);
            }
            /**
             * @brief Forward to IStepableObserver::Reset() method.
             */
            void Reset()
            {
                return mStepableObserver->Reset();
            }

            /**
             * @brief Forward to IStepableObserver::ProcessTick() method.
             * @param state The IState object.
             */
            void ProcessTick(const Logic::IState* state) const
            {
                return mStepableObserver->ProcessTick(state);
            }
            /**
             * @brief Forward to IStepableObserver::FinishTick() method.
             * @param state The IState object.
             */
            void FinishTick(const Logic::IState* state) const
            {
                return mStepableObserver->FinishTick(state);
            }

            /**
             * @brief Forward to IStepableObserver::RemoveAll() method.
             */
            void RemoveAll()
            {
                mStepableObserver->RemoveAll();
            }

        protected:
            IStepableObserverPtr mStepableObserver;
        };
    }
}

#endif  // __MURL_LOGIC_BASE_STEPABLE_OBSERVER_H__

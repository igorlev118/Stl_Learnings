// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_STEPABLE_OBSERVER_H__
#define __MURL_LOGIC_I_STEPABLE_OBSERVER_H__

#include "murl_logic_i_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IStepableObserver
         * @brief The IStepableObserver interface.
         * The stepable observer notifies objects implementing the IStepable interface.
         * \n
         * The IProcessor object provides a ready to use stepable observer.
         */
        class IStepableObserver
        {
        public:
            /**
             * @brief Add a stepable object to the observer.
             * Adding a stepable twice is not allowed.
             * @param stepable The stepable object to add.
             * @return true if successful.
             */
            virtual Bool Add(IStepablePtr stepable) = 0;
            /**
             * @brief Remove a stepable object from the observer.
             * @param stepable The stepable object to remove.
             * @return true if successful.
             */
            virtual Bool Remove(IStepablePtr stepable) = 0;
            /**
             * @brief Remove a stepable object by index from the observer.
             * A valid index is [0 .. GetNumberOfStepables() - 1].
             * @param index The zero-based index of the stepable object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveAt(UInt32 index) = 0;
            /**
             * @brief Remove all stepable objects from the observer.
             */
            virtual void RemoveAll() = 0;

            /**
             * @brief Get the number of stepable objects in the observer.
             * @return The number of stepable objects.
             */
            virtual UInt32 GetNumberOfStepables() const = 0;
            /**
             * @brief Get a stepable object by index.
             * A valid index is [0 .. GetNumberOfStepables() - 1].
             * @param index The zero-based index of the stepable object.
             * @return The stepable object or 0 if index is out of range.
             */
            virtual IStepablePtr GetStepable(UInt32 index) const = 0;

            /**
             * @brief Notify IStepable::SetEnabled() to all observed objects.
             * @param isEnabled true for enable, false for disable.
             */
            virtual void SetEnabled(Bool isEnabled) = 0;
            /**
             * @brief Notify IStepable::Reset() to all observed objects.
             */
            virtual void Reset() = 0;
            /**
             * @brief Notify IStepable::ProcessTick() to all observed objects.
             * @param state The IState object.
             */
            virtual void ProcessTick(const Logic::IState* state) = 0;
            /**
             * @brief Notify IStepable::FinishTick() to all observed objects.
             * @param state The IState object.
             */
            virtual void FinishTick(const Logic::IState* state) = 0;

        protected:
            virtual ~IStepableObserver() {}
        };
    }
}

#endif // __MURL_LOGIC_I_STEPABLE_OBSERVER_H__

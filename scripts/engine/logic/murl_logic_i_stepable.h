// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_STEPABLE_H__
#define __MURL_LOGIC_I_STEPABLE_H__

#include "murl_logic_i_app_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IStepable
         * @brief The IStepable interface.
         * Objects implementing the IStepable interface can be registered to the IStepableObserver.
         * \n
         * The IProcessor object provides a ready to use stepable observer.
         */
        class IStepable
        {
        public:
            /**
             * @brief Set the stepable callback object.
             * @param appStepable The stepable callback object.
             * @return true if successful.
             */
            virtual Bool SetAppStepable(IAppStepablePtr appStepable) = 0;

            /**
             * @brief Set the Enable/Disable state of the object.
             * Execute the IAppStepable::OnSetEnabled() callback method
             * before setting the internal enabled state.
             *\n
             * The default enabled state is true.
             * @param isEnabled true for enable, false for disable.
             */
            virtual void SetEnabled(Bool isEnabled) = 0;
            /**
             * @brief Check if the object is enabled.
             * @return true if enabled.
             */
            virtual Bool IsEnabled() const = 0;

            /**
             * @brief Reset the object.
             * Execute the IAppStepable::OnReset() method.
             */
            virtual void Reset() = 0;

            /**
             * @brief Execute a logic tick.
             * Execute the IAppStepable::OnProcessTick() method if the enabled state is true.
             * @param state The IState object.
             */
            virtual void ProcessTick(const Logic::IState* state) = 0;
            /**
             * @brief Finish a logic tick.
             * Execute the IAppStepable::OnFinishTick() method if the enabled state is true.
             * @param state The IState object.
             */
            virtual void FinishTick(const Logic::IState* state) = 0;

        protected:
            virtual ~IStepable() {}
        };
    }
}

#endif // __MURL_LOGIC_I_STEPABLE_H__

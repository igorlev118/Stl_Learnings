// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_APP_STEPABLE_H__
#define __MURL_LOGIC_I_APP_STEPABLE_H__

#include "murl_logic_i_state.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicAppInterfaces
         * @interface IAppStepable
         * @brief The IAppStepable interface.
         * This interface is used by the IStepable object to callback the app.
         */
        class IAppStepable
        {
        public:
            /**
             * @brief Called by IStepable::SetEnabled().
             * This method is used to track the enabled state.
             * @param isEnabled true if enabled.
             */
            virtual void OnSetEnabled(Bool isEnabled) = 0;

            /**
             * @brief Called by IStepable::Reset().
             */
            virtual void OnReset() = 0;

            /**
             * @brief Called by IStepable::ProcessTick().
             * @param state The IState object.
             */
            virtual void OnProcessTick(const Logic::IState* state) = 0;
            /**
             * @brief Called by IStepable::FinishTick().
             * @param state The IState object.
             */
            virtual void OnFinishTick(const Logic::IState* state) = 0;

        protected:
            virtual ~IAppStepable() {}
        };
    }
}

#endif // __MURL_LOGIC_I_APP_STEPABLE_H__

// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_STEPABLE_H__
#define __MURL_LOGIC_STEPABLE_H__

#include "murl_logic_i_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief The IStepable interface implementation.
         */
        class Stepable : public IStepable
        {
        protected:
            Stepable();

        public:
            /**
             * @brief Create a stepable object.
             * @return The created stepable object, or null if failed.
             */
            static IStepablePtr Create();

            /**
             * The destructor.
             */
            virtual ~Stepable();

        public: // IStepable

            /**
             * @brief Implementation of IStepable::SetAppStepable() method.
             * @param appStepable The stepable callback object.
             * @return true if successful.
             */
            virtual Bool SetAppStepable(IAppStepablePtr appStepable);

            /**
             * @brief Implementation of IStepable::SetEnabled() method.
             * @param isEnabled true for enable, false for disable.
             */
            virtual void SetEnabled(Bool isEnabled);
            /**
             * @brief Implementation of IStepable::IsEnabled() method.
             * @return true if enabled.
             */
            virtual Bool IsEnabled() const;

            /**
             * @brief Implementation of IStepable::Reset() method.
             */
            virtual void Reset();

            /**
             * @brief Implementation of IStepable::ProcessTick() method.
             * @param state The IState object.
             */
            virtual void ProcessTick(const Logic::IState* state);

            /**
             * @brief Implementation of IStepable::FinishTick() method.
             * @param state The IState object.
             */
            virtual void FinishTick(const Logic::IState* state);

        protected:  // Stepable
            IAppStepablePtr mAppStepable;
            Bool mIsEnabled;
        };
    }
}

#endif // __MURL_LOGIC_STEPABLE_H__

// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_TIMEFRAME_H__
#define __MURL_LOGIC_TIMEFRAME_H__

#include "murl_logic_i_timeframe.h"
#include "murl_logic_stepable.h"
#include "murl_weak_pointer.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief The ITimeframe interface implementation.
         */
        class Timeframe : public ITimeframe, public Stepable
        {
        protected:
            Timeframe();

        public:
            /**
             * @brief Create a timeframe object.
             * @return The created timeframe object, or null if failed.
             */
            static ITimeframePtr Create();

            /**
             * The destructor.
             */
            virtual ~Timeframe();

        public:  // IStepable

            /**
             * @brief Implementation of IStepable::ProcessTick() method.
             * @param state The IState object.
             */
            virtual void ProcessTick(const Logic::IState* state);

        public:  // ITimeframe

            /**
             * @brief Implementation of Timeframe::GetStepable() method.
             * @return The stepable interface shared pointer.
             */
            virtual IStepablePtr GetStepable();

            /**
             * @brief Implementation of Timeframe::Reset() method.
             */
            virtual void Reset();
            
            /**
             * @brief Implementation of Timeframe::Start() method.
             */
            virtual void Start();

            /**
             * @brief Implementation of Timeframe::Start(Real endTime) method.
             * @param endTime The time interval in seconds.
             */
            virtual void Start(Real endTime);

            /**
             * @brief Implementation of Timeframe::SetCurrentTime() method.
             * @param time The current time in seconds.
             * @return true if successful.
             */
            virtual Bool SetCurrentTime(Real time);

            /**
             * @brief Implementation of Timeframe::Finish() method.
             * @return true if successful.
             */
            virtual Bool Finish();

            /**
             * @brief Implementation of Timeframe::IsRunning() method.
             * @return true if running.
             */
            virtual Bool IsRunning() const;

            /**
             * @brief Implementation of Timeframe::WasStarted() method.
             * @return true if started.
             */
            virtual Bool WasStarted() const;

            /**
             * @brief Implementation of Timeframe::WasRunning() method.
             * @return true if finished.
             */
            virtual Bool WasRunning() const;

            /**
             * @brief Implementation of Timeframe::IsOrWasRunning() method.
             * @return true if IsRunning() or WasRunning() is true.
             */
            virtual Bool IsOrWasRunning() const;

            /**
             * @brief Implementation of Timeframe::HasPassedTime() method.
             * @param time The time to check in seconds.
             * @return true if the current time has passed a specified time
             *  within the most recent tick.
             */
            virtual Bool HasPassedTime(Real time) const;

            /**
             * @brief Implementation of Timeframe::SetTimeScale() method.
             * @param timeScale The time scale factor.
             * @return true if successful.
             */
            virtual Bool SetTimeScale(Real timeScale);

            /**
             * @brief Implementation of Timeframe::GetTimeScale() method.
             * @return The time scale factor.
             */
            virtual Real GetTimeScale() const;

            /**
             * @brief Implementation of Timeframe::SetEndTime() method.
             * @param endTime The end time in seconds.
             * @return true if successful.
             */
            virtual Bool SetEndTime(Real endTime);

            /**
             * @brief Implementation of Timeframe::GetEndTime() method.
             * @return The end time in seconds.
             */
            virtual Real GetEndTime() const;

            /**
             * @brief Implementation of Timeframe::GetCurrentTime() method.
             * @return The current time in seconds.
             */
            virtual Double GetCurrentTime() const;

            /**
             * @brief Implementation of Timeframe::GetRemainingTime() method.
             * @return The remaining time in seconds.
             */
            virtual Double GetRemainingTime() const;

        protected:  // Timeframe
            WeakPointer<Timeframe> mSelf;

            Real mTimeScale;
            Real mEndTime;

            Bool mIsRunning;
            Bool mWasRunning;

            Double mCurrentTime;
            Double mRecentTime;
        };
    }
}

#endif // __MURL_LOGIC_TIMEFRAME_H__

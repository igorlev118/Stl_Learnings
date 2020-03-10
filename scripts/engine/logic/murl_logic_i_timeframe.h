// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_TIMEFRAME_H__
#define __MURL_LOGIC_I_TIMEFRAME_H__

#include "murl_logic_i_stepable.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface ITimeframe
         * @brief The ITimeframe interface.
         * The timeframe is evaluated each logic tick using the IStepable interface.
         * \n
         * A timeframe is a lightweight object for measuring a time interval.
         */
        class ITimeframe
        {
        public:
            /**
             * @brief Get the stepable interface shared pointer.
             * The ITimeframe conforms to the IStepable interface.
             * @return The stepable interface shared pointer.
             */
            virtual IStepablePtr GetStepable() = 0;

            /**
             * @brief Reset the timeframe.
             * Stop the timeframe, set the current time to zero and reset the WasRunning() state.
             */
            virtual void Reset() = 0;

            /**
             * @brief Start the timeframe.
             * The time starts with current time zero and is evaluated until the end time is reached.
             */
            virtual void Start() = 0;

            /**
             * @brief Start the timeframe with a specified interval.
             * The time starts with current time zero and is evaluated until the end time is reached.
             * @param endTime The time interval in seconds.
             */
            virtual void Start(Real endTime) = 0;

            /**
             * @brief Set the current time.
             * Modify the current time if the timeframe is running and the
             * new time is within the interval [0 .. end time].
             * @param time The current time in seconds.
             * @return true if successful.
             */
            virtual Bool SetCurrentTime(Real time) = 0;

            /**
             * @brief Finish the timeframe.
             * Set the current time to the end time and the WasRunning() state to true
             * if the timeframe is running.
             * @return true if successful.
             */
            virtual Bool Finish() = 0;

            /**
             * @brief Check if the timeframe is running.
             * A timeframe can be started by calling Start() and stopped by calling Finish() or Reset().
             * @return true if running.
             */
            virtual Bool IsRunning() const = 0;

            /**
             * @brief Check if the timeframe was started from the beginning.
             * @return true if started.
             */
            virtual Bool WasStarted() const = 0;

            /**
             * @brief Check if the timeframe has finished.
             * If the timeframe is finished this state is true within the current logic tick only
             * and will be cleared at the next logic tick.
             * \n
             * (!) This state remains unchanged if the processor holding the timeframe's observer
             * is set to inactive within the current logic tick.
             * In such a case the Reset() method can be called to clear the state.
             * @return true if finished.
             */
            virtual Bool WasRunning() const = 0;

            /**
             * @brief Check if the timeframe is or was running.
             * Returns (IsRunning() || WasRunning()) state.
             * @return true if IsRunning() or WasRunning() is true.
             */
            virtual Bool IsOrWasRunning() const = 0;

            /**
             * @brief Check if the current time has passed a specified time
             *  within the most recent tick.
             * @param time The time to check in seconds.
             * @return true if the current time has passed a specified time
             *  within the most recent tick.
             */
            virtual Bool HasPassedTime(Real time) const = 0;

            /**
             * @brief Set the time scale factor.
             * The recent tick duration is multiplied by the time scale factor
             * and added to the current time each logic tick.
             * The default time scale factor is 1.
             * @param timeScale The time scale factor.
             * @return true if successful.
             */
            virtual Bool SetTimeScale(Real timeScale) = 0;

            /**
             * @brief Get the time scale factor.
             * @return The time scale factor.
             */
            virtual Real GetTimeScale() const = 0;

            /**
             * @brief Set the end time.
             * @param endTime The end time in seconds.
             * @return true if successful.
             */
            virtual Bool SetEndTime(Real endTime) = 0;

            /**
             * @brief Get the end time.
             * @return The end time in seconds.
             */
            virtual Real GetEndTime() const = 0;

            /**
             * @brief Get the current time.
             * @return The current time in seconds.
             */
            virtual Double GetCurrentTime() const = 0;

            /**
             * @brief Get the remaining time.
             * This method calculates GetEndTime() - GetCurrentTime().
             * @return The remaining time in seconds.
             */
            virtual Double GetRemainingTime() const = 0;

        protected:
            virtual ~ITimeframe() {}
        };
    }
}

#endif // __MURL_LOGIC_I_TIMEFRAME_H__

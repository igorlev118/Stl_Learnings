// Copyright 2010-2016 Spraylight

#ifndef __MURL_LOGIC_I_TIMELINE_H__
#define __MURL_LOGIC_I_TIMELINE_H__

#include "murl_logic_i_stepable.h"
#include "murl_logic_i_app_timeline.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface ITimeline
         * @brief The ITimeline interface.
         * The timeline is evaluated each logic tick using the IStepable interface.
         * \n
         * A simple timeline is specified by a start/end time.
         * \n
         * The timeline can be controlled by Start(), Pause() and Stop() calls.
         * \n
         * All setters are taking effect immediately even if the timeline is running.
         *
         * A more detailed timeline can use a loop start/end time, resulting in 3 phases:
         * - Intro running from start to loop start time.
         * - Loop running from loop start to loop end time several times.
         * - Outro running from loop end to end time.
         *
         * The number of loops specifies the counter for of the loop phase.
         * \n
         * Endless looping can be achieved by setting number of loops to < 0.
         * \n
         * If number of loops is 0 the loop start/end time is ignored which means the
         * timeline simply runs from start to end time.
         * \n
         * If the start time is equal to the loop start time the intro phase is skipped.
         * \n
         * If the end time is equal to the loop end time the outro phase is skipped.
         */
        class ITimeline
        {
        public:
            /**
             * @brief Get the stepable interface.
             * The ITimeline conforms to the IStepable interface.
             * @return The stepable interface shared pointer.
             */
            virtual IStepablePtr GetStepable() = 0;

            /**
             * @brief Set the timeline callback object.
             * The IAppTimeline::OnEvaluate() callback method is processed if the
             * timeline's current time is set by IStepable::ProcessTick() or Rewind().
             * @param appTimeline The timeline callback object.
             * @return true if successful.
             */
            virtual Bool SetAppTimeline(IAppTimelinePtr appTimeline) = 0;

            /**
             * @brief Evaluate the current time immediately.
             * Process the IAppTimeline::OnEvaluate() callback method immediately.
             * This method is rarely used after modifying the timeline's current time.
             * This method is typically called when the timeline's current time was evaluated
             * by IStepable::ProcessTick() within each logic tick.
             * This method is called immediately by Reset(), ResetTo(), Rewind(),
             * Start() with parameters and Stop() if auto rewind is enabled.
             */
            virtual void Evaluate() = 0;

            /**
             * @brief Reset the timeline.
             * Stop the timeline, reset the WasRunning() state and call Rewind().
             * Finally Evaluate() is called.
             */
            virtual void Reset() = 0;

            /**
             * @brief Reset the timeline to a specified start time.
             * Set the start time and call Reset().
             * Finally Evaluate() is called.
             * @param startTime The start time in seconds.
             */
            virtual void ResetTo(Real startTime) = 0;

            /**
             * @brief Start or continue the timeline.
             * Reset the WasRunning() state.
             * Does not modify the current time and loop.
             * @return true if successful.
             */
            virtual Bool Start() = 0;
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, calls Rewind() and Start().
             * Finally Evaluate() is called.
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime) = 0;
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, number of loops, calls Rewind() and Start().
             * Finally Evaluate() is called.
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime, SInt32 numberOfLoops) = 0;
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, loop start/end time, number of loops, calls Rewind() and Start().
             * Finally Evaluate() is called.
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @param loopStartTime The loop start time in seconds.
             * @param loopEndTime The loop end time in seconds.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime,
                               Real loopStartTime, Real loopEndTime, SInt32 numberOfLoops) = 0;
            /**
             * @brief Pause the timeline.
             * @return true if timeline was paused, false if timeline is not running.
             */
            virtual Bool Pause() = 0;
            /**
             * @brief Stop the timeline.
             * Rewind() is called if auto rewind is enabled.
             * Finally Evaluate() is called if auto rewind is enabled.
             * @return true if timeline was stopped, false if timeline is already stopped.
             */
            virtual Bool Stop() = 0;
            /**
             * @brief Rewind the timeline.
             * Sets the current time to the start time and the current loop to the start loop.
             * Does not affect the current running state.
             * Finally Evaluate() is called.
             * @return true if successful.
             */
            virtual Bool Rewind() = 0;

            /**
             * @brief Set the start time.
             * @param startTime The start time in seconds.
             */
            virtual void SetStartTime(Real startTime) = 0;
            /**
             * @brief Get the start time.
             * @return The start time in seconds.
             */
            virtual Real GetStartTime() const = 0;

            /**
             * @brief Set the end time.
             * @param endTime The end time in seconds.
             */
            virtual void SetEndTime(Real endTime) = 0;
            /**
             * @brief Get the end time.
             * @return The end time in seconds.
             */
            virtual Real GetEndTime() const = 0;

            /**
             * @brief Set the loop start time.
             * @param startTime The loop start time in seconds.
             */
            virtual void SetLoopStartTime(Real startTime) = 0;
            /**
             * @brief Get the loop start time.
             * @return The loop start time in seconds.
             */
            virtual Real GetLoopStartTime() const = 0;

            /**
             * @brief Set the loop end time.
             * @param endTime The loop end time in seconds.
             */
            virtual void SetLoopEndTime(Real endTime) = 0;
            /**
             * @brief Get the loop end time.
             * @return The loop end time in seconds.
             */
            virtual Real GetLoopEndTime() const = 0;

            /**
             * @brief Set the number of loops.
             * @param numberOfLoops Number of loops.
             */
            virtual void SetNumberOfLoops(SInt32 numberOfLoops) = 0;
            /**
             * @brief Get the number of loops.
             * @return The number of loops.
             */
            virtual SInt32 GetNumberOfLoops() const = 0;

            /**
             * @brief Set the time scale factor.
             * The recent tick duration is multiplied by the time scale factor
             * and added to the current time each logic tick.
             * The default time scale factor is 1.
             * @param timeScale The time scale factor.
             */
            virtual void SetTimeScale(Real timeScale) = 0;
            /**
             * @brief Get the time scale factor.
             * @return true The time scale factor.
             */
            virtual Real GetTimeScale() const = 0;

            /**
             * @brief Enable/disable automatic rewind.
             * Automatic rewind is calling Rewind() when the timeline is stopped.
             * @param enabled Enable automatic rewind if true.
             */
            virtual void SetAutoRewindEnabled(Bool enabled) = 0;
            /**
             * @brief Check if automatic rewind is enabled.
             * @return true if automatic rewind.
             */
            virtual Bool IsAutoRewindEnabled() const = 0;

            /**
             * @brief Check if the timeline is running.
             * A timeline can be started by calling Start() and stopped by calling Stop().
             * @return true if running.
             */
            virtual Bool IsRunning() const = 0;
            /**
             * @brief Check if the timeline is paused.
             * A timeline can be paused by calling Pause() and continued by calling Start().
             * @return true if paused.
             */
            virtual Bool IsPaused() const = 0;
            /**
             * @brief Check if the timeline is stopped.
             * A timeline can be stopped by calling Stop() and started by calling Start().
             * @return true if stopped.
             */
            virtual Bool IsStopped() const = 0;
            /**
             * @brief Check if the timeline was started from stopped state.
             * @return true if started.
             */
            virtual Bool WasStarted() const = 0;
            /**
             * @brief Check if the timeline has stopped running.
             * If the timeline is stopped this state is true within the current logic tick only
             * and will be cleared at the next logic tick.
             * \n
             * (!) This state remains unchanged if the processor holding the timeline's observer
             * is set to inactive within the current logic tick.
             * In such a case the Reset() method can be called to clear the state.
             * @return true if stopped.
             */
            virtual Bool WasRunning() const = 0;

            /**
             * @brief Check if the timeline is or was running.
             * Returns (IsRunning() || WasRunning()) state.
             * @return true if IsRunning() or WasRunning() is true.
             */
            virtual Bool IsOrWasRunning() const = 0;

            /**
             * @brief Check if the current time has passed a specified time
             *  within the most recent tick.
             * Does not consider loops, for evaluating loops see HasPassedLoop().
             * @param time The time to check in seconds.
             * @return true if the current time has passed a specified time
             *  within the most recent tick.
             */
            virtual Bool HasPassedTime(Real time) const = 0;
            /**
             * @brief Check if the current loop has passed a specified loop number
             *  within the most recent tick.
             * If the loop number to check is negative, true is returned each time
             * the current loop has changed.
             * @param loop The loop number to check.
             * @return true if the current loop has passed a specified loop
             *  within the most recent tick.
             */
            virtual Bool HasPassedLoop(SInt32 loop) const = 0;

            /**
             * @brief Get the current time.
             * This method does not consider loops, for evaluating loops see GetCurrentLoop().
             * @return The current time in seconds.
             */
            virtual Double GetCurrentTime() const = 0;
            /**
             * @brief Get the remaining time.
             * This method calculates GetEndTime() - GetCurrentTime() which does not
             * consider loops, for evaluating loops see GetCurrentLoop().
             * @return The remaining time in seconds.
             */
            virtual Double GetRemainingTime() const = 0;
            /**
             * @brief Set the current time.
             * This method does not consider loops, for setting loops see SetCurrentLoop().
             * @param time The current time to set in seconds.
             */
            virtual void SetCurrentTime(Double time) = 0;

            /**
             * @brief Get the current loop.
             * The current loop provides the following information for n loops:
             * - 0 Intro running from start to loop start time.
             * - 1 .. n Loop running from loop start to loop end time.
             * - n + 1 Outro running from loop end to end time.
             *
             * @return The current loop,
             *      0 if number of loops is 0.
             */
            virtual SInt32 GetCurrentLoop() const = 0;
            /**
             * @brief Get the remaining loops.
             * Calculates GetNumberOfLoops() - GetCurrentLoop().
             * @return The remaining loops,
             *      -1 if number of loops is < 0,
             *      0 if number of loops is 0 or intro/outro is running.
             */
            virtual SInt32 GetRemainingLoops() const = 0;
            /**
             * @brief Set the current loop.
             * The current loop represents the following information for n loops:
             * - 0 Intro running from start to loop start time.
             * - 1 .. n Loop running from loop start to loop end time.
             * - n + 1 Outro running from loop end to end time.
             *
             * @param loop The current loop to set.
             * @return true if successful, false if the loop number is out of range.
             */
            virtual Bool SetCurrentLoop(SInt32 loop) = 0;

            /**
             * @brief Get the current animation state.
             * @return The current animation state.
             */
            virtual IEnums::AnimationState GetCurrentState() const = 0;

        protected:
            virtual ~ITimeline() {}
        };
    }
}

#endif // __MURL_LOGIC_I_TIMELINE_H__

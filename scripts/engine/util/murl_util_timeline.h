// Copyright 2011-2016 Spraylight

#ifndef __MURL_UTIL_TIMELINE_H__
#define __MURL_UTIL_TIMELINE_H__

#include "murl_i_enums.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief The timeline base class.
         * The timeline base class is used to implement the Graph::ITimeline
         * and the Logic::ITimeline object.
         */
        class Timeline
        {
        public:
            /**
             * @brief The default constructor.
             */
            Timeline();

            /**
             * @brief The destructor.
             */
            virtual ~Timeline();

            /**
             * @brief Reset the timeline.
             * Stop the timeline, reset the WasRunning() state and call Rewind().
             */
            void Reset();

            /**
             * @brief Reset the timeline to a specified start time.
             * Set the start time and call Reset().
             * @param startTime The start time in seconds.
             */
            void ResetTo(Real startTime);

            /**
             * @brief Start or continue the timeline.
             * Reset the WasRunning() state.
             * Does not modify the current time and loop.
             * @return true if successful.
             */
            Bool Start();
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, calls Rewind() and Start().
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @return true if successful.
             */
            Bool Start(Real startTime, Real endTime);
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, number of loops, calls Rewind() and Start().
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            Bool Start(Real startTime, Real endTime, SInt32 numberOfLoops);
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, loop start/end time, number of loops, calls Rewind() and Start().
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @param loopStartTime The loop start time in seconds.
             * @param loopEndTime The loop end time in seconds.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            Bool Start(Real startTime, Real endTime,
                       Real loopStartTime, Real loopEndTime, SInt32 numberOfLoops);
            /**
             * @brief Pause the timeline.
             * @return true if timeline was paused, false if timeline is not running.
             */
            Bool Pause();
            /**
             * @brief Stop the timeline.
             * Rewind() is called if auto rewind is enabled.
             * @return true if timeline was stopped, false if timeline is already stopped.
             */
            Bool Stop();
            /**
             * @brief Rewind the timeline.
             * Sets the current time to the start time and the current loop to the start loop.
             * Does not affect the current running state.
             * @return true if successful.
             */
            Bool Rewind();

            /**
             * @brief Set the start time.
             * @param startTime The start time in seconds.
             */
            void SetStartTime(Real startTime);
            /**
             * @brief Get the start time.
             * @return The start time in seconds.
             */
            Real GetStartTime() const;

            /**
             * @brief Set the end time.
             * @param endTime The end time in seconds.
             */
            void SetEndTime(Real endTime);
            /**
             * @brief Get the end time.
             * @return The end time in seconds.
             */
            Real GetEndTime() const;

            /**
             * @brief Set the loop start time.
             * @param startTime The loop start time in seconds.
             */
            void SetLoopStartTime(Real startTime);
            /**
             * @brief Get the loop start time.
             * @return The loop start time in seconds.
             */
            Real GetLoopStartTime() const;

            /**
             * @brief Set the loop end time.
             * @param endTime The loop end time in seconds.
             */
            void SetLoopEndTime(Real endTime);
            /**
             * @brief Get the loop end time.
             * @return The loop end time in seconds.
             */
            Real GetLoopEndTime() const;

            /**
             * @brief Set the start loop.
             * Loop #0 is considered the intro, if it is desired to start right in the
             * middle of the first actual loop, the start loop should be set to 1.
             * @param startLoop The start loop.
             */
            void SetStartLoop(SInt32 startLoop);
            /**
             * @brief Get the start loop.
             * @return The start loop.
             */
            SInt32 GetStartLoop() const;

            /**
             * @brief Set the number of loops.
             * @param numberOfLoops Number of loops.
             */
            void SetNumberOfLoops(SInt32 numberOfLoops);
            /**
             * @brief Get the number of loops.
             * @return The number of loops.
             */
            SInt32 GetNumberOfLoops() const;

            /**
             * @brief Set the time scale factor.
             * The recent tick duration is multiplied by the time scale factor
             * and added to the current time each logic tick.
             * The default time scale factor is 1.
             * @param timeScale The time scale factor.
             */
            void SetTimeScale(Real timeScale);
            /**
             * @brief Get the time scale factor.
             * @return true The time scale factor.
             */
            Real GetTimeScale() const;

            /**
             * @brief Enable/disable automatic rewind.
             * Automatic rewind is calling Rewind() when the timeline is stopped.
             * @param enabled Enable automatic rewind if true.
             */
            void SetAutoRewindEnabled(Bool enabled);
            /**
             * @brief Check if automatic rewind is enabled.
             * @return true if automatic rewind.
             */
            Bool IsAutoRewindEnabled() const;

            /**
             * @brief Check if the timeline is running.
             * A timeline can be started by calling Start() and stopped by calling Stop().
             * @return true if running.
             */
            Bool IsRunning() const;
            /**
             * @brief Check if the timeline is paused.
             * A timeline can be paused by calling Pause() and continued by calling Start().
             * @return true if paused.
             */
            Bool IsPaused() const;
            /**
             * @brief Check if the timeline is stopped.
             * A timeline can be stopped by calling Stop() and started by calling Start().
             * @return true if stopped.
             */
            Bool IsStopped() const;
            /**
             * @brief Check if the timeline was started from stopped state.
             * @return true if started.
             */
            Bool WasStarted() const;
            /**
             * @brief Check if the timeline has stopped running.
             * If the timeline is stopped this state is true within the current logic tick only
             * and will be cleared at the next logic tick.
             * \n
             * (!) This state remains unchanged if the timeline is no longer processed.
             * In such a case the Reset() method can be called to clear the state.
             * @return true if stopped.
             */
            Bool WasRunning() const;

            /**
             * @brief Check if the timeline is or was running.
             * Returns (IsRunning() || WasRunning()) state.
             * @return true if IsRunning() or WasRunning() is true.
             */
            Bool IsOrWasRunning() const;

            /**
             * @brief Check if the current time has passed a specified time
             *  within the most recent tick.
             * Does not consider loops, for evaluating loops see HasPassedLoop().
             * @param time The time to check in seconds.
             * @return true if the current time has passed a specified time
             *  within the most recent tick.
             */
            Bool HasPassedTime(Real time) const;
            /**
             * @brief Check if the current loop has passed a specified loop number
             *  within the most recent tick.
             * If the loop number to check is negative, true is returned each time
             * the current loop has changed.
             * @param loop The loop number to check.
             * @return true if the current loop has passed a specified loop
             *  within the most recent tick.
             */
            Bool HasPassedLoop(SInt32 loop = -1) const;

            /**
             * @brief Get the recent time.
             * @return The recent time in seconds.
             */
            Double GetRecentTime() const;
            /**
             * @brief Get the current time.
             * This method does not consider loops, for evaluating loops see GetCurrentLoop().
             * @return The current time in seconds.
             */
            Double GetCurrentTime() const;
            /**
             * @brief Get the remaining time.
             * This method calculates GetEndTime() - GetCurrentTime() which does not
             * consider loops, for evaluating loops see GetCurrentLoop().
             * @return The remaining time in seconds.
             */
            Double GetRemainingTime() const;
            /**
             * @brief Set the current time.
             * This method does not consider loops, for setting loops see SetCurrentLoop().
             * @param time The current time to set in seconds.
             */
            void SetCurrentTime(Double time);

            /**
             * @brief Get the recent loop.
             * @return The recent loop.
             */
            SInt32 GetRecentLoop() const;
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
            SInt32 GetCurrentLoop() const;
            /**
             * @brief Get the remaining loops.
             * Calculates GetNumberOfLoops() - GetCurrentLoop().
             * @return The remaining loops,
             *      -1 if number of loops is < 0,
             *      0 if number of loops is 0 or intro/outro is running.
             */
            SInt32 GetRemainingLoops() const;
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
            Bool SetCurrentLoop(SInt32 loop);

            /**
             * @brief Get the recent animation state.
             * @return The recent animation state.
             */
            IEnums::AnimationState GetRecentState() const;
            /**
             * @brief Get the current animation state.
             * @return The current animation state.
             */
            IEnums::AnimationState GetCurrentState() const;

            /**
             * @brief Process the timeline.
             * @param deltaTime The recent tick duration in seconds.
             * @return true if the timeline was processed.
             */
            Bool ProcessTimeline(Double deltaTime);

        protected:
            void UpdateTime(Double deltaTime);

            Real GetEffectiveLoopTime(Real startTime, Real endTime, Real diff) const;
            Real GetEffectiveLoopStartTime() const;
            Real GetEffectiveLoopEndTime() const;

            Real mStartTime;
            Real mEndTime;
            Real mLoopStartTime;
            Real mLoopEndTime;
            SInt32 mStartLoop;
            SInt32 mNumberOfLoops;
            Real mTimeScale;
            Bool mAutoRewind;

            enum PlaybackState
            {
                PLAYBACK_STATE_STOPPED,
                PLAYBACK_STATE_STARTED,
                PLAYBACK_STATE_FORWARD,
                PLAYBACK_STATE_BACKWARD,
                PLAYBACK_STATE_PAUSED
            };
            PlaybackState mCurrentPlaybackState;
            PlaybackState mRecentPlaybackState;

            Bool CheckTimeFromLeft(Real left, Real time, Real right, PlaybackState playbackState) const;
            Bool CheckTimeToRight(Real left, Real time, Real right, PlaybackState playbackState) const;

            Bool mWasRunning;

            Double mCurrentTime;
            SInt32 mCurrentLoop;

            Double mRecentTime;
            SInt32 mRecentLoop;

            IEnums::AnimationState mCurrentAnimationState;
            IEnums::AnimationState mRecentAnimationState;
        };
    }
}

#endif // __MURL_UTIL_TIMELINE_H__

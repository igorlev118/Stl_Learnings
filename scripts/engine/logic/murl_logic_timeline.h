// Copyright 2010-2016 Spraylight

#ifndef __MURL_LOGIC_TIMELINE_H__
#define __MURL_LOGIC_TIMELINE_H__

#include "murl_logic_i_timeline.h"
#include "murl_logic_stepable.h"
#include "murl_util_timeline.h"
#include "murl_weak_pointer.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief The ITimeline interface implementation.
         */
        class Timeline : public ITimeline, public Stepable
        {
        protected:
            Timeline();

        public:
            /**
             * @brief Create a timeline object.
             * @return The created timeline object, or null if failed.
             */
            static ITimelinePtr Create();

            /**
             * The destructor.
             */
            virtual ~Timeline();

        public: // IStepable

            /**
             * @brief Implementation of IStepable::ProcessTick() method.
             * @param state The IState object.
             */
            virtual void ProcessTick(const Logic::IState* state);

        public: // ITimeline

            /**
             * @brief Implementation of ITimeline::GetStepable() method.
             * @return The stepable interface shared pointer.
             */
            virtual IStepablePtr GetStepable();

            /**
             * @brief Implementation of ITimeline::SetAppTimeline() method.
             * @param appTimeline The timeline callback object.
             * @return true if successful.
             */
            virtual Bool SetAppTimeline(IAppTimelinePtr appTimeline);

            /**
             * @brief Implementation of ITimeline::Evaluate() method.
             */
            virtual void Evaluate();

            /**
             * @brief Implementation of ITimeline::Reset() and IStepable::Reset() method.
             */
            virtual void Reset();

            /**
             * @brief Implementation of ITimeline::ResetTo() method.
             * @param startTime The start time in seconds.
             */
            virtual void ResetTo(Real startTime);

            /**
             * @brief Implementation of ITimeline::Start() method.
             * @return true if successful.
             */
            virtual Bool Start();

            /**
             * @brief Implementation of ITimeline::Start(Real startTime, Real endTime) method.
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime);

            /**
             * @brief Implementation of ITimeline::Start(Real startTime, Real endTime, SInt32 numberOfLoops) method.
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime, SInt32 numberOfLoops);

            /**
             * @brief Implementation of ITimeline::Start(Real startTime, Real endTime, Real loopStartTime, Real loopEndTime, SInt32 numberOfLoops) method.
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @param loopStartTime The loop start time in seconds.
             * @param loopEndTime The loop end time in seconds.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime, Real loopStartTime, Real loopEndTime, SInt32 numberOfLoops);

            /**
             * @brief Implementation of ITimeline::Pause() method.
             * @return true if timeline was paused, false if timeline is not running.
             */
            virtual Bool Pause();

            /**
             * @brief Implementation of ITimeline::Stop() method.
             * @return true if timeline was stopped, false if timeline is already stopped.
             */
            virtual Bool Stop();

            /**
             * @brief Implementation of ITimeline::Rewind() method.
             * @return true if successful.
             */
            virtual Bool Rewind();

            /**
             * @brief Implementation of ITimeline::SetStartTime() method.
             * @param startTime The start time in seconds.
             */
            virtual void SetStartTime(Real startTime);

            /**
             * @brief Implementation of ITimeline::GetStartTime() method.
             * @return The start time in seconds.
             */
            virtual Real GetStartTime() const;

            /**
             * @brief Implementation of ITimeline::SetEndTime() method.
             * @param endTime The end time in seconds.
             */
            virtual void SetEndTime(Real endTime);

            /**
             * @brief Implementation of ITimeline::GetEndTime() method.
             * @return The end time in seconds.
             */
            virtual Real GetEndTime() const;

            /**
             * @brief Implementation of ITimeline::SetLoopStartTime() method.
             * @param startTime The loop start time in seconds.
             */
            virtual void SetLoopStartTime(Real startTime);

            /**
             * @brief Implementation of ITimeline::GetLoopStartTime() method.
             * @return The loop start time in seconds.
             */
            virtual Real GetLoopStartTime() const;

            /**
             * @brief Implementation of ITimeline::SetLoopEndTime() method.
             * @param endTime The loop end time in seconds.
             */
            virtual void SetLoopEndTime(Real endTime);

            /**
             * @brief Implementation of ITimeline::GetLoopEndTime() method.
             * @return The loop end time in seconds.
             */
            virtual Real GetLoopEndTime() const;

            /**
             * @brief Implementation of ITimeline::SetNumberOfLoops() method.
             * @param numberOfLoops Number of loops.
             */
            virtual void SetNumberOfLoops(SInt32 numberOfLoops);

            /**
             * @brief Implementation of ITimeline::GetNumberOfLoops() method.
             * @return The number of loops.
             */
            virtual SInt32 GetNumberOfLoops() const;

            /**
             * @brief Implementation of ITimeline::SetTimeScale() method.
             * @param timeScale The time scale factor.
             */
            virtual void SetTimeScale(Real timeScale);

            /**
             * @brief Implementation of ITimeline::GetTimeScale() method.
             * @return true The time scale factor.
             */
            virtual Real GetTimeScale() const;

            /**
             * @brief Implementation of ITimeline::SetAutoRewindEnabled() method.
             * @param enabled Enable automatic rewind if true.
             */
            virtual void SetAutoRewindEnabled(Bool enabled);

            /**
             * @brief Implementation of ITimeline::IsAutoRewindEnabled() method.
             * @return true if automatic rewind.
             */
            virtual Bool IsAutoRewindEnabled() const;

            /**
             * @brief Implementation of ITimeline::IsRunning() method.
             * @return true if running.
             */
            virtual Bool IsRunning() const;

            /**
             * @brief Implementation of ITimeline::IsPaused() method.
             * @return true if paused.
             */
            virtual Bool IsPaused() const;

            /**
             * @brief Implementation of ITimeline::IsStopped() method.
             * @return true if stopped.
             */
            virtual Bool IsStopped() const;

            /**
             * @brief Implementation of ITimeline::WasStarted() method.
             * @return true if started.
             */
            virtual Bool WasStarted() const;

            /**
             * @brief Implementation of ITimeline::WasRunning() method.
             * @return true if stopped.
             */
            virtual Bool WasRunning() const;

            /**
             * @brief Implementation of ITimeline::IsOrWasRunning() method.
             * @return true if IsRunning() or WasRunning() is true.
             */
            virtual Bool IsOrWasRunning() const;

            /**
             * @brief Implementation of ITimeline::HasPassedTime() method.
             * @param time The time to check in seconds.
             * @return true if the current time has passed a specified time
             *  within the most recent tick.
             */
            virtual Bool HasPassedTime(Real time) const;

            /**
             * @brief Implementation of ITimeline::HasPassedLoop() method.
             * @param loop The loop number to check.
             * @return true if the current loop has passed a specified loop
             *  within the most recent tick.
             */
            virtual Bool HasPassedLoop(SInt32 loop) const;

            /**
             * @brief Implementation of ITimeline::GetCurrentTime() method.
             * @return The current time in seconds.
             */
            virtual Double GetCurrentTime() const;

            /**
             * @brief Implementation of ITimeline::GetRemainingTime() method.
             * @return The remaining time in seconds.
             */
            virtual Double GetRemainingTime() const;

            /**
             * @brief Implementation of ITimeline::SetCurrentTime() method.
             * @param time The current time to set in seconds.
             */
            virtual void SetCurrentTime(Double time);
            
            /**
             * @brief Implementation of ITimeline::GetCurrentLoop() method.
             * @return The current loop,
             *      0 if number of loops is 0.
             */
            virtual SInt32 GetCurrentLoop() const;

            /**
             * @brief Implementation of ITimeline::GetRemainingLoops() method.
             * @return The remaining loops,
             *      -1 if number of loops is < 0,
             *      0 if number of loops is 0 or intro/outro is running.
             */
            virtual SInt32 GetRemainingLoops() const;

            /**
             * @brief Implementation of ITimeline::SetCurrentLoop() method.
             * @param loop The current loop to set.
             * @return true if successful, false if the loop number is out of range.
             */
            virtual Bool SetCurrentLoop(SInt32 loop);

            /**
             * @brief Implementation of ITimeline::GetCurrentState() method.
             * @return The current animation state.
             */
            virtual IEnums::AnimationState GetCurrentState() const;

        protected:  // Timeline
            WeakPointer<Timeline> mSelf;

            Util::Timeline mTimeline;
            IAppTimelinePtr mAppTimeline;
        };
    }
}

#endif // __MURL_LOGIC_TIMELINE_H__

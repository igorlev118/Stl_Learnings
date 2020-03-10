// Copyright 2010-2016 Spraylight

#ifndef __MURL_GRAPH_I_TIMELINE_H__
#define __MURL_GRAPH_I_TIMELINE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_graph_i_state_unit.h"
#include "murl_graph_i_blendable.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class ITimeline;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITimeline nodes.
         */
        typedef IGenericNodeTarget<ITimeline> ITimelineNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITimeline
         * @brief The ITimeline graph node interface.
         * The timeline node is evaluated each logic traversal if activated.\n
         *
         * A simple timeline is specified by a start/end time.\n
         * The timeline can be controlled by Start(), Pause() and Stop() calls.\n
         * All setters are taking effect immediately even if the timeline is running.\n
         *
         * A more detailed timeline can use a loop start/end time, resulting in 3 phases:
         * - Intro running from start to loop start time.
         * - Loop running from loop start to loop end time several times.
         * - Outro running from loop end to end time.
         *
         * The number of loops specifies the counter for of the loop phase.\n
         * Endless looping can be achieved by setting number of loops to < 0.\n
         * If number of loops is 0 the loop start/end time is ignored which means the
         * timeline simply runs from start to end time.\n
         * If the start time is equal to the loop start time the intro phase is skipped.\n
         * If the end time is equal to the loop end time the outro phase is skipped.
         *
         * Timelines may depend on an optional parent timeline, which is in control of
         * actually starting and stopping the current timeline.
         * See GetParentTimelineNodeTarget().
         *
         * Optionally, a Resource::IAnimation object may be defined, which can be used to
         * retrieve the time range of an animation clip, which is then used for playback.
         * See GetAnimationResourceTarget(), SetClipIndex() and SetClipName().
         *
         * A timeline also implements the Graph::IBlendable interface, in order to blend
         * multiple timelines together. Blending can be performed both between multiple
         * timeline units as well as multiple stages from a Graph::MultiTimeline.
         * See GetSubTimelineNodeTarget() for latter case.
         *
         * It is possible to define a bit mask of up to 32 different global trigger groups,
         * which can be used to selectively enable/disable the timeline's effect on e.g.
         * controllers that implement the Graph::ITimeController interface. See
         * SetTriggerGroupMask() and Graph::ITimeController::SetResponseGroupMask().
         * By default, all 32 groups are triggered.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during
         * scene graph traversal.\n
         * See Graph::ITimelineState for activating a timeline.
         */
        class ITimeline : public IStateUnit, public IBlendable
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;

            /**
             * @brief Get the mutable container holding an optional parent timeline.
             * This method returns a mutable pointer to the node's Graph::ITimelineNodeTarget
             * parent container, which is used to store an optional timeline parent to inherit
             * values from.
             * @return The mutable Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual ITimelineNodeTarget* GetParentTimelineNodeTarget() = 0;
            /**
             * @brief Get the constant container holding an optional parent timeline.
             * This method returns a constant pointer to the node's Graph::ITimelineNodeTarget
             * parent container, which is used to store an optional timeline parent to inherit
             * values from.
             * @return The constant Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual const ITimelineNodeTarget* GetParentTimelineNodeTarget() const = 0;

            /**
             * @brief Get the mutable container holding the optional sub-timelines.
             * This method returns a mutable pointer to the node's Graph::ITimelineNodeTarget
             * sub container, which is used to store multiple sub-timeline stages.
             * @return The mutable Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual ITimelineNodeTarget* GetSubTimelineNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the optional sub-timelines.
             * This method returns a constant pointer to the node's Graph::ITimelineNodeTarget
             * sub container, which is used to store multiple sub-timeline stages.
             * @return The constant Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual const ITimelineNodeTarget* GetSubTimelineNodeTarget() const = 0;

            /**
             * @brief Get a mutable Graph::IAnimationResourceTarget container.
             * This method returns a mutable pointer to a Graph::IAnimationResourceTarget
             * container, which allows to add, remove or query the optional animation resource
             * that can be used to configure the timeline to play back the time range of a specific
             * animation clip from the resource. See also ITimeline::SetClipIndex().
             * @return The mutable Graph::IAnimationResourceTarget container.
             */
            virtual IAnimationResourceTarget* GetAnimationResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IAnimationResourceTarget container.
             * This method returns a constant pointer to a Graph::IAnimationResourceTarget
             * container, which allows to query the optional animation resource
             * that can be used to configure the timeline to play back the time range of a specific
             * animation clip from the resource. See also ITimeline::SetClipIndex().
             * @return The constant Graph::IAnimationResourceTarget container.
             */
            virtual const IAnimationResourceTarget* GetAnimationResourceTarget() const = 0;

            /**
             * @brief Reset the timeline.
             * Stop the timeline, reset the WasRunning() state and call Rewind().
             * @return true if successful.
             */
            virtual Bool Reset() = 0;

            /**
             * @brief Reset the timeline to a specified start time.
             * Set the start time and call Reset().
             * @param startTime The start time in seconds.
             * @return true if successful.
             */
            virtual Bool ResetTo(Real startTime) = 0;

            /**
             * @brief Start or continue the timeline.
             * Does not modify the current time and loop.
             * @return true if successful.
             */
            virtual Bool Start() = 0;
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, calls Rewind() and Start().
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime) = 0;
            /**
             * @brief Start the timeline with specified parameters.
             * Set start/end time, number of loops, calls Rewind() and Start().
             * @param startTime The start time in seconds.
             * @param endTime The end time in seconds.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            virtual Bool Start(Real startTime, Real endTime, SInt32 numberOfLoops) = 0;
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
             * @return true if timeline was stopped, false if timeline is already stopped.
             */
            virtual Bool Stop() = 0;
            /**
             * @brief Rewind the timeline.
             * Sets the current time to the start time and the current loop to the start loop.
             * Does not affect the current running state.
             * @return true if successful.
             */
            virtual Bool Rewind() = 0;

            /**
             * @brief Stall the timeline.
             * This method acts as a trigger to pause the timeline for a single logic tick.
             * Usually this is called by some node that depends on a steady flow of input data
             * (such as a movie stream) whenever it has to wait for new input data in order
             * to continue decoding. In this case, the timeline may be stalled so that other
             * animations depending on that timeline are kept in sync.
             * @return true if successful.
             */
            virtual Bool Stall() const = 0;

            /**
             * @brief Set the clip index.
             * Setting the clip index works in conjunction with an animation resource set via
             * the resource target obtained from GetAnimationResourceTarget().
             * @param clipIndex The clip index to set.
             * @return true if successful.
             */
            virtual Bool SetClipIndex(UInt32 clipIndex) = 0;
            /**
             * @brief Get the clip index.
             * @return The clip index.
             */
            virtual UInt32 GetClipIndex() const = 0;

            /**
             * @brief Set the current clip by name.
             * Setting the clip works only in conjunction with an animation resource set via
             * the resource target obtained from GetAnimationResourceTarget(), from which the
             * actual clip index is retrieved by its name. This method fails if the given clip
             * name is empty, no animation resource is set, or no clip with that name was found
             * in the animation resource.
             * @param clipName The clip name.
             * @return true if successful.
             */
            virtual Bool SetClipName(const String& clipName) = 0;
            /**
             * @brief Get the current clip's name.
             * This method returns an empty string when no animation resource is defined or the
             * currently active clip is unnamed.
             * @return The clip name if available.
             */
            virtual String GetClipName() const = 0;

            /**
             * @brief Set the start time.
             * @param startTime The start time in seconds.
             * @return true if successful.
             */
            virtual Bool SetStartTime(Real startTime) = 0;
            /**
             * @brief Get the start time.
             * @return The start time in seconds.
             */
            virtual Real GetStartTime() const = 0;

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
             * @brief Set the loop start time.
             * @param startTime The loop start time in seconds.
             * @return true if successful.
             */
            virtual Bool SetLoopStartTime(Real startTime) = 0;
            /**
             * @brief Get the loop start time.
             * @return The loop start time in seconds.
             */
            virtual Real GetLoopStartTime() const = 0;

            /**
             * @brief Set the loop end time.
             * @param endTime The loop end time in seconds.
             * @return true if successful.
             */
            virtual Bool SetLoopEndTime(Real endTime) = 0;
            /**
             * @brief Get the loop end time.
             * @return The loop end time in seconds.
             */
            virtual Real GetLoopEndTime() const = 0;

            /**
             * @brief Set the start loop.
             * Loop #0 is considered the intro, if it is desired to start right in the
             * middle of the first actual loop, the start loop should be set to 1.
             * @param startLoop The start loop.
             * @return true if successful.
             */
            virtual Bool SetStartLoop(SInt32 startLoop) = 0;
            /**
             * @brief Get the start loop.
             * @return The start loop.
             */
            virtual SInt32 GetStartLoop() const = 0;

            /**
             * @brief Set the number of loops.
             * @param numberOfLoops Number of loops.
             * @return true if successful.
             */
            virtual Bool SetNumberOfLoops(SInt32 numberOfLoops) = 0;
            /**
             * @brief Get the number of loops.
             * @return The number of loops.
             */
            virtual SInt32 GetNumberOfLoops() const = 0;

            /**
             * @brief Set the time shift value.
             * @param timeShift The time shift value.
             * @return true if successful.
             */
            virtual Bool SetTimeShift(Double timeShift) = 0;
            /**
             * @brief Get the time shift value.
             * @return The time shift value.
             */
            virtual Double GetTimeShift() const = 0;

            /**
             * @brief Set the time offset value.
             * @param timeOffset The time offset value.
             * @return true if successful.
             */
            virtual Bool SetTimeOffset(Double timeOffset) = 0;
            /**
             * @brief Get the time offset value.
             * @return The time offset value.
             */
            virtual Double GetTimeOffset() const = 0;

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
             * @return true The time scale factor.
             */
            virtual Real GetTimeScale() const = 0;

            /**
             * @brief Set the active trigger groups for this timeline.
             * A timeline can be configured to influence a number of user-defined controller
             * groups stored as a UInt32 bit mask, allowing up to 32 individual groups.
             * See Graph::IController::SetResponseGroupMask().
             * @param mask The trigger group bit mask.
             * @return true if successful.
             */
            virtual Bool SetTriggerGroupMask(UInt32 mask) = 0;
            /**
             * @brief Get the active trigger groups for this timeline.
             * @return The bit mask specifying active trigger groups.
             */
            virtual UInt32 GetTriggerGroupMask() const = 0;

            /**
             * @brief Enable/disable automatic rewind.
             * Automatic rewind is calling Rewind() when the timeline is stopped.
             * @param enabled Enable automatic rewind if true.
             * @return true if successful.
             */
            virtual Bool SetAutoRewindEnabled(Bool enabled) = 0;
            /**
             * @brief Check if automatic rewind is enabled.
             * @return true if automatic rewind.
             */
            virtual Bool IsAutoRewindEnabled() const = 0;

            /**
             * @brief Enable/disable starting on node activation.
             * If the timeline node or a sub-tree containing the node is changed to active
             * the Start() method is called within the next logic traversal.
             * @param enabled Enable starting if true.
             * @return true if successful.
             */
            virtual Bool SetStartOnActivateEnabled(Bool enabled) = 0;
            /**
             * @brief Check if starting on node activation is enabled.
             * @return true if enabled.
             */
            virtual Bool IsStartOnActivateEnabled() const = 0;

            /**
             * @brief Enable/disable stopping on node deactivation.
             * If the timeline node or a sub-tree containing the node is changed to inactive
             * the Stop() method is called within the next logic traversal.
             * For potential sideffects see WasRunning().
             * @param enabled Enable stopping if true.
             * @return true if successful.
             */
            virtual Bool SetStopOnDeactivateEnabled(Bool enabled) = 0;
            /**
             * @brief Check if stopping on node deactivation is enabled.
             * @return true if enabled.
             */
            virtual Bool IsStopOnDeactivateEnabled() const = 0;

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
             * @brief Check if the timeline was started from the beginning.
             * @return true if started.
             */
            virtual Bool WasStarted() const = 0;
            /**
             * @brief Check if the timeline has stopped running.
             * If the timeline is stopped this state is true within the current logic tick only
             * and will be cleared at the next logic traversal.
             * \n
             * (!) This state remains unchanged if the timeline node or a sub-tree containing the node
             * is set to inactive within the current logic tick or if SetStopOnDeactivateEnabled()
             * is enabled.
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
            virtual Bool HasPassedLoop(SInt32 loop = -1) const = 0;

            /**
             * @brief Get the recent time.
             * @return The recent time in seconds.
             */
            virtual Double GetRecentTime() const = 0;
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
             * @brief Get the recent loop.
             * @return The recent loop, 0 if number of loops is 0.
             */
            virtual SInt32 GetRecentLoop() const = 0;
            /**
             * @brief Get the current loop.
             * The current loop provides the following information for n loops:
             * - 0 Intro running from start to loop start time.
             * - 1 .. n Loop running from loop start to loop end time.
             * - n + 1 Outro running from loop end to end time.
             *
             * @return The current loop, 0 if number of loops is 0.
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
             * @brief Get the recent animation state.
             * @return The recent animation state.
             */
            virtual IEnums::AnimationState GetRecentState() const = 0;
            /**
             * @brief Get the current animation state.
             * @return The current animation state.
             */
            virtual IEnums::AnimationState GetCurrentState() const = 0;

            /**
             * @brief Get the timeline's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the timeline's actual node at a given stage.
             * @param stage The stage to query.
             * @return The timeline sub-object.
             */
            virtual const ITimeline* GetTimeline(UInt32 stage) const = 0;

        protected:
            virtual ~ITimeline() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TIMELINE_H__

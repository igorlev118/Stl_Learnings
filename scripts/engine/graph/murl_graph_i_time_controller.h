// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TIME_CONTROLLER_H__
#define __MURL_GRAPH_I_TIME_CONTROLLER_H__

#include "murl_graph_i_controller.h"
#include "murl_graph_i_time_evaluator.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface ITimeController
         * @brief The ITimeController interface.
         * This interface provides a way to automatically manipulate individual properties of a given
         * Graph::INode by via individual Graph::ITimeEvaluator objects created upon initialization.
         *
         * The Graph::TimeController class implementing this interface provides a default implementation
         * that can be used to add individual custom Graph::ITimeEvaluator objects for the purpose of
         * manipulating different node properties.
         *
         * The Graph::AnimationTimeController class is a specialized implementation that acts on a given
         * Resource::IAnimation object, with different evaluators for each individual type of key
         * frame defined in the animation.
         *
         * See Graph::Node for details on creating controllers via an XML scene graph description.
         */
        class ITimeController
        {
        public:
            /**
             * @brief Get the mutable IController interface.
             * @return The mutable IController interface.
             */
            virtual IController* GetControllerInterface() = 0;
            /**
             * @brief Get the constant IController interface.
             * @return The constant IController interface.
             */
            virtual const IController* GetControllerInterface() const = 0;
            
            /**
             * @brief Set the time shift value used for evaluation.
             * @param timeShift The time shift value.
             * @return true if successful.
             */
            virtual Bool SetTimeShift(Double timeShift) = 0;
            /**
             * @brief Get the time shift value used for evaluation.
             * @return The time shift value.
             */
            virtual Double GetTimeShift() const = 0;
            
            /**
             * @brief Set the time offset value used for evaluation.
             * A positive value represents an actual controller start time after the given input
             * time t, which results in an already started animation for t=0. Negative values result
             * in a delay before the animation is started (at t=0 the controller's shifted time is
             * still negative and has has not reached its actual start time). By default, the time
             * shift value is 0.
             * @param timeOffset The time offset value.
             * @return true if successful.
             */
            virtual Bool SetTimeOffset(Double timeOffset) = 0;
            /**
             * @brief Get the time offset value used for evaluation.
             * @return The time offset value.
             */
            virtual Double GetTimeOffset() const = 0;
            
            /**
             * @brief Set the time scale value used for evaluation.
             * By default, the time scale value equals 1.0. Values less than 1.0 result in
             * a reduced animation time, for values higher than 1.0 the animation is running
             * faster than normal. Time scaling is applied before shifting, so the time scale
             * value does not affect a given time shift value.
             * @param timeScale The time scale value.
             * @return true if successful.
             */
            virtual Bool SetTimeScale(Double timeScale) = 0;
            /**
             * @brief Get the time scale value used for evaluation.
             * @return The time scale value.
             */
            virtual Double GetTimeScale() const = 0;

            /**
             * @brief Activate/deactivate processing of a timeline at a given unit.
             * @param unit The timeline unit.
             * @param enabled If true, a timeline at the given unit is processed.
             * @return true if successful.
             */
            virtual Bool SetTimelineUnitEnabled(UInt32 unit, Bool enabled) = 0;
            /**
             * @brief Check if a given timeline unit is used.
             * @param unit The timeline unit.
             * @return true if used.
             */
            virtual Bool IsTimelineUnitEnabled(UInt32 unit) const = 0;

            /**
             * @brief Enable/disable blend factor normalization.
             * If set to true, the blend factors of all currently relevant timelines
             * are summed up, and each of them is divided by that sum so that the 
             * total sum of the blend factors equals 1.
             * @param enabled If true, normalization is enabled.
             * @return true if successful.
             */
            virtual Bool SetBlendFactorNormalizationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if blend factor normalization is enabled.
             * @return true if enabled.
             */
            virtual Bool IsBlendFactorNormalizationEnabled() const = 0;

            /**
             * @brief Set the active response groups for this controller.
             * An active controller can be configured to only react on timelines belonging to
             * one or more specific groups. Group assignment is done via a UInt32 bit mask,
             * allowing up to 32 individual groups. The controller processes a given timeline
             * only if at least one specific group bit is set both in the timeline's trigger
             * mask and the controller's response mask. By default, a controller reacts on
             * all trigger groups (the mask is set to 0xffffffff).
             * See Graph::ITimeline::SetTriggerGroupMask().
             * @param mask The response group bit mask.
             * @return true if successful.
             */
            virtual Bool SetResponseGroupMask(UInt32 mask) = 0;
            /**
             * @brief Get the active response groups for this controller.
             * @return The bit mask specifying active response groups.
             */
            virtual UInt32 GetResponseGroupMask() const = 0;

        protected:
            virtual ~ITimeController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TIME_CONTROLLER_H__

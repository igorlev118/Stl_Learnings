// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CLIP_TRANSITION_H__
#define __MURL_GRAPH_I_CLIP_TRANSITION_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_variable.h"
#include "murl_graph_i_clip.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IClipTransition
         * @brief The IClipTransition graph node interface.
         * Clip transition nodes must be defined as direct children of a node implementing the
         * Graph::IClipSequencer interface, which is responsible for managing any transitions
         * between those clips. See Graph::IClipSequencer and Graph::IClip.
         * 
         * A clip transition must always reference exactly two Graph::IClip nodes: one representing
         * the "from" state and another one for the "to" state. See GetFromClipNodeTarget() and
         * GetToClipNodeTarget(). 
         * 
         * When a transition is triggered, the given "from" node is blended out (towards a blend
         * factor of 0.0). and the "to" node is synchronously blended in (towards 1.0), both with
         * their respective duration and offset.
         *
         * The actual trigger used to start a transition can be any combination of bits from the
         * IEnums::TriggerCondition enumeration, set via SetTriggerConditionEnabled(). The
         * following trigger types are available:
         *
         *  - IEnums::TRIGGER_CONDITION_CLIP_FINISHED: The transition is started when the timelines
         *    defined in the "from" clip are about to expire (see Graph::IClip::GetRemainingClipTime()).
         *    This takes into account the given out duration and offset values; the transition is
         *    started before the timelines are actually finished so that both transition and timelines
         *    expire at the same time. Negative offset values result in the transition being started
         *    earlier, positive values add a delay.
         *
         *  - IEnums::TRIGGER_CONDITION_LOOP_FINISHED: Similar to CLIP_FINISHED, but the transition
         *    is started when a timeline in the "from" clip is about to finish its next loop. This
         *    is useful for timelines that loop forever, where it is desired to synchronize a
         *    transition to a whole loop (e.g. when the feet are on the ground in a walk cycle
         *    animation).
         *
         *  - IEnums::TRIGGER_CONDITION_VARIABLE: When using this trigger, a Graph::IVariable node
         *    must be defined via GetTriggerVariableNodeTarget(), of type IEnums::VARIABLE_TYPE_BOOL.
         *    The transition is started immediately when the variable's value equals true. This means,
         *    that in this case negative offset values cannot have an effect and are clamped to zero.
         *
         * Note, that if a transition to a certain clip is started, and there is another transition
         * for that new clip whose condition is true at the same moment, that transition gets also
         * started at the same time. This means, that it is possible to chain transitions together
         * without any delay. However, the same clip cannot be processed twice in the same tick,
         * otherwise an infinite loop would occur. In such a case, the transition is delayed until
         * the next tick.
         */
        class IClipTransition
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
             * @brief Enable/disable a given trigger condition.
             * @param condition The condition to enable or disable
             * @param enabled If true, the given condition gets enabled.
             * @return true if successful.
             */
            virtual Bool SetTriggerConditionEnabled(IEnums::TriggerCondition condition, Bool enabled) = 0;
            /**
             * @brief Check if a given trigger condition is enabled.
             * @param condition The condition to check.
             * @return true if enabled.
             */
            virtual Bool IsTriggerConditionEnabled(IEnums::TriggerCondition condition) const = 0;

            /**
             * @brief Get the mutable Graph::IVariableNodeTarget container referencing a trigger variable.
             * This method returns a mutable pointer to the node's Graph::IVariableNodeTarget
             * container, which allows to set or query a reference to an optional trigger variable.
             * @return The mutable Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual IVariableNodeTarget* GetTriggerVariableNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IVariableNodeTarget container referencing a trigger variable.
             * This method returns a constant pointer to the node's Graph::IVariableNodeTarget
             * container, which allows to query a reference to an optional trigger variable.
             * @return The constant Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual const IVariableNodeTarget* GetTriggerVariableNodeTarget() const = 0;
            
            /**
             * @brief Get the mutable Graph::IClipNodeTarget container referencing the "from" clip.
             * This method returns a mutable pointer to the node's Graph::IClipNodeTarget
             * container, which allows to set or query a reference to the "from" clip node.
             * @return The mutable Graph::IClipNodeTarget container, or null if not available.
             */
            virtual IClipNodeTarget* GetFromClipNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IClipNodeTarget container referencing the "from" clip.
             * This method returns a constant pointer to the node's Graph::IClipNodeTarget
             * container, which allows to query a reference to the "from" clip node.
             * @return The constant Graph::IClipNodeTarget container, or null if not available.
             */
            virtual const IClipNodeTarget* GetFromClipNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IClipNodeTarget container referencing the "to" clip.
             * This method returns a mutable pointer to the node's Graph::IClipNodeTarget
             * container, which allows to set or query a reference to the "to" clip node.
             * @return The mutable Graph::IClipNodeTarget container, or null if not available.
             */
            virtual IClipNodeTarget* GetToClipNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IClipNodeTarget container referencing the "to" clip.
             * This method returns a constant pointer to the node's Graph::IClipNodeTarget
             * container, which allows to query a reference to the "to" clip node.
             * @return The constant Graph::IClipNodeTarget container, or null if not available.
             */
            virtual const IClipNodeTarget* GetToClipNodeTarget() const = 0;

            /**
             * @brief Set the duration of the "from" node's out transition.
             * @param duration The duration in seconds.
             * @return true if successful.
             */
            virtual Bool SetOutDuration(Double duration) = 0;
            /**
             * @brief Get the duration of the "from" node's out transition.
             * @return The duration in seconds.
             */
            virtual Double GetOutDuration() const = 0;

            /**
             * @brief Set the out transition time offset.
             * @param offset The offset in seconds, with positive values in the future.
             * @return true if successful.
             */
            virtual Bool SetOutOffset(Double offset) = 0;
            /**
             * @brief Get the out transition time offset.
             * @return The offset in seconds.
             */
            virtual Double GetOutOffset() const = 0;

            /**
             * @brief Set the duration of the "to" node's in transition.
             * @param duration The duration in seconds.
             * @return true if successful.
             */
            virtual Bool SetInDuration(Double duration) = 0;
            /**
             * @brief Get the duration of the "to" node's in transition.
             * @return The duration in seconds.
             */
            virtual Double GetInDuration() const = 0;

            /**
             * @brief Set the in transition time offset.
             * @param offset The offset in seconds, with positive values in the future.
             * @return true if successful.
             */
            virtual Bool SetInOffset(Double offset) = 0;
            /**
             * @brief Get the in transition time offset.
             * @return The offset in seconds.
             */
            virtual Double GetInOffset() const = 0;

        protected:
            virtual ~IClipTransition() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IClipTransition nodes.
         */
        typedef IGenericNodeTarget<IClipTransition> IClipTransitionNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CLIP_TRANSITION_H__

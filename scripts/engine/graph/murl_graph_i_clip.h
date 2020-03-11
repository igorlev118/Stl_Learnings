// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CLIP_H__
#define __MURL_GRAPH_I_CLIP_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_blendable.h"
#include "murl_graph_i_timeline.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IClip
         * @brief The IClip graph node interface.
         * Clip nodes must be defined as direct children of a node implementing the
         * Graph::IClipSequencer interface, which is responsible for managing any transitions 
         * between those clips. See Graph::IClipSequencer and Graph::IClipTransition for details.
         *
         * Each clip can reference any number of Graph::ITimeline nodes from within its sub-graph.
         * All referenced timelines are started whenever that clip starts an "in" transition, and
         * stopped whenever the clip finished an "out" transition (of course, if a referenced
         * timeline expires before an "out" transition is finished, it is also stopped). 
         * 
         * Additionally, a clip can reference any number of nodes implementing the Graph::IBlendable
         * interface (also from the nodes within its sub-graph), which receive the current "in" or
         * "out" transition value in the range from 0.0 (hidden) to 1.0 (fully visible).
         *
         * Note: If it is desired to start a specific Graph::ITimeline and also blend that timeline,
         * (as Graph::ITimeline also implements the Graph::IBlendable interface), the same node must 
         * be specified in both node targets (GetTimelineNodeTarget() and GetBlendableNodeTarget()).
         *
         * A clip can also signal the expiration of the last active timeline (or the last loop),
         * in order to perform automatic transitions. See GetRemainingClipTime(), 
         * GetRemainingLoopTime() and the Graph::IClipTransition interface.
         */
        class IClip
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
             * @brief Get the mutable Graph::ITimelineNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ITimelineNodeTarget
             * container, which allows to set or query the timelines that are affected by the
             * clip.
             * @return The mutable Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual ITimelineNodeTarget* GetTimelineNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITimelineNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ITimelineNodeTarget
             * container, which allows to query the timelines that are affected by the
             * clip.
             * @return The constant Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual const ITimelineNodeTarget* GetTimelineNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IBlendableNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IBlendableNodeTarget
             * container, which allows to set or query any blendable objects that are affected
             * by the clip.
             * @return The mutable Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual IBlendableNodeTarget* GetBlendableNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IBlendableNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IBlendableNodeTarget
             * container, which allows to query any blendable objects that are affected
             * by the clip.
             * @return The constant Graph::ITimelineNodeTarget container, or null if not available.
             */
            virtual const IBlendableNodeTarget* GetBlendableNodeTarget() const = 0;

            /**
             * @brief Reset all transitions.
             * @return true if successful.
             */
            virtual Bool ResetTransitions() = 0;

            /**
             * @brief Trigger an "in" transition for the clip.
             * This method gets called by the parent Graph::IClipSequencer whenever the clip
             * is supposed to become visible. The startTime parameter represents the actual
             * start time for the transition, given as an absolute logic time value in seconds.
             * If the startTime value is greater than the current absolute logic tick time,
             * the transition is delayed.
             * @param startTime The absolute start time when the transition shall start.
             * @param duration The transition duration.
             * @return true if successful.
             */
            virtual Bool TriggerInTransition(Double startTime, Double duration) = 0;
            /**
             * @brief Trigger an "out" transition for the clip.
             * See TriggerInTransition().
             * @param startTime The absolute start time when the transition shall start.
             * @param duration The transition duration.
             * @return true if successful.
             */
            virtual Bool TriggerOutTransition(Double startTime, Double duration) = 0;

            /**
             * @brief Check if the "in" transition is finished.
             * This method returns true only when all transitions are finished and the clip
             * is fully visible. 
             * @return true if the clip is fully visible.
             */
            virtual Bool IsInTransitionFinished() const = 0;
            /**
             * @brief Check if the "out" transition is finished.
             * This method returns true only when all transitions are finished and the clip
             * is fully hidden.
             * @return true if the clip is fully hidden.
             */
            virtual Bool IsOutTransitionFinished() const = 0;

            /**
             * @brief Get the total remaining clip time.
             * This method returns the remaining time until all timelines have expired, i.e.
             * including the durations for intro, outro and all loops.
             * @return The total remaining time.
             */
            virtual Double GetRemainingClipTime() const = 0;
            /**
             * @brief Get the remaining loop time.
             * This method returns the remaining time until all loops have finished for all
             * timelines affected by the clip, i.e. including only the durations for intro 
             * and loops, without outro durations.
             * @return The remaining loop time.
             */
            virtual Double GetRemainingLoopTime() const = 0;

        protected:
            virtual ~IClip() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IClip nodes.
         */
        typedef IGenericNodeTarget<IClip> IClipNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CLIP_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PLAYABLE_H__
#define __MURL_GRAPH_I_PLAYABLE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IPlayable
         * @brief The IPlayable property interface.
         * This interface provides basic properties of a "playable" object, e.g. an audio
         * or video sequence.
         */
        class IPlayable
        {
        public:
            /**
             * @brief Enable/disable endless looping.
             * If set to true, the playable keeps looping through its source objects
             * even when the timeline's actual time value is beyond the end of the sequence
             * duration.
             * @param enabled If true, endless looping is enabled.
             * @return true if successful.
             */
            virtual Bool SetEndlessLoopEnabled(Bool enabled) = 0;
            /**
             * @brief Check if endless looping is enabled.
             * @return true if endless looping is enabled.
             */
            virtual Bool IsEndlessLoopEnabled() const = 0;

            /**
             * @brief Enable/disable timeline stalling.
             * If set to true, the playable can stall the currently active timeline when
             * e.g. there is no input data available or the decoding process lags behind.
             * This is useful if other animations shall be synchronized to e.g. audio
             * or video playback.
             * @param enabled If true, timeline stalling is enabled.
             * @return true if successful.
             */
            virtual Bool SetTimelineStallingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if timeline stalling is enabled.
             * @return true if timeline stalling is enabled.
             */
            virtual Bool IsTimelineStallingEnabled() const = 0;

            /**
             * @brief Get the total duration of the playable.
             * @return The total duration in seconds.
             */
            virtual Double GetTotalDuration() const = 0;
            
        protected:
            virtual ~IPlayable() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IPlayable nodes.
         */
        typedef IGenericNodeTarget<IPlayable> IPlayableNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_PLAYABLE_H__

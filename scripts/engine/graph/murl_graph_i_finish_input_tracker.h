// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FINISH_INPUT_TRACKER_H__
#define __MURL_GRAPH_I_FINISH_INPUT_TRACKER_H__

#include "murl_graph_i_tracker.h"

namespace Murl
{
    namespace Input
    {
        class ITouchableHandler;
    }

    namespace Graph
    {
        class IProcessInputTracker;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IFinishInputTracker
         * @brief The tracker used for input finishing traversals.
         * This interface represents a graph state tracker used during Graph::INode::FinishInput
         * traversals.
         */
        class IFinishInputTracker
        {
        public:
            /**
             * @brief Initialize the tracker.
             * Called by the engine.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the tracker.
             * Called by the engine.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Get the tracker base class interface.
             * @return The tracker base class interface.
             */
            virtual ITracker* GetTrackerInterface() = 0;

            /**
             * @brief Begin a traversal frame.
             * Called by the engine.
             * @return true if successful.
             */
            virtual Bool BeginFrame() = 0;
            /**
             * @brief End a traversal frame.
             * Called by the engine.
             * @return true if successful.
             */
            virtual Bool EndFrame() = 0;

            /**
             * @brief Begin a traversal logic tick.
             * Called by the engine.
             * @return true if successful.
             */
            virtual Bool BeginLogicTick() = 0;
            /**
             * @brief End a traversal logic tick.
             * Called by the engine.
             * @return true if successful.
             */
            virtual Bool EndLogicTick() = 0;

            /**
             * @brief Get the current logic tick number.
             * @return The current logic tick number.
             */
            virtual UInt32 GetCurrentLogicTickNumber() const = 0;
            /**
             * @brief Get the current absolute logic tick time.
             * @return The current logic tick time in seconds.
             */
            virtual Double GetCurrentLogicTickTime() const = 0;
            /**
             * @brief Get the current logic tick duration.
             * @return The current logic tick duration in seconds.
             */
            virtual Double GetCurrentLogicTickDuration() const = 0;

            /**
             * @brief Get the input touchable handler used to submit input objects.
             * @return The input touchable handler.
             */
            virtual Input::ITouchableHandler* GetTouchableHandler() const = 0;

            /**
             * @brief Get the input processing tracker.
             * @return The tracker.
             */
            virtual IProcessInputTracker* GetProcessTracker() const = 0;

        protected:
            virtual ~IFinishInputTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_FINISH_INPUT_TRACKER_H__

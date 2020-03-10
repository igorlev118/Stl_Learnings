// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FINISH_OUTPUT_TRACKER_H__
#define __MURL_GRAPH_I_FINISH_OUTPUT_TRACKER_H__

#include "murl_graph_i_tracker.h"

namespace Murl
{
    namespace Audio
    {
        class IRenderer;
    }

    namespace Video
    {
        class IRenderer;
    }

    namespace Graph
    {
        class IProcessOutputTracker;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IFinishOutputTracker
         * @brief The tracker used for output finishing traversals.
         * This interface represents a graph state tracker used during Graph::INode::FinishOutput
         * traversals.
         */
        class IFinishOutputTracker
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
             * @brief Get the video renderer used to submit video objects.
             * @return The video renderer.
             */
            virtual Video::IRenderer* GetVideoRenderer() const = 0;
            /**
             * @brief Get the audio renderer used to submit audio objects.
             * @return The audio renderer.
             */
            virtual Audio::IRenderer* GetAudioRenderer() const = 0;

            /**
             * @brief Get the output processing tracker.
             * @return The tracker.
             */
            virtual IProcessOutputTracker* GetProcessTracker() const = 0;

        protected:
            virtual ~IFinishOutputTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_FINISH_OUTPUT_TRACKER_H__

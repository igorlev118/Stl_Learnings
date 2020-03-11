// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONFIG_CHANGED_TRACKER_H__
#define __MURL_GRAPH_I_CONFIG_CHANGED_TRACKER_H__

#include "murl_graph_i_tracker.h"

namespace Murl
{
    namespace Input
    {
        class ITouchableHandler;
    }

    namespace Output
    {
        class IDeviceHandler;
    }

    namespace Audio
    {
        class IRenderer;
    }

    namespace Video
    {
        class IRenderer;
    }

    namespace Physics
    {
        class ISimulator;
    }

    namespace Resource
    {
        class ICollection;
    }

    namespace Graph
    {
        class IFactory;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IConfigChangedTracker
         * @brief The tracker used for "config changed" traversals.
         * This interface represents a graph state tracker used during
         * Graph::INode::ConfigChangedLogic and Graph::INode::ConfigChangedOutput traversals,
         * as well as the respective methods in Graph::IController, Graph::IGenericNodeTarget
         * and Graph::IGenericResourceTarget.
         */
        class IConfigChangedTracker
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
             * @brief Get the engine's graph factory.
             * @return The graph factory.
             */
            virtual Graph::IFactory* GetGraphFactory() const = 0;
            /**
             * @brief Get the input touchable handler used to submit input objects.
             * @return The input touchable handler.
             */
            virtual Input::ITouchableHandler* GetTouchableHandler() const = 0;
            /**
             * @brief Get the engine's output device handler.
             * @return The output device handler.
             */
            virtual Output::IDeviceHandler* GetOutputDeviceHandler() const = 0;
            /**
             * @brief Get the engine's chosen video renderer.
             * @return The video renderer.
             */
            virtual Video::IRenderer* GetVideoRenderer() const = 0;
            /**
             * @brief Get the engine's chosen audio renderer.
             * @return The audio renderer.
             */
            virtual Audio::IRenderer* GetAudioRenderer() const = 0;
            /**
             * @brief Get the engine's chosen physics simulator.
             * @return The physics simulator.
             */
            virtual Physics::ISimulator* GetPhysicsSimulator() const = 0;
            /**
             * @brief Get the engine's main resource collection.
             * @return The resource collection.
             */
            virtual Resource::ICollection* GetResourceCollection() const = 0;

            /**
             * @brief Replace the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ConfigChangedTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 SetTriggers(UInt32 mask) = 0;
            /**
             * @brief Add given triggers to the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ConfigChangedTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 AddTriggers(UInt32 mask) = 0;
            /**
             * @brief Remove given triggers from the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ConfigChangedTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 RemoveTriggers(UInt32 mask) = 0;

            /**
             * @brief Check the traversal response for a given set of triggers.
             * @param mask A bit mask of individual triggers to query for, from the
             *  Graph::INode::ConfigChangedTriggers enumeration.
             * @return A bit mask of affected triggers.
             */
            virtual UInt32 GetResponse(UInt32 mask) const = 0;

        protected:
            virtual ~IConfigChangedTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CONFIG_CHANGED_TRACKER_H__

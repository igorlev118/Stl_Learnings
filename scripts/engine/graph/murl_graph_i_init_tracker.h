// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_INIT_TRACKER_H__
#define __MURL_GRAPH_I_INIT_TRACKER_H__

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
        class INamespace;
        class IFactory;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IInitTracker
         * @brief The tracker used for initialization traversals.
         * This interface represents a graph state tracker used during Graph::INode::Init
         * and Graph::INode::Resume traversals, as well as the respective methods in
         * Graph::IController, Graph::IGenericNodeTarget and Graph::IGenericResourceTarget.
         */
        class IInitTracker
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
             * @brief Get the constant graph root object the tracker refers to.
             * @return The constant graph root object.
             */
            virtual const IRoot* GetRoot() const = 0;
            /**
             * @brief Get the mutable graph root object the tracker refers to.
             * @return The mutable graph root object.
             */
            virtual IRoot* GetRoot() = 0;

            /**
             * @brief Signal the tracker that initialization should be aborted.
             * Called by the package loading mechanism, when loading is cancelled.
             * @param cancelled If true, initialization should be aborted.
             * @return true if successful.
             */
            virtual Bool SetCancelled(Bool cancelled) = 0;
            /**
             * @brief Check if initialization should be aborted.
             * @return true if initialization should be aborted.
             */
            virtual Bool IsCancelled() const = 0;

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
             * @brief Begin processing of a namespace node during traversal.
             * @param currentNmspc The current namespace node.
             * @return The previous namespace node.
             */
            virtual INamespace* BeginCurrentNamespace(INamespace* currentNmspc) = 0;
            /**
             * @brief End processing of a namespace node during traversal.
             * @param previousNmspc The namespace node returned from BeginCurrentNmspc().
             * @return The current namespace node.
             */
            virtual INamespace* EndCurrentNamespace(INamespace* previousNmspc) = 0;
            /**
             * @brief Get the current namespace node.
             * @return The current namespace node.
             */
            virtual INamespace* GetCurrentNamespace() const = 0;

        protected:
            virtual ~IInitTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_INIT_TRACKER_H__

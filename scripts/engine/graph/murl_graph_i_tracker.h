// Copyright 2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TRACKER_H__
#define __MURL_GRAPH_I_TRACKER_H__

#include "murl_graph_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAppConfiguration;
    class IEngineConfiguration;
    class IPlatformConfiguration;

    namespace Logic
    {
        class IEngineState;
    }

    namespace Graph
    {
        class INode;
        class IRoot;
        class ITrackerResult;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface ITracker
         * @brief The tracker base class.
         * This interface represents a graph state tracker base class.
         */
        class ITracker
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
             * @brief Set the logic engine state object.
             * @param logicState The logic engine state object.
             */
            virtual void SetLogicEngineState(Logic::IEngineState* logicState) = 0;
            /**
             * @brief Get the logic engine state object to perform Logic::IAppGraph calls.
             * @return The logic engine state object.
             */
            virtual Logic::IEngineState* GetLogicEngineState() const = 0;

            /**
             * @brief Set the graph root object the tracker refers to.
             * Called by the engine.
             * @param root The root object.
             * @return true if successful.
             */
            virtual Bool SetRoot(IRoot* root) = 0;
            /**
             * @brief Get the const graph root object the tracker refers to.
             * @return The const root object.
             */
            virtual const IRoot* GetRoot() const = 0;

            /**
             * @brief Enable/disable children processing.
             * Called by the engine.
             * @param enabled If true, children processing is enabled.
             * @return true if successful.
             */
            virtual Bool SetChildrenProcessingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if children processing is enabled.
             * @return true if children processing is enabled.
             */
            virtual Bool IsChildrenProcessingEnabled() const = 0;

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
             * @brief Get the current frame number.
             * @return The current frame number.
             */
            virtual UInt32 GetCurrentFrameNumber() const = 0;
            /**
             * @brief Get the current absolute frame time.
             * @return The current frame time in seconds.
             */
            virtual Double GetCurrentFrameTime() const = 0;
            /**
             * @brief Get the most recent frame duration.
             * @return The recent frame duration in seconds.
             */
            virtual Double GetRecentFrameDuration() const = 0;
            /**
             * @brief Get the number of ticks processed for the current frame.
             * @return The number of ticks.
             */
            virtual UInt32 GetNumberOfTicksForCurrentFrame() const = 0;

            /**
             * @brief Begin processing of a node during traversal.
             * @param currentNode The current node.
             * @return The previous node.
             */
            virtual INode* BeginCurrentNode(INode* currentNode) = 0;
            /**
             * @brief End processing of a node during traversal.
             * @param previousNode The node returned from BeginCurrentNode().
             * @return The current node.
             */
            virtual INode* EndCurrentNode(INode* previousNode) = 0;
            /**
             * @brief Get the current node during traversal.
             * @return The current node.
             */
            virtual INode* GetCurrentNode() const = 0;

            /**
             * @brief Record the current node's state during traversal for a given phase.
             * This only gets called during traversal when state recording is enabled
             * for a node via INode::SetStateRecordingEnabled(true).
             * @param phase The traversal phase
             * @return true if successful.
             */
            virtual Bool RecordNodeState(IEnums::TraversalPhase phase) = 0;

            /**
             * @brief Get the constant application configuration.
             * @return The constant application configuration.
             */
            virtual const IAppConfiguration* GetAppConfiguration() const = 0;
            /**
             * @brief Get the constant engine configuration.
             * @return The constant engine configuration.
             */
            virtual const IEngineConfiguration* GetEngineConfiguration() const = 0;
            /**
             * @brief Get the constant platform configuration.
             * @return The constant platform configuration.
             */
            virtual const IPlatformConfiguration* GetPlatformConfiguration() const = 0;

            /**
             * @brief Check if a given flag is set in IEngineConfiguration::GetSuspendableResources().
             * @param suspendableResource The suspendable resource flag to check.
             * @return true if the suspendable resource flag is set.
             */
            virtual Bool IsSuspendableResource(IEnums::SuspendableResource suspendableResource) const = 0;

            /**
             * @brief Reset the number of traversed nodes to zero.
             * For statistic purposes.
             */
            virtual void ResetNumberOfTraversedNodes() = 0;
            /**
             * @brief Increment the number of traversed nodes by one.
             * For statistic purposes.
             */
            virtual void IncrementNumberOfTraversedNodes() = 0;
            /**
             * @brief Get the most recent total number of traversed nodes.
             * For statistic purposes.
             * @return The number of traversed nodes.
             */
            virtual UInt32 GetNumberOfTraversedNodes() const = 0;

            /**
             * @brief Push a user data object with given ID to the stack.
             * @param id The unique user data ID previously acquired via IRoot::AcquireUserDataId().
             * @param userData The user data object.
             */
            virtual void PushUserData(SInt32 id, void* userData) = 0;
            /**
             * @brief Pop a user data object off the stack with a given ID.
             * @param id The unique user data ID previously acquired via IRoot::AcquireUserDataId().
             */
            virtual void PopUserData(SInt32 id) = 0;
            /**
             * @brief Get the most recent user data object from the stack with a given ID.
             * @param id The unique user data ID previously acquired via IRoot::AcquireUserDataId().
             * @return The user data object, or null if none is present.
             */
            virtual void* GetRecentUserData(SInt32 id) const = 0;

            /**
             * @brief Clear the list of result messages.
             */
            virtual void ClearResults() = 0;
            /**
             * @brief Add a result message during traversal.
             * @param result The result message to add.
             */
            virtual void AddResult(const ITrackerResult& result) = 0;
            /**
             * @brief Get the array of result messages added during traversal.
             * @return The array of messages.
             */
            virtual const Array<const ITrackerResult*>& GetResults() const = 0;

        protected:
            virtual ~ITracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TRACKER_H__

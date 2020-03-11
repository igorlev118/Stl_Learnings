// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PROCESS_LOGIC_TRACKER_H__
#define __MURL_GRAPH_I_PROCESS_LOGIC_TRACKER_H__

#include "murl_graph_i_tracker.h"

namespace Murl
{
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
        class IAnchor;
        class IBoundingVolume;
        class IListener;
        class ICamera;
        class IHandle;
        class IHandleInstance;
        class IIsland;
        class IReference;
        class ISurface;
        class ITimeline;
        class IView;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IProcessLogicTracker
         * @brief The tracker used for logic processing traversals.
         * This interface represents a graph state tracker used during Graph::INode::ProcessLogic
         * traversals, as well as the respective methods in Graph::IController, Graph::IGenericNodeTarget
         * and Graph::IGenericResourceTarget.
         */
        class IProcessLogicTracker
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
             * @brief Get the physics simulator used to submit physics objects.
             * @return The physics simulator.
             */
            virtual Physics::ISimulator* GetPhysicsSimulator() const = 0;
            /**
             * @brief Get the engine's main resource collection.
             * @return The resource collection.
             */
            virtual const Resource::ICollection* GetResourceCollection() const = 0;

            /**
             * @brief Obtain a handle for the current node.
             * @return The current node handle.
             */
            virtual IHandle* GetCurrentHandle() = 0;
            /**
             * @brief Obtain a handle instance for the current node.
             * @return The current node handle instance.
             */
            virtual IHandleInstance* GetCurrentHandleInstance() = 0;

            /**
             * @brief Bind a transform anchor to a specific slot.
             * @param anchor The anchor to bind.
             * @param slot The slot to use, from 0 to IEnums::NUM_ANCHOR_SLOTS-1.
             */
            virtual void SetCurrentAnchor(const IAnchor* anchor, SInt32 slot) = 0;
            /**
             * @brief Get a transform anchor bound to a specific slot.
             * @param slot The slot to query, from 0 to IEnums::NUM_ANCHOR_SLOTS-1.
             * @return The anchor at the given slot, or null if none is bound.
             */
            virtual const IAnchor* GetCurrentAnchor(SInt32 slot) const = 0;
            /**
             * @brief Clear the current transform anchor binding.
             */
            virtual void ClearCurrentAnchors() = 0;
            /**
             * @brief Save the current transform anchor binding.
             */
            virtual void SaveCurrentAnchors() = 0;
            /**
             * @brief Restore the previous transform anchor binding.
             */
            virtual void RestoreCurrentAnchors() = 0;

            /**
             * @brief Bind a collision surface to a specific slot.
             * @param surface The collision surface to bind.
             * @param slot The slot to use, from 0 to IEnums::NUM_SURFACE_SLOTS-1.
             */
            virtual void SetCurrentSurface(const ISurface* surface, SInt32 slot) = 0;
            /**
             * @brief Get a collision surface bound to a specific slot.
             * @param slot The slot to query, from 0 to IEnums::NUM_SURFACE_SLOTS-1.
             * @return The collision surface at the given slot, or null if none is bound.
             */
            virtual const ISurface* GetCurrentSurface(SInt32 slot) const = 0;
            /**
             * @brief Clear the current collision surface binding.
             */
            virtual void ClearCurrentSurfaces() = 0;
            /**
             * @brief Save the current collision surface binding.
             */
            virtual void SaveCurrentSurfaces() = 0;
            /**
             * @brief Restore the previous collision surface binding.
             */
            virtual void RestoreCurrentSurfaces() = 0;

            /**
             * @brief Bind a collision island to a specific slot.
             * @param island The collision island to bind.
             * @param slot The slot to use, from 0 to IEnums::NUM_ISLAND_SLOTS-1.
             */
            virtual void SetCurrentIsland(const IIsland* island, SInt32 slot) = 0;
            /**
             * @brief Get a collision island bound to a specific slot.
             * @param slot The slot to query, from 0 to IEnums::NUM_ISLAND_SLOTS-1.
             * @return The collision island at the given slot, or null if none is bound.
             */
            virtual const IIsland* GetCurrentIsland(SInt32 slot) const = 0;
            /**
             * @brief Clear the current collision island binding.
             */
            virtual void ClearCurrentIslands() = 0;
            /**
             * @brief Save the current collision island binding.
             */
            virtual void SaveCurrentIslands() = 0;
            /**
             * @brief Restore the previous collision island binding.
             */
            virtual void RestoreCurrentIslands() = 0;

            /**
             * @brief Bind a timeline to a specific unit.
             * @param timeline The timeline to bind.
             * @param unit The unit to use, from 0 to IEnums::NUM_TIMELINE_UNITS-1.
             */
            virtual void SetCurrentTimeline(const ITimeline* timeline, UInt32 unit) = 0;
            /**
             * @brief Get a timeline bound to a specific unit.
             * @param unit The unit to query, from 0 to IEnums::NUM_TIMELINE_UNITS-1.
             * @return The timeline at the given unit, or null if none is bound.
             */
            virtual const ITimeline* GetCurrentTimeline(UInt32 unit) const = 0;
            /**
             * @brief Clear the current timeline binding.
             */
            virtual void ClearCurrentTimelines() = 0;
            /**
             * @brief Save the current timeline binding.
             */
            virtual void SaveCurrentTimelines() = 0;
            /**
             * @brief Restore the previous timeline binding.
             */
            virtual void RestoreCurrentTimelines() = 0;

            /**
             * @brief Push a world transform matrix to the matrix stack.
             * @param transform The world transform.
             */
            virtual void PushWorldTransform(const Matrix& transform) = 0;
            /**
             * @brief Push a local transform matrix to the matrix stack.
             * @param transform The local transform.
             */
            virtual void PushLocalTransform(const Matrix& transform) = 0;
            /**
             * @brief Pop the topmost transform matrix off the matrix stack.
             */
            virtual void PopTransform() = 0;
            /**
             * @brief Get the most recent world transform matrix from the matrix stack.
             * @return The (possibly calculated) world transform.
             */
            virtual Matrix& GetRecentWorldTransform() const = 0;

            /**
             * @brief Push a world scale factor vector to the scale factor stack.
             * @param scaleFactor The world scale factor.
             */
            virtual void PushWorldScaleFactor(const Vector& scaleFactor) = 0;
            /**
             * @brief Push a local scale factor vector to the scale factor stack.
             * @param scaleFactor The local scale factor.
             */
            virtual void PushLocalScaleFactor(const Vector& scaleFactor) = 0;
            /**
             * @brief Pop the topmost scale factor vector off the scale factor stack.
             */
            virtual void PopScaleFactor() = 0;
            /**
             * @brief Get the most recent world scale factor vector from the scale factor stack.
             * @return The (possibly calculated) world scale factor.
             */
            virtual Vector& GetRecentWorldScaleFactor() const = 0;

            /**
             * @brief Push a world depth order to the depth order stack.
             * @param depthOrder The world depth order.
             */
            virtual void PushWorldDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Push a local depth order to the depth order stack.
             * @param depthOrder The local depth order.
             */
            virtual void PushLocalDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Pop the topmost depth order off the depth order stack.
             */
            virtual void PopDepthOrder() = 0;
            /**
             * @brief Get the most recent world depth order from the depth order stack.
             * @return The (possibly calculated) world depth order.
             */
            virtual SInt32 GetRecentWorldDepthOrder() const = 0;

            /**
             * @brief Push a reference node to the reference stack.
             * @param node The node to push.
             */
            virtual void PushReference(IReference* node) = 0;
            /**
             * @brief Pop the topmost reference node off the reference stack.
             */
            virtual void PopReference() = 0;
            /**
             * @brief Get the most recent reference node from the reference stack.
             * @return The reference node.
             */
            virtual IReference* GetRecentReference() const = 0;

            /**
             * @brief Push the current node flags to the node flag stack.
             * @param nodeFlags The node flags to push.
             */
            virtual void PushNodeFlags(UInt32 nodeFlags) = 0;
            /**
             * @brief Pop the topmost node flags off the node flag stack.
             */
            virtual void PopNodeFlags() = 0;
            /**
             * @brief Get the most recent node flags from the node flag stack.
             * @return The node flags.
             */
            virtual UInt32 GetRecentNodeFlags() const = 0;

            /**
             * @brief Push the current target bounding volume to the BV stack.
             * @param boundingVolume The bounding volume to push.
             */
            virtual void PushTargetBoundingVolume(IBoundingVolume* boundingVolume) = 0;
            /**
             * @brief Pop the topmost target bounding volume off the BV stack.
             */
            virtual void PopTargetBoundingVolume() = 0;
            /**
             * @brief Get the most recent target bounding volume from the BV stack.
             * @return The bounding volume.
             */
            virtual IBoundingVolume* GetRecentTargetBoundingVolume() const = 0;

            /**
             * @brief Queue up a node to have its FinishLogic() method called after traversal.
             * @param node The node to queue up.
             */
            virtual void PushNodeToFinishLogic(INode* node) = 0;

            /**
             * @brief Apply the current world transform in the physics simulator.
             * @return true if successful.
             */
            virtual Bool ApplyCurrentPhysicsTransform() const = 0;
            /**
             * @brief Apply the current physics island in the simulator.
             * @param islandSlot The slot of the bound island to apply.
             * @return true if an island is present at the given slot, false otherwise.
             */
            virtual Bool ApplyCurrentPhysicsIsland(SInt32 islandSlot) = 0;
            /**
             * @brief Apply the current collision surfaces in the physics simulator.
             * @param numSlots The number of surface slot indices to apply.
             * @param surfaceSlots An array of slot indices to apply.
             * @return true if successful.
             */
            virtual Bool ApplyCurrentPhysicsSurfaces(UInt32 numSlots, SInt32* surfaceSlots) const = 0;

            /**
             * @brief Process the current node's bounding volume.
             * @param boundingVolume The node's bounding volume.
             * @return The number of bounding volumes processed;
             */
            virtual UInt32 ProcessCurrentBoundingVolume(IBoundingVolume* boundingVolume) = 0;

            /**
             * @brief Check if the current node was already traversed in the current logic tick.
             * @param tickCount The tick count variable to update.
             * @return true if the node was previously traversed within the current tick.
             */
            virtual Bool WasTraversedInCurrentLogicTick(UInt32& tickCount) const = 0;

            /**
             * @brief Get a reference to the array of nodes that need their FinishLogic() method called.
             * @return The array of nodes to finish.
             */
            virtual Array<INode*>& GetNodesToFinish() = 0;

            /**
             * @brief Replace the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessLogicTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 SetTriggers(UInt32 mask) = 0;
            /**
             * @brief Add given triggers to the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessLogicTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 AddTriggers(UInt32 mask) = 0;
            /**
             * @brief Remove given triggers from the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessLogicTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 RemoveTriggers(UInt32 mask) = 0;

            /**
             * @brief Check the traversal response for a given set of triggers.
             * @param mask A bit mask of individual triggers to query for, from the
             *  Graph::INode::ProcessLogicTriggers enumeration.
             * @return A bit mask of affected triggers.
             */
            virtual UInt32 GetResponse(UInt32 mask) const = 0;

        protected:
            virtual ~IProcessLogicTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_PROCESS_LOGIC_TRACKER_H__

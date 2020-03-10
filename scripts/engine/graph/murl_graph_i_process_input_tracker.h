// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PROCESS_INPUT_TRACKER_H__
#define __MURL_GRAPH_I_PROCESS_INPUT_TRACKER_H__

#include "murl_graph_i_tracker.h"

namespace Murl
{
    namespace Input
    {
        class ITouchableHandler;
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
        class IReference;
        class IView;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IProcessInputTracker
         * @brief The tracker used for input processing traversals.
         * This interface represents a graph state tracker used during Graph::INode::ProcessInput
         * traversals, as well as the respective methods in Graph::IGenericNodeTarget and
         * Graph::IGenericResourceTarget.
         */
        class IProcessInputTracker
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
             * @brief Bind a listener to a specific slot.
             * @param listener The listener to bind.
             * @param slot The slot to use. Currently only slot 0 is allowed.
             */
            virtual void SetCurrentListener(const IListener* listener, SInt32 slot) = 0;
            /**
             * @brief Get a listener bound to a specific slot.
             * @param slot The slot to query. Currently only slot 0 is allowed.
             * @return The listener at the given slot, or null if none is bound.
             */
            virtual const IListener* GetCurrentListener(SInt32 slot) const = 0;
            /**
             * @brief Clear the current listener binding.
             */
            virtual void ClearCurrentListeners() = 0;
            /**
             * @brief Save the current listener binding.
             */
            virtual void SaveCurrentListeners() = 0;
            /**
             * @brief Restore the previous listener binding.
             */
            virtual void RestoreCurrentListeners() = 0;

            /**
             * @brief Bind a camera to a specific slot.
             * @param camera The camera to bind.
             * @param slot The slot to use. Currently only slot 0 is allowed.
             */
            virtual void SetCurrentCamera(const ICamera* camera, SInt32 slot) = 0;
            /**
             * @brief Get a camera bound to a specific slot.
             * @param slot The slot to query. Currently only slot 0 is allowed.
             * @return The camera at the given slot, or null if none is bound.
             */
            virtual const ICamera* GetCurrentCamera(SInt32 slot) const = 0;
            /**
             * @brief Clear the current camera binding.
             */
            virtual void ClearCurrentCameras() = 0;
            /**
             * @brief Save the current camera binding.
             */
            virtual void SaveCurrentCameras() = 0;
            /**
             * @brief Restore the previous camera binding.
             */
            virtual void RestoreCurrentCameras() = 0;

            /**
             * @brief Set the current input layer.
             * @param index The layer index.
             */
            virtual void SetCurrentLayer(UInt32 index) = 0;
            /**
             * @brief Get the current input layer.
             * @return The layer index.
             */
            virtual UInt32 GetCurrentLayer() const = 0;
            /**
             * @brief Clear the current input layer state.
             */
            virtual void ClearCurrentLayer() = 0;
            /**
             * @brief Save the current input layer state.
             */
            virtual void SaveCurrentLayer() = 0;
            /**
             * @brief Restore the previous input layer state.
             */
            virtual void RestoreCurrentLayer() = 0;

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
             * @brief Queue up a node to have its FinishInput() method called after traversal.
             * @param node The node to queue up.
             */
            virtual void PushNodeToFinishInput(INode* node) = 0;

            /**
             * @brief Apply the current world transform in the touchable handler.
             * @return true if successful.
             */
            virtual Bool ApplyCurrentInputTransform() const = 0;
            /**
             * @brief Apply the current projection in the touchable handler.
             * @param slot The camera slot to use. Currently only slot 0 is allowed.
             * @return true if a camera is present at the given slot, false otherwise.
             */
            virtual Bool ApplyCurrentInputProjection(SInt32 slot) = 0;
            /**
             * @brief Apply the current input layer in the touchable handler.
             * @return true if successful.
             */
            virtual Bool ApplyCurrentLayer() = 0;
            // TODO: Equivalent to input screen proj. for e.g. microphone

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
             * @brief Get a reference to the array of nodes that need their FinishInput() method called.
             * @return The array of nodes to finish.
             */
            virtual Array<INode*>& GetNodesToFinish() = 0;

            /**
             * @brief Replace the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessInputTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 SetTriggers(UInt32 mask) = 0;
            /**
             * @brief Add given triggers to the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessInputTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 AddTriggers(UInt32 mask) = 0;
            /**
             * @brief Remove given triggers from the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessInputTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 RemoveTriggers(UInt32 mask) = 0;

            /**
             * @brief Check the traversal response for a given set of triggers.
             * @param mask A bit mask of individual triggers to query for, from the
             *  Graph::INode::ProcessInputTriggers enumeration.
             * @return A bit mask of affected triggers.
             */
            virtual UInt32 GetResponse(UInt32 mask) const = 0;

        protected:
            virtual ~IProcessInputTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_PROCESS_INPUT_TRACKER_H__

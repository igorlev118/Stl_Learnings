// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PROCESS_OUTPUT_TRACKER_H__
#define __MURL_GRAPH_I_PROCESS_OUTPUT_TRACKER_H__

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

    namespace Output
    {
        class IDeviceHandler;
    }

    namespace Resource
    {
        class ICollection;
    }

    namespace Graph
    {
        class IAnchor;
        class IBoundingVolume;
        class IBone;
        class ICamera;
        class ICuller;
        class IHandle;
        class IHandleInstance;
        class ILight;
        class IListener;
        class IMaterial;
        class IParameters;
        class IReference;
        class ITexture;

        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IProcessOutputTracker
         * @brief The tracker used for output processing traversals.
         * This interface represents a graph state tracker used during Graph::INode::ProcessOutput
         * traversals, as well as the respective methods in Graph::IController, Graph::IGenericNodeTarget
         * and Graph::IGenericResourceTarget.
         */
        class IProcessOutputTracker
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
             * @brief Get the output device handler used to submit output objects.
             * @return The output device handler.
             */
            virtual const Output::IDeviceHandler* GetOutputDeviceHandler() const = 0;
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
             * @brief Bind an audio culler to a specific slot.
             * @param culler The culler to bind.
             * @param slot The slot to use. Currently only slot 0 is allowed.
             */
            virtual void SetCurrentAudioCuller(const ICuller* culler, SInt32 slot) = 0;
            /**
             * @brief Get an audio culler bound to a specific slot.
             * @param slot The slot to query. Currently only slot 0 is allowed.
             * @return The culler at the given slot, or null if none is bound.
             */
            virtual const ICuller* GetCurrentAudioCuller(SInt32 slot) const = 0;
            /**
             * @brief Clear the current audio culler binding.
             */
            virtual void ClearCurrentAudioCullers() = 0;
            /**
             * @brief Save the current audio culler binding.
             */
            virtual void SaveCurrentAudioCullers() = 0;
            /**
             * @brief Restore the previous audio culler binding.
             */
            virtual void RestoreCurrentAudioCullers() = 0;

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
             * @brief Bind a video culler to a specific slot.
             * @param culler The culler to bind.
             * @param slot The slot to use. Currently only slot 0 is allowed.
             */
            virtual void SetCurrentVideoCuller(const ICuller* culler, SInt32 slot) = 0;
            /**
             * @brief Get a video culler bound to a specific slot.
             * @param slot The slot to query. Currently only slot 0 is allowed.
             * @return The culler at the given slot, or null if none is bound.
             */
            virtual const ICuller* GetCurrentVideoCuller(SInt32 slot) const = 0;
            /**
             * @brief Clear the current video culler binding.
             */
            virtual void ClearCurrentVideoCullers() = 0;
            /**
             * @brief Save the current video culler binding.
             */
            virtual void SaveCurrentVideoCullers() = 0;
            /**
             * @brief Restore the previous video culler binding.
             */
            virtual void RestoreCurrentVideoCullers() = 0;

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
             * @brief Set the current camera layer.
             * @param index The layer index.
             */
            virtual void SetCurrentLayer(UInt32 index) = 0;
            /**
             * @brief Get the current camera layer.
             * @return The layer index.
             */
            virtual UInt32 GetCurrentLayer() const = 0;
            /**
             * @brief Clear the current camera layer state.
             */
            virtual void ClearCurrentLayer() = 0;
            /**
             * @brief Save the current camera layer state.
             */
            virtual void SaveCurrentLayer() = 0;
            /**
             * @brief Restore the previous camera layer state.
             */
            virtual void RestoreCurrentLayer() = 0;

            /**
             * @brief Bind a material to a specific slot.
             * @param material The material to bind.
             * @param slot The slot to use, from 0 to IEnums::NUM_MATERIAL_SLOTS-1.
             */
            virtual void SetCurrentMaterial(const IMaterial* material, SInt32 slot) = 0;
            /**
             * @brief Get a material bound to a specific slot.
             * @param slot The slot to query, from 0 to IEnums::NUM_MATERIAL_SLOTS-1.
             * @return The material at the given slot, or null if none is bound.
             */
            virtual const IMaterial* GetCurrentMaterial(SInt32 slot) const = 0;
            /**
             * @brief Clear the current material binding.
             */
            virtual void ClearCurrentMaterials() = 0;
            /**
             * @brief Save the current material binding.
             */
            virtual void SaveCurrentMaterials() = 0;
            /**
             * @brief Restore the previous material binding.
             */
            virtual void RestoreCurrentMaterials() = 0;

            /**
             * @brief Bind parameters to a specific slot.
             * @param parameters The parameters to bind.
             * @param slot The slot to use, from 0 to IEnums::NUM_PARAMETERS_SLOTS-1.
             */
            virtual void SetCurrentParameters(const IParameters* parameters, SInt32 slot) = 0;
            /**
             * @brief Get parameters bound to a specific slot.
             * @param slot The slot to query, from 0 to IEnums::NUM_PARAMETERS_SLOTS-1.
             * @return The parameters at the given slot, or null if none are bound.
             */
            virtual const IParameters* GetCurrentParameters(SInt32 slot) const = 0;
            /**
             * @brief Clear the current parameters' binding.
             */
            virtual void ClearCurrentParameters() = 0;
            /**
             * @brief Save the current parameters' binding.
             */
            virtual void SaveCurrentParameters() = 0;
            /**
             * @brief Restore the previous parameters' binding.
             */
            virtual void RestoreCurrentParameters() = 0;

            /**
             * @brief Bind a texture to a specific slot and unit.
             * @param texture The texture to bind.
             * @param slot The slot to use, from 0 to IEnums::NUM_TEXTURE_SLOTS-1.
             * @param unit The unit to use, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             */
            virtual void SetCurrentTexture(const ITexture* texture, SInt32 slot, UInt32 unit) = 0;
            /**
             * @brief Get a texture bound to a specific slot and unit.
             * @param slot The slot to query, from 0 to IEnums::NUM_TEXTURE_SLOTS-1.
             * @param unit The unit to query, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             * @return The texture at the given slot and unit, or null if none is bound.
             */
            virtual const ITexture* GetCurrentTexture(SInt32 slot, UInt32 unit) const = 0;
            /**
             * @brief Clear the current texture binding.
             * @param unit The texture unit.
             */
            virtual void ClearCurrentTextures(UInt32 unit) = 0;
            /**
             * @brief Save the current texture binding.
             * @param unit The texture unit.
             */
            virtual void SaveCurrentTextures(UInt32 unit) = 0;
            /**
             * @brief Restore the previous texture binding.
             * @param unit The texture unit.
             */
            virtual void RestoreCurrentTextures(UInt32 unit) = 0;

            /**
             * @brief Bind a light to a specific unit.
             * @param light The light to bind.
             * @param unit The unit to use, from 0 to IEnums::NUM_LIGHT_UNITS-1.
             */
            virtual void SetCurrentLight(const ILight* light, UInt32 unit) = 0;
            /**
             * @brief Get a light bound to a specific unit.
             * @param unit The unit to query, from 0 to IEnums::NUM_LIGHT_UNITS-1.
             * @return The light at the given unit, or null if none is bound.
             */
            virtual const ILight* GetCurrentLight(UInt32 unit) const = 0;
            /**
             * @brief Clear the current light binding.
             * @param unit The light unit.
             */
            virtual void ClearCurrentLights(UInt32 unit) = 0;
            /**
             * @brief Save the current light binding.
             * @param unit The light unit.
             */
            virtual void SaveCurrentLights(UInt32 unit) = 0;
            /**
             * @brief Restore the previous light binding.
             * @param unit The light unit.
             */
            virtual void RestoreCurrentLights(UInt32 unit) = 0;

            /**
             * @brief Bind a bone to a specific unit.
             * @param bone The bone to bind.
             * @param unit The unit to use, from 0 to IEnums::NUM_BONE_UNITS-1.
             */
            virtual void SetCurrentBone(const IBone* bone, UInt32 unit) = 0;
            /**
             * @brief Get a bone bound to a specific unit.
             * @param unit The unit to query, from 0 to IEnums::NUM_BONE_UNITS-1.
             * @return The bone at the given unit, or null if none is bound.
             */
            virtual const IBone* GetCurrentBone(UInt32 unit) const = 0;
            /**
             * @brief Clear the current bone binding.
             */
            virtual void ClearCurrentBones() = 0;
            /**
             * @brief Save the current bone binding.
             */
            virtual void SaveCurrentBones() = 0;
            /**
             * @brief Restore the previous bone binding.
             */
            virtual void RestoreCurrentBones() = 0;

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
             * @brief Queue up a node to have its FinishOutput() method called after traversal.
             * @param node The node to queue up.
             */
            virtual void PushNodeToFinishOutput(INode* node) = 0;

            /**
             * @brief Process the current audio cullers.
             * @param boundingVolume The node's bounding volume for the cullers to check against.
             * @param intersectionFlags A bit mask of intersection flags to check, from the
             *      Graph::ICuller::IntersectionFlags enumeration.
             * @return The number of nonzero intersections over all active audio cullers.
             */
            virtual UInt32 ProcessCurrentAudioCullers(const IBoundingVolume* boundingVolume, UInt32 intersectionFlags) = 0;
            /**
             * @brief Get the query result of an audio culler after ProcessCurrentAudioCullers().
             * @param cullerSlot The slot of the culler to query.
             * @return A bit mask of actually occurred intersections (Graph::ICuller::IntersectionFlags).
             */
            virtual UInt32 GetCurrentAudioCullerFlags(SInt32 cullerSlot) const = 0;
            /**
             * @brief Apply the current world transform in the audio renderer.
             * @return true if successful.
             */
            virtual Bool ApplyCurrentAudioTransform() const = 0;
            /**
             * @brief Apply the current listener in the audio renderer.
             * @param listenerSlot The slot of the bound listener to apply.
             * @return true if a listener is present at the given slot, false otherwise.
             */
            virtual Bool ApplyCurrentAudioListener(SInt32 listenerSlot) = 0;

            /**
             * @brief Process the current video cullers.
             * @param boundingVolume The node's bounding volume for the cullers to check against.
             * @param intersectionFlags A bit mask of intersection flags to check, from the
             *      Graph::ICuller::IntersectionFlags enumeration.
             * @return The number of nonzero intersections over all active audio cullers.
             */
            virtual UInt32 ProcessCurrentVideoCullers(const IBoundingVolume* boundingVolume, UInt32 intersectionFlags) = 0;
            /**
             * @brief Get the query result of a video culler after ProcessCurrentVideoCullers().
             * @param cullerSlot The slot of the culler to query.
             * @return A bit mask of actually occurred intersections (Graph::ICuller::IntersectionFlags).
             */
            virtual UInt32 GetCurrentVideoCullerFlags(SInt32 cullerSlot) const = 0;
            /**
             * @brief Process the currently active light sources.
             * @param boundingVolume The node's bounding volume with which to intersect each
             *      light's influence volume.
             * @param maxNumberOfStages The maximum number of light stages to process, for
             *      multi-stage light sources.
             * @return The number of actually used lights.
             */
            virtual UInt32 ProcessCurrentLights(const IBoundingVolume* boundingVolume, UInt32 maxNumberOfStages) = 0;
            /**
             * @brief Get the currently needed number of material stages to render.
             * @param materialSlot The slot of the material to query.
             * @return The number of material stages.
             */
            virtual UInt32 GetCurrentNumberOfMaterialStages(SInt32 materialSlot) const = 0;
            /**
             * @brief Get the currently needed number of camera stages to render.
             * @return The number of camera stages.
             */
            virtual UInt32 GetCurrentNumberOfCameraStages() const = 0;
            /**
             * @brief Get the currently needed number of light stages to render.
             * @return The number of light stages.
             */
            virtual UInt32 GetCurrentNumberOfLightStages() const = 0;
            /**
             * @brief Apply the current world transform in the video renderer.
             * @return true if successful.
             */
            virtual Bool ApplyCurrentVideoTransform() const = 0;
            /**
             * @brief Apply the current camera in the video renderer.
             * @param cameraSlot The slot of the bound camera to apply.
             * @return true if a camera is present at the given slot, false otherwise.
             */
            virtual Bool ApplyCurrentVideoCamera(SInt32 cameraSlot) = 0;
            /**
             * @brief Apply the current material stage in the video renderer.
             * @param materialStage The material stage, from 0 to GetCurrentNumberOfMaterialStages()-1.
             * @param materialSlot The slot of the bound material to apply.
             * @param parametersSlot The slot of the bound parameters to apply.
             * @param textureSlots An array of IEnums::NUM_TEXTURE_UNITS slot values of the bound
             *      textures to apply.
             * @return true if the current stage needs to be rendered, false otherwise.
             */
            virtual Bool ApplyCurrentVideoMaterialStage(UInt32 materialStage, SInt32 materialSlot, SInt32 parametersSlot, const SInt32* textureSlots) = 0;
            /**
             * @brief Apply the current camera stage in the video renderer.
             * @param cameraStage The camera stage, from 0 to GetCurrentNumberOfCameraStages()-1.
             * @return true if the current stage needs to be rendered, false otherwise.
             */
            virtual Bool ApplyCurrentVideoCameraStage(UInt32 cameraStage) = 0;
            /**
             * @brief Apply the current light stage in the video renderer.
             * @param lightStage The light stage, from 0 to GetCurrentNumberOfLightStages()-1.
             * @return true if the current stage needs to be rendered, false otherwise.
             */
            virtual Bool ApplyCurrentVideoLightStage(UInt32 lightStage) = 0;
            /**
             * @brief Apply the current set of bones in the video renderer.
             * @param numberOfUnits The number of bones, from 0 to IEnums::NUM_BONE_UNITS-1.
             * @return true if bones are present, false otherwise.
             */
            virtual Bool ApplyCurrentVideoBones(UInt32 numberOfUnits) = 0;
            /**
             * @brief Get the current light stage.
             * @param unit The light unit to check.
             * @return The current stage.
             */
            virtual SInt32 GetCurrentVideoLightStage(UInt32 unit) const = 0;

            /**
             * @brief Process the current node's bounding volume.
             * @param boundingVolume The node's bounding volume.
             * @return The number of bounding volumes processed;
             */
            virtual UInt32 ProcessCurrentBoundingVolume(IBoundingVolume* boundingVolume) = 0;

            /**
             * @brief Check if the current node was already traversed in the current frame.
             * @param frameCount The frame count variable to update.
             * @return true if the node was previously traversed within the current frame.
             */
            virtual Bool WasTraversedInCurrentFrame(UInt32& frameCount) const = 0;

            /**
             * @brief Get a reference to the array of nodes that need their FinishOutput() method called.
             * @return The array of nodes to finish.
             */
            virtual Array<INode*>& GetNodesToFinish() = 0;

            /**
             * @brief Replace the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessOutputTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 SetTriggers(UInt32 mask) = 0;
            /**
             * @brief Add given triggers to the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessOutputTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 AddTriggers(UInt32 mask) = 0;
            /**
             * @brief Remove given triggers from the currently set traversal triggers.
             * @param mask A bit mask of individual triggers, from the
             *  Graph::INode::ProcessOutputTriggers enumeration.
             * @return The previous triggers' bit mask.
             */
            virtual UInt32 RemoveTriggers(UInt32 mask) = 0;

            /**
             * @brief Check the traversal response for a given set of triggers.
             * @param mask A bit mask of individual triggers to query for, from the
             *  Graph::INode::ProcessOutputTriggers enumeration.
             * @return A bit mask of affected triggers.
             */
            virtual UInt32 GetResponse(UInt32 mask) const = 0;

        protected:
            virtual ~IProcessOutputTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_PROCESS_OUTPUT_TRACKER_H__

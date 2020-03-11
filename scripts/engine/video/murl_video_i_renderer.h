// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_RENDERER_H__
#define __MURL_VIDEO_I_RENDERER_H__

#include "murl_video_i_renderer_registry.h"
#include "murl_system_time.h"
#include "murl_i_enums.h"
#include "murl_i_factory_object.h"

namespace Murl
{
    class IAppConfiguration;
    class IEngine;
    class IFeatureSet;
    class IMethodCall;
    class IVideoStream;
    class IVideoInterface;
    
    namespace Video
    {
        class IBatch;
        class IBone;
        class ICamera;
        class IDrawable;
        class IFrameBuffer;
        class IIndexBuffer;
        class IIndices;
        class ILight;
        class IMaterial;
        class IConstantBuffer;
        class IConstants;
        class IObject;
        class IProgram;
        class ITexture;
        class IView;
        class IVertexBuffer;
        class IVertices;

        /**
         * @ingroup MurlVideoRendererInterfaces
         * @interface IRenderer
         * The Video::IRenderer interface represents a generic video renderer.
         *
         * For most cases, an application does not need to directly interact with this interface.
         * Instead, using video-related nodes from the @ref MurlGraphNodeInterfaces or
         * @ref MurlGraphNodeClasses sections is the preferred way to implement visual output
         * functionality in a cross-platform manner.
         *
         * Accessing the video renderer interface directly may be useful in advanced use cases,
         * when creating custom video objects or even a complete custom renderer suite.
         */
        class IRenderer : public IFactoryObject<IRenderer>, public IRendererRegistry
        {
        public:
            typedef IRenderer* (*CreateFunction)();
            
        public:
            /**
             * @brief Get the underlying video API.
             * @return The used video API.
             */
            virtual IEnums::VideoApi GetApi() const = 0;

            /**
             * @brief Get the number of supported shader languages.
             * If the renderer does not support programmable shaders, this method returns 0.
             * Otherwise, the number of supported languages is returned, the individual languages
             * can be queried using GetSupportedShaderLanguage() with an index from 0 to
             * GetNumberOfSupportedShaderLanguages()-1; the most preferrable shader language
             * can be found at index 0.
             * @return The number of supported languages.
             */
            virtual UInt32 GetNumberOfSupportedShaderLanguages() const = 0;
            /**
             * @brief Get the supported shader language for a given index.
             * @param index The index, from 0 to GetNumberOfSupportedShaderLanguages()-1.
             * @return The supported language.
             */
            virtual IEnums::ShaderLanguage GetSupportedShaderLanguage(UInt32 index) const = 0;

            /**
             * @brief Initialize the renderer.
             * @param engine The engine to attach to.
             * @param appConfig The application configuration object.
             * @param features The feature set to possibly update according to this renderer' capabilities.
             * @param videoInterface An interface to the platform front end's video interface for managing
             *      contexts etc.
             * @param sizeX The initial horizontal output surface size in pixels.
             * @param sizeY The initial vertical output surface size in pixels.
             * @return true if successful.
             */
            virtual Bool Init(IEngine* engine, const IAppConfiguration* appConfig, IFeatureSet* features, IVideoInterface* videoInterface, UInt32 sizeX, UInt32 sizeY) = 0;
            /**
             * @brief Deinitialize the renderer.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Start the renderer after it has been initialized.
             * @return true if successful.
             */
            virtual Bool Start() = 0;
            /**
             * @brief Stop the renderer before it gets deinitialized.
             * @return true if successful.
             */
            virtual Bool Stop() = 0;

            /**
             * @brief Pause the renderer if it is running.
             * @return true if successful.
             */
            virtual Bool Pause() = 0;
            /**
             * @brief Continue the renderer if it is paused.
             * @return true if successful.
             */
            virtual Bool Continue() = 0;

            /**
             * @brief Suspend the renderer.
             * @return true if successful.
             */
            virtual Bool Suspend() = 0;
            /**
             * @brief Resume the renderer.
             * @return true if successful.
             */
            virtual Bool Resume() = 0;

            /**
             * @brief Get the available features.
             * @return The set of available features.
             */
            virtual const IFeatureSet* GetFeatures() const = 0;

            /**
             * @brief Create a renderer object.
             * @param className The class name of the renderer object to create.
             * @return The newly created object, or null if failed.
             */
            virtual IObject* CreateObject(const String& className) = 0;
            /**
             * @brief Destroy an object that was created by this renderer.
             * @param object A reference to a pointer containing the object to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyObject(IObject*& object) = 0;

            /**
             * @brief Create a renderer batch.
             * @return The newly created batch, or null if failed.
             */
            virtual IBatch* CreateBatch() = 0;
            /**
             * @brief Destroy a batch that was created by this renderer.
             * @param batch A reference to a pointer containing the batch to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyBatch(IBatch*& batch) = 0;

            /**
             * @brief Set the current output surface dimensions.
             * @param sizeX The current horizontal output surface size in pixels.
             * @param sizeY The current vertical output surface size in pixels.
             * @return true if successful.
             */
            virtual Bool SetOutputSize(UInt32 sizeX, UInt32 sizeY) = 0;

            /**
             * @brief Begin submission of renderer objects for the next frame.
             * Any calls to state-changing methods like SetCurrentMaterial(), SetCurrentCamera() etc. 
             * as well as any queueing methods like PushObjectForRendering() must happen between a call
             * to this method and the corresponding EndSubmission() call.
             * @return true if successful.
             */
            virtual Bool BeginSubmission() = 0;
            /**
             * @brief End submission of renderer objects for the next frame.
             * @return true if successful.
             */
            virtual Bool EndSubmission() = 0;

            /**
             * @brief Start the actual rendering process after all current objects have been submitted.
             * @param triggerSuspend If true, all objects registered for manual resource suspension are
             *      triggered to release any resources that are not currently needed.
             * @return true if successful.
             */
            virtual Bool BeginRendering(Bool triggerSuspend) = 0;
            /**
             * @brief Wait for the current rendering process to complete, after calling BeginRendering().
             * @return true if successful.
             */
            virtual Bool EndRendering() = 0;

            /**
             * @brief Start the rendering process for an existing static batch.
             * @param batch The batch to render.
             * @return true if successful.
             */
            virtual Bool BeginBatchRendering(IBatch* batch) = 0;
            /**
             * @brief Finalize the rendering process for an existing static batch.
             * @param batch The batch to render.
             * @return true if successful.
             */
            virtual Bool EndBatchRendering(IBatch* batch) = 0;

            /**
             * @brief Register the actual render (main) thread with the renderer.
             * @param threadId The thread ID of the main thread.
             * @return true if successful.
             */
            virtual Bool RegisterRenderThread(UInt64 threadId) = 0;
            /**
             * @brief Register the logic processing thread with the renderer.
             * @param threadId The thread ID of the logic thread.
             * @return true if successful.
             */
            virtual Bool RegisterLogicThread(UInt64 threadId) = 0;
            /**
             * @brief Register the background loader thread with the renderer.
             * @param threadId The thread ID of the loader thread.
             * @return true if successful.
             */
            virtual Bool RegisterLoaderThread(UInt64 threadId) = 0;
            
            /**
             * @brief Unregister a render (main) thread from the renderer.
             * @param threadId The thread ID of the main thread.
             * @return true if successful.
             */
            virtual Bool UnregisterRenderThread(UInt64 threadId) = 0;
            /**
             * @brief Unregister a logic processing thread from the renderer.
             * @param threadId The thread ID of the logic thread.
             * @return true if successful.
             */
            virtual Bool UnregisterLogicThread(UInt64 threadId) = 0;
            /**
             * @brief Unregister a background loader thread from the renderer.
             * @param threadId The thread ID of the loader thread.
             * @return true if successful.
             */
            virtual Bool UnregisterLoaderThread(UInt64 threadId) = 0;

            /**
             * @brief Register an object for automatic resource suspension.
             * @param object The object to register.
             * @return true if successful.
             */
            virtual Bool RegisterAutomaticallySuspendableObject(IObject* object) = 0;
            /**
             * @brief Unregister an object from automatic resource suspension.
             * @param object The object to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterAutomaticallySuspendableObject(IObject* object) = 0;

            /**
             * @brief Register an object for manual resource suspension.
             * @param object The object to register.
             * @return true if successful.
             */
            virtual Bool RegisterManuallySuspendableObject(IObject* object) = 0;
            /**
             * @brief Unregister an object from manual resource suspension.
             * @param object The object to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterManuallySuspendableObject(IObject* object) = 0;

            /**
             * @brief Invoke a call to an object method on a suitable render thread.
             * If the platform supports video API calls on a thread other than the (single)
             * main render thread, this feature is also enabled in the engine configuration
             * (See IEngineConfiguratioh::SetAsyncLoadingEnabled()), and the current thread
             * is not the logic thread, this method tries to directly call the given method.
             * Otherwise, and also if the force parameter is set to true, the call is
             * invoked on the main render thread and this method blocks until the call
             * is finished.
             * @param call A call handle, obtained via Util::CreateMethodCall().
             * @param force If true, main thread invocation is forced.
             * @return true if successful.
             */
            virtual Bool InvokeOnRenderThread(const IMethodCall* call, Bool force) const = 0;

            /**
             * @brief Set the current camera affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param camera The camera to activate.
             */
            virtual void SetCurrentCamera(ICamera* camera) = 0;
            /**
             * @brief Set the current layer affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param layer The layer index to set.
             */
            virtual void SetCurrentLayer(UInt32 layer) = 0;
            
            /**
             * @brief Set the current world transform affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param transform The world transform to apply.
             * @param depthOrder The depth (sorting) order.
             */
            virtual void SetCurrentTransform(const Matrix* transform, SInt32 depthOrder) = 0;
            
            /**
             * @brief Set the current material affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param material The material to apply.
             */
            virtual void SetCurrentMaterial(IMaterial* material) = 0;
            /**
             * @brief Set the current shader variables affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param constants The shader variables to apply.
             */
            virtual void SetCurrentConstants(IConstants* constants) = 0;
            
            /**
             * @brief Set a single texture at a given unit affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param texture The texture to apply.
             * @param unit The texture unit, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             */
            virtual void SetCurrentTexture(ITexture* texture, UInt32 unit) = 0;
            /**
             * @brief Set the number of active texture units affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param numberOfUnitsUsed The current number of active texture units,
             *      from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             */
            virtual void SetCurrentNumberOfTextureUnitsUsed(UInt32 numberOfUnitsUsed) = 0;
            /**
             * @brief Set multiple texture units affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param textures An array of textures to apply.
             * @param numberOfUnitsUsed The actual number of textures to activate,
             *      from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             */
            virtual void SetCurrentTextures(ITexture** textures, UInt32 numberOfUnitsUsed) = 0;
            
            /**
             * @brief Set a single light source at a given unit affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param light The light source to apply.
             * @param unit The light unit, from 0 to IEnums::NUM_LIGHT_UNITS-1.
             */
            virtual void SetCurrentLight(ILight* light, UInt32 unit) = 0;
            /**
             * @brief Set the number of active light source units affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param numberOfUnitsUsed The current number of active light units,
             *      from 0 to IEnums::NUM_LIGHT_UNITS-1.
             */
            virtual void SetCurrentNumberOfLightUnitsUsed(UInt32 numberOfUnitsUsed) = 0;
            /**
             * @brief Set multiple light source units affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param lights An array of light sources to apply.
             * @param numberOfUnitsUsed The actual number of light sources to activate,
             *      from 0 to IEnums::NUM_LIGHT_UNITS-1.
             */
            virtual void SetCurrentLights(ILight** lights, UInt32 numberOfUnitsUsed) = 0;
            
            /**
             * @brief Set a single bone at a given unit affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param bone The bone to apply.
             * @param unit The bone unit, from 0 to IEnums::NUM_BONE_UNITS-1.
             */
            virtual void SetCurrentBone(IBone* bone, UInt32 unit) = 0;
            /**
             * @brief Set the number of active bone units affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param numberOfUnitsUsed The current number of active bone units,
             *      from 0 to IEnums::NUM_BONE_UNITS-1.
             */
            virtual void SetCurrentNumberOfBoneUnitsUsed(UInt32 numberOfUnitsUsed) = 0;
            /**
             * @brief Set multiple bone units affecting subsequent drawables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param bones An array of bones to apply.
             * @param numberOfUnitsUsed The actual number of bones to activate,
             *      from 0 to IEnums::NUM_BONE_UNITS-1.
             */
            virtual void SetCurrentBones(IBone** bones, UInt32 numberOfUnitsUsed) = 0;
            
            /**
             * @brief Queue up an object for updating.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param object The object to queue up.
             * @param localTime The time stamp.
             */
            virtual void PushObjectForUpdate(IObject* object, Real localTime = 0.0) = 0;
            /**
             * @brief Queue up a drawable object for rendering.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param vertices The drawable's vertices to queue up.
             * @param indices The drawable's optional indices to queue up.
             */
            virtual void PushObjectForRendering(IVertices* vertices, IIndices* indices) = 0;
            /**
             * @brief Queue up a drawable object for rendering.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param drawable The drawable to queue up.
             */
            virtual void PushObjectForRendering(IDrawable* drawable) = 0;
            /**
             * @brief Queue up a static batch for rendering.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param batch The batch to queue up.
             */
            virtual void PushBatchForRendering(IBatch* batch) = 0;

            /**
             * @brief Get the current number of texture units needed for rendering.
             * @return The number of active texture units.
             */
            virtual UInt32 GetCurrentNumberOfTextureUnitsNeeded() const = 0;
            /**
             * @brief Get the current number of light units needed for rendering.
             * @return The number of active light units.
             */
            virtual UInt32 GetCurrentNumberOfLightUnitsNeeded() const = 0;
            /**
             * @brief Get the current number of bone units needed for rendering.
             * @return The number of active bone units.
             */
            virtual UInt32 GetCurrentNumberOfBoneUnitsNeeded() const = 0;

            /**
             * @brief Get the currently active shader's light texture unit, if used.
             * When the currently active shader renders projective lights, this method
             * returns the shader's actually used texture unit for a given light unit.
             * Otherwise, -1 is returned.
             * @param lightUnit The light unit to check.
             * @return The texture unit used. or -1 if not used.
             */
            virtual SInt32 GetCurrentLightTextureUnit(UInt32 lightUnit) const = 0;

            /**
             * @brief Query the number of most recently rendered objects.
             * Must be called after EndRendering().
             * @return The number of objects renderered.
             */
            virtual UInt32 GetRecentNumberOfObjectsRendered() const = 0;
            /**
             * @brief Query the number of most recently rendered object batches.
             * Must be called after EndRendering().
             * @return The number of batches renderered.
             */
            virtual UInt32 GetRecentNumberOfBatchesRendered() const = 0;
            /**
             * @brief Query the number objects suspended after the most recent cycle.
             * Must be called after EndRendering().
             * @return The number of suspended objects.
             */
            virtual UInt32 GetRecentNumberOfSuspendedObjects() const = 0;

            /**
             * @brief Query the total number of allocated resource bytes.
             * Must be called after EndRendering().
             * @return The number of allocated bytes.
             */
            virtual UInt32 GetRecentNumberOfAllocatedResourceBytes() const = 0;

            /**
             * @brief Acquire a unique integer ID from a given index buffer name.
             * @param indexBufferName The name of the index buffer.
             * @return The unique index buffer ID.
             */
            virtual SInt32 AcquireIndexBufferId(const String& indexBufferName) = 0;
            /**
             * @brief Acquire a unique integer ID from a given vertex buffer name.
             * @param vertexBufferName The name of the vertex buffer.
             * @return The unique vertex buffer ID.
             */
            virtual SInt32 AcquireVertexBufferId(const String& vertexBufferName) = 0;
            /**
             * @brief Acquire a unique integer ID from a given constant buffer name.
             * @param constantBufferName The name of the constant buffer.
             * @return The unique constant buffer ID.
             */
            virtual SInt32 AcquireConstantBufferId(const String& constantBufferName) = 0;
            /**
             * @brief Acquire a unique integer ID from a given uniform variable name.
             * @param uniformName The name of the uniform variable.
             * @return The unique uniform variable ID.
             */
            virtual SInt32 AcquireUniformId(const String& uniformName) = 0;
            /**
             * @brief Acquire a unique integer ID from a given attribute variable name.
             * @param attributeName The name of the attribute variable.
             * @return The unique attribute variable ID.
             */
            virtual SInt32 AcquireAttributeId(const String& attributeName) = 0;

            /**
             * @brief Get the actual name of an index buffer by its unique integer ID.
             * @param id The unique integer ID.
             * @return The index buffer name, or an empty string if not found.
             */
            virtual const String& GetIndexBufferName(SInt32 id) const = 0;
            /**
             * @brief Get the actual name of an vertex buffer by its unique integer ID.
             * @param id The unique integer ID.
             * @return The vertex buffer name, or an empty string if not found.
             */
            virtual const String& GetVertexBufferName(SInt32 id) const = 0;
            /**
             * @brief Get the actual name of an constant buffer by its unique integer ID.
             * @param id The unique integer ID.
             * @return The constant buffer name, or an empty string if not found.
             */
            virtual const String& GetConstantBufferName(SInt32 id) const = 0;
            /**
             * @brief Get the actual name of a uniform variable by its unique integer ID.
             * @param id The unique integer ID.
             * @return The uniform variable name, or an empty string if not found.
             */
            virtual const String& GetUniformName(SInt32 id) const = 0;
            /**
             * @brief Get the actual name of an attribute variable by its unique integer ID.
             * @param id The unique integer ID.
             * @return The attribute variable name, or an empty string if not found.
             */
            virtual const String& GetAttributeName(SInt32 id) const = 0;

            /**
             * @brief Acquire a signature for a given constant buffer object.
             * @param constantBuffer The constant buffer for which to acquire the signature.
             * @return The signature.
             */
            virtual UInt32 AcquireConstantBufferSignature(const IConstantBuffer* constantBuffer) = 0;
            /**
             * @brief Release the signature of a given constant buffer object.
             * @param constantBuffer The constant buffer for which to release the signature.
             * @return true if successful.
             */
            virtual Bool ReleaseConstantBufferSignature(const IConstantBuffer* constantBuffer) = 0;
            
            /**
             * @brief Acquire a signature for a given constant buffer group object.
             * @param constants The constant buffer group for which to acquire the signature.
             * @return The signature.
             */
            virtual UInt32 AcquireConstantsSignature(const IConstants* constants) = 0;
            /**
             * @brief Release the signature of a given constant buffer group object.
             * @param constants The constant buffer group for which to release the signature.
             * @return true if successful.
             */
            virtual Bool ReleaseConstantsSignature(const IConstants* constants) = 0;
            
            /**
             * @brief Acquire a signature for a given index buffer object.
             * @param indexBuffer The index buffer for which to acquire the signature.
             * @return The signature.
             */
            virtual UInt32 AcquireIndexBufferSignature(const IIndexBuffer* indexBuffer) = 0;
            /**
             * @brief Release the signature of a given index buffer object.
             * @param indexBuffer The index buffer for which to release the signature.
             * @return true if successful.
             */
            virtual Bool ReleaseIndexBufferSignature(const IIndexBuffer* indexBuffer) = 0;
            
            /**
             * @brief Acquire a signature for a given index buffer group object.
             * @param indices The index buffer group for which to acquire the signature.
             * @return The signature.
             */
            virtual UInt32 AcquireIndicesSignature(const IIndices* indices) = 0;
            /**
             * @brief Release the signature of a given index buffer group object.
             * @param indices The index buffer group for which to release the signature.
             * @return true if successful.
             */
            virtual Bool ReleaseIndicesSignature(const IIndices* indices) = 0;
            
            /**
             * @brief Acquire a signature for a given vertex buffer object.
             * @param vertexBuffer The vertex buffer for which to acquire the signature.
             * @return The signature.
             */
            virtual UInt32 AcquireVertexBufferSignature(const IVertexBuffer* vertexBuffer) = 0;
            /**
             * @brief Release the signature of a given vertex buffer object.
             * @param vertexBuffer The vertex buffer for which to release the signature.
             * @return true if successful.
             */
            virtual Bool ReleaseVertexBufferSignature(const IVertexBuffer* vertexBuffer) = 0;
            
            /**
             * @brief Acquire a signature for a given vertex buffer group object.
             * @param vertices The vertex buffer group for which to acquire the signature.
             * @return The signature.
             */
            virtual UInt32 AcquireVerticesSignature(const IVertices* vertices) = 0;
            /**
             * @brief Release the signature of a given vertex buffer group object.
             * @param vertices The vertex buffer group for which to release the signature.
             * @return true if successful.
             */
            virtual Bool ReleaseVerticesSignature(const IVertices* vertices) = 0;

            /**
             * @brief Increase the internal suspended object count by 1.
             * Called by an object entering the suspended state.
             */
            virtual void IncreaseNumberOfSuspendedObjects() = 0;
            /**
             * @brief Decrease the internal suspended object count by 1.
             * Called by an object leaving the suspended state.
             */
            virtual void DecreaseNumberOfSuspendedObjects() = 0;

            /**
             * @brief Increase the internal number of allocated resource bytes.
             * Called by an object whenever it allocates a new memory resource.
             * @param numBytes The number of newly allocated bytes.
             */
            virtual void IncreaseNumberOfAllocatedResourceBytes(UInt32 numBytes) = 0;
            /**
             * @brief Decrease the internal number of allocated resource bytes.
             * Called by an object whenever it releases a memory resource.
             * @param numBytes The number of freed bytes.
             */
            virtual void DecreaseNumberOfAllocatedResourceBytes(UInt32 numBytes) = 0;

            /** 
             * @brief Validate a frame buffer format.
             * @param colorPixelFormat The color buffer pixel format to check.
             * @param depthBufferFormat The depth buffer format to check.
             * @param stencilBufferFormat The stencil buffer format to check.
             * @return true if the given buffer format combination represents a valid frame
             *      buffer format.
             */
            virtual Bool ValidateFrameBufferFormat(IEnums::PixelFormat& colorPixelFormat, IEnums::DepthBufferFormat& depthBufferFormat, IEnums::StencilBufferFormat& stencilBufferFormat) = 0;

            /**
             * @brief Take a screenshot.
             * @param outputStream The video stream receiving the current screen shot.
             * @param windowOrientation The window orientation.
             * @return true if successful.
             */
            virtual Bool TakeScreenshot(IVideoStream* outputStream, IEnums::Orientation windowOrientation) = 0;
            
        protected:
            virtual ~IRenderer() {}

            friend class Factory;
        };
    }
}

#endif // __MURL_VIDEO_I_RENDERER_H__

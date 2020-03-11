// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_I_RENDERER_H__
#define __MURL_AUDIO_I_RENDERER_H__

#include "murl_audio_i_renderer_registry.h"
#include "murl_graph_types.h"
#include "murl_i_factory_object.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAppConfiguration;
    class IAudioInterface;
    class IEngine;
    class IFeatureSet;
    
    namespace Audio
    {
        class IPlayable;
        class IBuffer;
        class IListener;
        class IView;

        /**
         * @ingroup MurlAudioRendererInterfaces
         * @interface IRenderer
         * The Audio::IRenderer interface represents a generic audio renderer. 
         * 
         * For most cases, an application does not need to directly interact with this interface. 
         * Instead, using audio-related nodes from the @ref MurlGraphNodeInterfaces or 
         * @ref MurlGraphNodeClasses sections is the preferred way to implement sound output
         * functionality in a cross-platform manner.
         *
         * Accessing the audio renderer interface directly may be useful in advanced use cases,
         * when creating custom audio objects or even a complete custom renderer suite.
         */
        class IRenderer : public IFactoryObject<IRenderer>, public IRendererRegistry
        {
        public:
            typedef IRenderer* (*CreateFunction)();
            
        public:
            /**
             * @brief Get the underlying audio API.
             * @return The used audio API.
             */
            virtual IEnums::AudioApi GetApi() const = 0;

            /**
             * @brief Initialize the renderer.
             * @param engine The engine to attach to.
             * @param appConfig The application configuration object.
             * @param features The feature set to possibly update according to this renderer' capabilities.
             * @param audioInterface An interface to the platform front end's audio interface for managing
             *      contexts etc.
             * @return true if successful.
             */
            virtual Bool Init(IEngine* engine, const IAppConfiguration* appConfig, IFeatureSet* features, IAudioInterface* audioInterface) = 0;
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
             * @brief Begin submission of renderer objects for the next frame.
             * Any calls to SetCurrentListener() and SetCurrentTransform(), as well as
             * PushObjectForUpdate() and PushObjectForRendering() must happen between a call to this
             * method and the corresponding EndSubmission() call.
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
             * @brief Register a render (main) thread with the renderer.
             * @param threadId The thread ID of the main thread.
             * @return true if successful.
             */
            virtual Bool RegisterRenderThread(UInt64 threadId) = 0;
            /**
             * @brief Register a logic processing thread with the renderer.
             * @param threadId The thread ID of the logic thread.
             * @return true if successful.
             */
            virtual Bool RegisterLogicThread(UInt64 threadId) = 0;
            /**
             * @brief Register a background loader thread with the renderer.
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
             * @brief Set the current listener affecting subsequent playables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param listener The listener to set.
             */
            virtual void SetCurrentListener(IListener* listener) = 0;
            /**
             * @brief Set the current world transform affecting subsequent playables.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param transform The world transform to set.
             */
            virtual void SetCurrentTransform(const Matrix* transform) = 0;

            /**
             * @brief Queue up an object for updating.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param object The object to queue up.
             * @param localTime The time stamp.
             */
            virtual void PushObjectForUpdate(IObject* object, Real localTime = 0.0) = 0;
            /**
             * @brief Queue up a playable object for rendering.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param object The playable object to queue up.
             * @param localTime The time stamp.
             */
            virtual void PushObjectForRendering(IPlayable* object, Real localTime) = 0;

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

            // TODO: Create filters & filter states for modifying playables during playback
            //       Analogous to materials in the video renderer
            
            // TODO: Create ambient effects like hall, dampen etc.
            //       Analogous to light sources in the video renderer
            
        protected:
            virtual ~IRenderer() {}

            friend class Factory;
        };
    }
}

#endif // __MURL_AUDIO_I_RENDERER_H__

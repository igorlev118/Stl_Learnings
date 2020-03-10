// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_ENGINE_H__
#define __MURL_I_ENGINE_H__

#include "murl_types.h"

namespace Murl
{
    class IApp;
    class IEngineConfiguration;
    class IDeviceHandler;
    class IMethodCall;

    namespace Core
    {
        class IClock;
    }

    /**
     * @ingroup MurlInterfaces
     * @interface IEngine
     * @brief The main engine interface.
     * The engine interface is created by the Murl::Factory.
     */
    class IEngine
    {
    public:
        /**
         * @brief Initialize the engine.
         * Upon initialization, all sub-components of the engine are created and initialized.
         *
         * @param app The app
         * @param engineConfig The mutable engine configuration.
         * @param deviceHandler A device handler instance that allows the engine to interact
         *        with various available input devices, such as keyboard, mouse, touch screen
         *        etc., as well as output devices such as rumble devices or e.g. system dialog.
         * @return true if successful.
         */
        virtual Bool Init(IApp* app, IEngineConfiguration* engineConfig, IDeviceHandler* deviceHandler) = 0;
        
        /**
         * @brief De-initialize the engine.
         * Upon de-initialization, all sub-components of the engine are shut down and destroyed.
         * @return true if successful.
         */
        virtual Bool DeInit() = 0;
        
        /**
         * @brief Start the engine.
         * Start up all engine treads and start loading resources.
         * \n The engine can be started if Init() was successful.
         * @return true if successful.
         */
        virtual Bool Start() = 0;
        
        /**
         * @brief Stop the started engine.
         * Shut down all engine threads and destroy all resources.
         * \n The engine will stop if Start() was successful.
         * @return true if successful.
         */
        virtual Bool Stop() = 0;
        
        /**
         * @brief Pause the engine.
         * The paused engine holds processing logic ticks until Continue() is called,
         * but frame updates are processed further on.
         * \n The engine can be paused if Start() was successful.
         * @return true if successful.
         */
        virtual Bool Pause() = 0;
        
        /**
         * @brief Continue the paused engine.
         * Continues logic ticks processing.
         * \n The engine will continue if Pause() was successful.
         * @return true if successful.
         */
        virtual Bool Continue() = 0;
        
        /**
         * @brief Suspend the engine.
         * The suspended engine holds processing logic ticks and frame updates
         * and unloads suspendable resources until Resume() is called.
         * \n The engine can be suspended if Start() was successful.
         * @return true if successful.
         */
        virtual Bool Suspend() = 0;
        
        /**
         * @brief Resume the suspended engine.
         * Reloads suspendable resources and continues processing logic ticks
         * and frame updates.
         * \n The engine will resume if Suspend() was successful.
         * @return true if successful.
         */
        virtual Bool Resume() = 0;
        
        /**
         * @brief Begin rendering a frame.
         * This method must be called from a valid render thread context.
         * This method returns when the rendering is done and the
         * video double buffer can be swapped.
         * @return true if successful, if false is returned
         *  the platform code typically quits the application.
         */
        virtual Bool BeginFrame() = 0;
        
        /**
         * @brief End rendering a frame.
         * When swapping the video double buffer has been finished,
         * this method must be called from a valid render thread context.
         * @return true if successful, if false is returned
         *  the platform code typically quits the application.
         */
        virtual Bool EndFrame() = 0;
        
        /**
         * @brief Invoke a method in the render thread context.
         * The render thread context is the context of the EndFrame() caller.
         * The invoke call is waiting until the method was processed.
         * This method is intend for internal use only.
         * @param call The method call object.
         * @param waitForMore If true, the engine continues processing the message
         *      loop for a given maximum amount of time, in order to e.g. speed up
         *      initialization of multiple render objects in a sequence. The maximum
         *      time can be set via IEngineConfiguration::SetSyncLoadingTimeout().
         * @return true if successful.
         */
        virtual Bool Invoke(const IMethodCall* call, Bool waitForMore) = 0;

        /**
         * @brief Get the system clock.
         * @return The system clock.
         */
        virtual const Core::IClock* GetClock() const = 0;

    protected:
        virtual ~IEngine() {}
    };
}

#endif  // __MURL_I_ENGINE_H__

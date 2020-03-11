// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_AUDIO_INTERFACE_H__
#define __MURL_I_AUDIO_INTERFACE_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IAudioInterface
     * @brief The audio interface.
     */
    class IAudioInterface
    {
    public:
        /**
         * @brief Check if the interface supports shared contexts.
         * @return true if the interface supports shared contexts.
         */
        virtual Bool CanShareContexts() const = 0;
        
        /**
         * @brief Get the audio render context.
         * @return The audio render context.
         */
        virtual void* GetRenderContext() = 0;
        /**
         * @brief Activate the audio render context.
         * @return true if successful.
         */
        virtual Bool ActivateRenderContext() = 0;
        /**
         * @brief Deactivate the audio render context.
         * @return true if successful.
         */
        virtual Bool DeactivateRenderContext() = 0;
        /**
         * @brief Check if the audio render context is active.
         * @return true if active.
         */
        virtual Bool IsRenderContextActive() const = 0;

        /**
         * @brief Get the audio loader context.
         * @return The audio loader context.
         */
        virtual void* GetLoaderContext() = 0;
        /**
         * @brief Activate the audio loader context.
         * @return true if successful.
         */
        virtual Bool ActivateLoaderContext() = 0;
        /**
         * @brief Deactivate the audio loader context.
         * @return true if successful.
         */
        virtual Bool DeactivateLoaderContext() = 0;
        /**
         * @brief Check if the audio loader context is active.
         * @return true if active.
         */
        virtual Bool IsLoaderContextActive() const = 0;

    protected:
        virtual ~IAudioInterface() {}
    };
}

#endif  // __MURL_I_AUDIO_INTERFACE_H__

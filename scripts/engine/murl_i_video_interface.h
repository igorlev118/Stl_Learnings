// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_VIDEO_INTERFACE_H__
#define __MURL_I_VIDEO_INTERFACE_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IVideoInterface
     * @brief The video interface.
     */
    class IVideoInterface
    {
    public:
        /**
         * @brief Check if the interface supports shared contexts.
         * @return true if the interface supports shared contexts.
         */
        virtual Bool CanShareContexts() const = 0;
        
        /**
         * @brief Create a shared context.
         * @return The shared context.
         */
        virtual void* CreateSharedContext() = 0;
        /**
         * @brief Destroy a shared context.
         * @param context The shared context.
         */
        virtual void DestroySharedContext(void* context) = 0;
        /**
         * @brief Activate a shared context.
         * @param context The shared context.
         * @return true if successful.
         */
        virtual Bool ActivateSharedContext(void* context) = 0;
        /**
         * @brief Deactivate a shared context.
         * @param context The shared context.
         * @return true if successful.
         */
        virtual Bool DeactivateSharedContext(void* context) = 0;
        
        /**
         * @brief Get the video render context.
         * @return The video render context.
         */
        virtual void* GetRenderContext() = 0;
        /**
         * @brief Activate the video render context.
         * @return true if successful.
         */
        virtual Bool ActivateRenderContext() = 0;
        /**
         * @brief Deactivate the video render context.
         * @return true if successful.
         */
        virtual Bool DeactivateRenderContext() = 0;
        /**
         * @brief Check if the video render context is active.
         * @return true if active.
         */
        virtual Bool IsRenderContextActive() const = 0;

        /**
         * @brief Get the video loader context.
         * @return The video loader context.
         */
        virtual void* GetLoaderContext() = 0;
        /**
         * @brief Activate the video loader context.
         * @return true if successful.
         */
        virtual Bool ActivateLoaderContext() = 0;
        /**
         * @brief Deactivate the video loader context.
         * @return true if successful.
         */
        virtual Bool DeactivateLoaderContext() = 0;
        /**
         * @brief Check if the video loader context is active.
         * @return true if active.
         */
        virtual Bool IsLoaderContextActive() const = 0;

        /**
         * @brief Activate the back buffer for rendering.
         * @return true if successful.
         */
        virtual Bool ActivateBackBuffer() = 0;
        /**
         * @brief Deactivate the back buffer.
         * @return true if successful.
         */
        virtual Bool DeactivateBackBuffer() = 0;
        
    protected:
        virtual ~IVideoInterface() {}
    };
}

#endif  // __MURL_I_VIDEO_INTERFACE_H__

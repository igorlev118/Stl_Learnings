// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_SCREENSHOT_CONTROL_H__
#define __MURL_I_SCREENSHOT_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Resource
    {
        class IImage;
    }
    
    /**
     * @ingroup MurlControlInterfaces
     * @interface IScreenshotControl
     * @brief The IScreenshotControl interface.
     */
    class IScreenshotControl : public IControlable
    {
    public:
        /**
         * @brief Create a screen shot of the next frame tick.
         * @return true if successful.
         */
        virtual Bool CreateScreenshot() = 0;
        /**
         * @brief Destroy the current screen shot.
         * @return true if successful.
         */
        virtual Bool DestroyScreenshot() = 0;
        
        /**
         * @brief Check if the current screen shot is in progress.
         * @return true if the current screen shot is in progress.
         */
        virtual Bool IsBusy() const = 0;
        /**
         * @brief Check if the current screen shot is ready to use.
         * @return true if the current screen shot is ready to use.
         */
        virtual Bool IsReady() const = 0;
        
        /**
         * @brief Get the current screen shot image.
         * @return The current screen shot image or null if no image is available.
         */
        virtual const Resource::IImage* GetScreenshotImage() const = 0;
        
    protected:
        virtual ~IScreenshotControl() {}
    };
}

#endif  // __MURL_I_SCREENSHOT_CONTROL_H__

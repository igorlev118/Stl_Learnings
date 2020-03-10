// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_APP_CONTROL_H__
#define __MURL_I_APP_CONTROL_H__

#include "murl_i_controlable.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IAppControl
     * @brief The IAppControl interface.
     */
    class IAppControl : public IControlable
    {
    public:
        /**
         * @brief Terminate (exit) the entire application within the next frame tick.
         * Terminating the application is not supported on iOS devices.
         * @return true if successful.
         */
        virtual Bool TerminateApp() = 0;
        /**
         * @brief Check if the application is terminated within the next frame tick.
         * @return true if the application is terminated within the next frame tick.
         */
        virtual Bool IsTerminateApp() const = 0;

        /**
         * @brief Set the current loading progress.
         * Setting the loading progress is an optional feature to communicate the
         * app's current loading state to the platform handler. By default, the
         * loading progress is set to 0.0 (unloaded).
         * @param progress The loading progress, between 0.0 and 1.0
         * @return true if successful.
         */
        virtual Bool SetLoadingProgress(Real progress) = 0;
        /**
         * @brief Get the current loading progress.
         * @return The current loading progress, between 0.0 and 1.0
         */
        virtual Real GetLoadingProgress() const = 0;

    protected:
        virtual ~IAppControl() {}
    };
}

#endif  // __MURL_I_APP_CONTROL_H__

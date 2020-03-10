// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_RUMBLE_CONTROL_H__
#define __MURL_I_RUMBLE_CONTROL_H__

#include "murl_i_controlable.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IRumbleControl
     * @brief The IRumbleControl interface.
     */
    class IRumbleControl : public IControlable
    {
    public:
        /**
         * @brief Trigger a rumble.
         * Note: Several devices do not support selecting a duration.
         * In such a case the device rumbles it's pre-defined duration.
         * @param duration Duration of the rumble in seconds.
         */
        virtual void Rumble(Float duration = 0.5 /* seconds */) = 0;
        
    protected:
        virtual ~IRumbleControl() {}
    };
}

#endif  // __MURL_I_RUMBLE_CONTROL_H__

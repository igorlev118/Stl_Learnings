// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_ORIENTATION_H__
#define __MURL_I_ORIENTATION_H__

#include "murl_i_enums.h"

namespace Murl
{
    /**
     * @ingroup MurlInputInterfaces
     * @interface IOrientation
     * @brief The orientation device interface.
     * Used by the platform to post events to the device.
     */
    class IOrientation
    {
    public:
        /**
         * @brief Post the current device orientation.
         * @param orientation The current device orientation.
         */
        virtual void PostEvent(IEnums::SensorOrientation orientation) = 0;
        
    protected:
        virtual ~IOrientation() {}
    };
}

#endif  // __MURL_I_ORIENTATION_H__

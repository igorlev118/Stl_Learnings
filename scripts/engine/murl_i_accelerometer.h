// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_ACCELEROMETER_H__
#define __MURL_I_ACCELEROMETER_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IAccelerometer
     * @brief The accelerometer device interface.
     * Used by the platform to post events to the device.
     */
    class IAccelerometer
    {
    public:
        /**
         * @brief Post the current accelerometer axis acceleration.
         * @param accelX The x-axis acceleration in meter per seconds^2.
         * @param accelY The y-axis acceleration in meter per seconds^2.
         * @param accelZ The z-axis acceleration in meter per seconds^2.
         */
        virtual void PostEvent(Real accelX, Real accelY, Real accelZ) = 0;
        
    protected:
        virtual ~IAccelerometer() {}
    };
}

#endif  // __MURL_I_ACCELEROMETER_H__

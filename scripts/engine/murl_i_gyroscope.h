// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_GYROSCOPE_H__
#define __MURL_I_GYROSCOPE_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IGyroscope
     * @brief The gyroscope device interface.
     * Used by the platform to post events to the device.
     */
    class IGyroscope
    {
    public:
        /**
         * @brief Post the current gyroscope angular velocity.
         * @param rotX The angular velocity around the x-axis in radians per second.
         * @param rotY The angular velocity around the y-axis in radians per second.
         * @param rotZ The angular velocity around the Z-axis in radians per second.
         */
        virtual void PostEvent(Real rotX, Real rotY, Real rotZ) = 0;

    protected:
        virtual ~IGyroscope() {}
    };
}

#endif  // __MURL_I_GYROSCOPE_H__

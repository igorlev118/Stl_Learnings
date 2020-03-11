// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_HEADING_H__
#define __MURL_I_HEADING_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IHeading
     * @brief The heading device interface.
     * Used by the platform to post events to the device.
     */
    class IHeading
    {
    public:
        /**
         * @brief Post the current geomagnetic data.
         * @param fieldX The geomagnetic data for the x-axis in microteslas.
         * @param fieldY The geomagnetic data for the y-axis in microteslas.
         * @param fieldZ The geomagnetic data for the z-axis in microteslas.
         * @param magneticAngle The angle relative to the magnetic north in degrees.
         *  The value 0 means the device is pointed toward magnetic north,
         *  90 means it is pointed east, 180 south, and 270 west.
         * @param trueAngle The angle relative to the true north in degrees.
         *  The value 0 means the device is pointed toward true north,
         *  90 means it is pointed east, 180 south, and 270 west.
         */
        virtual void PostEvent(Double fieldX, Double fieldY, Double fieldZ,
                               Double magneticAngle, Double trueAngle) = 0;
        
    protected:
        virtual ~IHeading() {}
    };
}

#endif  // __MURL_I_HEADING_H__

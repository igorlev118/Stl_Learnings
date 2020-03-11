// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_LOCATION_H__
#define __MURL_I_LOCATION_H__

#include "murl_i_enums.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface ILocation
     * @brief The location device interface.
     * Used by the platform to post events to the device.
     */
    class ILocation
    {
    public:
        /**
         * @brief Post the current location data.
         * @param latitude The latitude in degrees relative to the equator.
         *  Positive values indicate latitudes north of the equator.
         *  Negative values indicate latitudes south of the equator.
         * @param longitude The longitude in degrees relative to the zero meridian.
         *  Positive values extending east of the meridian and
         *  negative values extending west of the meridian.
         * @param altitude The altitude above sea level in meters.
         *  Positive values are above sea level and
         *  negative values are below sea level.
         * @param velocity The velocity over ground in meters per second.
         *  A negative value indicates an invalid speed.
         * @param horizontalAccuracy The radius of uncertainty for the location in meters.
         *  A negative value indicates that the latitude and longitude are invalid.
         * @param verticalAccuracy The accuracy of the altitude in meters.
         *  A negative value indicates that the altitude value is invalid.
         */
        virtual void PostEvent(Double latitude, Double longitude,
                               Double altitude, Double velocity,
                               Double horizontalAccuracy, Double verticalAccuracy) = 0;
        
        /**
         * @brief Post the current device authorization status.
         * @param authorization The current authorization status.
         */
        virtual void PostStatusEvent(IEnums::AuthorizationStatus authorization) = 0;
        
    protected:
        virtual ~ILocation() {}
    };
}

#endif  // __MURL_I_LOCATION_H__

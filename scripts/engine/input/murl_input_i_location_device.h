// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_LOCATION_DEVICE_H__
#define __MURL_INPUT_I_LOCATION_DEVICE_H__

#include "murl_input_i_device.h"
#include "murl_i_enums.h"

#include "murl_util_geo_location.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface ILocationDevice
         * @brief The ILocationDevice interface.
         * To receive data the device must be activated by
         * IAppConfiguration::SetLocationActive().
         */
        class ILocationDevice : public IDevice
        {
        public:
            /**
             * @brief Get the latitude in degrees relative to the equator.
             *  Use GetHorizontalAccuracy() to check validity.
             * @return The latitude in degrees relative to the equator.
             *  Positive values indicate latitudes north of the equator and
             *  negative values indicate latitudes south of the equator.
             */
            virtual Double GetLatitude() const = 0;

            /**
             * @brief Get the longitude in degrees relative to the zero meridian.
             *  Use GetHorizontalAccuracy() to check validity.
             * @return The longitude in degrees relative to the zero meridian.
             *  Positive values extending east of the meridian and
             *  negative values extending west of the meridian.
             */
            virtual Double GetLongitude() const = 0;

            /**
             * @brief Get the altitude above sea level in meters.
             *  Use GetVerticalAccuracy() to check validity.
             * @return The altitude above sea level in meters.
             *  Positive values are above sea level and
             *  negative values are below sea level.
             */
            virtual Double GetAltitude() const = 0;

            /**
             * @brief Get the latitude, longitude and altitude geo location.
             * @return The geo location object.
             */
            virtual Util::GeoLocation GetGeoLocation() const = 0;

            /**
             * @brief Get the velocity over ground in meters per second.
             *  A negative values indicates an invalid speed.
             * @return The velocity over ground in meters per second.
             */
            virtual Double GetVelocity() const = 0;

            /**
             * @brief Get the radius of uncertainty for the location in meters.
             *  A negative value indicates that the latitude and longitude are invalid.
             * @return The radius of uncertainty for the location in meters.
             */
            virtual Double GetHorizontalAccuracy() const = 0;

            /**
             * @brief Get the accuracy of the altitude in meters.
             *  A negative value indicates that the altitude value is invalid.
             * @return The accuracy of the altitude in meters.
             */
            virtual Double GetVerticalAccuracy() const = 0;

            /**
             * @brief Get the current device authorization status.
             * @return The current authorization status.
             */
            virtual IEnums::AuthorizationStatus GetAuthorization() const = 0;

        protected:
            virtual ~ILocationDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_LOCATION_DEVICE_H__

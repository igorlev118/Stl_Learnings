// Copyright 2013-2014 Spraylight GmbH

#ifndef __MURL_UTIL_GEO_LOCATION_H__
#define __MURL_UTIL_GEO_LOCATION_H__

#include "murl_input_i_accelerometer_device.h"
#include "murl_input_i_heading_device.h"
#include "murl_math_matrix.h"

namespace Murl
{
    namespace Util
    {
        typedef Math::Matrix<Real> Matrix;
        typedef Math::Vector<Real> Vector;

        /**
         * @ingroup MurlUtilClasses
         * @brief The geo location class.
         */
        class GeoLocation
        {
        public:
            /**
             * @brief Get the rotation matrix from acceleration and geomagnetic values.
             * @param acceleration The acceleration vector.
             * @param geomagnetic The geomagnetic field vector.
             * @return The rotation matrix.
             */
            static Matrix GetRotationMatrix(const Input::AccelerationVector& acceleration,
                                            const Input::MagneticFieldVector& geomagnetic);

            /**
             * @brief Get the geo rotation angles from a rotation matrix.
             * Extracts the following rotation angles:
             *  - Sets the vector member x to the pitch angle.
             *  - Sets the vector member y to the roll angle.
             *  - Sets the vector member z to the azimuth angle.
             * @param rotation The rotation matrix, typically from GetRotationMatrix().
             * @return The geo rotation angles in radiants.
             */
            static Vector GetRotationAngles(const Matrix& rotation);

            /**
             * @brief The default constructor.
             */
            GeoLocation();

            /**
             * @brief The constructor taking separate location values.
             * @param latitude The latitude in degrees relative to the equator.
             * @param longitude The longitude in degrees relative to the zero meridian.
             * @param altitude The altitude above sea level in meters.
             */
            GeoLocation(Double latitude, Double longitude, Double altitude);

            /**
             * @brief Check if the location is zero.
             * @return true if all location members are zero.
             */
            Bool IsZero() const;

            /**
             * @brief Calculate the distance from this location to a geo location.
             * The formula calculates on the basis of a spherical earth (ignoring
             * ellipsoidal effects) which is accurate enough for most purposes.
             * The altitude is not considered.\n
             * The calculation uses the simple spherical law of cosines formula.\n
             * distance = acos(sin(φ1) * sin(φ2) + cos(φ1) * cos(φ2) * cos(Δλ)) * earth radius.
             * @param location The geo location.
             * @return The distance to the geo location in meters.
             */
            Double GetDistance(const GeoLocation& location) const;

            /**
             * @brief Calculate the bearing angle between this and a geo locations.
             * The formula calculates on the basis of a spherical earth (ignoring
             * ellipsoidal effects) which is accurate enough for most purposes.
             * The altitude is not considered.\n
             * The formula is for the initial bearing (sometimes referred to as forward azimuth)
             * which if followed in a straight line along a great circle arc will take you from
             * the start point to the end point.\n
             * θ = atan2(sin(Δλ) * cos(φ2), cos(φ1) * sin(φ2) − sin(φ1) * cos(φ2) * cos(Δλ)).
             * @param location The geo location.
             * @return The bearing angle between this and the geo location
             *  in degrees in range [0 .. 360).
             */
            Double GetBearing(const GeoLocation& location) const;

            /**
             * @brief Calculate the destination geo location by a given
             * distance and bearing from this location.
             * The formula calculates on the basis of a spherical earth (ignoring
             * ellipsoidal effects) which is accurate enough for most purposes.\n
             * Given a start point, initial bearing, and distance, this will calculate the
             * destination point travelling along a great circle arc.\n
             * φ2 = asin(sin(φ1) * cos(d / R) + cos(φ1) * sin(d / R) * cos(θ))\n
             * λ2 = λ1 + atan2(sin(θ) * sin(d / R) * cos(φ1), cos(d / R) − sin(φ1) * sin(φ2))\n
             * φ is latitude, λ is longitude, θ is the bearing (clockwise from north),
             * d is the distance, R is the earth’s radius (d / R is the angular distance).
             * @param distance The distance to the destination geo location in meters.
             * @param bearing The bearing to the destination geo location in degrees.
             * @return The destination geo location including the altitude from this location.
             */
            GeoLocation GetDestination(Double distance, Double bearing) const;

            /// The latitude in degrees relative to the equator.
            Double mLatitude;
            /// The longitude in degrees relative to the zero meridian.
            Double mLongitude;
            /// The altitude above sea level in meters.
            Double mAltitude;

            /// The sphere radius in meters, default is the idealized earth radius of 6371000 meters.
            Double mRadius;
        };
    }
}

#endif // __MURL_UTIL_GEO_LOCATION_H__

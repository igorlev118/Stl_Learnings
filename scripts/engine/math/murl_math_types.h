// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_MATH_TYPES_H__
#define __MURL_MATH_TYPES_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlMathNamespaces
     * @brief Namespace containing mathematic related interfaces.
     */
    namespace Math
    {
        /**
         * @brief Definition of e.
         */
        const Double E          = 2.718281828459045;

        /**
         * @brief Definition of pi.
         */
        const Double PI         = 3.1415926535897932385E0;
        /**
         * @brief Definition of two pi.
         */
        const Double TWO_PI     = PI * 2.0;
        /**
         * @brief Definition of halve pi.
         */
        const Double HALF_PI    = PI / 2.0;
        /**
         * @brief Definition of inverse pi.
         */
        const Double INV_PI     = 1.0 / PI;
        /**
         * @brief Definition of inverse 2*pi.
         */
        const Double INV_TWO_PI = 0.5 / PI;
        /**
         * @brief Definition of inverse pi/2.
         */
        const Double INV_HALF_PI = 2.0 / PI;

        /**
         * @brief Definition of degrees to radians factor.
         */
        const Double DEG_TO_RAD = PI / 180.0;
        /**
         * @brief Definition of radians to degrees factor.
         */
        const Double RAD_TO_DEG = 180.0 / PI;

        /**
         * @brief Definition of millimeters to centimeters factor.
         */
        const Double MM_TO_CM     = 0.1;
        /**
         * @brief Definition of centimeters to millimeters factor.
         */
        const Double CM_TO_MM     = 10.0;

        /**
         * @brief Definition of millimeters to inches factor.
         */
        const Double MM_TO_INCHES = 1.0 / 25.4;
        /**
         * @brief Definition of centimeters to inches factor.
         */
        const Double CM_TO_INCHES = 1.0 / 2.54;

        /**
         * @brief Definition of inches to millimeters factor.
         */
        const Double INCHES_TO_MM = 25.4;
        /**
         * @brief Definition of inches to centimeters factor.
         */
        const Double INCHES_TO_CM = 2.54;
    }
}

#endif // __MURL_MATH_TYPES_H__

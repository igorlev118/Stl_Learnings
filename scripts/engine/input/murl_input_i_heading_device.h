// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_INPUT_I_HEADING_DEVICE_H__
#define __MURL_INPUT_I_HEADING_DEVICE_H__

#include "murl_input_i_device.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @brief Vector definition for geomagnetic field by axis.
         */
        typedef Math::Vector<Double> MagneticFieldVector;

        /**
         * @ingroup MurlInputInterfaces
         * @interface IHeadingDevice
         * @brief The IHeadingDevice interface.
         * To receive data the device must be activated by
         * IAppConfiguration::SetHeadingActive().
         */
        class IHeadingDevice : public IDevice
        {
        public:
            /**
             * @brief Get the geomagnetic field for the x-axis in microteslas.
             * @return The geomagnetic field for the x-axis in microteslas.
             */
            virtual Double GetMagneticFieldX() const = 0;

            /**
             * @brief Get the geomagnetic field for the y-axis in microteslas.
             * @return The geomagnetic field for the y-axis in microteslas.
             */
            virtual Double GetMagneticFieldY() const = 0;

            /**
             * @brief Get the geomagnetic field for the z-axis in microteslas.
             * @return The geomagnetic field for the z-axis in microteslas.
             */
            virtual Double GetMagneticFieldZ() const = 0;

            /**
             * @brief Get the geomagnetic field axes in microteslas.
             * @return The geomagnetic field axes in microteslas.
             */
            virtual MagneticFieldVector GetMagneticField() const = 0;

            /**
             * @brief Get the angle relative to the magnetic north in degrees.
             *  The value 0 means the device is pointed toward magnetic north,
             *  90 means it is pointed east, 180 means it is pointed south, and so on.
             * @return The angle relative to the magnetic north in degrees.
             */
            virtual Double GetMagneticAngle() const = 0;

            /**
             * @brief Get the angle relative to the true north in degrees.
             *  The value 0 means the device is pointed toward true north,
             *  90 means it is pointed east, 180 means it is pointed south, and so on.
             * @return The angle relative to the true north in degrees.
             */
            virtual Double GetTrueAngle() const = 0;

            /**
             * @brief Get the raw geomagnetic field axes in microteslas.
             * This method is useful to evaluate the absolute device orientation.
             * All other methods reports the values relative to the
             * current screen axis orientation.
             * @return The geomagnetic field axes in microteslas.
             */
            virtual MagneticFieldVector GetRawMagneticField() const = 0;

            /**
             * @brief Get the raw angle relative to the magnetic north in degrees.
             *  The value 0 means the device is pointed toward magnetic north,
             *  90 means it is pointed east, 180 means it is pointed south, and so on.
             *
             * This method is useful to evaluate the absolute device orientation.
             * All other methods reports the values relative to the
             * current screen axis orientation.
             * @return The angle relative to the magnetic north in degrees.
             */
            virtual Double GetRawMagneticAngle() const = 0;

            /**
             * @brief Get the raw angle relative to the true north in degrees.
             *  The value 0 means the device is pointed toward true north,
             *  90 means it is pointed east, 180 means it is pointed south, and so on.
             *
             * This method is useful to evaluate the absolute device orientation.
             * All other methods reports the values relative to the
             * current screen axis orientation.
             * @return The angle relative to the true north in degrees.
             */
            virtual Double GetRawTrueAngle() const = 0;
            
        protected:
            virtual ~IHeadingDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_HEADING_DEVICE_H__

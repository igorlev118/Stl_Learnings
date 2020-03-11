// Copyright 2010-2015 Spraylight

#ifndef __MURL_INPUT_I_ACCELEROMETER_DEVICE_H__
#define __MURL_INPUT_I_ACCELEROMETER_DEVICE_H__

#include "murl_input_i_device.h"
#include "murl_math_vector.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @brief Vector definition for acceleration by axis.
         */
        typedef Math::Vector<Double> AccelerationVector;

        /**
         * @ingroup MurlInputInterfaces
         * @interface IAccelerometerDevice
         * @brief The IAccelerometerDevice interface.
         * To receive data the device must be activated by
         * IAppConfiguration::SetAccelerometerActive().
         */
        class IAccelerometerDevice : public IDevice
        {
        public:
            /**
             * @brief Get the accelerometer x-axis acceleration.
             * @return The x-axis acceleration in meter per seconds^2.
             */
            virtual Real GetAccelerationX() const = 0;

            /**
             * @brief Get the accelerometer y-axis acceleration.
             * @return The y-axis acceleration in meter per seconds^2.
             */
            virtual Real GetAccelerationY() const = 0;

            /**
             * @brief Get the accelerometer z-axis acceleration.
             * @return The z-axis acceleration in meter per seconds^2.
             */
            virtual Real GetAccelerationZ() const = 0;

            /**
             * @brief Get the accelerometer axes acceleration.
             * @return The axes acceleration in meter per seconds^2.
             */
            virtual AccelerationVector GetAcceleration() const = 0;

            /**
             * @brief Get the raw accelerometer axes acceleration.
             * This method is useful to evaluate the absolute device orientation.
             * All other methods reports the values relative to the
             * current screen axis orientation.
             * @return The axes acceleration in meter per seconds^2.
             */
            virtual AccelerationVector GetRawAcceleration() const = 0;

        protected:
            virtual ~IAccelerometerDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_ACCELEROMETER_DEVICE_H__

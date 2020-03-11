// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_INPUT_I_GYROSCOPE_DEVICE_H__
#define __MURL_INPUT_I_GYROSCOPE_DEVICE_H__

#include "murl_input_i_device.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @brief Vector definition for angular velocity by axis.
         */
        typedef Math::Vector<Double> AngularVelocityVector;

        /**
         * @ingroup MurlInputInterfaces
         * @interface IGyroscopeDevice
         * @brief The IGyroscopeDevice interface.
         * To receive data the device must be activated by
         * IAppConfiguration::SetGyroscopeActive().
         */
        class IGyroscopeDevice : public IDevice
        {
        public:
            /**
             * @brief Get the gyroscope angular velocity around the x-axis.
             * @return The angular velocity around the x-axis in radians per second.
             */
            virtual Real GetAngularVelocityX() const = 0;

            /**
             * @brief Get the gyroscope angular velocity around the y-axis.
             * @return The angular velocity around the y-axis in radians per second.
             */
            virtual Real GetAngularVelocityY() const = 0;

            /**
             * @brief Get the gyroscope angular velocity around the z-axis.
             * @return The angular velocity around the z-axis in radians per second.
             */
            virtual Real GetAngularVelocityZ() const = 0;

            /**
             * @brief Get the gyroscope angular velocity axes.
             * @return The angular velocity axes in radians per second.
             */
            virtual AngularVelocityVector GetAngularVelocity() const = 0;

            /**
             * @brief Get the raw gyroscope angular velocity axes.
             * This method is useful to evaluate the absolute device orientation.
             * All other methods reports the values relative to the
             * current screen axis orientation.
             * @return The angular velocity axes in radians per second.
             */
            virtual AngularVelocityVector GetRawAngularVelocity() const = 0;

        protected:
            virtual ~IGyroscopeDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_GYROSCOPE_DEVICE_H__

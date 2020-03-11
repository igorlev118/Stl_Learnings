// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_MOTION_DEVICE_H__
#define __MURL_INPUT_I_MOTION_DEVICE_H__

#include "murl_input_i_device.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IMotionDevice
         * @brief The IMotionDevice interface.
         */
        class IMotionDevice : public IDevice
        {
        public:
            /**
             * @brief Check if the device is shaken.
             * @return true if the device is shaken.
             */
            virtual Bool IsShaken() const = 0;

            /**
             * @brief Check if the device was shaken in the most recent tick.
             * @return true if the device was shaken in the most recent tick.
             */
            virtual Bool WasShaken() const = 0;

        protected:
            virtual ~IMotionDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_MOTION_DEVICE_H__

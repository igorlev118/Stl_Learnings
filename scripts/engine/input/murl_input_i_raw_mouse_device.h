// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_RAW_MOUSE_DEVICE_H__
#define __MURL_INPUT_I_RAW_MOUSE_DEVICE_H__

#include "murl_input_i_device.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IRawMouseDevice
         * @brief The IRawMouseDevice interface.
         */
        class IRawMouseDevice : public IDevice
        {
        public:
            /**
             * @brief Get the mouse x-axis delta values in the most recent tick.
             * @return The x-axis delta value.
             */
            virtual SInt32 GetMouseDeltaX() const = 0;

            /**
             * @brief Get the mouse y-axis delta values in the most recent tick.
             * @return The y-axis delta value.
             */
            virtual SInt32 GetMouseDeltaY() const = 0;

            /**
             * @brief Get the mouse wheel x-axis delta values in the most recent tick.
             * @return The x-axis delta value.
             */
            virtual SInt32 GetWheelDeltaX() const = 0;

            /**
             * @brief Get the mouse wheel y-axis delta values in the most recent tick.
             * @return The y-axis delta value.
             */
            virtual SInt32 GetWheelDeltaY() const = 0;

        protected:
            virtual ~IRawMouseDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_RAW_MOUSE_DEVICE_H__

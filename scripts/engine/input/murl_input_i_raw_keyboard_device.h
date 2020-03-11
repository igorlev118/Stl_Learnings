// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_RAW_KEYBOARD_DEVICE_H__
#define __MURL_INPUT_I_RAW_KEYBOARD_DEVICE_H__

#include "murl_input_i_device.h"
#include "murl_raw_key_codes.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IRawKeyboardDevice
         * @brief The IRawKeyboardDevice interface.
         */
        class IRawKeyboardDevice : public IDevice
        {
        public:
            /**
             * @brief Check if a specified raw-key is pressed.
             * @param code The raw-key identifier.
             * @return true if the key is pressed.
             */
            virtual Bool IsKeyPressed(RawKeyCode code) const = 0;

            /**
             * @brief Check if a specified raw-key was pressed in the most recent tick.
             * @param code The raw-key identifier.
             * @return true if the key was pressed in the most recent tick.
             */
            virtual Bool WasKeyPressed(RawKeyCode code) const = 0;

            /**
             * @brief Check if a specified raw-key was released in the most recent tick.
             * @param code The raw-key identifier.
             * @return true if the key was released in the most recent tick.
             */
            virtual Bool WasKeyReleased(RawKeyCode code) const = 0;

        protected:
            virtual ~IRawKeyboardDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_RAW_KEYBOARD_DEVICE_H__

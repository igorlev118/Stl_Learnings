// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_KEYBOARD_DEVICE_H__
#define __MURL_INPUT_I_KEYBOARD_DEVICE_H__

#include "murl_input_i_device.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IKeyboardDevice
         * @brief The IKeyboardDevice interface.
         */
        class IKeyboardDevice : public IDevice
        {
        public:
            /**
             * @brief Get the number of keys pressed in the most recent tick.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfKeys() const = 0;

            /**
             * @brief Get a key pressed in the most recent tick.
             * A valid key buffer index is [0 .. GetNumberOfKeys() - 1].
             * @param index The zero-based index of the key buffer.
             * @return The UTF8 string of the key.
             */
            virtual const String& GetKey(UInt32 index) const = 0;

            /**
             * @brief Get all keys pressed in the most recent tick.
             * To concat all keys to a string use String::Cat(const StringArray& stringArray).
             * @return The UTF8 string array of the keys.
             */
            virtual const StringArray& GetKeys() const = 0;

        protected:
            virtual ~IKeyboardDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_KEYBOARD_DEVICE_H__

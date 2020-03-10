// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_RAW_BUTTON_DEVICE_H__
#define __MURL_INPUT_I_RAW_BUTTON_DEVICE_H__

#include "murl_input_i_device.h"
#include "murl_raw_button_codes.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IRawButtonDevice
         * @brief The IRawButtonDevice interface.
         */
        class IRawButtonDevice : public IDevice
        {
        public:
            /**
             * @brief Check if a specified raw-button is pressed.
             * @param code The raw-button identifier.
             * @return true if the button is pressed.
             */
            virtual Bool IsButtonPressed(RawButtonCode code) const = 0;

            /**
             * @brief Check if a specified raw-button was pressed in the most recent tick.
             * @param code The raw-button identifier.
             * @return true if the button was pressed in the most recent tick.
             */
            virtual Bool WasButtonPressed(RawButtonCode code) const = 0;

            /**
             * @brief Check if a specified raw-button was released in the most recent tick.
             * @param code The raw-button identifier.
             * @return true if the button was released in the most recent tick.
             */
            virtual Bool WasButtonReleased(RawButtonCode code) const = 0;

        protected:
            virtual ~IRawButtonDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_RAW_BUTTON_DEVICE_H__

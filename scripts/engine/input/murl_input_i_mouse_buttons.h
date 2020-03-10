// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_MOUSE_BUTTONS_H__
#define __MURL_INPUT_I_MOUSE_BUTTONS_H__

#include "murl_i_enums.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IMouseButtons
         * @brief The IMouseButtons interface.
         * The base interface of input device classes implementing mouse buttons.
         */
        class IMouseButtons
        {
        public:
            /**
             * @brief Get the number of buttons available in the device.
             * @return The number of buttons.
             */
            virtual UInt32 GetNumberOfButtons() const = 0;

            /**
             * @brief Check if a specified mouse button is pressed.
             * A valid mouse button identifier is [0 .. GetNumberOfButtons() - 1].
             * @param button The mouse button identifier.
             * @return true if the button is pressed.
             */
            virtual Bool IsButtonPressed(IEnums::MouseButton button) const = 0;

            /**
             * @brief Check if a specified mouse button was pressed in the most recent tick.
             * A valid mouse button identifier is [0 .. GetNumberOfButtons() - 1].
             * @param button The mouse button identifier.
             * @return true if the button was pressed in the most recent tick.
             */
            virtual Bool WasButtonPressed(IEnums::MouseButton button) const = 0;

            /**
             * @brief Check if a specified mouse button was released in the most recent tick.
             * A valid mouse button identifier is [0 .. GetNumberOfButtons() - 1].
             * @param button The mouse button identifier.
             * @return true if the button was released in the most recent tick.
             */
            virtual Bool WasButtonReleased(IEnums::MouseButton button) const = 0;

        protected:
            virtual ~IMouseButtons() {}
        };
    }
}

#endif  // __MURL_INPUT_I_MOUSE_BUTTONS_H__

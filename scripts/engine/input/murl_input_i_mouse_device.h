// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_MOUSE_DEVICE_H__
#define __MURL_INPUT_I_MOUSE_DEVICE_H__

#include "murl_input_i_device.h"
#include "murl_input_i_mouse_buttons.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IMouseDevice
         * @brief The IMouseDevice interface.
         */
        class IMouseDevice : public IDevice, public IMouseButtons
        {
        public:
            /**
             * @brief Check if the mouse device was moved in the most recent tick.
             * @return true if the mouse device was moved in the most recent tick.
             */
            virtual Bool WasMoved() const = 0;

            /**
             * @brief Get the mouse x-position on the display surface.
             * @return The x-position in range [-1.0 left .. 1.0 right].
             */
            virtual Real GetPositionX() const = 0;

            /**
             * @brief Get the mouse y-position on the display surface.
             * @return The y-position in range [-1.0 bottom .. 1.0 top].
             */
            virtual Real GetPositionY() const = 0;

            /**
             * @brief Check if the mouse x-position is in range of the display surface.
             * If the mouse cursor is moved out of the display surface (e.g. the window),
             * the mouse positions are clipped to range [-1.0, 1.0].
             * This method can be used to detect this case.
             * @return true if the mouse x-position is in range.
             */
            virtual Bool IsPositionXInRange() const = 0;

            /**
             * @brief Check if the mouse y-position is in range of the display surface.
             * If the mouse cursor is moved out of the display surface (e.g. the window),
             * the mouse positions are clipped to range [-1.0, 1.0].
             * This method can be used to detect this case.
             * @return true if the mouse y-position is in range.
             */
            virtual Bool IsPositionYInRange() const = 0;

        protected:
            virtual ~IMouseDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_MOUSE_DEVICE_H__

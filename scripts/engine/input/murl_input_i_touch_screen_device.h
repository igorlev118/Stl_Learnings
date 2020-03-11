// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_TOUCH_SCREEN_DEVICE_H__
#define __MURL_INPUT_I_TOUCH_SCREEN_DEVICE_H__

#include "murl_input_i_device.h"
#include "murl_input_i_mouse_buttons.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface ITouchScreenDevice
         * @brief The ITouchScreenDevice interface.
         * Multi touch devices represents each single touch by a separate device.
         * Multi touch reports can be disabled by IAppConfiguration::SetMultiTouchActive().
         */
        class ITouchScreenDevice : public IDevice, public IMouseButtons
        {
        public:
            /**
             * @brief Check if the touch is pressed.
             * @return true if the touch is pressed.
             */
            virtual Bool IsPressed() const = 0;

            /**
             * @brief Check if the touch was cancelled in the most recent tick.
             * A touch controller typically cancel multi touch inputs if too
             * much simultaneous touches are present.
             * @return true if the touch was cancelled in the most recent tick.
             */
            virtual Bool WasCancelled() const = 0;

            /**
             * @brief Check if the touch was pressed in the most recent tick.
             * @return true if the touch was pressed in the most recent tick.
             */
            virtual Bool WasPressed() const = 0;

            /**
             * @brief Check if the touch was released in the most recent tick.
             * @return true if the touch was released in the most recent tick.
             */
            virtual Bool WasReleased() const = 0;

            /**
             * @brief Check if the touch was moved in the most recent tick.
             * @return true if the touch was moved in the most recent tick.
             */
            virtual Bool WasMoved() const = 0;

            /**
             * @brief Get the touch x-position on the display surface.
             * @return The x-position in range [-1.0 left .. 1.0 right].
             */
            virtual Real GetPositionX() const = 0;

            /**
             * @brief Get the touch y-position on the display surface.
             * @return The y-position in range [-1.0 bottom .. 1.0 top].
             */
            virtual Real GetPositionY() const = 0;

        protected:
            virtual ~ITouchScreenDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_TOUCH_SCREEN_DEVICE_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_ENUMS_DEVICES_H__
#define __MURL_I_ENUMS_DEVICES_H__

#include "murl_enum.h"

namespace Murl
{
    namespace IEnums
    {
        /**
         * @addtogroup MurlDeviceEnumerations
         * @brief Device items enumerations.
         * @{
         */

        /**
         * @brief Input device types.
         */
        enum InputDeviceType
        {
            /// Unknown input device type.
            MURL_DECLARE_ENUM_VALUE(INPUT_DEVICE_TYPE, UNKNOWN)
            /// Keyboard input device type.
            MURL_DECLARE_ENUM_VALUE(INPUT_DEVICE_TYPE, KEYBOARD)
            /// Mouse input device type.
            MURL_DECLARE_ENUM_VALUE(INPUT_DEVICE_TYPE, MOUSE)
            /// Touch screen input device type.
            MURL_DECLARE_ENUM_VALUE(INPUT_DEVICE_TYPE, TOUCH_SCREEN)
            /// Game controller input device type.
            MURL_DECLARE_ENUM_VALUE(INPUT_DEVICE_TYPE, GAME_CONTROLLER)

            NUM_INPUT_DEVICE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(InputDeviceType)

        /**
         * @brief Button states.
         */
        enum ButtonState
        {
            /// Button is up (not pressed).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(BUTTON_STATE, UP,        0)
            /// Button is down (pressed).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(BUTTON_STATE, DOWN,      1)
            /// Mouse is hovering above the button. Not available for touch screens.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(BUTTON_STATE, HOVER,     2)
            /// Button is disabled (inactive).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(BUTTON_STATE, DISABLED,  3)

            /// Button is in an undefined state.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(BUTTON_STATE, UNDEFINED, 4)

            NUM_BUTTON_STATES_VISIBLE   = 4,
            NUM_BUTTON_STATES           = 5
        };
        MURL_DECLARE_ENUM_ACCESSOR(ButtonState)

        /**
         * @brief Mouse button enumeration.
         */
        enum MouseButton
        {
            /// Left mouse button.
            MURL_DECLARE_ENUM_VALUE(MOUSE_BUTTON, LEFT)
            /// Right mouse button, if available.
            MURL_DECLARE_ENUM_VALUE(MOUSE_BUTTON, RIGHT)
            /// Middle mouse button, if available.
            MURL_DECLARE_ENUM_VALUE(MOUSE_BUTTON, MIDDLE)
            /// A "next" button on the mouse, if available.
            MURL_DECLARE_ENUM_VALUE(MOUSE_BUTTON, NEXT)
            /// A "back" button on the mouse, if available.
            MURL_DECLARE_ENUM_VALUE(MOUSE_BUTTON, PREV)

            NUM_MOUSE_BUTTONS,

            /// Explicit "no button" value.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(MOUSE_BUTTON, NONE, NUM_MOUSE_BUTTONS)
        };
        MURL_DECLARE_ENUM_ACCESSOR(MouseButton)

        /**
         * @brief Keyboard codes for special functions.
         */
        enum KeyCode
        {
            /// Explicit "no key" value.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(KEYCODE, NONE, 0)

            /// The backspace key.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(KEYCODE, BACKSPACE, 8)
            /// The tabulator key.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(KEYCODE, TABULATOR, 9)
            /// The linefeed key.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(KEYCODE, LINEFEED, 10)
            /// The return key.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(KEYCODE, RETURN, 13)
            /// The escape key.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(KEYCODE, ESCAPE, 27)

            /// The space key.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(KEYCODE, SPACE, 32)
        };
        MURL_DECLARE_ENUM_ACCESSOR(KeyCode)

        /**
         * @brief Game controller control enumeration.
         */
        enum GameControllerControl
        {
            /** The digital pad. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, DPAD)

            /** The left analog stick. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, LEFT_STICK)
            /** The right analog stick. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, RIGHT_STICK)

            /** The left analog shoulder buttons (1st row). */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, SHOULDER_L1)
            /** The right analog shoulder buttons (1st row). */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, SHOULDER_R1)
            /** The left analog shoulder buttons (2nd row). */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, SHOULDER_L2)
            /** The right analog shoulder buttons (2nd row). */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, SHOULDER_R2)

            /** The low frequency vibration motor. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, VIBRATE_LOW)
            /** The high frequency vibration motor. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, VIBRATE_HIGH)

            /** A controller that has the ability to measure acceleration. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, ACCELERATION)
            /** A touchpad controller supporting inputs relative to the orientation. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, TOUCH_ORIENTATION)
            /** A touchpad controller supporting absolute and relative inputs. */
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_CONTROL, TOUCH_ABS_REL)

            NUM_GAME_CONTROLLER_CONTROLS
        };
        MURL_DECLARE_ENUM_ACCESSOR(GameControllerControl)

        /**
         * @brief Game controller button enumeration.
         */
        enum GameControllerButton
        {
            /// Digital "left".
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, DPAD_LEFT)
            /// Digital "right".
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, DPAD_RIGHT)
            /// Digital "up".
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, DPAD_UP)
            /// Digital "down".
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, DPAD_DOWN)

            /// The "A" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, A)
            /// The "B" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, B)
            /// The "C" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, C)
            /// The "D" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, D)

            /// The "X" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, X)
            /// The "Y" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, Y)
            /// The "Z" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, Z)

            /// The "Select" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, SELECT)
            /// The "Home" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, HOME)
            /// The "Start" button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, START)

            /// The left shoulder button (1st row).
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, L1)
            /// The right shoulder button (1st row).
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, R1)
            /// The left shoulder button (2nd row).
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, L2)
            /// The right shoulder button (2nd row).
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, R2)

            /// The left stick button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, LEFT_STICK)
            /// The right stick button.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, RIGHT_STICK)

            /// Auxiliary button 0.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_0)
            /// Auxiliary button 1.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_1)
            /// Auxiliary button 2.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_2)
            /// Auxiliary button 3.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_3)
            /// Auxiliary button 4.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_4)
            /// Auxiliary button 5.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_5)
            /// Auxiliary button 6.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_6)
            /// Auxiliary button 7.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_7)
            /// Auxiliary button 8.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_8)
            /// Auxiliary button 9.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_9)
            /// Auxiliary button 10.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_10)
            /// Auxiliary button 11.
            MURL_DECLARE_ENUM_VALUE(GAME_CONTROLLER_BUTTON, AUXILIARY_11)

            NUM_GAME_CONTROLLER_BUTTONS,

            /// The "-" button, equal to the "Select" button.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GAME_CONTROLLER_BUTTON, MINUS, GAME_CONTROLLER_BUTTON_SELECT)
            /// The "+" button, equal to the "Start" button.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GAME_CONTROLLER_BUTTON, PLUS,  GAME_CONTROLLER_BUTTON_START)
        };
        MURL_DECLARE_ENUM_ACCESSOR(GameControllerButton)

        /** @} */
    }
}

#endif  // __MURL_I_ENUMS_DEVICES_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_INPUT_I_GAME_CONTROLLER_DEVICE_H__
#define __MURL_INPUT_I_GAME_CONTROLLER_DEVICE_H__

#include "murl_input_i_accelerometer_device.h"
#include "murl_i_game_controller_mapping.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IGameControllerDevice
         * @brief The IGameControllerDevice interface.
         */
        class IGameControllerDevice : public IDevice
        {
        public:
            /**
             * @brief Check if the controller device is connected.
             * If a controller is disconnected, the connected state changes to false
             * and no more events are generated. \n
             * If another controller is connected, the controller device will be reconfigured
             * and the connected state changes to true.
             * @return true if the controlller device is connected.
             */
            virtual Bool IsConnected() const = 0;

            /**
             * @brief Get the player index.
             * @return The zero-based index of the player (typically indicated by lights
             *  on the controller), a negative value indicates an unset state (no lights
             *  are lit on the controller).
             */
            virtual SInt32 GetPlayerIndex() const = 0;

            /**
             * @brief Get the device information.
             * @return The device information.
             */
            virtual const IGameControllerMapping::DeviceInfo& GetDeviceInfo() const = 0;

            /**
             * @brief Check if a specified game controller button is available.
             * @param button The game controller button identifier.
             * @return true if the button is available.
             */
            virtual Bool IsButtonAvailable(IEnums::GameControllerButton button) const = 0;

            /**
             * @brief Check if a specified game controller button is pressed.
             * @param button The game controller button identifier.
             * @return true if the button is pressed.
             */
            virtual Bool IsButtonPressed(IEnums::GameControllerButton button) const = 0;

            /**
             * @brief Check if a specified game controller button was pressed in the most recent tick.
             * @param button The game controller button identifier.
             * @return true if the button was pressed in the most recent tick.
             */
            virtual Bool WasButtonPressed(IEnums::GameControllerButton button) const = 0;

            /**
             * @brief Check if a specified game controller button was released in the most recent tick.
             * @param button The game controller button identifier.
             * @return true if the button was released in the most recent tick.
             */
            virtual Bool WasButtonReleased(IEnums::GameControllerButton button) const = 0;

            /**
             * @brief Check if a specified game controller control is available.
             * @param control The game controller control identifier.
             * @return true if the game controller control is available.
             */
            virtual Bool IsControlAvailable(IEnums::GameControllerControl control) const = 0;

            /**
             * @brief Get the analog shoulder button value.
             * The return value is in range [0.0 not pressed .. 1.0 full pressed].
             * \n Supported controls are IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_L1,
             * IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_R1, IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_L2
             * or IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_R2.
             * @param value The button return value.
             * @param control The game controller control identifier.
             * @return true if the control is available,
             *  if false the 'value' return value stay unchanged.
             */
            virtual Bool GetShoulder(Float& value, IEnums::GameControllerControl control) const = 0;

            /**
             * @brief Get the gravity axes values.
             * Note that the total acceleration of the controller is equal to gravity plus acceleration.
             * \n The values are available if IsControlAvailable(IEnums::GAME_CONTROLLER_CONTROL_ACCELERATION).
             * @param gravity The gravity axes return value in meter per seconds^2.
             * @return true if the control is available,
             *  if false the 'gravity' return value stay unchanged.
             */
            virtual Bool GetGravity(AccelerationVector& gravity) const = 0;

            /**
             * @brief Get the acceleration axes values.
             * Note that the total acceleration of the controller is equal to gravity plus acceleration.
             * \n The values are available if IsControlAvailable(IEnums::GAME_CONTROLLER_CONTROL_ACCELERATION).
             * @param acceleration The acceleration axes return value in meter per seconds^2.
             * @return true if the control is available,
             *  if false the 'acceleration' return value stay unchanged.
             */
            virtual Bool GetAcceleration(AccelerationVector& acceleration) const = 0;

            /**
             * @brief Get the analog stick axis values.
             * The return values are in range [-1.0 bottom/left .. 1.0 top/right].
             * \n Supported controls are IEnums::GAME_CONTROLLER_CONTROL_LEFT_STICK or
             * IEnums::GAME_CONTROLLER_CONTROL_RIGHT_STICK.
             * @param xAxis The x-axis return value.
             * @param yAxis The y-axis return value.
             * @param control The game controller control identifier.
             * @return true if the control is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetStick(Float& xAxis, Float& yAxis, IEnums::GameControllerControl control) const = 0;

            /**
             * @brief Set the touchpad orientation enabled state.
             * The default value for this state is false, which means that the values of the
             * touchpad are always determined based on the controller’s portrait orientation.
             * If the state is set to true, then the touchpad values are calculated based
             * on its current orientation, either landscape or portrait.
             * \n Supported control is IEnums::GAME_CONTROLLER_CONTROL_TOUCH_ORIENTATION.
             * @param isEnabled The touchpad orientation enabled state.
             * @return true if the control is available.
             */
            virtual Bool SetTouchOrientationEnabled(Bool isEnabled) = 0;

            /**
             * @brief Get the touchpad orientation enabled state.
             * @param isEnabled The touchpad orientation enabled state return value.
             * @return true if the control is available,
             *  if false the 'isEnabled' return value stay unchanged.
             */
            virtual Bool GetTouchOrientationEnabled(Bool& isEnabled) const = 0;

            /**
             * @brief Set the touchpad absolute enabled state.
             * The default value for this state is false, which means that the location where the user
             * first touches the touchpad is assumed to be the neutral (0/0) value for the touchpad.
             * All subsequent values are calculated relative to this position until the user lifts the
             * finger. The next time the user’s finger touches the touchpad, a new origin is chosen.
             * If this state is set to true, then all values are calculated relative to the
             * physical center of the touchpad.
             * \n Supported control is IEnums::GAME_CONTROLLER_CONTROL_TOUCH_ABS_REL.
             * @param isEnabled The touchpad absolute enabled state.
             * @return true if the control is available.
             */
            virtual Bool SetTouchAbsoluteEnabled(Bool isEnabled) = 0;

            /**
             * @brief Get the touchpad absolute enabled state.
             * @param isEnabled The touchpad absolute enabled state return value.
             * @return true if the control is available,
             *  if false the 'isEnabled' return value stay unchanged.
             */
            virtual Bool GetTouchAbsoluteEnabled(Bool& isEnabled) const = 0;

            /**
             * @brief Set a vibration with a specified intensity.
             * Supported controls are IEnums::GAME_CONTROLLER_CONTROL_VIBRATE_LOW or
             * IEnums::GAME_CONTROLLER_CONTROL_VIBRATE_HIGH.
             * @param intensity The intensity of the vibration in range [0.0 none .. 1.0 full].
             * @param control The game controller control identifier.
             * @return true if the control is available.
             */
            virtual Bool SetVibration(Float intensity, IEnums::GameControllerControl control) = 0;

            /**
             * @brief Get the game controller mapping interface.
             *  Gamecontroller mapping is supported for USB HID game controller devices only,
             *  e.g. XBox controller or iOS controllers do not support mapping and return null.
             * @return The game controller mapping interface or
             *  null if mapping is not supported by the game controller.
             */
            virtual IGameControllerMappingPtr GetMapping() = 0;

        protected:
            virtual ~IGameControllerDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_GAME_CONTROLLER_DEVICE_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_GAME_CONTROLLER_H__
#define __MURL_I_GAME_CONTROLLER_H__

#include "murl_i_game_controller_mapping.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IGameController
     * @brief The game controller device interface.
     * Used by the platform to post events to the device.
     */
    class IGameController
    {
    public:
        /**
         * @brief Set the connected state.
         * Once a controller is created, it is not allowed to destroy the controller
         * instance when a controller is disconnected. Only the connected state changes.
         * If another controller is connected, the controller instance will be reconfigured.
         * @param isConnected The connected state.
         */
        virtual void SetConnected(Bool isConnected) = 0;

        /**
         * @brief Set the player index.
         *  The player number is typically indicated by lights on the controller, a negative
         *  index value indicates an unset state (no lights are lit on the controller).
         * @param playerIndex The zero-based index of the player.
         */
        virtual void SetPlayerIndex(SInt32 playerIndex) = 0;

        /**
         * @brief Set the device information.
         * @param deviceInfo The device information.
         */
        virtual void SetDeviceInfo(const IGameControllerMapping::DeviceInfo& deviceInfo) = 0;

        /**
         * @brief Definition of an array holding IEnums::GameControllerButton values.
         */
        typedef Array<IEnums::GameControllerButton> ButtonArray;

        /**
         * @brief Definition of an array holding IEnums::GameControllerControl values.
         */
        typedef Array<IEnums::GameControllerControl> ControlArray;

        /**
         * @brief Set the available controls.
         * Automatically sets the d-pad control to available if any d-pad button is set.
         * @param buttons An array of avaliable game controller buttons.
         * @param controls An array of available game controller controls.
         */
        virtual void SetAvailableControls(const ButtonArray& buttons,
                                          const ControlArray& controls) = 0;

        /**
         * @brief Post the current game controller axis value.
         * @param axisEvent The axis event, see enum IGameControllerMapping::AxisEvents.
         * @param value The corresponding event value.
         */
        virtual void PostAxisEvent(IGameControllerMapping::AxisEvent axisEvent, Float value) = 0;

        /**
         * @brief Post the current game controller button state.
         * @param button The button identifier.
         * @param pressed true if the button is pressed.
         */
        virtual void PostButtonEvent(IEnums::GameControllerButton button, Bool pressed) = 0;

        /**
         * @brief Post the current game controller gravity values.
         * @param gravX The x-axis gravity in meter per seconds^2.
         * @param gravY The y-axis gravity in meter per seconds^2.
         * @param gravZ The z-axis gravity in meter per seconds^2.
         */
        virtual void PostGravityEvent(Float gravX, Float gravY, Float gravZ) = 0;

        /**
         * @brief Post the current game controller acceleration values.
         * @param accelX The x-axis acceleration in meter per seconds^2.
         * @param accelY The y-axis acceleration in meter per seconds^2.
         * @param accelZ The z-axis acceleration in meter per seconds^2.
         */
        virtual void PostAccelerationEvent(Float accelX, Float accelY, Float accelZ) = 0;

        /**
         * @brief Take the touchpad orientation enabled state.
         *  Supported controls are IEnums::GAME_CONTROLLER_CONTROL_TOUCH_ORIENTATION.
         * @param isEnabled The touchpad orientation enabled state return value.
         * @return true if the control is available and the state was modified,
         *  if false the 'isEnabled' return value stays unchanged.
         */
        virtual Bool TakeTouchOrientationEnabled(Bool& isEnabled) = 0;

        /**
         * @brief Take the touchpad absolute enabled state.
         *  Supported controls are IEnums::GAME_CONTROLLER_CONTROL_TOUCH_ABS_REL.
         * @param isEnabled The touchpad absolute enabled state return value.
         * @return true if the control is available and the state was modified,
         *   if false the 'isEnabled' return value stays unchanged.
         */
        virtual Bool TakeTouchAbsoluteEnabled(Bool& isEnabled) = 0;

        /**
         * @brief Take the current vibration.
         *  Supported controls are IEnums::GAME_CONTROLLER_CONTROL_VIBRATE_LOW or
         *  IEnums::GAME_CONTROLLER_CONTROL_VIBRATE_HIGH.\n
         *  Automatically sets the used vibration control to available.
         * @param intensity The intensity of the vibration return value in range [0.0 none .. 1.0 full].
         * @param control The game controller control identifier.
         * @return true if the control is available and the intensity was modified,
         *  if false the 'intensity' return value stays unchanged.
         */
        virtual Bool TakeVibration(Float& intensity, IEnums::GameControllerControl control) = 0;

        /**
         * @brief Create the game controller mapping interface.
         *  Gamecontroller mapping is supported by USB HID game controller devices only,
         *  e.g. XBox controller or iOS controller do not create a mapping.
         * @return The game controller mapping interface.
         */
        virtual IGameControllerMappingPtr CreateMapping() = 0;

    protected:
        virtual ~IGameController() {}
    };
}

#endif  // __MURL_I_GAME_CONTROLLER_H__

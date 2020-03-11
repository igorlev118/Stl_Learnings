// Copyright 2010-2016 Spraylight

#ifndef __MURL_LOGIC_I_DEVICE_HANDER_H__
#define __MURL_LOGIC_I_DEVICE_HANDER_H__

#include "murl_logic_types.h"

#include "murl_input_i_device_handler.h"
#include "murl_output_i_device_handler.h"

namespace Murl
{
    namespace Graph
    {
        class ITextGeometry;
    }

    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IDeviceHandler
         * @brief The IDeviceHandler interface provides a collection of all
         * engine's Input and Output device methods.
         * All methods can be called without consideration of the availability of
         * the device, all methods simply return zero, false or empty strings
         * if the corresponding device is not available.
         */
        class IDeviceHandler
        {
        public:
            /**
             * @brief Initialize the object.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the object.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Notification of changed configuration.
             * The notification is executed in the engine thread context
             * if any configuration item has changed.
             * @param appConfig The application configuration object.
             */
            virtual void ConfigChanged(const IAppConfiguration* appConfig) = 0;

            /**
             * @name Accelerometer
             * @brief The Input::IAccelerometerDevice methods.
             * To receive data the device must be activated by
             * IAppConfiguration::SetAccelerometerActive().
             * @{
             */
            /**
             * @brief Check if the Input::IAccelerometerDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsAccelerationAvailable() const = 0;
            /**
             * @brief Forward to Input::Input::IAccelerometerDevice::GetAccelerationX()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Real GetAccelerationX() const = 0;
            /**
             * @brief Forward to Input::IAccelerometerDevice::GetAccelerationY()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Real GetAccelerationY() const = 0;
            /**
             * @brief Forward to Input::IAccelerometerDevice::GetAccelerationZ()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Real GetAccelerationZ() const = 0;
            /**
             * @brief Forward to Input::IAccelerometerDevice::GetAcceleration()
             *  if control is available, otherwise a zero vector is returned.
             */
            virtual Input::AccelerationVector GetAcceleration() const = 0;
            /** @} */

            /**
             * @name Gyroscope
             * @brief The Input::IGyroscopeDevice methods.
             * To receive data the device must be activated by
             * IAppConfiguration::SetGyroscopeActive().
             * @{
             */
            /**
             * @brief Check if the Input::IGyroscopeDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsGyroscopeAvailable() const = 0;
            /**
             * @brief Forward to Input::IGyroscopeDevice::GetAngularVelocityX()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Real GetAngularVelocityX() const = 0;
            /**
             * @brief Forward to Input::IGyroscopeDevice::GetAngularVelocityY()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Real GetAngularVelocityY() const = 0;
            /**
             * @brief Forward to Input::IGyroscopeDevice::GetAngularVelocityZ()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Real GetAngularVelocityZ() const = 0;
            /**
             * @brief Forward to Input::IGyroscopeDevice::GetAngularVelocity()
             *  if control is available, otherwise a zero vector is returned.
             */
            virtual Input::AngularVelocityVector GetAngularVelocity() const = 0;
            /** @} */

            /**
             * @name Heading
             * @brief The Input::IHeadingDevice methods.
             * To receive data the device must be activated by
             * IAppConfiguration::SetHeadingActive().
             * @{
             */
            /**
             * @brief Check if the Input::IHeadingDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsHeadingAvailable() const = 0;
            /**
             * @brief Forward to Input::IHeadingDevice::GetMagneticFieldX()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetMagneticFieldX() const = 0;
            /**
             * @brief Forward to Input::IHeadingDevice::GetMagneticFieldY()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetMagneticFieldY() const = 0;
            /**
             * @brief Forward to Input::IHeadingDevice::GetMagneticFieldZ()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetMagneticFieldZ() const = 0;
            /**
             * @brief Forward to Input::IHeadingDevice::GetMagneticField()
             *  if control is available, otherwise a zero vector is returned.
             */
            virtual Input::MagneticFieldVector GetMagneticField() const = 0;
            /**
             * @brief Forward to Input::IHeadingDevice::GetMagneticAngle()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetMagneticAngle() const = 0;
            /**
             * @brief Forward to Input::IHeadingDevice::GetTrueAngle()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetTrueAngle() const = 0;
            /** @} */

            /**
             * @name Location
             * @brief The Input::ILocationDevice methods.
             * To receive data the device must be activated by
             * IAppConfiguration::SetLocationActive().
             * @{
             */
            /**
             * @brief Check if the Input::ILocationDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsLocationAvailable() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetLatitude()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetLatitude() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetLongitude()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetLongitude() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetAltitude()
             *  if control is available, otherwise 0 is returned.
             */
            virtual Double GetAltitude() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetGeoLocation()
             *  if control is available, otherwise a zero location is returned.
             */
            virtual Util::GeoLocation GetGeoLocation() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetVelocity()
             *  if control is available, otherwise -1 is returned.
             */
            virtual Double GetVelocity() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetHorizontalAccuracy()
             *  if control is available, otherwise -1 is returned.
             */
            virtual Double GetHorizontalAccuracy() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetVerticalAccuracy()
             *  if control is available, otherwise -1 is returned.
             */
            virtual Double GetVerticalAccuracy() const = 0;
            /**
             * @brief Forward to Input::ILocationDevice::GetAuthorization()
             *  if control is available, otherwise
             *  IEnums::AUTHORIZATION_NOT_DETERMINED is returned.
             */
            virtual IEnums::AuthorizationStatus GetAuthorization() const = 0;
            /** @} */

            /**
             * @name GameController
             * @brief The Input::IGameControllerDevice methods.
             * @{
             */
            /**
             * @brief Get the number of Input::IGameControllerDevice devices.
             * If an additional controller is connected the number of devices will increase.
             * @return The number of game controller devices.
             */
            virtual UInt32 GetNumberOfGameControllerDevices() const = 0;
            /**
             * @brief Check if a game controller device is connected.
             * If a controller is disconnected, the connected state changes to false
             * and no more events are generated. \n
             * If another controller is connected, the controller device will be reconfigured
             * and the connected state changes to true.
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if a game controller device is connected, if false
             *  no controller is connected or the deviceIndex is out of range.
             */
            virtual Bool IsGameControllerConnected(UInt32 deviceIndex) const = 0;
            /**
             * @brief Get the game controller player index.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param deviceIndex The zero-based index of the game controller device.
             * @return The zero-based index of the player (typically indicated by lights
             *  on the controller), a negative value indicates an unset state (no lights
             *  are lit on the controller).
             */
            virtual SInt32 GetGameControllerPlayerIndex(UInt32 deviceIndex) const = 0;
            /**
             * @brief Get the game controller device information.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param deviceInfo The device information return value.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the device is available,
             *  if false the 'deviceInfo' return value stays unchanged.
             */
            virtual Bool GetGameControllerDeviceInfo(IGameControllerMapping::DeviceInfo& deviceInfo,
                                                     UInt32 deviceIndex) const = 0;
            /**
             * @brief Check if a specified game controller button is available.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param button The game controller button identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the button is available.
             */
            virtual Bool IsGameControllerButtonAvailable(IEnums::GameControllerButton button,
                                                         UInt32 deviceIndex) const = 0;
            /**
             * @brief Check if a specified game controller button is pressed.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param button The game controller button identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the button is pressed.
             */
            virtual Bool IsGameControllerButtonPressed(IEnums::GameControllerButton button,
                                                       UInt32 deviceIndex) const = 0;
            /**
             * @brief Check if a specified game controller button was pressed in the most recent tick.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param button The game controller button identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the button was pressed in the most recent tick.
             */
            virtual Bool WasGameControllerButtonPressed(IEnums::GameControllerButton button,
                                                        UInt32 deviceIndex) const = 0;
            /**
             * @brief Check if a specified game controller button was released in the most recent tick.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param button The game controller button identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the button was released in the most recent tick.
             */
            virtual Bool WasGameControllerButtonReleased(IEnums::GameControllerButton button,
                                                         UInt32 deviceIndex) const = 0;
            /**
             * @brief Check if a specified game controller control is available.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param control The game controller control identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the game controller control is available.
             */
            virtual Bool IsGameControllerControlAvailable(IEnums::GameControllerControl control,
                                                          UInt32 deviceIndex) const = 0;
            /**
             * @brief Get the game controller analog shoulder button value.
             * The return value is in range [0.0 not pressed .. 1.0 full pressed].
             * \n Supported controls are IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_L1,
             * IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_R1, IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_L2
             * or IEnums::GAME_CONTROLLER_CONTROL_SHOULDER_R2.
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param value The button return value.
             * @param control The game controller control identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control and the device is available,
             *  if false the 'value' return value stays unchanged.
             */
            virtual Bool GetGameControllerShoulder(Float& value, IEnums::GameControllerControl control,
                                                   UInt32 deviceIndex) const = 0;
            /**
             * @brief Get the game controller analog stick axis values.
             * The return values are in range [-1.0 bottom/left .. 1.0 top/right].
             * \n Supported controls are IEnums::GAME_CONTROLLER_CONTROL_LEFT_STICK or
             * IEnums::GAME_CONTROLLER_CONTROL_RIGHT_STICK.
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param xAxis The x-axis return value.
             * @param yAxis The y-axis return value.
             * @param control The game controller control identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control and the device is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetGameControllerStick(Float& xAxis, Float& yAxis, IEnums::GameControllerControl control,
                                                UInt32 deviceIndex) const = 0;
            /**
             * @brief Get the game controller gravity axes values.
             * Note that the total acceleration of the controller is equal to gravity plus acceleration.
             * \n The values are available if IsControlAvailable(IEnums::GAME_CONTROLLER_CONTROL_ACCELERATION).
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param gravity The gravity axes return value in meter per seconds^2.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control and the device is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetGameControllerGravity(Input::AccelerationVector& gravity, UInt32 deviceIndex) const = 0;
            /**
             * @brief Get the game controller acceleration axes values.
             * Note that the total acceleration of the controller is equal to gravity plus acceleration.
             * \n The values are available if IsControlAvailable(IEnums::GAME_CONTROLLER_CONTROL_ACCELERATION).
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param acceleration The acceleration axes return value in meter per seconds^2.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control and the device is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetGameControllerAcceleration(Input::AccelerationVector& acceleration, UInt32 deviceIndex) const = 0;
            /**
             * @brief Set the game controller touchpad orientation enabled state.
             * The default value for this state is false, which means that the values of the
             * touchpad are always determined based on the controller’s portrait orientation.
             * If the state is set to true, then the touchpad values are calculated based
             * on its current orientation, either landscape or portrait.
             * \n Supported control is IEnums::GAME_CONTROLLER_CONTROL_TOUCH_ORIENTATION.
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param isEnabled The touchpad orientation enabled state.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control and the device is available.
             */
            virtual Bool SetGameControllerTouchOrientationEnabled(Bool isEnabled, UInt32 deviceIndex) = 0;
            /**
             * @brief Get the game controller touchpad orientation enabled state.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param isEnabled The touchpad orientation enabled state return value.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control is available,
             *  if false the 'isEnabled' return value stay unchanged.
             */
            virtual Bool GetGameControllerTouchOrientationEnabled(Bool& isEnabled, UInt32 deviceIndex) const = 0;
            /**
             * @brief Set the game controller touchpad absolute enabled state.
             * The default value for this state is false, which means that the location where the user
             * first touches the touchpad is assumed to be the neutral (0/0) value for the touchpad.
             * All subsequent values are calculated relative to this position until the user lifts the
             * finger. The next time the user’s finger touches the touchpad, a new origin is chosen.
             * If this state is set to true, then all values are calculated relative to the
             * physical center of the touchpad.
             * \n Supported control is IEnums::GAME_CONTROLLER_CONTROL_TOUCH_ABS_REL.
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param isEnabled The touchpad absolute enabled state.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control and the device is available.
             */
            virtual Bool SetGameControllerTouchAbsoluteEnabled(Bool isEnabled, UInt32 deviceIndex) = 0;
            /**
             * @brief Get the game controller touchpad absolute enabled state.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param isEnabled The touchpad absolute enabled state return value.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control is available,
             *  if false the 'isEnabled' return value stay unchanged.
             */
            virtual Bool GetGameControllerTouchAbsoluteEnabled(Bool& isEnabled, UInt32 deviceIndex) const = 0;
            /**
             * @brief Set a game controller vibration with a specified intensity.
             * Supported controls are IEnums::GAME_CONTROLLER_CONTROL_VIBRATE_LOW or
             * IEnums::GAME_CONTROLLER_CONTROL_VIBRATE_HIGH.
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param intensity The intensity of the vibration in range [0.0 none .. 1.0 full].
             * @param control The game controller control identifier.
             * @param deviceIndex The zero-based index of the game controller device.
             * @return true if the control and the device are available.
             */
            virtual Bool SetGameControllerVibration(Float intensity, IEnums::GameControllerControl control,
                                                    UInt32 deviceIndex) = 0;
            /**
             * @brief Get the game controller mapping interface.
             *  Gamecontroller mapping is supported for USB HID game controller devices only,
             *  e.g. XBox controller or iOS controllers do not support mapping and return null.
             * \n A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param deviceIndex The zero-based index of the game controller device.
             * @return The game controller mapping interface if the device is available or
             *  null if mapping is not supported by the game controller.
             */
            virtual IGameControllerMappingPtr GetGameControllerMapping(UInt32 deviceIndex) = 0;
            /** @} */

            /**
             * @name Keyboard
             * @brief The Input::IKeyboardDevice methods.
             * @{
             */
            /**
             * @brief Check if the Input::IKeyboardDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsKeyboardAvailable() const = 0;
            /**
             * @brief Forward to Input::IKeyboardDevice::GetNumberOfKeys()
             *  if control is available, otherwise 0 is returned.
             */
            virtual UInt32 GetNumberOfKeys() const = 0;
            /**
             * @brief Forward to Input::IKeyboardDevice::GetKey()
             *  if control is available, otherwise an empty string is returned.
             */
            virtual const String& GetKey(UInt32 index) const = 0;
            /**
             * @brief Forward to Input::IKeyboardDevice::GetKeys()
             *  if control is available, otherwise an empty string array is returned.
             */
            virtual const StringArray& GetKeys() const = 0;
            /**
             * @brief Get the key code of a key pressed in the most recent tick.
             * A valid key buffer index is [0 .. GetNumberOfKeys() - 1].
             * @param index The zero-based index of the key buffer.
             * @return The key code of the key or IEnums::KEYCODE_NONE
             *  if the key is not in the set of IEnums::KeyCode.
             */
            virtual IEnums::KeyCode GetKeyCode(UInt32 index) const = 0;
            /**
             * @brief Edit a UTF8 string using all keys pressed in the most recent tick.
             * This method supports the IEnums::KEYCODE_BACKSPACE key to remove UTF8
             * characters from the end of the string.
             * @param editString The string to edit.
             * @param maxLength Maximum number of UTF8 characters to put into the string
             *  or zero for unlimited number of characters.
             * @param hideKeyboard If true hide the on screen keyboard if the
             *  IEnums::KEYCODE_RETURN key was pressed.
             * @param textGeometry A textgeometry node to add printable characters only.
             * @param nonPrintableReplacement If a text geometry node is given, any non-printable
             *  characters are replaced by this string if it is not empty.
             * @return 1 if a character was added to the string or removed from the string,
             *  -1 if IEnums::KEYCODE_RETURN key was pressed or 0 if the string is unchanged.
             */
            virtual SInt32 EditString(String& editString, UInt32 maxLength = 0, Bool hideKeyboard = false,
                                      const Graph::ITextGeometry* textGeometry = 0, String nonPrintableReplacement = String()) const = 0;
            /** @} */

            /**
             * @name Motion
             * @brief The Input::IMotionDevice methods.
             * @{
             */
            /**
             * @brief Check if the Input::IMotionDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsMotionAvailable() const = 0;
            /**
             * @brief Forward to Input::IMotionDevice::IsShaken()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsShaken() const = 0;
            /**
             * @brief Forward to Input::IMotionDevice::WasShaken()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool WasShaken() const = 0;
            /** @} */

            /**
             * @name Mouse
             * @brief The Input::IMouseDevice methods.
             * @{
             */
            /**
             * @brief Check if the Input::IMouseDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsMouseAvailable() const = 0;
            /**
             * @brief Forward to Input::IMouseDevice::WasMoved()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool WasMouseMoved() const = 0;
            /**
             * @brief Get the mouse position on the display surface.
             * The return values are in range [-1.0 bottom/left .. 1.0 top/right].
             * @param x The x-position return value.
             * @param y The y-position return value.
             * @return true if the device is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetMousePosition(Real& x, Real& y) const = 0;
            /**
             * @brief Check if the mouse position is in range of the display surface.
             * If the mouse cursor is moved out of the display surface (e.g. the window),
             * the mouse positions are clipped to range [-1.0, 1.0].
             * This method can be used to detect this case.
             * @return true if the mouse position is in range.
             */
            virtual Bool IsMousePositionInRange() const = 0;
            /**
             * @brief Forward to Input::IMouseDevice::IsPositionXInRange()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsMousePositionXInRange() const = 0;
            /**
             * @brief Forward to Input::IMouseDevice::IsPositionYInRange()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsMousePositionYInRange() const = 0;
            /**
             * @brief Check if a specified mouse button is pressed.
             * @param button The mouse button identifier.
             * @return true if the button is pressed.
             */
            virtual Bool IsMouseButtonPressed(IEnums::MouseButton button) const = 0;
            /**
             * @brief Check if a specified mouse button was pressed in the most recent tick.
             * @param button The mouse button identifier.
             * @return true if the button was pressed in the most recent tick.
             */
            virtual Bool WasMouseButtonPressed(IEnums::MouseButton button) const = 0;
            /**
             * @brief Check if a specified mouse button was released in the most recent tick.
             * @param button The mouse button identifier.
             * @return true if the button was released in the most recent tick.
             */
            virtual Bool WasMouseButtonReleased(IEnums::MouseButton button) const = 0;
            /** @} */

            /**
             * @name Orientation
             * @brief The Input::IOrientationDevice methods.
             * To receive data the device must be activated by
             * IAppConfiguration::SetOrientationActive().
             * @{
             */
            /**
             * @brief Check if the Input::IOrientationDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsOrientationAvailable() const = 0;
            /**
             * @brief Forward to Input::IOrientationDevice::GetOrientation()
             *  if control is available, otherwise IEnums::SENSOR_ORIENTATION_UNKNOWN
             *  is returned.
             */
            virtual IEnums::SensorOrientation GetOrientation() const = 0;
            /** @} */

            /**
             * @name RawButton
             * @brief The Input::IRawButtonDevice methods.
             * @{
             */
            /**
             * @brief Check if the Input::IRawButtonDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsRawButtonAvailable() const = 0;
            /**
             * @brief Forward to Input::IRawButtonDevice::IsButtonPressed()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsRawButtonPressed(RawButtonCode code) const = 0;
            /**
             * @brief Forward to Input::IRawButtonDevice::WasButtonPressed()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool WasRawButtonPressed(RawButtonCode code) const = 0;
            /**
             * @brief Forward to Input::IRawButtonDevice::WasButtonReleased()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool WasRawButtonReleased(RawButtonCode code) const = 0;
            /** @} */

            /**
             * @name RawKeyboard
             * @brief The Input::IRawKeyboardDevice methods.
             * @{
             */
            /**
             * @brief Check if the Input::IRawKeyboardDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsRawKeyboardAvailable() const = 0;
            /**
             * @brief Forward to Input::IRawKeyboardDevice::IsKeyPressed()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsRawKeyPressed(RawKeyCode code) const = 0;
            /**
             * @brief Forward to Input::IRawKeyboardDevice::WasKeyPressed()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool WasRawKeyPressed(RawKeyCode code) const = 0;
            /**
             * @brief Forward to Input::IRawKeyboardDevice::WasKeyReleased()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool WasRawKeyReleased(RawKeyCode code) const = 0;
            /** @} */

            /**
             * @name RawMouse
             * @brief The Input::IRawMouseDevice methods.
             * @{
             */
            /**
             * @brief Check if the Input::IRawMouseDevice is available.
             * @return true if the device is available.
             */
            virtual Bool IsRawMouseAvailable() const = 0;
            /**
             * @brief Get the mouse axis delta values in the most recent tick.
             * @param x The x-axis return value.
             * @param y The y-axis return value.
             * @return true if the device is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetRawMouseDelta(Real& x, Real& y) const = 0;
            /**
             * @brief Get the mouse wheel axis delta values in the most recent tick.
             * @param x The x-axis return value.
             * @param y The y-axis return value.
             * @return true if the device is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetRawWheelDelta(Real& x, Real& y) const = 0;
            /** @} */

            /**
             * @name TouchScreen
             * @brief The Input::ITouchScreenDevice methods.
             * Multi touch reports can be disabled by IAppConfiguration::SetMultiTouchActive().
             * @{
             */
            /**
             * @brief Get the number of Input::ITouchScreenDevice devices.
             * Multi touch devices represents each single touch by a separate device.
             * @return The number of touch devices.
             */
            virtual UInt32 GetNumberOfTouchDevices() const = 0;
            /**
             * @brief Check if the touch is pressed.
             * A valid device index is [0 .. GetNumberOfTouchDevices() - 1].
             * @param deviceIndex The zero-based index of the touch device.
             * @return true if the touch is pressed.
             */
            virtual Bool IsTouchPressed(UInt32 deviceIndex = 0) const = 0;
            /**
             * @brief Check if the touch was cancelled in the most recent tick.
             * A touch controller typically cancel multi touch inputs if too
             * much simultaneous touches are present.
             * A valid device index is [0 .. GetNumberOfTouchDevices() - 1].
             * @param deviceIndex The zero-based index of the touch device.
             * @return true if the touch was cancelled in the most recent tick.
             */
            virtual Bool WasTouchCancelled(UInt32 deviceIndex = 0) const = 0;
            /**
             * @brief Check if the touch was pressed in the most recent tick.
             * A valid device index is [0 .. GetNumberOfTouchDevices() - 1].
             * @param deviceIndex The zero-based index of the touch device.
             * @return true if the touch was pressed in the most recent tick.
             */
            virtual Bool WasTouchPressed(UInt32 deviceIndex = 0) const = 0;
            /**
             * @brief Check if the touch was released in the most recent tick.
             * A valid device index is [0 .. GetNumberOfTouchDevices() - 1].
             * @param deviceIndex The zero-based index of the touch device.
             * @return true if the touch was released in the most recent tick.
             */
            virtual Bool WasTouchReleased(UInt32 deviceIndex = 0) const = 0;
            /**
             * @brief Check if the touch was moved in the most recent tick.
             * A valid device index is [0 .. GetNumberOfTouchDevices() - 1].
             * @param deviceIndex The zero-based index of the touch device.
             * @return true if the touch was moved in the most recent tick.
             */
            virtual Bool WasTouchMoved(UInt32 deviceIndex = 0) const = 0;
            /**
             * @brief Get the touch position on the display surface.
             * The return values are in range [-1.0 bottom/left .. 1.0 top/right].
             * A valid device index is [0 .. GetNumberOfTouchDevices() - 1].
             * @param x The x-position return value.
             * @param y The y-position return value.
             * @param deviceIndex The zero-based index of the touch device.
             * @return true if the device is available,
             *  if false all return values stay unchanged.
             */
            virtual Bool GetTouchPosition(Real& x, Real& y, UInt32 deviceIndex = 0) const = 0;
            /** @} */

            /**
             * @name KeyboardControl
             * @brief The IKeyboardControl methods.
             * @{
             */
            /**
             * @brief Check if the keyboard control is available.
             * @return true if the control is available.
             */
            virtual Bool IsKeyboardControlAvailable() const = 0;
            /**
             * @brief Get the keyboard control interface.
             * Use this interface to use on-screen keyboard with text fields.
             * @return The keyboard control interface or null if not available.
             */
            virtual IKeyboardControl* GetKeyboardControl() = 0;
            /**
             * @brief Forward to IKeyboardControl::SetKeyboardType() if control is available.
             */
            virtual void SetKeyboardType(IKeyboardControl::KeyboardType keyboardType) = 0;
            /**
             * @brief Forward to IKeyboardControl::SetReturnKeyType() if control is available.
             */
            virtual void SetReturnKeyType(IKeyboardControl::ReturnKeyType returnKeyType) = 0;
            /**
             * @brief Forward to IKeyboardControl::Show() if control is available.
             */
            virtual void ShowKeyboard() const = 0;
            /**
             * @brief Forward to IKeyboardControl::Hide() if control is available.
             */
            virtual void HideKeyboard() const = 0;
            /**
             * @brief Toggle the show/hide state of the on-screen keyboard.
             * @return true if the on-screen keyboard is showing.
             */
            virtual Bool ToggleKeyboard() const = 0;
            /**
             * @brief Forward to IKeyboardControl::IsShowing()
             *  if control is available, otherwise false is returned.
             * @return true if the on-screen keyboard is showing.
             */
            virtual Bool IsKeyboardShowing() const = 0;
            /**
             * @brief Forward to IKeyboardControl::WasClosed()
             *  if control is available, otherwise false is returned.
             * @return true if the on-screen keyboard was closed.
             */
            virtual Bool WasKeyboardClosed() const = 0;
            /**
             * @brief Forward to IKeyboardControl::HasTextfield()
             *  if control is available, otherwise false is returned.
             * @return true if the on-screen keyboard has a text field for editing.
             */
            virtual Bool HasKeyboardTextfield() const = 0;
            /**
             * @brief Forward to IKeyboardControl::SetTitle() if control is available.
             * @param title The title string.
             */
            virtual void SetKeyboardTitle(const String& title) = 0;
            /**
             * @brief Forward to IKeyboardControl::SetDescription() if control is available.
             * @param description The description string.
             */
            virtual void SetKeyboardDescription(const String& description) = 0;
            /**
             * @brief Forward to IKeyboardControl::SetText() if control is available.
             * @param text The editing string.
             */
            virtual void SetKeyboardText(const String& text) = 0;
            /**
             * @brief Forward to IKeyboardControl::GetText()
             *  if control is available, otherwise an empty string is returned.
             * @return The editing string from the text field.
             */
            virtual const String& GetKeyboardText() const = 0;
            /** @} */

            /**
             * @name RumbleControl
             * @brief The IRumbleControl methods.
             * @{
             */
            /**
             * @brief Check if the rumble control is available.
             * @return true if the control is available.
             */
            virtual Bool IsRumbleControlAvailable() const = 0;
            /**
             * @brief Forward to IRumbleControl::Rumble() if control is available.
             */
            virtual void Rumble(Float duration = 0.5) const = 0;
            /** @} */

            /**
             * @name AppStoreControl
             * @brief The IAppStoreControl methods.
             * @{
             */
            /**
             * @brief Check if the app-store control is available.
             * @return true if the control is available.
             */
            virtual Bool IsAppStoreControlAvailable() const = 0;
            /**
             * @brief Get the app-store control interface.
             * @return The app-store control interface or null if not available.
             */
            virtual IAppStoreControl* GetAppStoreControl() = 0;
            /**
             * @brief Forward to IAppStoreControl::GetStatus()
             *  if control is available, otherwise IAppStoreControl::STATUS_IDLE is returned.
             */
            virtual IAppStoreControl::Status GetAppStoreStatus() const = 0;
            /**
             * @brief Forward to IAppStoreControl::RegisterProduct() if control is available,
             *  otherwise false is returned.
             */
            virtual Bool RegisterProduct(const String& productId, IAppStoreProduct::ProductType productType) = 0;
            /**
             * @brief Forward to IAppStoreControl::ConnectToStore()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool ConnectToStore() = 0;
            /**
             * @brief Forward to IAppStoreControl::DisconnectToStore()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool DisconnectFromStore() = 0;
            /**
             * @brief Forward to IAppStoreControl::ReconnectToStore()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool ReconnectToStore() = 0;
            /**
             * @brief Forward to IAppStoreControl::RestoreTransactions()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool RestoreTransactions() = 0;
            /**
             * @brief Forward to IAppStoreControl::GetNumberOfAvailableProducts()
             *  if control is available, otherwise 0 is returned.
             */
            virtual UInt32 GetNumberOfAvailableProducts() const = 0;
            /**
             * @brief Forward to IAppStoreControl::GetAvailableProduct()
             *  if control is available, otherwise null is returned.
             */
            virtual IAppStoreProduct* GetAvailableProduct(UInt32 index) const = 0;
            /**
             * @brief Forward to IAppStoreControl::GetAvailableProduct()
             *  if control is available, otherwise null is returned.
             */
            virtual IAppStoreProduct* GetAvailableProduct(const String& productId) const = 0;
            /**
             * @brief Forward to IAppStoreControl::CanPurchaseProducts()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool CanPurchaseProducts() const = 0;
            /**
             * @brief Forward to IAppStoreControl::PurchaseProduct()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool PurchaseProduct(IAppStoreProduct* product) = 0;
            /**
             * @brief Forward to IAppStoreControl::ConsumeProduct()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool ConsumeProduct(IAppStoreProduct* product) = 0;
            /**
             * @brief Forward to IAppStoreControl::ConfirmConsumedProduct()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool ConfirmConsumedProduct(IAppStoreProduct* product) = 0;
            /**
             * @brief Forward to IAppStoreControl::TryCancelProduct()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool TryCancelProduct(IAppStoreProduct* product) = 0;
            /**
             * @brief Forward to IAppStoreControl::GetLastError()
             *  if control is available, otherwise an empty string is returned.
             */
            virtual const String& GetAppStoreLastError() const = 0;
            /**
             * @brief Forward to IAppStoreControl::ClearLastError()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool ClearAppStoreLastError() = 0;
            /** @} */

            /**
             * @name CloudControl
             * @brief The ICloudControl methods.
             * @{
             */
            /**
             * @brief Check if the cloud control is available.
             * The cloud control must be enabled during IApp::Configure()
             * by setting IEngineConfiguration::SetCloudControlEnable().
             * @return true if the control is available.
             */
            virtual Bool IsCloudControlAvailable() const = 0;
            /**
             * @brief Get the cloud control interface.
             * The cloud control must be enabled during IApp::Configure()
             * by setting IEngineConfiguration::SetCloudControlEnable().
             * @return The cloud control interface or null if not available.
             */
            virtual ICloudControl* GetCloudControl() = 0;
            /** @} */

            /**
             * @name GameCenterControl
             * @brief The IGameCenterControl methods.
             * @{
             */
            /**
             * @brief Check if the game-center control is available.
             * @return true if the control is available.
             */
            virtual Bool IsGameCenterControlAvailable() const = 0;
            /**
             * @brief Get the game center control interface.
             * @return The game center control interface or null if not available.
             */
            virtual IGameCenterControl* GetGameCenterControl() = 0;
            /** @} */

            /**
             * @name SystemDialogControl
             * @brief The ISystemDialogControl methods.
             * @{
             */
            /**
             * @brief Check if the system-dialog control is available.
             * @return true if the control is available.
             */
            virtual Bool IsSystemDialogControlAvailable() const = 0;
            /**
             * @brief Create a system-dialog object with 1 button.
             * @param title The title string for the system-dialog object.
             * @param message The message string for the system-dialog object.
             * @param button0Label The button label string for the system-dialog object.
             * @return The system-dialog object or null if creation failed.
             */
            virtual ISystemDialog* CreateSystemDialog(const String& title, const String& message,
                                                      const String& button0Label) const = 0;
            /**
             * @brief Create a system-dialog object with 2 buttons.
             * Button appearance is right to left or bottom up.
             * @param title The title string for the system-dialog object.
             * @param message The message string for the system-dialog object.
             * @param button0Label The 1st button label string for the system-dialog object.
             * @param button1Label The 2nd button label string for the system-dialog object.
             * @return The system-dialog object or null if creation failed.
             */
            virtual ISystemDialog* CreateSystemDialog(const String& title, const String& message,
                                                      const String& button0Label, const String& button1Label) const = 0;
            /**
             * @brief Create a system-dialog object with 3 buttons.
             * Button appearance is right to left or bottom up.
             * @param title The title string for the system-dialog object.
             * @param message The message string for the system-dialog object.
             * @param button0Label The 1st button label string for the system-dialog object.
             * @param button1Label The 2nd button label string for the system-dialog object.
             * @param button2Label The 3rd button label string for the system-dialog object.
             * @return The system-dialog object or null if creation failed.
             */
            virtual ISystemDialog* CreateSystemDialog(const String& title, const String& message, const String& button0Label,
                                                      const String& button1Label, const String& button2Label) const = 0;
            /**
             * @brief Create a system-dialog object with a variable number of buttons.
             * Button appearance is right to left or bottom up.
             * @param title The title string for the system-dialog object.
             * @param message The message string for the system-dialog object.
             * @param buttonLabels The button label strings for the system-dialog object.
             * @return The system-dialog object or null if creation failed.
             */
            virtual ISystemDialog* CreateSystemDialog(const String& title, const String& message,
                                                      const StringArray& buttonLabels) const = 0;
            /**
             * @brief Forward to ISystemDialogControl::CreateSystemDialog()
             *  if control is available, otherwise null is returned.
             */
            virtual ISystemDialog* CreateSystemDialog(const String& title, const String& message) const = 0;
            /**
             * @brief Forward to ISystemDialogControl::DestroySystemDialog()
             *  if control is available.
             */
            virtual void DestroySystemDialog(ISystemDialog*& dialog) = 0;
            /** @} */

            /**
             * @name WebControl
             * @brief The IWebControl methods.
             * @{
             */
            /**
             * @brief Check if the web control is available.
             * @return true if the control is available.
             */
            virtual Bool IsWebControlAvailable() const = 0;
            /**
             * @brief Forward to IWebControl::OpenUrlInSystemBrowser()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool OpenUrlInSystemBrowser(const String& url) const = 0;
            /**
             * @brief Forward to IWebControl::CreateUrlRequest()
             *  if control is available, otherwise null is returned.
             */
            virtual IUrlRequest* CreateUrlRequest() = 0;
            /**
             * @brief Forward to IWebControl::DestroyUrlRequest() if control is available.
             */
            virtual void DestroyUrlRequest(IUrlRequest*& urlRequest) = 0;
            /**
             * @brief Forward to IWebControl::CreateEMail()
             *  if control is available, otherwise null is returned.
             */
            virtual IEMail* CreateEMail(const String& subject, const String& message) = 0;
            /**
             * @brief Forward to IWebControl::CreateEMail()
             *  if control is available, otherwise null is returned.
             */
            virtual IEMail* CreateEMail(const String& subject, const String& message, const String& recipientAddress) = 0;
            /**
             * @brief Forward to IWebControl::DestroyEMail() if control is available.
             */
            virtual void DestroyEMail(IEMail*& eMail) = 0;
            /** @} */

            /**
             * @name ScreenshotControl
             * @brief The IScreenshotControl methods.
             * @{
             */
            /**
             * @brief Check if the screen-shot control is available.
             * @return true if the control is available.
             */
            virtual Bool IsScreenshotControlAvailable() const = 0;
            /**
             * @brief Forward to IScreenshotControl::CreateScreenshot()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool CreateScreenshot() = 0;
            /**
             * @brief Forward to IScreenshotControl::DestroyScreenshot()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool DestroyScreenshot() = 0;
            /**
             * @brief Forward to IScreenshotControl::IsBusy()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsScreenshotBusy() const = 0;
            /**
             * @brief Forward to IScreenshotControl::IsReady()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsScreenshotReady() const = 0;
            /**
             * @brief Forward to IScreenshotControl::GetScreenshotImage()
             *  if control is available, otherwise null is returned.
             */
            virtual const Resource::IImage* GetScreenshotImage() const = 0;
            /** @} */

            /**
             * @name PreferencesControl
             * @brief The IPreferencesControl methods.
             * @{
             */
            /**
             * @brief Check if the preferences control is available.
             * @return true if the control is available.
             */
            virtual Bool IsPreferencesControlAvailable() const = 0;
            /**
             * @brief Get the preferences control interface.
             * @return The preferences control interface or null if not available.
             */
            virtual IPreferencesControl* GetPreferencesControl() = 0;
            /**
             * @brief Forward to IPreferencesControl::Exists()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool PreferenceExists(const String& key) = 0;
            /**
             * @brief Forward to IPreferencesControl::GetValue(const String& key)
             *  if control is available, otherwise an empty string is returned.
             */
            virtual String GetPreferenceValue(const String& key) const = 0;
            /**
             * @brief Forward to IPreferencesControl::GetValue(const String& key, String& value)
             *  if control is available, otherwise false is returned.
             */
            virtual Bool GetPreferenceValue(const String& key, String& value) const = 0;
            /**
             * @brief Forward to IPreferencesControl::SetValue()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool SetPreferenceValue(const String& key, const String& value) = 0;
            /**
             * @brief Forward to IPreferencesControl::GetData()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool GetPreferenceData(const String& key, Data& value) const = 0;
            /**
             * @brief Forward to IPreferencesControl::SetData()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool SetPreferenceData(const String& key, const Data& value) = 0;
            /**
             * @brief Forward to IPreferencesControl::Remove()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool PreferenceRemove(const String& key) = 0;
            /** @} */

            /**
             * @name TelephonyControl
             * @brief The ITelephonyControl methods.
             * @{
             */
            /**
             * @brief Check if the telephony control is available.
             * @return true if the control is available.
             */
            virtual Bool IsTelephonyControlAvailable() const = 0;
            /**
             * @brief Forward to ITelephonyControl::GetCarrierName()
             *  if control is available, otherwise an empty string is returned.
             */
            virtual String GetTelephonyCarrierName() const = 0;
            /**
             * @brief Forward to ITelephonyControl::GetCountryCode()
             *  if control is available, otherwise an empty string is returned.
             */
            virtual String GetTelephonyCountryCode() const = 0;
            /**
             * @brief Forward to ITelephonyControl::GetNetworkCode()
             *  if control is available, otherwise an empty string is returned.
             */
            virtual String GetTelephonyNetworkCode() const = 0;
            /** @} */

            /**
             * @name AppControl
             * @brief The IAppControl methods.
             * @{
             */
            /**
             * @brief Forward to IAppControl::TerminateApp()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool TerminateApp() = 0;
            /**
             * @brief Forward to IAppControl::IsTerminateApp()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool IsTerminateApp() const = 0;
            /**
             * @brief Forward to IAppControl::SetLoadingProgress()
             *  if control is available, otherwise false is returned.
             */
            virtual Bool SetLoadingProgress(Real progress) = 0;
            /**
             * @brief Forward to IAppControl::GetLoadingProgress()
             *  if control is available, otherwise 0.0 is returned.
             */
            virtual Real GetLoadingProgress() const = 0;
            /** @} */

            /**
             * @name MusicPlayerControl
             * @brief The IMusicPlayerControl methods.
             * @{
             */
            /**
             * @brief Check if the music player control is available.
             * @return true if the control is available.
             */
            virtual Bool IsMusicPlayerControlAvailable() const = 0;
            /**
             * @brief Get the music player control interface.
             * @return The music player control interface or null if not available.
             */
            virtual IMusicPlayerControl* GetMusicPlayerControl() = 0;
            /** @} */

            /**
             * @brief Get the virtual-mouse device object.
             * @return The virtual-mouse device object.
             */
            virtual IVirtualMouse* GetVirtualMouse() = 0;

            /**
             * @brief Get the input devicehandler object.
             * @return The input devicehandler object.
             */
            virtual Input::IDeviceHandler* GetInputDeviceHandler() = 0;
            /**
             * @brief Get the output devicehandler object.
             * @return The output devicehandler object.
             */
            virtual Output::IDeviceHandler* GetOutputDeviceHandler() = 0;

        protected:
            virtual ~IDeviceHandler() {}
        };
    }
}

#endif // __MURL_LOGIC_I_DEVICE_HANDER_H__

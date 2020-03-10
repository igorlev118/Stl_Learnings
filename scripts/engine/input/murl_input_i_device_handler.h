// Copyright 2010-2015 Spraylight

#ifndef __MURL_INPUT_I_DEVICE_HANDLER_H__
#define __MURL_INPUT_I_DEVICE_HANDLER_H__

#include "murl_input_i_accelerometer_device.h"
#include "murl_input_i_game_controller_device.h"
#include "murl_input_i_gyroscope_device.h"
#include "murl_input_i_heading_device.h"
#include "murl_input_i_keyboard_device.h"
#include "murl_input_i_location_device.h"
#include "murl_input_i_motion_device.h"
#include "murl_input_i_mouse_device.h"
#include "murl_input_i_orientation_device.h"
#include "murl_input_i_raw_button_device.h"
#include "murl_input_i_raw_keyboard_device.h"
#include "murl_input_i_raw_mouse_device.h"
#include "murl_input_i_touch_screen_device.h"
#include "murl_i_virtual_mouse.h"

#include "murl_raw_key_codes.h"
#include "murl_raw_button_codes.h"

namespace Murl
{
    class IAccelerometer;
    class IGameController;
    class IGyroscope;
    class IHeading;
    class IKeyboard;
    class ILocation;
    class IMotion;
    class IMouse;
    class IOrientation;
    class IRawButton;
    class IRawKeyboard;
    class IRawMouse;
    class ITouchScreen;

    namespace Input
    {
        class ITouchableHandler;

        /**
         * @ingroup MurlInputInterfaces
         * @interface IDeviceHandler
         * @brief The IDeviceHandler interface.
         * The device handler creates and registers all input device instances.
         * Devices are used by the platform which post's the current device states.
         * The states are processed by the registered devices each logic tick
         * before executing the logic processors Logic::IEngineProcessor::ProcessTick().
         */
        class IDeviceHandler
        {
        public:
            /**
             * @brief Initialize the device handler.
             * @param appConfig The application configuration object.
             * @return true if successful.
             */
            virtual Bool Init(const IAppConfiguration* appConfig) = 0;
            /**
             * @brief Deinitialize the device handler.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Update all registered devices.
             * The update is executed in the logic thread context each logic tick
             * before executing the logic processors Logic::IEngineProcessor::ProcessTick().
             * @return true if successful.
             */
            virtual Bool UpdateDevices() = 0;

            /**
             * @brief Notification of changed configuration.
             * The notification is executed in the engine thread context
             * if any configuration item has changed.
             * @param appConfig The application configuration object.
             */
            virtual void ConfigChanged(const IAppConfiguration* appConfig) = 0;

            /**
             * @brief Begin updating the touchable handler.
             * The update is executed in the logic thread context each logic tick
             * after executing the logic processors Logic::IEngineProcessor::ProcessTick()
             * and before the graph's logic-traversal.
             * @param touchableHandler The touchable handler object.
             * @return true if successful.
             */
            virtual Bool BeginLogicUpdate(ITouchableHandler* touchableHandler) = 0;
            /**
             * @brief End updating the touchable handler.
             * The update is executed in the logic thread context each logic tick
             * after executing UpdateDevices() and before executing the logic
             * processors Logic::IEngineProcessor::ProcessTick().
             * @param touchableHandler The touchable handler object.
             * @return true if successful.
             */
            virtual Bool EndLogicUpdate(ITouchableHandler* touchableHandler) = 0;

            /**
             * @brief Create an accelerometer device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created accelerometer device object.
             */
            virtual IAccelerometer* AddAccelerometerDevice(const String& name) = 0;
            /**
             * @brief Remove an accelerometer device from the devicehandler and destroy the object.
             * @param accelerometer A reference to the accelerometer device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveAccelerometerDevice(IAccelerometer*& accelerometer) = 0;
            /**
             * @brief Get a registered accelerometer device object.
             * @param index The zero-based index of the device.
             * @return The accelerometer device object or null if the index is out of range.
             */
            virtual const IAccelerometerDevice* GetAccelerometerDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a gyroscope device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created gyroscope device object.
             */
            virtual IGyroscope* AddGyroscopeDevice(const String& name) = 0;
            /**
             * @brief Remove a gyroscope device from the devicehandler and destroy the object.
             * @param gyroscope A reference to the gyroscope device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveGyroscopeDevice(IGyroscope*& gyroscope) = 0;
            /**
             * @brief Get a registered gyroscope device object.
             * @param index The zero-based index of the device.
             * @return The gyroscope device object or null if index the is out of range.
             */
            virtual const IGyroscopeDevice* GetGyroscopeDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a heading device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created heading device object.
             */
            virtual IHeading* AddHeadingDevice(const String& name) = 0;
            /**
             * @brief Remove a heading device from the devicehandler and destroy the object.
             * @param heading A reference to the heading device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveHeadingDevice(IHeading*& heading) = 0;
            /**
             * @brief Get a registered heading device object.
             * @param index The zero-based index of the device.
             * @return The heading device object or null if index the is out of range.
             */
            virtual const IHeadingDevice* GetHeadingDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a location device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created location device object.
             */
            virtual ILocation* AddLocationDevice(const String& name) = 0;
            /**
             * @brief Remove a location device from the devicehandler and destroy the object.
             * @param location A reference to the location device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveLocationDevice(ILocation*& location) = 0;
            /**
             * @brief Get a registered location device object.
             * @param index The zero-based index of the device.
             * @return The location device object or null if index the is out of range.
             */
            virtual const ILocationDevice* GetLocationDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a game controller device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created game controller device object.
             */
            virtual IGameController* AddGameControllerDevice(const String& name) = 0;
            /**
             * @brief Remove a game controller device from the devicehandler and destroy the object.
             * @param gameController A reference to the game controller device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveGameControllerDevice(IGameController*& gameController) = 0;
            /**
             * @brief Get the number of registered game controller devices.
             * @return The number of registered game controller devices.
             */
            virtual UInt32 GetNumberOfGameControllerDevices() const = 0;
            /**
             * @brief Get a registered game controller device object.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param index The zero-based index of the device.
             * @return The game controller device object or null if index the is out of range.
             */
            virtual const IGameControllerDevice* GetGameControllerDevice(UInt32 index = 0) const = 0;
            /**
             * @brief Get a registered mutable game controller device object.
             * A valid device index is [0 .. GetNumberOfGameControllerDevices() - 1].
             * @param index The zero-based index of the device.
             * @return The mutable game controller device object or null if index the is out of range.
             */
            virtual IGameControllerDevice* GetGameControllerDevice(UInt32 index = 0) = 0;

            /**
             * @brief Create a keyboard device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created keyboard device object.
             */
            virtual IKeyboard* AddKeyboardDevice(const String& name) = 0;
            /**
             * @brief Remove a keyboard device from the devicehandler and destroy the object.
             * @param keyboard A reference to the keyboard device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveKeyboardDevice(IKeyboard*& keyboard) = 0;
            /**
             * @brief Get a registered keyboard device object.
             * @param index The zero-based index of the device.
             * @return The keyboard device object or null if index the is out of range.
             */
            virtual const IKeyboardDevice* GetKeyboardDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a motion device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created motion device object.
             */
            virtual IMotion* AddMotionDevice(const String& name) = 0;
            /**
             * @brief Remove a motion device from the devicehandler and destroy the object.
             * @param motion A reference to the motion device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveMotionDevice(IMotion*& motion) = 0;
            /**
             * @brief Get a registered motion device object.
             * @param index The zero-based index of the device.
             * @return The motion device object or null if index the is out of range.
             */
            virtual const IMotionDevice* GetMotionDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a mouse device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created mouse device object.
             */
            virtual IMouse* AddMouseDevice(const String& name) = 0;
            /**
             * @brief Remove a mouse device from the devicehandler and destroy the object.
             * @param mouse A reference to the mouse device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveMouseDevice(IMouse*& mouse) = 0;
            /**
             * @brief Get a registered mouse device object.
             * @param index The zero-based index of the device.
             * @return The mouse device object or null if index the is out of range.
             */
            virtual const IMouseDevice* GetMouseDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a orientation device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created orientation device object.
             */
            virtual IOrientation* AddOrientationDevice(const String& name) = 0;
            /**
             * @brief Remove a orientation device from the devicehandler and destroy the object.
             * @param orientation A reference to the orientation device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveOrientationDevice(IOrientation*& orientation) = 0;
            /**
             * @brief Get a registered orientation device object.
             * @param index The zero-based index of the device.
             * @return The orientation device object or null if index the is out of range.
             */
            virtual const IOrientationDevice* GetOrientationDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a raw-button device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created raw-button device object.
             */
            virtual IRawButton* AddRawButtonDevice(const String& name) = 0;
            /**
             * @brief Remove a raw-button device from the devicehandler and destroy the object.
             * @param rawButton A reference to the raw-button device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveRawButtonDevice(IRawButton*& rawButton) = 0;
            /**
             * @brief Get a registered raw-button device object.
             * @param index The zero-based index of the device.
             * @return The raw-button device object or null if index the is out of range.
             */
            virtual const IRawButtonDevice* GetRawButtonDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a raw-keyboard device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created raw-keyboard device object.
             */
            virtual IRawKeyboard* AddRawKeyboardDevice(const String& name) = 0;
            /**
             * @brief Remove a raw-keyboard device from the devicehandler and destroy the object.
             * @param rawKeyboard A reference to the raw-keyboard device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveRawKeyboardDevice(IRawKeyboard*& rawKeyboard) = 0;
            /**
             * @brief Get a registered raw-keyboard device object.
             * @param index The zero-based index of the device.
             * @return The raw-keyboard device object or null if index the is out of range.
             */
            virtual const IRawKeyboardDevice* GetRawKeyboardDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a raw-mouse device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created raw-mouse device object.
             */
            virtual IRawMouse* AddRawMouseDevice(const String& name) = 0;
            /**
             * @brief Remove a raw-mouse device from the devicehandler and destroy the object.
             * @param rawMouse A reference to the raw-mouse device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveRawMouseDevice(IRawMouse*& rawMouse) = 0;
            /**
             * @brief Get a registered raw-mouse device object.
             * @param index The zero-based index of the device.
             * @return The raw-mouse device object or null if index the is out of range.
             */
            virtual const IRawMouseDevice* GetRawMouseDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Create a touch-screen device and add the device to the input device handler.
             * @param name The device name, the default device name is "BuiltIn".
             * @return The created touch-screen device object.
             */
            virtual ITouchScreen* AddTouchScreenDevice(const String& name) = 0;
            /**
             * @brief Remove a touch-screen device from the devicehandler and destroy the object.
             * @param touchScreen A reference to the touch-screen device pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool RemoveTouchScreenDevice(ITouchScreen*& touchScreen) = 0;
            /**
             * @brief Get the number of registered touch-screen devices.
             * @return The number of registered touch-screen devices.
             */
            virtual UInt32 GetNumberOfTouchScreenDevices() const = 0;
            /**
             * @brief Get a registered touch-screen device object.
             * A valid device index is [0 .. GetNumberOfTouchScreenDevices() - 1].
             * @param index The zero-based index of the device.
             * @return The touch-screen device object or null if index the is out of range.
             */
            virtual const ITouchScreenDevice* GetTouchScreenDevice(UInt32 index = 0) const = 0;

            /**
             * @brief Get the virtual-mouse device object.
             * @return The virtual-mouse device object.
             */
            virtual IVirtualMouse* GetVirtualMouse() = 0;

        protected:
            virtual ~IDeviceHandler() {}
        };
    }
}

#endif  // __MURL_INPUT_I_DEVICE_HANDLER_H__

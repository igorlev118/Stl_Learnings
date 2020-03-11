// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_DEVICE_HANDLER_H__
#define __MURL_I_DEVICE_HANDLER_H__

#include "murl_types.h"

namespace Murl
{
    class IAppConfiguration;

    class IControlable;
    class ICustomControlable;

    class IAppControl;
    class IAppStoreControl;
    class ICloudControl;
    class IGameCenterControl;
    class IKeyboardControl;
    class IMediaControl;
    class IMusicPlayerControl;
    class IPreferencesControl;
    class IRumbleControl;
    class IScreenshotControl;
    class ISystemDialogControl;
    class ISystemFontControl;
    class ITelephonyControl;
    class IWebControl;

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
    class IVirtualMouse;

    class IAudioInterface;
    class IFileInterface;
    class IVideoInterface;

    /**
     * @ingroup MurlInterfaces
     * @interface IDeviceHandler
     * @brief The main device handler interface.
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
         * @name Input devices
         * @brief The input device methods.
         * @{
         */
        /**
         * @brief Forward to Input::IDeviceHandler::AddAccelerometerDevice().
         */
        virtual IAccelerometer* CreateAccelerometer(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveAccelerometerDevice().
         */
        virtual Bool DestroyAccelerometer(IAccelerometer*& accelerometer) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddGyroscopeDevice().
         */
        virtual IGyroscope* CreateGyroscope(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveGyroscopeDevice().
         */
        virtual Bool DestroyGyroscope(IGyroscope*& gyroscope) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddHeadingDevice().
         */
        virtual IHeading* CreateHeading(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveHeadingDevice().
         */
        virtual Bool DestroyHeading(IHeading*& heading) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddLocationDevice().
         */
        virtual ILocation* CreateLocation(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveLocationDevice().
         */
        virtual Bool DestroyLocation(ILocation*& location) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddGameControllerDevice().
         */
        virtual IGameController* CreateGameController(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveGameControllerDevice().
         */
        virtual Bool DestroyGameController(IGameController*& gameController) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddKeyboardDevice().
         */
        virtual IKeyboard* CreateKeyboard(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveKeyboardDevice().
         */
        virtual Bool DestroyKeyboard(IKeyboard*& keyboard) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddMotionDevice().
         */
        virtual IMotion* CreateMotion(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveMotionDevice().
         */
        virtual Bool DestroyMotion(IMotion*& motion) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddMouseDevice().
         */
        virtual IMouse* CreateMouse(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveMouseDevice().
         */
        virtual Bool DestroyMouse(IMouse*& mouse) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddOrientationDevice().
         */
        virtual IOrientation* CreateOrientation(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveOrientationDevice().
         */
        virtual Bool DestroyOrientation(IOrientation*& orientation) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddRawButtonDevice().
         */
        virtual IRawButton* CreateRawButton(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveRawButtonDevice().
         */
        virtual Bool DestroyRawButton(IRawButton*& rawButton) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddRawKeyboardDevice().
         */
        virtual IRawKeyboard* CreateRawKeyboard(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveRawKeyboardDevice().
         */
        virtual Bool DestroyRawKeyboard(IRawKeyboard*& rawKeyboard) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddRawMouseDevice().
         */
        virtual IRawMouse* CreateRawMouse(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveRawMouseDevice().
         */
        virtual Bool DestroyRawMouse(IRawMouse*& rawMouse) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::AddTouchScreenDevice().
         */
        virtual ITouchScreen* CreateTouchScreen(const String& name) = 0;
        /**
         * @brief Forward to Input::IDeviceHandler::RemoveTouchScreenDevice().
         */
        virtual Bool DestroyTouchScreen(ITouchScreen*& touchScreen) = 0;

        /**
         * @brief Forward to Input::IDeviceHandler::GetVirtualMouse().
         */
        virtual IVirtualMouse* GetVirtualMouse() = 0;
        /** @} */

        /**
         * @name Output devices
         * @brief The output device methods.
         * @{
         */
        /**
         * @brief Forward to Output::IDeviceHandler::AddAppControl().
         */
        virtual Bool AddAppControl(IAppControl* appControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveAppControl().
         */
        virtual Bool RemoveAppControl(IAppControl* appControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddKeyboardControl().
         */
        virtual Bool AddKeyboardControl(IKeyboardControl* keyboardControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveKeyboardControl().
         */
        virtual Bool RemoveKeyboardControl(IKeyboardControl* keyboardControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddRumbleControl().
         */
        virtual Bool AddRumbleControl(IRumbleControl* rumbleControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveRumbleControl().
         */
        virtual Bool RemoveRumbleControl(IRumbleControl* rumbleControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddAppStoreControl().
         */
        virtual Bool AddAppStoreControl(IAppStoreControl* appStoreControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveAppStoreControl().
         */
        virtual Bool RemoveAppStoreControl(IAppStoreControl* appStoreControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddCloudControl().
         */
        virtual Bool AddCloudControl(ICloudControl* cloudControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveCloudControl().
         */
        virtual Bool RemoveCloudControl(ICloudControl* cloudControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddGameCenterControl().
         */
        virtual Bool AddGameCenterControl(IGameCenterControl* gameCenterControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveGameCenterControl().
         */
        virtual Bool RemoveGameCenterControl(IGameCenterControl* gameCenterControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddSystemDialogControl().
         */
        virtual Bool AddSystemDialogControl(ISystemDialogControl* systemDialogControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveSystemDialogControl().
         */
        virtual Bool RemoveSystemDialogControl(ISystemDialogControl* systemDialogControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddSystemFontControl().
         */
        virtual Bool AddSystemFontControl(ISystemFontControl* systemFontControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveSystemFontControl().
         */
        virtual Bool RemoveSystemFontControl(ISystemFontControl* systemFontControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddWebControl().
         */
        virtual Bool AddWebControl(IWebControl* webControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveWebControl().
         */
        virtual Bool RemoveWebControl(IWebControl* webControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddScreenshotControl().
         */
        virtual Bool AddScreenshotControl(IScreenshotControl* screenshotControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveScreenshotControl().
         */
        virtual Bool RemoveScreenshotControl(IScreenshotControl* screenshotControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddPreferencesControl().
         */
        virtual Bool AddPreferencesControl(IPreferencesControl* preferencesControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemovePreferencesControl().
         */
        virtual Bool RemovePreferencesControl(IPreferencesControl* preferencesControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddTelephonyControl().
         */
        virtual Bool AddTelephonyControl(ITelephonyControl* telephonyControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveTelephonyControl().
         */
        virtual Bool RemoveTelephonyControl(ITelephonyControl* telephonyControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddMediaControl().
         */
        virtual Bool AddMediaControl(IMediaControl* mediaControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveMediaControl().
         */
        virtual Bool RemoveMediaControl(IMediaControl* mediaControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddMusicPlayerControl().
         */
        virtual Bool AddMusicPlayerControl(IMusicPlayerControl* musicPlayerControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveMusicPlayerControl().
         */
        virtual Bool RemoveMusicPlayerControl(IMusicPlayerControl* musicPlayerControl) = 0;

        /**
         * @brief Forward to Output::IDeviceHandler::AddCustomControl(ICustomControlable* customControl).
         */
        virtual Bool AddCustomControl(ICustomControlable* customControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::AddCustomControl(const String& name, ICustomControlable* customControl).
         */
        virtual Bool AddCustomControl(const String& name, ICustomControlable* customControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveCustomControl(const String& name).
         */
        virtual ICustomControlable* RemoveCustomControl(const String& name) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::RemoveCustomControl(const ICustomControlable* customControl).
         */
        virtual Bool RemoveCustomControl(const ICustomControlable* customControl) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::GetCustomControl().
         */
        virtual ICustomControlable* GetCustomControl(const String& name) = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::GetNumberOfCustomControls().
         */
        virtual UInt32 GetNumberOfCustomControls() const = 0;
        /**
         * @brief Forward to Output::IDeviceHandler::GetCustomControl().
         */
        virtual ICustomControlable* GetCustomControl(UInt32 index) = 0;
        /** @} */

        /**
         * @name Platform interfaces
         * @brief Audio / Video / File interface.
         * @{
         */
        /**
         * @brief Set the platform video interface.
         * @param videoInterface The video interface.
         * @return true if successful.
         */
        virtual Bool SetVideoInterface(IVideoInterface* videoInterface) = 0;
        /**
         * @brief Set the platform audio interface.
         * @param audioInterface The audio interface.
         * @return true if successful.
         */
        virtual Bool SetAudioInterface(IAudioInterface* audioInterface) = 0;
        /**
         * @brief Set the platform file interface.
         * @param fileInterface The file interface.
         * @return true if successful.
         */
        virtual Bool SetFileInterface(IFileInterface* fileInterface) = 0;
        /** @} */

    protected:
        virtual ~IDeviceHandler() {}
    };
}

#endif  // __MURL_I_DEVICE_HANDLER_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_OUTPUT_I_DEVICE_HANDLER_H__
#define __MURL_OUTPUT_I_DEVICE_HANDLER_H__

#include "murl_output_types.h"

#include "murl_i_app_control.h"
#include "murl_i_app_store_control.h"
#include "murl_i_cloud_control.h"
#include "murl_i_game_center_control.h"
#include "murl_i_keyboard_control.h"
#include "murl_i_media_control.h"
#include "murl_i_music_player_control.h"
#include "murl_i_preferences_control.h"
#include "murl_i_rumble_control.h"
#include "murl_i_screenshot_control.h"
#include "murl_i_system_dialog_control.h"
#include "murl_i_system_font_control.h"
#include "murl_i_telephony_control.h"
#include "murl_i_web_control.h"
#include "murl_i_custom_controlable.h"

namespace Murl
{
    namespace Output
    {
        /**
         * @ingroup MurlOutputInterfaces
         * @interface IDeviceHandler
         * @brief The IDeviceHandler interface.
         * The device handler registers all control device instances
         * created by the platform or the application.
         */
        class IDeviceHandler
        {
        public:
            /**
             * @brief Initialize the device handler.
             * @return true if successful.
             */
            virtual Bool Init() = 0;

            /**
             * @brief Deinitialize the device handler.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Update all registered devices.
             * The update is executed in the logic thread context each logic tick
             * after executing the logic processors Logic::IEngineProcessor::ProcessTick().
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
             * @brief Add a keyboard control object to the output device handler.
             * @param keyboardControl The keyboard control object to add.
             * @return true if successful.
             */
            virtual Bool AddKeyboardControl(IKeyboardControl* keyboardControl) = 0;
            /**
             * @brief Remove a keyboard control object from the output device handler.
             * @param keyboardControl The keyboard control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveKeyboardControl(const IKeyboardControl* keyboardControl) = 0;
            /**
             * @brief Get a registered keyboard control object.
             * @param index The zero-based index of the control.
             * @return The keyboard control object or null if the index is out of range.
             */
            virtual IKeyboardControl* GetKeyboardControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a application control object to the output device handler.
             * @param appControl The application control object to add.
             * @return true if successful.
             */
            virtual Bool AddAppControl(IAppControl* appControl) = 0;
            /**
             * @brief Remove a application control object from the output device handler.
             * @param appControl The application control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveAppControl(const IAppControl* appControl) = 0;
            /**
             * @brief Get a registered application control object.
             * @param index The zero-based index of the control.
             * @return The application control object or null if the index is out of range.
             */
            virtual IAppControl* GetAppControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a rumble control object to the output device handler.
             * @param rumbleControl The rumble control object to add.
             * @return true if successful.
             */
            virtual Bool AddRumbleControl(IRumbleControl* rumbleControl) = 0;
            /**
             * @brief Remove a rumble control object from the output device handler.
             * @param rumbleControl The rumble control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveRumbleControl(const IRumbleControl* rumbleControl) = 0;
            /**
             * @brief Get a registered rumble control object.
             * @param index The zero-based index of the control.
             * @return The rumble control object or null if the index is out of range.
             */
            virtual IRumbleControl* GetRumbleControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a app-store control object to the output device handler.
             * @param appStoreControl The app-store control object to add.
             * @return true if successful.
             */
            virtual Bool AddAppStoreControl(IAppStoreControl* appStoreControl) = 0;
            /**
             * @brief Remove a app-store control object from the output device handler.
             * @param appStoreControl The app-store control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveAppStoreControl(const IAppStoreControl* appStoreControl) = 0;
            /**
             * @brief Get a registered app-store control object.
             * @param index The zero-based index of the control.
             * @return The app-store control object or null if the index is out of range.
             */
            virtual IAppStoreControl* GetAppStoreControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a cloud control object to the output device handler.
             * @param cloudControl The cloud control object to add.
             * @return true if successful.
             */
            virtual Bool AddCloudControl(ICloudControl* cloudControl) = 0;
            /**
             * @brief Remove a cloud control object from the output device handler.
             * @param cloudControl The cloud control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveCloudControl(const ICloudControl* cloudControl) = 0;
            /**
             * @brief Get a registered cloud control object.
             * @param index The zero-based index of the control.
             * @return The cloud control object or null if the index is out of range.
             */
            virtual ICloudControl* GetCloudControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a game-center control object to the output device handler.
             * @param gameCenterControl The game-center control object to add.
             * @return true if successful.
             */
            virtual Bool AddGameCenterControl(IGameCenterControl* gameCenterControl) = 0;
            /**
             * @brief Remove a game-center control object from the output device handler.
             * @param gameCenterControl The game-center control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveGameCenterControl(const IGameCenterControl* gameCenterControl) = 0;
            /**
             * @brief Get a registered game-center control object.
             * @param index The zero-based index of the control.
             * @return The game-center control object or null if the index is out of range.
             */
            virtual IGameCenterControl* GetGameCenterControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a system-dialog control object to the output device handler.
             * @param systemDialogControl The system-dialog control object to add.
             * @return true if successful.
             */
            virtual Bool AddSystemDialogControl(ISystemDialogControl* systemDialogControl) = 0;
            /**
             * @brief Remove a system-dialog control object from the output device handler.
             * @param systemDialogControl The system-dialog control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveSystemDialogControl(const ISystemDialogControl* systemDialogControl) = 0;
            /**
             * @brief Get a registered system-dialog control object.
             * @param index The zero-based index of the control.
             * @return The system-dialog control object or null if the index is out of range.
             */
            virtual ISystemDialogControl* GetSystemDialogControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a system-font control object to the output device handler.
             * @param systemFontControl The system-font control object to add.
             * @return true if successful.
             */
            virtual Bool AddSystemFontControl(ISystemFontControl* systemFontControl) = 0;
            /**
             * @brief Remove a system-font control object from the output device handler.
             * @param systemFontControl The system-font control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveSystemFontControl(const ISystemFontControl* systemFontControl) = 0;
            /**
             * @brief Get a registered system-font control object.
             * @param index The zero-based index of the control.
             * @return The system-font control object or null if the index is out of range.
             */
            virtual ISystemFontControl* GetSystemFontControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a web control object to the output device handler.
             * @param webControl The web control object to add.
             * @return true if successful.
             */
            virtual Bool AddWebControl(IWebControl* webControl) = 0;
            /**
             * @brief Remove a web control object from the output device handler.
             * @param webControl The web control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveWebControl(const IWebControl* webControl) = 0;
            /**
             * @brief Get a registered web control object.
             * @param index The zero-based index of the control.
             * @return The web control object or null if the index is out of range.
             */
            virtual IWebControl* GetWebControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a screen-shot control object to the output device handler.
             * @param screenshotControl The screen-shot control object to add.
             * @return true if successful.
             */
            virtual Bool AddScreenshotControl(IScreenshotControl* screenshotControl) = 0;
            /**
             * @brief Remove a screen-shot control object from the output device handler.
             * @param screenshotControl The screen-shot control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveScreenshotControl(const IScreenshotControl* screenshotControl) = 0;
            /**
             * @brief Get a registered screen-shot control object.
             * @param index The zero-based index of the control.
             * @return The screen-shot control object or null if the index is out of range.
             */
            virtual IScreenshotControl* GetScreenshotControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a preferences control object to the output device handler.
             * @param preferencesControl The preferences control object to add.
             * @return true if successful.
             */
            virtual Bool AddPreferencesControl(IPreferencesControl* preferencesControl) = 0;
            /**
             * @brief Remove a preferences control object from the output device handler.
             * @param preferencesControl The preferences control object to remove.
             * @return true if successful.
             */
            virtual Bool RemovePreferencesControl(const IPreferencesControl* preferencesControl) = 0;
            /**
             * @brief Get a registered preferences control object.
             * @param index The zero-based index of the control.
             * @return The preferences control object or null if the index is out of range.
             */
            virtual IPreferencesControl* GetPreferencesControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a telephony control object to the output device handler.
             * @param telephonyControl The telephony control object to add.
             * @return true if successful.
             */
            virtual Bool AddTelephonyControl(ITelephonyControl* telephonyControl) = 0;
            /**
             * @brief Remove a telephony control object from the output device handler.
             * @param telephonyControl The telephony control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveTelephonyControl(const ITelephonyControl* telephonyControl) = 0;
            /**
             * @brief Get a registered telephony control object.
             * @param index The zero-based index of the control.
             * @return The telephony control object or null if the index is out of range.
             */
            virtual ITelephonyControl* GetTelephonyControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a media control object to the output device handler.
             * @param mediaControl The media control object to add.
             * @return true if successful.
             */
            virtual Bool AddMediaControl(IMediaControl* mediaControl) = 0;
            /**
             * @brief Remove a media control object from the output device handler.
             * @param mediaControl The media control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveMediaControl(const IMediaControl* mediaControl) = 0;
            /**
             * @brief Get a registered media control object.
             * @param index The zero-based index of the control.
             * @return The media control object or null if the index is out of range.
             */
            virtual IMediaControl* GetMediaControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a music player control object to the output device handler.
             * @param musicPlayerControl The music player control object to add.
             * @return true if successful.
             */
            virtual Bool AddMusicPlayerControl(IMusicPlayerControl* musicPlayerControl) = 0;
            /**
             * @brief Remove a music player control object from the output device handler.
             * @param musicPlayerControl The music player control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveMusicPlayerControl(const IMusicPlayerControl* musicPlayerControl) = 0;
            /**
             * @brief Get a registered music player control object.
             * @param index The zero-based index of the control.
             * @return The music player control object or null if the index is out of range.
             */
            virtual IMusicPlayerControl* GetMusicPlayerControl(UInt32 index = 0) const = 0;

            /**
             * @brief Add a custom control object to the output device handler.
             * The identifier of the custom control is the control's name.
             * @param customControl The custom control object to add.
             * @return true if successful.
             */
            virtual Bool AddCustomControl(ICustomControlable* customControl) = 0;
            /**
             * @brief Add a custom control object to the output device handler.
             * @param name The identifier of the custom control.
             * @param customControl The custom control object to add.
             * @return true if successful.
             */
            virtual Bool AddCustomControl(const String& name, ICustomControlable* customControl) = 0;
            /**
             * @brief Remove a custom control object from the output device handler.
             * @param name The identifier of the custom control to remove.
             * @return The removed custom control object.
             */
            virtual ICustomControlable* RemoveCustomControl(const String& name) = 0;
            /**
             * @brief Remove a custom control object from the output device handler.
             * @param customControl The custom control object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveCustomControl(const ICustomControlable* customControl) = 0;
            /**
             * @brief Get a registered custom control object by name.
             * @param name The identifier of the custom control.
             * @return The custom control object or null if the identifier is not found.
             */
            virtual ICustomControlable* GetCustomControl(const String& name) const = 0;
            /**
             * @brief Get the number of registered custom controls.
             * @return The number of registered custom controls.
             */
            virtual UInt32 GetNumberOfCustomControls() const = 0;
            /**
             * @brief Get a registered custom control object by index.
             * A valid device index is [0 .. GetNumberOfCustomControls() - 1].
             * @param index The zero-based index of the control.
             * @return The custom control object or null if the index is out of range.
             */
            virtual ICustomControlable* GetCustomControl(UInt32 index) const = 0;

        protected:
            virtual ~IDeviceHandler() {}
        };
    }
}

#endif  // __MURL_OUTPUT_I_DEVICE_HANDLER_H__

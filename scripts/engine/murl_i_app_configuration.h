// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_APP_CONFIGURATION_H__
#define __MURL_I_APP_CONFIGURATION_H__

#include "murl_i_enums.h"
#include "murl_change_controller.h"

namespace Murl
{
    class IEngineConfiguration;
    class IPlatformConfiguration;
    class IApp;

    /**
     * @ingroup MurlConfigurationInterfaces
     * @interface IAppConfiguration
     * @brief The application configuration interface defines the application-specific
     * settings which can be modified during runtime.
     *
     * (!) Specific platform implementations may not react on all modifications.
     */
    class IAppConfiguration
    {
    public:
        /**
         * @brief Get the const platform configuration object.
         * @return The platform configuration object.
         */
        virtual const IPlatformConfiguration* GetPlatformConfiguration() const = 0;
        /**
         * @brief Get the const engine configuration object.
         * @return The engine configuration object.
         */
        virtual const IEngineConfiguration* GetEngineConfiguration() const = 0;

        /**
         * @brief Check is any configuration setting has changed.
         * @param inspector The change inspector.
         * @return true if any configuration setting has changed.
         */
        virtual Bool HasChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Register the app with this configuration.
         * @param app The app to register.
         * @return true if successful.
         */
        virtual Bool RegisterApp(const IApp* app) = 0;
        /**
         * @brief Unregister the app from this configuration.
         * @param app The app to unregister.
         * @return true if successful.
         */
        virtual Bool UnregisterApp(const IApp* app) = 0;
        /**
         * @brief Check if the current user-defined configuration is matching a given ID.
         * @param userConfigId The ID of the user-defined config to check.
         * @return true if the current language is the language to check.
         */
        virtual Bool IsUserConfigurationMatching(const String& userConfigId) const = 0;

        /**
         * @brief Set the window title.
         * The window title is displayed on desktop platforms only.
         * The window title can be modified during runtime.
         *
         * The OSX platform uses the window title to replace "%@" in
         * the interface builder's main window title.
         *
         * The default window title is "Murl Engine".
         * On OSX and iOS the window title is set to the CFBundleExecutable identifier.
         * @param title The window title string.
         */
        virtual void SetWindowTitle(const String& title) = 0;
        /**
         * @brief Get the window title.
         * @return The window title string.
         */
        virtual const String& GetWindowTitle() const = 0;
        /**
         * @brief Check if the window title has changed.
         * @param inspector The change inspector.
         * @return true if the window title has changed.
         */
        virtual Bool HasWindowTitleChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the current language.
         * The current language can be modified during runtime.\n
         * The default current language is IEnums::LANGUAGE_ENGLISH.
         * @param language The current language.
         */
        virtual void SetLanguage(IEnums::Language language) = 0;
        /**
         * @brief Get the current language.
         * @return The current language.
         */
        virtual IEnums::Language GetLanguage() const = 0;
        /**
         * @brief Check if the current language is matching a given one.
         * @param language The language to check.
         * @return true if the current language is the language to check.
         */
        virtual Bool IsLanguageMatching(IEnums::Language language) const = 0;
        /**
         * @brief Check if the current language has changed.
         * @param inspector The change inspector.
         * @return true if the current language has changed.
         */
        virtual Bool HasLanguageChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the current currency symbol.
         * @param currencySymbol The current currency symbol.
         */
        virtual void SetCurrencySymbol(const String& currencySymbol) = 0;
        /**
         * @brief Get the current currency symbol.
         * @return The current currency symbol.
         */
        virtual const String& GetCurrencySymbol() const = 0;
        /**
         * @brief Check if the current currency symbol has changed.
         * @param inspector The change inspector.
         * @return true if the current currency symbol has changed.
         */
        virtual Bool HasCurrencySymbolChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the current currency code.
         * @param currencyCode The current currency code.
         */
        virtual void SetCurrencyCode(const String& currencyCode) = 0;
        /**
         * @brief Get the current international currency symbol.
         *  A country typically has a local currency symbol and an international currency symbol.\n
         *  The local symbol is used within the country, while the international currency symbol
         *  is used in international contexts to specify that country’s currency unambiguously.
         * @return The current international currency symbol.
         */
        virtual const String& GetCurrencyCode() const = 0;
        /**
         * @brief Check if the current currency code has changed.
         * @param inspector The change inspector.
         * @return true if the current currency code has changed.
         */
        virtual Bool HasCurrencyCodeChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the current decimal separator.
         * @param decimalSeparator The current decimal separator.
         */
        virtual void SetDecimalSeparator(const String& decimalSeparator) = 0;
        /**
         * @brief Get the current decimal separator.
         * @return The current decimal separator.
         */
        virtual const String& GetDecimalSeparator() const = 0;
        /**
         * @brief Check if the current decimal separator has changed.
         * @param inspector The change inspector.
         * @return true if the current decimal separator has changed.
         */
        virtual Bool HasDecimalSeparatorChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the current grouping separator.
         * @param groupingSeparator The current grouping separator.
         */
        virtual void SetGroupingSeparator(const String& groupingSeparator) = 0;
        /**
         * @brief Get the current grouping separator.
         * @return The current grouping separator.
         */
        virtual const String& GetGroupingSeparator() const = 0;
        /**
         * @brief Check if the current grouping separator has changed.
         * @param inspector The change inspector.
         * @return true if the current grouping separator has changed.
         */
        virtual Bool HasGroupingSeparatorChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the current application run state.
         * The current application run state is typically modified by the platform
         * depending on the IEngineConfiguration::SetDeactivatedAppRunState().
         *
         * Run state changes are reported to the application by calling the
         * Logic::IEngineProcessor::RunStateChanged() method which calls
         * Logic::IAppProcessor::OnRunStateChanged() for all child processors.
         * @param appRunState The current application run state.
         */
        virtual void SetAppRunState(IEnums::AppRunState appRunState) = 0;
        /**
         * @brief Get the current application run state.
         * @return The current application run state.
         */
        virtual IEnums::AppRunState GetAppRunState() const = 0;
        /**
         * @brief Check if the current application run state has changed.
         * @param inspector The change inspector.
         * @return true if the current application run state has changed.
         */
        virtual Bool HasAppRunStateChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the memory warning state.
         * The memory warning state is typically set by the iOS platform
         * to signal low memory from ApplicationDidReceiveMemoryWarning.
         * On Android this state is set/cleared if the ActivityManager.MemoryInfo()
         * lowMemory member changes (updated each frame).
         * @param warn The memory warning state.
         */
        virtual void SetMemoryWarning(Bool warn) = 0;
        /**
         * @brief Get the memory warning state.
         * @return true if the a memory warning occured.
         */
        virtual Bool GetMemoryWarning() const = 0;
        /**
         * @brief Check if the memory warning state has changed.
         * @param inspector The change inspector.
         * @return true if the memory warning state has changed.
         */
        virtual Bool HasMemoryWarningChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable/disable automatic resource eviction.
         * If enabled, all nodes in the scene graph for which automatic swapping is
         * enabled (set via Graph::INode::SetAutomaticSwappingEnabled() or via the
         * node's "enableAutomaticSwapping" XML attribute) will also try to evict any
         * additional resources (e.g. texture memory surfaces) to save memory. However,
         * when these nodes are restored later on, there may be an extra performance
         * cost for re-creating these resources at run time. By default, automatic
         * eviction is disabled; it is considered good practice to only enable it
         * once a memory warning occurred (see GetMemoryWarning()).
         * Note that when manual swapping is enabled on a node (via "enableManualSwapping"
         * or Graph::INode::SetManualSwappingEnabled()), the engine always tries to evict
         * the node's resources when manual swapping is triggered via
         * Graph::IRoot::TriggerSwapping().
         * @param enabled If true, automatic resource eviction is enabled.
         */
        virtual void SetAutomaticResourceEvictionEnabled(Bool enabled) = 0;
        /**
         * @brief Check if automatic resource eviction is enabled.
         * @return true if enabled.
         */
        virtual Bool IsAutomaticResourceEvictionEnabled() const = 0;
        /**
         * @brief Check if the automatic resource eviction property has changed.
         * @param inspector The change inspector.
         * @return true if changed.
         */
        virtual Bool HasAutomaticResourceEvictionEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Activate the multi-touch functionality.
         * Activate to receive data by multiple Input::ITouchScreenDevice instances.
         *
         * This feature is currently supported by iOS platform only.
         * This feature can be activated / deactivated during runtime.
         *
         * The default multi-touch activation state is true.
         * @param enable true to enable the multi-touch functionality.
         */
        virtual void SetMultiTouchActive(Bool enable) = 0;
        /**
         * @brief Check if the multi-touch functionality is activated.
         * @return true if the multi-touch functionality is activated.
         */
        virtual Bool IsMultiTouchActive() const = 0;
        /**
         * @brief Check if the multi-touch activation state has changed.
         * @param inspector The change inspector.
         * @return true if the multi-touch activation state has changed.
         */
        virtual Bool HasMultiTouchActiveChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Activate the accelerometer functionality.
         * Activate to receive data by the Input::IAccelerometerDevice.
         *
         * This feature is currently supported by iOS and Android platform.
         * This feature can be activated / deactivated during runtime.
         *
         * The default accelerometer activation state is false.
         * @param enable true to enable the accelerometer functionality.
         */
        virtual void SetAccelerometerActive(Bool enable) = 0;
        /**
         * @brief Check if the accelerometer functionality is activated.
         * @return true if the accelerometer functionality is activated.
         */
        virtual Bool IsAccelerometerActive() const = 0;
        /**
         * @brief Check if the accelerometer activation state has changed.
         * @param inspector The change inspector.
         * @return true if the accelerometer activation state has changed.
         */
        virtual Bool HasAccelerometerActiveChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the accelerometer frequency.
         * This feature is currently supported by iOS platform only.
         * This feature can be activated / deactivated during runtime.
         *
         * The default accelerometer frequency is 60.
         * @param frequency The accelerometer frequency in samples per second.
         */
        virtual void SetAccelerometerFrequency(UInt32 frequency) = 0;
        /**
         * @brief Get the accelerometer frequency.
         * @return The accelerometer frequency in samples per second.
         */
        virtual UInt32 GetAccelerometerFrequency() const = 0;
        /**
         * @brief Check if the accelerometer frequency has changed.
         * @param inspector The change inspector.
         * @return true if the accelerometer frequency has changed.
         */
        virtual Bool HasAccelerometerFrequencyChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Activate the gyroscope functionality.
         * Activate to receive data by the Input::IGyroscopeDevice.
         *
         * This feature is currently supported by iOS and Android platform.
         * This feature can be activated / deactivated during runtime.
         *
         * The default gyroscope activation state is false.
         * @param enable true to enable the gyroscope functionality.
         */
        virtual void SetGyroscopeActive(Bool enable) = 0;
        /**
         * @brief Check if the gyroscope functionality is activated.
         * @return true if the gyroscope functionality is activated.
         */
        virtual Bool IsGyroscopeActive() const = 0;
        /**
         * @brief Check if the gyroscope activation state has changed.
         * @param inspector The change inspector.
         * @return true if the gyroscope activation state has changed.
         */
        virtual Bool HasGyroscopeActiveChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the gyroscope frequency.
         * This feature is currently supported by iOS platform only.
         * This feature can be activated / deactivated during runtime.
         *
         * The default gyroscope frequency is 60.
         * @param frequency The gyroscope frequency in samples per second.
         */
        virtual void SetGyroscopeFrequency(UInt32 frequency) = 0;
        /**
         * @brief Get the gyroscope frequency.
         * @return The gyroscope frequency in samples per second.
         */
        virtual UInt32 GetGyroscopeFrequency() const = 0;
        /**
         * @brief Check if the gyroscope frequency has changed.
         * @param inspector The change inspector.
         * @return true if the gyroscope frequency has changed.
         */
        virtual Bool HasGyroscopeFrequencyChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Activate the location functionality.
         * Activate to receive data by the Input::ILocationDevice.
         *
         * This feature is currently supported by iOS, OSX and Android platform.
         * This feature can be activated / deactivated during runtime.
         *
         * The default location activation state is false.
         * @param enable true to enable the location functionality.
         */
        virtual void SetLocationActive(Bool enable) = 0;
        /**
         * @brief Check if the location functionality is activated.
         * @return true if the location functionality is activated.
         */
        virtual Bool IsLocationActive() const = 0;
        /**
         * @brief Check if the location activation state has changed.
         * @param inspector The change inspector.
         * @return true if the location activation state has changed.
         */
        virtual Bool HasLocationActiveChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the location distance filter.
         * The minimum distance a device must move horizontally before an event is generated.
         *
         * This feature is currently supported by iOS, OSX and Android platform.
         * This value can be modified during runtime on iOS and OSX only.
         *
         * The default value is zero, which reports all movements.
         * @param meters The minimum distance in meters.
         */
        virtual void SetLocationDistanceFilter(Real meters) = 0;
        /**
         * @brief Get the location distance filter.
         * @return The minimum distance in meters.
         */
        virtual Real GetLocationDistanceFilter() const = 0;
        /**
         * @brief Check if the location distance filter has changed.
         * @param inspector The change inspector.
         * @return true if the location distance filter has changed.
         */
        virtual Bool HasLocationDistanceFilterChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the location accuracy.
         * The receiver does its best to achieve the requested accuracy, however,
         * the actual accuracy is not guaranteed.
         * You should assign a value that is appropriate for your usage scenario.
         * Determining a location with greater accuracy requires more time and more power.
         *
         * This feature is currently supported by iOS and OSX platform.
         * This value can be modified during runtime.
         *
         * The default value is zero, which is the highest accuracy of the device.
         * @param meters The location accuracy in meters, if the accuracy is negative
         *  the highest possible accuracy combined with additional sensor data is used.
         *  This level of accuracy is intended for use in navigation applications that
         *  require precise position information at all times and are intended to be
         *  used only while the device is plugged in.
         */
        virtual void SetLocationAccuracy(Real meters) = 0;
        /**
         * @brief Get the location accuracy.
         * @return The accuracy in meters.
         */
        virtual Real GetLocationAccuracy() const = 0;
        /**
         * @brief Check if the location accuracy has changed.
         * @param inspector The change inspector.
         * @return true if the location accuracy has changed.
         */
        virtual Bool HasLocationAccuracyChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the location purpose description.
         * If the system needs to ask for the user’s consent to use location services,
         * it displays the location purpose description which should explain why the
         * application is using the location services.
         *
         * This feature is currently supported by iOS and OSX platform.
         * This value can be modified during runtime.
         *
         * The default value is an empty string.
         * @param purpose The location purpose description string.
         */
        virtual void SetLocationPurpose(const String& purpose) = 0;
        /**
         * @brief Get the location purpose description.
         * @return The location purpose description string.
         */
        virtual const String& GetLocationPurpose() const = 0;
        /**
         * @brief Check if the location purpose description has changed.
         * @param inspector The change inspector.
         * @return true if the location purpose description has changed.
         */
        virtual Bool HasLocationPurposeChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Activate the heading functionality.
         * Activate to receive data by the Input::IHeadingDevice.
         *
         * This feature is currently supported by iOS, OSX and Android platform.
         * This feature can be activated / deactivated during runtime.
         *
         * The default heading activation state is false.
         * @param enable true to enable the heading functionality.
         */
        virtual void SetHeadingActive(Bool enable) = 0;
        /**
         * @brief Check if the heading functionality is activated.
         * @return true if the heading functionality is activated.
         */
        virtual Bool IsHeadingActive() const = 0;
        /**
         * @brief Check if the heading activation state has changed.
         * @param inspector The change inspector.
         * @return true if the heading activation state has changed.
         */
        virtual Bool HasHeadingActiveChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Allow the heading calibration alert.
         * Allow to displays the heading calibration alert on top of
         * the current window immediately if requested by the system.
         *
         * This feature is currently supported by iOS platform only.
         * This value can be modified during runtime.
         *
         * The default value is true.
         * @param enable true to allow the heading calibration alert.
         */
        virtual void SetHeadingCalibrationAllowed(Bool enable) = 0;
        /**
         * @brief Check if the heading calibration alert is allowed.
         * @return true if the heading calibration alert is allowed.
         */
        virtual Bool IsHeadingCalibrationAllowed() const = 0;
        /**
         * @brief Check if the heading calibration alert permission has changed.
         * @param inspector The change inspector.
         * @return true if the heading calibration alert permission has changed.
         */
        virtual Bool HasHeadingCalibrationAllowedChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Activate the screen auto-rotation functionality.
         * Requires active orientation functionality SetOrientationActive(true).
         *
         * This feature is currently supported by iOS and Android platform.
         * This value can be modified during runtime.
         *
         * The default screen auto-rotation activation state is false.
         * @param enable true to allow the screen auto-rotation functionality.
         */
        virtual void SetAutoRotationActive(Bool enable) = 0;
        /**
         * @brief Check if the screen auto-rotation functionality is activated.
         * @return true if the screen auto-rotation functionality is activated.
         */
        virtual Bool IsAutoRotationActive() const = 0;
        /**
         * @brief Check if the screen auto-rotation activation state has changed.
         * @param inspector The change inspector.
         * @return true if the screen auto-rotation activation state has changed.
         */
        virtual Bool HasAutoRotationActiveChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the duration of the screen auto-rotation animation.
         * Describes the duration of a screen rotation by 90 degrees,
         * if rotating by 180 degrees the time is doubled.\n
         * A duration of zero means no animation.
         *
         * This feature is supported by iOS platform only.
         * This value can be modified during runtime.
         *
         * The default screen auto-rotation duration is 0.3 seconds.
         * @param duration The screen auto-rotation duration in seconds.
         */
        virtual void SetAutoRotationDuration(Real duration) = 0;
        /**
         * @brief Get the duration of the screen auto-rotation animation.
         * @return The screen auto-rotation duration in seconds.
         */
        virtual Real GetAutoRotationDuration() const = 0;
        /**
         * @brief Check if the duration of the screen auto-rotation animation has changed.
         * @param inspector The change inspector.
         * @return true if the screen auto-rotation duration has changed.
         */
        virtual Bool HasAutoRotationDurationChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Activate the device orientation functionality.
         * Activate to receive data by the Input::IOrientationDevice.
         *
         * This feature is currently supported by iOS and Android platform.
         * This feature can be activated / deactivated during runtime.
         *
         * The default device orientation activation state is false.
         * @param enable true to enable the device orientation functionality.
         */
        virtual void SetOrientationActive(Bool enable) = 0;
        /**
         * @brief Check if the device orientation functionality is activated.
         * @return true if the device orientation functionality is activated.
         */
        virtual Bool IsOrientationActive() const = 0;
        /**
         * @brief Check if the device orientation activation state has changed.
         * @param inspector The change inspector.
         * @return true if the device orientation activation state has changed.
         */
        virtual Bool HasOrientationActiveChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the allowed screen orientations.
         * Predefined values are IEnums::SCREEN_ORIENTATIONS_PORTRAIT,
         * IEnums::SCREEN_ORIENTATIONS_LANDSCAPE or IEnums::SCREEN_ORIENTATIONS_ALL.
         * Alternatively the IEnums::ScreenOrientation values can be binary or'ed.
         *
         * This feature is currently supported by iOS and Android platform.
         * This value can be modified during runtime.
         *
         * The default allowed orientations is IEnums::SCREEN_ORIENTATION_DEFAULT.
         * @param orientations The allowed screen orientations.
         */
        virtual void SetAllowedScreenOrientations(IEnums::CombinedScreenOrientation orientations) = 0;
        /**
         * @brief Get the allowed screen orientations.
         * @return The allowed screen orientations.
         */
        virtual IEnums::CombinedScreenOrientation GetAllowedScreenOrientations() const = 0;
        /**
         * @brief Check if the allowed screen orientations value has changed.
         * @param inspector The change inspector.
         * @return true if the allowed screen orientations value has changed.
         */
        virtual Bool HasAllowedScreenOrientationsChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the current screen orientation.
         * The current screen orientation defines the screen's orientation relative to the device.
         *
         * The engine adjust's the rendering output and the input device coordinates
         * depending on the current screen orientation.
         *
         * The current screen orientation is typically set by the platform's
         * screen auto-rotation feature, see SetAutoRotationActive().
         *
         * The default screen orientation is IEnums::SCREEN_ORIENTATION_DEFAULT.
         * @param orientation The current screen orientation.
         */
        virtual void SetScreenOrientation(IEnums::ScreenOrientation orientation) = 0;
        /**
         * @brief Get the current screen orientation.
         * @return The current screen orientation.
         */
        virtual IEnums::ScreenOrientation GetScreenOrientation() const = 0;
        /**
         * @brief Check if the current screen orientation has changed.
         * @param inspector The change inspector.
         * @return true if the current screen orientation has changed.
         */
        virtual Bool HasScreenOrientationChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the display surface orientation.
         * The display surface orientation defines the display's rendering surface orientation
         * relative to the device.
         *
         * This is typically set by the platform implementation,
         * applications should not modify this setting.
         *
         * The default display surface orientation is IEnums::SCREEN_ORIENTATION_DEFAULT.
         * @param orientation The current screen orientation.
         */
        virtual void SetDisplaySurfaceOrientation(IEnums::ScreenOrientation orientation) = 0;
        /**
         * @brief Get the display surface orientation.
         * This is typically set by the platform implementation,
         * applications should not depend on this setting.
         * @return The display surface orientation.
         */
        virtual IEnums::ScreenOrientation GetDisplaySurfaceOrientation() const = 0;
        /**
         * @brief Check if the display surface orientation has changed.
         * @param inspector The change inspector.
         * @return true if the display surface orientation has changed.
         */
        virtual Bool HasDisplaySurfaceOrientationChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Get the display-renderer orientation.
         * The display-renderer orientation is the relative rotation for
         * video rendering depending on the SetScreenOrientation() and
         * the SetDisplaySurfaceOrientation() setting.
         * @return The display-renderer orientation.
         */
        virtual IEnums::Orientation GetDisplayRendererOrientation() const = 0;
        /**
         * @brief Check if the display-renderer orientation has changed.
         * @param inspector The change inspector.
         * @return true if the display-renderer orientation has changed.
         */
        virtual Bool HasDisplayRendererOrientationChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Get the combined relative portrait orientations.
         * @return The combined relative portrait orientations.
         */
        virtual IEnums::CombinedOrientation GetPortraitOrientations() const = 0;
        /**
         * @brief Get a relative portrait orientation.
         * @param index The index in range [0 .. 1].
         * @return The relative portrait orientation.
         */
        virtual IEnums::Orientation GetPortraitOrientation(UInt32 index) const = 0;
        /**
         * @brief Check if the relative portrait orientations value has changed.
         * @param inspector The change inspector.
         * @return true if the relative portrait orientations value has changed.
         */
        virtual Bool HasPortraitOrientationsChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Get the combined relative landscape orientations.
         * @return The combined relative landscape orientations.
         */
        virtual IEnums::CombinedOrientation GetLandscapeOrientations() const = 0;
        /**
         * @brief Get a relative landscape orientation.
         * @param index The index in range [0 .. 1].
         * @return The relative landscape orientation.
         */
        virtual IEnums::Orientation GetLandscapeOrientation(UInt32 index) const = 0;
        /**
         * @brief Check if the relative landscape orientations value has changed.
         * @param inspector The change inspector.
         * @return true if the relative landscape orientations value has changed.
         */
        virtual Bool HasLandscapeOrientationsChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the display surface size.
         * The display surface size defines the video rendering size
         * and the initial window size.
         *
         * The default display surface size is set by the platform to the
         * full screen resolution of the primary monitor.
         *
         * The application can modify this setting prior to starting the
         * engine only, e.g. IApp::Configure().
         * Setting the size is not supported on Android devices.
         * @param sizeX The display surface width in pixels.
         * @param sizeY The display surface height in pixels.
         */
        virtual void SetDisplaySurfaceSize(UInt32 sizeX, UInt32 sizeY) = 0;
        /**
         * @brief Get the display surface width.
         * @return The display surface width in pixels.
         */
        virtual UInt32 GetDisplaySurfaceSizeX() const = 0;
        /**
         * @brief Get the display surface height.
         * @return The display surface height in pixels.
         */
        virtual UInt32 GetDisplaySurfaceSizeY() const = 0;
        /**
         * @brief Check if the display surface size has changed.
         * @param inspector The change inspector.
         * @return true if the display surface size has changed.
         */
        virtual Bool HasDisplaySurfaceSizeChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the display surface's safe margins.
         * On devices with a notched display and/or overlaid virtual system controls (e.g.
         * iPhone X), this specifies the margins relative to the display surface's four
         * edges making up the area that can be safely used to display relevant content
         * and/or input elements without being obscured.
         *
         * The value for x1 stores a positive offset from the left edge of the surface,
         * defining the leftmost pixel column to use. Likewise, y1 stores a positive
         * offset from the bottom edge for the bottommost row. (In fact, as the surface
         * always starts at 0/0, the values for x1 and y1 represent the actual left and
         * top pixel coordinate of the safe area).
         *
         * The values for x2 and y2 store negative offsets from the right and top edges,
         * respectively.
         *
         * Calculating the actual coordinate values can be done this way:
         * x1 = GetDisplaySurfaceSafeMarginX1();
         * y1 = GetDisplaySurfaceSafeMarginY1();
         * x2 = GetDisplaySurfaceSafeMarginX2() + GetDisplaySurfaceSizeX();
         * y2 = GetDisplaySurfaceSafeMarginY2() + GetDisplaySurfaceSizeY();
         *
         * Devices without a notch or virtual controls have all four values set to zero.
         * The actual values are defined by the platform implementation.
         * @param x1 The left offset of the safe area in pixels.
         * @param y1 The bottom offset of the safe area in pixels.
         * @param x2 The right offset of the safe area in pixels.
         * @param y2 The top offset of the safe area in pixels.
         */
        virtual void SetDisplaySurfaceSafeMargin(SInt32 x1, SInt32 y1, SInt32 x2, SInt32 y2) = 0;
        /**
         * @brief Get the display surface's left safe area margin.
         * @return The left margin in pixels.
         */
        virtual SInt32 GetDisplaySurfaceSafeMarginX1() const = 0;
        /**
         * @brief Get the display surface's bottom safe area margin.
         * @return The bottom margin in pixels.
         */
        virtual SInt32 GetDisplaySurfaceSafeMarginY1() const = 0;
        /**
         * @brief Get the display surface's right safe area margin.
         * @return The right margin in pixels.
         */
        virtual SInt32 GetDisplaySurfaceSafeMarginX2() const = 0;
        /**
         * @brief Get the display surface's top safe area margin.
         * @return The top margin in pixels.
         */
        virtual SInt32 GetDisplaySurfaceSafeMarginY2() const = 0;
        /**
         * @brief Check if the display surface's safe margins have changed.
         * @param inspector The change inspector.
         * @return true if the display surface's safe margins have changed.
         */
        virtual Bool HasDisplaySurfaceSafeMarginChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the window aspect ratio.
         * Windows are supported on desktop platforms only.
         * @param ratio The window aspect ratio (width / height).
         */
        virtual void SetWindowAspectRatio(Real ratio) = 0;
        /**
         * @brief Set the window aspect ratio by integer.
         * Windows are supported on desktop platforms only.
         * @param numerator The window aspect numerator value.
         * @param denominator The window aspect denominator value.
         */
        virtual void SetWindowAspectRatio(UInt32 numerator, UInt32 denominator) = 0;
        /**
         * @brief Get the window aspect ratio.
         * Windows are supported on desktop platforms only.
         * @return The window aspect ratio (width / height).
         */
        virtual Real GetWindowAspectRatio() const = 0;
        /**
         * @brief Get the window aspect numerator.
         * Windows are supported on desktop platforms only.
         * @return The window aspect numerator value.
         */
        virtual UInt32 GetWindowAspectRatioNumerator() const = 0;
        /**
         * @brief Get the window aspect denominator.
         * Windows are supported on desktop platforms only.
         * @return The window aspect denominator value.
         */
        virtual UInt32 GetWindowAspectRatioDenominator() const = 0;
        /**
         * @brief Check if the window aspect ratio has changed.
         * @param inspector The change inspector.
         * @return true if the window aspect ratio has changed.
         */
        virtual Bool HasWindowAspectRatioChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Get the window width.
         * The initial window width is set to the size passed
         * to SetDisplaySurfaceSize().
         *
         * Windows are supported on desktop platforms only.
         * @return The window width in pixels.
         */
        virtual UInt32 GetWindowSizeX() const = 0;
        /**
         * @brief Get the window height.
         * The initial window height is set to the size passed
         * to SetDisplaySurfaceSize().
         *
         * Windows are supported on desktop platforms only.
         * @return The window height in pixels.
         */
        virtual UInt32 GetWindowSizeY() const = 0;
        /**
         * @brief Check if the window size has changed.
         * @param inspector The change inspector.
         * @return true if the window size has changed.
         */
        virtual Bool HasWindowSizeChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Lock the window aspect ratio.
         * Windows are supported on desktop platforms only.
         * @param enable true to lock the window aspect ratio.
         */
        virtual void SetLockWindowAspectEnabled(Bool enable) = 0;
        /**
         * @brief Check if the window aspect ratio is locked.
         * Windows are supported on desktop platforms only.
         * @return true if the window aspect ratio is locked.
         */
        virtual Bool IsLockWindowAspectEnabled() const = 0;
        /**
         * @brief Check if the window aspect ratio lock has changed.
         * @param inspector The change inspector.
         * @return true if the window aspect ratio lock has changed.
         */
        virtual Bool HasLockWindowAspectEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Hide the mouse cursor.
         * The mouse cursor is supported on desktop platforms only.
         * @param hide true to hide the mouse cursor.
         */
        virtual void SetMouseCursorHidden(Bool hide) = 0;
        /**
         * @brief Check if the mouse cursor is hidden.
         * The mouse cursor is supported on desktop platforms only.
         * @return true the mouse cursor is hidden.
         */
        virtual Bool IsMouseCursorHidden() const = 0;
        /**
         * @brief Check if the mouse cursor is hidden status has changed.
         * @param inspector The change inspector.
         * @return true if the mouse cursor is hidden status has changed.
         */
        virtual Bool HasMouseCursorHiddenChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Disable the mouse cursor.
         * If the mouse cursor is disabled no mouse coordinates are generated
         * but mouse movement can be accessed by Input::IRawMouseDevice.
         * When disabling the mouse cursor typically SetMouseCursorHidden(true)
         * should be called too.
         *
         * The mouse cursor is supported on desktop platforms only.
         * @param disable true to disable the mouse cursor.
         */
        virtual void SetMouseCursorDisabled(Bool disable) = 0;
        /**
         * @brief Check if the mouse cursor is disabled.
         * The mouse cursor is supported on desktop platforms only.
         * @return true the mouse cursor is disabled.
         */
        virtual Bool IsMouseCursorDisabled() const = 0;
        /**
         * @brief Check if the mouse cursor is disabled status has changed.
         * @param inspector The change inspector.
         * @return true if the mouse cursor is disabled status has changed.
         */
        virtual Bool HasMouseCursorDisabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Disable mouse input coordinate clamping.
         * By default, input mouse coordinates are clamped to the range [-1.0 .. 1.0],
         * which represents the actual screen bounds in view space.
         * @param disable true to disable the coordinate clamping.
         */
        virtual void SetMouseCoordinateClampingDisabled(Bool disable) = 0;
        /**
         * @brief Check if mouse input coordinate clamping is disabled.
         * @return true ifdisabled.
         */
        virtual Bool IsMouseCoordinateClampingDisabled() const = 0;
        /**
         * @brief Check if the mouse input coordinate clamping status has changed.
         * @param inspector The change inspector.
         * @return true if changed.
         */
        virtual Bool HasMouseCoordinateClampingDisabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Disable the command-key.
         * Disabling the command-key suppresses the functionallity
         * of the windows-key.
         *
         * This feature is supported on windows platforms only.
         * @param disable true to disable the command-key.
         */
        virtual void SetCommandKeyDisabled(Bool disable) = 0;
        /**
         * @brief Check if the command-key is disabled.
         * This feature is supported on windows platforms only.
         * @return true the command-key is disabled.
         */
        virtual Bool IsCommandKeyDisabled() const = 0;
        /**
         * @brief Check if the command-key is disabled status has changed.
         * @param inspector The change inspector.
         * @return true if the command-key is disabled status has changed.
         */
        virtual Bool HasCommandKeyDisabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the desired display refresh frequency.
         * This feature is currently supported by the iOS and Android platforms only.
         * This feature can be activated / deactivated during runtime.
         * The default desired display refresh frequency is 60 frames per second.
         * @param frequency The display refresh frequency in frames per second.
         * @param forcedFrames The number of frames to subsequently force the internal
         *      clock's frame duration to the value calculated from the desired frame
         *      rate, or 0 if forcing should not be done.
         */
        virtual void SetDisplayRefreshFrequency(UInt32 frequency, UInt32 forcedFrames = 0) = 0;
        /**
         * @brief Get the display refresh frequency.
         * @return The display refresh frequency in frames per second.
         */
        virtual UInt32 GetDisplayRefreshFrequency() const = 0;
        /**
         * @brief Get the number of frames the frame duration is forced to the selected
         *      frame rate.
         * @return The number of frames to apply forcing.
         */
        virtual UInt32 GetDisplayRefreshFrequencyForcedFrames() const = 0;
        /**
         * @brief Check if the display refresh frequency has changed.
         * @param inspector The change inspector.
         * @return true if the display refresh frequency has changed.
         */
        virtual Bool HasDisplayRefreshFrequencyChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the internal clock's maximum frame delta limit.
         * The default limit is 1.0 seconds.
         * @param seconds The upper frame duration limit in seconds.
         */
        virtual void SetClockDeltaLimit(Double seconds) = 0;
        /**
         * @brief Get the internal clock's maximum frame delta limit.
         * @return The upper frame duration limit in seconds.
         */
        virtual Double GetClockDeltaLimit() const = 0;
        /**
         * @brief Check if the maximum frame delta limit has changed.
         * @param inspector The change inspector.
         * @return true if the limit has changed.
         */
        virtual Bool HasClockDeltaLimitChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the internal clock's time base factor.
         * The default time base factor is 1.0.
         * @param factor The time base factor.
         */
        virtual void SetClockTimeBase(Double factor) = 0;
        /**
         * @brief Get the internal clock's time base factor.
         * @return The time base factor.
         */
        virtual Double GetClockTimeBase() const = 0;
        /**
         * @brief Check if the clock time base has changed.
         * @param inspector The change inspector.
         * @return true if the time base has changed.
         */
        virtual Bool HasClockTimeBaseChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the internal clock's averaging factor.
         * The default averaging factor is 0.1.
         * @param factor The averaging factor.
         */
        virtual void SetClockAveragingFactor(Double factor) = 0;
        /**
         * @brief Get the internal clock's averaging factor.
         * @return The averaging factor.
         */
        virtual Double GetClockAveragingFactor() const = 0;
        /**
         * @brief Check if the clock's averaging factor has changed.
         * @param inspector The change inspector.
         * @return true if the factor has changed.
         */
        virtual Bool HasClockAveragingFactorChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set run loop trigger hints.
         * @param triggers A combination of IEnums::RunLoopTrigger values.
         */
        virtual void SetRunLoopTriggers(IEnums::RunLoopTriggers triggers) = 0;
        /**
         * @brief Get run loop trigger hints.
         * @return A combination of IEnums::RunLoopTrigger values.
         */
        virtual IEnums::RunLoopTriggers GetRunLoopTriggers() const = 0;
        /**
         * @brief Check if the run loop triggers have changed.
         * @param inspector The change inspector.
         * @return true if changed.
         */
        virtual Bool HasRunLoopTriggersChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable the full screen display.
         * The full screen display is a borderless window which
         * covers the entire screen of the window's current monitor.
         *
         * The default full screen display state is enabled.
         * Windows are supported on desktop platforms only.
         * @param enable true to enable the full screen display.
         */
        virtual void SetFullScreenEnabled(Bool enable) = 0;
        /**
         * @brief Check if the full screen display is enabled.
         * Windows are supported on desktop platforms only.
         * @return true if the full screen display is enabled.
         */
        virtual Bool IsFullScreenEnabled() const = 0;
        /**
         * @brief Check if the full screen display status has changed.
         * @param inspector The change inspector.
         * @return true if the full screen display status has changed.
         */
        virtual Bool HasFullScreenEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable or disable auto-hiding of the home indicator on iOS 11+ devices, if present.
         * If enabled the home indicator will automatically be hidden when there is no user input
         * for a certain amount of time.
         *
         * This option is only available on devices that do not have a physical home button and
         * show a virtual home indicator instead, such as iPhone X/XS/XR etc. On all other devices,
         * setting this option has no effect.
         *
         * The default value is true.
         * @param enabled true to enable.
         */
        virtual void SetIosHomeIndicatorAutoHiddenEnabled(Bool enabled) = 0;
        /**
         * @brief Check if auto-hiding of the home indicator is enabled.
         * @return true if the feature is enabled.
         */
        virtual Bool IsIosHomeIndicatorAutoHiddenEnabled() const = 0;
        /**
         * @brief Check if auto-hiding of the home indicator has changed.
         * @param inspector The change inspector.
         * @return true if the setting has changed.
         */
        virtual Bool HasIosHomeIndicatorAutoHiddenChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set screen edges with user gesture precedence over system gestures.
         * This option is only available for iOS 11+ devices. On all other devices, setting this
         * option has no effect.
         *
         * The default value specifies all edges.
         * @param edges A bit mask of preferred edges.
         */
        virtual void SetIosPreferredScreenEdgesDeferringSystemGestures(IEnums::CombinedScreenEdges edges) = 0;
        /**
         * @brief Get screen edges with user gesture precedence over system gestures.
         * @return A bit mask of preferred edges.
         */
        virtual IEnums::CombinedScreenEdges GetIosPreferredScreenEdgesDeferringSystemGestures() const = 0;
        /**
         * @brief Check if user gesture precedence edges have changed.
         * @param inspector The change inspector.
         * @return true if the setting has changed.
         */
        virtual Bool HasIosPreferredScreenEdgesDeferringSystemGesturesChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable or disable low profile mode for navigation bars on Android devices.
         * If enabled the navigation bar will switch to (dimmed) low profile mode.
         *
         * This option is only available on devices where the Android API level 
         * is greater than or equal to 14 (Android 4.0 ICE_CREAM_SANDWICH).  Enabling this 
         * feature will have no effect on devices with API level smaller than 14.
         *
         * The default value is false.
         * @param enabled true to enable.
         */
        virtual void SetAndroidLowProfileNavigationBarEnabled(Bool enabled) = 0;
        /**
         * @brief Check if the low profile mode for navigation bars is enabled.
         * @return true if the feature is enabled.
         */
        virtual Bool IsAndroidLowProfileNavigationBarEnabled() const = 0;
        /**
         * @brief Check if the low profile mode has changed.
         * @param inspector The change inspector.
         * @return true if the setting has changed.
         */
        virtual Bool HasAndroidLowProfileNavigationBarChanged(ChangeInspector& inspector) const = 0;
        
        /**
         * @brief Enable or disable the hide navigation bar feature on Android devices.
         * If enabled the app will hide the navigation bar and set the Immersive_Sticky_Flag.
         * When system bars are hidden in immersive mode, they can be revealed temporarily 
         * with system gestures, such as swiping from the top of the screen. 
         * These transient system bars will overlay app’s content, may have some degree of 
         * transparency, and will automatically hide after a short timeout. 
         *
         * This option is only available on devices where the Android API level 
         * is greater than or equal to 18 (Android 4.4 KITKAT). Enabling this feature will have
         * no effect on devices with API level smaller than 18.
         *
         * The default value is false.
         * @param enabled true to enable.
         */
        virtual void SetAndroidHideNavigationBarImmersiveStickyEnabled(Bool enabled) = 0;
        /**
         * @brief Check if the hide navigation bar feature is enabled.
         * @return true if the feature is enabled.
         */
        virtual Bool IsAndroidHideNavigationBarImmersiveStickyEnabled() const = 0;
        /**
         * @brief Check if the hide navigation bar feature has changed.
         * @param inspector The change inspector.
         * @return true if the setting has changed.
         */
        virtual Bool HasAndroidHideNavigationBarImmersiveStickyChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable the system debug-info display.
         * The system debug-info display is available if the
         * built-in "debug" resource package is loaded.
         *
         * The default system debug-info state is enabled.
         * @param enable true to enable the system debug-info display.
         */
        virtual void SetSystemDebugInfoEnabled(Bool enable) = 0;
        /**
         * @brief Check if the system debug-info display is enabled.
         * @return true if the system debug-info display is enabled.
         */
        virtual Bool IsSystemDebugInfoEnabled() const = 0;
        /**
         * @brief Check if the system debug-info status has changed.
         * @param inspector The change inspector.
         * @return true if the system debug-info status has changed.
         */
        virtual Bool HasSystemDebugInfoEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the system debug-info scale factor.
         * The system debug-info display is available if the
         * built-in "debug" resource package is loaded.
         *
         * The default system debug-info scale factor is 1.
         * @param factor The system debug-info scale factor.
         */
        virtual void SetSystemDebugInfoScaleFactor(Real factor) = 0;
        /**
         * @brief Get the system debug-info scale factor.
         * @return The system debug-info scale factor.
         */
        virtual Real GetSystemDebugInfoScaleFactor() const = 0;
        /**
         * @brief Check if the system debug-info scale factor has changed.
         * @param inspector The change inspector.
         * @return true if the system debug-info scale factor has changed.
         */
        virtual Bool HasSystemDebugInfoScaleFactorChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Select which items to display in the system debug info display.
         * This method can be used to manually select which debug info should be displayed.
         * The itemMask parameter represents a bit mask of individual IEnums::StatisticItem
         * values.
         * @param itemMask The bit mask of items to display.
         */
        virtual void SetSystemDebugInfoItems(UInt32 itemMask) = 0;
        /**
         * @brief Get the bit mask of displayed debug info items.
         * @return The bit mask of displayed items.
         */
        virtual UInt32 GetSystemDebugInfoItems() const = 0;
        /**
         * @brief Check if the system debug-info items have changed.
         * @param inspector The change inspector.
         * @return true if the system debug-info items have changed.
         */
        virtual Bool HasSystemDebugInfoItemsChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable the user debug-info display.
         * The user debug-info display is available if the
         * built-in "debug" resource package is loaded.
         * The user debug-info can be set by Logic::IState::SetUserDebugMessage().
         *
         * The default user debug-info state is enabled.
         * @param enable true to enable the user debug-info display.
         */
        virtual void SetUserDebugInfoEnabled(Bool enable) = 0;
        /**
         * @brief Check if the user debug-info display is enabled.
         * @return true if the user debug-info display is enabled.
         */
        virtual Bool IsUserDebugInfoEnabled() const = 0;
        /**
         * @brief Check if the user debug-info status has changed.
         * @param inspector The change inspector.
         * @return true if the user debug-info status has changed.
         */
        virtual Bool HasUserDebugInfoEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the user debug-info scale factor.
         * The user debug-info display is available if the
         * built-in "debug" resource package is loaded.
         * The user debug-info can be set by Logic::IState::SetUserDebugMessage().
         *
         * The default user debug-info scale factor is 1.
         * @param factor The user debug-info scale factor.
         */
        virtual void SetUserDebugInfoScaleFactor(Real factor) = 0;
        /**
         * @brief Get the user debug-info scale factor.
         * @return The user debug-info scale factor.
         */
        virtual Real GetUserDebugInfoScaleFactor() const = 0;
        /**
         * @brief Check if the user debug-info scale factor has changed.
         * @param inspector The change inspector.
         * @return true if the user debug-info scale factor has changed.
         */
        virtual Bool HasUserDebugInfoScaleFactorChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable the debug mouse pointer.
         * The debug mouse pointer is available if the
         * built-in "debug" resource package is loaded.
         *
         * The default debug mouse pointer state is disabled.
         * @param enable true to enable the debug mouse pointer.
         */
        virtual void SetDebugMouseEnabled(Bool enable) = 0;
        /**
         * @brief Check if the debug mouse pointer is enabled.
         * @return true if the debug mouse pointer is enabled.
         */
        virtual Bool IsDebugMouseEnabled() const = 0;
        /**
         * @brief Check if the debug mouse pointer status has changed.
         * @param inspector The change inspector.
         * @return true if the debug mouse pointer status has changed.
         */
        virtual Bool HasDebugMouseEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the debug mouse pointer scale factor.
         * The debug mouse pointer is available if the
         * built-in "debug" resource package is loaded.
         *
         * The default debug mouse pointer scale factor is 1.
         * @param factor The debug mouse pointer scale factor.
         */
        virtual void SetDebugMouseScaleFactor(Real factor) = 0;
        /**
         * @brief Get the debug mouse pointer scale factor.
         * @return The debug mouse pointer scale factor.
         */
        virtual Real GetDebugMouseScaleFactor() const = 0;
        /**
         * @brief Check if the debug mouse pointer scale factor has changed.
         * @param inspector The change inspector.
         * @return true if the debug mouse pointer scale factor has changed.
         */
        virtual Bool HasDebugMouseScaleFactorChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the trace/error items' verbosity bit mask.
         * The itemMask parameter represents a bit mask of individual values from the
         * IEnums::DebugOutputFunctionItem enumeration, which can be used to select individual
         * items to trace for each function/method call.
         * @param itemMask The trace item bit mask.
         */
        virtual void SetDebugOutputFunctionVerbosity(UInt32 itemMask) = 0;
        /**
         * @brief Get the trace items' bit mask.
         * @return The trace item bit mask.
         */
        virtual UInt32 GetDebugOutputFunctionVerbosity() const = 0;

        /**
         * @brief Set the global trace level used in MURL_TRACE macros.
         * When running a debug build, only those trace messages are printed whose trace
         * level is equal or below the value specified using this method. In a release build,
         * all calls to MURL_TRACE macros are removed, so no tracing occurs at all.
         * By default, the trace level is set to 1, which enables basic engine traces.
         * Increase the level to get more detailed traces from the engine, currently
         * the most detailed level is 3.
         * The default application trace level is 0, so a value of 0 disables all engine
         * traces and only prints app-specific messages. To further filter app traces,
         * the level can also be set to negative values.
         * The trace level can also be changed at run-time, so it is possible to only
         * activate more detailed traces when a specific (user-defined) condition is met.
         * @param level The global trace level.
         */
        virtual void SetDebugTraceLevel(SInt32 level) = 0;
        /**
         * @brief Get the global trace level used in MURL_TRACE macros.
         * @return The global trace level.
         */
        virtual SInt32 GetDebugTraceLevel() const = 0;

        /**
         * @brief Set the trace verbosity for scene graph tracker messages.
         * A level <= 0 disables both errors and warnings, a level of 1 enables
         * only errors and a level >= 2 enables both.
         * By default, in release builds a trace level of 1 is set, and for debug
         * builds a level of 2.
         * @param level The tracker trace level.
         */
        virtual void SetTrackerTraceLevel(SInt32 level) = 0;
        /**
         * @brief Get the trace verbosity for scene graph tracker messages.
         * @return The tracker trace level.
         */
        virtual SInt32 GetTrackerTraceLevel() const = 0;

    protected:
        virtual ~IAppConfiguration() {}
    };
}

#endif  // __MURL_I_APP_CONFIGURATION_H__

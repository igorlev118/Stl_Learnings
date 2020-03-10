// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_ENGINE_CONFIGURATION_H__
#define __MURL_I_ENGINE_CONFIGURATION_H__

#include "murl_i_enums.h"
#include "murl_change_controller.h"
#include "murl_data.h"
#include "murl_system_time.h"

namespace Murl
{
    class IPlatformConfiguration;
    class IAppConfiguration;
    class IFeatureSet;
    class IAttributes;

    /**
     * @ingroup MurlConfigurationInterfaces
     * @interface IEngineConfiguration
     * @brief The engine configuration interface defines the engine-specific settings
     * which can be modified prior to starting the engine only, e.g. IApp::Configure().
     */
    class IEngineConfiguration
    {
    public:
        /**
         * @brief Get the const platform configuration object.
         * @return The platform configuration object.
         */
        virtual const IPlatformConfiguration* GetPlatformConfiguration() const = 0;
        /**
         * @brief Get the const application configuration object.
         * @return The application configuration object.
         */
        virtual const IAppConfiguration* GetAppConfiguration() const = 0;
        /**
         * @brief Get the application configuration object.
         * @return The application configuration object.
         */
        virtual IAppConfiguration* GetAppConfiguration() = 0;

        /**
         * @brief Check is any configuration setting has changed.
         * @param inspector The change inspector.
         * @return true if any configuration setting has changed.
         */
        virtual Bool HasChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Get the mutable set of default graph parameters.
         * Use the returned object in the IApp::Configure() method to add any
         * custom parameters to be used in attribute evaluation during the creation
         * of a scene (sub-)graph.
         * @return The mutable parameters object.
         */
        virtual IAttributes* GetDefaultGraphParameters() = 0;
        /**
         * @brief Get the constant set of default graph parameters.
         * @return The constant parameters object.
         */
        virtual const IAttributes* GetDefaultGraphParameters() const = 0;

        /**
         * @brief Get the feature set object.
         * @return The feature set object.
         */
        virtual IFeatureSet* GetFeatures() = 0;
        /**
         * @brief Get the const feature set object.
         * @return The const feature set object.
         */
        virtual const IFeatureSet* GetFeatures() const = 0;

        /**
         * @brief Get the major revision of the engine.
         * @return The major revision of the engine.
         */
        virtual UInt32 GetMajorRevision() const = 0;
        /**
         * @brief Get the minor revision of the engine.
         * @return The minor revision of the engine.
         */
        virtual UInt32 GetMinorRevision() const = 0;
        /**
         * @brief Get the build number of the engine.
         * @return The build number of the engine.
         */
        virtual UInt32 GetBuildNumber() const = 0;
        /**
         * @brief Get the release state string of the engine.
         * @return The release state string of the engine.
         */
        virtual const String& GetReleaseState() const = 0;
        /**
         * @brief Get the version string of the engine.
         * @return The version string of the engine.
         */
        virtual const String& GetVersionString() const = 0;
        /**
         * @brief Get the copyright string of the engine.
         * @return The copyright string of the engine.
         */
        virtual const String& GetCopyrightString() const = 0;

        /**
         * @brief Set the licence key data.
         * @param key The licence key data.
         */
        virtual void SetLicenseKey(const UInt8* key) = 0;
        /**
         * @brief Get the licence key data object.
         * @return The licence key data object.
         */
        virtual const ConstData& GetLicenseKey() const = 0;

        /**
         * @brief Set the log file name.
         * If the log file name is set, all MURL_TRACE, MURL_ERROR
         * and MURL_ASSERT messages are written into the file.
         *
         * The default log file name is empty.
         * @param logFileName The log file name, see also SetLogFileFullPath().
         */
        virtual void SetLogFileName(const String& logFileName) = 0;
        /**
         * @brief Get the log file name.
         * @return The log file name, see also GetLogFileFullPath().
         */
        virtual const String& GetLogFileName() const = 0;

        /**
         * @brief Set the log file full path.
         * @param logFilePath The log file full path, see also SetLogFileName().
         */
        virtual void SetLogFileFullPath(const String& logFilePath) = 0;
        /**
         * @brief Get the log file full path.
         * @return The log file full path, see also GetLogFileName().
         */
        virtual const String& GetLogFileFullPath() const = 0;

        /**
         * @brief Set the engine's run loop mode.
         * @param runLoopMode The run loop mode.
         */
        virtual void SetRunLoopMode(IEnums::RunLoopMode runLoopMode) = 0;
        /**
         * @brief Get the engine's run loop mode.
         * @return The run loop mode.
         */
        virtual IEnums::RunLoopMode GetRunLoopMode() const = 0;

        /**
         * @brief Set the boot time.
         * @param time The boot time in number of seconds since 00:00 hours, Jan 1, 1970 UTC.
         */
        virtual void SetBootTime(const System::Time& time) = 0;
        /**
         * @brief Get the boot time.
         * @return The boot time in number of seconds since 00:00 hours, Jan 1, 1970 UTC
         *  or zero if not set by the platform implementation.
         */
        virtual const System::Time& GetBootTime() const = 0;
        /**
         * @brief Check if the boot time has changed.
         * @param inspector The change inspector.
         * @return true if the boot time has changed.
         */
        virtual Bool HasBootTimeChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the product name.
         * The product name is used to create a subfolder for IEnums::FILE_CATEGORY_CACHE,
         * IEnums::FILE_CATEGORY_PRIVATE, and IEnums::FILE_CATEGORY_TEMPORARY except on iOS.
         *
         * The OSX platform uses the product name to replace "%@" in all
         * interface builder's menu items.
         *
         * On OSX and iOS the product name is set to the kCFBundleExecutableKey identifier.\n
         * On Android the product name is set to the application android:label from the manifest.\n
         * On Win32 the product name is set to the "ProductName" from version info resource.
         * @param productName The product name.
         */
        virtual void SetProductName(const String& productName) = 0;
        /**
         * @brief Get the product name.
         * @return The product name or "MurlApp"
         *  if not set by the platform implementation.
         */
        virtual const String& GetProductName() const = 0;
        /**
         * @brief Check if the product name has changed.
         * @param inspector The change inspector.
         * @return true if the product name has changed.
         */
        virtual Bool HasProductNameChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the app version name.
         * On OSX and iOS the app version name is set to the kCFBundleVersionKey identifier.\n
         * On Android the app version name is set to the android:versionName from the manifest.\n
         * On Win32 the app version name is set to the "ProductVersion" from version info resource.
         * @param versionName The app version name.
         */
        virtual void SetVersionName(const String& versionName) = 0;
        /**
         * @brief Get the app version name.
         * @return The app version name or "N/A"
         *  if not set by the platform implementation.
         */
        virtual const String& GetVersionName() const = 0;
        /**
         * @brief Check if the app version name has changed.
         * @param inspector The change inspector.
         * @return true if the app version name has changed.
         */
        virtual Bool HasVersionNameChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the audio session category.
         * Setting the audio session category effects the IMusicPlayerControl only.
         *
         * If IEnums::AUDIO_SESSION_CATEGORY_MIX_AMBIENT_IF_PLAYING is set, the
         * system's audio session is set to mix ambient if another audio is playing
         * otherwise the system's audio session is not set (default category behaviour).
         * After IApp::Configure() the IMusicPlayerControl::GetPlaybackState() returns 
         * IMusicPlayerControl::PLAYBACK_PLAYING if another audio was playing at app start
         * until a IMusicPlayerControl::MusicPlayer is selected.
         *
         * The default audio session category is IEnums::AUDIO_SESSION_CATEGORY_DEFAULT.
         * @param sessionCategory The audio session category.
         */
        virtual void SetAudioSessionCategory(IEnums::AudioSessionCategory sessionCategory) = 0;
        /**
         * @brief Get the audio session category.
         * The IMusicPlayerControl does not change this item.
         * @return The audio session category.
         */
        virtual IEnums::AudioSessionCategory GetAudioSessionCategory() const = 0;
        /**
         * @brief Check if the audio session category has changed.
         * @param inspector The change inspector.
         * @return true if the audio session category has changed.
         */
        virtual Bool HasAudioSessionCategoryChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the video api enumeration value.
         * Typically the platform implementaition sets this to an appropriate value,
         * see also SetVideoRendererClassName().
         *
         * The default video api is IEnums::VIDEO_API_DEFAULT.
         * @param videoApi The video api enumeration value.
         */
        virtual void SetVideoApi(IEnums::VideoApi videoApi) = 0;
        /**
         * @brief Get the video api enumeration value.
         * @return The video api enumeration value.
         */
        virtual IEnums::VideoApi GetVideoApi() const = 0;
        /**
         * @brief Check if the video api is matching a specified value.
         * @param videoApi The video api enumeration value.
         * @return true if the video api is matching the parameter value.
         */
        virtual Bool IsVideoApiMatching(IEnums::VideoApi videoApi) const = 0;
        /**
         * @brief Check if the video api enumeration value has changed.
         * @param inspector The change inspector.
         * @return true if the video api enumeration value has changed.
         */
        virtual Bool HasVideoApiChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the audio api enumeration value.
         * Typically the platform implementaition sets this to an appropriate value,
         * see also SetAudioRendererClassName().
         *
         * The default audio api is IEnums::AUDIO_API_DEFAULT.
         * @param audioApi The audio api enumeration value.
         */
        virtual void SetAudioApi(IEnums::AudioApi audioApi) = 0;
        /**
         * @brief Get the audio api enumeration value.
         * @return The audio api enumeration value.
         */
        virtual IEnums::AudioApi GetAudioApi() const = 0;
        /**
         * @brief Check if the audio api is matching a specified value.
         * @param audioApi The audio api enumeration value.
         * @return true if the audio api is matching the parameter value.
         */
        virtual Bool IsAudioApiMatching(IEnums::AudioApi audioApi) const = 0;
        /**
         * @brief Check if the audio api enumeration value has changed.
         * @param inspector The change inspector.
         * @return true if the audio api enumeration value has changed.
         */
        virtual Bool HasAudioApiChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the video renderer class name.
         * If the video renderer class name is empty the engine creates
         * a renderer depending on the value set by SetVideoApi().
         *
         * The default video renderer class name is empty.
         * @param className The video renderer class name.
         */
        virtual void SetVideoRendererClassName(const String& className) = 0;
        /**
         * @brief Get the video renderer class name.
         * @return The video renderer class name.
         */
        virtual const String& GetVideoRendererClassName() const = 0;
        /**
         * @brief Check if the video renderer class name has changed.
         * @param inspector The change inspector.
         * @return true if the video renderer class name has changed.
         */
        virtual Bool HasVideoRendererClassNameChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the audio renderer class name.
         * If the audio renderer class name is empty the engine creates
         * a renderer depending on the value set by SetAudioApi().
         *
         * The default audio renderer class name is empty.
         * @param className The audio renderer class name.
         */
        virtual void SetAudioRendererClassName(const String& className) = 0;
        /**
         * @brief Get the audio renderer class name.
         * @return The audio renderer class name.
         */
        virtual const String& GetAudioRendererClassName() const = 0;
        /**
         * @brief Check if the audio renderer class name has changed.
         * @param inspector The change inspector.
         * @return true if the audio renderer class name has changed.
         */
        virtual Bool HasAudioRendererClassNameChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the physics simulator class name.
         * If the physics simulator class name is empty the engine creates
         * the built-in simulator.
         *
         * The default physics simulator class name is empty.
         * @param className The physics simulator class name.
         */
        virtual void SetPhysicsSimulatorClassName(const String& className) = 0;
        /**
         * @brief Get the physics simulator class name.
         * @return The physics simulator class name.
         */
        virtual const String& GetPhysicsSimulatorClassName() const = 0;
        /**
         * @brief Check if the physics simulator class name has changed.
         * @param inspector The change inspector.
         * @return true if the physics simulator class name has changed.
         */
        virtual Bool HasPhysicsSimulatorClassNameChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the resource collection class name.
         * If the resource collection class name is empty the engine creates
         * the built-in collection.
         *
         * The default resource collection class name is empty.
         * @param className The resource collection class name.
         */
        virtual void SetResourceCollectionClassName(const String& className) = 0;
        /**
         * @brief Get the resource collection class name.
         * @return The resource collection class name.
         */
        virtual const String& GetResourceCollectionClassName() const = 0;
        /**
         * @brief Check if the resource collection class name has changed.
         * @param inspector The change inspector.
         * @return true if the resource collection class name has changed.
         */
        virtual Bool HasResourceCollectionClassNameChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the preferred resource package type.
         * When a package is added to the loader in the App::Init() method without explicitly
         * specifying a file suffix (.murlres/.murlpkg), the resource system loads the first
         * appropriate package found in the folder specified by SetResourceFileCategory();
         * usually, this will be a .murlpkg file if present. During development it may
         * be convenient to directly work from .murlres packages, so one does not need to
         * run the resource packer tool every time the application is started. For this reason,
         * this method can be used to manually specify a different preferred package type.
         * By default, release builds on all platforms use the IEnums::PACKAGE_TYPE_NATIVE
         * type, and IEnums::PACKAGE_TYPE_XML is used for debug builds on all available
         * platforms except Android (where only native packages are supported).
         * If a file suffix is specified, this setting has no effect.
         * @param type The preferred resource package type.
         */
        virtual void SetPreferredResourcePackageType(IEnums::PackageType type) = 0;
        /**
         * @brief Get the preferred resource package type.
         * @return The package type
         */
        virtual IEnums::PackageType GetPreferredResourcePackageType() const = 0;
        /**
         * @brief Check if the preferred resource package type has changed.
         * @param inspector The change inspector.
         * @return true if changed.
         */
        virtual Bool HasPreferredResourcePackageTypeChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the resource file category.
         * The category specifies the working directory of the package loader.
         * On desktop platforms the category is set to Murl::IEnums::FILE_CATEGORY_CURRENT
         * in debug build, which allows easier development.
         *
         * The default resource file category is IEnums::FILE_CATEGORY_RESOURCE.
         * @param category The resource file category.
         */
        virtual void SetResourceFileCategory(IEnums::FileCategory category) = 0;
        /**
         * @brief Get the resource file category.
         * @return The resource file category.
         */
        virtual IEnums::FileCategory GetResourceFileCategory() const = 0;
        /**
         * @brief Check if the resource file category has changed.
         * @param inspector The change inspector.
         * @return true if the resource file category has changed.
         */
        virtual Bool HasResourceFileCategoryChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the deactivated application run state.
         * Depending on this setting the platform implementation decides how to
         * set the IAppConfiguration::SetAppRunState() if the application is
         * activated or deactivated.
         *
         * The application is deactivated:
         *  - If the application is sent to background on mobile platforms.
         *  - If the application's window looses it's focus on desktop platforms.
         *
         * The default deactivated application run state is IEnums::APP_RUN_STATE_DEFAULT
         * which performs no action.
         * @param appRunState The deactivated application run state.
         */
        virtual void SetDeactivatedAppRunState(IEnums::AppRunState appRunState) = 0;
        /**
         * @brief Get the deactivated application run state.
         * @return The deactivated application run state.
         */
        virtual IEnums::AppRunState GetDeactivatedAppRunState() const = 0;
        /**
         * @brief Check if the deactivated application run state has changed.
         * @param inspector The change inspector.
         * @return true if the deactivated application run state has changed.
         */
        virtual Bool HasDeactivatedAppRunStateChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the suspend unloads resources flag.
         * If the suspend unloads resources flag is true the engine unloads
         * all resource types specified by SetSuspendableResources() if the
         * IAppConfiguration::SetAppRunState() is set to IEnums::APP_RUN_STATE_SUSPENDED.
         *
         * The default suspend unloads resources flag is false.
         * @param unload The suspend unloads resources flag.
         */
        virtual void SetSuspendUnloadsResources(Bool unload) = 0;
        /**
         * @brief Get the suspend unloads resources flag.
         * @return The suspend unloads resources flag.
         */
        virtual Bool GetSuspendUnloadsResources() const = 0;
        /**
         * @brief Check if the suspend unloads resources flag has changed.
         * @param inspector The change inspector.
         * @return true if the suspend unloads resources flag has changed.
         */
        virtual Bool HasSuspendUnloadsResourcesChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the suspendable resources type.
         * See also SetSuspendUnloadsResources().
         *
         * The default suspendable resources value is IEnums::SUSPENDABLE_RESOURCE_ALL.
         * @param suspendableResources The suspendable resources type.
         */
        virtual void SetSuspendableResources(IEnums::SuspendableResources suspendableResources) = 0;
        /**
         * @brief Get the suspendable resources type.
         * @return The suspendable resources type.
         */
        virtual IEnums::SuspendableResources GetSuspendableResources() const = 0;
        /**
         * @brief Check if the suspendable resources type has changed.
         * @param inspector The change inspector.
         * @return true if the suspendable resources type has changed.
         */
        virtual Bool HasSuspendableResourcesChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the global unit size factor.
         * The global unit size factor is multiplied to the camera's unit size.
         *
         * The default global unit size factor is 1.0.
         * @param sizeX The horizontal unit size factor.
         * @param sizeY The vertical unit size factor.
         */
        virtual void SetUnitSize(Real sizeX, Real sizeY) = 0;
        /**
         * @brief Get the horizontal unit size factor.
         * @return The horizontal unit size factor.
         */
        virtual Real GetUnitSizeX() const = 0;
        /**
         * @brief Get the vertical unit size factor.
         * @return The vertical unit size factor.
         */
        virtual Real GetUnitSizeY() const = 0;
        /**
         * @brief Check if the global unit size factor has changed.
         * @param inspector The change inspector.
         * @return true if the global unit size factor has changed.
         */
        virtual Bool HasUnitSizeChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the pixel center position.
         * The pixel center position is used by the camera, the range is [0 .. 1].
         * The pixel center is typically determined by the platform implementation
         * depending on the graphic driver's properties.
         *
         * The default pixel center position is 0 / 0.
         * @param centerX The horizontal pixel center position.
         * @param centerY The vertical pixel center position.
         */
        virtual void SetPixelCenter(Real centerX, Real centerY) = 0;
        /**
         * @brief Get the horizontal pixel center position.
         * @return The horizontal pixel center position.
         */
        virtual Real GetPixelCenterX() const = 0;
        /**
         * @brief Get the vertical pixel center position.
         * @return The vertical pixel center position.
         */
        virtual Real GetPixelCenterY() const = 0;
        /**
         * @brief Check if the global pixel center position has changed.
         * @param inspector The change inspector.
         * @return true if the global pixel center position has changed.
         */
        virtual Bool HasPixelCenterChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the synchronous resource initialization timeout.
         * Is used only if SetAsyncLoadingEnabled() is set to false.
         * The timeout specifies the maximum time to use for initializing
         * multiple graphic objects before the next frame is rendered.
         * At least one object is initialized each frame which can take
         * more time than the timeout depending on the complexity of the object.
         *
         * The default timeout is 0.005 seconds.
         * @param timeout The loading timeout in seconds.
         */
        virtual void SetSyncLoadingTimeout(Double timeout) = 0;
        /**
         * @brief Get the synchronous resource initialization timeout.
         * @return The synchronous resource initialization timeout.
         */
        virtual Double GetSyncLoadingTimeout() const = 0;
        /**
         * @brief Check if the synchronous resource initialization timeout has changed.
         * @param inspector The change inspector.
         * @return true if the synchronous resource initialization timeout has changed.
         */
        virtual Bool HasSyncLoadingTimeoutChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable asynchronous resource initialization after loading.
         * Setup how to initialize loaded graphic objects:
         *  - If true the initialization is performed asynchronous in the loader
         *      thread context (in parallel to the rendering).
         *  - If false the initialization is performed synchronous in the render
         *      thread context, which blocks rendering for a specified time
         *      set up by SetSyncLoadingTimeout().
         *  - Framebuffer objects are always initialized in the render thread context.
         *
         * This feature is typically determined by the platform implementation
         * depending on the graphic driver's capabilities.
         *
         * The default value is true.
         * @param enabled true to enable.
         */
        virtual void SetAsyncLoadingEnabled(Bool enabled) = 0;
        /**
         * @brief Check if the asynchronous loading is enabled.
         * @return true if the asynchronous loading is enabled.
         */
        virtual Bool IsAsyncLoadingEnabled() const = 0;
        /**
         * @brief Check if the asynchronous loading setting has changed.
         * @param inspector The change inspector.
         * @return true if the asynchronous loading setting has changed.
         */
        virtual Bool HasAsyncLoadingEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable synchronous vertical blank page flipping.
         * The platform implementation is using this setting to enable vertical
         * blank page flipping depending on the graphic driver capabilities.
         *
         * The default value is true.
         * @param enabled true to enable.
         */
        virtual void SetSyncToVBlankEnabled(Bool enabled) = 0;
        /**
         * @brief Check if the synchronous vertical blank page flipping is enabled.
         * @return true if the synchronous vertical blank page flipping is enabled.
         */
        virtual Bool IsSyncToVBlankEnabled() const = 0;
        /**
         * @brief Check if the synchronous vertical blank page flipping setting has changed.
         * @param inspector The change inspector.
         * @return true if the synchronous vertical blank page flipping setting has changed.
         */
        virtual Bool HasSyncToVBlankEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable checks to video api calls.
         * Api checks are used for development purposes and are available in debug build only.
         *
         * The default value is false.
         * @param enabled true to enable.
         */
        virtual void SetVideoApiChecksEnabled(Bool enabled) = 0;
        /**
         * @brief Check if the video api check feature is enabled.
         * @return true if the video api check feature is enabled.
         */
        virtual Bool AreVideoApiChecksEnabled() const = 0;
        /**
         * @brief Check if the video api check setting has changed.
         * @param inspector The change inspector.
         * @return true if the video api check setting has changed.
         */
        virtual Bool HasVideoApiChecksEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Enable checks to audio api calls.
         * Api checks are used for development purposes and are available in debug build only.
         *
         * The default value is false.
         * @param enabled true to enable.
         */
        virtual void SetAudioApiChecksEnabled(Bool enabled) = 0;
        /**
         * @brief Check if the audio api check feature is enabled.
         * @return true if the audio api check feature is enabled.
         */
        virtual Bool AreAudioApiChecksEnabled() const = 0;
        /**
         * @brief Check if the audio api check setting has changed.
         * @param inspector The change inspector.
         * @return true if the audio api check setting has changed.
         */
        virtual Bool HasAudioApiChecksEnabledChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the number of antialiasing samples.
         * The platform implementation is using this setting
         * depending on the graphic driver capabilities.
         *
         * The default value is 1.
         * @param numSamples The number of antialiasing samples.
         */
        virtual void SetNumberOfAntialiasSamples(UInt32 numSamples) = 0;
        /**
         * @brief Get the number of antialiasing samples.
         * @return The number of antialiasing samples.
         */
        virtual UInt32 GetNumberOfAntialiasSamples() const = 0;
        /**
         * @brief Check if the number of antialiasing samples has changed.
         * @param inspector The change inspector.
         * @return true if the number of antialiasing samples has changed.
         */
        virtual Bool HasNumberOfAntialiasSamplesChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the default maximum texture anisotropy for filtering.
         * This value specifies the preferred maximum anisotropy used for texture filtering
         * if not specified for a given texture. The actual value is clamped to hardware-specific 
         * limits. Higher values produce better visual results, but may result in degraded
         * rendering performance.
         * The default value is 1.0, i.e. isotropic filtering (fastest). The maximum anisotropy
         * value supported by the hardware is typically around 16.0.
         * @param maxAnisotropy The default maximum texture filtering anisotropy.
         */
        virtual void SetDefaultMaxTextureAnisotropy(Real maxAnisotropy) = 0;
        /**
         * @brief Get the default maximum texture anisotropy for filtering.
         * @return The default maximum texture filtering anisotropy.
         */
        virtual Real GetDefaultMaxTextureAnisotropy() const = 0;
        /**
         * @brief Check if the default maximum texture anisotropy has changed.
         * @param inspector The change inspector.
         * @return true if the default maximum texture anisotropy has changed.
         */
        virtual Bool HasDefaultMaxTextureAnisotropyChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the texture prescale divisor.
         * The texture prescale divisor is used to shrink textures before loading
         * to the graphics memory. This allows reducing of memory usage on
         * small equipped platforms.
         *
         * The default texture prescale divisor is 1.
         * @param divisor The texture prescale divisor.
         */
        virtual void SetTexturePrescaleDivisor(UInt32 divisor) = 0;
        /**
         * @brief Get the texture prescale divisor.
         * @return The texture prescale divisor.
         */
        virtual UInt32 GetTexturePrescaleDivisor() const = 0;
        /**
         * @brief Check if the texture prescale divisor matching a specified value.
         * @param divisor The divisor value to check.
         * @return true if the texture prescale divisor is matching the parameter value.
         */
        virtual Bool IsTexturePrescaleDivisorMatching(UInt32 divisor) const = 0;
        /**
         * @brief Check if the texture prescale divisor has changed.
         * @param inspector The change inspector.
         * @return true if the texture prescale divisor has changed.
         */
        virtual Bool HasTexturePrescaleDivisorChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the exact logic tick duration.
         * Set the duration bounds to the same value, see SetBoundsForLogicTickDuration().
         * @param dt The exact logic tick duration in seconds.
         */
        virtual void SetExactLogicTickDuration(Double dt) = 0;
        /**
         * @brief Set the logic tick duration bounds.
         * The logic tick duration allows exact tick cycles for e.g. physics simulation.
         *
         * If the bounds have the same value, the SetBoundsForLogicTicksPerFrame()
         * should be set to an appropriate range.
         *
         * The default value is (0, 1).
         * @param dtMin The minimum logic tick duration in seconds.
         * @param dtMax The maximum logic tick duration in seconds.
         */
        virtual void SetBoundsForLogicTickDuration(Double dtMin, Double dtMax) = 0;
        /**
         * @brief Get minimum logic tick duration in seconds.
         * @return The minimum logic tick duration in seconds.
         */
        virtual Double GetMinimumLogicTickDuration() const = 0;
        /**
         * @brief Get maximum logic tick duration in seconds.
         * @return The maximum logic tick duration in seconds.
         */
        virtual Double GetMaximumLogicTickDuration() const = 0;
        /**
         * @brief Check if the logic tick duration setting has changed.
         * @param inspector The change inspector.
         * @return true if the logic tick duration setting has changed.
         */
        virtual Bool HasLogicTickDurationChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Set the exact number of logic ticks per frame.
         * Set the per frame bounds to the same value, see SetBoundsForLogicTicksPerFrame().
         * @param numTicks The exact number of logic ticks per frame.
         */
        virtual void SetExactLogicTicksPerFrame(UInt32 numTicks) = 0;
        /**
         * @brief Set the number of logic ticks per frame bounds.
         * If the bounds have the same value, the SetBoundsForLogicTickDuration()
         * should be set to an appropriate range.
         *
         * The default value is (1, 1).
         * @param numTicksMin The minimum number of logic logic ticks per frame.
         * @param numTicksMax The maximum number of logic logic ticks per frame.
         */
        virtual void SetBoundsForLogicTicksPerFrame(UInt32 numTicksMin, UInt32 numTicksMax) = 0;
        /**
         * @brief Get minimum number of logic logic ticks per frame.
         * @return The minimum number of logic logic ticks per frame.
         */
        virtual UInt32 GetMinimumLogicTicksPerFrame() const = 0;
        /**
         * @brief Get maximum number of logic logic ticks per frame.
         * @return The maximum number of logic logic ticks per frame.
         */
        virtual UInt32 GetMaximumLogicTicksPerFrame() const = 0;
        /**
         * @brief Check if the number of logic logic ticks per frame setting has changed.
         * @param inspector The change inspector.
         * @return true if the number of logic logic ticks per frame has changed.
         */
        virtual Bool HasLogicTicksPerFrameChanged(ChangeInspector& inspector) const = 0;

        /**
         * @brief Add a user-defined system font.
         * This method can be used to define additional platform-specific system fonts used
         * in conjunction with a Graph::IFlatTextTexture.
         * If user-defined system fonts are required, this method must be called with different
         * values for the "fontName" parameter depending on the platform. In addition, some
         * platforms accept a "Bold" identifier as part of the font name, e.g. "Helvetica-Bold"
         * on iOS and OSX. In this case, the weight parameter is ignored.
         * On other platforms, it is required to specify the boldness of the font via the "weight"
         * parameter (usually 400 for regular thickness and 800 for bold fonts), and only specify
         * the font name without style.
         * @param fontId The unique font ID within the %Murl Engine.
         * @param fontName The font name, as expected by the operating system.
         * @param weight The font weight (default 400), if supported by the operating system.
         * @param sizeFactor The scale factor to apply (default 1.0).
         * @param ascent The font ascent, i.e. height above the base line. Ascent and descent
         *      should sum up to 1.0.
         * @param descent The font descent.
         * @param leading The font leading, i.e. additional space between consecutive text lines.
         */
        virtual void AddSystemFont(const String& fontId, const String& fontName, Real weight,
                                   Real sizeFactor, Real ascent, Real descent, Real leading) = 0;
        /**
         * @brief Get the number of user-defined system fonts.
         * @return The number of system fonts defined by the user.
         */
        virtual UInt32 GetNumberOfSystemFonts() const = 0;
        /**
         * @brief Get the internal ID of the user-defined system font at a given index.
         * @param index The index of the font, in the range from 0 to GetNumberOfSystemFonts()-1.
         * @return The font ID.
         */
        virtual const String& GetSystemFontId(UInt32 index) const = 0;
        /**
         * @brief Get the OS-specific name of the user-defined system font at a given index.
         * @param index The index of the font, in the range from 0 to GetNumberOfSystemFonts()-1.
         * @return The font name.
         */
        virtual const String& GetSystemFontName(UInt32 index) const = 0;
        /**
         * @brief Get the weight of the user-defined system font at a given index.
         * @param index The index of the font, in the range from 0 to GetNumberOfSystemFonts()-1.
         * @return The font weight.
         */
        virtual Real GetSystemFontWeight(UInt32 index) const = 0;
        /**
         * @brief Get the size factor of the user-defined system font at a given index.
         * @param index The index of the font, in the range from 0 to GetNumberOfSystemFonts()-1.
         * @return The size factor.
         */
        virtual Real GetSystemFontSizeFactor(UInt32 index) const = 0;
        /**
         * @brief Get the ascent of the user-defined system font at a given index.
         * @param index The index of the font, in the range from 0 to GetNumberOfSystemFonts()-1.
         * @return The font ascent.
         */
        virtual Real GetSystemFontAscent(UInt32 index) const = 0;
        /**
         * @brief Get the descent of the user-defined system font at a given index.
         * @param index The index of the font, in the range from 0 to GetNumberOfSystemFonts()-1.
         * @return The font descent.
         */
        virtual Real GetSystemFontDescent(UInt32 index) const = 0;
        /**
         * @brief Get the leading value of the user-defined system font at a given index.
         * @param index The index of the font, in the range from 0 to GetNumberOfSystemFonts()-1.
         * @return The font leading value.
         */
        virtual Real GetSystemFontLeading(UInt32 index) const = 0;

        /**
         * @brief Enable the virtual mouse device.
         * A virtual mouse is available on AppleTV Siri Remote device.
         * The default value is true on AppleTV, otherwise false.
         * @param isEnabled The enabled state.
         * @return true if successful.
         */
        virtual void SetVirtualMouseEnable(Bool isEnabled) = 0;
        /**
         * @brief Check if the virtual mouse device is enabled.
         * @return true if the virtual mouse device is enabled.
         */
        virtual Bool IsVirtualMouseEnabled() const = 0;

        /**
         * @brief Enable the virtual raw-mouse device.
         * A virtual raw-mouse is available on AppleTV Siri Remote device.
         * The default value is true on AppleTV, otherwise false.
         * @param isEnabled The enabled state.
         * @return true if successful.
         */
        virtual void SetVirtualRawMouseEnable(Bool isEnabled) = 0;
        /**
         * @brief Check if the virtual raw-mouse device is enabled.
         * @return true if the virtual raw-mouse device is enabled.
         */
        virtual Bool IsVirtualRawMouseEnabled() const = 0;

        /**
         * @brief Enable the cloud control.
         * The cloud control is available on iOS/OSX/tvOS.
         * The default value is false, if enabled an iCloud entitlement must
         * be setup for the application, @see CloudKit Framework Reference.
         * @param isEnabled The enabled state.
         * @return true if successful.
         */
        virtual void SetCloudControlEnable(Bool isEnabled) = 0;
        /**
         * @brief Check if the cloud control is enabled.
         * @return true if the cloud control is enabled.
         */
        virtual Bool IsCloudControlEnabled() const = 0;

        /**
         * @brief Define the action to perform on a specific graph node/controller parsing result.
         * This method allows to define the action to perform when a specific result occurred
         * during scene graph object (node or controller) parsing.
         * If the default action for the given code cannot be changed, this method returns false.
         * Actions can be defined for the following codes (with defaults after colon):
         * IEnums::RESULT_CODE_ATTRIBUTE_NUMBER_CONVERSION_ERROR     : IEnums::RESULT_ACTION_ABORT
         * IEnums::RESULT_CODE_ATTRIBUTE_ENUM_CONVERSION_ERROR       : IEnums::RESULT_ACTION_ABORT
         * IEnums::RESULT_CODE_ATTRIBUTE_UNKNOWN_ERROR               : IEnums::RESULT_ACTION_WARN
         * IEnums::RESULT_CODE_GRAPH_NODE_NOT_FOUND_ERROR            : IEnums::RESULT_ACTION_ABORT
         * IEnums::RESULT_CODE_GRAPH_NODE_WRONG_INTERFACE_ERROR      : IEnums::RESULT_ACTION_ABORT
         * IEnums::RESULT_CODE_RESOURCE_OBJECT_NOT_FOUND_ERROR       : IEnums::RESULT_ACTION_ABORT
         * IEnums::RESULT_CODE_RESOURCE_OBJECT_WRONG_INTERFACE_ERROR : IEnums::RESULT_ACTION_ABORT
         * @param code The result code for which to define the action.
         * @param action The action to perform.
         * @return true if successful.
         */
        virtual Bool SetGraphObjectResultAction(IEnums::ResultCode code, IEnums::ResultAction action) = 0;
        /**
         * @brief Get the action to perform on a specific graph node/controller parsing result.
         * If the default action for the given code cannot be changed, IEnums::RESULT_ACTION_UNDEFINED
         * is returned.
         * @param code The result code for which to query the action.
         * @return The action to perform.
         */
        virtual IEnums::ResultAction GetGraphObjectResultAction(IEnums::ResultCode code) const = 0;

        virtual void SetDefaultDepthBufferFormat(IEnums::DepthBufferFormat depthBufferFormat) = 0;
        virtual IEnums::DepthBufferFormat GetDefaultDepthBufferFormat() const = 0;
        virtual Bool HasDefaultDepthBufferFormatChanged(ChangeInspector& inspector) const = 0;

        virtual void SetDefaultRgbPixelFormat(IEnums::RgbPixelFormat pixelFormat) = 0;
        virtual IEnums::RgbPixelFormat GetDefaultRgbPixelFormat() const = 0;
        virtual Bool HasDefaultRgbPixelFormatChanged(ChangeInspector& inspector) const = 0;

        virtual void SetDefaultRgbaPixelFormat(IEnums::RgbaPixelFormat pixelFormat) = 0;
        virtual IEnums::RgbaPixelFormat GetDefaultRgbaPixelFormat() const = 0;
        virtual Bool HasDefaultRgbaPixelFormatChanged(ChangeInspector& inspector) const = 0;

        virtual IEnums::PixelFormat GetDefaultResourcePixelFormat(Bool useAlpha) const = 0;

    protected:
        virtual ~IEngineConfiguration() {}
    };
}

#endif  // __MURL_I_ENGINE_CONFIGURATION_H__

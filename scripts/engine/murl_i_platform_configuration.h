// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_I_PLATFORM_CONFIGURATION_H__
#define __MURL_I_PLATFORM_CONFIGURATION_H__

#include "murl_i_enums.h"

namespace Murl
{
    class IEngineConfiguration;
    class IAppConfiguration;

    /**
     * @ingroup MurlConfigurationInterfaces
     * @interface IPlatformConfiguration
     * @brief The platform configuration interface defines the immutable
     *  platform-specific settings.
     */
    class IPlatformConfiguration
    {
    public:
        /**
         * @brief Get the const engine configuration object.
         * @return The engine configuration object.
         */
        virtual const IEngineConfiguration* GetEngineConfiguration() const = 0;
        /**
         * @brief Get the const application configuration object.
         * @return The application configuration object.
         */
        virtual const IAppConfiguration* GetAppConfiguration() const = 0;

        /**
         * @brief Get the engine configuration object.
         * @return The engine configuration object.
         */
        virtual IEngineConfiguration* GetEngineConfiguration() = 0;
        /**
         * @brief Get the application configuration object.
         * @return The application configuration object.
         */
        virtual IAppConfiguration* GetAppConfiguration() = 0;

        /**
         * @brief Set the application's launch arguments, if existing.
         * When supported by the specific platform, the first argument in the list
         * represents the path and file name to the application executable itself,
         * followed by individual optional strings for each argument given at
         * launch.
         * @param arguments A string array containing all launch arguments.
         */
        virtual void SetLaunchArguments(const StringArray& arguments) = 0;
        /**
         * @brief Get the application's launch arguments.
         * On platforms that do not support launch arguments, this simply returns
         * an empty array.
         * @return A constant string array containing all launch arguments.
         */
        virtual const StringArray& GetLaunchArguments() const = 0;

        /**
         * @brief Set the unique device identifier string.
         * Removes all '-' characters from the identifier string.
         * @param id The unique device identifier string.
         */
        virtual void SetUniqueDeviceId(const String& id) = 0;
        /**
         * @brief Get the unique device identifier string.
         * On multiuser platforms each user gets an own unique identifier.
         * @return The unique device identifier string or
         *  32 x '0' characters if not set by the platform implementation.
         */
        virtual const String& GetUniqueDeviceId() const = 0;

        /**
         * @brief Set the unique install identifier string.
         * Removes all '-' characters from the identifier string.
         * @param id The unique install identifier string.
         */
        virtual void SetUniqueInstallId(const String& id) = 0;
        /**
         * @brief Get the unique install identifier string.
         * On multiuser platforms each user gets an own unique identifier.
         * @return The unique install identifier string or
         *  32 x '0' characters if not set by the platform implementation.
         */
        virtual const String& GetUniqueInstallId() const = 0;

        /**
         * @brief Set the country code string.
         * @param code The country code string.
         */
        virtual void SetCountryCode(const String& code) = 0;
        /**
         * @brief Get the country code string.
         * The country code string is provided in the ISO 3166-1-alpha-2 code.
         * @return The country code string or
         *  "??" if not set by the platform implementation.
         */
        virtual const String& GetCountryCode() const = 0;

        /**
         * @brief Set the manufacturer name.
         * @param name The manufacturer name.
         */
        virtual void SetTargetManufacturerName(const String& name) = 0;
        /**
         * @brief Get the manufacturer name.
         * @return The manufacturer name or
         *  "N/A" if not set by the platform implementation.
         */
        virtual const String& GetTargetManufacturerName() const = 0;

        /**
         * @brief Set the target device name.
         * @param name The target device name.
         */
        virtual void SetTargetDeviceName(const String& name) = 0;
        /**
         * @brief Get the target device name.
         * @return THe target device name or
         *  "N/A" if not set by the platform implementation.
         */
        virtual const String& GetTargetDeviceName() const = 0;

        /**
         * @brief Set the target model name.
         * @param name The target model name.
         */
        virtual void SetTargetModelName(const String& name) = 0;
        /**
         * @brief Get the target model name.
         * @return The target model name or
         *  "N/A" if not set by the platform implementation.
         */
        virtual const String& GetTargetModelName() const = 0;

        /**
         * @brief Set the target product name.
         * @param name The target product name.
         */
        virtual void SetTargetProductName(const String& name) = 0;
        /**
         * @brief Get the target product name.
         * @return The target product name or
         *  "N/A" if not set by the platform implementation.
         */
        virtual const String& GetTargetProductName() const = 0;

        /**
         * @brief Set the system version name.
         * @param name The system version name.
         */
        virtual void SetSystemVersionName(const String& name) = 0;
        /**
         * @brief Get the system version name.
         * @return The system version name or
         *  "N/A" if not set by the platform implementation.
         */
        virtual const String& GetSystemVersionName() const = 0;

        /**
         * @brief Set the target class enumeration value.
         * @param targetClass The target class enumeration value.
         */
        virtual void SetTargetClass(IEnums::TargetClass targetClass) = 0;
        /**
         * @brief Get the target class enumeration value.
         * @return The target class enumeration value or
         *  IEnums::TARGET_CLASS_DEFAULT if not set by the platform implementation.
         */
        virtual IEnums::TargetClass GetTargetClass() const = 0;
        /**
         * @brief Check if the target class is matching a specified value.
         * @param targetClass The target class enumeration value.
         * @return true if the target class is matching the parameter value.
         */
        virtual Bool IsTargetClassMatching(IEnums::TargetClass targetClass) const = 0;

        /**
         * @brief Set the target device enumeration value.
         * @param targetDevice The target device enumeration value.
         */
        virtual void SetTargetDevice(IEnums::TargetDevice targetDevice) = 0;
        /**
         * @brief Get the target device enumeration value.
         * @return The target device enumeration value or
         *  IEnums::TARGET_DEVICE_DEFAULT if not set by the platform implementation.
         */
        virtual IEnums::TargetDevice GetTargetDevice() const = 0;
        /**
         * @brief Check if the target device is matching a specified value.
         * @param targetDevice The target device enumeration value.
         * @return true if the target device is matching the parameter value.
         */
        virtual Bool IsTargetDeviceMatching(IEnums::TargetDevice targetDevice) const = 0;

        /**
         * @brief Set the target host enumeration value.
         * @param targetHost The target host enumeration value.
         */
        virtual void SetTargetHost(IEnums::TargetHost targetHost) = 0;
        /**
         * @brief Get the target host enumeration value.
         * @return The target host enumeration value or
         *  IEnums::TARGET_HOST_DEFAULT if not set by the platform implementation.
         */
        virtual IEnums::TargetHost GetTargetHost() const = 0;
        /**
         * @brief Check if the target host is matching a specified value.
         * @param targetHost The target host enumeration value.
         * @return true if the target host is matching the parameter value.
         */
        virtual Bool IsTargetHostMatching(IEnums::TargetHost targetHost) const = 0;

        /**
         * @brief Set the operating system enumeration value.
         * @param operatingSystem The operating system enumeration value.
         */
        virtual void SetOperatingSystem(IEnums::OperatingSystem operatingSystem) = 0;
        /**
         * @brief Get the operating system enumeration value.
         * @return The operating system enumeration value or
         *  IEnums::OPERATING_SYSTEM_DEFAULT if not set by the platform implementation.
         */
        virtual IEnums::OperatingSystem GetOperatingSystem() const = 0;
        /**
         * @brief Check if the operating system is matching a specified value.
         * @param operatingSystem The operating system enumeration value.
         * @return true if the operating system is matching the parameter value.
         */
        virtual Bool IsOperatingSystemMatching(IEnums::OperatingSystem operatingSystem) const = 0;

        /**
         * @brief Set the graphics processing unit enumeration value.
         * @param gpu The graphics processing unit enumeration value.
         */
        virtual void SetGpu(IEnums::Gpu gpu) = 0;
        /**
         * @brief Get the graphics processing unit enumeration value.
         * @return The graphics processing unit enumeration value or
         *  IEnums::GPU_DEFAULT if not set by the platform implementation.
         */
        virtual IEnums::Gpu GetGpu() const = 0;
        /**
         * @brief Check if the graphics processing unit is matching a specified value.
         * @param gpu The graphics processing unit enumeration value.
         * @return true if the graphics processing unit is matching the parameter value.
         */
        virtual Bool IsGpuMatching(IEnums::Gpu gpu) const = 0;

        /**
         * @brief Set the back buffer's bit depths for a single color value.
         * @param numRedBits The number of bits for the red component.
         * @param numGreenBits The number of bits for the green component.
         * @param numBlueBits The number of bits for the blue component.
         * @param numAlphaBits The number of bits for the alpha component.
         */
        virtual void SetNumberOfBackBufferColorBits(UInt32 numRedBits, UInt32 numGreenBits, UInt32 numBlueBits, UInt32 numAlphaBits) = 0;
        /**
         * @brief Get the back buffer's bit depth for the red component.
         * @return The bit depth.
         */
        virtual UInt32 GetNumberOfBackBufferRedBits() const = 0;
        /**
         * @brief Get the back buffer's bit depth for the green component.
         * @return The bit depth.
         */
        virtual UInt32 GetNumberOfBackBufferGreenBits() const = 0;
        /**
         * @brief Get the back buffer's bit depth for the blue component.
         * @return The bit depth.
         */
        virtual UInt32 GetNumberOfBackBufferBlueBits() const = 0;
        /**
         * @brief Get the back buffer's bit depth for the alpha component.
         * @return The bit depth.
         */
        virtual UInt32 GetNumberOfBackBufferAlphaBits() const = 0;

        /**
         * @brief Set the back buffer's depth buffer bit depth.
         * @param numDepthBits The number of bits for a single depth buffer fragment.
         */
        virtual void SetNumberOfBackBufferDepthBits(UInt32 numDepthBits) = 0;
        /**
         * @brief Get the back buffer's depth buffer bit depth.
         * @return The number of bits for a single depth buffer fragment.
         */
        virtual UInt32 GetNumberOfBackBufferDepthBits() const = 0;

        /**
         * @brief Set the back buffer's stencil buffer bit depth.
         * @param numStencilBits The number of bits for a single stencil buffer fragment.
         */
        virtual void SetNumberOfBackBufferStencilBits(UInt32 numStencilBits) = 0;
        /**
         * @brief Get the back buffer's stencil buffer bit depth.
         * @return The number of bits for a single stencil buffer fragment.
         */
        virtual UInt32 GetNumberOfBackBufferStencilBits() const = 0;

        /**
         * @brief Set the physical screen size.
         * @param mmSizeX The screen width in millimeters.
         * @param mmSizeY The screen height in millimeters.
         */
        virtual void SetPhysicalScreenSize(Real mmSizeX, Real mmSizeY) = 0;
        /**
         * @brief Get the physical screen width.
         * @return The physical screen width in millimeters or
         *  (1680 pixels x (25.4 mm / 96 dpi)) if not set by the platform implementation.
         */
        virtual Real GetPhysicalScreenSizeX() const = 0;
        /**
         * @brief Get the physical screen height.
         * @return The physical screen height in millimeters or
         *  (1050 pixels x (25.4 mm / 96 dpi)) if not set by the platform implementation.
         */
        virtual Real GetPhysicalScreenSizeY() const = 0;

        /**
         * @brief Set the physical pixel size.
         * @param mmSizeX The pixel width in millimeters.
         * @param mmSizeY The pixel height in millimeters.
         */
        virtual void SetPhysicalPixelSize(Real mmSizeX, Real mmSizeY) = 0;
        /**
         * @brief Get the physical pixel width.
         * @return The physical pixel width in millimeters or
         *  (25.4 mm / 96 dpi) if not set by the platform implementation.
         */
        virtual Real GetPhysicalPixelSizeX() const = 0;
        /**
         * @brief Get the physical pixel height.
         * @return The physical pixel height in millimeters or
         *  (25.4 mm / 96 dpi) if not set by the platform implementation.
         */
        virtual Real GetPhysicalPixelSizeY() const = 0;

        /**
         * @brief Set the pixel scale factor.
         * @param sizeXFactor The pixel width scale factor.
         * @param sizeYFactor The pixel height scale factor.
         */
        virtual void SetPixelScaleFactor(Real sizeXFactor, Real sizeYFactor) = 0;
        /**
         * @brief Set the pixel width scale factor.
         * @return The pixel width scale factor or
         *  1.0 if not set by the platform implementation.
         */
        virtual Real GetPixelScaleFactorX() const = 0;
        /**
         * @brief Set the pixel height scale factor.
         * @return The pixel height scale factor or
         *  1.0 if not set by the platform implementation.
         */
        virtual Real GetPixelScaleFactorY() const = 0;

        /**
         * @brief Get the number of pixels from a specified width and unit.
         * @param sizeValue The width value.
         * @param unit The unit enumeration value.
         * @return The number of pixels from the specified width and unit or
         *  zero if the unit is IEnums::LENGTH_MEASURE_VIRTUAL or unknown.
         */
        virtual Real GetNumberOfPixelsFromSizeX(Real sizeValue, IEnums::LengthMeasure unit) const = 0;
        /**
         * @brief Get the number of pixels from a specified height and unit.
         * @param sizeValue The height value.
         * @param unit The unit enumeration value.
         * @return The number of pixels from the specified height and unit or
         *  zero if the unit is IEnums::LENGTH_MEASURE_VIRTUAL or unknown.
         */
        virtual Real GetNumberOfPixelsFromSizeY(Real sizeValue, IEnums::LengthMeasure unit) const = 0;

        /**
         * @brief Get the width in a specified unit from a specified number of pixels.
         * @param numberOfPixels The number of pixels value.
         * @param unit The unit enumeration value.
         * @return The width in the specified unit or
         *  zero if the unit is IEnums::LENGTH_MEASURE_VIRTUAL or unknown.
         */
        virtual Real GetSizeXFromNumberOfPixels(Real numberOfPixels, IEnums::LengthMeasure unit) const = 0;
        /**
         * @brief Get the height in a specified unit from a specified number of pixels.
         * @param numberOfPixels The number of pixels value.
         * @param unit The unit enumeration value.
         * @return The height in the specified unit or
         *  zero if the unit is IEnums::LENGTH_MEASURE_VIRTUAL or unknown.
         */
        virtual Real GetSizeYFromNumberOfPixels(Real numberOfPixels, IEnums::LengthMeasure unit) const = 0;

        /**
         * @brief Set the name of the In-App Billing provider.
         * @param name The IAB provider name.
         */
        virtual void SetInAppBillingProviderName(const String& name) = 0;
        /**
         * @brief Get the In-App Billing provider name.
         * - "N/A" if the provider name has not been set
         * - "none" if In-App Billing is not supported
         * - "apple-ios" for Apple iOS In-App Purchasing
         * - "apple-osx" for Apple OSX In-App Purchasing
         * - "google" for Google Play In-App Billing
         * - "amazon" for Amazon In-App Purchasing
         * - "samsung" for Samsung In-App Purchasing
         * - "ouya" for OUYA In-App Purchasing
         * @return The In-App Billing provider name or
         *  "N/A" if not set by the platform implementation.
         */
        virtual const String& GetInAppBillingProviderName() const = 0;

        /**
         * @brief Enable/disable multithreading support.
         * @param supported If true, multithreading is supported.
         */
        virtual void SetMultithreadingSupported(Bool supported) = 0;
        /**
         * @brief Check if multithreading is supported.
         * @return true if supported
         */
        virtual Bool IsMultithreadingSupported() const = 0;

    protected:
        virtual ~IPlatformConfiguration() {}
    };
}

#endif  // __MURL_I_PLATFORM_CONFIGURATION_H__

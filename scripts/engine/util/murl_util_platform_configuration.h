// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_PLATFORM_CONFIGURATION_H__
#define __MURL_UTIL_PLATFORM_CONFIGURATION_H__

#include "murl_i_platform_configuration.h"
#include "murl_string.h"

namespace Murl
{
    namespace Util
    {
        class PlatformConfiguration : public IPlatformConfiguration
        {
        public:
            PlatformConfiguration();
            virtual ~PlatformConfiguration();
            
            virtual Bool Init(IEngineConfiguration* engineConfig, IAppConfiguration* appConfig);
            
            virtual const IEngineConfiguration* GetEngineConfiguration() const;
            virtual const IAppConfiguration* GetAppConfiguration() const;
            
            virtual IEngineConfiguration* GetEngineConfiguration();
            virtual IAppConfiguration* GetAppConfiguration();

            virtual void SetLaunchArguments(const StringArray& arguments);
            virtual const StringArray& GetLaunchArguments() const;

            virtual void SetUniqueDeviceId(const String& id);
            virtual const String& GetUniqueDeviceId() const;
            
            virtual void SetUniqueInstallId(const String& id);
            virtual const String& GetUniqueInstallId() const;
            
            virtual void SetCountryCode(const String& code);
            virtual const String& GetCountryCode() const;
            
            virtual void SetTargetManufacturerName(const String& name);
            virtual const String& GetTargetManufacturerName() const;
            
            virtual void SetTargetDeviceName(const String& name);
            virtual const String& GetTargetDeviceName() const;
            
            virtual void SetTargetModelName(const String& name);
            virtual const String& GetTargetModelName() const;
            
            virtual void SetTargetProductName(const String& name);
            virtual const String& GetTargetProductName() const;
            
            virtual void SetSystemVersionName(const String& name);
            virtual const String& GetSystemVersionName() const;
            
            virtual void SetTargetClass(IEnums::TargetClass targetClass);
            virtual IEnums::TargetClass GetTargetClass() const;
            virtual Bool IsTargetClassMatching(IEnums::TargetClass targetClass) const;
            
            virtual void SetTargetDevice(IEnums::TargetDevice targetDevice);
            virtual IEnums::TargetDevice GetTargetDevice() const;
            virtual Bool IsTargetDeviceMatching(IEnums::TargetDevice targetDevice) const;
            
            virtual void SetTargetHost(IEnums::TargetHost targetHost);
            virtual IEnums::TargetHost GetTargetHost() const;
            virtual Bool IsTargetHostMatching(IEnums::TargetHost targetHost) const;

            virtual void SetOperatingSystem(IEnums::OperatingSystem operatingSystem);
            virtual IEnums::OperatingSystem GetOperatingSystem() const;
            virtual Bool IsOperatingSystemMatching(IEnums::OperatingSystem operatingSystem) const;
            
            virtual void SetGpu(IEnums::Gpu gpu);
            virtual IEnums::Gpu GetGpu() const;
            virtual Bool IsGpuMatching(IEnums::Gpu gpu) const;

            virtual void SetNumberOfBackBufferColorBits(UInt32 numRedBits, UInt32 numGreenBits, UInt32 numBlueBits, UInt32 numAlphaBits);
            virtual UInt32 GetNumberOfBackBufferRedBits() const;
            virtual UInt32 GetNumberOfBackBufferGreenBits() const;
            virtual UInt32 GetNumberOfBackBufferBlueBits() const;
            virtual UInt32 GetNumberOfBackBufferAlphaBits() const;

            virtual void SetNumberOfBackBufferDepthBits(UInt32 numDepthBits);
            virtual UInt32 GetNumberOfBackBufferDepthBits() const;

            virtual void SetNumberOfBackBufferStencilBits(UInt32 numStencilBits);
            virtual UInt32 GetNumberOfBackBufferStencilBits() const;

            virtual void SetPhysicalScreenSize(Real mmSizeX, Real mmSizeY);
            virtual Real GetPhysicalScreenSizeX() const;
            virtual Real GetPhysicalScreenSizeY() const;
            
            virtual void SetPhysicalPixelSize(Real mmSizeX, Real mmSizeY);
            virtual Real GetPhysicalPixelSizeX() const;
            virtual Real GetPhysicalPixelSizeY() const;
            
            virtual void SetPixelScaleFactor(Real sizeXFactor, Real sizeYFactor);
            virtual Real GetPixelScaleFactorX() const;
            virtual Real GetPixelScaleFactorY() const;
            
            virtual Real GetNumberOfPixelsFromSizeX(Real sizeValue, IEnums::LengthMeasure unit) const;
            virtual Real GetNumberOfPixelsFromSizeY(Real sizeValue, IEnums::LengthMeasure unit) const;
            virtual Real GetSizeXFromNumberOfPixels(Real numberOfPixels, IEnums::LengthMeasure unit) const;
            virtual Real GetSizeYFromNumberOfPixels(Real numberOfPixels, IEnums::LengthMeasure unit) const;
            
            virtual void SetInAppBillingProviderName(const String& name);
            virtual const String& GetInAppBillingProviderName() const;

            virtual void SetMultithreadingSupported(Bool supported);
            virtual Bool IsMultithreadingSupported() const;

        protected:
            class Size
            {
            public:
                Size(Real sizeX, Real sizeY)
                : mSizeX(sizeX)
                , mSizeY(sizeY)
                {
                }
                
                bool operator==(const Size& rhs) const
                {
                    return ((mSizeX == rhs.mSizeX) && (mSizeY == rhs.mSizeY));
                }
                
                Real mSizeX;
                Real mSizeY;
            };
            
            Real GetNumberOfPixelsFromSize(Real sizeValue, IEnums::LengthMeasure unit, Real unitSize) const;
            Real GetSizeFromNumberOfPixels(Real numberOfPixels, IEnums::LengthMeasure unit, Real unitSize) const;
            
            IEngineConfiguration* mEngineConfig;
            IAppConfiguration* mAppConfig;

            StringArray mLaunchArguments;

            String mUniqueDeviceId;
            String mUniqueInstallId;
            String mCountryCode;
            
            String mTargetManufacturerName;
            String mTargetDeviceName;
            String mTargetModelName;
            String mTargetProductName;
            String mSystemVersionName;
            
            IEnums::TargetClass mTargetClass;
            IEnums::TargetDevice mTargetDevice;
            IEnums::TargetHost mTargetHost;
            IEnums::OperatingSystem mOperatingSystem;
            IEnums::Gpu mGpu;

            UInt32 mBackBufferRedBits;
            UInt32 mBackBufferGreenBits;
            UInt32 mBackBufferBlueBits;
            UInt32 mBackBufferAlphaBits;
            UInt32 mBackBufferDepthBits;
            UInt32 mBackBufferStencilBits;

            Size mPhysicalScreenSize;
            Size mPhysicalPixelSize;
            Size mPixelScaleFactor;
            
            String mIabProviderName;

            Bool mIsMultithreadingSupported;
        };
    }
}

#endif  // __MURL_UTIL_PLATFORM_CONFIGURATION_H__

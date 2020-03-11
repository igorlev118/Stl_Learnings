// Copyright 2010-2015 Spraylight

#ifndef __MURL_UTIL_ENGINE_CONFIGURATION_H__
#define __MURL_UTIL_ENGINE_CONFIGURATION_H__

#include "murl_i_engine_configuration.h"
#include "murl_util_attributes.h"
#include "murl_util_feature_set.h"

namespace Murl
{
    namespace Util
    {
        class EngineConfiguration : public IEngineConfiguration
        {
        public:
            EngineConfiguration();
            virtual ~EngineConfiguration();

            virtual Bool Init(const IPlatformConfiguration* platformConfig, IAppConfiguration* appConfig);

            virtual const IPlatformConfiguration* GetPlatformConfiguration() const;
            virtual const IAppConfiguration* GetAppConfiguration() const;

            virtual IAppConfiguration* GetAppConfiguration();

            virtual Bool HasChanged(ChangeInspector& inspector) const;

            virtual IAttributes* GetDefaultGraphParameters();
            virtual const IAttributes* GetDefaultGraphParameters() const;

            virtual IFeatureSet* GetFeatures();
            virtual const IFeatureSet* GetFeatures() const;

            virtual UInt32 GetMajorRevision() const;
            virtual UInt32 GetMinorRevision() const;
            virtual UInt32 GetBuildNumber() const;
            virtual const String& GetReleaseState() const;
            virtual const String& GetVersionString() const;
            virtual const String& GetCopyrightString() const;

            virtual void SetLicenseKey(const UInt8* key);
            virtual const ConstData& GetLicenseKey() const;

            virtual void SetLogFileName(const String& logFileName);
            virtual const String& GetLogFileName() const;
            virtual void SetLogFileFullPath(const String& logFilePath);
            virtual const String& GetLogFileFullPath() const;

            virtual void SetRunLoopMode(IEnums::RunLoopMode runLoopMode);
            virtual IEnums::RunLoopMode GetRunLoopMode() const;

            virtual void SetBootTime(const System::Time& time);
            virtual const System::Time& GetBootTime() const;
            virtual Bool HasBootTimeChanged(ChangeInspector& inspector) const;

            virtual void SetProductName(const String& productName);
            virtual const String& GetProductName() const;
            virtual Bool HasProductNameChanged(ChangeInspector& inspector) const;

            virtual void SetVersionName(const String& versionName);
            virtual const String& GetVersionName() const;
            virtual Bool HasVersionNameChanged(ChangeInspector& inspector) const;

            virtual void SetAudioSessionCategory(IEnums::AudioSessionCategory sessionCategory);
            virtual IEnums::AudioSessionCategory GetAudioSessionCategory() const;
            virtual Bool HasAudioSessionCategoryChanged(ChangeInspector& inspector) const;

            virtual void SetVideoApi(IEnums::VideoApi videoApi);
            virtual IEnums::VideoApi GetVideoApi() const;
            virtual Bool IsVideoApiMatching(IEnums::VideoApi videoApi) const;
            virtual Bool HasVideoApiChanged(ChangeInspector& inspector) const;

            virtual void SetAudioApi(IEnums::AudioApi audioApi);
            virtual IEnums::AudioApi GetAudioApi() const;
            virtual Bool IsAudioApiMatching(IEnums::AudioApi audioApi) const;
            virtual Bool HasAudioApiChanged(ChangeInspector& inspector) const;

            virtual void SetVideoRendererClassName(const String& className);
            virtual const String& GetVideoRendererClassName() const;
            virtual Bool HasVideoRendererClassNameChanged(ChangeInspector& inspector) const;

            virtual void SetAudioRendererClassName(const String& className);
            virtual const String& GetAudioRendererClassName() const;
            virtual Bool HasAudioRendererClassNameChanged(ChangeInspector& inspector) const;

            virtual void SetPhysicsSimulatorClassName(const String& className);
            virtual const String& GetPhysicsSimulatorClassName() const;
            virtual Bool HasPhysicsSimulatorClassNameChanged(ChangeInspector& inspector) const;

            virtual void SetResourceCollectionClassName(const String& className);
            virtual const String& GetResourceCollectionClassName() const;
            virtual Bool HasResourceCollectionClassNameChanged(ChangeInspector& inspector) const;

            virtual void SetPreferredResourcePackageType(IEnums::PackageType type);
            virtual IEnums::PackageType GetPreferredResourcePackageType() const;
            virtual Bool HasPreferredResourcePackageTypeChanged(ChangeInspector& inspector) const;

            virtual void SetResourceFileCategory(IEnums::FileCategory category);
            virtual IEnums::FileCategory GetResourceFileCategory() const;
            virtual Bool HasResourceFileCategoryChanged(ChangeInspector& inspector) const;

            virtual void SetDeactivatedAppRunState(IEnums::AppRunState appRunState);
            virtual IEnums::AppRunState GetDeactivatedAppRunState() const;
            virtual Bool HasDeactivatedAppRunStateChanged(ChangeInspector& inspector) const;

            virtual void SetSuspendUnloadsResources(Bool unload);
            virtual Bool GetSuspendUnloadsResources() const;
            virtual Bool HasSuspendUnloadsResourcesChanged(ChangeInspector& inspector) const;

            virtual void SetSuspendableResources(IEnums::SuspendableResources suspendableResources);
            virtual IEnums::SuspendableResources GetSuspendableResources() const;
            virtual Bool HasSuspendableResourcesChanged(ChangeInspector& inspector) const;

            virtual void SetUnitSize(Real sizeX, Real sizeY);
            virtual Real GetUnitSizeX() const;
            virtual Real GetUnitSizeY() const;
            virtual Bool HasUnitSizeChanged(ChangeInspector& inspector) const;

            virtual void SetPixelCenter(Real centerX, Real centerY);
            virtual Real GetPixelCenterX() const;
            virtual Real GetPixelCenterY() const;
            virtual Bool HasPixelCenterChanged(ChangeInspector& inspector) const;

            virtual void SetSyncLoadingTimeout(Double timeout);
            virtual Double GetSyncLoadingTimeout() const;
            virtual Bool HasSyncLoadingTimeoutChanged(ChangeInspector& inspector) const;

            virtual void SetAsyncLoadingEnabled(Bool enabled);
            virtual Bool IsAsyncLoadingEnabled() const;
            virtual Bool HasAsyncLoadingEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetSyncToVBlankEnabled(Bool enabled);
            virtual Bool IsSyncToVBlankEnabled() const;
            virtual Bool HasSyncToVBlankEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetVideoApiChecksEnabled(Bool enabled);
            virtual Bool AreVideoApiChecksEnabled() const;
            virtual Bool HasVideoApiChecksEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetAudioApiChecksEnabled(Bool enabled);
            virtual Bool AreAudioApiChecksEnabled() const;
            virtual Bool HasAudioApiChecksEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetNumberOfAntialiasSamples(UInt32 numSamples);
            virtual UInt32 GetNumberOfAntialiasSamples() const;
            virtual Bool HasNumberOfAntialiasSamplesChanged(ChangeInspector& inspector) const;

            virtual void SetDefaultMaxTextureAnisotropy(Real maxAnisotropy);
            virtual Real GetDefaultMaxTextureAnisotropy() const;
            virtual Bool HasDefaultMaxTextureAnisotropyChanged(ChangeInspector& inspector) const;

            virtual void SetTexturePrescaleDivisor(UInt32 divisor);
            virtual UInt32 GetTexturePrescaleDivisor() const;
            virtual Bool IsTexturePrescaleDivisorMatching(UInt32 divisor) const;
            virtual Bool HasTexturePrescaleDivisorChanged(ChangeInspector& inspector) const;

            virtual void SetExactLogicTickDuration(Double dt);
            virtual void SetBoundsForLogicTickDuration(Double dtMin, Double dtMax);
            virtual Double GetMinimumLogicTickDuration() const;
            virtual Double GetMaximumLogicTickDuration() const;
            virtual Bool HasLogicTickDurationChanged(ChangeInspector& inspector) const;

            virtual void SetExactLogicTicksPerFrame(UInt32 numTicks);
            virtual void SetBoundsForLogicTicksPerFrame(UInt32 numTicksMin, UInt32 numTicksMax);
            virtual UInt32 GetMinimumLogicTicksPerFrame() const;
            virtual UInt32 GetMaximumLogicTicksPerFrame() const;
            virtual Bool HasLogicTicksPerFrameChanged(ChangeInspector& inspector) const;

            virtual void AddSystemFont(const String& fontId, const String& fontName, Real weight,
                                       Real sizeFactor, Real ascent, Real descent, Real leading);
            virtual UInt32 GetNumberOfSystemFonts() const;
            virtual const String& GetSystemFontId(UInt32 index) const;
            virtual const String& GetSystemFontName(UInt32 index) const;
            virtual Real GetSystemFontWeight(UInt32 index) const;
            virtual Real GetSystemFontSizeFactor(UInt32 index) const;
            virtual Real GetSystemFontAscent(UInt32 index) const;
            virtual Real GetSystemFontDescent(UInt32 index) const;
            virtual Real GetSystemFontLeading(UInt32 index) const;

            virtual void SetDefaultDepthBufferFormat(IEnums::DepthBufferFormat depthBufferFormat);
            virtual IEnums::DepthBufferFormat GetDefaultDepthBufferFormat() const;
            virtual Bool HasDefaultDepthBufferFormatChanged(ChangeInspector& inspector) const;

            virtual void SetDefaultRgbPixelFormat(IEnums::RgbPixelFormat pixelFormat);
            virtual IEnums::RgbPixelFormat GetDefaultRgbPixelFormat() const;
            virtual Bool HasDefaultRgbPixelFormatChanged(ChangeInspector& inspector) const;

            virtual void SetDefaultRgbaPixelFormat(IEnums::RgbaPixelFormat pixelFormat);
            virtual IEnums::RgbaPixelFormat GetDefaultRgbaPixelFormat() const;
            virtual Bool HasDefaultRgbaPixelFormatChanged(ChangeInspector& inspector) const;

            virtual IEnums::PixelFormat GetDefaultResourcePixelFormat(Bool useAlpha) const;

            virtual void SetVirtualMouseEnable(Bool isEnabled);
            virtual Bool IsVirtualMouseEnabled() const;

            virtual void SetVirtualRawMouseEnable(Bool isEnabled);
            virtual Bool IsVirtualRawMouseEnabled() const;

            virtual void SetCloudControlEnable(Bool isEnabled);
            virtual Bool IsCloudControlEnabled() const;

            virtual Bool SetGraphObjectResultAction(IEnums::ResultCode code, IEnums::ResultAction action);
            virtual IEnums::ResultAction GetGraphObjectResultAction(IEnums::ResultCode code) const;

        protected:
            struct UnitSize
            {
                UnitSize(Real sizeX, Real sizeY)
                : mSizeX(sizeX)
                , mSizeY(sizeY)
                {
                }

                bool operator==(const UnitSize& other) const
                {
                    return ((mSizeX == other.mSizeX) && (mSizeY == other.mSizeY));
                }

                Real mSizeX;
                Real mSizeY;
            };

            struct PixelCenter
            {
                PixelCenter(Real centerX, Real centerY)
                : mCenterX(centerX)
                , mCenterY(centerY)
                {
                }

                bool operator==(const PixelCenter& other) const
                {
                    return ((mCenterX == other.mCenterX) && (mCenterY == other.mCenterY));
                }

                Real mCenterX;
                Real mCenterY;
            };

            struct LogicTickDuration
            {
                LogicTickDuration(Double min, Double max)
                : mMin(min)
                , mMax(max)
                {
                }

                bool operator==(const LogicTickDuration& other) const
                {
                    return ((mMin == other.mMin) && (mMax == other.mMax));
                }

                Double mMin;
                Double mMax;
            };

            struct LogicTicksPerFrame
            {
                LogicTicksPerFrame(UInt32 min, UInt32 max)
                : mMin(min)
                , mMax(max)
                {
                }

                bool operator==(const LogicTicksPerFrame& other) const
                {
                    return ((mMin == other.mMin) && (mMax == other.mMax));
                }

                UInt32 mMin;
                UInt32 mMax;
            };

            struct SystemFont
            {
                SystemFont()
                : mWeight(Real(400.0))
                , mSizeFactor(Real(1.0))
                , mAscent(Real(0.7625))
                , mDescent(Real(0.2375))
                , mLeading(Real(0.0))
                {
                }

                String mId;
                String mName;
                Real mWeight;
                Real mSizeFactor;
                Real mAscent;
                Real mDescent;
                Real mLeading;
            };

            template<class DataType>
            void SetItemValue(ChangeController<DataType>& item, const DataType& value)
            {
                if (item.SetValue(value))
                {
                    mHasChanged.SetChanged();
                }
            }

            const IPlatformConfiguration* mPlatformConfig;
            IAppConfiguration* mAppConfig;

            Attributes mDefaultGraphParameters;
            FeatureSet mFeatureSet;

            Data mLicenseKey;

            BoolChangeController mHasChanged;

            StringChangeController mLogFileName;
            StringChangeController mLogFileFullPath;

            ChangeController<IEnums::RunLoopMode> mRunLoopMode;

            ChangeController<System::Time> mBootTime;

            StringChangeController mProductName;
            StringChangeController mVersionName;

            ChangeController<IEnums::AudioSessionCategory> mAudioSessionCategory;

            ChangeController<IEnums::VideoApi> mVideoApi;
            ChangeController<IEnums::AudioApi> mAudioApi;

            StringChangeController mVideoRendererClassName;
            StringChangeController mAudioRendererClassName;
            StringChangeController mPhysicsSimulatorClassName;
            StringChangeController mResourceCollectionClassName;

            ChangeController<IEnums::PackageType> mResourcePackageType;
            ChangeController<IEnums::FileCategory> mResourceFileCategory;

            ChangeController<IEnums::AppRunState> mDeactivatedAppRunState;
            BoolChangeController mSuspendUnloadsResources;
            ChangeController<IEnums::SuspendableResources> mSuspendableResources;

            ChangeController<UnitSize> mUnitSize;
            ChangeController<PixelCenter> mPixelCenter;

            ChangeController<Double> mSyncLoadingTimeout;

            BoolChangeController mAsyncLoadingEnabled;
            BoolChangeController mSyncToVBlankEnabled;
            BoolChangeController mVideoApiChecksEnabled;
            BoolChangeController mAudioApiChecksEnabled;

            ChangeController<UInt32> mNumberOfAntialiasSamples;
            ChangeController<Real> mDefaultMaxTextureAnisotropy;

            ChangeController<UInt32> mTexturePrescaleDivisor;

            ChangeController<LogicTickDuration> mLogicTickDuration;
            ChangeController<LogicTicksPerFrame> mLogicTicksPerFrame;

            ChangeController<IEnums::DepthBufferFormat> mDefaultDepthBufferFormat;
            ChangeController<IEnums::RgbPixelFormat> mDefaultRgbPixelFormat;
            ChangeController<IEnums::RgbaPixelFormat> mDefaultRgbaPixelFormat;

            Array<SystemFont*> mSystemFonts;

            BoolChangeController mVirtualMouseEnabled;
            BoolChangeController mVirtualRawMouseEnabled;

            BoolChangeController mCloudControlEnabled;

            ChangeController<IEnums::ResultAction> mGraphObjectResultActionAttributeNumberConversionError;
            ChangeController<IEnums::ResultAction> mGraphObjectResultActionAttributeEnumConversionError;
            ChangeController<IEnums::ResultAction> mGraphObjectResultActionAttributeUnknownError;
            ChangeController<IEnums::ResultAction> mGraphObjectResultActionGraphNodeNotFoundError;
            ChangeController<IEnums::ResultAction> mGraphObjectResultActionGraphNodeWrongInterfaceError;
            ChangeController<IEnums::ResultAction> mGraphObjectResultActionResourceObjectNotFoundError;
            ChangeController<IEnums::ResultAction> mGraphObjectResultActionResourceObjectWrongInterfaceError;
        };
    }
}

#endif  // __MURL_UTIL_ENGINE_CONFIGURATION_H__

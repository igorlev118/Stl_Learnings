// Copyright 2010-2015 Spraylight

#ifndef __MURL_UTIL_APP_CONFIGURATION_H__
#define __MURL_UTIL_APP_CONFIGURATION_H__

#include "murl_i_app_configuration.h"
#include "murl_string.h"

namespace Murl
{
    namespace Util
    {
        class AppConfiguration : public IAppConfiguration
        {
        public:
            AppConfiguration();
            virtual ~AppConfiguration();

            virtual Bool Init(const IPlatformConfiguration* platformConfig, const IEngineConfiguration* engineConfig);

            virtual const IPlatformConfiguration* GetPlatformConfiguration() const;
            virtual const IEngineConfiguration* GetEngineConfiguration() const;

            virtual Bool HasChanged(ChangeInspector& inspector) const;

            virtual Bool RegisterApp(const IApp* app);
            virtual Bool UnregisterApp(const IApp* app);
            virtual Bool IsUserConfigurationMatching(const String& userConfigId) const;

            virtual void SetWindowTitle(const String& title);
            virtual const String& GetWindowTitle() const;
            virtual Bool HasWindowTitleChanged(ChangeInspector& inspector) const;

            virtual void SetLanguage(IEnums::Language language);
            virtual IEnums::Language GetLanguage() const;
            virtual Bool IsLanguageMatching(IEnums::Language language) const;
            virtual Bool HasLanguageChanged(ChangeInspector& inspector) const;

            virtual void SetCurrencySymbol(const String& currencySymbol);
            virtual const String& GetCurrencySymbol() const;
            virtual Bool HasCurrencySymbolChanged(ChangeInspector& inspector) const;

            virtual void SetCurrencyCode(const String& currencyCode);
            virtual const String& GetCurrencyCode() const;
            virtual Bool HasCurrencyCodeChanged(ChangeInspector& inspector) const;

            virtual void SetDecimalSeparator(const String& decimalSeparator);
            virtual const String& GetDecimalSeparator() const;
            virtual Bool HasDecimalSeparatorChanged(ChangeInspector& inspector) const;

            virtual void SetGroupingSeparator(const String& groupingSeparator);
            virtual const String& GetGroupingSeparator() const;
            virtual Bool HasGroupingSeparatorChanged(ChangeInspector& inspector) const;

            virtual void SetAppRunState(IEnums::AppRunState appRunState);
            virtual IEnums::AppRunState GetAppRunState() const;
            virtual Bool HasAppRunStateChanged(ChangeInspector& inspector) const;

            virtual void SetMemoryWarning(Bool warn);
            virtual Bool GetMemoryWarning() const;
            virtual Bool HasMemoryWarningChanged(ChangeInspector& inspector) const;

            virtual void SetAutomaticResourceEvictionEnabled(Bool enabled);
            virtual Bool IsAutomaticResourceEvictionEnabled() const;
            virtual Bool HasAutomaticResourceEvictionEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetMultiTouchActive(Bool enable);
            virtual Bool IsMultiTouchActive() const;
            virtual Bool HasMultiTouchActiveChanged(ChangeInspector& inspector) const;

            virtual void SetAccelerometerActive(Bool enable);
            virtual Bool IsAccelerometerActive() const;
            virtual Bool HasAccelerometerActiveChanged(ChangeInspector& inspector) const;

            virtual void SetAccelerometerFrequency(UInt32 frequency);
            virtual UInt32 GetAccelerometerFrequency() const;
            virtual Bool HasAccelerometerFrequencyChanged(ChangeInspector& inspector) const;

            virtual void SetGyroscopeActive(Bool enable);
            virtual Bool IsGyroscopeActive() const;
            virtual Bool HasGyroscopeActiveChanged(ChangeInspector& inspector) const;

            virtual void SetGyroscopeFrequency(UInt32 frequency);
            virtual UInt32 GetGyroscopeFrequency() const;
            virtual Bool HasGyroscopeFrequencyChanged(ChangeInspector& inspector) const;

            virtual void SetLocationActive(Bool enable);
            virtual Bool IsLocationActive() const;
            virtual Bool HasLocationActiveChanged(ChangeInspector& inspector) const;

            virtual void SetLocationDistanceFilter(Real meters);
            virtual Real GetLocationDistanceFilter() const;
            virtual Bool HasLocationDistanceFilterChanged(ChangeInspector& inspector) const;

            virtual void SetLocationAccuracy(Real meters);
            virtual Real GetLocationAccuracy() const;
            virtual Bool HasLocationAccuracyChanged(ChangeInspector& inspector) const;

            virtual void SetLocationPurpose(const String& purpose);
            virtual const String& GetLocationPurpose() const;
            virtual Bool HasLocationPurposeChanged(ChangeInspector& inspector) const;

            virtual void SetHeadingActive(Bool enable);
            virtual Bool IsHeadingActive() const;
            virtual Bool HasHeadingActiveChanged(ChangeInspector& inspector) const;

            virtual void SetHeadingCalibrationAllowed(Bool enable);
            virtual Bool IsHeadingCalibrationAllowed() const;
            virtual Bool HasHeadingCalibrationAllowedChanged(ChangeInspector& inspector) const;

            virtual void SetAutoRotationActive(Bool enable);
            virtual Bool IsAutoRotationActive() const;
            virtual Bool HasAutoRotationActiveChanged(ChangeInspector& inspector) const;

            virtual void SetAutoRotationDuration(Real duration);
            virtual Real GetAutoRotationDuration() const;
            virtual Bool HasAutoRotationDurationChanged(ChangeInspector& inspector) const;

            virtual void SetOrientationActive(Bool enable);
            virtual Bool IsOrientationActive() const;
            virtual Bool HasOrientationActiveChanged(ChangeInspector& inspector) const;

            virtual void SetAllowedScreenOrientations(IEnums::CombinedScreenOrientation orientations);
            virtual IEnums::CombinedScreenOrientation GetAllowedScreenOrientations() const;
            virtual Bool HasAllowedScreenOrientationsChanged(ChangeInspector& inspector) const;

            virtual IEnums::CombinedOrientation GetPortraitOrientations() const;
            virtual IEnums::Orientation GetPortraitOrientation(UInt32 index) const;
            virtual Bool HasPortraitOrientationsChanged(ChangeInspector& inspector) const;

            virtual IEnums::CombinedOrientation GetLandscapeOrientations() const;
            virtual IEnums::Orientation GetLandscapeOrientation(UInt32 index) const;
            virtual Bool HasLandscapeOrientationsChanged(ChangeInspector& inspector) const;

            virtual void SetDisplaySurfaceOrientation(IEnums::ScreenOrientation orientation);
            virtual IEnums::ScreenOrientation GetDisplaySurfaceOrientation() const;
            virtual Bool HasDisplaySurfaceOrientationChanged(ChangeInspector& inspector) const;

            virtual void SetScreenOrientation(IEnums::ScreenOrientation orientation);
            virtual IEnums::ScreenOrientation GetScreenOrientation() const;
            virtual Bool HasScreenOrientationChanged(ChangeInspector& inspector) const;

            virtual IEnums::Orientation GetDisplayRendererOrientation() const;
            virtual Bool HasDisplayRendererOrientationChanged(ChangeInspector& inspector) const;

            virtual void SetDisplaySurfaceSize(UInt32 sizeX, UInt32 sizeY);
            virtual UInt32 GetDisplaySurfaceSizeX() const;
            virtual UInt32 GetDisplaySurfaceSizeY() const;
            virtual Bool HasDisplaySurfaceSizeChanged(ChangeInspector& inspector) const;

            virtual void SetDisplaySurfaceSafeMargin(SInt32 x1, SInt32 y1, SInt32 x2, SInt32 y2);
            virtual SInt32 GetDisplaySurfaceSafeMarginX1() const;
            virtual SInt32 GetDisplaySurfaceSafeMarginY1() const;
            virtual SInt32 GetDisplaySurfaceSafeMarginX2() const;
            virtual SInt32 GetDisplaySurfaceSafeMarginY2() const;
            virtual Bool HasDisplaySurfaceSafeMarginChanged(ChangeInspector& inspector) const;

            virtual UInt32 GetWindowSizeX() const;
            virtual UInt32 GetWindowSizeY() const;
            virtual Bool HasWindowSizeChanged(ChangeInspector& inspector) const;

            virtual void SetWindowAspectRatio(Real ratio);
            virtual void SetWindowAspectRatio(UInt32 numerator, UInt32 denominator);
            virtual Real GetWindowAspectRatio() const;
            virtual UInt32 GetWindowAspectRatioNumerator() const;
            virtual UInt32 GetWindowAspectRatioDenominator() const;
            virtual Bool HasWindowAspectRatioChanged(ChangeInspector& inspector) const;

            virtual void SetLockWindowAspectEnabled(Bool enable);
            virtual Bool IsLockWindowAspectEnabled() const;
            virtual Bool HasLockWindowAspectEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetMouseCursorHidden(Bool hide);
            virtual Bool IsMouseCursorHidden() const;
            virtual Bool HasMouseCursorHiddenChanged(ChangeInspector& inspector) const;

            virtual void SetMouseCursorDisabled(Bool disable);
            virtual Bool IsMouseCursorDisabled() const;
            virtual Bool HasMouseCursorDisabledChanged(ChangeInspector& inspector) const;

            virtual void SetMouseCoordinateClampingDisabled(Bool disable);
            virtual Bool IsMouseCoordinateClampingDisabled() const;
            virtual Bool HasMouseCoordinateClampingDisabledChanged(ChangeInspector& inspector) const;

            virtual void SetCommandKeyDisabled(Bool disable);
            virtual Bool IsCommandKeyDisabled() const;
            virtual Bool HasCommandKeyDisabledChanged(ChangeInspector& inspector) const;

            virtual void SetDisplayRefreshFrequency(UInt32 frequency, UInt32 forcedFrames);
            virtual UInt32 GetDisplayRefreshFrequency() const;
            virtual UInt32 GetDisplayRefreshFrequencyForcedFrames() const;
            virtual Bool HasDisplayRefreshFrequencyChanged(ChangeInspector& inspector) const;

            virtual void SetClockDeltaLimit(Double seconds);
            virtual Double GetClockDeltaLimit() const;
            virtual Bool HasClockDeltaLimitChanged(ChangeInspector& inspector) const;

            virtual void SetClockTimeBase(Double factor);
            virtual Double GetClockTimeBase() const;
            virtual Bool HasClockTimeBaseChanged(ChangeInspector& inspector) const;

            virtual void SetClockAveragingFactor(Double factor);
            virtual Double GetClockAveragingFactor() const;
            virtual Bool HasClockAveragingFactorChanged(ChangeInspector& inspector) const;

            virtual void SetRunLoopTriggers(IEnums::RunLoopTriggers triggers);
            virtual IEnums::RunLoopTriggers GetRunLoopTriggers() const;
            virtual Bool HasRunLoopTriggersChanged(ChangeInspector& inspector) const;

            virtual void SetFullScreenEnabled(Bool enable);
            virtual Bool IsFullScreenEnabled() const;
            virtual Bool HasFullScreenEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetIosHomeIndicatorAutoHiddenEnabled(Bool enabled);
            virtual Bool IsIosHomeIndicatorAutoHiddenEnabled() const;
            virtual Bool HasIosHomeIndicatorAutoHiddenChanged(ChangeInspector& inspector) const;

            virtual void SetIosPreferredScreenEdgesDeferringSystemGestures(IEnums::CombinedScreenEdges edges);
            virtual IEnums::CombinedScreenEdges GetIosPreferredScreenEdgesDeferringSystemGestures() const;
            virtual Bool HasIosPreferredScreenEdgesDeferringSystemGesturesChanged(ChangeInspector& inspector) const;

            virtual void SetAndroidLowProfileNavigationBarEnabled(Bool enable);
            virtual Bool IsAndroidLowProfileNavigationBarEnabled() const;
            virtual Bool HasAndroidLowProfileNavigationBarChanged(ChangeInspector& inspector) const;

            virtual void SetAndroidHideNavigationBarImmersiveStickyEnabled(Bool enable);
            virtual Bool IsAndroidHideNavigationBarImmersiveStickyEnabled() const;
            virtual Bool HasAndroidHideNavigationBarImmersiveStickyChanged(ChangeInspector& inspector) const;

            virtual void SetSystemDebugInfoEnabled(Bool enable);
            virtual Bool IsSystemDebugInfoEnabled() const;
            virtual Bool HasSystemDebugInfoEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetSystemDebugInfoScaleFactor(Real factor);
            virtual Real GetSystemDebugInfoScaleFactor() const;
            virtual Bool HasSystemDebugInfoScaleFactorChanged(ChangeInspector& inspector) const;

            virtual void SetSystemDebugInfoItems(UInt32 itemMask);
            virtual UInt32 GetSystemDebugInfoItems() const;
            virtual Bool HasSystemDebugInfoItemsChanged(ChangeInspector& inspector) const;

            virtual void SetUserDebugInfoEnabled(Bool enable);
            virtual Bool IsUserDebugInfoEnabled() const;
            virtual Bool HasUserDebugInfoEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetUserDebugInfoScaleFactor(Real factor);
            virtual Real GetUserDebugInfoScaleFactor() const;
            virtual Bool HasUserDebugInfoScaleFactorChanged(ChangeInspector& inspector) const;

            virtual void SetDebugMouseEnabled(Bool enable);
            virtual Bool IsDebugMouseEnabled() const;
            virtual Bool HasDebugMouseEnabledChanged(ChangeInspector& inspector) const;

            virtual void SetDebugMouseScaleFactor(Real factor);
            virtual Real GetDebugMouseScaleFactor() const;
            virtual Bool HasDebugMouseScaleFactorChanged(ChangeInspector& inspector) const;

            virtual void SetDebugOutputFunctionVerbosity(UInt32 itemMask);
            virtual UInt32 GetDebugOutputFunctionVerbosity() const;

            virtual void SetDebugTraceLevel(SInt32 level);
            virtual SInt32 GetDebugTraceLevel() const;

            virtual void SetTrackerTraceLevel(SInt32 level);
            virtual SInt32 GetTrackerTraceLevel() const;

        protected:
            struct AspectRatio
            {
                AspectRatio(UInt32 numerator, UInt32 denominator)
                : mNumerator(numerator)
                , mDenominator(denominator)
                , mRatio(Real(numerator) / Real(denominator))
                {
                }

                AspectRatio(Real ratio)
                : mNumerator(UInt32(ratio * 65536.0))
                , mDenominator(65536)
                , mRatio(ratio)
                {
                }

                bool operator==(const AspectRatio& other) const
                {
                    return ((mNumerator == other.mNumerator) && (mDenominator == other.mDenominator));
                }

                UInt32 mNumerator;
                UInt32 mDenominator;
                Real mRatio;
            };

            struct WindowSize
            {
                WindowSize(UInt32 sizeX, UInt32 sizeY)
                : mSizeX(sizeX)
                , mSizeY(sizeY)
                {
                }

                bool operator==(const WindowSize& other) const
                {
                    return ((mSizeX == other.mSizeX) && (mSizeY == other.mSizeY));
                }

                UInt32 mSizeX;
                UInt32 mSizeY;
            };

            struct WindowRect
            {
                WindowRect(SInt32 x1, SInt32 y1, SInt32 x2, SInt32 y2)
                : mX1(x1)
                , mY1(y1)
                , mX2(x2)
                , mY2(y2)
                {
                }

                bool operator==(const WindowRect& other) const
                {
                    return ((mX1 == other.mX1) && (mY1 == other.mY1) && (mX2 == other.mX2) && (mY2 == other.mY2));
                }

                SInt32 mX1;
                SInt32 mY1;
                SInt32 mX2;
                SInt32 mY2;
            };

            template<class DataType>
            void SetItemValue(ChangeController<DataType>& item, const DataType& value)
            {
                if (item.SetValue(value))
                {
                    mHasChanged.SetChanged();
                }
            }

            void SetPortraitAndLandscapeOrientations();
            void SetDisplayRendererOrientation();
            void SetWindowSize();

            const IPlatformConfiguration* mPlatformConfig;
            const IEngineConfiguration* mEngineConfig;
            const IApp* mRegisteredApp;

            BoolChangeController mHasChanged;

            ChangeController<IEnums::Language> mLanguage;

            StringChangeController mCurrencySymbol;
            StringChangeController mCurrencyCode;
            StringChangeController mDecimalSeparator;
            StringChangeController mGroupingSeparator;

            ChangeController<IEnums::AppRunState> mAppRunState;

            BoolChangeController mMemoryWarning;
            BoolChangeController mAutomaticResourceEvictionEnabled;
            BoolChangeController mMultiTouchActive;

            BoolChangeController mAccelerometerActive;
            ChangeController<UInt32> mAccelerometerFrequency;

            BoolChangeController mGyroscopeActive;
            ChangeController<UInt32> mGyroscopeFrequency;

            BoolChangeController mLocationActive;
            ChangeController<Real> mLocationDistanceFilter;
            ChangeController<Real> mLocationAccuracy;
            StringChangeController mLocationPurpose;

            BoolChangeController mHeadingActive;
            BoolChangeController mHeadingCalibrationAllowed;

            BoolChangeController mAutoRotationActive;
            ChangeController<Real> mAutoRotationDuration;
            BoolChangeController mOrientationActive;
            ChangeController<IEnums::CombinedScreenOrientation> mAllowedScreenOrientations;
            ChangeController<IEnums::CombinedOrientation> mPortraitOrientations;
            ChangeController<IEnums::CombinedOrientation> mLandscapeOrientations;
            ChangeController<IEnums::Orientation> mPortraitOrientation1;
            ChangeController<IEnums::Orientation> mPortraitOrientation2;
            ChangeController<IEnums::Orientation> mLandscapeOrientation1;
            ChangeController<IEnums::Orientation> mLandscapeOrientation2;
            ChangeController<IEnums::ScreenOrientation> mScreenOrientation;
            ChangeController<IEnums::ScreenOrientation> mDisplaySurfaceOrientation;
            ChangeController<IEnums::Orientation> mDisplayRendererOrientation;

            ChangeController<WindowSize> mDisplaySurfaceSize;
            ChangeController<WindowRect> mDisplaySurfaceSafeMargin;

            ChangeController<WindowSize> mWindowSize;

            ChangeController<AspectRatio> mWindowAspectRatio;
            BoolChangeController mLockWindowAspect;

            StringChangeController mWindowTitle;

            BoolChangeController mMouseCursorHidden;
            BoolChangeController mMouseCursorDisabled;
            BoolChangeController mMouseCoordinateClampingDisabled;

            BoolChangeController mCommandKeyDisabled;

            ChangeController<UInt32> mDisplayRefreshFrequency;
            ChangeController<UInt32> mDisplayRefreshFrequencyForcedFrames;

            ChangeController<Double> mClockDeltaLimit;
            ChangeController<Double> mClockTimeBase;
            ChangeController<Double> mClockAveragingFactor;

            ChangeController<IEnums::RunLoopTriggers> mRunLoopTriggers;

            BoolChangeController mFullscreenEnabled;

            BoolChangeController mIosHomeIndicatorAutoHiddenEnabled;
            ChangeController<IEnums::CombinedScreenEdges> mIosPreferredScreenEdgesDeferringSystemGestures;

            BoolChangeController mLowProfileNavigationBarEnabled;
            BoolChangeController mHideNavigationBarImmersiveStickyEnabled;

            BoolChangeController mSystemDebugInfoEnabled;
            ChangeController<Real> mSystemDebugInfoScaleFactor;
            ChangeController<UInt32> mSystemDebugInfoItems;

            BoolChangeController mUserDebugInfoEnabled;
            ChangeController<Real> mUserDebugInfoScaleFactor;

            BoolChangeController mDebugMouseEnabled;
            ChangeController<Real> mDebugMouseScaleFactor;

            ChangeController<UInt32> mDebugOutputFunctionItemMask;
            ChangeController<SInt32> mDebugTraceLevel;

            ChangeController<SInt32> mTrackerTraceLevel;
        };
    }
}

#endif  // __MURL_UTIL_APP_CONFIGURATION_H__

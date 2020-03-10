// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_VIDEO_SCALER_H__
#define __MURL_UTIL_VIDEO_SCALER_H__

#include "murl_i_enums.h"
#include "murl_i_video_scaler.h"
#include "murl_util_filter.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The video scaler class.
         */
        class VideoScaler : public IVideoScaler
        {
        public:
            /**
             * @brief Constructor creating a scaler using a specified filter.
             * @param filter The filter used for scaling.
             */
            VideoScaler(const IFilter* filter);

            /**
             * @brief The destructor.
             */
            virtual ~VideoScaler();

            /**
             * @brief Implementation of IVideoScaler::Scale().
             * @param srcData The source image data.
             * @param dstData The destination image data.
             * @param srcPixelSizeX The number of horizontal source pixels.
             * @param srcPixelSizeY The number of vertical source pixels.
             * @param srcBytePitch The number of source bytes per line.
             * @param dstPixelSizeX The number of horizontal destination pixels.
             * @param dstPixelSizeY The number of vertical destination pixels.
             * @param dstBytePitch The number of destination bytes per line.
             * @param pixelFormat The pixel format.
             * @param gamma The gamma value. Specify 1.0 to disable gamma
             *  correct scaling.
             * @return true if successful.
             */
            virtual Bool Scale(const ConstData& srcData, const MutableData& dstData,
                               UInt32 srcPixelSizeX, UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                               UInt32 dstPixelSizeX, UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                               IEnums::PixelFormat pixelFormat, Real gamma) const;

        protected:
            enum BaseType
            {
                BASE_TYPE_UINT8,
                BASE_TYPE_FLOAT,
                BASE_TYPE_HALF_FLOAT,
                NUM_BASE_TYPES
            };

            /**
             * @brief Alternative scale method for overloading.
             * A derived class can implement alternative scaling algorithms by overloading
             * this method and returning true if alternative scaling has been performed.
             * @param srcData The source image data.
             * @param dstData The destination image data.
             * @param srcPixelSizeX The number of horizontal source pixels.
             * @param srcPixelSizeY The number of vertical source pixels.
             * @param srcBytePitch The number of source bytes per line.
             * @param dstPixelSizeX The number of horizontal destination pixels.
             * @param dstPixelSizeY The number of vertical destination pixels.
             * @param dstBytePitch The number of destination bytes per line.
             * @param pixelFormat The pixel format.
             * @param gamma The gamma value. Specify 1.0 to disable gamma
             *  correct scaling.
             * @return false if fast scaling is not supported.
             */
            virtual Bool ScaleFast(const ConstData& srcData, const MutableData& dstData,
                                   UInt32 srcPixelSizeX, UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                                   UInt32 dstPixelSizeX, UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                                   IEnums::PixelFormat pixelFormat, Real gamma) const;

            Bool GetScaleParams(IEnums::PixelFormat pixelFormat, Real gamma,
                                BaseType& baseType, UInt32& componentsPerPixel,
                                Real* p, Real* q) const;

        private:
            class PixelContribution
            {
            public:
                PixelContribution();
                ~PixelContribution();

                Double* mWeights;
                SInt32 mLeft;
                SInt32 mRight;
            };

            class LineContribution
            {
            public:
                LineContribution();
                ~LineContribution();

                void Calculate(UInt32 dstSize, UInt32 srcSize, Double scale, const IFilter* filter);

                PixelContribution* mPixelContributions;
                UInt32 mWindowSize;
                UInt32 mLineLength;
            };

            template<class DataType>
            void ScaleRow(const UInt8* srcData, UInt8* dstData,
                          UInt32 srcPixelSizeX, UInt32 srcBytePitch,
                          UInt32 dstPixelSizeX, UInt32 dstBytePitch,
                          UInt32 commonComponentsPerPixel, UInt32 row,
                          const LineContribution* contrib) const;

            template<class DataType>
            void ScaleRow(const UInt8* srcData, UInt8* dstData,
                          UInt32 srcPixelSizeX, UInt32 srcBytePitch,
                          UInt32 dstPixelSizeX, UInt32 dstBytePitch,
                          UInt32 commonComponentsPerPixel, UInt32 row,
                          const LineContribution* contrib,
                          const Float* p, const Float* q) const;

            template<class DataType>
            void ScaleCol(const UInt8* srcData, UInt8* dstData,
                          UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                          UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                          UInt32 commonComponentsPerPixel, UInt32 col,
                          const LineContribution* contrib) const;

            template<class DataType>
            void ScaleCol(const UInt8* srcData, UInt8* dstData,
                          UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                          UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                          UInt32 commonComponentsPerPixel, UInt32 col,
                          const LineContribution* contrib,
                          const Float* p, const Float* q) const;

            Bool HorizScale(const UInt8* srcData, UInt8* dstData,
                            UInt32 srcPixelSizeX, UInt32 srcBytePitch,
                            UInt32 dstPixelSizeX, UInt32 dstBytePitch,
                            UInt32 commonPixelSizeY,
                            UInt32 commonComponentsPerPixel,
                            BaseType commonBaseType,
                            const Real* p, const Real* q) const;

            Bool VertScale(const UInt8* srcData, UInt8* dstData,
                           UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                           UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                           UInt32 commonPixelSizeX,
                           UInt32 commonComponentsPerPixel,
                           BaseType commonBaseType,
                           const Real* p, const Real* q) const;

            const IFilter* mFilter;
        };

        /** @brief The VideoScaler shared pointer type. */
        typedef SharedPointer<VideoScaler> VideoScalerPtr;

        /** @brief The VideoScaler const shared pointer type. */
        typedef SharedPointer<VideoScaler const> VideoScalerCPtr;

        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The nearest video scaler class simply samples
         * single points without filtering.
         */
        class NearestVideoScaler : public VideoScaler
        {
        public:
            /**
             * @brief The default constructor.
             */
            NearestVideoScaler();

        protected:
            virtual Bool ScaleFast(const ConstData& srcData, const MutableData& dstData,
                                   UInt32 srcPixelSizeX, UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                                   UInt32 dstPixelSizeX, UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                                   IEnums::PixelFormat pixelFormat, Real gamma) const;
        };
        
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The box video scaler class uses the BoxFilter
         * and supports optimized scaling to half of the size.
         */
        class BoxVideoScaler : public VideoScaler
        {
        public:
            /**
             * @brief The default constructor.
             * Create a BoxFilter having width 0.5.
             */
            BoxVideoScaler();

            /**
             * @brief Constructor taking the filter width value.
             * @param filterWidth The BoxFilter width.
             */
            BoxVideoScaler(Double filterWidth);

        protected:
            /**
             * @brief Optimized scaling to a quarter of the original size (half width and height).
             * @param srcData The source image data.
             * @param dstData The destination image data.
             * @param srcPixelSizeX The number of horizontal source pixels.
             * @param srcPixelSizeY The number of vertical source pixels.
             * @param srcBytePitch The number of source bytes per line.
             * @param dstPixelSizeX The number of horizontal destination pixels.
             * @param dstPixelSizeY The number of vertical destination pixels.
             * @param dstBytePitch The number of destination bytes per line.
             * @param pixelFormat The pixel format.
             * @param gamma The gamma value. Specify 1.0 to disable gamma
             *  correct scaling.
             * @return false if not supported for the given set of parameters.
             */
            virtual Bool ScaleFast(const ConstData& srcData, const MutableData& dstData,
                                   UInt32 srcPixelSizeX, UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                                   UInt32 dstPixelSizeX, UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                                   IEnums::PixelFormat pixelFormat, Real gamma) const;

        private:
            template<class DataType>
            Bool ScaleFast(const UInt8* pSrcData, UInt8* pDstData,
                           UInt32 w, UInt32 h,
                           UInt32 srcBytePitch, UInt32 dstBytePitch,
                           UInt32 componentsPerPixel) const;

            template<class DataType>
            Bool ScaleFast(const UInt8* pSrcData, UInt8* pDstData,
                           UInt32 w, UInt32 h,
                           UInt32 srcBytePitch, UInt32 dstBytePitch,
                           UInt32 componentsPerPixel,
                           const Float* p, const Float* q) const;

            BoxFilter mBoxFilter;
        };

        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The bilinear video scaler class uses the BilinearFilter.
         */
        class BilinearVideoScaler : public VideoScaler
        {
        public:
            /**
             * @brief The default constructor.
             * Create a BilinearFilter having width 1.0.
             */
            BilinearVideoScaler();

            /**
             * @brief Constructor taking the filter width value.
             * @param filterWidth The BilinearFilter width.
             */
            BilinearVideoScaler(Double filterWidth);

        private:
            BilinearFilter mBilinearFilter;
        };

        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The gaussian video scaler class uses the GaussianFilter.
         */
        class GaussianVideoScaler : public VideoScaler
        {
        public:
            /**
             * @brief The default constructor.
             * Create a GaussianFilter having width 3.0 and sigma 1.0.
             */
            GaussianVideoScaler();

            /**
             * @brief Constructor taking the filter width and sigma value.
             * @param filterWidth The GaussianFilter width.
             * @param filterSigma The GaussianFilter standard deviation.
             */
            GaussianVideoScaler(Double filterWidth, Double filterSigma);

        private:
            GaussianFilter mGaussianFilter;
        };
    }
}

#endif // __MURL_UTIL_VIDEO_SCALER_H__

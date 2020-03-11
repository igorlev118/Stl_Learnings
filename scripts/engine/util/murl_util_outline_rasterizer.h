// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_OUTLINE_RASTERIZER_H__
#define __MURL_UTIL_OUTLINE_RASTERIZER_H__

#include "murl_array.h"
#include "murl_system_mutex.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IVideoSurface;

    namespace Resource
    {
        class IOutline;
    }

    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief A class for rasterizing vector outlines.
         */
        class OutlineRasterizer
        {
        public:
            /**
             * @ingroup MurlUtilClasses
             * @brief A handle for rasterizing individual vector outlines.
             */
            class Handle
            {
            protected:
                virtual ~Handle() {}
            };

            /**
             * @brief Acquire a rasterizer.
             * Each call to Acquire() must have a corresponding call to Release(), when the 
             * rasterizer is not needed anymore.
             * @return The rasterizer instance.
             */
            static OutlineRasterizer* Acquire();
            /**
             * @brief Release a previously acquired rasterizer.
             * @param rasterizer A reference to a pointer of the rasterizer to be released.
             * @return true if successful.
             */
            static Bool Release(OutlineRasterizer*& rasterizer);

            /**
             * @brief Begin rasterizing a sequence of outlines.
             * Rasterizing any number of outlines must always be enclosed within paired calls
             * to BeginRasterizing() and EndRasterizing().
             * These methods ensure that no two threads are using the same rasterizer instance
             * concurrently, by locking/unlocking an internal mutex.
             * @return A pointer to a rasterizer handle, or null if failed.
             */
            const Handle* BeginRasterizing();
            /**
             * @brief End rasterizing a sequence of outlines.
             * @param handle The rasterizer handle obtained via BeginRasterizing().
             * @return true if successful.
             */
            Bool EndRasterizing(const Handle* handle);

            /**
             * @brief Rasterize an outline.
             * @param handle A handle obtained via BeginRasterizing().
             * @param outline The resource outline object to rasterize.
             * @param outlineColor The outline color.
             * @param backColor The background color.
             * @param surface The output surface to rasterize to.
             * @param posX The horizontal position of the outline in the surface.
             * @param posY The vertical position of the outline in the surface.
             * @param scaleX The horizontal scale factor.
             * @param scaleY The vertical scale factor.
             * @param embolden The emboldening value. A value of 0.0 renders an unmodified outline,
             *      a negative value produces a thinner outline.
             * @return true if successful.
             */
            Bool Rasterize(const Handle* handle, const Resource::IOutline* outline, const Color& outlineColor, const Color& backColor,
                           IVideoSurface* surface, Real posX, Real posY, Real scaleX, Real scaleY, Real embolden);

        protected:
            struct Vec2
            {
                Float mX;
                Float mY;
            };

            struct Point
            {
                SInt32 mX;
                SInt32 mY;
            };

            struct BBox
            {
                SInt32 mMinX;
                SInt32 mMinY;
                SInt32 mMaxX;
                SInt32 mMaxY;

            };

            struct Bitmap
            {
                SInt32 mSizeX;
                SInt32 mSizeY;
                SInt32 mPitch;
                UInt8* mData;
            };

            struct Outline
            {
                SInt16 mNumContours;
                SInt16 mNumPoints;
                SInt32 mFlags;

                Point* mPoints;
                const SInt16* mContours;
                const UInt8* mTags;
            };

            struct Cell
            {
                SInt32 mX;
                SInt32 mCover;
                SInt32 mArea;
                Cell* mNext;
            };

            struct Span
            {
                SInt16 mX;
                UInt16 mLength;
                UInt8 mCoverage;
            };

            struct Band
            {
                SInt32 mMin;
                SInt32 mMax;
            };

            enum
            {
                PIXEL_BITS = 8,
                MAX_GRAY_SPANS = 32,

                MAX_SCRATCH_BANDS = 512,
                MAX_SCRATCH_CELLS = MAX_SCRATCH_BANDS * 8,
                MAX_SCRATCH_BYTES = MAX_SCRATCH_CELLS * sizeof(Cell),

                ONE_PIXEL =  (1 << PIXEL_BITS),
                PIXEL_MASK = (-1 << PIXEL_BITS)
            };

            typedef void (*RenderSpanFunc)(UInt8* p, SInt32 count, const Span* spans, UInt32 color);

            OutlineRasterizer();
            virtual ~OutlineRasterizer();

            Bool Init();
            Bool DeInit();

            Bool Render();
            Bool ReduceBands(Band*& band);
            Bool DecomposeOutline();
            Bool MoveTo(const Point* to);
            Bool LineTo(const Point* to);
            Bool ConicTo(const Point* control, const Point* to);
            Bool CubicTo(const Point* control1, const Point* control2, const Point* to);
            Bool RenderLine(SInt32 toX, SInt32 toY);
            Bool RenderScanline(SInt32 ey, SInt32 x1, SInt32 y1, SInt32 x2, SInt32 y2);
            Bool RenderConic(const Point* control, const Point* to);
            Bool RenderCubic(const Point* control1, const Point* control2, const Point* to);

            void SplitConic(Point* base);
            void SplitCubic(Point* base);

            void ComputeCBox();
            void Sweep();
            void HLine(SInt32 x, SInt32 y, SInt32 area, SInt32 acount);
            Cell* FindCell();
            Bool RecordCell();
            Bool SetCell(SInt32 ex, SInt32 ey);
            Bool StartCell(SInt32 ex, SInt32 ey);

            void SetOutlinePoints(const Vec2* points, Real posX, Real posY, Real scaleX, Real scaleY, Real embolden);

            void RenderSpan(SInt32 y, SInt32 count, const Span* spans);

            static void RenderSpanLumaCopy(UInt8* p, SInt32 count, const Span* spans, UInt32 color);
            static void RenderSpanLumaMultiply(UInt8* p, SInt32 count, const Span* spans, UInt32 color);

            static void RenderSpanAlphaCopy(UInt8* p, SInt32 count, const Span* spans, UInt32 color);
            static void RenderSpanAlphaMultiply(UInt8* p, SInt32 count, const Span* spans, UInt32 color);

            static void RenderSpanLumaAlphaCopy(UInt8* p, SInt32 count, const Span* spans, UInt32 color);
            static void RenderSpanLumaAlphaMultiply(UInt8* p, SInt32 count, const Span* spans, UInt32 color);

            static void RenderSpanRgbCopy(UInt8* p, SInt32 count, const Span* spans, UInt32 color);
            static void RenderSpanRgbMultiply(UInt8* p, SInt32 count, const Span* spans, UInt32 color);

            static void RenderSpanRgbaCopy(UInt8* p, SInt32 count, const Span* spans, UInt32 color);
            static void RenderSpanRgbaMultiply(UInt8* p, SInt32 count, const Span* spans, UInt32 color);

            inline static SInt32 Trunc(SInt32 x)
            {
                return (x >> PIXEL_BITS);
            }

            inline static SInt32 SubPixels(SInt32 x)
            {
                return (x << PIXEL_BITS);
            }

            inline static SInt32 Upscale(SInt32 x)
            {
                return (x << (PIXEL_BITS - 6));
            }

            inline static SInt32 Downscale(SInt32 x)
            {
                return (x >> (PIXEL_BITS - 6));
            }

            Bool mIsInitialized;

            UInt8* mBuffer;
            SInt32 mBufferSize;

            SInt32 mEx;
            SInt32 mEy;
            SInt32 mMinEx;
            SInt32 mMaxEx;
            SInt32 mMinEy;
            SInt32 mMaxEy;
            SInt32 mCountEx;
            SInt32 mCountEy;
            SInt32 mLastEy;

            SInt32 mArea;
            SInt32 mCover;

            Bool mIsInvalid;
            Bool mHasOverflow;

            Cell* mCells;
            UInt32 mMaxCells;
            UInt32 mNumCells;

            SInt32 mX;
            SInt32 mY;

            Point mBezierStack[32 * 3 + 1];
            SInt32 mLevelStack[32];

            Outline mOutline;
            Bitmap mBitmap;
            BBox mClipBox;

            Span mGraySpans[MAX_GRAY_SPANS];
            SInt32 mNumGraySpans;

            SInt32 mSpanY;

            SInt32 mBandSize;
            SInt32 mBandShoot;

            Cell** mCellsY;
            SInt32 mCountY;

            UInt32 mTextColor;
            UInt32 mBackColor;
            IEnums::PixelFormat mPixelFormat;

            RenderSpanFunc mRenderSpanFunc;

            Array<Point> mOutlinePoints;
            Array<Vec2> mTmpPoints;

            System::Mutex mMutex;
            const Handle* mCurrentHandle;

            static UInt32 sNumInstances;
            static OutlineRasterizer* sInstance;
        };
    }
}

#endif  // __MURL_UTIL_OUTLINE_RASTERIZER_H__

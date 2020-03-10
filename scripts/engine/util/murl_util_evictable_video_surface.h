// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_UTIL_EVICTABLE_VIDEO_SURFACE_H__
#define __MURL_UTIL_EVICTABLE_VIDEO_SURFACE_H__

#include "murl_util_video_surface.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The evictable video surface class, see IVideoSurface.
         */
        class EvictableVideoSurface : public VideoSurface, NonCopyable
        {
        public:
            /**
             * @brief Constructor creating a surface of specified dimension.
             * Creates a surface with pixel format IEnums::PIXEL_FORMAT_R8_G8_B8_A8.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             */
            EvictableVideoSurface(UInt32 pixelSizeX, UInt32 pixelSizeY);

            /**
             * @brief Constructor creating a surface of specified pixel format and dimension.
             * @param pixelFormat The pixel format.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             */
            EvictableVideoSurface(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY);

            /**
             * @brief The destructor.
             */
            virtual ~EvictableVideoSurface();

            /**
             * @brief Implementation of IVideoSurface::GetMutablePixels().
             * @return The mutable data object which is holding the pixels.
             */
            virtual const MutableData& GetMutablePixels();

            /**
             * @brief Implementation of IVideoSurface::Evict().
             * @return true if successful.
             */
            virtual Bool Evict();
            /**
             * @brief Implementation of IVideoSurface::Restore().
             * @return true if successful.
             */
            virtual Bool Restore();

            /**
             * @brief Implementation of IVideoSurface::FlipX().
             * @return true if successful.
             */
            virtual Bool FlipX();
            /**
             * @brief Implementation of IVideoSurface::FlipY().
             * @return true if successful.
             */
            virtual Bool FlipY();

            /**
             * @brief Implementation of IVideoSurface::Blit(const IVideoSurface* source,
             *  SInt32 sourcePositionX, SInt32 sourcePositionY, SInt32 destPositionX,
             *  SInt32 destPositionY, UInt32 pixelSizeX, UInt32 pixelSizeY).
             * @param source The source surface.
             * @param sourcePositionX The source x-position.
             * @param sourcePositionY The source y-position.
             * @param destPositionX The destination x-position.
             * @param destPositionY The destination y-position.
             * @param pixelSizeX The number of horizontal pixels to copy.
             * @param pixelSizeY The number of vertical pixels to copy.
             * @return true if successful.
             */
            virtual Bool Blit(const IVideoSurface* source, SInt32 sourcePositionX, SInt32 sourcePositionY,
                              SInt32 destPositionX, SInt32 destPositionY, UInt32 pixelSizeX, UInt32 pixelSizeY);

            /**
             * @brief Implementation of IVideoSurface::BlitScaled().
             * @param source The source surface.
             * @param scaler Pointer to a scaler object or null to scale using the BoxVideoScaler.
             * @param gamma The gamma value used during scaling.
             * @return true if successful.
             */
            virtual Bool BlitScaled(const IVideoSurface* source, const IVideoScaler* scaler = 0, Real gamma = 1.0f);

            /**
             * @brief Implementation of IVideoSurface::Clear(SInt32 positionX, SInt32 positionY,
             *  UInt32 pixelSizeX, UInt32 pixelSizeY, const Color& clearColor).
             * @param positionX The source x-position of the region.
             * @param positionY The source y-position of the region.
             * @param pixelSizeX The number of horizontal pixels of the region.
             * @param pixelSizeY The number of vertical pixels of the region.
             * @param clearColor The clear color to apply.
             * @return true if successful.
             */
            virtual Bool Clear(SInt32 positionX, SInt32 positionY, UInt32 pixelSizeX, UInt32 pixelSizeY,
                               const Color& clearColor);

            /**
             * @brief Implementation of IVideoSurface::GaussBlur(SInt32 positionX, SInt32 positionY,
             *  UInt32 pixelSizeX, UInt32 pixelSizeY, Real strength).
             * @param positionX The x-position of the region.
             * @param positionY The y-position of the region.
             * @param pixelSizeX The number of horizontal pixels of the region.
             * @param pixelSizeY The number of vertical pixels of the region.
             * @param strength The blur filter strength.
             * @return true if successful.
             */
            virtual Bool GaussBlur(SInt32 positionX, SInt32 positionY, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                   Real strength);

            /**
             * @brief Implementation of IVideoSurface::ApplyMatte(SInt32 positionX, SInt32 positionY,
             *  UInt32 pixelSizeX, UInt32 pixelSizeY, const Color& matteColor, Real matteThreshold = 0).
             * @param positionX The source x-position of the region.
             * @param positionY The source y-position of the region.
             * @param pixelSizeX The number of horizontal pixels of the region.
             * @param pixelSizeY The number of vertical pixels of the region.
             * @param matteColor The matte color to apply.
             * @param matteThreshold The alpha threshold in range [0.0 .. 1.0].
             * @return true if successful.
             */
            virtual Bool ApplyMatte(SInt32 positionX, SInt32 positionY, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                    const Color& matteColor, Real matteThreshold = 0);

            /**
             * @brief Implementation of IVideoSurface::RenderText().
             * @param font The font used for rendering.
             * @param text The text to render.
             * @param textColor The text color to render.
             * @param backgroundColor The text background color to render.
             * @param clearSurface If true, the output surface is cleared before rendering.
             * @param enableWordWrap If true, word wrapping is enabled.
             * @param containerPosX The horizontal text position in the video stream.
             * @param containerPosY The vertical text position in the video stream.
             * @param containerSizeX The horizontal size of the text rectangle, or 0
             *      if the video stream's X size should be used
             * @param containerSizeY The vertical size of the text rectangle, or 0 if
             *      the video stream's Y size should be used
             * @param alignX The horizontal text alignment.
             * @param alignY The vertical text alignment.
             * @return true if successful.
             */
            virtual Bool RenderText(const IFont* font, const String& text,
                                    const Color& textColor, const Color& backgroundColor,
                                    Bool clearSurface, Bool enableWordWrap,
                                    Real containerPosX, Real containerPosY,
                                    Real containerSizeX, Real containerSizeY,
                                    IEnums::TextAlignmentX alignX, IEnums::TextAlignmentY alignY);

        protected:
            class Operation
            {
            public:
                virtual ~Operation() {}

                virtual Bool Execute(IVideoSurface* target) = 0;
            };

            class RenderTextOperation : public Operation
            {
            public:
                RenderTextOperation(const IFont* font, const String& text,
                                    const Color& textColor, const Color& backgroundColor,
                                    Bool clearSurface, Bool enableWordWrap,
                                    Real containerPosX, Real containerPosY,
                                    Real containerSizeX, Real containerSizeY,
                                    IEnums::TextAlignmentX alignX, IEnums::TextAlignmentY alignY);
                virtual Bool Execute(IVideoSurface* target);
            protected:
                const IFont* mFont;
                String mText;
                Color mTextColor;
                Color mBackgroundColor;
                Bool mClearSurface;
                Bool mEnableWordWrap;
                Real mContainerPosX;
                Real mContainerPosY;
                Real mContainerSizeX;
                Real mContainerSizeY;
                IEnums::TextAlignmentX mAlignX;
                IEnums::TextAlignmentY mAlignY;
            };

            virtual void AddOperation(Operation* o);

            virtual void DestroyOperations();
            virtual void DisableEviction();

            virtual Bool BeginBatch(Bool disableEviction);
            virtual Bool EndBatch(Bool returnValue);

            Bool mCanBeEvicted;
            Bool mIsEvicted;
            UInt32 mBatchCount;

            Array<Operation*> mOperations;
        };
    }
}

#endif // __MURL_UTIL_EVICTABLE_VIDEO_SURFACE_H__

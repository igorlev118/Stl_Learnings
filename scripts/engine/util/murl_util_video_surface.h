// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_UTIL_VIDEO_SURFACE_H__
#define __MURL_UTIL_VIDEO_SURFACE_H__

#include "murl_i_video_surface.h"
#include "murl_i_video_scaler.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The video surface class, see IVideoSurface.
         */
        class VideoSurface : public IVideoSurface
        {
        public:
            /**
             * @brief The default constructor.
             * Create an empty surface with unknown pixel format.
             */
            VideoSurface();

            /**
             * @brief Constructor creating a surface of specified dimension.
             * Creates a surface with pixel format IEnums::PIXEL_FORMAT_R8_G8_B8_A8.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             */
            VideoSurface(UInt32 pixelSizeX, UInt32 pixelSizeY);

            /**
             * @brief Constructor creating a surface of specified dimension, with given line pitch.
             * Creates a surface with pixel format IEnums::PIXEL_FORMAT_R8_G8_B8_A8.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param bytesPerLine The line pitch in bytes.
             */
            VideoSurface(UInt32 pixelSizeX, UInt32 pixelSizeY, UInt32 bytesPerLine);

            /**
             * @brief Constructor creating a surface of specified pixel format and dimension.
             * @param pixelFormat The pixel format.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             */
            VideoSurface(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY);

            /**
             * @brief Constructor creating a surface of specified pixel format and dimension, with given line pitch.
             * @param pixelFormat The pixel format.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param bytesPerLine The line pitch in bytes.
             */
            VideoSurface(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY, UInt32 bytesPerLine);

            /**
             * @brief Constructor creating a surface of specified pixel format and dimension with given source data.
             * This constructor can be used to create a surface effectively wrapping a given block of mutable data
             * without copying the source contents.
             * @param pixelFormat The pixel format.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param sourceData The mutable data block to be wrapped.
             */
            VideoSurface(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY, MutableData& sourceData);

            /**
             * @brief Constructor creating a surface of specified pixel format and dimension with given source data.
             * This constructor can be used to create a surface effectively wrapping a given block of mutable data
             * without copying the source contents, using a given line pitch.
             * @param pixelFormat The pixel format.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param bytesPerLine The line pitch in bytes.
             * @param sourceData The mutable data block to be wrapped.
             */
            VideoSurface(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY, UInt32 bytesPerLine, MutableData& sourceData);

            /**
             * @brief Constructor creating a surface of specified pixel format and dimension with given source data.
             * This constructor can be used to create a surface effectively wrapping a given block of constant data
             * without copying the source contents.
             * @param pixelFormat The pixel format.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param sourceData The constant data block to be wrapped.
             */
            VideoSurface(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY, const ConstData& sourceData);

            /**
             * @brief Constructor creating a surface of specified pixel format and dimension with given source data.
             * This constructor can be used to create a surface effectively wrapping a given block of constant data
             * without copying the source contents, using a given line pitch.
             * @param pixelFormat The pixel format.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param bytesPerLine The line pitch in bytes.
             * @param sourceData The constant data block to be wrapped.
             */
            VideoSurface(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY, UInt32 bytesPerLine, const ConstData& sourceData);

            /**
             * @brief The destructor.
             */
            virtual ~VideoSurface();

            /**
             * @brief Implementation of IVideoSurface::Clone(IEnums::PixelFormat pixelFormat).
             * @param pixelFormat The pixel format of the new surface.
             * @return The new surface or null if conversion is not available.
             */
            virtual IVideoSurface* Clone(IEnums::PixelFormat pixelFormat) const;

            /**
             * @brief Implementation of IVideoSurface::Clone(IEnums::PixelFormat pixelFormat,
             *  const IVideoScaler* scaler = 0).
             * @param pixelSizeX The number of horizontal pixels of the new surface.
             * @param pixelSizeY The number of vertical pixels of the new surface.
             * @param scaler Pointer to a scaler object or null to scale using the BoxVideoScaler.
             * @param gamma The gamma value used during cloning.
             * @return The new surface or null if conversion is not available.
             */
            virtual IVideoSurface* Clone(UInt32 pixelSizeX, UInt32 pixelSizeY,
                                         const IVideoScaler* scaler = 0, Real gamma = 1.0f) const;

            /**
             * @brief Implementation of IVideoSurface::Clone(IEnums::PixelFormat pixelFormat,
             *  UInt32 pixelSizeX, UInt32 pixelSizeY, const IVideoScaler* scaler).
             * @param pixelFormat The pixel format of the new surface.
             * @param pixelSizeX The number of horizontal pixels of the new surface.
             * @param pixelSizeY The number of vertical pixels of the new surface.
             * @param scaler Pointer to a scaler object or null to scale using the BoxVideoScaler.
             * @param gamma The gamma value used during cloning.
             * @return The new surface or null if conversion is not available.
             */
            virtual IVideoSurface* Clone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                         const IVideoScaler* scaler = 0, Real gamma = 1.0f) const;

            /**
             * @brief Implementation of IVideoSurface::CloneRotated(IEnums::Orientation orientation).
             * @param orientation The orientation of the new surface.
             * @return The new surface or null if conversion is not available.
             */
            virtual IVideoSurface* CloneRotated(IEnums::Orientation orientation) const;

            /**
             * @brief Implementation of IVideoSurface::CloneRotated(IEnums::Orientation orientation,
             *  IEnums::PixelFormat pixelFormat).
             * @param orientation The orientation of the new surface.
             * @param pixelFormat The pixel format of the new surface.
             * @return The new surface or null if conversion is not available.
             */
            virtual IVideoSurface* CloneRotated(IEnums::Orientation orientation, IEnums::PixelFormat pixelFormat) const;

            /**
             * @brief Implementation of IVideoSurface::CloneFrame().
             * @param positionX The source x-position of the region.
             * @param positionY The source y-position of the region.
             * @param pixelSizeX The number of horizontal pixels of the region.
             * @param pixelSizeY The number of vertical pixels of the region.
             * @return The new surface with the specified region's size.
             */
            virtual IVideoSurface* CloneFrame(SInt32 positionX, SInt32 positionY,
                                              UInt32 pixelSizeX, UInt32 pixelSizeY) const;

            /**
             * @brief Implementation of IVideoSurface::GetPixelSizeX().
             * @return The number of horizontal pixels.
             */
            virtual UInt32 GetPixelSizeX() const;

            /**
             * @brief Implementation of IVideoSurface::GetPixelSizeY().
             * @return The number of vertical pixels.
             */
            virtual UInt32 GetPixelSizeY() const;

            /**
             * @brief Implementation of IVideoSurface::GetBytesPerPixel().
             * @return The number of bytes per pixel.
             */
            virtual UInt32 GetBytesPerPixel() const;

            /**
             * @brief Implementation of IVideoSurface::GetBytesPerLine().
             * @return The number of bytes per line.
             */
            virtual UInt32 GetBytesPerLine() const;

            /**
             * @brief Implementation of IVideoSurface::GetPixelFormat().
             * @return The pixel format of the surface.
             */
            virtual IEnums::PixelFormat GetPixelFormat() const;

            /**
             * @brief Implementation of IVideoSurface::GetPixels().
             * @return The data object which is holding the pixels.
             */
            virtual const ConstData& GetPixels() const;

            /**
             * @brief Implementation of IVideoSurface::GetMutablePixels().
             * @return The mutable data object which is holding the pixels.
             */
            virtual const MutableData& GetMutablePixels();

            /**
             * @brief Implementation of IVideoSurface::GetPixel().
             * @param positionX The pixel x-position.
             * @param positionY The pixel y-position.
             * @return The color of the pixel at the specified position.
             */
            virtual Color GetPixel(SInt32 positionX, SInt32 positionY) const;

            /**
             * @brief Implementation of IVideoSurface::SetPixel().
             * @param positionX The pixel x-position.
             * @param positionY The pixel y-position.
             * @param color The color of the pixel to set.
             * @return true if successful.
             */
            virtual Bool SetPixel(SInt32 positionX, SInt32 positionY, const Color& color);

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
             *  SInt32 destPositionX, SInt32 destPositionY).
             * @param source The source surface.
             * @param destPositionX The destination x-position.
             * @param destPositionY The destination y-position.
             * @return true if successful.
             */
            virtual Bool Blit(const IVideoSurface* source, SInt32 destPositionX, SInt32 destPositionY);

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
             * @brief Implementation of IVideoSurface::Clear(const Color& clearColor).
             * @param clearColor The clear color to apply.
             * @return true if successful.
             */
            virtual Bool Clear(const Color& clearColor);

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
             * @brief Implementation of IVideoSurface::GaussBlur(Real strength).
             * @param strength The blur filter strength.
             * @return true if successful.
             */
            virtual Bool GaussBlur(Real strength);

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
             * @brief Implementation of IVideoSurface::ApplyMatte(const Color& matteColor, Real matteThreshold = 0).
             * @param matteColor The matte color to apply.
             * @param matteThreshold The alpha threshold in range [0.0 .. 1.0].
             * @return true if successful.
             */
            virtual Bool ApplyMatte(const Color& matteColor, Real matteThreshold = 0);

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

            /**
             * @brief Implementation of IVideoSurface::IsColumnEmpty().
             * @param column The zero-based column.
             * @param threshold The alpha threshold in range [0.0 .. 1.0].
             * @return true if all alpha values in the column are less or equal to the threshold.
             */
            virtual Bool IsColumnEmpty(UInt32 column, Real threshold) const;

            /**
             * @brief Implementation of IVideoSurface::IsRowEmpty().
             * @param row The zero-based row.
             * @param threshold The alpha threshold in range [0.0 .. 1.0].
             * @return true if all alpha values in the row are less or equal to the threshold.
             */
            virtual Bool IsRowEmpty(UInt32 row, Real threshold) const;

            /**
             * @brief Implementation of IVideoSurface::ClipSizeXRight().
             * @param positionX The x-position.
             * @param sizeX The number of horzontal pixels.
             * @return The clipped width.
             */
            virtual SInt32 ClipSizeXRight(SInt32 positionX, SInt32 sizeX) const;

            /**
             * @brief Implementation of IVideoSurface::ClipSizeYBottom().
             * @param positionY The y-position.
             * @param sizeY The number of vertical pixels.
             * @return The clipped height.
             */
            virtual SInt32 ClipSizeYBottom(SInt32 positionY, SInt32 sizeY) const;

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

        private:
            /**
             * @brief The copy constructor.
             * Create a new surface by copying an existing surface's data.
             * @param other The source surface.
             */
            VideoSurface(const VideoSurface& other);

        protected:
            /** @brief The pixel width. */
            UInt32 mSizeX;
            /** @brief The pixel height. */
            UInt32 mSizeY;
            /** @brief The pixel format. */
            IEnums::PixelFormat mPixelFormat;
            /** @brief The number of bytes per line. */
            UInt32 mBytesPerLine;
            /** @brief The own surface data, if specified via constructor. */
            Data mData;
            /** @brief The actually visible constant surface data store. */
            ConstData mConstData;
            /** @brief The actually visible mutable surface data store, if possible. */
            MutableData mMutableData;
        };

        /** @brief The VideoSurface shared pointer type. */
        typedef SharedPointer<VideoSurface> VideoSurfacePtr;

        /** @brief The VideoSurface const shared pointer type. */
        typedef SharedPointer<VideoSurface const> VideoSurfaceCPtr;
    }
}

#endif // __MURL_UTIL_VIDEO_SURFACE_H__

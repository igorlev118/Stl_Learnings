// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_VIDEO_SURFACE_H__
#define __MURL_I_VIDEO_SURFACE_H__

#include "murl_i_enums.h"
#include "murl_color.h"
#include "murl_data.h"
#include "murl_shared_pointer.h"

namespace Murl
{
    class IFont;
    class IVideoScaler;

    /**
     * @ingroup MurlInterfaces
     * @interface IVideoSurface
     * @brief The video surface interface.
     * The video surface stores properties and pixel data of a graphic image.
     * The video surface offers cloning of surfaces of different pixel format and size,
     * copying rectangular regions from other video surfaces and applying matte colors.
     */
    class IVideoSurface
    {
    public:
        /**
         * @brief The destructor.
         */
        virtual ~IVideoSurface() {}

        /**
         * @brief Create a clone of the surface with a specified pixel format.
         * @param pixelFormat The pixel format of the new surface.
         * @return The new surface or null if conversion is not available.
         */
        virtual IVideoSurface* Clone(IEnums::PixelFormat pixelFormat) const = 0;

        /**
         * @brief Create a clone of the surface with a specified size.
         * Scaling to different size is supported for IEnums::PIXEL_FORMAT_R8_G8_B8_A8
         * and IEnums::PIXEL_FORMAT_R8_G8_B8 only.
         * @param pixelSizeX The number of horizontal pixels of the new surface.
         * @param pixelSizeY The number of vertical pixels of the new surface.
         * @param scaler Pointer to a scaler object or null to scale using the BoxVideoScaler.
         * @param gamma The gamma value used during cloning.
         * @return The new surface or null if conversion is not available.
         */
        virtual IVideoSurface* Clone(UInt32 pixelSizeX, UInt32 pixelSizeY,
                                     const IVideoScaler* scaler = 0, Real gamma = 1.0f) const = 0;

        /**
         * @brief Create a clone of the surface with a specified pixel format and size.
         * Scaling to different size is supported for IEnums::PIXEL_FORMAT_R8_G8_B8_A8
         * and IEnums::PIXEL_FORMAT_R8_G8_B8 only.
         * @param pixelFormat The pixel format of the new surface.
         * @param pixelSizeX The number of horizontal pixels of the new surface.
         * @param pixelSizeY The number of vertical pixels of the new surface.
         * @param scaler Pointer to a scaler object or null to scale using the BoxVideoScaler.
         * @param gamma The gamma value used during cloning.
         * @return The new surface or null if conversion is not available.
         */
        virtual IVideoSurface* Clone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                     const IVideoScaler* scaler = 0, Real gamma = 1.0f) const = 0;

        /**
         * @brief Create a clone of the surface with a specified orientation.
         * @param orientation The orientation of the new surface.
         * @return The new surface or null if conversion is not available.
         */
        virtual IVideoSurface* CloneRotated(IEnums::Orientation orientation) const = 0;

        /**
         * @brief Create a clone of the surface with a specified orientation and pixel format.
         * @param orientation The orientation of the new surface.
         * @param pixelFormat The pixel format of the new surface.
         * @return The new surface or null if conversion is not available.
         */
        virtual IVideoSurface* CloneRotated(IEnums::Orientation orientation, IEnums::PixelFormat pixelFormat) const = 0;

        /**
         * @brief Create a surface and copy a specified rectangular region.
         * @param positionX The source x-position of the region.
         * @param positionY The source y-position of the region.
         * @param pixelSizeX The number of horizontal pixels of the region.
         * @param pixelSizeY The number of vertical pixels of the region.
         * @return The new surface with the specified region's size.
         */
        virtual IVideoSurface* CloneFrame(SInt32 positionX, SInt32 positionY,
                                          UInt32 pixelSizeX, UInt32 pixelSizeY) const = 0;

        /**
         * @brief Get the number of horizontal pixels.
         * @return The number of horizontal pixels.
         */
        virtual UInt32 GetPixelSizeX() const = 0;

        /**
         * @brief Get the number of vertical pixels.
         * @return The number of vertical pixels.
         */
        virtual UInt32 GetPixelSizeY() const = 0;

        /**
         * @brief Get the number of bytes per line.
         * @return The number of bytes per line.
         */
        virtual UInt32 GetBytesPerLine() const = 0;

        /**
         * @brief Get the number of bytes per pixel.
         * @return The number of bytes per pixel.
         */
        virtual UInt32 GetBytesPerPixel() const = 0;

        /**
         * @brief Get the pixel format of the surface.
         * @return The pixel format of the surface.
         */
        virtual IEnums::PixelFormat GetPixelFormat() const = 0;

        /**
         * @brief Get the data object which is holding the pixels.
         * @return The data object which is holding the pixels.
         */
        virtual const ConstData& GetPixels() const = 0;

        /**
         * @brief Get the mutable data object which is holding the pixels.
         * @return The mutable data object which is holding the pixels.
         */
        virtual const MutableData& GetMutablePixels() = 0;

        /**
         * @brief Get the color of a pixel.
         * @param positionX The pixel x-position.
         * @param positionY The pixel y-position.
         * @return The color of the pixel at the specified position.
         */
        virtual Color GetPixel(SInt32 positionX, SInt32 positionY) const = 0;

        /**
         * @brief Set the color of a pixel.
         * @param positionX The pixel x-position.
         * @param positionY The pixel y-position.
         * @param color The color of the pixel to set.
         * @return true if successful.
         */
        virtual Bool SetPixel(SInt32 positionX, SInt32 positionY, const Color& color) = 0;

        /**
         * @brief Horizontally flip the surface.
         * @return true if successful.
         */
        virtual Bool FlipX() = 0;
        /**
         * @brief Vertically flip the surface.
         * @return true if successful.
         */
        virtual Bool FlipY() = 0;

        /**
         * @brief Copy a source surface to a specified position.
         * All cases of overlapping are supported.
         * @param source The source surface.
         * @param destPositionX The destination x-position.
         * @param destPositionY The destination y-position.
         * @return true if successful.
         */
        virtual Bool Blit(const IVideoSurface* source, SInt32 destPositionX, SInt32 destPositionY) = 0;

        /**
         * @brief Copy a rectangular region from a source surface to a specified position.
         * All cases of overlapping are supported.
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
                          SInt32 destPositionX, SInt32 destPositionY, UInt32 pixelSizeX, UInt32 pixelSizeY) = 0;

        /**
         * @brief Copy a source surface of different size.
         * Scaling to different size is supported for IEnums::PIXEL_FORMAT_R8_G8_B8_A8
         * and IEnums::PIXEL_FORMAT_R8_G8_B8 only.
         * @param source The source surface.
         * @param scaler Pointer to a scaler object or null to scale using the BoxVideoScaler.
         * @param gamma The gamma value used during scaling.
         * @return true if successful.
         */
        virtual Bool BlitScaled(const IVideoSurface* source, const IVideoScaler* scaler = 0, Real gamma = 1.0f) = 0;

        /**
         * @brief Clear the surface.
         * @param clearColor The clear color to apply.
         * @return true if successful.
         */
        virtual Bool Clear(const Color& clearColor) = 0;

        /**
         * @brief Clear a rectangular region of the surface.
         * @param positionX The source x-position of the region.
         * @param positionY The source y-position of the region.
         * @param pixelSizeX The number of horizontal pixels of the region.
         * @param pixelSizeY The number of vertical pixels of the region.
         * @param clearColor The clear color to apply.
         * @return true if successful.
         */
        virtual Bool Clear(SInt32 positionX, SInt32 positionY, UInt32 pixelSizeX, UInt32 pixelSizeY,
                           const Color& clearColor) = 0;

        /**
         * @brief Perform a Gauss blur operation on the surface.
         * @param strength The blur filter strength.
         * @return true if successful.
         */
        virtual Bool GaussBlur(Real strength) = 0;
        /**
         * @brief Perform a Gauss blur operation on the surface.
         * @param positionX The x-position of the region.
         * @param positionY The y-position of the region.
         * @param pixelSizeX The number of horizontal pixels of the region.
         * @param pixelSizeY The number of vertical pixels of the region.
         * @param strength The blur filter strength.
         * @return true if successful.
         */
        virtual Bool GaussBlur(SInt32 positionX, SInt32 positionY, UInt32 pixelSizeX, UInt32 pixelSizeY,
                               Real strength) = 0;

        /**
         * @brief Apply a matte color using a specified alpha threshold value.
         * The matte color's RGB values are set to all pixels which alpha values are
         * less or equal to the specified alpha threshold value.
         * Applying matte is supported for IEnums::PIXEL_FORMAT_R8_G8_B8_A8,
         * IEnums::PIXEL_FORMAT_L8_A8 and IEnums::PIXEL_FORMAT_R5_G5_B5_A1 only.
         * @param matteColor The matte color to apply.
         * @param matteThreshold The alpha threshold in range [0.0 .. 1.0].
         * @return true if successful.
         */
        virtual Bool ApplyMatte(const Color& matteColor, Real matteThreshold = 0) = 0;

        /**
         * @brief Apply a matte color to a rectangular region using a specified alpha threshold value.
         * The matte color's RGB values are set to all pixels which alpha values are
         * less or equal to the specified alpha threshold value.
         * Applying matte is supported for IEnums::PIXEL_FORMAT_R8_G8_B8_A8,
         * IEnums::PIXEL_FORMAT_L8_A8 and IEnums::PIXEL_FORMAT_R5_G5_B5_A1 only.
         * @param positionX The source x-position of the region.
         * @param positionY The source y-position of the region.
         * @param pixelSizeX The number of horizontal pixels of the region.
         * @param pixelSizeY The number of vertical pixels of the region.
         * @param matteColor The matte color to apply.
         * @param matteThreshold The alpha threshold in range [0.0 .. 1.0].
         * @return true if successful.
         */
        virtual Bool ApplyMatte(SInt32 positionX, SInt32 positionY, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                const Color& matteColor, Real matteThreshold = 0) = 0;

        /**
         * @brief Render some text into the surface using a given font.
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
                                IEnums::TextAlignmentX alignX, IEnums::TextAlignmentY alignY) = 0;

        /**
         * @brief Check if a column is empty using a specified alpha threshold value.
         * Checking is supported for IEnums::PIXEL_FORMAT_R8_G8_B8_A8
         * and IEnums::PIXEL_FORMAT_R5_G5_B5_A1 only.
         * @param column The zero-based column.
         * @param threshold The alpha threshold in range [0.0 .. 1.0].
         * @return true if all alpha values in the column are less or equal to the threshold.
         */
        virtual Bool IsColumnEmpty(UInt32 column, Real threshold) const = 0;

        /**
         * @brief Check if a row is empty using a specified alpha threshold value.
         * Checking is supported for IEnums::PIXEL_FORMAT_R8_G8_B8_A8
         * and IEnums::PIXEL_FORMAT_R5_G5_B5_A1 only.
         * @param row The zero-based row.
         * @param threshold The alpha threshold in range [0.0 .. 1.0].
         * @return true if all alpha values in the row are less or equal to the threshold.
         */
        virtual Bool IsRowEmpty(UInt32 row, Real threshold) const = 0;

        /**
         * @brief Clip the width relative to a position and the right border of the surface.
         * @param positionX The x-position.
         * @param sizeX The number of horzontal pixels.
         * @return The clipped width.
         */
        virtual SInt32 ClipSizeXRight(SInt32 positionX, SInt32 sizeX) const = 0;

        /**
         * @brief Clip the height relative to a position and the bottom border of the surface.
         * @param positionY The y-position.
         * @param sizeY The number of vertical pixels.
         * @return The clipped height.
         */
        virtual SInt32 ClipSizeYBottom(SInt32 positionY, SInt32 sizeY) const = 0;

        /**
         * @brief Evict restoreable resoures.
         * Evictable surfaces can free resources e.g. on memory low warnings.
         * These resources can be restored later by calling Restore().
         * @return true if successful.
         */
        virtual Bool Evict() = 0;

        /**
         * @brief Restore evictable resoures freed by Evict().
         * @return true if successful.
         */
        virtual Bool Restore() = 0;
    };

    /** @brief The IVideoSurface shared pointer type. */
    typedef SharedPointer<IVideoSurface> IVideoSurfacePtr;

    /** @brief The IVideoSurface const shared pointer type. */
    typedef SharedPointer<IVideoSurface const> IVideoSurfaceCPtr;
}

#endif  // __MURL_I_VIDEO_SURFACE_H__

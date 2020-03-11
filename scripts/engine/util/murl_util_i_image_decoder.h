// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_I_IMAGE_DECODER_H__
#define __MURL_UTIL_I_IMAGE_DECODER_H__

#include "murl_i_factory_object.h"
#include "murl_array.h"
#include "murl_data.h"

namespace Murl
{
    class IVideoSurface;

    namespace Util
    {
        class IFactory;

        class IImageDecoder : public IFactoryObject<IImageDecoder>
        {
        public:
            typedef IImageDecoder* (*CreateFunction)(const IFactory* factory);
            
        public:
            /**
             * @brief Decoder flags
             */
            enum Flag
            {
                /** @brief Default flags. */
                FLAG_NONE                = 0,

                /**
                 * @brief Flag to allow data wrapping.
                 * If this flag is set, the decoder is allowed to create a surface
                 * that directly wraps a sub-region of the given constant input data
                 * without having to perform any actual decoding. In this case, an
                 * immutable surface is created, and the source data must be retained
                 * until the returned surface is destroyed.
                 * If this flag is not set, or source data wrapping is not possible,
                 * a mutable surface is returned where the given data is copied or
                 * decoded to.
                 */
                FLAG_ALLOW_DATA_WRAPPING = (1 << 0),
                /**
                 * @brief Flag to force decoding with the given pixel format.
                 * If this flag is set, the decoder is forced to use the given pixel
                 * format for output and is not allowed to choose a different one.
                 * If the given format is not directly supported, decoding will fail.
                 */
                FLAG_FORCE_FORMAT        = (1 << 1),
                /**
                 * @brief Flag to decode the image to an alternative format.
                 * If this flag is set, the decoder is instructed to decode the image
                 * reinterpreting its actual pixel format as a different compatible one,
                 * The following restrictions apply:
                 * - The output pixel format must have the same bit depth as the encoded image
                 * - No conversion is applied, but it is possible to e.g. decode a L8 image to an
                 *   A8 surface by reinterpreting the pixel data. In other words, it is possible to
                 *   shuffle input components into the output surface.
                 */
                FLAG_REINTERPRET_FORMAT  = (1 << 2),
            };

            /**
             * @brief The image information structure.
             */
            class ImageInfo
            {
            public:
                /** @brief Image flags. */
                enum Flag
                {
                    FLAG_NONE       = 0,

                    FLAG_FLIPPED_X  = (1 << 0),
                    FLAG_FLIPPED_Y  = (1 << 1),
                    FLAG_PALETTIZED = (1 << 2),
                    FLAG_COMPRESSED = (1 << 3),
                    FLAG_BIG_ENDIAN = (1 << 4)
                };

                /** @brief The default constructor. */
                ImageInfo()
                : mImageFormat(IEnums::IMAGE_FORMAT_UNKNOWN)
                , mPixelFormat(IEnums::PIXEL_FORMAT_UNDEFINED)
                , mTextureType(IEnums::TEXTURE_TYPE_DEFAULT)
                , mPixelSizeX(0)
                , mPixelSizeY(0)
                , mBitsPerPixel(0)
                , mRedShift(0)
                , mGreenShift(0)
                , mBlueShift(0)
                , mAlphaShift(0)
                , mNumberOfLayers(0)
                , mNumberOfFaces(0)
                , mNumberOfStreams(0)
                , mNumberOfMipLevels(0)
                , mFlags(FLAG_NONE)
                {
                }

                /** @brief The image file format type. */
                IEnums::ImageFormat mImageFormat;

                /** @brief The native pixel format. */
                IEnums::PixelFormat mPixelFormat;
                /** @brief The texture type represented by the image. */
                IEnums::TextureType mTextureType;

                /** @brief The number of horizontal pixels. */
                UInt32 mPixelSizeX;
                /** @brief The number of vertical pixels. */
                UInt32 mPixelSizeY;

                /** @brief The numebr of bits per pixel. */
                UInt32 mBitsPerPixel;

                /** @brief The red component shift value. */
                UInt32 mRedShift;
                /** @brief The green component shift value. */
                UInt32 mGreenShift;
                /** @brief The blue component shift value. */
                UInt32 mBlueShift;
                /** @brief The alpha component shift value. */
                UInt32 mAlphaShift;

                /** @brief The number of layers (i.e. array elements). */
                UInt32 mNumberOfLayers;
                /** @brief The number of faces per layer (6 for a cubemap). */
                UInt32 mNumberOfFaces;
                /** @brief The number of individual surface streams. */
                UInt32 mNumberOfStreams;
                /** @brief The number of MIP levels per surface. */
                UInt32 mNumberOfMipLevels;

                /** @brief Flag bitfield. */
                UInt32 mFlags;

                /** @brief An array of data objects, one for each stream and MIP level. */
                Array<ConstData> mData;
            };

            virtual Bool CanDecode(const ConstData& source) const = 0;
            virtual Bool GetImageInfo(const ConstData& source, ImageInfo& info) const = 0;

            virtual IVideoSurface* Decode(const ConstData& source, UInt32 surfaceIndex, UInt32 mipLevel, UInt32 flags, IEnums::PixelFormat pixelFormat) const = 0;
            virtual IVideoSurface* Decode(const ImageInfo& info, UInt32 surfaceIndex, UInt32 mipLevel, UInt32 flags, IEnums::PixelFormat pixelFormat) const = 0;

        protected:
            virtual ~IImageDecoder() {}

            friend class Factory;
        };
    }
}

#endif // __MURL_UTIL_I_IMAGE_DECODER_H__

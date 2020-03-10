// Copyright 2012-2013 Spraylight GmbH

#ifndef __MURL_UTIL_VIDEO_SURFACE_TOOLS_H__
#define __MURL_UTIL_VIDEO_SURFACE_TOOLS_H__

#include "murl_util_i_image_decoder.h"
#include "murl_i_video_surface.h"
#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The video surface tools class.
         * The video surface tools can read and write several
         * image formats from and to IVideoSurface objects.
         */
        class VideoSurfaceTools
        {
        public:
            /**
             * @brief Check if a file has a supported image format.
             * @param fileName The file name.
             * @return true if the file exists and the image format is supported.
             */
            static Bool IsSupportedImage(const String& fileName);

            /**
             * @brief Get the image format type of a file.
             * @param fileName The file name.
             * @return The image format type or IMAGE_FORMAT_UNKNOWN
             *  if reading the file failed.
             */
            static IEnums::ImageFormat GetImageFormat(const String& fileName);

            /**
             * @brief Get the typical file extension of a specified image format.
             * @param imageFormat The image format type.
             * @return The file extension string or
             *  an empty string if the image format is unknown.
             */
            static String GetFileExtension(IEnums::ImageFormat imageFormat);

            /**
             * @brief Read an image from a file and create a video surface.
             * @param fileName The file name.
             * @param preferredPixelFormat The preferred pixel format.
             * @return The video surface or null if reading the file failed.
             */
            static IVideoSurface* ReadImageFile(const String& fileName,
                                                IEnums::PixelFormat preferredPixelFormat);

            /**
             * @brief Read an image from a file, create a video surface and
             * return the image format type.
             * @param fileName The file name.
             * @param imageInfo The image information return value.
             * @param preferredPixelFormat The preferred pixel format.
             * @return The video surface or null if reading the file failed.
             */
            static IVideoSurface* ReadImageFile(const String& fileName, IImageDecoder::ImageInfo& imageInfo,
                                                IEnums::PixelFormat preferredPixelFormat);

            /**
             * @brief Get the image information of an image from a data object.
             * @param imageData The data object containing the image.
             * @param imageInfo The image information return value.
             * @return true if successful.
             */
            static Bool GetImageInfo(const ConstData& imageData, IImageDecoder::ImageInfo& imageInfo);

            /**
             * @brief Read an image from a data object and create a video surface.
             * @param imageData The data object containing the image.
             * @param preferredPixelFormat The preferred pixel format.
             * @return The video surface or null if reading the data failed.
             */
            static IVideoSurface* ReadImage(const ConstData& imageData,
                                            IEnums::PixelFormat preferredPixelFormat);

            /**
             * @brief Read an image from a data object, create a video surface and
             * return the image information.
             * @param imageData The data object containing the image.
             * @param imageInfo The image information return value.
             * @param preferredPixelFormat The preferred pixel format.
             * @return The video surface or null if reading the data failed.
             */
            static IVideoSurface* ReadImage(const ConstData& imageData, IImageDecoder::ImageInfo& imageInfo,
                                            IEnums::PixelFormat preferredPixelFormat);

            /**
             * @brief Write a video surface to a PNG encoded file.
             * @param fileName The file name to write.
             * @param source The video surface to encode from.
             * @param compression The type of compression.
             *  Use the zlib best compression if COMPRESSION_TYPE_BEST,
             *  otherwise the png-lib default compression is used.
             * @return true if successful.
             */
            static Bool WritePngImageFile(const String& fileName, const IVideoSurface* source,
                                          IEnums::CompressionType compression);

            /**
             * @brief Write a video surface to a WEBP encoded file.
             * @param fileName The file name to write.
             * @param source The video surface to encode from.
             * @param compression The type of compression.
             * @param quality The quality of compression in range [0 .. 100]
             *  where 0 is the lowest quality and the highest compression
             *  and 100 is the highest quality and the lowest compression.
             * @return true if successful.
             */
            static Bool WriteWebpImageFile(const String& fileName, const IVideoSurface* source,
                                           IEnums::CompressionType compression, Real quality);

            /**
             * @brief Write a video surface to a JPEG encoded file.
             * @param fileName The file name to write.
             * @param source The video surface to encode from.
             * @param quality The quality of compression in range [0 .. 100]
             *  where 0 is the lowest quality and the highest compression
             *  and 100 is the highest quality and the lowest compression.
             * @return true if successful.
             */
            static Bool WriteJpgImageFile(const String& fileName, const IVideoSurface* source, Real quality);
            /**
             * @brief Write a video surface to a DDS file.
             * @param fileName The file name to write.
             * @param source The video surface to encode from.
             * @return true if successful.
             */
            static Bool WriteDdsImageFile(const String& fileName, const IVideoSurface* source);

            /**
             * @brief Create a video surface with explicit pixel format and dimensions, and decode raw data into it.
             * Source data must contain enough bytes to hold the full surface of given width, height
             * and pixel format, which can be calculated via IEnums::GetPixelFormatBytesPerSurface().
             * See IEnums::GetPixelFormatBytesPerLine() for details regarding the line pitch of an
             * uncompressed pixel format.
             * See also IEnums::GetPixelFormatCompressedBlockSizeX(), IEnums::GetPixelFormatCompressedBlockSizeY()
             * and IEnums::GetPixelFormatCompressedBytesPerBlock() for details regarding compressed
             * pixel formats.
             * @param source The data object containing the raw data.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The pixel format represented by the given data.
             * @param sizeX The horizontal size of the image in pixels.
             * @param sizeY The vertical size of the image in pixels.
             * @param pitch The line pitch (bytes per line) of the given data. Ignored for compressed formats.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeRawImage(const ConstData& source, UInt32 flags, IEnums::PixelFormat pixelFormat, UInt32 sizeX, UInt32 sizeY, UInt32 pitch);

            /**
             * @brief Check if a data object contains a PNG image.
             * @param source The data object containing the image.
             * @return true if the data object contains a PNG image.
             */
            static Bool IsPngImage(const ConstData& source);
            /**
             * @brief Get the PNG image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetPngImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a PNG image from given source data to a newly created video surface.
             * @param source The data object containing the encoded PNG image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePngImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a PNG image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePngImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a JPG image.
             * @param source The data object containing the image.
             * @return true if the data object contains a JPG image.
             */
            static Bool IsJpgImage(const ConstData& source);
            /**
             * @brief Get the JPG image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetJpgImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a JPG image from given source data to a newly created video surface.
             * @param source The data object containing the encoded JPG image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeJpgImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a JPG image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeJpgImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a WEBP image.
             * @param source The data object containing the image.
             * @return true if the data object contains a WEBP image.
             */
            static Bool IsWebpImage(const ConstData& source);
            /**
             * @brief Get the WEBP image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetWebpImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a WEBP image from given source data to a newly created video surface.
             * @param source The data object containing the encoded WEBP image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeWebpImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a WEBP image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeWebpImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a DDS image.
             * @param source The data object containing the image.
             * @return true if the data object contains a DDS image.
             */
            static Bool IsDdsImage(const ConstData& source);
            /**
             * @brief Get the DDS image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetDdsImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a DDS image from given source data to a newly created video surface.
             * @param source The data object containing the encoded DDS image.
             * @param surfaceIndex The zero-based index of the surface within the
             *   DDS image. For single-layer images, this must be 0 for 2D images or
             *   in the range [0..5] for cube maps. For array images, this must be in
             *   the range [0..N-1] for 2D images or [0..6*N-1] for cube maps, with N
             *   being the number of array layers present.
             * @param mipLevel The zero-based index into the surface's MIP chain.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeDdsImage(const ConstData& source, UInt32 surfaceIndex = 0, UInt32 mipLevel = 0, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a DDS image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param surfaceIndex The zero-based index of the surface within the
             *   DDS image. For single-layer images, this must be 0 for 2D images or
             *   in the range [0..5] for cube maps. For array images, this must be in
             *   the range [0..N-1] for 2D images or [0..6*N-1] for cube maps, with N
             *   being the number of array layers present.
             * @param mipLevel The zero-based index into the surface's MIP chain.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeDdsImage(const IImageDecoder::ImageInfo& info, UInt32 surfaceIndex = 0, UInt32 mipLevel = 0, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a KTX image.
             * @param source The data object containing the image.
             * @return true if the data object contains a KTX image.
             */
            static Bool IsKtxImage(const ConstData& source);
            /**
             * @brief Get the KTX image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetKtxImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a KTX image from given source data to a newly created video surface.
             * @param source The data object containing the encoded KTX image.
             * @param surfaceIndex The zero-based index of the surface within the
             *   KTX image. For single-layer images, this must be 0 for 2D images or
             *   in the range [0..5] for cube maps. For array images, this must be in
             *   the range [0..N-1] for 2D images or [0..6*N-1] for cube maps, with N
             *   being the number of array layers present.
             * @param mipLevel The zero-based index into the surface's MIP chain.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeKtxImage(const ConstData& source, UInt32 surfaceIndex = 0, UInt32 mipLevel = 0, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a KTX image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param surfaceIndex The zero-based index of the surface within the
             *   KTX image. For single-layer images, this must be 0 for 2D images or
             *   in the range [0..5] for cube maps. For array images, this must be in
             *   the range [0..N-1] for 2D images or [0..6*N-1] for cube maps, with N
             *   being the number of array layers present.
             * @param mipLevel The zero-based index into the surface's MIP chain.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeKtxImage(const IImageDecoder::ImageInfo& info, UInt32 surfaceIndex = 0, UInt32 mipLevel = 0, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a PVR image.
             * @param source The data object containing the image.
             * @return true if the data object contains a PVR image.
             */
            static Bool IsPvrImage(const ConstData& source);
            /**
             * @brief Get the PVR image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetPvrImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a PVR image from given source data to a newly created video surface.
             * @param source The data object containing the encoded PVR image.
             * @param surfaceIndex The zero-based index of the surface within the
             *   PVR image. For single-layer images, this must be 0 for 2D images or
             *   in the range [0..5] for cube maps. For array images, this must be in
             *   the range [0..N-1] for 2D images or [0..6*N-1] for cube maps, with N
             *   being the number of array layers present.
             * @param mipLevel The zero-based index into the surface's MIP chain.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePvrImage(const ConstData& source, UInt32 surfaceIndex = 0, UInt32 mipLevel = 0, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a PVR image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param surfaceIndex The zero-based index of the surface within the
             *   PVR image. For single-layer images, this must be 0 for 2D images or
             *   in the range [0..5] for cube maps. For array images, this must be in
             *   the range [0..N-1] for 2D images or [0..6*N-1] for cube maps, with N
             *   being the number of array layers present.
             * @param mipLevel The zero-based index into the surface's MIP chain.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePvrImage(const IImageDecoder::ImageInfo& info, UInt32 surfaceIndex = 0, UInt32 mipLevel = 0, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a PKM image.
             * @param source The data object containing the image.
             * @return true if the data object contains a PKM image.
             */
            static Bool IsPkmImage(const ConstData& source);
            /**
             * @brief Get the PKM image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetPkmImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a PKM image from given source data to a newly created video surface.
             * @param source The data object containing the encoded PKM image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePkmImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a PVR image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePkmImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains an ASTC image.
             * @param source The data object containing the image.
             * @return true if the data object contains an ASTC image.
             */
            static Bool IsAstcImage(const ConstData& source);
            /**
             * @brief Get the ASTC image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetAstcImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode an ASTC image from given source data to a newly created video surface.
             * @param source The data object containing the encoded ASTC image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeAstcImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a PVR image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeAstcImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a TGA image.
             * @param source The data object containing the image.
             * @return true if the data object contains a TGA image.
             */
            static Bool IsTgaImage(const ConstData& source);
            /**
             * @brief Get the TGA image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetTgaImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a TGA image from given source data to a newly created video surface.
             * @param source The data object containing the encoded TGA image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeTgaImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a TGA image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeTgaImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains an HDR image.
             * @param source The data object containing the image.
             * @return true if the data object contains an HDR image.
             */
            static Bool IsHdrImage(const ConstData& source);
            /**
             * @brief Get the HDR image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetHdrImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode an HDR image from given source data to a newly created video surface.
             * @param source The data object containing the encoded HDR image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeHdrImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode an HDR image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodeHdrImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Check if a data object contains a PFM image.
             * @param source The data object containing the image.
             * @return true if the data object contains a PFM image.
             */
            static Bool IsPfmImage(const ConstData& source);
            /**
             * @brief Get the PFM image information.
             * @param source The data object containing the image.
             * @param info The image information structure return value.
             * @return true if information structure is valid.
             */
            static Bool GetPfmImageInfo(const ConstData& source, IImageDecoder::ImageInfo& info);
            /**
             * @brief Decode a PFM image from given source data to a newly created video surface.
             * @param source The data object containing the encoded PFM image.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePfmImage(const ConstData& source, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);
            /**
             * @brief Decode a PFM image from a given image info structure to a newly created video surface.
             * @param info The image info structure.
             * @param flags A bitfield of decoder flags from the DecoderFlag enumeration.
             * @param pixelFormat The desired output pixel format.
             * @return The video surface or null if decoding failed.
             */
            static IVideoSurface* DecodePfmImage(const IImageDecoder::ImageInfo& info, UInt32 flags = 0, IEnums::PixelFormat pixelFormat = IEnums::PIXEL_FORMAT_UNDEFINED);

            /**
             * @brief Encode a video surface to a data object.
             * @param imageFormat The image format to encode.
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param compression The type of compression.
             * @param quality The quality of compression in range [0 .. 100]
             *  where 0 represents lowest quality and highest compression
             *  and 100 represents highest quality and lowest compression.
             * @return true if successful.
             */
            static Bool EncodeImage(IEnums::ImageFormat imageFormat, Data& destination, const IVideoSurface* source,
                                    IEnums::CompressionType compression, Real quality);
            /**
             * @brief Encode a video surface to a PNG data object.
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param compression The type of compression.
             *  Use the zlib best compression if COMPRESSION_TYPE_BEST,
             *  otherwise the png-lib default compression is used.
             * @return true if successful.
             */
            static Bool EncodePngImage(Data& destination, const IVideoSurface* source,
                                       IEnums::CompressionType compression);
            /**
             * @brief Encode a video surface to a WEBP data object.
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param compression The type of compression.
             * @param quality The quality of compression in range [0 .. 100]
             *  where 0 is the lowest quality and the highest compression
             *  and 100 is the highest quality and the lowest compression.
             * @return true if successful.
             */
            static Bool EncodeWebpImage(Data& destination, const IVideoSurface* source,
                                        IEnums::CompressionType compression, Real quality);
            /**
             * @brief Encode a video surface to a JPEG data object.
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param quality The quality of compression in range [0 .. 100]
             *  where 0 is the lowest quality and the highest compression
             *  and 100 is the highest quality and the lowest compression.
             * @return true if successful.
             */
            static Bool EncodeJpgImage(Data& destination, const IVideoSurface* source, Real quality);
            /**
             * @brief Encode a video surface to a DDS data object.
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @return true if successful.
             */
            static Bool EncodeDdsImage(Data& destination, const IVideoSurface* source);
            /**
             * @brief Encode a video surface to a raw data object.
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @return true if successful.
             */
            static Bool EncodeRawImage(Data& destination, const IVideoSurface* source);

            /**
             * @brief Encode a video surface to a data object, using an explicit image pixel format.
             * This method tries to encode a given surface as an image of a given type, possibly
             * shuffling the source surface's color components so that they can be stored in one
             * of the image format's actually supported storage pixel format.
             * Use GetPixelFormatToEncodeImage() to query necessary values for a given pixel format.
             * The given surface must match the surfacePixelFormat retrieved from that method.
             * @param imageFormat The image format to encode.
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param pixelFormat The actual image pixel format, retrieved from GetPixelFormatToEncodeImage().
             * @param components The color component indices, retrieved from GetPixelFormatToEncodeImage().
             * @param compression The type of compression.
             * @param quality The quality of compression in range [0 .. 100]
             *  where 0 represents lowest quality and highest compression
             *  and 100 represents highest quality and lowest compression.
             * @return true if successful.
             */
            static Bool EncodeImageAs(IEnums::ImageFormat imageFormat, Data& destination, const IVideoSurface* source,
                                      IEnums::PixelFormat pixelFormat, const SInt32 components[4],
                                      IEnums::CompressionType compression, Real quality);
            /**
             * @brief Encode a video surface to a PNG data object, using an explicit image pixel format.
             * See EncodeImageAs().
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param pixelFormat The actual image pixel format, retrieved from GetPixelFormatToEncodePngImage().
             * @param components The color component indices, retrieved from GetPixelFormatToEncodePngImage().
             * @param compression The type of compression.
             * @return true if successful.
             */
            static Bool EncodePngImageAs(Data& destination, const IVideoSurface* source,
                                         IEnums::PixelFormat pixelFormat, const SInt32 components[4],
                                         IEnums::CompressionType compression);
            /**
             * @brief Encode a video surface to a WEBP data object, using an explicit image pixel format.
             * See EncodeImageAs().
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param pixelFormat The actual image pixel format, retrieved from GetPixelFormatToEncodeWebpImage().
             * @param components The color component indices, retrieved from GetPixelFormatToEncodeWebpImage().
             * @param compression The type of compression.
             * @param quality The quality of compression.
             * @return true if successful.
             */
            static Bool EncodeWebpImageAs(Data& destination, const IVideoSurface* source,
                                          IEnums::PixelFormat pixelFormat, const SInt32 components[4],
                                          IEnums::CompressionType compression, Real quality);
            /**
             * @brief Encode a video surface to a JPG data object, using an explicit image pixel format.
             * See EncodeImageAs().
             * @param destination The data object to write into.
             * @param source The video surface to encode from.
             * @param pixelFormat The actual image pixel format, retrieved from GetPixelFormatToEncodeJpgImage().
             * @param components The color component indices, retrieved from GetPixelFormatToEncodeJpgImage().
             * @param quality The quality of compression.
             * @return true if successful.
             */
            static Bool EncodeJpgImageAs(Data& destination, const IVideoSurface* source,
                                         IEnums::PixelFormat pixelFormat, const SInt32 components[4],
                                         Real quality);

            /**
             * @brief For a given output image format and desired pixel format to encode,
             * get the best matching pixel format an image of the given type can store,
             * and get the pixel format needed for a surface to be correctly encoded.
             * @param outputImageFormat The image format for which to query the formats.
             * @param outputPixelFormat The desired pixel format of the color values to encode.
             * @param surfacePixelFormat A reference receiving the pixel format needed to create
             *  a surface to be encoded.
             * @param imagePixelFormat The actual pixel format to encode.
             * @param imageComponents An array of 4 integers receiving the component indices
             *  into the surface that are encoded.
             * @return true if successful.
             */
            static Bool GetPixelFormatToEncodeImage(IEnums::ImageFormat outputImageFormat, IEnums::PixelFormat outputPixelFormat, IEnums::PixelFormat& surfacePixelFormat, IEnums::PixelFormat& imagePixelFormat, SInt32 imageComponents[4]);
            /**
             * @brief Get the best matching pixel formats to encode a PNG image.
             * See GetPixelFormatToEncodeImage().
             * @param outputPixelFormat The desired pixel format of the color values to encode.
             * @param surfacePixelFormat A reference receiving the pixel format needed to create
             *  a surface to be encoded.
             * @param imagePixelFormat The actual pixel format to encode.
             * @param imageComponents An array of 4 integers receiving the component indices
             *  into the surface that are encoded.
             * @return true if successful.
             */
            static Bool GetPixelFormatToEncodePngImage(IEnums::PixelFormat outputPixelFormat, IEnums::PixelFormat& surfacePixelFormat, IEnums::PixelFormat& imagePixelFormat, SInt32 imageComponents[4]);
            /**
             * @brief Get the best matching pixel formats to encode a WEBP image.
             * See GetPixelFormatToEncodeImage().
             * @param outputPixelFormat The desired pixel format of the color values to encode.
             * @param surfacePixelFormat A reference receiving the pixel format needed to create
             *  a surface to be encoded.
             * @param imagePixelFormat The actual pixel format to encode.
             * @param imageComponents An array of 4 integers receiving the component indices
             *  into the surface that are encoded.
             * @return true if successful.
             */
            static Bool GetPixelFormatToEncodeWebpImage(IEnums::PixelFormat outputPixelFormat, IEnums::PixelFormat& surfacePixelFormat, IEnums::PixelFormat& imagePixelFormat, SInt32 imageComponents[4]);
            /**
             * @brief Get the best matching pixel formats to encode a JPG image.
             * See GetPixelFormatToEncodeImage().
             * @param outputPixelFormat The desired pixel format of the color values to encode.
             * @param surfacePixelFormat A reference receiving the pixel format needed to create
             *  a surface to be encoded.
             * @param imagePixelFormat The actual pixel format to encode.
             * @param imageComponents An array of 4 integers receiving the component indices
             *  into the surface that are encoded.
             * @return true if successful.
             */
            static Bool GetPixelFormatToEncodeJpgImage(IEnums::PixelFormat outputPixelFormat, IEnums::PixelFormat& surfacePixelFormat, IEnums::PixelFormat& imagePixelFormat, SInt32 imageComponents[4]);
        };
    }
}

#endif // __MURL_UTIL_VIDEO_SURFACE_TOOLS_H__

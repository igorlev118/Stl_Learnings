// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_IMAGE_H__
#define __MURL_RESOURCE_I_IMAGE_H__

#include "murl_util_iff.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IVideoStream;
    
    namespace Resource
    {
        class IObject;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IImage
         * @brief The IImage resource object interface.
         * An image resource holds a (possibly compressed) bitmap image in one of the available
         * image formats, such as PNG, JPG etc.
         */
        class IImage
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as an image.
                    FOURCC = 'IMGS',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native image resource.
                 */
                struct HeaderChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a HeaderChunk.
                        FOURCC = 'HEAD'
                    };

                    /// The actual resource version.
                    UInt32 mVersion;

                    /// The image's horizontal size in pixels, at the base MIP level.
                    UInt32 mPixelSizeX;
                    /// The image's vertical size in pixels, at the base MIP level.
                    UInt32 mPixelSizeY;

                    /// The number of individual streams.
                    UInt32 mNumberOfStreams;
                    /// The number of MIP levels.
                    UInt32 mNumberOfMipLevels;

                    /// The texture type represented by this image, maps to the IEnums::TextureType enumeration.
                    UInt32 mTextureType;
                    /// The image's desired output pixel format, from the IEnums::PixelFormat enumeration.
                    UInt32 mPixelFormat;
                };

                /**
                 * @struct StreamChunk
                 * @brief An IFF chunk containing a single image data stream.
                 * Regular 2D images only have a single image stream chunk. Cube map images store
                 * six stream chunks, and 2D arrays and 3D images store an arbitrary number of
                 * chunks, depending on their array size / Z dimension.
                 */
                struct StreamChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a StreamChunk.
                        FOURCC = 'STRM'
                    };

                    /// The actual MIP level (0 equals the base level).
                    UInt32 mStreamIndex;

                    /// The horizontal size of the base level image in pixels.
                    UInt32 mPixelSizeX;
                    /// The vertical size of the base level image in pixels.
                    UInt32 mPixelSizeY;

                    /// The image's native pixel format, from the IEnums::PixelFormat enumeration.
                    UInt32 mNativePixelFormat;
                    /// The image's binary pixel format, from the IEnums::PixelFormat enumeration.
                    UInt32 mBinaryPixelFormat;
                    /// The video stream format, from the IEnums::VideoStreamFormat enumeration.
                    UInt32 mVideoStreamFormat;

                    /// An offset into the chunk where the stream's MIP level chunks are stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The size in bytes of the MIP level chunk data.
                    UInt32 mDataByteSize;
                };

                /**
                 * @struct MipLevelChunk
                 * @brief An IFF chunk containing the actual image data for a specific MIP level.
                 * A native image must at least contain one MIP level chunk within each of its stream
                 * chunks representing the (unscaled) base level.
                 */
                struct MipLevelChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a MipLevelChunk.
                        FOURCC = 'MLEV'
                    };

                    /// The actual MIP level (0 equals the base level).
                    UInt32 mMipLevel;

                    /// The horizontal size of the image at the given MIP level in pixels.
                    UInt32 mPixelSizeX;
                    /// The vertical size of the image at the given MIP level in pixels.
                    UInt32 mPixelSizeY;
                    /// The line pitch in bytes.
                    UInt32 mBytesPerLine;
                    
                    /// An offset into the chunk where the image data is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The total size in bytes of the contained image data.
                    UInt32 mDataByteSize;
                };
            };
            
            /**
             * @brief Get the mutable Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Get the texture type represented by the image.
             * @return The texture type.
             */
            virtual IEnums::TextureType GetTextureType() const = 0;

            /**
             * @brief Get the number of individual image streams.
             * @return The number of streams.
             */
            virtual UInt32 GetNumberOfStreams() const = 0;
            /**
             * @brief Get the number of image layers.
             * For non-array images, this always returns 1.
             * @return The number of layers.
             */
            virtual UInt32 GetNumberOfLayers() const = 0;
            /**
             * @brief Get the number of image faces.
             * For flat images or arrays, this always returns 1.
             * For cubemap images or arrays, this returns 6.
             * @return The number of faces.
             */
            virtual UInt32 GetNumberOfFaces() const = 0;
            /**
             * @brief Get the stream index for a given layer and face index.
             * @param layerIndex The layer index, from 0 to GetNumberOfLayers()-1.
             * @param faceIndex The face index, from 0 to GetNumberOfFaces()-1.
             * @return The stream index from 0 to GetNumberOfStreams()-1, or -1 if
             *  any of the given parameters is out of range.
             */
            virtual SInt32 GetStreamIndex(UInt32 layerIndex, UInt32 faceIndex) const = 0;

            /**
             * @brief Get the number of actual MIP levels stored in the image resource.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The number of MIP levels.
             */
            virtual UInt32 GetNumberOfMipLevels(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the image's horizontal size in pixels, at the base MIP level.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The horizontal size.
             */
            virtual UInt32 GetPixelSizeX(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the image's vertical size in pixels, at the base MIP level.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The vertical size.
             */
            virtual UInt32 GetPixelSizeY(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the image's native pixel format.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The native pixel format.
             */
            virtual IEnums::PixelFormat GetNativePixelFormat(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the image's preferred pixel format.
             * If the given image has no actual preference for the format used, this method returns
             * IEnums::PIXEL_FORMAT_UNDEFINED. Otherwise, a specific format is returned.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The preferred pixel format.
             */
            virtual IEnums::PixelFormat GetPreferredPixelFormat(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the image's forced pixel format, when no conversion is available.
             * If a pixel format converter is available that can convert the image's native format
             * to some other format, this method should return IEnums::PIXEL_FORMAT_UNDEFINED.
             * Otherwise, a specific format is returned. This is usually the case for images
             * using some compressed format like ETC1, PVRTC or similar.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The forced pixel format.
             */
            virtual IEnums::PixelFormat GetForcedPixelFormat(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the image's actual format.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The stream format.
             */
            virtual IEnums::VideoStreamFormat GetVideoStreamFormat(UInt32 streamIndex) const = 0;
            
            /**
             * @brief Create an IVideoStream object from the resource, with default pixel format and size.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @param mipMapGen The MIP map generation mode.
             * @return The newly created stream object, or null if failed.
             */
            virtual IVideoStream* CreateStream(UInt32 streamIndex, IEnums::MipMapGenerationMode mipMapGen) const = 0;
            /**
             * @brief Create an IVideoStream object from the resource, with custom pixel format and size.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @param pixelFormat The desired pixel format.
             * @param pixelSizeX The horizontal size of the stream in pixels, at the base MIP level.
             * @param pixelSizeY The vertical size of the stream in pixels, at the base MIP level.
             * @param divisor An optional power-of-two prescale factor (use 1 for a 1:1 image).
             * @param mipMapGen The MIP map generation mode.
             * @return The newly created stream object, or null if failed.
             */
            virtual IVideoStream* CreateStream(UInt32 streamIndex, IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY, UInt32 divisor, IEnums::MipMapGenerationMode mipMapGen) const = 0;

            /**
             * @brief Create a default binary encoded image.
             * @param data The Data object to receive the encoded image.
             * @return true if successful.
             */
            virtual Bool CreateDefaultBinary(Data& data) const = 0;
            /**
             * @brief Create a binary encoded image, explicit stream and pixel formats and size.
             * @param data The Data object to receive the encoded image.
             * @param streamFormat The stream format to use.
             * @param pixelFormat The pixel format to use.
             * @param sizeX The width in pixels, or 0 to encode the image using its original width.
             * @param sizeY The height in pixels, or 0 to encode the image using its original height.
             * @return true if successful.
             */
            virtual Bool CreateBinary(Data& data, IEnums::VideoStreamFormat streamFormat, IEnums::PixelFormat pixelFormat, UInt32 sizeX, UInt32 sizeY) const = 0;
            
        protected:
            virtual ~IImage() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_IMAGE_H__

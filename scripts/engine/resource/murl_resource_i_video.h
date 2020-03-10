// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_VIDEO_H__
#define __MURL_RESOURCE_I_VIDEO_H__

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
         * @interface IVideo
         * @brief The IVideo resource object interface.
         */
        class IVideo
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as a video resource.
                    FOURCC = 'VDEO',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native video resource.
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
                };

                /**
                 * @struct DataChunk
                 * @brief An IFF chunk containing the actual video stream data.
                 */
                struct DataChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a DataChunk.
                        FOURCC = 'DATA'
                    };

                    /// The total size in bytes of the contained stream data.
                    UInt32 mByteSize;
                    /// An offset into the chunk where the stream data is stored. See IffOffset().
                    UInt32 mDataOffset;

                    /// A hash value of the stream contents.
                    UInt8 mHash[16];
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
             * @brief Get the number of individual video streams.
             * @return The number of streams.
             */
            virtual UInt32 GetNumberOfStreams() const = 0;

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

        protected:
            virtual ~IVideo() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_VIDEO_H__

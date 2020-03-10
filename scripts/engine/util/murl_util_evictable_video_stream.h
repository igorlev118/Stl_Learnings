// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_EVICTABLE_VIDEO_STREAM_H__
#define __MURL_UTIL_EVICTABLE_VIDEO_STREAM_H__

#include "murl_util_video_stream.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The evictable video stream class, see IVideoStream.
         */
        class EvictableVideoStream : public VideoStream
        {
        public:
            /**
             * @brief The constructor.
             * Creates a video stream with spcified pixel format and dimension.
             * @param outputFormat The pixel format of the new video object.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param mipMapGen Specifies if and how mip maps are generated.
             */
            EvictableVideoStream(IEnums::PixelFormat outputFormat, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                 IEnums::MipMapGenerationMode mipMapGen);

            /**
             * @brief The destructor.
             */
            virtual ~EvictableVideoStream();

            /**
             * @brief Release decoded surface data.
             * Calls IVideoSurface::Evict() on all mip-level surfaces.
             * @return true if successful.
             */
            virtual Bool ReleaseDecodedData();

        protected:
            /**
             * @brief Create or restore surface data for a specified mip level.
             * Calls IVideoSurface::Restore() if the surface exists,
             * otherwise a new surface is created.
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @return true if successful.
             */
            virtual Bool AcquireMipLevelSurface(UInt32 mipLevel);
        };
    }
}

#endif  // __MURL_UTIL_EVICTABLE_VIDEO_STREAM_H__

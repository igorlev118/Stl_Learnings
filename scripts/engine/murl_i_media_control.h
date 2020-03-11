// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_MEDIA_CONTROL_H__
#define __MURL_I_MEDIA_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_i_enums.h"
#include "murl_data.h"

namespace Murl
{
    class IMovie;
    class IVideoStream;

    /**
     * @ingroup MurlControlInterfaces
     * @interface IMediaControl
     * @brief The IMediaControl interface.
     */
    class IMediaControl : public IControlable
    {
    public:
        /**
         * @brief Create a video stream from a media resource.
         * @param id The resource ID.
         * @param data The resource data.
         * @param videoTrackIndex The zero-based index of the video track in the resource.
         * @return A new video stream, or null if failed.
         */
        virtual IVideoStream* CreateVideoStream(const String& id, const ConstData& data, UInt32 videoTrackIndex) = 0;

        /**
         * @brief Create a video stream from a media resource.
         * @param id The resource ID.
         * @param data The resource data.
         * @param videoTrackIndex The zero-based index of the video track in the resource.
         * @param pixelFormat The desired output pixel format.
         * @param pixelSizeX The desired horizontal size of the stream in pixels.
         * @param pixelSizeY The desired vertical size of the stream in pixels.
         * @return A new video stream, or null if failed.
         */
        virtual IVideoStream* CreateVideoStream(const String& id, const ConstData& data, UInt32 videoTrackIndex,
                                                IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY) = 0;

    protected:
        virtual ~IMediaControl() {}
    };
}

#endif  // __MURL_I_MEDIA_CONTROL_H__

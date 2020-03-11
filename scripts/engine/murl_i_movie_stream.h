// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_MOVIE_STREAM_H__
#define __MURL_I_MOVIE_STREAM_H__

#include "murl_i_enums.h"

namespace Murl
{
    class IAudioStream;
    class IVideoStream;

    /**
     * @ingroup MurlInterfaces
     * @interface IMovieStream
     * @brief The movie stream interface.
     */
    class IMovieStream
    {
    public:
        /**
         * @brief The destructor.
         */
        virtual ~IMovieStream() {}

        /**
         * @brief Create a clone of the movie stream object.
         * @return The new stream object.
         */
        virtual IMovieStream* Clone() const = 0;

        /**
         * @brief Get the movie's video stream object.
         * @return The video stream object.
         */
        virtual IVideoStream* GetVideoStream() = 0;

        /**
         * @brief Get the movie's audio stream object.
         * @return The audio stream object.
         */
        virtual IAudioStream* GetAudioStream() = 0;
    };
}

#endif  // __MURL_I_MOVIE_STREAM_H__

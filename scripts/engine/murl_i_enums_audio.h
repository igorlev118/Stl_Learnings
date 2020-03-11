// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_ENUMS_AUDIO_H__
#define __MURL_I_ENUMS_AUDIO_H__

#include "murl_enum.h"

namespace Murl
{
    namespace IEnums
    {
        /**
         * @addtogroup MurlAudioEnumerations
         * @brief Audio items enumerations.
         * @{
         */

        /**
         * @brief Available audio session categories.
         */
        enum AudioSessionCategory
        {
            /// The default category, no audio session category is applied.
            MURL_DECLARE_ENUM_VALUE(AUDIO_SESSION_CATEGORY, DEFAULT)
            /// The solo ambient category, silences other audio.
            MURL_DECLARE_ENUM_VALUE(AUDIO_SESSION_CATEGORY, SOLO_AMBIENT)
            /// The mix ambient category, mixes other audio.
            MURL_DECLARE_ENUM_VALUE(AUDIO_SESSION_CATEGORY, MIX_AMBIENT)
            /// The mix ambient category, mixes if another audio is playing at app start.
            MURL_DECLARE_ENUM_VALUE(AUDIO_SESSION_CATEGORY, MIX_AMBIENT_IF_PLAYING)
            /// The playback category, audio continues playing if app is in background.
            MURL_DECLARE_ENUM_VALUE(AUDIO_SESSION_CATEGORY, PLAYBACK)
        };

        /**
         * @brief Available sample formats for sound playback.
         */
        enum SampleFormat
        {
            /// The default sample format specified in a sound resource.
            MURL_DECLARE_ENUM_VALUE(SAMPLE_FORMAT, DEFAULT)

            /// 8bit mono (1 Byte per sample)
            MURL_DECLARE_ENUM_VALUE(SAMPLE_FORMAT, MONO_8_BIT)
            /// 16bit mono (2 Bytes per sample)
            MURL_DECLARE_ENUM_VALUE(SAMPLE_FORMAT, MONO_16_BIT)
            /// 8bit stereo (2 Bytes per sample)
            MURL_DECLARE_ENUM_VALUE(SAMPLE_FORMAT, STEREO_8_BIT)
            /// 16bit stereo (4 Bytes per sample)
            MURL_DECLARE_ENUM_VALUE(SAMPLE_FORMAT, STEREO_16_BIT)

            NUM_SAMPLE_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(SampleFormat)

        /**
         * @brief Query the number of bytes per sample for a given sample format.
         * @param sampleFormat The sample format to query.
         * @return The number of bytes per sample.
         */
        UInt32 GetSampleFormatByteSize(SampleFormat sampleFormat);

        /**
         * @brief Available audio stream formats.
         */
        enum AudioStreamFormat
        {
            /// The default compression
            MURL_DECLARE_ENUM_VALUE(AUDIO_STREAM_FORMAT, DEFAULT)

            /// No compression, i.e. raw sample values.
            MURL_DECLARE_ENUM_VALUE(AUDIO_STREAM_FORMAT, RAW)
            /// Ogg Vorbis compression.
            MURL_DECLARE_ENUM_VALUE(AUDIO_STREAM_FORMAT, VORBIS)

            NUM_AUDIO_STREAM_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(AudioStreamFormat)

        /**
         * @brief Available distance models for audio volume attenuation.
         * See Graph::IListener for a detailed description.
         */
        enum DistanceModel
        {
            /// Inverse distance model.
            MURL_DECLARE_ENUM_VALUE(DISTANCE_MODEL, INVERSE)
            /// Inverse clamped distance model.
            MURL_DECLARE_ENUM_VALUE(DISTANCE_MODEL, INVERSE_CLAMPED)
            /// Linear distance model.
            MURL_DECLARE_ENUM_VALUE(DISTANCE_MODEL, LINEAR)
            /// Linear clamped distance model.
            MURL_DECLARE_ENUM_VALUE(DISTANCE_MODEL, LINEAR_CLAMPED)
            /// Exponential distance model.
            MURL_DECLARE_ENUM_VALUE(DISTANCE_MODEL, EXPONENT)
            /// Exponential clamped distance model.
            MURL_DECLARE_ENUM_VALUE(DISTANCE_MODEL, EXPONENT_CLAMPED)

            NUM_DISTANCE_MODELS
        };
        MURL_DECLARE_ENUM_ACCESSOR(DistanceModel)
        
        /** @} */
    }
}

#endif  // __MURL_I_ENUMS_AUDIO_H__

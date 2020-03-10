// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_AUDIO_H__
#define __MURL_RESOURCE_I_AUDIO_H__

#include "murl_util_iff.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAudioStream;
    
    namespace Resource
    {
        class IObject;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IAudio
         * @brief The IAudio resource object interface.
         */
        class IAudio
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as an audio resource.
                    FOURCC = 'SNDS',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native audio resource.
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

                    /// The total number of samples in the audio stream.
                    UInt32 mNumberOfSamples;
                    /// The sample rate in Hertz.
                    UInt32 mSampleRate;
                    /// The native sample format, from the IEnums::SampleFormat enumeration.
                    UInt32 mSampleFormat;
                    /// The audio stream format, from the IEnums::AudioStreamFormat enumeration.
                    UInt32 mAudioStreamFormat;
                };

                /**
                 * @struct DataChunk
                 * @brief An IFF chunk containing the actual audio stream data.
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
             * @brief Get the number of individual audio streams.
             * @return The number of streams.
             */
            virtual UInt32 GetNumberOfStreams() const = 0;

            /**
             * @brief Get the audio stream's sample rate.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The sample rate in Hertz.
             */
            virtual UInt32 GetSampleRate(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the audio stream's total number of samples.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The number of samples.
             */
            virtual UInt32 GetNumberOfSamples(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the audio stream's original (preferred) sample format.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The sample format.
             */
            virtual IEnums::SampleFormat GetSampleFormat(UInt32 streamIndex) const = 0;
            /**
             * @brief Get the audio stream's actual format.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The stream format.
             */
            virtual IEnums::AudioStreamFormat GetAudioStreamFormat(UInt32 streamIndex) const = 0;
            
            /**
             * @brief Create an IAudioStream object from the resource, with default sample format.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @return The newly created stream object, or null if failed.
             */
            virtual IAudioStream* CreateStream(UInt32 streamIndex) const = 0;
            /**
             * @brief Create an IAudioStream object from the resource, with given sample format.
             * @param streamIndex The index of the stream, from 0 to GetNumberOfStreams()-1.
             * @param sampleFormat The desired output sample format.
             * @return The newly created stream object, or null if failed.
             */
            virtual IAudioStream* CreateStream(UInt32 streamIndex, IEnums::SampleFormat sampleFormat) const = 0;

        protected:
            virtual ~IAudio() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_AUDIO_H__

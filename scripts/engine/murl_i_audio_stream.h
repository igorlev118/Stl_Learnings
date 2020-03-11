// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_AUDIO_STREAM_H__
#define __MURL_I_AUDIO_STREAM_H__

#include "murl_i_enums.h"
#include "murl_data.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IAudioStream
     * @brief The audio stream interface.
     */
    class IAudioStream
    {
    public:
        /**
         * @brief The destructor.
         */
        virtual ~IAudioStream() {}
        
        /**
         * @brief Create a clone of the audio stream object.
         * @return The new audio stream object.
         */
        virtual IAudioStream* Clone() const = 0;
        /**
         * @brief Create a clone of the audio with a specified sample format.
         * @param sampleFormat The sample format of the new audio object.
         * @return The new audio stream object or null if conversion is not available.
         */
        virtual IAudioStream* Clone(IEnums::SampleFormat sampleFormat) const = 0;
        
        /**
         * @brief Get the total number of decoded samples in the stream.
         * @return The number of samples.
         */
        virtual UInt32 GetNumberOfSamples() const = 0;
        /**
         * @brief Get the index of the sample at a given start time.
         * @param startTime The sample start time in seconds.
         * @return The sample index.
         */
        virtual UInt32 GetSampleIndex(Double startTime) const = 0;
        /**
         * @brief Get the start time of a sample at a given index.
         * @param sampleIndex The index of the sample to query.
         * @return The sample's start time.
         */
        virtual Double GetStartTime(UInt32 sampleIndex) const = 0;

        /**
         * @brief Get the sample rate, i.e. the number of samples per second
         * @return The number of samples per second.
         */
        virtual Double GetSampleRate() const = 0;
        /**
         * @brief Get the duration of a single sample, i.e. the inverse sample rate.
         * @return The sample duration in seconds.
         */
        virtual Double GetSampleDuration() const = 0;
        /**
         * @brief Get the total duration of the stream, in seconds.
         * @return The total duration.
         */
        virtual Double GetTotalDuration() const = 0;

        /**
         * @brief Get the sample format.
         * @return The sample format.
         */
        virtual IEnums::SampleFormat GetSampleFormat() const = 0;
        /**
         * @brief Get the number of bytes per sample.
         * @return The number of bytes per sample.
         */
        virtual UInt32 GetBytesPerSample() const = 0;
        /**
         * @brief Get the total number of bytes for the fully decoded stream.
         * @return The number of bytes.
         */
        virtual UInt32 GetNumberOfBytes() const = 0;

        /**
         * @brief Check if the stream is ready to be decoded.
         * @return true if ready.
         */
        virtual Bool IsReadyForDecoding() const = 0;

        /**
         * @brief Start decoding the stream.
         * Has to be called before Decode().
         * @return true if successful.
         */
        virtual Bool StartDecoding() = 0;
        /**
         * @brief End decoding the stream.
         * Has to be called after Decode().
         * @return true if successful.
         */
        virtual Bool EndDecoding() = 0;
        /**
         * @brief Decode the stream.
         * StartDecoding() has to be called before, see also EndDecoding().
         * @param dstBuffer The destination data.
         * @param dstFormat The destination sample format.
         * @param firstSample The sample number to start from.
         * @param numSamples The number of samples to decode.
         * @return The number of decoded samples.
         */
        virtual UInt32 Decode(Data& dstBuffer, IEnums::SampleFormat dstFormat, UInt32 firstSample, UInt32 numSamples) = 0;
        
        /**
         * @brief Set the stream's current access mode.
         * This serves as a hint to a possible underlying stream decoder, to be able to
         * do optimal decoding whether single sample access or a continuous sequence of
         * audio data is desired.
         * @param mode The access mode to apply.
         * @return true if successful.
         */
        virtual Bool SetCurrentMode(IEnums::StreamMode mode) = 0;
        /**
         * @brief Get the stream's current access mode.
         * @return The current access mode.
         */
        virtual const IEnums::StreamMode GetCurrentMode() const = 0;

        /**
         * @brief Set the current time offset for subsequent PrepareDecodedData() calls.
         * @param timeOffset The time offset in seconds.
         * @return true if successful.
         */
        virtual Bool SetCurrentTimeOffset(Double timeOffset) = 0;
        /**
         * @brief Get the current time offset.
         * @return The time offset in seconds.
         */
        virtual Double GetCurrentTimeOffset() const = 0;

        /**
         * @brief Prepare decoded data, creating the underlying sample storage if needed.
         * Decode the entire stream, see GetDecodedData().
         * @return true if successful.
         */
        virtual Bool PrepareDecodedData() = 0;
        /**
         * @brief Finish decoded data after a call to PrepareDecodedData().
         * If the stream supports re-creating its contents on its own, it may also
         * free its underlying sample storage to save memory.
         * @return true if successful.
         */
        virtual Bool FinishDecodedData() = 0;
        /**
         * @brief Release decoded data.
         * If the stream supports re-creating its contents on its own, it may
         * free any underlying sample storage to save memory on this call, otherwise
         * this may be a no-op.
         * @return true if successful.
         */
        virtual Bool ReleaseDecodedData() = 0;

        /**
         * @brief Get the time offset of the recently decoded data buffer.
         * @return The time offset in seconds.
         */
        virtual Double GetDecodedTimeOffset() const = 0;
        /**
         * @brief Get the index of the first decoded sample in the recently decoded buffer.
         * @return The sample index.
         */
        virtual UInt64 GetDecodedSampleIndex() const = 0;
        
        /**
         * @brief Get the decoded data.
         * PrepareDecodedData() has to be called before, see also FinishDecodedData().
         * @return The decoded data or empty data if not supported.
         */
        virtual const ConstData& GetDecodedData() = 0;
        
        /**
         * @brief Lock the decoded data.
         * @return The mutable data or empty data if not supported.
         */
        virtual const MutableData& LockDecodedData() = 0;
        /**
         * @brief Unlock the decoded data.
         * @return true if successful.
         */
        virtual Bool UnlockDecodedData() = 0;
    };
}

#endif  // __MURL_I_AUDIO_STREAM_H__

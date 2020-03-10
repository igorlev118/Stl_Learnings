// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_I_BUFFER_H__
#define __MURL_AUDIO_I_BUFFER_H__

#include "murl_audio_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IAudioStream;
    
    namespace Audio
    {
        class IObject;

        /**
         * @ingroup MurlAudioObjectInterfaces
         * @interface IBuffer
         * @brief The IBuffer audio object interface.
         * This interface represents an audio sample buffer with typical properties
         * such as sample format and sample rate.
         *
         * Used internally by Graph::AudioSource and Graph::AudioSequence.
         */
        class IBuffer
        {
        public:
            /**
             * @brief Get the mutable Audio::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Audio::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Set the buffer type (stream or static).
             * @param type The buffer type.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::BufferType type) = 0;
            /**
             * @brief Get the buffer type.
             * @return The buffer type.
             */
            virtual IEnums::BufferType GetType() const = 0;
            
            /**
             * @brief Set the access mode hint (read only or read/write).
             * @param mode The access mode.
             * @return true if successful.
             */
            virtual Bool SetAccessMode(IEnums::BufferAccessMode mode) = 0;
            /**
             * @brief Get the access mode hint.
             * @return The access mode.
             */
            virtual IEnums::BufferAccessMode GetAccessMode() const = 0;

            /**
             * @brief Set the desired output sample format.
             * @param format The sample format.
             * @return true if successful.
             */
            virtual Bool SetSampleFormat(IEnums::SampleFormat format) = 0;
            /**
             * @brief Get the output sample format.
             * @return The sample format.
             */
            virtual IEnums::SampleFormat GetSampleFormat() const = 0;

            /**
             * @brief Set the desired output sample rate.
             * @param sampleRate The sample rate in Hertz.
             * @return true if successful.
             */
            virtual Bool SetSampleRate(UInt32 sampleRate) = 0;
            /**
             * @brief Get the output sample rate.
             * @return The sample rate in Hertz.
             */
            virtual UInt32 GetSampleRate() const = 0;
            
            /**
             * @brief Set the total number of samples.
             * @param numberOfSamples The number of samples.
             * @return true if successful.
             */
            virtual Bool SetNumberOfSamples(UInt32 numberOfSamples) = 0;
            /**
             * @brief Get the total number of samples.
             * @return The number of samples.
             */
            virtual UInt32 GetNumberOfSamples() const = 0;

            /**
             * @brief Set the audio stream source.
             * @param stream The audio stream.
             * @return true if successful.
             */
            virtual Bool SetAudioStream(IAudioStream* stream) = 0;
            /**
             * @brief Get the audio stream source.
             * @return The audio stream.
             */
            virtual IAudioStream* GetAudioStream() const = 0;

        protected:
            virtual ~IBuffer() {}
        };
    }
}

#endif // __MURL_AUDIO_I_BUFFER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_I_PLAYABLE_H__
#define __MURL_AUDIO_I_PLAYABLE_H__

#include "murl_audio_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Audio
    {
        class IObject;
        class IBuffer;

        /**
         * @ingroup MurlAudioObjectInterfaces
         * @interface IPlayable
         * This interface represents a playable sound object, which can reference
         * a number of IBuffer objects to play back.
         *
         * Used internally by Graph::AudioSequence.
         */
        class IPlayable
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
             * @brief Trigger playback for a single frame.
             * @param worldTransform The current transform of the object in 3D space.
             * @param time The current playback time.
             * @return true if successful.
             */
            virtual Bool Play(const Matrix& worldTransform, Double time) = 0;
            /**
             * @brief Stop playback.
             * @return true if successful.
             */
            virtual Bool Stop() = 0;
            
            /**
             * @brief Enable/disable endless looping.
             * @param enabled If true, endless looping is enabled.
             * @return true if successful.
             */
            virtual Bool SetEndlessLoopEnabled(Bool enabled) = 0;
            /**
             * @brief Check if endless looping is enabled.
             * @return true if endless looping is enabled.
             */
            virtual Bool IsEndlessLoopEnabled() const = 0;
            
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
             * @brief Set the maximum number of stream buffers used during playback.
             * @param maxNumBuffers The maximum number of stream buffers.
             * @return true if successful.
             */
            virtual Bool SetMaxNumberOfStreamBuffers(UInt32 maxNumBuffers) = 0;
            /**
             * @brief Get the maximum number of stream buffers used during playback
             * @return The maximum number of stream buffers.
             */
            virtual UInt32 GetMaxNumberOfStreamBuffers() const = 0;

            /**
             * @brief Set the playable's actual volume.
             * @param volume The playback volume.
             * @return true if successful.
             */
            virtual Bool SetVolume(Real volume) = 0;
            /**
             * @brief Get the playable's actual volume.
             * @return The playback volume.
             */
            virtual Real GetVolume() const = 0;
            
            /**
             * @brief Set the reference distance.
             * See Graph::IListener for details.
             * @param referenceDistance The reference distance.
             * @return true if successful.
             */
            virtual Bool SetReferenceDistance(Real referenceDistance) = 0;
            /**
             * @brief Get the reference distance.
             * @return The reference distance.
             */
            virtual Real GetReferenceDistance() const = 0;

            /**
             * @brief Set the rolloff factor.
             * See Graph::IListener for details.
             * @param rolloffFactor The rolloff factor.
             * @return true if successful.
             */
            virtual Bool SetRolloffFactor(Real rolloffFactor) = 0;
            /**
             * @brief Get the rolloff factor.
             * @return The rolloff factor.
             */
            virtual Real GetRolloffFactor() const = 0;

            /**
             * @brief Set the maximum distance.
             * See Graph::IListener for details.
             * @param maxDistance The maximum distance.
             * @return true if successful.
             */
            virtual Bool SetMaxDistance(Real maxDistance) = 0;
            /**
             * @brief Get the maximum distance.
             * @return The maximum distance.
             */
            virtual Real GetMaxDistance() const = 0;

            /**
             * @brief Detach all buffers from the playable object.
             * @return true if successful.
             */
            virtual Bool ClearBuffers() = 0;
            /**
             * @brief Attach a buffer to the playable object's buffer sequence.
             * @param buffer The buffer to add.
             * @return true if successful.
             */
            virtual Bool AddBuffer(IBuffer* buffer) = 0;
            /**
             * @brief Get the number of currently attached buffer objects.
             * @return The number of buffers.
             */
            virtual UInt32 GetNumberOfBuffers() const = 0;
            /**
             * @brief Get the buffer attached at a given index.
             * @param index The index, from 0 to GetNumberOfBuffers()-1.
             * @return The buffer, or null if the index is out of range.
             */
            virtual IBuffer* GetBuffer(UInt32 index) const = 0;
            /**
             * @brief Get the actual start time of an attached buffer in the sequence.
             * @param index The index, from 0 to GetNumberOfBuffers()-1.
             * @return The start time, or 0.0 if the index is out of range.
             */
            virtual Double GetBufferStartTime(UInt32 index) const = 0;

            /**
             * @brief Check if the playable actually has data to play back.
             * @return true if playback data is present.
             */
            virtual Bool HasDataToPlay() const = 0;
            
        protected:
            virtual ~IPlayable() {}
        };
    }
}

#endif // __MURL_AUDIO_I_PLAYABLE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_AUDIBLE_H__
#define __MURL_GRAPH_I_AUDIBLE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IAudible
         * @brief The IAudible property interface.
         * This interface provides setting and retrieving common properties of an audible
         * object (i.e. a sound), including volume, reference and maximum distance, and 
         * rolloff factor. For a detailed description of the distance model, see the IListener
         * interface.
         *
         * Animation controllers may call the SetVolume() method when volume keys are
         * present in a given Resource::IAnimation.
         */
        class IAudible
        {
        public:
            /**
             * @brief Set the sample format used for playback.
             * This method sets the internal sample format used for playback. Usually,
             * the native sample format of a given sound object is used by default, but
             * can be overridden by any other value.
             * @param sampleFormat The internal sample format to use.
             * @return true if successful.
             */
            virtual Bool SetSampleFormat(IEnums::SampleFormat sampleFormat) = 0;
            /**
             * @brief Get the sample format used for playback.
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
             * @brief Set the playback volume.
             * @param volume The playback volume in the range from 0.0 (silent) to 1.0
             *      (full volume).
             * @return true if successful.
             */
            virtual Bool SetVolume(Real volume) = 0;
            /**
             * @brief Get the playback volume.
             * @return The playback volume in the range from 0.0 (silent) to 1.0 (full volume).
             */
            virtual Real GetVolume() const = 0;
            
            /**
             * @brief Set the reference distance.
             * @param referenceDistance The reference distance. See the IListener interface
             *      for details.
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
             * @param rolloffFactor The rolloff factor. See the IListener interface
             *      for details.
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
             * @param maxDistance The maximum distance. See the IListener interface
             *      for details.
             * @return true if successful.
             */
            virtual Bool SetMaxDistance(Real maxDistance) = 0;
            /**
             * @brief Get the maximum distance.
             * @return The maximum distance.
             */
            virtual Real GetMaxDistance() const = 0;
            
        protected:
            virtual ~IAudible() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IAudible nodes.
         */
        typedef IGenericNodeTarget<IAudible> IAudibleNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_AUDIBLE_H__

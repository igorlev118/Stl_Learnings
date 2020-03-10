// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_STATE_H__
#define __MURL_AUDIO_STATE_H__

#include "murl_audio_types.h"

namespace Murl
{
    class IAudioInterface;
    
    namespace Audio
    {
        /**
         * @ingroup MurlAudioObjectClasses
         * @brief The internal renderer state object.
         * Only necessary when implementing custom audio objects.
         */
        class State
        {
        public:
            /**
             * @brief Set up the state for rendering.
             */
            virtual void Setup();
            /**
             * @brief Finish the state after rendering.
             */
            virtual void Finish();

            /**
             * @brief Get the platform front end's audio interface.
             * @return The audio interface.
             */
            virtual IAudioInterface* GetAudioInterface() const;
            
        public:
            UInt32 mCurrentFrameCount;

        protected:
            State(IAudioInterface* audioInterface);
            virtual ~State();
            
            IAudioInterface* mAudioInterface;
            
            friend class Renderer;
        };
    }
}

#endif // __MURL_AUDIO_STATE_H__

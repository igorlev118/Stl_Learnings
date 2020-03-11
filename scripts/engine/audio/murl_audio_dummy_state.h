// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_DUMMY_STATE_H__
#define __MURL_AUDIO_DUMMY_STATE_H__

#include "murl_audio_state.h"

namespace Murl
{
    namespace Audio
    {
        namespace Dummy
        {
            /**
             * @ingroup MurlAudioDummyRendererClasses
             * @brief The internal dummy renderer state object.
             * Only necessary when implementing custom audio objects.
             */
            class State : public Audio::State
            {
            protected:
                State(IAudioInterface* audioInterface);
                virtual ~State();
                
                friend class Renderer;
            };
        }
    }
}

#endif // __MURL_AUDIO_DUMMY_STATE_H__

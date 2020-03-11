// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_AL11_STATE_H__
#define __MURL_AUDIO_AL11_STATE_H__

#include "murl_audio_state.h"

namespace Murl
{
    namespace Audio
    {
        namespace Al11
        {
            /**
             * @ingroup MurlAudioAl11RendererClasses
             * @brief The internal renderer state object for OpenAL 1.1.
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

#endif // __MURL_AUDIO_AL11_STATE_H__

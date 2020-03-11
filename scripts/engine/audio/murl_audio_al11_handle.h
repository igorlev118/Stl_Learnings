// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_AL11_HANDLE_H__
#define __MURL_AUDIO_AL11_HANDLE_H__

#include "murl_audio_i_renderer.h"

namespace Murl
{
    namespace Audio
    {
        namespace Al11
        {
            class State;
            class Renderer;
            
            /**
             * @ingroup MurlAudioAl11RendererClasses
             * @brief The internal handle object for OpenAL 1.1.
             * Only necessary when implementing custom audio objects.
             */
            class Handle
            {
            public:
                Handle(IRenderer* renderer);
                ~Handle();

            private:
                Handle();
                
            public:
                Renderer* mRenderer;
                State* mState;
            };
        }
    }
}

#endif // __MURL_AUDIO_AL11_HANDLE_H__

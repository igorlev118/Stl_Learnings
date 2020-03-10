// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_DUMMY_HANDLE_H__
#define __MURL_AUDIO_DUMMY_HANDLE_H__

#include "murl_audio_i_renderer.h"

namespace Murl
{
    namespace Audio
    {
        namespace Dummy
        {
            class State;
            class Renderer;
            
            /**
             * @ingroup MurlAudioDummyRendererClasses
             * @brief The internal dummy renderer handle object.
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

#endif // __MURL_AUDIO_DUMMY_HANDLE_H__

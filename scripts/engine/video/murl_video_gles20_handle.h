// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_GLES20_HANDLE_H__
#define __MURL_VIDEO_GLES20_HANDLE_H__

#include "murl_video_i_renderer.h"

namespace Murl
{
    namespace Video
    {
        namespace GlEs20
        {
            class State;
            class Renderer;
            
            /**
             * @ingroup MurlVideoGlEs20RendererClasses
             * @brief The internal handle object for OpenGL|ES 2.0.
             * Only necessary when implementing custom video objects.
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

#endif // __MURL_VIDEO_GLES20_HANDLE_H__

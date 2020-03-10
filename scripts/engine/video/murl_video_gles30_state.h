// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_GLES30_STATE_H__
#define __MURL_VIDEO_GLES30_STATE_H__

#include "murl_video_gles20_state.h"
#include "murl_system_opengl_es30.h"

namespace Murl
{
    namespace Video
    {
        class IRenderer;

        namespace GlEs30
        {
            /**
             * @ingroup MurlVideoGlEs20RendererClasses
             * @brief The internal renderer state object for OpenGL|ES 2.0.
             * Only necessary when implementing custom video objects.
             */
            class State : public Video::GlEs20::State
            {
            public:
                virtual void Setup();
                virtual void Finish();
                
            public:

            protected:
                State(IVideoInterface* videoInterface, IRenderer* renderer);
                virtual ~State();

                IRenderer* mRenderer;
                
                friend class Renderer;
            };
        }
    }
}

#endif // __MURL_VIDEO_GLES30_STATE_H__

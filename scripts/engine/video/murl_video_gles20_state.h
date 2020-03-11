// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_GLES20_STATE_H__
#define __MURL_VIDEO_GLES20_STATE_H__

#include "murl_video_state.h"
#include "murl_system_opengl_es20.h"

namespace Murl
{
    namespace Video
    {
        namespace GlEs20
        {
            /**
             * @ingroup MurlVideoGlEs20RendererClasses
             * @brief The internal renderer state object for OpenGL|ES 2.0.
             * Only necessary when implementing custom video objects.
             */
            class State : public Video::State
            {
            public:
                virtual void Setup();
                virtual void Finish();
                
            public:

            protected:
                State(IVideoInterface* videoInterface);
                virtual ~State();
                
                friend class Renderer;
            };
        }
    }
}

#endif // __MURL_VIDEO_GLES20_STATE_H__

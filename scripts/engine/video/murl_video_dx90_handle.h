// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_DX90_HANDLE_H__
#define __MURL_VIDEO_DX90_HANDLE_H__

#include <d3d9.h>
#undef GetClassInfo

#include "murl_system_platform.h"

#include "murl_video_i_renderer.h"

namespace Murl
{
    namespace Video
    {
        namespace Dx90
        {
            class State;
            class Renderer;
            
            /**
             * @ingroup MurlVideoDx90RendererClasses
             * @brief The internal handle object for DirectX 9.0.
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
                IDirect3DDevice9* mDevice;
            };
        }
    }
}

#endif // __MURL_VIDEO_DX90_HANDLE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_DX111_HANDLE_H__
#define __MURL_VIDEO_DX111_HANDLE_H__

#include <d3d11.h>
#if !defined(MURL_TARGET_OS_WINPHONE8) && !defined(MURL_TARGET_OS_WIN8)
#include <D3D11Shader.h>
#endif
#undef GetClassInfo

#include "murl_system_platform.h"

#include "murl_video_types.h"
#include "murl_video_i_renderer.h"

namespace Murl
{
    namespace Video
    {
        namespace Dx111
        {
            class State;
            class Renderer;
            
            /**
             * @ingroup MurlVideoDx111RendererClasses
             * @brief The internal handle object for DirectX 11.1.
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
                ID3D11Device* mDevice;
                ID3D11DeviceContext* mContext;
            };
        }
    }
}

#endif // __MURL_VIDEO_DX111_HANDLE_H__

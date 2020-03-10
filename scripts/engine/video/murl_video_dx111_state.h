// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_DX111_STATE_H__
#define __MURL_VIDEO_DX111_STATE_H__

#include "murl_video_state.h"
#include "murl_video_dx111_handle.h"

namespace Murl
{
    namespace Video
    {
        namespace Dx111
        {
            /**
             * @ingroup MurlVideoDx111RendererClasses
             * @brief The internal renderer state object for DirectX 11.1.
             * Only necessary when implementing custom video objects.
             */
            class State : public Video::State
            {
            public:
                virtual void Setup();
                virtual void Finish();

            public:
                Bool mIsCameraFlipped;
                Bool mIsFrontFaceClockwise;
                
                UInt32 mCurrentSurfaceWidth;
                UInt32 mCurrentSurfaceHeight;
                
                ID3D11RenderTargetView* mCurrentRenderTargetView;
                ID3D11DepthStencilView* mCurrentDepthStencilView;

            protected:
                State(IVideoInterface* videoInterface);
                virtual ~State();
                
                friend class Renderer;
            };
        }
    }
}

#endif // __MURL_VIDEO_DX111_STATE_H__

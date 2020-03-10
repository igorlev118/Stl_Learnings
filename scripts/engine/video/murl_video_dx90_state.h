// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_DX90_STATE_H__
#define __MURL_VIDEO_DX90_STATE_H__

#include "murl_video_state.h"

namespace Murl
{
    namespace Video
    {
        namespace Dx90
        {
            class Renderer;

            /**
             * @ingroup MurlVideoDx90RendererClasses
             * @brief The internal renderer state object for DirectX 9.0.
             * Only necessary when implementing custom video objects.
             */
            class State : public Video::State
            {
            public:
                virtual void Setup();
                virtual void Finish();

            public:
                Matrix mCurrentCameraViewMatrix;
                Matrix mCurrentCameraProjectionMatrix;
                Matrix mCurrentCameraViewProjectionMatrix;
                Vector mCurrentCameraPosition;
                Vector mCurrentCameraDirection;
                UInt32 mCurrentCameraUpdateCount;

                Matrix mCurrentLightViewMatrix;
                Matrix mCurrentLightProjectionMatrix;
                Matrix mCurrentLightViewProjectionMatrix;
                Vector mCurrentLightPosition;
                Vector mCurrentLightDirection;
                UInt32 mCurrentLightUpdateCount;

                Bool mIsCameraFlipped;
                Bool mIsFrontFaceClockwise;

                UInt32 mCurrentSurfaceWidth;
                UInt32 mCurrentSurfaceHeight;

            protected:
                State(IVideoInterface* videoInterface, Renderer* renderer);
                virtual ~State();

                Renderer* mRenderer;

                friend class Renderer;
            };
        }
    }
}

#endif // __MURL_VIDEO_DX90_STATE_H__

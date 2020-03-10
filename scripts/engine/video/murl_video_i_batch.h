// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_BATCH_H__
#define __MURL_VIDEO_I_BATCH_H__

#include "murl_video_types.h"

namespace Murl
{
    namespace Video
    {
        /**
         * @ingroup MurlVideoRendererInterfaces
         * @interface IBatch
         * This interface represents a statically grouped set of render state
         * objects and drawables.
         */
        class IBatch
        {
        public:
            /**
             * @brief Get the total number of objects rendered in this batch.
             * @return The number of objects rendered.
             */
            virtual UInt32 GetNumberOfObjectsRendered() const = 0;
            
        protected:
            virtual ~IBatch() {}
        };
    }
}

#endif // __MURL_VIDEO_I_BATCH_H__

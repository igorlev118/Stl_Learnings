// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_VIDEO_SCALER_H__
#define __MURL_I_VIDEO_SCALER_H__

#include "murl_i_enums.h"
#include "murl_data.h"
#include "murl_shared_pointer.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IVideoScaler
     * @brief The video scaler interface.
     */
    class IVideoScaler
    {
    public:
        /**
         * @brief The destructor.
         */
        virtual ~IVideoScaler() {}

        /**
         * @brief Scale a source image to a destination image.
         * @param srcData The source image data.
         * @param dstData The destination image data.
         * @param srcPixelSizeX The number of horizontal source pixels.
         * @param srcPixelSizeY The number of vertical source pixels.
         * @param srcBytePitch The number of source bytes per line.
         * @param dstPixelSizeX The number of horizontal destination pixels.
         * @param dstPixelSizeY The number of vertical destination pixels.
         * @param dstBytePitch The number of destination bytes per line.
         * @param pixelFormat The pixel format.
         * @param gamma The gamma value. Specify 1.0 to disable gamma 
         *  correct scaling.
         * @return true if successful.
         */
        virtual Bool Scale(const ConstData& srcData, const MutableData& dstData,
                           UInt32 srcPixelSizeX, UInt32 srcPixelSizeY, UInt32 srcBytePitch,
                           UInt32 dstPixelSizeX, UInt32 dstPixelSizeY, UInt32 dstBytePitch,
                           IEnums::PixelFormat pixelFormat, Real gamma) const = 0;
    };

    /** @brief The IVideoScaler shared pointer type. */
    typedef SharedPointer<IVideoScaler> IVideoScalerPtr;

    /** @brief The IVideoScaler const shared pointer type. */
    typedef SharedPointer<IVideoScaler const> IVideoScalerCPtr;
}

#endif  // __MURL_I_VIDEO_SCALER_H__

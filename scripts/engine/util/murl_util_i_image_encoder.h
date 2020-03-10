// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_I_IMAGE_ENCODER_H__
#define __MURL_UTIL_I_IMAGE_ENCODER_H__

#include "murl_i_video_surface.h"
#include "murl_i_factory_object.h"

namespace Murl
{
    namespace Util
    {
        class IFactory;

        class IImageEncoder : public IFactoryObject<IImageEncoder>
        {
        public:
            typedef IImageEncoder* (*CreateFunction)(const IFactory* factory);

        public:
            /**
             * @brief Encoder flags
             */
            enum Flag
            {
                /** @brief Default flags. */
                FLAG_NONE                = 0,
            };

            virtual Bool Encode(Data& destination, const IVideoSurface* source, UInt32 flags, IEnums::CompressionType compression, Real quality) const = 0;
            virtual Bool Encode(Data& destination, const IVideoSurface* source, UInt32 flags, IEnums::CompressionType compression, Real quality, IEnums::PixelFormat dstPixelFormat, const SInt32 dstComponents[4]) const = 0;

        protected:
            virtual ~IImageEncoder() {}

            friend class Factory;
        };
    }
}

#endif // __MURL_UTIL_I_IMAGE_ENCODER_H__

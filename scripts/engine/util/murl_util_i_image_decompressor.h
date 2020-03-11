// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_I_IMAGE_DECOMPRESSOR_H__
#define __MURL_UTIL_I_IMAGE_DECOMPRESSOR_H__

#include "murl_i_factory_object.h"
#include "murl_array.h"
#include "murl_data.h"

namespace Murl
{
    class IVideoSurface;

    namespace Util
    {
        class IFactory;

        class IImageDecompressor : public IFactoryObject<IImageDecompressor>
        {
        public:
            typedef IImageDecompressor* (*CreateFunction)(const IFactory* factory);
            
        public:
            /**
             * @brief Decompressor flags
             */
            enum Flag
            {
                /** @brief Default flags. */
                FLAG_NONE                = 0,
            };

            virtual Bool CanDecompress(IEnums::PixelFormat inputFormat) const = 0;
            virtual IEnums::PixelFormat GetOutputFormat(IEnums::PixelFormat inputFormat) const = 0;
            virtual IEnums::PixelFormat GetOutputFormat(IEnums::PixelFormat inputFormat, IEnums::PixelFormat outputFormat) const = 0;

            virtual IVideoSurface* Decompress(const ConstData& input, UInt32 outputSizeX, UInt32 outputSizeY, UInt32 flags, IEnums::PixelFormat inputFormat, IEnums::PixelFormat outputFormat) const = 0;

        protected:
            virtual ~IImageDecompressor() {}

            friend class Factory;
        };
    }
}

#endif // __MURL_UTIL_I_IMAGE_DECOMPRESSOR_H__

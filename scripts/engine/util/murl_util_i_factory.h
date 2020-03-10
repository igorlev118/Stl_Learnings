// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_I_FACTORY_H__
#define __MURL_UTIL_I_FACTORY_H__

#include "murl_util_i_factory_registry.h"

namespace Murl
{
    namespace Util
    {
        class IImageDecoder;
        class IImageEncoder;
        class IImageDecompressor;

        /**
         * @ingroup MurlUtilFactoryInterfaces
         * @interface IFactory
         * @brief The factory used to create utility objects
         * Use the Util::IFactoryRegistry base interface for managing registered
         * classes.
         */
        class IFactory : public IFactoryRegistry
        {
        public:
            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Get an image decoder using a given class name.
             * @param className The class name of a registered decoder.
             * @return The registered decoder, or null if not present.
             */
            virtual IImageDecoder* GetImageDecoder(const String& className) = 0;
            /**
             * @brief Get an image decoder using a given class info.
             * @param classInfo The ClassInfo structure of a registered decoder.
             * @return The registered decoder, or null if not present.
             */
            virtual IImageDecoder* GetImageDecoder(const IImageDecoder::ClassInfo& classInfo) = 0;

            /**
             * @brief Get an image encoder using a given class name.
             * @param className The class name of a registered encoder.
             * @return The registered encoder, or null if not present.
             */
            virtual IImageEncoder* GetImageEncoder(const String& className) = 0;
            /**
             * @brief Get an image encoder using a given class info.
             * @param classInfo The ClassInfo structure of a registered encoder.
             * @return The registered encoder, or null if not present.
             */
            virtual IImageEncoder* GetImageEncoder(const IImageEncoder::ClassInfo& classInfo) = 0;

            /**
             * @brief Get an image decompressor using a given class name.
             * @param className The class name of a registered decompressor.
             * @return The registered decompressor, or null if not present.
             */
            virtual IImageDecompressor* GetImageDecompressor(const String& className) = 0;
            /**
             * @brief Get an image decompressor using a given class info.
             * @param classInfo The ClassInfo structure of a registered decompressor.
             * @return The registered decompressor, or null if not present.
             */
            virtual IImageDecompressor* GetImageDecompressor(const IImageDecompressor::ClassInfo& classInfo) = 0;
            /**
             * @brief Get an image decompressor for a given compressed pixel format.
             * @param pixelFormat The format for which to get a decompressor.
             * @return The registered decompressor, or null if not present.
             */
            virtual IImageDecompressor* GetImageDecompressor(IEnums::PixelFormat pixelFormat) = 0;

        protected:
            virtual ~IFactory() {}
        };
        
        /**
         * @ingroup MurlUtilFactoryClasses
         * @brief The StaticFactory class to create the IFactory object.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create the util factory object.
             * @return The created util factory object, or null if failed.
             */
            static IFactory* CreateFactory();
            /**
             * @brief Destroy the util factory object.
             * @param factory A reference to the util factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyFactory(IFactory*& factory);
        };
    }
}

#endif  // __MURL_UTIL_I_FACTORY_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_I_FACTORY_REGISTRY_H__
#define __MURL_UTIL_I_FACTORY_REGISTRY_H__

#include "murl_util_i_image_decoder.h"
#include "murl_util_i_image_encoder.h"
#include "murl_util_i_image_decompressor.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilFactoryInterfaces
         * @interface IFactoryRegistry
         * The IFactoryRegistry interface provides methods to add, remove and query different
         * utility classes that can be instantiated using the Util::IFactory
         * implementing this interface.
         */
        class IFactoryRegistry
        {
        public:
            /**
             * @brief Register an image decoder class.
             * @param classInfo The ClassInfo structure of the decoder to register.
             * @return true if successful.
             */
            virtual Bool RegisterImageDecoderClass(const IImageDecoder::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered image decoder class.
             * @param classInfo The ClassInfo structure of the decoder to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterImageDecoderClass(const IImageDecoder::ClassInfo& classInfo) = 0;
            
            /**
             * @brief Query the index of a registered image decoder class, by its ClassInfo structure.
             * @param classInfo The class info structure of the decoder class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredImageDecoderClassInfoIndex(const IImageDecoder::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the index of a registered image decoder class, by its class name.
             * @param className The name of the decoder class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredImageDecoderClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered image decoder classes.
             * @return The number of registered decoder classes.
             */
            virtual UInt32 GetNumberOfRegisteredImageDecoderClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered image decoder class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredImageDecoderClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const IImageDecoder::ClassInfo* GetRegisteredImageDecoderClassInfo(UInt32 index) const = 0;
             
            /**
             * @brief Register an image encoder class.
             * @param classInfo The ClassInfo structure of the encoder to register.
             * @return true if successful.
             */
            virtual Bool RegisterImageEncoderClass(const IImageEncoder::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered image encoder class.
             * @param classInfo The ClassInfo structure of the encoder to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterImageEncoderClass(const IImageEncoder::ClassInfo& classInfo) = 0;

            /**
             * @brief Query the index of a registered image encoder class, by its ClassInfo structure.
             * @param classInfo The class info structure of the encoder class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredImageEncoderClassInfoIndex(const IImageEncoder::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the index of a registered image encoder class, by its class name.
             * @param className The name of the encoder class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredImageEncoderClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered image encoder classes.
             * @return The number of registered encoder classes.
             */
            virtual UInt32 GetNumberOfRegisteredImageEncoderClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered image encoder class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredImageEncoderClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const IImageEncoder::ClassInfo* GetRegisteredImageEncoderClassInfo(UInt32 index) const = 0;

            /**
             * @brief Register an image decompressor class.
             * @param classInfo The ClassInfo structure of the decompressor to register.
             * @return true if successful.
             */
            virtual Bool RegisterImageDecompressorClass(const IImageDecompressor::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered image decompressor class.
             * @param classInfo The ClassInfo structure of the decompressor to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterImageDecompressorClass(const IImageDecompressor::ClassInfo& classInfo) = 0;

            /**
             * @brief Query the index of a registered image decompressor class, by its ClassInfo structure.
             * @param classInfo The class info structure of the decompressor class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredImageDecompressorClassInfoIndex(const IImageDecompressor::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the index of a registered image decompressor class, by its class name.
             * @param className The name of the decompressor class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredImageDecompressorClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered image decompressor classes.
             * @return The number of registered decompressor classes.
             */
            virtual UInt32 GetNumberOfRegisteredImageDecompressorClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered image decompressor class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredImageDecompressorClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const IImageDecompressor::ClassInfo* GetRegisteredImageDecompressorClassInfo(UInt32 index) const = 0;

        protected:
            virtual ~IFactoryRegistry() {}
        };
    }
}

#endif  // __MURL_UTIL_I_FACTORY_REGISTRY_H__

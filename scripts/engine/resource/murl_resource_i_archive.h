// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_ARCHIVE_H__
#define __MURL_RESOURCE_I_ARCHIVE_H__

#include "murl_resource_types.h"
#include "murl_util_iff.h"

namespace Murl
{
    class ConstData;
    
    namespace Resource
    {
        class IObject;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IArchive
         * @brief The IArchive resource object interface.
         * An archive resource stores a (ZLib) compressed block of raw data, with
         * optional encryption.
         */
        class IArchive
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as an archive.
                    FOURCC = 'BNAR',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native archive resource.
                 */
                struct HeaderChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a HeaderChunk.
                        FOURCC = 'HEAD'
                    };

                    /// The actual resource version.
                    UInt32 mVersion;

                    /// If non-zero, the binary data are encrypted.
                    UInt32 mIsEncrypted;

                    /// An offset into the chunk where the binary archive is stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The size in bytes of the archive data.
                    UInt32 mDataByteSize;
                };
            };
            
            /**
             * @brief Get the mutable Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Get a data object containing the uncompressed data.
             * Calling this method returns a constant data object containing the uncompressed
             * payload data, performing decryption if necessary. If decryption or decompression
             * fails, an empty data object is returned.
             * It is necessary to make a corresponding call to ReleaseData() for every GetData()
             * invocation.
             * @return A constant data object containing the uncompressed contents.
             */
            virtual const ConstData& GetData() const = 0;
            /**
             * @brief Release the previously obtained data.
             * @return true if successful.
             */
            virtual Bool ReleaseData() const = 0;
            
        protected:
            virtual ~IArchive() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_ARCHIVE_H__

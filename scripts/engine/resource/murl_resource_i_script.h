// Copyright 2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_SCRIPT_H__
#define __MURL_RESOURCE_I_SCRIPT_H__

#include "murl_logic_types.h"
#include "murl_util_iff.h"
#include "murl_data.h"

namespace Murl
{
    namespace Resource
    {
        class IObject;

        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IScript
         * @brief The IScript resource object interface.
         */
        class IScript
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as an script.
                    FOURCC = 'SCPT',
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

                    enum StorageFlags
                    {
                        STORAGE_FLAG_NONE =     0,
                        STORAGE_FLAG_COMPILE =  1 << 0,
                        STORAGE_FLAG_COMPRESS = 1 << 1,
                        STORAGE_FLAG_ENCRYPT =  1 << 2
                    };
                    /// The storage flags.
                    UInt32 mStorageFlags;

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
             * @brief Create a logic processor object from the script data.
             * @param logicState The logic state object.
             * @param info A string containing additional information passed to the script,
             *  e.g. the replication number when created from resource script instance.
             * @return The logic processor object or null if creation failed.
             */
            virtual Logic::IProcessorPtr CreateIProcessor(const Logic::IState* logicState,
                                                          const String& info) const = 0;

            /**
             * @brief Create a logic app graph object from the script data.
             * @param info A string containing additional information passed to the script,
             *  e.g. the replication number when created from resource script instance.
             * @return The logic app graph object or null if creation failed.
             */
            virtual Logic::IAppGraphPtr CreateIAppGraph(const String& info) const = 0;

            /**
             * @brief Get a data object containing the script data.
             * Calling this method returns a constant data object containing the script data,
             * performing decryption if necessary.
             * If decryption fails, an empty data object is returned.
             * It is necessary to make a corresponding call to ReleaseData() for every GetData()
             * invocation.
             * @return A constant data object containing the script contents.
             */
            virtual const ConstData& GetData() const = 0;

            /**
             * @brief Release the previously obtained data.
             * @return true if successful.
             */
            virtual Bool ReleaseData() const = 0;

        protected:
            virtual ~IScript() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_SCRIPT_H__

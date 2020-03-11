// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_DICTIONARY_H__
#define __MURL_RESOURCE_I_DICTIONARY_H__

#include "murl_resource_types.h"
#include "murl_util_iff.h"

namespace Murl
{
    class ConstData;
    
    namespace Resource
    {
        class IObject;
        class IText;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IDictionary
         * @brief The IDictionary resource object interface.
         * A binary resource stores one or more individual text objects.
         */
        class IDictionary
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as a dictionary.
                    FOURCC = 'DICT',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native dictionary resource.
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

                    /// If nonzero, the resource's texts are accessible in the global package scope.
                    UInt32 mRegisterGlobally;
                };

                /**
                 * @struct TextChunk
                 * @brief An IFF chunk of a native dictionary resource storing multiple texts.
                 */
                struct TextChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a TextChunk.
                        FOURCC  = 'TEXT',
                    };

                    /// The total number of texts in this chunk.
                    UInt32 mNumberOfTexts;

                    /// An offset into the chunk where the key and value strings are stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The size in bytes of the string data.
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
             * @brief Check if the contained text objects should be registered
             *  globally with the containing package.
             * @return true if texts should be accessible from package scope.
             */
            virtual Bool RegisterGlobally() const = 0;

            /**
             * @brief Get the number of text objects contained in this resource.
             * @return The number of text objects.
             */
            virtual UInt32 GetNumberOfTexts() const = 0;
            /**
             * @brief Get the text object at a given index.
             * @param index The index in the range from 0 to GetNumberOfTexts()-1.
             * @return The text object, or null if index is out of range.
             */
            virtual const IText* GetText(UInt32 index) const = 0;
            /**
             * @brief Get the text object with a given id.
             * @param id The text ID to search for.
             * @return The text object, or null if the given ID was not found.
             */
            virtual const IText* GetText(const String& id) const = 0;

        protected:
            virtual ~IDictionary() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_DICTIONARY_H__

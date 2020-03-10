// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_IFF_DATA_H__
#define __MURL_UTIL_IFF_DATA_H__

#include "murl_util_iff.h"
#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilIffClasses
         * @brief Definition of the IffChunk pointer array.
         */
        typedef Array<IffChunk*> IffChunkArray;
        
        /**
         * @ingroup MurlUtilIffClasses
         * @brief The Interchange File Format data class.
         * The IffData class is used to allocate and store application
         * defined iff chunks.
         * The Create() method composes an iff-file from the stored chunks.
         */
        class IffData
        {
        public:
            /**
             * @brief Constructor taking the file identifier and the file type identifier.
             * This method takes care of the system's byte ordering.
             * @param form The file format identifier.
             * @param fourCC The file type identifier.
             */
            IffData(UInt32 form, UInt32 fourCC);
            /**
             * @brief Constructor taking the file type identifier.
             * Set the file format identifier to 'MURL'.
             * This method takes care of the system's byte ordering.
             * @param fourCC The file type identifier.
             */
            IffData(UInt32 fourCC);
            /**
             * @brief Constructor to create an IffData object without a header.
             * When using this constructor, the data object does not include a
             * file header. Only chunks are stored, which is useful for including
             * the output data as a sub-stream within another IFF stream.
             * This method takes care of the system's byte ordering.
             */
            IffData();
            /**
             * The destructor.
             */
            virtual ~IffData();
            
            /**
             * @brief Add an iff chunk.
             * The chunk must be heap allocated using new, the
             * IffData object takes the ownership of the memory.
             * @param chunk The chunk to add.
             */
            virtual void AddChunk(IffChunk* chunk);
            /**
             * Get the pointer array of the iff chunks added.
             * @return The IffChunk pointer array.
             */
            virtual const IffChunkArray& GetChunks() const;
            
            /**
             * @brief Allocate and initialize an iff chunk.
             * This method takes care of the system's byte ordering
             * and the iff size format.
             * @param fourCC The FourCC chunk identifier.
             * @param chunkSize The byte size of the chunk.
             * @param additionalSize Additional byte size to allocate.
             * @return The heap allocated and initialized iff chunk.
             */
            virtual IffChunk* Alloc(UInt32 fourCC, UInt32 chunkSize, UInt32 additionalSize = 0) const;
            
            /**
             * @brief Alloc() an iff chunk of specified type.
             * @tparam ChunkType The iff chunk type which must have a public
             * enum FOURCC constant defining the chunk identifier.
             * @param additionalSize Additional byte size to allocate.
             * @return The heap allocated and initialized iff chunk of specified type.
             */
            template<class ChunkType>
            ChunkType* AllocChunk(UInt32 additionalSize = 0) const
            {
                return reinterpret_cast<ChunkType*>(Alloc(ChunkType::FOURCC, sizeof(ChunkType), additionalSize));
            }
            
            /**
             * @brief Create an iff-file data object.
             * @param data The data object to write the iff-file into.
             * @return true if successful.
             */
            virtual Bool Create(Data& data) const;
            
        protected:
            /** @brief The file format identifier. */
            UInt32 mForm;
            /** @brief The FourCC file type identifier. */
            UInt32 mFourCC;
            /** @brief The IffChunk pointer array. */
            IffChunkArray mChunks;
        };
    }
}

#endif  // __MURL_UTIL_IFF_DATA_H__

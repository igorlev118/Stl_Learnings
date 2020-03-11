// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_IFF_STREAM_H__
#define __MURL_UTIL_IFF_STREAM_H__

#include "murl_util_iff.h"
#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilIffClasses
         * @brief The Interchange File Format stream class.
         * The IffStream class is used to deserialize an data object which
         * contains iff-file data.
         * The data object's memory to read from is used by reference only,
         * which allows using memory mapped files without copying the data
         * to memory.
         *
         * (!) The ownership of the data object's memory pointer remains to
         * the caller. This means as long as the IffStream is used, the memory
         * pointer of the data object (but probably not to data object itself)
         * must be available in memory.
         */
        class IffStream
        {
        public:
            /**
             * @brief Constructor taking the file identifier and the file type identifier.
             * This method takes care of the system's byte ordering.
             * @param form The file format identifier.
             * @param fourCC The file type identifier.
             * @param data The iff-file data object.
             */
            IffStream(UInt32 form, UInt32 fourCC, const ConstData& data);
            /**
             * @brief Constructor taking the file type identifier.
             * Set the file format identifier to 'MURL'.
             * This method takes care of the system's byte ordering.
             * @param fourCC The file type identifier.
             * @param data The iff-file data object.
             */
            IffStream(UInt32 fourCC, const ConstData& data);
            /**
             * @brief Constructor to create a headerless IffStream.
             * Use this constructor to parse sub-streams from a given container stream.
             * This method takes care of the system's byte ordering.
             * @param data The iff-file data object.
             */
            IffStream(const ConstData& data);
            /**
             * The destructor.
             */
            virtual ~IffStream();
            
            /**
             * @brief Open the iff-file stream.
             * Verify the IffHeader and set the read position to the first chunk.
             * The verification checks the file identifier,
             * the file type identifier and the file size.
             * @return true if successful.
             */
            virtual Bool Open();
            /**
             * @brief Close the iff-file stream.
             * @return true if successful.
             */
            virtual Bool Close();
            
            /**
             * @brief Check the chunk identifier at the current read position
             * and return the byte size of the chunk.
             * This method takes care of the system's byte ordering.
             * @param fourCC The FourCC chunk identifier to check or
             *  zero to skip the chunk test.
             * @return The byte size of the chunk,  zero if the check
             *  failed or the end of the stream is reached.
             */
            virtual UInt32 Check(UInt32 fourCC = 0) const;
            
            /**
             * @brief Check the chunk identifier at the current read position
             * and verify the byte size of the chunk.
             * This method takes care of the system's byte ordering.
             * @param fourCC The FourCC chunk identifier to check or
             *  zero to skip the chunk test.
             * @param chunkSize The byte size of the chunk.
             * @param additionalSize Additional byte size to check.
             * @return true if successful.
             */
            virtual Bool Check(UInt32 fourCC, UInt32 chunkSize, UInt32 additionalSize = 0) const;
            
            /**
             * @brief Check the chunk identifier and size at the current
             * read position and return the the chunk.
             * This method takes care of the system's byte ordering.
             * @param fourCC The FourCC chunk identifier to check or
             *  zero to skip the chunk test.
             * @return Pointer to the chunk, null if the check failed
             *  or the end of the stream is reached.
             */
            virtual const IffChunk* Read(UInt32 fourCC = 0) const;
            
            /**
             * @brief Advance the current read position to the next chunk.
             * @return true if successful,
             *  false if the end of the stream is reached.
             */
            virtual Bool Advance();
            
            /**
             * @brief Rewind the read postition to the first chunk.
             * @return true if successful.
             */
            virtual Bool Rewind();
            
            /**
             * @brief Check if the end of the stream is reached.
             * @return true if the end of the stream is reached.
             */
            virtual Bool Eos() const;
            
            /**
             * @brief Check() a chunk of specified type at the current
             * read position.
             * @tparam ChunkType The iff chunk type which must have a public
             * enum FOURCC constant defining the chunk identifier.
             * @param additionalSize Additional byte size to check.
             * @return true if successful.
             */
            template<class ChunkType>
            Bool CheckChunk(UInt32 additionalSize = 0) const
            {
                return Check(ChunkType::FOURCC, sizeof(ChunkType), additionalSize);
            }
            
            /**
             * @brief Read() a chunk of specified type at the current
             * read position.
             * @tparam ChunkType The iff chunk type which must have a public
             * enum FOURCC constant defining the chunk identifier.
             * @return Pointer to the chunk of specified type, null if
             *  the check failed or the end of the stream is reached.
             */
            template<class ChunkType>
            const ChunkType* ReadChunk() const
            {
                return reinterpret_cast<const ChunkType*>(Read(ChunkType::FOURCC));
            }
            
        protected:
            /** @brief The file format identifier. */
            UInt32 mForm;
            /** @brief The FourCC file type identifier. */
            UInt32 mFourCC;
            
            /** @brief Reference to the iff-file data. */
            ConstData mData;
            /** @brief The current byte position. */
            UInt32 mCurrentPos;
        };
    }
}

#endif // __MURL_UTIL_IFF_STREAM_H__

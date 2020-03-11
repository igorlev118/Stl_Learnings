// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_IFF_H__
#define __MURL_UTIL_IFF_H__

#include "murl_debug_assert.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilIffClasses
         * @brief Compute an integer value from a FourCC.
         * The FourCC value is converted to the host's byte ordering.
         * @param fourCC The FourCC value.
         * @return The FourCC integer value.
         */
        inline UInt32 IffFourCC(UInt32 fourCC)
        {
#ifdef MURL_ENDIANNESS_LITTLE
            return (((fourCC & 0x000000ff) << 24) |
                    ((fourCC & 0x0000ff00) <<  8) |
                    ((fourCC & 0x00ff0000) >>  8) |
                    ((fourCC & 0xff000000) >> 24));
#else
            return fourCC;
#endif
        }
        
        /**
         * @ingroup MurlUtilIffClasses
         * @brief The Interchange File Format header format structure.
         */
        class IffHeader
        {
        public:
            /** @brief The FourCC constants. */
            enum
            {
                /** @brief The Interchange File Format identifier. */
#ifdef MURL_ENDIANNESS_LITTLE
                FOURCC = 'RIFF'
#else
                FOURCC = 'FORM'
#endif
            };
            
            /**
             * @brief The default constructor.
             * Set the file format identifier to FOURCC, the file size to 4 bytes
             * and the file type identifier to 0.
             */
            IffHeader()
            : mForm(IffFourCC(FOURCC))
            , mSize(sizeof(mFourCC))
            , mFourCC(0)
            {
            }
            
            /**
             * @brief Constructor taking the file size and the file type identifier.
             * Set the file format identifier to FOURCC.
             * This method takes care of the system's byte ordering and the iff size format.
             * @param size The size of the file.
             * @param fourCC The file type identifier.
             */
            IffHeader(UInt32 size, UInt32 fourCC)
            : mForm(IffFourCC(FOURCC))
            , mSize(size - sizeof(mForm) - sizeof(mSize))
            , mFourCC(IffFourCC(fourCC))
            {
            }
            
            /**
             * @brief Constructor taking the file identifier, the file size
             * and the file type identifier.
             * This method takes care of the system's byte ordering and the iff size format.
             * @param form The file format identifier.
             * @param size The size of the file.
             * @param fourCC The file type identifier.
             */
            IffHeader(UInt32 form, UInt32 size, UInt32 fourCC)
            : mForm(IffFourCC(form))
            , mSize(size - sizeof(mForm) - sizeof(mSize))
            , mFourCC(IffFourCC(fourCC))
            {
            }
            
            /**
             * @brief Set the file format identifier.
             * This method takes care of the system's byte ordering.
             * @param fourCC The FourCC file format identifier.
             */
            void SetForm(UInt32 fourCC)
            {
                mForm = IffFourCC(fourCC);
            }
            /**
             * @brief Get the file format identifier.
             * This method takes care of the system's byte ordering.
             * @return The FourCC file format identifier.
             */
            UInt32 GetForm() const
            {
                return IffFourCC(mForm);
            }
            
            /**
             * @brief Set the file size.
             * This method takes care of the iff size format.
             * @param size The byte size of the file.
             */
            void SetFileSize(UInt32 size)
            {
                mSize = size - sizeof(mForm) - sizeof(mSize);
            }
            /**
             * @brief Get the file size.
             * This method takes care of the iff size format.
             * @return The byte size of the file.
             */
            UInt32 GetFileSize() const
            {
                return mSize + sizeof(mForm) + sizeof(mSize);
            }
            
            /**
             * @brief Get the file size minus 8 bytes.
             * @return The byte size of the file minus 8 bytes.
             */
            UInt32 GetRawSize() const
            {
                return mSize;
            }
            
            /**
             * @brief Set the file type identifier.
             * This method takes care of the system's byte ordering.
             * @param fourCC The FourCC file type identifier.
             */
            void SetFourCC(UInt32 fourCC)
            {
                mFourCC = IffFourCC(fourCC);
            }
            /**
             * @brief Get the file type identifier.
             * This method takes care of the system's byte ordering.
             * @return The FourCC file type identifier.
             */
            UInt32 GetFourCC() const
            {
                return IffFourCC(mFourCC);
            }
            
        protected:
            /** @brief The file format identifier. */
            UInt32 mForm;
            /** @brief The size of the whole file minus 8 bytes. */
            UInt32 mSize;
            /** @brief The FourCC file type identifier. */
            UInt32 mFourCC;
        };
        
        /**
         * @ingroup MurlUtilIffClasses
         * @brief The Interchange File Format chunk format structure.
         */
        class IffChunk
        {
        public:
            /**
             * @brief Get a typed pointer from an offset relative to the chunk.
             * Returns the address of the chunk + offset + sizeof(IffChunk).
             * @param byteOffset The byte offset.
             * @return The typed pointer or null if the
             *  offset is greater than the chunk size.
             */
            template<class DataType>
            DataType* IffOffset(UInt32 byteOffset) const
            {
                if (!MURL_VERIFY(byteOffset < mSize))
                {
                    return 0;
                }
                UInt8* p = const_cast<UInt8*>(reinterpret_cast<const UInt8*>(this));
                p += (byteOffset + sizeof(IffChunk));
                return reinterpret_cast<DataType*>(p);
            }
            
            /**
             * @brief Set the chunk identifier.
             * This method takes care of the system's byte ordering.
             * @param fourCC The FourCC chunk identifier.
             */
            void SetFourCC(UInt32 fourCC)
            {
                mFourCC = IffFourCC(fourCC);
            }
            /**
             * @brief Get the chunk identifier.
             * This method takes care of the system's byte ordering.
             * @return The FourCC chunk identifier.
             */
            UInt32 GetFourCC() const
            {
                return IffFourCC(mFourCC);
            }
            
            /**
             * @brief Set the chunk size.
             * This method takes care of the iff size format.
             * @param size The byte size of the chunk.
             */
            void SetChunkSize(UInt32 size)
            {
                mSize = size - sizeof(IffChunk);
            }
            /**
             * @brief Get the chunk size.
             * This method takes care of the iff size format.
             * @return The byte size of the chunk.
             */
            UInt32 GetChunkSize() const
            {
                return mSize + sizeof(IffChunk);
            }
            
            /**
             * @brief Get the chunk size minus sizeof(IffChunk).
             * @return The byte size of the chunk minus sizeof(IffChunk).
             */
            UInt32 GetRawSize() const
            {
                return mSize;
            }
            
        protected:
            /** @brief The FourCC chunk identifier. */
            UInt32 mFourCC;
            /** @brief The size of this chunk minus sizeof(IffChunk). */
            UInt32 mSize;
        };
    }
}

#endif // __MURL_UTIL_IFF_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_MEMORY_STREAM_H__
#define __MURL_UTIL_MEMORY_STREAM_H__

#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief The memory stream class.
         * The MemoryStream class implements file behaviour on a memory block.
         * The memory to read from is used by reference only, which allows
         * using memory mapped files without copying the data to memory.
         *
         * (!) The ownership of the data object's memory pointer remains to
         * the caller. This means as long as the MemoryStream is used, the memory
         * pointer of the data object (but probably not to data object itself)
         * must be available in memory.
         */
        class MemoryStream
        {
        public:
            /**
             * @brief The default constructor.
             */
            MemoryStream();
            /**
             * @brief The destructor.
             */
            virtual ~MemoryStream();
            
            /**
             * @brief Open a memory stream from a data object.
             * @param data The data object.
             * @return true if successful.
             */
            virtual Bool Open(const ConstData& data);
            /**
             * @brief Open a memory stream.
             * @param data Pointer to the memory location.
             * @param byteSize Byte size of the memory location.
             * @return true if successful.
             */
            virtual Bool Open(const void* data, UInt64 byteSize);
            /**
             * @brief Close the memory stream.
             * @return true if successful.
             */
            virtual Bool Close();
            
            /**
             * @brief Check if the memory stream is open.
             * @return true if the memory stream is open.
             */
            Bool IsOpen() const;
            /**
             * @brief Get the size of the memory stream.
             * @return The byte size of the memory stream.
             */
            virtual UInt64 GetSize() const;
            
            /**
             * @brief Get the current read position.
             * @return The current read position in bytes.
             */
            virtual UInt64 GetPosition() const;
            /**
             * @brief Set the current read position.
             * @param position The current read in bytes.
             */
            virtual void SetPosition(UInt64 position);
            
            /**
             * @brief Read from the memory stream at the current position.
             * @param data Pointer to the memory to read into.
             * @param byteSize The byte size of the memory.
             * @return The number of bytes read from the memory stream.
             */
            virtual UInt64 Read(void* data, UInt64 byteSize);
            
            /**
             * @brief Check if the end of the stream is reached.
             * @return true if the end of the stream is reached.
             */
            virtual Bool Eos() const;
            
        protected:
            /** @brief Reference to the memory data. */
            ConstData mData;
            /** @brief The open status. */
            Bool mIsOpen;
            /** @brief The current byte position. */
            UInt64 mCurrentOffset;
        };
    }
}

#endif // __MURL_UTIL_MEMORY_STREAM_H__

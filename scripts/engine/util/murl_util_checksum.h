// Copyright 2011-2012 Spraylight GmbH

#ifndef __MURL_UTIL_CHECKSUM_H__
#define __MURL_UTIL_CHECKSUM_H__

#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief The MD5 checksum class.
         */
        class MD5Checksum
        {
        public:
            /** @brief Constants. */
            enum
            {
                /** @brief The byte size of the MD5 Checksum. */
                CHECKSUM_BYTE_SIZE = 16
            };
            
            /**
             * @brief The default constructor.
             */
            MD5Checksum();
            
            /**
             * @brief Calculate the MD5 checksum from a memory block.
             * @param srcData Pointer to the source memory block.
             * @param srcByteSize The byte size of the memory block.
             * @return A pointer to the checksum, the byte size of the
             *  checksum is defined by CHECKSUM_BYTE_SIZE.
             */
            const UInt8* Calculate(const void* srcData, UInt64 srcByteSize);
            
            /**
             * @brief Calculate the MD5 checksum from a data object.
             * @param data The source data object.
             * @return The checksum data object.
             */
            const ConstData& Calculate(const ConstData& data);
            
            /**
             * @brief Calculate the MD5 checksum from a string.
             * @param srcString The source string object.
             * @return The hex-encoded checksum string.
             */
            String CalculateHex(const String& srcString);
            
            /**
             * @brief Calculate the MD5 checksum from a data object.
             * @param data The source data object.
             * @return The hex-encoded checksum string.
             */
            String CalculateHex(const ConstData& data);
            
            /**
             * @brief Get the hex-encoded checksum string
             * from the recent checksum calculation.
             * @return The hex-encoded checksum string.
             */
            String GetChecksumHex() const;
            
            /**
             * @brief Get the checksum data object
             *  from the recent checksum calculation.
             * @return The checksum data object.
             */
            const ConstData& GetChecksum() const;
            
        protected:
            /** @brief The data object holding the checksum. */
            Data mDigest;
        };

        /**
         * @ingroup MurlUtilClasses
         * @brief The CRC32 checksum class.
         */
        class CRC32Checksum
        {
        public:
            /**
             * @brief The default constructor.
             */
            CRC32Checksum();
            
            /**
             * @brief Calculate the CRC32 checksum from a memory block.
             * @param srcData Pointer to the source memory block.
             * @param srcByteSize The byte size of the memory block.
             * @return The 32bit checksum value
             */
            UInt32 Calculate(const void* srcData, UInt64 srcByteSize);
            
            /**
             * @brief Calculate the CRC32 checksum from a data object.
             * @param data The source data object.
             * @return The 32bit checksum value
             */
            UInt32 Calculate(const ConstData& data);
            
            /**
             * @brief Calculate the MD5 checksum from a string.
             * @param srcString The source string object.
             * @return The hex-encoded checksum string.
             */
            String CalculateHex(const String& srcString);
            
            /**
             * @brief Calculate the MD5 checksum from a data object.
             * @param data The source data object.
             * @return The hex-encoded checksum string.
             */
            String CalculateHex(const ConstData& data);
            
            /**
             * @brief Get the hex-encoded checksum string
             * from the recent checksum calculation.
             * @return The hex-encoded checksum string.
             */
            String GetChecksumHex() const;
            
            /**
             * @brief Get the checksum from the recent checksum calculation.
             * @return The 32bit checksum value
             */
            UInt32 GetChecksum() const;
            
        protected:
            UInt32 mChecksum;
        };
    }
}

#endif // __MURL_UTIL_CHECKSUM_H__

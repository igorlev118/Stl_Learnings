// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_HASH_H__
#define __MURL_UTIL_HASH_H__

#include "murl_types.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilNamespaces
         * @brief Basic hash functions.
         */
        namespace Hash
        {
            /**
             * @brief Compute a hash value from a memory block.
             * @param ptr Pointer to the source memory block.
             * @param byteSize The byte size of the memory block.
             * @return The hash value.
             */
            inline UInt32 GetMemoryHashValue(const void* ptr, UInt64 byteSize)
            {
                UInt32 hash = 1234567890U;
                
                const UInt8* start = static_cast<const UInt8*>(ptr);
                const UInt8* end = start + byteSize;
                while (start < end)
                {
                    hash = ((hash << 5) - hash) ^ *start++;
                }
                
                return hash;
            }
            
            /**
             * @brief Compute a hash value from a memory pointer.
             * @param ptr The memory pointer.
             * @return The hash value.
             */
            inline UInt32 GetPointerHashValue(const void* ptr)
            {
#ifdef MURL_TARGET_ARCHITECTURE_64BIT
                UInt64 ptrVal = UInt64(ptr);
                UInt32 hash = 1234567890U;
                hash = ((hash << 4) + hash) ^ UInt32(ptrVal);
                hash = ((hash << 4) + hash) ^ UInt32(ptrVal >> 32);
                return hash;
#else
                return reinterpret_cast<UInt32>(ptr);
#endif
            }
            
            /**
             * @brief Compute a hash value from an object.
             * @param x The object which has implemented a GetHashValue method.
             * @return The hash value.
             */
            template<class DataType>
            inline UInt32 GetHashValue(const DataType& x)
            {
                return x.GetHashValue();
            }
            
            /**
             * @brief Compute a hash value from a shared pointer.
             * @param ptr The shared pointer.
             * @return The hash value.
             */
            template<class DataType>
            inline UInt32 GetHashValue(SharedPointer<DataType> ptr)
            {
                return GetPointerHashValue(ptr.Get());
            }

            /**
             * @brief Compute a hash value from an object pointer.
             * @param ptr The object pointer.
             * @return The hash value.
             */
            template<class DataType>
            inline UInt32 GetHashValue(DataType* ptr)
            {
                return GetPointerHashValue(ptr);
            }

            /**
             * @brief Compute a hash value from a character value.
             * @param x The character value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(Char x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a boolean value.
             * @param x The boolean value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(Bool x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a SInt8 value.
             * @param x The SInt8 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(SInt8 x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a UInt8 value.
             * @param x The UInt8 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(UInt8 x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a SInt16 value.
             * @param x The SInt16 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(SInt16 x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a UInt16 value.
             * @param x The UInt16 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(UInt16 x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a SInt32 value.
             * @param x The SInt32 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(SInt32 x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a UInt32 value.
             * @param x The UInt32 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(UInt32 x)
            {
                return static_cast<UInt32>(x);
            }
            
            /**
             * @brief Compute a hash value from a SInt64 value.
             * @param x The SInt64 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(const SInt64& x)
            {
                return GetMemoryHashValue(&x, sizeof(SInt64));
            }
            
            /**
             * @brief Compute a hash value from a UInt64 value.
             * @param x The UInt64 value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(const UInt64& x)
            {
                return GetMemoryHashValue(&x, sizeof(UInt64));
            }
            
            /**
             * @brief Compute a hash value from a float value.
             * @param x The float value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(const Float& x)
            {
                return GetMemoryHashValue(&x, sizeof(Float));
            }
            
            /**
             * @brief Compute a hash value from a double value.
             * @param x The double value.
             * @return The hash value.
             */
            inline UInt32 GetHashValue(const Double& x)
            {
                return GetMemoryHashValue(&x, sizeof(Double));
            }
        }
    }
}

#endif // __MURL_UTIL_HASH_H__

// Copyright 2010-2016 Spraylight

#ifndef __MURL_UTIL_DEEP_COPY_H__
#define __MURL_UTIL_DEEP_COPY_H__

#include "murl_types.h"
#include <new>

/** @brief Placement new definition. */
#define MURL_PLACEMENT_NEW(ptr) ::new(ptr)

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilNamespaces
         * @brief Object deep copy functions.
         */
        namespace DeepCopy
        {
            /**
             * @brief Placement new an object with default constructor.
             * @param dstPtr The destination memory pointer.
             * @return The destination memory pointer.
             */
            template<class DataType>
            inline DataType* PlacementNew(DataType* dstPtr)
            {
                return MURL_PLACEMENT_NEW(dstPtr) DataType;
            }

            /**
             * @brief Placement new and copy construct an object.
             * @param dstPtr The destination memory pointer.
             * @param value The object to copy.
             * @return The destination memory pointer.
             */
            template<class DataType>
            inline DataType* PlacementNew(DataType* dstPtr, const DataType& value)
            {
                return MURL_PLACEMENT_NEW(dstPtr) DataType(value);
            }

            /**
             * @brief Placement new and default construct an array of objects.
             * @param dstPtr The destination memory start pointer.
             * @param dstEnd The destination memory end pointer.
             */
            template<class DataType>
            inline void PlacementNewArray(DataType* dstPtr, const DataType* dstEnd)
            {
                while (dstPtr < dstEnd)
                {
                    MURL_PLACEMENT_NEW(dstPtr) DataType;
                    dstPtr++;
                }
            }

            /**
             * @brief Destruct an array of objects.
             * @param dstPtr The destination memory start pointer.
             * @param dstEnd The destination memory end pointer.
             */
            template<class DataType>
            inline void DestructArray(DataType* dstPtr, const DataType* dstEnd)
            {
                while (dstPtr < dstEnd)
                {
                    dstPtr->DataType::~DataType();
                    dstPtr++;
                }
            }

            /**
             * @brief Placement new and copy construct an array of objects.
             * Overlapping memory blocks are not supported.
             * @param dstPtr The destination memory pointer.
             * @param srcPtr The source memory start pointer.
             * @param srcEnd The source memory end pointer.
             */
            template<class DataType>
            inline void PlacementNewCopyArray(DataType* dstPtr, const DataType* srcPtr, const DataType* srcEnd)
            {
                while (srcPtr < srcEnd)
                {
                    MURL_PLACEMENT_NEW(dstPtr) DataType(*srcPtr);
                    dstPtr++;
                    srcPtr++;
                }
            }

            /**
             * @brief Placement new and copy construct an array of objects from a single object.
             * @param dstPtr The destination memory start pointer.
             * @param dstEnd The destination memory end pointer.
             * @param value The object to copy.
             */
            template<class DataType>
            inline void PlacementNewFillArray(DataType* dstPtr, const DataType* dstEnd, const DataType& value)
            {
                while (dstPtr < dstEnd)
                {
                    MURL_PLACEMENT_NEW(dstPtr) DataType(value);
                    dstPtr++;
                }
            }
        }
    }
}

#endif // __MURL_UTIL_DEEP_COPY_H__

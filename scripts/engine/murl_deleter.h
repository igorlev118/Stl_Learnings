// Copyright 2012 Spraylight GmbH

#ifndef __MURL_DELETER_H__
#define __MURL_DELETER_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief The default delete functor.
     */
    class Deleter
    {
    public:
        /**
         * @brief Delete the pointer and set the pointer to zero.
         * @param pointer Reference to the pointer to delete.
         */
        template<class DataType>
        void operator()(DataType*& pointer)
        {
            if (pointer != 0)
            {
                delete pointer;
                pointer = 0;
            }
        }
    };
    
    /**
     * @ingroup MurlClasses
     * @brief The default array-delete functor.
     */
    class ArrayDeleter
    {
    public:
        /**
         * @brief Array-delete the pointer and set the pointer to zero.
         * @param arrayPointer Reference to the pointer to array-delete.
         */
        template<class DataType>
        void operator()(DataType*& arrayPointer)
        {
            if (arrayPointer !=  0)
            {
                delete[] arrayPointer;
                arrayPointer = 0;
            }
        }
    };
    
    /**
     * @ingroup MurlClasses
     * @brief The no-delete functor.
     */
    class NoDeleter
    {
    public:
        /**
         * @brief Set the pointer to zero.
         * @param pointer Reference to the pointer to set.
         */
        template<class DataType>
        void operator()(DataType*& pointer)
        {
            pointer = 0;
        }
    };
}

#endif  // __MURL_DELETER_H__

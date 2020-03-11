// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_POOL_H__
#define __MURL_POOL_H__

#include "murl_array.h"
#include "murl_debug_trace.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A pool template class.
     */
    template<class DataType>
    class Pool
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor.
         * Create an empty pool.
         */
        Pool()
        : mTotalNumberOfItems(0)
        {
        }

        /**
         * @brief The destructor.
         */
        ~Pool()
        {
            if (mTotalNumberOfItems != UInt32(mFreeItems.GetCount()))
            {
                MURL_TRACE(1, "Not all items released.");
            }

            for (UInt32 i = 0; i < UInt32(mFreeItems.GetCount()); i++)
            {
                delete mFreeItems[i];
            }
        }

        /**
         * @brief Acquire an item.
         * Get an item from the pool or allocate a new one.
         * @return The item.
         */
        DataType* Acquire()
        {
            if (mFreeItems.GetCount() > 0)
            {
                DataType* item = mFreeItems.Top();
                mFreeItems.Drop();
                return item;
            }

            DataType* item = new DataType();
            mTotalNumberOfItems++;
            return item;
        }

        /**
         * @brief Release an acquired item.
         * Put the item to the pool.
         * @param item The acquired item to put into the pool.
         */
        void Release(DataType* item)
        {
            mFreeItems.Add(item);
        }

        /**
         * @brief Release an array of acquired items.
         * Put the items to the pool.
         * @param items The acquired items to put into the pool.
         */
        void Release(const Array<DataType*>& items)
        {
            mFreeItems.Add(items);
        }

    protected:
        /** The pool array. */
        Array<DataType*> mFreeItems;
        /** The number of created items. */
        UInt32 mTotalNumberOfItems;
    };
}

#endif  // __MURL_POOL_H__

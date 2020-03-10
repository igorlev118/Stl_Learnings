// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_RING_BUFFER_H__
#define __MURL_RING_BUFFER_H__

#include "murl_array.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A ringbuffer template class.
     * The RingBuffer template provides simple ringbuffer functionality
     * including the option to overwrite the first item or
     * to skip adding if the ringbuffer is full.
     *
     * The ringbuffer holds a fixed array of default items which are replaced
     * by used items when calling Add(). Used items can be requested by calling
     * GetCount(), Get() or using the array operator[]().
     * Used items can be removed (replaced by default items) by calling Remove().
     */
    template<class DataType>
    class RingBuffer
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor.
         * Create an empty ringbuffer with capacity 10 and overwrite mode off.
         * All items are initialized using the value type's default constructor.
         */
        RingBuffer()
        : mReadIndex(0)
        , mWriteIndex(0)
        , mRingCount(0)
        , mIsOverwrite(false)
        {
            mBuffer.SetCount(10);
        }

        /**
         * @brief Constructor taking a capacity.
         * Create an empty ringbuffer with a specified capacity
         * and overwrite mode off.
         * All items are initialized using the value type's default constructor.
         * @param count The number of available items in the ringbuffer.
         */
        RingBuffer(UInt32 count)
        : mReadIndex(0)
        , mWriteIndex(0)
        , mRingCount(0)
        , mIsOverwrite(false)
        {
            SetCapacity(count);
        }

        /**
         * @brief Constructor taking a capacity and overwrite mode.
         * Create an empty ringbuffer with a specified capacity
         * and specified overwrite mode.
         * The overwrite mode specifies the behaviour of the Add() operation
         * if the ringbuffer IsFull().
         * All items are initialized using the value type's default constructor.
         * @param count The number of available items in the ringbuffer.
         * @param overwrite If true Add() overwrites the first item,
         * if false Add() returns false.
         */
        RingBuffer(UInt32 count, Bool overwrite)
        : mReadIndex(0)
        , mWriteIndex(0)
        , mRingCount(0)
        , mIsOverwrite(overwrite)
        {
            SetCapacity(count);
        }

        /**
         * @brief Get the ringbuffer's capacity.
         * @return The number of available items in the ringbuffer.
         */
        UInt32 GetCapacity() const
        {
            return mBuffer.GetCount();
        }

        /**
         * @brief Set the ringbuffer's capacity.
         * If the given capacity is smaller than the current capacity,
         * the ringbuffer is cleared.
         * If the given capacity is higher, new items are initialized
         * via the value type's default constructor.
         * If the given capacity is zero, a capacity of 1 is set.
         * @param count The number of available items in the ringbuffer.
         */
        void SetCapacity(UInt32 count)
        {
            if (count == 0)
            {
                count = 1;
            }
            if (count < mBuffer.GetCount())
            {
                Clear();
            }
            mBuffer.SetCount(count);
        }

        /**
         * @brief Check if the ringbuffer is operating in overwrite mode.
         * See SetOverwrite().
         * @return true if the ringbuffer is operating in overwrite mode.
         */
        Bool IsOverwrite() const
        {
            return mIsOverwrite;
        }

        /**
         * @brief Set the ringbuffer overwrite operation mode.
         * Set the behaviour of the Add() operation if the ringbuffer IsFull().
         * @param overwrite If true Add() overwrites the first item,
         * if false Add() returns false.
         */
        void SetOverwrite(Bool overwrite)
        {
            mIsOverwrite = overwrite;
        }

        /**
         * @brief Get the number of used items in the ringbuffer.
         * @return The number of used items in the ringbuffer.
         */
        UInt32 GetCount() const
        {
            return mRingCount;
        }

        /**
         * @brief Clear the ringbuffer.
         * All items are initialized using the value type's default constructor.
         */
        void Clear()
        {
            while (!IsEmpty())
            {
                mBuffer[mReadIndex] = DataType();
                mReadIndex = IncrementIndex(mReadIndex);
                mRingCount--;
            }
            mReadIndex = 0;
            mWriteIndex = 0;
            mRingCount = 0;
        }

        /**
         * @brief Check if the ringbuffer is empty.
         * @return true if the ringbuffer is empty.
         */
        Bool IsEmpty() const
        {
            return mRingCount == 0;
        }

        /**
         * @brief Check if the ringbuffer is full.
         * @return true if the ringbuffer is full.
         */
        Bool IsFull() const
        {
            return mRingCount >= mBuffer.GetCount();
        }

        /**
         * @brief Add a used item at the end of the ringbuffer.
         * The item entry is initialized using the given item's copy constructor.
         * @param item The item to be added at the end of the ringbuffer.
         * @return true if the item was added successful,
         *  false if the overwrite mode is off and the ringbuffer is full.
         */
        Bool Add(const DataType& item)
        {
            if (IsFull())
            {
                if (mIsOverwrite)
                {
                    mReadIndex = IncrementIndex(mReadIndex);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                mRingCount++;
            }
            mBuffer[mWriteIndex] = item;
            mWriteIndex = IncrementIndex(mWriteIndex);
            return true;
        }

        /**
         * @brief Retrieve the first used item from the ringbuffer.
         * @return A reference to the item.
         */
        DataType& Get()
        {
            return mBuffer[mReadIndex];
        }

        /**
         * @brief Retrieve the first used item from the ringbuffer.
         * @return A const reference to the item.
         */
        const DataType& Get() const
        {
            return mBuffer[mReadIndex];
        }

        /**
         * @brief Retrieve an item at a given position from the ringbuffer.
         * A valid index is [0 .. GetCount()].
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& operator[](SInt32 index)
        {
            return mBuffer[(mReadIndex + index) % mBuffer.GetCount()];
        }

        /**
         * @brief Retrieve an item at a given position from the ringbuffer.
         * A valid index is [0 .. GetCount()].
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& operator[](SInt32 index) const
        {
            return mBuffer[(mReadIndex + index) % mBuffer.GetCount()];
        }

        /**
         * @brief Remove the first used item from the ringbuffer.
         * The item is initialized using the value type's default constructor.
         */
        void Remove()
        {
            if (!IsEmpty())
            {
                mBuffer[mReadIndex] = DataType();
                mReadIndex = IncrementIndex(mReadIndex);
                mRingCount--;
            }
        }

    private:
        UInt32 IncrementIndex(UInt32 index) const
        {
            index++;
            if (index >= mBuffer.GetCount())
            {
                index = 0;
            }
            return index;
        }

        Array<DataType> mBuffer;

        UInt32 mReadIndex;
        UInt32 mWriteIndex;
        UInt32 mRingCount;
        Bool mIsOverwrite;
    };
}

#endif  // __MURL_RING_BUFFER_H__

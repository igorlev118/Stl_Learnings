// Copyright 2015-2016 Spraylight

#ifndef __MURL_QUEUE_H__
#define __MURL_QUEUE_H__

#include "murl_array.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic queue template class for moveable objects
     * eg.\ structs or fundamental data types like UInt32, Real, etc.
     * The Queue class works for moveable objects only,
     * use ObjectQueue class for storing non-moveable objects.
     * \n This class is based on the NTL BiVector container, see http://www.ultimatepp.org
     * @tparam DataType The value's data type of the queue.
     */
    template <class DataType>
    class Queue
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

#ifdef MURL_COMPILER_C11
        MURL_STL_INIT_LIST_TYPEDEF(DataType);

        /**
         * @brief The initializer-list constructor.
         * @param initList The initializer-list.
         */
        Queue(InitListType initList)
        : Queue()
        {
            Reserve(SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                Util::DeepCopy::PlacementNew(AddTailImp(), item);
            }
        }

        /**
         * @brief Add an initializer-list at the head of the queue.
         * @param initList The initializer-list to be added.
         */
        void AddHead(InitListType initList)
        {
            Reserve(mNumItems + SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                Util::DeepCopy::PlacementNew(AddHeadImp(), item);
            }
        }

        /**
         * @brief Add an initializer-list at the tail of the queue.
         * @param initList The initializer-list to be added.
         */
        void AddTail(InitListType initList)
        {
            Reserve(mNumItems + SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                Util::DeepCopy::PlacementNew(AddTailImp(), item);
            }
        }
#endif  // MURL_COMPILER_C11

        /**
         * @brief Construct an empty queue.
         */
        Queue()
        : mQueue(0)
        , mStart(0)
        , mNumItems(0)
        , mNumAlloc(0)
        {
        }

        /**
         * @brief Construct a queue from an already existing one, performing a deep copy.
         * @param other The queue to copy.
         */
        Queue(const Queue& other)
        {
            DeepCopy(other);
        }

        /**
         * @brief Destroy the queue and all of its contents.
         */
        ~Queue()
        {
            Free();
        }

        /**
         * @brief Assign the content of another queue to this one, performing a deep copy.
         * @param other The source queue.
         */
        void operator=(const Queue& other)
        {
            if (this != &other)
            {
                Free();
                DeepCopy(other);
            }
        }

        /**
         * @brief Get the number of items in the queue.
         * @return The number of items.
         */
        SInt32 GetCount() const
        {
            return mNumItems;
        }

        /**
         * @brief Check if the queue is empty.
         * @return true if the queue is empty, false otherwise.
         */
        Bool IsEmpty() const
        {
            return mNumItems == 0;
        }

        /**
         * @brief Clear the queue and remove the underlying storage.
         */
        void Clear()
        {
            Free();
            mQueue = 0;
            mStart = 0;
            mNumItems = 0;
            mNumAlloc = 0;
        }

        /**
         * @brief Empty the queue, but keep the underlying storage.
         */
        void Empty()
        {
            Destruct();
            mStart = 0;
            mNumItems = 0;
        }

        /**
         * @brief Add a new item at the head of the queue.
         * The new item entry is initialized using the value type's default constructor.
         * The new item will be at position 0.
         * @return A reference to the newly created item.
         */
        DataType& AddHead()
        {
            return *Util::DeepCopy::PlacementNew(AddHeadImp());
        }

        /**
         * @brief Add a new item at the tail of the queue.
         * The new item entry is initialized using the value type's default constructor.
         * The new item will be at position GetCount() - 1.
         * @return A reference to the newly created item.
         */
        DataType& AddTail()
        {
            return *Util::DeepCopy::PlacementNew(AddTailImp());
        }

        /**
         * @brief Add a given item at the head of the queue.
         * The new item entry is initialized using the given item's copy constructor.
         * The new item will be at position 0.
         * @param item The given item to be inserted at the head of the queue.
         * @return A reference to the newly created item.
         */
        DataType& AddHead(const DataType& item)
        {
            return *Util::DeepCopy::PlacementNew(AddHeadImp(), item);
        }

        /**
         * @brief Add a given item at the tail of the queue.
         * The new item entry is initialized using the given item's copy constructor.
         * The new item will be at position GetCount() - 1.
         * @param item The given item to be inserted at the tail of the queue.
         * @return A reference to the newly created item.
         */
        DataType& AddTail(const DataType& item)
        {
            return *Util::DeepCopy::PlacementNew(AddTailImp(), item);
        }

        /**
         * @brief Get the item at the head of the queue.
         * @return A reference to the item at the head of the queue.
         */
        DataType& Head()
        {
            MURL_ASSERT(mNumItems > 0);
            return mQueue[mStart];
        }

        /**
         * @brief Get the item at the tail of the queue.
         * @return A reference to the item at the tail of the queue.
         */
        DataType& Tail()
        {
            MURL_ASSERT(mNumItems > 0);
            return mQueue[GetEndIndex()];
        }

        /**
         * @brief Get the item at the head of the queue.
         * @return A const reference to the item at the head of the queue.
         */
        const DataType& Head() const
        {
            MURL_ASSERT(mNumItems > 0);
            return mQueue[mStart];
        }

        /**
         * @brief Get the item at the tail of the queue.
         * @return A const reference to the item at the tail of the queue.
         */
        const DataType& Tail() const
        {
            MURL_ASSERT(mNumItems > 0);
            return mQueue[GetEndIndex()];
        }

        /**
         * @brief Drop the item from the head of the queue and get a copy of the item.
         * @return A copy of the removed item.
         */
        DataType DropGetHead()
        {
            DataType ret = Head();
            DropHead();
            return ret;
        }

        /**
         * @brief Drop the item from the tail of the queue and get a copy of the item.
         * @return A copy of the removed item.
         */
        DataType DropGetTail()
        {
            DataType ret = Tail();
            DropTail();
            return ret;
        }

        /**
         * @brief Drop the item from the head of the queue.
         */
        void DropHead()
        {
            (&Head())->DataType::~DataType();
            mNumItems--;
            mStart = GetIndex(1);
        }

        /**
         * @brief Drop the item from the tail of the queue.
         */
        void DropTail()
        {
            (&Tail())->DataType::~DataType();
            mNumItems--;
        }

        /**
         * @brief Drop a specified number of items from the head of the queue.
         * @param n The number of items to remove from the head.
         */
        void DropHead(SInt32 n)
        {
            while (n-- > 0)
            {
                DropHead();
            }
        }

        /**
         * @brief Drop a specified number of items from the tail of the queue.
         * @param n The number of items to remove from the tail.
         */
        void DropTail(SInt32 n)
        {
            while (n-- > 0)
            {
                DropTail();
            }
        }

        /**
         * @brief Retrieve the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& operator[](SInt32 index) const
        {
            return GetImp(index);
        }

        /**
         * @brief Retrieve the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& operator[](SInt32 index)
        {
            return GetImp(index);
        }

        /**
         * @brief Get the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& Get(SInt32 index)
        {
            return GetImp(index);
        }

        /**
         * @brief Get the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& Get(SInt32 index) const
        {
            return GetImp(index);
        }

        /**
         * @brief Shrink the queue so that the underlying storage is only as large as necessary.
         */
        void Shrink()
        {
            MURL_ASSERT(mNumItems >= 0);
            if (mNumItems < mNumAlloc)
            {
                ReAlloc(mNumItems);
            }
        }

        /**
         * @brief Reserve storage space.
         * If the given size is less than the actual size, nothing is done.
         * @param n The number of items the underlying storage should hold.
         */
        void Reserve(SInt32 n)
        {
            MURL_ASSERT(mNumItems >= 0);
            n += mNumItems;
            if (n > mNumAlloc)
            {
                ReAlloc(n);
            }
        }

        /**
         * @brief Get the number of actually allocated items.
         * @return The number of allocated items.
         */
        SInt32 GetAlloc() const
        {
            return mNumAlloc;
        }

        /**
         * @brief Compare the queue to another one.
         * @param other The queue to compare.
         * @return true if both queue have identical contents.
         */
        Bool IsEqual(const Queue& other) const
        {
            if (mNumItems != other.mNumItems)
            {
                return false;
            }
            for (UInt32 i = 0; i < mNumItems; i++)
            {
                if (!(mQueue[GetIndex(i)] == other[i]))
                {
                    return false;
                }
            }
            return true;
        }

        /**
         * @brief The "equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side queue to compare.
         * @return true if both queues have identical contents.
         */
        bool operator==(const Queue& rhs) const
        {
            return IsEqual(rhs);
        }
        /**
         * @brief The "not equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side queue to compare.
         * @return true if the queues differ.
         */
        bool operator!=(const Queue& rhs) const
        {
            return !IsEqual(rhs);
        }

        /**
         * @brief Exchange the content of the queue with a given second one.
         * @param other The second queue.
         */
        void Swap(Queue& other)
        {
            Util::Swap(mQueue, other.mQueue);
            Util::Swap(mStart, other.mStart);
            Util::Swap(mNumItems, other.mNumItems);
            Util::Swap(mNumAlloc, other.mNumAlloc);
        }

        /**
         * @brief Definition of the const iterator.
         */
        class ConstIterator
        {
        public:
            ConstIterator(const Queue<DataType>* iter, SInt32 index)
            : mIter(iter)
            , mIndex(index)
            {
            }

            const DataType& operator*() const           { return (*mIter)[mIndex]; }
            const DataType* operator->() const          { return &(*mIter)[mIndex]; }
            const DataType& operator[](int i) const     { return (*mIter)[mIndex + i]; }

            ConstIterator& operator++()                 { mIndex++; return *this; }
            ConstIterator& operator--()                 { mIndex--; return *this; }
            ConstIterator operator++(int)               { ConstIterator t = *this; mIndex++; return t; }
            ConstIterator operator--(int)               { ConstIterator t = *this; mIndex--; return t; }

            ConstIterator& operator+=(int i)            { mIndex += i; return *this; }
            ConstIterator& operator-=(int i)            { mIndex -= i; return *this; }

            ConstIterator operator+(int i) const        { return ConstIterator(*mIter, mIndex + i); }
            ConstIterator operator-(int i) const        { return ConstIterator(*mIter, mIndex - i); }

            int operator-(ConstIterator rhs) const      { return int(mIndex - rhs.mIndex); }

            bool operator==(ConstIterator rhs) const    { return mIndex == rhs.mIndex; }
            bool operator!=(ConstIterator rhs) const    { return mIndex != rhs.mIndex; }
            bool operator<(ConstIterator rhs) const     { return mIndex < rhs.mIndex; }
            bool operator>(ConstIterator rhs) const     { return mIndex > rhs.mIndex; }
            bool operator<=(ConstIterator rhs) const    { return mIndex <= rhs.mIndex; }
            bool operator>=(ConstIterator rhs) const    { return mIndex >= rhs.mIndex; }

            operator bool() const                       { return (mIndex < 0); }

        protected:
            const Queue<DataType>* mIter;
            SInt32 mIndex;
        };

        /**
         * @brief Get the const iterator to the first item.
         * @return The const iterator to the first item.
         */
        ConstIterator Begin() const
        {
            return ConstIterator(this, 0);
        }

        /**
         * @brief Get the const iterator next to the last item.
         * @return The const iterator next to the last item.
         */
        ConstIterator End() const
        {
            return ConstIterator(this, GetCount());
        }

        /**
         * @brief Get the const iterator of a specified index.
         * @param index The index for the iterator.
         * @return The const iterator or null if the index is out of range.
         */
        ConstIterator GetIter(SInt32 index) const
        {
            return ConstIterator(this, index);
        }

        /**
         * @brief Definition of the iterator.
         */
        class Iterator
        {
        public:
            Iterator(Queue<DataType>* iter, SInt32 index)
            : mIter(iter)
            , mIndex(index)
            {
            }

            DataType& operator*()                       { return (*mIter)[mIndex]; }
            DataType* operator->()                      { return &(*mIter)[mIndex]; }
            DataType& operator[](int i)                 { return (*mIter)[mIndex + i]; }

            const DataType& operator*() const        { return (*mIter)[mIndex]; }
            const DataType *operator->() const       { return &(*mIter)[mIndex]; }
            const DataType& operator[](int i) const  { return (*mIter)[mIndex + i]; }

            Iterator& operator++()           { ++mIndex; return *this; }
            Iterator& operator--()           { --mIndex; return *this; }
            Iterator  operator++(int)        { Iterator t = *this; ++mIndex; return t; }
            Iterator  operator--(int)        { Iterator t = *this; --mIndex; return t; }

            Iterator& operator+=(int i)      { mIndex += i; return *this; }
            Iterator& operator-=(int i)      { mIndex -= i; return *this; }

            Iterator  operator+(int i) const { return Iterator(*mIter, mIndex + i); }
            Iterator  operator-(int i) const { return Iterator(*mIter, mIndex - i); }

            int  operator-(const Iterator& rhs) const     { return mIndex - rhs.mIndex; }

            bool operator==(const Iterator& rhs) const  { return mIndex == rhs.mIndex; }
            bool operator!=(const Iterator& rhs) const  { return mIndex != rhs.mIndex; }
            bool operator<(const Iterator& rhs) const   { return mIndex < rhs.mIndex; }
            bool operator>(const Iterator& rhs) const   { return mIndex > rhs.mIndex; }
            bool operator<=(const Iterator& rhs) const  { return mIndex <= rhs.mIndex; }
            bool operator>=(const Iterator& rhs) const  { return mIndex >= rhs.mIndex; }

            operator bool() const                       { return (mIndex < 0); }

        protected:
            Queue<DataType>* mIter;
            SInt32 mIndex;
        };

        /**
         * @brief Get the iterator to the first item.
         * @return The iterator to the first item.
         */
        Iterator Begin()
        {
            return Iterator(this, 0);
        }

        /**
         * @brief Get the iterator next to the last item.
         * @return The iterator next to the last item.
         */
        Iterator End()
        {
            return Iterator(this, GetCount());
        }

        /**
         * @brief Get the iterator of a specified index.
         * @param index The index for the iterator.
         * @return The iterator or null if the index is out of range.
         */
        Iterator GetIter(SInt32 index)
        {
            return Iterator(this, index);
        }

#ifdef MURL_COMPILER_C11
        MURL_STL_CONST_ITERATOR
        MURL_STL_ITERATOR
#endif // MURL_COMPILER_C11

    private:
        SInt32 GetIndex(SInt32 index) const
        {
            index += mStart;
            if (index >= mNumAlloc)
            {
                index -= mNumAlloc;
            }
            return index;
        }

        SInt32 GetEndIndex() const
        {
            return GetIndex(mNumItems - 1);
        }

        DataType& GetImp(SInt32 index) const
        {
            MURL_ASSERT((index >= 0) && (index < mNumItems));
            return mQueue[GetIndex(index)];
        }

        void ReAlloc(SInt32 newalloc)
        {
            MURL_ASSERT((mNumItems <= newalloc) && (mNumItems >= 0));
            DataType* newvector = newalloc ? (DataType*)new UInt8[newalloc * sizeof(DataType)] : 0;
            if (mNumItems)
            {
                SInt32 end = mStart + mNumItems;
                if (end <= mNumAlloc)
                {
                    System::CLib::MemCopy(newvector, mQueue + mStart, (end - mStart) * sizeof(DataType));
                }
                else
                {
                    System::CLib::MemCopy(newvector, mQueue + mStart, (mNumAlloc - mStart) * sizeof(DataType));
                    System::CLib::MemCopy(newvector + mNumAlloc - mStart, mQueue, (end - mNumAlloc) * sizeof(DataType));
                }
                delete[] (UInt8*)mQueue;
            }
            mQueue = newvector;
            mNumAlloc = newalloc;
            mStart = 0;
        }

        void AddImp()
        {
            MURL_ASSERT(mNumItems >= 0);
            if (mNumItems >= mNumAlloc)
            {
                ReAlloc(Math::Max(2 * mNumItems, 4));
            }
            mNumItems++;
        }

        void DeepCopy(const Queue& src)
        {
            mNumAlloc = mNumItems = src.mNumItems;
            mQueue = mNumAlloc ? (DataType*) new UInt8[mNumAlloc * sizeof(DataType)] : 0;
            if (mNumItems)
            {
                SInt32 end = src.mStart + src.mNumItems;
                if (end <= src.mNumAlloc)
                {
                    Util::DeepCopy::PlacementNewCopyArray(mQueue, src.mQueue + src.mStart, src.mQueue + end);
                }
                else
                {
                    Util::DeepCopy::PlacementNewCopyArray(mQueue, src.mQueue + src.mStart, src.mQueue + src.mNumAlloc);
                    Util::DeepCopy::PlacementNewCopyArray(mQueue + src.mNumAlloc - src.mStart, src.mQueue,
                                                          src.mQueue + end - src.mNumAlloc);
                }
            }
            mStart = 0;
        }

        DataType* AddHeadImp()
        {
            AddImp();
            mStart = GetIndex(mNumAlloc - 1);
            return &mQueue[mStart];
        }

        DataType* AddTailImp()
        {
            AddImp();
            return &mQueue[GetEndIndex()];
        }

        Bool Destruct()
        {
            if (mQueue && (mNumItems >= 0))
            {
                SInt32 end = mStart + mNumItems;
                if (end <= mNumAlloc)
                {
                    Util::DeepCopy::DestructArray(mQueue + mStart, mQueue + end);
                }
                else
                {
                    Util::DeepCopy::DestructArray(mQueue + mStart, mQueue + mNumAlloc);
                    Util::DeepCopy::DestructArray(mQueue, mQueue + end - mNumAlloc);
                }
                return true;
            }
            return false;
        }

        void Free()
        {
            if (Destruct())
            {
                delete[] (UInt8*)mQueue;
            }
        }

        DataType* mQueue;
        SInt32 mStart;
        SInt32 mNumItems;
        SInt32 mNumAlloc;
    };
}

#endif // __MURL_QUEUE_H__

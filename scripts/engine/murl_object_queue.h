// Copyright 2015 Spraylight

#ifndef __MURL_OBJECT_QUEUE_H__
#define __MURL_OBJECT_QUEUE_H__

#include "murl_queue.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic queue template class for non-moveable objects eg.\ NonCopyable classes.
     * The object queue class uses a queue of pointers to the objects, this ensures
     * that the object's memory location is unchanged when modifying the queue.
     * \n This class is based on the NTL BiArray container, see http://www.ultimatepp.org
     * @tparam DataType The value's data type of the queue.
     */
    template <class DataType>
    class ObjectQueue
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
        ObjectQueue(InitListType initList)
        {
            mObjects.Reserve(SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                mObjects.AddTail(new DataType(item));
            }
        }

        /**
         * @brief Add an initializer-list at the head of the queue.
         * @param initList The initializer-list to be added.
         */
        void AddHead(InitListType initList)
        {
            mObjects.Reserve(mObjects.GetCount() + SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                mObjects.AddHead(new DataType(item));
            }
        }

        /**
         * @brief Add an initializer-list at the tail of the queue.
         * @param initList The initializer-list to be added.
         */
        void AddTail(InitListType initList)
        {
            mObjects.Reserve(mObjects.GetCount() + SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                mObjects.AddTail(new DataType(item));
            }
        }
#endif  // MURL_COMPILER_C11

        /**
         * @brief Construct an empty queue.
         */
        ObjectQueue()
        {
        }

        /**
         * @brief Construct a queue from an already existing one, performing a deep copy.
         * @param other The queue to copy.
         */
        ObjectQueue(const ObjectQueue& other)
        {
            DeepCopy(other);
        }

        /**
         * @brief Destroy the queue and all of its contents.
         */
        ~ObjectQueue()
        {
            Free();
        }

        /**
         * @brief Assign the content of another queue to this one, performing a deep copy.
         * @param other The source queue.
         */
        void operator=(const ObjectQueue& other)
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
            return mObjects.GetCount();
        }

        /**
         * @brief Check if the queue is empty.
         * @return true if the queue is empty, false otherwise.
         */
        Bool IsEmpty() const
        {
            return GetCount() == 0;
        }

        /**
         * @brief Clear the queue and remove the underlying storage.
         */
        void Clear()
        {
            Free();
            mObjects.Clear();
        }

        /**
         * @brief Empty the queue, but keep the underlying storage.
         */
        void Empty()
        {
            Free();
            mObjects.Empty();
        }

        /**
         * @brief Add a new item at the head of the queue.
         * The new item entry is initialized using the value type's default constructor.
         * The new item will be at position 0.
         * @return A reference to the newly created item.
         */
        DataType& AddHead()
        {
            return *mObjects.AddHead(new DataType);
        }

        /**
         * @brief Add a new item at the tail of the queue.
         * The new item entry is initialized using the value type's default constructor.
         * The new item will be at position GetCount() - 1.
         * @return A reference to the newly created item.
         */
        DataType& AddTail()
        {
            return *mObjects.AddTail(new DataType);
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
            return *mObjects.AddHead(new DataType(item));
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
            return *mObjects.AddTail(new DataType(item));
        }

        /**
         * @brief Add a new allocated item at the head of the queue.
         * The queue takes the ownership of the item.
         * The new item will be at position 0.
         * @param item The given item to be inserted at the head of the queue.
         * @return A reference to the item.
         */
        DataType& AddHead(DataType* item)
        {
            return *mObjects.AddHead(item);
        }

        /**
         * @brief Add a new allocated item at the tail of the queue.
         * The queue takes the ownership of the item.
         * The new item will be at position GetCount() - 1.
         * @param item The given item to be inserted at the tail of the queue.
         * @return A reference to the item.
         */
        DataType& AddTail(DataType* item)
        {
            return *mObjects.AddTail(item);
        }

        /**
         * @brief Get the item at the head of the queue.
         * @return A reference to the item at the head of the queue.
         */
        DataType& Head()
        {
            return *mObjects.Head();
        }

        /**
         * @brief Get the item at the tail of the queue.
         * @return A reference to the item at the tail of the queue.
         */
        DataType& Tail()
        {
            return *mObjects.Tail();
        }

        /**
         * @brief Get the item at the head of the queue.
         * @return A const reference to the item at the head of the queue.
         */
        const DataType& Head() const
        {
            return *mObjects.Head();
        }

        /**
         * @brief Get the item at the tail of the queue.
         * @return A const reference to the item at the tail of the queue.
         */
        const DataType& Tail() const
        {
            return *mObjects.Tail();
        }

        /**
         * @brief Drop the item from the head of the queue and get a copy of the item.
         * @return A copy of the removed item.
         */
        DataType DropGetHead()
        {
            DataType* item = mObjects.DropGetHead();
            DataType ret = *item;
            delete item;
            return ret;
        }

        /**
         * @brief Drop the item from the tail of the queue and get a copy of the item.
         * @return A copy of the removed item.
         */
        DataType DropGetTail()
        {
            DataType* item = mObjects.DropGetTail();
            DataType ret = *item;
            delete item;
            return ret;
        }

        /**
         * @brief Drop the item from the head of the queue.
         */
        void DropHead()
        {
            delete mObjects.DropGetHead();
        }

        /**
         * @brief Drop the item from the tail of the queue.
         */
        void DropTail()
        {
            delete mObjects.DropGetTail();
        }

        /**
         * @brief Drop a specified number of items from the head of the queue.
         * @param n The number of items to remove from the head.
         */
        void DropHead(SInt32 n)
        {
            while (n-- > 0)
            {
                delete mObjects.DropGetHead();
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
                delete mObjects.DropGetTail();
            }
        }

        /**
         * @brief Removes the item from the head and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @return The pointer to the heap allocated item.
         */
        DataType* DetachHead()
        {
            return mObjects.DropGetHead();
        }

        /**
         * @brief Removes the item from the tail and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @return The pointer to the heap allocated item.
         */
        DataType* DetachTail()
        {
            return mObjects.DropGetTail();
        }

        /**
         * @brief Retrieve the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& operator[](SInt32 index) const
        {
            return *mObjects[index];
        }

        /**
         * @brief Retrieve the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& operator[](SInt32 index)
        {
            return *mObjects[index];
        }

        /**
         * @brief Get the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& Get(SInt32 index)
        {
            return *mObjects[index];
        }

        /**
         * @brief Get the item at a given position from the queue.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& Get(SInt32 index) const
        {
            return *mObjects[index];
        }

        /**
         * @brief Shrink the queue so that the underlying storage is only as large as necessary.
         */
        void Shrink()
        {
            mObjects.Shrink();
        }

        /**
         * @brief Reserve storage space.
         * If the given size is less than the actual size, nothing is done.
         * @param n The number of items the underlying storage should hold.
         */
        void Reserve(SInt32 n)
        {
            mObjects.Reserve(n);
        }

        /**
         * @brief Get the number of actually allocated items.
         * @return The number of allocated items.
         */
        SInt32 GetAlloc() const
        {
            return mObjects.GetAlloc();
        }

        /**
         * @brief Compare the queue to another one.
         * @param other The queue to compare.
         * @return true if both queue have identical contents.
         */
        Bool IsEqual(const ObjectQueue& other) const
        {
            if (GetCount() != other.GetCount())
            {
                return false;
            }
            for (UInt32 i = 0; i < GetCount(); i++)
            {
                if (!(*mObjects[i] == *other.mObjects[i]))
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
        bool operator==(const ObjectQueue& rhs) const
        {
            return IsEqual(rhs);
        }
        /**
         * @brief The "not equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side queue to compare.
         * @return true if the queues differ.
         */
        bool operator!=(const ObjectQueue& rhs) const
        {
            return !IsEqual(rhs);
        }

        /**
         * @brief Exchange the content of the queue with a given second one.
         * @param other The second queue.
         */
        void Swap(ObjectQueue& other)
        {
            mObjects.Swap(other.mObjects);
        }

        /**
         * @brief Definition of the const iterator.
         */
        class ConstIterator
        {
        public:
            ConstIterator(const ObjectQueue<DataType>* iter, SInt32 index)
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
            const ObjectQueue<DataType>* mIter;
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
            Iterator(ObjectQueue<DataType>* iter, SInt32 index)
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
            ObjectQueue<DataType>* mIter;
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
        void Free()
        {
            for (SInt32 i = 0; i < GetCount(); i++)
            {
                delete mObjects[i];
            }
        }

        void DeepCopy(const ObjectQueue<DataType>& src)
        {
            SInt32 n = src.GetCount();
            mObjects.Clear();
            mObjects.Reserve(n);
            for (SInt32 i = 0; i < n; i++)
            {
                mObjects.AddTail(new DataType(src[i]));
            }
        }

        Queue<DataType*> mObjects;
    };
}

#endif // __MURL_OBJECT_QUEUE_H__

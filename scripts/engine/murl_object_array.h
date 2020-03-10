// Copyright 2010-2015 Spraylight

#ifndef __MURL_OBJECT_ARRAY_H__
#define __MURL_OBJECT_ARRAY_H__

#include "murl_array.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic array template class for non-moveable objects eg.\ NonCopyable classes.
     * The object array class uses an array of pointers to the objects, this ensures
     * that the object's memory location is unchanged when modifying the array.
     * \n This class is based on the NTL Array container, see http://www.ultimatepp.org
     * @tparam DataType The value's data type of the array.
     */
    template<class DataType>
    class ObjectArray
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
        ObjectArray(InitListType initList)
        {
            mObjects.Reserve(SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                mObjects.Add(new DataType(item));
            }
        }

        /**
         * @brief Add an initializer-list at the end of the array.
         * @param initList The initializer-list to be added.
         */
        void Add(InitListType initList)
        {
            mObjects.Reserve(mObjects.GetCount() + SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                mObjects.Add(new DataType(item));
            }
        }

        /**
         * @brief Insert a given initializer-list at a given position.
         * The new item entries are initialized using the original items' copy constructors.
         * @param index the zero-based index where the new items should be inserted.
         * @param initList The initializer-list to be inserted.
         * @return true if successful.
         */
        Bool Insert(SInt32 index, InitListType initList)
        {
            SInt32 count = SInt32(initList.size());
            if (mObjects.InsertN(index, count))
            {
                for (const DataType& item : initList)
                {
                    mObjects[index] = new DataType(item);
                    index++;
                }
                return true;
            }
            return false;
        }
#endif  // MURL_COMPILER_C11

        /**
         * @brief Construct an empty array.
         */
        ObjectArray()
        {
        }

        /**
         * @brief Construct an array from an already existing one, performing a deep copy.
         * @param other The array to copy.
         */
        ObjectArray(const ObjectArray& other)
        {
            DeepCopy(other);
        }

        /**
         * @brief Destroy the array and all of its contents.
         */
        ~ObjectArray()
        {
            Free();
        }

        /**
         * @brief Assign the content of another array to this one, performing a deep copy.
         * @param other The source array.
         */
        void operator=(const ObjectArray& other)
        {
            if (this != &other)
            {
                Free();
                DeepCopy(other);
            }
        }

        /**
         * @brief Clear the array and remove the underlying storage.
         */
        void Clear()
        {
            Free();
            mObjects.Clear();
        }

        /**
         * @brief Empty the array, but keep the underlying storage.
         */
        void Empty()
        {
            Free();
            mObjects.Empty();
        }

        /**
         * @brief Shrink the array so that the underlying storage is only as large as necessary.
         */
        void Shrink()
        {
            mObjects.Shrink();
        }

        /**
         * @brief Reduce the array to a given number of items.
         * @param n The new number of items in the array,
         *  must be smaller than the current item count.
         * @return true if successful.
         */
        Bool Trim(SInt32 n)
        {
            if (MURL_VERIFY((n >= 0) && (n <= GetCount())))
            {
                Delete(mObjects.Begin() + n, mObjects.End());
                mObjects.Trim(n);
                return true;
            }
            return false;
        }

        /**
         * @brief Reduce the array by removing a given number of items from the end.
         * @param n The number of items to remove from the end.
         * @return true if successful.
         */
        Bool Drop(SInt32 n = 1)
        {
            return Trim(GetCount() - n);
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
         * @brief Set the actual number of items in the array.
         * If the given number is smaller than the current size, the array is trimmed, and existing
         * items beyond the new size are destroyed. If the given number is higher, new items are
         * initialized via the value type's default constructor. If the given number is also higher
         * than the underlying storage's capacity, the storage is enlarged to hold exactly the
         * requested number of items.
         * @param n The new number of items in the array.
         * @return true if successful.
         */
        Bool SetCount(SInt32 n)
        {
            if (!MURL_VERIFY(n >= 0))
            {
                return false;
            }
            SInt32 lc = mObjects.GetCount();
            Delete(mObjects.Begin() + n, mObjects.End());
            mObjects.SetCount(n);
            Init(mObjects.Begin() + lc, mObjects.Begin() + n);
            return true;
        }

        /**
         * @brief Set the actual number of items in the array.
         * If the given number is smaller than the current size, the array is trimmed, and existing
         * items beyond the new size are destroyed. If the given number is higher, new items are
         * initialized via the given value's copy constructor. If the given number is also higher
         * than the underlying storage's capacity, the storage is enlarged to hold exactly the
         * requested number of items.
         * @param n The new number of items in the array.
         * @param item The value to initialize any newly added items with.
         * @return true if successful.
         */
        Bool SetCount(SInt32 n, const DataType& item)
        {
            if (!MURL_VERIFY(n >= 0))
            {
                return false;
            }
            SInt32 lc = mObjects.GetCount();
            Delete(mObjects.Begin() + n, mObjects.End());
            mObjects.SetCount(n);
            Init(mObjects.Begin() + lc, mObjects.Begin() + n, item);
            return true;
        }

        /**
         * @brief Set the actual number of items in the array and reserve extra storage space.
         * If the given number is smaller than the current size, the array is trimmed, and existing
         * items beyond the new size are destroyed. If the given number is higher, new items are
         * initialized via the value type's default constructor. If the given number is also higher
         * than the underlying storage's capacity, the storage is enlarged and some extra capacity
         * is added.
         * @param n The new number of items in the array.
         * @return true if successful.
         */
        Bool SetCountAndReserve(SInt32 n)
        {
            if (!MURL_VERIFY(n >= 0))
            {
                return false;
            }
            SInt32 lc = mObjects.GetCount();
            Delete(mObjects.Begin() + n, mObjects.End());
            mObjects.SetCountAndReserve(n);
            Init(mObjects.Begin() + lc, mObjects.Begin() + n);
            return true;
        }

        /**
         * @brief Set the actual number of items in the array and reserve extra storage space.
         * If the given number is smaller than the current size, the array is trimmed, and existing
         * items beyond the new size are destroyed. If the given number is higher, new items are
         * initialized via the given value's copy constructor. If the given number is also higher
         * than the underlying storage's capacity, the storage is enlarged and some extra capacity
         * is added.
         * @param n The new number of items in the array.
         * @param item The value to initialize any newly added items with.
         * @return true if successful.
         */
        Bool SetCountAndReserve(SInt32 n, const DataType& item)
        {
            if (!MURL_VERIFY(n >= 0))
            {
                return false;
            }
            SInt32 lc = mObjects.GetCount();
            Delete(mObjects.Begin() + n, mObjects.End());
            mObjects.SetCountAndReserve(n);
            Init(mObjects.Begin() + lc, mObjects.Begin() + n, item);
            return true;
        }

        /**
         * @brief Initialize an item with a given item.
         * @param index The index of the item to set.
         * @param item The source item to copy.
         * @return A reference to the set item.
         */
        DataType& Set(SInt32 index, const DataType& item)
        {
            Set(index, item, 1);
            return *mObjects[index];
        }

        /**
         * @brief Set a new allocated item at a given position.
         * The array takes the ownership of the item.
         * @param index the zero-based index where the new item should be set.
         * @param item The given item to be set.
         * @return A reference to the item.
         */
        DataType& Set(SInt32 index, DataType* item)
        {
            delete mObjects[index];
            mObjects[index] = item;
            return *item;
        }

        /**
         * @brief Initialize a range of items with a given item.
         * @param index The index of the first item to set.
         * @param item The source item to copy.
         * @param count The number of items to set.
         * @return true if successful.
         */
        Bool Set(SInt32 index, const DataType& item, SInt32 count)
        {
            if (!MURL_VERIFY((index >= 0) && (count >= 0)))
            {
                return false;
            }
            if (index + count >= GetCount())
            {
                SetCountAndReserve(index + count);
            }
            for (DataType** ptr = mObjects.Begin() + index; ptr < mObjects.Begin() + index + count; ptr++)
            {
                delete *ptr;
                *ptr = new DataType(item);
            }
            return true;
        }

        /**
         * @brief Fill all items with a given item.
         * @param item The source item to copy.
         */
        void Fill(const DataType& item)
        {
            Set(0, item, GetCount());
        }

        /**
         * @brief Swap two array items.
         * @param index1 The index of the first item.
         * @param index2 The index of the second item.
         */
        void Swap(SInt32 index1, SInt32 index2)
        {
            Util::Swap(mObjects[index1], mObjects[index2]);
        }

        /**
         * @brief Move an item from a source position to a destination position.
         * Removes the item at the source position and inserts it at the destination
         * position without using the copy constructor.
         * @param source The index of the item to move.
         * @param dest The destination index to insert the item.
         */
        void Move(SInt32 source, SInt32 dest)
        {
            DataType* item = mObjects[source];
            mObjects.Remove(source);
            mObjects.Insert(dest - (dest > source)) = item;
        }

        /**
         * @brief Add a new item at the end of the array.
         * The new item entry is initialized using the value type's default constructor.
         * @return A reference to the newly created item.
         */
        DataType& Add()
        {
            DataType* value = new DataType;
            mObjects.Add(value);
            return *value;
        }

        /**
         * @brief Add a given item at the end of the array.
         * The new item entry is initialized using the given item's copy constructor.
         * @param item The given item to be inserted at the end of the array.
         * @return A reference to the newly created item.
         */
        DataType& Add(const DataType& item)
        {
            DataType* value = new DataType(item);
            mObjects.Add(value);
            return *value;
        }

        /**
         * @brief Add a new allocated item at the end of the array.
         * The array takes the ownership of the item.
         * @param item The given item to be inserted at the end of the array.
         * @return A reference to the item.
         */
        DataType& Add(DataType* item)
        {
            mObjects.Add(item);
            return *item;
        }

        /**
         * @brief Create and add an item at the end of the array.
         * @tparam DataTypeT The type of object to create.
         * @return A reference to the newly created item.
         */
        template<class DataTypeT>
        DataTypeT& Create()
        {
            DataTypeT* item = new DataTypeT;
            Add(item);
            return *item;
        }

        /**
         * @brief Add a given array of items at the end of the array.
         * The new item entries are initialized using the original items' copy constructors.
         * @param other The given item array to be inserted.
         * @return true if successful.
         */
        Bool Add(const ObjectArray& other)
        {
            return Insert(GetCount(), other);
        }

        /**
         * @brief Add a subset of given array of items at the end of the array.
         * The new item entries are initialized using the original items' copy constructors.
         * @param other The given source item array.
         * @param offset The index into the source array specifying the first item to copy.
         * @param count The number of source array items to copy.
         * @return true if successful.
         */
        Bool Add(const ObjectArray& other, int offset, int count)
        {
            return Insert(GetCount(), other, offset, count);
        }

        /**
         * @brief Insert a new item at a given position.
         * The new item entry is initialized using the value type's default constructor.
         * @param index the zero-based index where the new item should be inserted.
         * @return A reference to the newly created item.
         */
        DataType& Insert(SInt32 index)
        {
            InsertN(index);
            return *mObjects[index];
        }

        /**
         * @brief Insert a given item at a given position.
         * The new item is initialized using the given item's copy constructor.
         * @param index the zero-based index where the new item should be inserted.
         * @param item The given item to be inserted.
         * @return A reference to the newly created item.
         */
        DataType& Insert(SInt32 index, const DataType& item)
        {
            Insert(index, item, 1);
            return *mObjects[index];
        }

        /**
         * @brief Insert a new allocated item at a given position.
         * The array takes the ownership of the item.
         * @param index the zero-based index where the new item should be inserted.
         * @param item The given item to be inserted.
         * @return A reference to the item.
         */
        DataType& Insert(SInt32 index, DataType* item)
        {
            mObjects.InsertN(index, 1);
            mObjects[index] = item;
            return *item;
        }

        /**
         * @brief Insert a number of copies of a given item at a given position.
         * The new item entries are initialized using the given item's copy constructor.
         * @param index the zero-based index where the new items should be inserted.
         * @param item The given item to be inserted.
         * @param count The number of copies of the given item to insert.
         * @return true if successful.
         */
        Bool Insert(SInt32 index, const DataType& item, SInt32 count)
        {
            if (mObjects.InsertN(index, count))
            {
                Init(mObjects.Begin() + index, mObjects.Begin() + index + count, item);
                return true;
            }
            return false;
        }

        /**
         * @brief Insert a given number of new items at a given position.
         * The new item entries are initialized using the value type's default constructor.
         * @param index the zero-based index where the new items should be inserted.
         * @param count The number of new items to be inserted.
         * @return true if successful.
         */
        Bool InsertN(SInt32 index, SInt32 count = 1)
        {
            if (mObjects.InsertN(index, count))
            {
                Init(mObjects.Begin() + index, mObjects.Begin() + index + count);
                return true;
            }
            return false;
        }

        /**
         * @brief Insert a given array of items at a given position.
         * The new item entries are initialized using the original items' copy constructors.
         * @param index the zero-based index where the new items should be inserted.
         * @param other The given item array to be inserted.
         * @return true if successful.
         */
        Bool Insert(SInt32 index, const ObjectArray& other)
        {
            if (other.IsEmpty())
            {
                return false;
            }
            return Insert(index, other, 0, other.GetCount());
        }

        /**
         * @brief Insert a subset of given array of items at a given position.
         * The new item entries are initialized using the original items' copy constructors.
         * @param index the zero-based index where the new items should be inserted.
         * @param other The given source item array.
         * @param offset The index into the source array specifying the first item to copy.
         * @param count The number of source array items to copy.
         * @return true if successful.
         */
        Bool Insert(SInt32 index, const ObjectArray& other, SInt32 offset, SInt32 count)
        {
            if (mObjects.InsertN(index, count))
            {
                for(SInt32 q = 0; q < count; q++)
                {
                    mObjects[q + index] = new DataType(other[q + offset]);
                }
                return true;
            }
            return false;
        }

        /**
         * @brief Remove (and destroy) a number of items at a given position.
         * @param index The zero-based index from where to remove the items.
         * @param count The number of items to remove.
         * @return true if successful.
         */
        Bool Remove(SInt32 index, SInt32 count = 1)
        {
            if (!MURL_VERIFY(((index + count) <= GetCount()) && (count >= 0) && (index >= 0)))
            {
                return false;
            }
            Delete(mObjects.Begin() + index, mObjects.Begin() + index + count);
            mObjects.Remove(index, count);
            return true;
        }

        /**
         * @brief Remove (and destroy) a number of items at given positions.
         * @param sortedIndices A pointer to sorted indices where to remove the items.
         * @param count The number of items to remove, i.e. the number of indices.
         */
        void Remove(const SInt32* sortedIndices, SInt32 count)
        {
            const SInt32* q = sortedIndices;
            const SInt32* e = sortedIndices + count;
            while (q < e)
            {
                MURL_ASSERT((*q >= 0) && (*q < GetCount()));
                delete mObjects[*q++];
            }
            mObjects.Remove(sortedIndices, count);
        }

        /**
         * @brief Remove (and destroy) a number of items at given positions.
         * @param sortedIndices A sorted array of indices where to remove the items.
         */
        void Remove(const SInt32Array& sortedIndices)
        {
            Remove(sortedIndices, sortedIndices.GetCount());
        }

        /**
         * @brief Find the first occurrence of a given item in the array.
         * @param item The item to find.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 Find(const DataType& item) const
        {
            for (SInt32 i = 0; i < GetCount(); i++)
            {
                if (*mObjects[i] == item)
                {
                    return i;
                }
            }
            return -1;
        }

        /**
         * @brief Find the first occurrence of a given item in the array.
         * @param item The item to find.
         * @param firstIndex The index where to start searching.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 Find(const DataType& item, SInt32 firstIndex) const
        {
            if (firstIndex >= 0)
            {
                for (SInt32 i = firstIndex; i < GetCount(); i++)
                {
                    if (*mObjects[i] == item)
                    {
                        return i;
                    }
                }
            }
            return -1;
        }

        /**
         * @brief Find the last occurrence of a given item in the array.
         * @param item The item to find.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 FindLast(const DataType& item) const
        {
            for (SInt32 i = (GetCount() - 1); i >= 0; i--)
            {
                if (*mObjects[i] == item)
                {
                    return i;
                }
            }
            return -1;
        }

        /**
         * @brief Find the last occurrence of a given item in the array.
         * @param item The item to find.
         * @param lastIndex The index where to start searching.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 FindLast(const DataType& item, SInt32 lastIndex) const
        {
            if (lastIndex < GetCount())
            {
                for (SInt32 i = lastIndex; i >= 0; i--)
                {
                    if (*mObjects[i] == item)
                    {
                        return i;
                    }
                }
            }
            return -1;
        }

        /**
         * @brief Retrieve the first item from the array.
         * @return A reference to the first item.
         */
        DataType& Bottom()
        {
            return *mObjects[0];
        }

        /**
         * @brief Retrieve the first item from the array.
         * @return A const reference to the first item.
         */
        const DataType& Bottom() const
        {
            return *mObjects[0];
        }

        /**
         * @brief Retrieve the last item from the array.
         * @return A reference to the last item.
         */
        DataType& Top()
        {
            return *mObjects[GetCount() - 1];
        }

        /**
         * @brief Retrieve the last item from the array.
         * @return A const reference to the last item.
         */
        const DataType& Top() const
        {
            return *mObjects[GetCount() - 1];
        }

        /**
         * @brief Retrieve the item at a given position from the array.
         * If the given index is greater than the actual array size,
         * the array is enlarged as needed, using the value type's
         * default constructor for initializing.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& At(SInt32 index)
        {
            if (index >= GetCount())
            {
                SetCountAndReserve(index + 1);
            }
            return *mObjects[index];
        }

        /**
         * @brief Retrieve the item at a given position from the array.
         * If the given index is greater than the actual array size,
         * the array is enlarged as needed, using the given reference
         * item's copy constructor for initializing.
         * @param index The zero-based index of the item to retrieve.
         * @param item The reference item used for initialization.
         * @return A reference to the specified item.
         */
        DataType& At(SInt32 index, const DataType& item)
        {
            if (index >= GetCount())
            {
                SetCountAndReserve(index + 1, item);
            }
            return *mObjects[index];
        }

        /**
         * @brief Get the number of items in the array.
         * @return The number of items.
         */
        SInt32 GetCount() const
        {
            return mObjects.GetCount();
        }

        /**
         * @brief Check if the array is empty.
         * @return true if the array is empty, false otherwise.
         */
        Bool IsEmpty() const
        {
            return mObjects.IsEmpty();
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
         * @brief Compare the array to another one.
         * @param other The array to check against.
         * @return True if both arrays have identical contents.
         */
        Bool IsEqual(const ObjectArray& other) const
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
         * @brief Check if a given index is a valid index.
         * @param index The index to check.
         * @return true if index >= 0 and index < GetCount().
         */
        Bool IsIndexValid(SInt32 index) const
        {
            return mObjects.IsIndexValid(index);
        }

        /**
         * @brief Retrieve the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& operator[](SInt32 index)
        {
            return *mObjects[index];
        }

        /**
         * @brief Retrieve the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& operator[](SInt32 index) const
        {
            return *mObjects[index];
        }

        /**
         * @brief Get the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& Get(SInt32 index)
        {
            return *mObjects[index];
        }

        /**
         * @brief Get the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& Get(SInt32 index) const
        {
            return *mObjects[index];
        }

        /**
         * @brief Removes the item at a given position and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @param index The zero-based index of the item to remove.
         * @return The pointer to the heap allocated item.
         */
        DataType* Detach(SInt32 index)
        {
            DataType* obj = mObjects[index];
            mObjects.Remove(index);
            return obj;
        }

        /**
         * @brief Removes the item at the top position and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @return The pointer to the heap allocated item.
         */
        DataType* PopDetach()
        {
            return mObjects.Pop();
        }

        /**
         * @brief Swap the item at a given position with a new allocated item.
         * The array takes the ownership of the item.
         * (!) The client is responsible for deletion of the returned item.
         * @param index The zero-based index of the item to swap.
         * @param newItem The new allocated item to swap into.
         * @return The pointer to the swapped-out heap allocated item.
         */
        DataType* Swap(SInt32 index, DataType* newItem)
        {
            DataType* item = mObjects[index];
            mObjects[index] = newItem;
            return item;
        }

        /**
         * @brief Exchange the content of the array with a given second one.
         * @param other The second array.
         */
        void Swap(ObjectArray& other)
        {
            mObjects.Swap(other.mObjects);
        }

        /**
         * @brief Definition of the const iterator.
         */
        class ConstIterator
        {
        public:
            ConstIterator(DataType*const* iter)
            : mIter(iter)
            {
            }

            const DataType& operator*() const          { return **mIter; }
            const DataType* operator->() const         { return *mIter; }
            const DataType& operator[](int i) const    { return *mIter[i]; }

            ConstIterator& operator++()                 { mIter++; return *this; }
            ConstIterator& operator--()                 { mIter--; return *this; }
            ConstIterator operator++(int)               { ConstIterator t = *this; ++*this; return t; }
            ConstIterator operator--(int)               { ConstIterator t = *this; --*this; return t; }

            ConstIterator& operator+=(int i)            { mIter += i; return *this; }
            ConstIterator& operator-=(int i)            { mIter -= i; return *this; }

            ConstIterator operator+(int i) const        { return mIter + i; }
            ConstIterator operator-(int i) const        { return mIter - i; }

            int operator-(ConstIterator rhs) const      { return (int)(mIter - rhs.mIter); }

            bool operator==(ConstIterator rhs) const    { return mIter == rhs.mIter; }
            bool operator!=(ConstIterator rhs) const    { return mIter != rhs.mIter; }
            bool operator<(ConstIterator rhs) const     { return (mIter < rhs.mIter); }
            bool operator>(ConstIterator rhs) const     { return (mIter > rhs.mIter); }
            bool operator<=(ConstIterator rhs) const    { return (mIter <= rhs.mIter); }
            bool operator>=(ConstIterator rhs) const    { return (mIter >= rhs.mIter); }

            operator bool() const                       { return mIter; }

            operator DataType*const*() const           { return mIter; }

        protected:
            DataType*const* mIter;
        };

        /**
         * @brief Get the const iterator to the first item.
         * @return The const iterator to the first item.
         */
        ConstIterator Begin() const
        {
            return mObjects.Begin();
        }

        /**
         * @brief Get the const iterator next to the last item.
         * @return The const iterator next to the last item.
         */
        ConstIterator End() const
        {
            return mObjects.End();
        }

        /**
         * @brief Get the const iterator of a specified index.
         * @param index The index for the iterator.
         * @return The const iterator or null if the index is out of range.
         */
        ConstIterator GetIter(SInt32 index) const
        {
            return mObjects.GetIter(index);
        }

        /**
         * @brief Get the item index by iterator.
         * (!) Adding or removing items will invalidate iterators.
         * @param iterator The iterator of the item.
         * @return The index of the item, or -1 if the iterator is invalid.
         */
        SInt32 GetIterIndex(ConstIterator iterator) const
        {
            return mObjects.GetIterIndex(iterator);
        }

        /**
         * @brief Definition of the iterator.
         */
        class Iterator : public ConstIterator
        {
        public:
            Iterator(DataType** iter)
            : ConstIterator(iter)
            {
            }

            DataType& operator*()                      { return **ConstIterator::mIter; }
            DataType* operator->()                     { return *ConstIterator::mIter; }
            DataType& operator[](int i)                { return *ConstIterator::mIter[i]; }

            const DataType& operator*() const          { return **ConstIterator::mIter; }
            const DataType* operator->() const         { return *ConstIterator::mIter; }
            const DataType& operator[](int i) const    { return *ConstIterator::mIter[i]; }

            Iterator& operator++()                      { ConstIterator::mIter++; return *this; }
            Iterator& operator--()                      { ConstIterator::mIter--; return *this; }
            Iterator operator++(int)                    { Iterator t = *this; ++*this; return t; }
            Iterator operator--(int)                    { Iterator t = *this; --*this; return t; }

            Iterator& operator+=(int i)                 { ConstIterator::mIter += i; return *this; }
            Iterator& operator-=(int i)                 { ConstIterator::mIter -= i; return *this; }

            Iterator operator+(int i) const             { return ConstIterator::mIter + i; }
            Iterator operator-(int i) const             { return ConstIterator::mIter - i; }

            int operator-(Iterator x) const             { return ConstIterator::operator-(x); }

            operator DataType**() const                { return const_cast<DataType**>(ConstIterator::mIter); }
        };

        /**
         * @brief Get the iterator to the first item.
         * @return The iterator to the first item.
         */
        Iterator Begin()
        {
            return mObjects.Begin();
        }

        /**
         * @brief Get the iterator next to the last item.
         * @return The iterator next to the last item.
         */
        Iterator End()
        {
            return mObjects.End();
        }

        /**
         * @brief Get the iterator of a specified index.
         * @param index The index for the iterator.
         * @return The iterator or null if the index is out of range.
         */
        Iterator GetIter(SInt32 index)
        {
            return mObjects.GetIter(index);
        }

#ifdef MURL_COMPILER_C11
        MURL_STL_CONST_ITERATOR
        MURL_STL_ITERATOR
#endif // MURL_COMPILER_C11

    private:
        void Free()
        {
            for (UInt32 i = 0; i < mObjects.GetCount(); i++)
            {
                delete mObjects[i];
            }
        }

        void DeepCopy(const ObjectArray& src)
        {
            SInt32 n = src.GetCount();
            mObjects.SetCount(n);
            for (UInt32 i = 0; i < n; i++)
            {
                mObjects[i] = new DataType(src[i]);
            }
        }

        void Init(DataType** ptr, DataType** lim)
        {
            while (ptr < lim)
            {
                *ptr++ = new DataType;
            }
        }

        void Init(DataType** ptr, DataType** lim, const DataType& x)
        {
            while (ptr < lim)
            {
                *ptr++ = new DataType(x);
            }
        }

        void Delete(DataType** ptr, DataType** lim)
        {
            while (ptr < lim)
            {
                delete *ptr++;
            }
        }

        Array<DataType*> mObjects;
    };
}

#endif // __MURL_OBJECT_ARRAY_H__

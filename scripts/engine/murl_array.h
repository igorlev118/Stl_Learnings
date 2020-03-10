// Copyright 2010-2016 Spraylight

#ifndef __MURL_ARRAY_H__
#define __MURL_ARRAY_H__

#include "murl_util.h"
#include "murl_util_deep_copy.h"
#include "murl_debug_assert.h"

#ifdef MURL_COMPILER_C11
#   include  <initializer_list>
#   ifdef MURL_COMPILER_VS2013
#       define MURL_STL_NOEXCEPT throw ()
#   else   // MURL_COMPILER_VS
#       define MURL_STL_NOEXCEPT noexcept
#   endif  // MURL_COMPILER_VS
#   define MURL_STL_INIT_LIST_TYPEDEF(dataType) \
    typedef std::initializer_list<dataType> InitListType
#   define MURL_STL_CONST_ITERATOR \
    typedef ConstIterator const_iterator; \
    const_iterator begin() const MURL_STL_NOEXCEPT { return Begin(); } \
    const_iterator end() const MURL_STL_NOEXCEPT { return End(); }
#   define MURL_STL_ITERATOR \
    typedef Iterator iterator; \
    iterator begin() MURL_STL_NOEXCEPT { return Begin(); } \
    iterator end() MURL_STL_NOEXCEPT { return End(); }
#   define MURL_STL_BASE_CONST_ITERATOR(base) \
    typedef typename base::ConstIterator const_iterator; \
    const_iterator begin() const MURL_STL_NOEXCEPT { return base::Begin(); } \
    const_iterator end() const MURL_STL_NOEXCEPT { return base::End(); }
#   define MURL_STL_BASE_ITERATOR(base) \
    typedef typename base::Iterator iterator; \
    iterator begin() MURL_STL_NOEXCEPT { return base::Begin(); } \
    iterator end() MURL_STL_NOEXCEPT { return base::End(); }
#endif  // MURL_COMPILER_C11

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic array template class for moveable objects
     * eg.\ structs or fundamental data types like UInt32, Real, etc.
     * The array class works for moveable objects only,
     * use ObjectArray class for storing non-moveable objects.
     * \n This class is based on the NTL Vector container, see http://www.ultimatepp.org
     * @tparam DataType The value's data type of the array.
     */
    template<class DataType>
    class Array
    {
        template<SInt32 byteSize>
        class Filler
        {
            UInt8 mFiller[byteSize];
        };

    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

#ifdef MURL_COMPILER_C11
        MURL_STL_INIT_LIST_TYPEDEF(DataType);

        /**
         * @brief The initializer-list constructor.
         * @param initList The initializer-list.
         */
        Array(InitListType initList)
        : Array()
        {
            Reserve(SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                Util::DeepCopy::PlacementNew(ReserveNextItem(), item);
            }
        }

        /**
         * @brief Add an initializer-list at the end of the array.
         * @param initList The initializer-list to be added.
         */
        void Add(InitListType initList)
        {
            Reserve(mNumItems + SInt32(initList.size()));
            for (const DataType& item : initList)
            {
                Util::DeepCopy::PlacementNew(ReserveNextItem(), item);
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
            if (count <= 0)
            {
                return false;
            }
            if (MURL_VERIFY((index >= 0) && (index <= mNumItems)))
            {
                if (RawInsert(index, count))
                {
                    for (const DataType& item : initList)
                    {
                        Util::DeepCopy::PlacementNew(mArray + index, item);
                        index++;
                    }
                    return true;
                }
            }
            return false;
        }
#endif  // MURL_COMPILER_C11

        /**
         * @brief Construct an empty array.
         */
        Array()
        : mArray(0)
        , mNumItems(0)
        , mNumAlloc(0)
        {
        }

        /**
         * @brief Construct an array containing a single item.
         * @param item The item.
         */
        Array(const DataType& item)
        : mArray(0)
        , mNumItems(0)
        , mNumAlloc(0)
        {
            Add(item);
        }

        /**
         * @brief Construct an array containing two items.
         * @param item1 The first item.
         * @param item2 The second item.
         */
        Array(const DataType& item1, const DataType& item2)
        : mArray(0)
        , mNumItems(0)
        , mNumAlloc(0)
        {
            Add(item1);
            Add(item2);
        }

        /**
         * @brief Construct an array containing three items.
         * @param item1 The first item.
         * @param item2 The second item.
         * @param item3 The third item.
         */
        Array(const DataType& item1, const DataType& item2, const DataType& item3)
        : mArray(0)
        , mNumItems(0)
        , mNumAlloc(0)
        {
            Add(item1);
            Add(item2);
            Add(item3);
        }

        /**
         * @brief Construct an array from an already existing one, performing a deep copy.
         * @param other The array to copy.
         */
        Array(const Array& other)
        {
            DeepCopy(other);
        }

        /**
         * @brief Destroy the array and all of its contents.
         */
        ~Array()
        {
            Free();
        }

        /**
         * @brief Assign the content of another array to this one, performing a deep copy.
         * @param other The source array.
         */
        void operator=(const Array& other)
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
            mNumAlloc = mNumItems = 0;
            mArray = 0;
        }

        /**
         * @brief Empty the array, but keep the underlying storage.
         */
        void Empty()
        {
            Trim(0);
        }

        /**
         * @brief Shrink the array so that the underlying storage is only as large as necessary.
         */
        void Shrink()
        {
            if (mNumItems != mNumAlloc)
            {
                ReAlloc(mNumItems);
            }
        }

        /**
         * @brief Reduce the array to a given number of items.
         * @param n The new number of items in the array,
         *  must be smaller than the current item count.
         * @return true if successful.
         */
        Bool Trim(SInt32 n)
        {
            if (MURL_VERIFY((n >= 0) && (n <= mNumItems)))
            {
                Util::DeepCopy::DestructArray(mArray + n, mArray + mNumItems);
                mNumItems = n;
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
            return Trim(mNumItems - n);
        }

        /**
         * @brief Reserve storage space.
         * If the given size is less than the actual size, nothing is done.
         * @param n The number of items the underlying storage should hold.
         */
        void Reserve(SInt32 n)
        {
            if (n > mNumAlloc)
            {
                ReAlloc(n);
            }
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
            if (n == mNumItems)
            {
                return true;
            }
            if (n < mNumItems)
            {
                return Trim(n);
            }
            else
            {
                if (n > mNumAlloc)
                {
                    ReAlloc(n);
                }
                Util::DeepCopy::PlacementNewArray(mArray + mNumItems, mArray + n);
                mNumItems = n;
            }
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
            if (n == mNumItems)
            {
                return true;
            }
            if (n < mNumItems)
            {
                Util::DeepCopy::DestructArray(mArray + n, mArray + mNumItems);
            }
            else
            {
                if (n > mNumAlloc)
                {
                    ReAlloc(n);
                }
                Util::DeepCopy::PlacementNewFillArray(mArray + mNumItems, mArray + n, item);
            }
            mNumItems = n;
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
            if (n > mNumAlloc)
            {
                ReAlloc(mNumAlloc + Math::Max(mNumAlloc, n - mNumItems));
            }
            return SetCount(n);
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
            if (n == mNumItems)
            {
                return true;
            }
            if (n < mNumItems)
            {
                Util::DeepCopy::DestructArray(mArray + n, mArray + mNumItems);
            }
            else
            {
                if (n > mNumAlloc)
                {
                    ReAlloc(mNumAlloc + Math::Max(mNumAlloc, n - mNumItems));
                }
                Util::DeepCopy::PlacementNewFillArray(mArray + mNumItems, mArray + n, item);
            }
            mNumItems = n;
            return true;
        }

        /**
         * @brief Initialize an item with a given item.
         * If the given index is greater than the actual array size,
         * the array is enlarged as needed.
         * @param index The index of the item to set.
         * @param item The source item to copy.
         * @return A reference to the set item.
         */
        DataType& Set(SInt32 index, const DataType& item)
        {
            Set(index, item, 1);
            return GetImp(index);
        }

        /**
         * @brief Initialize a range of items with a given item.
         * If the given index plus the count is greater than the actual
         * array size, the array is enlarged as needed.
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
            if (count == 0)
            {
                return true;
            }
            if ((&item >= mArray) && (&item < (mArray + mNumItems)))
            {
                DataType copy = item;
                At(index + count - 1);
                Fill(mArray + index, mArray + index + count, copy);
            }
            else
            {
                At(index + count - 1);
                Fill(mArray + index, mArray + index + count, item);
            }
            return true;
        }

        /**
         * @brief Fill all items with a given item.
         * @param item The source item to copy.
         */
        void Fill(const DataType& item)
        {
            Set(0, item, mNumItems);
        }

        /**
         * @brief Swap two array items.
         * @param index1 The index of the first item.
         * @param index2 The index of the second item.
         */
        void Swap(SInt32 index1, SInt32 index2)
        {
            Util::Swap(GetImp(index1), GetImp(index2));
        }

        /**
         * @brief Add a new item at the end of the array.
         * The new item entry is initialized using the value type's default constructor.
         * @return A reference to the newly created item.
         */
        DataType& Add()
        {
            if (mNumItems >= mNumAlloc)
            {
                Grow();
            }
            return *Util::DeepCopy::PlacementNew(ReserveNextItem());
        }

        /**
         * @brief Add a given item at the end of the array.
         * The new item entry is initialized using the given item's copy constructor.
         * @param item The given item to be inserted at the end of the array.
         * @return A reference to the newly created item.
         */
        DataType& Add(const DataType& item)
        {
            if (mNumItems >= mNumAlloc)
            {
                Grow();
            }
            return *Util::DeepCopy::PlacementNew(ReserveNextItem(), item);
        }

        /**
         * @brief Add a given number of new items at the end of the array.
         * The new item entries are initialized using the value type's default constructor.
         * @param count The number of new items to be inserted at the end of the array.
         */
        void AddN(SInt32 count)
        {
            if ((mNumItems + count) <= mNumAlloc)
            {
                Util::DeepCopy::PlacementNewArray(mArray + mNumItems, mArray + mNumItems + count);
                mNumItems += count;
            }
            else
            {
                SetCountAndReserve(mNumItems + count);
            }
        }

        /**
         * @brief Add a given array of items at the end of the array.
         * The new item entries are initialized using the original items' copy constructors.
         * @param other The given item array to be inserted.
         * @return true if successful.
         */
        Bool Add(const Array& other)
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
        Bool Add(const Array& other, int offset, int count)
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
            return GetImp(index);
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
            return GetImp(index);
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
            if (count <= 0)
            {
                return false;
            }
            if (MURL_VERIFY(!(&item >= mArray && &item < mArray + mNumItems)))
            {
                if (RawInsert(index, count))
                {
                    Util::DeepCopy::PlacementNewFillArray(mArray + index, mArray + index + count, item);
                    return true;
                }
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
            if (count <= 0)
            {
                return false;
            }
            if (MURL_VERIFY((index >= 0) && (index <= mNumItems)))
            {
                if (RawInsert(index, count))
                {
                    Util::DeepCopy::PlacementNewArray(mArray + index, mArray + index + count);
                    return true;
                }
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
        Bool Insert(SInt32 index, const Array& other)
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
        Bool Insert(SInt32 index, const Array& other, SInt32 offset, SInt32 count)
        {
            if (!MURL_VERIFY((offset >= 0) && (count >= 0) && ((offset + count) <= other.GetCount())))
            {
                return false;
            }
            if (!MURL_VERIFY(!mArray || (other.mArray != mArray)))
            {
                return false;
            }
            if (RawInsert(index, count))
            {
                Util::DeepCopy::PlacementNewCopyArray(mArray + index, other.mArray + offset, other.mArray + offset + count);
                return true;
            }
            return false;
        }

        /**
         * @brief Remove (and destroy) an item at a given position and get a copy of the item.
         * @param index The zero-based index from where to remove the item.
         * @return A copy of the removed item.
         */
        DataType RemoveGet(SInt32 index)
        {
            DataType ret = GetImp(index);
            Remove(index);
            return ret;
        }

        /**
         * @brief Remove (and destroy) a number of items at a given position.
         * @param index The zero-based index from where to remove the items.
         * @param count The number of items to remove.
         * @return true if successful.
         */
        Bool Remove(SInt32 index, SInt32 count = 1)
        {
            if (!MURL_VERIFY((index >= 0) && (index <= (mNumItems - count)) && (count >= 0)))
            {
                return false;
            }
            if (count > 0)
            {
                Util::DeepCopy::DestructArray(mArray + index, mArray + index + count);
                System::CLib::MemMove(mArray + index, mArray + index + count, (mNumItems - index - count) * sizeof(DataType));
                mNumItems -= count;
            }
            return true;
        }

        /**
         * @brief Remove (and destroy) a number of items at given positions.
         * @param sortedIndices A pointer to sorted indices where to remove the items.
         * @param count The number of items to remove, i.e. the number of indices.
         */
        void Remove(const SInt32* sortedIndices, SInt32 count)
        {
            if (count <= 0)
            {
                return;
            }
            SInt32 pos = *sortedIndices;
            SInt32 npos = pos;
            for (;;)
            {
                if (!MURL_VERIFY(pos < mNumItems))
                {   // index out of range
                    break;
                }
                if (pos == *sortedIndices)
                {
                    (mArray + pos)->DataType::~DataType();
                    pos++;
                    sortedIndices++;
                    if (--count == 0)
                    {
                        break;
                    }
                    if (!MURL_VERIFY(*sortedIndices >= pos))
                    {   // unsorted indices
                        break;
                    }
                }
                else
                {
                    *((Filler<sizeof(DataType)>*)mArray + npos++) = *((Filler<sizeof(DataType)>*)mArray + pos++);
                }
            }
            while (pos < mNumItems)
            {
                *((Filler<sizeof(DataType)>*)mArray + npos++) = *((Filler<sizeof(DataType)>*)mArray + pos++);
            }
            mNumItems = npos;
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
            for (SInt32 i = 0; i < mNumItems; i++)
            {
                if (mArray[i] == item)
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
                for (SInt32 i = firstIndex; i < mNumItems; i++)
                {
                    if (mArray[i] == item)
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
            for (SInt32 i = (mNumItems - 1); i >= 0; i--)
            {
                if (mArray[i] == item)
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
            if (lastIndex < mNumItems)
            {
                for (SInt32 i = lastIndex; i >= 0; i--)
                {
                    if (mArray[i] == item)
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
            return GetImp(0);
        }

        /**
         * @brief Retrieve the first item from the array.
         * @return A const reference to the first item.
         */
        const DataType& Bottom() const
        {
            return GetImp(0);
        }

        /**
         * @brief Retrieve the last item from the array.
         * @return A reference to the last item.
         */
        DataType& Top()
        {
            return GetImp(mNumItems - 1);
        }

        /**
         * @brief Retrieve the last item from the array.
         * @return A const reference to the last item.
         */
        const DataType& Top() const
        {
            return GetImp(mNumItems - 1);
        }

        /**
         * @brief Remove the last item from the array.
         * @return A copy of the removed item.
         */
        DataType Pop()
        {
            DataType ret = Top();
            Drop();
            return ret;
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
            if (index >= mNumItems)
            {
                SetCountAndReserve(index + 1);
            }
            return GetImp(index);
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
            if (index >= mNumItems)
            {
                SetCountAndReserve(index + 1, item);
            }
            return GetImp(index);
        }

        /**
         * @brief Get the number of items in the array.
         * @return The number of items.
         */
        SInt32 GetCount() const
        {
            return mNumItems;
        }

        /**
         * @brief Check if the array is empty.
         * @return true if the array is empty, false otherwise.
         */
        Bool IsEmpty() const
        {
            return mNumItems == 0;
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
         * @brief Compare the array to another one.
         * @param other The array to compare.
         * @return true if both arrays have identical contents.
         */
        Bool IsEqual(const Array& other) const
        {
            if (mNumItems != other.mNumItems)
            {
                return false;
            }
            for (UInt32 i = 0; i < mNumItems; i++)
            {
                if (!(mArray[i] == other.mArray[i]))
                {
                    return false;
                }
            }
            return true;
        }

        /**
         * @brief The "equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side array to compare.
         * @return true if both arrays have identical contents.
         */
        bool operator==(const Array& rhs) const
        {
            return IsEqual(rhs);
        }

        /**
         * @brief The "not equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side array to compare.
         * @return true if both arrays do not have identical contents.
         */
        bool operator!=(const Array& rhs) const
        {
            return !IsEqual(rhs);
        }

        /**
         * @brief Check if a given index is a valid index.
         * @param index The index to check.
         * @return true if index >= 0 and index < GetCount().
         */
        Bool IsIndexValid(SInt32 index) const
        {
            return (index >= 0) && (index < mNumItems);
        }

        /**
         * @brief Retrieve the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& operator[](SInt32 index)
        {
            return GetImp(index);
        }

        /**
         * @brief Retrieve the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& operator[](SInt32 index) const
        {
            return GetImp(index);
        }

        /**
         * @brief Get the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& Get(SInt32 index)
        {
            return GetImp(index);
        }

        /**
         * @brief Get the item at a given position from the array.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& Get(SInt32 index) const
        {
            return GetImp(index);
        }

        /**
         * @brief Conversion operator to the underlying raw array.
         * @return A pointer to the raw array.
         */
        operator DataType*()
        {
            return mArray;
        }

        /**
         * @brief Conversion operator to the underlying raw array.
         * @return A pointer to the constant raw array.
         */
        operator const DataType*() const
        {
            return mArray;
        }

        /**
         * @brief Get the number of bytes of the underlying raw array.
         * @return The number of bytes of the underlying raw array.
         */
        UInt32 GetByteSize() const
        {
            return UInt32(mNumItems) * sizeof(DataType);
        }

        /**
         * @brief Definition of the const iterator.
         */
        typedef const DataType* ConstIterator;

        /**
         * @brief Get the const iterator to the first item.
         * @return The const iterator to the first item.
         */
        ConstIterator Begin() const
        {
            return mArray;
        }

        /**
         * @brief Get the const iterator next to the last item.
         * @return The const iterator next to the last item.
         */
        ConstIterator End() const
        {
            return mArray + mNumItems;
        }

        /**
         * @brief Get the const iterator of a specified index.
         * @param index The index for the iterator.
         * @return The const iterator or null if the index is out of range.
         */
        ConstIterator GetIter(SInt32 index) const
        {
            if (MURL_VERIFY((index >= 0) && (index <= mNumItems)))
            {
                return Begin() + index;
            }
            return 0;
        }

        /**
         * @brief Get the item index by iterator.
         * (!) Adding or removing items will invalidate iterators.
         * @param iterator The iterator of the item.
         * @return The index of the item, or -1 if the iterator is invalid.
         */
        SInt32 GetIterIndex(ConstIterator iterator) const
        {
            if ((iterator >= Begin()) && iterator < End())
            {
                UIntPtr offs = reinterpret_cast<const UInt8*>(iterator) - reinterpret_cast<const UInt8*>(Begin());
                if ((offs % sizeof(DataType)) == 0)
                {
                    return SInt32(offs / sizeof(DataType));
                }
            }
            return -1;
        }

        /**
         * @brief Exchange the content of the array with a given second one.
         * @param other The second array.
         */
        void Swap(Array& other)
        {
            Util::Swap(mArray, other.mArray);
            Util::Swap(mNumItems, other.mNumItems);
            Util::Swap(mNumAlloc, other.mNumAlloc);
        }

        /**
         * @brief Definition of the iterator.
         */
        typedef DataType* Iterator;

        /**
         * @brief Get the iterator to the first item.
         * @return The iterator to the first item.
         */
        Iterator Begin()
        {
            return mArray;
        }

        /**
         * @brief Get the iterator next to the last item.
         * @return The iterator next to the last item.
         */
        Iterator End()
        {
            return mArray + mNumItems;
        }

        /**
         * @brief Get the iterator of a specified index.
         * @param index The index for the iterator.
         * @return The iterator or null if the index is out of range.
         */
        Iterator GetIter(SInt32 index)
        {
            if (MURL_VERIFY((index >= 0) && (index <= mNumItems)))
            {
                return Begin() + index;
            }
            return 0;
        }

#ifdef MURL_COMPILER_C11
        MURL_STL_CONST_ITERATOR
        MURL_STL_ITERATOR
#endif // MURL_COMPILER_C11

    private:
        DataType* RawAlloc(SInt32 numAlloc) const
        {
            if (numAlloc > 0)
            {
                UInt8* mem = new UInt8[numAlloc * sizeof(DataType)];
                return reinterpret_cast<DataType*>(mem);
            }
            return 0;
        }

        void RawFree(DataType* ptr) const
        {
            if (ptr != 0)
            {
                delete[] reinterpret_cast<UInt8*>(ptr);
            }
        }

        DataType* ReserveNextItem()
        {
            return mArray + mNumItems++;
        }

        void Free()
        {
            if ((mArray != 0) && (mNumItems >= 0))
            {
                Util::DeepCopy::DestructArray(mArray, mArray + mNumItems);
            }
            RawFree(mArray);
        }

        void DeepCopy(const Array& src)
        {
            mNumItems = mNumAlloc = src.mNumItems;
            if (src.mArray != 0)
            {
                mArray = RawAlloc(mNumAlloc);
                Util::DeepCopy::PlacementNewCopyArray(mArray, src.mArray, src.mArray + mNumItems);
            }
            else
            {
                mArray = 0;
            }
        }

        DataType& GetImp(SInt32 index) const
        {
            MURL_ASSERT((index >= 0) && (index < mNumItems));
            return mArray[index];
        }

        Bool RawInsert(int q, int count)
        {
            if (!MURL_VERIFY(count >= 0))
            {
                return false;
            }
            if (!MURL_VERIFY((q >= 0) && (q <= mNumItems)))
            {
                return false;
            }
            if (count == 0)
            {
                return true;
            }
            if ((mNumItems + count) > mNumAlloc)
            {
                mNumAlloc += Math::Max(mNumAlloc, count);
                DataType* newarray = RawAlloc(mNumAlloc);
                if (mArray != 0)
                {
                    System::CLib::MemCopy(newarray, mArray, q * sizeof(DataType));
                    System::CLib::MemCopy(newarray + q + count, mArray + q, (mNumItems - q) * sizeof(DataType));
                    RawFree(mArray);
                }
                mArray = newarray;
            }
            else
            {
                System::CLib::MemMove(mArray + q + count, mArray + q, (mNumItems - q) * sizeof(DataType));
            }
            mNumItems += count;
            return true;
        }

        void ReAlloc(SInt32 numAlloc)
        {
            MURL_ASSERT(numAlloc >= mNumItems);

            DataType* newArray = RawAlloc(numAlloc);
            mNumAlloc = numAlloc;
            if (mArray != 0)
            {
                System::CLib::MemCopy(newArray, mArray, mNumItems * sizeof(DataType));
                RawFree(mArray);
            }
            mArray = newArray;
        }

        void Grow()
        {
            ReAlloc(Math::Max(mNumAlloc + 1, SInt32(mNumAlloc + (UInt32(mNumAlloc) >> 1))));
        }

        void Fill(DataType* dst, const DataType* lim, const DataType& x)
        {
            while (dst < lim)
            {
                *dst++ = x;
            }
        }

        DataType* mArray;
        SInt32 mNumItems;
        SInt32 mNumAlloc;
    };
}

#endif // __MURL_ARRAY_H__

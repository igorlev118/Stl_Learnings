// Copyright 2010-2015 Spraylight

#ifndef __MURL_INDEX_BASE_H__
#define __MURL_INDEX_BASE_H__

#include "murl_hash.h"
#include "murl_util_sort.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic index template base class.
     * The index class stores a number of (not necessarily unique) keys in a hash table.
     * \n This is the base class of the Index and ObjectIndex class.
     * \n This class is based on the NTL AIndex container, see http://www.ultimatepp.org
     * @tparam KeyType The key's data type of the index.
     * @tparam ArrayType The array type of the keys.
     * @tparam HashFunc The hash function of the key.
     */
    template<class KeyType, class ArrayType, class HashFunc>
    class IndexBase
    {
    public:
        /**
         * @brief Clear the index object and remove the underlying storage.
         */
        void Clear()
        {
            mHash.Clear();
            mKeys.Clear();
        }

        /**
         * @brief Clear the hash index.
         */
        void ClearIndex()
        {
            mHash.ClearIndex();
        }

        /**
         * @brief Empty the index object, but keep the underlying storage.
         */
        void Empty()
        {
            mKeys.Empty();
            mHash.Trim(0);
        }

        /**
         * @brief Clear and rebuild the hash index for a given number of items.
         * @param n The number of items to rebuild.
         */
        void RebuildHash(SInt32 n)
        {
            mHash.Reindex(n);
        }

        /**
         * @brief Clear and rebuild the hash index.
         */
        void RebuildHash()
        {
            mHash.Reindex();
        }

        /**
         * @brief Shrink the index object so that the underlying storage
         * is only as large as necessary.
         */
        void Shrink()
        {
            mKeys.Shrink();
            mHash.Shrink();
        }

        /**
         * @brief Reduce the index object to a given number of items.
         * @param n The new number of items in the index,
         *  must be smaller than the current item count.
         */
        void Trim(SInt32 n)
        {
            mKeys.SetCount(n);
            mHash.Trim(n);
        }

        /**
         * @brief Reduce the index object by removing a given number of items from the end.
         * @param n The number of items to remove from the end.
         */
        void Drop(SInt32 n = 1)
        {
            mKeys.Drop(n);
            mHash.Drop(n);
        }

        /**
         * @brief Reserve storage space.
         * If the given size is less than the actual size, nothing is done.
         * @param n The number of items the underlying storage should hold.
         */
        void Reserve(SInt32 n)
        {
            mKeys.Reserve(n);
            mHash.Reserve(n);
        }

        /**
         * @brief Unlink the item at a given index.
         * Unlinked items remain in the Index, but are ignored by any search operations.
         * @param index The index of the item to unlink.
         */
        void Unlink(SInt32 index)
        {
            mHash.Unlink(index);
        }

        /**
         * @brief Unlink all items matching a given key.
         * Unlinked items remain in the Index, but are ignored by any search operations.
         * @param key The key of the item(s) to unlink.
         * @return The number of items that were unlinked.
         */
        SInt32 UnlinkKey(const KeyType& key)
        {
            return UnlinkKey(key, mHashFunc(key));
        }

        /**
         * @brief Unlink all items matching a given key, using a precalculated hash value.
         * Unlinked items remain in the Index, but are ignored by any search operations.
         * @param key The key of the item(s) to unlink.
         * @param hash The precalculated hash value.
         * @return The number of items that were unlinked.
         */
        SInt32 UnlinkKey(const KeyType& key, UInt32 hash)
        {
            SInt32 n = 0;
            SInt32 q = mHash.Find(hash);
            while (q >= 0)
            {
                SInt32 w = q;
                q = mHash.FindNext(q);
                if (key == mKeys[w])
                {
                    mHash.Unlink(w);
                    n++;
                }
            }
            return n;
        }

        /**
         * @brief Check if the item at a given index is unlinked.
         * @param index The index of the item to check.
         * @return true if the specified item is unlinked.
         */
        Bool IsUnlinked(SInt32 index) const
        {
            return mHash.IsUnlinked(index);
        }

        /**
         * @brief Get an array of indices of all unlinked items.
         * @return The array of indices.
         */
        SInt32Array GetUnlinked() const
        {
            return mHash.GetUnlinked();
        }

        /**
         * @brief Remove all unlinked items from the index.
         */
        void Sweep()
        {
            SInt32Array b = mHash.GetUnlinked();
            Util::SortArray(b, true);
            Remove(b);
        }

        /**
         * @brief Replace the item at a specified index using a precomputed hash.
         * @param index The index to set.
         * @param key The value to set.
         * @param hash The precomputed hash.
         * @return A reference to the set item.
         */
        KeyType& Set(SInt32 index, const KeyType& key, UInt32 hash)
        {
            KeyType& ret = mKeys[index];
            ret = key;
            mHash.Set(index, hash);
            return ret;
        }

        /**
         * @brief Replace the item at a specified index.
         * @param index The index to set.
         * @param key The value to set.
         * @return A reference to the set item.
         */
        KeyType& Set(SInt32 index, const KeyType& key)
        {
            return Set(index, key, mHashFunc(key));
        }

        /**
         * @brief Add an item with a precomputed hash value.
         * @param key The item to add.
         * @param hash The precomputed hash.
         * @return A reference to the added item.
         */
        KeyType& Add(const KeyType& key, UInt32 hash)
        {
            KeyType& ret = mKeys.Add(key);
            mHash.Add(hash);
            return ret;
        }

        /**
         * @brief Add an item.
         * @param key The item to add.
         * @return A reference to the added item.
         */
        KeyType& Add(const KeyType& key)
        {
            return Add(key, mHashFunc(key));
        }

        /**
         * @brief Add an item or replace an unlinked item if present,
         * using a precomputed hash value.
         * @param key The item to add.
         * @param hash The precomputed hash.
         * @return The index of the item.
         */
        SInt32 Put(const KeyType& key, UInt32 hash)
        {
            SInt32 q = mHash.Put(hash);
            if (q < 0)
            {
                q = mKeys.GetCount();
                Add(key, hash);
            }
            else
            {
                mKeys[q] = key;
            }
            return q;
        }

        /**
         * @brief Add an item or replace an unlinked item if present.
         * @param key The item to add.
         * @return The index of the item.
         */
        SInt32 Put(const KeyType& key)
        {
            return Put(key, mHashFunc(key));
        }

        /**
         * @brief Find the first occurrence of a given item in the index, or add an item
         * if the item was not found, using a precomputed hash value.
         * @param key The item to search for and add.
         * @param hash The precomputed hash.
         * @return The index of the item.
         */
        SInt32 FindAdd(const KeyType& key, UInt32 hash)
        {
            SInt32 i = Find(key, hash);
            if (i >= 0)
            {
                return i;
            }
            i = mKeys.GetCount();
            Add(key, hash);
            return i;
        }

        /**
         * @brief Find the first occurrence of a given item in the index, or add an item
         * if the item was not found.
         * @param key The item to search for and add.
         * @return The index of the item.
         */
        SInt32 FindAdd(const KeyType& key)
        {
            return FindAdd(key, mHashFunc(key));
        }

        /**
         * @brief Find the first occurrence of a given item or add the item
         * if the item was not found, using a precomputed hash value.
         * Hereby replacing an unlinked element if possible.
         * @param key The item to search for and add.
         * @param hash The precomputed hash.
         * @return The index of the item.
         */
        SInt32 FindPut(const KeyType& key, UInt32 hash)
        {
            SInt32 i = Find(key, hash);
            if (i >= 0)
            {
                return i;
            }
            return Put(key, hash);
        }

        /**
         * @brief Find the first occurrence of a given item or put the item
         * if the item was not found.
         * Hereby replacing an unlinked element if possible.
         * @param key The item to search for and add.
         * @return The index of the item.
         */
        SInt32 FindPut(const KeyType& key)
        {
            return FindPut(key, mHashFunc(key));
        }

        /**
         * @brief Find the first occurrence of a given item using a precomputed hash value.
         * @param key The item to search for.
         * @param hash The precomputed hash.
         * @return The index of the item, or -1 if not found.
         */
        SInt32 Find(const KeyType& key, UInt32 hash) const
        {
            return Find0(key, mHash.Find(hash));
        }

        /**
         * @brief Find the first occurrence of a given item.
         * @param key The item to search for.
         * @return The index of the item, or -1 if not found.
         */
        SInt32 Find(const KeyType& key) const
        {
            return Find(key, mHashFunc(key));
        }

        /**
         * @brief Find the next occurrence of an item that is specified by a given index.
         * @param index The index of the item containing the key to search for.
         * @return The index of the next item, or -1 if not found.
         */
        SInt32 FindNext(SInt32 index) const
        {
            return Find0(mKeys[index], mHash.FindNext(index));
        }

        /**
         * @brief Find the previous occurrence of an item that is specified by a given index.
         * @param index The index of the item containing the key to search for.
         * @return The index of the previous item, or -1 if not found.
         */
        SInt32 FindPrev(SInt32 index) const
        {
            return FindB(mKeys[index], mHash.FindPrev(index));
        }

        /**
         * @brief Find the last occurrence of a given item, using a precomputed hash value.
         * @param key The item to search for.
         * @param hash The precomputed hash value.
         * @return The index of the item, or -1 if not found.
         */
        SInt32 FindLast(const KeyType& key, UInt32 hash) const
        {
            return FindB(key, mHash.FindLast(hash));
        }

        /**
         * @brief Find the last occurrence of a given item.
         * @param key The item to search for.
         * @return The index of the item, or -1 if not found.
         */
        SInt32 FindLast(const KeyType& key) const
        {
            return FindLast(key, mHashFunc(key));
        }

        /**
         * @brief Insert an item at a given position, using a precomputed hash value.
         * @param index The index where to insert the item.
         * @param key The item to insert.
         * @param hash The precomputed hash value.
         * @return A reference to the inserted item.
         */
        KeyType& Insert(SInt32 index, const KeyType& key, UInt32 hash)
        {
            mKeys.Insert(index, key);
            mHash.Insert(index, hash);
            return mKeys[index];
        }

        /**
         * @brief Insert an item at a given position.
         * @param index The index where to insert the item.
         * @param key The item to insert.
         * @return A reference to the inserted item.
         */
        KeyType& Insert(SInt32 index, const KeyType& key)
        {
            mKeys.Insert(index, key);
            mHash.Insert(index, mHashFunc(key));
            return mKeys[index];
        }

        /**
         * @brief Remove the item at a given position.
         * @param index The index from where to remove the item.
         */
        void Remove(SInt32 index)
        {
            mKeys.Remove(index);
            mHash.Remove(index);
        }

        /**
         * @brief Remove a number of items at a given starting position.
         * @param index The index from where to start removing the items.
         * @param count The number of subsequent items to remove.
         */
        void Remove(SInt32 index, SInt32 count)
        {
            mKeys.Remove(index, count);
            mHash.Remove(index, count);
        }

        /**
         * @brief Remove a number of items at given positions.
         * @param sortedIndices A pointer to sorted indices where to remove the items.
         * @param count The number of items to remove, i.e. the number of indices.
         */
        void Remove(const SInt32* sortedIndices, SInt32 count)
        {
            mKeys.Remove(sortedIndices, count);
            mHash.Remove(sortedIndices, count);
        }

        /**
         * @brief Remove a number of items at given positions.
         * @param sortedIndices A sorted array of indices where to remove the items.
         */
        void Remove(const SInt32Array& sortedIndices)
        {
            Remove(sortedIndices, sortedIndices.GetCount());
        }

        /**
         * @brief Remove all items that match a given item, using a precomputed hash value.
         * @param key The item to remove.
         * @param hash The precomputed hash value.
         * @return The number of items that were removed.
         */
        SInt32 RemoveKey(const KeyType& key, UInt32 hash)
        {
            SInt32Array rk;
            SInt32 q = Find(key, hash);
            while (q >= 0)
            {
                rk.Add(q);
                q = FindNext(q);
            }
            Remove(rk);
            return rk.GetCount();
        }

        /**
         * @brief Remove all items that match a given item.
         * @param key The item to remove.
         * @return The number of items that were removed.
         */
        SInt32 RemoveKey(const KeyType& key)
        {
            return RemoveKey(key, mHashFunc(key));
        }

        /**
         * @brief Get a reference to the first item.
         * @return A reference to the first item.
         */
        const KeyType& Bottom() const
        {
            return mKeys.Bottom();
        }

        /**
         * @brief Get a reference to the last item.
         * @return A reference to the last item.
         */
        const KeyType& Top() const
        {
            return mKeys.Top();
        }

        /**
         * @brief Check if a given index is a valid index.
         * @param index The index to check.
         * @return true if index >= 0 and index < GetCount().
         */
        Bool IsIndexValid(SInt32 index) const
        {
            return mKeys.IsIndexValid(index);
        }

        /**
         * @brief Get a const reference to the item at a given index.
         * If the index is out of range, the behaviour is undefined.
         * @param index The index of the item to retrieve.
         * @return A const reference to the requested item.
         */
        const KeyType& operator[](SInt32 index) const
        {
            return mKeys[index];
        }

        /**
         * @brief Get a const reference to the item at a given index.
         * If the index is out of range, the behaviour is undefined.
         * @param index The index of the item to retrieve.
         * @return A const reference to the requested item.
         */
        const KeyType& Get(SInt32 index) const
        {
            return mKeys.Get(index);
        }

        /**
         * @brief Get the number of actually allocated items.
         * @return The number of allocated items.
         */
        SInt32 GetAlloc() const
        {
            return mKeys.GetAlloc();
        }

        /**
         * @brief Get the number of items.
         * @return The number of items.
         */
        SInt32 GetCount() const
        {
            return mKeys.GetCount();
        }

        /**
         * @brief Check if the Index is empty.
         * @return true if the Index is empty, false otherwise.
         */
        Bool IsEmpty() const
        {
            return mKeys.IsEmpty();
        }

        /**
         * @brief Get a const reference to the array of items.
         * @return A const reference to the underlying item storage array.
         */
        const ArrayType& GetKeys() const
        {
            return mKeys;
        }

        /**
         * @brief Exchange the content of the index object with a given second one.
         * @param other The second index object.
         */
        void Swap(IndexBase& other)
        {
            mKeys.Swap(other.mKeys);
            mHash.Swap(other.mHash);
        }

        /**
         * @brief Definition of the const iterator.
         */
        typedef typename ArrayType::ConstIterator ConstIterator;

        /**
         * @brief Get the const iterator to the first item.
         * @return The const iterator to the first item.
         */
        ConstIterator Begin() const
        {
            return mKeys.Begin();
        }

        /**
         * @brief Get the const iterator next to the last item.
         * @return The const iterator next to the last item.
         */
        ConstIterator End() const
        {
            return mKeys.End();
        }

        /**
         * @brief Get the const iterator of a specified index.
         * @param index The index for the iterator.
         * @return The const iterator or null if the index is out of range.
         */
        ConstIterator GetIter(SInt32 index) const
        {
            return mKeys.GetIter(index);
        }

        /**
         * @brief Get the item index by iterator.
         * (!) Adding or removing items will invalidate iterators.
         * @param iterator The iterator of the item.
         * @return The index of the item, or -1 if the iterator is invalid.
         */
        SInt32 GetIterIndex(ConstIterator iterator) const
        {
            return mKeys.GetIterIndex(iterator);
        }

        /**
         * @brief Calculate the hash for an item.
         * @param key The item to calculate.
         * @return The hash value of the item.
         */
        UInt32 CalculateHash(const KeyType& key) const
        {
            return mHashFunc(key);
        }

        /**
         * @brief Compare the index to another one.
         * @param other The index to compare.
         * @return true if all keys have identical contents.
         */
        Bool IsEqual(const IndexBase& other) const
        {
            return mKeys == other.mKeys;
        }

        /**
         * @brief The "equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side index to compare.
         * @return true if all keys have identical contents.
         */
        bool operator==(const IndexBase& rhs) const
        {
            return IsEqual(rhs);
        }
        /**
         * @brief The "not equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side index to compare.
         * @return true if the indices differ.
         */
        bool operator!=(const IndexBase& rhs) const
        {
            return !IsEqual(rhs);
        }

#ifdef MURL_COMPILER_C11
        MURL_STL_INIT_LIST_TYPEDEF(KeyType);

        /**
         * @brief Add an initializer-list to the index.
         * @param initList The initializer-list to be added.
         */
        void Add(InitListType initList)
        {
            mKeys.Add(initList);
            for (const KeyType& key : initList)
            {
                mHash.Add(mHashFunc(key));
            }
        }
#endif  // MURL_COMPILER_C11

    protected:

#ifdef MURL_COMPILER_C11
        IndexBase(InitListType initList)
        : mKeys(initList)
        {
            for (const KeyType& key : initList)
            {
                mHash.Add(mHashFunc(key));
            }
        }
#endif  // MURL_COMPILER_C11

        IndexBase()
        {
        }

        IndexBase(const IndexBase& index)
        : mKeys(index.mKeys)
        , mHash(index.mHash)
        {
        }

        IndexBase(const ArrayType& array)
        : mKeys(array)
        {
            for (UInt32 i = 0; i < mKeys.GetCount(); i++)
            {
                mHash.Add(mHashFunc(mKeys[i]));
            }
        }

        SInt32 Find0(const KeyType& key, SInt32 i) const
        {
            while ((i >= 0) && !(key == mKeys[i]))
            {
                i = mHash.FindNext(i);
            }
            return i;
        }

        SInt32 FindB(const KeyType& key, SInt32 i) const
        {
            while ((i >= 0) && !(key == mKeys[i]))
            {
                i = mHash.FindPrev(i);
            }
            return i;
        }

        ArrayType mKeys;
        Hash mHash;
        HashFunc mHashFunc;
    };
}

#endif // __MURL_INDEX_BASE_H__

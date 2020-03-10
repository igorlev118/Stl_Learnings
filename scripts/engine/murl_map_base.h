// Copyright 2010-2015 Spraylight

#ifndef __MURL_MAP_BASE_H__
#define __MURL_MAP_BASE_H__

#include "murl_index.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic map template base class.
     * A map stores a number of key/value pairs, where the keys do not have to be unique.
     * \n This is the base class of the Map and ObjectMap class.
     * \n This class is based on the NTL AMap container, see http://www.ultimatepp.org
     * @tparam KeyType The key's data type of the map.
     * @tparam DataType The value's data type of the map.
     * @tparam ArrayType The array type of the values.
     * @tparam HashFunc The hash function of the key.
     */
    template<class KeyType, class DataType, class ArrayType, class HashFunc>
    class MapBase
    {
    public:
        /** @brief The template key parameter value type. */
        typedef KeyType KeyValueType;
        /** @brief The template data parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief Definition of the key index type.
         */
        typedef Index<KeyType, HashFunc> KeyIndexType;

        /**
         * @brief Clear the map and remove the underlying storage.
         */
        void Clear()
        {
            mKeys.Clear();
            mValues.Clear();
        }

        /**
         * @brief Empty the map, but keep the underlying storage.
         */
        void Empty()
        {
            mKeys.Empty();
            mValues.Empty();
        }

        /**
         * @brief Shrink the map so that the underlying key and value storage is only as large as necessary.
         */
        void Shrink()
        {
            mValues.Shrink();
            mKeys.Shrink();
        }

        /**
         * @brief Reduce the map to a given number of items.
         * @param n The new number of items in the map, must be smaller than the current item count.
         */
        void Trim(SInt32 n)
        {
            mKeys.Trim(n);
            mValues.SetCount(n);
        }

        /**
         * @brief Reduce the map by removing a given number of items from the end.
         * @param n The number of items to remove from the end.
         */
        void Drop(SInt32 n = 1)
        {
            mKeys.Drop(n);
            mValues.Drop(n);
        }

        /**
         * @brief Reserve storage space.
         * If the given size is less than the actual size, nothing is done.
         * @param n The number of items the underlying storage should hold.
         */
        void Reserve(SInt32 n)
        {
            mValues.Reserve(n);
            mKeys.Reserve(n);
        }

        /**
         * @brief Remove any unlinked pairs from the map.
         */
        void Sweep()
        {
            SInt32Array b = mKeys.GetUnlinked();
            Util::SortArray(b, true);
            mKeys.Remove(b);
            mValues.Remove(b);
        }

        /**
         * @brief Set the key of a given index.
         * @param index The index to replace.
         * @param key The new key.
         */
        void SetKey(SInt32 index, const KeyType& key)
        {
            mKeys.Set(index, key);
        }

        /**
         * @brief Exchange the content of the map with a given second one.
         * @param other The second map.
         */
        void Swap(MapBase& other)
        {
            mKeys.Swap(other.mKeys);
            mValues.Swap(other.mValues);
        }

        /**
         * @brief Add a new key/value pair to the map.
         * The newly added value is initialized using the value type's default
         * constructor.
         * @param key The key under which the value can be retrieved.
         * @return A reference to the newly constructed value.
         */
        DataType& Add(const KeyType& key)
        {
            mKeys.Add(key);
            return mValues.Add();
        }

        /**
         * @brief Add a key/value pair to the map.
         * The newly added value is initialized using the given reference value's
         * copy constructor.
         * @param key The key under which the value can be retrieved.
         * @param value The reference value to add.
         * @return A reference to the newly constructed value.
         */
        DataType& Add(const KeyType& key, const DataType& value)
        {
            mKeys.Add(key);
            return mValues.Add(value);
        }

        /**
         * @brief Add a new key/value pair to the map, replacing an unlinked element if present.
         * The newly added value is initialized using the value type's default
         * constructor.
         * @param key The key under which the value can be retrieved.
         * @return A reference to the newly added value.
         */
        DataType& Put(const KeyType& key)
        {
            SInt32 i = mKeys.Put(key);
            if (i < mValues.GetCount())
            {
                return mValues[i];
            }
            MURL_ASSERT(i == mValues.GetCount());
            return mValues.Add();
        }

        /**
         * @brief Add a key/value pair to the map, replacing an unlinked element if present.
         * The newly added value is initialized using the given reference value's
         * copy constructor.
         * @param key The key under which the value can be retrieved.
         * @param value The reference value to add.
         * @return The index of the pair in the map.
         */
        SInt32 Put(const KeyType& key, const DataType& value)
        {
            SInt32 i = mKeys.Put(key);
            if (i < mValues.GetCount())
            {
                mValues[i] = value;
            }
            else
            {
                MURL_ASSERT(i == mValues.GetCount());
                mValues.Add(value);
            }
            return i;
        }

        /**
         * @brief Insert a new key/value pair into the map at a given position.
         * The newly added value is initialized using the value type's default
         * constructor.
         * @param index The index where to insert the new pair.
         * @param key The key under which the value can be retrieved.
         * @return A reference to the newly constructed value.
         */
        DataType& Insert(SInt32 index, const KeyType& key)
        {
            mKeys.Insert(index, key);
            return mValues.Insert(index);
        }

        /**
         * @brief Insert a key/value pair into the map at a given position.
         * The newly added value is initialized using the given reference value's
         * copy constructor.
         * @param index The index where to insert the new pair.
         * @param key The key under which the value can be retrieved.
         * @param value The reference value to insert.
         * @return A reference to the newly constructed value.
         */
        DataType& Insert(SInt32 index, const KeyType& key, const DataType& value)
        {
            mKeys.Insert(index, key);
            return mValues.Insert(index, value);
        }

        /**
         * @brief Unlink the pair at a given index.
         * Unlinked elements remain in the map, but are ignored by any search operations.
         * @param index The index of the pair to unlink.
         */
        void Unlink(SInt32 index)
        {
            mKeys.Unlink(index);
        }

        /**
         * @brief Unlink all pairs matching a given key.
         * Unlinked elements remain in the map, but are ignored by any search operations.
         * @param key The key for which to unlink all elements.
         * @return The number of elements that were unlinked.
         */
        SInt32 UnlinkKey(const KeyType& key)
        {
            return mKeys.UnlinkKey(key);
        }

        /**
         * @brief Unlink all pairs matching a given key, using a precomputed hash value.
         * Unlinked elements remain in the map, but are ignored by any search operations.
         * @param key The key for which to unlink all elements.
         * @param hash The precomputed hash value.
         * @return The number of elements that were unlinked.
         */
        SInt32 UnlinkKey(const KeyType& key, UInt32 hash)
        {
            return mKeys.UnlinkKey(key, hash);
        }

        /**
         * @brief Check if the pair at a given index is unlinked.
         * @param index The index of the pair to check.
         * @return true if the pair is unlinked.
         */
        Bool IsUnlinked(SInt32 index) const
        {
            return mKeys.IsUnlinked(index);
        }

        /**
         * @brief Remove the key/value pair at a given position from the map.
         * @param index The zero-based index from where to remove the pair.
         */
        void Remove(SInt32 index)
        {
            mKeys.Remove(index);
            mValues.Remove(index);
        }

        /**
         * @brief Remove a number of key/value pairs from the map at a given starting position.
         * @param index The zero-based index from where to remove the first pair.
         * @param count The number of subsequent pairs to remove.
         */
        void Remove(SInt32 index, SInt32 count)
        {
            mKeys.Remove(index, count);
            mValues.Remove(index, count);
        }

        /**
         * @brief Remove a number of key/value pairs from the map at given positions.
         * @param sortedIndices A pointer to sorted indices where to remove the pairs.
         * @param count The number of pairs to remove, i.e. the number of indices.
         */
        void Remove(const SInt32* sortedIndices, SInt32 count)
        {
            mKeys.Remove(sortedIndices, count);
            mValues.Remove(sortedIndices, count);
        }

        /**
         * @brief Remove a number of key/value pairs from the map at given positions.
         * @param sortedIndices A sorted array of indices where to remove the items.
         */
        void Remove(const SInt32Array& sortedIndices)
        {
            Remove(sortedIndices, sortedIndices.GetCount());
        }

        /**
         * @brief Remove all pairs from the map that match a given key.
         * @param key The key for which to remove the pairs.
         * @return The number of pairs that were removed.
         */
        SInt32 RemoveKey(const KeyType& key)
        {
            SInt32Array rk;
            SInt32 q = Find(key);
            while (q >= 0)
            {
                rk.Add(q);
                q = FindNext(q);
            }
            Remove(rk);
            return rk.GetCount();
        }

        /**
         * @brief Find the first occurrence of a given key in the map.
         * @param key The key to search for.
         * @return The index of the pair in the map, or -1 if not found.
         */
        SInt32 Find(const KeyType& key) const
        {
            return mKeys.Find(key);
        }

        /**
         * @brief Find the first occurrence of a given key in the map, using a precomputed
         * hash value.
         * @param key The key to search for.
         * @param hash The precomputed hash value.
         * @return The index of the pair in the map, or -1 if not found.
         */
        SInt32 Find(const KeyType& key, UInt32 hash) const
        {
            return mKeys.Find(key, hash);
        }

        /**
         * @brief Find the last occurrence of a given key in the map.
         * @param key The key to search for.
         * @return The index of the pair in the map, or -1 if not found.
         */
        SInt32 FindLast(const KeyType& key) const
        {
            return mKeys.FindLast(key);
        }

        /**
         * @brief Find the last occurrence of a given key in the map, using a precomputed
         * hash value.
         * @param key The key to search for.
         * @param hash The precomputed hash value.
         * @return The index of the pair in the map, or -1 if not found.
         */
        SInt32 FindLast(const KeyType& key, UInt32 hash) const
        {
            return mKeys.FindLast(key, hash);
        }

        /**
         * @brief Find the next occurrence of a key that is specified by a given index.
         * @param index The index of the pair containing the key to search for.
         * @return The index of the next pair in the map, or -1 if not found.
         */
        SInt32 FindNext(SInt32 index) const
        {
            return mKeys.FindNext(index);
        }

        /**
         * @brief Find the previous occurrence of a key that is specified by a given index.
         * @param index The index of the pair containing the key to search for.
         * @return The index of the previous pair in the map, or -1 if not found.
         */
        SInt32 FindPrev(SInt32 index) const
        {
            return mKeys.FindPrev(index);
        }

        /**
         * @brief Find the first occurrence of a given key in the map, or add a new pair
         * if the key was not found.
         * If a pair needs to be added, the newly created value is initialized using
         * the value type's default constructor.
         * @param key The key to search for.
         * @return The index of the pair in the map.
         */
        SInt32 FindAdd(const KeyType& key)
        {
            UInt32 hash = mKeys.CalculateHash(key);
            SInt32 i = Find(key, hash);
            if (i < 0)
            {
                i = GetCount();
                mKeys.Add(key, hash);
                mValues.Add();
            }
            return i;
        }

        /**
         * @brief Find the first occurrence of a given key in the map, or add a new pair
         * if the key was not found.
         * If a pair needs to be added, the newly created value is initialized using
         * the given value's copy constructor.
         * @param key The key to search for.
         * @param value The reference value to add.
         * @return The index of the pair in the map.
         */
        SInt32 FindAdd(const KeyType& key, const DataType& value)
        {
            UInt32 hash = mKeys.CalculateHash(key);
            SInt32 i = Find(key, hash);
            if (i < 0)
            {
                i = GetCount();
                mKeys.Add(key, hash);
                mValues.Add(value);
            }
            return i;
        }

        /**
         * @brief Find the first occurrence of a given key in the map, or add a new pair
         * if the key was not found, hereby replacing an unlinked element if possible.
         * If a pair needs to be added, the newly created value is initialized using
         * the value type's default constructor.
         * @param key The key to search for.
         * @return The index of the pair in the map.
         */
        SInt32 FindPut(const KeyType& key)
        {
            UInt32 hash = mKeys.CalculateHash(key);
            SInt32 i = Find(key, hash);
            if (i < 0)
            {
                i = mKeys.Put(key, hash);
                mValues.At(i);
            }
            return i;
        }

        /**
         * @brief Find the first occurrence of a given key in the map, or add a new pair
         * if the key was not found, hereby replacing an unlinked element if possible.
         * If a pair needs to be added, the newly created value is initialized using
         * the given value's copy constructor.
         * @param key The key to search for.
         * @param value The reference value to add.
         * @return The index of the pair in the map.
         */
        SInt32 FindPut(const KeyType& key, const DataType& value)
        {
            UInt32 hash = mKeys.CalculateHash(key);
            SInt32 i = Find(key, hash);
            if (i < 0)
            {
                i = mKeys.Put(key, hash);
                if (i >= mValues.GetCount())
                {
                    if (!MURL_VERIFY(i == mValues.GetCount()))
                    {
                        i = mValues.GetCount();
                    }
                    mValues.Add(value);
                }
                else
                {
                    mValues[i] = value;
                }
            }
            return i;
        }

        /**
         * @brief Get a reference to the first occurrence of a given key in the map.
         * If the key was not found, the behaviour is undefined.
         * @param key The key to search for.
         * @return A reference to the value of the first pair found.
         */
        DataType& Get(const KeyType& key)
        {
            return mValues[Find(key)];
        }

        /**
         * @brief Get a const reference to the first occurrence of a given key in the map.
         * If the key was not found, the behaviour is undefined.
         * @param key The key to search for.
         * @return A const reference to the value of the first pair found.
         */
        const DataType& Get(const KeyType& key) const
        {
            return mValues[Find(key)];
        }

        /**
         * @brief Get a const reference to the first occurrence of a given key in the map.
         * If the key was not found, the given default value is returned
         * @param key The key to search for.
         * @param defaultValue The default value to return if the key was not found.
         * @return A const reference to the value of the first pair, or the given default value.
         */
        const DataType& Get(const KeyType& key, const DataType& defaultValue) const
        {
            SInt32 i = Find(key);
            return i >= 0 ? mValues[i] : defaultValue;
        }

        /**
         * @brief Get a pointer to the first occurrence of a given key in the map.
         * If the key was not found, a null pointer is returned.
         * @param key The key to search for.
         * @return A pointer to the value of the first pair found, or null.
         */
        DataType* GetPtr(const KeyType& key)
        {
            SInt32 i = Find(key);
            return i >= 0 ? &mValues[i] : 0;
        }

        /**
         * @brief Get a const pointer to the first occurrence of a given key in the map.
         * If the key was not found, a null pointer is returned.
         * @param key The key to search for.
         * @return A const pointer to the value of the first pair found, or null.
         */
        const DataType* GetPtr(const KeyType& key) const
        {
            SInt32 i = Find(key);
            return i >= 0 ? &mValues[i] : 0;
        }

        /**
         * @brief Get a reference to the first occurrence of a given key in the map, or add
         * a new pair if the key was not found.
         * If a pair needs to be added, the newly created value is initialized using
         * the value type's default constructor.
         * @param key The key to search for.
         * @return A reference to the value of the first pair found.
         */
        DataType& GetAdd(const KeyType& key)
        {
            UInt32 hash = mKeys.CalculateHash(key);
            SInt32 i = mKeys.Find(key, hash);
            if (i >= 0)
            {
                return mValues[i];
            }
            mKeys.Add(key, hash);
            return mValues.Add();
        }

        /**
         * @brief Get a reference to the first occurrence of a given key in the map, or add
         * a new pair if the key was not found.
         * If a pair needs to be added, the newly created value is initialized using
         * the given value's copy constructor.
         * @param key The key to search for.
         * @param value The reference value to add.
         * @return A reference to the value of the first pair found.
         */
        DataType& GetAdd(const KeyType& key, const DataType& value)
        {
            UInt32 hash = mKeys.CalculateHash(key);
            SInt32 i = Find(key, hash);
            if (i >= 0)
            {
                return mValues[i];
            }
            mKeys.Add(key, hash);
            mValues.Add(value);
            return mValues.Top();
        }

        /**
         * @brief Get a reference to the first occurrence of a given key in the map, or add
         * a new pair if the key was not found, hereby replacing an unlinked element
         * if possible.
         * If a pair needs to be added, the newly created value is initialized using
         * the value type's default constructor.
         * @param key The key to search for.
         * @return A reference to the value of the first pair found.
         */
        DataType& GetPut(const KeyType& key)
        {
            return mValues[FindAdd(key)];
        }

        /**
         * @brief Get a reference to the first occurrence of a given key in the map, or add
         * a new pair if the key was not found, hereby replacing an unlinked element
         * if possible.
         * If a pair needs to be added, the newly created value is initialized using
         * the given value's copy constructor.
         * @param key The key to search for.
         * @param value The reference value to add.
         * @return A reference to the value of the first pair found.
         */
        DataType& GetPut(const KeyType& key, const DataType& value)
        {
            return mValues[FindAdd(key, value)];
        }

        /**
         * @brief Get a const reference to the key at a given index.
         * If the index is out of range, the behaviour is undefined.
         * @param index The index of the key to retrieve.
         * @return A const reference to the requested key.
         */
        const KeyType& GetKey(SInt32 index) const
        {
            return mKeys[index];
        }

        /**
         * @brief Get a const reference to the key storage.
         * @return A const reference to the underlying key storage.
         */
        const KeyIndexType& GetIndex() const
        {
            return mKeys;
        }

        /**
         * @brief Get a const reference to the array of keys.
         * @return A const reference to the underlying key storage array.
         */
        const Array<KeyType>& GetKeys() const
        {
            return mKeys.GetKeys();
        }

        /**
         * @brief Get a reference to the array of values.
         * @return A reference to the underlying value array.
         */
        ArrayType& GetValues()
        {
            return mValues;
        }

        /**
         * @brief Get a const reference to the array of values.
         * @return A const reference to the underlying value array.
         */
        const ArrayType& GetValues() const
        {
            return mValues;
        }

        /**
         * @brief Check if a given index is a valid index.
         * @param index The index to check.
         * @return true if index >= 0 and index < GetCount().
         */
        Bool IsIndexValid(SInt32 index) const
        {
            return mValues.IsIndexValid(index);
        }

        /**
         * @brief Get a const reference to the value at a given index.
         * If the index is out of range, the behaviour is undefined.
         * @param index The index of the value to retrieve.
         * @return A reference to the requested value.
         */
        const DataType& operator[](SInt32 index) const
        {
            return mValues[index];
        }

        /**
         * @brief Get a reference to the value at a given index.
         * If the index is out of range, the behaviour is undefined.
         * @param index The index of the value to retrieve.
         * @return A const reference to the requested value.
         */
        DataType& operator[](SInt32 index)
        {
            return mValues[index];
        }

        /**
         * @brief Get a reference to the first value in the storage.
         * @return A reference to the first value.
         */
        DataType& Bottom()
        {
            return mValues.Bottom();
        }

        /**
         * @brief Get a const reference to the first value in the storage.
         * @return A const reference to the first value.
         */
        const DataType& Bottom() const
        {
            return mValues.Bottom();
        }

        /**
         * @brief Get a const reference to the first key in the storage.
         * @return A const reference to the first key.
         */
        const KeyType& BottomKey() const
        {
            return mKeys.Bottom();
        }

        /**
         * @brief Get a reference to the last value in the storage.
         * @return A reference to the last value.
         */
        DataType& Top()
        {
            return mValues.Top();
        }

        /**
         * @brief Get a const reference to the last value in the storage.
         * @return A const reference to the last value.
         */
        const DataType& Top() const
        {
            return mValues.Top();
        }

        /**
         * @brief Get a const reference to the last key in the storage.
         * @return A const reference to the last key.
         */
        const KeyType& TopKey() const
        {
            return mKeys.Top();
        }

        /**
         * @brief Remove the last key/value pair from the map and return its key.
         * @return The key of the removed pair.
         */
        KeyType PopKey()
        {
            KeyType h = TopKey();
            Drop();
            return h;
        }

        /**
         * @brief Get the number of actually allocated pairs.
         * @return The number of allocated pairs.
         */
        SInt32 GetAlloc() const
        {
            return mValues.GetAlloc();
        }

        /**
         * @brief Get the number of items in the map.
         * @return The number of items.
         */
        SInt32 GetCount() const
        {
            return mValues.GetCount();
        }

        /**
         * @brief Check if the map is empty.
         * @return true if the map is empty, false otherwise.
         */
        Bool IsEmpty() const
        {
            return mValues.IsEmpty();
        }

        /**
         * @brief Definition of the const key iterator.
         */
        typedef typename KeyIndexType::ConstIterator KeyConstIterator;

        /**
         * @brief Get the const key iterator to the first element.
         * @return The const key iterator to the first element.
         */
        KeyConstIterator KeyBegin() const
        {
            return mKeys.Begin();
        }

        /**
         * @brief Get the const key iterator next to the last element.
         * @return The const key iterator next to the last element.
         */
        KeyConstIterator KeyEnd() const
        {
            return mKeys.End();
        }

        /**
         * @brief Get the const key iterator of a specified index.
         * @param index The index for the key iterator.
         * @return The const key iterator or null if the index is out of range.
         */
        KeyConstIterator KeyGetIter(SInt32 index) const
        {
            return mKeys.GetIter(index);
        }

        /**
         * @brief Definition of the const iterator.
         */
        typedef typename ArrayType::ConstIterator ConstIterator;

        /**
         * @brief Get the const iterator to the first element.
         * @return The const iterator to the first element.
         */
        ConstIterator Begin() const
        {
            return mValues.Begin();
        }

        /**
         * @brief Get the const iterator next to the last element.
         * @return The const iterator next to the last element.
         */
        ConstIterator End() const
        {
            return mValues.End();
        }

        /**
         * @brief Get the const iterator of a specified index.
         * @param index The index for the iterator.
         * @return The const iterator or null if the index is out of range.
         */
        ConstIterator GetIter(SInt32 index) const
        {
            return mValues.GetIter(index);
        }

        /**
         * @brief Definition of the iterator.
         */
        typedef typename ArrayType::Iterator Iterator;

        /**
         * @brief Get the iterator to the first element.
         * @return The iterator to the first element.
         */
        Iterator Begin()
        {
            return mValues.Begin();
        }

        /**
         * @brief Get the iterator next to the last element.
         * @return The iterator next to the last element.
         */
        Iterator End()
        {
            return mValues.End();
        }

        /**
         * @brief Get the iterator of a specified index.
         * @param index The index for the iterator.
         * @return The iterator or null if the index is out of range.
         */
        Iterator GetIter(SInt32 index)
        {
            return mValues.GetIter(index);
        }

        /**
         * @brief Compare the map to another one.
         * @param other The map to compare.
         * @return true if all key value pairs have identical contents.
         */
        Bool IsEqual(const MapBase& other) const
        {
            if (mKeys == other.mKeys)
            {
                return mValues == other.mValues;
            }
            return false;
        }

        /**
         * @brief The "equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side map to compare.
         * @return true if all key value pairs have identical contents.
         */
        bool operator==(const MapBase& rhs) const
        {
            return IsEqual(rhs);
        }
        /**
         * @brief The "not equal to" comparison operator, calls IsEqual().
         * @param rhs The right hand side map to compare.
         * @return true if the maps differ.
         */
        bool operator!=(const MapBase& rhs) const
        {
            return !IsEqual(rhs);
        }

    protected:
        MapBase()
        {
        }

        MapBase(const MapBase& map)
        : mKeys(map.mKeys)
        , mValues(map.mValues)
        {
        }

        KeyIndexType mKeys;
        ArrayType mValues;
    };
}

#endif // __MURL_MAP_BASE_H__

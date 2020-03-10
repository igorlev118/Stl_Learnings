// Copyright 2010-2015 Spraylight

#ifndef __MURL_OBJECT_INDEX_H__
#define __MURL_OBJECT_INDEX_H__

#include "murl_index_base.h"
#include "murl_object_array.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic index template class for non-moveable objects eg.\ NonCopyable classes.
     * See IndexBase class for all index methods.
     * \n The index class stores a number of (not necessarily unique) keys in a hash table.
     * \n The object index class uses pointers to the key objects, this ensures
     * that the object's memory location is unchanged when modifying the index.
     * \n This class is based on the NTL ArrayIndex container, see http://www.ultimatepp.org
     * @tparam KeyType The key's data type of the index.
     * @tparam HashFunc The hash function of the key.
     */
    template<class KeyType, class HashFunc = StdHash<KeyType> >
    class ObjectIndex : public IndexBase<KeyType, ObjectArray<KeyType>, HashFunc>
    {
        typedef IndexBase<KeyType, ObjectArray<KeyType>, HashFunc> BaseType;

    public:
        /** @brief The template key parameter value type. */
        typedef KeyType KeyValueType;
        /** @brief The template hash parameter value type. */
        typedef HashFunc HashValueType;

#ifdef MURL_COMPILER_C11
        MURL_STL_INIT_LIST_TYPEDEF(KeyType);

        /**
         * @brief The initializer-list constructor.
         * @param initList The initializer-list.
         */
        ObjectIndex(InitListType initList)
        : BaseType(initList)
        {
        }
#endif  // MURL_COMPILER_C11

        /**
         * @brief The default constructor.
         * Create an empty index object.
         */
        ObjectIndex()
        {
        }

        /**
         * @brief The copy constructor.
         * @param index The index object to copy.
         */
        ObjectIndex(const ObjectIndex& index)
        : BaseType(index)
        {
        }

        /**
         * @brief Constructor taking an array.
         * @param array The array object to copy.
         */
        ObjectIndex(const ObjectArray<KeyType>& array)
        : BaseType(array)
        {
        }

        /**
         * @brief Add a new allocated item with a precomputed hash value.
         * The index takes the ownership of the item.
         * @param key The item to add.
         * @param hash The precomputed hash.
         * @return A reference to the added item.
         */
        KeyType& Add(KeyType* key, UInt32 hash)
        {
            BaseType::mHash.Add(hash);
            return BaseType::mKeys.Add(key);
        }

        /**
         * @brief Add a new allocated item.
         * The index takes the ownership of the item.
         * @param key The item to add.
         * @return A reference to the added item.
         */
        KeyType& Add(KeyType* key)
        {
            return Add(key, BaseType::mHashFunc(*key));
        }

        using BaseType::Add;

        /**
         * @brief Replace the item at a specified index using a precomputed hash.
         * The index takes the ownership of the item.
         * @param index The index to set.
         * @param key The value to set.
         * @param hash The precomputed hash.
         * @return A reference to the set item.
         */
        KeyType& Set(SInt32 index, KeyType* key, UInt32 hash)
        {
            KeyType& ret = BaseType::mKeys.Set(index, key);
            BaseType::mHash.Set(index, hash);
            return ret;
        }

        /**
         * @brief Replace the item at a specified index.
         * The index takes the ownership of the item.
         * @param index The index to set.
         * @param key The value to set.
         * @return A reference to the set item.
         */
        KeyType& Set(SInt32 index, KeyType* key)
        {
            return Set(index, key, BaseType::mHashFunc(*key));
        }

        using BaseType::Set;

        /**
         * @brief Removes the item from the top position and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @return The pointer to the heap allocated item.
         */
        KeyType* PopDetach()
        {
            BaseType::mHash.Drop(1);
            return BaseType::mKeys.PopDetach();
        }

        /**
         * @brief Removes the item at a given position and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @param index The zero-based index of the item to remove.
         * @return The pointer to the heap allocated item.
         */
        KeyType* Detach(SInt32 index)
        {
            BaseType::mHash.Remove(index);
            return BaseType::mKeys.Detach(index);
        }

        typedef typename BaseType::ConstIterator ConstIterator;

#ifdef MURL_COMPILER_C11
        MURL_STL_BASE_CONST_ITERATOR(BaseType)
#endif // MURL_COMPILER_C11
    };
}

#endif // __MURL_OBJECT_INDEX_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_OBJECT_MAP_H__
#define __MURL_OBJECT_MAP_H__

#include "murl_map_base.h"
#include "murl_object_array.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic map template class for non-moveable objects eg.\ NonCopyable classes.
     * See MapBase class for all map methods.
     * \n A map stores a number of key/value pairs, where the keys do not have to be unique.
     * \n The object map class uses pointers to the value objects, this ensures
     * that the object's memory location is unchanged when modifying the map.
     * \n This class is based on the NTL ArrayMap container, see http://www.ultimatepp.org
     * @tparam KeyType The key's data type of the map.
     * @tparam DataType The value's data type of the map.
     * @tparam HashFunc The hash function of the key.
     */
    template<class KeyType, class DataType, class HashFunc = StdHash<KeyType> >
    class ObjectMap : public MapBase<KeyType, DataType, ObjectArray<DataType>, HashFunc>
    {
        typedef MapBase<KeyType, DataType, ObjectArray<DataType>, HashFunc> BaseType;

    public:
        /** @brief The template key parameter value type. */
        typedef KeyType KeyValueType;
        /** @brief The template data parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor.
         * Create an empty map.
         */
        ObjectMap()
        {
        }

        /**
         * @brief The copy constructor.
         * @param map The map object to copy.
         */
        ObjectMap(const ObjectMap& map)
        : BaseType(map)
        {
        }

        /**
         * @brief Add a key/value pair to the map.
         * The map takes the ownership of the value item.
         * @param key The key under which the value can be retrieved.
         * @param value The value to add.
         * @return A reference to the newly constructed value.
         */
        DataType& Add(const KeyType& key, DataType* value)
        {
            BaseType::mKeys.Add(key);
            return BaseType::mValues.Add(value);
        }

        using BaseType::Add;

        /**
         * @brief Insert a key/value pair into the map at a given position.
         * The map takes the ownership of the value item.
         * @param index The index where to insert the new pair.
         * @param key The key under which the value can be retrieved.
         * @param value The reference value to insert.
         * @return A reference to the newly constructed value.
         */
        DataType& Insert(SInt32 index, const KeyType& key, DataType* value)
        {
            BaseType::mKeys.Insert(index, key);
            return BaseType::mValues.Insert(index, value);
        }

        using BaseType::Insert;

        /**
         * @brief Create and add an value at the specified key.
         * @tparam DataTypeT The type of object to create.
         * @param key The key under which the value can be retrieved.
         * @return A reference to the newly created item.
         */
        template<class DataTypeT>
        DataTypeT& Create(const KeyType& key)
        {
            DataTypeT* value = new DataTypeT;
            BaseType::mKeys.Add(key);
            return static_cast<DataTypeT&>(BaseType::mValues.Add(value));
        }

        /**
         * @brief Set a new allocated value item at a given position.
         * The map takes the ownership of the value item.
         * @param index The zero-based index of the item to set.
         * @param item The new allocated item to set.
         * @return A reference to the item.
         */
        DataType& Set(SInt32 index, DataType* item)
        {
            return BaseType::mValues.Set(index, item);
        }

        /**
         * @brief Removes the item from the top position and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @return The pointer to the heap allocated item.
         */
        DataType* PopDetach()
        {
            BaseType::mKeys.Drop();
            return BaseType::mValues.PopDetach();
        }

        /**
         * @brief Removes the item at a given position and giving up ownership.
         * (!) The client is responsible for deletion of the returned item.
         * @param index The zero-based index of the item to remove.
         * @return The pointer to the heap allocated item.
         */
        DataType* Detach(SInt32 index)
        {
            BaseType::mKeys.Remove(index);
            return BaseType::mValues.Detach(index);
        }

        /**
         * @brief Swap the item at a given position with a new allocated item.
         * (!) The client is responsible for deletion of the returned item.
         * @param index The zero-based index of the item to swap.
         * @param newItem The new allocated item to swap into.
         * @return The pointer to the swapped-out heap allocated item.
         */
        DataType* Swap(SInt32 index, DataType* newItem)
        {
            return BaseType::mValues.Swap(index, newItem);
        }

        using BaseType::Swap;

        typedef typename BaseType::ConstIterator ConstIterator;
        typedef typename BaseType::Iterator Iterator;

#ifdef MURL_COMPILER_C11
        MURL_STL_BASE_CONST_ITERATOR(BaseType)
        MURL_STL_BASE_ITERATOR(BaseType)
#endif // MURL_COMPILER_C11
    };
}

#endif // __MURL_OBJECT_MAP_H__

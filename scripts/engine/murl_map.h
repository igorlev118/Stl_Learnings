// Copyright 2010-2015 Spraylight

#ifndef __MURL_MAP_H__
#define __MURL_MAP_H__

#include "murl_map_base.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic map template class for moveable objects
     * eg.\ structs or fundamental data types like UInt32, Real, etc.
     * See MapBase class for all map methods.
     * \n A map stores a number of key/value pairs, where the keys do not have to be unique.
     * \n The map class works for moveable objects only,
     * use ObjectMap class for storing non-moveable objects.
     * \n This class is based on the NTL VectorMap container, see http://www.ultimatepp.org
     * @tparam KeyType The key's data type of the map.
     * @tparam DataType The value's data type of the map.
     * @tparam HashFunc The hash function of the key.
     */
    template<class KeyType, class DataType, class HashFunc = StdHash<KeyType> >
    class Map : public MapBase<KeyType, DataType, Array<DataType>, HashFunc>
    {
        typedef MapBase<KeyType, DataType, Array<DataType>, HashFunc> BaseType;

    public:
        /** @brief The template key parameter value type. */
        typedef KeyType KeyValueType;
        /** @brief The template data parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor.
         * Create an empty map.
         */
        Map()
        {
        }

        /**
         * @brief The copy constructor.
         * @param map The map object to copy.
         */
        Map(const Map& map)
        : BaseType(map)
        {
        }

        /**
         * @brief Remove the last key/value pair from the map and return its value.
         * @return The value of the removed pair.
         */
        DataType Pop()
        {
            DataType ret = BaseType::Top();
            BaseType::Drop();
            return ret;
        }

        typedef typename BaseType::ConstIterator ConstIterator;
        typedef typename BaseType::Iterator Iterator;

#ifdef MURL_COMPILER_C11
        MURL_STL_BASE_CONST_ITERATOR(BaseType)
        MURL_STL_BASE_ITERATOR(BaseType)
#endif // MURL_COMPILER_C11
    };
}

#endif // __MURL_MAP_H__

// Copyright 2010-2015 Spraylight

#ifndef __MURL_INDEX_H__
#define __MURL_INDEX_H__

#include "murl_index_base.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A generic index template class for moveable objects
     * eg.\ structs or fundamental data types like UInt32, Real, etc.
     * See IndexBase class for all index methods.
     * \n The index class stores a number of (not necessarily unique) keys in a hash table.
     * \n The index class works for moveable objects only,
     * use ObjectIndex class for storing non-moveable objects.
     * \n This class is based on the NTL Index container, see http://www.ultimatepp.org
     * @tparam KeyType The key's data type of the index.
     * @tparam HashFunc The hash function of the key.
     */
    template<class KeyType, class HashFunc = StdHash<KeyType> >
    class Index : public IndexBase<KeyType, Array<KeyType>, HashFunc>
    {
        typedef IndexBase<KeyType, Array<KeyType>, HashFunc> BaseType;

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
        Index(InitListType initList)
        : BaseType(initList)
        {
        }
#endif  // MURL_COMPILER_C11

        /**
         * @brief The default constructor.
         * Create an empty index object.
         */
        Index()
        {
        }

        /**
         * @brief Construct an index containing a single item.
         * @param item The item.
         */
        Index(const KeyType& item)
        {
            BaseType::Add(item);
        }

        /**
         * @brief Construct an index containing two items.
         * @param item1 The first item.
         * @param item2 The second item.
         */
        Index(const KeyType& item1, const KeyType& item2)
        {
            BaseType::Add(item1);
            BaseType::Add(item2);
        }

        /**
         * @brief Construct an index containing three items.
         * @param item1 The first item.
         * @param item2 The second item.
         * @param item3 The third item.
         */
        Index(const KeyType& item1, const KeyType& item2, const KeyType& item3)
        {
            BaseType::Add(item1);
            BaseType::Add(item2);
            BaseType::Add(item3);
        }

        /**
         * @brief The copy constructor.
         * @param index The index object to copy.
         */
        Index(const Index& index)
        : BaseType(index)
        {
        }

        /**
         * @brief Constructor taking an array.
         * @param array The array object to copy.
         */
        Index(const Array<KeyType>& array)
        : BaseType(array)
        {
        }

        /**
         * @brief Remove the last item.
         * @return The the removed item.
         */
        KeyType Pop()
        {
            KeyType key = BaseType::Top();
            BaseType::Drop();
            return key;
        }

        typedef typename BaseType::ConstIterator ConstIterator;

#ifdef MURL_COMPILER_C11
        MURL_STL_BASE_CONST_ITERATOR(BaseType)
#endif // MURL_COMPILER_C11
    };
}

#endif // __MURL_INDEX_H__

// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_SORT_H__
#define __MURL_UTIL_SORT_H__

#include "murl_system_clib.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @addtogroup MurlUtilSortFunctions
         * @brief Sorting functions.
         * @{
         */

        /**
         * @brief The compare functions.
         * @tparam DataType Available for UInt64, SInt64, UInt32, SInt32, Real, Double and String.
         */
        template<class DataType>
        class CompareFunction
        {
        public:
            /**
             * @brief The compare function for ascending sort.
             * @param source1 Pointer to the 1st source.
             * @param source2 Pointer to the 2nd source.
             * @return Zero if source1 is equal to source2,
             *  negativ if source1 is lesser than source2,
             *  positive if source1 is greater than source2.
             */
            static SInt32 Ascending(const DataType* source1, const DataType* source2);

            /**
             * @brief The compare function for descending sort.
             * @param source1 Pointer to the 1st source.
             * @param source2 Pointer to the 2nd source.
             * @return Zero if source1 is equal to source2,
             *  negativ if source2 is lesser than source1,
             *  positive if source2 is greater than source1.
             */
            static SInt32 Descending(const DataType* source1, const DataType* source2);
        };

        /**
         * @brief Quick sort items of specified type.
         * @tparam DataType The type of item to sort.
         * @param items Pointer to the items to sort.
         * @param numberOfItems Number of items to sort.
         * @param compareFunction The compare function for the item,
         *  see CompareFunction::Ascending and Descending method.
         */
        template<class DataType>
        void QuickSort(DataType* items, UInt32 numberOfItems, SInt32 (*compareFunction)(const DataType*, const DataType*))
        {
            System::CLib::QuickSort(items, numberOfItems, sizeof(DataType),
                                    reinterpret_cast<System::CLib::CompareFunctionType>(compareFunction));
        }

        /**
         * @brief Binary search an item of specified type.
         * The items to search for are required to be sorted.
         * @tparam DataType The type of item to sort.
         * @param key Pointer to the item to find.
         * @param items Pointer to the items to search for.
         * @param numberOfItems Number of items to search for.
         * @param compareFunction The compare function for the item,
         *  see CompareFunction::Ascending and Descending method.
         * @return Pointer to the item found or null if the item is not found.
         * If there are multiple elements matching key, the element returned is unspecified.
         */
        template<class DataType>
        DataType* BinarySearch(const DataType* key, DataType* items, UInt32 numberOfItems,
                               SInt32 (*compareFunction)(const DataType*, const DataType*))
        {
            return reinterpret_cast<DataType*>(System::CLib::BinarySearch(key, items, numberOfItems, sizeof(DataType),
                                                                          reinterpret_cast<System::CLib::CompareFunctionType>(compareFunction)));
        }

        /**
         * @brief Bubble sort items of specified type.
         * @tparam DataType The type of item to sort.
         * @param items Pointer to the items to sort.
         * @param numberOfItems Number of items to sort.
         * @param compareFunction The compare function for the item,
         *  see CompareFunction::Ascending and Descending method.
         */
        template<class DataType>
        void BubbleSort(DataType* items, UInt32 numberOfItems, SInt32 (*compareFunction)(const DataType*, const DataType*))
        {
            Bool finished = false;
            SInt32 nrOfItems = numberOfItems;
            while (!finished)
            {
                finished = true;
                nrOfItems--;
                for (SInt32 i = 0; i < nrOfItems; i++)
                {
                    DataType item1 = items[i];
                    DataType item2 = items[i + 1];
                    SInt32 result = (*compareFunction)(&item1, &item2);
                    if (result > 0)
                    {
                        items[i] = item2;
                        items[i + 1] = item1;
                        finished = false;
                    }
                }
            }
        }

        /**
         * @brief Sort an array of specified type.
         * The array is sorted by using the QuickSort algorithm
         * and the compareFunction.
         * @param array The array to sort.
         * @param compareFunction The compare function for the item,
         *  see CompareFunction::Ascending and Descending method.
         */
        template<class DataType>
        void SortArray(Array<DataType>& array, SInt32 (*compareFunction)(const DataType*, const DataType*))
        {
            QuickSort<DataType>(array, array.GetCount(), compareFunction);
        }

        /**
         * @brief Sort an array of specified type.
         * The array is sorted by using the QuickSort algorithm
         * and the CompareFunction class.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        template<class DataType>
        void SortArray(Array<DataType>& array, Bool ascending)
        {
            if (ascending)
            {
                QuickSort<DataType>(array, array.GetCount(), CompareFunction<DataType>::Ascending);
            }
            else
            {
                QuickSort<DataType>(array, array.GetCount(), CompareFunction<DataType>::Descending);
            }
        }

        /**
         * @brief Sort a UInt64 array.
         * The array is sorted by using the quick sort algorithm.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        void SortUInt64Array(UInt64Array& array, Bool ascending);

        /**
         * @brief Sort a SInt64 array.
         * The array is sorted by using the quick sort algorithm.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        void SortSInt64Array(SInt64Array& array, Bool ascending);

        /**
         * @brief Sort a UInt32 array.
         * The array is sorted by using the quick sort algorithm.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        void SortUInt32Array(UInt32Array& array, Bool ascending);

        /**
         * @brief Sort a SInt32 array.
         * The array is sorted by using the quick sort algorithm.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        void SortSInt32Array(SInt32Array& array, Bool ascending);

        /**
         * @brief Sort a Real array.
         * The array is sorted by using the quick sort algorithm.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        void SortRealArray(RealArray& array, Bool ascending);

        /**
         * @brief Sort a Double array.
         * The array is sorted by using the quick sort algorithm.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        void SortDoubleArray(DoubleArray& array, Bool ascending);

        /**
         * @brief Sort a String array.
         * The array is sorted by using the quick sort algorithm.
         * @param array The array to sort.
         * @param ascending true for ascending sort order,
         *  false for descending sort order.
         */
        void SortStringArray(StringArray& array, Bool ascending);

        /** @} */
    }
}

#endif // __MURL_UTIL_SORT_H__

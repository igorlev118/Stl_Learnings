// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_H__
#define __MURL_UTIL_H__

#include "murl_math.h"
#include "murl_system_clib.h"

namespace Murl
{
    class Data;

    /**
     * @ingroup MurlUtilNamespaces
     * @brief Utility classes, templates and functions.
     * Following is a short overview of how the print/conversion functions are layered (from low to high level):
     *
     * 1) String System::CLib::PrintToStringArg(const Char* format, void* vaListPtr):
     * This is the lowest-level function that can be used to print any list of variables to a Murl::String.
     * It takes an UTF8 format string, and a pointer to a std::va_list (as void*) that carries the variables.
     * Internally, it uses the vsnprintf function for printing, which accepts the standard format specifiers.
     *
     * 2) String System::CLib::PrintToString(const Char* format, ...);
     * For convenience, this function can be used to print to a string without having to build a va_list.
     * This function builds a va_list internally and calls System::CLib::PrintToStringArg().
     *
     * 3) String Util::PrintToString(const Char* format, ...)
     * This function is pretty much identical to 2), provided as a convenience in the Util namespace.
     *
     * 4) String Util::UInt64ToString(UInt64 inputValue, const String& format)
     * This function (and the respective functions for the other data types described below) directly calls
     * Util::PrintToString() with the given format and the inputValue as a single value parameter.
     * Care must be taken that the given format is acceptable for the given data type, e.g. providing a format
     * string of "%f" with a Murl::UInt32 variable will produce incorrect results. No check or conversion is
     * done internally to ensure correct behavior.
     *
     * 5) String Util::UInt64ToString(UInt64 inputValue)
     * This function (and the respective functions for the other data types described below) directly call
     * Util::PrintToString() with a default format for the respective data type and the inputValue as a single
     * value parameter. See also below for these default format strings.
     * Calling these methods is preferable when the actual input variable has a different data type than
     * the one desired in the output string, e.g. when a Murl::Float variable should be implicity converted to
     * a Murl::SInt64 variable upon conversion.
     *
     * 6) String Util::ValueToString(UInt64 inputValue)
     * This inline function and the respective overloads for the other data types directly call
     * Util::UInt64ToString() and the respective counterparts.
     * Using these methods is preferable when the input variable of a given data type should be printed
     * with the actual default format for that data type.
     *
     * Following is a list of number data types and their default format strings used in 5) and 6):
     * - Murl::UInt64 : "%llu"
     * - Murl::SInt64 : "%lld"
     * - Murl::UInt32 : "%u"
     * - Murl::SInt32 : "%d"
     * - Murl::Double : "%f"
     */
    namespace Util
    {
        /**
         * @addtogroup MurlUtilFunctions
         * @brief Utility template functions (memory manipulation).
         * @{
         */

        /**
         * @brief Release an object.
         * Delete the object if the object pointer is not null.
         * After destruction the object pointer is set to null.
         * @param p The reference to the object to delete.
         */
        template<class DataType>
        void Release(DataType& p)
        {
            if (p != 0)
            {
                delete p;
                p = 0;
            }
        }

        /**
         * @brief Release an object array.
         * Array delete the object array if the object pointer is not null.
         * After destruction the object pointer is set to null.
         * @param p The reference to the object array to delete.
         */
        template<class DataType>
        void ReleaseArray(DataType& p)
        {
            if (p != 0)
            {
                delete[] p;
                p = 0;
            }
        }

        /**
         * @brief Release an object of specified type.
         * The object is dynamic_cast'ed to the specified type
         * and deleted if the casted pointer is not null.
         * After destruction the object pointer is set to null.
         * @tparam DestType The type to dynamic_cast the object pointer to.
         * @param p The reference to the object to delete.
         * @return true if the pointer was deleted successfully.
         */
        template<class DestType, class SrcType>
        bool ReleaseType(SrcType& p)
        {
            DestType* t = dynamic_cast<DestType*>(p);
            if (t != 0)
            {
                delete t;
                p = 0;
                return true;
            }
            return false;
        }

        /**
         * @brief Clear the memory of a concrete type.
         * @param memory A reference to the memory to clear.
         */
        template<class DataType>
        void MemClear(DataType& memory)
        {
            System::CLib::MemSet(&memory, 0, sizeof(memory));
        }

        /**
         * @brief Set memory bytes to a given value.
         * @param memory The memory to set.
         * @param value The byte value to write into the memory.
         * @param byteSize The byte size of the memory location.
         */
        template<class DataType>
        void MemSet(DataType memory, UInt8 value, UInt64 byteSize)
        {
            System::CLib::MemSet(memory, value, byteSize);
        }

        /**
         * @brief Copy memory bytes.
         * @param destination The destination memory.
         * @param source The source memory.
         * @param byteSize The number of bytes to copy.
         */
        template<class DestType, class SrcType>
        void MemCopy(DestType destination, const SrcType source, UInt64 byteSize)
        {
            System::CLib::MemCopy(destination, source, byteSize);
        }

        /**
         * @brief Copy the memory of a concrete type.
         * The source and destination memory must be the same type.
         * @param destination A reference to the destination memory.
         * @param source A reference to the source memory.
         */
        template<class DataType>
        void MemCopyArray(DataType& destination, const DataType& source)
        {
            System::CLib::MemCopy(destination, source, sizeof(destination));
        }

        /**
         * @brief Move overlapping memory bytes.
         * @param destination The destination memory.
         * @param source The source memory.
         * @param byteSize The number of bytes to move.
         */
        template<class DestType, class SrcType>
        void MemMove(DestType destination, const SrcType source, UInt64 byteSize)
        {
            System::CLib::MemMove(destination, source, byteSize);
        }

        /**
         * @brief Compare memory bytes.
         * @param source1 The 1st source memory.
         * @param source2 The 2nd source memory.
         * @param byteSize The number of bytes to compare.
         * @return Zero if source1 is equal to source2,
         *  negativ if source1 is lesser than source2,
         *  positive if source1 is greater than source2.
         */
        template<class DataType1, class DataType2>
        SInt32 MemCompare(const DataType1 source1, const DataType2 source2, UInt64 byteSize)
        {
            return System::CLib::MemCompare(source1, source2, byteSize);
        }

        /**
         * @brief Fill the memory of a concrete type.
         * @param dstPtr The destination memory start pointer.
         * @param dstEnd The destination memory end pointer.
         * @param value The value to fill.
         */
        template<class DataType>
        void Fill(DataType* dstPtr, const DataType* dstEnd, const DataType& value)
        {
            while (dstPtr < dstEnd)
            {
                *dstPtr++ = value;
            }
        }

        /**
         * @brief Set all C-array elements to a given value.
         * @param array A reference to the C-array to set.
         * @param value The value to set for each array item.
         */
        template<class ArrayType, class DataType>
        void FillArray(ArrayType& array, const DataType& value)
        {
            for (UInt32 i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
            {
                array[i] = value;
            }
        }

        /**
         * @brief Find the first appearance of a concrete type in memory.
         * @param memory The source memory pointer.
         * @param item The item to find.
         * @param maxElements The maximum number of items to scan.
         * @return The zero-based index of the item or
         *  maxElements if the item was not found.
         */
        template<class DataType>
        UInt32 Find(const DataType* memory, const DataType& item, UInt32 maxElements)
        {
            UInt32 i = 0;
            for (; i < maxElements; i++)
            {
                if (memory[i] == item)
                {
                    break;
                }
            }
            return i;
        }

        /**
         * @brief Find the first appearance of an item in a C-array.
         * @param array A reference to the C-array.
         * @param item The item to find.
         * @return The zero-based index of the item or
         *  (sizeof(array) / sizeof(array[0])) if the item was not found.
         */
        template<class ArrayType, class DataType>
        UInt32 FindArray(ArrayType& array, const DataType& item)
        {
            UInt32 i = 0;
            for (; i < (sizeof(array) / sizeof(array[0])); i++)
            {
                if (array[i] == item)
                {
                    break;
                }
            }
            return i;
        }

        /**
         * @brief Swap two values.
         * @param a The 1st value to swap.
         * @param b The 2nd value to swap.
         */
        template<class DataType>
        void Swap(DataType& a, DataType& b)
        {
            DataType tmp = a;
            a = b;
            b = tmp;
        }

        /**
         * @brief Round a value to the next power of two.
         * @param value The value to round.
         * @return The value rounded to the next power of two.
         */
        template<class DataType>
        DataType RoundToNextPowerOfTwo(DataType value)
        {
            if (value == 0)
            {
                return 0;
            }

            value--;
            UInt32 n = 0;
            while (value > 0)
            {
                value >>= 1;
                n++;
            }

            return (DataType(1) << n);
        }

        /**
         * @brief Check if a given value equals a power of two.
         * @param value The value to check.
         * @return true if the value is a power of two.
         */
        template<class DataType>
        Bool IsPowerOfTwo(DataType value)
        {
            return (value == RoundToNextPowerOfTwo<DataType>(value));
        }

        /**
         * @brief Round a value to the next 4 byte boundary.
         * @param value The value to round.
         * @return The value rounded to the next 4 byte boundary.
         */
        template<class DataType>
        DataType RoundToNextFourByteBoundary(DataType value)
        {
            return ((value + DataType(3)) & ~DataType(3));
        }

        /**
         * @brief Round a value to the next 8 byte boundary.
         * @param value The value to round.
         * @return The value rounded to the next 8 byte boundary.
         */
        template<class DataType>
        DataType RoundToNextEightByteBoundary(DataType value)
        {
            return ((value + DataType(7)) & ~DataType(7));
        }

        /**
         * @brief Round a value to the next 16 byte boundary.
         * @param value The value to round.
         * @return The value rounded to the next 16 byte boundary.
         */
        template<class DataType>
        DataType RoundToNextSixteenByteBoundary(DataType value)
        {
            return ((value + DataType(15)) & ~DataType(15));
        }

        /**
         * @brief Round a value to the next raster and return the rounded value
         * and the difference to the previous raster before rounding.
         * @param value The value to round.
         * @param raster The raster to round to.
         * @param diff The difference return value.
         * @return The value rounded to the next raster.
         */
        template<class DataType>
        DataType RoundToRaster(DataType value, DataType raster, DataType& diff)
        {
            if (raster > 0)
            {
                diff = value % raster;
                if (diff != 0)
                {
                    diff = raster - diff;
                    value += diff;
                }
                return value;
            }
            return 0;
        }

        /**
         * @brief Round a value to the next raster.
         * @param value The value to round.
         * @param raster The raster to round to.
         * @return The value rounded to the next raster.
         */
        template<class DataType>
        DataType RoundToRaster(DataType value, DataType raster)
        {
            DataType diff;
            return RoundToRaster(value, raster, diff);
        }

        /**
         * @brief Compute the number of set bits.
         * @param value The value to count the set bits.
         * @return The number of set bits.
         */
        template<class DataType>
        UInt32 GetNumberOfSetBits(DataType value)
        {
            UInt32 num = 0;
            for (UInt32 i = 0; i < (sizeof(DataType) * 8); i++)
            {
                if (value & 1)
                {
                    num++;
                }
                value >>= 1;
            }
            return num;
        }

        /**
         * @brief Compute the number of cleared bits.
         * @param value The value to count the cleared bits.
         * @return The number of cleared bits.
         */
        template<class DataType>
        UInt32 GetNumberOfClearedBits(DataType value)
        {
            return GetNumberOfSetBits(~value);
        }

        /**
         * @brief Compute the number of digits.
         * @param value The value to compute the number of digits.
         * @param base The base of the digits.
         * @return The number of digits.
         */
        template<class DataType>
        UInt32 GetNumberOfDigits(DataType value, DataType base = 10)
        {
            UInt32 num = 0;
            if (base > 0)
            {
                while (value > 0)
                {
                    num++;
                    value /= base;
                }
            }
            return num;
        }

        /**
         * @brief Get a constant static empty data object.
         * @return The constant static empty data object.
         */
        const Data& StaticEmptyData();

        /**
         * @brief Swap all bytes of a 64 bit value.
         * @param value The value to swap the bytes.
         * @return The value in reverse byte ordering.
         */
        UInt64 SwapBytes(UInt64 value);

        /**
         * @brief Swap all bytes of a 32 bit value.
         * @param value The value to swap the bytes.
         * @return The value in reverse byte ordering.
         */
        UInt32 SwapBytes(UInt32 value);

        /**
         * @brief Swap all bytes of a 16 bit value.
         * @param value The value to swap the bytes.
         * @return The value in reverse byte ordering.
         */
        UInt16 SwapBytes(UInt16 value);

        /**
         * @brief Check if the engine was built using the debug configuration.
         * @return true if the engine was built using the debug configuration.
         */
        inline Bool IsDebugBuild()
        {
#ifdef MURL_DEBUG
            return true;
#else
            return false;
#endif
        }

        /**
         * @brief Check if the engine was built using the release configuration.
         * @return true if the engine was built using the release configuration.
         */
        inline Bool IsReleaseBuild()
        {
#ifdef MURL_RELEASE
            return true;
#else
            return false;
#endif
        }

        /** @} */
    }
}

#endif // __MURL_UTIL_H__

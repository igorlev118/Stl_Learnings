// Copyright 2011-2014 Spraylight GmbH

#ifndef __MURL_BITFIELD_H__
#define __MURL_BITFIELD_H__

#include "murl_array.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief The bitfield class.
     */
    class Bitfield
    {
    public:
        /**
         * @brief The default constructor.
         * Create an empty bitfield.
         */
        Bitfield()
        {
        }

        /**
         * @brief Empty the bitfield.
         */
        void Empty()
        {
            mBits.Empty();
        }

        /**
         * @brief Set a bit in the bitfield.
         * Extends the bitfield if the bitIndex is greater than
         *  the current number of bits, new bits are set to zero.
         * @param bitIndex The zero based index of the bit to set.
         */
        void Set(UInt32 bitIndex)
        {
            UInt32 arrayIndex = bitIndex / BITS_PER_ENTRY;
            if (arrayIndex >= UInt32(mBits.GetCount()))
            {
                mBits.SetCount(arrayIndex + 1, 0);
            }
            UInt32 bitMask = 1 << (bitIndex & ENTRY_MASK);
            mBits[arrayIndex] |= bitMask;
        }

        /**
         * @brief Clear a bit in the bitfield.
         * Extends the bitfield if the bitIndex is greater than
         *  the current number of bits, new bits are set to zero.
         * @param bitIndex The zero based index of the bit to clear.
         */
        void Clear(UInt32 bitIndex)
        {
            UInt32 arrayIndex = bitIndex / BITS_PER_ENTRY;
            if (arrayIndex >= UInt32(mBits.GetCount()))
            {
                mBits.SetCount(arrayIndex + 1, 0);
            }
            UInt32 bitMask = 1 << (bitIndex & ENTRY_MASK);
            mBits[arrayIndex] &= ~bitMask;
        }

        /**
         * @brief Check if a bit is set in the bitfield.
         * @param bitIndex The zero based index of the bit to test.
         * @return true if the bit is set, false if the index is out of range.
         */
        Bool IsSet(UInt32 bitIndex) const
        {
            UInt32 arrayIndex = bitIndex / BITS_PER_ENTRY;
            if (arrayIndex >= UInt32(mBits.GetCount()))
            {
                return false;
            }
            UInt32 bitMask = 1 << (bitIndex & ENTRY_MASK);
            return (mBits[arrayIndex] & bitMask) != 0;
        }

        /**
         * @brief Check if a bit is cleared in the bitfield.
         * @param bitIndex The zero based index of the bit to test.
         * @return true if the bit is cleared or the index is out of range.
         */
        Bool IsCleared(UInt32 bitIndex) const
        {
            UInt32 arrayIndex = bitIndex / BITS_PER_ENTRY;
            if (arrayIndex >= UInt32(mBits.GetCount()))
            {
                return true;
            }
            UInt32 bitMask = 1 << (bitIndex & ENTRY_MASK);
            return (mBits[arrayIndex] & bitMask) == 0;
        }

        /**
         * @brief Get the number of allocated bits in the bitfield.
         * @return The number of allocated bits in the bitfield.
         */
        UInt32 GetBitsCount() const
        {
            return mBits.GetCount() * BITS_PER_ENTRY;
        }

        /**
         * @brief Set the number of bits in the bitfield.
         * The bitfield is allocated in 32-bit steps, if the
         * bitfield is extended, the new bits are set to zero.
         * @param numBits The new number of bits in the bitfield.
         * @return The number of allocated bits in the bitfield.
         */
        UInt32 SetBitsCount(UInt32 numBits)
        {
            mBits.SetCount((numBits / BITS_PER_ENTRY) + 1, 0);
            return mBits.GetCount() * BITS_PER_ENTRY;
        }

        /**
         * @brief Get the pointer to the first bitfield byte.
         * @return The pointer to the first bitfield byte.
         */
        const UInt8* Begin() const
        {
            return reinterpret_cast<const UInt8*>(mBits.Begin());
        }

        /**
         * @brief Get the pointer next to the last bitfield byte.
         * @return The pointer next to the last bitfield byte.
         */
        const UInt8* End() const
        {
            return reinterpret_cast<const UInt8*>(mBits.End());
        }

        /**
         * @brief Get the byte size of the bitfield.
         * @return The number of bytes used by the bitfield.
         */
        UInt32 GetByteSize() const
        {
            return mBits.GetCount() * sizeof(UInt32);
        }

    protected:
        enum
        {
            BITS_PER_ENTRY = sizeof(UInt32) * 8,
            ENTRY_MASK = BITS_PER_ENTRY - 1
        };
        Array<UInt32> mBits;
    };
}

#endif  // __MURL_BITFIELD_H__

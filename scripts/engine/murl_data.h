// Copyright 2011-2015 Spraylight GmbH

#ifndef __MURL_DATA_H__
#define __MURL_DATA_H__

#include "murl_string.h"
#include "murl_util_hash.h"
#include "murl_debug_trace.h"
#include "murl_debug_assert.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief The ConstData object holds a pointer and size information
     * to a read-only memory data location. 
     * see also Data, BufferedData
     */
    class ConstData
    {
    public:
        /**
         * @brief The default constructor.
         */
        ConstData()
        : mData(0)
        , mByteSize(0)
        {
        }

        /**
         * @brief The constructor taking data and byte size.
         * @param data Pointer to the memory data location.
         * @param byteSize Byte size of the memory data location.
         */
        ConstData(const void* data, UInt64 byteSize)
        : mData(0)
        , mByteSize(0)
        {
            if (data != 0)
            {
                mData = static_cast<UInt8*>(const_cast<void*>(data));
                mByteSize = byteSize;
            }
        }

        /**
         * @brief The destructor.
         */
        virtual ~ConstData()
        {
        }

        /**
         * @brief Release the data, set data pointer to null and size to zero.
         */
        virtual void ReleaseData()
        {
            mData = 0;
            mByteSize = 0;
        }

        /**
         * @brief Assign a memory data location.
         * @param data Pointer to the memory data location.
         * @param byteSize Byte size of the memory data location.
         */
        virtual void AssignData(const void* data, UInt64 byteSize)
        {
            if (data != 0)
            {
                mData = static_cast<UInt8*>(const_cast<void*>(data));
                mByteSize = byteSize;
            }
            else
            {
                mData = 0;
                mByteSize = 0;
            }
        }

        /**
         * @brief Check if the data object is empty.
         * @return true if the data pointer is null.
         */
        Bool IsEmpty() const
        {
            return mData == 0;
        }

        /**
         * @brief Get the 32 bit byte size of the memory data location.
         * @return The 32 bit byte size of the memory data location
         *  or zero if the memory data byte size does not fit into 32 bit.
         */
        UInt32 GetByteSize32() const
        {
            if (mByteSize > UInt64(0xffffffffU))
            {
                MURL_TRACE(0, "Byte size does not fit into 32 bit %llu", mByteSize);
                return 0;
            }
            return UInt32(mByteSize);
        }

        /**
         * @brief Get the byte size of the memory data location.
         * @return The byte size of the memory data location.
         */
        UInt64 GetByteSize() const
        {
            return mByteSize;
        }

        /**
         * @brief Get the pointer to the memory data location.
         * @tparam DataType The type of the returned pointer.
         * @return The pointer to the memory data location.
         */
        template<class DataType>
        const DataType* GetData() const
        {
            return reinterpret_cast<const DataType*>(mData);
        }

        /**
         * @brief Get the pointer to the memory data location.
         * @return The pointer to the memory data location.
         */
        const UInt8* GetData() const
        {
            return mData;
        }

        /**
         * @brief Get the pointer to the memory data location including a byte offset.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @tparam DataType The type of the returned pointer.
         * @param byteOffset The byte offset.
         * @return The pointer to the memory data location
         *  or null if the byte offset is out of range.
         */
        template<class DataType>
        const DataType* GetData(UInt64 byteOffset) const
        {
            if (byteOffset < mByteSize)
            {
                return reinterpret_cast<const DataType*>(mData + byteOffset);
            }
            return 0;
        }

        /**
         * @brief Get the pointer to the memory data location including a byte offset.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @param byteOffset The byte offset.
         * @return The pointer to the memory data location
         *  or null if the byte offset is out of range.
         */
        const UInt8* GetData(UInt64 byteOffset) const
        {
            if (byteOffset < mByteSize)
            {
                return mData + byteOffset;
            }
            return 0;
        }

        /**
         * @brief Copy the memory data to a destination.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @param destination The pointer to the destination memory.
         * @param byteSize The destination byte size.
         * @param byteOffset The source byte offset.
         * @return The number of bytes copied to the destination.
         */
        UInt64 CopyTo(void* destination, UInt64 byteSize, UInt64 byteOffset) const
        {
            if ((destination != 0) && (byteSize != 0) && (byteOffset < mByteSize))
            {
                if (byteSize > mByteSize - byteOffset)
                {
                    byteSize = mByteSize - byteOffset;
                }
                Util::MemCopy(destination, mData + byteOffset, byteSize);
                return byteSize;
            }
            return 0;
        }

        /**
         * @brief Get a string from the memory data.
         * (!) This method does not take care of zero termination.
         * @return The string object containing the memory data.
         */
        String GetString() const
        {
            return String(mData, SInt32(mByteSize));
        }

        /**
         * @brief Get a string from the memory data with length.
         * (!) This method does not take care of zero termination.
         * @param length The length of the string.
         * @return The string object containing the memory data.
         */
        String GetString(UInt64 length) const
        {
            if (length > mByteSize)
            {
                length = mByteSize;
            }
            return String(mData, SInt32(length));
        }

        /**
         * @brief Calculate the data hash value.
         * @return The hash value.
         */
        UInt64 GetHashValue() const
        {
            return Util::Hash::GetMemoryHashValue(mData, mByteSize);
        }

        /**
         * @brief Equal to comparison operator.
         * @param rhs The right hand side data to compare.
         * @return true if the memory bytes are equal.
         */
        bool operator==(const ConstData& rhs) const
        {
            if (mByteSize == rhs.mByteSize)
            {
                if (Util::MemCompare(mData, rhs.mData, mByteSize) == 0)
                {
                    return true;
                }
            }
            return false;
        }

        /**
         * @brief Not equal to comparison operator.
         * @param rhs The right hand side data to compare.
         * @return true if the memory bytes are not equal.
         */
        bool operator!=(const ConstData& rhs) const
        {
            return !(*this == rhs);
        }

        /**
         * @brief Equal to comparison operator with string.
         * @param rhs The right hand side string to compare.
         * @return true if the memory and string bytes are equal.
         */
        bool operator==(const String& rhs) const
        {
            if (mByteSize == UInt64(rhs.GetLength()))
            {
                if (Util::MemCompare(mData, rhs.Begin(), mByteSize) == 0)
                {
                    return true;
                }
            }
            return false;
        }

        /**
         * @brief Not equal to comparison operator with string.
         * @param rhs The right hand side string to compare.
         * @return true if the memory and string bytes are not equal.
         */
        bool operator!=(const String& rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        UInt8* mData;
        UInt64 mByteSize;
    };

    /**
     * @ingroup MurlClasses
     * @brief The MutableData object holds a pointer and size information
     * to a mutable memory data location.
     */
    class MutableData : public ConstData
    {
    public:
        /**
         * @brief The default constructor.
         */
        MutableData()
        {
        }

        /**
         * @brief The constructor taking data and byte size.
         * @param data Pointer to the memory data location.
         * @param byteSize Byte size of the memory data location.
         */
        MutableData(void* data, UInt64 byteSize)
        {
            if (data != 0)
            {
                mData = static_cast<UInt8*>(data);
                mByteSize = byteSize;
            }
        }

        /**
         * @brief The destructor.
         */
        virtual ~MutableData()
        {
        }

        /**
         * @brief Get the pointer to the mutable memory data location.
         * @tparam DataType The type of the returned pointer.
         * @return The pointer to the mutable memory data location.
         */
        template<class DataType>
        DataType* GetMutableData() const
        {
            return reinterpret_cast<DataType*>(mData);
        }

        /**
         * @brief Get the pointer to the mutable memory data location.
         * @return The pointer to the mutable memory data location.
         */
        UInt8* GetMutableData() const
        {
            return mData;
        }

        /**
         * @brief Get the pointer to the mutable memory data location including a byte offset.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @tparam DataType The type of the returned pointer.
         * @param byteOffset The byte offset.
         * @return The pointer to the mutable memory data location
         *  or null if the byte offset is out of range.
         */
        template<class DataType>
        DataType* GetMutableData(UInt64 byteOffset) const
        {
            if (byteOffset < mByteSize)
            {
                return reinterpret_cast<DataType*>(mData + byteOffset);
            }
            return 0;
        }

        /**
         * @brief Get the pointer to the mutable memory data location including a byte offset.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @param byteOffset The byte offset.
         * @return The pointer to the mutable memory data location
         *  or null if the byte offset is out of range.
         */
        UInt8* GetMutableData(UInt64 byteOffset) const
        {
            if (byteOffset < mByteSize)
            {
                return mData + byteOffset;
            }
            return 0;
        }

        /**
         * @brief Copy the memory data to a destination data object.
         * The destination data object must have already assigned memory.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @param destination The the destination data object.
         * @param byteOffset The source byte offset.
         * @return The number of bytes copied to the destination.
         */
        UInt64 CopyDataTo(MutableData& destination, UInt64 byteOffset) const
        {
            return CopyTo(destination.mData, destination.mByteSize, byteOffset);
        }

        /**
         * @brief Copy the memory data from a source memory location.
         * The data object must have already assigned memory.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @param source The pointer to the source memory.
         * @param byteSize The source byte size.
         * @param byteOffset The destination byte offset.
         * @return The number of bytes copied to the destination.
         */
        UInt64 CopyFrom(const void* source, UInt64 byteSize, UInt64 byteOffset) const
        {
            if ((source != 0) && (byteSize != 0) && (byteOffset < mByteSize))
            {
                if (byteSize > mByteSize - byteOffset)
                {
                    byteSize = mByteSize - byteOffset;
                }
                Util::MemCopy(mData + byteOffset, source, byteSize);
                return byteSize;
            }
            return 0;
        }

        /**
         * @brief Copy the memory data from a source data object.
         * The data object must have already assigned memory.
         * A valid byte offset is in range [0 .. GetByteSize() - 1].
         * @param source The source data object.
         * @param byteOffset The destination byte offset.
         * @return The number of bytes copied to the destination.
         */
        UInt64 CopyDataFrom(const ConstData& source, UInt64 byteOffset) const
        {
            return CopyFrom(source.GetData(), source.GetByteSize(), byteOffset);
        }
    };

    /**
     * @ingroup MurlClasses
     * @brief The Data object holds a pointer and size information
     * to an allocated memory data location. 
     * see also ConstData, BufferedData
     *
     * Usage examples:
     * @code
     *  #include "murl_data.h"
     *  
     *  // convert to / from String
     *  String s("abc");
     *  Data data(s);
     *  String s = data.GetString();
     *
     *  // convert to / from Hex String
     *  Data key = Util::DecodeHex("0123456789ABCDEF");
     *  String hexString = Util::EncodeHex(key.GetString());
     *
     *  // convert to / from UInt8Array
     *  UInt8Array byteArray;
     *  for (UInt32 i = 0; i < 100; i++)
     *  {
     *      byteArray.Add(i);
     *  }
     *  Data data;
     *  data.ResizeData(byteArray.GetByteSize());
     *  data.CopyFrom(byteArray.Begin(), byteArray.GetCount(), 0);
     *
     *  byteArray.Clear();
     *  byteArray.SetCount(data.GetByteSize());
     *  data.CopyTo(byteArray.Begin(), byteArray.GetCount(), 0);
     * @endcode
     */
    class Data : public MutableData
    {
    public:
        /**
         * @brief The default constructor.
         */
        Data()
        {
        }

        /**
         * @brief Constructor allocating memory.
         * The allocated memory is filled with zeros.
         * @param byteSize Byte size of the memory to allocate.
         */
        Data(UInt64 byteSize)
        {
            if (byteSize > 0)
            {
                mByteSize = byteSize;
                mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(mByteSize)];
                Util::MemSet(mData, 0, mByteSize);
            }
        }

        /**
         * @brief Constructor allocating memory and copying data.
         * @param data Pointer to the memory data location to copy.
         * @param byteSize Byte size of the memory to allocate and copy.
         */
        Data(const void* data, UInt64 byteSize)
        {
            if ((byteSize > 0) && (data != 0))
            {
                mByteSize = byteSize;
                mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(mByteSize)];
                Util::MemCopy(mData, data, mByteSize);
            }
        }

        /**
         * @brief The destructor.
         * Free (delete) the memory.
         */
        virtual ~Data()
        {
            Util::ReleaseArray(mData);
        }

        /**
         * @brief Release the data.
         * Free (delete) the memory.
         */
        virtual void ReleaseData()
        {
            Util::ReleaseArray(mData);
            mByteSize = 0;
        }

        /**
         * @brief Return the data memory and give up ownership.
         * After detaching the object's data and byte size is null.
         * (!) The client is responsible for deletion of the returned memory data.
         * @tparam DataType The type of the returned pointer.
         * @param byteSize The byte size of the memory data return value.
         * @return The pointer to the heap allocated memory data.
         */
        template<class DataType>
        DataType* DetachData(UInt64& byteSize)
        {
            DataType* data = reinterpret_cast<DataType*>(mData);
            byteSize = mByteSize;
            mData = 0;
            mByteSize = 0;
            return data;
        }

        /**
         * @brief Return the data memory and give up ownership.
         * After detaching the object's data and byte size is null.
         * (!) The client is responsible for deletion of the returned memory data.
         * @param byteSize The byte size of the memory data return value.
         * @return The pointer to the heap allocated memory data.
         */
        UInt8* DetachData(UInt64& byteSize)
        {
            UInt8* data = mData;
            byteSize = mByteSize;
            mData = 0;
            mByteSize = 0;
            return data;
        }

        /**
         * @brief Assign data by allocating memory and copying the data.
         * @param data Pointer to the memory data location to copy.
         * @param byteSize Byte size of the memory to allocate and copy.
         */
        virtual void AssignData(const void* data, UInt64 byteSize)
        {
            if ((byteSize == mByteSize) && (data != 0))
            {
                Util::MemCopy(mData, data, byteSize);
            }
            else
            {
                Util::ReleaseArray(mData);
                if ((byteSize > 0) && (data != 0))
                {
                    mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(byteSize)];
                    mByteSize = byteSize;
                    Util::MemCopy(mData, data, byteSize);
                }
                else
                {
                    mByteSize = 0;
                }
            }
        }

        /**
         * @brief Obtain a memory data location.
         * (!) Obtaining memory requires an allocated memory location,
         * the data object takes the ownership of the memory and free
         * (delete) the memory if necessary.
         * @param data Pointer to the memory data location.
         * @param byteSize Byte size of the memory data location.
         */
        void ObtainData(void* data, UInt64 byteSize)
        {
            Util::ReleaseArray(mData);
            if (data != 0)
            {
                mData = static_cast<UInt8*>(data);
                mByteSize = byteSize;
            }
            else
            {
                mByteSize = 0;
            }
        }

        /**
         * @brief Obtain the memory from a data object.
         * The source data object is empty after obtaining.
         * @param data The data object to obtain.
         */
        void ObtainData(Data& data)
        {
            ObtainData(data.mData, data.mByteSize);
            data.mData = 0;
            data.mByteSize = 0;
        }

        /**
         * @brief Resize the memory.
         * The content of the current memory is copied into the resized memory.
         * The current memory is truncated if the new size is smaller, the
         * remaining new memory is filled with zeros if the new size is larger.
         * @param newByteSize The new byte size of the memory.
         */
        void ResizeData(UInt64 newByteSize)
        {
            if (newByteSize == 0)
            {
                Util::ReleaseArray(mData);
                mByteSize = 0;
            }
            else if (newByteSize != mByteSize)
            {
                UInt8* newData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(newByteSize)];
                if (newByteSize > mByteSize)
                {
                    if (mByteSize != 0)
                    {
                        Util::MemCopy(newData, mData, mByteSize);
                    }
                    Util::MemSet(newData + mByteSize, 0, newByteSize - mByteSize);
                }
                else
                {
                    if (mByteSize != 0)
                    {
                        Util::MemCopy(newData, mData, newByteSize);
                    }
                }
                Util::ReleaseArray(mData);
                mData = newData;
                mByteSize = newByteSize;
            }
        }

        /**
         * @brief Append data to the current memory.
         * @param data Pointer to the memory data location to append.
         * @param byteSize Byte size of the memory to append.
         */
        virtual void AppendData(const void* data, UInt64 byteSize)
        {
            if ((byteSize > 0) && (data != 0))
            {
                UInt64 newByteSize = mByteSize + byteSize;
                UInt8* newData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(newByteSize)];
                Util::MemCopy(newData, mData, mByteSize);
                Util::MemCopy(newData + mByteSize, data, byteSize);
                Util::ReleaseArray(mData);
                mData = newData;
                mByteSize = newByteSize;
            }
        }

        /**
         * @brief The copy constructor taking a ConstData object.
         * @param data The data object to copy.
         */
        Data(const ConstData& data)
        {
            if ((data.GetByteSize() > 0) && (data.GetData() != 0))
            {
                mByteSize = data.GetByteSize();
                mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(mByteSize)];
                Util::MemCopy(mData, data.GetData(), mByteSize);
            }
        }

        /**
         * @brief The copy constructor taking a MutableData object.
         * @param data The data object to copy.
         */
        Data(const MutableData& data)
        {
            if ((data.GetByteSize() > 0) && (data.GetData() != 0))
            {
                mByteSize = data.GetByteSize();
                mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(mByteSize)];
                Util::MemCopy(mData, data.GetData(), mByteSize);
            }
        }

        /**
         * @brief The copy constructor.
         * @param data The data object to copy.
         */
        Data(const Data& data)
        {
            if ((data.GetByteSize() > 0) && (data.GetData() != 0))
            {
                mByteSize = data.GetByteSize();
                mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(mByteSize)];
                Util::MemCopy(mData, data.GetData(), mByteSize);
            }
        }

        /**
         * @brief The copy constructor taking an Array object.
         * @param array The array object to copy.
         */
        template<class DataType>
        Data(const Array<DataType>& array)
        {
            if (array.GetCount() > 0)
            {
                mByteSize = array.GetByteSize();
                mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(mByteSize)];
                Util::MemCopy(mData, array, mByteSize);
            }
        }

        /**
         * @brief The copy constructor taking a String object.
         * @param string The string object to copy.
         */
        Data(const String& string)
        {
            if (string.GetLength() > 0)
            {
                mByteSize = string.GetLength();
                mData = new UInt8[MURL_VERIFY_ALLOCATION_SIZE(mByteSize)];
                Util::MemCopy(mData, string.Begin(), mByteSize);
            }
        }

        /**
         * @brief Assignment operator taking a ConstData object.
         * @param data The data object to copy.
         * @return The object itself.
         */
        Data& operator=(const ConstData& data)
        {
            if (this != &data)
            {
                AssignData(data.GetData(), data.GetByteSize());
            }
            return *this;
        }

        /**
         * @brief Assignment operator taking a MutableData object.
         * @param data The data object to copy.
         * @return The object itself.
         */
        Data& operator=(const MutableData& data)
        {
            if (this != &data)
            {
                AssignData(data.GetData(), data.GetByteSize());
            }
            return *this;
        }

        /**
         * @brief Assignment operator.
         * @param data The data object to copy.
         * @return The object itself.
         */
        Data& operator=(const Data& data)
        {
            if (this != &data)
            {
                AssignData(data.GetData(), data.GetByteSize());
            }
            return *this;
        }

        /**
         * @brief Assignment operator taking a String object.
         * @param string The string object to copy.
         * @return The object itself.
         */
        Data& operator=(const String& string)
        {
            AssignData(string.Begin(), string.GetLength());
            return *this;
        }

        /**
         * @brief Assignment operator taking an Array object.
         * @param array The array object to copy.
         * @return The object itself.
         */
        template<class DataType>
        Data& operator=(const Array<DataType>& array)
        {
            AssignData(array, array.GetByteSize());
            return *this;
        }

        /**
         * @brief In-place addition operator taking a ConstData object.
         * @param data The data object to append.
         * @return The object itself.
         */
        Data& operator+=(const ConstData& data)
        {
            AppendData(data.GetData(), data.GetByteSize());
            return *this;
        }

        /**
         * @brief In-place addition operator taking a MutableData object.
         * @param data The data object to append.
         * @return The object itself.
         */
        Data& operator+=(const MutableData& data)
        {
            AppendData(data.GetData(), data.GetByteSize());
            return *this;
        }

        /**
         * @brief In-place addition operator.
         * @param data The data object to append.
         * @return The object itself.
         */
        Data& operator+=(const Data& data)
        {
            AppendData(data.GetData(), data.GetByteSize());
            return *this;
        }

        /**
         * @brief In-place addition operator taking a String object.
         * @param string The string object to append.
         * @return The object itself.
         */
        Data& operator+=(const String& string)
        {
            AppendData(string.Begin(), string.GetLength());
            return *this;
        }

        /**
         * @brief In-place addition operator taking an Array object.
         * @param array The array object to append.
         * @return The object itself.
         */
        template<class DataType>
        Data& operator+=(const Array<DataType>& array)
        {
            AppendData(array, array.GetByteSize());
            return *this;
        }
    };

    /**
     * @ingroup MurlClasses
     * @brief The BufferedData object extends the Data object for appending data portions
     * to pre-allocated memory. The memory grows by doubling the memory size if needed.
     * If the memory exceeds a size threshold, the memory grows in steps of the threshold.
     * The size threshold is ignored if the size threshold is 0.
     */
    class BufferedData : public Data
    {
    public:
        /**
         * @brief The default constructor.
         * Initializes the write position to 0 and the size threshold to 64 kilobytes.
         */
        BufferedData()
        : mWritePosition(0)
        , mSizeThreshold(64 * 1024)
        {
        }

        /**
         * @brief Release the data.
         * Free (delete) the memory and set the write position to 0.
         */
        virtual void ReleaseData()
        {
            Data::ReleaseData();
            mWritePosition = 0;
        }

        /**
         * @brief Assign data by copying the data to position 0.
         * The memory grows by doubling the memory size if needed. If the memory
         * exceeds the size threshold, the memory grows in steps of the threshold.
         * The size threshold is ignored if the size threshold is 0.
         * @param data Pointer to the memory data location to copy.
         * @param byteSize Byte size of the memory to allocate and copy.
         */
        virtual void AssignData(const void* data, UInt64 byteSize)
        {
            mWritePosition = 0;
            AppendData(data, byteSize);
        }

        /**
         * @brief Append data to the current write position.
         * The memory grows by doubling the memory size if needed. If the memory
         * exceeds the size threshold, the memory grows in steps of the threshold.
         * The size threshold is ignored if the size threshold is 0.
         * @param data Pointer to the memory data location to append.
         * @param byteSize Byte size of the memory to append.
         */
        virtual void AppendData(const void* data, UInt64 byteSize)
        {
            UInt64 newSize = mWritePosition + byteSize;
            if (newSize > mByteSize)
            {
                if ((mSizeThreshold > 0) && (newSize < mSizeThreshold))
                {
                    newSize = Util::RoundToNextPowerOfTwo(newSize);
                }
                else
                {
                    newSize = Util::RoundToRaster(newSize, mSizeThreshold);
                }
                ResizeData(newSize);
            }
            CopyFrom(data, byteSize, mWritePosition);
            mWritePosition += byteSize;
        }

        /**
         * @brief Set the memory growing size threshold.
         * See AppendData().
         * @param sizeThreshold The memory growing size threshold in bytes.
         */
        void SetSizeThreshold(UInt64 sizeThreshold)
        {
            mSizeThreshold = sizeThreshold;
        }

        /**
         * @brief Get the memory growing size threshold.
         * See AppendData().
         * @return The memory growing size threshold in bytes.
         */
        UInt64 GetSizeThreshold() const
        {
            return mSizeThreshold;
        }

        /**
         * @brief Set the write position.
         * @param bytePosition The write position in bytes.
         */
        void SetWritePosition(UInt64 bytePosition)
        {
            mWritePosition = bytePosition;
        }

        /**
         * @brief Get the write position.
         * @return The write position in bytes.
         */
        UInt64 GetWritePosition() const
        {
            return mWritePosition;
        }

        /**
         * @brief Trim the memory size to the write position.
         * @return The data object itself.
         */
        Data& Trim()
        {
            if (mByteSize > mWritePosition)
            {
                mByteSize = mWritePosition;
            }
            return *this;
        }

    protected:
        UInt64 mWritePosition;
        UInt64 mSizeThreshold;
    };
}

#endif  // __MURL_DATA_H__

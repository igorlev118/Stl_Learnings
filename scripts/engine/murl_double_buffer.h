// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_DOUBLE_BUFFER_H__
#define __MURL_DOUBLE_BUFFER_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A double buffer template class.
     * The double buffer holds a read and write value and
     * can check the change of the values.
     */
    template<class DataType>
    class DoubleBuffer
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor.
         */
        DoubleBuffer()
        : mReadValue()
        , mWriteValue()
        {
        }

        /**
         * @brief The constructor taking a default value.
         * @param value The read and write value.
         */
        DoubleBuffer(const DataType& value)
        : mReadValue(value)
        , mWriteValue(value)
        {
        }

        /**
         * @brief Reset the read and write value with the value's
         * default constructor.
         */
        void Reset()
        {
            mReadValue = DataType();
            mWriteValue = DataType();
        }

        /**
         * @brief Reset the read and write value with a given value.
         * @param value The read and write value.
         */
        void Reset(const DataType& value)
        {
            mReadValue = value;
            mWriteValue = value;
        }

        /**
         * @brief Reset the read value with the value's default constructor.
         */
        void ResetReadValue()
        {
            mReadValue = DataType();
        }

        /**
         * @brief Reset the read value with a given value.
         * @param value The read value.
         */
        void ResetReadValue(const DataType& value)
        {
            mReadValue = value;
        }

        /**
         * @brief Reset the write value with the value's default constructor.
         */
        void ResetWriteValue()
        {
            mWriteValue = DataType();
        }

        /**
         * @brief Reset the write value with a given value.
         * @param value The write value.
         */
        void ResetWriteValue(const DataType& value)
        {
            mWriteValue = value;
        }

        /**
         * @brief Assign the write value to the read value.
         */
        void Update()
        {
            mReadValue = mWriteValue;
        }

        /**
         * @brief Assign the write value to the read value and set the write value.
         * @param value The write value.
         */
        void Update(const DataType& value)
        {
            Update();
            mWriteValue = value;
        }

        /**
         * @brief Check if the write value has changed.
         * @return true if the write value is not equal to the read value.
         */
        Bool HasChanged() const
        {
            return mReadValue != mWriteValue;
        }

        /**
         * @brief Check if the write value has changed and update.
         *  If true assign the write value to the read value.
         * @return true if the write value was not equal to the read value.
         */
        Bool UpdateChanged()
        {
            if (HasChanged())
            {
                Update();
                return true;
            }
            return false;
        }

        /**
         * @brief Set the write value.
         * @param value The write value.
         */
        void SetValue(const DataType& value)
        {
            mWriteValue = value;
        }

        /**
         * @brief Get the read value.
         * @return The read value.
         */
        const DataType& GetValue() const
        {
            return mReadValue;
        }

        /**
         * @brief Get the mutable read value.
         * @return The mutable read value.
         */
        DataType& GetValue()
        {
            return mReadValue;
        }

        /**
         * @brief Get the write value.
         * @return The write value.
         */
        const DataType& GetWriteValue() const
        {
            return mWriteValue;
        }

        /**
         * @brief Get the mutable write value.
         * @return The mutable write value.
         */
        DataType& GetWriteValue()
        {
            return mWriteValue;
        }

        /**
         * @brief Set the write value (assignment operator).
         * @param value The write value.
         * @return The object itself.
         */
        DoubleBuffer& operator=(const DataType& value)
        {
            SetValue(value);
            return *this;
        }

        /**
         * @brief Get the read value (conversion operator).
         * @return The read value.
         */
        operator const DataType&() const
        {
            return GetValue();
        }

    protected:
        DataType mReadValue;
        DataType mWriteValue;
    };
}

#endif  // __MURL_DOUBLE_BUFFER_H__

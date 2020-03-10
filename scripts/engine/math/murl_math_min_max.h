// Copyright 2015 Spraylight GmbH

#ifndef __MURL_MATH_MIN_MAX_H__
#define __MURL_MATH_MIN_MAX_H__

#include "murl_math_limits.h"
#include "murl_util_string_conversion.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief The minimum maximum values template class.
         * This template can be specialized with UInt32, SInt32, UInt64, SInt64, Float and Double, e.g:
         * @code
         * Math::MinMax<SInt32> range;
         * @endcode
         * Specialization of other datatypes require the LimitsType template parameter, e.g. use of System::Time:
         * @code
         * Math::MinMax<System::Time, System::Time> timeRange;
         * @endcode
         * @tparam DataType The minimum and maximum value datatype, must support being compared with operator<.
         * @tparam LimitsType The datatype's limits type, must implement a static %Min() and %Max() method.
         */
        template<class DataType, class LimitsType = Limits<DataType> >
        class MinMax
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             * Initialize the minimum with %LimitsType::Max() and the maximum with %LimitsType::Min().
             */
            MinMax()
            : mMin(LimitsType::Max())
            , mMax(LimitsType::Min())
            {
            }

            /**
             * @brief Constructor to initialize with a given minimum and maximum value.
             * @param min The minimum value.
             * @param max The maximum value.
             */
            MinMax(const DataType& min, const DataType& max)
            : mMin(min)
            , mMax(max)
            {
            }

            /**
             * @brief Constructor to initialize with given values.
             * Initialize the minimum with %LimitsType::Max() and the maximum with %LimitsType::Min()
             *  and Add() values from an array.
             * @param values The values to add.
             */
            MinMax(const Array<DataType>& values)
            : mMin(LimitsType::Max())
            , mMax(LimitsType::Min())
            {
                Add(values);
            }

            /**
             * @brief Reset the minimum and maximum value.
             * Set the minimum to %LimitsType::Max() and the maximum to %LimitsType::Min().
             */
            void Reset()
            {
                mMin = LimitsType::Max();
                mMax = LimitsType::Min();
            }

            /**
             * @brief Add a value.
             * Set the minimum to the value if the value is less than the current minimum.
             * Set the maximum to the value if the value is greater than the current maximum.
             * @param value The value to add.
             */
            void Add(const DataType& value)
            {
                if (value < mMin)
                {
                    mMin = value;
                }
                if (mMax < value)
                {
                    mMax = value;
                }
            }

            /**
             * @brief Add values.
             * Add() all values from an array.
             * @param values The values to add.
             */
            void Add(const Array<DataType>& values)
            {
                for (UInt32 i = 0; i < values.GetCount(); i++)
                {
                    Add(values[i]);
                }
            }

            /**
             * @brief Get the minimum.
             * @return The minimum.
             */
            const DataType& GetMin() const
            {
                return mMin;
            }

            /**
             * @brief Get the maximum.
             * @return The maximum.
             */
            const DataType& GetMax() const
            {
                return mMax;
            }

            /**
             * @brief Check if a value is in minimum / maximum range.
             * @param value The value to check.
             * @return true if the value is greater or equal the minimum
             *  and less or equal the maximum.
             */
            Bool IsInRange(const DataType& value) const
            {
                return (mMin <= value) && (value <= mMax);
            }

            /**
             * @brief Check if a value is in minimum / maximum range excluding the bounds.
             * @param value The value to check.
             * @return true if the value is greater the minimum and less the maximum.
             */
            Bool IsInRangeEx(const DataType& value) const
            {
                return (mMin < value) && (value < mMax);
            }

            /**
             * @brief Check if a value is in minimum / maximum range excluding minimum.
             * @param value The value to check.
             * @return true if the value is greater the minimum and less or equal the maximum.
             */
            Bool IsInRangeExMin(const DataType& value) const
            {
                return (mMin < value) && (value <= mMax);
            }

            /**
             * @brief Check if a value is in minimum / maximum range excluding maximum.
             * @param value The value to check.
             * @return true if the value is greater or equal the minimum and less the maximum.
             */
            Bool IsInRangeExMax(const DataType& value) const
            {
                return (mMin <= value) && (value < mMax);
            }

            /**
             * @brief Unite this MinMax with another MinMax object.
             * @param other The other MinMax object to unite.
             */
            void Unite(const MinMax& other)
            {
                if (other.mMin < mMin)
                {
                    mMin = other.mMin;
                }
                if (mMax < other.mMax)
                {
                    mMax = other.mMax;
                }
            }

            /**
             * @brief Set the minimum.
             * @param min The minimum to set.
             */
            void SetMin(const DataType& min)
            {
                mMin = min;
            }

            /**
             * @brief Set the maximum.
             * @param max The maximum to set.
             */
            void SetMax(const DataType& max)
            {
                mMax = max;
            }

            /**
             * @brief Set the minimum and the maximum.
             * @param min The maximum to set.
             * @param max The maximum to set.
             */
            void Set(const DataType& min, const DataType& max)
            {
                mMin = min;
                mMax = max;
            }

            /**
             * @brief Equal to comparison operator.
             * @param lhs The left hand side to compare.
             * @param rhs The right hand side to compare.
             * @return true if minimum and maximum are the same.
             */
            friend bool operator==(const MinMax& lhs, const MinMax& rhs)
            {
                return (lhs.mMin == rhs.mMin) && (lhs.mMin == rhs.mMin);
            }

            /**
             * @brief Not equal to comparison operator.
             * @param lhs The left hand side vector to compare.
             * @param rhs The right hand side vector to compare.
             * @return true if minimum and maximum are not the same.
             */
            friend bool operator!=(const MinMax& lhs, const MinMax& rhs)
            {
                return !operator==(lhs, rhs);
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return Util::ValueToString(mMin) + " - " + Util::ValueToString(mMax);
            }

        protected:
            /** @brief The minimum value. */
            DataType mMin;
            /** @brief The maximum value. */
            DataType mMax;
        };
    }
}

#endif // __MURL_MATH_MIN_MAX_H__

// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_LIMITS_H__
#define __MURL_MATH_LIMITS_H__

#include "murl_math_types.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief The limit values class.
         * This class typically implements std::numeric_limits<DataType>.
         * @tparam DataType Available for UInt32, SInt32, UInt64, SInt64, Float and Double.
         */
        template<class DataType>
        class Limits
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief Get the minimum finite value of the data type.
             * @return The minimum finite value of the data type.
             */
            static const DataType Min()
            {
                return sMin;
            }

            /**
             * @brief Get the maximum finite value of the data type.
             * @return The maximum finite value of the data type.
             */
            static const DataType Max()
            {
                return sMax;
            }

            /**
             * @brief Get the quiet (non-signaling) "Not-a-Number" value of the data type.
             * @return The quiet (non-signaling) "Not-a-Number" value of the data type
             *  or zero if not available (e.g. integer types).
             */
            static const DataType NaN()
            {
                return sNaN;
            }

            /**
             * @brief Get the positive infinity value of the data type.
             * @return The positive infinity value of the data type
             *  or zero if not available (e.g. integer types).
             */
            static const DataType Infinity()
            {
                return sInfinity;
            }

            /**
             * @brief Get the default epsilon value of the data type.
             *  The difference between 1 and the least value greater than 1 that is representable.
             * @return The default epsilon value of the data type.
             */
            static const DataType Epsilon()
            {
                return sEpsilon;
            }

        protected:
            static const DataType sMin;
            static const DataType sMax;
            static const DataType sNaN;
            static const DataType sInfinity;
            static const DataType sEpsilon;
        };

#ifdef MURL_USE_TEMPLATE_VARIABLE_FORWARD_DECLARATIONS
        template<> const UInt32 Limits<UInt32>::sMin;
        template<> const UInt32 Limits<UInt32>::sMax;
        template<> const UInt32 Limits<UInt32>::sNaN;
        template<> const UInt32 Limits<UInt32>::sInfinity;
        template<> const UInt32 Limits<UInt32>::sEpsilon;

        template<> const SInt32 Limits<SInt32>::sMin;
        template<> const SInt32 Limits<SInt32>::sMax;
        template<> const SInt32 Limits<SInt32>::sNaN;
        template<> const SInt32 Limits<SInt32>::sInfinity;
        template<> const SInt32 Limits<SInt32>::sEpsilon;

        template<> const UInt64 Limits<UInt64>::sMin;
        template<> const UInt64 Limits<UInt64>::sMax;
        template<> const UInt64 Limits<UInt64>::sNaN;
        template<> const UInt64 Limits<UInt64>::sInfinity;
        template<> const UInt64 Limits<UInt64>::sEpsilon;

        template<> const SInt64 Limits<SInt64>::sMin;
        template<> const SInt64 Limits<SInt64>::sMax;
        template<> const SInt64 Limits<SInt64>::sNaN;
        template<> const SInt64 Limits<SInt64>::sInfinity;
        template<> const SInt64 Limits<SInt64>::sEpsilon;

        template<> const Float Limits<Float>::sMin;
        template<> const Float Limits<Float>::sMax;
        template<> const Float Limits<Float>::sNaN;
        template<> const Float Limits<Float>::sInfinity;
        template<> const Float Limits<Float>::sEpsilon;

        template<> const Double Limits<Double>::sMin;
        template<> const Double Limits<Double>::sMax;
        template<> const Double Limits<Double>::sNaN;
        template<> const Double Limits<Double>::sInfinity;
        template<> const Double Limits<Double>::sEpsilon;
#endif
    }
}

#endif // __MURL_MATH_LIMITS_H__

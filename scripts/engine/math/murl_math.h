// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_MATH_H__
#define __MURL_MATH_H__

#include "murl_math_limits.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @addtogroup MurlMathFunctions
         * @brief Basic mathematic functions available for Float and Double data type.
         * @{
         */

        /**
         * @brief Get the absolute value.
         * @param value The input value.
         * @return The absolute value.
         */
        template<class DataType>
        DataType Abs(DataType value)
        {
            return (value < 0) ? -value : value;
        }

        /**
         * @brief Get the sign of a value.
         * @param value The input value.
         * @return 1 if the value is positive, -1 if the value is negative
         *  or zero if the value is zero.
         */
        template<class DataType>
        DataType Sgn(DataType value)
        {
            if (value < 0)
            {
                return -1;
            }
            if (value > 0)
            {
                return 1;
            }
            return 0;
        }

        /**
         * @brief Get the minimum of two values.
         * If both are equivalent, x is returned.
         * @param x The 1st value.
         * @param y The 2nd value.
         * @return The lesser value of x and y.
         */
        template<class DataType>
        const DataType& Min(const DataType& x, const DataType& y)
        {
            return !(y < x) ? x : y;
        }

        /**
         * @brief Get the minimum of three values.
         * If all are equivalent, x is returned.
         * @param x The 1st value.
         * @param y The 2nd value.
         * @param z The 3rd value.
         * @return The lowest value of x, y and z.
         */
        template<class DataType>
        const DataType& Min(const DataType& x, const DataType& y, const DataType& z)
        {
            return Min(x, Min(y, z));
        }

        /**
         * @brief Get the minimum of four values.
         * If all are equivalent, x is returned.
         * @param x The 1st value.
         * @param y The 2nd value.
         * @param z The 3rd value.
         * @param w The 4th value.
         * @return The lowest value of x, y, z and w.
         */
        template<class DataType>
        const DataType& Min(const DataType& x, const DataType& y, const DataType& z, const DataType& w)
        {
            return Min(Min(x, y), Min(z, w));
        }
        
        /**
         * @brief Get the maximum of two values.
         * If both are equivalent, x is returned.
         * @param x The 1st value.
         * @param y The 2nd value.
         * @return The greater value of x and y.
         */
        template<class DataType>
        const DataType& Max(const DataType& x, const DataType& y)
        {
            return (x < y) ? y : x;
        }

        /**
         * @brief Get the maximum of three values.
         * If all are equivalent, x is returned.
         * @param x The 1st value.
         * @param y The 2nd value.
         * @param z The 3rd value.
         * @return The highest value of x, y and z.
         */
        template<class DataType>
        const DataType& Max(const DataType& x, const DataType& y, const DataType& z)
        {
            return Max(x, Max(y, z));
        }

        /**
         * @brief Get the maximum of four values.
         * If all are equivalent, x is returned.
         * @param x The 1st value.
         * @param y The 2nd value.
         * @param z The 3rd value.
         * @param w The 4th value.
         * @return The highest value of x, y, z and w.
         */
        template<class DataType>
        const DataType& Max(const DataType& x, const DataType& y, const DataType& z, const DataType& w)
        {
            return Max(Max(x, y), Max(z, w));
        }
        
        /**
         * @brief Clamp a value.
         * @param val The value to clamp.
         * @param min The minimum value.
         * @param max The maximum value.
         * @return The value clamped in range [min .. max].
         */
        template<class DataType>
        const DataType& Clamp(const DataType& val, const DataType& min, const DataType& max)
        {
            return Min(Max(val, min), max);
        }

        /**
         * @brief Check if a value is not a number (NaN).
         * The NaN values are used to identify undefined or non-representable
         * values for floating-point elements, such as the result of 0/0.
         * @param value The value to check.
         * @return true if the value is not a number (NaN).
         */
        template<class DataType>
        Bool IsNaN(DataType value);

        /**
         * @brief Check if a value is infinite
         *  (either positive infinity or negative infinity).
         * @param value The value to check.
         * @return true if the value is an infinity value.
         */
        template<class DataType>
        Bool IsInfinite(DataType value);

        /**
         * @brief Check if a value is finite.
         * A finite value is any floating-point value that is neither infinite nor NaN.
         * @param value The value to check.
         * @return true if the value is finite.
         */
        template<class DataType>
        Bool IsFinite(DataType value);

        /**
         * @brief Get the the e number raised to the power of a value.
         * @param value The input value.
         * @return The the e number raised to the power of the value.
         */
        template<class DataType>
        DataType Exp(DataType value);

        /**
         * @brief Get the natural logarithm of a value.
         * @param value The input value.
         * @return The natural logarithm of the value.
         */
        template<class DataType>
        DataType Log(DataType value);

        /**
         * @brief Get the base 2 logarithm of a value.
         * @param value The input value.
         * @return The base 2 logarithm of the value.
         */
        template<class DataType>
        DataType Log2(DataType value);

        /**
         * @brief Get the base 10 logarithm of a value.
         * @param value The input value.
         * @return The base 10 logarithm of the value.
         */
        template<class DataType>
        DataType Log10(DataType value);

        /**
         * @brief Get the square root of a value.
         * @param value The input value.
         * @return The square root of the value.
         */
        template<class DataType>
        DataType Sqrt(DataType value);

        /**
         * @brief Get a base raised to the power of an exponent.
         * @param base The base input value.
         * @param exponent The exponent input value.
         * @return The base raised to the power of the exponent.
         */
        template<class DataType>
        DataType Pow(DataType base, DataType exponent);

        /**
         * @brief Get the remainder of a numerator divided by a denominator.
         * @param numerator The numerator input value.
         * @param denominator The denominator input value.
         * @return The remainder of the numerator divided by the denominator.
         */
        template<class DataType>
        DataType Fmod(DataType numerator, DataType denominator);

        /**
         * @brief Get the integer part and the fractional part of a value.
         * @param value The input value.
         * @param intPart The integer part return value.
         * @return The fractional part of the value.
         */
        template<class DataType>
        DataType ModF(DataType value, DataType& intPart);

        /**
         * @brief Get the IEEE remainder of a numerator divided by a denominator.
         * @param numerator The numerator input value.
         * @param denominator The denominator input value.
         * @return The IEEE remainder of the numerator divided by the denominator.
         */
        template<class DataType>
        DataType Remainder(DataType numerator, DataType denominator);

        /**
         * @brief Get the sine of an angle value.
         * @param radAngle The angle value in radiants.
         * @return The sine of the angle value.
         */
        template<class DataType>
        DataType Sin(DataType radAngle);

        /**
         * @brief Get the cosine of an angle value.
         * @param radAngle The angle value in radiants.
         * @return The cosine of the angle value.
         */
        template<class DataType>
        DataType Cos(DataType radAngle);

        /**
         * @brief Get the tangent of an angle value.
         * @param radAngle The angle value in radiants.
         * @return The tangent of the angle value.
         */
        template<class DataType>
        DataType Tan(DataType radAngle);

        /**
         * @brief Get the arc sine of a value.
         * @param value The input value.
         * @return The arc sine of the value in radiants.
         */
        template<class DataType>
        DataType ArcSin(DataType value);

        /**
         * @brief Get the arc cosine of a value.
         * @param value The input value.
         * @return The arc cosine of the value in radiants.
         */
        template<class DataType>
        DataType ArcCos(DataType value);

        /**
         * @brief Get the arc tangent of a value.
         * @param value The input value.
         * @return The arc tangent of the value in radiants.
         */
        template<class DataType>
        DataType ArcTan(DataType value);

        /**
         * @brief Get the arc tangent of y divided by x.
         * The function uses the sign of both arguments to determine the quadrant.
         * @param y The y input value.
         * @param x The x input value.
         * @return The arc tangent of y divided by x in radiants.
         */
        template<class DataType>
        DataType ArcTan2(DataType y, DataType x);

        /**
         * @brief Get the hyperbolic sine of an value.
         * @param value The input value.
         * @return The hyperbolic sine of the value.
         */
        template<class DataType>
        DataType SinHyp(DataType value);

        /**
         * @brief Get the hyperbolic cosine of an value.
         * @param value The input value.
         * @return The hyperbolic cosine of the value.
         */
        template<class DataType>
        DataType CosHyp(DataType value);

        /**
         * @brief Get the hyperbolic tangent of an value.
         * @param value The input value.
         * @return The hyperbolic tangent of the value.
         */
        template<class DataType>
        DataType TanHyp(DataType value);

        /**
         * @brief Get the hyperbolic arc sine of an value.
         * @param value The input value.
         * @return The hyperbolic arc sine of the value.
         */
        template<class DataType>
        DataType ArcSinHyp(DataType value);

        /**
         * @brief Get the hyperbolic arc cosine of an value.
         * @param value The input value.
         * @return The hyperbolic arc cosine of the value.
         */
        template<class DataType>
        DataType ArcCosHyp(DataType value);

        /**
         * @brief Get the hyperbolic arc tangent of an value.
         * @param value The input value.
         * @return The hyperbolic arc tangent of the value.
         */
        template<class DataType>
        DataType ArcTanHyp(DataType value);

        /**
         * @brief Round down to an integral value.
         * @param value The input value.
         * @return The round down integral value.
         */
        template<class DataType>
        DataType Floor(DataType value);

        /**
         * @brief Round up to an integral value.
         * @param value The input value.
         * @return The round up integral value.
         */
        template<class DataType>
        DataType Ceil(DataType value);

        /**
         * @brief Round to an integral value, regardless of the rounding direction.
         * Rounding half-way cases away from zero.
         * @param value The input value.
         * @return The rounded integral value.
         */
        template<class DataType>
        DataType Round(DataType value)
        {
            if (value < 0)
            {
                return Ceil(value - DataType(0.5));
            }
            else
            {
                return Floor(value + DataType(0.5));
            }
        }

        /**
         * @brief Check if two values are equal within an epsilon range.
         * @param a The 1st value.
         * @param b The 2nd value.
         * @param epsilon The epsilon value.
         * @return true if Abs(a - b) is within epsilon range.
         */
        template<class DataType>
        Bool IsEqual(const DataType& a, const DataType& b,
                     const DataType& epsilon = Limits<DataType>::Epsilon())
        {
            return Abs(a - b) < epsilon;
        }

        /**
         * @brief Convert degrees into radiants.
         * @param degrees The degrees to convert.
         * @return The radiants.
         */
        template<class DataType>
        DataType DegToRad(DataType degrees)
        {
            return degrees * DEG_TO_RAD;
        }

        /**
         * @brief Convert radiants into degrees.
         * @param radiants The radiants to convert.
         * @return The degrees.
         */
        template<class DataType>
        DataType RadToDeg(DataType radiants)
        {
            return radiants * RAD_TO_DEG;
        }

        /**
         * @brief Map an angle into range [-PI .. PI).
         * @param angle The angle value in radiants.
         * @return The mapped angle in range [-PI .. PI).
         */
        template<class DataType>
        DataType MapAngle(DataType angle)
        {
            angle = Fmod(angle, DataType(TWO_PI));
            if (angle < 0)
            {
                angle += DataType(TWO_PI);
            }
            if (angle >= PI)
            {
                angle -= TWO_PI;
            }
            return angle;
        }

        /**
         * @brief Calculate the sum of two angles.
         * @param angle1 The first angle value in radiants.
         * @param angle2 The second angle value in radiants.
         * @return The result of (angle1 + angle2) in range [-PI .. PI).
         */
        template<class DataType>
        DataType AddAngle(DataType angle1, DataType angle2)
        {
            return MapAngle(angle1 + angle2);
        }

        /**
         * @brief Calculate the difference between two angles.
         * @param angle1 The first angle value in radiants.
         * @param angle2 The second angle value in radiants.
         * @return The result of (angle1 - angle2) in range [-PI .. PI).
         */
        template<class DataType>
        DataType SubAngle(DataType angle1, DataType angle2)
        {
            return MapAngle(angle1 - angle2);
        }

        /**
         * @brief Convert a given 32bit float value to 16bit ("half float"),
         * represented by a UInt16 integer.
         * @param value The 32bit float value to convert
         * @return The half float value as an UInt16.
         */
        inline UInt16 FloatToHalfFloat(Float value)
        {
            UInt32 p = *reinterpret_cast<UInt32*>(&value);
            UInt32 sign = (p >> 31) & 0x01;
            UInt32 exponent = Clamp(SInt32(((p >> 23) & 0xff) + 15 - 127), 0, 31) & 0x1f;
            UInt32 mantissa = (p & 0x7fffff);

            UInt16 v = (sign << 15) | (exponent << 10) | (mantissa >> 13);
            return v;
        }
        /**
         * @brief Convert a given 8bit unsigned integer value to a 16bit floating
         * point value ("half float"), represented by a UInt16 integer. The input 
         * value is divided by 255.
         * @param value The 8bit unsigned integer value to convert
         * @return The half float value as an UInt16.
         */
        inline UInt16 IntToHalfFloat(UInt8 value)
        {
            static const Float sScale = 1.0f / 255.0f;
            return FloatToHalfFloat(Float(value) * sScale);
        }
        /**
         * @brief Convert a given 16bit half float value stored in a UInt16 to a
         * 32bit float value.
         * @param value The 16bit float value to convert
         * @return The converted 32bit float value
         */
        inline Float HalfFloatToFloat(UInt16 value)
        {
            UInt32 sign = (value >> 15) & 0x01;
            UInt32 exponent = Clamp(SInt32(((value >> 10) & 0x1f) + 127 - 15), 0, 255) & 0xff;
            UInt32 mantissa = (value & 0x3ff);

            UInt32 v = (sign << 31) | (exponent << 23) | (mantissa << 13);
            return *reinterpret_cast<Float*>(&v);
        }
        /**
         * @brief Convert a given 16bit half float value stored in a UInt16 to a
         * 8bit unsigned integer value. The output value is multiplied by 255.
         * @param value The 16bit float value to convert
         * @return The converted 8bit unsigned integer value
         */
        inline UInt8 HalfFloatToInt(UInt16 value)
        {
            static const Float sScale = 255.0f;
            Float v = HalfFloatToFloat(value);
            return UInt8(Clamp(v, 0.0f, 1.0f) * sScale);
        }

        /** @} */

        template<class DataType> class Vector;

        /**
         * @ingroup MurlMathClasses
         * @brief The static vector class.
         * @tparam DataType Available for Float and Double.
         */
        template<class DataType>
        class StaticVector
        {
        public:
            /**
             * @brief Get a constant static vector with zero position.
             * @return The constant static vector with zero position.
             */
            static const Vector<DataType>& ZeroPosition()
            {
                return sZeroPosition;
            }

            /**
             * @brief Get a constant static vector with zero direction.
             * @return The constant static vector with zero direction.
             */
            static const Vector<DataType>& ZeroDirection()
            {
                return sZeroDirection;
            }

        protected:
            static const Vector<DataType> sZeroPosition;
            static const Vector<DataType> sZeroDirection;
        };

        template<class DataType> class Matrix;

        /**
         * @ingroup MurlMathClasses
         * @brief The static matrix class.
         * @tparam DataType Available for Float and Double.
         */
        template<class DataType>
        class StaticMatrix
        {
        public:
            /**
             * @brief Get a constant static matrix with zeros.
             * @return The constant static matrix with zeros.
             */
            static const Matrix<DataType>& Zero()
            {
                return sZero;
            }

            /**
             * @brief Get a constant static matrix with the identity matrix.
             * @return The constant static matrix with the identity matrix.
             */
            static const Matrix<DataType>& Identity()
            {
                return sIdentity;
            }

        protected:
            static const Matrix<DataType> sZero;
            static const Matrix<DataType> sIdentity;
        };

#ifdef MURL_USE_TEMPLATE_VARIABLE_FORWARD_DECLARATIONS
        template<> const Vector<Float> StaticVector<Float>::sZeroPosition;
        template<> const Vector<Float> StaticVector<Float>::sZeroDirection;

        template<> const Vector<Double> StaticVector<Double>::sZeroPosition;
        template<> const Vector<Double> StaticVector<Double>::sZeroDirection;
        
        template<> const Matrix<Float> StaticMatrix<Float>::sZero;
        template<> const Matrix<Float> StaticMatrix<Float>::sIdentity;

        template<> const Matrix<Double> StaticMatrix<Double>::sZero;
        template<> const Matrix<Double> StaticMatrix<Double>::sIdentity;
#endif
    }
}

#endif // __MURL_MATH_H__

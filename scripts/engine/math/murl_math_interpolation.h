// Copyright 2011-2015 Spraylight

#ifndef __MURL_MATH_INTERPOLATION_H__
#define __MURL_MATH_INTERPOLATION_H__

#include "murl_math_easing.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathFunctions
         * @brief The linear interpolation template function.
         * @param startValue The start value to interpolate.
         * @param endValue The end value to interpolate.
         * @param t The parameter to interpolate in range [0 .. 1].
         * @return The interpolation between the inputs startValue and endValue
         *  for a parameter t in the closed unit interval [0 .. 1].
         */
        template<class DataTypeV, class DataTypeT>
        DataTypeV Lerp(const DataTypeV& startValue, const DataTypeV& endValue, DataTypeT t)
        {
            if (t == DataTypeT(1))
            {
                return endValue;
            }
            return startValue + (endValue - startValue) * t;

            // return startValue * (DataTypeT(1) - t) + endValue * t;
            // has floating-point arithmetic error if startValue == endValue
        }

        /**
         * @ingroup MurlMathFunctions
         * @brief The linear interpolation template function for Double.
         * @param startValue The start value to interpolate.
         * @param endValue The end value to interpolate.
         * @param t The parameter to interpolate in range [0 .. 1].
         * @return The interpolation between the inputs startValue and endValue
         *  for a parameter t in the closed unit interval [0 .. 1].
         */
        template<class DataTypeT>
        Double Lerp(Double startValue, Double endValue, DataTypeT t)
        {
            if (t == DataTypeT(1))
            {
                return endValue;
            }
            return startValue + t * (endValue - startValue);
        }

        /**
         * @ingroup MurlMathFunctions
         * @brief Get the cubic bezier parameter t for a given X value.
         * This function interpolates the bezier parameter t (in the range [0..1]
         * for a given target X value and the X values of the four curve control
         * points.
         * @param x0 The X value of the starting point (first control point)
         * @param x1 The X value of the second control point
         * @param x2 The X value of the third control point
         * @param x3 The X value of the end point (fourth control point)
         * @param x The target X value
         * @return The interpolated curve parameter in the range [0..1].
         */
        template<class DataTypeV, class DataTypeT>
        DataTypeT GetCubicBezierParameter(DataTypeV x0, DataTypeV x1, DataTypeV x2, DataTypeV x3, DataTypeV x)
        {
            static const SInt32 sMaxIterations = 16;
            static const DataTypeV sEpsilon = DataTypeV(0.0001);

            if ((x - x0) < sEpsilon)
            {
                return DataTypeT(0.0);
            }
            if ((x3 - x) < sEpsilon)
            {
                return DataTypeT(1.0);
            }

            DataTypeT u = DataTypeT(0.0);
            DataTypeT v = DataTypeT(1.0);

            SInt32 iteration = 0;
            while (iteration < sMaxIterations)
            {
                DataTypeV a = (x0 + x1) * DataTypeV(0.5);
                DataTypeV b = (x1 + x2) * DataTypeV(0.5);
                DataTypeV c = (x2 + x3) * DataTypeV(0.5);
                DataTypeV d = (a + b) * DataTypeV(0.5);
                DataTypeV e = (b + c) * DataTypeV(0.5);
                DataTypeV f = (d + e) * DataTypeV(0.5);

                if (Math::Abs(f - x) < sEpsilon)
                {
                    break;
                }

                if (f < x)
                {
                    x0 = f;
                    x1 = e;
                    x2 = c;
                    u = (u + v) * DataTypeT(0.5);
                }
                else
                {
                    x1 = a;
                    x2 = d;
                    x3 = f;
                    v = (u + v) * DataTypeT(0.5);
                }

                iteration++;
            }

            return Math::Clamp((u + v) * DataTypeT(0.5), DataTypeT(0.0), DataTypeT(1.0));
        }

        /**
         * @ingroup MurlMathFunctions
         * @brief Evaluate a cubic bezier curve for a given parameter t.
         * This function returns the interpolated value of a cubic bezier curve
         * defined via four control points and a given parameter t in
         * the range [0..1].
         * @param x0 The starting point (first control point)
         * @param x1 The second control point
         * @param x2 The third control point
         * @param x3 The end point (fourth control point)
         * @param t The curve parameter in the range [0..1]
         * @return The interpolated X value.
         */
        template<class DataTypeV, class DataTypeT>
        DataTypeV CubicBezier(DataTypeV x0, DataTypeV x1, DataTypeV x2, DataTypeV x3, DataTypeT t)
        {
            DataTypeT u = DataTypeT(1.0) - t;
            DataTypeT t2 = t * t;
            DataTypeT u2 = u * u;
            DataTypeT u3 = u2 * u;
            DataTypeT t3 = t2 * t;

            return (u3) * x0 + (3.0f * u2 * t) * x1 + (3.0f * u * t2) * x2 + (t3) * x3;
        }

        /**
         * @ingroup MurlMathFunctions
         * @brief Evaluate a cubic bezier curve at a given X value.
         * This function returns the interpolated Y value of a cubic bezier curve
         * defined via four (X,Y) control point pairs and a given target X value.
         * If the target X value is outside the range [x0..x3], it is clamped to
         * that range. 
         * @param x0 The X value of the starting point (first control point)
         * @param x1 The X value of the second control point
         * @param x2 The X value of the third control point
         * @param x3 The X value of the end point (fourth control point)
         * @param y0 The Y value of the starting point (first control point)
         * @param y1 The Y value of the second control point
         * @param y2 The Y value of the third control point
         * @param y3 The Y value of the end point (fourth control point)
         * @param x The target X value
         * @return The interpolated Y value
         */
        template<class DataTypeV>
        DataTypeV CubicBezierAt(DataTypeV x0, DataTypeV x1, DataTypeV x2, DataTypeV x3, DataTypeV y0, DataTypeV y1, DataTypeV y2, DataTypeV y3, DataTypeV x)
        {
            DataTypeV t = GetCubicBezierParameter<DataTypeV, DataTypeV>(x0, x1, x2, x3, x);
            return CubicBezier<DataTypeV, DataTypeV>(y0, y1, y2, y3, t);
        }

        /**
         * @ingroup MurlMathFunctions
         * @brief Get the Easing::Interpolate function for a specified interpolation.
         * @param interpolation The interpolation.
         * @return The corresponding Easing::Interpolate function,
         *  or Easing::Linear() if the interpolation is invalid.
         */
        template<class DataType>
        typename Easing<DataType>::Interpolate GetEasingFunction(IEnums::Interpolation interpolation)
        {
            switch (interpolation)
            {
                case IEnums::INTERPOLATION_CONSTANT:
                    return &Easing<DataType>::Constant;
                case IEnums::INTERPOLATION_LINEAR:
                    return &Easing<DataType>::Linear;

                case IEnums::INTERPOLATION_EASE_IN:
                    return &Easing<DataType>::EaseIn;
                case IEnums::INTERPOLATION_EASE_OUT:
                    return &Easing<DataType>::EaseOut;
                case IEnums::INTERPOLATION_EASE_IN_OUT:
                    return &Easing<DataType>::EaseInOut;
                case IEnums::INTERPOLATION_EASE_OUT_IN:
                    return &Easing<DataType>::EaseOutIn;

                case IEnums::INTERPOLATION_SMOOTHSTEP_IN:
                    return &Easing<DataType>::SmoothstepIn;
                case IEnums::INTERPOLATION_SMOOTHSTEP_OUT:
                    return &Easing<DataType>::SmoothstepOut;
                case IEnums::INTERPOLATION_SMOOTHSTEP_IN_OUT:
                    return &Easing<DataType>::SmoothstepInOut;
                case IEnums::INTERPOLATION_SMOOTHSTEP_OUT_IN:
                    return &Easing<DataType>::SmoothstepOutIn;

                case IEnums::INTERPOLATION_SMOOTHERSTEP_IN:
                    return &Easing<DataType>::SmootherstepIn;
                case IEnums::INTERPOLATION_SMOOTHERSTEP_OUT:
                    return &Easing<DataType>::SmootherstepOut;
                case IEnums::INTERPOLATION_SMOOTHERSTEP_IN_OUT:
                    return &Easing<DataType>::SmootherstepInOut;
                case IEnums::INTERPOLATION_SMOOTHERSTEP_OUT_IN:
                    return &Easing<DataType>::SmootherstepOutIn;

                case IEnums::INTERPOLATION_EASE_QUART_IN:
                    return &Easing<DataType>::EaseQuartIn;
                case IEnums::INTERPOLATION_EASE_QUART_OUT:
                    return &Easing<DataType>::EaseQuartOut;
                case IEnums::INTERPOLATION_EASE_QUART_IN_OUT:
                    return &Easing<DataType>::EaseQuartInOut;
                case IEnums::INTERPOLATION_EASE_QUART_OUT_IN:
                    return &Easing<DataType>::EaseQuartOutIn;

                case IEnums::INTERPOLATION_EASE_EXPONENTIAL_IN:
                    return &Easing<DataType>::EaseExponentialIn;
                case IEnums::INTERPOLATION_EASE_EXPONENTIAL_OUT:
                    return &Easing<DataType>::EaseExponentialOut;
                case IEnums::INTERPOLATION_EASE_EXPONENTIAL_IN_OUT:
                    return &Easing<DataType>::EaseExponentialInOut;
                case IEnums::INTERPOLATION_EASE_EXPONENTIAL_OUT_IN:
                    return &Easing<DataType>::EaseExponentialOutIn;

                case IEnums::INTERPOLATION_EASE_CIRCULAR_IN:
                    return &Easing<DataType>::EaseCircularIn;
                case IEnums::INTERPOLATION_EASE_CIRCULAR_OUT:
                    return &Easing<DataType>::EaseCircularOut;
                case IEnums::INTERPOLATION_EASE_CIRCULAR_IN_OUT:
                    return &Easing<DataType>::EaseCircularInOut;
                case IEnums::INTERPOLATION_EASE_CIRCULAR_OUT_IN:
                    return &Easing<DataType>::EaseCircularOutIn;

                case IEnums::INTERPOLATION_EASE_BACK_IN:
                    return &Easing<DataType>::EaseBackIn;
                case IEnums::INTERPOLATION_EASE_BACK_OUT:
                    return &Easing<DataType>::EaseBackOut;
                case IEnums::INTERPOLATION_EASE_BACK_IN_OUT:
                    return &Easing<DataType>::EaseBackInOut;
                case IEnums::INTERPOLATION_EASE_BACK_OUT_IN:
                    return &Easing<DataType>::EaseBackOutIn;

                case IEnums::INTERPOLATION_EASE_ELASTIC_IN:
                    return &Easing<DataType>::EaseElasticIn;
                case IEnums::INTERPOLATION_EASE_ELASTIC_OUT:
                    return &Easing<DataType>::EaseElasticOut;
                case IEnums::INTERPOLATION_EASE_ELASTIC_IN_OUT:
                    return &Easing<DataType>::EaseElasticInOut;
                case IEnums::INTERPOLATION_EASE_ELASTIC_OUT_IN:
                    return &Easing<DataType>::EaseElasticOutIn;

                case IEnums::INTERPOLATION_EASE_BOUNCE_IN:
                    return &Easing<DataType>::EaseBounceIn;
                case IEnums::INTERPOLATION_EASE_BOUNCE_OUT:
                    return &Easing<DataType>::EaseBounceOut;
                case IEnums::INTERPOLATION_EASE_BOUNCE_IN_OUT:
                    return &Easing<DataType>::EaseBounceInOut;
                case IEnums::INTERPOLATION_EASE_BOUNCE_OUT_IN:
                    return &Easing<DataType>::EaseBounceOutIn;

                case IEnums::INTERPOLATION_CUBIC_BEZIER:
                    // Cubic Bezier function defaults to linear without parameters
                    return &Easing<DataType>::Linear;

                default:
                    break;
            }
            return &Easing<DataType>::Linear;
        }

        /**
         * @ingroup MurlMathFunctions
         * @brief The interpolation template function calculates
         *  the IEnums::Interpolation curve (easing function).
         * @param interpolation The interpolation.
         * @param x The value to interpolate in range [0 .. 1].
         * @return The easing function result.
         */
        template<class DataType>
        DataType Interpolation(IEnums::Interpolation interpolation, DataType x)
        {
            return (*GetEasingFunction<DataType>(interpolation))(x);
        }
    }
}

#endif // __MURL_MATH_INTERPOLATION_H__

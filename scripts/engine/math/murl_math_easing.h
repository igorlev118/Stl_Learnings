// Copyright 2015 Spraylight

#ifndef __MURL_MATH_EASING_H__
#define __MURL_MATH_EASING_H__

#include "murl_math.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief The easing class implements the functions of
         *  the predefined IEnums::Interpolation curves.
         * Smoothstep functions description can be found at http://wikipedia.org/wiki/Smoothstep
         * \n Easing functions description can be found at http://easings.net
         */
        template<class DataType>
        class Easing
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /** Definition of the easing function type. */
            typedef DataType (*Interpolate)(DataType x);

            /**
             * @brief Constant interpolation.
             *  Function: f(x)=0
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType Constant(DataType x)
            {
                return 0;
            }

            /**
             * @brief Linear interpolation.
             *  Function: f(x)=x
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType Linear(DataType x)
            {
                return x;
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Smoothstep
#endif
            /**
             * @brief Smoothstep "in-out" interpolation.
             *  Function: f(x)=(x^2)*(3-2*x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmoothstepInOut(DataType x)
            {
                return x * x * (3 - (2 * x));
            }

            /**
             * @brief Smoothstep "in" interpolation.
             *  Function: f(x)=SmoothstepInOut(x/2)*2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmoothstepIn(DataType x)
            {
                return SmoothstepInOut(x / 2) * 2;
            }

            /**
             * @brief Smoothstep "out" interpolation.
             *  Function: f(x)=SmoothstepInOut((x+1)/2)*2-1
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmoothstepOut(DataType x)
            {
                return SmoothstepInOut((x + 1) / 2) * 2 - 1;
            }

            /**
             * @brief Smoothstep "out-in" interpolation.
             *  Function: f(x)=(x < 0.5) ? SmoothstepInOut(x+0.5)-0.5 : SmoothstepInOut(x-0.5)+0.5
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmoothstepOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return SmoothstepInOut(x + DataType(0.5)) - DataType(0.5);
                }
                else
                {
                    return SmoothstepInOut(x - DataType(0.5)) + DataType(0.5);
                }
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Smootherstep
#endif
            /**
             * @brief Smootherstep "in-out" interpolation.
             *  Function: f(x)=(x^3)*(x*(6*x-15)+10)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmootherstepInOut(DataType x)
            {
                return x = x * x * x * (x * (6 * x - 15) + 10);
            }

            /**
             * @brief Smootherstep "in" interpolation.
             *  Function: f(x)=SmootherstepInOut(x/2)*2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmootherstepIn(DataType x)
            {
                return SmootherstepInOut(x / 2) * 2;
            }

            /**
             * @brief Smootherstep "out" interpolation.
             *  Function: f(x)=SmootherstepInOut((x+1)/2)*2-1
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmootherstepOut(DataType x)
            {
                return SmootherstepInOut((x + 1) / 2) * 2 - 1;
            }

            /**
             * @brief Smootherstep "out-in" interpolation.
             *  Function: f(x)=(x < 0.5) ? SmootherstepInOut(x+0.5)-0.5 : SmootherstepInOut(x-0.5)+0.5
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType SmootherstepOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return SmootherstepInOut(x + DataType(0.5)) - DataType(0.5);
                }
                else
                {
                    return SmootherstepInOut(x - DataType(0.5)) + DataType(0.5);
                }
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Ease (Cubic)
#endif
            /**
             * @brief Ease (cubic) "in" interpolation.
             *  Function: f(x)=x^3
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseIn(DataType x)
            {
                return x * x * x;
            }

            /**
             * @brief Ease (cubic) "out" interpolation.
             *  Function: f(x)=1-EaseIn(1-x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseOut(DataType x)
            {
                return DataType(1) - EaseIn(DataType(1) - x);
            }

            /**
             * @brief Ease (cubic) "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseIn(2*x)/2 : 1-EaseIn(2-2*x)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseInOut(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseIn(x * 2) / 2;
                }
                else
                {
                    return DataType(1) - EaseIn(DataType(2) - x * 2) / 2;
                }
            }

            /**
             * @brief Ease (cubic) "out-in" interpolation.
             *  Function: f(x)=4*EaseIn(x-0.5)+0.5
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseOutIn(DataType x)
            {
                return DataType(4) * EaseIn(x - DataType(0.5)) + DataType(0.5);
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Ease Quart
#endif
            /**
             * @brief Ease Quart "in" interpolation.
             *  Function: f(x)=x^4
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseQuartIn(DataType x)
            {
                return x * x * x * x;
            }

            /**
             * @brief Ease Quart "out" interpolation.
             *  Function: f(x)=1-EaseQuartIn(1-x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseQuartOut(DataType x)
            {
                return DataType(1) - EaseQuartIn(DataType(1) - x);
            }

            /**
             * @brief Ease Quart "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseQuartIn(2*x)/2 : 1-EaseQuartIn(2-2*x)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseQuartInOut(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseQuartIn(x * 2) / 2;
                }
                else
                {
                    return DataType(1) - EaseQuartIn(DataType(2) - x * 2) / 2;
                }
            }

            /**
             * @brief Ease Quart "out-in" interpolation.
             *  Function: f(x)=(x < 0.5) ? 0.5-EaseQuartIn(1-2*x)/2 : 0.5+EaseQuartIn(2*x-1)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseQuartOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return DataType(0.5) - EaseQuartIn(DataType(1) - x * 2) / 2;
                }
                else
                {
                    return DataType(0.5) + EaseQuartIn(x * 2 - 1) / 2;
                }
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Ease Exponential
#endif
            /**
             * @brief Ease Exponential "in" interpolation.
             *  Function: f(x)=(2^8x)*x/256
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseExponentialIn(DataType x)
            {
                return Math::Pow(DataType(2), x * 8) * x / 256;
            }

            /**
             * @brief Ease Exponential "out" interpolation.
             *  Function: f(x)=1-EaseExponentialIn(1-x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseExponentialOut(DataType x)
            {
                return DataType(1) - EaseExponentialIn(DataType(1) - x);
            }

            /**
             * @brief Ease Exponential "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseExponentialIn(2*x)/2 : 1-EaseExponentialIn(2-2*x)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseExponentialInOut(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseExponentialIn(x * 2) / 2;
                }
                else
                {
                    return DataType(1) - EaseExponentialIn(DataType(2) - x * 2) / 2;
                }
            }

            /**
             * @brief Ease Exponential "out-in" interpolation.
             *  Function: f(x)=(x < 0.5) ? 0.5-EaseExponentialIn(1-2*x)/2 : 0.5+EaseExponentialIn(2*x-1)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseExponentialOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return DataType(0.5) - EaseExponentialIn(DataType(1) - x * 2) / 2;
                }
                else
                {
                    return DataType(0.5) + EaseExponentialIn(x * 2 - 1) / 2;
                }
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Ease Circular
#endif
            /**
             * @brief Ease Circular "in" interpolation.
             *  Function: f(x)=1-sqrt(1-x^2)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseCircularIn(DataType x)
            {
                return DataType(1) - Math::Sqrt(DataType(1) - x * x);
            }

            /**
             * @brief Ease Circular "out" interpolation.
             *  Function: f(x)=sqrt((2-x)*x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseCircularOut(DataType x)
            {
                return Math::Sqrt((DataType(2) - x) * x);
            }

            /**
             * @brief Ease Circular helper interpolation.
             *  Function: f(x)=sqrt(x-x^2)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseCircularHelper(DataType x)
            {
                return Math::Sqrt(x - x * x);
            }

            /**
             * @brief Ease Circular "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? 0.5-EaseCircularHelper(x+0.5) : 0.5+EaseCircularHelper(x-0.5)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseCircularInOut(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return DataType(0.5) - EaseCircularHelper(x + DataType(0.5));
                }
                else
                {
                    return DataType(0.5) + EaseCircularHelper(x - DataType(0.5));
                }
            }

            /**
             * @brief Ease Circular "out-in" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseCircularHelper(x) : 1-EaseCircularHelper(x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseCircularOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseCircularHelper(x);
                }
                else
                {
                    return DataType(1) - EaseCircularHelper(x);
                }
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Ease Back
#endif
            /**
             * @brief Ease Back "in" interpolation.
             *  Function: f(x)=(x^3)-x*sin(x*PI)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBackIn(DataType x)
            {
                return x * x * x - x * Math::Sin(x * Math::PI);
            }

            /**
             * @brief Ease Back "out" interpolation.
             *  Function: f(x)=1-EaseBackIn(1-x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBackOut(DataType x)
            {
                return DataType(1) - EaseBackIn(DataType(1) - x);
            }

            /**
             * @brief Ease Back "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseBackIn(2*x)/2 : 1-EaseBackIn(2-2*x)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBackInOut(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseBackIn(x * 2) / 2;
                }
                else
                {
                    return DataType(1) - EaseBackIn(DataType(2) - x * 2) / 2;
                }
            }

            /**
             * @brief Ease Back "out-in" interpolation.
             *  Function: f(x)=(x < 0.5) ? 0.5-EaseBackIn(1-2*x)/2 : 0.5+EaseBackIn(2*x-1)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBackOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return DataType(0.5) - EaseBackIn(DataType(1) - x * 2) / 2;
                }
                else
                {
                    return DataType(0.5) + EaseBackIn(x * 2 - 1) / 2;
                }
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Ease Elastic
#endif
            /**
             * @brief Ease Elastic "in" interpolation.
             *  Function: f(x)=sin(13*PI/2*x)*2^(10*(x-1))
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseElasticIn(DataType x)
            {
                return Math::Sin(DataType(13) * Math::HALF_PI * x) * Math::Pow(DataType(2), DataType(10) * (x - 1));
            }

            /**
             * @brief Ease Elastic "out" interpolation.
             *  Function: f(x)=1-EaseElasticIn(1-x)
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseElasticOut(DataType x)
            {
                return DataType(1) - EaseElasticIn(DataType(1) - x);
            }

            /**
             * @brief Ease Elastic "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseElasticIn(2*x)/2 : 1-EaseElasticIn(2-2*x)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseElasticInOut(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseElasticIn(x * 2) / 2;
                }
                else
                {
                    return DataType(1) - EaseElasticIn(DataType(2) - x * 2) / 2;
                }
            }

            /**
             * @brief Ease Elastic "out-in" interpolation.
             *  Function: f(x)=(x < 0.5) ? 0.5-EaseElasticIn(1-2*x)/2 : 0.5+EaseElasticIn(2*x-1)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseElasticOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return DataType(0.5) - EaseElasticIn(DataType(1) - x * 2) / 2;
                }
                else
                {
                    return DataType(0.5) + EaseElasticIn(x * 2 - 1) / 2;
                }
            }

#ifdef MURL_COMPILER_XCODE
#pragma mark Ease Bounce
#endif
            /**
             * @brief Ease Bounce "out" interpolation.
             *  Function: f(x)= ... = a halve and three shrinking bounces
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBounceOut(DataType x)
            {
                if (x < DataType(4 / DataType(11)))
                {
                    return DataType(121) * x * x / DataType(16);
                }
                else if (x < DataType(8 / DataType(11)))
                {
                    return DataType(363 / DataType(40)) * x * x - DataType(99 / DataType(10)) * x + DataType(17 / DataType(5));
                }
                else if (x < DataType(9 / DataType(10)))
                {
                    return DataType(4356 / DataType(361)) * x * x - DataType(35442 / DataType(1805)) * x + DataType(16061 / DataType(1805));
                }
                else
                {
                    return DataType(54 / DataType(5)) * x * x - DataType(513 / DataType(25)) * x + DataType(268 / DataType(25));
                }
            }

            /**
             * @brief Ease Bounce "in" interpolation.
             *  Function: f(x)=1-EaseBounceOut(1-x) = three and a halve growing bounces
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBounceIn(DataType x)
            {
                return DataType(1) - EaseBounceOut(DataType(1) - x);
            }

            /**
             * @brief Ease Bounce "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseBounceIn(2*x)/2 : 0.5+EaseBounceOut(2*x-1)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBounceInOut(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseBounceIn(x * 2) / 2;
                }
                else
                {
                    return DataType(0.5) + EaseBounceOut(x * 2 - 1) / 2;
                }
            }

            /**
             * @brief Ease Bounce "in-out" interpolation.
             *  Function: f(x)=(x < 0.5) ? EaseBounceOut(2*x)/2 : 0.5+EaseBounceIn(2*x-1)/2
             * @param x The value to interpolate in range [0 .. 1].
             * @return The result for f(x).
             */
            static DataType EaseBounceOutIn(DataType x)
            {
                if (x < DataType(0.5))
                {
                    return EaseBounceOut(x * 2) / 2;

                }
                else
                {
                    return DataType(0.5) + EaseBounceIn(x * 2 - 1) / 2;
                }
            }
        };
    }
}

#endif // __MURL_MATH_EASING_H__

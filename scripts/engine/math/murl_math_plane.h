// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_PLANE_H__
#define __MURL_MATH_PLANE_H__

#include "murl_math_vector.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief A plane class describing the equation for a plane
         *  a*x + b*y + c*z + d = 0.
         */
        template<class DataType>
        class Plane
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             */
            Plane()
            : mA()
            , mB()
            , mC()
            , mD()
            {
            }

            /**
             * @brief The copy constructor using a plane of different type.
             * @param p The plane to copy.
             */
            template<class DataType2>
            Plane(const Plane<DataType2>& p)
            : mA(p.mA)
            , mB(p.mB)
            , mC(p.mC)
            , mD(p.mD)
            {
            }

            /**
             * @brief Set all variables of the equation for a plane
             *  a*x + b*y + c*z + d = 0.
             * @param a The a variable.
             * @param b The b variable.
             * @param c The c variable.
             * @param d The d variable.
             */
            void Set(DataType a, DataType b, DataType c, DataType d)
            {
                mA = a;
                mB = b;
                mC = c;
                mD = d;
            }

            /**
             * @brief Normalize the plane.
             */
            void NormalizeSelf()
            {
                DataType f = DataType(1) / Sqrt(mA * mA + mB * mB + mC * mC);
                mA *= f;
                mB *= f;
                mC *= f;
                mD *= f;
            }

            /**
             * @brief Get the distance from a point to the plane.
             * @param point The point to measure the distance from.
             * @return The distance between the point and the plane.
             */
            DataType GetPointDistance(const Vector<DataType>& point) const
            {
                return point.x * mA + point.y * mB + point.z * mC + mD;
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return Util::PrintToString("%f, %f, %f, %f",
                                           Double(mA), Double(mB), Double(mC), Double(mD));
            }

            /** @brief The a variable. */
            DataType mA;
            /** @brief The b variable. */
            DataType mB;
            /** @brief The c variable. */
            DataType mC;
            /** @brief The d variable. */
            DataType mD;
        };
    }
}

#endif // __MURL_MATH_PLANE_H__

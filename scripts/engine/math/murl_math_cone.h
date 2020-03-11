// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_CONE_H__
#define __MURL_MATH_CONE_H__

#include "murl_math_vector.h"
#include "murl_math_plane.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Frustum;

        template<class DataType>
        class Sphere;

        /**
         * @ingroup MurlMathClasses
         * @brief A cone class describing a cone by its angle and length.
         */
        template<class DataType>
        class Cone
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             */
            Cone()
            : mLength(1)
            , mAngle(0)
            , mSin(0)
            , mCos(1)
            , mTan(0)
            , mShearX(0)
            , mShearY(0)
            {
            }

            /**
             * @brief Constructor taking cone length and angle.
             * @param length The length of the cone.
             * @param angle The angle of the cone.
             */
            Cone(DataType length, DataType angle)
            : mLength(length)
            , mAngle(angle)
            , mShearX(0)
            , mShearY(0)
            {
                mSin = Sin(mAngle);
                mCos = Cos(mAngle);
                mTan = Tan(mAngle);
            }

            /**
             * @brief Constructor taking a frustum.
             * @param frustum The frustum.
             */
            Cone(const Frustum<DataType>& frustum)
            {
                Set(frustum);
            }

            /**
             * @brief The copy constructor using a cone of different type.
             * @param c The cone to copy.
             */
            template<class DataType2>
            Cone(const Cone<DataType2>& c)
            : mLength(c.GetLength())
            , mAngle(c.GetAngle())
            , mShearX(c.mShearX)
            , mShearY(c.mShearY)
            {
                mSin = Sin(mAngle);
                mCos = Cos(mAngle);
                mTan = Tan(mAngle);
            }

            /**
             * @brief Get the length.
             * @return The length.
             */
            DataType GetLength() const
            {
                return mLength;
            }

            /**
             * @brief Get the angle.
             * @return The angle.
             */
            DataType GetAngle() const
            {
                return mAngle;
            }

            /**
             * @brief Set the cone by a frustum.
             * @param frustum The frustum.
             */
            void Set(const Frustum<DataType>& frustum)
            {
                Plane<DataType> farPlane = frustum.GetClipPlane(Frustum<DataType>::CLIP_PLANE_FAR);
                DataType z = -(farPlane.mD / farPlane.mC);

                Plane<DataType> leftPlane = frustum.GetClipPlane(Frustum<DataType>::CLIP_PLANE_LEFT);
                Plane<DataType> rightPlane = frustum.GetClipPlane(Frustum<DataType>::CLIP_PLANE_RIGHT);
                Plane<DataType> topPlane = frustum.GetClipPlane(Frustum<DataType>::CLIP_PLANE_TOP);
                Plane<DataType> bottomPlane = frustum.GetClipPlane(Frustum<DataType>::CLIP_PLANE_BOTTOM);

                DataType x1 = leftPlane.mC / leftPlane.mA;
                DataType x2 = rightPlane.mC / rightPlane.mA;
                DataType y1 = bottomPlane.mC / bottomPlane.mB;
                DataType y2 = topPlane.mC / topPlane.mB;

                DataType cx = (x1 + x2) * DataType(0.5);
                DataType cy = (y1 + y2) * DataType(0.5);

                DataType x;
                DataType y;

                if (leftPlane.mA != DataType(0))
                {
                    x = -((leftPlane.mC * z + leftPlane.mD) / leftPlane.mA);
                    y = -((topPlane.mA * x + topPlane.mC * z + topPlane.mD) / topPlane.mB);
                }
                else
                {
                    x = -((topPlane.mC * z + topPlane.mD) / topPlane.mA);
                    y = -((leftPlane.mA * x + leftPlane.mC * z + leftPlane.mD) / leftPlane.mB);
                }

                x += cx * z;
                y += cy * z;

                DataType xy = Sqrt(x * x + y * y);
                DataType angleTangent = xy / Abs(z);

                mLength = Abs(z);
                mAngle = ArcTan(angleTangent);

                mSin = Sin(mAngle);
                mCos = Cos(mAngle);
                mTan = angleTangent;

                mShearX = cx;
                mShearY = cy;
            }

            /**
             * @brief Check if the cone is intersecting a sphere.
             * @param sphere The sphere to check.
             * @return true if the cone is intersecting the sphere.
             */
            Bool IsIntersecting(const Sphere<DataType>& sphere) const
            {
                // Simplification: Zero origin, axis in negative Z direction
                DataType sphereRadius = sphere.GetRadius();
                const Vector<DataType>& sphereCenter = sphere.GetCenter();

                DataType sz = sphereCenter.z;
                DataType sx = sphereCenter.x + mShearX * sz;
                DataType sy = sphereCenter.y + mShearY * sz;

                if (sz <= DataType(0))
                {
                    // Case 1: The sphere center is between origin and infinity,
                    // we only need to check against the cone's surface
                    DataType d = sx * sx + sy * sy;
                    DataType a = -sz * mTan;
                    DataType b = sphereRadius / mCos;
                    DataType c = a + b;
                    return (d < (c * c));
                }

                DataType offsetZ = sz - sphereRadius;
                if (offsetZ > DataType(0))
                {
                    // Case 2: The sphere is completely behind the origin, so
                    // no intersection is possible
                    return false;
                }

                DataType w = sphereRadius * mSin;
                offsetZ = sz - w;
                if (offsetZ <= DataType(0))
                {
                    // Case 3: The sphere center's normal projection is still on the
                    // cone's body, however here the cone diameter becomes negative
                    DataType d = sx * sx + sy * sy;
                    DataType a = -sz * mTan;
                    DataType b = sphereRadius / mCos;
                    DataType c = a + b;
                    return (d < (c * c));
                }

                // Case 4: The sphere "rolls around" the tip of the cone, we only need
                // to check the sphere against the origin (which is zero)
                return (sphereCenter.GetSquaredLength() < (sphereRadius * sphereRadius));
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return Util::PrintToString("%f", Double(mAngle));
            }

        protected:
            /** @brief The length of the cone. */
            DataType mLength;
            /** @brief The angle of the cone. */
            DataType mAngle;
            /** @brief The sine of the angle. */
            DataType mSin;
            /** @brief The cosine of the angle. */
            DataType mCos;
            /** @brief The tangent of the angle. */
            DataType mTan;
            /** @brief The X shear value. */
            DataType mShearX;
            /** @brief The Y shear value. */
            DataType mShearY;
        };
    }
}

#endif // __MURL_MATH_CONE_H__

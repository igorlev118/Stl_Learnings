// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_CYLINDER_H__
#define __MURL_MATH_CYLINDER_H__

#include "murl_math_vector.h"
#include "murl_math_plane.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Box;

        template<class DataType>
        class Sphere;

        /**
         * @ingroup MurlMathClasses
         * @brief A cylinder class describing a cylinder by its radius and length.
         */
        template<class DataType>
        class Cylinder
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             */
            Cylinder()
            : mLength(1)
            , mRadius(1)
            , mOffsetX(0)
            , mOffsetY(0)
            , mShearX(0)
            , mShearY(0)
            {
            }

            /**
             * @brief Constructor taking cylinder length and radius.
             * @param length The length of the cylinder.
             * @param radius The radius of the cylinder.
             */
            Cylinder(DataType length, DataType radius)
            : mLength(length)
            , mRadius(radius)
            , mOffsetX(0)
            , mOffsetY(0)
            , mShearX(0)
            , mShearY(0)
            {
            }

            /**
             * @brief Constructor taking a box.
             * @param box The box.
             */
            Cylinder(const Box<DataType>& box)
            {
                Set(box);
            }

            /**
             * @brief The copy constructor using a cylinder of different type.
             * @param c The cylinder to copy.
             */
            template<class DataType2>
            Cylinder(const Cylinder<DataType2>& c)
            : mLength(c.GetLength())
            , mRadius(c.GetRadius())
            , mOffsetX(c.mOffsetX)
            , mOffsetY(c.mOffsetY)
            , mShearX(c.mShearX)
            , mShearY(c.mShearY)
            {
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
             * @brief Get the radius.
             * @return The radius.
             */
            DataType GetRadius() const
            {
                return mRadius;
            }

            /**
             * @brief Set the cylinder by a box.
             * @param box The box.
             */
            void Set(const Box<DataType>& box)
            {
                Set(box, 0.0f, 0.0f);
            }

            /**
             * @brief Set the cylinder from a sheared box.
             * @param box The box.
             * @param shearX The shear value in X direction.
             * @param shearY The shear value in Y direction.
             */
            void Set(const Box<DataType>& box, DataType shearX, DataType shearY)
            {
                const Vector<DataType>& min = box.GetMinimum();
                const Vector<DataType>& max = box.GetMaximum();

                mOffsetX = (min.x + max.x) * 0.5f;
                mOffsetY = (min.y + max.y) * 0.5f;

                Real sx = max.x - min.x;
                Real sy = max.y - min.y;
                mRadius = Sqrt(sx * sx + sy * sy);

                mLength = -min.z;

                mShearX = shearX;
                mShearY = shearY;
            }
            
            /**
             * @brief Check if the cylinder is intersecting a sphere.
             * @param sphere The sphere to check.
             * @return true if the cylinder is intersecting the sphere.
             */
            Bool IsIntersecting(const Sphere<DataType>& sphere) const
            {
                // Simplification: Zero origin, axis in negative Z direction
                DataType sphereRadius = sphere.GetRadius();
                const Vector<DataType>& sphereCenter = sphere.GetCenter();

                DataType sz = sphereCenter.z;
                DataType sx = sphereCenter.x + mShearX * sz - mOffsetX;
                DataType sy = sphereCenter.y + mShearY * sz - mOffsetY;

                DataType offsetZNear = sz - sphereRadius;
                DataType offsetZFar = sz + sphereRadius;

                if (offsetZNear > DataType(0))
                {
                    // The sphere is completely behind the origin, so
                    // no intersection is possible
                    return false;
                }
                if (offsetZFar < -mLength)
                {
                    // The sphere is completely beyond the length, so
                    // no intersection is possible
                    return false;
                }

                // The sphere center is between origin and length,
                // we only need to check against the cylinder's surface
                DataType d = sx * sx + sy * sy;
                DataType a = mRadius;
                DataType b = sphereRadius;
                DataType c = a + b;
                return (d < (c * c));
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return Util::PrintToString("%f", Double(mRadius));
            }

        protected:
            /** @brief The length of the cylinder. */
            DataType mLength;
            /** @brief The radius of the cylinder. */
            DataType mRadius;
            /** @brief The X offset value. */
            DataType mOffsetX;
            /** @brief The Y offset value. */
            DataType mOffsetY;
            /** @brief The X shear value. */
            DataType mShearX;
            /** @brief The Y shear value. */
            DataType mShearY;
        };
    }
}

#endif // __MURL_MATH_CYLINDER_H__

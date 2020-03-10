// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_RAY_H__
#define __MURL_MATH_RAY_H__

#include "murl_math_box.h"
#include "murl_math_sphere.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;
        
        /**
         * @ingroup MurlMathClasses
         * @brief A ray class.
         */
        template<class DataType>
        class Ray
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             * This creates a ray starting at (0/0/0) and pointing towards the positive Z axis.
             */
            Ray()
            : mOrigin(Vector<DataType>::ZERO_POSITION)
            , mDirection(DataType(0.0), DataType(0.0), DataType(1.0), DataType(0.0))
            {
            }

            /**
             * @brief Constructor taking origin and direction vectors.
             * @param origin The ray origin.
             * @param direction The ray direction.
             */
            Ray(const Vector<DataType>& origin, const Vector<DataType>& direction)
            : mOrigin(origin)
            , mDirection(direction)
            {
            }

            /**
             * @brief The copy constructor using a ray of different type.
             * @param other The ray to copy.
             */
            template<class DataType2>
            Ray(const Ray<DataType2>& other)
            : mOrigin(other.GetOrigin())
            , mDirection(other.GetDirection())
            {
            }

            /**
             * @brief Copy the content of a source ray to the ray instance.
             * @param other The ray to copy from.
             */
            void Set(const Ray& other)
            {
                mOrigin.Set(other.mOrigin);
                mDirection.Set(other.mDirection);
            }
            
            /**
             * @brief Set a ray from given origin and direction vectors.
             * @param origin The ray origin.
             * @param direction The ray direction.
             */
            void Set(const Vector<DataType>& origin, const Vector<DataType>& direction)
            {
                mOrigin.Set(origin);
                mDirection.Set(direction);
            }

            /**
             * @brief Set the ray origin.
             * @param origin The ray origin.
             */
            void SetOrigin(const Vector<DataType>& origin)
            {
                mOrigin.Set(origin);
            }
            
            /**
             * @brief Get the ray origin.
             * @return The ray origin.
             */
            const Vector<DataType>& GetOrigin() const
            {
                return mOrigin;
            }
            
            /**
             * @brief Set the ray direction.
             * @param direction The ray direction.
             */
            void SetDirection(const Vector<DataType>& direction)
            {
                mDirection.Set(direction);
            }

            /**
             * @brief Get the ray direction.
             * @return The ray direction.
             */
            const Vector<DataType>& GetDirection() const
            {
                return mDirection;
            }

            /**
             * @brief Check if the ray is intersecting a given sphere.
             * @param sphere The sphere to check.
             * @param lambda An optional pointer to a variable receiving the lambda
             *   value of the intersection, i.e. the distance between the intersection
             *   point and the ray origin along the ray direction.
             * @return true if the ray is intersecting the sphere.
             */
            Bool IsIntersecting(const Sphere<DataType>& sphere, DataType* lambda = 0) const
            {
                return false;
            }

            /**
             * @brief Check if the ray is intersecting a given box.
             * @param box The box to check.
             * @param lambda An optional pointer to a variable receiving the lambda
             *   value of the intersection, i.e. the distance between the intersection
             *   point and the ray origin along the ray direction.
             * @return true if the ray is intersecting the box.
             */
            Bool IsIntersecting(const Box<DataType>& box, DataType* lambda = 0) const
            {
                return false;
            }

        protected:
            /** @brief The origin of the ray. */
            Vector<DataType> mOrigin;
            /** @brief The direction of the ray. */
            Vector<DataType> mDirection;
        };
    }
}

#endif // __MURL_MATH_RAY_H__

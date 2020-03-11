// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_BOX_H__
#define __MURL_MATH_BOX_H__

#include "murl_math_vector.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Sphere;

        /**
         * @ingroup MurlMathClasses
         * @brief A box class describing the minimum and maximum coordinate of a 3d-box.
         */
        template<class DataType>
        class Box
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             */
            Box()
            : mMin(Vector<DataType>::ZERO_POSITION)
            , mMax(Vector<DataType>::ZERO_POSITION)
            , mFlags(FLAG_EMPTY)
            {
            }

            /**
             * @brief Constructor uniting two given boxes.
             * @param b1 The first box.
             * @param b2 The second box.
             */
            Box(const Box& b1, const Box& b2)
            : mMin(b1.mMin)
            , mMax(b1.mMax)
            , mFlags(b1.mFlags)
            {
                Unite(b2);
            }

            /**
             * @brief Constructor taking a single coordinate.
             * @param point The coordinate for minimum and maximum.
             */
            Box(const Vector<DataType>& point)
            : mMin(point.x, point.y, point.z, DataType(1))
            , mMax(point.x, point.y, point.z, DataType(1))
            , mFlags(0)
            {
            }

            /**
             * @brief Constructor taking minimum and maximum coordinates.
             * @param min The minimum coordinate.
             * @param max The maximum coordinate.
             */
            Box(const Vector<DataType>& min, const Vector<DataType>& max)
            : mMin(min.x, min.y, min.z, DataType(1))
            , mMax(max.x, max.y, max.z, DataType(1))
            , mFlags(0)
            {
            }

            /**
             * @brief Constructor taking the three points of a triangle.
             * @param a The first triangle coordinate.
             * @param b The second triangle coordinate.
             * @param c The third triangle coordinate.
             */
            Box(const Vector<DataType>& a, const Vector<DataType>& b, const Vector<DataType>& c)
            {
                Set(a, b, c);
            }

            /**
             * @brief Constructor taking a sphere.
             * The box is only approximated and slightly larger than it needs to be.
             * @param sphere The sphere to enclose.
             */
            Box(const Sphere<DataType>& sphere)
            {
                Set(sphere);
            }

            /**
             * @brief The copy constructor using a box of different type.
             * @param b The box to copy.
             */
            template<class DataType2>
            Box(const Box<DataType2>& b)
            : mMin(b.GetMinimum())
            , mMax(b.GetMaximum())
            , mFlags(b.GetFlags())
            {
            }

            /**
             * @brief Clear the box
             */
            void Clear()
            {
                mMin.Set(Vector<DataType>::ZERO_POSITION);
                mMax.Set(Vector<DataType>::ZERO_POSITION);
                mFlags = FLAG_EMPTY;
            }

            /**
             * @brief Set the coordinates from a box.
             * @param other The box to copy from.
             */
            void Set(const Box& other)
            {
                mMin.Set(other.mMin);
                mMax.Set(other.mMax);
                mFlags = other.mFlags;
            }

            /**
             * @brief Set the coordinates by uniting two given boxes.
             * @param b1 The first box.
             * @param b2 The second box.
             */
            void Set(const Box& b1, const Box& b2)
            {
                mMin.Set(b1.mMin);
                mMax.Set(b1.mMax);
                mFlags = b1.mFlags;
                Unite(b2);
            }

            /**
             * @brief Set the coordinates to a single coordinate.
             * @param point The coordinate for minimum and maximum.
             */
            void Set(const Vector<DataType>& point)
            {
                mMin.Set(point.x, point.y, point.z, DataType(1));
                mMax.Set(point.x, point.y, point.z, DataType(1));
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the minimum and maximum coordinates.
             * @param min The minimum coordinate.
             * @param max The maximum coordinate.
             */
            void Set(const Vector<DataType>& min, const Vector<DataType>& max)
            {
                mMin.Set(min.x, min.y, min.z, DataType(1));
                mMax.Set(max.x, max.y, max.z, DataType(1));
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the coordinates by the three points of a triangle.
             * @param a The first triangle coordinate.
             * @param b The second triangle coordinate.
             * @param c The third triangle coordinate.
             */
            void Set(const Vector<DataType>& a, const Vector<DataType>& b, const Vector<DataType>& c)
            {
                mMin.Set(a.Min(b.Min(c)));
                mMax.Set(a.Max(b.Max(c)));
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the coordinates by a sphere.
             * The box is only approximated and slightly larger than it needs to be.
             * @param sphere The sphere to enclose.
             */
            void Set(const Sphere<DataType>& sphere)
            {
                if (sphere.IsEmpty())
                {
                    Clear();
                    return;
                }

                const Vector<DataType>& center = sphere.GetCenter();
                DataType radius = sphere.GetRadius();
                Vector<DataType> offset(radius, radius, radius, 0);

                mMin.Set(center - offset);
                mMax.Set(center + offset);
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the minimum coordinate.
             * @param min The minimum coordinate.
             */
            void SetMinimum(const Vector<DataType>& min)
            {
                mMin.Set(min);
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the maximum coordinate.
             * @param max The maximum coordinate.
             */
            void SetMaximum(const Vector<DataType>& max)
            {
                mMax.Set(max);
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Get the minimum coordinate.
             * @return The minimum coordinate.
             */
            const Vector<DataType>& GetMinimum() const
            {
                return mMin;
            }

            /**
             * @brief Get the maximum coordinate.
             * @return The maximum coordinate.
             */
            const Vector<DataType>& GetMaximum() const
            {
                return mMax;
            }

            /**
             * @brief Unite this box with another box.
             * @param other The other box to unite.
             */
            void Unite(const Box& other)
            {
                if (other.IsEmpty())
                {
                    return;
                }
                if (IsEmpty())
                {
                    Set(other);
                    return;
                }

                mMin.MinSelf(other.mMin);
                mMax.MaxSelf(other.mMax);
            }

            /**
             * @brief Include a point in this box.
             * @param point The point to include.
             */
            void Include(const Vector<DataType>& point)
            {
                mMin.MinSelf(point);
                mMax.MaxSelf(point);
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Check if a given box is intersecting this box.
             * @param other The other box to check.
             * @return true if the other box is intersecting this box.
             */
            Bool IsIntersecting(const Box& other) const
            {
                if (mMax.x < other.mMin.x)
                {
                    return false;
                }
                if (mMax.y < other.mMin.y)
                {
                    return false;
                }
                if (mMax.z < other.mMin.z)
                {
                    return false;
                }

                if (mMin.x > other.mMax.x)
                {
                    return false;
                }
                if (mMin.y > other.mMax.y)
                {
                    return false;
                }
                if (mMin.z > other.mMax.z)
                {
                    return false;
                }

                return true;
            }

            /**
             * @brief Check if a the box is empty.
             * A box is only empty when created with the default constructor,
             * explicitly cleared by calling Clear(), or duplicated from another
             * empty box or sphere. As soon as a single point is included, the
             * box is considered "not empty".
             * @return true if the box is empty.
             */
            Bool IsEmpty() const
            {
                return ((mFlags & FLAG_EMPTY) != 0);
            }

            /**
             * @brief Get the flags.
             * @return The bit-mask of flags.
             */
            UInt32 GetFlags() const
            {
                return mFlags;
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return mMin.ToString() + " - " + mMax.ToString();
            }

        protected:
            enum
            {
                FLAG_EMPTY = (1 << 0)
            };

            /** @brief The minimum position. */
            Vector<DataType> mMin;
            /** @brief The maximum position. */
            Vector<DataType> mMax;
            /** @brief Box flags. */
            UInt32 mFlags;
        };
    }
}

#endif // __MURL_MATH_BOX_H__

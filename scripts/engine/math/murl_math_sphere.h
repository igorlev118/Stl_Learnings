// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_SPHERE_H__
#define __MURL_MATH_SPHERE_H__

#include "murl_math_box.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;
        
        /**
         * @ingroup MurlMathClasses
         * @brief A sphere class.
         */
        template<class DataType>
        class Sphere
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             */
            Sphere()
            : mCenter(Vector<DataType>::ZERO_POSITION)
            , mRadius(DataType(0.0))
            , mFlags(FLAG_EMPTY)
            {
            }
            
            /**
             * @brief Constructor uniting two given spheres.
             * @param s1 The first sphere to unite.
             * @param s2 The second sphere to unite.
             */
            Sphere(const Sphere& s1, const Sphere& s2)
            : mCenter(s1.mCenter)
            , mRadius(s1.mRadius)
            , mFlags(s1.mFlags)
            {
                Unite(s2);
            }
            
            /**
             * @brief Constructor taking a center position vector and a radius.
             * @param center The center position.
             * @param radius The radius.
             */
            Sphere(const Vector<DataType>& center, DataType radius)
            : mCenter(center.x, center.y, center.z, DataType(1))
            , mRadius(radius)
            , mFlags(0)
            {
            }
            
            /**
             * @brief Constructor taking individual center position coordinates and a radius.
             * @param centerX The center x-position coordinate.
             * @param centerY The center y-position coordinate.
             * @param centerZ The center z-position coordinate.
             * @param radius The radius.
             */
            Sphere(DataType centerX, DataType centerY, DataType centerZ, DataType radius)
            : mCenter(centerX, centerY, centerZ, DataType(1))
            , mRadius(radius)
            , mFlags(0)
            {
            }
            
            /**
             * @brief Constructor taking the three points of a triangle.
             * @param a The first triangle point.
             * @param b The second triangle point.
             * @param c The third triangle point.
             */
            Sphere(const Vector<DataType>& a, const Vector<DataType>& b, const Vector<DataType>& c)
            : mCenter(Vector<DataType>::UNINITIALIZED)
            , mFlags(0)
            {
                SetContaining(a, b, c);
            }

            /**
             * @brief Constructor taking a box.
             * @param box The box to fit in.
             */
            Sphere(const Box<DataType>& box)
            : mCenter(Vector<DataType>::UNINITIALIZED)
            , mFlags(0)
            {
                Set(box);
            }
            
            /**
             * @brief The copy constructor using a sphere of different type.
             * @param s The sphere to copy.
             */
            template<class DataType2>
            Sphere(const Sphere<DataType2>& s)
            : mCenter(s.GetCenter())
            , mRadius(s.GetRadius())
            , mFlags(s.GetFlags())
            {
            }

            /**
             * @brief Clear the sphere
             */
            void Clear()
            {
                if (IsEmpty())
                {
                    return;
                }
                
                mCenter.Set(Vector<DataType>::ZERO_POSITION);
                mRadius = DataType(0.0);
                mFlags = FLAG_EMPTY;
            }
            
            /**
             * @brief Copy the content of a source sphere to the sphere instance.
             * @param other The sphere to copy from.
             */
            void Set(const Sphere& other)
            {
                mCenter.Set(other.mCenter);
                mRadius = other.mRadius;
                mFlags = other.mFlags;
            }
            
            /**
             * @brief Unite two spheres to the sphere instance.
             * @param s1 The first sphere to unite.
             * @param s2 The second sphere to unite.
             */
            void Set(const Sphere& s1, const Sphere& s2)
            {
                mCenter.Set(s1.mCenter);
                mRadius = s1.mRadius;
                mFlags = s1.mFlags;
                Unite(s2);
            }
            
            /**
             * @brief Set a center position vector and a radius.
             * @param center The center position.
             * @param radius The radius.
             */
            void Set(const Vector<DataType>& center, DataType radius)
            {
                mCenter.Set(center.x, center.y, center.z, DataType(1));
                mRadius = radius;
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the sphere containing a single point.
             * The center of the sphere is set to the given point, 
             * and the radius to 0.
             * @param a The point.
             */
            void SetBounding(const Vector<DataType>& a)
            {
                mCenter.Set(a);
                mRadius = DataType(0);
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the sphere containing two points.
             * The center of the sphere is set to the position at half way
             * between the given points, and the radius to half their distance.
             * @param a The first point.
             * @param b The second point.
             */
            void SetBounding(const Vector<DataType>& a, const Vector<DataType>& b)
            {
                Vector<DataType> ab = b - a;

                Vector<DataType> offset = ab * DataType(0.5);

                mCenter = a + offset;
                mRadius = offset.GetLength();
                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the sphere using three points lying on the sphere boundary.
             * @param a The first point.
             * @param b The second point.
             * @param c The third point.
             */
            void SetBounding(const Vector<DataType>& a, const Vector<DataType>& b, const Vector<DataType>& c)
            {
                Vector<DataType> ab = b - a;
                Vector<DataType> ac = c - a;

                DataType divisor = ab.Cross(ac).GetSquaredLength() * DataType(2.0);

                if (Abs(divisor) <= Limits<DataType>::Epsilon())
                {
                    Box<DataType> bbox(a, b, c);
                    const Vector<DataType>& bboxMin = bbox.GetMinimum();
                    const Vector<DataType>& bboxMax = bbox.GetMaximum();

                    mCenter = (bboxMin + bboxMax) * DataType(0.5);
                    mRadius = (mCenter - bboxMin).GetLength();
                }
                else
                {
                    Vector<DataType> u = (ab.Cross(ac)).Cross(ab) * ac.GetSquaredLength();
                    Vector<DataType> v = (ac.Cross(ab.Cross(ac))) * ab.GetSquaredLength();
                    Vector<DataType> offset = (u + v) / divisor;

                    mCenter = a + offset;
                    mRadius = offset.GetLength();
                }

                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the sphere using four points lying on the sphere boundary.
             * @param a The first point.
             * @param b The second point.
             * @param c The third point.
             * @param d The fourth point.
             */
            void SetBounding(const Vector<DataType>& a, const Vector<DataType>& b, const Vector<DataType>& c, const Vector<DataType>& d)
            {
                Vector<DataType> ab = b - a;
                Vector<DataType> ac = c - a;
                Vector<DataType> ad = d - a;

                DataType divisor = (ab.x * (ac.y * ad.z - ad.y * ac.z) -
                                    ac.x * (ab.y * ad.z - ad.y * ab.z) +
                                    ad.x * (ab.y * ac.z - ac.y * ab.z)) * DataType(2.0);

                if (Abs(divisor) <= Limits<DataType>::Epsilon())
                {
                    Box<DataType> bbox(a, b, c);
                    bbox.Include(d);
                    const Vector<DataType>& bboxMin = bbox.GetMinimum();
                    const Vector<DataType>& bboxMax = bbox.GetMaximum();

                    mCenter = (bboxMin + bboxMax) * DataType(0.5);
                    mRadius = (mCenter - bboxMin).GetLength();
                }
                else
                {
                    Vector<DataType> u = ab.Cross(ac) * ad.GetSquaredLength();
                    Vector<DataType> v = ad.Cross(ab) * ac.GetSquaredLength();
                    Vector<DataType> w = ac.Cross(ad) * ab.GetSquaredLength();
                    Vector<DataType> offset = (u + v + w) / divisor;

                    mCenter = a + offset;
                    mRadius = offset.GetLength();
                }

                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the sphere containing a single point.
             * @param a The point.
             */
            void SetContaining(const Vector<DataType>& a)
            {
                SetBounding(a);
            }

            /**
             * @brief Set the sphere containing two points.
             * This is equal to setting the sphere with the given two points
             * lying on the surface of the returned sphere.
             * @param a The first point.
             * @param b The second point.
             */
            void SetContaining(const Vector<DataType>& a, const Vector<DataType>& b)
            {
                SetBounding(a, b);
            }

            /**
             * @brief Set the sphere containing three points.
             * This is different to SetBounding() in that one of the given
             * points may lie inside the returned sphere and not on the boundary.
             * @param a The first point.
             * @param b The second point.
             * @param c The third point.
             */
            void SetContaining(const Vector<DataType>& a, const Vector<DataType>& b, const Vector<DataType>& c)
            {
                Vector<DataType> ba = b - a;
                Vector<DataType> ca = c - a;
                
                DataType abab = ba.Dot(ba);
                DataType abac = ba.Dot(ca);
                DataType acac = ca.Dot(ca);
                
                DataType d = (abab * acac - abac * abac) * DataType(2);
                
                if (Abs(d) <= Limits<DataType>::Epsilon())
                {
                    Box<DataType> bbox(a, b, c);
                    const Vector<DataType>& bboxMin = bbox.GetMinimum();
                    const Vector<DataType>& bboxMax = bbox.GetMaximum();
                    
                    mCenter = (bboxMin + bboxMax) * DataType(0.5);
                    mRadius = (mCenter - bboxMin).GetLength();
                }
                else
                {
                    DataType r = DataType(1) / d;
                    DataType s = (abab * acac - acac * abac) * r;
                    DataType t = (acac * abab - abab * abac) * r;
                    
                    if (s <= DataType(0))
                    {
                        mCenter = (a + c) * DataType(0.5);
                        mRadius = (mCenter - a).GetLength();
                    }
                    else if (t <= DataType(0))
                    {
                        mCenter = (a + b) * DataType(0.5);
                        mRadius = (mCenter - a).GetLength();
                    }
                    else if ((s + t) >= DataType(1))
                    {
                        mCenter = (b + c) * DataType(0.5);
                        mRadius = (mCenter - b).GetLength();
                    }
                    else
                    {
                        mCenter = a + (ba * s) + (ca * t);
                        mRadius = (mCenter - a).GetLength();
                    }
                }

                mFlags &= ~FLAG_EMPTY;
            }

            /**
             * @brief Set the sphere containing a number of given points.
             * @param p The array of points
             * @param n The number of points
             */
            void SetContaining(const Vector<DataType>* p, UInt32 n)
            {
                const Vector<DataType>** q = new const Vector<DataType>*[n];
                for (UInt32 i = 0; i < n; i++)
                {
                    q[i] = &p[i];
                }

                Set(GetContaining(q, n, 0));

                delete[] q;
            }
            
            /**
             * @brief Set the sphere to fit into a box.
             * @param box The box to fit in.
             */
            void Set(const Box<DataType>& box)
            {
                if (box.IsEmpty())
                {
                    Clear();
                    return;
                }
                
                const Vector<DataType>& min = box.GetMinimum();
                const Vector<DataType>& max = box.GetMaximum();
                
                mCenter.Set((min + max) * DataType(0.5));
                mRadius = (max - min).GetLength() * DataType(0.5);
                mFlags &= ~FLAG_EMPTY;
            }
            
            /**
             * @brief Set the center position.
             * @param center The center position.
             */
            void SetCenter(const Vector<DataType>& center)
            {
                mCenter.Set(center.x, center.y, center.z, DataType(1));
                mFlags &= ~FLAG_EMPTY;
            }
            
            /**
             * @brief Get the center position.
             * @return The center position.
             */
            const Vector<DataType>& GetCenter() const
            {
                return mCenter;
            }
            
            /**
             * @brief Set the radius.
             * @param radius The radius.
             */
            void SetRadius(DataType radius)
            {
                mRadius = radius;
                mFlags &= ~FLAG_EMPTY;
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
             * @brief Unite this sphere with another sphere.
             * @param other The other sphere to unite.
             */
            void Unite(const Sphere& other)
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

                DataType ra = mRadius;
                DataType rb = other.mRadius;
                
                const Vector<DataType>& ca = mCenter;
                const Vector<DataType>& cb = other.mCenter;
                
                Vector<DataType> d = cb - ca;
                DataType l = d.GetLength();
                
                if (l < Limits<DataType>::Epsilon())
                {
                    if (rb > ra)
                    {
                        mRadius = rb;
                    }
                    return;
                }
                
                DataType f = DataType(1) / l;
                DataType distMin = Min(-ra, l - rb) * f;
                DataType distMax = Max(ra, l + rb) * f;
                
                Vector<DataType> posMin = ca + d * distMin;
                Vector<DataType> posMax = ca + d * distMax;
                
                Box<DataType> bbox(posMin, posMax);
                const Vector<DataType>& bboxMin = bbox.GetMinimum();
                const Vector<DataType>& bboxMax = bbox.GetMaximum();
                
                mCenter = (bboxMax + bboxMin) * DataType(0.5);
                mRadius = (bboxMax - bboxMin).GetLength() * DataType(0.5);
                mFlags &= ~FLAG_EMPTY;
            }
            
            /**
             * @brief Include a point in this sphere.
             * @param point The point to include.
             */
            void Include(const Vector<DataType>& point)
            {
                Vector<DataType> d = point - mCenter;
                DataType l2 = d.GetSquaredLength();
                
                if (l2 < (mRadius * mRadius))
                {
                    return;
                }
                
                DataType l = Sqrt(l2);
                DataType f = DataType(1) / l;
                DataType distMin = -mRadius * f;
                DataType distMax = Max(mRadius, l) * f;
                
                Vector<DataType> posMin = mCenter + d * distMin;
                Vector<DataType> posMax = mCenter + d * distMax;
                
                Box<DataType> bbox(posMin, posMax);
                const Vector<DataType>& bboxMin = bbox.GetMinimum();
                const Vector<DataType>& bboxMax = bbox.GetMaximum();
                
                mCenter = (bboxMax + bboxMin) * DataType(0.5);
                mRadius = (bboxMax - bboxMin).GetLength() * DataType(0.5);
                mFlags &= ~FLAG_EMPTY;
            }
            
            /**
             * @brief Check if a given sphere is intersecting this sphere.
             * @param other The other sphere to check.
             * @return true if the other sphere is intersecting this sphere.
             */
            Bool IsIntersecting(const Sphere& other) const
            {
                DataType distanceSquared = (other.mCenter - mCenter).GetSquaredLength();
                DataType radii = other.mRadius + mRadius;
                
                return DataType(distanceSquared - DataType(radii * radii)) <= DataType(0);
            }

            /**
             * @brief Check if a given point is inside this sphere.
             * @param p The point to check.
             * @return true if the point is inside this sphere.
             */
            Bool IsContaining(const Vector<DataType>& p) const
            {
                DataType distanceSquared = (p - mCenter).GetSquaredLength();

                return DataType(distanceSquared - DataType(mRadius * mRadius)) <= DataType(0);
           }
            
            /**
             * @brief Check if a the sphere is empty.
             * A sphere is only empty when created with the default constructor,
             * explicitly cleared by calling Clear(), or duplicated from another
             * empty sphere or box. As soon as a single point is included, the
             * sphere is considered "not empty".
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
                return mCenter.ToString().Cat(Util::PrintToString(" - %f", Double(mRadius)));
            }

        protected:
            enum
            {
                FLAG_EMPTY = (1 << 0)
            };

            Sphere GetContaining(const Vector<DataType>** p, UInt32 n, UInt32 b) const
            {
                Sphere s;

                switch (b)
                {
                    case 1:
                        s.SetBounding(*p[-1]);
                        break;
                    case 2:
                        s.SetBounding(*p[-1], *p[-2]);
                        break;
                    case 3:
                        s.SetBounding(*p[-1], *p[-2], *p[-3]);
                        break;
                    case 4:
                        s.SetBounding(*p[-1], *p[-2], *p[-3], *p[-4]);
                        return s;

                    default:
                        break;

                }

                for (UInt32 i = 0; i < n; i++)
                {
                    if (s.IsContaining(*p[i]))
                    {
                        continue;
                    }

                    for (UInt32 j = i; j > 0; j--)
                    {
                        Util::Swap(p[j], p[j - 1]);
                    }

                    s = GetContaining(p + 1, i, b + 1);
                }

                return s;
            }

            /** @brief The center position of the sphere. */
            Vector<DataType> mCenter;
            /** @brief The radius of the sphere. */
            DataType mRadius;
            /** @brief Sphere flags. */
            UInt32 mFlags;
        };
    }
}

#endif // __MURL_MATH_SPHERE_H__

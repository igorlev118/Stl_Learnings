// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_QUATERNION__
#define __MURL_MATH_QUATERNION__

#include "murl_math.h"
#include "murl_util_string.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;

        template<class DataType>
        class Matrix;

        /**
         * @ingroup MurlMathClasses
         * @brief A quaternion class.
         */
        template<class DataType>
        class Quaternion
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief Enumeration of the components raw data index.
             *  The components can be accessed by using the [] operator.
             */
            enum Component
            {
                /** The index to the R component. */
                R = 0,
                /** The index to the I component. */
                I,
                /** The index to the J component. */
                J,
                /** The index to the K component. */
                K,
                /** The number of components. */
                NUM_COMPONENTS
            };

            /**
             * @brief Enumeration of the components' bit masks
             */
            enum ComponentMask
            {
                /** No component */
                MASK_NONE   = 0,

                /** R component mask */
                MASK_R      = (1 << R),
                /** I component mask */
                MASK_I      = (1 << I),
                /** J component mask */
                MASK_J      = (1 << J),
                /** K component mask */
                MASK_K      = (1 << K),

                /** Component mask for I, J and K (imaginary part) */
                MASK_IJK    = MASK_I + MASK_J + MASK_K,

                /** All components */
                MASK_ALL    = MASK_R + MASK_I + MASK_J + MASK_K
            };

            /**
             * @brief The components storage union overlaps the raw
             * data array mComponents and the component structure.
             */
            union
            {
                /** The components data array. */
                DataType mComponents[NUM_COMPONENTS];

                /** The components member struct. */
                struct
                {
                    /** @brief The R component. */
                    DataType r;
                    /** @brief The I component. */
                    DataType i;
                    /** @brief The J component. */
                    DataType j;
                    /** @brief The K component. */
                    DataType k;
                };
            };

            /**
             * @brief Enumeration of the predefined initialization types
             * for constructing a Quaternion(PredefinedType type).
             */
            enum PredefinedType
            {
                /** Create an uninitialized instance. */
                UNINITIALIZED = 0,

                /** Initialize with the identity {1, 0, 0, 0}. */
                IDENTITY
            };

            /**
             * @brief The default constructor.
             */
            Quaternion()
            : r()
            , i()
            , j()
            , k()
            {
            }

            /**
             * @brief Constructor to initialize a quaternion with given component values.
             * @param vr The r component.
             * @param vi The i component.
             * @param vj The j component.
             * @param vk The k component.
             */
            Quaternion(DataType vr, DataType vi, DataType vj, DataType vk)
            :r(vr)
            ,i(vi)
            ,j(vj)
            ,k(vk)
            {
            }

            /**
             * @brief Constructor to initialize a quaternion from a given 4-vector
             * containing a normalized rotation axis in its x,y and z components,
             * and a rotation angle in its w component.
             * @param v The vector.
             */
            Quaternion(const Vector<DataType>& v)
            {
                DataType s = Sin(v.w * DataType(0.5));
                DataType c = Cos(v.w * DataType(0.5));

                r = c;
                i = v.x * s;
                j = v.y * s;
                k = v.z * s;
            }

            /**
             * @brief Constructor to initialize a quaternion from a given rotation angle
             * and a normalized axis vector.
             * @param angle The rotation angle.
             * @param axis The normalized axis vector.
             */
            Quaternion(DataType angle, const Vector<DataType>& axis)
            {
                DataType s = Sin(angle * DataType(0.5));
                DataType c = Cos(angle * DataType(0.5));

                r = c;
                i = axis.x * s;
                j = axis.y * s;
                k = axis.z * s;
            }

            /**
             * @brief Constructor to initialize a quaternion from the rotation component
             * of a given 4x4 matrix.
             * @param m The matrix.
             */
            Quaternion(const Matrix<DataType>& m)
            {
                Set(m);
            }

            /**
             * @brief Constructor to create a quaternion from a predefined type.
             * @param type The predefined type.
             */
            Quaternion(PredefinedType type)
            {
                switch (type)
                {
                    case UNINITIALIZED:
                        break;

                    case IDENTITY:
                        r = 1;
                        i = 0;
                        j = 0;
                        k = 0;
                        break;

                    default:
                        r = DataType();
                        i = DataType();
                        j = DataType();
                        k = DataType();
                        break;
                }
            }

            /**
             * @brief The copy constructor using a quaternion of different type.
             * @param q The quaternion to copy.
             */
            template<class DataType2>
            Quaternion(const Quaternion<DataType2>& q)
            :r(q.r)
            ,i(q.i)
            ,j(q.j)
            ,k(q.k)
            {
            }

            /**
             * @brief Get a const reference to one of the 4 component values.
             * @param index The component index, see enum #Component.
             * @return The component value const reference.
             */
            const DataType& operator[](UInt32 index) const
            {
                MURL_ASSERT(index < NUM_COMPONENTS);
                return mComponents[index];
            }
            /**
             * @brief Get a reference to one of the 4 component values.
             * @param index The component index, see enum #Component.
             * @return The component value reference.
             */
            DataType& operator[](UInt32 index)
            {
                MURL_ASSERT(index < NUM_COMPONENTS);
                return mComponents[index];
            }
            /**
             * @brief Get a const pointer to the raw data.
             * @return Const pointer to the raw data.
             */
            const DataType* GetPointer() const
            {
                return mComponents;
            }
            /**
             * @brief Get a pointer to the raw data.
             * @return Pointer to the raw data.
             */
            DataType* GetPointer()
            {
                return mComponents;
            }

            /**
             * @brief Set the quaternion from the rotation component of a given 4D matrix.
             * @param m The input matrix.
             */
            void Set(const Matrix<DataType>& m)
            {
                DataType xx = m.GetXX();
                DataType xy = m.GetXY();
                DataType xz = m.GetXZ();

                DataType yx = m.GetYX();
                DataType yy = m.GetYY();
                DataType yz = m.GetYZ();

                DataType zx = m.GetZX();
                DataType zy = m.GetZY();
                DataType zz = m.GetZZ();

                r = DataType(DataType( xx + yy) + DataType( zz + DataType(1.0))) * DataType(0.25);
                i = DataType(DataType( xx - yy) + DataType(-zz + DataType(1.0))) * DataType(0.25);
                j = DataType(DataType(-xx + yy) + DataType(-zz + DataType(1.0))) * DataType(0.25);
                k = DataType(DataType(-xx - yy) + DataType( zz + DataType(1.0))) * DataType(0.25);

                r = Max(r, DataType(0.0));
                i = Max(i, DataType(0.0));
                j = Max(j, DataType(0.0));
                k = Max(k, DataType(0.0));

                r = Sqrt(r);
                i = Sqrt(i);
                j = Sqrt(j);
                k = Sqrt(k);

                if ((r >= i) && (r >= j) && (r >= k))
                {
                    i = ((zy - yz) < DataType(0.0)) ? -i : i;
                    j = ((xz - zx) < DataType(0.0)) ? -j : j;
                    k = ((yx - xy) < DataType(0.0)) ? -k : k;
                }
                else if ((i >= r) && (i >= j) && (i >= k))
                {
                    r = ((zy - yz) < DataType(0.0)) ? -r : r;
                    j = ((yx + xy) < DataType(0.0)) ? -j : j;
                    k = ((xz + zx) < DataType(0.0)) ? -k : k;
                }
                else if ((j >= r) && (j >= i) && (j >= k))
                {
                    r = ((xz - zx) < DataType(0.0)) ? -r : r;
                    i = ((yx + xy) < DataType(0.0)) ? -i : i;
                    k = ((zy + yz) < DataType(0.0)) ? -k : k;
                }
                else if ((k >= r) && (k >= i) && (k >= j))
                {
                    r = ((yx - xy) < DataType(0.0)) ? -r : r;
                    i = ((zx + xz) < DataType(0.0)) ? -i : i;
                    j = ((zy + yz) < DataType(0.0)) ? -j : j;
                }

                DataType l = DataType(DataType(DataType(r * r) + DataType(i * i)) + DataType(DataType(j * j) + DataType(k * k)));
                DataType s = DataType(1.0) / l;
                r *= s;
                i *= s;
                j *= s;
                k *= s;
            }

            /**
             * @brief Assignment operator to convert a 4D vector to a 4D quaternion.
             * @param v The vector to convert.
             * @return The object itself.
             */
            Quaternion& operator=(const Vector<DataType>& v)
            {
                r = 0;
                i = v.x;
                j = v.y;
                k = v.z;

                return *this;
            }

            /**
             * @brief Assignment operator to convert a 4D matrix to a 4D quaternion.
             * @param m The matrix to convert.
             * @return The object itself.
             */
            Quaternion& operator=(const Matrix<DataType>& m)
            {
                Set(m);
                return *this;
            }

            /**
             * @brief In-place addition operator.
             * @param q The quaternion to add.
             * @return The object itself.
             */
            Quaternion& operator+=(const Quaternion& q)
            {
                AddSelf(q);
                return *this;
            }

            /**
             * @brief In-place subtraction operator.
             * @param q The quaternion to subtract.
             * @return The object itself.
             */
            Quaternion& operator*=(const Quaternion& q)
            {
                MultiplySelf(q);
                return *this;
            }

            /**
             * @brief In-place quaternion-vector multiplication operator.
             * @param v The vector to multiply.
             * @return The object itself.
             */
            Quaternion& operator*=(const Vector<DataType>& v)
            {
                MultiplySelf(v);
                return *this;
            }

            /**
             * @brief In-place multiplication operator (scaling).
             * @param d The value to multiply.
             * @return The object itself.
             */
            Quaternion& operator*=(DataType d)
            {
                MultiplySelf(d);
                return *this;
            }

            /**
             * @brief Addition operator.
             * @param rhs The right hand side quaternion.
             * @return The added quaternion.
             */
            Quaternion operator+(const Quaternion& rhs) const
            {
                return Add(rhs);
            }

            /**
             * @brief Quaternion-quaternion multiplication operator.
             * @param rhs The right hand side quaternion.
             * @return The multiplied quaternion.
             */
            Quaternion operator*(const Quaternion& rhs) const
            {
                return Multiply(rhs);
            }

            /**
             * @brief Quaternion-vector multiplication operator.
             * @param rhs The right hand side vector.
             * @return The multiplied quaternion.
             */
            Quaternion operator*(const Vector<DataType>& rhs) const
            {
                return Multiply(rhs);
            }

            /**
             * @brief Multiplication (scaling) operator
             * @param rhs The right hand side value.
             * @return The multiplied quaternion.
             */
            Quaternion operator*(DataType rhs) const
            {
                return Multiply(rhs);
            }

            /**
             * @brief Clear all components of the quaternion instance.
             * Set all components to default constructor of data type.
             */
            void Clear()
            {
                r = DataType();
                i = DataType();
                j = DataType();
                k = DataType();
            }

            /**
             * @brief Copy the content of a source quaternion to the quaternion instance.
             * @param q The quaternion to copy from.
             */
            void Set(const Quaternion& q)
            {
                r = q.r;
                i = q.i;
                j = q.j;
                k = q.k;
            }

            /**
             * @brief Set all components of the quaternion instance to a set of given component values.
             * @param vr The x-component value to set.
             * @param vi The y-component value to set.
             * @param vj The z-component value to set.
             * @param vk The w-component value to set.
             */
            void Set(DataType vr, DataType vi, DataType vj, DataType vk)
            {
                r = vr;
                i = vi;
                j = vj;
                k = vk;
            }

            /**
             * @brief In-place inversion.
             */
            void InvertSelf()
            {
                Set(Invert());
            }

            /**
             * @brief In-place addition.
             * @param q The quaternion to add.
             */
            void AddSelf(const Quaternion& q)
            {
                Set(Add(q));
            }

            /**
             * @brief In-place Quaternion-quaternion multiplication.
             * @param q The quaternion to multiply.
             */
            void MultiplySelf(const Quaternion& q)
            {
                Set(Multiply(q));
            }

            /**
             * @brief In-place Quaternion-vector multiplication.
             * @param v The vector to multiply.
             */
            void MultiplySelf(const Vector<DataType>& v)
            {
                Set(Multiply(v));
            }

            /**
             * @brief In-place multiplication (scaling).
             * @param d The value to multiply.
             */
            void MultiplySelf(DataType d)
            {
                r *= d;
                i *= d;
                j *= d;
                k *= d;
            }

            /**
             * @brief In-place normalization of the quaternion instance.
             */
            void NormalizeSelf()
            {
                DataType d = DataType(DataType(r * r) + DataType(i * i)) + DataType(DataType(j * j) + DataType(k * k));
                if (d != DataType(0.0))
                {
                    DataType l = DataType(1) / Sqrt(d);

                    r *= l;
                    i *= l;
                    j *= l;
                    k *= l;
                }
            }

            /**
             * @brief Get the inverse of a quaternion.
             * This only works for normalized quaternions.
             * @return The inverted quaternion.
             */
            Quaternion Invert() const
            {
                Quaternion n;

                n.r = r;

                n.i = -i;
                n.j = -j;
                n.k = -k;

                return n;
            }

            /**
             * @brief Get the addition of a quaternion.
             * @param q The quaternion to add.
             * @return The added quaternion.
             */
            Quaternion Add(const Quaternion& q) const
            {
                Quaternion n;

                n.r = r + q.r;

                n.i = i + q.i;
                n.j = j + q.j;
                n.k = k + q.k;

                return n;
            }

            /**
             * @brief Get the multiplication with a quaternion.
             * @param q The quaternion to multiply.
             * @return The multiplied quaternion.
             */
            Quaternion Multiply(const Quaternion& q) const
            {
                Quaternion n;

                n.r = DataType(r * q.r) - DataType(DataType(DataType(i * q.i) + DataType(j * q.j)) + DataType(k * q.k));

                n.i = DataType(DataType(r * q.i) + DataType(q.r * i)) + DataType(DataType(j * q.k) - DataType(k * q.j));
                n.j = DataType(DataType(r * q.j) + DataType(q.r * j)) + DataType(DataType(k * q.i) - DataType(i * q.k));
                n.k = DataType(DataType(r * q.k) + DataType(q.r * k)) + DataType(DataType(i * q.j) - DataType(j * q.i));

                return n;
            }

            /**
             * @brief Get the multiplication with a vector.
             * @param v The vector to multiply.
             * @return The multiplied quaternion.
             */
            Quaternion Multiply(const Vector<DataType>& v) const
            {
                Quaternion n;

                n.r = -DataType(DataType(DataType(i * v.x) + DataType(j * v.y)) + DataType(k * v.z));

                n.i = DataType(r * v.x) + DataType(DataType(j * v.z) - DataType(k * v.y));
                n.j = DataType(r * v.y) + DataType(DataType(k * v.x) - DataType(i * v.z));
                n.k = DataType(r * v.z) + DataType(DataType(i * v.y) - DataType(j * v.x));

                return n;
            }

            /**
             * @brief Get the multiplication (scaling).
             * @param d The value to multiply.
             * @return The multiplied quaternion.
             */
            Quaternion Multiply(DataType d) const
            {
                Quaternion n;

                n.r = r * d;
                n.i = i * d;
                n.j = j * d;
                n.k = k * d;

                return n;
            }

            /**
             * @brief Get the normalization of the quaternion instance.
             * @return The normalized quaternion.
             */
            Quaternion Normalize() const
            {
                Quaternion n;

                DataType d = DataType(DataType(r * r) + DataType(i * i)) + DataType(DataType(j * j) + DataType(k * k));
                if (d != DataType(0.0))
                {
                    DataType l = DataType(1) / Sqrt(d);

                    n.r = r * l;
                    n.i = i * l;
                    n.j = j * l;
                    n.k = k * l;
                }
                else
                {
                    n = *this;
                }

                return n;
            }

            /**
             * @brief Interpolate between this instance and a second quaternion.
             * For t=0.0, the result equals the first quaternion, and for t=1.0 the second one.
             * @param q The quaternion to interpolate to.
             * @param t The interpolation factor.
             * @param spherical If true, a spherical interpolation is applied. If false,
             *      nterpolation is performed in a linear way.
             * @return The interpolated quaternion.
             */
            Quaternion Interpolate(const Quaternion& q, DataType t, Bool spherical) const
            {
                Quaternion n;

                Clamp(t, DataType(0.0), DataType(1.0));

                DataType cosOmega = (i * q.i) + (j * q.j) + (k * q.k) + (r * q.r);

                Bool invert = false;
                if (cosOmega < DataType(0.0))
                {
                    cosOmega = -cosOmega;
                    invert = true;
                }

                DataType sclp;
                DataType sclq;
                if (spherical && ((DataType(1.0) - cosOmega) > DataType(0.0001)))
                {
                    DataType omega = ArcCos(Double(cosOmega));
                    DataType sinOmega = Sin(Double(omega));

                    sclp = Sin(Double((DataType(1.0) - t) * omega)) / sinOmega;
                    sclq = Sin(Double(t * omega)) / sinOmega;
                }
                else
                {
                    sclp = DataType(1.0) - t;
                    sclq = t;
                }

                if (!invert)
                {
                    n.i = i * sclp + q.i * sclq;
                    n.j = j * sclp + q.j * sclq;
                    n.k = k * sclp + q.k * sclq;
                    n.r = r * sclp + q.r * sclq;
                }
                else
                {
                    n.i = i * sclp - q.i * sclq;
                    n.j = j * sclp - q.j * sclq;
                    n.k = k * sclp - q.k * sclq;
                    n.r = r * sclp - q.r * sclq;
                }

                return n;
            }

            /**
             * @brief Check if the quaternion instance is equal to a given second quaternion.
             * Compares all values within the default epsilon range Limits::Epsilon().
             * @param q The quaternion to compare.
             * @return true if equal to the compared quaternion.
             */
            Bool IsEqual(const Quaternion& q) const
            {
                return IsEqual(q, Limits<DataType>::Epsilon());
            }

            /**
             * @brief Check if the quaternion instance is equal to a given second quaternion.
             * Compares all values within a given epsilon range.
             * @param q The quaternion to compare.
             * @param epsilon The epsilon to compare.
             * @return true if equal to the compared quaternion.
             */
            Bool IsEqual(const Quaternion& q, DataType epsilon) const
            {
                if ((Math::Abs(r - q.r) < epsilon) && (Math::Abs(i - q.i) < epsilon) &&
                    (Math::Abs(j - q.j) < epsilon) && (Math::Abs(k - q.k) < epsilon))
                {
                    return true;
                }

                if ((Math::Abs(r + q.r) < epsilon) && (Math::Abs(i + q.i) < epsilon) &&
                    (Math::Abs(j + q.j) < epsilon) && (Math::Abs(k + q.k) < epsilon))
                {
                    return true;
                }

                return false;
            }

            /**
             * @brief Equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Quaternion> class.
             * To compare within an epsilon range use Quaternion::IsEqual().
             * @param lhs The left hand side quaternion to compare.
             * @param rhs The right hand side quaternion to compare.
             * @return true if all components are exactly the same.
             */
            friend bool operator==(const Quaternion<DataType>& lhs, const Quaternion<DataType>& rhs)
            {
                return ((lhs.r == rhs.r) && (lhs.i == rhs.i) &&
                        (lhs.j == rhs.j) && (lhs.k == rhs.k));
            }

            /**
             * @brief Not equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Quaternion> class.
             * To compare within an epsilon range use Quaternion::IsEqual().
             * @param lhs The left hand side quaternion to compare.
             * @param rhs The right hand side quaternion to compare.
             * @return true if all components are not exactly the same.
             */
            friend bool operator!=(const Quaternion<DataType>& lhs, const Quaternion<DataType>& rhs)
            {
                return !operator==(lhs, rhs);
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return Util::PrintToString("%f, %f, %f, %f",
                                           Double(r), Double(i), Double(j), Double(k));
            }

            /**
             * @brief Get the number of elements in the object.
             * @return The number of elements in the object.
             */
            SInt32 GetCount() const
            {
                return NUM_COMPONENTS;
            }
        };
    }
}

#endif // __MURL_MATH_QUATERNION__

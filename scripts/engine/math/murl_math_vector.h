// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_VECTOR_H__
#define __MURL_MATH_VECTOR_H__

#include "murl_math.h"
#include "murl_util_string.h"
#include "murl_debug_assert.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Quaternion;

        /**
         * @ingroup MurlMathClasses
         * @brief A 4-component vector class.
         */
        template<class DataType>
        class Vector
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
                /** The index to the X component. */
                X = 0,
                /** The index to the Y component. */
                Y,
                /** The index to the Z component. */
                Z,
                /** The index to the W component. */
                W,
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

                /** X component mask */
                MASK_X      = (1 << X),
                /** Y component mask */
                MASK_Y      = (1 << Y),
                /** Z component mask */
                MASK_Z      = (1 << Z),
                /** W component mask */
                MASK_W      = (1 << W),

                /** Component mask for X and Y */
                MASK_XY     = MASK_X + MASK_Y,
                /** Component mask for X and Z */
                MASK_XZ     = MASK_X + MASK_Z,
                /** Component mask for Y and Z */
                MASK_YZ     = MASK_Y + MASK_Z,

                /** Component mask for X, Y  and Z */
                MASK_XYZ    = MASK_X + MASK_Y + MASK_Z,

                /** All components */
                MASK_ALL    = MASK_X + MASK_Y + MASK_Z + MASK_W
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
                    /** The X component. */
                    DataType x;
                    /** The Y component. */
                    DataType y;
                    /** The Z component. */
                    DataType z;
                    /** The W component. */
                    DataType w;
                };
            };

            /**
             * @brief Enumeration of the predefined initialization types
             * for constructing a Vector(PredefinedType type).
             */
            enum PredefinedType
            {
                /** Initialize with zero direction {0, 0, 0, 0}. */
                ZERO_DIRECTION = 0,

                /** Initialize with zero position {0, 0, 0, 1}. */
                ZERO_POSITION = 1,

                /** Create an uninitialized instance. */
                UNINITIALIZED,
            };

            /**
             * @brief The default constructor.
             */
            Vector()
            : x()
            , y()
            , z()
            , w()
            {
            }

            /**
             * @brief The copy constructor using a vector of different type.
             * @param v The vector to copy.
             */
            template<class DataType2>
            Vector(const Vector<DataType2>& v)
            : x(v.x)
            , y(v.y)
            , z(v.z)
            , w(v.w)
            {
            }

            /**
             * @brief Constructor to initialize a vector with given component values.
             * @param vx The x component.
             * @param vy The y component.
             * @param vz The z component.
             * @param vw The w component.
             */
            Vector(DataType vx, DataType vy, DataType vz, DataType vw)
            : x(vx)
            , y(vy)
            , z(vz)
            , w(vw)
            {
            }

            /**
             * @brief Constructor to initialize an axis/angle vector from a quaternion.
             * @param q The quaternion.
             */
            Vector(const Quaternion<DataType>& q)
            {
                Set(q);
            }

            /**
             * @brief Constructor to create a vector from a predefined type.
             * @param type The predefined type.
             */
            Vector(PredefinedType type)
            {
                Set(type);
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
             * @brief In-place addition operator.
             * @param v The vector to add.
             * @return The object itself.
             */
            Vector& operator+=(const Vector& v)
            {
                AddSelf(v);
                return *this;
            }

            /**
             * @brief In-place subtraction operator.
             * @param v The vector to subtract.
             * @return The object itself.
             */
            Vector& operator-=(const Vector& v)
            {
                SubtractSelf(v);
                return *this;
            }

            /**
             * @brief In-place multiplication operator (scaling).
             * @param v The value to multiply.
             * @return The object itself.
             */
            Vector& operator*=(DataType v)
            {
                MultiplySelf(v);
                return *this;
            }

            /**
             * @brief In-place component-wise multiplication operator.
             * @param v The vector to multiply.
             * @return The object itself.
             */
            Vector& operator*=(const Vector& v)
            {
                MultiplySelf(v);
                return *this;
            }

            /**
             * @brief In-place division operator (inverse scaling).
             * @param v The value to divide.
             * @return The object itself.
             */
            Vector& operator/=(DataType v)
            {
                DivideSelf(v);
                return *this;
            }

            /**
             * @brief In-place component-wise division operator.
             * @param v The vector to multiply.
             * @return The object itself.
             */
            Vector& operator/=(const Vector& v)
            {
                DivideSelf(v);
                return *this;
            }

            /**
             * @brief Addition operator.
             * @param rhs The right hand side vector.
             * @return The added vector.
             */
            Vector operator+(const Vector& rhs) const
            {
                return Add(rhs);
            }

            /**
             * @brief Subtraction operator.
             * @param rhs The right hand side vector.
             * @return The subtracted vector.
             */
            Vector operator-(const Vector& rhs) const
            {
                return Subtract(rhs);
            }

            /**
             * @brief Multiplication (scaling) operator.
             * @param rhs The right hand side value.
             * @return The multiplied vector.
             */
            Vector operator*(DataType rhs) const
            {
                return Multiply(rhs);
            }

            /**
             * @brief Component-wise multiplication operator.
             * @param rhs The right hand side vector.
             * @return The multiplied vector.
             */
            Vector operator*(const Vector& rhs) const
            {
                return Multiply(rhs);
            }

            /**
             * @brief Division (inverse scaling) operator.
             * @param rhs The right hand side value.
             * @return The divided vector.
             */
            Vector operator/(DataType rhs) const
            {
                return Divide(rhs);
            }

            /**
             * @brief Component-wise division operator.
             * @param rhs The right hand side vector.
             * @return The divided vector.
             */
            Vector operator/(const Vector& rhs) const
            {
                return Divide(rhs);
            }

            /**
             * @brief Inversion (negation) operator.
             * @return The inverted vector.
             */
            Vector operator-() const
            {
                return Invert();
            }

            /**
             * @brief Multiplication operator for quaternion.
             * @param rhs The right hand side quaternion.
             * @return The multiplied Quaternion.
             */
            Quaternion<DataType> operator*(const Quaternion<DataType>& rhs) const
            {
                return Multiply(rhs);
            }

            /**
             * @brief Clear all components of the vector instance.
             * Set all components to default constructor of data type.
             */
            void Clear()
            {
                x = DataType();
                y = DataType();
                z = DataType();
                w = DataType();
            }

            /**
             * @brief Set all components of the vector instance to the values of a given predefined type.
             * @param type The value to set.
             */
            void Set(PredefinedType type)
            {
                switch (type)
                {
                    case UNINITIALIZED:
                        return;

                    case ZERO_POSITION:
                        x = 0;
                        y = 0;
                        z = 0;
                        w = 1;
                        return;

                    default:
                    case ZERO_DIRECTION:
                        x = 0;
                        y = 0;
                        z = 0;
                        w = 0;
                        return;
                }
            }

            /**
             * @brief Copy the content of a source vector to the vector instance.
             * @param v The vector to copy from.
             */
            void Set(const Vector& v)
            {
                x = v.x;
                y = v.y;
                z = v.z;
                w = v.w;
            }

            /**
             * @brief Set all components of the vector instance to a given value.
             * @param v The value to set.
             */
            void Set(DataType v)
            {
                x = v;
                y = v;
                z = v;
                w = v;
            }

            /**
             * @brief Set all components of the vector instance to a set of given component values.
             * @param vx The x-component value to set.
             * @param vy The y-component value to set.
             * @param vz The z-component value to set.
             * @param vw The w-component value to set.
             */
            void Set(DataType vx, DataType vy, DataType vz, DataType vw)
            {
                x = vx;
                y = vy;
                z = vz;
                w = vw;
            }

            /**
             * @brief Convert a given quaternion to an axis/angle vector.
             * @param q The quaternion to convert from.
             */
            void Set(const Quaternion<DataType>& q)
            {
                Quaternion<DataType> o(q);
                if (o.r > DataType(1))
                {
                    o.NormalizeSelf();
                }

                w = DataType(2) * ArcCos(o.r);
                DataType s = Sqrt(DataType(1) - DataType(o.r * o.r));

                if (s < DataType(0.001))
                {
                    x = o.i;
                    y = o.j;
                    z = o.k;
                }
                else
                {
                    x = o.i / s;
                    y = o.j / s;
                    z = o.k / s;
                }

                if (GetSquaredLength() == DataType(0))
                {
                    x = 0;
                    y = 0;
                    z = DataType(-1);
                    w = 0;
                }
            }

            /**
             * @brief In-place addition.
             * @param v The vector to add.
             */
            void AddSelf(const Vector& v)
            {
                x += v.x;
                y += v.y;
                z += v.z;
                w += v.w;
            }

            /**
             * @brief In-place subtraction.
             * @param v The vector to subtract.
             */
            void SubtractSelf(const Vector& v)
            {
                x -= v.x;
                y -= v.y;
                z -= v.z;
                w -= v.w;
            }

            /**
             * @brief In-place multiplication (scaling).
             * @param v The value to multiply.
             */
            void MultiplySelf(DataType v)
            {
                x *= v;
                y *= v;
                z *= v;
                w *= v;
            }

            /**
             * @brief In-place component-wise multiplication.
             * @param v The vector to multiply.
             */
            void MultiplySelf(const Vector& v)
            {
                x *= v.x;
                y *= v.y;
                z *= v.z;
                w *= v.w;
            }

            /**
             * @brief In-place division (inverse scaling).
             * @param v The value to divide.
             */
            void DivideSelf(DataType v)
            {
                DataType d = DataType(1) / v;
                x *= d;
                y *= d;
                z *= d;
                w *= d;
            }

            /**
             * @brief In-place component-wise division.
             * @param v The vector to divide.
             */
            void DivideSelf(const Vector& v)
            {
                x /= v.x;
                y /= v.y;
                z /= v.z;
                w /= v.w;
            }

            /**
             * @brief In-place cross product.
             * @param v The vector to cross.
             */
            void CrossSelf(const Vector& v)
            {
                DataType nx = DataType(y * v.z) - DataType(z * v.y);
                DataType ny = DataType(z * v.x) - DataType(x * v.z);
                DataType nz = DataType(x * v.y) - DataType(y * v.x);

                x = nx;
                y = ny;
                z = nz;

                w *= v.w;
            }

            /**
             * @brief In-place linear interpolation.
             * Interpolation along a straight line between the vector
             * instance (first vector) and a given second vector. For t=0.0, the
             * result equals the first vector and for t=1.0 the second one.
             * @param v The vector to interpolate.
             * @param t The distance for interplation.
             */
            void InterpolateSelf(const Vector& v, DataType t)
            {
                x += t * DataType(v.x - x);
                y += t * DataType(v.y - y);
                z += t * DataType(v.z - z);
                w += t * DataType(v.w - w);
            }

            /**
             * @brief In-place projection of a given second vector.
             * Project the given second vector onto the vector instance (first vector).
             * The first vector gets normalized and then multiplied by the length
             * retrieved from a dot-product multiplication between the two vectors
             * (i.e. the vector instance retains its direction,
             * but retrieves the length of the projection).
             * @param v The vector to project from.
             */
            void ProjectSelf(const Vector& v)
            {
                NormalizeSelf();
                MultiplySelf(Dot(v));
            }

            /**
             * @brief In-place set each component to the minimum from the vector instance
             * and a given second vector.
             * @param v The vector to evaluate the minimum from.
             */
            void MinSelf(const Vector& v)
            {
                x = x < v.x ? x : v.x;
                y = y < v.y ? y : v.y;
                z = z < v.z ? z : v.z;
                w = w < v.w ? w : v.w;
            }

            /**
             * @brief In-place set each component to the maximum from the vector instance
             * and a given second vector.
             * @param v The vector to evaluate the maximum from.
             */
            void MaxSelf(const Vector& v)
            {
                x = x > v.x ? x : v.x;
                y = y > v.y ? y : v.y;
                z = z > v.z ? z : v.z;
                w = w > v.w ? w : v.w;
            }

            /**
             * @brief In-place clamp each component to the value range given by the min
             * and max vector parameters.
             * @param min The component-wise minimum to clamp to.
             * @param max The component-wise maximum to clamp to.
             */
            void ClampSelf(const Vector& min, const Vector& max)
            {
                MaxSelf(min);
                MinSelf(max);
            }

            /**
             * @brief Rescale the vector to a length below or equal a given minimum.
             * See MinLength().
             * @param v The minimum length.
             */
            void MinLengthSelf(DataType v)
            {
                Set(MinLength(v));
            }

            /**
             * @brief Rescale the vector to a length above or equal a given maximum.
             * See MaxLength().
             * @param v The maximum length.
             */
            void MaxLengthSelf(DataType v)
            {
                Set(MaxLength(v));
            }

            /**
             * @brief Clamp the vector to a length within a given range.
             * See ClampLength().
             * @param min The minimum length.
             * @param max The maximum length.
             */
            void ClampLengthSelf(DataType min, DataType max)
            {
                Set(ClampLength(min, max));
            }

            /**
             * @brief Set all vector components to their absolute value.
             */
            void AbsSelf()
            {
                x = Math::Abs(x);
                y = Math::Abs(y);
                z = Math::Abs(z);
                w = Math::Abs(w);
            }

            /**
             * @brief Set all vector components to either -1, 0 or +1 depending on
             * their sign.
             */
            void SgnSelf()
            {
                for (UInt32 i = 0; i < 4; i++)
                {
                    if (mComponents[i] > Real(0.0))
                    {
                        mComponents[i] = Real(1.0);
                    }
                    else if (mComponents[i] < Real(0.0))
                    {
                        mComponents[i] = Real(-1.0);
                    }
                }
            }

            /**
             * @brief In-place inversion (negation) of the vector instance.
             */
            void InvertSelf()
            {
                x = -x;
                y = -y;
                z = -z;
                w = -w;
            }

            /**
             * @brief In-place normalization of the vector instance.
             * Normalization retains the direction and sets the length to 1.0.
             */
            void NormalizeSelf()
            {
                DataType l = DataType(1) / GetLength();
                x *= l;
                y *= l;
                z *= l;
                w = 0;  //*= l;
            }

            /**
             * @brief In-place normalization of the x, y and z components.
             * Calculates the normalization without touching the w component,
             * for normalizing the axis of an axis/angle representation.
             */
            void NormalizeAxisSelf()
            {
                DataType l = DataType(1) / GetLength();
                x *= l;
                y *= l;
                z *= l;
            }

            /**
             * @brief Get the addition of a vector.
             * @param v The vector to add.
             * @return The added vector.
             */
            Vector Add(const Vector& v) const
            {
                Vector n;
                n.x = x + v.x;
                n.y = y + v.y;
                n.z = z + v.z;
                n.w = w + v.w;
                return n;
            }

            /**
             * @brief Get the subtraction of a vector.
             * @param v The vector to subtract.
             * @return The subtracted vector.
             */
            Vector Subtract(const Vector& v) const
            {
                Vector n;
                n.x = x - v.x;
                n.y = y - v.y;
                n.z = z - v.z;
                n.w = w - v.w;
                return n;
            }

            /**
             * @brief Get the multiplication with a quaternion.
             * @param q The quaternion to multiply.
             * @return The multiplied quaternion.
             */
            Quaternion<DataType> Multiply(const Quaternion<DataType>& q) const
            {
                Quaternion<DataType> n;

                n.r = -DataType(DataType(DataType(x * q.i) + DataType(y * q.j)) + DataType(z * q.k));

                n.i = DataType(q.r * x) + DataType(DataType(y * q.k) - DataType(z * q.j));
                n.j = DataType(q.r * y) + DataType(DataType(z * q.i) - DataType(x * q.k));
                n.k = DataType(q.r * z) + DataType(DataType(x * q.j) - DataType(y * q.i));

                return n;
            }

            /**
             * @brief Get the multiplication (scaling).
             * @param v The value to multiply.
             * @return The multiplied vector.
             */
            Vector Multiply(DataType v) const
            {
                Vector n;
                n.x = x * v;
                n.y = y * v;
                n.z = z * v;
                n.w = w * v;
                return n;
            }

            /**
             * @brief Get the component-wise multiplication.
             * @param v The vector to multiply.
             * @return The multiplied vector.
             */
            Vector Multiply(const Vector& v) const
            {
                Vector n;
                n.x = x * v.x;
                n.y = y * v.y;
                n.z = z * v.z;
                n.w = w * v.w;
                return n;
            }

            /**
             * @brief Get the division (inverse scaling).
             * @param v The value to divide.
             * @return The divided vector.
             */
            Vector Divide(DataType v) const
            {
                DataType d = DataType(1) / v;
                Vector n;
                n.x = x * d;
                n.y = y * d;
                n.z = z * d;
                n.w = w * d;
                return n;
            }

            /**
             * @brief Get the component-wise division
             * @param v The vector to divide.
             * @return The divided vector.
             */
            Vector Divide(const Vector& v) const
            {
                Vector n;
                n.x = x / v.x;
                n.y = y / v.y;
                n.z = z / v.z;
                n.w = w / v.w;
                return n;
            }

            /**
             * @brief Get the cross product.
             * @param v The vector to cross.
             * @return The cross product vector.
             */
            Vector Cross(const Vector& v) const
            {
                Vector n;
                n.x = DataType(y * v.z) - DataType(z * v.y);
                n.y = DataType(z * v.x) - DataType(x * v.z);
                n.z = DataType(x * v.y) - DataType(y * v.x);
                n.w = w * v.w;
                return n;
            }

            /**
             * @brief Get the linear interpolation.
             * Interpolation along a straight line between the vector
             * instance (first vector) and a given second vector. For t=0.0, the
             * result equals the first vector and for t=1.0 the second one.
             * @param v The vector to interpolate.
             * @param t The interpolation factor.
             * @return The interpolated vector.
             */
            Vector Interpolate(const Vector& v, DataType t) const
            {
                Vector n;
                n.x = DataType(DataType(x) + DataType(t * DataType(v.x - x)));
                n.y = DataType(DataType(y) + DataType(t * DataType(v.y - y)));
                n.z = DataType(DataType(z) + DataType(t * DataType(v.z - z)));
                n.w = DataType(DataType(w) + DataType(t * DataType(v.w - w)));
                return n;
            }

            /**
             * @brief Get the projection of a given second vector.
             * Project the given second vector onto the vector instance (first vector).
             * The first vector gets normalized and then multiplied by the length
             * retrieved from a dot-product multiplication between the two vectors
             * (i.e. the vector instance retains its direction,
             * but retrieves the length of the projection).
             * @param v The vector to project from.
             * @return The projected vector.
             */
            Vector Project(const Vector& v) const
            {
                Vector n = Normalize();
                return n.Multiply(Dot(v));
            }

            /**
             * @brief Get the minimum of each component from the vector instance
             * and a given second vector.
             * @param v The vector to evaluate the minimum from.
             * @return The minimum vector.
             */
            Vector Min(const Vector& v) const
            {
                Vector n;
                n.x = x < v.x ? x : v.x;
                n.y = y < v.y ? y : v.y;
                n.z = z < v.z ? z : v.z;
                n.w = w < v.w ? w : v.w;
                return n;
            }

            /**
             * @brief Get the maximum of each component from the vector instance
             * and a given second vector.
             * @param v The vector to evaluate the maximum from.
             * @return The maximum vector.
             */
            Vector Max(const Vector& v) const
            {
                Vector n;
                n.x = x > v.x ? x : v.x;
                n.y = y > v.y ? y : v.y;
                n.z = z > v.z ? z : v.z;
                n.w = w > v.w ? w : v.w;
                return n;
            }

            /**
             * @brief Clamp each component to the value range given by the min and
             * max vector parameters.
             * @param min The component-wise minimum to clamp to.
             * @param max The component-wise maximum to clamp to.
             * @return The clamped vector.
             */
            Vector Clamp(const Vector& min, const Vector& max) const
            {
                Vector ret(*this);
                ret.ClampSelf(min, max);
                return ret;
            }

            /**
             * @brief Get a vector with a length below or equal a given minimum.
             * If the current vector's length is below or equal the given minimum value,
             * the vector is directly returned. Otherwise a scaled vector is returned,
             * with the original direction and given length.
             * @param v The minimum length.
             * @return A minimum length vector.
             */
            Vector MinLength(DataType v) const
            {
                if (v <= DataType(0.0))
                {
                    if (w == DataType(0.0))
                    {
                        return Vector::ZERO_DIRECTION;
                    }
                    else
                    {
                        return Vector::ZERO_POSITION;
                    }
                }

                DataType length = GetLength();
                if (length <= v)
                {
                    return *this;
                }
                DataType scale = v / length;

                Vector ret;
                ret.x = x * scale;
                ret.y = y * scale;
                ret.z = z * scale;
                ret.w = w;

                return ret;
            }

            /**
             * @brief Get a vector with a length above or equal a given maximum.
             * If the current vector's length is above or equal the given maximum value,
             * the vector is directly returned. Otherwise a scaled vector is returned,
             * with the original direction and given length. If the vector has zero length
             * (i.e. undefined direction) a zero vector is returned with its w component
             * set to either 0 or 1, depending on the current vector's w value.
             * @param v The maximum length.
             * @return A maximum length vector.
             */
            Vector MaxLength(DataType v) const
            {
                if (v <= DataType(0.0))
                {
                    if (w == DataType(0.0))
                    {
                        return Vector::ZERO_DIRECTION;
                    }
                    else
                    {
                        return Vector::ZERO_POSITION;
                    }
                }

                DataType length = GetLength();
                if (length >= v)
                {
                    return *this;
                }
                if (length == DataType(0.0))
                {
                    return *this;
                }

                DataType scale = v / length;

                Vector ret;
                ret.x = x * scale;
                ret.y = y * scale;
                ret.z = z * scale;
                ret.w = w;

                return ret;
            }

            /**
             * @brief Get the a vector with clamped length.
             * This method returns a vector in the direction of the vector instance,
             * but with its length clamped to the given range.
             * @param min The minimum length.
             * @param max The maximum length.
             * @return A clamped vector.
             */
            Vector ClampLength(DataType min, DataType max) const
            {
                if ((min > max) || (max <= DataType(0.0)))
                {
                    if (w == DataType(0.0))
                    {
                        return Vector::ZERO_DIRECTION;
                    }
                    else
                    {
                        return Vector::ZERO_POSITION;
                    }
                }

                DataType length = GetLength();
                if ((length >= min) && (length <= max))
                {
                    return *this;
                }
                if (length == DataType(0.0))
                {
                    return *this;
                }

                DataType scale = DataType(0.0);
                if (length < min)
                {
                    scale = min / length;
                }
                if (length > max)
                {
                    scale = max / length;
                }

                Vector ret;
                ret.x = x * scale;
                ret.y = y * scale;
                ret.z = z * scale;
                ret.w = w;

                return ret;
            }

            /**
             * @brief Get a vector containing absolute values for each of the instance's
             * components.
             * @return The resulting vector.
             */
            Vector Abs() const
            {
                Vector n;
                n.x = Math::Abs(x);
                n.y = Math::Abs(y);
                n.z = Math::Abs(z);
                n.w = Math::Abs(w);
                return n;
            }

            /**
             * @brief Get a vector containing component values of either -1, 0 or +1,
             * depending on the instance component's signs.
             * @return The resulting vector.
             */
            Vector Sgn() const
            {
                Vector n;
                for (UInt32 i = 0; i < 4; i++)
                {
                    if (mComponents[i] > Real(0.0))
                    {
                        n.mComponents[i] = Real(1.0);
                    }
                    else if (mComponents[i] < Real(0.0))
                    {
                        n.mComponents[i] = Real(-1.0);
                    }
                    else
                    {
                        n.mComponents[i] = Real(0.0);
                    }
                }
                return n;
            }

            /**
             * @brief Get the inversion (negation) of the vector instance.
             * @return The inverted vector.
             */
            Vector Invert() const
            {
                Vector n;
                n.x = -x;
                n.y = -y;
                n.z = -z;
                n.w = -w;
                return n;
            }

            /**
             * @brief Get the normalization of the vector instance.
             * Normalization retains the direction and sets the length to 1.0.
             * @return The normalized vector.
             */
            Vector Normalize() const
            {
                DataType l = DataType(1) / GetLength();
                Vector n;
                n.x = x * l;
                n.y = y * l;
                n.z = z * l;
                n.w = 0;    //w * l;
                return n;
            }

            /**
             * @brief Get the normalization of the x, y and z components.
             * Calculates the normalization without touching the w component,
             * for normalizing the axis of an axis/angle representation.
             * @return The normalized axis vector.
             */
            Vector NormalizeAxis() const
            {
                DataType l = DataType(1) / GetLength();
                Vector n;
                n.x = x * l;
                n.y = y * l;
                n.z = z * l;
                n.w = w;
                return n;
            }

            /**
             * @brief Get the dot product of the vector instance and a given second vector.
             * @param v The second vector.
             * @return The dot product.
             */
            DataType Dot(const Vector& v) const
            {
                return DataType(DataType(x * v.x) + DataType(y * v.y)) + DataType(z * v.z);
            }

            /**
             * @brief Get the length of the vector instance.
             * @return The length of the vector.
             */
            DataType GetLength() const
            {
                DataType x2 = DataType(x) * DataType(x);
                DataType y2 = DataType(y) * DataType(y);
                DataType z2 = DataType(z) * DataType(z);
                DataType sum = DataType(x2 + y2);
                sum += z2;

                return Sqrt(sum);
            }

            /**
             * @brief Get the squared length of the vector instance.
             * @return The squared length of the vector.
             */
            DataType GetSquaredLength() const
            {
                DataType x2 = DataType(x) * DataType(x);
                DataType y2 = DataType(y) * DataType(y);
                DataType z2 = DataType(z) * DataType(z);
                DataType sum = DataType(x2 + y2);
                sum += z2;

                return sum;
            }

            /**
             * @brief Get the x/y angle of the vector instance.
             * @return The angle in radians [0 .. 2π].
             */
            DataType GetAngle2D() const
            {
                DataType angle = ArcCos(x / Sqrt(x * x + y * y));
                if (y < 0)
                {
                    angle = TWO_PI - angle;
                }
                return angle;
            }

            /**
             * @brief Check if the vector instance equals the null vector.
             * Compares all values within the default epsilon range Limits::Epsilon().
             * @return true if equals the null vector.
             */
            Bool IsZero() const
            {
                return IsZero(Limits<DataType>::Epsilon());
            }

            /**
             * @brief Check if the vector instance equals the null vector.
             * Compares all values within a given epsilon range.
             * @param epsilon The epsilon to compare.
             * @return true if equals the null vector.
             */
            Bool IsZero(DataType epsilon) const
            {
                DataType dx = x < 0 ? -x : x;
                DataType dy = y < 0 ? -y : y;
                DataType dz = z < 0 ? -z : z;
                DataType dw = w < 0 ? -w : w;

                if ((dx < epsilon) && (dy < epsilon) && (dz < epsilon) && (dw < epsilon))
                {
                    return true;
                }

                return false;
            }

            /**
             * @brief Check if the vector instance equals the zero position.
             * Compares the x, y and z values within the default epsilon range Limits::Epsilon().
             * @return true if equals the null vector.
             */
            Bool IsZeroPosition() const
            {
                return IsZeroPosition(Limits<DataType>::Epsilon());
            }

            /**
             * @brief Check if the vector instance equals the zero position.
             * Compares the x, y and z values within a given epsilon range.
             * @param epsilon The epsilon to compare.
             * @return true if equals the null vector.
             */
            Bool IsZeroPosition(DataType epsilon) const
            {
                DataType dx = x < 0 ? -x : x;
                DataType dy = y < 0 ? -y : y;
                DataType dz = z < 0 ? -z : z;

                if ((dx < epsilon) && (dy < epsilon) && (dz < epsilon))
                {
                    return true;
                }

                return false;
            }

            /**
             * @brief Check if the vector instance is equal to a given second vector.
             * Compares all values within the default epsilon range Limits::Epsilon().
             * @param v The vector to compare.
             * @return true if equal to the compared vector.
             */
            Bool IsEqual(const Vector& v) const
            {
                return IsEqual(v, Limits<DataType>::Epsilon());
            }

            /**
             * @brief Check if the vector instance is equal to a given second vector.
             * Compares all values within a given epsilon range.
             * @param v The vector to compare.
             * @param epsilon The epsilon to compare.
             * @return true if equal to the compared vector.
             */
            Bool IsEqual(const Vector& v, DataType epsilon) const
            {
                return ((Math::Abs(x - v.x) < epsilon) && (Math::Abs(y - v.y) < epsilon) &&
                        (Math::Abs(z - v.z) < epsilon) && (Math::Abs(w - v.w) < epsilon));
            }

            /**
             * @brief Get base vectors for this vector instance.
             * This method tries to calculate three direction vectors from
             * the current instance, so that they form an orthonormal base.
             * If the current vector has zero length, false is returned.
             * @param n1 Base vector 1
             * @param n2 Base vector 2
             * @param n3 Base vector 3
             * @return true if successful.
             */
            Bool GetBaseNormals(Vector& n1, Vector& n2, Vector& n3) const
            {
                if (IsZero())
                {
                    return false;
                }

                DataType ax = Math::Abs(x);
                DataType ay = Math::Abs(y);
                DataType az = Math::Abs(z);

                Vector v1;
                Vector v2;
                if (ax >= ay)
                {
                    if (ax >= az)
                    {
                        // X longest, YZ plane
                        v1.Set(0, 1, 0, 0);
                        v2.Set(0, 0, 1, 0);
                    }
                    else
                    {
                        // Z longest, XY plane
                        v1.Set(1, 0, 0, 0);
                        v2.Set(0, 1, 0, 0);
                    }
                }
                else
                {
                    if (ay >= az)
                    {
                        // Y longest, XZ plane
                        v1.Set(1, 0, 0, 0);
                        v2.Set(0, 0, 1, 0);
                    }
                    else
                    {
                        // Z longest, XY plane
                        v1.Set(1, 0, 0, 0);
                        v2.Set(0, 1, 0, 0);
                    }
                }

                n1 = Normalize();
                n1.w = 0;
                n2 = Cross(v1).Normalize();
                n3 = Cross(v2).Normalize();

                return true;
            }

            /**
             * @brief Equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Vector> class.
             * To compare within an epsilon range use Vector::IsEqual().
             * @param lhs The left hand side vector to compare.
             * @param rhs The right hand side vector to compare.
             * @return true if all components are exactly the same.
             */
            friend bool operator==(const Vector<DataType>& lhs, const Vector<DataType>& rhs)
            {
                return ((lhs.x == rhs.x) && (lhs.y == rhs.y) &&
                        (lhs.z == rhs.z) && (lhs.w == rhs.w));
            }

            /**
             * @brief Not equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Vector> class.
             * To compare within an epsilon range use Vector::IsEqual().
             * @param lhs The left hand side vector to compare.
             * @param rhs The right hand side vector to compare.
             * @return true if all components are not exactly the same.
             */
            friend bool operator!=(const Vector<DataType>& lhs, const Vector<DataType>& rhs)
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
                                           Double(x), Double(y), Double(z), Double(w));
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

        /**
         * @ingroup MurlMathClasses
         * @brief A 4-component uninitialized vector class.
         * This object can create arrays of uninitialized vector instances.
         */
        template<class DataType>
        class VectorUninitialized : public Vector<DataType>
        {
        public:
            /**
             * @brief The default constructor.
             * Create an uninitialized vector instance.
             */
            VectorUninitialized()
            : Vector<DataType>(Vector<DataType>::UNINITIALIZED)
            {
            }

            /**
             * @brief The copy constructor using a vector of different type.
             * @param v The vector to copy.
             */
            template<class DataType2>
            VectorUninitialized(const Vector<DataType2>& v)
            : Vector<DataType>(v)
            {
            }
        };
    }
}

#endif // __MURL_MATH_VECTOR_H__

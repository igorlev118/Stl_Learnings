// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_MATRIX_H__
#define __MURL_MATH_MATRIX_H__

#include "murl_math.h"

#include "murl_i_enums.h"
#include "murl_debug_assert.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;

        template<class DataType>
        class Quaternion;

        /**
         * @ingroup MurlMathClasses
         * @brief A 4x4 matrix class.
         */
        template<class DataType>
        class Matrix
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
                XX = 0, YX, ZX, WX,
                XY, YY, ZY, WY,
                XZ, YZ, ZZ, WZ,
                XW, YW, ZW, WW,
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

                /** XX component mask */
                MASK_XX      = (1 << XX),
                /** YX component mask */
                MASK_YX      = (1 << YX),
                /** ZX component mask */
                MASK_ZX      = (1 << ZX),
                /** WX component mask */
                MASK_WX      = (1 << WX),

                /** XY component mask */
                MASK_XY      = (1 << XY),
                /** YY component mask */
                MASK_YY      = (1 << YY),
                /** ZY component mask */
                MASK_ZY      = (1 << ZY),
                /** WY component mask */
                MASK_WY      = (1 << WY),

                /** XZ component mask */
                MASK_XZ      = (1 << XZ),
                /** YZ component mask */
                MASK_YZ      = (1 << YZ),
                /** ZZ component mask */
                MASK_ZZ      = (1 << ZZ),
                /** WZ component mask */
                MASK_WZ      = (1 << WZ),

                /** XW component mask */
                MASK_XW      = (1 << XW),
                /** YW component mask */
                MASK_YW      = (1 << YW),
                /** ZW component mask */
                MASK_ZW      = (1 << ZW),
                /** WW component mask */
                MASK_WW      = (1 << WW),

                /** All components */
                MASK_ALL    = (MASK_XX + MASK_YX + MASK_ZX + MASK_WX +
                               MASK_XY + MASK_YY + MASK_ZY + MASK_WY +
                               MASK_XZ + MASK_YZ + MASK_ZZ + MASK_WZ +
                               MASK_XW + MASK_YW + MASK_ZW + MASK_WW)
            };

            /**
             * @brief Enumeration of the predefined initialization types
             * for constructing a Matrix(PredefinedType type).
             */
            enum PredefinedType
            {
                /** Create an uninitialized instance. */
                UNINITIALIZED = 0,

                /** Initialize with zero. */
                ZERO,
                /** Initialize with the identity matrix. */
                IDENTITY
            };

            /**
             * @brief Enumeration of hint flags.
             * Hints are used internally to optimize several operations.
             */
            enum HintFlags
            {
                /** The matrix contains translation components. */
                FLAG_TRANSLATION    = (1 << 0),
                /** The matrix contains rotation components. */
                FLAG_ROTATION       = (1 << 1),
                /** The matrix contains scale components. */
                FLAG_SCALE          = (1 << 2),
                /** The matrix contains arbitrary components. */
                FLAG_ARBITRARY      = (1 << 3),

                /** The matrix has no component hints. */
                FLAG_NO_HINTS       = (1 << 8)
            };

        protected:
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
                    DataType xx, yx, zx, wx;
                    DataType xy, yy, zy, wy;
                    DataType xz, yz, zz, wz;
                    DataType xw, yw, zw, ww;
                };
            };

            /** The hint flags. */
            UInt32 mFlags;

        public:
            /**
             * @brief The default constructor, creating an identity matrix.
             * Hints are disabled by default.
             */
            Matrix()
            : mFlags(FLAG_NO_HINTS)
            {
                SetIdentity();
            }

            /**
             * @brief Constructor to create a matrix from a predefined type.
             * Hints are disabled by default.
             * @param type The predefined type.
             */
            Matrix(PredefinedType type)
            {
                switch (type)
                {
                    case UNINITIALIZED:
                        break;

                    case IDENTITY:
                        SetIdentity();
                        mFlags = FLAG_NO_HINTS;
                        break;

                    default:
                    case ZERO:
                        Clear();
                        mFlags = FLAG_NO_HINTS;
                        break;
                }
            }

            /**
             * @brief The copy constructor using a Matrix of different type.
             * @param matrix The Matrix to copy.
             */
            template<class DataType2>
            Matrix(const Matrix<DataType2>& matrix)
            : mFlags(matrix.GetHints())
            {
                for (UInt32 i = 0; i < NUM_COMPONENTS; i++)
                {
                    mComponents[i] = matrix.GetPointer()[i];
                }
            }

            /**
             * @brief Create a look-at matrix from a given center point, target point and up vector.
             * @param center The center point position vector.
             * @param target The target point position vector.
             * @param up The up direction vector.
             * @return The calculated matrix.
             */
            static Matrix LookAt(const Vector<DataType>& center, const Vector<DataType>& target, const Vector<DataType>& up)
            {
                Vector<DataType> f = (target - center).Normalize();
                Vector<DataType> p = up.Normalize();

                Vector<DataType> s = f.Cross(p).Normalize();
                Vector<DataType> u = s.Cross(f).Normalize();

                Matrix m(ZERO);

                m.SetXX(s.x);
                m.SetXY(s.y);
                m.SetXZ(s.z);

                m.SetYX(u.x);
                m.SetYY(u.y);
                m.SetYZ(u.z);

                m.SetZX(-f.x);
                m.SetZY(-f.y);
                m.SetZZ(-f.z);

                m.SetWW(Real(1.0));

                return m;
            }

            /**
             * @brief Get the hint flags.
             * @return The bit-mask of hints.
             */
            UInt32 GetHints() const
            {
                return mFlags;
            }

            /**
             * @brief Set the hint flags.
             * @param mask The bit-mask of hints to set.
             */
            void SetHints(UInt32 mask)
            {
                mFlags &= ~FLAG_NO_HINTS;
                mFlags |= mask;
            }

            /**
             * @brief Clear hint flags.
             * @param mask The bit-mask of hints to clear.
             */
            void ClearHints(UInt32 mask)
            {
                mFlags &= ~FLAG_NO_HINTS;
                mFlags &= ~mask;
            }

            /**
             * @brief Enable hints.
             * Enabling hints requires good knowlede of the entire Matrix class
             * e.g. several setter methods do not consider hints.
             * @param autoDetect Evaluate the correct hints if true.
             */
            void EnableHints(Bool autoDetect)
            {
                mFlags = 0;
                if (!autoDetect)
                {
                    return;
                }

                if ((wx != DataType(0.0)) ||
                    (wy != DataType(0.0)) ||
                    (wz != DataType(0.0)) ||
                    (ww != DataType(1.0)))
                {
                    mFlags |= FLAG_ARBITRARY;
                }

                if ((xw != DataType(0.0)) ||
                    (yw != DataType(0.0)) ||
                    (zw != DataType(0.0)))
                {
                    mFlags |= FLAG_TRANSLATION;
                }

                if ((xx != DataType(1.0)) ||
                    (xy != DataType(0.0)) ||
                    (xz != DataType(0.0)) ||
                    (yx != DataType(0.0)) ||
                    (yy != DataType(1.0)) ||
                    (yz != DataType(0.0)) ||
                    (zx != DataType(0.0)) ||
                    (zy != DataType(0.0)) ||
                    (zz != DataType(1.0)))
                {
                    mFlags |= FLAG_ROTATION | FLAG_SCALE;
                }
            }

            /**
             * @brief Disable hints.
             */
            void DisableHints()
            {
                mFlags = FLAG_NO_HINTS;
            }

            /**
             * @brief Get a component element.
             * @param index The component index, see enum #Component.
             * @return The component value.
             */
            DataType operator[](UInt32 index) const
            {
                MURL_ASSERT(index < NUM_COMPONENTS);
                return mComponents[index];
            }
            /**
             * @brief Get a writeable reference to a component element.
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
             * @brief Get a writeable pointer to the raw data.
             * @return Pointer to the raw data.
             */
            DataType* GetPointer()
            {
                return mComponents;
            }

            /**
             * @brief In-place matrix-matrix multiplication operator.
             * @param m The matrix to multiply.
             * @return The object itself.
             */
            Matrix& operator*=(const Matrix& m)
            {
                MultiplySelf(m);
                return *this;
            }

            /**
             * @brief Matrix-matrix multiplication operator.
             * @param rhs The right hand side matrix.
             * @return The multiplied matrix.
             */
            Matrix operator*(const Matrix& rhs) const
            {
                return Multiply(rhs);
            }

            /**
             * @brief Matrix-vector multiplication operator.
             * @param rhs The right hand side vector.
             * @return The multiplied vector.
             */
            Vector<DataType> operator*(const Vector<DataType>& rhs) const
            {
                return Multiply(rhs);
            }


            /**
             * @brief Clear all components of the matrix instance.
             * Set the component data array to zero.
             */
            void Clear()
            {
                Util::MemSet(mComponents, 0, sizeof(mComponents));
                mFlags &= ~(FLAG_TRANSLATION | FLAG_ROTATION | FLAG_SCALE | FLAG_ARBITRARY);
            }

            /**
             * @brief Load the identity matrix to the current instance.
             */
            void SetIdentity()
            {
                xx = 1; xy = 0; xz = 0; xw = 0;
                yx = 0; yy = 1; yz = 0; yw = 0;
                zx = 0; zy = 0; zz = 1; zw = 0;
                wx = 0; wy = 0; wz = 0; ww = 1;
                mFlags &= ~(FLAG_TRANSLATION | FLAG_ROTATION | FLAG_SCALE | FLAG_ARBITRARY);
            }

            /**
             * @brief Load the identity matrix to the upper 3x3 matrix
             */
            void SetIdentityRotation()
            {
                xx = 1; xy = 0; xz = 0;
                yx = 0; yy = 1; yz = 0;
                zx = 0; zy = 0; zz = 1;
                mFlags &= ~(FLAG_ROTATION | FLAG_SCALE);
            }

            /**
             * @brief Copy the content of a source matrix to the matrix instance.
             * @param m The matrix to copy from.
             */
            void Set(const Matrix& m)
            {
                *this = m;
            }

            /**
             * @brief Set the translation component to a given vector.
             * @param v The vector to set the translation component.
             */
            void SetTranslationComponent(const Vector<DataType>& v)
            {
                SetTranslationComponent(v.x, v.y, v.z);
            }

            /**
             * @brief Set the translation component to given values.
             * @param x The X translation component.
             * @param y The Y translation component.
             * @param z The Z translation component.
             */
            void SetTranslationComponent(DataType x, DataType y, DataType z)
            {
                xw = x;
                yw = y;
                zw = z;

                if ((x == DataType(0.0)) &&
                    (y == DataType(0.0)) &&
                    (z == DataType(0.0)))
                {
                    mFlags &= ~FLAG_TRANSLATION;
                }
                else
                {
                    mFlags |= FLAG_TRANSLATION;
                }
            }

            /**
             * @brief Set the translation X component.
             * @param x The X translation component.
             */
            void SetTranslationComponentX(DataType x)
            {
                xw = x;

                if ((xw == DataType(0.0)) &&
                    (yw == DataType(0.0)) &&
                    (zw == DataType(0.0)))
                {
                    mFlags &= ~FLAG_TRANSLATION;
                }
                else
                {
                    mFlags |= FLAG_TRANSLATION;
                }
            }

            /**
             * @brief Set the translation Y component.
             * @param y The Y translation component.
             */
            void SetTranslationComponentY(DataType y)
            {
                yw = y;

                if ((xw == DataType(0.0)) &&
                    (yw == DataType(0.0)) &&
                    (zw == DataType(0.0)))
                {
                    mFlags &= ~FLAG_TRANSLATION;
                }
                else
                {
                    mFlags |= FLAG_TRANSLATION;
                }
            }

            /**
             * @brief Set the translation Z component.
             * @param z The Z translation component.
             */
            void SetTranslationComponentZ(DataType z)
            {
                zw = z;

                if ((xw == DataType(0.0)) &&
                    (yw == DataType(0.0)) &&
                    (zw == DataType(0.0)))
                {
                    mFlags &= ~FLAG_TRANSLATION;
                }
                else
                {
                    mFlags |= FLAG_TRANSLATION;
                }
            }

            /**
             * @brief Get the translation component vector.
             * @return The translation component vector.
             */
            const Vector<DataType>& GetTranslationComponent() const
            {
                return reinterpret_cast<const Vector<DataType>&>(xw);
            }

            /**
             * @brief Get the translation component's X value.
             * @return The X value.
             */
            DataType GetTranslationComponentX() const
            {
                return xw;
            }

            /**
             * @brief Get the translation component's Y value.
             * @return The Y value.
             */
            DataType GetTranslationComponentY() const
            {
                return yw;
            }

            /**
             * @brief Get the translation component's Z value.
             * @return The Z value.
             */
            DataType GetTranslationComponentZ() const
            {
                return zw;
            }

            /**
             * @brief Set the scaling component using a vector.
             * This method only sets the upper 3 diagonal elements of the matrix,
             * so it should only be applied to matrices without rotation.
             * @param v The vector containing X, Y and Z scaling components.
             */
            void SetScalingComponent(const Vector<DataType>& v)
            {
                SetScalingComponent(v.x, v.y, v.z);
            }

            /**
             * @brief Set the scaling component using three distinct values.
             * This method only sets the upper 3 diagonal elements of the matrix,
             * so it should only be applied to matrices without rotation.
             * @param x The X scaling factor.
             * @param y The Y scaling factor.
             * @param z The Z scaling factor.
             */
            void SetScalingComponent(DataType x, DataType y, DataType z)
            {
                xx = x;
                yy = y;
                zz = z;

                if ((x == DataType(1.0)) &&
                    (y == DataType(1.0)) &&
                    (z == DataType(1.0)))
                {
                    mFlags &= ~FLAG_SCALE;
                }
                else
                {
                    mFlags |= FLAG_SCALE;
                }
            }

            /**
             * @brief Get a vector containing the X, Y and Z scaling components of the matrix.
             * @return The scaling components.
             */
            Vector<DataType> GetScalingComponent() const
            {
                Vector<DataType> s;
                s.x = Sqrt(DataType(DataType(xx * xx) + DataType(yx * yx)) + DataType(zx * zx));
                s.y = Sqrt(DataType(DataType(xy * xy) + DataType(yy * yy)) + DataType(zy * zy));
                s.z = Sqrt(DataType(DataType(xz * xz) + DataType(yz * yz)) + DataType(zz * zz));
                s.w = DataType(0.0);
                return s;
            }

            /**
             * @brief Get the X scale value of the matrix.
             * @return The X scale value.
             */
            DataType GetScalingComponentX() const
            {
                return Sqrt(DataType(DataType(xx * xx) + DataType(yx * yx)) + DataType(zx * zx));
            }

            /**
             * @brief Get the Y scale value of the matrix.
             * @return The Y scale value.
             */
            DataType GetScalingComponentY() const
            {
                return Sqrt(DataType(DataType(xy * xy) + DataType(yy * yy)) + DataType(zy * zy));
            }

            /**
             * @brief Get the Z scale value of the matrix.
             * @return The Z scale value.
             */
            DataType GetScalingComponentZ() const
            {
                return Sqrt(DataType(DataType(xz * xz) + DataType(yz * yz)) + DataType(zz * zz));
            }

            /**
             * @brief Set the rotation component by a vector.
             * @param axisAngle The vector of the rotation including
             *  the angle in w component in radiants.
             */
            void SetRotationComponent(const Vector<DataType>& axisAngle)
            {
                SetRotationComponentAxisAngle(axisAngle.w, axisAngle.x, axisAngle.y, axisAngle.z);
            }

            /**
             * @brief Set the rotation component by an angle and vector.
             * @param angle The angle of the rotation in radiants.
             * @param axis The vector of the rotation.
             */
            void SetRotationComponent(DataType angle, const Vector<DataType>& axis)
            {
                SetRotationComponentAxisAngle(angle, axis.x, axis.y, axis.z);
            }

            /**
             * @brief Set the rotation component by an angle and vector components.
             * @param angle The angle of the rotation in radiants.
             * @param ax The x-component of the rotation vector.
             * @param ay The y-component of the rotation vector.
             * @param az The z-component of the rotation vector.
             */
            void SetRotationComponentAxisAngle(DataType angle, DataType ax, DataType ay, DataType az)
            {
                if (angle == DataType(0.0))
                {
                    SetIdentityRotation();
                    return;
                }

                DataType sa = Sin(angle);
                DataType ca = Cos(angle);
                DataType nca = DataType(1) - ca;

                xx = DataType(DataType(ax*ax) * nca) + ca;
                yx = DataType(DataType(ax*ay) * nca) + DataType(az * sa);
                zx = DataType(DataType(ax*az) * nca) - DataType(ay * sa);

                xy = DataType(DataType(ay*ax) * nca) - DataType(az * sa);
                yy = DataType(DataType(ay*ay) * nca) + ca;
                zy = DataType(DataType(ay*az) * nca) + DataType(ax * sa);

                xz = DataType(DataType(az*ax) * nca) + DataType(ay * sa);
                yz = DataType(DataType(az*ay) * nca) - DataType(ax * sa);
                zz = DataType(DataType(az*az) * nca) + ca;

                mFlags |= FLAG_ROTATION;
                mFlags &= ~FLAG_SCALE;
            }

            /**
             * @brief Set the rotation component by euler angles.
             * The default axis rotation order is IEnums::ROTATION_ORDER_ZYX.
             * @param angleX The x-axis angle in radiants.
             * @param angleY The y-axis angle in radiants.
             * @param angleZ The z-axis angle in radiants.
             */
            void SetRotationComponent(DataType angleX, DataType angleY, DataType angleZ)
            {
                SetRotationComponentXYZ(angleX, angleY, angleZ, IEnums::ROTATION_ORDER_ZYX);
            }

            /**
             * @brief Set the rotation component by euler angles with a given rotation order.
             * @param angles A vector containing the X, Y and Z angles in radiants.
             * @param rotationOrder The axis rotation order.
             */
            void SetRotationComponentXYZ(const Vector<DataType>& angles,
                                         IEnums::RotationOrder rotationOrder)
            {
                SetRotationComponentXYZ(angles.x, angles.y, angles.z, rotationOrder);
            }

            /**
             * @brief Set the rotation component by euler angles with a given rotation order.
             * @param angleX The x-axis angle in radiants.
             * @param angleY The y-axis angle in radiants.
             * @param angleZ The z-axis angle in radiants.
             * @param rotationOrder The axis rotation order.
             */
            void SetRotationComponentXYZ(DataType angleX, DataType angleY, DataType angleZ,
                                         IEnums::RotationOrder rotationOrder)
            {
                if ((angleX == DataType(0.0)) &&
                    (angleY == DataType(0.0)) &&
                    (angleZ == DataType(0.0)))
                {
                    SetIdentityRotation();
                    return;
                }

                DataType sx = Sin(angleX);
                DataType cx = Cos(angleX);
                DataType sy = Sin(angleY);
                DataType cy = Cos(angleY);
                DataType sz = Sin(angleZ);
                DataType cz = Cos(angleZ);

                switch (rotationOrder)
                {
                    default:
                    case IEnums::ROTATION_ORDER_ZYX:
                    {
                        DataType s1 = sz;
                        DataType c1 = cz;
                        DataType s2 = sy;
                        DataType c2 = cy;
                        DataType s3 = sx;
                        DataType c3 = cx;

                        xx =  DataType(c1 * c2);
                        xy =  DataType(DataType(c1 * s2) * s3) - DataType(c3 * s1);
                        xz =  DataType(s1 * s3) + DataType(DataType(c1 * c3) * s2);

                        yx =  DataType(c2 * s1);
                        yy =  DataType(c1 * c3) + DataType(DataType(s1 * s2) * s3);
                        yz =  DataType(DataType(c3 * s1) * s2) - DataType(c1 * s3);

                        zx = -DataType(s2);
                        zy =  DataType(c2 * s3);
                        zz =  DataType(c2 * c3);

                        break;
                    }

                    case IEnums::ROTATION_ORDER_ZXY:
                    {
                        DataType s1 = sz;
                        DataType c1 = cz;
                        DataType s2 = sx;
                        DataType c2 = cx;
                        DataType s3 = sy;
                        DataType c3 = cy;

                        xx =  DataType(c1 * c3) - DataType(DataType(s1 * s2) * s3);
                        xy = -DataType(c2 * s1);
                        xz =  DataType(c1 * s3) + DataType(DataType(c3 * s1) * s2);

                        yx =  DataType(c3 * s1) + DataType(DataType(c1 * s2) * s3);
                        yy =  DataType(c1 * c2);
                        yz =  DataType(s1 * s3) - DataType(DataType(c1 * c3) * s2);

                        zx = -DataType(c2 * s3);
                        zy =  DataType(s2);
                        zz =  DataType(c2 * c3);

                        break;
                    }

                    case IEnums::ROTATION_ORDER_YZX:
                    {
                        DataType s1 = sy;
                        DataType c1 = cy;
                        DataType s2 = sz;
                        DataType c2 = cz;
                        DataType s3 = sx;
                        DataType c3 = cx;

                        xx =  DataType(c1 * c2);
                        xy =  DataType(s1 * s3) - DataType(DataType(c1 * c3) * s2);
                        xz =  DataType(c3 * s1) + DataType(DataType(c1 * s2) * s3);

                        yx =  DataType(s2);
                        yy =  DataType(c2 * c3);
                        yz = -DataType(c2 * s3);

                        zx = -DataType(c2 * s1);
                        zy =  DataType(c1 * s3) + DataType(DataType(c3 * s1) * s2);
                        zz =  DataType(c1 * c3) - DataType(DataType(s1 * s2) * s3);

                        break;
                    }

                    case IEnums::ROTATION_ORDER_YXZ:
                    {
                        DataType s1 = sy;
                        DataType c1 = cy;
                        DataType s2 = sx;
                        DataType c2 = cx;
                        DataType s3 = sz;
                        DataType c3 = cz;

                        xx =  DataType(c1 * c3) + DataType(DataType(s1 * s2) * s3);
                        xy =  DataType(DataType(c3 * s1) * s2) - DataType(c1 * s3);
                        xz =  DataType(c2 * s1);

                        yx =  DataType(c2 * s3);
                        yy =  DataType(c2 * c3);
                        yz = -DataType(s2);

                        zx =  DataType(DataType(c1 * s2) * s3) - DataType(c3 * s1);
                        zy =  DataType(DataType(c1 * c3) * s2) + DataType(s1 * s3);
                        zz =  DataType(c1 * c2);

                        break;
                    }

                    case IEnums::ROTATION_ORDER_XZY:
                    {
                        DataType s1 = sx;
                        DataType c1 = cx;
                        DataType s2 = sz;
                        DataType c2 = cz;
                        DataType s3 = sy;
                        DataType c3 = cy;

                        xx =  DataType(c2 * c3);
                        xy = -DataType(s2);
                        xz =  DataType(c2 * s3);

                        yx =  DataType(s1 * s3) + DataType(DataType(c1 * c3) * s2);
                        yy =  DataType(c1 * c2);
                        yz =  DataType(DataType(c1 * s2) * s3) - DataType(c3 * s1);

                        zx =  DataType(DataType(c3 * s1) * s2) - DataType(c1 * s3);
                        zy =  DataType(c2 * s1);
                        zz =  DataType(c1 * c3) + DataType(DataType(s1 * s2) * s3);

                        break;
                    }

                    case IEnums::ROTATION_ORDER_XYZ:
                    {
                        DataType s1 = sx;
                        DataType c1 = cx;
                        DataType s2 = sy;
                        DataType c2 = cy;
                        DataType s3 = sz;
                        DataType c3 = cz;

                        xx =  DataType(c2 * c3);
                        xy = -DataType(c2 * s3);
                        xz =  DataType(s2);

                        yx =  DataType(c1 * s3) + DataType(DataType(c3 * s1) * s2);
                        yy =  DataType(c1 * c3) - DataType(DataType(s1 * s2) * s3);
                        yz = -DataType(c2 * s1);

                        zx =  DataType(s1 * s3) - DataType(DataType(c1 * c3) * s2);
                        zy =  DataType(c3 * s1) + DataType(DataType(c1 * s2) * s3);
                        zz =  DataType(c1 * c2);

                        break;
                    }
                }

                mFlags |= FLAG_ROTATION;
                mFlags &= ~FLAG_SCALE;
            }

            /**
             * @brief Set the rotation component of the transformation matrix to only rotate around the X axis.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and applying a rotation around the unit X axis. The angle value must be given in
             * radians. A positive value result in a clockwise rotation.
             * @param angleX The x-axis angle in radiants.
             */
            void SetRotationComponentX(DataType angleX)
            {
                if (angleX == DataType(0.0))
                {
                    SetIdentityRotation();
                    return;
                }

                DataType sx = Sin(angleX);
                DataType cx = Cos(angleX);

                xx = 1;
                xy = 0;
                xz = 0;

                yx = 0;
                yy = cx;
                yz = -sx;

                zx = 0;
                zy = sx;
                zz = cx;

                mFlags |= FLAG_ROTATION;
                mFlags &= ~FLAG_SCALE;
            }

            /**
             * @brief Set the rotation component of the transformation matrix to only rotate around the Y axis.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and applying a rotation around the unit Y axis. The angle value must be given in
             * radians. A positive value result in a clockwise rotation.
             * @param angleY The y-axis angle in radiants.
             */
            void SetRotationComponentY(DataType angleY)
            {
                if (angleY == DataType(0.0))
                {
                    SetIdentityRotation();
                    return;
                }

                DataType sy = Sin(angleY);
                DataType cy = Cos(angleY);

                xx = cy;
                xy = 0;
                xz = sy;

                yx = 0;
                yy = 1;
                yz = 0;

                zx = -sy;
                zy = 0;
                zz = cy;

                mFlags |= FLAG_ROTATION;
                mFlags &= ~FLAG_SCALE;
            }

            /**
             * @brief Set the rotation component of the transformation matrix to only rotate around the Z axis.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and applying a rotation around the unit Z axis. The angle value must be given in
             * radians. A positive value result in a clockwise rotation.
             * @param angleZ The z-axis angle in radiants.
             */
            void SetRotationComponentZ(DataType angleZ)
            {
                if (angleZ == DataType(0.0))
                {
                    SetIdentityRotation();
                    return;
                }

                DataType sz = Sin(angleZ);
                DataType cz = Cos(angleZ);

                xx = cz;
                xy = -sz;
                xz = 0;

                yx = sz;
                yy = cz;
                yz = 0;

                zx = 0;
                zy = 0;
                zz = 1;

                mFlags |= FLAG_ROTATION;
                mFlags &= ~FLAG_SCALE;
            }

            /**
             * @brief Get the euler rotation angles.
             * Extract the euer rotation angles based on
             *  https://d3cw3dd2w32x2b.cloudfront.net/wp-content/uploads/2012/07/euler-angles.pdf
             * @return The euler rotation angles in radiants.
             *  The vector members x, y and z corresponds to the axis angles.
             */
            Vector<DataType> GetEulerRotation() const
            {
                Vector<DataType> ret;

                ret.x = ArcTan2(zy, zz);

                Real c2 = Sqrt(xx * xx + yx * yx);
                ret.y = ArcTan2<DataType>(-zx, c2);

                Real s1 = Sin(ret.x);
                Real c1 = Cos(ret.x);
                ret.z = ArcTan2(s1 * xz - c1 * xy, c1 * yy - s1 * yz);

                return ret;
            }

            /**
             * @brief Set the rotation component by a quaternion.
             * @param q The quaternion.
             */
            void SetRotationComponent(const Quaternion<DataType>& q)
            {
                DataType vxvx2 = DataType(2) * DataType(q.i * q.i);
                DataType vyvy2 = DataType(2) * DataType(q.j * q.j);
                DataType vzvz2 = DataType(2) * DataType(q.k * q.k);

                DataType vxvy2 = DataType(2) * DataType(q.i * q.j);
                DataType vxvz2 = DataType(2) * DataType(q.i * q.k);
                DataType vyvz2 = DataType(2) * DataType(q.j * q.k);

                DataType svx2  = DataType(2) * DataType(q.r * q.i);
                DataType svy2  = DataType(2) * DataType(q.r * q.j);
                DataType svz2  = DataType(2) * DataType(q.r * q.k);

                xx = DataType(1) - DataType(vyvy2 + vzvz2);
                xy = DataType(vxvy2 - svz2);
                xz = DataType(vxvz2 + svy2);

                yx = DataType(vxvy2 + svz2);
                yy = DataType(1) - DataType(vxvx2 + vzvz2);
                yz = DataType(vyvz2 - svx2);

                zx = DataType(vxvz2 - svy2);
                zy = DataType(vyvz2 + svx2);
                zz = DataType(1) - DataType(vxvx2 + vyvy2);

                mFlags |= FLAG_ROTATION;
                mFlags &= ~FLAG_SCALE;
            }

            /**
             * @brief Set the rotation component by a rotation matrix.
             * @param rotationMatrix The rotation matrix.
             */
            void SetRotationComponent(const Matrix<DataType>& rotationMatrix)
            {
                xx = rotationMatrix.xx;
                yx = rotationMatrix.yx;
                zx = rotationMatrix.zx;

                xy = rotationMatrix.xy;
                yy = rotationMatrix.yy;
                zy = rotationMatrix.zy;

                xz = rotationMatrix.xz;
                yz = rotationMatrix.yz;
                zz = rotationMatrix.zz;

                mFlags &= ~(FLAG_ROTATION | FLAG_SCALE);
                mFlags |= (rotationMatrix.mFlags & (FLAG_ROTATION | FLAG_SCALE));
            }

            /**
             * @brief Extract the rotation and scaling component of the matrix.
             * @return A matrix containing only scaling and rotation.
             */
            Matrix<DataType> GetRotationAndScalingComponent()
            {
                Matrix m;

                m.xx = xx;
                m.yx = yx;
                m.zx = zx;
                m.wx = DataType(0.0);

                m.xy = xy;
                m.yy = yy;
                m.zy = zy;
                m.wy = DataType(0.0);

                m.xz = xz;
                m.yz = yz;
                m.zz = zz;
                m.wz = DataType(0.0);

                m.xw = DataType(0.0);
                m.yw = DataType(0.0);
                m.zw = DataType(0.0);
                m.ww = DataType(1.0);

                m.mFlags = mFlags & ~FLAG_TRANSLATION;
                return m;
            }

            /**
             * @brief Get the vector of a specified column.
             * @param columnIndex The column index in range [0 .. 3].
             * @return The vector of the colum at the specified index.
             */
            const Vector<DataType>& GetColumnVector(UInt32 columnIndex) const
            {
                MURL_ASSERT(columnIndex < 4);
                return reinterpret_cast<const Vector<DataType>& >(mComponents[columnIndex * 4]);
            }

            /**
             * @brief Set a specified column by a vector.
             * Hints are not considered.
             * @param columnIndex The column index in range [0 .. 3].
             * @param vec The vector to set the colum at the specified index.
             */
            void SetColumnVector(UInt32 columnIndex, const Vector<DataType>& vec)
            {
                if (MURL_VERIFY(columnIndex < 4))
                {
                    reinterpret_cast<Vector<DataType>& >(mComponents[columnIndex * 4]) = vec;
                }
            }

            /**
             * @brief Get the vector of a specified row.
             * @param rowIndex The row index in range [0 .. 3].
             * @return The vector of the row at the specified index.
             */
            Vector<DataType> GetRowVector(UInt32 rowIndex) const
            {
                MURL_ASSERT(rowIndex < 4);

                Vector<DataType> v;
                v.x = mComponents[rowIndex];
                v.y = mComponents[rowIndex + 4];
                v.z = mComponents[rowIndex + 8];
                v.w = mComponents[rowIndex + 12];

                return v;
            }

            /**
             * @brief Set a specified row by a vector.
             * Hints are not considered.
             * @param rowIndex The row index in range [0 .. 3].
             * @param vec The vector to set the row at the specified index.
             */
            void SetRowVector(UInt32 rowIndex, const Vector<DataType> vec)
            {
                if (MURL_VERIFY(rowIndex < 4))
                {
                    mComponents[rowIndex] = vec.x;
                    mComponents[rowIndex + 4] = vec.y;
                    mComponents[rowIndex + 8] = vec.z;
                    mComponents[rowIndex + 12] = vec.w;
                }
            }

            /**
             * @brief In-place matrix-matrix multiplication.
             * @param m The matrix to multiply.
             */
            void MultiplySelf(const Matrix& m)
            {
                Set(Multiply(m));
            }

            /**
             * @brief In-place reverse matrix-matrix multiplication.
             * @param m The matrix to multiply.
             */
            void MultiplySelfReverse(const Matrix& m)
            {
                Set(m.Multiply(*this));
            }

            /**
             * @brief In-place transpose of the matrix.
             */
            void TransposeSelf()
            {
                for (UInt32 i = 0; i < 4; i++)
                {
                    for (UInt32 j = i + 1; j < 4; j++)
                    {
                        DataType& v1 = mComponents[i * 4 + j];
                        DataType& v2 = mComponents[j * 4 + i];

                        DataType h = v1;
                        v1 = v2;
                        v2 = h;
                    }
                }
                mFlags |= FLAG_ARBITRARY;
            }

            /**
             * @brief In-place inversion of the matrix.
             */
            void InvertSelf()
            {
                Set(Invert());
            }

            /**
             * @brief Transform (multiply) a vector by the matrix.
             * @param v The vector to mulitply.
             * @return The multiplied vector.
             */
            Vector<DataType> Transform(const Vector<DataType>& v) const
            {
                return Multiply(v);
            }

            /**
             * @brief Rotate a vector by the matrix.
             * @param v The vector to rotate.
             * @return The rotated vector.
             */
            Vector<DataType> Rotate(const Vector<DataType>& v) const
            {
                Vector<DataType> n(Vector<DataType>::UNINITIALIZED);

                n.x = DataType(DataType(xx * v.x) + DataType(xy * v.y)) + DataType(xz * v.z);
                n.y = DataType(DataType(yx * v.x) + DataType(yy * v.y)) + DataType(yz * v.z);
                n.z = DataType(DataType(zx * v.x) + DataType(zy * v.y)) + DataType(zz * v.z);
                n.w = v.w;

                return n;
            }

            /**
             * @brief Translate a vector by the matrix (add the translation component).
             * @param v The vector to translate.
             * @return The translated vector.
             */
            Vector<DataType> Translate(const Vector<DataType>& v) const
            {
                return Vector<DataType>(xw + v.x, yw + v.y, zw + v.z, v.w);
            }

            /**
             * @brief Multiply a matrix by the matrix.
             * @param m The matrix to mulitply.
             * @return The multiplied matrix.
             */
            Matrix Multiply(const Matrix& m) const
            {
                if (mFlags == 0)
                {
                    // Self identity
                    return m;
                }
                if (m.mFlags == 0)
                {
                    // Other identity
                    return *this;
                }

                if ((mFlags == FLAG_TRANSLATION) && (m.mFlags == FLAG_TRANSLATION))
                {
                    Matrix n;

                    n.xw = xw + m.xw;
                    n.yw = yw + m.yw;
                    n.zw = zw + m.zw;
                    n.mFlags = mFlags;
                    return n;
                }

                Matrix n(UNINITIALIZED);

                n.xx = DataType(DataType(xx * m.xx) + DataType(xy * m.yx)) + DataType(DataType(xz * m.zx) + DataType(xw * m.wx));
                n.yx = DataType(DataType(yx * m.xx) + DataType(yy * m.yx)) + DataType(DataType(yz * m.zx) + DataType(yw * m.wx));
                n.zx = DataType(DataType(zx * m.xx) + DataType(zy * m.yx)) + DataType(DataType(zz * m.zx) + DataType(zw * m.wx));
                n.wx = DataType(DataType(wx * m.xx) + DataType(wy * m.yx)) + DataType(DataType(wz * m.zx) + DataType(ww * m.wx));

                n.xy = DataType(DataType(xx * m.xy) + DataType(xy * m.yy)) + DataType(DataType(xz * m.zy) + DataType(xw * m.wy));
                n.yy = DataType(DataType(yx * m.xy) + DataType(yy * m.yy)) + DataType(DataType(yz * m.zy) + DataType(yw * m.wy));
                n.zy = DataType(DataType(zx * m.xy) + DataType(zy * m.yy)) + DataType(DataType(zz * m.zy) + DataType(zw * m.wy));
                n.wy = DataType(DataType(wx * m.xy) + DataType(wy * m.yy)) + DataType(DataType(wz * m.zy) + DataType(ww * m.wy));

                n.xz = DataType(DataType(xx * m.xz) + DataType(xy * m.yz)) + DataType(DataType(xz * m.zz) + DataType(xw * m.wz));
                n.yz = DataType(DataType(yx * m.xz) + DataType(yy * m.yz)) + DataType(DataType(yz * m.zz) + DataType(yw * m.wz));
                n.zz = DataType(DataType(zx * m.xz) + DataType(zy * m.yz)) + DataType(DataType(zz * m.zz) + DataType(zw * m.wz));
                n.wz = DataType(DataType(wx * m.xz) + DataType(wy * m.yz)) + DataType(DataType(wz * m.zz) + DataType(ww * m.wz));

                n.xw = DataType(DataType(xx * m.xw) + DataType(xy * m.yw)) + DataType(DataType(xz * m.zw) + DataType(xw * m.ww));
                n.yw = DataType(DataType(yx * m.xw) + DataType(yy * m.yw)) + DataType(DataType(yz * m.zw) + DataType(yw * m.ww));
                n.zw = DataType(DataType(zx * m.xw) + DataType(zy * m.yw)) + DataType(DataType(zz * m.zw) + DataType(zw * m.ww));
                n.ww = DataType(DataType(wx * m.xw) + DataType(wy * m.yw)) + DataType(DataType(wz * m.zw) + DataType(ww * m.ww));

                n.mFlags = (mFlags | m.mFlags);
                return n;
            }

            /**
             * @brief Multiply a vector by the matrix.
             * @param v The vector to mulitply.
             * @return The multiplied vector.
             */
            Vector<DataType> Multiply(const Vector<DataType>& v) const
            {
                Vector<DataType> n(Vector<DataType>::UNINITIALIZED);

                if (mFlags == 0)
                {
                    // Self identity
                    return v;
                }
                if (mFlags == FLAG_TRANSLATION)
                {
                    if (v.w == 0.0)
                    {
                        return v;
                    }

                    n.x = v.x + xw;
                    n.y = v.y + yw;
                    n.z = v.z + zw;
                    n.w = 1.0;
                    return n;
                }

                n.x = DataType(DataType(xx * v.x) + DataType(xy * v.y)) + DataType(DataType(xz * v.z) + DataType(xw * v.w));
                n.y = DataType(DataType(yx * v.x) + DataType(yy * v.y)) + DataType(DataType(yz * v.z) + DataType(yw * v.w));
                n.z = DataType(DataType(zx * v.x) + DataType(zy * v.y)) + DataType(DataType(zz * v.z) + DataType(zw * v.w));
                n.w = DataType(DataType(wx * v.x) + DataType(wy * v.y)) + DataType(DataType(wz * v.z) + DataType(ww * v.w));

                return n;
            }

            /**
             * @brief Get the transposed matrix.
             * @return The transposed matrix.
             */
            Matrix Transpose() const
            {
                Matrix n;

                for (UInt32 i = 0; i < 4; i++)
                {
                    for (UInt32 j = 0; j < 4; j++)
                    {
                        n[i + j * 4] = (*this)[j + i * 4];
                    }
                }

                n.mFlags |= FLAG_ARBITRARY;
                return n;
            }

            /**
             * @brief Fast inversion of a rotation/translation matrix.
             * This method can be used to quickly invert a given matrix that is only made up
             * from rotation and translation operations. If the matrix also contains any
             * scaling operations, use InvertTransRotScl() instead. For general 4x4 matrices,
             * use Invert().
             * @return The inverted rotation/translation matrix.
             */
            Matrix InvertTransRot() const
            {
                // Only for pure rotation & translation matrices!
                DataType ixw = -xw;
                DataType iyw = -yw;
                DataType izw = -zw;
                Matrix n;

                n.xx = xx;
                n.yx = xy;
                n.zx = xz;
                n.wx = 0;

                n.xy = yx;
                n.yy = yy;
                n.zy = yz;
                n.wy = 0;

                n.xz = zx;
                n.yz = zy;
                n.zz = zz;
                n.wz = 0;

                n.xw = DataType(DataType(xx * ixw) + DataType(yx * iyw)) + DataType(zx * izw);
                n.yw = DataType(DataType(xy * ixw) + DataType(yy * iyw)) + DataType(zy * izw);
                n.zw = DataType(DataType(xz * ixw) + DataType(yz * iyw)) + DataType(zz * izw);
                n.ww = 1;

                n.mFlags = mFlags;
                return n;
            }

            /**
             * @brief Fast inversion of a rotation/translation/scaling matrix.
             * This method can be used to quickly invert a given matrix that is only made up
             * from rotation, translation and scaling operations. If only rotation and translation
             * is present, use InvertTransRot(). For general 4x4 matrices, use Invert() instead.
             * @return The inverted rotation/translation/scaling matrix.
             */
            Matrix InvertTransRotScl() const
            {
                // Only for pure rotation, translation & scaling matrices!
                DataType sx = DataType(DataType(xx * xx) + DataType(yx * yx)) + DataType(zx * zx);
                DataType sy = DataType(DataType(xy * xy) + DataType(yy * yy)) + DataType(zy * zy);
                DataType sz = DataType(DataType(xz * xz) + DataType(yz * yz)) + DataType(zz * zz);
                DataType dx = DataType(1) / sx;
                DataType dy = DataType(1) / sy;
                DataType dz = DataType(1) / sz;

                DataType tx = -xw;
                DataType ty = -yw;
                DataType tz = -zw;

                Matrix n;

                n.xx = xx * dx;
                n.yx = xy * dy;
                n.zx = xz * dz;
                n.wx = 0;

                n.xy = yx * dx;
                n.yy = yy * dy;
                n.zy = yz * dz;
                n.wy = 0;

                n.xz = zx * dx;
                n.yz = zy * dy;
                n.zz = zz * dz;
                n.wz = 0;

                n.xw = DataType(DataType(n.xx * tx) + DataType(n.xy * ty)) + DataType(n.xz * tz);
                n.yw = DataType(DataType(n.yx * tx) + DataType(n.yy * ty)) + DataType(n.yz * tz);
                n.zw = DataType(DataType(n.zx * tx) + DataType(n.zy * ty)) + DataType(n.zz * tz);
                n.ww = 1;

                n.mFlags = mFlags;
                return n;
            }

            /**
             * @brief Matrix inversion.
             * This method can be used to calculate the inverse of a general 4x4 matrix.
             * In case the matrix is only made up from rotation and translation operations,
             * it is possible to use InvertTransRot() instead. If it also contains additional
             * scaling operations, InvertTransRotScl() can be used; both alternative methods
             * show better overall performance.
             * @return The inverted matrix.
             */
            Matrix Invert() const
            {
                const DataType epsilon = Limits<DataType>::Epsilon();
                Matrix nm;

                const UInt32 n = 4;
                UInt32 i, j;
                UInt32 s;
                UInt32 prow;
                SInt32 pivot = 1;
                DataType f, maximum;

                // Horizontally append the identity matrix to the input matrix
                DataType a[n][2 * n];
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        a[i][j] = GetElementAt(i, j);
                        a[i][j + n] = (i == j) ? 1 : 0;
                    }
                }

                // Elimination
                s = 0;
                do
                {
                    maximum = Abs(a[s][s]);
                    if (pivot)
                    {
                        prow = s;
                        for (i = s + 1; i < n; i++)
                        {
                            if (Abs(a[i][s]) > maximum)
                            {
                                maximum = Abs(a[i][s]);
                                prow = i;
                            }
                        }
                    }

                    if (maximum < epsilon)
                    {
                        break;
                    }

                    if (pivot)
                    {
                        if (prow != s)  // swap rows if necessary
                        {
                            DataType h;
                            for (j = s; j < 2 * n; j++)
                            {
                                h = a[s][j];
                                a[s][j] = a[prow][j];
                                a[prow][j]= h;
                            }
                        }
                    }

                    f = a[s][s];
                    for (j = s; j < 2 * n; j++)
                    {
                        a[s][j] = a[s][j] / f;
                    }

                    for (i = 0; i < n; i++ )
                    {
                        if (i != s)
                        {
                            f = -a[i][s];
                            for (j = s; j < 2 * n ; j++)
                            {
                                a[i][j] += f*a[s][j];
                            }
                        }
                    }

                    s++;
                }
                while (s < n);

                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        nm.SetElementAt(i, j, a[i][j + n]);
                    }
                }

                nm.mFlags |= FLAG_ARBITRARY;
                return nm;
            }

            /**
             * @brief Solve the matrix by a vector.
             * @param v The vector to solve.
             * @return The solved vector.
             */
            Vector<DataType> Solve(const Vector<DataType>& v) const
            {
                const DataType epsilon = Limits<DataType>::Epsilon();

                const UInt32 n = 4;
                SInt32 i, j;
                SInt32 s;
                SInt32 r;
                DataType f;
                DataType maximum;

                DataType a[4][5];
                Vector<DataType> l;

                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        a[i][j] = GetElementAt(i, j);
                    }
                }
                for (i = 0; i < n; i++)
                {
                    a[i][n] = v.mComponents[i];
                }

                s = 0;
                do
                {
                    maximum = Abs(a[s][s]);
                    r = s;

                    for (i = (s + 1); i < n; i++)
                    {
                        if (Abs(a[i][s]) > maximum)
                        {
                            maximum = Abs(a[i][s]);
                            r = i;
                        }
                    }

                    if (maximum < epsilon)
                    {
                        return l;
                    }

                    if (r != s)
                    {
                        DataType h;

                        for (j = s; j <= n; j++)
                        {
                            h = a[s][j];
                            a[s][j] = a[r][j];
                            a[r][j]= h;
                        }
                    }

                    for (i = (s + 1); i < n; i++)
                    {
                        f = -(a[i][s] / a[s][s]);
                        a[i][s] = 0;

                        for (j = (s + 1); j <= n ; j++)
                        {
                            a[i][j] += f*a[s][j];
                        }
                    }

                    s++;
                }
                while (s < (n - 1)) ;

                l.mComponents[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

                for (i = (n - 2); i >= 0; i--)
                {
                    for (j = (n - 1); j > i ; j--)
                    {
                        a[i][n] -= l.mComponents[j] * a[i][j];
                    }

                    l.mComponents[i] = a[i][n] / a[i][i];
                }

                return l;
            }

            /**
             * @brief Set a component element.
             * Hints are not considered.
             * @param row The row in range [0 .. 3].
             * @param col The column in range [0 .. 3].
             * @param value The value to set.
             */
            void SetElementAt(UInt32 row, UInt32 col, DataType value)
            {
                if (MURL_VERIFY((row + col * 4) < NUM_COMPONENTS))
                {
                    mComponents[row + col * 4] = value;
                }
            }

            /**
             * @brief Get a component element.
             * @param row The row in range [0 .. 3].
             * @param col The column in range [0 .. 3].
             * @return The value at the given position.
             */
            DataType GetElementAt(UInt32 row, UInt32 col) const
            {
                MURL_ASSERT((row + col * 4) < NUM_COMPONENTS);
                return mComponents[row + col * 4];
            }

            /**
             * @brief Get a writeable reference to a component element.
             * @param row The row in range [0 .. 3].
             * @param col The column in range [0 .. 3].
             * @return The value at the given position.
             */
            DataType& GetElementAt(UInt32 row, UInt32 col)
            {
                MURL_ASSERT((row + col * 4) < NUM_COMPONENTS);
                return mComponents[row + col * 4];
            }

            /**
             * @brief Set a component element.
             * Hints are not considered.
             * @param element The element
             * @param value The value to set.
             */
            void SetElement(Component element, DataType value)
            {
                if (MURL_VERIFY(element < NUM_COMPONENTS))
                {
                    mComponents[element] = value;
                }
            }

            /**
             * @brief Get a component element.
             * @param element The element's component.
             * @return The value at the given position.
             */
            DataType GetElement(Component element) const
            {
                MURL_ASSERT(element < NUM_COMPONENTS);
                return mComponents[element];
            }

            /**
             * @brief Get a writeable reference to a component element.
             * @param element The element's component.
             * @return The value at the given position.
             */
            DataType& GetElement(Component element)
            {
                MURL_ASSERT(element < NUM_COMPONENTS);
                return mComponents[element];
            }

            /**
             * @brief Set the XX component.
             * Hints are not considered.
             * @param value The XX component value to set.
             */
            void SetXX(DataType value)
            {
                xx = value;
            }
            /**
             * @brief Set the XY component.
             * Hints are not considered.
             * @param value The XY component value to set.
             */
            void SetXY(DataType value)
            {
                xy = value;
            }
            /**
             * @brief Set the XZ component.
             * Hints are not considered.
             * @param value The XZ component value to set.
             */
            void SetXZ(DataType value)
            {
                xz = value;
            }
            /**
             * @brief Set the XW component.
             * Hints are not considered.
             * @param value The XW component value to set.
             */
            void SetXW(DataType value)
            {
                xw = value;
            }

            /**
             * @brief Set the YX component.
             * Hints are not considered.
             * @param value The YX component value to set.
             */
            void SetYX(DataType value)
            {
                yx = value;
            }
            /**
             * @brief Set the YY component.
             * Hints are not considered.
             * @param value The YY component value to set.
             */
            void SetYY(DataType value)
            {
                yy = value;
            }
            /**
             * @brief Set the YZ component.
             * Hints are not considered.
             * @param value The YZ component value to set.
             */
            void SetYZ(DataType value)
            {
                yz = value;
            }
            /**
             * @brief Set the YW component.
             * Hints are not considered.
             * @param value The YW component value to set.
             */
            void SetYW(DataType value)
            {
                yw = value;
            }

            /**
             * @brief Set the ZX component.
             * Hints are not considered.
             * @param value The ZX component value to set.
             */
            void SetZX(DataType value)
            {
                zx = value;
            }
            /**
             * @brief Set the ZY component.
             * Hints are not considered.
             * @param value The ZY component value to set.
             */
            void SetZY(DataType value)
            {
                zy = value;
            }
            /**
             * @brief Set the ZZ component.
             * Hints are not considered.
             * @param value The ZZ component value to set.
             */
            void SetZZ(DataType value)
            {
                zz = value;
            }
            /**
             * @brief Set the ZW component.
             * Hints are not considered.
             * @param value The ZW component value to set.
             */
            void SetZW(DataType value)
            {
                zw = value;
            }

            /**
             * @brief Set the WX component.
             * Hints are not considered.
             * @param value The WX component value to set.
             */
            void SetWX(DataType value)
            {
                wx = value;
            }
            /**
             * @brief Set the WY component.
             * Hints are not considered.
             * @param value The WY component value to set.
             */
            void SetWY(DataType value)
            {
                wy = value;
            }
            /**
             * @brief Set the WZ component.
             * Hints are not considered.
             * @param value The WZ component value to set.
             */
            void SetWZ(DataType value)
            {
                wz = value;
            }
            /**
             * @brief Set the WW component.
             * Hints are not considered.
             * @param value The WW component value to set.
             */
            void SetWW(DataType value)
            {
                ww = value;
            }

            /**
             * @brief Get the XX component.
             * @return The XX component value.
             */
            DataType GetXX() const
            {
                return xx;
            }
            /**
             * @brief Get the XY component.
             * @return The XY component value.
             */
            DataType GetXY() const
            {
                return xy;
            }
            /**
             * @brief Get the XZ component.
             * @return The XZ component value.
             */
            DataType GetXZ() const
            {
                return xz;
            }
            /**
             * @brief Get the XW component.
             * @return The XW component value.
             */
            DataType GetXW() const
            {
                return xw;
            }

            /**
             * @brief Get the YX component.
             * @return The YX component value.
             */
            DataType GetYX() const
            {
                return yx;
            }
            /**
             * @brief Get the YY component.
             * @return The YY component value.
             */
            DataType GetYY() const
            {
                return yy;
            }
            /**
             * @brief Get the YZ component.
             * @return The YZ component value.
             */
            DataType GetYZ() const
            {
                return yz;
            }
            /**
             * @brief Get the YW component.
             * @return The YW component value.
             */
            DataType GetYW() const
            {
                return yw;
            }

            /**
             * @brief Get the ZX component.
             * @return The ZX component value.
             */
            DataType GetZX() const
            {
                return zx;
            }
            /**
             * @brief Get the ZY component.
             * @return The ZY component value.
             */
            DataType GetZY() const
            {
                return zy;
            }
            /**
             * @brief Get the ZZ component.
             * @return The ZZ component value.
             */
            DataType GetZZ() const
            {
                return zz;
            }
            /**
             * @brief Get the ZW component.
             * @return The ZW component value.
             */
            DataType GetZW() const
            {
                return zw;
            }

            /**
             * @brief Get the WX component.
             * @return The WX component value.
             */
            DataType GetWX() const
            {
                return wx;
            }
            /**
             * @brief Get the WY component.
             * @return The WY component value.
             */
            DataType GetWY() const
            {
                return wy;
            }
            /**
             * @brief Get the WZ component.
             * @return The WZ component value.
             */
            DataType GetWZ() const
            {
                return wz;
            }
            /**
             * @brief Get the WW component.
             * @return The WW component value.
             */
            DataType GetWW() const
            {
                return ww;
            }

            /**
             * @brief Check if the matrix is equal to a given matrix.
             * Compares all values within the default epsilon range Limits::Epsilon().
             * @param m The matrix to compare.
             * @return true if all components are exactly the same.
             */
            Bool IsEqual(const Matrix& m) const
            {
                return IsEqual(m, Limits<DataType>::Epsilon());
            }

            /**
             * @brief Check if the matrix is equal to a given matrix.
             * Compares all values within a given epsilon range.
             * @param m The matrix to compare.
             * @param epsilon The epsilon to compare.
             * @return true if equal.
             */
            Bool IsEqual(const Matrix& m, DataType epsilon) const
            {
                for (UInt32 i = 0; i < NUM_COMPONENTS; i++)
                {
                    if (Abs(mComponents[i] - m.mComponents[i]) >= epsilon)
                    {
                        return false;
                    }
                }
                return true;
            }

            /**
             * @brief Check if the matrix is equal to the identity matrix.
             * Performs a test without an epsilon range.
             * @return true if equal.
             */
            Bool IsIdentity() const
            {
                return *this == StaticMatrix<DataType>::Identity();
            }

            /**
             * @brief Check if the matrix is equal to the identity matrix.
             * Compares all values within a given epsilon range.
             * @param epsilon The epsilon to compare.
             * @return true if equal.
             */
            Bool IsIdentity(DataType epsilon) const
            {
                return IsEqual(StaticMatrix<DataType>::Identity(), epsilon);
            }

            /**
             * @brief Equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Matrix> class.
             * To compare within an epsilon range use Matrix::IsEqual().
             * @param lhs The left hand side matrix to compare.
             * @param rhs The right hand side matrix to compare.
             * @return true if all components are exactly the same.
             */
            friend bool operator==(const Matrix<DataType>& lhs, const Matrix<DataType>& rhs)
            {
                for (UInt32 i = 0; i < NUM_COMPONENTS; i++)
                {
                    if (lhs.mComponents[i] != rhs.mComponents[i])
                    {
                        return false;
                    }
                }
                return true;
            }

            /**
             * @brief Not equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Matrix> class.
             * To compare within an epsilon range use Matrix::IsEqual().
             * @param lhs The left hand side matrix to compare.
             * @param rhs The right hand side matrix to compare.
             * @return true if all components are not exactly the same.
             */
            friend bool operator!=(const Matrix<DataType>& lhs, const Matrix<DataType>& rhs)
            {
                return !operator==(lhs, rhs);
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return Util::PrintToString("%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f",
                                           Double(xx), Double(yx), Double(zx), Double(wx),
                                           Double(xy), Double(yy), Double(zy), Double(wy),
                                           Double(xz), Double(yz), Double(zz), Double(wz),
                                           Double(xw), Double(yw), Double(zw), Double(ww));
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

#endif // __MURL_MATH_MATRIX_H__

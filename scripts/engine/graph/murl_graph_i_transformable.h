// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TRANSFORMABLE_H__
#define __MURL_GRAPH_I_TRANSFORMABLE_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface ITransformable
         * @brief The ITransformable property interface.
         * This interface provides the basis for transforming nodes within a virtual 2D or 3D space.
         * Internally, this encapsulates a 4x4 transformation matrix. In general, transforms are applied according to
         * the hierarchy in which they are specified.
         *
         * Animation controllers may call the SetTransform() method when translation and/or rotation
         * keys are present in a given Resource::IAnimation.
         */
        class ITransformable
        {
        public:
            /**
             * @brief Set the depth order.
             * For any geometry that gets sorted back-to-front (i.e. with disabled Z-Buffer writes), the
             * depth order provides an additional means for sorting, useful when two or more objects share
             * the same depth (or distance value, depending on the depth sorting mode applied by the
             * currently active Graph::ICamera). In such a case, objects with a higher depth order will
             * be drawn later, i.e. on top of others. Like the hierarchical behavior of the transformation
             * matrix, depth orders are also applied relative to their parents.
             * @param depthOrder A signed 32bit integer
             * @return true if successful
             */
            virtual Bool SetDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Get the depth order.
             * @return The transform's depth order
             */
            virtual SInt32 GetDepthOrder() const = 0;

            /**
             * @brief Set the 4x4 transformation matrix.
             * This method copies the given transformation matrix to the internal matrix as a whole.
             * @param transform The transformation matrix to apply
             * @return true if successful
             */
            virtual Bool SetTransform(const Matrix& transform) = 0;
            /**
             * @brief Get a constant reference to the internal 4x4 transformation matrix.
             * @return The transformation matrix
             */
            virtual const Matrix& GetTransform() const = 0;
            /**
             * @brief Get a mutable reference to the internal 4x4 transformation matrix.
             * This method may be called to directly modify the internal transformation matrix.
             * Calling this will internally flag the transform as "modified" in any case, even
             * if it was not actually modified.
             * @return The transformation matrix
             */
            virtual Matrix& GetTransform() = 0;

            /**
             * @brief Set the translation component of the transformation matrix.
             * This method directly copies the X, Y and Z values of the given position vector to the
             * XW, YW and ZW components of the matrix without modifying any other component.
             * @param pos The position vector to apply
             * @return true if successful
             */
            virtual Bool SetPosition(const Vector& pos) = 0;
            /**
             * @brief Set the translation component of the transformation matrix.
             * This method directly copies the individually given X, Y and Z position values to the
             * XW, YW and ZW components of the matrix without modifying any other component.
             * @param posX The X component to apply
             * @param posY The Y component to apply
             * @param posZ The Z component to apply
             * @return true if successful
             */
            virtual Bool SetPosition(Real posX, Real posY, Real posZ) = 0;
            /**
             * @brief Set the X component of the transformation matrix' translation.
             * This method directly copies the given X position value to the XW component of the
             * matrix without modifying any other component.
             * @param pos The X component to apply
             * @return true if successful
             */
            virtual Bool SetPositionX(Real pos) = 0;
            /**
             * @brief Set the Y component of the transformation matrix' translation.
             * This method directly copies the given Y position value to the YW component of the
             * matrix without modifying any other component.
             * @param pos The Y component to apply
             * @return true if successful
             */
            virtual Bool SetPositionY(Real pos) = 0;
            /**
             * @brief Set the Z component of the transformation matrix' translation.
             * This method directly copies the given Z position value to the ZW component of the
             * matrix without modifying any other component.
             * @param pos The Z component to apply
             * @return true if successful
             */
            virtual Bool SetPositionZ(Real pos) = 0;
            /**
             * @brief Get a constant reference to the internal position vector.
             * @return The position vector.
             */
            virtual const Vector& GetPosition() const = 0;
            /**
             * @brief Get the X component of the transformation matrix' translation.
             * @return The X component
             */
            virtual Real GetPositionX() const = 0;
            /**
             * @brief Get the Y component of the transformation matrix' translation.
             * @return The Y component
             */
            virtual Real GetPositionY() const = 0;
            /**
             * @brief Get the Z component of the transformation matrix' translation.
             * @return The Z component
             */
            virtual Real GetPositionZ() const = 0;

            /**
             * @brief Set the rotation component of the transformation matrix in axis-angle notation.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating the rotation component from a given axis and angle. The axis must be
             * normalized (i.e. have unit length), and the angle must be given in radians. Positive
             * angle values result in a clockwise rotation when viewed along the given axis.
             * @param axis The normalized rotation axis
             * @param angle The rotation angle around the axis in radians
             * @return true if successful
             */
            virtual Bool SetRotation(const Vector& axis, Real angle) = 0;
            /**
             * @brief Set the rotation component of the transformation matrix by a quaternion.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating the rotation component from a given quaternion.
             * @param q The quaternion.
             * @return true if successful
             */
            virtual Bool SetRotation(const Quaternion& q) = 0;

            /**
             * @brief Set the axis rotation order for Euler axis notation.
             * The default axis rotation order is IEnums::ROTATION_ORDER_ZYX.
             * @param rotationOrder The axis rotation order.
             * @return true if successful
             */
            virtual Bool SetRotationOrder(IEnums::RotationOrder rotationOrder) = 0;
            /**
             * @brief Set the rotation component of the transformation matrix in Euler angles notation.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and subsequently applying individual X, Y and Z rotations (Euler angles).
             * Uses the axis rotation order set by SetRotationOrder() or rotationOrder="" XML attribute.
             * Angle values must be given in radians. Positive values result in a clockwise rotation
             * when viewed along the unit X, Y and Z axes, respectively.
             * @param angleX The rotation angle around the X axis in radians
             * @param angleY The rotation angle around the Y axis in radians
             * @param angleZ The rotation angle around the Z axis in radians
             * @return true if successful
             */
            virtual Bool SetRotation(Real angleX, Real angleY, Real angleZ) = 0;
            /**
             * @brief Set the rotation component of the transformation matrix in Euler angles notation
             *   with a given rotation order.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and subsequently applying individual X, Y and Z rotations (Euler angles).
             * Angle values must be given in radians. Positive values result in a clockwise rotation
             * when viewed along the unit X, Y and Z axes, respectively.
             * @param angleX The rotation angle around the X axis in radians
             * @param angleY The rotation angle around the Y axis in radians
             * @param angleZ The rotation angle around the Z axis in radians
             * @param rotationOrder The axis rotation order.
             * @return true if successful
             */
            virtual Bool SetRotationXYZ(Real angleX, Real angleY, Real angleZ, IEnums::RotationOrder rotationOrder) = 0;
            /**
             * @brief Set the rotation component of the transformation matrix to only rotate around the X axis.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and applying a rotation around the unit X axis. The angle value must be given in
             * radians. A positive value result in a clockwise rotation.
             * @param angle The rotation angle around the X axis in radians
             * @return true if successful
             */
            virtual Bool SetRotationX(Real angle) = 0;
            /**
             * @brief Set the rotation component of the transformation matrix to only rotate around the Y axis.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and applying a rotation around the unit Y axis. The angle value must be given in
             * radians. A positive value result in a clockwise rotation.
             * @param angle The rotation angle around the Y axis in radians
             * @return true if successful
             */
            virtual Bool SetRotationY(Real angle) = 0;
            /**
             * @brief Set the rotation component of the transformation matrix to only rotate around the Z axis.
             * This method directly overwrites the upper 3x3 matrix of the internal transformation
             * by calculating and applying a rotation around the unit Z axis. The angle value must be given in
             * radians. A positive value result in a clockwise rotation.
             * @param angle The rotation angle around the Z axis in radians
             * @return true if successful
             */
            virtual Bool SetRotationZ(Real angle) = 0;

            /**
             * @brief Get the axis rotation order for Euler axis notation.
             * @return The axis rotation order.
             */
            virtual IEnums::RotationOrder GetRotationOrder() const = 0;
            /**
             * @brief Get a constant reference to the internal euler angles vector.
             * This method returns the Euler angles set by XML attribute angleX/Y/Z="" or SetRotationX/Y/Z(),
             * SetRotationXYZ() or SetRotation(Real angleX, Real angleY, Real angleZ) only.
             * @return The rotation vector.
             */
            virtual const Vector& GetRotation() const = 0;
            /**
             * @brief Get the rotation around the X axis.
             * This method returns the Euler angle set by XML attribute angleX="" or SetRotationX(),
             * SetRotationXYZ() or SetRotation(Real angleX, Real angleY, Real angleZ) only.
             * \n If the upper 3x3 matrix of the internal transformation matrix has been modified
             * by other methods, the returned angle is incorrect.
             * In this case Matrix::GetEulerRotation() can be used to calculate corresponding angles.
             * @return The rotation around the X axis.
             */
            virtual Real GetRotationX() const = 0;
            /**
             * @brief Get the rotation around the Y axis.
             * This method returns the Euler angle set by XML attribute angleY="" or SetRotationY(),
             * SetRotationXYZ() or SetRotation(Real angleX, Real angleY, Real angleZ) only.
             * \n If the upper 3x3 matrix of the internal transformation matrix has been modified
             * by other methods, the returned angle is incorrect.
             * In this case Matrix::GetEulerRotation() can be used to calculate corresponding angles.
             * @return The rotation around the Y axis.
             */
            virtual Real GetRotationY() const = 0;
            /**
             * @brief Get the rotation around the Z axis.
             * This method returns the Euler angle set by XML attribute angleZ="" or SetRotationZ(),
             * SetRotationXYZ() or SetRotation(Real angleX, Real angleY, Real angleZ) only.
             * \n If the upper 3x3 matrix of the internal transformation matrix has been modified
             * by other methods, the returned angle is incorrect.
             * In this case Matrix::GetEulerRotation() can be used to calculate corresponding angles.
             * @return The rotation around the Z axis.
             */
            virtual Real GetRotationZ() const = 0;

        protected:
            virtual ~ITransformable() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITransformable nodes.
         */
        typedef IGenericNodeTarget<ITransformable> ITransformableNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TRANSFORMABLE_H__

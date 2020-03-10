// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_GRAPH_TRANSFORM_H__
#define __MURL_GRAPH_TRANSFORM_H__

#include "murl_graph_node.h"
#include "murl_graph_i_transform.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeClasses
         * @brief The Transform node class.
         *
         * @xmlelements
         *
         * @graphtags
         * @graphtag{Transform}
         *
         * @graphatts
         * @graphatt{depthOrder,SInt32,0, The depth order. See Murl::Graph::ITransformable::SetDepthOrder().}
         * @graphatt{posX,Real,0.0, The translation X component. See Murl::Graph::ITransformable::SetPositionX().}
         * @graphatt{posY,Real,0.0, The translation Y component. See Murl::Graph::ITransformable::SetPositionY().}
         * @graphatt{posZ,Real,0.0, The translation Z component. See Murl::Graph::ITransformable::SetPositionZ().}
         * @graphatt{angleX,Real,0.0, The x-axis angle. The angle value must be given in degrees with unit suffix "d" or "deg" or radians with unit suffix "r" or "rad". See Murl::Graph::ITransformable::SetRotationXYZ().}
         * @graphatt{angleY,Real,0.0, The y-axis angle. The angle value must be given in degrees with unit suffix "d" or "deg" or radians with unit suffix "r" or "rad". See Murl::Graph::ITransformable::SetRotationXYZ().}
         * @graphatt{angleZ,Real,0.0, The z-axis angle. The angle value must be given in degrees with unit suffix "d" or "deg" or radians with unit suffix "r" or "rad". See Murl::Graph::ITransformable::SetRotationXYZ().}
         * @graphatt{rotationOrder,IEnums::RotationOrder,ZYX, The axis rotation order. See Murl::Graph::ITransformable::SetRotationXYZ().}
         * @graphatt{axisX,Real,0.0, The rotation axis' X component. See Murl::Graph::ITransformable::SetRotation(const Vector& axis\, Real angle).}
         * @graphatt{axisY,Real,0.0, The rotation axis' Y component. See Murl::Graph::ITransformable::SetRotation(const Vector& axis\, Real angle).}
         * @graphatt{axisZ,Real,1.0, The rotation axis' Z component. See Murl::Graph::ITransformable::SetRotation(const Vector& axis\, Real angle).}
         * @graphatt{angle,Real,0.0, The rotation axis angle. The angle value must be given in degrees with unit suffix "d" or "deg" or radians with unit suffix "r" or "rad".
         *           If this attribute is set to a non-zero value the angleX/angleY/angleZ values are ignored.
         *           See Murl::Graph::ITransformable::SetRotation(const Vector& axis\, Real angle).}
         * @graphatt{xx,Real,1.0, Can be used to directly specify the values of the 4x4 transformation matrix (xx is 1st row and 1st column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{xy,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (xy is 1st row and 2nd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{xz,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (xz is 1st row and 3rd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{xw,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (xw is 1st row and 4th column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{yx,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (yx is 2nd row and 1st column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{yy,Real,1.0, Can be used to directly specify the values of the 4x4 transformation matrix (yy is 2nd row and 2nd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{yz,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (yz is 2nd row and 3rd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{yw,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (yw is 2nd row and 4th column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{zx,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (zx is 3rd row and 1st column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{zy,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (zy is 3rd row and 2nd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{zz,Real,1.0, Can be used to directly specify the values of the 4x4 transformation matrix (zz is 3rd row and 3rd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{zw,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (zw is 3rd row and 4th column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{wx,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (wx is 4th row and 1st column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{wy,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (wy is 4th row and 2nd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{wz,Real,0.0, Can be used to directly specify the values of the 4x4 transformation matrix (wz is 4th row and 3rd column). Values will be overridden if used in combination with posX\, angle etc.}
         * @graphatt{ww,Real,1.0, Can be used to directly specify the values of the 4x4 transformation matrix (ww is 4th row and 4th column). Values will be overridden if used in combination with posX\, angle etc.}
         
         * @animtags
         * @animtag{DepthOrderKey,IntegerKey,LINEAR, The animation key acting on
         *      Murl::Graph::ITransformable::SetDepthOrder().}
         * @animtag{PositionKey,PositionKey,LINEAR, The animation key acting on
         *      Murl::Graph::ITransformable::SetPosition().}
         * @animtag{RotationKey,EulerAngleKey,LINEAR, The animation key acting on
         *      Murl::Graph::ITransformable::SetRotationXYZ().}
         * @animtag{RotationKey,AxisAngleKey,LINEAR, The animation key acting on
         *      Murl::Graph::ITransformable::SetRotation(const Vector& axis\, Real angle).}
         * @animtag{RotationKey,QuaternionKey,LINEAR, The animation key acting on
         *      Murl::Graph::ITransformable::SetRotation(const Quaternion& q).}
         */
        class Transform : public Node, public ITransform
        {
            MURL_FACTORY_OBJECT_DERIVED_CLASS(Murl::Graph::Transform, Murl::Graph::Node)

            MURL_FACTORY_OBJECT_PROPERTIES(Murl::Graph::Transform,
                                           (PROPERTY_TRANSFORM,      mTransform,     Matrix(Matrix::IDENTITY),   MatrixProperty),
                                           (PROPERTY_EULER_ANGLE,    mEulerAngle,    Vector(0.0, 0.0, 0.0, 0.0), VectorAngleProperty),
                                           (PROPERTY_ROTATION_ORDER, mRotationOrder, IEnums::ROTATION_ORDER_ZYX, EnumProperty, IEnums::RotationOrder),
                                           (PROPERTY_AXIS,           mAxis,          Vector(0.0, 0.0, 1.0, 0.0), VectorProperty),
                                           (PROPERTY_ANGLE,          mAngle,         Math::Limits<Real>::NaN(),  RealAngleProperty),
                                           (PROPERTY_DEPTH_ORDER,    mDepthOrder,    0,                          SInt32Property))

            MURL_FACTORY_OBJECT_ATTRIBUTES(Murl::Graph::Transform,
                                           (ATTRIBUTE_DEPTH_ORDER,    "depthOrder",    mDepthOrder,    COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_POS_X,          "posX",          mTransform,     COMPONENT_XW,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_POS_Y,          "posY",          mTransform,     COMPONENT_YW,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_POS_Z,          "posZ",          mTransform,     COMPONENT_ZW,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_EULER_ANGLE_X,  "angleX",        mEulerAngle,    COMPONENT_X,      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_EULER_ANGLE_Y,  "angleY",        mEulerAngle,    COMPONENT_Y,      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_EULER_ANGLE_Z,  "angleZ",        mEulerAngle,    COMPONENT_Z,      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ROTATION_ORDER, "rotationOrder", mRotationOrder, COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_AXIS_X,         "axisX",         mAxis,          COMPONENT_X,      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_AXIS_Y,         "axisY",         mAxis,          COMPONENT_Y,      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_AXIS_Z,         "axisZ",         mAxis,          COMPONENT_Z,      ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ANGLE,          "angle",         mAngle,         COMPONENT_SINGLE, ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_XX,             "xx",            mTransform,     COMPONENT_XX,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_YX,             "yx",            mTransform,     COMPONENT_YX,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ZX,             "zx",            mTransform,     COMPONENT_ZX,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_WX,             "wx",            mTransform,     COMPONENT_WX,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_XY,             "xy",            mTransform,     COMPONENT_XY,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_YY,             "yy",            mTransform,     COMPONENT_YY,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ZY,             "zy",            mTransform,     COMPONENT_ZY,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_WY,             "wy",            mTransform,     COMPONENT_WY,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_XZ,             "xz",            mTransform,     COMPONENT_XZ,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_YZ,             "yz",            mTransform,     COMPONENT_YZ,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ZZ,             "zz",            mTransform,     COMPONENT_ZZ,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_WZ,             "wz",            mTransform,     COMPONENT_WZ,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_XW,             "xw",            mTransform,     COMPONENT_XW,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_YW,             "yw",            mTransform,     COMPONENT_YW,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_ZW,             "zw",            mTransform,     COMPONENT_ZW,     ACCESS_SINGLE, ELEMENT_SINGLE),
                                           (ATTRIBUTE_WW,             "ww",            mTransform,     COMPONENT_WW,     ACCESS_SINGLE, ELEMENT_SINGLE))

            static INode* Create(const IFactory* factory);

        protected:
            virtual Bool DeserializeBaseAttribute(IDeserializeAttributeTracker* tracker);

        protected:
            enum TransformFlags
            {
                TRANSFORM_FLAG_MODIFIED   = (1 << 0),
                TRANSFORM_FLAG_IDENTITY   = (1 << 1)
            };

        public:
            virtual INode* GetNodeInterface();
            virtual const INode* GetNodeInterface() const;

            virtual Bool SetDepthOrder(SInt32 depthOrder);
            virtual SInt32 GetDepthOrder() const;

            virtual Bool SetTransform(const Matrix& transform);
            virtual const Matrix& GetTransform() const;
            virtual Matrix& GetTransform();

            virtual Bool SetPosition(const Vector& pos);
            virtual Bool SetPosition(Real posX, Real posY, Real posZ);
            virtual Bool SetPositionX(Real pos);
            virtual Bool SetPositionY(Real pos);
            virtual Bool SetPositionZ(Real pos);

            virtual const Vector& GetPosition() const;
            virtual Real GetPositionX() const;
            virtual Real GetPositionY() const;
            virtual Real GetPositionZ() const;

            virtual Bool SetRotation(const Vector& axis, Real angle);
            virtual Bool SetRotation(const Quaternion& q);
            virtual Bool SetRotationOrder(IEnums::RotationOrder rotationOrder);
            virtual Bool SetRotation(Real angleX, Real angleY, Real angleZ);
            virtual Bool SetRotationXYZ(Real angleX, Real angleY, Real angleZ, IEnums::RotationOrder rotationOrder);
            virtual Bool SetRotationX(Real angle);
            virtual Bool SetRotationY(Real angle);
            virtual Bool SetRotationZ(Real angle);

            virtual IEnums::RotationOrder GetRotationOrder() const;
            virtual const Vector& GetRotation() const;
            virtual Real GetRotationX() const;
            virtual Real GetRotationY() const;
            virtual Real GetRotationZ() const;

        protected:
            Transform(const IFactory* factory);
            virtual ~Transform();

            virtual Bool InitSelf(IInitTracker* tracker);

            virtual Bool ProcessLogicSelf(IProcessLogicTracker* tracker);
            virtual Bool ProcessLogicChildren(IProcessLogicTracker* tracker);

            virtual Bool ProcessInputSelf(IProcessInputTracker* tracker);
            virtual Bool ProcessInputChildren(IProcessInputTracker* tracker);

            virtual Bool ProcessOutputSelf(IProcessOutputTracker* tracker);
            virtual Bool ProcessOutputChildren(IProcessOutputTracker* tracker);

            void ClearIdentitySetModified();

            // Members
            UInt32 mTransformFlags;
        };
    }
}

#endif // __MURL_GRAPH_TRANSFORM_H__

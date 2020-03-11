// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_HINGE_JOINT_H__
#define __MURL_PHYSICS_I_HINGE_JOINT_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IJoint;
        class IObject;
        
        class IHingeJoint
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual IJoint* GetJointInterface() = 0;
            virtual const IJoint* GetJointInterface() const = 0;

            virtual Bool SetAxis(const Vector& axis) = 0;
            virtual const Vector& GetAxis() const = 0;

            virtual Bool SetMinAngle(Real angle) = 0;
            virtual Real GetMinAngle() const = 0;

            virtual Bool SetMaxAngle(Real angle) = 0;
            virtual Real GetMaxAngle() const = 0;

        protected:
            virtual ~IHingeJoint() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_HINGE_JOINT_H__

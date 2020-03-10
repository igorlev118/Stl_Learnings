// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_BALL_JOINT_H__
#define __MURL_PHYSICS_I_BALL_JOINT_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IJoint;
        class IObject;
        
        class IBallJoint
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual IJoint* GetJointInterface() = 0;
            virtual const IJoint* GetJointInterface() const = 0;

        protected:
            virtual ~IBallJoint() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_BALL_JOINT_H__

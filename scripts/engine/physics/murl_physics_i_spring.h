// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_SPRING_H__
#define __MURL_PHYSICS_I_SPRING_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IBody;
        class IObject;

        class ISpring
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual Bool SetParameters(Real springConstant, Real dampingConstant, Real minimumLength, Real maximumLength, Bool affectForce, Bool affectTorque) = 0;

            virtual Bool AttachBody(UInt32 index, IBody* body, const Vector& localPosition, Bool isInfluenced) = 0;
            virtual Bool DetachBody(UInt32 index) = 0;
            
        protected:
            virtual ~ISpring() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_SPRING_H__

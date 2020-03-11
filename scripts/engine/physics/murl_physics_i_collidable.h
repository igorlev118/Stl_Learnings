// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_COLLIDABLE_H__
#define __MURL_PHYSICS_I_COLLIDABLE_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class ICollidable
        {
        public:
            virtual Bool ReportCollision(ICollidable* body1, ICollidable* geometry1, UInt32 surfaceIndex1, ICollidable* body2, ICollidable* geometry2, UInt32 surfaceIndex2, const Vector& worldPosition, const Vector& worldDirection, Real depth) = 0;
            
        protected:
            virtual ~ICollidable() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_COLLIDABLE_H__

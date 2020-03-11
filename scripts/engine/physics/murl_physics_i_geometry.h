// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_GEOMETRY_H__
#define __MURL_PHYSICS_I_GEOMETRY_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IBody;
        class ICollidable;
        class IObject;

        class IGeometry
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual Bool SetResponseTarget(ICollidable* node) = 0;
            virtual ICollidable* GetResponseTarget() const = 0;

        protected:
            virtual ~IGeometry() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_GEOMETRY_H__

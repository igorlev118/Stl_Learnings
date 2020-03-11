// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_PLANE_GEOMETRY_H__
#define __MURL_PHYSICS_I_PLANE_GEOMETRY_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IPlaneGeometry
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual IGeometry* GetGeometryInterface() = 0;
            virtual const IGeometry* GetGeometryInterface() const = 0;
            
            virtual Bool SetNormal(const Vector& normal) = 0;
            virtual const Vector& GetNormal() const = 0;
            
            virtual Bool SetDistance(Real distance) = 0;
            virtual Real GetDistance() const = 0;
            
        protected:
            virtual ~IPlaneGeometry() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_PLANE_GEOMETRY_H__

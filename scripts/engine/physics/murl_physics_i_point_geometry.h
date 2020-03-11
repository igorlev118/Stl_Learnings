// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_POINT_GEOMETRY_H__
#define __MURL_PHYSICS_I_POINT_GEOMETRY_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IGeometry;
        class IObject;
        
        class IPointGeometry
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual IGeometry* GetGeometryInterface() = 0;
            virtual const IGeometry* GetGeometryInterface() const = 0;
            
        protected:
            virtual ~IPointGeometry() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_POINT_GEOMETRY_H__

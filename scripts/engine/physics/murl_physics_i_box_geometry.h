// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_BOX_GEOMETRY_H__
#define __MURL_PHYSICS_I_BOX_GEOMETRY_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IGeometry;
        class IObject;
        
        class IBoxGeometry
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual IGeometry* GetGeometryInterface() = 0;
            virtual const IGeometry* GetGeometryInterface() const = 0;
            
            virtual Bool SetSize(const Vector& size) = 0;
            virtual Bool SetSize(Real sizeX, Real sizeY, Real sizeZ) = 0;
            virtual Bool SetSizeX(Real sizeX) = 0;
            virtual Bool SetSizeY(Real sizeY) = 0;
            virtual Bool SetSizeZ(Real sizeZ) = 0;
            virtual const Vector& GetSize() const = 0;
            virtual Real GetSizeX() const = 0;
            virtual Real GetSizeY() const = 0;
            virtual Real GetSizeZ() const = 0;
            
        protected:
            virtual ~IBoxGeometry() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_BOX_GEOMETRY_H__

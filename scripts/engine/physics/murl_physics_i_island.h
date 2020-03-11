// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_ISLAND_H__
#define __MURL_PHYSICS_I_ISLAND_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class IBody;
        class IGeometry;
        class IJoint;
        class ISpring;
        class IField;
        class ISurface;
        class IObject;

        class IIsland
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;

            virtual Bool SetTime(Double currentTime, Double deltaTime) = 0;
        
        protected:
            virtual ~IIsland() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_ISLAND_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_SURFACE_H__
#define __MURL_PHYSICS_I_SURFACE_H__

#include "murl_physics_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Physics
    {
        class ISurface
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
        protected:
            virtual ~ISurface() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_SURFACE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_CONTACT_H__
#define __MURL_PHYSICS_I_CONTACT_H__

#include "murl_physics_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Physics
    {
        class IObject;
        class ISurface;
        
        class IContact
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual Bool SetSurface(UInt32 index, ISurface* surface) = 0;
            virtual ISurface* GetSurface(UInt32 index) const = 0;
            
            virtual Bool SetStaticFrictionConstant(Real c) = 0;
            virtual Real GetStaticFrictionConstant() const = 0;
            
            virtual Bool SetDynamicFrictionConstant(Real c) = 0;
            virtual Real GetDynamicFrictionConstant() const = 0;
            
            virtual Bool SetRollingFrictionConstant(Real c) = 0;
            virtual Real GetRollingFrictionConstant() const = 0;
            
            virtual Bool SetSpringConstant(Real c) = 0;
            virtual Real GetSpringConstant() const = 0;
            
            virtual Bool SetDampingConstant(Real c) = 0;
            virtual Real GetDampingConstant() const = 0;

            virtual Bool SetBounceFactor(Real f) = 0;
            virtual Real GetBounceFactor() const = 0;
            
            virtual Bool SetBounceThreshold(Real f) = 0;
            virtual Real GetBounceThreshold() const = 0;

            virtual Bool SetSlip(Real s) = 0;
            virtual Real GetSlip() const = 0;

        protected:
            virtual ~IContact() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_CONTACT_H__

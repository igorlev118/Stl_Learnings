// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_FIELD_H__
#define __MURL_PHYSICS_I_FIELD_H__

#include "murl_physics_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Physics
    {
        class IObject;
        
        class IField
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual Bool SetType(IEnums::FieldType type) = 0;
            virtual IEnums::FieldType GetType() const = 0;
            
            virtual Bool SetInfluenceMask(UInt32 influenceMask) = 0;
            virtual UInt32 GetInfluenceMask() = 0;
            
            virtual Bool SetParameters(Real constantFactor, Real linearFactor, Real quadraticFactor) = 0;
            
        protected:
            virtual ~IField() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_FIELD_H__

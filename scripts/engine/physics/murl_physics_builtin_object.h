// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_BUILTIN_OBJECT_H__
#define __MURL_PHYSICS_BUILTIN_OBJECT_H__

#include "murl_physics_i_object.h"

namespace Murl
{
    namespace Physics
    {
        namespace Builtin
        {
            class Simulator;
            
            /**
             * @ingroup MurlPhysicsBuiltinObjectClasses
             * @brief The internal base class of all builtin simulator objects.
             * Only necessary when implementing custom physics objects.
             */
            class Object : public IObject
            {
                MURL_FACTORY_OBJECT_ABSTRACT_BASE_CLASS(Murl::Physics::Builtin::Object)
                
            public:
                virtual IObject* GetObjectInterface();
                virtual const IObject* GetObjectInterface() const;
                
                virtual Bool Init();
                virtual Bool DeInit();
                
                virtual Bool IsInitialized() const;
                
            protected:
                Object(ISimulator* simulator);
                virtual ~Object();
                
                Bool mIsInitialized;
                
                ISimulator* mSimulator;

                friend class Simulator;
            };
        }
    }
}

#endif // __MURL_PHYSICS_BUILTIN_OBJECT_H__

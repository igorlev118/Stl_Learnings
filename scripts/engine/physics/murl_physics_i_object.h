// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_OBJECT_H__
#define __MURL_PHYSICS_I_OBJECT_H__

#include "murl_physics_types.h"
#include "murl_i_factory_object.h"

namespace Murl
{
    namespace Physics
    {
        class ISimulator;
        
        /**
         * @ingroup MurlPhysicsObjectInterfaces
         * @interface IObject
         * @brief The base interface for all physics objects.
         */
        class IObject : public IFactoryObject<IObject>
        {
        public:
            typedef IObject* (*CreateFunction)(ISimulator*);

        public:
            /**
             * @brief Get the mutable IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Initialize this object.
             * Called by the ISimulator owning this object.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief De-initialize this object.
             * Called by the ISimulator owning this object.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Check if this object is initialized.
             * @return true if initialized.
             */
            virtual Bool IsInitialized() const = 0;
            
        protected:
            virtual ~IObject() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_OBJECT_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_FACTORY_REGISTRY_H__
#define __MURL_PHYSICS_I_FACTORY_REGISTRY_H__

#include "murl_physics_i_simulator.h"

namespace Murl
{
    namespace Physics
    {
        /**
         * @ingroup MurlPhysicsFactoryInterfaces
         * @interface IFactoryRegistry
         * The IFactoryRegistry interface provides methods to add, remove and query different
         * physics simulator classes that can be instantiated using the Physics::IFactory 
         * implementing this interface.
         */
        class IFactoryRegistry
        {
        public:
            /**
             * @brief Register a physics simulator class.
             * @param classInfo The ClassInfo structure of the simulator to register.
             * @return true if successful.
             */
            virtual Bool RegisterSimulatorClass(const ISimulator::ClassInfo& classInfo) = 0;
            /**
             * @brief Unregister a previously registered physics simulator class.
             * @param classInfo The ClassInfo structure of the simulator to unregister.
             * @return true if successful.
             */
            virtual Bool UnregisterSimulatorClass(const ISimulator::ClassInfo& classInfo) = 0;
            
            /**
             * @brief Query the index of a registered physics simulator class, by its ClassInfo structure.
             * @param classInfo The class info structure of the simulator class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredSimulatorClassInfoIndex(const ISimulator::ClassInfo& classInfo) const = 0;
            /**
             * @brief Query the index of a registered physics simulator class, by its class name.
             * @param className The name of the simulator class to query.
             * @return The zero-based index, or -1 if not registered.
             */
            virtual SInt32 GetRegisteredSimulatorClassInfoIndex(const String& className) const = 0;
            /**
             * @brief Get the total number of registered physics simulator classes.
             * @return The number of registered simulator classes.
             */
            virtual UInt32 GetNumberOfRegisteredSimulatorClassInfos() const = 0;
            /**
             * @brief Get the ClassInfo structure of a registered physics simulator class.
             * @param index The index to query, from 0 to GetNumberOfRegisteredSimulatorClassInfos()-1.
             * @return The class info, or null if the index is out of range.
             */
            virtual const ISimulator::ClassInfo* GetRegisteredSimulatorClassInfo(UInt32 index) const = 0;
             
        protected:
            virtual ~IFactoryRegistry() {}
        };
    }
}

#endif  // __MURL_PHYSICS_I_FACTORY_REGISTRY_H__

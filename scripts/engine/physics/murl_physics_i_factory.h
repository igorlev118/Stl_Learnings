// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_FACTORY_H__
#define __MURL_PHYSICS_I_FACTORY_H__

#include "murl_physics_i_factory_registry.h"

namespace Murl
{
    class IAppConfiguration;
    
    namespace Physics
    {
        class ISimulator;
        
        /**
         * @ingroup MurlPhysicsFactoryInterfaces
         * @interface IFactory
         * @brief The factory used to create and destroy physics simulators.
         * Use the Physics::IFactoryRegistry base interface for managing registered
         * simulator classes.
         */
        class IFactory : public IFactoryRegistry
        {
        public:
            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Create a default physics simulator.
             * @return The newly created simulator, or null if failed.
             */
            virtual ISimulator* CreateDefaultSimulator() = 0;
            /**
             * @brief Create a physics simulator from the set of registered simulators.
             * @param className The class name of the simulator to create.
             * @return The newly created simulator, or null if failed.
             */
            virtual ISimulator* CreateSimulator(const String& className) = 0;
            /**
             * @brief Create a physics simulator from the set of registered simulators.
             * @param classInfo The ClassInfo structure of the simulator to create.
             * @return The newly created simulator, or null if failed.
             */
            virtual ISimulator* CreateSimulator(const ISimulator::ClassInfo& classInfo) = 0;
            /**
             * @brief Destroy a previously created physics simulator.
             * @param simulator A reference to a pointer holding the simulator to destroy.
             * @return true if successful.
             */
            virtual Bool DestroySimulator(ISimulator*& simulator) = 0;
            
        protected:
            virtual ~IFactory() {}
        };
        
        /**
         * @ingroup MurlPhysicsFactoryClasses
         * @brief The StaticFactory class to create the IFactory object.
         * The StaticFactory is used by the engine's core only.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create the physics factory object.
             * @param appConfig The application configuration object.
             * @return The created physics factory object, or null if failed.
             */
            static IFactory* CreateFactory(const IAppConfiguration* appConfig);
            /**
             * @brief Destroy the physics factory object.
             * @param factory A reference to the physics factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyFactory(IFactory*& factory);
        };
    }
}

#endif  // __MURL_PHYSICS_I_FACTORY_H__

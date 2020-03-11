// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_SIMULATOR_H__
#define __MURL_PHYSICS_I_SIMULATOR_H__

#include "murl_physics_i_simulator_registry.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Physics
    {
        class IBody;
        class IGeometry;
        class IIsland;
        class IJoint;
        class ISpring;
        class IField;
        class ISurface;
        
        /**
         * @ingroup MurlPhysicsSimulatorInterfaces
         * @interface ISimulator
         * The Physics::ISimulator interface represents a generic physics simulator.
         *
         * For most cases, an application does not need to directly interact with this interface.
         * Instead, using physics-related nodes from the @ref MurlGraphNodeInterfaces or
         * @ref MurlGraphNodeClasses sections is the preferred way to implement physics simulation
         * functionality in a cross-platform manner.
         *
         * Accessing the physics simulator interface directly may be useful in advanced use cases,
         * when creating custom physics objects or even a complete custom simulator suite.
         */
        class ISimulator : public IFactoryObject<ISimulator>, public ISimulatorRegistry
        {
        public:
            typedef ISimulator* (*CreateFunction)();
            
        public:
            /**
             * @brief Initialize the simulator.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the simulator.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Create a simulator object.
             * @param className The class name of the simulator object to create.
             * @return The newly created object, or null if failed.
             */
            virtual IObject* CreateObject(const String& className) = 0;
            /**
             * @brief Destroy an object that was created by this simulator.
             * @param object A reference to a pointer containing the object to destroy.
             * @return true if successful.
             */
            virtual Bool DestroyObject(IObject*& object) = 0;

            /**
             * @brief Begin submission of simulator objects for the next tick.
             * Any calls to state-changing methods like SetCurrentTransform() or SetCurrentSurfaces()
             * must happen between a call to this method and the corresponding EndSubmission() call.
             * @return true if successful.
             */
            virtual Bool BeginSubmission() = 0;
            /**
             * @brief End submission of simulator objects for the next tick.
             * @return true if successful.
             */
            virtual Bool EndSubmission() = 0;

            /**
             * @brief Start the actual simulation process after all current objects have been submitted.
             * @param dt The simulator time step.
             * @return true if successful.
             */
            virtual Bool BeginSimulation(Real dt) = 0;
            /**
             * @brief Wait for the current simulation process to complete, after calling BeginSimulation().
             * @return true if successful.
             */
            virtual Bool EndSimulation() = 0;

            /**
             * @brief Set the current island affecting subsequent physics objects.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param island The island to activate.
             */
            virtual void SetCurrentIsland(IIsland* island) = 0;
            /**
             * @brief Set the current world transform affecting subsequent objects.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param transform The world transform to apply.
             * @param scaleFactor The world scale factor to apply.
             */
            virtual void SetCurrentTransform(const Matrix* transform, const Vector* scaleFactor) = 0;
            /**
             * @brief Set multiple surfaces affecting subsequent object collisions.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param surfaces An array of surfaces to apply.
             * @param numberOfSurfaces The actual number of surfaces to activate.
             */
            virtual void SetCurrentSurfaces(const ISurface** surfaces, UInt32 numberOfSurfaces) = 0;
            
            /**
             * @brief Attach a collidable geometry object to the current body for simulation.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param geometry The collidable geometry to attach.
             */
            virtual void PushGeometryToSimulate(IGeometry* geometry) = 0;
            /**
             * @brief Queue up a spring object for simulation.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param spring The spring to queue up.
             */
            virtual void PushSpringToSimulate(ISpring* spring) = 0;
            /**
             * @brief Queue up a joint object for simulation.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param joint The joint to queue up.
             */
            virtual void PushJointToSimulate(IJoint* joint) = 0;
            /**
             * @brief Queue up a field object for simulation.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param field The field to queue up.
             */
            virtual void PushFieldToSimulate(IField* field) = 0;
            /**
             * @brief Push a body to the internal stack for simulation.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param body The body to push.
             * @param worldTransform The output world transform return value.
             */
            virtual void PushBodyToSimulate(IBody* body, Matrix& worldTransform) = 0;
            /**
             * @brief Pop a body off the internal stack for simulation.
             * This method must only be called between BeginSubmission() and
             * EndSubmission().
             * @param body The body to pop.
             */
            virtual void PopBodyToSimulate(IBody* body) = 0;

            /**
             * @brief Check if the current island was reset.
             * @return true if reset.
             */
            virtual Bool WasReset() const = 0;

        protected:
            virtual ~ISimulator() {}

            friend class Factory;
        };
    }
}

#endif // __MURL_PHYSICS_I_SIMULATOR_H__

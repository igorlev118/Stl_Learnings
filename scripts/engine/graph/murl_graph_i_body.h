// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BODY_H__
#define __MURL_GRAPH_I_BODY_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Physics
    {
        class IBody;
    }
    
    namespace Graph
    {
        class ICollider;
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IBody
         * @brief The IBody graph node interface.
         * Body nodes are the basis for objects controlled by the framework's built-in
         * physics engine. A body has several properties that affect how it behaves in
         * the simulated environment, such as mass, friction coefficients, contact softness
         * etc. In addition, to be able to react to collisions with other bodies, it needs
         * to have one or more Graph::ICollider nodes attached, which can have different shapes
         * like planes, spheres or generic triangle meshes.
         *
         * To gain more control over which bodies can collide with other bodies, it is
         * possible to define up to 32 individual body groups. Each body may belong to
         * any number of these groups (including no group), regarding both triggering of and
         * responding to pending collision events (See SetTriggerGroupMask() and
         * SetResponseGroupMask(), respectively). These groups also determine a body's reaction
         * to the influence of a Graph::IField.
         *
         * See Graph::ICollidable to define a body's collision surface.\n
         * See Graph::IField to define fields acting on a body.
         */
        class IBody
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;
            
            /**
             * @brief Get the mutable Graph::ITransform interface.
             * This method returns a mutable pointer to the node's Graph::ITransform interface,
             * to be able to query or modify the node's transformation matrix and depth
             * order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's Graph::ITransform interface,
             * to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;
            
            /**
             * @brief Set the active collision trigger groups for this body.
             * The group assignment for triggering collisions is performed via a UInt32 bit
             * mask (up to 32 simultaneous groups), any individual bit set in the given mask
             * results in generating a collision event in the respective group (e.g. group
             * #5 for bit 5).
             * @param mask The group assignment bit mask.
             * @return true if successful.
             */
            virtual Bool SetTriggerGroupMask(UInt32 mask) = 0;
            /**
             * @brief Get the active collision trigger groups for this body.
             * @return The bit mask specifying active trigger groups.
             */
            virtual UInt32 GetTriggerGroupMask() const = 0;
            
            /**
             * @brief Set the active response groups for this body.
             * The group assignment for responding to collisions and field influence is performed
             * via a UInt32 bit mask (up to 32 simultaneous groups), any individual bit set in
             * the given mask results in a response to a pending collision event or field influence
             * in the respective group (e.g. group #5 for bit 5).
             * @param mask The group assignment bit mask.
             * @return true if successful.
             */
            virtual Bool SetResponseGroupMask(UInt32 mask) = 0;
            /**
             * @brief Get the active response groups for this body.
             * @return The bit mask specifying active response groups.
             */
            virtual UInt32 GetResponseGroupMask() const = 0;
            
            /**
             * @brief Set the body's mass.
             * This also affects the internal inverse mass value; therefore it is not possible
             * to set different values for mass and inverse mass.
             * @param mass The body's mass.
             * @return true if successful.
             */
            virtual Bool SetMass(Real mass) = 0;
            /**
             * @brief Get the body's mass.
             * @return The body's mass.
             */
            virtual Real GetMass() const = 0;
            
            /**
             * @brief Set the body's inverse mass.
             * To define VERY heavy bodies, it is possible to set the inverse mass to zero,
             * which results in an infinite mass for this body. In that case, the body will
             * not show any reaction on collision impacts from other (less heavy) bodies.
             * This also affects the internal mass value; therefore it is not possible to set
             * different values for mass and inverse mass.
             * @param inverseMass The body's inverse mass.
             * @return true if successful.
             */
            virtual Bool SetInverseMass(Real inverseMass) = 0;
            /**
             * @brief Get the body's inverse mass.
             * @return The body's inverse mass.
             */
            virtual Real GetInverseMass() const = 0;
            
            /**
             * @brief Set the body's drag coefficient (aka "cw" or "cd" value).
             * @param value The body's drag coefficient.
             * @return true if successful.
             */
            virtual Bool SetDragCoefficient(Real value) = 0;
            /**
             * @brief Get the body's drag coefficient.
             * @return The body's drag coefficient.
             */
            virtual Real GetDragCoefficient() const = 0;

            /**
             * @brief Set the physical size of the body.
             * This sets the actual physical size of the body, which is used internally
             * to calculate things like inertia tensor etc. It may actually differ from the
             * "real" size that is defined by the body's attached colliders.
             * @param size A vector containing the body's size in X, Y and Z dimensions.
             * @return true if successful.
             */
            virtual Bool SetSize(const Vector& size) = 0;
            /**
             * @brief Get the body's physical size.
             * @return A vector containing the body's size in X, Y and Z dimensions.
             */
            virtual const Vector& GetSize() const = 0;
            
            /**
             * @brief Enable/disable force effects on this body.
             * For certain special use cases, it may be desired to restrict the way a body
             * reacts on external influences. When both force effect and torque effect
             * (see SetTorqueEffectEnabled()) are enabled, the body reacts normally. When force
             * effect is enabled and torque effect disabled, any applied off-center forces will
             * result in a translation movement only. For disabled force effect and enabled
             * torque effect, the result will be a rotational movement only.
             * @param enabled If true, force effect is enabled.
             * @return true if successful.
             */
            virtual Bool SetForceEffectEnabled(Bool enabled) = 0;
            /**
             * @brief Check if force effect is enabled.
             * @return true if enabled.
             */
            virtual Bool IsForceEffectEnabled() const = 0;
            
            /**
             * @brief Enable/disable torque effects on this body.
             * See SetForceEffectEnabled() for details.
             * @param enabled If true, torque effect is enabled.
             * @return true if successful.
             */
            virtual Bool SetTorqueEffectEnabled(Bool enabled) = 0;
            /**
             * @brief Check if torque effect is enabled.
             * @return true if enabled.
             */
            virtual Bool IsTorqueEffectEnabled() const = 0;
            
            /**
             * @brief Enable/disable collision effect on this body.
             * @param enabled If true, collision effect is enabled.
             * @return true if successful.
             */
            virtual Bool SetCollisionEffectEnabled(Bool enabled) = 0;
            /**
             * @brief Check if collision effect is enabled.
             * @return true if enabled.
             */
            virtual Bool IsCollisionEffectEnabled() const = 0;
            
            /**
             * @brief Enable/disable collision reporting on this body.
             * @param enabled If true, collision reporting is enabled.
             * @return true if successful.
             */
            virtual Bool SetCollisionReportingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if collision reporting is enabled.
             * @return true if enabled.
             */
            virtual Bool IsCollisionReportingEnabled() const = 0;
            
            /**
             * @brief Apply both force and torque, given a relative force at a relative position.
             * The given input force vector is always relative to the untransformed body, e.g. for
             * an untransformed aeroplane with its nose pointing towards the -Z axis, its cockpit
             * towards the +Y axis and its right wing towards the +X axis, a force vector of
             * (0,0,-1) will always produce forward thrust, regardless of the plane's actual
             * orientation in world space.
             * The given position vector specifies the actual point where that force is applied;
             * this point is also relative to the untransformed body. If that point is not equal
             * to (0,0,0), the result will not only be a positional movement of the body, but will
             * also result in some torque value applied to the body, resulting in a spin. For the
             * previous example, if the plane's up vector is along the +Y axis, a position vector
             * of (0,1,0) will apply a torque forcing the plane's nose "down".
             * See also ApplyAbsoluteForceAndTorqueAtRelativePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyRelativeForceAndTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply both force and torque, given an absolute force at a relative position.
             * The given input force vector is absolute in world space. Taking the plane example
             * from ApplyRelativeForceAndTorqueAtRelativePoint(), with the world's north direction
             * towards -Z, east towards +X and increasing altitude towards +Y, applying a vector
             * of (1,0,0) will always represent west wind (blowing from west to east) acting on the
             * plane, regardless of its position and orientation in world space.
             * The given position vector specifies the actual point where that force is applied;
             * this point is relative to the untransformed body. If this vector equals (0,0,0),
             * no torque will be applied, and the plane will simply be blown off its course, keeping
             * its orientation. A vector of e.g. (0,0,-1) would result in a torque forcing the
             * plane's nose towards the direction of the wind.
             * @param p The position vector relative to the untransformed body.
             * @param f The absolute force direction in world space.
             */
            virtual void ApplyAbsoluteForceAndTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply both force and torque, given a relative force at an absolute position.
             * See also ApplyRelativeForceAndTorqueAtRelativePoint() and
             * ApplyAbsoluteForceAndTorqueAtRelativePoint().
             * TODO: Find a nice example.
             * @param p The absolute position vector in world space.
             * @param f The absolute force direction in world space.
             */
            virtual void ApplyRelativeForceAndTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply both force and torque, given an absolute force at an absolute position.
             * See also ApplyRelativeForceAndTorqueAtRelativePoint() and
             * ApplyAbsoluteForceAndTorqueAtRelativePoint().
             * TODO: Find a nice example.
             * @param p The absolute position vector in world space.
             * @param f The absolute force direction in world space.
             */
            virtual void ApplyAbsoluteForceAndTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            
            /**
             * @brief Apply force only, given a relative force at a relative position.
             * This method only applies a force influence, without applying any torque.
             * See also ApplyRelativeForceAndTorqueAtRelativePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyRelativeForceAtRelativePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply force only, given an absolute force at a relative position.
             * This method only applies a force influence, without applying any torque.
             * See also ApplyAbsoluteForceAndTorqueAtRelativePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyAbsoluteForceAtRelativePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply force only, given a relative force at an absolute position.
             * This method only applies a force influence, without applying any torque.
             * See also ApplyRelativeForceAndTorqueAtAbsolutePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyRelativeForceAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply force only, given an absolute force at an absolute position.
             * This method only applies a force influence, without applying any torque.
             * See also ApplyAbsoluteForceAndTorqueAtAbsolutePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyAbsoluteForceAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            
            /**
             * @brief Apply torque only, given a relative force at a relative position.
             * This method only applies a torque influence, without applying any force.
             * See also ApplyRelativeForceAndTorqueAtRelativePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyRelativeTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply torque only, given an absolute force at a relative position.
             * This method only applies a torque influence, without applying any force.
             * See also ApplyAbsoluteForceAndTorqueAtRelativePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyAbsoluteTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply torque only, given a relative force at an absolute position.
             * This method only applies a torque influence, without applying any force.
             * See also ApplyRelativeForceAndTorqueAtAbsolutePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyRelativeTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            /**
             * @brief Apply torque only, given an absolute force at an absolute position.
             * This method only applies a torque influence, without applying any force.
             * See also ApplyAbsoluteForceAndTorqueAtAbsolutePoint().
             * @param p The position vector relative to the untransformed body.
             * @param f The force direction vector relative to the untransformed body.
             */
            virtual void ApplyAbsoluteTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            
            /**
             * @brief Get the currently acting linear momentum.
             * @return A vector containing the current linear momentum.
             */
            virtual Vector GetLinearMomentum() const = 0;
            /**
             * @brief Get the currently acting angular momentum.
             * @return A vector containing the current angular momentum.
             */
            virtual Vector GetAngularMomentum() const = 0;
            
            /**
             * @brief Get the body's current linear velocity.
             * @return A vector containing the current linear velocity.
             */
            virtual Vector GetLinearVelocity() const = 0;
            /**
             * @brief Get the body's current angular velocity.
             * @return A vector containing the current angular velocity.
             */
            virtual Vector GetAngularVelocity() const = 0;
            
            /**
             * @brief Get the number of individual collisions.
             * This returns the total number of individual collisions that occurred during the
             * last simulation step on the body. After each step, this number is reset to zero,
             * and new collisions are evaluated.
             * @return The total number of individual collisions.
             */
            virtual UInt32 GetNumberOfCollisions() const = 0;
            /**
             * @brief Get the actual incidence point for a specific collision.
             * This returns the incidence point for a given collision in world coordinates.
             * @param collisionIndex The collision index, in the range from 0 to GetNumberOfCollisions().
             * @return a constant pointer to the wold collision point, or null if the
             *      index was out of range.
             */
            virtual const Vector* GetCollisionWorldPoint(UInt32 collisionIndex) const = 0;
            /**
             * @brief Get the normal vector of the collision.
             * @param collisionIndex The collision index, in the range from 0 to GetNumberOfCollisions().
             * @return a constant pointer to the wold collision normal, or null if the
             *      index was out of range.
             */
            virtual const Vector* GetCollisionWorldDirection(UInt32 collisionIndex) const = 0;
            /**
             * @brief Get the depth of the collision along the collision's normal vector.
             * @param collisionIndex The collision index, in the range from 0 to GetNumberOfCollisions().
             * @return The collision depth, or 0.0 if the index was out of range.
             */
            virtual Real GetCollisionDepth(UInt32 collisionIndex) const = 0;
            /**
             * @brief Get a body involved in a specific collision.
             * Individual collisions always occur between only two bodies; if during a simulation
             * step a body collides with more than one other body (or with the same body at more
             * than one contact point), a number of individual pair-wise collisions are generated.
             * @param collisionIndex The collision index, in the range from 0 to GetNumberOfCollisions().
             * @param bodyIndex The index of the collision body, either 0 for this body or 1 for the other one.
             * @return a pointer to the involved body, or null if the index was out of range.
             */
            virtual IBody* GetCollisionBody(UInt32 collisionIndex, UInt32 bodyIndex) const = 0;
            /**
             * @brief Get the actual collider of a body involved in a specific collision.
             * @param collisionIndex The collision index, in the range from 0 to GetNumberOfCollisions().
             * @param bodyIndex The index of the collision body, either 0 for this body or 1 for the other one.
             * @return a pointer to involved body's collider, or null if the index was out of range.
             */
            virtual ICollider* GetCollisionGeometry(UInt32 collisionIndex, UInt32 bodyIndex) const = 0;
            /**
             * @brief Get the surface index of a collision.
             * @param collisionIndex The collision index, in the range from 0 to GetNumberOfCollisions().
             * @param bodyIndex The index of the collision body for which to get the index, either 0
             *      for this body or 1 for the other one.
             * @return The surface index.
             */
            virtual UInt32 GetCollisionSurfaceIndex(UInt32 collisionIndex, UInt32 bodyIndex) const = 0;
            /**
             * @brief DEPRECATED: Get the partner of a specific collision.
             * Use GetCollisionBody(collisionIndex, 1) instead.
             * @param collisionIndex The collision index, in the range from 0 to GetNumberOfCollisions().
             * @return a pointer to the collision's other involved body, or null if the index
             *      was out of range.
             */
            virtual IBody* GetCollisionPartner(UInt32 collisionIndex) const = 0;
            /**
             * @brief Resolve all collisions, optionally with a given partner only.
             * This method tries to resolve all pending collisions of this body, optionally
             * restricted to collisions with a given partner only. The result is
             * a direction vector that represents the world space offset to be applied
             * to the body so that it does not collide with any other objects anymore.
             * If no collisions are pending, a zero direction vector is returned.
             * Applying the resulting offset vector to a body's position should be done
             * only on bodies for which the collision/force/torque effect is manually disabled,
             * e.g. a player character that should be precisely controlled by explicitly
             * setting its velocity instead of applying forces.
             * Setting the "margin" parameter to a positive non-zero value pushes all
             * collisions "inward" by that distance. This allows to also detect collisions that
             * do not actually occur, but become relevant during collision resolution.
             * Ideally, this value should be set to the maximum distance a body can be moved
             * between subsequent ticks, but may be lower. However, any collision geometry
             * used must be enlarged by that value to give the same result.
             * @param partner The collision partner to query, or null if all partners should
             *      be queried.
             * @param margin The collision margin.
             * @return The offset vector.
             */
            virtual Vector ResolveCollisions(const IBody* partner, Real margin) const = 0;

            /**
             * @brief Get a constant reference to the body's current world transform matrix.
             * @return The world transform.
             */
            virtual const Matrix& GetBodyTransform() const = 0;
            /**
             * @brief Get a mutable reference to the body's current world transform matrix.
             * @return The world transform.
             */
            virtual Matrix& GetBodyTransform() = 0;

            /**
             * @brief Get the body's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the body's internal physics simulator object.
             * @param stage The stage to query.
             * @return The physics simulator object.
             */
            virtual Physics::IBody* GetPhysicsBodyObject(UInt32 stage) const = 0;
            
        protected:
            virtual ~IBody() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IBody nodes.
         */
        typedef IGenericNodeTarget<IBody> IBodyNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BODY_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_I_BODY_H__
#define __MURL_PHYSICS_I_BODY_H__

#include "murl_physics_types.h"

namespace Murl
{
    namespace Physics
    {
        class ICollidable;
        class IGeometry;
        class IObject;
        class ISurface;

        class IBody
        {
        public:
            virtual IObject* GetObjectInterface() = 0;
            virtual const IObject* GetObjectInterface() const = 0;
            
            virtual Bool SetTriggerMask(UInt32 triggerMask) = 0;
            virtual UInt32 GetTriggerMask() const = 0;
            
            virtual Bool SetResponseMask(UInt32 responseMask) = 0;
            virtual UInt32 GetResponseMask() const = 0;
            
            virtual Bool SetForceEffect(Bool enabled) = 0;
            virtual Bool IsAffectedByForce() const = 0;

            virtual Bool SetTorqueEffect(Bool enabled) = 0;
            virtual Bool IsAffectedByTorque() const = 0;

            virtual Bool EmptyGeometries() = 0;
            virtual Bool EmptyChildren() = 0;

            virtual Bool AddGeometry(IGeometry* geometry, IBody* controllerBody, const ISurface** surfaces, UInt32 numSurfaces, const Matrix& transform, const Vector& scaleFactor) = 0;
            virtual Bool AttachToParent(IBody* parent) = 0;
            virtual IBody* GetParent() const = 0;
            
            virtual Bool SetInverseMass(Real inverseMass) = 0;
            virtual Real GetInverseMass() const = 0;
            
            virtual Bool SetDragCoefficient(Real dragCoefficient) = 0;
            virtual Real GetDragCoefficient() const = 0;

            virtual Bool SetSize(Vector size) = 0;
            virtual const Vector& GetSize() const = 0;

            virtual Bool ApplyRelativeForceAndTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyAbsoluteForceAndTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyRelativeForceAndTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyAbsoluteForceAndTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;

            virtual Bool ApplyRelativeForceAtRelativePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyAbsoluteForceAtRelativePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyRelativeForceAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyAbsoluteForceAtAbsolutePoint(const Vector& p, const Vector& f) = 0;

            virtual Bool ApplyRelativeTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyAbsoluteTorqueAtRelativePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyRelativeTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;
            virtual Bool ApplyAbsoluteTorqueAtAbsolutePoint(const Vector& p, const Vector& f) = 0;

            virtual Bool SetWorldTransform(Matrix& worldTransform) = 0;
            virtual Bool SetLocalTransform(const Matrix& localTransform) = 0;

            virtual Bool SetResponseTarget(ICollidable* node) = 0;
            virtual ICollidable* GetResponseTarget() const = 0;

            virtual Bool SetCollisionEnabled(Bool enabled) = 0;
            virtual Bool IsCollisionEnabled() const = 0;
            
            virtual Bool SetResponseEnabled(Bool enabled) = 0;
            virtual Bool IsResponseEnabled() const = 0;

            virtual Bool ClearForce() = 0;
            virtual Bool ClearTorque() = 0;

            virtual Bool ClearLinearVelocityAndMomentum() = 0;
            virtual Bool ClearAngularVelocityAndMomentum() = 0;

            virtual Vector GetLinearMomentum() const = 0;
            virtual Vector GetAngularMomentum() const = 0;

            virtual Vector GetLinearVelocity() const = 0;
            virtual Vector GetAngularVelocity() const = 0;

        protected:
            virtual ~IBody() {}
        };
    }
}

#endif // __MURL_PHYSICS_I_BODY_H__

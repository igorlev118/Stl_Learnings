// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BOUNDING_VOLUME_H__
#define __MURL_GRAPH_I_BOUNDING_VOLUME_H__

#include "murl_graph_types.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphMiscInterfaces
         * @interface IBoundingVolume
         * @brief The IBoundingVolume interface.
         * This interface represents a simple bounding volume in 3D space that encloses the 
         * outer bounds of some geometry, which are used for e.g. visibility determination 
         * (a.k.a. culling), and optionally provides an "inner" volume that is used for
         * alignment purposes.
         */
        class IBoundingVolume
        {
        public:
            /**
             * @brief Clear the bounding volume.
             * This method clears the bounding value by setting all of its internal values
             * to zero.
             * @return true if successful.
             */
            virtual Bool Clear() = 0;
            
            /**
             * @brief Set the local bounding volume extent from a box.
             * @param box The local bounding box.
             * @return true if successful.
             */
            virtual Bool SetLocalBounds(const Box& box) = 0;
            /**
             * @brief Set the local bounding volume extent.
             * This method sets the bounding volume to enclose the given minimum and maximum values
             * in local 3D (object) space.
             * @param minExtent A vector containing minimum X, Y and Z values of a bounding box.
             * @param maxExtent A vector containing maximum X, Y and Z values of a bounding box.
             * @return true if successful.
             */
            virtual Bool SetLocalBounds(const Vector& minExtent, const Vector& maxExtent) = 0;

            /**
             * @brief Set the local bounding volume extent from an inner and outer box.
             * @param outerBox The local outer bounding box.
             * @param innerBox The local inner bounding box.
             * @return true if successful.
             */
            virtual Bool SetLocalBounds(const Box& outerBox, const Box& innerBox) = 0;
            /**
             * @brief Set the local bounding volume extent.
             * This method sets the bounding volume to enclose the given minimum and maximum values
             * in local 3D (object) space, for both an inner and outer box.
             * @param minOuterExtent A vector containing minimum values of the outer bounding box.
             * @param maxOuterExtent A vector containing maximum values of the outer bounding box.
             * @param minInnerExtent A vector containing minimum values of the inner bounding box.
             * @param maxInnerExtent A vector containing maximum values of the inner bounding box.
             * @return true if successful.
             */
            virtual Bool SetLocalBounds(const Vector& minOuterExtent, const Vector& maxOuterExtent,
                                        const Vector& minInnerExtent, const Vector& maxInnerExtent) = 0;
            
            /**
             * @brief Set the local bounding volume extent from a sphere.
             * @param sphere The local bounding sphere.
             * @return true if successful.
             */
            virtual Bool SetLocalBounds(const Sphere& sphere) = 0;
            /**
             * @brief Set the local bounding volume extent.
             * This method sets the bounding volume to enclose the sphere represented by the given
             * sphere center and radius.
             * @param sphereCenter The bounding sphere center.
             * @param sphereRadius The bounding sphere radius.
             * @return true if successful.
             */
            virtual Bool SetLocalBounds(const Vector& sphereCenter, Real sphereRadius) = 0;
            
            /**
             * @brief Unite the local bounding volume with a given other one.
             * @param other The other bounding volume to unite with.
             * @return true if successful.
             */
            virtual Bool UniteLocalBounds(const IBoundingVolume* other) = 0;
            /**
             * @brief Unite the local bounding volume with a given other one using an additional transformation.
             * @param other The other bounding volume to unite with.
             * @param baseTransform The transform to apply to the other volume.
             * @param baseScale The scale factor to apply to the other volume.
             * @return true if successful.
             */
            virtual Bool UniteLocalBounds(const IBoundingVolume* other, const Matrix& baseTransform, const Vector& baseScale) = 0;
            
            /**
             * @brief Get the bounding sphere in object space.
             * @return A constant reference to the local object space bounding sphere.
             */
            virtual const Sphere& GetLocalSphere() const = 0;
            /**
             * @brief Get the bounding sphere in world space.
             * @return A constant reference to the world space bounding sphere.
             */
            virtual const Sphere& GetWorldSphere() const = 0;
            /**
             * @brief Calculate the bounding sphere relative to a given base transform and scale.
             * @param baseTransform The base transform to use.
             * @param baseScale The base scale factor to use.
             * @return The calculated sphere.
             */
            virtual Sphere CalculateWorldSphereRelativeToBase(const Matrix& baseTransform, const Vector& baseScale) const = 0;
            /**
             * @brief Calculate the bounding sphere relative to a given view transform and scale.
             * @param viewTransform The view transform to use.
             * @param viewScale The view scale factor to use.
             * @return The calculated sphere.
             */
            virtual Sphere CalculateWorldSphereRelativeToView(const Matrix& viewTransform, const Vector& viewScale) const = 0;
            
            /**
             * @brief Get the outer bounding box in object space.
             * @return A constant reference to the local object space outer bounding box.
             */
            virtual const Box& GetOuterLocalBox() const = 0;
            /**
             * @brief Get the outer bounding box in world space.
             * @return A constant reference to the world space outer bounding box.
             */
            virtual const Box& GetOuterWorldBox() const = 0;
            /**
             * @brief Calculate the outer bounding box relative to a given base transform and scale.
             * @param baseTransform The base transform to use.
             * @param baseScale The base scale factor to use.
             * @return The calculated box.
             */
            virtual Box CalculateOuterWorldBoxRelativeToBase(const Matrix& baseTransform, const Vector& baseScale) const = 0;
            /**
             * @brief Calculate the outer bounding box relative to a given view transform and scale.
             * @param viewTransform The view transform to use.
             * @param viewScale The view scale factor to use.
             * @return The calculated box.
             */
            virtual Box CalculateOuterWorldBoxRelativeToView(const Matrix& viewTransform, const Vector& viewScale) const = 0;
            
            /**
             * @brief Get the inner bounding box in object space.
             * @return A constant reference to the local object space inner bounding box.
             */
            virtual const Box& GetInnerLocalBox() const = 0;
            /**
             * @brief Get the inner bounding box in world space.
             * @return A constant reference to the world space inner bounding box.
             */
            virtual const Box& GetInnerWorldBox() const = 0;
            /**
             * @brief Calculate the inner bounding box relative to a given base transform and scale.
             * @param baseTransform The base transform to use.
             * @param baseScale The base scale factor to use.
             * @return The calculated box.
             */
            virtual Box CalculateInnerWorldBoxRelativeToBase(const Matrix& baseTransform, const Vector& baseScale) const = 0;
            /**
             * @brief Calculate the inner bounding box relative to a given view transform and scale.
             * @param viewTransform The view transform to use.
             * @param viewScale The view scale factor to use.
             * @return The calculated box.
             */
            virtual Box CalculateInnerWorldBoxRelativeToView(const Matrix& viewTransform, const Vector& viewScale) const = 0;
            
            /**
             * @brief Set the bounding volume's current world transform matrix.
             * @param worldTransform The world transform matrix.
             * @return true if successful.
             */
            virtual Bool SetWorldTransform(const Matrix& worldTransform) = 0;
            /**
             * @brief Clear the bounding volume's current world transform matrix.
             * @return true if successful.
             */
            virtual Bool ClearWorldTransform() = 0;
            /**
             * @brief Get the bounding volume's current world transform matrix.
             * @return The world transform matrix.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            
            /**
             * @brief Set the bounding volume's current world scale factor.
             * @param worldScaleFactor The world scale factor in X, Y and Z direction.
             * @return true if successful.
             */
            virtual Bool SetWorldScaleFactor(const Vector& worldScaleFactor) = 0;
            /**
             * @brief Reset the bounding volume's current world scale factor to 1.
             * @return true if successful.
             */
            virtual Bool ClearWorldScaleFactor() = 0;
            /**
             * @brief Get the bounding volume's current world scale factor.
             * @return The world scale factor in X, Y and Z direction.
             */
            virtual const Vector& GetWorldScaleFactor() const = 0;
            
            /**
             * @brief Check if the bounding volume intersects another one.
             * @param other The bounding volume to check against.
             * @return true if both volumes are intersecting.
             */
            virtual Bool IsIntersecting(const IBoundingVolume* other) const = 0;
            /**
             * @brief Check if the bounding volume is empty.
             * @return true if the volume is empty.
             */
            virtual Bool IsEmpty() const = 0;
            /**
             * @brief Check if the bounding volume has an inner box.
             * @return true if the volume has an inner box.
             */
            virtual Bool HasInnerBox() const = 0;

        protected:
            virtual ~IBoundingVolume() {}
        };
    }
}

#endif // __MURL_GRAPH_I_BOUNDING_VOLUME_H__

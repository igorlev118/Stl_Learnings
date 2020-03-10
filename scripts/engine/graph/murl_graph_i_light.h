// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LIGHT_H__
#define __MURL_GRAPH_I_LIGHT_H__

#include "murl_graph_i_colored.h"
#include "murl_graph_i_state_unit.h"
#include "murl_graph_i_texture.h"
#include "murl_graph_i_subject.h"
#include "murl_math_sphere.h"
#include "murl_i_enums.h"

namespace Murl
{
    class Color;

    namespace Video
    {
        class ILight;
        class ITexture;
    }

    namespace Graph
    {
        class ILight;
        class ITexture;
        class IBoundingVolume;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ILight nodes.
         */
        typedef IGenericNodeTarget<ILight> ILightNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ILight
         * @brief The ILight graph node interface.
         * This interface represents a light source in world space. The light's position
         * and direction cannot be specified directly; instead, a separate ILightTransform
         * node must be used that references the ILight node it is supposed to move/rotate.
         *
         * To enable colored light, the SetColor() method of the Graph::IColored base interface
         * can be used.
         *
         * By default, the light source's direction runs along the negative Z axis, i.e.
         * parallel to the default camera viewing direction. The default position is (0/0/0).
         * Depending on the actual type of this light source, either the light's position,
         * direction, or both are used for lighting calculations:
         * - DIRECTIONAL: Only direction is used. The light's position is ignored, resulting
         *      in parallel light rays, like a light source inifinitely far away.
         * - POINT: Only position is used, with light rays emitted in all directions from that
         *      point.
         * - SPOT: Light rays are emitted from the given point, in the given direction.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene
         * graph traversal.\n
         * See Graph::ILightTransform for setting a light's position and orientation.\n
         * See Graph::ILightState for activating lights for rendering.
         */
        class ILight : public IColored, public IStateUnit
        {
        public:
            /**
             * @brief Get the mutable INode interface.
             * This method returns a mutable pointer to the node's INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable INode interface, or null if not available.
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant INode interface.
             * This method returns a constant pointer to the node's INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant INode interface, or null if not available.
             */
            virtual const INode* GetNodeInterface() const = 0;

            /**
             * @brief Get the mutable ISubject interface.
             * This method returns a mutable pointer to the node's ISubject interface, to
             * be able to query or modify subject properties such as world transform,
             * viewing matrix, projection matrix etc.
             * @return The mutable ISubject interface, or null if not available
             */
            virtual ISubject* GetSubjectInterface() = 0;
            /**
             * @brief Get the constant ISubject interface.
             * This method returns a constant pointer to the node's ISubject interface, to
             * be able to query subject properties such as world transform, viewing
             * matrix, projection matrix etc.
             * @return The mutable ISubject interface, or null if not available
             */
            virtual const ISubject* GetSubjectInterface() const = 0;

            /**
             * @brief Get the mutable container holding the optional child lights.
             * This method returns a mutable pointer to the node's Graph::ILightNodeTarget
             * sub container, which is used to store multiple sub-lights.
             * @return The mutable Graph::ILightNodeTarget container, or null if not available.
             */
            virtual ILightNodeTarget* GetSubLightNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the optional child lights.
             * This method returns a constant pointer to the node's Graph::ILightNodeTarget
             * sub container, which is used to store multiple sub-lights.
             * @return The constant Graph::ILightNodeTarget container, or null if not available.
             */
            virtual const ILightNodeTarget* GetSubLightNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::ITextureNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ITextureNodeTarget
             * container, which allows to set or query an optional texture to project onto the
             * geometry affected by the light.
             * @return The mutable Graph::ITextureNodeTarget container, or null if not available.
             */
            virtual ITextureNodeTarget* GetTextureNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITextureNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ITextureNodeTarget
             * container, which allows to query an optional texture to project onto the
             * geometry affected by the light.
             * @return The mutable Graph::ITextureNodeTarget container, or null if not available.
             */
            virtual const ITextureNodeTarget* GetTextureNodeTarget() const = 0;

            /**
             * @brief Set the light type.
             * This method sets the type of light, either directional, point or spot light.
             * @param type The light type to set.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::LightType type) = 0;
            /**
             * @brief Get the light type.
             * @return The light type.
             */
            virtual IEnums::LightType GetType() const = 0;
            
            /**
             * @brief Set the light shape.
             * This method sets the shape of the light's projection. This is only useful when
             * a projected light texture is used.
             * @param shape The light shape to set.
             * @return true if successful.
             */
            virtual Bool SetShape(IEnums::LightShape shape) = 0;
            /**
             * @brief Get the light shape.
             * @return The light shape.
             */
            virtual IEnums::LightShape GetShape() const = 0;

            /**
             * @brief Set the light intensity.
             * The light intensity can be queried in a shader via the uLightSpotN.z uniform
             * variable, with N being the light unit where the light is currently bound.
             * By default, the intensity is set to 1.0.
             * @param intensity The light intensity to set.
             * @return true if successful.
             */
            virtual Bool SetIntensity(Real intensity) = 0;
            /**
             * @brief Get the light intensity.
             * @return The light intensity.
             */
            virtual Real GetIntensity() const = 0;

            /**
             * @brief Set the light attenuation parameters.
             * This method sets all three light attenuation parameters (constant, linear and
             * quadratic), packed into a given vector's X, Y and Z components, respectively.
             * @param values A vector holding the light attenuation parameters.
             * @return true if successful.
             */
            virtual Bool SetAttenuation(const Vector& values) = 0;
            /**
             * @brief Set the light attenuation parameters.
             * This method sets all three light attenuation parameters (constant, linear and
             * quadratic), given as individual values.
             * @param constant The constant light attenuation value.
             * @param linear The linear light attenuation value.
             * @param quadratic The quadratic light attenuation value.
             * @return true if successful.
             */
            virtual Bool SetAttenuation(Real constant, Real linear, Real quadratic) = 0;
            /**
             * @brief Set the constant light attenuation parameter.
             * @param value The constant light attenuation value.
             * @return true if successful.
             */
            virtual Bool SetConstantAttenuation(Real value) = 0;
            /**
             * @brief Set the linear light attenuation parameter.
             * @param value The linear light attenuation value.
             * @return true if successful.
             */
            virtual Bool SetLinearAttenuation(Real value) = 0;
            /**
             * @brief Set the quadratic light attenuation parameter.
             * @param value The quadratic light attenuation value.
             * @return true if successful.
             */
            virtual Bool SetQuadraticAttenuation(Real value) = 0;
            /**
             * @brief Get the light attenuation parameters.
             * @return A vector holding the light attenuation parameters, packed into its
             *      X, Y and Z components.
             */
            virtual const Vector& GetAttenuation() const = 0;
            /**
             * @brief Get the constant light attenuation parameter.
             * @return The constant light attenuation value.
             */
            virtual Real GetConstantAttenuation() const = 0;
            /**
             * @brief Get the linear light attenuation parameter.
             * @return The linear light attenuation value.
             */
            virtual Real GetLinearAttenuation() const = 0;
            /**
             * @brief Get the quadratic light attenuation parameter.
             * @return The quadratic light attenuation value.
             */
            virtual Real GetQuadraticAttenuation() const = 0;
            
            /**
             * @brief Set the combined spot exponent and cutoff angle value.
             * @param values A vector containing the spot exponent value in the range [0, 128] in
             *      the X component, and the spot cutoff angle in the range [0, PI/2] radians in the
             *      Y component.
             * @return true if successful.
             */
            virtual Bool SetSpot(const Vector& values) = 0;
            /**
             * @brief Set the spot exponent and cutoff angle value.
             * @param exponent The spot exponent value in the range [0, 128].
             * @param cutoffAngle The spot cutoff angle in the range [0, PI/2] radians.
             * @return true if successful.
             */
            virtual Bool SetSpot(Real exponent, Real cutoffAngle) = 0;
            /**
             * @brief Set the spot exponent value.
             * @param exponent The spot exponent value in the range [0, 128].
             * @return true if successful.
             */
            virtual Bool SetSpotExponent(Real exponent) = 0;
            /**
             * @brief Set the spot cutoff angle in degrees.
             * @param cutoffAngle The spot cutoff angle in the range [0, PI/2].
             * @return true if successful.
             */
            virtual Bool SetSpotCutoffAngle(Real cutoffAngle) = 0;
            /**
             * @brief Get the combined spot exponent and cutoff angle value.
             * @return A constant reference to a  vector containing the spot exponent value in the range [0, 128] in
             *      the X component, and the spot cutoff angle in the range [0, PI/2] radians in the
             *      Y component.
             */
            virtual const Vector& GetSpot() const = 0;
            /**
             * @brief Get the spot exponent value.
             * @return The spot exponent value in the range [0, 128].
             */
            virtual Real GetSpotExponent() const = 0;
            /**
             * @brief Get the spot cutoff angle in radians.
             * @return The spot cutoff angle in the range [0, PI/2].
             */
            virtual Real GetSpotCutoffAngle() const = 0;

            /**
             * @brief Set the light's aspect ratio used for shadow maps.
             * When using directional or point lights for rendering into a shadow
             * map, this method (together with any of the SetFieldOfView methods
             * below) can be used to define the actual volume considered for generating
             * the shadow map.
             * @param ratio The X:Y aspect ratio.
             * @return true if successful.
             */
            virtual Bool SetAspectRatio(Real ratio) = 0;
            /**
             * @brief Get the current aspect ratio.
             * @return The X:Y aspect ratio.
             */
            virtual Real GetAspectRatio() const = 0;

            /**
             * @brief Set the field of view at the minimum distance.
             * This method sets both the horizontal and vertical field of view values.
             * See SetAspectRatio().
             * @param fovX The horizontal field of view.
             * @param fovY The vertical field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfView(Real fovX, Real fovY) = 0;
            /**
             * @brief Set the horizontal field of view, at the minimum distance.
             * See SetAspectRatio().
             * @param fovX The horizontal field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfViewX(Real fovX) = 0;
            /**
             * @brief Set the vertical field of view, at the minimum distance.
             * See SetAspectRatio().
             * @param fovY The vertical field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfViewY(Real fovY) = 0;
            /**
             * @brief Get the horizontal field of view.
             * @return The horizontal field of view, or 0.0 if variable.
             */
            virtual Real GetFieldOfViewX() const = 0;
            /**
             * @brief Get the vertical field of view.
             * @return The vertical field of view, or 0.0 if variable.
             */
            virtual Real GetFieldOfViewY() const = 0;

            /**
             * @brief Set the light's minimum influence radius.
             * The given value only has effect when rendering a projected light texture.
             * In this case, it represents the near plane distance of the light projection
             * matrix.
             * @param distance The minimum distance.
             * @return true if successful.
             */
            virtual Bool SetMinDistance(Real distance) = 0;
            /**
             * @brief Set the light's maximum influence radius.
             * This method sets the radius of the light's bounding sphere, which is used
             * to determine the nearest light source within a group, for every geometry
             * object for which the respective group is active. For rendering projected
             * light textures, this also represents the far plane of the light projection
             * matrix.
             * @param distance The radius of the bounding sphere.
             * @return true if successful.
             */
            virtual Bool SetMaxDistance(Real distance) = 0;
            
            /**
             * @brief Get the stage indices of the N nearest sub-lights.
             * @param boundingVolume The bounding volume to check the sub-lights against.
             * @param stageIndices A reference to an array of stage indices to write to.
             * @param maxStages The size of the output array.
             * @return The actual number of stage indices written.
             */
            virtual UInt32 GetNearestStages(const IBoundingVolume* boundingVolume, Array<UInt32>& stageIndices, UInt32 maxStages) const = 0;
            /**
             * @brief Get the light's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the light's bounding volume for a given stage.
             * @param stage The stage to query.
             * @return The bounding volume, or null if the light has infinite influence.
             */
            virtual IBoundingVolume* GetBoundingVolume(UInt32 stage) = 0;
            /**
             * @brief Get the light's bounding volume for a given stage.
             * @param stage The stage to query.
             * @return The bounding volume, or null if the light has infinite influence.
             */
            virtual const IBoundingVolume* GetBoundingVolume(UInt32 stage) const = 0;
            /**
             * @brief Get the light's world transform for a given stage.
             * @param stage The stage to query.
             * @return The world transform matrix, or null if not available.
             */
            virtual const Matrix* GetWorldTransform(UInt32 stage) const = 0;
            /**
             * @brief Get the light attenuation parameters for a given stage.
             * @param stage The stage to query.
             * @return A vector holding the light attenuation parameters, packed into its
             *      X, Y and Z components.
             */
            virtual const Vector* GetAttenuation(UInt32 stage) const = 0;
            /**
             * @brief Get the combined spot exponent and cutoff angle value for a given stage.
             * @param stage The stage to query.
             * @return A constant reference to a  vector containing the spot exponent value in the range [0, 128] in
             *      the X component, and the spot cutoff angle in the range [0, 90] degrees in the
             *      Y component.
             */
            virtual const Vector* GetSpot(UInt32 stage) const = 0;
            /**
             * @brief Get the light's minimum influence distance for a given stage.
             * @param stage The stage to query.
             * @return The minimum distance.
             */
            virtual Real GetMinDistance(UInt32 stage) const = 0;
            /**
             * @brief Get the light's maximum influence radius for a given stage.
             * @param stage The stage to query.
             * @return The maximum distance.
             */
            virtual Real GetMaxDistance(UInt32 stage) const = 0;
            /**
             * @brief Get the light's internal video renderer object.
             * @param stage The stage to query.
             * @return The video renderer object.
             */
            virtual Video::ILight* GetVideoLightObject(UInt32 stage) const = 0;
            /**
             * @brief Get the light's internal projected renderer texture.
             * @param stage The stage to query.
             * @return The video renderer texture.
             */
            virtual Video::ITexture* GetVideoTextureObject(UInt32 stage) const = 0;

        protected:
            virtual ~ILight() {}
        };
    }
}

#endif // __MURL_GRAPH_I_LIGHT_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_LIGHT_H__
#define __MURL_VIDEO_I_LIGHT_H__

#include "murl_video_types.h"
#include "murl_color.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IProgram;
        class ICamera;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface ILight
         * @brief The ILight video object interface.
         * This interface represents a light source used during rendering.
         *
         * Used internally by Graph::Light.
         */
        class ILight
        {
        public:
            /**
             * @brief Get the mutable Video::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Video::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Enable the light at a given unit.
             * @param unit The light unit, from 0 to IEnums::NUM_LIGHT_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Enable(UInt32 unit) = 0;
            /**
             * @brief Disable the light at a given unit.
             * @param unit The light unit, from 0 to IEnums::NUM_LIGHT_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Disable(UInt32 unit) = 0;

            /**
             * @brief Attach the light to the current GPU program at a given unit.
             * @param currentProgram The current GPU program.
             * @param unit The light unit, from 0 to IEnums::NUM_LIGHT_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram, UInt32 unit) = 0;
        
            /**
             * @brief Set the color value of a given lighting component.
             * @param component The lighting component.
             * @param color The color to set.
             * @return true if successful.
             */
            virtual Bool SetColor(IEnums::LightingComponent component, const Color& color) = 0;
            /**
             * @brief Get the color value set for a given lighting component.
             * @param component The lighting component.
             * @return The current color.
             */
            virtual const Color& GetColor(IEnums::LightingComponent component) const = 0;

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
             * @brief Set the light attenuation parameters and maximum distance.
             * This method sets all three light attenuation parameters (constant, linear and
             * quadratic), packed into a given vector's X, Y and Z components, respectively.
             * In addition, the maximum distance contained in the vector's W component is
             * also set.
             * @param values A vector holding the light attenuation and maximum distance parameters.
             * @return true if successful.
             */
            virtual Bool SetAttenuation(const Vector& values) = 0;
            /**
             * @brief Set the light attenuation parameters and maximum distance.
             * This method sets all three light attenuation parameters (constant, linear and
             * quadratic) and the maximum distance, given as individual values.
             * @param constant The constant light attenuation value.
             * @param linear The linear light attenuation value.
             * @param quadratic The quadratic light attenuation value.
             * @param maxDistance The maximum distance value.
             * @return true if successful.
             */
            virtual Bool SetAttenuation(Real constant, Real linear, Real quadratic, Real maxDistance) = 0;
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
             * @brief Set the light's maximum influence radius.
             * @param value The radius of the bounding sphere.
             * @return true if successful.
             */
            virtual Bool SetMaxDistance(Real value) = 0;
            /**
             * @brief Get the light attenuation parameters and maximum distance.
             * @return A vector holding the light attenuation parameters, packed into its
             *      X, Y and Z components, and the maximum distance in the W component.
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
             * @brief Get the light's maximum influence radius.
             * @return The radius of the bounding sphere.
             */
            virtual Real GetMaxDistance() const = 0;
            
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
             * @brief Set the light's current world transform.
             * @param transform The current world transform.
             * @return true if successful.
             */
            virtual Bool SetWorldTransform(const Matrix& transform) = 0;
            /**
             * @brief Set the light's projection matrix.
             * @param projection The projection matrix.
             * @return true if successful.
             */
            virtual Bool SetLightProjection(const Matrix& projection) = 0;
            /**
             * @brief Set the light's shadow view/projection matrix for a given cascade.
             * @param viewProjection The view/projection matrix.
             * @param cascadeIndex The cascade index, in the range [0..3]
             * @return true if successful.
             */
            virtual Bool SetShadowViewProjection(const Matrix& viewProjection, UInt32 cascadeIndex) = 0;

            /**
             * @brief Get the current light position in world space.
             * @return The current light position.
             */
            virtual const Vector& GetWorldPosition() const = 0;
            /**
             * @brief Get the current light direction in world space.
             * @return The current light direction.
             */
            virtual const Vector& GetWorldDirection() const = 0;
            /**
             * @brief Get the light's current world transform.
             * @return The current world transform.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            /**
             * @brief Get the light's projection matrix.
             * @return The projection matrix.
             */
            virtual const Matrix& GetLightProjection() const = 0;
            /**
             * @brief Get the light's current view matrix.
             * This equals the inverse of the current world transform.
             * @return The current view matrix.
             */
            virtual const Matrix& GetLightView() const = 0;
            /**
             * @brief Get the light's combined current view and projection matrix.
             * @return The current view/projection matrix.
             */
            virtual const Matrix& GetLightViewProjection() const = 0;
            /**
             * @brief Get the light's combined current shadow view and projection matrix for a given cascade.
             * @param cascadeIndex The cascade index, in the range [0..3]
             * @return The current shadow view/projection matrix.
             */
            virtual const Matrix& GetShadowViewProjection(UInt32 cascadeIndex) const = 0;

            /**
             * @brief Calculate the screen area affected by the light with respect to a camera.
             * @param camera The camera.
             * @return A rectangle of the affected screen area.
             */
            virtual Rectangle CalculateScreenArea(const ICamera* camera) = 0;

        protected:
            virtual ~ILight() {}
        };
    }
}

#endif // __MURL_VIDEO_I_LIGHT_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SHADOW_CAMERA_H__
#define __MURL_GRAPH_I_SHADOW_CAMERA_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_camera.h"
#include "murl_graph_i_light.h"

namespace Murl
{
    namespace Graph
    {
        class ICamera;
        class IShadowCamera;
        class ISubject;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IShadowCamera nodes.
         */
        typedef IGenericNodeTarget<IShadowCamera> IShadowCameraNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IShadowCamera
         * @brief The IShadowCamera graph node interface.
         */
        class IShadowCamera
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
             * @brief Get the mutable ICamera interface.
             * This method returns a mutable pointer to the node's ICamera interface, to
             * be able to query or modify common camera parameters.
             * @return The mutable ICamera interface, or null if not available
             */
            virtual ICamera* GetCameraInterface() = 0;
            /**
             * @brief Get the constant ICamera interface.
             * This method returns a constant pointer to the node's ICamera interface, to
             * be able to query common camera parameters.
             * @return The mutable ICamera interface, or null if not available
             */
            virtual const ICamera* GetCameraInterface() const = 0;

            /**
             * @brief Get the mutable container holding the light node casting the shadow.
             * This method returns a mutable pointer to the node's Graph::ILightNodeTarget
             * container, which is used to store the light node.
             * @return The mutable Graph::ILightNodeTarget container, or null if not available.
             */
            virtual ILightNodeTarget* GetLightNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the light node casting the shadow.
             * This method returns a constant pointer to the node's Graph::ILightNodeTarget
             * container, which is used to store the light node.
             * @return The constant Graph::ILightNodeTarget container, or null if not available.
             */
            virtual const ILightNodeTarget* GetLightNodeTarget() const = 0;

            /**
             * @brief Get the mutable container holding the camera node rendering the shadowed scene.
             * This method returns a mutable pointer to the node's Graph::ICameraNodeTarget
             * container, which is used to store the scene camera node.
             * @return The mutable Graph::ICameraNodeTarget container, or null if not available.
             */
            virtual ICameraNodeTarget* GetCameraNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the camera node rendering the shadowed scene.
             * This method returns a constant pointer to the node's Graph::ILightNodeTarget
             * container, which is used to store the scene camera node.
             * @return The constant Graph::ICameraNodeTarget container, or null if not available.
             */
            virtual const ICameraNodeTarget* GetCameraNodeTarget() const = 0;

            /**
             * @brief Set the shadow map placement mode.
             * This method sets the placement mode for the shadow map, either at the view volume's
             * actual center, or at the center of the bounding sphere surrounding the view volume.
             * @param mode The placement mode.
             * @return true if successful.
             */
            virtual Bool SetPlacementMode(IEnums::ShadowMapPlacementMode mode) = 0;
            /**
             * @brief Get the shadow map placement mode.
             * @return The placement mode.
             */
            virtual IEnums::ShadowMapPlacementMode GetPlacementMode() const = 0;

            /**
             * @brief Set the shadow map alignment mode.
             * This method sets the alignment mode for the shadow map, either perpendicular to the view
             * vector (i.e. the light's main direction), or perpendicular to a given up vector defining
             * a custom plane. See SetUpVector().
             * @param mode The alignment mode.
             * @return true if successful.
             */
            virtual Bool SetAlignmentMode(IEnums::ShadowMapAlignmentMode mode) = 0;
            /**
             * @brief Get the shadow map alignment mode.
             * @return The alignment mode.
             */
            virtual IEnums::ShadowMapAlignmentMode GetAlignmentMode() const = 0;

            /**
             * @brief Set the alignment plane's up vector.
             * The alignment plane's up vector is only used when the actual alignment mode is set to
             * IEnums::SHADOW_MAP_ALIGNMENT_MODE_FIXED_PLANE. See SetAlignmentMode();
             * @param upVector The up vector.
             * @return true if successful.
             */
            virtual Bool SetUpVector(const Vector& upVector) = 0;
            /**
             * @brief Get the alignment plane's up vector.
             * @return The up vector.
             */
            virtual const Vector& GetUpVector() const = 0;

            /**
             * @brief Enable/disable shadow map stabilization.
             * @param enabled If true, stabilization is enabled.
             * @return true if successful.
             */
            virtual Bool SetStabilizationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if shadow map stabilization is enabled.
             * @return true if enabled.
             */
            virtual Bool IsStabilizationEnabled() const = 0;

            /**
             * @brief Set the bounding volume's additonal scale factor.
             * By default, the scale factor is set to 1.
             * @param scaleFactor The scale factor.
             * @return true if successful.
             */
            virtual Bool SetSphereScaleFactor(Real scaleFactor) = 0;
            /**
             * @brief Get the bounding volume's additonal scale factor.
             * @return The scale factor.
             */
            virtual Real GetSphereScaleFactor() const = 0;

        protected:
            virtual ~IShadowCamera() {}
        };
    }
}

#endif // __MURL_GRAPH_I_SHADOW_CAMERA_H__

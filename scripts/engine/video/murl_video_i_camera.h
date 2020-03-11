// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_CAMERA_H__
#define __MURL_VIDEO_I_CAMERA_H__

#include "murl_video_types.h"
#include "murl_color.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IProgram;
        class IView;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface ICamera
         * @brief The ICamera video object interface.
         * This interface represents a camera used for rendering a scene.
         *
         * Used internally by Graph::Camera.
         */
        class ICamera
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
             * @brief Enable the camera.
             * @return true if successful.
             */
            virtual Bool Enable() = 0;
            /**
             * @brief Disable the camera.
             * @return true if successful.
             */
            virtual Bool Disable() = 0;
            
            /**
             * @brief Attach the camera to the current GPU program.
             * @param currentProgram The current GPU program.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram) = 0;
            
            /**
             * @brief Enable/disable clearing of the render target's color buffer.
             * @param enabled Set to false to disable color buffer clearing.
             * @return true if successful.
             */
            virtual Bool SetColorBufferClearingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if clearing of the render target's color buffer is enabled.
             * @return true if color buffer clearing is enabled.
             */
            virtual Bool IsColorBufferClearingEnabled() const = 0;

            /**
             * @brief Enable/disable clearing of the render target's depth buffer.
             * @param enabled Set to false to disable depth buffer clearing.
             * @return true if successful.
             */
            virtual Bool SetDepthBufferClearingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if clearing of the render target's depth buffer is enabled.
             * @return true if depth buffer clearing is enabled.
             */
            virtual Bool IsDepthBufferClearingEnabled() const = 0;
            
            /**
             * @brief Enable/disable clearing of the render target's stencil buffer.
             * @param enabled Set to false to disable stencil buffer clearing.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferClearingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if clearing of the render target's stencil buffer is enabled.
             * @return true if stencil buffer clearing is enabled.
             */
            virtual Bool IsStencilBufferClearingEnabled() const = 0;

            /**
             * @brief Set the clear color in effect when color buffer clearing is enabled.
             * @param color The clear color.
             * @return true if successful.
             */
            virtual Bool SetColorBufferClearValue(const Color& color) = 0;
            /**
             * @brief Get the clear color in effect when color buffer clearing is enabled.
             * @return The clear color.
             */
            virtual const Color& GetColorBufferClearValue() const = 0;
            
            /**
             * @brief Set the clear value in effect when depth buffer clearing is enabled.
             * @param value The clear value.
             * @return true if successful.
             */
            virtual Bool SetDepthBufferClearValue(Real value) = 0;
            /**
             * @brief Get the clear value in effect when depth buffer clearing is enabled.
             * @return The clear value.
             */
            virtual Real GetDepthBufferClearValue() const = 0;
            
            /**
             * @brief Set the clear value in effect when stencil buffer clearing is enabled.
             * @param value The clear value.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferClearValue(UInt8 value) = 0;
            /**
             * @brief Get the clear value in effect when stencil buffer clearing is enabled.
             * @return The clear value.
             */
            virtual UInt8 GetStencilBufferClearValue() const = 0;

            /**
             * @brief Set the camera's absolute depth order.
             * @param depthOrder The absolute order of this camera within its view.
             * @return true if successful.
             */
            virtual Bool SetDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Get the camera's absolute depth order.
             * @return The absolute order of this camera within its view.
             */
            virtual SInt32 GetDepthOrder() const = 0;

            /**
             * @brief Set the camera mask.
             * @param x1 The left mask coordinate in pixels.
             * @param y1 The bottom mask coordinate in pixels.
             * @param x2 The right mask coordinate in pixels.
             * @param y2 The top mask coordinate in pixels.
             * @return true if successful.
             */
            virtual Bool SetMask(SInt32 x1, SInt32 x2, SInt32 y1, SInt32 y2) = 0;
            /**
             * @brief Get the camera mask's left border coordinate.
             * @return The left mask coordinate in pixels.
             */
            virtual SInt32 GetMaskX1() const = 0;
            /**
             * @brief Get the camera mask's right border coordinate.
             * @return The right mask coordinate in pixels.
             */
            virtual SInt32 GetMaskX2() const = 0;
            /**
             * @brief Get the camera mask's bottom border coordinate.
             * @return The bottom mask coordinate in pixels.
             */
            virtual SInt32 GetMaskY1() const = 0;
            /**
             * @brief Get the camera mask's top border coordinate.
             * @return The top mask coordinate in pixels.
             */
            virtual SInt32 GetMaskY2() const = 0;

            /**
             * @brief Set the winding order for front-facing polygons
             * @param order The winding order, either clockwise or counter-clockwise.
             * @return true if successful.
             */
            virtual Bool SetFrontFacingVertexOrder(IEnums::VertexOrder order) = 0;
            /**
             * @brief Get the winding order for front-facing polygons
             * @return The winding order, either clockwise or counter-clockwise.
             */
            virtual IEnums::VertexOrder GetFrontFacingVertexOrder() const = 0;
            
            /**
             * @brief Set the depth sort mode for geometries within this camera.
             * @param mode The depth sort mode used for this camera.
             * @return true if successful.
             */
            virtual Bool SetDepthSortMode(IEnums::DepthSortMode mode) = 0;
            /**
             * @brief Get the depth sort mode for geometries within this camera.
             * @return The depth sort mode used for this camera.
             */
            virtual IEnums::DepthSortMode GetDepthSortMode() const = 0;

            /**
             * @brief Set an optional view offset for rendering.
             * When rendering to a regular 2D frame buffer, the given offset parameter
             * is set to null. When rendering to a cube map frame buffer, the camera
             * gets processed six times (once for each side of the cube map), and the
             * given offset matrix represents a rotation towards the currently active
             * face.
             * @param offset The optional view offset matrix.
             * @return true if successful.
             */
            virtual Bool SetViewOffsetTransform(const Matrix* offset) = 0;
            /**
             * @brief Get the current view offset matrix.
             * @return The view offset matrix, or null if not set.
             */
            virtual const Matrix* GetViewOffsetTransform() const = 0;

            /**
             * @brief Set the camera's current world transform.
             * @param transform The current world transform.
             * @return true if successful.
             */
            virtual Bool SetWorldTransform(const Matrix& transform) = 0;
            /**
             * @brief Set the camera's projection matrix.
             * @param projection The projection matrix.
             * @param nearPlane The absolute distance of the near clipping plane.
             * @param farPlane The absolute distance of the far clipping plane.
             * @param isOrthographic If true, the given matrix represents an
             *      orthographic projection.
             * @return true if successful.
             */
            virtual Bool SetProjectionTransform(const Matrix& projection, Real nearPlane, Real farPlane, Bool isOrthographic) = 0;

            /**
             * @brief Get the current camera position in world space.
             * @return The current camera position.
             */
            virtual const Vector& GetWorldPosition() const = 0;
            /**
             * @brief Get the current camera direction in world space.
             * @return The current camera direction.
             */
            virtual const Vector& GetWorldDirection() const = 0;
            /**
             * @brief Get the camera's current world transform.
             * @return The current world transform.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            /**
             * @brief Get the camera's projection matrix.
             * @return The projection matrix.
             */
            virtual const Matrix& GetProjectionTransform() const = 0;
            /**
             * @brief Get the camera's current view matrix.
             * This equals the inverse of the current world transform.
             * @return The current view matrix.
             */
            virtual const Matrix& GetViewTransform() const = 0;
            /**
             * @brief Get the camera's combined current view and projection matrix.
             * @return The current view/projection matrix.
             */
            virtual const Matrix& GetViewProjectionTransform() const = 0;

            /**
             * @brief Get the camera's absolute near clipping plane distance.
             * @return The near plane distance.
             */
            virtual Real GetNearPlane() const = 0;
            /**
             * @brief Get the camera's absolute far clipping plane distance.
             * @return The far plane distance.
             */
            virtual Real GetFarPlane() const = 0;
            
            /**
             * @brief Check if the camera's view volume intersects a given sphere.
             * @param boundingSphere The world-coordinate bounding sphere to check.
             * @return true if the bounding sphere intersects the view volume.
             */
            virtual Bool IsIntersecting(const Sphere& boundingSphere) const = 0;

            /**
             * @brief Set the camera view.
             * @param view The view to use.
             * @return true if successful.
             */
            virtual Bool SetView(IView* view) = 0;
            /**
             * @brief Get the camera view.
             * @return The view used.
             */
            virtual IView* GetView() const = 0;

        protected:
            virtual ~ICamera() {}
        };
    }
}

#endif // __MURL_VIDEO_I_CAMERA_H__

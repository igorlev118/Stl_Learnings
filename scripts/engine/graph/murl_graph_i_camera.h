// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CAMERA_H__
#define __MURL_GRAPH_I_CAMERA_H__

#include "murl_graph_i_state_slot.h"
#include "murl_graph_i_view.h"
#include "murl_color.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class ICamera;
    }
    
    namespace Input
    {
        class IProjection;
    }

    namespace Graph
    {
        class ICamera;
        class ICuller;
        class ISubject;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICamera nodes.
         */
        typedef IGenericNodeTarget<ICamera> ICameraNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ICamera
         * @brief The ICamera graph node interface.
         * A camera represents a node positioned in world space through which any renderable
         * geometry can be viewed within its viewing volume. The view volume can either be a
         * box for orthographic cameras or a frustum for perspective cameras.
         *
         * Along the screen-space Z axis, the view volume is bounded by a near plane and a far
         * plane, which can be set by SetNearAndFarPlaneZ() and related methods. The values for
         * the near and far plane always represent positive (absolute) distances from the camera's
         * eye point, regardless of the actual camera position and orientation in world space.
         *
         * For the screen-space X (left-right) and Y (bottom-top) axes, defining the view volume
         * can be done independently in one of two ways:
         *
         * - Specifying a unit size results in a constant mapping between output pixels and virtual
         *   coordinates catched by the camera, with a value of 1.0 producing a 1:1 relationship.
         *   In other words, if the output window is enlarged, more of the virtual space becomes
         *   visible for that camera.
         *
         * - Specifying a field-of-view value keeps a constant relationship between virtual coordinates
         *   and window size. In other words, enlarging the window will enlarge the rendered scene,
         *   but no additional geometry will become visible.
         *
         * The actual meaning of the given values is different for each type of camera:
         *
         * - Orthographic cameras:
         *   - The fovX and fovY parameters of the SetFieldOfView() method (and related ones) simply
         *     represent the X and Y extent of the viewing box from the center in both directions
         *     (i.e. the actual width and height of the box are 2*fovX and 2*fovY, respectively).
         *   - The unitSizeX and unitSizeY parameters of the SetUnitSize() method (and related ones)
         *     directly map pixels to virtual coordinates.
         *
         * - Perspective cameras:
         *   - The fovX and fovY parameters of the SetFieldOfView() method (and related ones)
         *     represent the horizontal and vertical extent of the viewing frustum <em>at the near
         *     plane</em>, measured from the center. A near plane distance of 10.0 and a fovX of 10.0
         *     therefore represent a 45° angle between the center line to both the left and right
         *     front edges of the frustum, resulting in a total horizontal field of view of 90°,
         *     with the virtual coordinates ranging from -10.0 to +10.0 in X direction, at a distance
         *     of 10.0 units in front of the camera.
         *   - The unitSizeX and unitSizeY parameters of the SetUnitSize() method (and related ones)
         *     directly map pixels to virtual coordinates, again <em>at the near plane</em>.
         *
         * Note, that you cannot specify both FOV and unit size for the same axis. It is however
         * possible to define a FOV in X direction and a unit size in Y direction (and vice versa).
         *
         * If only one axis is defined by an FOV or unit size value, the bounds of
         * the missing dimension can be automatically calculated to maintain a given coordinate
         * aspect ratio, which can be defined via SetAspectRatio(). (default 1.0). In this case
         * (only one axis given), the aspect ratio cannot be 0, and the view area of the automatically
         * calculated axis is adjusted with respect to the actual window size.
         *
         * If both axes are set and the aspect ratio is set to a value higher than 0.0, the engine
         * tries to both respect the given ratio as well as the FOV/unit size values. There are
         * two cases how this is done:
         *
         * - If SetAspectClippingEnabled() is set to false, the system always fits the camera to its
         *   output surface so that the given field of view is always fully visible. This may mean
         *   that the FOV of either the horizontal or vertical axis is actually bigger than specified
         *   (if the aspect ratio of the output surface is different from the camera aspect).
         *   To clip away this (possibly undesired) extra space, SetBorderMaskEnabled(true) can be 
         *   called.
         * - If SetAspectClippingEnabled() is set to true, the system fits the camera to the output
         *   surface so that none of the given FOV values can become bigger than specified. If the 
         *   aspect ratio of the output surface is different from the camera aspect, this means that
         *   either the horizontal or vertical FOV value becomes actually smaller than specified,
         *   clipping away those portions that do not fit.
         *
         * In order to use a camera, it must be attached to a Graph::IView node, which specifies the
         * actually visible area within the output surface (either the back buffer or a custom frame
         * buffer). Attaching the camera can be done via the camera's Graph::IViewNodeTarget retrieved
         * from GetViewNodeTarget(). If multiple cameras are attached to a single view, their drawing
         * order can be specified via SetDepthOrder(), with higher values being "nearer", i.e.
         * rendered later.
         *
         * It is possible to define an explicit rectangular area to which the camera's given field
         * of view is related. Setting this rectangle can be done via the SetBorderCoords() and
         * SetBorderAnchors() methods (and related ones), which behaves analogously to setting
         * the mask rectangle of a Graph::IView. See Graph::IView::SetMaskCoords() for details.
         * By default, the border area covers the whole output surface, which is equivalent to
         * all border coordinates equalling zero, and the left, top, right and bottom anchors
         * set to the corresponding alignment values (IEnums::ALIGNMENT_X_LEFT,
         * IEnums::ALIGNMENT_Y_TOP and so on).
         *
         * Note, that setting a camera border rectangle does not actually clip the output at the
         * given border edges; instead, the border rectangle only defines the reference edges to
         * which the view volume is anchored. In other words, the view volume actually extends beyond
         * this rectangle; if clipping is desired, it must be enabled in the camera's view by
         * specifying arbitrary values for that view's mask coordinates and anchors.
         *
         * Within the given border rectangle, it is possible to also define the camera's projection
         * center via SetCenter(), with values ranging from -1.0 to 1.0 for left/right and bottom/top
         * edges.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::ICameraTransform for setting a camera's position and orientation.\n
         * See Graph::ICameraState for activating a camera for rendering.
         */
        class ICamera : public IStateSlot
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
             * @brief Get the mutable container holding the optional child cameras.
             * This method returns a mutable pointer to the node's Graph::ICameraNodeTarget
             * sub container, which is used to store multiple sub-cameras.
             * @return The mutable Graph::ICameraNodeTarget container, or null if not available.
             */
            virtual ICameraNodeTarget* GetSubCameraNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the optional child cameras.
             * This method returns a constant pointer to the node's Graph::ICameraNodeTarget
             * sub container, which is used to store multiple sub-cameras.
             * @return The constant Graph::ICameraNodeTarget container, or null if not available.
             */
            virtual const ICameraNodeTarget* GetSubCameraNodeTarget() const = 0;

            /**
             * @brief Get the mutable IViewNodeTarget container.
             * This method returns a mutable pointer to the node's IViewNodeTarget
             * container, which allows to set or query the view object the camera is
             * attached to.
             * @return The mutable IViewNodeTarget container, or null if not available
             */
            virtual IViewNodeTarget* GetViewNodeTarget() = 0;
            /**
             * @brief Get the constant IViewNodeTarget container.
             * This method returns a constant pointer to the node's IViewNodeTarget
             * container, which allows to query the view object the camera is
             * attached to.
             * @return The constant IViewNodeTarget container, or null if not available
             */
            virtual const IViewNodeTarget* GetViewNodeTarget() const = 0;

            /**
             * @brief Set the projection type.
             * @param type The projection type.
             * @return true if successful.
             */
            virtual Bool SetProjectionType(IEnums::ProjectionType type) = 0;
            /**
             * @brief Get the projection type.
             * @return The projection type.
             */
            virtual IEnums::ProjectionType GetProjectionType() const = 0;

            /**
             * @brief Set the camera's absolute depth order.
             * When a Graph::IView contains more than one camera to render to, it may be
             * necessary to define the exact order in which those cameras are overlaid.
             * The given depth order value represents a 32 bit signed integer; higher values
             * result in a "later" rendering on top of previous cameras, i.e. back-to-front
             * rendering in ascending order of depth order values.
             * See also Graph::IView::SetDepthOrder().
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
             * When rendering alpha blended geometries, it is often necessary to sort these
             * from back to front, to maintain correct blending.
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
             * @brief Set the allowed screen orientation of the camera.
             * By default, all screen orientations are allowed. Use this method to restrict
             * the camera's orientation to the given value.
             * @param orientation The desired screen orientation.
             * @return true if successful.
             */
            virtual Bool SetScreenOrientation(IEnums::ScreenOrientation orientation) = 0;
            /**
             * @brief Get the depth sort mode for geometries within this camera.
             * @return The depth sort mode used for this camera.
             */
            virtual IEnums::ScreenOrientation GetScreenOrientation() const = 0;

            /**
             * @brief Enable/disable automatic deactivation if no geometry is to be rendered.
             * When automatic deactivation is enabled, the renderer will not process that
             * specific camera when it does not contain any visible geometry to render.
             * In this case, the render target (e.g. frame buffer) will retain the most
             * recently rendered image, and the target will not be cleared.
             * When using an empty camera for e.g. clearing portions of the screen where no
             * other camera is rendering to, this must be set to "false", otherwise this
             * camera will never be processed.
             * @param enabled Set to true if auto deactivation is desired.
             * @return true if successful.
             */
            virtual Bool SetAutoDeactivationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if automatic deactivation is enabled if no geometry is to be rendered.
             * @return true if auto deactivation is enabled.
             */
            virtual Bool IsAutoDeactivationEnabled() const = 0;
            
            /**
             * @brief Enable/disable clearing of the render target's color buffer.
             * When multiple cameras are defined for a specific Graph::IView (e.g. one for
             * rendering a 3D scene and the other one for rendering a heads-up display),
             * color buffer clearing should be disabled for the second camera to prevent
             * overwriting all previously rendered pixels. The same applies, when multiple
             * views with different cameras are stacked atop each other; in most cases only
             * the "farthest away" camera should have color buffer clearing enabled.
             * See SetColorBufferClearValue() for setting the color used for clearing.
             * See also SetDepthBufferClearingEnabled() and SetStencilBufferClearingEnabled().
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
             * In the example shown in SetColorBufferClearingEnabled(), color buffer clearing
             * is intentionally disabled for the second camera. However, if the HUD rendered
             * by the second camera also performs depth testing, it may be necessary to
             * clear the depth buffer to prevent unwanted rendering artifacts.
             * See SetDepthBufferClearValue() for setting the depth value used for clearing.
             * See also SetStencilBufferClearingEnabled().
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
             * See SetStencilBufferClearValue() for setting the stencil value used for clearing.
             * See SetDepthBufferClearingEnabled() and SetColorBufferClearingEnabled().
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
             * @param value The clear color.
             * @return true if successful.
             */
            virtual Bool SetColorBufferClearValue(const Color& value) = 0;
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
            virtual Bool SetStencilBufferClearValue(UInt32 value) = 0;
            /**
             * @brief Get the clear value in effect when stencil buffer clearing is enabled.
             * @return The clear value.
             */
            virtual UInt32 GetStencilBufferClearValue() const = 0;

            /**
             * @brief Set the camera's view volume border coordinates.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @param left The left border coordinate. Positive values run to the right.
             * @param right The right border coordinate. Positive values run to the right.
             * @param top The top border coordinate. Positive values run up.
             * @param bottom The bottom border coordinate. Positive values run up.
             * @return true if successful.
             */
            virtual Bool SetBorderCoords(SInt32 left, SInt32 right, SInt32 top, SInt32 bottom) = 0;
            /**
             * @brief Set the camera's horizontal view volume border coordinates.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @param left The left border coordinate.
             * @param right The right border coordinate.
             * @return true if successful.
             */
            virtual Bool SetBorderCoordsX(SInt32 left, SInt32 right) = 0;
            /**
             * @brief Set the camera's vertical view volume border coordinates.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @param top The top border coordinate. Positive values run up.
             * @param bottom The bottom border coordinate. Positive values run up.
             * @return true if successful.
             */
            virtual Bool SetBorderCoordsY(SInt32 top, SInt32 bottom) = 0;
            /**
             * @brief Get the camera's left view volume border coordinate.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The left border coordinate.
             */
            virtual SInt32 GetLeftBorderCoord() const = 0;
            /**
             * @brief Get the camera's right view volume border coordinate.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The right border coordinate.
             */
            virtual SInt32 GetRightBorderCoord() const = 0;
            /**
             * @brief Get the camera's top view volume border coordinate.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The top border coordinate.
             */
            virtual SInt32 GetTopBorderCoord() const = 0;
            /**
             * @brief Get the camera's bottom view volume border coordinate.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The bottom border coordinate.
             */
            virtual SInt32 GetBottomBorderCoord() const = 0;
            
            /**
             * @brief Set the camera's view volume border anchors.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @param left The left border anchor.
             * @param right The right border anchor.
             * @param top The top border anchor.
             * @param bottom The bottom border anchor.
             * @return true if successful.
             */
            virtual Bool SetBorderAnchors(IEnums::AlignmentX left, IEnums::AlignmentX right, IEnums::AlignmentY top, IEnums::AlignmentY bottom) = 0;
            /**
             * @brief Set the camera's horizontal view volume border anchors.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @param left The left border anchor.
             * @param right The right border anchor.
             * @return true if successful.
             */
            virtual Bool SetBorderAnchorsX(IEnums::AlignmentX left, IEnums::AlignmentX right) = 0;
            /**
             * @brief Set the camera's vertical view volume border anchors.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @param top The top border anchor.
             * @param bottom The bottom border anchor.
             * @return true if successful.
             */
            virtual Bool SetBorderAnchorsY(IEnums::AlignmentY top, IEnums::AlignmentY bottom) = 0;
            /**
             * @brief Get the camera's left view volume border anchor.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The left border anchor.
             */
            virtual IEnums::AlignmentX GetLeftBorderAnchor() const = 0;
            /**
             * @brief Get the camera's right view volume border anchor.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The right border anchor.
             */
            virtual IEnums::AlignmentX GetRightBorderAnchor() const = 0;
            /**
             * @brief Get the camera's top view volume border anchor.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The top border anchor.
             */
            virtual IEnums::AlignmentY GetTopBorderAnchor() const = 0;
            /**
             * @brief Get the camera's bottom view volume border anchor.
             * See the Graph::ICamera description, and Graph::IView::SetMaskCoords().
             * @return The bottom border anchor.
             */
            virtual IEnums::AlignmentY GetBottomBorderAnchor() const = 0;
            
            /**
             * @brief Enable/disable border masking.
             * See the Graph::ICamera description.
             * @param enabled If true, masking is enabled.
             * @return true if successful.
             */
            virtual Bool SetBorderMaskEnabled(Bool enabled) = 0;
            /**
             * @brief Check if border masking is enabled.
             * @return true if masking is enabled.
             */
            virtual Bool IsBorderMaskEnabled() const = 0;
            
            /**
             * @brief Enable/disable aspect clipping.
             * See the Graph::ICamera description.
             * @param enabled If true, aspect clipping is enabled.
             * @return true if successful.
             */
            virtual Bool SetAspectClippingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if aspect clipping is enabled.
             * @return true if clipping is enabled.
             */
            virtual Bool IsAspectClippingEnabled() const = 0;
            
            /**
             * @brief Set the camera's aspect ratio.
             * The aspect ratio is used in different ways to calculate the actual field of view and
             * border area, depending on the given FOV parameters:
             * - If only one axis is defined using a unit size value, the missing one is calculated so
             *   that the virtual coordinate system maintains the given X:Y aspect ratio.
             * - The same is true if only a single FOV value is given; in this case the FOV of the other
             *   axis grows or shrinks depending on the window size and window aspect.
             * - If both FOV axes are specified and the given aspect ratio is not 0, the FOV of both axes
             *   remains as defined. Here, the actual outcome depends on whether aspect clipping and/or
             *   border masking is enabled or not:
             *   - If aspect clipping is enabled, the camera calculates the actual FOV so that the view
             *     area is always fully covered. If the window aspect is smaller than the FOV aspect
             *     (the window is taller than the FOV), the vertical FOV is clipped. If the window aspect
             *     is greater (wider than the FOV), the horizontal FOV is clipped.
             *   - If aspect clipping is disabled, the camera always keeps both FOV axes fully within the
             *     view. If the window is taller than the FOV, borders are added vertically, and if it is
             *     wider, horizontal borders are added. Note, that it is necessary to enable border masking
             *     (see SetBorderMaskEnabled()) so that these borders actually have effect.
             * - If both FOV axes are specified and the given aspect ratio equals 0, the given FOV values
             *   are directly used regardless of the actual view size. In other words, the virtual
             *   coordinate system gets skewed, resulting in non-square coordinate units on screen.
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
             * @brief Set the field of view at the near plane.
             * This method sets both the horizontal and vertical field of view values.
             * See the detailed description above on how the camera's viewing volume is
             * calculated from these values.
             * @param fovX The horizontal field of view.
             * @param fovY The vertical field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfView(Real fovX, Real fovY) = 0;
            /**
             * @brief Set the horizontal field of view, at the near plane.
             * See the detailed description above on how the camera's viewing volume is
             * calculated.
             * @param fovX The horizontal field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfViewX(Real fovX) = 0;
            /**
             * @brief Set the vertical field of view, at the near plane.
             * See the detailed description above on how the camera's viewing volume is
             * calculated.
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
             * @brief Set the unit size, at the near plane.
             * This method sets both the horizontal and vertical unit size.
             * See the detailed description above on how the camera's viewing volume is
             * calculated from these values.
             * @param unitSizeX The horizontal unit size.
             * @param unitSizeY The vertical unit size.
             * @return true if successful.
             */
            virtual Bool SetUnitSize(Real unitSizeX, Real unitSizeY) = 0;
            /**
             * @brief Set the horizontal unit size, at the near plane.
             * See the detailed description above on how the camera's viewing volume is
             * calculated.
             * @param unitSizeX The horizontal unit size.
             * @return true if successful.
             */
            virtual Bool SetUnitSizeX(Real unitSizeX) = 0;
            /**
             * @brief Set the vertical unit size, at the near plane.
             * See the detailed description above on how the camera's viewing volume is
             * calculated.
             * @param unitSizeY The vertical unit size.
             * @return true if successful.
             */
            virtual Bool SetUnitSizeY(Real unitSizeY) = 0;
            /**
             * @brief Get the horizontal unit size.
             * @return The horizontal unit size, or 0.0 if variable.
             */
            virtual Real GetUnitSizeX() const = 0;
            /**
             * @brief Get the vertical unit size.
             * @return The vertical unit size, or 0.0 if variable.
             */
            virtual Real GetUnitSizeY() const = 0;

            /**
             * @brief Set the projection center.
             * @param centerX The horizontal projection center.
             * @param centerY The vertical projection center.
             * @return true if successful.
             */
            virtual Bool SetCenter(Real centerX, Real centerY) = 0;
            /**
             * @brief Set the horizontal projection center.
             * @param centerX The horizontal projection center.
             * @return true if successful.
             */
            virtual Bool SetCenterX(Real centerX) = 0;
            /**
             * @brief Set the vertical projection center.
             * @param centerY The vertical projection center.
             * @return true if successful.
             */
            virtual Bool SetCenterY(Real centerY) = 0;
            /**
             * @brief Get the horizontal projection center.
             * @return The horizontal projection center.
             */
            virtual Real GetCenterX() const = 0;
            /**
             * @brief Get the vertical projection center.
             * @return The vertical projection center.
             */
            virtual Real GetCenterY() const = 0;

            /**
             * @brief Set the projection shearing.
             * @param shearX The horizontal projection shearing.
             * @param shearY The vertical projection shearing.
             * @return true if successful.
             */
            virtual Bool SetShear(Real shearX, Real shearY) = 0;
            /**
             * @brief Set the horizontal projection shearing.
             * @param shearX The horizontal projection shearing.
             * @return true if successful.
             */
            virtual Bool SetShearX(Real shearX) = 0;
            /**
             * @brief Set the vertical projection shearing.
             * @param shearY The vertical projection shearing.
             * @return true if successful.
             */
            virtual Bool SetShearY(Real shearY) = 0;
            /**
             * @brief Get the horizontal projection shearing.
             * @return The horizontal projection shearing.
             */
            virtual Real GetShearX() const = 0;
            /**
             * @brief Get the vertical projection shearing.
             * @return The vertical projection shearing.
             */
            virtual Real GetShearY() const = 0;

            /**
             * @brief Set the relative position within the view.
             * @param posX The horizontal position.
             * @param posY The vertical position.
             * @return true if successful.
             */
            virtual Bool SetPosition(Real posX, Real posY) = 0;
            /**
             * @brief Set the relative horizontal position within the view.
             * @param posX The horizontal position.
             * @return true if successful.
             */
            virtual Bool SetPositionX(Real posX) = 0;
            /**
             * @brief Set the relative vertical position within the view.
             * @param posY The vertical position.
             * @return true if successful.
             */
            virtual Bool SetPositionY(Real posY) = 0;
            /**
             * @brief Get the relative horizontal position within the view.
             * @return The horizontal position.
             */
            virtual Real GetPositionX() const = 0;
            /**
             * @brief Get the relative vertical position within the view.
             * @return The vertical position.
             */
            virtual Real GetPositionY() const = 0;
            
            /**
             * @brief Set the relative size within the view.
             * @param sizeX The horizontal size.
             * @param sizeY The vertical size.
             * @return true if successful.
             */
            virtual Bool SetSize(Real sizeX, Real sizeY) = 0;
            /**
             * @brief Set the relative horizontal size within the view.
             * @param sizeX The horizontal size.
             * @return true if successful.
             */
            virtual Bool SetSizeX(Real sizeX) = 0;
            /**
             * @brief Set the relative vertical size within the view.
             * @param sizeY The vertical size.
             * @return true if successful.
             */
            virtual Bool SetSizeY(Real sizeY) = 0;
            /**
             * @brief Get the relative horizontal size within the view.
             * @return The horizontal size.
             */
            virtual Real GetSizeX() const = 0;
            /**
             * @brief Get the relative vertical size within the view.
             * @return The vertical size.
             */
            virtual Real GetSizeY() const = 0;
            
            /**
             * @brief Set the absolute distances for both near and far clipping planes.
             * Both values must be positive, with 0 < nearZ < farZ.
             * @param nearZ The positive near plane distance.
             * @param farZ The positive near plane distance.
             * @return true if successful.
             */
            virtual Bool SetNearAndFarPlaneZ(Real nearZ, Real farZ) = 0;
            /**
             * @brief Set the absolute distance for the near clipping plane.
             * See SetNearAndFarPlaneZ().
             * @param nearZ The positive near plane distance.
             * @return true if successful.
             */
            virtual Bool SetNearPlaneZ(Real nearZ) = 0;
            /**
             * @brief Set the absolute distance for the far clipping plane.
             * See SetNearAndFarPlaneZ().
             * @param farZ The positive near plane distance.
             * @return true if successful.
             */
            virtual Bool SetFarPlaneZ(Real farZ) = 0;
            /**
             * @brief Get the absolute distance for the near clipping plane.
             * @return The positive near plane distance.
             */
            virtual Real GetNearPlaneZ() const = 0;
            /**
             * @brief Get the absolute distance for the far clipping plane.
             * @return The positive far plane distance.
             */
            virtual Real GetFarPlaneZ() const = 0;
            
            /**
             * @brief Set a user-defined view volume clipping plane in world space.
             * @param clipPlane A vector holding the A, B, C and D coefficients from the
             *      plane equation defining the clipping plane, contained in the vector's
             *      x, y, z and w components, respectively. The x, y and z components
             *      represent the actual plane normal, where the w component represents
             *      the plane's normal distance from the origin.
             * @return true if successful.
             */
            virtual Bool SetClipPlane(const Vector& clipPlane) = 0;
            /**
             * @brief Set a user-defined view volume clipping plane in world space.
             * @param position A vector holding the position of an arbitrary point in
             *      world space that is lying on the clip plane.
             * @param normal A vector holding the clipping plane's normal vector in its
             *      x, y and z components.
             * @return true if successful.
             */
            virtual Bool SetClipPlane(const Vector& position, const Vector& normal) = 0;
            /**
             * @brief Get the user-defined view volume clipping plane in world space.
             * @return A vector holding the A, B, C and D coefficients from the
             *      plane equation defining the clipping plane, contained in the vector's
             *      x, y, z and w components, respectively.
             */
            virtual const Vector& GetClipPlane() const = 0;
            
            /**
             * @brief Calculate the camera space position from given screen coordinates.
             * This method can be used to get a vector to a point in camera space, defined
             * by a pair of X and Y screen coordinates, and a distance along the camera's
             * viewing axis. As the viewing axis is always parallel to the Z axis, looking
             * in the negative direction, the given distance must also be negative to represent
             * a point in front of the camera.
             * @param screenCoord A vector containing the horizontal and vertical screen
             *      coordinates in the X and Y components, and the distance from the camera
             *      along its viewing axis in the Z component. A negative distance represents 
             *      a point in front of the camera.
             * @return The camera-space position.
             */
            virtual Vector GetLocalPositionFromScreen(const Vector& screenCoord) const = 0;
            /**
             * @brief Calculate the camera space position from given screen coordinates.
             * See GetLocalPositionFromScreen(const Vector& screenCoord).
             * @param screenX The X coordinate on screen for which to calculate the local point.
             * @param screenY The Y coordinate on screen for which to calculate the local point.
             * @param distance The distance from the camera.
             * @return The camera-space position.
             */
            virtual Vector GetLocalPositionFromScreen(Real screenX, Real screenY, Real distance) const = 0;
            /**
             * @brief Calculate the world-space position from given screen coordinates.
             * This method first calculates the local position via GetLocalPositionFromScreen(),
             * and then transforms the resulting point to world space by multiplying it with the
             * camera's world transform.
             * @param screenCoord A vector containing the horizontal and vertical screen
             *      coordinates in the X and Y components, and the distance from the camera
             *      along its viewing axis in the Z component. A negative distance represents
             *      a point in front of the camera.
             * @return The world-space position.
             */
            virtual Vector GetWorldPositionFromScreen(const Vector& screenCoord) const = 0;
            /**
             * @brief Calculate the world-space position from given screen coordinates.
             * See GetWorldPositionFromScreen(const Vector& screenCoord).
             * @param screenX The X coordinate on screen for which to calculate the world point.
             * @param screenY The Y coordinate on screen for which to calculate the world point.
             * @param distance The distance from the camera.
             * @return The world-space position.
             */
            virtual Vector GetWorldPositionFromScreen(Real screenX, Real screenY, Real distance) const = 0;

            /**
             * @brief Calculate the screen coordinates from a given coordinate in camera space.
             * This method performs a regular view space to screen space transformation, using the
             * projection matrix set for the camera. The input coordinate is relative to the
             * camera itself.
             * @param localCoord The coordinate to transform, in camera space.
             * @return The camera space position.
             */
            virtual Vector GetScreenPositionFromLocal(const Vector& localCoord) const = 0;
            /**
             * @brief Calculate the screen coordinates from a given coordinate in camera space.
             * See GetScreenPositionFromLocal(const Vector& localCoord).
             * @param localX The input coordinate's X component, in camera space.
             * @param localY The input coordinate's Y component, in camera space.
             * @param localZ The input coordinate's Z component, in camera space.
             * @return The camera space position.
             */
            virtual Vector GetScreenPositionFromLocal(Real localX, Real localY, Real localZ) const = 0;
            /**
             * @brief Calculate the screen coordinates from a given coordinate in world space.
             * This method performs a regular world space to screen space transformation, using the
             * inverse model matrix and the regular projection matrix set for the camera. 
             * The input coordinate represents an absolute world position.
             * @param worldCoord The coordinate to transform, in world space.
             * @return The camera space position.
             */
            virtual Vector GetScreenPositionFromWorld(const Vector& worldCoord) const = 0;
            /**
             * @brief Calculate the screen coordinates from a given coordinate in world space.
             * See GetScreenPositionFromWorld(const Vector& worldCoord).
             * @param worldX The input coordinate's X component, in world space.
             * @param worldY The input coordinate's Y component, in world space.
             * @param worldZ The input coordinate's Z component, in world space.
             * @return The camera space position.
             */
            virtual Vector GetScreenPositionFromWorld(Real worldX, Real worldY, Real worldZ) const = 0;

            /**
             * @brief Get the camera's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the camera's internal video renderer object.
             * @param stage The stage to query.
             * @return The video renderer object.
             */
            virtual Video::ICamera* GetVideoCameraObject(UInt32 stage) const = 0;
            /**
             * @brief Get the camera's internal input handler object.
             * @param stage The stage to query.
             * @return The input handler object.
             */
            virtual Input::IProjection* GetInputProjectionObject(UInt32 stage) const = 0;

        protected:
            virtual ~ICamera() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CAMERA_H__

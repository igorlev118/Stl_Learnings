// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_VIEW_H__
#define __MURL_GRAPH_I_VIEW_H__

#include "murl_graph_i_frame_buffer.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Audio
    {
        class IView;
    }
    
    namespace Video
    {
        class IView;
    }
    
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IView
         * @brief The IView graph node interface.
         * A view specifies the actually visible area within an output surface. Which output
         * surface is used can be controlled by setting the Graph::IFrameBufferNodeTarget
         * retrieved from GetFrameBufferNodeTarget(). If a null pointer is given, the view
         * will render to the system back buffer, otherwise it is possible to set the target
         * to a given Graph::IFrameBuffer node, which will instruct the view to render to
         * that custom frame buffer.
         *
         * A view can have any number of cameras attached, see the description of Graph::ICamera
         * and Graph::ICamera::GetViewNodeTarget().
         *
         * If multiple views are attached to the same output buffer, their drawing order can
         * be specified via SetDepthOrder(), with higher values being "nearer", i.e. rendered
         * later.
         *
         * To allow for only rendering to a rectangular sub-region of the output surface, the
         * view's SetMaskCoords() and SetMaskAnchors() methods (and related ones) can be used.
         * By default, the view covers the whole output surface, which is equivalent to
         * all mask coordinates equalling zero, and the left, top, right and bottom anchors
         * set to the corresponding alignment values (IEnums::ALIGNMENT_X_LEFT,
         * IEnums::ALIGNMENT_Y_TOP and so on). See SetMaskCoords() for details.
         */
        class IView
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
             * @brief Get the mutable IFrameBufferNodeTarget container.
             * This method returns a mutable pointer to the node's IFrameBufferNodeTarget
             * container, which allows to set or query the frame buffer object the view is
             * attached to.
             * @return The mutable IFrameBufferNodeTarget container, or null if not available
             */
            virtual IFrameBufferNodeTarget* GetFrameBufferNodeTarget() = 0;
            /**
             * @brief Get the constant IFrameBufferNodeTarget container.
             * This method returns a constant pointer to the node's IFrameBufferNodeTarget
             * container, which allows to query the frame buffer object the view is
             * attached to.
             * @return The constant IFrameBufferNodeTarget container, or null if not available
             */
            virtual const IFrameBufferNodeTarget* GetFrameBufferNodeTarget() const = 0;
            
            /**
             * @brief Set the view's absolute depth order.
             * Analogous to Graph::ICamera::SetDepthOrder().
             * @param depthOrder The absolute order of this view within its frame buffer.
             * @return true if successful.
             */
            virtual Bool SetDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Get the view's absolute depth order.
             * @return The absolute order of this view within its frame buffer.
             */
            virtual SInt32 GetDepthOrder() const = 0;
            
            /**
             * @brief Set the view mask's border coordinates.
             * To define a rectangular mask for the view, it is necessary to specify 4 values,
             * one for each edge of the desired rectangle: left, right, top and bottom.
             * In addition, it is necessary to specify an anchor point for each of these edges,
             * via SetMaskAnchors() or related methods, which represents the absolute origin for
             * the respective coordinate value. For example, if the left coordinate value is set
             * to a value of 50 and the left anchor is set to IEnums::ALIGNMENT_X_LEFT,
             * the mask is always anchored at the left window edge with an offset of 50 pixels to
             * the right. If the left coordinate has a value of -200 and the left anchor is set
             * to IEnums::ALIGNMENT_X_RIGHT, the mask's left border will always be 200
             * pixels left of the right window border.
             * Note that the engine's window coordinate origin is at the left bottom corner of
             * the surface with positive Y values running up. Therefore, to define e.g. a vertical
             * mask that clips 100 pixels from both top and bottom, it is necessary to specify
             * a value of +100 for the bottom coordinate (with the bottom anchor set to
             * IEnums::ALIGNMENT_Y_BOTTOM), and a value of -100 for the top coordinate,
             * with IEnums::ALIGNMENT_Y_TOP for the top anchor.
             * @param left The left mask coordinate. Positive values run to the right.
             * @param right The right mask coordinate. Positive values run to the right.
             * @param top The top mask coordinate. Positive values run up.
             * @param bottom The bottom mask coordinate. Positive values run up.
             * @return true if successful.
             */
            virtual Bool SetMaskCoords(SInt32 left, SInt32 right, SInt32 top, SInt32 bottom) = 0;
            /**
             * @brief Set the view mask's horizontal border coordinates.
             * See SetMaskCoords() for details.
             * @param left The left mask coordinate.
             * @param right The right mask coordinate.
             * @return true if successful.
             */
            virtual Bool SetMaskCoordsX(SInt32 left, SInt32 right) = 0;
            /**
             * @brief Set the view mask's vertical border coordinates.
             * See SetMaskCoords() for details.
             * @param top The top mask coordinate.
             * @param bottom The bottom mask coordinate.
             * @return true if successful.
             */
            virtual Bool SetMaskCoordsY(SInt32 top, SInt32 bottom) = 0;
            /**
             * @brief Get the view mask's left border coordinate.
             * See SetMaskCoords() for details.
             * @return The left mask coordinate.
             */
            virtual SInt32 GetLeftMaskCoord() const = 0;
            /**
             * @brief Get the view mask's right border coordinate.
             * See SetMaskCoords() for details.
             * @return The right mask coordinate.
             */
            virtual SInt32 GetRightMaskCoord() const = 0;
            /**
             * @brief Get the view mask's top border coordinate.
             * See SetMaskCoords() for details.
             * @return The top mask coordinate.
             */
            virtual SInt32 GetTopMaskCoord() const = 0;
            /**
             * @brief Get the view mask's bottom border coordinate.
             * See SetMaskCoords() for details.
             * @return The bottom mask coordinate.
             */
            virtual SInt32 GetBottomMaskCoord() const = 0;
            
            /**
             * @brief Set the view mask's border anchors.
             * See SetMaskCoords() for details.
             * @param left The left mask anchor.
             * @param right The right mask anchor.
             * @param top The top mask anchor.
             * @param bottom The bottom mask anchor.
             * @return true if successful.
             */
            virtual Bool SetMaskAnchors(IEnums::AlignmentX left, IEnums::AlignmentX right, IEnums::AlignmentY top, IEnums::AlignmentY bottom) = 0;
            /**
             * @brief Set the view mask's horizontal border anchors.
             * See SetMaskCoords() for details.
             * @param left The left mask anchor.
             * @param right The right mask anchor.
             * @return true if successful.
             */
            virtual Bool SetMaskAnchorsX(IEnums::AlignmentX left, IEnums::AlignmentX right) = 0;
            /**
             * @brief Set the view mask's vertical border anchors.
             * See SetMaskCoords() for details.
             * @param top The top mask anchor.
             * @param bottom The bottom mask anchor.
             * @return true if successful.
             */
            virtual Bool SetMaskAnchorsY(IEnums::AlignmentY top, IEnums::AlignmentY bottom) = 0;
            /**
             * @brief Get the view mask's left border anchor.
             * See SetMaskCoords() for details.
             * @return The left mask anchor.
             */
            virtual IEnums::AlignmentX GetLeftMaskAnchor() const = 0;
            /**
             * @brief Get the view mask's right border anchor.
             * See SetMaskCoords() for details.
             * @return The right mask anchor.
             */
            virtual IEnums::AlignmentX GetRightMaskAnchor() const = 0;
            /**
             * @brief Get the view mask's top border anchor.
             * See SetMaskCoords() for details.
             * @return The top mask anchor.
             */
            virtual IEnums::AlignmentY GetTopMaskAnchor() const = 0;
            /**
             * @brief Get the view mask's bottom border anchor.
             * See SetMaskCoords() for details.
             * @return The bottom mask anchor.
             */
            virtual IEnums::AlignmentY GetBottomMaskAnchor() const = 0;
            
            /**
             * @brief Set the view's unit measures for width and height.
             * If a camera attached to this view is defining its view volume via its unit size
             * parameters for either X or Y direction or both (not via its FOV parameters), the
             * respective unit measures defined here are taken into account for calculating the
             * camera's projection matrix. By default, the view's unit measures in both dimensions
             * are set to IEnums::LENGTH_MEASURE_PIXELS. Note that if the view is rendering to
             * a frame buffer, this is the only allowed value.
             * @param measureX The width unit measure.
             * @param measureY The height unit measure.
             * @return true if successful.
             */
            virtual Bool SetUnitMeasures(IEnums::LengthMeasure measureX, IEnums::LengthMeasure measureY) = 0;
            /**
             * @brief Set the view's width unit measure.
             * See SetUnitMeasures().
             * @param measureX The width unit measure.
             * @return true if successful.
             */
            virtual Bool SetUnitMeasureX(IEnums::LengthMeasure measureX) = 0;
            /**
             * @brief Set the view's height unit measure.
             * See SetUnitMeasures().
             * @param measureY The height unit measure.
             * @return true if successful.
             */
            virtual Bool SetUnitMeasureY(IEnums::LengthMeasure measureY) = 0;
            /**
             * @brief Get the view's width unit measure.
             * @return The width unit measure.
             */
            virtual IEnums::LengthMeasure GetUnitMeasureX() const = 0;
            /**
             * @brief Get the view's height unit measure.
             * @return The height unit measure.
             */
            virtual IEnums::LengthMeasure GetUnitMeasureY() const = 0;
            
            /**
             * @brief Get the view's unit width.
             * If rendering to the system back buffer, the value returned equals the value specified
             * in the application's IEngineConfiguration. If rendering to a frame buffer, this value
             * is always 1.
             * @return The view's unit width
             */
            virtual Real GetUnitSizeX() const = 0;
            /**
             * @brief Get the view's unit height.
             * If rendering to the system back buffer, the value returned equals the value specified
             * in the application's IEngineConfiguration. If rendering to a frame buffer, this value
             * is always 1.
             * @return The view's unit height
             */
            virtual Real GetUnitSizeY() const = 0;
            
            /**
             * @brief Set the field of view.
             * This method sets the view's field of view in both horizontal and vertical
             * direction. These values act as multiplicators for any attached cameras, i.e.
             * if the view has a FOV of 3 and the camera a FOV of 2, the resulting visible
             * FOV will be 6. By default, both values are set to 1.
             * @param fovX The horizontal field of view.
             * @param fovY The vertical field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfView(Real fovX, Real fovY) = 0;
            /**
             * @brief Set the horizontal field of view.
             * @param fovX The horizontal field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfViewX(Real fovX) = 0;
            /**
             * @brief Set the vertical field of view, at the near plane.
             * @param fovY The vertical field of view.
             * @return true if successful.
             */
            virtual Bool SetFieldOfViewY(Real fovY) = 0;
            /**
             * @brief Get the horizontal field of view.
             * @return The horizontal field of view.
             */
            virtual Real GetFieldOfViewX() const = 0;
            /**
             * @brief Get the vertical field of view.
             * @return The vertical field of view.
             */
            virtual Real GetFieldOfViewY() const = 0;
            
            /**
             * @brief Get the horizontal pixel center offset.
             * The value returned by this method represents a horizontal offset usually in the
             * range from 0.0 to 1.0, which should be applied to the projection so that integer
             * coordinate values directly map to a unique pixel in the output surface.
             * This method returns the corresponding value from the IEngineConfiguration,
             * which is usually set by the platform at application startup.
             * @return The horizontal pixel center offset.
             */
            virtual Real GetPixelCenterX() const = 0;
            /**
             * @brief Get the vertical pixel center offset.
             * Analogous to GetPixelCenterX().
             * @return The vertical pixel center offset.
             */
            virtual Real GetPixelCenterY() const = 0;

            /**
             * @brief Get the output surface's actual width in pixels.
             * If rendering to the system back buffer, this value reflects the current width of
             * the output surface from the application's IAppConfiguration; this value may change
             * when e.g. the window size is changed in a windowed application. If rendering to
             * a frame buffer, this value reflects the frame buffer's actual width.
             * @return The output surface width in pixels.
             */
            virtual UInt32 GetDisplaySurfaceSizeX() const = 0;
            /**
             * @brief Get the output surface's actual height in pixels.
             * If rendering to the system back buffer, this value reflects the current height of
             * the output surface from the application's IAppConfiguration; this value may change
             * when e.g. the window size is changed in a windowed application. If rendering to
             * a frame buffer, this value reflects the frame buffer's actual height.
             * @return The output surface height in pixels.
             */
            virtual UInt32 GetDisplaySurfaceSizeY() const = 0;

            /**
             * @brief Get the renderer's surface orientation.
             * If rendering to the system back buffer, this value represents the current renderer
             * orientation in the application's IAppConfiguration. If rendering to a frame buffer,
             * the actual value is controlled by the orientation specified in the Graph::IFrameBuffer
             * node; see Graph::IFrameBuffer::SetRendererOrientation() for details.
             * @return The current renderer orientation.
             */
            virtual IEnums::Orientation GetDisplayRendererOrientation() const = 0;

            /**
             * @brief Get the current screen orientation.
             * @return The current screen orientation.
             */
            virtual IEnums::ScreenOrientation GetScreenOrientation() const = 0;

            /**
             * @brief Check if the output surface changed since the most recent frame.
             * @return true if the output surface dimensions have changed.
             */
            virtual Bool HasDisplaySurfaceChanged() const = 0;
            
            /**
             * @brief Get the view's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the view's internal video renderer object.
             * @param stage The stage to query.
             * @return The video renderer object.
             */
            virtual Video::IView* GetVideoViewObject(UInt32 stage) const = 0;
            /**
             * @brief Get the view's internal audio renderer object.
             * @param stage The stage to query.
             * @return The audio renderer object.
             */
            virtual Audio::IView* GetAudioViewObject(UInt32 stage) const = 0;
            
        protected:
            virtual ~IView() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IView nodes.
         */
        typedef IGenericNodeTarget<IView> IViewNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_VIEW_H__

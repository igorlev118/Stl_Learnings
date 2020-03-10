// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FRAME_BUFFER_H__
#define __MURL_GRAPH_I_FRAME_BUFFER_H__

#include "murl_graph_i_texture.h"

namespace Murl
{
    namespace Input
    {
        class IScreenArea;
    }
    
    namespace Video
    {
        class IFrameBuffer;
    }

    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IFrameBuffer
         * @brief The IFrameBuffer graph node interface.
         * Normally, all geometry contained in the scene graph gets rendered to the back buffer
         * provided by the platform, which gets presented to the user once per frame. For certain
         * purposes however, it can be necessary not to render directly to the back buffer but to
         * an off-screen area:
         * - Post-processing effects on the rendered scene
         * - Dynamic reflections
         * - Statically generated 2D backgrounds etc.
         *
         * A frame buffer represents a render target to such an off-screen area. To be able to
         * access the generated contents, a frame buffer must refer to at least one Graph::ITexture,
         * which holds the generated image after rendering to the frame buffer is complete, and
         * serves as the pixel input for a later render stage.
         *
         * Depending on which information is actually needed for such a later stage, one or more
         * different texture attachment points can be used for a given frame buffer, e.g. the color
         * target texture receives actual RGBA pixel color values, and a depth target texture
         * receives pixel depth values.
         *
         * Often, only color values are needed later but the rendering process requires an active
         * depth buffer for correct display. In such a case, it is not necessary to create and attach
         * a depth texture; instead, it is sufficient to explicitly set a depth buffer format to
         * create a depth buffer that is only used internally.
         *
         * To use a frame buffer for rendering, one or more Graph::IView nodes must refer to this
         * frame buffer; after activating a Graph::ICamera referring to such a view, all subsequent
         * geometry is then rendered to that frame buffer, with the given view and camera settings.
         *
         * Note, that when multiple textures are attached, all of these textures must have the
         * same dimensions, or initialization will fail.
         */
        class IFrameBuffer
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
             * @brief Get the mutable Graph::ITextureNodeTarget color buffer container.
             * This method returns a mutable pointer to the node's Graph::ITextureNodeTarget
             * container to set or query the referenced texture node used for storing the
             * frame buffer's output color values.
             * @return The mutable Graph::ITextureNodeTarget color buffer container, or null
             *      if not available.
             */
            virtual ITextureNodeTarget* GetColorTextureNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITextureNodeTarget color buffer container.
             * This method returns a constant pointer to the node's Graph::ITextureNodeTarget
             * container to query the referenced texture node used for storing the frame
             * buffer's output color values.
             * @return The constant Graph::ITextureNodeTarget color buffer container, or null
             *      if not available.
             */
            virtual const ITextureNodeTarget* GetColorTextureNodeTarget() const = 0;
            
            /**
             * @brief Get the mutable Graph::ITextureNodeTarget depth buffer container.
             * This method returns a mutable pointer to the node's Graph::ITextureNodeTarget
             * container to set or query the referenced texture node used for storing the
             * frame buffer's output depth values.
             * @return The mutable Graph::ITextureNodeTarget depth buffer container, or null
             *      if not available.
             */
            virtual ITextureNodeTarget* GetDepthTextureNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITextureNodeTarget depth buffer container.
             * This method returns a constant pointer to the node's Graph::ITextureNodeTarget
             * container to query the referenced texture node used for storing the frame
             * buffer's output depth values.
             * @return The constant Graph::ITextureNodeTarget depth buffer container, or null
             *      if not available.
             */
            virtual const ITextureNodeTarget* GetDepthTextureNodeTarget() const = 0;
            
            /**
             * @brief Get the mutable Graph::ITextureNodeTarget stencil buffer container.
             * This method returns a mutable pointer to the node's Graph::ITextureNodeTarget
             * container to set or query the referenced texture node used for storing the
             * frame buffer's output stencil values.
             * @return The mutable Graph::ITextureNodeTarget stencil buffer container, or null
             *      if not available.
             */
            virtual ITextureNodeTarget* GetStencilTextureNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ITextureNodeTarget stencil buffer container.
             * This method returns a constant pointer to the node's Graph::ITextureNodeTarget
             * container to query the referenced texture node used for storing the frame
             * buffer's output stencil values.
             * @return The constant Graph::ITextureNodeTarget stencil buffer container, or null
             *      if not available.
             */
            virtual const ITextureNodeTarget* GetStencilTextureNodeTarget() const = 0;
            
            /**
             * @brief Explicitly set the format of the depth buffer.
             * If no texture is specified as a target for storing depth buffer values, the
             * explicit depth buffer format is used to create an offscreen buffer. In that
             * case, the depth buffer is only used for rendering internally and cannot be
             * accessed from the outside.
             * @param format The explicit depth buffer format.
             * @return true if successful.
             */
            virtual Bool SetDepthBufferFormat(IEnums::DepthBufferFormat format) = 0;
            /**
             * @brief Get the explicit depth buffer format.
             * @return The explicit depth buffer format.
             */
            virtual IEnums::DepthBufferFormat GetDepthBufferFormat() const = 0;

            /**
             * @brief Explicitly set the format of the stencil buffer.
             * If no texture is specified as a target for storing stencil buffer values, the
             * explicit stencil buffer format is used to create an offscreen buffer. In that
             * case, the stencil buffer is only used for rendering internally and cannot be
             * accessed from the outside.
             * @param format The explicit stencil buffer format.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferFormat(IEnums::StencilBufferFormat format) = 0;
            /**
             * @brief Get the explicit stencil buffer format.
             * @return The explicit stencil buffer format.
             */
            virtual IEnums::StencilBufferFormat GetStencilBufferFormat() const = 0;
            
            /**
             * @brief Set the framebuffer's orientation.
             * By default, the framebuffer has this value set to IEnums::ORIENTATION_ROTATE_0,
             * so all views referring to this framebuffer as a render target will render
             * their contents 'upright'. For certain cases, like post-processing in image
             * space, it may be necessary that the framebuffer receives its contents in the
             * same orientation as the back buffer. This can be achieved by calling this
             * method with IEnums::ORIENTATION_DEFAULT.
             * @param orientation One of the four values NORMAL, ROTATE_CW, FLIP or ROTATE_CCW
             *      to define a fixed framebuffer orientation, or DEFAULT to select the main
             *      back buffer's orientation.
             * @return true if successful.
             */
            virtual Bool SetRendererOrientation(IEnums::Orientation orientation) = 0;
            /**
             * @brief Get the framebuffer's orientation.
             * @return One of the four values NORMAL, ROTATE_CW, FLIP or ROTATE_CCW if the
             *      framebuffer has a fixed orientation, or DEFAULT if the main back buffer's
             *      orientation is used.
             */
            virtual IEnums::Orientation GetRendererOrientation() const = 0;

            /**
             * @brief Enable/disable color de-linearization when writing to the color buffer, if available.
             * By default, a fragment shader's color output RGB values are written to the output color
             * buffer without any conversion. If the shader performs operations on linear color values
             * and the target color buffer is a regular integer RGB(A) texture or render buffer, the output 
             * will be too dark, as the target color buffer expects gamma-corrected values. In this
             * case, de-linearization should be enabled on the frame buffer, so that the usual gamma value
             * of 2.2 is applied to the output pixels. Note, that floating point color buffers are always
             * linear, so this has no effect.
             * @param enabled If true, color de-linearization is enabled.
             * @return true if successful.
             */
            virtual Bool SetDelinearizationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if color de-linearization during rendering is enabled.
             * @return true if enabled.
             */
            virtual Bool IsDelinearizationEnabled() const = 0;

            /**
             * @brief Enable/disable automatic MIP map generation.
             * @param enabled If true, automatic MIP map generation is enabled.
             * @return true if successful.
             */
            virtual Bool SetMipMapGenerationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if automatic MIP map generation is enabled.
             * @return true if automatic MIP map generation is enabled.
             */
            virtual Bool IsMipMapGenerationEnabled() const = 0;

            /**
             * @brief Set the target texture layer when rendering to an array texture.
             * By default, the output is rendered to layer 0.
             * This value is ignored for non-array textures.
             * @param layer The target layer.
             * @return true if successful.
             */
            virtual Bool SetTargetLayer(UInt32 layer) = 0;
            /**
             * @brief Get the target texture layer for rendering.
             * @return The MIP level.
             */
            virtual UInt32 GetTargetLayer() const = 0;

            /**
             * @brief Set the target MIP level when rendering to (a) mip-mapped texture(s).
             * By default, the output is rendered to a texture's base level, i.e. level=0.
             * This value is ignored if automatic MIP map generation is enabled via
             * SetMipMapGenerationEnabled().
             * @param level The target MIP level.
             * @return true if successful.
             */
            virtual Bool SetTargetMipLevel(UInt32 level) = 0;
            /**
             * @brief Get the target MIP level for rendering.
             * @return The MIP level.
             */
            virtual UInt32 GetTargetMipLevel() const = 0;

            /**
             * @brief Set the number of samples for multisample anti-aliasing.
             * By default, the number of samples is set to 1, i.e. multisampling is disabled.
             * A value of 0 indicates that the global number of samples is to be used, which can
             * be configured via IEngineConfiguration::SetNumberOfAntiAliasSamples().
             * A value greater than 1 enables multisampling for this frame buffer, with the given
             * number of samples clamped to the maximum allowed value indicated by the GPU.
             * @param numSamples The number of samples.
             * @return true if successful.
             */
            virtual Bool SetNumberOfSamples(UInt32 numSamples) = 0;
            /**
             * @brief Get the number of samples for multisample anti-aliasing.
             * @return The number of samples.
             */
            virtual UInt32 GetNumberOfSamples() const = 0;

            /**
             * @brief Set the frame buffers's absolute sort order.
             * Frame buffers are generally processed in the order in which they receive
             * drawables during rendering. If a frame buffer depends on another frame buffer,
             * which should be updated before it is used, it is often desired to specify
             * an explicit order in which the frame buffers are processed globally.
             * Setting a higher sort order results in the frame buffer always being processed
             * after all frame buffers with a lower order have been updated. Frame buffers
             * with the same sort order are processed in the order in which they get filled
             * with drawables. 
             * Note: The back buffer is always processed last.
             * @param sortOrder The global order of this frame buffer.
             * @return true if successful.
             */
            virtual Bool SetSortOrder(SInt32 sortOrder) = 0;
            /**
             * @brief Get the frame buffers's global sort order.
             * @return The global order.
             */
            virtual SInt32 GetSortOrder() const = 0;

            /**
             * @brief Get the frame buffer width.
             * @return The frame buffer width in pixels (texels).
             */
            virtual UInt32 GetSizeX() const = 0;
            /**
             * @brief Get the frame buffer height.
             * @return The frame buffer height in pixels (texels).
             */
            virtual UInt32 GetSizeY() const = 0;
            
            /**
             * @brief Set the input coordinate reference size.
             * Generally, input coordinates are represented by values ranging from -1.0 to 1.0.
             * As a convenience, this method can be used to set an arbitrary reference size for
             * both dimensions of the frame buffer; this way it is possible to specify integer (pixel)
             * values instead of (quite unreadable) floats. By default, both sizeX and sizeY
             * are set to 1.0.
             * See also Graph::IButton::SetOutCoordSize() as the counterpart providing the actual
             * input coordinates.
             * @param sizeX The horizontal coordinate reference size.
             * @param sizeY The vertical coordinate reference size.
             * @return true if successful.
             */
            virtual Bool SetInCoordSize(Real sizeX, Real sizeY) = 0;
            /**
             * @brief Set the horizontal input coordinate reference size.
             * See SetInCoordSize().
             * @param sizeX The horizontal coordinate reference size.
             * @return true if successful.
             */
            virtual Bool SetInCoordSizeX(Real sizeX) = 0;
            /**
             * @brief Set the vertical input coordinate reference size.
             * See SetInCoordSize().
             * @param sizeY The vertical coordinate reference size.
             * @return true if successful.
             */
            virtual Bool SetInCoordSizeY(Real sizeY) = 0;
            /**
             * @brief Get the horizontal input coordinate reference size.
             * See SetInCoordSize().
             * @return The horizontal input coordinate reference size.
             */
            virtual Real GetInCoordSizeX() const = 0;
            /**
             * @brief Get the vertical input coordinate reference size.
             * See SetInCoordSize().
             * @return The vertical output coordinate reference size.
             */
            virtual Real GetInCoordSizeY() const = 0;
            
            /**
             * @brief Set the frame buffer's input coordinate range.
             * This method sets the frame buffer's start and end input coordinates.
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoord(Real x1, Real y1, Real x2, Real y2) = 0;
            /**
             * @brief Set the frame buffer's input coordinate start.
             * See SetInCoord().
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoord1(Real x1, Real y1) = 0;
            /**
             * @brief Set the frame buffer's input coordinate end.
             * See SetInCoord().
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoord2(Real x2, Real y2) = 0;
            /**
             * @brief Set the frame buffer's horizontal start input coordinate.
             * See SetInCoord().
             * @param x1 The start coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordX1(Real x1) = 0;
            /**
             * @brief Set the frame buffer's vertical start input coordinates.
             * See SetInCoord().
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordY1(Real y1) = 0;
            /**
             * @brief Set the frame buffer's horizontal end input coordinate.
             * See SetInCoord().
             * @param x2 The end coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordX2(Real x2) = 0;
            /**
             * @brief Set the frame buffer's vertical end input coordinates.
             * See SetInCoord().
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordY2(Real y2) = 0;
            /**
             * @brief Get the frame buffer's horizontal start input coordinate.
             * See SetInCoord().
             * @return The start coordinate in X direction.
             */
            virtual Real GetInCoordX1() const = 0;
            /**
             * @brief Get the frame buffer's vertical start input coordinate.
             * See SetInCoord().
             * @return The start coordinate in Y direction.
             */
            virtual Real GetInCoordY1() const = 0;
            /**
             * @brief Get the frame buffer's horizontal end input coordinate.
             * See SetInCoord().
             * @return The end coordinate in X direction.
             */
            virtual Real GetInCoordX2() const = 0;
            /**
             * @brief Get the frame buffer's vertical end input coordinate.
             * See SetInCoord().
             * @return The end coordinate in Y direction.
             */
            virtual Real GetInCoordY2() const = 0;
            
            /**
             * @brief Get the frame buffer's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the frame buffer's internal video renderer object.
             * @param stage The stage to query.
             * @return The video renderer object.
             */
            virtual Video::IFrameBuffer* GetVideoFrameBufferObject(UInt32 stage) const = 0;
            /**
             * @brief Get the frame buffer's internal input screen area object.
             * @param stage The stage to query.
             * @return The input object.
             */
            virtual Input::IScreenArea* GetInputScreenAreaObject(UInt32 stage) const = 0;
            
        protected:
            virtual ~IFrameBuffer() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IFrameBuffer nodes.
         */
        typedef IGenericNodeTarget<IFrameBuffer> IFrameBufferNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_FRAME_BUFFER_H__

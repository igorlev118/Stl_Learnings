// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_FRAME_BUFFER_H__
#define __MURL_VIDEO_I_FRAME_BUFFER_H__

#include "murl_video_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;
        class IProgram;
        class ITexture;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IFrameBuffer
         * @brief The IFrameBuffer video object interface.
         * This interface represents a frame buffer render target used for off-screen
         * rendering. It encapsulates different optional target textures or render buffers
         * for color, depth and/or stencil output.
         *
         * Used internally by Graph::FrameBuffer.
         */
        class IFrameBuffer
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
             * @brief Enable the frame buffer for rendering.
             * @param targetIndex The target index. Must be 0 when rendering to a 2D texture,
             *      or in the range from 0 to 5 when rendering to a cube map.
             * @return true if successful.
             */
            virtual Bool Enable(UInt32 targetIndex) = 0;
            /**
             * @brief Disable the frame buffer.
             * @param targetIndex The target index. Must be 0 when rendering to a 2D texture,
             *      or in the range from 0 to 5 when rendering to a cube map.
             * @return true if successful.
             */
            virtual Bool Disable(UInt32 targetIndex) = 0;

            /**
             * @brief Resolve the frame buffer.
             * @param targetIndex The target index. Must be 0 when rendering to a 2D texture,
             *      or in the range from 0 to 5 when rendering to a cube map.
             * @return true if successful.
             */
            virtual Bool Resolve(UInt32 targetIndex) = 0;

            /**
             * @brief Attach the frame buffer to the current GPU program.
             * @param currentProgram The current GPU program.
             * @param targetIndex The target index. Must be 0 when rendering to a 2D texture,
             *      or in the range from 0 to 5 when rendering to a cube map.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram, UInt32 targetIndex) = 0;

            /**
             * @brief Touch the frame buffer after rendering.
             * Especially on mobile devices, some flawed graphics driver implementations run into
             * trouble when a frame buffer is updated but the generated textures are not used
             * for rendering, which is a perfectly valid use case for e.g. pre-rendering some
             * scenery to an offscreen buffer for later use. To overcome these problems, the
             * renderer briefly activates the output textures for all frame buffers that are
             * updated in a given frame.
             * @param frameCount The current frame count.
             * @return true if successful.
             */
            virtual Bool TouchTextures(UInt32 frameCount) = 0;

            /**
             * @brief Set the internal format of the depth buffer.
             * If an explicit depth texture is defined via SetTargetDepthTexture(), the given
             * value is ignored.
             * If format is set to a value other than IEnums::DEPTH_BUFFER_FORMAT_NONE, an
             * internal render buffer is created to hold intermediate depth information of the
             * given format.
             * If format is IEnums::DEPTH_BUFFER_FORMAT_NONE, depth buffering is disabled.
             * @param format The optional depth buffer format.
             * @return true if successful.
             */
            virtual Bool SetDepthBufferFormat(IEnums::DepthBufferFormat format) = 0;
            /**
             * @brief Get the internal format of the depth buffer.
             * @return The optional depth buffer format.
             */
            virtual IEnums::DepthBufferFormat GetDepthBufferFormat() const = 0;
            
            /**
             * @brief Set the internal format of the stencil buffer.
             * If an explicit stencil texture is defined via SetTargetStencilTexture(), the given
             * value is ignored.
             * If format is set to a value other than IEnums::STENCIL_BUFFER_FORMAT_NONE, an
             * internal render buffer is created to hold intermediate stencil information of the
             * given format.
             * If format is IEnums::STENCIL_BUFFER_FORMAT_NONE, stencil buffering is disabled.
             * @param format The optional stencil buffer format.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferFormat(IEnums::StencilBufferFormat format) = 0;
            /**
             * @brief Get the internal format of the stencil buffer.
             * @return The optional stencil buffer format.
             */
            virtual IEnums::StencilBufferFormat GetStencilBufferFormat() const = 0;

            /**
             * @brief Set an optional target texture receiving the color output.
             * If no color texture is defined, the color output of the rendering is discarded.
             * @param texture The target texture to attach.
             * @param unit The index of the texture. Currently, only index 0 is supported
             *      (multiple render targets not available).
             * @return true if successful.
             */
            virtual Bool SetTargetColorTexture(ITexture* texture, UInt32 unit) = 0;
            /**
             * @brief Get the target color texture at a given unit.
             * @param unit The index of the texture. Currently, only index 0 is supported
             *      (multiple render targets not available).
             * @return The attached texture, or null if not set.
             */
            virtual ITexture* GetTargetColorTexture(UInt32 unit) const = 0;
            
            /**
             * @brief Set an optional target texture receiving the depth output.
             * If no depth texture is defined, the format set via SetDepthBufferFormat()
             * is used to possibly create an internal render buffer.
             * @param texture The target texture to attach.
             * @return true if successful.
             */
            virtual Bool SetTargetDepthTexture(ITexture* texture) = 0;
            /**
             * @brief Get the target depth texture.
             * @return The attached texture, or null if not set.
             */
            virtual ITexture* GetTargetDepthTexture() const = 0;
            
            /**
             * @brief Set an optional target texture receiving the stencil output.
             * If no stencil texture is defined, the format set via SetStencilBufferFormat()
             * is used to possibly create an internal render buffer.
             * It is possible to attach the same texture as both a depth and stencil target,
             * in this case the texture's pixel format must be set to IEnums::PIXEL_FORMAT_D24_S8.
             * @param texture The target texture to attach.
             * @return true if successful.
             */
            virtual Bool SetTargetStencilTexture(ITexture* texture) = 0;
            /**
             * @brief Get the target stencil texture.
             * @return The attached texture, or null if not set.
             */
            virtual ITexture* GetTargetStencilTexture() const = 0;

            /**
             * @brief Enable/disable color de-linearization.
             * @param enabled If true, color de-linearization is enabled.
             * @return true if successful.
             */
            virtual Bool SetDelinearizationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if color de-linearization is enabled.
             * @return true if color de-linearization is enabled.
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
             * A value of 0 or 1 disables multisampling.
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
             * @brief Get the horizontal output texture/render buffer size in pixels.
             * @return The size in pixels.
             */
            virtual UInt32 GetSizeX() const = 0;
            /**
             * @brief Get the vertical output texture/render buffer size in pixels.
             * @return The size in pixels.
             */
            virtual UInt32 GetSizeY() const = 0;

            /**
             * @brief Get the number of targets.
             * If the frame buffer is used to render to a 2D texture, this method returns 1.
             * If rendering to a cube map, 6 is returned.
             * @return The number of targets.
             */
            virtual UInt32 GetNumberOfTargets() const = 0;
            
            /**
             * @brief Get the offset matrix for a given target index.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return The offset matrix.
             */
            virtual const Matrix& GetViewOffsetMatrix(UInt32 targetIndex) const = 0;

            /**
             * @brief Check if the frame buffer is complete.
             * @return true if complete.
             */
            virtual Bool IsComplete() const = 0;

            /**
             * @brief Detach a texture from all binding points it is present.
             * @param texture The texture to detach.
             * @return true if OK.
             */
            virtual Bool DetachTexture(ITexture* texture) = 0;

        protected:
            virtual ~IFrameBuffer() {}
        };
    }
}

#endif // __MURL_VIDEO_I_FRAME_BUFFER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_TEXTURE_H__
#define __MURL_VIDEO_I_TEXTURE_H__

#include "murl_video_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IVideoStream;
    
    namespace Video
    {
        class IObject;
        class IProgram;
        class IFrameBuffer;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface ITexture
         * @brief The ITexture video object interface.
         * This interface represents a GPU texture, either 2D or cube map.
         *
         * Used internally by various geometry texture nodes, such as Graph::FlatTexture,
         * Graph::CubemapTexture, Graph::FrameBufferTexture and others.
         */
        class ITexture
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
             * @brief Enable the texture at a given unit.
             * @param unit The texture unit, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Enable(UInt32 unit) = 0;
            /**
             * @brief Disable the texture at a given unit.
             * @param unit The texture unit, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Disable(UInt32 unit) = 0;

            /**
             * @brief Attach the texture to the current GPU program at a given unit.
             * @param currentProgram The current GPU program.
             * @param unit The texture unit, from 0 to IEnums::NUM_TEXTURE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram, UInt32 unit) = 0;
            
            /**
             * @brief Set the texture type.
             * @param type One of the available texture types.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::TextureType type) = 0;
            /**
             * @brief Get the texture type.
             * @return The actual texture type.
             */
            virtual IEnums::TextureType GetType() const = 0;

            /**
             * @brief Define if this texture supports being rendered to.
             * @param supported If true, this texture can act as a render target.
             * @return true if successful.
             */
            virtual Bool SetRenderTargetSupported(Bool supported) = 0;
            /**
             * @brief Check if this texture supports being rendered to.
             * @return true if this texture can act as a render target.
             */
            virtual Bool IsRenderTargetSupported() const = 0;
            
            /**
             * @brief Enable/disable mip-mapping for this texture.
             * @param enabled If true, mip-maps are enabled.
             * @return true if successful.
             */
            virtual Bool SetMipMappingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if mip-mapping is enabled for this texture.
             * @return true if enabled.
             */
            virtual Bool IsMipMappingEnabled() const = 0;

            /**
             * @brief Set the texture's wrap mode in X direction.
             * @param mode The wrap mode.
             * @return true if successful.
             */
            virtual Bool SetWrapModeX(IEnums::TextureWrapMode mode) = 0;
            /**
             * @brief Set the texture's wrap mode in Y direction.
             * @param mode The wrap mode.
             * @return true if successful.
             */
            virtual Bool SetWrapModeY(IEnums::TextureWrapMode mode) = 0;
            /**
             * @brief Set the texture's wrap mode in Z direction.
             * @param mode The wrap mode.
             * @return true if successful.
             */
            virtual Bool SetWrapModeZ(IEnums::TextureWrapMode mode) = 0;
            /**
             * @brief Get the texture's wrap mode in X direction.
             * @return The wrap mode.
             */
            virtual IEnums::TextureWrapMode GetWrapModeX() const = 0;
            /**
             * @brief Get the texture's wrap mode in Y direction.
             * @return The wrap mode.
             */
            virtual IEnums::TextureWrapMode GetWrapModeY() const = 0;
            /**
             * @brief Get the texture's wrap mode in Z direction.
             * @return The wrap mode.
             */
            virtual IEnums::TextureWrapMode GetWrapModeZ() const = 0;

            /**
             * @brief Set the texture filter used for magnification.
             * @param magFilter The filter to use.
             * @return true if successful.
             */
            virtual Bool SetMagFilter(IEnums::TextureFilter magFilter) = 0;
            /**
             * @brief Set the texture filters used for minification and MIP level selection.
             * @param minFilter The minification filter to use.
             * @param mipFilter The MIP level selection filter to use.
             * @return true if successful.
             */
            virtual Bool SetMinFilter(IEnums::TextureFilter minFilter, IEnums::TextureFilter mipFilter) = 0;
            /**
             * @brief Get the texture filter used for magnification.
             * @return The filter used.
             */
            virtual IEnums::TextureFilter GetMagFilter() const = 0;
            /**
             * @brief Get the texture filter used for minification.
             * @return The filter used.
             */
            virtual IEnums::TextureFilter GetMinFilter() const = 0;
            /**
             * @brief Get the texture filter used for mip-level selection.
             * @return The filter used.
             */
            virtual IEnums::TextureFilter GetMipFilter() const = 0;

            /**
             * @brief Set the depth compare mode, if the pixel format defines a depth texture.
             * @param mode The depth compare mode to use.
             * @return true if successful.
             */
            virtual Bool SetDepthTestMode(IEnums::DepthTestMode mode) = 0;
            /**
             * @brief Get the depth compare mode.
             * @return The depth compare mode used.
             */
            virtual IEnums::DepthTestMode GetDepthTestMode() const = 0;

            /**
             * @brief Set the depth test function, if the pixel format defines a depth texture and the depth compare mode is not NONE.
             * @param function The depth test function to use.
             * @return true if successful.
             */
            virtual Bool SetDepthTestFunction(IEnums::DepthTestFunction function) = 0;
            /**
             * @brief Get the depth test function.
             * @return The depth test function used.
             */
            virtual IEnums::DepthTestFunction GetDepthTestFunction() const = 0;
            
            /**
             * @brief Set the maximum anisotropy for filtering.
             * The given value is clamped to the range from 1.0 to the highest possible value 
             * defined in the graphics driver/hardware, with 1.0 representing isotropic filtering 
             * (fastest), and higher values producing better visual results at the cost of 
             * rendering performance.
             * @param maxAnisotropy The maximum anisotropy value.
             * @return true if successful.
             */
            virtual Bool SetMaxAnisotropy(Real maxAnisotropy) = 0;
            /**
             * @brief Set the maximum anisotropy for filtering.
             * @return The maximum anisotropy value.
             */
            virtual Real GetMaxAnisotropy() const = 0;

            /**
             * @brief Set the number of actual targets.
             * For flat or cubemap textures, the number of targets must be 1 or 6, respectively.
             * For cubemap array textures the given value must be dividable by 6.
             * @param numTargets The number of targets.
             * @return true if successful.
             */
            virtual Bool SetNumberOfTargets(UInt32 numTargets) = 0;
            /**
             * @brief Get the number of actual targets.
             * This method should return 1 for 2D textures, and 6 for cube maps.
             * @return The number of targets.
             */
            virtual UInt32 GetNumberOfTargets() const = 0;

            /**
             * @brief Define the source data via a given video stream.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @param stream The video stream to set.
             * @return true if successful.
             */
            virtual Bool SetSourceStream(UInt32 targetIndex, IVideoStream* stream) = 0;
            /**
             * @brief Define the source data via a given format and dimensions.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @param sizeX The horizontal size in pixels.
             * @param sizeY The vertical size in pixels.
             * @param pixelFormat The pixel format to use.
             * @param useSystemMemory If false, the texture should be created in GPU memory.
             * @return true if successful.
             */
            virtual Bool DefineSourceData(UInt32 targetIndex, UInt32 sizeX, UInt32 sizeY, IEnums::PixelFormat pixelFormat, Bool useSystemMemory) = 0;
            /**
             * @brief Mark a texture target as modified.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return true if successful.
             */
            virtual Bool SetSourceModified(UInt32 targetIndex) = 0;
            /**
             * @brief Check if the texture is modified.
             * @return true if modified.
             */
            virtual Bool IsSourceModified() const = 0;

            /**
             * @brief Get the source stream for a target if it has been set.
             * This method returns the source stream for a target, if it has been set via
             * SetSourceStream(). If DefineSourceData() or none of these methods was used,
             * a null pointer is returned.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return The source stream if present, null otherwise.
             */
            virtual IVideoStream* GetSourceStream(UInt32 targetIndex) const = 0;
            /**
             * @brief Get the raw source data for a target if it has been set.
             * This method returns a pointer to the raw source data for a target, if it has 
             * been defined via DefineSourceData(). Otherwise, a null pointer is returned.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return The raw source data if present, null otherwise.
             */
            virtual UInt8* GetSourceData(UInt32 targetIndex) const = 0;
            /**
             * @brief Get the horizontal source pixel size of the base MIP level, if defined.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return The horizontal source size in pixels.
             */
            virtual UInt32 GetSourceSizeX(UInt32 targetIndex) const = 0;
            /**
             * @brief Get the vertical source pixel size of the base MIP level, if defined.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return The vertical source size in pixels.
             */
            virtual UInt32 GetSourceSizeY(UInt32 targetIndex) const = 0;
            /**
             * @brief Get the line pitch (stride) of the source data, if defined.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return The line pitch in bytes.
             */
            virtual UInt32 GetSourcePitch(UInt32 targetIndex) const = 0;
            /**
             * @brief Get the pixel format of the source data, if defined.
             * @param targetIndex The target index, from 0 to GetNumberOfTargets()-1.
             * @return The pixel format.
             */
            virtual IEnums::PixelFormat GetSourcePixelFormat(UInt32 targetIndex) const = 0;

            /**
             * @brief Attach the texture to a frame buffer.
             * In order for this method to succeed, SetRenderTargetSupported(true) must be called.
             * @param frameBuffer The frame buffer to attach the texture to.
             * @param attachment The attachment point.
             * @param targetLayer The target array layer
             * @param targetFace The target face, from 0 to GetNumberOfTargets()-1.
             * @param targetLevel The target MIP level
             * @return true if successful.
             */
            virtual Bool AttachToFrameBuffer(IFrameBuffer* frameBuffer, IEnums::TextureAttachment attachment, UInt32 targetLayer, UInt32 targetFace, UInt32 targetLevel) = 0;
            /**
             * @brief Detach the texture from a frame buffer.
             * @param frameBuffer The frame buffer to detach the texture from.
             * @param attachment The attachment point.
             * @param targetLayer The target array layer
             * @param targetFace The target face, from 0 to GetNumberOfTargets()-1.
             * @param targetLevel The target MIP level
             * @return true if successful.
             */
            virtual Bool DetachFromFrameBuffer(IFrameBuffer* frameBuffer, IEnums::TextureAttachment attachment, UInt32 targetLayer, UInt32 targetFace, UInt32 targetLevel) = 0;
            /**
             * @brief Check if the texure is attached to a frame buffer.
             * @param frameBuffer The frame buffer to check.
             * @param attachment The attachment point.
             * @param targetLayer The target array layer
             * @param targetFace The target face, from 0 to GetNumberOfTargets()-1.
             * @param targetLevel The target MIP level
             * @return true if attached.
             */
            virtual Bool IsAttachedToFrameBuffer(IFrameBuffer* frameBuffer, IEnums::TextureAttachment attachment, UInt32 targetLayer, UInt32 targetFace, UInt32 targetLevel) const = 0;

        protected:
            virtual ~ITexture() {}
        };
    }
}

#endif // __MURL_VIDEO_I_TEXTURE_H__

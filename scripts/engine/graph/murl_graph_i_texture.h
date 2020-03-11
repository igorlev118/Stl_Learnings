// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TEXTURE_H__
#define __MURL_GRAPH_I_TEXTURE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_graph_i_state_slot.h"
#include "murl_graph_i_state_unit.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IVideoStream;

    namespace Video
    {
        class ITexture;
    }
    
    namespace Graph
    {
        class ITexture;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITexture nodes.
         */
        typedef IGenericNodeTarget<ITexture> ITextureNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITexture
         * @brief The ITexture graph node interface.
         * This interface represents a generic node representing a texture for rendering.
         */
        class ITexture : public IStateSlot, public IStateUnit
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
             * @brief Get the mutable container holding the optional child textures.
             * This method returns a mutable pointer to the node's Graph::ITextureNodeTarget
             * sub container, which is used to store multiple sub-textures.
             * @return The mutable Graph::ITextureNodeTarget container, or null if not available.
             */
            virtual ITextureNodeTarget* GetSubTextureNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the optional child textures.
             * This method returns a constant pointer to the node's Graph::ITextureNodeTarget
             * sub container, which is used to store multiple sub-textures.
             * @return The constant Graph::ITextureNodeTarget container, or null if not available.
             */
            virtual const ITextureNodeTarget* GetSubTextureNodeTarget() const = 0;
            
            /**
             * @brief Get a mutable Graph::IImageResourceTarget container.
             * This method returns a mutable pointer to a Graph::IImageResourceTarget
             * container, which allows to add, remove or query the image resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IImageResourceTarget container, or null if not available
             */
            virtual IImageResourceTarget* GetImageResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IImageResourceTarget container.
             * This method returns a constant pointer to a Graph::IImageResourceTarget
             * container, which allows to query the image resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IImageResourceTarget container, or null if not available
             */
            virtual const IImageResourceTarget* GetImageResourceTarget() const = 0;

            /**
             * @brief Manually set a video stream for a given layer and target.
             * This method can be used to supply a manually created video stream as the texture's
             * pixel source. Note, that you cannot supply both an image resource and a video stream
             * for the same target. Note also, that the user is responsible for correct destruction
             * of the given stream.
             * The layer parameter must specify a layer in the range from 0 to GetNumberOfLayers()-1.
             * @param target The texture target (flat, or one of the 6 cube map sides)
             * @param layer The texture layer
             * @param stream The video stream to apply.
             * @return true if successful.
             */
            virtual Bool SetVideoStream(IEnums::TextureTarget target, UInt32 layer, IVideoStream* stream) = 0;
            /**
             * @brief Manually set a video stream for layer 0 and a given target.
             * This method can be used to supply a manually created video stream as the texture's
             * pixel source. Note, that you cannot supply both an image resource and a video stream
             * for the same target. Note also, that the user is responsible for correct destruction
             * of the given stream.
             * @param target The texture target (flat, or one of the 6 cube map sides)
             * @param stream The video stream to apply.
             * @return true if successful.
             */
            virtual Bool SetVideoStream(IEnums::TextureTarget target, IVideoStream* stream) = 0;
            /**
             * @brief Get the video stream for a given layer and target.
             * @param layer The texture layer
             * @param target The texture target to query
             * @return The video stream at the given target, or null if none is active.
             */
            virtual IVideoStream* GetVideoStream(IEnums::TextureTarget target, UInt32 layer) const = 0;
            /**
             * @brief Get the video stream for layer 0 and a given target.
             * @param target The texture target to query
             * @return The video stream at the given target, or null if none is active.
             */
            virtual IVideoStream* GetVideoStream(IEnums::TextureTarget target) const = 0;

            /**
             * @brief Set the texture type.
             * For a generic node implementing this interface, the actual texture type may be set
             * using this method. For specialized implementations that implicitly set the type (like
             * flat textures or cube maps), this method always returns false.
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
             * @brief Set the number of texture layers.
             * If the node's type is not an array texture (flat or cubemap), this method returns false.
             * See SetType().
             * @param numLayers The number of array layers.
             * @return true if successful.
             */
            virtual Bool SetNumberOfLayers(UInt32 numLayers) = 0;
            /**
             * @brief Get the number of texture layers.
             * If the node's type is not an array texture (flat or cubemap), this method always returns 1.
             * See SetType().
             * @return The number of array layers.
             */
            virtual UInt32 GetNumberOfLayers() const = 0;

            /**
             * @brief Set the MIP map generation mode.
             * By default, the MIP map generation mode is set to IEnums::MIP_MAP_GENERATION_MODE_FAST.
             * @param mode The MIP map generation mode.
             * @return true if successful.
             */
            virtual Bool SetMipMapGenerationMode(IEnums::MipMapGenerationMode mode) = 0;
            /**
             * @brief Get the texture type.
             * @return The actual texture type.
             */
            virtual IEnums::MipMapGenerationMode GetMipMapGenerationMode() const = 0;

            /**
             * @brief Set the texure's dimensions.
             * A given value has no effect if a positive non-zero scale
             * factor is defined for the respective axis via SetAutoScaleFactor().
             * @param sizeX The texture width in pixels.
             * @param sizeY The texture height in pixels.
             * @return true if successful.
             */
            virtual Bool SetSize(UInt32 sizeX, UInt32 sizeY) = 0;
            /**
             * @brief Get the texture's base width.
             * This returns the base width of the texture (at MIP level 0), which is either 
             * defined via SetSize(), SetAutoScaleFactor() or implicitly from a given image
             * resource when none of the previous value is defined. A possible prescale 
             * factor is not considered.
             * @return The texture width in pixels.
             */
            virtual UInt32 GetSizeX() const = 0;
            /**
             * @brief Get the texture's base height.
             * See GetSizeX().
             * @return The texture height in pixels.
             */
            virtual UInt32 GetSizeY() const = 0;
            
            /**
             * @brief Set the texure's auto scale factors.
             * By default, the auto scale factors for both axes are set to
             * 0.0, and the texture's dimensions match the values given via
             * SetSize(). If any of the given scale factors is a positive 
             * non-zero value, the actual texture dimension for the respective
             * axis is calculated from the current output surface dimension
             * multiplied by that factor. In this case, a size value set via
             * SetSize() has no effect. The current output surface size is
             * retrieved via IAppConfiguration::GetDisplaySurfaceSizeX() and
             * IAppConfiguration::GetDisplaySurfaceSizeY().
             * This is useful for e.g. post-processing frame buffer textures,
             * which are supposed to match the current output display dimensions.
             * For example, to create a texture that is half as wide and equal
             * in height as the current output surface, specify a value of 0.5
             * for scaleX and a value of 1.0 for scaleY.
             * @param scaleX The width scale factor.
             * @param scaleY The height scale factor.
             * @return true if successful.
             */
            virtual Bool SetAutoScaleFactor(Real scaleX, Real scaleY) = 0;
            /**
             * @brief Get the texture's width.
             * @return The texture width in pixels.
             */
            virtual Real GetAutoScaleFactorX() const = 0;
            /**
             * @brief Get the texture's height.
             * @return The texture height in pixels.
             */
            virtual Real GetAutoScaleFactorY() const = 0;

            /**
             * @brief Enable/disable the alpha channel for this texture.
             * @param enabled If true, the alpha channel should be used.
             * @return true if successful.
             */
            virtual Bool SetAlphaEnabled(Bool enabled) = 0;
            /**
             * @brief Check if the alpha channel is enabled for this texture.
             * @return true if enabled.
             */
            virtual Bool IsAlphaEnabled() const = 0;
            
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
             * @brief Enable/disable prescaling for this texture.
             * In the IEngineConfiguration, an application may define a power-of-2 texture prescale
             * factor that can be used to e.g. scale down texture resources depending on a device's
             * actual screen resolution. However, in certain cases it may not be desired to prescale
             * all textures (e.g. when using shadow maps); for such textures, prescaling can be
             * disabled using this method.
             * @param enabled If true, prescaling is enabled.
             * @return true if successful.
             */
            virtual Bool SetPrescalingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if prescaling is enabled for this texture.
             * @return true if enabled.
             */
            virtual Bool IsPrescalingEnabled() const = 0;

            /**
             * @brief Set the texture's actual pixel format.
             * @param pixelFormat The pixel format to use.
             * @return true if successful.
             */
            virtual Bool SetPixelFormat(IEnums::PixelFormat pixelFormat) = 0;
            /**
             * @brief Get the texture's actual pixel format.
             * @return The texture's pixel format.
             */
            virtual IEnums::PixelFormat GetPixelFormat() const = 0;
            
            /**
             * @brief Set the texture's wrap mode in X direction.
             * @param mode The wrap mode.
             * @return true if successful.
             */
            virtual Bool SetWrapModeX(IEnums::TextureWrapMode mode) = 0;
            /**
             * @brief Get the texture's wrap mode in X direction.
             * @return The wrap mode.
             */
            virtual IEnums::TextureWrapMode GetWrapModeX() const = 0;
            
            /**
             * @brief Set the texture's wrap mode in Y direction.
             * @param mode The wrap mode.
             * @return true if successful.
             */
            virtual Bool SetWrapModeY(IEnums::TextureWrapMode mode) = 0;
            /**
             * @brief Get the texture's wrap mode in Y direction.
             * @return The wrap mode.
             */
            virtual IEnums::TextureWrapMode GetWrapModeY() const = 0;

            /**
             * @brief Set the texture's wrap mode in Z direction.
             * @param mode The wrap mode.
             * @return true if successful.
             */
            virtual Bool SetWrapModeZ(IEnums::TextureWrapMode mode) = 0;
            /**
             * @brief Get the texture's wrap mode in Z direction.
             * @return The wrap mode.
             */
            virtual IEnums::TextureWrapMode GetWrapModeZ() const = 0;

            /**
             * @brief Set the texture filter used for magnification.
             * Valid magFilter values are restricted to TEXTURE_FILTER_NEAREST and TEXTURE_FILTER_LINEAR.
             * @param magFilter The filter to use.
             * @return true if successful.
             */
            virtual Bool SetMagFilter(IEnums::TextureFilter magFilter) = 0;
            /**
             * @brief Get the texture filter used for magnification.
             * @return The filter used.
             */
            virtual IEnums::TextureFilter GetMagFilter() const = 0;
            
            /**
             * @brief Set the texture filter used for minification.
             * Valid minFilter values are restricted to TEXTURE_FILTER_NEAREST and TEXTURE_FILTER_LINEAR.
             * @param minFilter The filter to use.
             * @return true if successful.
             */
            virtual Bool SetMinFilter(IEnums::TextureFilter minFilter) = 0;
            /**
             * @brief Get the texture filter used for minification.
             * @return The filter used.
             */
            virtual IEnums::TextureFilter GetMinFilter() const = 0;
            
            /**
             * @brief Set the texture filter used for mip-level selection.
             * @param mipFilter The filter to use.
             * @return true if successful.
             */
            virtual Bool SetMipFilter(IEnums::TextureFilter mipFilter) = 0;
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
             * By default, a maximum anisotropy value of 0.0 is defined. In this case, the global
             * value defined via Murl::IEngineConfiguration::SetDefaultMaxTextureAnisotropy()
             * is used. If set to a value other than 0.0, the given value is used. The actual
             * value is clamped to the range from 1.0 to the highest possible value defined in the 
             * graphics driver/hardware (typically around 16.0, but may be lower), with 1.0 
             * representing isotropic filtering (fastest), and higher values producing better visual 
             * results at the cost of rendering performance.
             * Note that if the maximum anisotropy is higher than 1.0, it may be the case that
             * the actual filter(s) chosen by the graphics API are different than the ones 
             * specified via SetMagFilter(), SetMinFilter() and/or SetMipFilter().
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
             * @brief Get the texture's number of detail levels.
             * @return The number of detail levels.
             */
            virtual UInt32 GetNumberOfDetailLevels() const = 0;
            /**
             * @brief Get the texture's number of stages for a given detail level.
             * @param detailLevel The detail level to query.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages(UInt32 detailLevel) const = 0;
            /**
             * @brief Get the texture's internal video renderer object for a given pass.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return A pointer to the mutable video renderer object.
             */
            virtual Video::ITexture* GetVideoTextureObject(UInt32 detailLevel, UInt32 stage) const = 0;
            
        protected:
            virtual ~ITexture() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TEXTURE_H__

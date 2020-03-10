// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_STATE_H__
#define __MURL_VIDEO_STATE_H__

#include "murl_video_types.h"
#include "murl_math_matrix.h"
#include "murl_math_vector.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IVideoInterface;
    
    namespace Video
    {
        class IBone;
        class ICamera;
        class IMaterial;
        class IConstants;
        class IProgram;
        class ITexture;
        class ILight;
        class IVertices;
        
        /**
         * @ingroup MurlVideoRendererClasses
         * @brief The internal renderer state object.
         * Only necessary when implementing custom video objects.
         */
        class State
        {
        public:
            enum
            {
                MAX_ATTRIBUTES = 16,
                MAX_CONSTANT_BUFFERS = 14,
            };
            
            struct AttributeLocation
            {
                AttributeLocation()
                : mCurrentIndex(-1)
                {
                }
                
                SInt32 mCurrentIndex;
            };
            
            struct ConstantBufferLocation
            {
                ConstantBufferLocation()
                : mCurrentIndex(-1)
                {
                }
                
                SInt32 mCurrentIndex;
            };
            
            struct AttributeIndex
            {
                UInt32 mCurrentNumberOfComponents;
                UInt32 mCurrentNormalization;
                const void* mCurrentBuffer;
                const void* mCurrentData;
                UInt32 mCurrentByteStride;
                Bool mIsEnabled;
            };
            
            struct ConstantBufferIndex
            {
                UInt32 mCurrentNumberOfComponents;
                const void* mCurrentBuffer;
                const void* mCurrentData;
                UInt32 mCurrentByteSize;
                Bool mIsEnabled;
            };
            
            /**
             * @brief Set up the state for rendering.
             */
            virtual void Setup();
            /**
             * @brief Finish the state after rendering.
             */
            virtual void Finish();
            
            /**
             * @brief Get the platform front end's video interface.
             * @return The video interface.
             */
            virtual IVideoInterface* GetVideoInterface() const;
            
        public:
            Vector mCurrentViewportPosition;
            Vector mCurrentViewportSize;
            Vector mCurrentViewportSizeInverted;

            Float mCurrentTimeSeconds;
            Float mCurrentTimeFraction;

            const Matrix* mCurrentModelMatrix;
            const Matrix* mCurrentViewOffsetMatrix;
            
            ICamera* mCurrentCamera;
            IVertices* mCurrentVertices;
            IMaterial* mCurrentMaterial;
            IConstants* mCurrentConstants;
            IProgram* mCurrentProgram;
            ITexture* mCurrentTextures[IEnums::NUM_TEXTURE_UNITS];
            ILight* mCurrentLights[IEnums::NUM_LIGHT_UNITS];
            IBone* mCurrentBones[IEnums::NUM_BONE_UNITS];
            
            ICamera* mRecentCamera;
            IVertices* mRecentVertices;
            IMaterial* mRecentMaterial;
            IConstants* mRecentConstants;
            IProgram* mRecentProgram;
            ITexture* mRecentTextures[IEnums::NUM_TEXTURE_UNITS];
            ILight* mRecentLights[IEnums::NUM_LIGHT_UNITS];
            IBone* mRecentBones[IEnums::NUM_BONE_UNITS];
            
            UInt32 mCurrentFrameCount;
            
            UInt32 mCurrentNumberOfActiveTextureUnits;
            UInt32 mCurrentNumberOfActiveLightUnits;
            UInt32 mCurrentNumberOfActiveBoneUnits;
            
            UInt32 mCurrentActiveTextureUnit;
            UInt32 mCurrentBound2DTextureId[IEnums::NUM_TEXTURE_UNITS];
            UInt32 mCurrentBoundCubeTextureId[IEnums::NUM_TEXTURE_UNITS];
            UInt32 mCurrentBound2DArrayTextureId[IEnums::NUM_TEXTURE_UNITS];
            UInt32 mCurrentBoundCubeArrayTextureId[IEnums::NUM_TEXTURE_UNITS];

            UInt32 mCurrentBoundIndexBufferId;
            UInt32 mCurrentBoundVertexBufferId;
            
            UInt32 mCurrentBoundVertexArrayObjectId;
            
            UInt32 mCurrentVerticesSignature;
            IEnums::AttributeItem mCurrentAttributeItems[IEnums::NUM_ATTRIBUTE_ITEMS];
            Array<SInt32> mCurrentAttributeIds;
            UInt32 mCurrentNumberOfAttributes;
            Array<AttributeLocation> mCurrentAttributeLocations;
            AttributeIndex mCurrentAttributeIndices[MAX_ATTRIBUTES];

            IEnums::PolygonFaces mCurrentVisibleFaces;
            
            IEnums::ColorBufferMode mCurrentColorBufferMode;
            IEnums::ColorBufferMask mCurrentColorBufferMask;
            
            IEnums::DepthBufferMode mCurrentDepthBufferMode;
            IEnums::DepthBufferMask mCurrentDepthBufferMask;
            IEnums::DepthTestFunction mCurrentDepthTestFunction;
            
            IEnums::StencilBufferMode mCurrentStencilBufferMode;
            IEnums::StencilBufferMask mCurrentStencilBufferMask;
            IEnums::StencilTestFunction mCurrentFrontStencilTestFunction;
            IEnums::StencilTestFunction mCurrentBackStencilTestFunction;
            UInt32 mCurrentFrontStencilTestReferenceValue;
            UInt32 mCurrentBackStencilTestReferenceValue;
            UInt32 mCurrentFrontStencilTestMask;
            UInt32 mCurrentBackStencilTestMask;
            IEnums::StencilBufferAction mCurrentFrontStencilBufferActionForFailedStencilTest;
            IEnums::StencilBufferAction mCurrentBackStencilBufferActionForFailedStencilTest;
            IEnums::StencilBufferAction mCurrentFrontStencilBufferActionForFailedDepthTest;
            IEnums::StencilBufferAction mCurrentBackStencilBufferActionForFailedDepthTest;
            IEnums::StencilBufferAction mCurrentFrontStencilBufferActionForPassedDepthTest;
            IEnums::StencilBufferAction mCurrentBackStencilBufferActionForPassedDepthTest;
            
            IEnums::BlendMode mCurrentBlendMode;
            IEnums::BlendFunction mCurrentSrcColorBlendFunction;
            IEnums::BlendFunction mCurrentSrcAlphaBlendFunction;
            IEnums::BlendFunction mCurrentDstColorBlendFunction;
            IEnums::BlendFunction mCurrentDstAlphaBlendFunction;
            IEnums::BlendEquation mCurrentColorBlendEquation;
            IEnums::BlendEquation mCurrentAlphaBlendEquation;
            
            SInt32 mCurrentViewMaskX1;
            SInt32 mCurrentViewMaskY1;
            SInt32 mCurrentViewMaskX2;
            SInt32 mCurrentViewMaskY2;
            
            SInt32 mCurrentCameraMaskX1;
            SInt32 mCurrentCameraMaskY1;
            SInt32 mCurrentCameraMaskX2;
            SInt32 mCurrentCameraMaskY2;
            
            SInt32 mCurrentLightMaskX1;
            SInt32 mCurrentLightMaskY1;
            SInt32 mCurrentLightMaskX2;
            SInt32 mCurrentLightMaskY2;
            
            Bool mIsCurrentLightMaskDefined;
            Bool mIsCurrentLightMaskSet;
            
            Bool mIsMaskEmpty;

            Real mCurrentVariableDepthOffset;
            Real mCurrentConstantDepthOffset;

        protected:
            State(IVideoInterface* videoInterface);
            virtual ~State();
            
            IVideoInterface* mVideoInterface;
            
            friend class Renderer;
        };
    }
}

#endif // __MURL_VIDEO_STATE_H__

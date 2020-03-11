// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_MATERIAL_H__
#define __MURL_GRAPH_I_MATERIAL_H__

#include "murl_graph_i_program.h"
#include "murl_graph_i_state_slot.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IMaterial;
    }

    namespace Graph
    {
        class IMaterial;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IMaterial nodes.
         */
        typedef IGenericNodeTarget<IMaterial> IMaterialNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IMaterial
         * @brief The IMaterial graph node interface.
         * Material nodes hold common rendering parameters that cannot be controlled
         * via GPU shader programs or fixed function programs, such as e.g. depth and stencil
         * buffer access modes and actions, or different blend modes and blend equations.
         *
         * A material must always refer to exactly one Graph::IProgram, which is used to
         * calculate actual per-pixel color values.
         *
         * Use the Graph::IStateSlot base interface to set or get the material slot index this
         * material is temporarily attached to if any children are present.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during 
         * scene graph traversal.\n
         * See Graph::IMaterialState for activating a material for rendering.
         * See Graph::IProgram for defining GPU programs to refer to.
         * See Graph::IParameters for defining actual program parameters.
         */
        class IMaterial : public IStateSlot
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
             * @brief Get the mutable container holding the optional child materials.
             * This method returns a mutable pointer to the node's Graph::IMaterialNodeTarget
             * sub container, which is used to store multiple sub-materials.
             * @return The mutable Graph::IMaterialNodeTarget container, or null if not available.
             */
            virtual IMaterialNodeTarget* GetSubMaterialNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the optional child materials.
             * This method returns a constant pointer to the node's Graph::IMaterialNodeTarget
             * sub container, which is used to store multiple sub-materials.
             * @return The constant Graph::IMaterialNodeTarget container, or null if not available.
             */
            virtual const IMaterialNodeTarget* GetSubMaterialNodeTarget() const = 0;
            
            /**
             * @brief Get the mutable Graph::IProgramNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IProgramNodeTarget
             * container, which allows to set or query the program object used with this material.
             * @return The mutable Graph::IProgramNodeTarget container, or null if not available.
             */
            virtual IProgramNodeTarget* GetProgramNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IProgramNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IProgramNodeTarget
             * container, which allows to query the program object used with this material.
             * @return The mutable Graph::IProgramNodeTarget container, or null if not available.
             */
            virtual const IProgramNodeTarget* GetProgramNodeTarget() const = 0;
            
            /**
             * @brief Set which faces of a triangle are visible for rendering.
             * @param faces One of the available IEnums::PolygonFaces enumeration values.
             * @return true if successful.
             */
            virtual Bool SetVisibleFaces(IEnums::PolygonFaces faces) = 0;
            /**
             * @brief Check which faces of a triangle are visible for rendering.
             * @return One of the available IEnums::PolygonFaces enumeration values.
             */
            virtual IEnums::PolygonFaces GetVisibleFaces() const = 0;
            
            /**
             * @brief Set the material's color buffer access mode.
             * The color buffer access mode can be set to either IEnums::COLOR_BUFFER_MODE_WRITE_ONLY
             * to enable writing to the color buffer, or IEnums::COLOR_BUFFER_MODE_NONE to disable
             * color output.
             * Use SetColorBufferMask() to enable/disable specific color channels when writing is
             * enabled.
             * @param mode The color buffer access mode.
             * @return true if successful.
             */
            virtual Bool SetColorBufferMode(IEnums::ColorBufferMode mode) = 0;
            /**
             * @brief Get the material's color buffer access mode.
             * @return The color buffer access mode.
             */
            virtual IEnums::ColorBufferMode GetColorBufferMode() const = 0;
            
            /**
             * @brief Set the material's color buffer mask.
             * If color buffer writes are enabled, and a specific bit is set in the given mask, the
             * respective color channel is enabled for writing, otherwise that channel is not written
             * to the output pixels. To generally enable/disable color buffer writes, use
             * SetColorBufferMode().
             * @param mask The color buffer write mask.
             * @return true if successful.
             */
            virtual Bool SetColorBufferMask(IEnums::ColorBufferMask mask) = 0;
            /**
             * @brief Get the material's color buffer mask.
             * @return The color buffer write mask.
             */
            virtual IEnums::ColorBufferMask GetColorBufferMask() const = 0;
            
            /**
             * @brief Set the material's depth buffer access mode.
             * The depth buffer access mode can be set to enable/disable both depth buffer reads
             * and writes, through one of the available IEnums::DepthBufferMode values.
             * @param mode The depth buffer access mode.
             * @return true if successful.
             */
            virtual Bool SetDepthBufferMode(IEnums::DepthBufferMode mode) = 0;
            /**
             * @brief Get the material's depth buffer access mode.
             * @return The depth buffer access mode.
             */
            virtual IEnums::DepthBufferMode GetDepthBufferMode() const = 0;
            
            /**
             * @brief Set the material's depth buffer mask.
             * This method can be used to independently enable/disable depth buffer writes in addition
             * to the general depth buffer access mode set via SetDepthBufferMode().
             * @param mask The depth buffer write mask.
             * @return true if successful.
             */
            virtual Bool SetDepthBufferMask(IEnums::DepthBufferMask mask) = 0;
            /**
             * @brief Get the material's depth buffer mask.
             * @return The depth buffer write mask.
             */
            virtual IEnums::DepthBufferMask GetDepthBufferMask() const = 0;
            
            /**
             * @brief Set the material's depth test function.
             * If the material's depth buffer access mode is set to either IEnums::DEPTH_BUFFER_MODE_READ_ONLY
             * or IEnums::DEPTH_BUFFER_MODE_READ_AND_WRITE, the given function is used for all depth
             * buffer comparisons using this material. The output pixel is only written if the result
             * of its depth comparison is true using the given function.
             * @param function The depth test function.
             * @return true if successful.
             */
            virtual Bool SetDepthTestFunction(IEnums::DepthTestFunction function) = 0;
            /**
             * @brief Get the material's depth test function.
             * @return The depth test function.
             */
            virtual IEnums::DepthTestFunction GetDepthTestFunction() const = 0;
            
            /**
             * @brief Set the material's stencil buffer access mode.
             * The stencil buffer access mode can be set to enable/disable both stencil buffer reads
             * and writes, through one of the available IEnums::StencilBufferMode values.
             * @param mode The stencil buffer access mode.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferMode(IEnums::StencilBufferMode mode) = 0;
            /**
             * @brief Get the material's stencil buffer access mode.
             * @return The stencil buffer access mode.
             */
            virtual IEnums::StencilBufferMode GetStencilBufferMode() const = 0;
            
            /**
             * @brief Set the material's stencil buffer mask.
             * If stencil buffer writes are enabled, and a specific bit is set in the given mask, the
             * respective stencil bit is enabled for writing, otherwise that bit is not written
             * to the output pixels. To generally enable/disable stencil buffer writes, use
             * SetStencilBufferMode().
             * @param mask The stencil buffer write mask.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferMask(IEnums::StencilBufferMask mask) = 0;
            /**
             * @brief Get the material's stencil buffer mask.
             * @return The stencil buffer write mask.
             */
            virtual IEnums::StencilBufferMask GetStencilBufferMask() const = 0;
            
            /**
             * @brief Set the material's stencil test functions.
             * If the material's stencil buffer access mode is set to either IEnums::STENCIL_BUFFER_MODE_READ_ONLY
             * or IEnums::STENCIL_BUFFER_MODE_READ_AND_WRITE, the given functions are used for all stencil
             * buffer comparisons using this material. The output pixel is only written if the result
             * of its stencil comparison is true using the given function.
             * @param frontFunction The stencil test function used for front-facing primitives.
             * @param backFunction The stencil test function used for back-facing primitives.
             * @return true if successful.
             */
            virtual Bool SetStencilTestFunction(IEnums::StencilTestFunction frontFunction,
                                                IEnums::StencilTestFunction backFunction) = 0;
            /**
             * @brief Set the material's stencil test function for front-facing primitives.
             * @return The stencil test function.
             */
            virtual IEnums::StencilTestFunction GetFrontStencilTestFunction() const = 0;
            /**
             * @brief Set the material's stencil test function for back-facing primitives.
             * @return The stencil test function.
             */
            virtual IEnums::StencilTestFunction GetBackStencilTestFunction() const = 0;
            
            /**
             * @brief Set the material's stencil test reference values.
             * If stencil test is enabled (see SetStencilBufferMode()), the values given represent the
             * actual reference values used for the per-pixel stencil test with the respective functions
             * specified via SetStencilTestFunction(). In addition, before each comparison, both test
             * value and reference value are ANDed with the test mask given via SetStencilTestMask().
             * @param frontValue The reference value used for comparing pixels of front-facing primitives.
             * @param backValue The reference value used for comparing pixels of back-facing primitives.
             * @return true if successful.
             */
            virtual Bool SetStencilTestReferenceValue(UInt32 frontValue, UInt32 backValue) = 0;
            /**
             * @brief Get the material's stencil test reference value for testing front-facing primitives.
             * @return The stencil test reference value.
             */
            virtual UInt32 GetFrontStencilTestReferenceValue() const = 0;
            /**
             * @brief Get the material's stencil test reference value for testing back-facing primitives.
             * @return The stencil test reference value.
             */
            virtual UInt32 GetBackStencilTestReferenceValue() const = 0;
            
            /**
             * @brief Set the material's stencil test masks.
             * See SetStencilTestReferenceValue().
             * @param frontMask The comparison mask for front-facing primitives.
             * @param backMask The comparison mask for back-facing primitives.
             * @return true if successful.
             */
            virtual Bool SetStencilTestMask(UInt32 frontMask, UInt32 backMask) = 0;
            /**
             * @brief Get the material's stencil test mask for front-facing primitives.
             * @return The stencil test mask.
             */
            virtual UInt32 GetFrontStencilTestMask() const = 0;
            /**
             * @brief Get the material's stencil test mask for back-facing primitives.
             * @return The stencil test mask.
             */
            virtual UInt32 GetBackStencilTestMask() const = 0;
            
            /**
             * @brief Set the actions to be performed if the stencil test fails.
             * If stencil test is enabled (see SetStencilBufferMode()), the given actions specify how the
             * stencil buffer is modified whenever the stencil test fails for a pixel.
             * @param frontAction The action to perform for front-facing primitives.
             * @param backAction The action to perform for back-facing primitives.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferActionForFailedStencilTest(IEnums::StencilBufferAction frontAction,
                                                                    IEnums::StencilBufferAction backAction) = 0;
            /**
             * @brief Get the front-facing primitive stencil buffer action for failed stencil tests.
             * @return The stencil buffer action.
             */
            virtual IEnums::StencilBufferAction GetFrontStencilBufferActionForFailedStencilTest() const = 0;
            /**
             * @brief Get the back-facing primitive stencil buffer action for failed stencil tests.
             * @return The stencil buffer action.
             */
            virtual IEnums::StencilBufferAction GetBackStencilBufferActionForFailedStencilTest() const = 0;
            
            /**
             * @brief Set the actions to be performed if the stencil test passes, but the depth test fails.
             * If stencil test is enabled (see SetStencilBufferMode()), the given actions specify how the
             * stencil buffer is modified whenever the depth test fails for a pixel (after successfully
             * passing the stencil test).
             * @param frontAction The action to perform for front-facing primitives.
             * @param backAction The action to perform for back-facing primitives.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferActionForFailedDepthTest(IEnums::StencilBufferAction frontAction,
                                                                  IEnums::StencilBufferAction backAction) = 0;
            /**
             * @brief Get the front-facing primitive stencil buffer action for failed depth tests.
             * @return The stencil buffer action.
             */
            virtual IEnums::StencilBufferAction GetFrontStencilBufferActionForFailedDepthTest() const = 0;
            /**
             * @brief Get the back-facing primitive stencil buffer action for failed depth tests.
             * @return The stencil buffer action.
             */
            virtual IEnums::StencilBufferAction GetBackStencilBufferActionForFailedDepthTest() const = 0;
            
            /**
             * @brief Set the actions to be performed if both the stencil test and the depth test pass.
             * If stencil test is enabled (see SetStencilBufferMode()), the given actions specify how the
             * stencil buffer is modified whenever both stencil and depth test succeed for a pixel.
             * @param frontAction The action to perform for front-facing primitives.
             * @param backAction The action to perform for back-facing primitives.
             * @return true if successful.
             */
            virtual Bool SetStencilBufferActionForPassedDepthTest(IEnums::StencilBufferAction frontAction,
                                                                  IEnums::StencilBufferAction backAction) = 0;
            /**
             * @brief Get the front-facing primitive stencil buffer action for passed depth tests.
             * @return The stencil buffer action.
             */
            virtual IEnums::StencilBufferAction GetFrontStencilBufferActionForPassedDepthTest() const = 0;
            /**
             * @brief Get the back-facing primitive stencil buffer action for passed depth tests.
             * @return The stencil buffer action.
             */
            virtual IEnums::StencilBufferAction GetBackStencilBufferActionForPassedDepthTest() const = 0;
            
            /**
             * @brief Set the material's blend mode.
             * @param mode The blend mode.
             * @return true if successful.
             */
            virtual Bool SetBlendMode(IEnums::BlendMode mode) = 0;
            /**
             * @brief Get the material's blend mode.
             * @return The blend mode.
             */
            virtual IEnums::BlendMode GetBlendMode() const = 0;
            
            /**
             * @brief Set the material's blending functions.
             * If alpha blending is enabled (SetBlendMode() with a parameter of IEnums::BLEND_MODE_ALPHA),
             * this method sets the combiner factors used for calculating the actual output pixel RGBA
             * values depending on the source and destination pixel's color and alpha values. The values
             * resulting from evaluating these functions are then combined using the blending equations
             * set via SetBlendEquation().
             * @param srcColorFunction The combiner function for the source pixel's RGB values.
             * @param srcAlphaFunction The combiner function for the source pixel's alpha value.
             * @param dstColorFunction The combiner function for the destination pixel's RGB values.
             * @param dstAlphaFunction The combiner function for the destination pixel's alpha value.
             * @return true if successful.
             */
            virtual Bool SetBlendFunction(IEnums::BlendFunction srcColorFunction, IEnums::BlendFunction srcAlphaFunction,
                                          IEnums::BlendFunction dstColorFunction, IEnums::BlendFunction dstAlphaFunction) = 0;
            /**
             * @brief Get the material's blending function used for the source pixels' RGB values.
             * @return The blending function.
             */
            virtual IEnums::BlendFunction GetSrcColorBlendFunction() const = 0;
            /**
             * @brief Get the material's blending function used for the source pixels' alpha value.
             * @return The blending function.
             */
            virtual IEnums::BlendFunction GetSrcAlphaBlendFunction() const = 0;
            /**
             * @brief Get the material's blending function used for the destination pixels' RGB values.
             * @return The blending function.
             */
            virtual IEnums::BlendFunction GetDstColorBlendFunction() const = 0;
            /**
             * @brief Get the material's blending function used for the destination pixels' alpha value.
             * @return The blending function.
             */
            virtual IEnums::BlendFunction GetDstAlphaBlendFunction() const = 0;
            
            /**
             * @brief Set the material's blending equations.
             * If alpha blending is enabled (SetBlendMode() with a parameter of IEnums::BLEND_MODE_ALPHA),
             * this method sets the actual equations used to combine the outcome of transforming the
             * source and destination pixels according to the functions specified via SetBlendFunction().
             * @param colorEquation The blending equation used to combine source and destination RGB values.
             * @param alphaEquation The blending equation used to combine source and destination alpha values.
             * @return true if successful.
             */
            virtual Bool SetBlendEquation(IEnums::BlendEquation colorEquation, IEnums::BlendEquation alphaEquation) = 0;
            /**
             * @brief Get the material's blending equation for RGB values.
             * @return The blending equation.
             */
            virtual IEnums::BlendEquation GetColorBlendEquation() const = 0;
            /**
             * @brief Get the material's blending equation for alpha values.
             * @return The blending equation.
             */
            virtual IEnums::BlendEquation GetAlphaBlendEquation() const = 0;
            
            /**
             * @brief Enable/disable clearing of the render target's color buffer.
             * If color buffer clearing is enabled for a material, the output color buffer gets
             * cleared every time the material is activated (off by default).
             * See SetColorBufferClearValue() for setting the color used for clearing.
             * See also SetDepthBufferClearingEnabled() and SetStencilBufferClearingEnabled().
             * @param enabled Set to true to enable color buffer clearing.
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
             * If depth buffer clearing is enabled for a material, the output depth buffer gets
             * cleared every time the material is activated (off by default).
             * See SetDepthBufferClearValue() for setting the depth value used for clearing.
             * See also SetStencilBufferClearingEnabled().
             * @param enabled Set to true to enable depth buffer clearing.
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
             * If stencil buffer clearing is enabled for a material, the output stencil buffer gets
             * cleared every time the material is activated (off by default).
             * See SetStencilBufferClearValue() for setting the stencil value used for clearing.
             * See SetDepthBufferClearingEnabled() and SetColorBufferClearingEnabled().
             * @param enabled Set to true to enable stencil buffer clearing.
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
             * @brief Set the material's object sorting mode.
             * If not specified, the object sort mode is set to IEnums::OBJECT_SORT_MODE_BY_MATERIAL
             * when the material writes to the depth buffer, and to IEnums::OBJECT_SORT_MODE_BY_DEPTH
             * if depth writes are disabled. During rendering a layer, first all drawables are
             * processed that do update the depth buffer (usually opaque geometry) without and
             * depth sorting, and afterwards all other drawables are rendered back-to-front.
             * The actual depth measure (either Z-distance or squared distance) for the latter case
             * is defined per-camera via Graph::ICamera::SetDepthSortMode().
             * @param mode The object sorting mode.
             * @return true if successful.
             */
            virtual Bool SetObjectSortMode(IEnums::ObjectSortMode mode) = 0;
            /**
             * @brief Get the material's object sorting mode.
             * @return The object sorting mode.
             */
            virtual IEnums::ObjectSortMode GetObjectSortMode() const = 0;
            
            /**
             * @brief Set the material's sorting order relative to other materials.
             * This is useful when doing multi-pass rendering using e.g. a Graph::MultiMaterial.
             * Materials with higher values are rendered later.
             * @param order The sorting order.
             * @return true if successful.
             */
            virtual Bool SetSortOrder(SInt32 order) = 0;
            /**
             * @brief Get the material's sorting order relative to other materials.
             * @return The sorting order.
             */
            virtual SInt32 GetSortOrder() const = 0;

            /**
             * @brief Set the variable offset for depth buffer value calculation.
             * This value specifies a variable offset for the generated depth values, before
             * they are written to the depth buffer. See the description of the "factor" parameter
             * at http://www.khronos.org/opengles/sdk/docs/man/xhtml/glPolygonOffset.xml for
             * OpenGL|ES, or the "D3DRS_SLOPESCALEDEPTHBIAS" parameter at
             * http://msdn.microsoft.com/en-us/library/windows/desktop/bb205599(v=vs.85).aspx
             * for DirectX 9.
             * The default offset value is 0.
             * @param offset The variable depth offset.
             * @return true if successful.
             */
            virtual Bool SetVariableDepthOffset(Real offset) = 0;
            /**
             * @brief Get the variable offset for depth buffer value calculation.
             * @return The variable depth offset.
             */
            virtual Real GetVariableDepthOffset() const = 0;

            /**
             * @brief Set the constant offset for depth buffer value calculation.
             * This value specifies a constant offset for the generated depth values, before
             * they are written to the depth buffer. See the description of the "units" parameter
             * at http://www.khronos.org/opengles/sdk/docs/man/xhtml/glPolygonOffset.xml for
             * OpenGL|ES, or the "D3DRS_DEPTHBIAS" parameter at
             * http://msdn.microsoft.com/en-us/library/windows/desktop/bb205599(v=vs.85).aspx
             * for DirectX 9.
             * The default offset value is 0.
             * @param offset The constant depth offset.
             * @return true if successful.
             */
            virtual Bool SetConstantDepthOffset(Real offset) = 0;
            /**
             * @brief Get the constant offset for depth buffer value calculation.
             * @return The constant depth offset.
             */
            virtual Real GetConstantDepthOffset() const = 0;

            /**
             * @brief Set the material's camera slot.
             * @param cameraSlot The camera slot.
             * @return true if successful.
             */
            virtual Bool SetCameraSlot(SInt32 cameraSlot) = 0;
            /**
             * @brief Set the material's layer offset.
             * @param layerOffset The layer offset.
             * @return true if successful.
             */
            virtual Bool SetLayerOffset(SInt32 layerOffset) = 0;
            /**
             * @brief Set the material's parameters pass.
             * @param parametersStage The parameters pass.
             * @return true if successful.
             */
            virtual Bool SetParametersStage(SInt32 parametersStage) = 0;
            /**
             * @brief Set the material's texture pass for a given unit.
             * @param unit The texture unit
             * @param textureStage The texture pass.
             * @return true if successful.
             */
            virtual Bool SetTextureStage(UInt32 unit, SInt32 textureStage) = 0;
            /**
             * @brief Set the light stage unit used for multi-pass lighting.
             * @param unit The light stage unit, or -1 to disable multi-pass lighting.
             * @return true if successful.
             */
            virtual Bool SetLightStageUnit(SInt32 unit) = 0;
            /**
             * @brief Set if the light should be masked for multi-pass lighting.
             * When multi-pass lighting is performed, this property defines whether
             * rendering should only happen within the light's bounding volume projected
             * on screen. This value only has effect when the light pass unit is set
             * to a defined value (other than -1), otherwise the light is never masked.
             * Setting this value to true can considerably speed up multi-light rendering,
             * as only necessary screen areas are updated.
             * @param enabled Set to true if the light should be masked.
             * @return true if successful.
             */
            virtual Bool SetLightMaskEnabled(Bool enabled) = 0;
            /**
             * @brief Set the material's minimum number of light stages.
             * @param minNumStages The minimum number of light stages.
             * @return true if successful.
             */
            virtual Bool SetMinNumberOfLightStages(UInt32 minNumStages) = 0;
            /**
             * @brief Set the material's maximum number of light stages.
             * @param maxNumStages The maximum number of light stages.
             * @return true if successful.
             */
            virtual Bool SetMaxNumberOfLightStages(UInt32 maxNumStages) = 0;
            
            /**
             * @brief Get the material's number of detail levels.
             * @return The number of detail levels.
             */
            virtual UInt32 GetNumberOfDetailLevels() const = 0;
            /**
             * @brief Get the material's number of stages for a given detail level.
             * @param detailLevel The detail level to query.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages(UInt32 detailLevel) const = 0;
            /**
             * @brief Get the material's camera slot for a given stage.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return The camera slot.
             */
            virtual SInt32 GetCameraSlot(UInt32 detailLevel, UInt32 stage) const = 0;
            /**
             * @brief Get the material's layer offset for a given stage.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return The layer offset.
             */
            virtual SInt32 GetLayerOffset(UInt32 detailLevel, UInt32 stage) const = 0;
            /**
             * @brief Get the material's parameter stage for a given material stage.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return The parameter stage.
             */
            virtual SInt32 GetParametersStage(UInt32 detailLevel, UInt32 stage) const = 0;
            /**
             * @brief Get the material's texture stage for a given material stage and texture unit.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @param unit The texture unit
             * @return The parameter stage.
             */
            virtual SInt32 GetTextureStage(UInt32 detailLevel, UInt32 stage, UInt32 unit) const = 0;
            /**
             * @brief Get the light stage unit used for multi-stage lighting for a given material stage.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return The light stage unit, or -1 if multi-pass lighting is disabled.
             */
            virtual SInt32 GetLightStageUnit(UInt32 detailLevel, UInt32 stage) const = 0;
            /**
             * @brief Check if the light is masked for multi-pass lighting.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return true if the light is masked.
             */
            virtual Bool IsLightMaskEnabled(UInt32 detailLevel, UInt32 stage) const = 0;
            /**
             * @brief Get the material's minimum number of light stages for a given material stage.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return The minimum number of light stages.
             */
            virtual UInt32 GetMinNumberOfLightStages(UInt32 detailLevel, UInt32 stage) const = 0;
            /**
             * @brief Get the material's maximum number of light stages for a given material stage.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return The maximum number of light stages.
             */
            virtual UInt32 GetMaxNumberOfLightStages(UInt32 detailLevel, UInt32 stage) const = 0;
            /**
             * @brief Get the material's minimum number of light stages for a given material stage.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @param numLights The actual number of currently active lights.
             * @return The layer offset.
             */
            virtual UInt32 GetNumberOfLightStages(UInt32 detailLevel, UInt32 stage, UInt32 numLights) const = 0;
            /**
             * @brief Get the material's internal video renderer object for a given index.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return A pointer to the mutable video renderer object.
             */
            virtual Video::IMaterial* GetVideoMaterialObject(UInt32 detailLevel, UInt32 stage) const = 0;
            
        protected:
            virtual ~IMaterial() {}
        };
    }
}

#endif // __MURL_GRAPH_I_MATERIAL_H__

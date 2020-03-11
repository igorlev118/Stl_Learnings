// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_DRAWABLE_H__
#define __MURL_GRAPH_I_DRAWABLE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IDrawable
         * @brief The IDrawable property interface.
         * This interface provides setting and retrieving common properties of a drawable
         * geometry object, such as associated material, parameters and texture slots,
         * the maximum number of light stages applied, and enabling/disabling view culling.
         */
        class IDrawable
        {
        public:
            /**
             * @brief Set the vertices slot used for rendering.
             * @param slot The vertices slot.
             * @return true if successful.
             */
            virtual Bool SetVerticesSlot(SInt32 slot) = 0;
            /**
             * @brief Get the vertices slot used for rendering.
             * @return The vertices slot.
             */
            virtual SInt32 GetVerticesSlot() const = 0;
            
            /**
             * @brief Set the material slot used for rendering.
             * @param slot The material slot.
             * @return true if successful.
             */
            virtual Bool SetMaterialSlot(SInt32 slot) = 0;
            /**
             * @brief Get the material slot used for rendering.
             * @return The material slot.
             */
            virtual SInt32 GetMaterialSlot() const = 0;
            
            /**
             * @brief Set the parameters slot used for rendering.
             * @param slot The parameters slot.
             * @return true if successful.
             */
            virtual Bool SetParametersSlot(SInt32 slot) = 0;
            /**
             * @brief Get the parameters slot used for rendering.
             * @return The parameters slot.
             */
            virtual SInt32 GetParametersSlot() const = 0;
            
            /**
             * @brief Set a texture slot used for rendering.
             * @param unit The texture unit for which to set the slot.
             * @param slot The texture slot.
             * @return true if successful.
             */
            virtual Bool SetTextureSlot(UInt32 unit, SInt32 slot) = 0;
            /**
             * @brief Get a texture slot used for rendering.
             * @param unit The texture unit for which to query the slot.
             * @return The texture slot.
             */
            virtual SInt32 GetTextureSlot(UInt32 unit) const = 0;

            /**
             * @brief Set the buffer access mode.
             * @param mode The access mode.
             * @return true if successful.
             */
            virtual Bool SetBufferAccessMode(IEnums::BufferAccessMode mode) = 0;
            /**
             * @brief Get the buffer access mode.
             * @return The access mode.
             */
            virtual IEnums::BufferAccessMode GetBufferAccessMode() const = 0;

            /**
             * @brief Set the primitive type used for rendering.
             * @param type One of the IEnums::PrimitiveType members.
             * @return true if successful.
             */
            virtual Bool SetPrimitiveType(IEnums::PrimitiveType type) = 0;
            /**
             * @brief Get the primitive type used for rendering.
             * @return One of the IEnums::PrimitiveType members.
             */
            virtual IEnums::PrimitiveType GetPrimitiveType() const = 0;
            
            /**
             * @brief Set the maximum number of light stages used for rendering.
             * @param maxNumStages The maximum number of light stages.
             * @return true if successful.
             */
            virtual Bool SetMaxNumberOfLightStages(UInt32 maxNumStages) = 0;
            /**
             * @brief Get the maximum number of light stages used for rendering.
             * @return The maximum number of light stages.
             */
            virtual UInt32 GetMaxNumberOfLightStages() const = 0;

            /**
             * @brief Set the maximum number of bones per vertex for vertex skinning.
             * @param maxNumBones The maximum number of bones.
             * @return true if successful.
             */
            virtual Bool SetMaxNumberOfBonesPerVertex(UInt32 maxNumBones) = 0;
            /**
             * @brief Get the maximum number of bones per vertex for vertex skinning.
             * @return The maximum number of bones.
             */
            virtual UInt32 GetMaxNumberOfBonesPerVertex() const = 0;

            /**
             * @brief Enable/disable view culling.
             * @param enabled If true, culling is performed, otherwise the geometry is always
             *      rendered.
             * @return true if successful.
             */
            virtual Bool SetViewCullingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if view culling is enabled.
             * @return true if enabled.
             */
            virtual Bool IsViewCullingEnabled() const = 0;
            
            /**
             * @brief Allow/disallow dynamic batching.
             * @param allowed If true, the renderer tries to batch the drawable together with
             *      other drawables sharing the same material/texture/light state.
             * @return true if successful, or false if not supported by this drawable.
             */
            virtual Bool SetDynamicBatchingAllowed(Bool allowed) = 0;
            /**
             * @brief Check if dynamic batching is allowed.
             * @return true if allowed.
             */
            virtual Bool IsDynamicBatchingAllowed() const = 0;

            /**
             * @brief Enable/disable CPU vertex skinning.
             * Enabling CPU vertex skinning only has effect when the drawable contains
             * skeleton information, i.e. bone indices and weights.
             * @param enabled If true, vertex skinning is performed using the CPU, otherwise
             *      a GPU shader program must be active to perform this task.
             * @return true if successful.
             */
            virtual Bool SetCpuSkinningEnabled(Bool enabled) = 0;
            /**
             * @brief Check if CPU vertex skinning is enabled.
             * @return true if enabled.
             */
            virtual Bool IsCpuSkinningEnabled() const = 0;

        protected:
            virtual ~IDrawable() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IDrawable nodes.
         */
        typedef IGenericNodeTarget<IDrawable> IDrawableNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_DRAWABLE_H__

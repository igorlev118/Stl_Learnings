// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_FIXED_TECHNIQUE_H__
#define __MURL_VIDEO_I_FIXED_TECHNIQUE_H__

#include "murl_video_types.h"
#include "murl_color.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;

        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IFixedTechnique
         * @brief The IFixedTechnique video object interface.
         * This interface represents a simple fixed-function pipeline GPU program.
         *
         * Used internally by Graph::FixedProgram.
         */
        class IFixedTechnique
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
             * @brief Enable/disable texturing for a given texture unit.
             * @param unit The texture unit to enable/disable, from 0 to IEnums::NUM_TEXTURE_UNITS.
             * @param enabled If true, texturing is enabled for the given unit.
             * @return true if successful.
             */
            virtual Bool SetTextureEnabled(UInt32 unit, Bool enabled) = 0;
            /**
             * @brief Check if texturing for a given texture unit.
             * @param unit The texture unit to query, from 0 to IEnums::NUM_TEXTURE_UNITS.
             * @return true if texturing is enabled for the given unit.
             */
            virtual Bool IsTextureEnabled(UInt32 unit) const = 0;
            
            /**
             * @brief Enable/disable the use of color parameters.
             * @param enabled If true, coloring is enabled.
             * @return true if successful.
             */
            virtual Bool SetColoringEnabled(Bool enabled) = 0;
            /**
             * @brief Check if coloring is enabled.
             * @return true if coloring is enabled.
             */
            virtual Bool IsColoringEnabled() const = 0;
            
            /**
             * @brief Enable/disable the use of per-vertex colors.
             * @param enabled If true, vertex coloring is enabled.
             * @return true if successful.
             */
            virtual Bool SetVertexColoringEnabled(Bool enabled) = 0;
            /**
             * @brief Check if per-vertex colors are enabled.
             * @return true if vertex coloring is enabled.
             */
            virtual Bool IsVertexColoringEnabled() const = 0;

            /**
             * @brief Enable/disable lighting calculations.
             * @param enabled If true, lighting calculations are enabled.
             * @return true if successful.
             */
            virtual Bool SetLightingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if lighting calculations are enabled.
             * @return true if lighting calculations are enabled.
             */
            virtual Bool IsLightingEnabled() const = 0;
            
            /**
             * @brief Set the light model used when lighting is enabled.
             * @param lightModel The light model.
             * @return true if successful.
             */
            virtual Bool SetLightModel(IEnums::LightModel lightModel) = 0;
            /**
             * @brief Get the light model used when lighting is enabled.
             * @return The light model.
             */
            virtual IEnums::LightModel GetLightModel() const = 0;
            
        protected:
            virtual ~IFixedTechnique() {}
        };
    }
}

#endif // __MURL_VIDEO_I_FIXED_TECHNIQUE_H__

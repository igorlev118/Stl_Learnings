// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FIXED_PROGRAM_H__
#define __MURL_GRAPH_I_FIXED_PROGRAM_H__

#include "murl_graph_i_program.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IFixedProgram
         * @brief The IFixedProgram graph node interface.
         * Fixed programs represent an easy way to define simple material shaders
         * without having to actually write any GPU shader code. However, they are
         * quite restricted regarding any possible graphical effects; fixed programs
         * are mainly used for simple tasks like flat shading with not more than 2
         * active texture units, e.g. for rendering HUDs or any othe 2D-only
         * content.
         *
         * See Graph::IMaterial for attaching a fixed program to a given material.
         * See Graph::IFixedParameters for defining actual program parameters.
         */
        class IFixedProgram : public IProgram
        {
        public:
            /**
             * @brief Enable/disable the use of color parameters.
             * If coloring is enabled, the program will make use of the actual color
             * parameters stored in the currently active Graph::IParameters node.
             * If disabled, 100% white is used.
             * Note, that the global alpha (transparency) value of an object is
             * controlled via the alpha value of the diffuse lighting component. If
             * coloring is disabled, alpha fading of the object is also disabled.
             * See also SetLightingEnabled() and SetTexturingEnabled().
             * If per-vertex colors are enabled (see SetVertexColoringEnabled()),
             * they override the parameter's ambient and diffuse components.
             * @param enabled If true, color parameters are used.
             * @return true if successful.
             */
            virtual Bool SetColoringEnabled(Bool enabled) = 0;
            /**
             * @brief Check if color parameters are used.
             * @return true if color parameters are used.
             */
            virtual Bool IsColoringEnabled() const = 0;
            
            /**
             * @brief Enable/disable the use of per-vertex colors.
             * If vertex coloring is enabled, the program will make use of individual
             * per-vertex color values present in the currently active vertex buffer,
             * to be applied for the ambient and diffuse components. If color parameters
             * are also enabled (see SetColoringEnabled()), ambient and diffuse components
             * are taken from per-vertex information, and only specular and emissive
             * components are used from the currently set parameters.
             * @param enabled If true, vertex colors are used.
             * @return true if successful.
             */
            virtual Bool SetVertexColoringEnabled(Bool enabled) = 0;
            /**
             * @brief Check if per-vertex colors are used.
             * @return true if per-vertex colors are used.
             */
            virtual Bool IsVertexColoringEnabled() const = 0;
            
            /**
             * @brief Enable/disable simple (1 source) lighting.
             * If lighting is enabled, the program evaluates the lighting equation
             * for a single light source at unit 0, using the four possible lighting
             * components defined in IEnums::LightingComponent. If disabled, only
             * the IEnums::LIGHTING_COMPONENT_DIFFUSE is used.
             * Note: If coloring is disabled, all of these components are set to
             * 100% white (with 100% alpha for the diffuse component).
             * See also SetColoringEnabled() and SetTexturingEnabled().
             * @param enabled If true, lighting is enabled.
             * @return true if successful.
             */
            virtual Bool SetLightingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if lighting is enabled.
             * @return true if lighting is enabled.
             */
            virtual Bool IsLightingEnabled() const = 0;
            
            /**
             * @brief Enable/disable texturing for a given texture unit.
             * If texturing is enabled, the resulting color from the color & lighting
             * evaluation at each pixel is multiplied component-wise with the color
             * retrieved from the active texture at that pixel. If disabled, only the
             * plain color is used.
             * See also SetColoringEnabled() and SetLightingEnabled().
             * @param unit The texture unit to enable or disable.
             * @param enabled If true, texturing is enabled for the given unit.
             * @return true if successful.
             */
            virtual Bool SetTexturingEnabled(UInt32 unit, Bool enabled) = 0;
            /**
             * @brief Check if texturing is enabled for a given unit.
             * @param unit The texture unit to check.
             * @return true if texturing is enabled.
             */
            virtual Bool IsTexturingEnabled(UInt32 unit) const = 0;
            
            /**
             * @brief Set the light model used for rendering.
             * @param lightModel the light model to use.
             * @return true if successful.
             */
            virtual Bool SetLightModel(IEnums::LightModel lightModel) = 0;
            /**
             * @brief Get the light model used for rendering.
             * @return The light model used.
             */
            virtual IEnums::LightModel GetLightModel() const = 0;
                        
        protected:
            virtual ~IFixedProgram() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IFixedProgram nodes.
         */
        typedef IGenericNodeTarget<IFixedProgram> IFixedProgramNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_FIXED_PROGRAM_H__

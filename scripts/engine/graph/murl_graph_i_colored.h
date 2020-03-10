// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_COLORED_H__
#define __MURL_GRAPH_I_COLORED_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    class Color;

    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IColored
         * @brief The IColored property interface.
         * This interface provides a generic way to specify individual colors for any
         * of the possible components found in a regular lighting equation, in particular
         * ambient, diffuse, specular and emissive components.
         *
         * Animation controllers may call the SetColor() method when color keys are
         * present in a given Resource::IAnimation.
         */
        class IColored
        {
        public:
            /**
             * @brief Set the color value of a given lighting component.
             * @param component The lighting component.
             * @param color The color to set.
             * @return true if successful.
             */
            virtual Bool SetColor(IEnums::LightingComponent component, const Color& color) = 0;
            /**
             * @brief Get the color value set for a given lighting component.
             * @param component The lighting component.
             * @return The current color.
             */
            virtual const Color& GetColor(IEnums::LightingComponent component) const = 0;

        protected:
            virtual ~IColored() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IColored nodes.
         */
        typedef IGenericNodeTarget<IColored> IColoredNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_COLORED_H__

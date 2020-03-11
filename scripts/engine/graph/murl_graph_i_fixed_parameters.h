// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_FIXED_PARAMETERS_H__
#define __MURL_GRAPH_I_FIXED_PARAMETERS_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_colored.h"
#include "murl_i_enums.h"

namespace Murl
{
    class Color;
    
    namespace Graph
    {
        class IParameters;
        class IFixedParameters;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IFixedParameters nodes.
         */
        typedef IGenericNodeTarget<IFixedParameters> IFixedParametersNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IFixedParameters
         * @brief The IFixedParameters graph node interface.
         * The IFixedParameters interface provides an easy way to define commonly used fixed
         * parameters such as material color or material shininess, to control the appearance
         * of renderable objects in conjunction with a given material.
         *
         * Use the Graph::IColored base interface to set or get the predefined lighting component
         * color values, such as ambient, diffuse, specular or emissive material properties.
         *
         * See the Graph::IParameters base interface for additional information.
         */
        class IFixedParameters : public IColored
        {
        public:
            enum FixedParametersFlags
            {
                FIXED_PARAMETERS_FLAG_AMBIENT_COLOR_MODIFIED  = (1 << 0),
                FIXED_PARAMETERS_FLAG_DIFFUSE_COLOR_MODIFIED  = (1 << 1),
                FIXED_PARAMETERS_FLAG_SPECULAR_COLOR_MODIFIED = (1 << 2),
                FIXED_PARAMETERS_FLAG_EMISSIVE_COLOR_MODIFIED = (1 << 3),
                
                FIXED_PARAMETERS_FLAG_SHININESS_MODIFIED      = (1 << 4),
                
                FIXED_PARAMETERS_FLAG_COLOR_MODIFIED = FIXED_PARAMETERS_FLAG_AMBIENT_COLOR_MODIFIED
                                                     + FIXED_PARAMETERS_FLAG_DIFFUSE_COLOR_MODIFIED
                                                     + FIXED_PARAMETERS_FLAG_SPECULAR_COLOR_MODIFIED
                                                     + FIXED_PARAMETERS_FLAG_EMISSIVE_COLOR_MODIFIED,
                
                FIXED_PARAMETERS_FLAG_MODIFIED       = FIXED_PARAMETERS_FLAG_AMBIENT_COLOR_MODIFIED
                                                     + FIXED_PARAMETERS_FLAG_DIFFUSE_COLOR_MODIFIED
                                                     + FIXED_PARAMETERS_FLAG_SPECULAR_COLOR_MODIFIED
                                                     + FIXED_PARAMETERS_FLAG_EMISSIVE_COLOR_MODIFIED
                                                     + FIXED_PARAMETERS_FLAG_SHININESS_MODIFIED
            };
            
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
             * @brief Get the mutable Graph::IParameters interface.
             * This method returns a mutable pointer to the node's Graph::IParameters interface, to
             * be able to query or modify common parameter properties.
             * @return The mutable Graph::IParameters interface, or null if not available
             */
            virtual IParameters* GetParametersInterface() = 0;
            /**
             * @brief Get the constant Graph::IParameters interface.
             * This method returns a constant pointer to the node's Graph::IParameters interface, to
             * be able to query common parameter properties.
             * @return The constant Graph::IParameters interface, or null if not available
             */
            virtual const IParameters* GetParametersInterface() const = 0;
            
            /**
             * @brief Get the mutable Graph::IFixedParameters container storing the object's parent.
             * This method returns a mutable pointer to the node's Graph::IFixedParameters
             * container that stores an optional reference to another fixed parameters object, to set
             * or query the object's parent.
             * @return The mutable Graph::IFixedParameters parent container, or null if not available.
             */
            virtual IFixedParametersNodeTarget* GetParentFixedParametersNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IFixedParameters container storing the object's parent.
             * This method returns a constant pointer to the node's Graph::IFixedParameters
             * container that stores an optional reference to another fixed parameters object, to query
             * the object's parent.
             * @return The constant Graph::IFixedParameters parent container, or null if not available.
             */
            virtual const IFixedParametersNodeTarget* GetParentFixedParametersNodeTarget() const = 0;
            
            /**
             * @brief Get current flags.
             * @return A bit mask made up from individual FixedParametersFlags values.
             */
            virtual UInt32 GetFixedParametersFlags() const = 0;
            
            /**
             * @brief Set the material shininess (specular exponent).
             * @param shininess The shininess value in the range from 0.0 to 128.0
             */
            virtual void SetShininess(Real shininess) = 0;
            /**
             * @brief Get the material shininess (specular exponent).
             * @return The shininess value in the range from 0.0 to 128.0
             */
            virtual Real GetShininess() const = 0;

            /**
             * @brief Get the color value set for a given lighting component, modulated with an optional parent.
             * @param component The lighting component.
             * @return The modulated color.
             */
            virtual const Color& GetModulatedColor(IEnums::LightingComponent component) const = 0;
            /**
             * @brief Get the shininess modulated with an optional parent.
             * @return The modulated shininess value in the range from 0.0 to 128.0
             */
            virtual Real GetModulatedShininess() const = 0;

        protected:
            virtual ~IFixedParameters() {}
        };
    }
}

#endif // __MURL_GRAPH_I_FIXED_PARAMETERS_H__

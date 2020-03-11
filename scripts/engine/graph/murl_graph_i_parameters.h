// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PARAMETERS_H__
#define __MURL_GRAPH_I_PARAMETERS_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_colored.h"
#include "murl_graph_i_state_slot.h"
#include "murl_i_enums.h"

namespace Murl
{
    class Color;
    
    namespace Video
    {
        class IConstants;
    }
    
    namespace Graph
    {
        class IParameters;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IParameters nodes.
         */
        typedef IGenericNodeTarget<IParameters> IParametersNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IParameters
         * @brief The IParameters graph node interface.
         * Parameters nodes hold different individual parameters that may be used by a
         * Graph::IProgram to parameterize its output. There exist a number of predefined
         * values for e.g. lighting component color values (see Graph::IFixedParameters); 
         * in addition, custom parameters can be added to control the behavior of user-defined 
         * GPU shader programs (see Graph::IGenericParameters).
         *
         * Use the Graph::IStateSlot base interface to set or get the parameters slot index these
         * parameters are temporarily attached to if any children are present.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::IParametersState for activating parameters for rendering.
         * See Graph::IProgram for defining GPU programs that act on these parameters.
         */
        class IParameters : public IStateSlot
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
             * @brief Get the mutable container holding the optional child parameters.
             * This method returns a mutable pointer to the node's Graph::IParametersNodeTarget
             * sub container, which is used to store multiple sub-parameters.
             * @return The mutable Graph::IParametersNodeTarget container, or null if not available.
             */
            virtual IParametersNodeTarget* GetSubParametersNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the optional child parameters.
             * This method returns a constant pointer to the node's Graph::IParametersNodeTarget
             * sub container, which is used to store multiple sub-parameters.
             * @return The constant Graph::IParametersNodeTarget container, or null if not available.
             */
            virtual const IParametersNodeTarget* GetSubParametersNodeTarget() const = 0;
            
            /**
             * @brief Get the parameters' number of detail levels.
             * @return The number of detail levels.
             */
            virtual UInt32 GetNumberOfDetailLevels() const = 0;
            /**
             * @brief Get the parameters' number of stages for a given detail level.
             * @param detailLevel The detail level to query.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages(UInt32 detailLevel) const = 0;
            /**
             * @brief Get the parameters' internal video renderer object for a given pass.
             * @param detailLevel The detail level to query.
             * @param stage The stage to query.
             * @return A pointer to the mutable video renderer object.
             */
            virtual Video::IConstants* GetVideoConstantsObject(UInt32 detailLevel, UInt32 stage) const = 0;
            
        protected:
            virtual ~IParameters() {}
        };
    }
}

#endif // __MURL_GRAPH_I_PARAMETERS_H__

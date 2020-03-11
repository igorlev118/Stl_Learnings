// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PARAMETERS_STATE_H__
#define __MURL_GRAPH_I_PARAMETERS_STATE_H__

#include "murl_graph_i_parameters.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IParametersState
         * @brief The IParametersState graph node interface.
         * Parameter state nodes are used to activate and/or quickly switch between GPU program
         * parameters during scene graph traversal. As soon as specific parameters are activated
         * at a given slot via a parameter state node, they stay active during traversal until
         * a different parameter state node using the same slot is encountered.
         *
         * Use the base interface's IStateSlot::SetSlot() method to set the actual slot index
         * the referenced parameters should be attached to.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::IParameters for defining specific parameters for rendering.\n
         */
        class IParametersState : public IStateSlot
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
             * @brief Get the mutable Graph::IParametersNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IParametersNodeTarget
             * container, which allows to set or query the parameters this state node refers to.
             * @return The mutable Graph::IParametersNodeTarget container, or null if not available.
             */
            virtual IParametersNodeTarget* GetParametersNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IParametersNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IParametersNodeTarget
             * container, which allows to query the parameters this state node refers to.
             * @return The mutable Graph::IParametersNodeTarget container, or null if not available.
             */
            virtual const IParametersNodeTarget* GetParametersNodeTarget() const = 0;
            
        protected:
            virtual ~IParametersState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IParametersState nodes.
         */
        typedef IGenericNodeTarget<IParametersState> IParametersStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_PARAMETERS_STATE_H__

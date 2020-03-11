// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_MATERIAL_STATE_H__
#define __MURL_GRAPH_I_MATERIAL_STATE_H__

#include "murl_graph_i_material.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IMaterialState
         * @brief The IMaterialState graph node interface.
         * Material state nodes are used to activate and/or quickly switch between materials
         * during scene graph traversal. As soon as a specific material is activated at a given
         * slot via a material state node, it stays active during traversal until a different
         * material state node using the same slot is encountered.
         *
         * Use the base interface's IStateSlot::SetSlot() method to set the actual slot index
         * the referenced material should be attached to.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::IMaterial for defining a specific material for rendering.\n
         */
        class IMaterialState : public IStateSlot
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
             * @brief Get the mutable Graph::IMaterialNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IMaterialNodeTarget
             * container, which allows to set or query the material this state node refers to.
             * @return The mutable Graph::IMaterialNodeTarget container, or null if not available.
             */
            virtual IMaterialNodeTarget* GetMaterialNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IMaterialNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IMaterialNodeTarget
             * container, which allows to query the material this state node refers to.
             * @return The mutable Graph::IMaterialNodeTarget container, or null if not available.
             */
            virtual const IMaterialNodeTarget* GetMaterialNodeTarget() const = 0;
            
        protected:
            virtual ~IMaterialState() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IMaterialState nodes.
         */
        typedef IGenericNodeTarget<IMaterialState> IMaterialStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_MATERIAL_STATE_H__

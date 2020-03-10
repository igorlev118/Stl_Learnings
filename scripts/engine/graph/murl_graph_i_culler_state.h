// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CULLER_STATE_H__
#define __MURL_GRAPH_I_CULLER_STATE_H__

#include "murl_graph_i_culler.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ICullerState
         * @brief The ICullerState graph node interface.
         * Culler state nodes are used to activate and/or quickly switch between object
         * cullers during scene graph traversal. As soon as a specific culler is activated
         * for audio or video rendering via a culler state node, it stays active for that
         * renderer during traversal until a different culler state node is encountered.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during 
         * scene graph traversal.\n
         * See Graph::ICuller for defining a specific object culler.\n
         */
        class ICullerState : public IStateSlot
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
             * @brief Get the mutable Graph::ICullerNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ICullerNodeTarget
             * container, which allows to set or query the culler this state node refers to.
             * @return The mutable Graph::ICullerNodeTarget container, or null if not available.
             */
            virtual ICullerNodeTarget* GetCullerNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ICullerNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ICullerNodeTarget
             * container, which allows to query the culler this state node refers to.
             * @return The mutable Graph::ICullerNodeTarget container, or null if not available.
             */
            virtual const ICullerNodeTarget* GetCullerNodeTarget() const = 0;
            
        protected:
            virtual ~ICullerState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICullerState nodes.
         */
        typedef IGenericNodeTarget<ICullerState> ICullerStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CULLER_STATE_H__

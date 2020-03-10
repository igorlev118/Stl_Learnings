// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SURFACE_STATE_H__
#define __MURL_GRAPH_I_SURFACE_STATE_H__

#include "murl_graph_i_surface.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISurfaceState
         * @brief The ISurfaceState graph node interface.
         * Surface state nodes are used to activate and/or quickly switch between physical
         * collision surfaces (Graph::ISurface) during scene graph traversal. As soon as a 
         * specific surface is activated at a given slot via a surface state node, it stays 
         * active during traversal until a different surface state node using the same slot 
         * is encountered.
         *
         * Use the base interface's IStateSlot::SetSlot() method to set the actual slot index
         * the referenced surface should be attached to.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene
         * graph traversal.\n
         * See Graph::ISurface for defining a specific surface for handling collisions.\n
         */
        class ISurfaceState : public IStateSlot
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
             * @brief Get the mutable Graph::ISurfaceNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ISurfaceNodeTarget
             * container, which allows to set or query the surface this state node refers to.
             * @return The mutable Graph::ISurfaceNodeTarget container, or null if not available.
             */
            virtual ISurfaceNodeTarget* GetSurfaceNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ISurfaceNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ISurfaceNodeTarget
             * container, which allows to query the surface this state node refers to.
             * @return The mutable Graph::ISurfaceNodeTarget container, or null if not available.
             */
            virtual const ISurfaceNodeTarget* GetSurfaceNodeTarget() const = 0;
            
        protected:
            virtual ~ISurfaceState() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISurfaceState nodes.
         */
        typedef IGenericNodeTarget<ISurfaceState> ISurfaceStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SURFACE_STATE_H__

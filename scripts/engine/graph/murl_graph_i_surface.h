// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SURFACE_H__
#define __MURL_GRAPH_I_SURFACE_H__

#include "murl_graph_i_program.h"
#include "murl_graph_i_state_slot.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Physics
    {
        class ISurface;
    }

    namespace Graph
    {
        class ISurface;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISurface nodes.
         */
        typedef IGenericNodeTarget<ISurface> ISurfaceNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISurface
         * @brief The ISurface graph node interface.
         * Surface nodes (not to be confused with Murl::IVideoSurface objects, which are used
         * to represent graphical (bitmap) data) are used to define a physical property for
         * nodes implementing the Graph::ICollidable interface.
         *
         * A surface does not store any physical properties itself, because the actual physical
         * behavior of a collision (such as bounciness or friction) greatly depends on the
         * surface combination of the collision partners. For this reason, every possible
         * (or at least every desired) combination of colliding surfaces must be explicitly
         * defined via individual Graph::IContact nodes, which store the actual collision 
         * properties for a given surface pair.
         *
         * Use the Graph::IStateSlot base interface to set or get the surface slot index this
         * surface is temporarily attached to if any children are present.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during
         * scene graph traversal.\n
         * See Graph::ISurfaceState for activating a surface for handling collisions.
         */
        class ISurface : public IStateSlot
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
             * @brief Get the surface's internal physics simulator object.
             * @return A pointer to the mutable physics simulator object.
             */
            virtual Physics::ISurface* GetPhysicsSurfaceObject() const = 0;
            
        protected:
            virtual ~ISurface() {}
        };
    }
}

#endif // __MURL_GRAPH_I_SURFACE_H__

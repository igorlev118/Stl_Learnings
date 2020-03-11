// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_COLLIDABLE_H__
#define __MURL_GRAPH_I_COLLIDABLE_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface ICollidable
         * @brief The ICollidable graph node interface.
         * Collidables are used in the framework's physics simulator to generate collisions
         * between individual Graph::IBody nodes. There exist a number of derived interfaces
         * that represent colliders of different shapes, such as planes, spheres or triangle
         * meshes.
         *
         * To attach a collider to a specific body, it must be defined within the sub graph
         * of that body, not necessarily as a direct child. It is possible to apply a relative
         * transform between the actual body and any of its colliders, to build a more complex
         * collision object made up from a number of simple colliders.
         *
         * The actual physical properties of an encountered collision with another collidable (such
         * as bounciness or friction) are determined from a Graph::IContact node defining these
         * properties for a Graph::ISurface pair, with the Graph::ISurface currently active at
         * at the given slot (see SetSurfaceSlot()) and the collision partner's surface.
         *
         * See Graph::ISurface for defining a collidable's phyiscal surface properties.
         * See Graph::IBody for defining a body to attach to.
         */
        class ICollidable
        {
        public:
            /**
             * @brief Set the surface slot used for simulation.
             * @param slot The surface slot.
             * @return true if successful.
             */
            virtual Bool SetSurfaceSlot(SInt32 slot) = 0;
            /**
             * @brief Get the surface slot used for simulation.
             * @return The surface slot.
             */
            virtual SInt32 GetSurfaceSlot() const = 0;
            
        protected:
            virtual ~ICollidable() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICollidable nodes.
         */
        typedef IGenericNodeTarget<ICollidable> ICollidableNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_COLLIDABLE_H__

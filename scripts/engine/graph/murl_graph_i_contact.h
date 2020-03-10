// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONTACT_H__
#define __MURL_GRAPH_I_CONTACT_H__

#include "murl_graph_i_surface.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IContact;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IContact nodes.
         */
        typedef IGenericNodeTarget<IContact> IContactNodeTarget;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IContact
         * @brief The IContact graph node interface.
         * Contact nodes define the actual physical properties of a possible collision
         * in the physics simulator, such as bounciness or friction. Every possible (or
         * desired) combination of Graph::ISurface pairs must be defined via a contact.
         *
         * See Graph::ISurface for defining a collision surface.
         * See Graph::ISurfaceSlot for activating a surface for collision handling.
         * See Graph::ICollidable for assigning a surface to a given collider.
         */
        class IContact
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
            
            /**
             * @brief Set the contact's static friction coefficient.
             * @param value The static friction coefficient.
             * @return true if successful.
             *
             * @todo More detailed description.
             */
            virtual Bool SetStaticFrictionConstant(Real value) = 0;
            /**
             * @brief Get the contact's static friction coefficient.
             * @return The contact's static friction coefficient.
             */
            virtual Real GetStaticFrictionConstant() const = 0;
            
            /**
             * @brief Set the contact's dynamic (kinetic) friction coefficient.
             * @param value The contact's dynamic friction coefficient.
             * @return true if successful.
             *
             * @todo More detailed description.
             */
            virtual Bool SetDynamicFrictionConstant(Real value) = 0;
            /**
             * @brief Get the contact's dynamic friction coefficient.
             * @return The contact's dynamic friction coefficient.
             */
            virtual Real GetDynamicFrictionConstant() const = 0;
            
            /**
             * @brief Set the contact's rolling friction coefficient.
             * TODO: More detailed description.
             * @param value The contact's rolling friction coefficient.
             * @return true if successful.
             */
            virtual Bool SetRollingFrictionConstant(Real value) = 0;
            /**
             * @brief Get the contact's rolling friction coefficient.
             * @return The contact's rolling friction coefficient.
             */
            virtual Real GetRollingFrictionConstant() const = 0;
            
            /**
             * @brief Set the contact's spring constant.
             * TODO: More detailed description.
             * @param value The contact's spring constant.
             * @return true if successful.
             */
            virtual Bool SetSpringConstant(Real value) = 0;
            /**
             * @brief Get the contact's spring constant.
             * @return The contact's spring constant.
             */
            virtual Real GetSpringConstant() const = 0;
            
            /**
             * @brief Set the contact's damping constant.
             * TODO: More detailed description.
             * @param value The contact's damping constant.
             * @return true if successful.
             */
            virtual Bool SetDampingConstant(Real value) = 0;
            /**
             * @brief Get the contact's damping constant.
             * @return The contact's damping constant.
             */
            virtual Real GetDampingConstant() const = 0;
            
            /**
             * @brief Set the contact's bounce factor.
             * TODO: More detailed description.
             * @param value The contact's bounce factor.
             * @return true if successful.
             */
            virtual Bool SetBounceFactor(Real value) = 0;
            /**
             * @brief Get the contact's bounce factor.
             * @return The contact's bounce factor.
             */
            virtual Real GetBounceFactor() const = 0;
            
            /**
             * @brief Set the contact's bounce velocity threshold.
             * TODO: More detailed description.
             * @param value The contact's bounce velocity threshold.
             * @return true if successful.
             */
            virtual Bool SetBounceThreshold(Real value) = 0;
            /**
             * @brief Get the contact's bounce velocity threshold.
             * @return The contact's bounce velocity threshold.
             */
            virtual Real GetBounceThreshold() const = 0;

            /**
             * @brief Set the contact's surface slip value.
             * TODO: More detailed description.
             * @param slip The contact's surface slip value.
             * @return true if successful.
             */
            virtual Bool SetSlip(Real slip) = 0;
            /**
             * @brief Get the contact's surface slip value.
             * @return The contact's surface slip value.
             */
            virtual Real GetSlip() const = 0;

        protected:
            virtual ~IContact() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CONTACT_H__

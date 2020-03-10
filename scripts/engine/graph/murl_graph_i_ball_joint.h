// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BALL_JOINT_H__
#define __MURL_GRAPH_I_BALL_JOINT_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        class IJoint;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IBallJoint
         * @brief The IBallJoint graph node interface.
         * A ball joint (also known as a ball-and-socket joint) is a joint that connects two
         * bodies by enforcing a translation constraint along each of the three axes in 3D space,
         * while leaving the rotation axes unconstrained (3 degrees of freedom).
         */
        class IBallJoint
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
             * @brief Get the mutable Graph::ITransform interface.
             * This method returns a mutable pointer to the node's Graph::ITransform interface,
             * to be able to query or modify the node's transformation matrix and depth
             * order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's Graph::ITransform interface,
             * to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;

            /**
             * @brief Get the mutable Graph::IJoint interface.
             * This method returns a mutable pointer to the node's Graph::IJoint interface,
             * to be able to query or modify common joint-related properties.
             * @return The mutable Graph::IJoint interface.
             */
            virtual IJoint* GetJointInterface() = 0;
            /**
             * @brief Get the constant Graph::IJoint interface.
             * This method returns a constant pointer to the node's Graph::IJoint interface,
             * to be able to query common joint-related properties.
             * @return The constant Graph::IJoint interface.
             */
            virtual const IJoint* GetJointInterface() const = 0;
            
        protected:
            virtual ~IBallJoint() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IBallJoint nodes.
         */
        typedef IGenericNodeTarget<IBallJoint> IBallJointNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BALL_JOINT_H__

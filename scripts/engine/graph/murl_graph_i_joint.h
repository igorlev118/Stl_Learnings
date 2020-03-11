// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_JOINT_H__
#define __MURL_GRAPH_I_JOINT_H__

#include "murl_graph_i_body.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IJoint
         * @brief The IJoint graph node interface.
         * Joint nodes are used in the framework's physics simulator to connect two Graph::IBody
         * nodes, or to connect a single Graph::IBody node to a specific point in world space.
         * There exist different joint types (e.g. Graph::IBallJoint or Graph::IHingeJoint),
         * each of which enforces different constraints on the connection.
         */
        class IJoint
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
             * @brief Get the mutable Graph::IBodyNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IBodyNodeTarget
             * container, which allows to set or query the bodies to be connected.
             * @return The mutable Graph::IBodyNodeTarget container.
             */
            virtual IBodyNodeTarget* GetBodyNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IBodyNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IBodyNodeTarget
             * container, which allows to query the connected bodies.
             * @return The constant Graph::IBodyNodeTarget container.
             */
            virtual const IBodyNodeTarget* GetBodyNodeTarget() const = 0;

            /**
             * @brief Set the anchor position at a given index.
             * If a body is present at the given index (in the range from 0 to 1), the given
             * position represents the anchor position relative to that body's local coordinate
             * system. If no body is present, the position is interpreted relative to the
             * joint itself, which can be set using the joint's ITransformable interface
             * obtained from GetTransformInterface().
             * @param index The anchor index, either 0 or 1.
             * @param position The anchor position.
             * @return true if successful.
             */
            virtual Bool SetBodyPosition(UInt32 index, const Vector& position) = 0;
            /**
             * @brief Get the anchor position at a given index.
             * See SetBodyPosition().
             * @param index The anchor index, either 0 or 1.
             * @return The anchor position.
             */
            virtual const Vector& GetBodyPosition(UInt32 index) const = 0;
            
            /**
             * @brief Enable/disable the joint's influence on an attached body.
             * @param index The body index, either 0 or 1.
             * @param enabled If true, the attached body gets influenced by the joint.
             * @return true if successful.
             */
            virtual Bool SetBodyInfluence(UInt32 index, Bool enabled) = 0;
            /**
             * @brief Check if the joint is influencing an attached body.
             * @param index The body index, either 0 or 1.
             * @return true if influence is enabled.
             */
            virtual Bool GetBodyInfluence(UInt32 index) const = 0;

            /**
             * @brief Set the joint's spring constant.
             * @param springConstant The spring constant.
             * @return true if successful.
             */
            virtual Bool SetSpringConstant(Real springConstant) = 0;
            /**
             * @brief Get the joint's spring constant.
             * @return The spring constant.
             */
            virtual Real GetSpringConstant() const = 0;

            /**
             * @brief Set the joint's damping constant.
             * @param dampingConstant The damping constant.
             * @return true if successful.
             */
            virtual Bool SetDampingConstant(Real dampingConstant) = 0;
            /**
             * @brief Get the joint's damping constant.
             * @return The damping constant.
             */
            virtual Real GetDampingConstant() const = 0;

        protected:
            virtual ~IJoint() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IJoint nodes.
         */
        typedef IGenericNodeTarget<IJoint> IJointNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_JOINT_H__

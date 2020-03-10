// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SPRING_H__
#define __MURL_GRAPH_I_SPRING_H__

#include "murl_graph_i_body.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISpring
         * @brief The ISpring graph node interface.
         * Spring nodes can be used to either connect a Graph::IBody instance to a given point
         * in world space, or to connect two separate Graph::IBody instances.
         *
         * If only one body is connected to the spring (at either end), the other end point is
         * represented by the spring's actual position in world space, defined by its
         * Graph::ITransform interface (and its parent transform hierarchy).
         */
        class ISpring
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
             * container, which allows to set or query the (up to) two bodies this spring
             * is connected to.
             * @return The mutable Graph::IBodyNodeTarget container, or null if not available.
             */
            virtual IBodyNodeTarget* GetBodyNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IBodyNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IBodyNodeTarget
             * container, which allows to query the (up to) two bodies this spring is
             * connected to.
             * @return The mutable Graph::IBodyNodeTarget container, or null if not available.
             */
            virtual const IBodyNodeTarget* GetBodyNodeTarget() const = 0;
            
            /**
             * @brief Set the relative attachment point of a body.
             * If a body is connected to the spring at the given index, the given position vector
             * represents the spring's anchor point at that body, relative to the body's center.
             * @param index The body index, either 0 or 1.
             * @param position The anchor position relative to the body's center.
             * @return true if successful.
             */
            virtual Bool SetBodyPosition(UInt32 index, const Vector& position) = 0;
            /**
             * @brief Get the relative attachment point of a body.
             * @param index The body index, either 0 or 1.
             * @return The anchor position relative to the body's center.
             */
            virtual const Vector& GetBodyPosition(UInt32 index) const = 0;
            
            /**
             * @brief Enable/disable the spring's influence on an attached body.
             * @param index The body index, either 0 or 1.
             * @param enabled If true, the attached body gets influenced by the spring.
             * @return true if successful.
             */
            virtual Bool SetBodyInfluence(UInt32 index, Bool enabled) = 0;
            /**
             * @brief Check if the spring is influencing an attached body.
             * @param index The body index, either 0 or 1.
             * @return true if influence is enabled.
             */
            virtual Bool GetBodyInfluence(UInt32 index) const = 0;
            
            /**
             * @brief Set the spring constant.
             * @param springConstant The spring constant.
             * @return true if successful.
             */
            virtual Bool SetSpringConstant(Real springConstant) = 0;
            /**
             * @brief Get the spring constant.
             * @return The spring constant.
             */
            virtual Real GetSpringConstant() const = 0;
            
            /**
             * @brief Set the damping constant.
             * @param dampingConstant The damping constant.
             * @return true if successful.
             */
            virtual Bool SetDampingConstant(Real dampingConstant) = 0;
            /**
             * @brief Get the damping constant.
             * @return The damping constant.
             */
            virtual Real GetDampingConstant() const = 0;
            
            /**
             * @brief Set the minimum length of the spring.
             * As long as the simulated length of the spring is between its defined minimum and
             * maximum length, no force is applied to its attached bodies. When the spring gets
             * compressed below its minimum length or expanded above its maximum length, a
             * directional force is applied to restore the spring to a safe "resting length".
             * See also SetMaximumLength().
             * @param minLength The spring's minimum length.
             * @return true if successful.
             */
            virtual Bool SetMinimumLength(Real minLength) = 0;
            /**
             * @brief Get the minimum length of the spring.
             * @return The spring's minimum length.
             */
            virtual Real GetMinimumLength() const = 0;
            
            /**
             * @brief Set the maximum length of the spring.
             * See SetMinimumLength().
             * @param maxLength The spring's maximum length.
             * @return true if successful.
             */
            virtual Bool SetMaximumLength(Real maxLength) = 0;
            /**
             * @brief Get the maximum length of the spring.
             * @return The spring's maximum length.
             */
            virtual Real GetMaximumLength() const = 0;
            
            /**
             * @brief Enable/disable force effect.
             * @param enabled If false, the spring does not apply any directional force on
             *      its attached bodies.
             * @return true if successful.
             */
            virtual Bool SetForceEffectEnabled(Bool enabled) = 0;
            /**
             * @brief Check if force effect is enabled.
             * @return true if enabled.
             */
            virtual Bool IsForceEffectEnabled() const = 0;
            
            /**
             * @brief Enable/disable torque effect.
             * @param enabled If false, the spring does not apply any torque on
             *      its attached bodies.
             * @return true if successful.
             */
            virtual Bool SetTorqueEffectEnabled(Bool enabled) = 0;
            /**
             * @brief Check if torque effect is enabled.
             * @return true if enabled.
             */
            virtual Bool IsTorqueEffectEnabled() const = 0;
            
        protected:
            virtual ~ISpring() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISpring nodes.
         */
        typedef IGenericNodeTarget<ISpring> ISpringNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SPRING_H__

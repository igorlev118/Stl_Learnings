// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_RESET_TRANSFORM_H__
#define __MURL_GRAPH_I_RESET_TRANSFORM_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IResetTransform
         * @brief The IResetTransform graph node interface.
         * Nodes implementing this interface can be used to reset the position and/or
         * rotation component of the currently active combined transform on the transform stack.
         * This can be useful if e.g. a camera is attached to a moving object, but should always
         * look in a specific direction regardless of the object's actual orientation. In such
         * a case, an IResetTransform node can be inserted below the object and above the camera,
         * with calling SetAffectTranslationEnabled(false) to retain the object's position, and
         * SetAffectRotationEnabled(true) to reset its rotation to the identity 3x3 matrix.
         *
         * Note, that like all other transform nodes, the effect is limited to this node's children;
         * all siblings of this node are not affected.
         */
        class IResetTransform
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
             * @brief Enable/disable resetting of the current world rotation.
             * @param enabled If true, the rotation part of the current world transform is reset
             *      to the 3x3 identity matrix.
             * @return true if successful.
             */
            virtual Bool SetAffectRotationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if resetting of the current world rotation is enabled.
             * @return true if enabled.
             */
            virtual Bool IsAffectRotationEnabled() const = 0;
            
            /**
             * @brief Enable/disable resetting of the current world translation.
             * @param enabled If true, the translation part of the current world transform is
             *      reset to the zero position vector.
             * @return true if successful.
             */
            virtual Bool SetAffectTranslationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if resetting of the current world translation is enabled.
             * @return true if enabled.
             */
            virtual Bool IsAffectTranslationEnabled() const = 0;
            
            /**
             * @brief Enable/disable resetting of the current depth order.
             * @param enabled If true, the depth order is reset to zero.
             * @return true if successful.
             */
            virtual Bool SetAffectDepthOrderEnabled(Bool enabled) = 0;
            /**
             * @brief Check if resetting of the current depth order is enabled.
             * @return true if enabled.
             */
            virtual Bool IsAffectDepthOrderEnabled() const = 0;

        protected:
            virtual ~IResetTransform() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IResetTransform nodes.
         */
        typedef IGenericNodeTarget<IResetTransform> IResetTransformNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_RESET_TRANSFORM_H__

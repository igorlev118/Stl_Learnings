// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LISTENER_TRANSFORM_H__
#define __MURL_GRAPH_I_LISTENER_TRANSFORM_H__

#include "murl_graph_i_listener.h"
#include "murl_graph_i_anchor.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IListenerTransform
         * @brief The IListenerTransform graph node interface.
         * A listener node defined in the scene graph only defines the general behavior of a
         * listener in the virtual world; to be able to move and rotate the listener, it is
         * necessary to define an IListenerTransform node that refers to a specific listener.
         * By separating a listener from its transform, it is possible to already use a listener
         * before its actual world position and rotation are evaluated; this way, the listener
         * can be quickly attached to e.g. a moving object that is supposed to be also audible
         * throught that listener, by simply defining an IListenerTransform node as a child of
         * the respective object.
         *
         * See Graph::IListener for defining a specific listener for rendering.\n
         * See Graph::IListenerState for activating a listener for rendering.
         */
        class IListenerTransform
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
             * @brief Get the mutable Graph::IListenerNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IListenerNodeTarget
             * container, which allows to set or query the listener this transform node refers to.
             * @return The mutable Graph::IListenerNodeTarget container, or null if not available.
             */
            virtual IListenerNodeTarget* GetListenerNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IListenerNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IListenerNodeTarget
             * container, which allows to query the listener this transform node refers to.
             * @return The mutable Graph::IListenerNodeTarget container, or null if not available.
             */
            virtual const IListenerNodeTarget* GetListenerNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IAnchorNodeTarget container for the target position.
             * This method returns a mutable pointer to the node's Graph::IAnchorNodeTarget
             * container, which allows to add, remove or query the referenced Graph::IAnchor node used
             * as a view target.
             * @return The mutable Graph::IAnchorNodeTarget container, or null if not available
             */
            virtual IAnchorNodeTarget* GetAnchorNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IAnchorNodeTarget container for the target position.
             * This method returns a constant pointer to the node's Graph::IAnchorNodeTarget
             * container, which allows to query the referenced Graph::IAnchor node used
             * as a view target.
             * @return The constant Graph::IAnchorNodeTarget container, or null if not available
             */
            virtual const IAnchorNodeTarget* GetAnchorNodeTarget() const = 0;

            /**
             * @brief Set the target anchor up vector.
             * The up vector is used to orient the view when a target anchor node is given.
             * @param upVector The up vector.
             * @return true if successful.
             */
            virtual Bool SetUpVector(const Vector& upVector) = 0;
            /**
             * @brief Get the target anchor up vector.
             * @return The up vector.
             */
            virtual const Vector& GetUpVector() const = 0;

        protected:
            virtual ~IListenerTransform() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IListenerTransform nodes.
         */
        typedef IGenericNodeTarget<IListenerTransform> IListenerTransformNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_LISTENER_TRANSFORM_H__

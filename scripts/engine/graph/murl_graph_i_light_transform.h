// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LIGHT_TRANSFORM_H__
#define __MURL_GRAPH_I_LIGHT_TRANSFORM_H__

#include "murl_graph_i_light.h"
#include "murl_graph_i_anchor.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ILightTransform
         * @brief The ILightTransform graph node interface.
         * A light node defined in the scene graph only defines the general parameters of a
         * light in the virtual world; to be able to position and rotate the light, it is
         * necessary to define an ILightTransform node that refers to a specific light.
         * By separating a light from its transform, it is possible to already use a light
         * before its actual world position and rotation are evaluated; this way, the light
         * can be quickly attached as a child to e.g. a moving object that is supposed to be
         * also influenced by that light.
         *
         * See Graph::ILight for defining individual light sources and their group assignment.\n
         * See Graph::ILightState for activating lights for rendering.
         */
        class ILightTransform
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
             * @brief Get the mutable Graph::ILightNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ILightNodeTarget
             * container, which allows to set or query the light this transform node refers to.
             * @return The mutable Graph::ILightNodeTarget container, or null if not available.
             */
            virtual ILightNodeTarget* GetLightNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ILightNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ILightNodeTarget
             * container, which allows to query the light this transform node refers to.
             * @return The mutable Graph::ILightNodeTarget container, or null if not available.
             */
            virtual const ILightNodeTarget* GetLightNodeTarget() const = 0;

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
            virtual ~ILightTransform() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ILightTransform nodes.
         */
        typedef IGenericNodeTarget<ILightTransform> ILightTransformNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_LIGHT_TRANSFORM_H__

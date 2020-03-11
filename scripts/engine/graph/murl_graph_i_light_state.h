// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LIGHT_STATE_H__
#define __MURL_GRAPH_I_LIGHT_STATE_H__

#include "murl_graph_i_light.h"
#include "murl_graph_i_state_unit.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ILightState
         * @brief The ILightState graph node interface.
         * Light state nodes are used to activate lights for rendering during scene graph
         * traversal. As soon as a specific light is activated via a light state node,
         * it stays active during traversal until a different light state node is encountered.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::ILight for defining individual light sources and their group assignment.\n
         * See Graph::ILightTransform for setting a light's position and orientation.\n
         */
        class ILightState : public IStateUnit
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
             * @brief Get the mutable Graph::ILightNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ILightNodeTarget
             * container, which allows to set or query the light this state refers to.
             * @return The mutable Graph::ILightNodeTarget container, or null if not available.
             */
            virtual ILightNodeTarget* GetLightNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ILightNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ILightNodeTarget
             * container, which allows to query the light this state refers to.
             * @return The mutable Graph::ILightNodeTarget container, or null if not available.
             */
            virtual const ILightNodeTarget* GetLightNodeTarget() const = 0;
            
        protected:
            virtual ~ILightState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ILightState nodes.
         */
        typedef IGenericNodeTarget<ILightState> ILightStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_LIGHT_STATE_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CAMERA_STATE_H__
#define __MURL_GRAPH_I_CAMERA_STATE_H__

#include "murl_graph_i_camera.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ICameraState
         * @brief The ICameraState graph node interface.
         * Camera state nodes are used to activate and/or quickly switch between cameras
         * during scene graph traversal. As soon as a specific camera is activated via a
         * camera state node, it stays active during traversal until a different camera
         * state node is encountered.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during 
         * scene graph traversal.\n
         * See Graph::ICamera for defining a specific camera for rendering.\n
         * See Graph::ICameraTransform for setting a camera's position and orientation.
         */
        class ICameraState : public IStateSlot
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
             * @brief Get the mutable Graph::ICameraNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ICameraNodeTarget
             * container, which allows to set or query the camera this state node refers to.
             * @return The mutable Graph::ICameraNodeTarget container, or null if not available.
             */
            virtual ICameraNodeTarget* GetCameraNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ICameraNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ICameraNodeTarget
             * container, which allows to query the camera this state node refers to.
             * @return The mutable Graph::ICameraNodeTarget container, or null if not available.
             */
            virtual const ICameraNodeTarget* GetCameraNodeTarget() const = 0;
            
        protected:
            virtual ~ICameraState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICameraState nodes.
         */
        typedef IGenericNodeTarget<ICameraState> ICameraStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CAMERA_STATE_H__

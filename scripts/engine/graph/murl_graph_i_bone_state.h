// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BONE_STATE_H__
#define __MURL_GRAPH_I_BONE_STATE_H__

#include "murl_graph_i_bone.h"
#include "murl_graph_i_state_unit.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IBoneState
         * @brief The IBoneState graph node interface.
         * A bone state node is used to assign a given Graph::IBone to a given unit during
         * scene graph traversal. For the purpose of vertex skinning, a renderable geometry
         * such as a Graph::IResourceMeshGeometry node can link to one or more bones by
         * specifying the appropriate number of bone unit indices; during scene graph
         * traversal, the currently active bones at the selected units will be taken to
         * actually deform the geometry.
         *
         * The correct sequence of creating and using a skeleton for performing vertex
         * skinning is as follows:
         * - Create a hierarchical skeleton made up from individual transform and bone nodes,
         *   with unique IDs assigned to each bone
         * - Activate all bones needed for a specific mesh in the correct bone units, by
         *   means of individual IBoneState nodes
         * - Render the geometry through e.g. a Graph::IResourceMeshGeometry node
         *   (not forgetting to also set needed material/texture states etc.)
         *
         * Use the interface's GetBoneNodeTarget() method to programmatically set the bone
         * node this state object is supposed to refer to.\n
         * Use the base interface's IStateUnit::SetUnit() method to set the actual unit index
         * the referenced bone should be attached to.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::IBone for defining bones to refer to.
         */
        class IBoneState : public IStateUnit
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
             * @brief Get the mutable Graph::IBoneNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IBoneNodeTarget
             * container, which allows to add, remove or query the bone state node's
             * referenced bone node.
             * @return The mutable Graph::IBoneNodeTarget container, or null if not available
             */
            virtual IBoneNodeTarget* GetBoneNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IBoneNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IBoneNodeTarget
             * container, which allows to query the bone state node's referenced bone
             * node.
             * @return The constant Graph::IBoneNodeTarget container, or null if not available
             */
            virtual const IBoneNodeTarget* GetBoneNodeTarget() const = 0;
            
        protected:
            virtual ~IBoneState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IBoneState nodes.
         */
        typedef IGenericNodeTarget<IBoneState> IBoneStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BONE_STATE_H__

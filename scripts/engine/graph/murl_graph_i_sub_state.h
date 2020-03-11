// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SUB_STATE_H__
#define __MURL_GRAPH_I_SUB_STATE_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISubState
         * @brief The ISubState graph node interface.
         * Graph::ISubState nodes can be used to encapsulate scene graph traversal state changes,
         * so that the user does not have to track all changes to e.g. material states, texture
         * states etc.
         *
         * By default, when it gets initialized, a sub state node determines the states that get
         * actually changed during traversal of its sub-graph. When the scene graph gets traversed,
         * only those states are preserved. It is possible to manually override this behavior by
         * setting a state bit mask via SetPreservedStatesIncludeMask() and SetPreservedStatesExcludeMask(),
         * to either include additional preserved states or force the node to not include specific
         * ones.
         *
         * State preserving is not free; the more states are changing within the sub-graph, the more
         * information must be kept at each traversal. Especially when a lot of texture and/or material
         * state slots are involved, this can be a costly operation.
         */
        class ISubState
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
             * @brief Set the traversal states to be preserved.
             * @param mask A bit mask of individual traversal states. See IEnums::TraversalState.
             * @return true if successful.
             */
            virtual Bool SetPreservedStatesIncludeMask(UInt32 mask) = 0;
            /**
             * @brief Get the traversal states to be preserved.
             * @return A bit mask of individual traversal states. See IEnums::TraversalState.
             */
            virtual UInt32 GetPreservedStatesIncludeMask() const = 0;

            /**
             * @brief Set the traversal states to be explicitly not preserved.
             * @param mask A bit mask of individual traversal states. See IEnums::TraversalState.
             * @return true if successful.
             */
            virtual Bool SetPreservedStatesExcludeMask(UInt32 mask) = 0;
            /**
             * @brief Get the traversal states to be explicitly not preserved.
             * @return A bit mask of individual traversal states. See IEnums::TraversalState.
             */
            virtual UInt32 GetPreservedStatesExcludeMask() const = 0;
            
        protected:
            virtual ~ISubState() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISubState nodes.
         */
        typedef IGenericNodeTarget<ISubState> ISubStateNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SUB_STATE_H__

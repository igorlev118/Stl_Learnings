// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TRAVERSABLE_H__
#define __MURL_GRAPH_I_TRAVERSABLE_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface ITraversable
         * @brief The ITraversable property interface.
         * Animation controllers may call the SetActive() and SetVisible() methods when
         * appropriate keys are present in a given Resource::IAnimation.
         */
        class ITraversable
        {
        public:
            /**
             * @brief Enable/disable logic traversals.
             * The 'active' state controls whether or not logic traversals are carried out
             * on a node implementing this interface and its children.
             * @param isActive If true, logic traversals are enabled.
             * @return true if successful.
             */
            virtual Bool SetActive(Bool isActive) = 0;
            /**
             * @brief Check if logic traversals are enabled
             * @return true if enabled.
             */
            virtual Bool IsActive() const = 0;
            
            /**
             * @brief Enable/disable output traversals.
             * The 'visible' state controls whether or not output traversals are carried out
             * on a node implementing this interface and its children.
             * @param isVisible If true, output traversals are enabled.
             * @return true if successful.
             */
            virtual Bool SetVisible(Bool isVisible) = 0;
            /**
             * @brief Check if output traversals are enabled
             * @return true if enabled.
             */
            virtual Bool IsVisible() const = 0;
            
            /**
             * @brief Enable/disable both logic and output traversals.
             * @see SetActive()
             * @see SetVisible()
             * @param enabled If true, both logic and output traversals are enabled.
             * @return true if successful.
             */
            virtual Bool SetActiveAndVisible(Bool enabled) = 0;
            /**
             * @brief Check if both logic and output traversals are enabled
             * @return true if both are enabled.
             */
            virtual Bool IsActiveAndVisible() const = 0;
            
        protected:
            virtual ~ITraversable() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITraversable nodes.
         */
        typedef IGenericNodeTarget<ITraversable> ITraversableNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TRAVERSABLE_H__

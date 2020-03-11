// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_OBSERVABLE_NODE_H__
#define __MURL_LOGIC_I_OBSERVABLE_NODE_H__

#include "murl_logic_types.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IObservableNode
         * @brief The IObservableNode interface.
         * Objects implementing the IObservableNode interface can be registered to the INodeObserver.
         * This interface is typically used to maintain graph node interface references.
         * See @link MurlLogicGraphNodeTypes GraphNodeTypes @endlink for predefined types.
         * \n
         * The IProcessor object provides a ready to use node observer.
         */
        class IObservableNode
        {
        public:
            /**
             * @brief Check the node.
             * @return true if the node is valid.
             */
            virtual Bool IsValid() const = 0;

            /**
             * @brief Remove the reference from the node.
             * @return true if successful.
             */
            virtual Bool RemoveReference() = 0;

        protected:
            virtual ~IObservableNode() {}
        };
    }
}

#endif  // __MURL_LOGIC_I_OBSERVABLE_NODE_H__

// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_NODE_OBSERVER_H__
#define __MURL_LOGIC_I_NODE_OBSERVER_H__

#include "murl_logic_i_observable_node.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface INodeObserver
         * @brief The INodeObserver interface.
         * The node observer notifies objects implementing the IObservableNode interface.
         * \n
         * The IProcessor object provides a ready to use node observer.
         */
        class INodeObserver
        {
        public:
            /**
             * @brief Add a observable node object to the observer.
             * @param node The observable node object to add.
             * @return true if successful.
             */
            virtual Bool Add(IObservableNodePtr node) = 0;
            /**
             * @brief Remove a observable node object from the observer.
             * @param node The observable node object to remove.
             * @return true if successful.
             */
            virtual Bool Remove(IObservableNodePtr node) = 0;
            /**
             * @brief Remove a observable node object by index from the observer.
             * A valid index is [0 .. GetNumberOfNodes() - 1].
             * @param index The zero based index of the observable node object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveAt(UInt32 index) = 0;

            /**
             * @brief Get the number of observable node objects in the observer.
             * @return The number of observable node objects.
             */
            virtual UInt32 GetNumberOfNodes() const = 0;

            /**
             * @brief Get a observable node object by index.
             * A valid index is [0 .. GetNumberOfNodes() - 1].
             * @param index The zero based index of the observable node object.
             * @return The observable node object or null if the index is out of range.
             */
            virtual IObservableNodePtr GetNode(UInt32 index) const = 0;
            /**
             * @brief Get a valid observable node object by index.
             * Check the observable node at index using IObservableNode::IsValid().
             * A valid index is [0 .. GetNumberOfNodes() - 1].
             * @param index The zero based index of the observable node object.
             * @return The observable node object or null if the node object is invalid
             *  or the index is out of range.
             */
            virtual IObservableNodePtr GetNodeIfValid(UInt32 index) const = 0;

            /**
             * @brief Check all observed nodes.
             * @return true if all observed nodes are valid.
             */
            virtual Bool AreValid() const = 0;
            /**
             * @brief Remove all observed nodes from the observer.
             * @return true if successful.
             */
            virtual Bool RemoveAll() = 0;

        protected:
            virtual ~INodeObserver() {}
        };
    }
}

#endif  // __MURL_LOGIC_I_NODE_OBSERVER_H__

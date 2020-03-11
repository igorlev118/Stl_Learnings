// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_BASE_NODE_OBSERVER_H__
#define __MURL_LOGIC_BASE_NODE_OBSERVER_H__

#include "murl_logic_i_node_observer.h"
#include "murl_logic_i_factory.h"

#include "murl_logic_graph_node_types.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the INodeObserver object.
         * A node observer is created and initialized at object instantiation.
         */
        class BaseNodeObserver : public NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             * Creates a INodeObserver object.
             */
            BaseNodeObserver()
            : mNodeObserver(StaticFactory::CreateNodeObserver())
            {
            }

            /**
             * @brief The destructor.
             * Destroys the INodeObserver object.
             */
            virtual ~BaseNodeObserver()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The INodeObserver interface.
             */
            operator INodeObserver*() const
            {
                return mNodeObserver.Get();
            }

            /**
             * @brief Conversion operator.
             * @return The INodeObserver interface.
             */
            operator INodeObserverPtr() const
            {
                return mNodeObserver;
            }

            /**
             * @brief Get the node observer interface.
             * @return The INodeObserver interface.
             */
            INodeObserverPtr GetNodeObserver() const
            {
                return mNodeObserver;
            }

        public: // INodeObserver

            /**
             * @brief Forward to INodeObserver::Add() method.
             * @param node The observable node object to add.
             * @return true if successful.
             */
            Bool Add(IObservableNodePtr node)
            {
                return mNodeObserver->Add(node);
            }
            /**
             * @brief Forward to INodeObserver::Remove() method.
             * @param node The observable node object to remove.
             * @return true if successful.
             */
            Bool Remove(IObservableNodePtr node)
            {
                return mNodeObserver->Remove(node);
            }
            /**
             * @brief Forward to INodeObserver::RemoveAt() method.
             * @param index The zero based index of the observable node object to remove.
             * @return true if successful.
             */
            Bool RemoveAt(UInt32 index)
            {
                return mNodeObserver->RemoveAt(index);
            }

            /**
             * @brief Forward to INodeObserver::GetNumberOfNodes() method.
             * @return The number of observable node objects.
             */
            UInt32 GetNumberOfNodes() const
            {
                return mNodeObserver->GetNumberOfNodes();
            }
            /**
             * @brief Forward to INodeObserver::GetNode() method.
             * @param index The zero based index of the observable node object.
             * @return The observable node object or null if the index is out of range.
             */
            IObservableNodePtr GetNode(UInt32 index) const
            {
                return mNodeObserver->GetNode(index);
            }
            /**
             * @brief Forward to INodeObserver::GetNodeIfValid() method.
             * @param index The zero based index of the observable node object.
             * @return The observable node object or null if the node object is invalid
             *  or the index is out of range.
             */
            IObservableNodePtr GetNodeIfValid(UInt32 index) const
            {
                return mNodeObserver->GetNodeIfValid(index);
            }

            /**
             * @brief Forward to INodeObserver::AreValid() method.
             * @return true if all observed nodes are valid.
             */
            Bool AreValid() const
            {
                return mNodeObserver->AreValid();
            }
            /**
             * @brief Forward to INodeObserver::RemoveAll() method.
             * @return true if successful.
             */
            Bool RemoveAll()
            {
                return mNodeObserver->RemoveAll();
            }

        protected:
            INodeObserverPtr mNodeObserver;
        };
    }
}

#endif  // __MURL_LOGIC_BASE_NODE_OBSERVER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_HANDLE_INSTANCE_H__
#define __MURL_GRAPH_I_HANDLE_INSTANCE_H__

#include "murl_graph_types.h"

namespace Murl
{
    namespace Graph
    {
        class IHandle;
        
        /**
         * @ingroup MurlGraphMiscInterfaces
         * @interface IHandleInstance
         * @brief The IHandleInstance interface.
         * A graph node may obtain a generic handle instance for storing information
         * that is dependent on the actual graph traversal state.
         */
        class IHandleInstance
        {
        public:
            virtual ~IHandleInstance() {}

            /**
             * @brief Get the constant handle owning this handle instance.
             * @return The owner handle.
             */
            virtual const IHandle* GetOwner() const = 0;
            /**
             * @brief Get the mutable handle owning this handle instance.
             * @return The owner handle.
             */
            virtual IHandle* GetOwner() = 0;

            /**
             * @brief Get the constant world transform.
             * @return The world transform.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            /**
             * @brief Get the mutable world transform.
             * @return The world transform.
             */
            virtual Matrix& GetWorldTransform() = 0;
            
        protected:
        };
    }
}

#endif // __MURL_GRAPH_I_HANDLE_INSTANCE_H__

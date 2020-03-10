// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_HANDLE_H__
#define __MURL_GRAPH_I_HANDLE_H__

#include "murl_graph_types.h"

namespace Murl
{
    namespace Graph
    {
        class INode;
        
        /**
         * @ingroup MurlGraphMiscInterfaces
         * @interface IHandle
         * @brief The IHandle interface.
         * A handle can store traversal or reference-dependent information for
         * a graph node.
         */
        class IHandle
        {
        public:
            virtual ~IHandle() {}

            /**
             * @brief Get the constant node owning this handle.
             * @return The owner node.
             */
            virtual const INode* GetOwner() const = 0;
            /**
             * @brief Get the mutable node owning this handle.
             * @return The owner node.
             */
            virtual INode* GetOwner() = 0;
            
        protected:
        };
    }
}

#endif // __MURL_GRAPH_I_HANDLE_H__

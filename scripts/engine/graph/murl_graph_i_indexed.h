// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_INDEXED_H__
#define __MURL_GRAPH_I_INDEXED_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IIndexed
         * @brief The IIndexed property interface.
         * This interface provides a common way to set a generic index for an object.
         * The meaning of the index property is not explicitly defined; nodes may use
         * the given value for e.g. indexing into their children (see Graph::ISwitch),
         * indexing into an atlas resource (see Graph::IPlaneSequenceGeometry) or whatever
         * other purpose suitable.
         *
         * Animation controllers may call the SetIndex() method when index keys are
         * present in a given Resource::IAnimation.
         */
        class IIndexed
        {
        public:
            enum Index
            {
                INDEX_NONE = -1
            };
            
        public:
            /**
             * @brief Set the current index.
             * @param index The signed index to set.
             * @return true if successful.
             */
            virtual Bool SetIndex(SInt32 index) = 0;
            /**
             * @brief Get the current index.
             * @return The current index.
             */
            virtual SInt32 GetIndex() const = 0;
            /**
             * @brief Get the lowest valid index.
             * @return The lowest valid index.
             */
            virtual SInt32 GetFirstIndex() const = 0;
            /**
             * @brief Get the total number of valid indices.
             * @return The total number of indices.
             */
            virtual UInt32 GetNumberOfIndices() const = 0;
            
        protected:
            virtual ~IIndexed() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IIndexed nodes.
         */
        typedef IGenericNodeTarget<IIndexed> IIndexedNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_INDEXED_H__

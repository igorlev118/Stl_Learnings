// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_GENERIC_NODE_TARGET_H__
#define __MURL_GRAPH_GENERIC_NODE_TARGET_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_debug_trace.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphTargetClasses
         * @interface GenericNodeTarget
         * @brief The GenericNodeTarget class.
         * This is the common abstract base class for the engine's NodeTarget and 
         * NodeArrayTarget classes, implementing the IGenericNodeTarget interface.
         */
        template<class ObjectType>
        class GenericNodeTarget : public IGenericNodeTarget<ObjectType>
        {
        public:
            virtual Bool IsInitialized() const
            {
                return (mFlags & FLAG_IS_INITIALIZED) != 0;
            }
            
            virtual Bool IsModified() const
            {
                return (mFlags & FLAG_IS_MODIFIED) != 0;
            }
            
            virtual Bool SetInitialized(Bool initialized)
            {
                if (initialized)
                {
                    mFlags |= FLAG_IS_INITIALIZED;
                }
                else
                {
                    mFlags &= ~FLAG_IS_INITIALIZED;
                }
                return true;
            }
            
            virtual Bool SetModified(Bool modified)
            {
                if (modified)
                {
                    mFlags |= FLAG_IS_MODIFIED;
                }
                else
                {
                    mFlags &= ~FLAG_IS_MODIFIED;
                }
                return true;
            }
            
        protected:
            enum Flags
            {
                FLAG_IS_INITIALIZED = (1 << 0),
                FLAG_IS_MODIFIED    = (1 << 1)
            };
            
            GenericNodeTarget()
            : mFlags(0)
            {
            }
            
            UInt32 mFlags;
        };
    }
}

#endif // __MURL_GRAPH_GENERIC_NODE_TARGET_H__

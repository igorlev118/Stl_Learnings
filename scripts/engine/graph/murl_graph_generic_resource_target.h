// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_GENERIC_RESOURCE_TARGET_H__
#define __MURL_GRAPH_GENERIC_RESOURCE_TARGET_H__

#include "murl_graph_i_generic_resource_target.h"

namespace Murl
{
    namespace Resource
    {
        class ICollection;
    }
    
    namespace Graph
    {
        /**
         * @ingroup MurlGraphTargetClasses
         * @interface GenericResourceTarget
         * @brief The GenericResourceTarget class.
         * This is the common abstract base class for the engine's ResourceTarget and
         * ResourceArrayTarget classes, implementing the IGenericResourceTarget interface.
         */
        template<class ObjectType>
        class GenericResourceTarget : public IGenericResourceTarget<ObjectType>
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
            
            GenericResourceTarget()
            : mFlags(0)
            {
            }

            Bool GetResourceFromCollection(const Resource::ICollection* collection, const String& id, const ObjectType*& object) const;
            
            UInt32 mFlags;
        };
    }
}

#endif // __MURL_GRAPH_GENERIC_RESOURCE_TARGET_H__

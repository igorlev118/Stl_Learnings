// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_GRID_H__
#define __MURL_RESOURCE_I_GRID_H__

#include "murl_resource_types.h"

namespace Murl
{
    class ConstData;
    
    namespace Resource
    {
        class IObject;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IGrid
         * @todo
         */
        class IGrid
        {
        public:
            /**
             * @brief Get the mutable Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

        protected:
            virtual ~IGrid() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_GRID_H__

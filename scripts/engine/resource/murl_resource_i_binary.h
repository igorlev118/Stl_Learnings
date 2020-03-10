// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_BINARY_H__
#define __MURL_RESOURCE_I_BINARY_H__

#include "murl_resource_types.h"

namespace Murl
{
    class ConstData;
    
    namespace Resource
    {
        class IObject;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IBinary
         * @brief The IBinary resource object interface.
         * A binary resource simply stores a raw block of data.
         */
        class IBinary
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

            /**
             * @brief Get a data object containing the raw data.
             * @return A constant data object containing the raw contents.
             */
            virtual const ConstData& GetData() const = 0;
            
        protected:
            virtual ~IBinary() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_BINARY_H__

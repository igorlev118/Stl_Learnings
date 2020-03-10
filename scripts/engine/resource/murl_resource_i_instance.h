// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_INSTANCE_H__
#define __MURL_RESOURCE_I_INSTANCE_H__

#include "murl_types.h"

namespace Murl
{
    namespace Resource
    {
        class IGraph;
        class IScript;

        /**
         * @ingroup MurlResourceMiscInterfaces
         * @interface IInstance
         * @brief The IInstance resource interface.
         * This interface provides methods to query information about any optional graph or script
         * instances that must be created when a package has been successfully loaded.
         */
        class IInstance
        {
        public:
            /**
             * @brief Get the resource ID of the Resource::IGraph to instantiate.
             * @return The resource ID.
             */
            virtual const String& GetResourceId() const = 0;
            /**
             * @brief Get the ID of an existing node in the scene graph where to add the instance.
             * @return The parent node ID.
             */
            virtual const String& GetParentNodeId() const = 0;

            /**
             * @brief Get the desired number of replications.
             * @return The number of replications.
             */
            virtual UInt32 GetNumberOfReplications() const = 0;

        protected:
            virtual ~IInstance() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_INSTANCE_H__

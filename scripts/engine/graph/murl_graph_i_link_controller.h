// Copyright 2010-2017 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LINK_CONTROLLER_H__
#define __MURL_GRAPH_I_LINK_CONTROLLER_H__

#include "murl_graph_i_controller.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface ILinkController
         * @brief The ILinkController interface.
         */
        class ILinkController
        {
        public:
            /**
             * @brief Get the mutable IController interface.
             * @return The mutable IController interface.
             */
            virtual IController* GetControllerInterface() = 0;
            /**
             * @brief Get the constant IController interface.
             * @return The constant IController interface.
             */
            virtual const IController* GetControllerInterface() const = 0;
            
        protected:
            virtual ~ILinkController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_LINK_CONTROLLER_H__

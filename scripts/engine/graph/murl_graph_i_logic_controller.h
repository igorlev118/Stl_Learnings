// Copyright 2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LOGIC_CONTROLLER_H__
#define __MURL_GRAPH_I_LOGIC_CONTROLLER_H__

#include "murl_logic_types.h"

namespace Murl
{
    namespace Graph
    {
        class IController;

        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface ILogicController
         * @brief The ILogicController interface.
         *
         * See Graph::Node for details on creating controllers via an XML scene graph description.
         */
        class ILogicController
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

            /**
             * @brief Set the logic graph callback object.
             * @param logicAppGraph The logic graph callback object.
             * @return true if successful.
             */
            virtual Bool SetLogicAppGraph(Logic::IAppGraphPtr logicAppGraph) = 0;

            /**
             * @brief Get the logic graph callback object.
             * @return logicAppGraph The logic graph callback object.
             */
            virtual Logic::IAppGraphPtr GetLogicAppGraph() = 0;

        protected:
            virtual ~ILogicController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_LOGCI_CONTROLLER_H__

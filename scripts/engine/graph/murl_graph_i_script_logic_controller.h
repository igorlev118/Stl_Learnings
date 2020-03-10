// Copyright 2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SCRIPT_LOGIC_CONTROLLER_H__
#define __MURL_GRAPH_I_SCRIPT_LOGIC_CONTROLLER_H__

#include "murl_graph_i_logic_controller.h"
#include "murl_graph_i_generic_resource_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface IScriptLogicController
         * @brief The IScriptLogicController interface.
         *
         * See Graph::Node for details on creating controllers via an XML scene graph description.
         */
        class IScriptLogicController
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
             * @brief Get the mutable ILogicController interface.
             * @return The mutable ILogicController interface.
             */
            virtual ILogicController* GetLogicControllerInterface() = 0;
            /**
             * @brief Get the constant ILogicController interface.
             * @return The constant ILogicController interface.
             */
            virtual const ILogicController* GetLogicControllerInterface() const = 0;

            /**
             * @brief Get a mutable Graph::IScriptResourceTarget container.
             * This method returns a mutable pointer to a Graph::IScriptResourceTarget
             * container, which allows to add, remove or query the script resource referenced.
             * @return The mutable Graph::IScriptResourceTarget container.
             */
            virtual IScriptResourceTarget* GetScriptResourceTarget() = 0;

            /**
             * @brief Get a constant Graph::IScriptResourceTarget container.
             * This method returns a constant pointer to a Graph::IScriptResourceTarget
             * container, which allows to query the script resource referenced.
             * @return The constant Graph::IScriptResourceTarget container.
             */
            virtual const IScriptResourceTarget* GetScriptResourceTarget() const = 0;

        protected:
            virtual ~IScriptLogicController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_SCRIPT_LOGIC_CONTROLLER_H__

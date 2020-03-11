// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_UNIFORM_TIME_CONTROLLER_H__
#define __MURL_GRAPH_I_UNIFORM_TIME_CONTROLLER_H__

#include "murl_graph_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IController;
        class ITimeController;

        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface IUniformTimeController
         * @brief The IUniformTimeController interface.
         * This interface provides a specialized Graph::ITimeController to manipulate individual
         * Graph::IGenericParameter nodes.
         */
        class IUniformTimeController
        {
        public:
            /**
             * @brief Get the mutable IController interface.
             * @return The mutable IController interface.
             */
            virtual IController* GetControllerInterface() = 0;
            /**
             * @brief Get the constant IController interface.
             * @return The constant  IController interface.
             */
            virtual const IController* GetControllerInterface() const = 0;

            /**
             * @brief Get the mutable ITimeController interface.
             * @return The mutable ITimeController interface.
             */
            virtual ITimeController* GetTimeControllerInterface() = 0;
            /**
             * @brief Get the constant ITimeController interface.
             * @return The constant ITimeController interface.
             */
            virtual const ITimeController* GetTimeControllerInterface() const = 0;

        protected:
            virtual ~IUniformTimeController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_UNIFORM_TIME_CONTROLLER_H__

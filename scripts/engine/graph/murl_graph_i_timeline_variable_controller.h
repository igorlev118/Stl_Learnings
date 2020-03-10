// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TIMELINE_VARIABLE_CONTROLLER_H__
#define __MURL_GRAPH_I_TIMELINE_VARIABLE_CONTROLLER_H__

#include "murl_graph_i_variable_controller.h"
#include "murl_graph_i_variable.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface ITimelineVariableController
         * @brief The ITimelineVariableController interface.
         * A timeline variable controller can be attached to any node implementing the
         * Graph::ITimeline interface. It is used to control the timeline's time scale
         * and/or blend factor properties.
         */
        class ITimelineVariableController
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
             * @brief Get the mutable IVariableController interface.
             * @return The mutable IVariableController interface.
             */
            virtual IVariableController* GetVariableControllerInterface() = 0;
            /**
             * @brief Get the constant IVariableController interface.
             * @return The constant IVariableController interface.
             */
            virtual const IVariableController* GetVariableControllerInterface() const = 0;

            /**
             * @brief Get the mutable Graph::IVariableNodeTarget container for controlling the time scale.
             * This method returns a mutable pointer to the node's Graph::IVariableNodeTarget
             * container that allows to set or query the variable node used to control the timeline's
             * time scale property.
             * @return The mutable Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual IVariableNodeTarget* GetTimeScaleVariableNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IVariableNodeTarget container for controlling the time scale.
             * This method returns a constant pointer to the node's Graph::IVariableNodeTarget
             * container that allows to query the variable node used to control the timeline's
             * time scale property.
             * @return The constant Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual const IVariableNodeTarget* GetTimeScaleVariableNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::IVariableNodeTarget container for controlling the blend factor.
             * This method returns a mutable pointer to the node's Graph::IVariableNodeTarget
             * container that allows to set or query the variable node used to control the timeline's
             * blend factor property.
             * @return The mutable Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual IVariableNodeTarget* GetBlendFactorVariableNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IVariableNodeTarget container for controlling the blend factor.
             * This method returns a constant pointer to the node's Graph::IVariableNodeTarget
             * container that allows to query the variable node used to control the timeline's
             * blend factor property.
             * @return The constant Graph::IVariableNodeTarget container, or null if not available.
             */
            virtual const IVariableNodeTarget* GetBlendFactorVariableNodeTarget() const = 0;

        protected:
            virtual ~ITimelineVariableController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TIMELINE_VARIABLE_CONTROLLER_H__

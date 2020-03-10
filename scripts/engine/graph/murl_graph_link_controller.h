// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_LINK_CONTROLLER_H__
#define __MURL_GRAPH_LINK_CONTROLLER_H__

#include "murl_graph_controller.h"
#include "murl_graph_i_link_controller.h"
#include "murl_i_attributes.h"
#include "murl_array.h"
#include "murl_string.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphControllerClasses
         * @brief The abstract base class of all scene graph node controllers that link to a given source node.
         */
        class LinkController : public Controller, public ILinkController
        {
            MURL_FACTORY_OBJECT_ABSTRACT_DERIVED_CLASS(Murl::Graph::LinkController, Murl::Graph::Controller)
            
        public:
            virtual IController* GetControllerInterface();
            virtual const IController* GetControllerInterface() const;

            virtual Bool DeserializeAttribute(IDeserializeAttributeTracker* tracker);
            
            virtual Bool PreInit(IInitTracker* tracker);
            virtual Bool PostInit(IInitTracker* tracker);

            virtual Bool PreDeInit(IDeInitTracker* tracker);
            virtual Bool PostDeInit(IDeInitTracker* tracker);

            virtual Bool PreConfigChangedLogic(IConfigChangedTracker* tracker);
            virtual Bool PostConfigChangedLogic(IConfigChangedTracker* tracker);

            virtual Bool PreProcessLogic(IProcessLogicTracker* tracker);
            virtual Bool PostProcessLogic(IProcessLogicTracker* tracker);

        protected:
            LinkController(const IFactory* factory, INode* owner);
            virtual ~LinkController();
            
            virtual Bool DeserializeBaseAttribute(IDeserializeAttributeTracker* tracker);
            virtual Bool DeserializeChildAttribute(IDeserializeAttributeTracker* tracker);
        };
    }
}

#endif // __MURL_GRAPH_LINK_CONTROLLER_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_CONTROLLER_H__
#define __MURL_GRAPH_CONTROLLER_H__

#include "murl_graph_i_controller.h"
#include "murl_graph_tracker_result.h"
#include "murl_graph_property.h"
#include "murl_i_attributes.h"
#include "murl_array.h"
#include "murl_string.h"

namespace Murl
{
    namespace Graph
    {
        class INode;

        /**
         * @ingroup MurlGraphControllerClasses
         * @brief The base class of all scene graph node controllers.
         * This class represents the internal base class of all different controllers that are
         * implemented in the framework's core library. Custom controllers may derive from this
         * class, make use of the default method implementations, and override any of these
         * methods if desired.
         */
        class Controller : public IController
        {
            MURL_FACTORY_OBJECT_ABSTRACT_BASE_CLASS(Murl::Graph::Controller)
            
        public:
            virtual IController* GetControllerInterface();
            virtual const IController* GetControllerInterface() const;

            virtual Bool SetOwner(INode* owner);
            virtual INode* GetOwner() const;

            virtual Bool PreInit(IInitTracker* tracker);
            virtual Bool PostInit(IInitTracker* tracker);

            virtual Bool PreDeInit(IDeInitTracker* tracker);
            virtual Bool PostDeInit(IDeInitTracker* tracker);

            virtual Bool PreConfigChangedLogic(IConfigChangedTracker* tracker);
            virtual Bool PostConfigChangedLogic(IConfigChangedTracker* tracker);

            virtual Bool PreConfigChangedOutput(IConfigChangedTracker* tracker);
            virtual Bool PostConfigChangedOutput(IConfigChangedTracker* tracker);

            virtual Bool PreProcessLogic(IProcessLogicTracker* tracker);
            virtual Bool PostProcessLogic(IProcessLogicTracker* tracker);

            virtual Bool PreProcessInput(IProcessInputTracker* tracker);
            virtual Bool PostProcessInput(IProcessInputTracker* tracker);

            virtual Bool PreProcessOutput(IProcessOutputTracker* tracker);
            virtual Bool PostProcessOutput(IProcessOutputTracker* tracker);

            virtual Bool SetInitialized(Bool isInitialized);
            virtual Bool IsInitialized() const;

            virtual UInt32 GetConfigChangedResponse() const;
            virtual UInt32 GetProcessLogicResponse() const;
            virtual UInt32 GetProcessInputResponse() const;
            virtual UInt32 GetProcessOutputResponse() const;

        protected:
            Controller(const IFactory* factory, INode* owner);
            virtual ~Controller();

            virtual Bool UpdateOwner();
            
            INode* mOwner;
            Bool mIsInitialized;

            UInt32 mConfigChangedResponse;
            UInt32 mProcessLogicResponse;
            UInt32 mProcessInputResponse;
            UInt32 mProcessOutputResponse;

            static NullProperty sNullProperty;

        private:
            const IFactory* mFactory;
            
            friend class Factory;
        };
    }
}

#endif // __MURL_GRAPH_CONTROLLER_H__

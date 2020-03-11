// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONTROLLER_H__
#define __MURL_GRAPH_I_CONTROLLER_H__

#include "murl_i_factory_object.h"

namespace Murl
{
    class IAttributes;
    
    namespace Graph
    {
        class IController;
        class IFactory;
        class INode;
        class IInitTracker;
        class IDeInitTracker;
        class IConfigChangedTracker;
        class IProcessLogicTracker;
        class IProcessInputTracker;
        class IProcessOutputTracker;
        class IDeserializeAttributeTracker;

        typedef Array<IController*> IControllerArray;
        
        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface IController
         * @brief The IController interface.
         * This interface provides a generic way to automatically manipulate individual properties
         * of a given Graph::INode. A class implementing this interface may modify a node's properties 
         * by overriding the ProcessLogic() method.
         *
         * The Graph::ITimeController interface represents a more specialized controller type, which
         * acts on current animation time values of individual Graph::ITimeline nodes.
         *
         * See Graph::Node for details on creating controllers via an XML scene graph description.
         */
        class IController : public IFactoryObject<IController>
        {
        public:
            typedef IController* (*CreateFunction)(const IFactory* factory, INode* owner);
            
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
             * @brief Deserialize a single controller attribute.
             * See Graph::INode::DeserializeAttribute().
             * @param tracker The tracker used.
             * @return true if the given attribute was recognized.
             */
            virtual Bool DeserializeAttribute(IDeserializeAttributeTracker* tracker) = 0;

            /**
             * @brief Set the controller's owning (controlled) node.
             * Setting the owner is only allowed when the controller is not yet initialized.
             * @param owner The owner.
             * @return true if successful.
             */
            virtual Bool SetOwner(INode* owner) = 0;
            /**
             * @brief Get the controller's owning (controlled) node.
             * @return The owner.
             */
            virtual INode* GetOwner() const = 0;

            /**
             * @brief Perform initializaton before the node and its children are being initialized.
             * This method is invoked prior to a call to InitSelf() on the controlled node. It is used to 
             * perform any work necessary before the node or its children are being processed.
             * @param tracker The tracker used for initialization.
             * @return true if successful.
             */
            virtual Bool PreInit(IInitTracker* tracker) = 0;
            /**
             * @brief Perform initializaton after the node and its children have been initialized.
             * This method is invoked after InitChildren() of the controlled node has been called.
             * It is used to perform any work necessary after the node's children have been 
             * processed.
             * @param tracker The tracker used for initialization.
             * @return true if successful.
             */
            virtual Bool PostInit(IInitTracker* tracker) = 0;

            /**
             * @brief Perform de-initializaton step before the node and its children are being de-initialized.
             * This method is invoked before DeInitChildren() of the controlled node is called.
             * It is used to perform any work necessary before the node's sub-graph is processed.
             * @param tracker The tracker used for de-initialization.
             * @return true if successful.
             */
            virtual Bool PreDeInit(IDeInitTracker* tracker) = 0;
            /**
             * @brief Perform de-initializaton step after the node and its children have been de-initialized.
             * This method is invoked after DeInitSelf() of the controlled node is called.
             * It is used to perform any work necessary after the node's sub-graph is processed.
             * @param tracker The tracker used for de-initialization.
             * @return true if successful.
             */
            virtual Bool PostDeInit(IDeInitTracker* tracker) = 0;

            /**
             * @brief Signal a configuration change, before the node is being processed.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool PreConfigChangedLogic(IConfigChangedTracker* tracker) = 0;
            /**
             * @brief Signal a configuration change, after the node's children have been processed.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool PostConfigChangedLogic(IConfigChangedTracker* tracker) = 0;

            /**
             * @brief Signal a configuration change, before the node is being processed.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool PreConfigChangedOutput(IConfigChangedTracker* tracker) = 0;
            /**
             * @brief Signal a configuration change, after the node's children have been processed.
             * @param tracker The tracker used.
             * @return true if successful.
             */
            virtual Bool PostConfigChangedOutput(IConfigChangedTracker* tracker) = 0;

            /**
             * @brief Perform a logic traversal, before the node is being processed.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool PreProcessLogic(IProcessLogicTracker* tracker) = 0;
            /**
             * @brief Perform a logic traversal, after the node's children have been processed.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool PostProcessLogic(IProcessLogicTracker* tracker) = 0;

            /**
             * @brief Perform an input traversal, before the node is being processed.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool PreProcessInput(IProcessInputTracker* tracker) = 0;
            /**
             * @brief Perform an input traversal, after the node's children have been processed.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool PostProcessInput(IProcessInputTracker* tracker) = 0;

            /**
             * @brief Perform an output traversal, before the node is being processed.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool PreProcessOutput(IProcessOutputTracker* tracker) = 0;
            /**
             * @brief Perform an output traversal, after the node's children have been processed.
             * @param tracker The tracker used for traversal.
             * @return true if successful.
             */
            virtual Bool PostProcessOutput(IProcessOutputTracker* tracker) = 0;

            /**
             * @brief Set/reset the initialized state of the controller.
             * @param isInitialized If true, the controller is set to the initialized state.
             * @return true if successful.
             */
            virtual Bool SetInitialized(Bool isInitialized) = 0;
            /**
             * @brief Check if this controller is initialized.
             * @return true if initialized.
             */
            virtual Bool IsInitialized() const = 0;

            /**
             * @brief Get the controller's active response for config change traversal.
             * @return A bit mask of traversal triggers this controller will respond to, from the
             *  INode::ConfigChangedTriggers enumeration.
             */
            virtual UInt32 GetConfigChangedResponse() const = 0;
            /**
             * @brief Get the controller's active response for logic traversal.
             * @return A bit mask of traversal triggers this controller will respond to, from the
             *  INode::ProcessLogicTriggers enumeration.
             */
            virtual UInt32 GetProcessLogicResponse() const = 0;
            /**
             * @brief Get the controller's active response for input traversal.
             * @return A bit mask of traversal triggers this controller will respond to, from the
             *  INode::ProcessInputTriggers enumeration.
             */
            virtual UInt32 GetProcessInputResponse() const = 0;
            /**
             * @brief Get the controller's active response for output traversal.
             * @return A bit mask of traversal triggers this controller will respond to, from the
             *  INode::ProcessOutputTriggers enumeration.
             */
            virtual UInt32 GetProcessOutputResponse() const = 0;

        protected:
            virtual ~IController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CONTROLLER_H__

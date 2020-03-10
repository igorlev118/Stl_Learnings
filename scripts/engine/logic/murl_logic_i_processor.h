// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_PROCESSOR_H__
#define __MURL_LOGIC_I_PROCESSOR_H__

#include "murl_logic_i_engine_processor.h"
#include "murl_logic_i_app_processor.h"
#include "murl_logic_i_node_observer.h"
#include "murl_logic_i_stepable_observer.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IProcessor
         * @brief The IProcessor interface.
         * The IProcessor implements the IEngineProcessor interface including:
         *  - IAppProcessor callbacks.
         *  - Child processing of IProcessor objects.
         *  - A IStepableObserver object.
         *  - A INodeObserver object.
         *
         * The following is performed on the IEngineProcessor interface:
         *  - Init() Execute IStepableObserver::Reset(), IAppProcessor::OnInit(),
         *      INodeObserver::AreValid() and IEngineProcessor::Init() for all children.
         *  - DeInit() Execute IAppProcessor::OnDeInit(), INodeObserver::RemoveAll(),
         *      IStepableObserver::RemoveAll() and IEngineProcessor::DeInit() for all children.
         *  - ProcessTick() Execute IStepableObserver::ProcessTick(), IAppProcessor::OnProcessTick(),
         *      IEngineProcessor::ProcessTick() for all children and IAppProcessor::OnProcessTickChildren().
         *  - ProcessFrame() Execute IAppProcessor::OnProcessFrame(), IEngineProcessor::ProcessFrame()
         *      for all children and IAppProcessor::OnProcessFrameChildren().
         *  - PackageWillBeLoaded() Execute IAppProcessor::OnPackageWillBeLoaded() and
         *      IEngineProcessor::PackageWillBeLoaded() for all children.
         *  - PackageWasLoaded() Execute IAppProcessor::OnPackageWasLoaded() and
         *      IEngineProcessor::PackageWasLoaded() for all children.
         *  - PackageFailedLoading() Execute IAppProcessor::OnPackageFailedLoading() and
         *      IEngineProcessor::PackageFailedLoading() for all children.
         *  - PackageWillBeUnloaded() Execute IAppProcessor::OnPackageWillBeUnloaded() and
         *      IEngineProcessor::PackageWillBeUnloaded() for all children.
         *  - PackageWasUnloaded() Execute IAppProcessor::OnPackageWasUnloaded() and
         *      IEngineProcessor::PackageWasUnloaded() for all children.
         *  - PackageFailedUnloading() Execute IAppProcessor::OnPackageFailedUnloading() and
         *      IEngineProcessor::PackageFailedUnloading() for all children.
         *  - RunStateChanged() Execute IAppProcessor::OnRunStateChanged() and
         *      IEngineProcessor::RunStateChanged() for all children.
         */
        class IProcessor : public IEngineProcessor
        {
        public:
            /**
             * @brief Set the processor callback object.
             * @param appProcessor The processor callback object.
             * @return true if successful.
             */
            virtual Bool SetAppProcessor(IAppProcessorPtr appProcessor) = 0;

            /**
             * @brief Check if the processor is initialized.
             * IsInitialized() is typically the opposite of IsDeInitialized(), except
             * if initialization fails. In this situation the processor is not initialized
             * and not deinitialized, which means if the initialization fails, the
             * deinitialization sequence is performed to clean-up the unfinished
             * initialization process.
             * @return true if the processor is initialized.
             */
            virtual Bool IsInitialized() const = 0;
            /**
             * @brief Check if the processor is deinitialized.
             * IsDeInitialized() is typically the opposite of IsInitialized(), except
             * if initialization fails. In this situation the processor is not initialized
             * and not deinitialized, which means if the initialization fails, the
             * deinitialization sequence is performed to clean-up the unfinished
             * initialization process.
             * @return true if the processor is deinitialized.
             */
            virtual Bool IsDeInitialized() const = 0;

            /**
             * @brief Set the Enable/Disable state of the processor.
             * A disabled processor skips the IAppProcessor::OnProcessTick(),
             * IAppProcessor::OnProcessFrame(), IStepableObserver::ProcessTick() callback.
             *\n
             * SetEnabled performs the following:
             *  - Execute the IStepableObserver::SetEnabled().
             *  - Execute the IAppProcessor::OnSetEnabled() callback method.
             *  - Set the internal enabled state.
             *\n
             * The default enabled state is true.
             * @param isEnabled true for enable, false for disable.
             */
            virtual void SetEnabled(Bool isEnabled) = 0;
            /**
             * @brief Set the Enable/Disable state for all child processors.
             * Call SetEnabled() for all child processors.
             * @param isEnabled true for enable, false for disable.
             */
            virtual void SetChildrenEnabled(Bool isEnabled) = 0;
            /**
             * @brief Check if the processor is enabled.
             * @return true if enabled.
             */
            virtual Bool IsEnabled() const = 0;

            /**
             * @brief Add a child processor.
             * Add a given processor as the next child of the current processor.
             * @param processor The processor object to add.
             * @return true if successful.
             */
            virtual Bool AddChild(IProcessorPtr processor) = 0;
            /**
             * @brief Remove a child processor.
             * Remove the first instance of a given processor node
             * from this processor's children.
             * @param processor The processor object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveChild(IProcessorPtr processor) = 0;

            /**
             * @brief Initialize and add a child processor.
             * Execute Init() of a given processor and add the given processor
             * as the next child of the current processor.
             * This method is used for adding processors after initialization
             * of the current processor.
             * @param state The IState object.
             * @param processor The processor object to initialize and add.
             * @return true if successful.
             */
            virtual Bool InitAddChild(const IState* state, IProcessorPtr processor) = 0;
            /**
             * @brief Remove and deinitialize a child processor.
             * Remove the first instance of a given processor node from this
             * processor's children and execute DeInit() of the given processor.
             * This method is used for removing processors before deinitialization
             * of the current processor.
             * @param state The IState object.
             * @param processor The processor object to remove and deinitialize.
             * @return true if successful.
             */
            virtual Bool RemoveDeInitChild(const IState* state, IProcessorPtr processor) = 0;

            /**
             * @brief Get the number of childen.
             * @return The number of children.
             */
            virtual UInt32 GetNumberOfChildren() const = 0;
            /**
             * @brief Get a child processor by index.
             * A valid index is [0 .. GetNumberOfChildren() - 1].
             * @param index The zero-based index of the child processor.
             * @return The child processor object or null if the index is out of range.
             */
            virtual IProcessorPtr GetChild(UInt32 index) const = 0;

            /**
             * @brief Add a stepable object to the processor's stepable observer.
             * See IStepableObserver::Add().
             * @param stepable The stepable object to add.
             * @return true if successful.
             */
            virtual Bool AddStepable(IStepablePtr stepable) = 0;
            /**
             * @brief Remove a stepable object from the processor's stepable observer.
             * See IStepableObserver::Remove().
             * @param stepable The stepable object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveStepable(IStepablePtr stepable) = 0;
            /**
             * @brief Get the processor's stepable observer object.
             * @return The processor's IStepableObserver object.
             */
            virtual IStepableObserverPtr GetStepableObserver() const = 0;

            /**
             * @brief Add a observable node object to the processor's node observer.
             * See INodeObserver::Add().
             * @param observableNode The observable node object to add.
             * @return true if successful.
             */
            virtual Bool AddGraphNode(IObservableNodePtr observableNode) = 0;
            /**
             * @brief Remove a observable node object from the processor's node observer.
             * See INodeObserver::Remove().
             * @param observableNode The observable node object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveGraphNode(IObservableNodePtr observableNode) = 0;
            /**
             * @brief Check if all observed nodes are valid.
             * See INodeObserver::AreValid().
             * @return true if all observed nodes are valid.
             */
            virtual Bool AreGraphNodesValid() const = 0;

            /**
             * @brief Get the processor's node observer object.
             * @return The processor's INodeObserver object.
             */
            virtual INodeObserverPtr GetNodeObserver() const = 0;

        protected:
            virtual ~IProcessor() {}
        };
    }
}

#endif // __MURL_LOGIC_I_PROCESSOR_H__

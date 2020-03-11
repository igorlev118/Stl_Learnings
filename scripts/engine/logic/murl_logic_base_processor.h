// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_LOGIC_BASE_PROCESSOR_H__
#define __MURL_LOGIC_BASE_PROCESSOR_H__

#include "murl_logic_i_processor.h"

#include "murl_logic_animation.h"
#include "murl_logic_base_timeframe.h"
#include "murl_logic_base_timeline.h"
#include "murl_logic_state_machine.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the IProcessor object.
         * The BaseProcessor class implements the IAppProcessor app interface.\n
         * A processor is created and initialized at object instantiation.
         */
        class BaseProcessor : public IAppProcessor, NonCopyable
        {
        public:
            /**
             * @brief The constructor.
             * Creates a IProcessor object and setup the processor app interface.
             * @param factory The logic factory object.
             */
            BaseProcessor(IFactory* factory)
            : mProcessor(factory->CreateProcessor())
            {
                mProcessor->SetAppProcessor(IAppProcessorPtr(this, NoDeleter()));
            }

            /**
             * @brief The destructor.
             * Destroys the IProcessor object.
             */
            virtual ~BaseProcessor()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The IProcessor interface.
             */
            operator IProcessorPtr() const
            {
                return mProcessor;
            }

            /**
             * @brief Get the processor interface.
             * @return The IProcessor interface.
             */
            IProcessorPtr GetProcessor() const
            {
                return mProcessor;
            }

        public: // IProcessor

            /**
             * @brief Forward to IProcessor::SetAppProcessor() method.
             * @param appProcessor The processor callback object.
             * @return true if successful.
             */
            Bool SetAppProcessor(IAppProcessorPtr appProcessor)
            {
                return mProcessor->SetAppProcessor(appProcessor);
            }

            /**
             * @brief Forward to IProcessor::IsInitialized() method.
             * @return true if the processor is initialized.
             */
            Bool IsInitialized() const
            {
                return mProcessor->IsInitialized();
            }

            /**
             * @brief Forward to IProcessor::SetEnabled() method.
             * @param isEnabled true for enable, false for disable.
             */
            void SetEnabled(Bool isEnabled)
            {
                mProcessor->SetEnabled(isEnabled);
            }
            /**
             * @brief Forward to IProcessor::IsEnabled() method.
             * @return true if enabled.
             */
            Bool IsEnabled() const
            {
                return mProcessor->IsEnabled();
            }

            /**
             * @brief Forward to IProcessor::AddChild() method.
             * @param processor The processor object to add.
             * @return true if successful.
             */
            Bool AddChild(IProcessorPtr processor)
            {
                return mProcessor->AddChild(processor);
            }
            /**
             * @brief Forward to IProcessor::RemoveChild() method.
             * @param processor The processor object to remove.
             * @return true if successful.
             */
            Bool RemoveChild(IProcessorPtr processor)
            {
                return mProcessor->RemoveChild(processor);
            }

            /**
             * @brief Forward to IProcessor::InitAddChild() method.
             * @param state The IState object.
             * @param processor The processor object to initialize and add.
             * @return true if successful.
             */
            Bool InitAddChild(const IState* state, IProcessorPtr processor)
            {
                return mProcessor->InitAddChild(state, processor);
            }
            /**
             * @brief Forward to IProcessor::RemoveDeInitChild() method.
             * @param state The IState object.
             * @param processor The processor object to remove and deinitialize.
             * @return true if successful.
             */
            Bool RemoveDeInitChild(const IState* state, IProcessorPtr processor)
            {
                return mProcessor->RemoveDeInitChild(state, processor);
            }

            /**
             * @brief Forward to IProcessor::GetNumberOfChildren() method.
             * @return The number of children.
             */
            UInt32 GetNumberOfChildren() const
            {
                return mProcessor->GetNumberOfChildren();
            }
            /**
             * @brief Forward to IProcessor::GetChild() method.
             * @param index The zero-based index of the child processor.
             * @return The child processor object or null if the index is out of range.
             */
            IProcessorPtr GetChild(UInt32 index) const
            {
                return mProcessor->GetChild(index);
            }

            /**
             * @brief Forward to IProcessor::AddStepable() method.
             * @param stepable The stepable object to add.
             * @return true if successful.
             */
            Bool AddStepable(IStepablePtr stepable)
            {
                return mProcessor->AddStepable(stepable);
            }
            /**
             * @brief Forward to IProcessor::RemoveStepable() method.
             * @param stepable The stepable object to remove.
             * @return true if successful.
             */
            Bool RemoveStepable(IStepablePtr stepable)
            {
                return mProcessor->RemoveStepable(stepable);
            }
            /**
             * @brief Forward to IProcessor::GetStepableObserver() method.
             * @return The processor's IStepableObserver object.
             */
            Logic::IStepableObserverPtr GetStepableObserver() const
            {
                return mProcessor->GetStepableObserver();
            }

            /**
             * @brief Forward to IProcessor::AddGraphNode() method.
             * @param observableNode The observable node object to add.
             * @return true if successful.
             */
            Bool AddGraphNode(IObservableNodePtr observableNode)
            {
                return mProcessor->AddGraphNode(observableNode);
            }
            /**
             * @brief Forward to IProcessor::RemoveGraphNode() method.
             * @param observableNode The observable node object to remove.
             * @return true if successful.
             */
            Bool RemoveGraphNode(IObservableNodePtr observableNode)
            {
                return mProcessor->RemoveGraphNode(observableNode);
            }
            /**
             * @brief Forward to IProcessor::AreGraphNodesValid() method.
             * @return true if all observed nodes are valid.
             */
            Bool AreGraphNodesValid() const
            {
                return mProcessor->AreGraphNodesValid();
            }

            /**
             * @brief Forward to IProcessor::GetNodeObserver() method.
             * @return The processor's INodeObserver object.
             */
            INodeObserverPtr GetNodeObserverPtr() const
            {
                return mProcessor->GetNodeObserver();
            }

            /**
             * @brief Get the processor's node observer interface pointer.
             * @return The processor's INodeObserver interface pointer.
             */
            INodeObserver* GetNodeObserver() const
            {
                return mProcessor->GetNodeObserver().Get();
            }

        protected:  // IAppProcessor

            /**
             * @brief Default implementation of IAppProcessor::OnInit() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnInit(const Logic::IState* state)
            {
                return true;
            }
            /**
             * @brief Default implementation of IAppProcessor::OnDeInit() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any deinitialization failed.
             */
            virtual Bool OnDeInit(const Logic::IState* state)
            {
                return true;
            }

            /**
             * @brief Default implementation of IAppProcessor::OnProcessTick() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnProcessTick(const Logic::IState* state)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnProcessTickChildren() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnProcessTickChildren(const Logic::IState* state)
            {
            }

            /**
             * @brief Default implementation of IAppProcessor::OnProcessFrame() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnProcessFrame(const Logic::IState* state)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnProcessFrameChildren() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnProcessFrameChildren(const Logic::IState* state)
            {
            }

            /**
             * @brief Default implementation of IAppProcessor::OnFinishTick() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnFinishTick(const Logic::IState* state)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnFinishTickChildren() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnFinishTickChildren(const Logic::IState* state)
            {
            }

            /**
             * @brief Default implementation of IAppProcessor::OnFinishFrame() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnFinishFrame(const Logic::IState* state)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnFinishFrameChildren() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             */
            virtual void OnFinishFrameChildren(const Logic::IState* state)
            {
            }

            /**
             * @brief Default implementation of IAppProcessor::OnPackageWillBeLoaded() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWillBeLoaded(const Logic::IState* state, IPackage* package)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnPackageWasLoaded() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWasLoaded(const Logic::IState* state, IPackage* package)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnPackageFailedLoading() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageFailedLoading(const Logic::IState* state, IPackage* package)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnPackageWillBeUnloaded() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWillBeUnloaded(const Logic::IState* state, IPackage* package)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnPackageWasUnloaded() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWasUnloaded(const Logic::IState* state, IPackage* package)
            {
            }
            /**
             * @brief Default implementation of IAppProcessor::OnPackageFailedUnloading() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageFailedUnloading(const Logic::IState* state, IPackage* package)
            {
            }

            /**
             * @brief Default implementation of IAppProcessor::OnRunStateChanged() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param currentState The current run state.
             * @param previousState The previous run state.
             */
            virtual void OnRunStateChanged(const Logic::IState* state, IEnums::AppRunState currentState,
                                           IEnums::AppRunState previousState)
            {
            }

            /**
             * @brief Default implementation of IAppProcessor::OnSetEnabled() method,
             * this method is empty and can be overwritten.
             * @param isEnabled true if enabled.
             */
            virtual void OnSetEnabled(Bool isEnabled)
            {
            }

        protected:  // used by derived classes
            BaseProcessor()
            {
            }

            virtual void SetupProcessor(IProcessorPtr processor)
            {
                mProcessor = processor;
                if (!mProcessor.IsNull())
                {
                    mProcessor->SetAppProcessor(IAppProcessorPtr(this, NoDeleter()));
                }
            }

            IProcessorPtr mProcessor;
        };
    }
}

#endif  // __MURL_LOGIC_BASE_PROCESSOR_H__

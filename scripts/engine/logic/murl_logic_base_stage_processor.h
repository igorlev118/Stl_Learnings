// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_BASE_STAGE_PROCESSOR_H__
#define __MURL_LOGIC_BASE_STAGE_PROCESSOR_H__

#include "murl_logic_base_processor.h"
#include "murl_logic_i_stage_processor.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the IStageProcessor object.
         * The BaseStageProcessor class implements a BaseProcessor.\n
         * A stage processor is created and initialized at object instantiation.
         */
        class BaseStageProcessor : public BaseProcessor
        {
        public:
            /**
             * @brief The constructor.
             * Creates a IStageProcessor object.
             * @param factory The logic factory object.
             */
            BaseStageProcessor(IFactory* factory)
            : mStageProcessor(factory->CreateStageProcessor())
            {
                SetupProcessor(mStageProcessor->GetProcessor());
            }

            /**
             * @brief The destructor.
             * Destroys the IStageProcessor object.
             */
            virtual ~BaseStageProcessor()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The IStageProcessor interface.
             */
            operator IStageProcessorPtr() const
            {
                return mStageProcessor;
            }

            /**
             * @brief Get the stage processor interface.
             * @return The IStageProcessor interface.
             */
            IStageProcessorPtr GetStageProcessor() const
            {
                return mStageProcessor;
            }

        public: // IStageProcessor

            /**
             * @brief Forward to IStageProcessor::AddStage() method.
             * @param stage The stage object to add.
             * @return true if successful.
             */
            Bool AddStage(IStagePtr stage)
            {
                return mStageProcessor->AddStage(stage);
            }
            /**
             * @brief Forward to IStageProcessor::RemoveStage() method.
             * @param stage The stage object to remove.
             * @return true if successful.
             */
            Bool RemoveStage(IStagePtr stage)
            {
                return mStageProcessor->RemoveStage(stage);
            }

            /**
             * @brief Forward to IStageProcessor::InitAddStage() method.
             * @param state The IState object.
             * @param stage The stage object to initialize and add.
             * @return true if successful.
             */
            Bool InitAddStage(const IState* state, IStagePtr stage)
            {
                return mStageProcessor->InitAddStage(state, stage);
            }
            /**
             * @brief Forward to IStageProcessor::RemoveDeInitStage() method.
             * @param state The IState object.
             * @param stage The stage object to deinitialize and remove.
             * @return true if successful.
             */
            Bool RemoveDeInitStage(const IState* state, IStagePtr stage)
            {
                return mStageProcessor->RemoveDeInitStage(state, stage);
            }

            /**
             * @brief Forward to IStageProcessor::SetSwitchNodeId() method.
             * @param switchNodeId The full path to the graph &lt;Switch&gt; instance.
             * @return true if successful.
             */
            void SetSwitchNodeId(const String& switchNodeId)
            {
                mStageProcessor->SetSwitchNodeId(switchNodeId);
            }
            /**
             * @brief Forward to IStageProcessor::GetSwitchNodeId() method.
             * @return The switch node identifier string including the full path.
             */
            const String& GetSwitchNodeId() const
            {
                return mStageProcessor->GetSwitchNodeId();
            }

            /**
             * @brief Forward to IStageProcessor::GetStage() method.
             * @param stageId The identifier of the stage to get.
             * @return The stage object or null if the identifier is not found.
             */
            IStagePtr GetStage(const String& stageId) const
            {
                return mStageProcessor->GetStage(stageId);
            }

            /**
             * @brief Forward to IStageProcessor::SetStageRunState() method.
             * @param stageId The identifier of the stage to modify.
             * @param runState The run state to set.
             * @return true if successful.
             */
            Bool SetStageRunState(const String& stageId, IStage::RunState runState)
            {
                return mStageProcessor->SetStageRunState(stageId, runState);
            }

            /**
             * @brief Forward to IStageProcessor::IsAnyTimelineRunning() method.
             * @return true if any stage timeline is running.
             */
            Bool IsAnyTimelineRunning() const
            {
                return mStageProcessor->IsAnyTimelineRunning();
            }

            /**
             * @brief Forward to IStageProcessor::StartIntro() method.
             * @param stageId The identifier of the stage to start.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageIntro() failed.
             */
            Bool StartIntro(const String& stageId)
            {
                return mStageProcessor->StartIntro(stageId);
            }
            /**
             * @brief Forward to IStageProcessor::StartOutro() method.
             * @param stageId The identifier of the stage to start.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageOutro() failed.
             */
            Bool StartOutro(const String& stageId)
            {
                return mStageProcessor->StartOutro(stageId);
            }

            /**
             * @brief Forward to IStageProcessor::StartIntro() method.
             * @param stageId The identifier of the stage to start.
             * @param startTime The IStageTimeline intro start time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageIntro() failed.
             */
            Bool StartIntro(const String& stageId, Real startTime)
            {
                return mStageProcessor->StartIntro(stageId, startTime);
            }
            /**
             * @brief Forward to IStageProcessor::StartOutro() method.
             * @param stageId The identifier of the stage to start.
             * @param endTime The IStageTimeline outro end time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageOutro() failed.
             */
            Bool StartOutro(const String& stageId, Real endTime)
            {
                return mStageProcessor->StartOutro(stageId, endTime);
            }

            /**
             * @brief Forward to IStageProcessor::StartIntro() method.
             * @param stageId The identifier of the stage to start.
             * @param startTime The IStageTimeline intro start time.
             * @param endTime The IStageTimeline intro end time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageIntro() failed.
             */
            Bool StartIntro(const String& stageId, Real startTime, Real endTime)
            {
                return mStageProcessor->StartIntro(stageId, startTime, endTime);
            }
            /**
             * @brief Forward to IStageProcessor::StartOutro() method.
             * @param stageId The identifier of the stage to start.
             * @param startTime The IStageTimeline outro start time.
             * @param endTime The IStageTimeline outro end time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageOutro() failed.
             */
            Bool StartOutro(const String& stageId, Real startTime, Real endTime)
            {
                return mStageProcessor->StartOutro(stageId, startTime, endTime);
            }

        protected:
            IStageProcessorPtr mStageProcessor;
        };
    }
}

#endif  // __MURL_LOGIC_BASE_STAGE_PROCESSOR_H__

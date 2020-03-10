// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_STAGE_PROCESSOR_H__
#define __MURL_LOGIC_I_STAGE_PROCESSOR_H__

#include "murl_logic_i_processor.h"
#include "murl_logic_i_stage.h"

namespace Murl
{
    namespace Logic
    {
        class IState;

        /**
         * @ingroup MurlLogicInterfaces
         * @interface IStageProcessor
         * @brief The IStageProcessor interface.
         * The IStageProcessor is handling a set of IStage objects.
         * The IStage::RunState is controlled by the IStageProcessor.
         * \n
         * Optional a graph &lt;Switch&gt; identifier can be specified to
         * automatically select a sub graph attached to a switch child.
         * The graph switch identifier must be set by SetSwitchNodeId() and each IStage
         * registered to the IStageHandler can specify a switch identifier for selecting
         * the active child of the switch at IStage::RUN_STATE_BEGIN_INTRO.
         * \n
         * Additional IProcessor objects can be added to the IStageProcessor object
         * by using myStageProc->GetProcessor(myStageProc)->AddChild().
         * The IProcessor (OnInit, OnProcessTick, OnProcessFrame) is always executed
         * before the stage execution.
         */
        class IStageProcessor
        {
        public:
            /**
             * @brief Get the processor interface from a stage-processor object.
             * The IStageProcessor conforms to the IProcessor interface.
             * @return The processor interface shared pointer.
             */
            virtual IProcessorPtr GetProcessor() = 0;

            /**
             * @brief Add a stage object.
             * @param stage The stage object to add.
             * @return true if successful.
             */
            virtual Bool AddStage(IStagePtr stage) = 0;

            /**
             * @brief Remove a stage object.
             * @param stage The stage object to remove.
             * @return true if successful.
             */
            virtual Bool RemoveStage(IStagePtr stage) = 0;

            /**
             * @brief Initialize and add a stage object.
             * @param state The IState object.
             * @param stage The stage object to initialize and add.
             * @return true if successful.
             */
            virtual Bool InitAddStage(const IState* state, IStagePtr stage) = 0;

            /**
             * @brief Remove and deinitialize a stage object.
             * @param state The IState object.
             * @param stage The stage object to deinitialize and remove.
             * @return true if successful.
             */
            virtual Bool RemoveDeInitStage(const IState* state, IStagePtr stage) = 0;

            /**
             * @brief Set the graph switch node identifier.
             * Must be set before the stage processor is initialized.
             * @param switchNodeId The full path to the graph &lt;Switch&gt; instance.
             * @return true if successful.
             */
            virtual Bool SetSwitchNodeId(const String& switchNodeId) = 0;

            /**
             * @brief Get the graph switch node identifier.
             * @return The switch node identifier string including the full path.
             */
            virtual const String& GetSwitchNodeId() const = 0;

            /**
             * @brief Get a stage object by name.
             * @param stageId The identifier of the stage to get.
             * @return The stage object or null if the identifier is not found.
             */
            virtual IStagePtr GetStage(const String& stageId) const = 0;

            /**
             * @brief Set the current run state of a stage.
             * @param stageId The identifier of the stage to modify.
             * @param runState The run state to set.
             * @return true if successful.
             */
            virtual Bool SetStageRunState(const String& stageId, IStage::RunState runState) = 0;

            /**
             * @brief Check if any stage's IStageTimeline is running.
             * @return true if any stage timeline is running.
             */
            virtual Bool IsAnyTimelineRunning() const = 0;

            /**
             * @brief Start a stage intro.
             * Execute the IStage::StartStageIntro() method.
             * @param stageId The identifier of the stage to start.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageIntro() failed.
             */
            virtual Bool StartIntro(const String& stageId) = 0;

            /**
             * @brief Start a stage outro.
             * Execute the IStage::StartStageOutro() method.
             * @param stageId The identifier of the stage to start.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageOutro() failed.
             */
            virtual Bool StartOutro(const String& stageId) = 0;

            /**
             * @brief Start a stage intro and set the IStageTimeline intro start time.
             * Execute the IStage::StartStageIntro() method.
             * @param stageId The identifier of the stage to start.
             * @param startTime The IStageTimeline intro start time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageIntro() failed.
             */
            virtual Bool StartIntro(const String& stageId, Real startTime) = 0;

            /**
             * @brief Start a stage outro and set the IStageTimeline outro end time.
             * Execute the IStage::StartStageOutro() method.
             * @param stageId The identifier of the stage to start.
             * @param endTime The IStageTimeline outro end time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageOutro() failed.
             */
            virtual Bool StartOutro(const String& stageId, Real endTime) = 0;

            /**
             * @brief Start a stage intro and set the IStageTimeline intro (start / end) time.
             * Execute the IStage::StartStageIntro() method.
             * @param stageId The identifier of the stage to start.
             * @param startTime The IStageTimeline intro start time.
             * @param endTime The IStageTimeline intro end time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageIntro() failed.
             */
            virtual Bool StartIntro(const String& stageId, Real startTime, Real endTime) = 0;

            /**
             * @brief Start a stage outro and set the IStageTimeline outro (start / end) time.
             * Execute the IStage::StartStageOutro() method.
             * @param stageId The identifier of the stage to start.
             * @param startTime The IStageTimeline outro start time.
             * @param endTime The IStageTimeline outro end time.
             * @return true if successful, false if the identifier is not found
             *  or IStage::StartStageOutro() failed.
             */
            virtual Bool StartOutro(const String& stageId, Real startTime, Real endTime) = 0;

        protected:
            virtual ~IStageProcessor() {}
        };
    }
}

#endif // __MURL_LOGIC_I_STAGE_PROCESSOR_H__

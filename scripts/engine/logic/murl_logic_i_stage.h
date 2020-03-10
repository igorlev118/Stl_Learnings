// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_STAGE_H__
#define __MURL_LOGIC_I_STAGE_H__

#include "murl_logic_i_app_stage.h"
#include "murl_logic_i_processor.h"
#include "murl_logic_i_stage_timeline.h"

namespace Murl
{
    namespace Logic
    {
        class IStageProcessor;

        /**
         * @ingroup MurlLogicInterfaces
         * @interface IStage
         * @brief The IStage interface.
         * The IStage is an extended IProcessor containing a run state
         * and an optional IStageTimeline object.
         * An IStage object is controlled by the IStageProcessor.
         * \n
         * Additional IProcessor objects can be added to the IStageProcessor object
         * by using myStageProc->GetProcessor(myStageProc)->AddChild().
         * See also enum #StageProcessing.
         */
        class IStage
        {
        public:
            /**
             * @brief Get the processor interface from a stage object.
             * The IStage conforms to the IProcessor interface.
             * @return The processor interface shared pointer.
             */
            virtual IProcessorPtr GetProcessor() = 0;

            /**
             * @brief Definiton of the stage processsing sequence.
             * The sequence of calling the IAppStage callbacks and
             * the IAppProcessor callbacks can be controlled.
             */
            enum StageProcessing
            {
                /**
                 * @brief Default, process stage before processor.
                 *  - IAppStage::OnProcessStageTick() or OnProcessStageFrame().
                 *  - IAppStage::OnProcessTick[RUN_STATE_STATE].
                 *  - IAppProcessor::OnProcessTick() or OnProcessFrame().
                 *  - IAppProcessor::OnProcessTickChildren() or OnProcessFrameChildren().
                 */
                BEFORE_STEP,

                /**
                 * @brief Process stage in between processor.
                 *  - IAppProcessor::OnProcessTick() or OnProcessFrame().
                 *  - IAppStage::OnProcessStageTick() or OnProcessStageFrame().
                 *  - IAppStage::OnProcessTick[RUN_STATE_STATE].
                 *  - IAppProcessor::OnProcessTickChildren() or OnProcessFrameChildren().
                 */
                BEFORE_CHILDREN,

                /**
                 * @brief Process stage after processor.
                 *  - IAppProcessor::OnProcessTick() or OnProcessFrame().
                 *  - IAppProcessor::OnProcessTickChildren() or OnProcessFrameChildren().
                 *  - IAppStage::OnProcessStageTick() or OnProcessStageFrame().
                 *  - IAppStage::OnProcessTick[RUN_STATE_STATE].
                 */
                AFTER_CHILDREN
            };

            /**
             * @brief Set the stage processing sequence.
             * @param processing The stage processing sequence.
             */
            virtual void SetStageProcessing(StageProcessing processing) = 0;

            /**
             * @brief Get the stage processing sequence.
             * @return The stage processing sequence.
             */
            virtual StageProcessing GetStageProcessing() const = 0;

            /**
             * @brief Set the stage callback object.
             * @param appStage The stage callback object.
             * @return true if successful.
             */
            virtual Bool SetAppStage(IAppStagePtr appStage) = 0;

            /**
             * @brief Set the stage identifier.
             * The stage identifier is used by the IStageProcessor to select
             * stages by string identifier.
             * @param stageId The stage identifier.
             */
            virtual void SetStageId(const String& stageId) = 0;

            /**
             * @brief Get the stage identifier.
             * @return The stage identifier string.
             */
            virtual const String& GetStageId() const = 0;

            /**
             * @brief Set the graph switch child identifier.
             * See IStageProcessor description.
             * @param switchId The graph switch child identifier.
             */
            virtual void SetSwitchId(const String& switchId) = 0;

            /**
             * @brief Get the graph switch child identifier.
             * @return The graph switch child identifier.
             */
            virtual const String& GetSwitchId() const = 0;

            /**
             * @brief Definition of RunStates controlled by the IStageProcessor.
             */
            enum RunState
            {
                /**
                 * @brief The idle state.
                 * - No IAppStage and IAppProcessor callbacks are processed.
                 */
                RUN_STATE_STOP,

                /**
                 * @brief The begin intro state.
                 *  - If the IStageProcessor switch is set, set the switch to
                 *    the stage's switch identifier.
                 *  - If the IStageTimeline is set, execute IStageTimeline::StartIntro().
                 *  - Call IAppStage::OnProcessStageTickBeginIntro().
                 *  - Switch to RUN_STATE_RUN_INTRO if run state is unchanged.
                 */
                RUN_STATE_BEGIN_INTRO,

                /**
                 * @brief The run intro state.
                 *  - Call IAppStage::OnProcessStageTickRunIntro().
                 *  - If the IStageTimeline is set and not running,
                 *    switch to RUN_STATE_BEGIN_RUN if run state is unchanged.
                 */
                RUN_STATE_RUN_INTRO,

                /**
                 * @brief The begin run state.
                 *  - Call IAppStage::OnProcessStageTickBeginRun().
                 *  - Switch to RUN_STATE_RUN if run state is unchanged.
                 */
                RUN_STATE_BEGIN_RUN,

                /**
                 * @brief The run state.
                 *  - Call IAppStage::OnProcessStageTickRun().
                 */
                RUN_STATE_RUN,

                /**
                 * @brief The begin outro state.
                 *  - If the IStageTimeline is set, execute IStageTimeline::StartOutro().
                 *  - Call IAppStage::OnProcessStageTickBeginOutro().
                 *  - Switch to RUN_STATE_RUN_OUTRO if run state is unchanged.
                 */
                RUN_STATE_BEGIN_OUTRO,

                /**
                 * @brief The run outro state.
                 *  - Call IAppStage::OnProcessStageTickRunOutro().
                 *  - If the IStageTimeline is set and not running,
                 *    switch to RUN_STATE_STOP and call IAppStage::OnProcessStageTickStop()
                 *    if run state is unchanged.
                 */
                RUN_STATE_RUN_OUTRO
            };

            /**
             * @brief Set the current run state.
             * @param runState The run state to set.
             */
            virtual void SetRunState(RunState runState) = 0;

            /**
             * @brief Check the current run state.
             * @param runState The run state to compare.
             * @return true if the current run state is equal.
             */
            virtual Bool IsRunState(RunState runState) const = 0;

            /**
             * @brief Get the current run state.
             * @return The current run state.
             */
            virtual RunState GetRunState() const = 0;

            /**
             * @brief Start a stage intro.
             * If the current run state is RUN_STATE_STOP, set the RUN_STATE_BEGIN_INTRO.
             * @return true if successful, false if the run state check failed.
             */
            virtual Bool StartStageIntro() = 0;

            /**
             * @brief Start a stage intro.
             * If the current run state is not RUN_STATE_STOP, set the RUN_STATE_BEGIN_OUTRO.
             * @return true if successful, false if the run state check failed.
             */
            virtual Bool StartStageOutro() = 0;

            /**
             * @brief Stop the stage.
             * If the current run state is not RUN_STATE_STOP, set the RUN_STATE_STOP.
             * \n
             * (!) IAppStage::OnStop() is not executed.
             * @return true if successful, false if the run state check failed.
             */
            virtual Bool StopStage() = 0;

            /**
             * @brief Check if stage is stopped.
             * @return true if run state is RUN_STATE_STOP.
             */
            virtual Bool IsStageStopped() const = 0;

            /**
             * @brief Create and initialize the IStageTimeline object.
             * The IStageTimeline object created is deinitialized and destroyed
             * automatically by DeInitStage().
             * \n
             * The intro start time is set to zero, the outro start time
             * is set to the intro end time by default.
             * The intro / outro time can be modified at any time by accessing
             * the IStageTimeline object using GetStageTimeline().
             * @param state The IState object.
             * @param timeline The full path to the graph &lt;Timeline&gt; instance.
             * @param introTime The intro end time in seconds,
             * @param outroTime The outro end time in seconds,
             * @return true if successful.
             */
            virtual Bool CreateStageTimeline(const IState* state, const String& timeline,
                                             Real introTime, Real outroTime) = 0;

            /**
             * @brief Set the IStageTimeline object.
             * The IStageTimeline object is not affected by DeInitStage().
             * @param stageTimeline An initialized IStageTimeline object.
             * @return true if successful.
             */
            virtual Bool SetStageTimeline(IStageTimelinePtr stageTimeline) = 0;

            /**
             * @brief Get the IStageTimeline object.
             * @return The IStageTimeline object, or null if not available.
             */
            virtual IStageTimelinePtr GetStageTimeline() const = 0;

        public: // typically used by IStageProcessor

            /**
             * @brief Initialize the stage.
             * This method is typically used by the corresponding IStageProcessor.
             * Execute IAppProcessor::OnInit(), IAppStage::OnInitStage() and
             * initialization of all processor's children.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             * @return true if successful.
             */
            virtual Bool InitStage(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Deinitialize the stage.
             * This method is typically used by the corresponding IStageProcessor.
             * Execute deinitialization of all processor's children,
             * AppStage::OnDeInitStage() and IAppProcessor::OnDeInit().
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             * @return true if successful.
             */
            virtual Bool DeInitStage(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Execute a logic tick.
             * This method is typically used by the corresponding IStageProcessor.
             * \n
             * Evaluate the #StageProcessing state to execute the IProcessor logic tick
             * and the ProcessStageTickSelf() method.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void ProcessStageTick(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Execute a frame tick.
             * This method is typically used by the corresponding IStageProcessor.
             * \n
             * Evaluate the #StageProcessing state to execute the IProcessor frame tick
             * and the ProcessStageFrameSelf() method.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void ProcessStageFrame(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Finish a logic tick.
             * This method is typically used by the corresponding IStageProcessor.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void FinishStageTick(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Finish a frame tick.
             * This method is typically used by the corresponding IStageProcessor.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void FinishStageFrame(const IState* state, IStageProcessor* stageProcessor) = 0;

        public:  // typically used by IStage internally

            /**
             * @brief Execute a IAppStage logic tick.
             * This method is typically used by IStage::ProcessStageTick() method.
             * \n
             * Execute the IAppStage::OnProcessStageTick() method first and afterwards the
             * IAppStage::OnProcessTick[RUN_STATE_STATE] method depending on the current #RunState.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void ProcessStageTickSelf(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Execute a IAppStage frame tick.
             * This method is typically used by IStage::ProcessStageFrame() method.
             * \n
             * Execute the IAppStage::OnProcessStageFrame() method.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void ProcessStageFrameSelf(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Finish a IAppStage logic tick.
             * This method is typically used by IStage::ProcessStageTick() method.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void FinishStageTickSelf(const IState* state, IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Finish a IAppStage frame tick.
             * This method is typically used by IStage::ProcessStageFrame() method.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void FinishStageFrameSelf(const IState* state, IStageProcessor* stageProcessor) = 0;

        protected:
            virtual ~IStage() {}
        };
    }
}

#endif // __MURL_LOGIC_I_STAGE_H__

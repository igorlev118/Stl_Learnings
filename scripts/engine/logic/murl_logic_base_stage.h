// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_BASE_STAGE_H__
#define __MURL_LOGIC_BASE_STAGE_H__

#include "murl_logic_base_processor.h"
#include "murl_logic_i_stage_processor.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicBaseClasses
         * @brief A helper class for simple use of the IStage object.
         * The BaseStage class implements the IAppStage app interface
         * and a BaseProcessor.\n
         * A stage is created and initialized at object instantiation.
         */
        class BaseStage : public IAppStage, public BaseProcessor
        {
        public:
            /**
             * @brief The constructor.
             * Creates a IStage object and setup the stage app interface.
             * @param factory The logic factory object.
             */
            BaseStage(IFactory* factory)
            : mStage(factory->CreateStage())
            {
                SetupProcessor(mStage->GetProcessor());
                mStage->SetAppStage(IAppStagePtr(this, NoDeleter()));
            }

            /**
             * @brief The constructor including the stage identifier.
             * Creates a IStage object and setup the stage app interface.
             * @param factory The logic factory object.
             * @param stageId The stage identifier.
             */
            BaseStage(IFactory* factory, const String& stageId)
            : mStage(factory->CreateStage())
            {
                SetupProcessor(mStage->GetProcessor());
                mStage->SetAppStage(IAppStagePtr(this, NoDeleter()));
                mStage->SetStageId(stageId);
            }

            /**
             * @brief The constructor including the stage identifier
             * and the graph switch identifier.
             * Creates a IStage object and setup the stage app interface.
             * @param factory The logic factory object.
             * @param stageId The stage identifier.
             * @param switchId The graph switch child identifier.
             */
            BaseStage(IFactory* factory, const String& stageId, const String& switchId)
            : mStage(factory->CreateStage())
            {
                SetupProcessor(mStage->GetProcessor());
                mStage->SetAppStage(IAppStagePtr(this, NoDeleter()));
                mStage->SetStageId(stageId);
                mStage->SetSwitchId(switchId);
            }

            /**
             * @brief The destructor.
             * Destroys the IStage object.
             */
            virtual ~BaseStage()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The IStage interface.
             */
            operator IStagePtr() const
            {
                return mStage;
            }

            /**
             * @brief Get the stage interface.
             * @return The IStage interface.
             */
            IStagePtr GetStage() const
            {
                return mStage;
            }

        public: // IStage

            /**
             * @brief Forward to IStage::SetStageProcessing() method.
             * @param processing The stage processing sequence.
             */
            void SetStageProcessing(IStage::StageProcessing processing)
            {
                mStage->SetStageProcessing(processing);
            }
            /**
             * @brief Forward to IStage::GetStageProcessing() method.
             * @return The stage processing sequence.
             */
            IStage::StageProcessing GetStageProcessing() const
            {
                return mStage->GetStageProcessing();
            }

            /**
             * @brief Forward to IStage::SetAppStage() method.
             * @param appStage The stage callback object.
             * @return true if successful.
             */
            Bool SetAppStage(IAppStagePtr appStage)
            {
                return mStage->SetAppStage(appStage);
            }

            /**
             * @brief Forward to IStage::SetStageId() method.
             * @param stageId The stage identifier.
             */
            void SetStageId(const String& stageId)
            {
                mStage->SetStageId(stageId);
            }
            /**
             * @brief Forward to IStage::GetStageId() method.
             * @return The stage identifier string.
             */
            const String& GetStageId() const
            {
                return mStage->GetStageId();
            }

            /**
             * @brief Forward to IStage::SetSwitchId() method.
             * @param switchId The graph switch child identifier.
             */
            void SetSwitchId(const String& switchId)
            {
                mStage->SetSwitchId(switchId);
            }
            /**
             * @brief Forward to IStage::GetSwitchId() method.
             * @return The graph switch child identifier.
             */
            const String& GetSwitchId() const
            {
                return mStage->GetSwitchId();
            }

            /**
             * @brief Forward to IStage::SetRunState() method.
             * @param runState The run state to set.
             */
            void SetRunState(IStage::RunState runState)
            {
                mStage->SetRunState(runState);
            }
            /**
             * @brief Forward to IStage::IsRunState() method.
             * @param runState The run state to compare.
             * @return true if the current run state is equal.
             */
            Bool IsRunState(IStage::RunState runState) const
            {
                return mStage->IsRunState(runState);
            }
            /**
             * @brief Forward to IStage::GetRunState() method.
             * @return The current run state.
             */
            IStage::RunState GetRunState() const
            {
                return mStage->GetRunState();
            }

            /**
             * @brief Forward to IStage::StartStageIntro() method.
             * @return true if successful, false if the run state check failed.
             */
            Bool StartStageIntro()
            {
                return mStage->StartStageIntro();
            }
            /**
             * @brief Forward to IStage::StartStageOutro() method.
             * @return true if successful, false if the run state check failed.
             */
            Bool StartStageOutro()
            {
                return mStage->StartStageOutro();
            }
            /**
             * @brief Forward to IStage::StopStage() method.
             * @return true if successful, false if the run state check failed.
             */
            Bool StopStage()
            {
                return mStage->StopStage();
            }

            /**
             * @brief Forward to IStage::IsStageStopped() method.
             * @return true if run state is RUN_STATE_STOP.
             */
            Bool IsStageStopped() const
            {
                return mStage->IsStageStopped();
            }

            /**
             * @brief Forward to IStage::CreateStageTimeline() method.
             * @param state The IState object.
             * @param timeline The full path to the graph &lt;Timeline&gt; instance.
             * @param introTime The intro end time in seconds,
             * @param outroTime The outro end time in seconds,
             * @return true if successful.
             */
            Bool CreateStageTimeline(const IState* state, const String& timeline,
                                     Real introTime, Real outroTime)
            {
                return mStage->CreateStageTimeline(state, timeline, introTime, outroTime);
            }
            /**
             * @brief Forward to IStage::SetStageTimeline() method.
             * @param stageTimeline An initialized IStageTimeline object.
             * @return true if successful.
             */
            Bool SetStageTimeline(IStageTimelinePtr stageTimeline)
            {
                return mStage->SetStageTimeline(stageTimeline);
            }
            /**
             * @brief Forward to IStage::GetStageTimeline() method.
             * @return The IStageTimeline object, or null if not available.
             */
            IStageTimelinePtr GetStageTimeline() const
            {
                return mStage->GetStageTimeline();
            }

        protected:  // IAppStage

            /**
             * @brief Default implementation of IAppStage::OnInitStage() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnInitStage(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
                return true;
            }
            /**
             * @brief Default implementation of IAppStage::OnDeInitStage() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             * @return true if successful, should return false
             *  if any deinitialization failed.
             */
            virtual Bool OnDeInitStage(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
                return true;
            }

            /**
             * @brief Default implementation of IAppStage::OnProcessStageTickBeginIntro() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickBeginIntro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnProcessStageTickRunIntro() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickRunIntro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnProcessStageTickBeginRun() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickBeginRun(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnProcessStageTickRun() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickRun(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnProcessStageTickBeginOutro() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickBeginOutro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnProcessStageTickRunOutro() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickRunOutro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnProcessStageTickStop() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickStop(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }

            /**
             * @brief Default implementation of IAppStage::OnProcessStageTick() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTick(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnProcessStageFrame() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageFrame(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnFinishStageTick() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnFinishStageTick(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }
            /**
             * @brief Default implementation of IAppStage::OnFinishStageFrame() method,
             * this method is empty and can be overwritten.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnFinishStageFrame(const Logic::IState* state, Logic::IStageProcessor* stageProcessor)
            {
            }

        protected:
            IStagePtr mStage;
        };
    }
}

#endif  // __MURL_LOGIC_BASE_STAGE_H__

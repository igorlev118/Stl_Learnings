// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_APP_STAGE_H__
#define __MURL_LOGIC_I_APP_STAGE_H__

#include "murl_logic_types.h"

namespace Murl
{
    namespace Logic
    {
        class IState;
        class IStageProcessor;

        /**
         * @ingroup MurlLogicAppInterfaces
         * @interface IAppStage
         * @brief The IAppStage interface.
         * This interface is used by the IStage object to callback the app.
         */
        class IAppStage
        {
        public:
            /**
             * @brief Called by IStage::InitStage().
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnInitStage(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;
            /**
             * @brief Called by IStage::DeInitStage().
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             * @return true if successful, should return false
             *  if any deinitialization failed.
             */
            virtual Bool OnDeInitStage(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf() for IStage::RUN_STATE_BEGIN_INTRO.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickBeginIntro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf() for IStage::RUN_STATE_RUN_INTRO.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickRunIntro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf() for IStage::RUN_STATE_BEGIN_RUN.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickBeginRun(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf() for IStage::RUN_STATE_RUN.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickRun(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf() for IStage::RUN_STATE_BEGIN_OUTRO.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickBeginOutro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf() for IStage::RUN_STATE_RUN_OUTRO.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickRunOutro(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf() at finish of IStage::RUN_STATE_RUN_OUTRO.
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTickStop(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageTickSelf().
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageTick(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::ProcessStageFrameSelf().
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnProcessStageFrame(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::FinishStageTickSelf().
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnFinishStageTick(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

            /**
             * @brief Called by IStage::FinishStageFrameSelf().
             * @param state The IState object.
             * @param stageProcessor The corresponding IStageProcessor object.
             */
            virtual void OnFinishStageFrame(const Logic::IState* state, Logic::IStageProcessor* stageProcessor) = 0;

        protected:
            virtual ~IAppStage() {}
        };
    }
}

#endif // __MURL_LOGIC_I_APP_STAGE_H__

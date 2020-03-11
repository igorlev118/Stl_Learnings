// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_APP_PROCESSOR_H__
#define __MURL_LOGIC_I_APP_PROCESSOR_H__

#include "murl_logic_i_state.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IPackage;

    namespace Logic
    {
        /**
         * @ingroup MurlLogicAppInterfaces
         * @interface IAppProcessor
         * @brief The IAppProcessor interface.
         * This interface is used by the IProcessor object to callback the app.
         */
        class IAppProcessor
        {
        public:
            /**
             * @brief Called by IProcessor at initialization.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any initialization failed.
             */
            virtual Bool OnInit(const Logic::IState* state) = 0;
            /**
             * @brief Called by IProcessor at deinitialization.
             * @param state The IState object.
             * @return true if successful, should return false
             *  if any deinitialization failed.
             */
            virtual Bool OnDeInit(const Logic::IState* state) = 0;

            /**
             * @brief Called by IProcessor each logic tick if enabled.
             * @param state The IState object.
             */
            virtual void OnProcessTick(const Logic::IState* state) = 0;
            /**
             * @brief Called by IProcessor after processing children's OnProcessTick()
             *  each logic tick if enabled.
             * @param state The IState object.
             */
            virtual void OnProcessTickChildren(const Logic::IState* state) = 0;

            /**
             * @brief Called by IProcessor each frame tick if enabled.
             * @param state The IState object.
             */
            virtual void OnProcessFrame(const Logic::IState* state) = 0;
            /**
             * @brief Called by IProcessor after processing children's OnProcessFrame()
             *  each frame tick if enabled.
             * @param state The IState object.
             */
            virtual void OnProcessFrameChildren(const Logic::IState* state) = 0;

            /**
             * @brief Called by IProcessor each logic tick if enabled.
             * @param state The IState object.
             */
            virtual void OnFinishTick(const Logic::IState* state) = 0;
            /**
             * @brief Called by IProcessor after processing children's OnFinishTick()
             *  each logic tick if enabled.
             * @param state The IState object.
             */
            virtual void OnFinishTickChildren(const Logic::IState* state) = 0;

            /**
             * @brief Called by IProcessor each frame tick if enabled.
             * @param state The IState object.
             */
            virtual void OnFinishFrame(const Logic::IState* state) = 0;
            /**
             * @brief Called by IProcessor after processing children's OnFinishFrame()
             *  each frame tick if enabled.
             * @param state The IState object.
             */
            virtual void OnFinishFrameChildren(const Logic::IState* state) = 0;

            /**
             * @brief Called by IProcessor to report the beginning of package loading.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWillBeLoaded(const Logic::IState* state, IPackage* package) = 0;
            /**
             * @brief Called by IProcessor to report the succesful loading of a package.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWasLoaded(const Logic::IState* state, IPackage* package) = 0;
            /**
             * @brief Called by IProcessor to report failed loading a package.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageFailedLoading(const Logic::IState* state, IPackage* package) = 0;
            /**
             * @brief Called by IProcessor to report the beginning of package unloading.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWillBeUnloaded(const Logic::IState* state, IPackage* package) = 0;
            /**
             * @brief Called by IProcessor to report the succesful unloading of a package.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageWasUnloaded(const Logic::IState* state, IPackage* package) = 0;
            /**
             * @brief Called by IProcessor to report failed unloading a package.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void OnPackageFailedUnloading(const Logic::IState* state, IPackage* package) = 0;

            /**
             * @brief Called by IProcessor to report a change of the application run state.
             * @param state The IState object.
             * @param currentState The current run state.
             * @param previousState The previous run state.
             */
            virtual void OnRunStateChanged(const Logic::IState* state, IEnums::AppRunState currentState,
                                           IEnums::AppRunState previousState) = 0;

            /**
             * @brief Called by IProcessor::SetEnabled().
             * This method is used to track the enabled state.
             * @param isEnabled true if enabled.
             */
            virtual void OnSetEnabled(Bool isEnabled) = 0;

        protected:
            virtual ~IAppProcessor() {}
        };
    }
}

#endif // __MURL_LOGIC_I_APP_PROCESSOR_H__
